#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_friends.h>

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

static EOS_HFriends eos_friends_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetFriendsInterface(p) : nullptr;
}

template <typename Fn>
static std::string eos_friends_copy_string_with_fixed_retry(Fn&& call_fn, size_t initial_capacity = 256)
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

    return eos_friends_copy_string_with_fixed_retry(
        [&](char* out_buffer, int32_t* inout_len) -> EOS_EResult
        {
            return EOS_EpicAccountId_ToString(account_id, out_buffer, inout_len);
        });
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

    ctx->callback.call(
        eos_friends_query_friends_info_from_native(data)
    );
    delete ctx;
}

// ============================================================
// EOS Friends
// ============================================================

void eos_friends_query_friends(std::string_view local_user_id, const GMFunction& callback)
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

static GMFunction g_cb_friends_update = nullptr;

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
    if (!data || !g_cb_friends_update)
        return;

    g_cb_friends_update.call(
        eos_friends_update_from_native(data)
    );
}

uint64_t eos_friends_add_notify_friends_update(
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HFriends friends = eos_friends_iface();
    if (!friends)
    {
        eos_set_last_error("EOS Friends interface unavailable.");
        return 0;
    }

    g_cb_friends_update = callback;

    EOS_Friends_AddNotifyFriendsUpdateOptions opts{};
    opts.ApiVersion = EOS_FRIENDS_ADDNOTIFYFRIENDSUPDATE_API_LATEST;

    return (uint64_t)EOS_Friends_AddNotifyFriendsUpdate(
        friends,
        &opts,
        nullptr,
        &eos_friends_update_callback
    );
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
}
