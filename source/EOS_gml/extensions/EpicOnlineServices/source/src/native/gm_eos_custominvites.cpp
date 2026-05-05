#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_custominvites.h>

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

static EOS_HCustomInvites eos_ci_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetCustomInvitesInterface(p) : nullptr;
}

static EOS_ProductUserId eos_product_user_id_from_string_internal(std::string_view id)
{
    std::string v(id);
    if (v.empty()) return nullptr;
    return EOS_ProductUserId_FromString(v.c_str());
}

static std::string eos_product_user_id_to_string_internal(EOS_ProductUserId id)
{
    if (!id) return std::string();
    char buf[64] = {};
    int32_t len = (int32_t)sizeof(buf);
    if (EOS_ProductUserId_ToString(id, buf, &len) != EOS_EResult::EOS_Success)
        return std::string();
    return std::string(buf);
}

// ============================================================
// Notify globals
// ============================================================

static GMFunction g_cb_ci_custom_invite_received;
static GMFunction g_cb_ci_custom_invite_accepted;
static GMFunction g_cb_ci_custom_invite_rejected;
static GMFunction g_cb_ci_request_to_join_response_received;
static GMFunction g_cb_ci_request_to_join_received;
static GMFunction g_cb_ci_send_custom_native_invite_requested;
static GMFunction g_cb_ci_request_to_join_accepted;
static GMFunction g_cb_ci_request_to_join_rejected;

// ============================================================
// Notify callbacks
// ============================================================

static void EOS_CALL eos_ci_custom_invite_received_callback(
    const EOS_CustomInvites_OnCustomInviteReceivedCallbackInfo* data)
{
    if (!data || !g_cb_ci_custom_invite_received) return;
    gm_structs::EpicCustomInvitesCustomInviteReceivedCallbackInfo out{};
    out.target_user_id   = eos_product_user_id_to_string_internal(data->TargetUserId);
    out.local_user_id    = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.custom_invite_id = data->CustomInviteId ? std::string(data->CustomInviteId) : std::string();
    out.payload          = data->Payload ? std::string(data->Payload) : std::string();
    g_cb_ci_custom_invite_received.call(out);
}

static void EOS_CALL eos_ci_custom_invite_accepted_callback(
    const EOS_CustomInvites_OnCustomInviteAcceptedCallbackInfo* data)
{
    if (!data || !g_cb_ci_custom_invite_accepted) return;
    gm_structs::EpicCustomInvitesCustomInviteAcceptedCallbackInfo out{};
    out.target_user_id   = eos_product_user_id_to_string_internal(data->TargetUserId);
    out.local_user_id    = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.custom_invite_id = data->CustomInviteId ? std::string(data->CustomInviteId) : std::string();
    out.payload          = data->Payload ? std::string(data->Payload) : std::string();
    g_cb_ci_custom_invite_accepted.call(out);
}

static void EOS_CALL eos_ci_custom_invite_rejected_callback(
    const EOS_CustomInvites_CustomInviteRejectedCallbackInfo* data)
{
    if (!data || !g_cb_ci_custom_invite_rejected) return;
    gm_structs::EpicCustomInvitesCustomInviteRejectedCallbackInfo out{};
    out.target_user_id   = eos_product_user_id_to_string_internal(data->TargetUserId);
    out.local_user_id    = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.custom_invite_id = data->CustomInviteId ? std::string(data->CustomInviteId) : std::string();
    out.payload          = data->Payload ? std::string(data->Payload) : std::string();
    g_cb_ci_custom_invite_rejected.call(out);
}

static void EOS_CALL eos_ci_request_to_join_response_received_callback(
    const EOS_CustomInvites_RequestToJoinResponseReceivedCallbackInfo* data)
{
    if (!data || !g_cb_ci_request_to_join_response_received) return;
    gm_structs::EpicCustomInvitesRequestToJoinResponseReceivedCallbackInfo out{};
    out.from_user_id = eos_product_user_id_to_string_internal(data->FromUserId);
    out.to_user_id   = eos_product_user_id_to_string_internal(data->ToUserId);
    out.response     = (gm_enums::EpicRequestToJoinResponse)data->Response;
    g_cb_ci_request_to_join_response_received.call(out);
}

