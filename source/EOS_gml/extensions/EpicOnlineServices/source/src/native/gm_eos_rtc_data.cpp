#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_rtc.h>
#include <eos_rtc_data.h>

#include <atomic>
#include <cstdint>
#include <cstring>
#include <mutex>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>
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

static EOS_HRTC eos_rtc_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetRTCInterface(p) : nullptr;
}

static EOS_HRTCData eos_rtc_data_iface()
{
    EOS_HRTC rtc = eos_rtc_iface();
    return rtc ? EOS_RTC_GetDataInterface(rtc) : nullptr;
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
// Notify callback storage - id-keyed, one heap ctx per registration
// (see gm_eos_p2p.cpp for the reference pattern this follows)
// ============================================================

struct EOSNotifyCallbackContext
{
    GMFunction callback;
};

// DataReceived also holds the most recent unfetched packet for its registration, keyed by a
// fresh handle issued on every firing (not the registration's notification_id - a registration
// can deliver different participants back-to-back, so reusing notification_id as the fetch key
// could let a fetch silently return a different participant's bytes than the metadata it was
// paired with). A new firing supersedes any previous unfetched packet for the same registration.
struct EOSDataBufferNotifyContext
{
    GMFunction callback;
    uint64_t pending_handle = 0;
    std::vector<uint8_t> pending_data;
};

static std::mutex g_notify_mutex;
static std::atomic<uint64_t> g_rtc_data_received_handle_counter{1};

static std::unordered_map<uint64_t, EOSDataBufferNotifyContext*> g_rtc_data_received_callbacks;
static std::unordered_map<uint64_t, EOSNotifyCallbackContext*> g_rtc_data_participant_updated_callbacks;

// ============================================================
// Native callbacks
// ============================================================

static void EOS_CALL eos_rtc_data_received_callback_native(
    const EOS_RTCData_DataReceivedCallbackInfo* data)
{
    if (!data) return;

    GMFunction cb;
    uint64_t handle = 0;
    {
        std::lock_guard<std::mutex> lock(g_notify_mutex);
        auto* ctx = static_cast<EOSDataBufferNotifyContext*>(data->ClientData);
        if (!ctx || !ctx->callback) return;
        cb = ctx->callback;

        // Supersede any previous unfetched packet for this registration.
        if (data->Data && data->DataLengthBytes > 0) {
            const auto* bytes = static_cast<const uint8_t*>(data->Data);
            ctx->pending_data.assign(bytes, bytes + data->DataLengthBytes);
            handle = g_rtc_data_received_handle_counter.fetch_add(1, std::memory_order_relaxed);
            ctx->pending_handle = handle;
        } else {
            ctx->pending_data.clear();
            ctx->pending_handle = 0;
        }
    }

    gm_structs::EpicRTCDataReceivedCallbackInfo out{};
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name = data->RoomName ? std::string(data->RoomName) : std::string();
    out.participant_id = eos_product_user_id_to_string_internal(data->ParticipantId);
    out.data_length_bytes = (int64_t)data->DataLengthBytes;
    out.handle_id = handle;

    cb.call(out);
}

static void EOS_CALL eos_rtc_data_participant_updated_callback_native(
    const EOS_RTCData_ParticipantUpdatedCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSNotifyCallbackContext*>(data->ClientData);
    if (!ctx || !ctx->callback) return;

    gm_structs::EpicRTCDataParticipantUpdatedCallbackInfo out{};
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name = data->RoomName ? std::string(data->RoomName) : std::string();
    out.participant_id = eos_product_user_id_to_string_internal(data->ParticipantId);
    out.data_status = (gm_enums::EpicRTCDataStatus)data->DataStatus;

    ctx->callback.call(out);
}

static void EOS_CALL eos_rtc_data_update_sending_callback_native(
    const EOS_RTCData_UpdateSendingCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicRTCDataUpdateSendingCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name = data->RoomName ? std::string(data->RoomName) : std::string();
    out.data_enabled = (data->bDataEnabled != 0);
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

static void EOS_CALL eos_rtc_data_update_receiving_callback_native(
    const EOS_RTCData_UpdateReceivingCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicRTCDataUpdateReceivingCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name = data->RoomName ? std::string(data->RoomName) : std::string();
    out.participant_id = eos_product_user_id_to_string_internal(data->ParticipantId);
    out.data_enabled = (data->bDataEnabled != 0);
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

// ============================================================
// Functions
// ============================================================

gm_enums::EpicResult eos_rtc_data_send_data(
    std::string_view local_user_id,
    std::string_view room_name,
    gm::wire::GMBuffer data,
    std::uint32_t bytes)
{
    EOS_GUARD_RET((gm_enums::EpicResult)EOS_EResult::EOS_InvalidState);

    EOS_HRTCData rtc_data = eos_rtc_data_iface();
    if (!rtc_data) {
        eos_set_last_error("EOS RTCData interface unavailable.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidState;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    std::string room_name_storage(room_name);
    if (!local_user || room_name_storage.empty()) {
        eos_set_last_error("EOS_RTCData_SendData: invalid parameters.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    if (bytes > EOS_RTCDATA_MAX_PACKET_SIZE) {
        eos_set_last_error("EOS_RTCData_SendData: bytes exceeds EOS_RTCDATA_MAX_PACKET_SIZE.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_RTCData_SendDataOptions opts{};
    opts.ApiVersion = EOS_RTCDATA_SENDDATA_API_LATEST;
    opts.LocalUserId = local_user;
    opts.RoomName = room_name_storage.c_str();
    opts.DataLengthBytes = bytes;
    opts.Data = (const void*)data.data();

    EOS_EResult result = EOS_RTCData_SendData(rtc_data, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_RTCData_SendData failed.");
    }
    return (gm_enums::EpicResult)result;
}

void eos_rtc_data_update_sending(
    std::string_view local_user_id,
    std::string_view room_name,
    bool data_enabled,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HRTCData rtc_data = eos_rtc_data_iface();
    if (!rtc_data) { eos_set_last_error("EOS RTCData interface unavailable."); return; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    std::string room_name_storage(room_name);
    if (!local_user || room_name_storage.empty()) {
        eos_set_last_error("EOS_RTCData_UpdateSending: invalid parameters.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_RTCData_UpdateSendingOptions opts{};
    opts.ApiVersion = EOS_RTCDATA_UPDATESENDING_API_LATEST;
    opts.LocalUserId = local_user;
    opts.RoomName = room_name_storage.c_str();
    opts.bDataEnabled = data_enabled ? EOS_TRUE : EOS_FALSE;

    EOS_RTCData_UpdateSending(rtc_data, &opts, ctx, &eos_rtc_data_update_sending_callback_native);
}

void eos_rtc_data_update_receiving(
    std::string_view local_user_id,
    std::string_view room_name,
    std::string_view participant_id,
    bool data_enabled,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HRTCData rtc_data = eos_rtc_data_iface();
    if (!rtc_data) { eos_set_last_error("EOS RTCData interface unavailable."); return; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    std::string room_name_storage(room_name);
    if (!local_user || room_name_storage.empty()) {
        eos_set_last_error("EOS_RTCData_UpdateReceiving: invalid parameters.");
        return;
    }

    // Empty participant_id means "global" - pass nullptr per SDK contract.
    EOS_ProductUserId participant = eos_product_user_id_from_string_internal(participant_id);

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_RTCData_UpdateReceivingOptions opts{};
    opts.ApiVersion = EOS_RTCDATA_UPDATERECEIVING_API_LATEST;
    opts.LocalUserId = local_user;
    opts.RoomName = room_name_storage.c_str();
    opts.ParticipantId = participant; // nullptr == all participants (global)
    opts.bDataEnabled = data_enabled ? EOS_TRUE : EOS_FALSE;

    EOS_RTCData_UpdateReceiving(rtc_data, &opts, ctx, &eos_rtc_data_update_receiving_callback_native);
}

std::uint64_t eos_rtc_data_add_notify_data_received(
    std::string_view local_user_id,
    std::string_view room_name,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD_RET(0);

    EOS_HRTCData rtc_data = eos_rtc_data_iface();
    if (!rtc_data) { eos_set_last_error("EOS RTCData interface unavailable."); return 0; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    std::string room_name_storage(room_name);
    if (!local_user || room_name_storage.empty()) {
        eos_set_last_error("EOS_RTCData_AddNotifyDataReceived: invalid parameters.");
        return 0;
    }

    auto* ctx = new EOSDataBufferNotifyContext();
    ctx->callback = callback.value_or(GMFunction{});

    EOS_RTCData_AddNotifyDataReceivedOptions opts{};
    opts.ApiVersion = EOS_RTCDATA_ADDNOTIFYDATARECEIVED_API_LATEST;
    opts.LocalUserId = local_user;
    opts.RoomName = room_name_storage.c_str();

    EOS_NotificationId id = EOS_RTCData_AddNotifyDataReceived(
        rtc_data, &opts, ctx, &eos_rtc_data_received_callback_native);

    if (id == EOS_INVALID_NOTIFICATIONID) {
        delete ctx;
        eos_set_last_error("EOS_RTCData_AddNotifyDataReceived returned invalid ID.");
        return 0;
    }

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    g_rtc_data_received_callbacks[(uint64_t)id] = ctx;
    return (uint64_t)id;
}

void eos_rtc_data_remove_notify_data_received(std::uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HRTCData rtc_data = eos_rtc_data_iface();
    if (rtc_data) EOS_RTCData_RemoveNotifyDataReceived(rtc_data, (EOS_NotificationId)notification_id);

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    auto it = g_rtc_data_received_callbacks.find(notification_id);
    if (it != g_rtc_data_received_callbacks.end()) {
        delete it->second;
        g_rtc_data_received_callbacks.erase(it);
    }
}

bool eos_rtc_data_received_data_fetch(std::uint64_t handle_id, gm::wire::GMBuffer out_buffer)
{
    eos_clear_last_error();
    if (handle_id == 0) {
        eos_set_last_error("EOS_RTCData_ReceivedDataFetch: invalid handle_id.");
        return false;
    }

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    for (auto& [id, ctx] : g_rtc_data_received_callbacks) {
        if (ctx->pending_handle != handle_id) continue;

        size_t byte_count = ctx->pending_data.size();
        if (out_buffer.length() < byte_count) {
            eos_set_last_error("EOS_RTCData_ReceivedDataFetch: out_buffer is too small.");
            return false;
        }
        if (byte_count > 0)
            std::memcpy(out_buffer.data(), ctx->pending_data.data(), byte_count);
        ctx->pending_data.clear();
        ctx->pending_handle = 0;
        return true;
    }

    eos_set_last_error("EOS_RTCData_ReceivedDataFetch: handle not found or already fetched.");
    return false;
}

std::uint64_t eos_rtc_data_add_notify_participant_updated(
    std::string_view local_user_id,
    std::string_view room_name,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD_RET(0);

    EOS_HRTCData rtc_data = eos_rtc_data_iface();
    if (!rtc_data) { eos_set_last_error("EOS RTCData interface unavailable."); return 0; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    std::string room_name_storage(room_name);
    if (!local_user || room_name_storage.empty()) {
        eos_set_last_error("EOS_RTCData_AddNotifyParticipantUpdated: invalid parameters.");
        return 0;
    }

    auto* ctx = new EOSNotifyCallbackContext{callback.value_or(GMFunction{})};

    EOS_RTCData_AddNotifyParticipantUpdatedOptions opts{};
    opts.ApiVersion = EOS_RTCDATA_ADDNOTIFYPARTICIPANTUPDATED_API_LATEST;
    opts.LocalUserId = local_user;
    opts.RoomName = room_name_storage.c_str();

    EOS_NotificationId id = EOS_RTCData_AddNotifyParticipantUpdated(
        rtc_data, &opts, ctx, &eos_rtc_data_participant_updated_callback_native);

    if (id == EOS_INVALID_NOTIFICATIONID) {
        delete ctx;
        eos_set_last_error("EOS_RTCData_AddNotifyParticipantUpdated returned invalid ID.");
        return 0;
    }

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    g_rtc_data_participant_updated_callbacks[(uint64_t)id] = ctx;
    return (uint64_t)id;
}

void eos_rtc_data_remove_notify_participant_updated(std::uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HRTCData rtc_data = eos_rtc_data_iface();
    if (rtc_data) EOS_RTCData_RemoveNotifyParticipantUpdated(rtc_data, (EOS_NotificationId)notification_id);

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    auto it = g_rtc_data_participant_updated_callbacks.find(notification_id);
    if (it != g_rtc_data_participant_updated_callbacks.end()) {
        delete it->second;
        g_rtc_data_participant_updated_callbacks.erase(it);
    }
}
