#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_rtc.h>
#include <eos_rtc_data.h>

#include <cstdint>
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

// ---- Base64 encode (for binary data delivered via callback) ----

static const char k_b64_chars[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static std::string base64_encode(const void* data, size_t len)
{
    const auto* src = static_cast<const uint8_t*>(data);
    std::string out;
    out.reserve(((len + 2) / 3) * 4);
    for (size_t i = 0; i < len; i += 3) {
        uint32_t b = (uint32_t)src[i] << 16;
        if (i + 1 < len) b |= (uint32_t)src[i + 1] << 8;
        if (i + 2 < len) b |= src[i + 2];
        out += k_b64_chars[(b >> 18) & 0x3f];
        out += k_b64_chars[(b >> 12) & 0x3f];
        out += (i + 1 < len) ? k_b64_chars[(b >> 6) & 0x3f] : '=';
        out += (i + 2 < len) ? k_b64_chars[b & 0x3f] : '=';
    }
    return out;
}

// ============================================================
// Notify globals — RTC data
// ============================================================

static GMFunction g_cb_rtc_data_received;
static GMFunction g_cb_rtc_data_participant_updated;

// ============================================================
// Native callbacks
// ============================================================

static void EOS_CALL eos_rtc_data_received_callback_native(
    const EOS_RTCData_DataReceivedCallbackInfo* data)
{
    if (!data || !g_cb_rtc_data_received) return;

    gm_structs::EpicRTCDataReceivedCallbackInfo out{};
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name = data->RoomName ? std::string(data->RoomName) : std::string();
    out.participant_id = eos_product_user_id_to_string_internal(data->ParticipantId);
    out.data_length_bytes = (int64_t)data->DataLengthBytes;
    if (data->Data && data->DataLengthBytes > 0)
        out.data = base64_encode(data->Data, (size_t)data->DataLengthBytes);

    g_cb_rtc_data_received.call(out);
}

static void EOS_CALL eos_rtc_data_participant_updated_callback_native(
    const EOS_RTCData_ParticipantUpdatedCallbackInfo* data)
{
    if (!data || !g_cb_rtc_data_participant_updated) return;

    gm_structs::EpicRTCDataParticipantUpdatedCallbackInfo out{};
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name = data->RoomName ? std::string(data->RoomName) : std::string();
    out.participant_id = eos_product_user_id_to_string_internal(data->ParticipantId);
    out.data_status = (gm_enums::EpicRTCDataStatus)data->DataStatus;

    g_cb_rtc_data_participant_updated.call(out);
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

    // Empty participant_id means "global" — pass nullptr per SDK contract.
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

    g_cb_rtc_data_received = callback.value_or(GMFunction{});

    EOS_RTCData_AddNotifyDataReceivedOptions opts{};
    opts.ApiVersion = EOS_RTCDATA_ADDNOTIFYDATARECEIVED_API_LATEST;
    opts.LocalUserId = local_user;
    opts.RoomName = room_name_storage.c_str();

    return (uint64_t)EOS_RTCData_AddNotifyDataReceived(
        rtc_data,
        &opts,
        nullptr,
        &eos_rtc_data_received_callback_native
    );
}

void eos_rtc_data_remove_notify_data_received(std::uint64_t notification_id)
{
    EOS_GUARD();

    EOS_HRTCData rtc_data = eos_rtc_data_iface();
    if (!rtc_data) { eos_set_last_error("EOS RTCData interface unavailable."); return; }

    EOS_RTCData_RemoveNotifyDataReceived(rtc_data, (EOS_NotificationId)notification_id);
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

    g_cb_rtc_data_participant_updated = callback.value_or(GMFunction{});

    EOS_RTCData_AddNotifyParticipantUpdatedOptions opts{};
    opts.ApiVersion = EOS_RTCDATA_ADDNOTIFYPARTICIPANTUPDATED_API_LATEST;
    opts.LocalUserId = local_user;
    opts.RoomName = room_name_storage.c_str();

    return (uint64_t)EOS_RTCData_AddNotifyParticipantUpdated(
        rtc_data,
        &opts,
        nullptr,
        &eos_rtc_data_participant_updated_callback_native
    );
}

void eos_rtc_data_remove_notify_participant_updated(std::uint64_t notification_id)
{
    EOS_GUARD();

    EOS_HRTCData rtc_data = eos_rtc_data_iface();
    if (!rtc_data) { eos_set_last_error("EOS RTCData interface unavailable."); return; }

    EOS_RTCData_RemoveNotifyParticipantUpdated(rtc_data, (EOS_NotificationId)notification_id);
}