static void EOS_CALL eos_ci_request_to_join_received_callback(
    const EOS_CustomInvites_RequestToJoinReceivedCallbackInfo* data)
{
    if (!data || !g_cb_ci_request_to_join_received) return;
    gm_structs::EpicCustomInvitesRequestToJoinReceivedCallbackInfo out{};
    out.from_user_id = eos_product_user_id_to_string_internal(data->FromUserId);
    out.to_user_id   = eos_product_user_id_to_string_internal(data->ToUserId);
    g_cb_ci_request_to_join_received.call(out);
}

static void EOS_CALL eos_ci_send_custom_native_invite_requested_callback(
    const EOS_CustomInvites_SendCustomNativeInviteRequestedCallbackInfo* data)
{
    if (!data || !g_cb_ci_send_custom_native_invite_requested) return;
    gm_structs::EpicCustomInvitesSendCustomNativeInviteRequestedCallbackInfo out{};
    out.ui_event_id                   = (std::int64_t)data->UiEventId;
    out.local_user_id                 = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.target_native_account_type    = data->TargetNativeAccountType ? std::string(data->TargetNativeAccountType) : std::string();
    out.target_user_native_account_id = data->TargetUserNativeAccountId ? std::string(data->TargetUserNativeAccountId) : std::string();
    out.invite_id                     = data->InviteId ? std::string(data->InviteId) : std::string();
    g_cb_ci_send_custom_native_invite_requested.call(out);
}

static void EOS_CALL eos_ci_request_to_join_accepted_callback(
    const EOS_CustomInvites_OnRequestToJoinAcceptedCallbackInfo* data)
{
    if (!data || !g_cb_ci_request_to_join_accepted) return;
    gm_structs::EpicCustomInvitesRequestToJoinAcceptedCallbackInfo out{};
    out.target_user_id = eos_product_user_id_to_string_internal(data->TargetUserId);
    out.local_user_id  = eos_product_user_id_to_string_internal(data->LocalUserId);
    g_cb_ci_request_to_join_accepted.call(out);
}

static void EOS_CALL eos_ci_request_to_join_rejected_callback(
    const EOS_CustomInvites_OnRequestToJoinRejectedCallbackInfo* data)
{
    if (!data || !g_cb_ci_request_to_join_rejected) return;
    gm_structs::EpicCustomInvitesRequestToJoinRejectedCallbackInfo out{};
    out.target_user_id = eos_product_user_id_to_string_internal(data->TargetUserId);
    out.local_user_id  = eos_product_user_id_to_string_internal(data->LocalUserId);
    g_cb_ci_request_to_join_rejected.call(out);
}

// Async callbacks

static void EOS_CALL eos_ci_send_custom_invite_callback(
    const EOS_CustomInvites_SendCustomInviteCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;
    gm_structs::EpicCustomInvitesSendCustomInviteCallbackInfo out{};
    out.result_code   = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    ctx->callback.call(out);
    delete ctx;
}

static void EOS_CALL eos_ci_send_request_to_join_callback(
    const EOS_CustomInvites_SendRequestToJoinCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;
    gm_structs::EpicCustomInvitesSendRequestToJoinCallbackInfo out{};
    out.result_code    = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id  = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.target_user_id = eos_product_user_id_to_string_internal(data->TargetUserId);
    ctx->callback.call(out);
    delete ctx;
}

static void EOS_CALL eos_ci_accept_request_to_join_callback(
    const EOS_CustomInvites_AcceptRequestToJoinCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;
    gm_structs::EpicCustomInvitesAcceptRequestToJoinCallbackInfo out{};
    out.result_code    = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id  = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.target_user_id = eos_product_user_id_to_string_internal(data->TargetUserId);
    ctx->callback.call(out);
    delete ctx;
}

