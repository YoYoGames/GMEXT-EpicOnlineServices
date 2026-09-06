#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"
#include "gm_eos_common.h"

#include <eos_sdk.h>
#include <eos_friends.h>

#include <cstdint>
#include <map>
#include <optional>
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
    std::optional<GMFunction> callback;
};

static EOS_HFriends eos_friends_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetFriendsInterface(p) : nullptr;
}

static gm_structs::EpicFriendsQueryFriendsCallbackInfo eos_friends_query_friends_info_from_native(
    const EOS_Friends_QueryFriendsCallbackInfo* p)
{
    gm_structs::EpicFriendsQueryFriendsCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.local_user_id = eos_epic_account_id_to_string_internal(p->LocalUserId);

    return out;
}

static void EOS_CALL eos_friends_query_friends_callback_native(
    const EOS_Friends_QueryFriendsCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    if (ctx->callback) ctx->callback.value().call(
        eos_friends_query_friends_info_from_native(data)
    );
    delete ctx;
}

// ============================================================
// EOS Friends
// ============================================================

void eos_friends_query_friends(std::string_view local_user_id, const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HFriends friends = eos_friends_iface();
    if (!friends) {
        eos_set_last_error("EOS Friends interface unavailable.");
        return;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Friends_QueryFriends: invalid local_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Friends_QueryFriendsOptions opts{};
    opts.ApiVersion = EOS_FRIENDS_QUERYFRIENDS_API_LATEST;
    opts.LocalUserId = local_user;

    EOS_Friends_QueryFriends(friends, &opts, ctx, &eos_friends_query_friends_callback_native);
}

int64_t eos_friends_get_friends_count(std::string_view local_user_id)
{
    eos_clear_last_error();

    EOS_HFriends friends = eos_friends_iface();
    if (!friends) {
        eos_set_last_error("EOS Friends interface unavailable.");
        return 0;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Friends_GetFriendsCount: invalid local_user_id.");
        return 0;
    }

    EOS_Friends_GetFriendsCountOptions opts{};
    opts.ApiVersion = EOS_FRIENDS_GETFRIENDSCOUNT_API_LATEST;
    opts.LocalUserId = local_user;

    return (int64_t)EOS_Friends_GetFriendsCount(friends, &opts);
}

std::string eos_friends_get_friend_at_index(std::string_view local_user_id, int64_t index)
{
    eos_clear_last_error();

    EOS_HFriends friends = eos_friends_iface();
    if (!friends) {
        eos_set_last_error("EOS Friends interface unavailable.");
        return std::string();
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Friends_GetFriendAtIndex: invalid local_user_id.");
        return std::string();
    }

    EOS_Friends_GetFriendAtIndexOptions opts{};
    opts.ApiVersion = EOS_FRIENDS_GETFRIENDATINDEX_API_LATEST;
    opts.LocalUserId = local_user;
    opts.Index = (int32_t)index;

    EOS_EpicAccountId friend_id = EOS_Friends_GetFriendAtIndex(friends, &opts);
    if (!friend_id)
        return std::string();

    return eos_epic_account_id_to_string_internal(friend_id);
}

gm_enums::EpicFriendsStatus eos_friends_get_status(
    std::string_view local_user_id,
    std::string_view target_user_id)
{
    eos_clear_last_error();

    EOS_HFriends friends = eos_friends_iface();
    if (!friends) {
        eos_set_last_error("EOS Friends interface unavailable.");
        return (gm_enums::EpicFriendsStatus)0;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    EOS_EpicAccountId target_user = eos_epic_account_id_from_string_internal(target_user_id);

    if (!local_user) {
        eos_set_last_error("EOS_Friends_GetStatus: invalid local_user_id.");
        return (gm_enums::EpicFriendsStatus)0;
    }

    if (!target_user) {
        eos_set_last_error("EOS_Friends_GetStatus: invalid target_user_id.");
        return (gm_enums::EpicFriendsStatus)0;
    }

    EOS_Friends_GetStatusOptions opts{};
    opts.ApiVersion = EOS_FRIENDS_GETSTATUS_API_LATEST;
    opts.LocalUserId = local_user;
    opts.TargetUserId = target_user;

    return (gm_enums::EpicFriendsStatus)EOS_Friends_GetStatus(friends, &opts);
}

// ============================================================
// EOS Friends Notify
// ============================================================

struct FriendsNotifyContext
{
    uint64_t notification_id;
};

static std::map<uint64_t, GMFunction> g_friends_update_callbacks;
static std::map<uint64_t, FriendsNotifyContext*> g_friends_update_contexts;

static gm_structs::EpicFriendsFriendsUpdateCallbackInfo
eos_friends_update_from_native(
    const EOS_Friends_OnFriendsUpdateInfo* p)
{
    gm_structs::EpicFriendsFriendsUpdateCallbackInfo out{};
    if (!p)
        return out;

    out.local_user_id =
        eos_epic_account_id_to_string_internal(p->LocalUserId);

    out.target_user_id =
        eos_epic_account_id_to_string_internal(p->TargetUserId);

    out.previous_status =
        (gm_enums::EpicFriendsStatus)p->PreviousStatus;

    out.current_status =
        (gm_enums::EpicFriendsStatus)p->CurrentStatus;

    return out;
}

static void EOS_CALL eos_friends_update_callback(
    const EOS_Friends_OnFriendsUpdateInfo* data)
{
    if (!data)
        return;

    FriendsNotifyContext* ctx = (FriendsNotifyContext*)data->ClientData;
    if (!ctx)
        return;

    uint64_t notification_id = ctx->notification_id;
    auto it = g_friends_update_callbacks.find(notification_id);
    if (it == g_friends_update_callbacks.end())
        return;

    it->second.call(eos_friends_update_from_native(data));
}

uint64_t eos_friends_add_notify_friends_update(
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HFriends friends = eos_friends_iface();
    if (!friends)
    {
        eos_set_last_error("EOS Friends interface unavailable.");
        return 0;
    }

    auto* ctx = new FriendsNotifyContext{};

    EOS_Friends_AddNotifyFriendsUpdateOptions opts{};
    opts.ApiVersion = EOS_FRIENDS_ADDNOTIFYFRIENDSUPDATE_API_LATEST;

    EOS_NotificationId notification_id = EOS_Friends_AddNotifyFriendsUpdate(
        friends,
        &opts,
        ctx,
        &eos_friends_update_callback
    );

    uint64_t result = (uint64_t)notification_id;
    if (result != 0)
    {
        ctx->notification_id = result;
        g_friends_update_callbacks[result] = callback.value_or(GMFunction{});
        g_friends_update_contexts[result] = ctx;
    }
    else
    {
        delete ctx;
    }

    return result;
}

void eos_friends_remove_notify_friends_update(
    uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HFriends friends = eos_friends_iface();
    if (!friends)
    {
        eos_set_last_error("EOS Friends interface unavailable.");
        return;
    }

    EOS_Friends_RemoveNotifyFriendsUpdate(
        friends,
        (EOS_NotificationId)notification_id
    );

    auto ctx_it = g_friends_update_contexts.find(notification_id);
    if (ctx_it != g_friends_update_contexts.end())
    {
        delete ctx_it->second;
        g_friends_update_contexts.erase(ctx_it);
    }

    g_friends_update_callbacks.erase(notification_id);
}
