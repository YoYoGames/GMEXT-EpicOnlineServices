#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_achievements.h>

#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

using namespace gm::wire;
using namespace gm_structs;
using namespace gm_enums;

// ============================================================
// Internal helpers / state
// ============================================================

struct EOSAsyncCallbackContext
{
    GMFunction callback;
};

static EOS_HAchievements eos_achievements_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetAchievementsInterface(p) : nullptr;
}

template <typename Fn>
static std::string eos_achievements_copy_string_with_fixed_retry(Fn&& call_fn, size_t initial_capacity = 256)
{
    std::vector<char> buffer(initial_capacity, '\0');
    int32_t length = (int32_t)buffer.size();

    EOS_EResult result = call_fn(buffer.data(), &length);
    if (result == EOS_EResult::EOS_LimitExceeded && length > 0)
    {
        buffer.assign((size_t)length, '\0');
        result = call_fn(buffer.data(), &length);
    }

    if (result != EOS_EResult::EOS_Success)
        return std::string();

    return std::string(buffer.data());
}

static EOS_ProductUserId eos_product_user_id_from_string_internal(std::string_view product_user_id)
{
    std::string value(product_user_id);
    if (value.empty())
        return nullptr;
    return EOS_ProductUserId_FromString(value.c_str());
}

static EOS_EpicAccountId eos_epic_account_id_from_string_internal(std::string_view account_id)
{
    std::string value(account_id);
    if (value.empty())
        return nullptr;
    return EOS_EpicAccountId_FromString(value.c_str());
}

static std::string eos_product_user_id_to_string_internal(EOS_ProductUserId product_user_id)
{
    if (!product_user_id)
        return std::string();

    return eos_achievements_copy_string_with_fixed_retry(
        [&](char* out_buffer, int32_t* inout_len) -> EOS_EResult
        {
            return EOS_ProductUserId_ToString(product_user_id, out_buffer, inout_len);
        });
}

static gm_structs::EpicAchievementsQueryDefinitionsCallbackInfo
eos_achievements_query_definitions_info_from_native(
    const EOS_Achievements_OnQueryDefinitionsCompleteCallbackInfo* p)
{
    gm_structs::EpicAchievementsQueryDefinitionsCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    return out;
}

static gm_structs::EpicAchievementsQueryPlayerAchievementsCallbackInfo
eos_achievements_query_player_achievements_info_from_native(
    const EOS_Achievements_OnQueryPlayerAchievementsCompleteCallbackInfo* p)
{
    gm_structs::EpicAchievementsQueryPlayerAchievementsCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.user_id = eos_product_user_id_to_string_internal(p->LocalUserId);
    out.target_user_id = eos_product_user_id_to_string_internal(p->TargetUserId);

    return out;
}

static void EOS_CALL eos_achievements_query_definitions_callback_native(
    const EOS_Achievements_OnQueryDefinitionsCompleteCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_achievements_query_definitions_info_from_native(data)
    );
    delete ctx;
}

static void EOS_CALL eos_achievements_query_player_achievements_callback_native(
    const EOS_Achievements_OnQueryPlayerAchievementsCompleteCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_achievements_query_player_achievements_info_from_native(data)
    );
    delete ctx;
}

// ============================================================
// EOS Achievements (Part 1)
// ============================================================

void eos_achievements_query_definitions(std::string_view local_user_id, const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HAchievements achievements = eos_achievements_iface();
    if (!achievements) {
        eos_set_last_error("EOS Achievements interface unavailable.");
        return;
    }

    // EOS definitions query may accept local epic account identity depending on SDK/API version.
    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Achievements_QueryDefinitions: invalid local_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Achievements_QueryDefinitionsOptions opts{};
    opts.ApiVersion = EOS_ACHIEVEMENTS_QUERYDEFINITIONS_API_LATEST;
    opts.LocalUserId = local_user;

    EOS_Achievements_QueryDefinitions(
        achievements,
        &opts,
        ctx,
        &eos_achievements_query_definitions_callback_native
    );
}