static void EOS_CALL eos_ci_reject_request_to_join_callback(
    const EOS_CustomInvites_RejectRequestToJoinCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;
    gm_structs::EpicCustomInvitesRejectRequestToJoinCallbackInfo out{};
    out.result_code    = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id  = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.target_user_id = eos_product_user_id_to_string_internal(data->TargetUserId);
    ctx->callback.call(out);
    delete ctx;
}

// ============================================================
// EOS Custom Invites — Core functions
// ============================================================

bool eos_custominvites_set_custom_invite(
    std::string_view local_user_id,
    std::string_view payload)
{
    EOS_GUARD_RET(false);

    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return false; }

    std::string pay(payload);

    EOS_CustomInvites_SetCustomInviteOptions opts{};
    opts.ApiVersion  = EOS_CUSTOMINVITES_SETCUSTOMINVITE_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.Payload     = pay.c_str();

    return EOS_CustomInvites_SetCustomInvite(ci, &opts) == EOS_EResult::EOS_Success;
}

void eos_custominvites_send_custom_invite(
    std::string_view local_user_id,
    const std::vector<std::string_view>& target_user_ids,
    const GMFunction& callback)
{
    EOS_GUARD();

    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return; }

    std::vector<EOS_ProductUserId> targets;
    targets.reserve(target_user_ids.size());
    for (const auto& id : target_user_ids)
        targets.push_back(eos_product_user_id_from_string_internal(id));

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_CustomInvites_SendCustomInviteOptions opts{};
    opts.ApiVersion          = EOS_CUSTOMINVITES_SENDCUSTOMINVITE_API_LATEST;
    opts.LocalUserId         = eos_product_user_id_from_string_internal(local_user_id);
    opts.TargetUserIds       = targets.empty() ? nullptr : targets.data();
    opts.TargetUserIdsCount  = (uint32_t)targets.size();

    EOS_CustomInvites_SendCustomInvite(ci, &opts, ctx, &eos_ci_send_custom_invite_callback);
}

bool eos_custominvites_finalize_invite(
    std::string_view target_user_id,
    std::string_view local_user_id,
    std::string_view custom_invite_id,
    gm_enums::EpicResult processing_result)
{
    EOS_GUARD_RET(false);

    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return false; }

    std::string invite_id(custom_invite_id);

    EOS_CustomInvites_FinalizeInviteOptions opts{};
    opts.ApiVersion       = EOS_CUSTOMINVITES_FINALIZEINVITE_API_LATEST;
    opts.TargetUserId     = eos_product_user_id_from_string_internal(target_user_id);
    opts.LocalUserId      = eos_product_user_id_from_string_internal(local_user_id);
    opts.CustomInviteId   = invite_id.c_str();
    opts.ProcessingResult = (EOS_EResult)(std::int64_t)processing_result;

    return EOS_CustomInvites_FinalizeInvite(ci, &opts) == EOS_EResult::EOS_Success;
}

void eos_custominvites_send_request_to_join(
    std::string_view local_user_id,
    std::string_view target_user_id,
    const GMFunction& callback)
{
    EOS_GUARD();

    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return; }

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_CustomInvites_SendRequestToJoinOptions opts{};
    opts.ApiVersion  = EOS_CUSTOMINVITES_SENDREQUESTTOJOIN_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.TargetUserId = eos_product_user_id_from_string_internal(target_user_id);

    EOS_CustomInvites_SendRequestToJoin(ci, &opts, ctx, &eos_ci_send_request_to_join_callback);
}

void eos_custominvites_accept_request_to_join(
    std::string_view local_user_id,
    std::string_view target_user_id,
    const GMFunction& callback)
{
    EOS_GUARD();

    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return; }

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_CustomInvites_AcceptRequestToJoinOptions opts{};
    opts.ApiVersion   = EOS_CUSTOMINVITES_ACCEPTREQUESTTOJOIN_API_LATEST;
    opts.LocalUserId  = eos_product_user_id_from_string_internal(local_user_id);
    opts.TargetUserId = eos_product_user_id_from_string_internal(target_user_id);

    EOS_CustomInvites_AcceptRequestToJoin(ci, &opts, ctx, &eos_ci_accept_request_to_join_callback);
}

