#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_presence.h>

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

static EOS_HPresence eos_presence_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetPresenceInterface(p) : nullptr;
}

template <typename Fn>
static std::string eos_presence_copy_string_with_fixed_retry(Fn&& call_fn, size_t initial_capacity = 256)
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

static EOS_EpicAccountId eos_epic_account_id_from_string_internal(std::string_view account_id)
{
    std::string value(account_id);
    if (value.empty())
        return nullptr;
    return EOS_EpicAccountId_FromString(value.c_str());
}

static std::string eos_epic_account_id_to_string_internal(EOS_EpicAccountId account_id)
{
    if (!account_id)
        return std::string();

    return eos_presence_copy_string_with_fixed_retry(
        [&](char* out_buffer, int32_t* inout_len) -> EOS_EResult
        {
            return EOS_EpicAccountId_ToString(account_id, out_buffer, inout_len);
        });
}

static gm_structs::EpicPresenceInfo eos_presence_info_from_native(const EOS_Presence_Info* p)
{
    gm_structs::EpicPresenceInfo out{};
    if (!p)
        return out;

    out.user_id = eos_epic_account_id_to_string_internal(p->UserId);
    out.status = (gm_enums::EpicPresenceStatus)p->Status;
    out.product_id = p->ProductId ? std::string(p->ProductId) : std::string();
    out.product_version = p->ProductVersion ? std::string(p->ProductVersion) : std::string();
    out.platform = p->Platform ? std::string(p->Platform) : std::string();
    out.rich_text = p->RichText ? std::string(p->RichText) : std::string();
    out.records_count = (int64_t)p->RecordsCount;

    return out;
}

static gm_structs::EpicPresenceQueryPresenceCallbackInfo eos_presence_query_presence_info_from_native(
    const EOS_Presence_QueryPresenceCallbackInfo* p)
{
    gm_structs::EpicPresenceQueryPresenceCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.local_user_id = eos_epic_account_id_to_string_internal(p->LocalUserId);
    out.target_user_id = eos_epic_account_id_to_string_internal(p->TargetUserId);

    return out;
}

static void EOS_CALL eos_presence_query_presence_callback_native(
    const EOS_Presence_QueryPresenceCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_presence_query_presence_info_from_native(data)
    );
    delete ctx;
}

// ============================================================
// EOS Presence (Part 1)
// ============================================================