void eos_achievements_query_player_achievements(
    std::string_view local_user_id,
    std::string_view target_user_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HAchievements achievements = eos_achievements_iface();
    if (!achievements) {
        eos_set_last_error("EOS Achievements interface unavailable.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);

    if (!local_user) {
        eos_set_last_error("EOS_Achievements_QueryPlayerAchievements: invalid local_user_id.");
        return;
    }

    if (!target_user) {
        eos_set_last_error("EOS_Achievements_QueryPlayerAchievements: invalid target_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Achievements_QueryPlayerAchievementsOptions opts{};
    opts.ApiVersion = EOS_ACHIEVEMENTS_QUERYPLAYERACHIEVEMENTS_API_LATEST;
    opts.LocalUserId = local_user;
    opts.TargetUserId = target_user;

    EOS_Achievements_QueryPlayerAchievements(
        achievements,
        &opts,
        ctx,
        &eos_achievements_query_player_achievements_callback_native
    );
}

int64_t eos_achievements_get_achievement_definition_count()
{
    eos_clear_last_error();

    EOS_HAchievements achievements = eos_achievements_iface();
    if (!achievements) {
        eos_set_last_error("EOS Achievements interface unavailable.");
        return 0;
    }

    EOS_Achievements_GetAchievementDefinitionCountOptions opts{};
    opts.ApiVersion = EOS_ACHIEVEMENTS_GETACHIEVEMENTDEFINITIONCOUNT_API_LATEST;

    return (int64_t)EOS_Achievements_GetAchievementDefinitionCount(achievements, &opts);
}

int64_t eos_achievements_get_player_achievement_count(
    std::string_view local_user_id,
    std::string_view target_user_id)
{
    eos_clear_last_error();

    EOS_HAchievements achievements = eos_achievements_iface();
    if (!achievements) {
        eos_set_last_error("EOS Achievements interface unavailable.");
        return 0;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);

    if (!local_user) {
        eos_set_last_error("EOS_Achievements_GetPlayerAchievementCount: invalid local_user_id.");
        return 0;
    }

    if (!target_user) {
        eos_set_last_error("EOS_Achievements_GetPlayerAchievementCount: invalid target_user_id.");
        return 0;
    }

    EOS_Achievements_GetPlayerAchievementCountOptions opts{};
    opts.ApiVersion = EOS_ACHIEVEMENTS_GETPLAYERACHIEVEMENTCOUNT_API_LATEST;
    opts.UserId = target_user;

    return (int64_t)EOS_Achievements_GetPlayerAchievementCount(achievements, &opts);
}

// ============================================================
// EOS Achievements (Part 2)
// ============================================================


static gm_structs::EpicAchievementsDefinition eos_achievements_definition_from_native(
    const EOS_Achievements_Definition* p)
{
    gm_structs::EpicAchievementsDefinition out{};
    if (!p)
        return out;

    out.achievement_id = p->AchievementId ? std::string(p->AchievementId) : std::string();

    out.achievement_id = p->AchievementId;
    out.display_name = p->DisplayName;
    out.description = p->Description;
    out.locked_display_name = p->LockedDisplayName;
    out.locked_description = p->LockedDescription;
    out.hidden_description = p->HiddenDescription;
    out.completion_description = p->CompletionDescription;
    out.is_hidden = (p->bIsHidden != 0);
    out.unlocked_icon_id = (int64_t)p->UnlockedIconId;
    out.locked_icon_id = (int64_t)p->LockedIconId;

    out.stat_thresholds_count = (int64_t)p->StatThresholdsCount;
    //TODO
    //const EOS_Achievements_StatThresholds* StatThresholds;

    return out;
}

static gm_structs::EpicPlayerAchievement eos_achievements_player_achievement_from_native(
    const EOS_Achievements_PlayerAchievement* p)
{
    gm_structs::EpicPlayerAchievement out{};
    if (!p)
        return out;

    out.achievement_id = p->AchievementId ? std::string(p->AchievementId) : std::string();
    out.progress = (double)p->Progress;
    out.unlock_time = p->UnlockTime;
    out.stat_info_count = (int64_t)p->StatInfoCount;

    return out;
}

static gm_structs::EpicAchievementsUnlockAchievementsCallbackInfo
eos_achievements_unlock_achievements_info_from_native(
    const EOS_Achievements_OnUnlockAchievementsCompleteCallbackInfo* p)
{
    gm_structs::EpicAchievementsUnlockAchievementsCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.user_id = eos_product_user_id_to_string_internal(p->UserId);
    out.achievements_count = (int64_t)p->AchievementsCount;

    return out;
}

static void EOS_CALL eos_achievements_unlock_achievements_callback_native(
    const EOS_Achievements_OnUnlockAchievementsCompleteCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_achievements_unlock_achievements_info_from_native(data)
    );
    delete ctx;
}

gm_structs::EpicAchievementsDefinition eos_achievements_copy_achievement_definition_by_index(int64_t index)
{
    eos_clear_last_error();

    gm_structs::EpicAchievementsDefinition out{};

    EOS_HAchievements achievements = eos_achievements_iface();
    if (!achievements) {
        eos_set_last_error("EOS Achievements interface unavailable.");
        return out;
    }

    EOS_Achievements_CopyAchievementDefinitionByIndexOptions opts{};
    opts.ApiVersion = EOS_ACHIEVEMENTS_COPYDEFINITIONBYINDEX_API_LATEST;
    opts.AchievementIndex = (uint32_t)index;

    EOS_Achievements_Definition* def = nullptr;
    const EOS_EResult result = EOS_Achievements_CopyAchievementDefinitionByIndex(
        achievements, &opts, &def);

    if (result != EOS_EResult::EOS_Success || def == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Achievements_CopyAchievementDefinitionByIndex failed.");
        return out;
    }

    out = eos_achievements_definition_from_native(def);
    EOS_Achievements_Definition_Release(def);
    return out;
}

gm_structs::EpicAchievementsDefinition eos_achievements_copy_achievement_definition_by_id(
    std::string_view achievement_id)
{
    eos_clear_last_error();

    gm_structs::EpicAchievementsDefinition out{};

    EOS_HAchievements achievements = eos_achievements_iface();
    if (!achievements) {
        eos_set_last_error("EOS Achievements interface unavailable.");
        return out;
    }

    std::string achievement_id_storage(achievement_id);
    if (achievement_id_storage.empty()) {
        eos_set_last_error("EOS_Achievements_CopyAchievementDefinitionByAchievementId: achievement_id is required.");
        return out;
    }

    EOS_Achievements_CopyAchievementDefinitionByAchievementIdOptions opts{};
    opts.ApiVersion = EOS_ACHIEVEMENTS_COPYDEFINITIONBYACHIEVEMENTID_API_LATEST;
    opts.AchievementId = achievement_id_storage.c_str();

    EOS_Achievements_Definition* def = nullptr;
    const EOS_EResult result = EOS_Achievements_CopyAchievementDefinitionByAchievementId(
        achievements, &opts, &def);

    if (result != EOS_EResult::EOS_Success || def == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Achievements_CopyAchievementDefinitionByAchievementId failed.");
        return out;
    }

    out = eos_achievements_definition_from_native(def);
    EOS_Achievements_Definition_Release(def);
    return out;
}

gm_structs::EpicPlayerAchievement eos_achievements_copy_player_achievement_by_index(
    std::string_view local_user_id,
    std::string_view target_user_id,
    int64_t index)
{
    eos_clear_last_error();

    gm_structs::EpicPlayerAchievement out{};

    EOS_HAchievements achievements = eos_achievements_iface();
    if (!achievements) {
        eos_set_last_error("EOS Achievements interface unavailable.");
        return out;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);

    if (!local_user) {
        eos_set_last_error("EOS_Achievements_CopyPlayerAchievementByIndex: invalid local_user_id.");
        return out;
    }

    if (!target_user) {
        eos_set_last_error("EOS_Achievements_CopyPlayerAchievementByIndex: invalid target_user_id.");
        return out;
    }

    EOS_Achievements_CopyPlayerAchievementByIndexOptions opts{};
    opts.ApiVersion = EOS_ACHIEVEMENTS_COPYPLAYERACHIEVEMENTBYINDEX_API_LATEST;
    opts.TargetUserId = target_user;
    opts.AchievementIndex = (uint32_t)index;

    EOS_Achievements_PlayerAchievement* achievement = nullptr;
    const EOS_EResult result = EOS_Achievements_CopyPlayerAchievementByIndex(
        achievements, &opts, &achievement);

    if (result != EOS_EResult::EOS_Success || achievement == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Achievements_CopyPlayerAchievementByIndex failed.");
        return out;
    }

    out = eos_achievements_player_achievement_from_native(achievement);
    EOS_Achievements_PlayerAchievement_Release(achievement);
    return out;
}

static gm_structs::EpicAchievementsDefinitionV2 eos_achievements_definition_v2_from_native(
    const EOS_Achievements_DefinitionV2* p)
{
    gm_structs::EpicAchievementsDefinitionV2 out{};
    if (!p)
        return out;

    out.achievement_id =
        p->AchievementId ? std::string(p->AchievementId) : std::string();

    out.unlocked_display_name =
        p->UnlockedDisplayName ? std::string(p->UnlockedDisplayName) : std::string();

    out.unlocked_description =
        p->UnlockedDescription ? std::string(p->UnlockedDescription) : std::string();

    out.locked_display_name =
        p->LockedDisplayName ? std::string(p->LockedDisplayName) : std::string();

    out.locked_description =
        p->LockedDescription ? std::string(p->LockedDescription) : std::string();

    out.flavor_text =
        p->FlavorText ? std::string(p->FlavorText) : std::string();

    // out.completion_description =
    //     p->CompletionDescription ? std::string(p->CompletionDescription) : std::string();

    out.unlocked_icon_url =
        p->UnlockedIconURL ? std::string(p->UnlockedIconURL) : std::string();

    out.locked_icon_url =
        p->LockedIconURL ? std::string(p->LockedIconURL) : std::string();

    out.is_hidden = (p->bIsHidden != 0);
    out.stat_thresholds_count = (int64_t)p->StatThresholdsCount;

    return out;
}

gm_structs::EpicAchievementsDefinitionV2 eos_achievements_copy_achievement_definition_v2_by_index(int64_t index)
{
    eos_clear_last_error();

    gm_structs::EpicAchievementsDefinitionV2 out{};

    EOS_HAchievements achievements = eos_achievements_iface();
    if (!achievements) {
        eos_set_last_error("EOS Achievements interface unavailable.");
        return out;
    }

    EOS_Achievements_CopyAchievementDefinitionV2ByIndexOptions opts{};
    opts.ApiVersion = EOS_ACHIEVEMENTS_COPYACHIEVEMENTDEFINITIONV2BYINDEX_API_LATEST;
    opts.AchievementIndex = (uint32_t)index;

    EOS_Achievements_DefinitionV2* def = nullptr;
    const EOS_EResult result =
        EOS_Achievements_CopyAchievementDefinitionV2ByIndex(
            achievements,
            &opts,
            &def
        );

    if (result != EOS_EResult::EOS_Success || def == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(
            err ? err : "EOS_Achievements_CopyAchievementDefinitionV2ByIndex failed."
        );
        return out;
    }

    out = eos_achievements_definition_v2_from_native(def);
    EOS_Achievements_DefinitionV2_Release(def);
    return out;
}

gm_structs::EpicPlayerAchievement eos_achievements_copy_player_achievement_by_id(
    std::string_view local_user_id,
    std::string_view target_user_id,
    std::string_view achievement_id)
{
    eos_clear_last_error();

    gm_structs::EpicPlayerAchievement out{};

    EOS_HAchievements achievements = eos_achievements_iface();
    if (!achievements) {
        eos_set_last_error("EOS Achievements interface unavailable.");
        return out;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);
    std::string achievement_id_storage(achievement_id);

    if (!local_user) {
        eos_set_last_error("EOS_Achievements_CopyPlayerAchievementByAchievementId: invalid local_user_id.");
        return out;
    }

    if (!target_user) {
        eos_set_last_error("EOS_Achievements_CopyPlayerAchievementByAchievementId: invalid target_user_id.");
        return out;
    }

    if (achievement_id_storage.empty()) {
        eos_set_last_error("EOS_Achievements_CopyPlayerAchievementByAchievementId: achievement_id is required.");
        return out;
    }

    EOS_Achievements_CopyPlayerAchievementByAchievementIdOptions opts{};
    opts.ApiVersion = EOS_ACHIEVEMENTS_COPYPLAYERACHIEVEMENTBYACHIEVEMENTID_API_LATEST;
    opts.TargetUserId = target_user;
    opts.AchievementId = achievement_id_storage.c_str();

    EOS_Achievements_PlayerAchievement* achievement = nullptr;
    const EOS_EResult result = EOS_Achievements_CopyPlayerAchievementByAchievementId(
        achievements, &opts, &achievement);

    if (result != EOS_EResult::EOS_Success || achievement == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Achievements_CopyPlayerAchievementByAchievementId failed.");
        return out;
    }

    out = eos_achievements_player_achievement_from_native(achievement);
    EOS_Achievements_PlayerAchievement_Release(achievement);
    return out;
}

void eos_achievements_unlock_achievements(
    std::string_view user_id,
    const std::vector<std::string_view>& achievement_ids,
    const gm::wire::GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HAchievements achievements = eos_achievements_iface();
    if (!achievements) {
        eos_set_last_error("EOS Achievements interface unavailable.");
        return;
    }

    EOS_ProductUserId user = eos_product_user_id_from_string_internal(user_id);
    if (!user) {
        eos_set_last_error("EOS_Achievements_UnlockAchievements: invalid user_id.");
        return;
    }

    if (achievement_ids.empty()) {
        eos_set_last_error("EOS_Achievements_UnlockAchievements: achievement_ids is required.");
        return;
    }

    // Copy string_view data into stable owned storage
    std::vector<std::string> achievement_id_storage;
    achievement_id_storage.reserve(achievement_ids.size());

    for (const auto& id : achievement_ids) {
        if (id.empty()) {
            eos_set_last_error("EOS_Achievements_UnlockAchievements: achievement_ids contains an empty achievement id.");
            return;
        }
        achievement_id_storage.emplace_back(id);
    }

    // Build pointer array referencing the owned strings above
    std::vector<const char*> achievement_id_ptrs;
    achievement_id_ptrs.reserve(achievement_id_storage.size());

    for (const auto& id : achievement_id_storage) {
        achievement_id_ptrs.push_back(id.c_str());
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Achievements_UnlockAchievementsOptions opts{};
    opts.ApiVersion = EOS_ACHIEVEMENTS_UNLOCKACHIEVEMENTS_API_LATEST;
    opts.UserId = user;
    opts.AchievementIds = achievement_id_ptrs.data();
    opts.AchievementsCount = static_cast<uint32_t>(achievement_id_ptrs.size());

    EOS_Achievements_UnlockAchievements(
        achievements,
        &opts,
        ctx,
        &eos_achievements_unlock_achievements_callback_native
    );
}

// ============================================================
// EOS Achievements Notify
// ============================================================

static GMFunction g_cb_achievements_unlocked_v2 = nullptr;

static gm_structs::EpicAchievementsUnlockedV2CallbackInfo
eos_achievements_unlocked_v2_from_native(
    const EOS_Achievements_OnAchievementsUnlockedCallbackV2Info* p)
{
    gm_structs::EpicAchievementsUnlockedV2CallbackInfo out{};
    if (!p)
        return out;

    out.user_id = eos_product_user_id_to_string_internal(p->UserId);
    out.achievement_id = p->AchievementId ? std::string(p->AchievementId) : std::string();
    out.unlock_time = p->UnlockTime;

    return out;
}

static void EOS_CALL eos_achievements_unlocked_v2_callback(
    const EOS_Achievements_OnAchievementsUnlockedCallbackV2Info* data)
{
    if (!data || !g_cb_achievements_unlocked_v2)
        return;

    g_cb_achievements_unlocked_v2.call(
        eos_achievements_unlocked_v2_from_native(data)
    );
}

uint64_t eos_achievements_add_notify_achievements_unlocked_v2(
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HAchievements achievements = eos_achievements_iface();
    if (!achievements)
    {
        eos_set_last_error("EOS Achievements interface unavailable.");
        return 0;
    }

    g_cb_achievements_unlocked_v2 = callback;

    EOS_Achievements_AddNotifyAchievementsUnlockedV2Options opts{};
    opts.ApiVersion = EOS_ACHIEVEMENTS_ADDNOTIFYACHIEVEMENTSUNLOCKEDV2_API_LATEST;

    return (uint64_t)EOS_Achievements_AddNotifyAchievementsUnlockedV2(
        achievements,
        &opts,
        nullptr,
        &eos_achievements_unlocked_v2_callback
    );
}

void eos_achievements_remove_notify_achievements_unlocked(
    uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HAchievements achievements = eos_achievements_iface();
    if (!achievements)
    {
        eos_set_last_error("EOS Achievements interface unavailable.");
        return;
    }
    EOS_Achievements_RemoveNotifyAchievementsUnlocked(
        achievements,
        (EOS_NotificationId)notification_id
    );
}