void eos_custominvites_reject_request_to_join(
    std::string_view local_user_id,
    std::string_view target_user_id,
    const GMFunction& callback)
{
    EOS_GUARD();

    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return; }

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_CustomInvites_RejectRequestToJoinOptions opts{};
    opts.ApiVersion   = EOS_CUSTOMINVITES_REJECTREQUESTTOJOIN_API_LATEST;
    opts.LocalUserId  = eos_product_user_id_from_string_internal(local_user_id);
    opts.TargetUserId = eos_product_user_id_from_string_internal(target_user_id);

    EOS_CustomInvites_RejectRequestToJoin(ci, &opts, ctx, &eos_ci_reject_request_to_join_callback);
}

// ============================================================
// EOS Custom Invites — Notify add/remove
// ============================================================

std::uint64_t eos_custominvites_add_notify_custom_invite_received(const GMFunction& callback)
{
    eos_clear_last_error();
    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return 0; }
    g_cb_ci_custom_invite_received = callback;
    EOS_CustomInvites_AddNotifyCustomInviteReceivedOptions opts{};
    opts.ApiVersion = EOS_CUSTOMINVITES_ADDNOTIFYCUSTOMINVITERECEIVED_API_LATEST;
    return (std::uint64_t)EOS_CustomInvites_AddNotifyCustomInviteReceived(
        ci, &opts, nullptr, &eos_ci_custom_invite_received_callback);
}

void eos_custominvites_remove_notify_custom_invite_received(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return; }
    EOS_CustomInvites_RemoveNotifyCustomInviteReceived(ci, (EOS_NotificationId)notification_id);
}

std::uint64_t eos_custominvites_add_notify_custom_invite_accepted(const GMFunction& callback)
{
    eos_clear_last_error();
    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return 0; }
    g_cb_ci_custom_invite_accepted = callback;
    EOS_CustomInvites_AddNotifyCustomInviteAcceptedOptions opts{};
    opts.ApiVersion = EOS_CUSTOMINVITES_ADDNOTIFYCUSTOMINVITEACCEPTED_API_LATEST;
    return (std::uint64_t)EOS_CustomInvites_AddNotifyCustomInviteAccepted(
        ci, &opts, nullptr, &eos_ci_custom_invite_accepted_callback);
}

void eos_custominvites_remove_notify_custom_invite_accepted(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return; }
    EOS_CustomInvites_RemoveNotifyCustomInviteAccepted(ci, (EOS_NotificationId)notification_id);
}

std::uint64_t eos_custominvites_add_notify_custom_invite_rejected(const GMFunction& callback)
{
    eos_clear_last_error();
    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return 0; }
    g_cb_ci_custom_invite_rejected = callback;
    EOS_CustomInvites_AddNotifyCustomInviteRejectedOptions opts{};
    opts.ApiVersion = EOS_CUSTOMINVITES_ADDNOTIFYCUSTOMINVITEREJECTED_API_LATEST;
    return (std::uint64_t)EOS_CustomInvites_AddNotifyCustomInviteRejected(
        ci, &opts, nullptr, &eos_ci_custom_invite_rejected_callback);
}

void eos_custominvites_remove_notify_custom_invite_rejected(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return; }
    EOS_CustomInvites_RemoveNotifyCustomInviteRejected(ci, (EOS_NotificationId)notification_id);
}

std::uint64_t eos_custominvites_add_notify_request_to_join_response_received(const GMFunction& callback)
{
    eos_clear_last_error();
    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return 0; }
    g_cb_ci_request_to_join_response_received = callback;
    EOS_CustomInvites_AddNotifyRequestToJoinResponseReceivedOptions opts{};
    opts.ApiVersion = EOS_CUSTOMINVITES_ADDNOTIFYREQUESTTOJOINRESPONSERECEIVED_API_LATEST;
    return (std::uint64_t)EOS_CustomInvites_AddNotifyRequestToJoinResponseReceived(
        ci, &opts, nullptr, &eos_ci_request_to_join_response_received_callback);
}