void eos_presence_query_presence(
    std::string_view local_user_id,
    std::string_view target_user_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HPresence presence = eos_presence_iface();
    if (!presence) {
        eos_set_last_error("EOS Presence interface unavailable.");
        return;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    EOS_EpicAccountId target_user = eos_epic_account_id_from_string_internal(target_user_id);

    if (!local_user) {
        eos_set_last_error("EOS_Presence_QueryPresence: invalid local_user_id.");
        return;
    }

    if (!target_user) {
        eos_set_last_error("EOS_Presence_QueryPresence: invalid target_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Presence_QueryPresenceOptions opts{};
    opts.ApiVersion = EOS_PRESENCE_QUERYPRESENCE_API_LATEST;
    opts.LocalUserId = local_user;
    opts.TargetUserId = target_user;

    EOS_Presence_QueryPresence(
        presence,
        &opts,
        ctx,
        &eos_presence_query_presence_callback_native
    );
}

bool eos_presence_has_presence(
    std::string_view local_user_id,
    std::string_view target_user_id)
{
    eos_clear_last_error();

    EOS_HPresence presence = eos_presence_iface();
    if (!presence) {
        eos_set_last_error("EOS Presence interface unavailable.");
        return false;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    EOS_EpicAccountId target_user = eos_epic_account_id_from_string_internal(target_user_id);

    if (!local_user) {
        eos_set_last_error("EOS_Presence_HasPresence: invalid local_user_id.");
        return false;
    }

    if (!target_user) {
        eos_set_last_error("EOS_Presence_HasPresence: invalid target_user_id.");
        return false;
    }

    EOS_Presence_HasPresenceOptions opts{};
    opts.ApiVersion = EOS_PRESENCE_HASPRESENCE_API_LATEST;
    opts.LocalUserId = local_user;
    opts.TargetUserId = target_user;

    return EOS_Presence_HasPresence(presence, &opts) != 0;
}

gm_structs::EpicPresenceInfo eos_presence_copy_presence(
    std::string_view local_user_id,
    std::string_view target_user_id)
{
    eos_clear_last_error();

    gm_structs::EpicPresenceInfo out{};

    EOS_HPresence presence = eos_presence_iface();
    if (!presence) {
        eos_set_last_error("EOS Presence interface unavailable.");
        return out;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    EOS_EpicAccountId target_user = eos_epic_account_id_from_string_internal(target_user_id);

    if (!local_user) {
        eos_set_last_error("EOS_Presence_CopyPresence: invalid local_user_id.");
        return out;
    }

    if (!target_user) {
        eos_set_last_error("EOS_Presence_CopyPresence: invalid target_user_id.");
        return out;
    }

    EOS_Presence_CopyPresenceOptions opts{};
    opts.ApiVersion = EOS_PRESENCE_COPYPRESENCE_API_LATEST;
    opts.LocalUserId = local_user;
    opts.TargetUserId = target_user;

    EOS_Presence_Info* info = nullptr;
    const EOS_EResult result = EOS_Presence_CopyPresence(presence, &opts, &info);
    if (result != EOS_EResult::EOS_Success || info == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Presence_CopyPresence failed.");
        return out;
    }

    out = eos_presence_info_from_native(info);
    EOS_Presence_Info_Release(info);
    return out;
}

// ============================================================
// EOS Presence (Part 2)
// ============================================================

#include <unordered_map>

static GMFunction g_cb_presence_changed = nullptr;
static GMFunction g_cb_presence_join_game_accepted = nullptr;

static std::unordered_map<uint64_t, EOS_HPresenceModification> g_presence_modifications;
static uint64_t g_next_presence_modification_id = 1;

static EOS_HPresenceModification eos_presence_modification_get(uint64_t id)
{
    auto it = g_presence_modifications.find(id);
    if (it == g_presence_modifications.end())
        return nullptr;
    return it->second;
}

static uint64_t eos_presence_modification_store(EOS_HPresenceModification mod)
{
    const uint64_t id = g_next_presence_modification_id++;
    g_presence_modifications[id] = mod;
    return id;
}

static void eos_presence_modification_erase(uint64_t id)
{
    auto it = g_presence_modifications.find(id);
    if (it == g_presence_modifications.end())
        return;

    //TODO
    // if (it->second)
    //     EOS_Presence_PresenceModification_Release(it->second);

    g_presence_modifications.erase(it);
}

static gm_structs::EpicPresenceSetPresenceCallbackInfo eos_presence_set_presence_info_from_native(
    const EOS_Presence_SetPresenceCallbackInfo* p)
{
    gm_structs::EpicPresenceSetPresenceCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.local_user_id = eos_epic_account_id_to_string_internal(p->LocalUserId);
    return out;
}

static gm_structs::EpicPresenceChangedCallbackInfo eos_presence_changed_info_from_native(
    const EOS_Presence_PresenceChangedCallbackInfo* p)
{
    gm_structs::EpicPresenceChangedCallbackInfo out{};
    if (!p)
        return out;

    out.local_user_id = eos_epic_account_id_to_string_internal(p->LocalUserId);
    out.presence_user_id = eos_epic_account_id_to_string_internal(p->PresenceUserId);
    return out;
}

static gm_structs::EpicPresenceJoinGameAcceptedCallbackInfo eos_presence_join_game_accepted_info_from_native(
    const EOS_Presence_JoinGameAcceptedCallbackInfo* p)
{
    gm_structs::EpicPresenceJoinGameAcceptedCallbackInfo out{};
    if (!p)
        return out;

    out.join_info = p->JoinInfo ? std::string(p->JoinInfo) : std::string();
    out.local_user_id = eos_epic_account_id_to_string_internal(p->LocalUserId);
    out.target_user_id = eos_epic_account_id_to_string_internal(p->TargetUserId);
    out.ui_event_id = (uint64_t)p->UiEventId;
    return out;
}

static void EOS_CALL eos_presence_set_presence_callback_native(
    const EOS_Presence_SetPresenceCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_presence_set_presence_info_from_native(data)
    );
    delete ctx;
}

static void EOS_CALL eos_presence_changed_callback_native(
    const EOS_Presence_PresenceChangedCallbackInfo* data)
{
    if (!data || !g_cb_presence_changed)
        return;

    g_cb_presence_changed.call(
        eos_presence_changed_info_from_native(data)
    );
}

static void EOS_CALL eos_presence_join_game_accepted_callback_native(
    const EOS_Presence_JoinGameAcceptedCallbackInfo* data)
{
    if (!data || !g_cb_presence_join_game_accepted)
        return;

    g_cb_presence_join_game_accepted.call(
        eos_presence_join_game_accepted_info_from_native(data)
    );
}

uint64_t eos_presence_create_presence_modification(std::string_view local_user_id)
{
    eos_clear_last_error();

    EOS_HPresence presence = eos_presence_iface();
    if (!presence) {
        eos_set_last_error("EOS Presence interface unavailable.");
        return 0;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Presence_CreatePresenceModification: invalid local_user_id.");
        return 0;
    }

    EOS_Presence_CreatePresenceModificationOptions opts{};
    opts.ApiVersion = EOS_PRESENCE_CREATEPRESENCEMODIFICATION_API_LATEST;
    opts.LocalUserId = local_user;

    EOS_HPresenceModification mod = nullptr;
    const EOS_EResult result = EOS_Presence_CreatePresenceModification(presence, &opts, &mod);
    if (result != EOS_EResult::EOS_Success || mod == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Presence_CreatePresenceModification failed.");
        return 0;
    }

    return eos_presence_modification_store(mod);
}

void eos_presence_modification_release(uint64_t modification_id)
{
    eos_clear_last_error();
    eos_presence_modification_erase(modification_id);
}

gm_enums::EpicResult eos_presence_modification_set_status(
    uint64_t modification_id,
    gm_enums::EpicPresenceStatus status)
{
    eos_clear_last_error();

    EOS_HPresenceModification mod = eos_presence_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS Presence modification handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_PresenceModification_SetStatusOptions opts{};
    opts.ApiVersion = EOS_PRESENCEMODIFICATION_SETSTATUS_API_LATEST;
    opts.Status = (EOS_Presence_EStatus)status;

    const EOS_EResult result = EOS_PresenceModification_SetStatus(mod, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_PresenceModification_SetStatus failed.");
    }

    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_presence_modification_set_raw_rich_text(
    uint64_t modification_id,
    std::string_view rich_text)
{
    eos_clear_last_error();

    EOS_HPresenceModification mod = eos_presence_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS Presence modification handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    std::string rich_text_storage(rich_text);

    EOS_PresenceModification_SetRawRichTextOptions opts{};
    opts.ApiVersion = EOS_PRESENCEMODIFICATION_SETRAWRICHTEXT_API_LATEST;
    opts.RichText = rich_text_storage.empty() ? nullptr : rich_text_storage.c_str();

    const EOS_EResult result = EOS_PresenceModification_SetRawRichText(mod, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_PresenceModification_SetRawRichText failed.");
    }

    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_presence_modification_set_data(
    uint64_t modification_id,
    std::string_view key,
    std::string_view value)
{
    eos_clear_last_error();

    EOS_HPresenceModification mod = eos_presence_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS Presence modification handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    std::string key_storage(key);
    std::string value_storage(value);

    if (key_storage.empty()) {
        eos_set_last_error("EOS_PresenceModification_SetData: key is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_Presence_DataRecord record{};
    record.ApiVersion = EOS_PRESENCE_DATARECORD_API_LATEST;
    record.Key = key_storage.c_str();
    record.Value = value_storage.c_str();

    EOS_PresenceModification_SetDataOptions opts{};
    opts.ApiVersion = EOS_PRESENCEMODIFICATION_SETDATA_API_LATEST;
    opts.Records = &record;
    opts.RecordsCount = 1;

    const EOS_EResult result = EOS_PresenceModification_SetData(mod, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_PresenceModification_SetData failed.");
    }

    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_presence_modification_delete_data(
    uint64_t modification_id,
    std::string_view key)
{
    eos_clear_last_error();

    EOS_HPresenceModification mod = eos_presence_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS Presence modification handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    std::string key_storage(key);
    if (key_storage.empty()) {
        eos_set_last_error("EOS_PresenceModification_DeleteData: key is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_PresenceModification_DataRecordId record_id{};
    record_id.ApiVersion = EOS_PRESENCEMODIFICATION_DATARECORDID_API_LATEST;
    record_id.Key = key_storage.c_str();

    EOS_PresenceModification_DeleteDataOptions opts{};
    opts.ApiVersion = EOS_PRESENCEMODIFICATION_DELETEDATA_API_LATEST;
    opts.Records = &record_id;
    opts.RecordsCount = 1;

    const EOS_EResult result = EOS_PresenceModification_DeleteData(mod, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_PresenceModification_DeleteData failed.");
    }

    return (gm_enums::EpicResult)result;
}

void eos_presence_set_presence(
    std::string_view local_user_id,
    uint64_t modification_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HPresence presence = eos_presence_iface();
    if (!presence) {
        eos_set_last_error("EOS Presence interface unavailable.");
        return;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Presence_SetPresence: invalid local_user_id.");
        return;
    }

    EOS_HPresenceModification mod = eos_presence_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS_Presence_SetPresence: invalid modification_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Presence_SetPresenceOptions opts{};
    opts.ApiVersion = EOS_PRESENCE_SETPRESENCE_API_LATEST;
    opts.LocalUserId = local_user;
    opts.PresenceModificationHandle = mod;

    EOS_Presence_SetPresence(
        presence,
        &opts,
        ctx,
        &eos_presence_set_presence_callback_native
    );

    // EOS docs say the modification handle can be safely released after SetPresence.
    eos_presence_modification_erase(modification_id);
}

uint64_t eos_presence_add_notify_on_presence_changed(const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HPresence presence = eos_presence_iface();
    if (!presence) {
        eos_set_last_error("EOS Presence interface unavailable.");
        return 0;
    }

    g_cb_presence_changed = callback;

    EOS_Presence_AddNotifyOnPresenceChangedOptions opts{};
    opts.ApiVersion = EOS_PRESENCE_ADDNOTIFYONPRESENCECHANGED_API_LATEST;

    return (uint64_t)EOS_Presence_AddNotifyOnPresenceChanged(
        presence,
        &opts,
        nullptr,
        &eos_presence_changed_callback_native
    );
}

void eos_presence_remove_notify_on_presence_changed(uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HPresence presence = eos_presence_iface();
    if (!presence) {
        eos_set_last_error("EOS Presence interface unavailable.");
        return;
    }

    EOS_Presence_RemoveNotifyOnPresenceChanged(
        presence,
        (EOS_NotificationId)notification_id
    );
}

uint64_t eos_presence_add_notify_join_game_accepted(const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HPresence presence = eos_presence_iface();
    if (!presence) {
        eos_set_last_error("EOS Presence interface unavailable.");
        return 0;
    }

    g_cb_presence_join_game_accepted = callback;

    EOS_Presence_AddNotifyJoinGameAcceptedOptions opts{};
    opts.ApiVersion = EOS_PRESENCE_ADDNOTIFYJOINGAMEACCEPTED_API_LATEST;

    return (uint64_t)EOS_Presence_AddNotifyJoinGameAccepted(
        presence,
        &opts,
        nullptr,
        &eos_presence_join_game_accepted_callback_native
    );
}

void eos_presence_remove_notify_join_game_accepted(uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HPresence presence = eos_presence_iface();
    if (!presence) {
        eos_set_last_error("EOS Presence interface unavailable.");
        return;
    }

    EOS_Presence_RemoveNotifyJoinGameAccepted(
        presence,
        (EOS_NotificationId)notification_id
    );
}