void eos_custominvites_remove_notify_request_to_join_response_received(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return; }
    EOS_CustomInvites_RemoveNotifyRequestToJoinResponseReceived(ci, (EOS_NotificationId)notification_id);
}

std::uint64_t eos_custominvites_add_notify_request_to_join_received(const GMFunction& callback)
{
    eos_clear_last_error();
    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return 0; }
    g_cb_ci_request_to_join_received = callback;
    EOS_CustomInvites_AddNotifyRequestToJoinReceivedOptions opts{};
    opts.ApiVersion = EOS_CUSTOMINVITES_ADDNOTIFYREQUESTTOJOINRECEIVED_API_LATEST;
    return (std::uint64_t)EOS_CustomInvites_AddNotifyRequestToJoinReceived(
        ci, &opts, nullptr, &eos_ci_request_to_join_received_callback);
}

void eos_custominvites_remove_notify_request_to_join_received(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return; }
    EOS_CustomInvites_RemoveNotifyRequestToJoinReceived(ci, (EOS_NotificationId)notification_id);
}

std::uint64_t eos_custominvites_add_notify_send_custom_native_invite_requested(const GMFunction& callback)
{
    eos_clear_last_error();
    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return 0; }
    g_cb_ci_send_custom_native_invite_requested = callback;
    EOS_CustomInvites_AddNotifySendCustomNativeInviteRequestedOptions opts{};
    opts.ApiVersion = EOS_CUSTOMINVITES_ADDNOTIFYSENDCUSTOMNATIVEINVITEREQUESTED_API_LATEST;
    return (std::uint64_t)EOS_CustomInvites_AddNotifySendCustomNativeInviteRequested(
        ci, &opts, nullptr, &eos_ci_send_custom_native_invite_requested_callback);
}

void eos_custominvites_remove_notify_send_custom_native_invite_requested(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return; }
    EOS_CustomInvites_RemoveNotifySendCustomNativeInviteRequested(ci, (EOS_NotificationId)notification_id);
}

std::uint64_t eos_custominvites_add_notify_request_to_join_accepted(const GMFunction& callback)
{
    eos_clear_last_error();
    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return 0; }
    g_cb_ci_request_to_join_accepted = callback;
    EOS_CustomInvites_AddNotifyRequestToJoinAcceptedOptions opts{};
    opts.ApiVersion = EOS_CUSTOMINVITES_ADDNOTIFYREQUESTTOJOINACCEPTED_API_LATEST;
    return (std::uint64_t)EOS_CustomInvites_AddNotifyRequestToJoinAccepted(
        ci, &opts, nullptr, &eos_ci_request_to_join_accepted_callback);
}

void eos_custominvites_remove_notify_request_to_join_accepted(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return; }
    EOS_CustomInvites_RemoveNotifyRequestToJoinAccepted(ci, (EOS_NotificationId)notification_id);
}

std::uint64_t eos_custominvites_add_notify_request_to_join_rejected(const GMFunction& callback)
{
    eos_clear_last_error();
    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return 0; }
    g_cb_ci_request_to_join_rejected = callback;
    EOS_CustomInvites_AddNotifyRequestToJoinRejectedOptions opts{};
    opts.ApiVersion = EOS_CUSTOMINVITES_ADDNOTIFYREQUESTTOJOINREJECTED_API_LATEST;
    return (std::uint64_t)EOS_CustomInvites_AddNotifyRequestToJoinRejected(
        ci, &opts, nullptr, &eos_ci_request_to_join_rejected_callback);
}

void eos_custominvites_remove_notify_request_to_join_rejected(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HCustomInvites ci = eos_ci_iface();
    if (!ci) { eos_set_last_error("EOS CustomInvites interface unavailable."); return; }
    EOS_CustomInvites_RemoveNotifyRequestToJoinRejected(ci, (EOS_NotificationId)notification_id);
}
