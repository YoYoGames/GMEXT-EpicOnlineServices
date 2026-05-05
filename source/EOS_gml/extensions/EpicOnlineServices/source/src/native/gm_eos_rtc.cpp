#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_rtc.h>
#include <eos_rtc_audio.h>

#include <string>
#include <string_view>

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

static EOS_HRTC eos_rtc_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetRTCInterface(p) : nullptr;
}

static EOS_HRTCAudio eos_rtc_audio_iface()
{
    EOS_HRTC rtc = eos_rtc_iface();
    return rtc ? EOS_RTC_GetAudioInterface(rtc) : nullptr;
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
// Notify globals — RTC core
// ============================================================

static GMFunction g_cb_rtc_disconnected;
static GMFunction g_cb_rtc_participant_status_changed;
static GMFunction g_cb_rtc_room_statistics_updated;

// Notify globals — RTC audio
static GMFunction g_cb_rtc_audio_participant_updated;
static GMFunction g_cb_rtc_audio_devices_changed;
static GMFunction g_cb_rtc_audio_input_state;
static GMFunction g_cb_rtc_audio_output_state;

// ============================================================
// RTC core notify callbacks
// ============================================================

static void EOS_CALL eos_rtc_disconnected_callback(
    const EOS_RTC_DisconnectedCallbackInfo* data)
{
    if (!data || !g_cb_rtc_disconnected) return;
    gm_structs::EpicRTCDisconnectedCallbackInfo out{};
    out.result_code   = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name     = data->RoomName ? std::string(data->RoomName) : std::string();
    g_cb_rtc_disconnected.call(out);
}

static void EOS_CALL eos_rtc_participant_status_changed_callback(
    const EOS_RTC_ParticipantStatusChangedCallbackInfo* data)
{
    if (!data || !g_cb_rtc_participant_status_changed) return;
    gm_structs::EpicRTCParticipantStatusChangedCallbackInfo out{};
    out.local_user_id          = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name              = data->RoomName ? std::string(data->RoomName) : std::string();
    out.participant_id         = eos_product_user_id_to_string_internal(data->ParticipantId);
    out.participant_status     = (gm_enums::EpicRTCParticipantStatus)data->ParticipantStatus;
    out.participant_in_blocklist = (bool)data->bParticipantInBlocklist;
    g_cb_rtc_participant_status_changed.call(out);
}

static void EOS_CALL eos_rtc_room_statistics_updated_callback(
    const EOS_RTC_RoomStatisticsUpdatedInfo* data)
{
    if (!data || !g_cb_rtc_room_statistics_updated) return;
    gm_structs::EpicRTCRoomStatisticsUpdatedInfo out{};
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name     = data->RoomName ? std::string(data->RoomName) : std::string();
    out.statistic     = data->Statistic ? std::string(data->Statistic) : std::string();
    g_cb_rtc_room_statistics_updated.call(out);
}

// ============================================================
// RTC core async callbacks
// ============================================================

static void EOS_CALL eos_rtc_join_room_callback(
    const EOS_RTC_JoinRoomCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;
    gm_structs::EpicRTCJoinRoomCallbackInfo out{};
    out.result_code   = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name     = data->RoomName ? std::string(data->RoomName) : std::string();
    ctx->callback.call(out);
    delete ctx;
}

static void EOS_CALL eos_rtc_leave_room_callback(
    const EOS_RTC_LeaveRoomCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;
    gm_structs::EpicRTCLeaveRoomCallbackInfo out{};
    out.result_code   = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name     = data->RoomName ? std::string(data->RoomName) : std::string();
    ctx->callback.call(out);
    delete ctx;
}

static void EOS_CALL eos_rtc_block_participant_callback(
    const EOS_RTC_BlockParticipantCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;
    gm_structs::EpicRTCBlockParticipantCallbackInfo out{};
    out.result_code    = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id  = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name      = data->RoomName ? std::string(data->RoomName) : std::string();
    out.participant_id = eos_product_user_id_to_string_internal(data->ParticipantId);
    out.blocked        = (bool)data->bBlocked;
    ctx->callback.call(out);
    delete ctx;
}

// ============================================================
// RTC audio notify callbacks
// ============================================================

static void EOS_CALL eos_rtc_audio_participant_updated_callback(
    const EOS_RTCAudio_ParticipantUpdatedCallbackInfo* data)
{
    if (!data || !g_cb_rtc_audio_participant_updated) return;
    gm_structs::EpicRTCAudioParticipantUpdatedCallbackInfo out{};
    out.local_user_id  = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name      = data->RoomName ? std::string(data->RoomName) : std::string();
    out.participant_id = eos_product_user_id_to_string_internal(data->ParticipantId);
    out.speaking       = (bool)data->bSpeaking;
    out.audio_status   = (gm_enums::EpicRTCAudioStatus)data->AudioStatus;
    g_cb_rtc_audio_participant_updated.call(out);
}

static void EOS_CALL eos_rtc_audio_devices_changed_callback(
    const EOS_RTCAudio_AudioDevicesChangedCallbackInfo* data)
{
    if (!data || !g_cb_rtc_audio_devices_changed) return;
    gm_structs::EpicRTCAudioDevicesChangedCallbackInfo out{};
    out.triggered = true;
    g_cb_rtc_audio_devices_changed.call(out);
}

static void EOS_CALL eos_rtc_audio_input_state_callback(
    const EOS_RTCAudio_AudioInputStateCallbackInfo* data)
{
    if (!data || !g_cb_rtc_audio_input_state) return;
    gm_structs::EpicRTCAudioInputStateCallbackInfo out{};
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name     = data->RoomName ? std::string(data->RoomName) : std::string();
    out.status        = (gm_enums::EpicRTCAudioInputStatus)data->Status;
    g_cb_rtc_audio_input_state.call(out);
}

static void EOS_CALL eos_rtc_audio_output_state_callback(
    const EOS_RTCAudio_AudioOutputStateCallbackInfo* data)
{
    if (!data || !g_cb_rtc_audio_output_state) return;
    gm_structs::EpicRTCAudioOutputStateCallbackInfo out{};
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name     = data->RoomName ? std::string(data->RoomName) : std::string();
    out.status        = (gm_enums::EpicRTCAudioOutputStatus)data->Status;
    g_cb_rtc_audio_output_state.call(out);
}

// ============================================================
// RTC audio async callbacks
// ============================================================

static void EOS_CALL eos_rtc_audio_update_sending_callback(
    const EOS_RTCAudio_UpdateSendingCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;
    gm_structs::EpicRTCAudioUpdateSendingCallbackInfo out{};
    out.result_code   = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name     = data->RoomName ? std::string(data->RoomName) : std::string();
    out.audio_status  = (gm_enums::EpicRTCAudioStatus)data->AudioStatus;
    ctx->callback.call(out);
    delete ctx;
}

static void EOS_CALL eos_rtc_audio_update_receiving_callback(
    const EOS_RTCAudio_UpdateReceivingCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;
    gm_structs::EpicRTCAudioUpdateReceivingCallbackInfo out{};
    out.result_code    = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id  = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name      = data->RoomName ? std::string(data->RoomName) : std::string();
    out.participant_id = eos_product_user_id_to_string_internal(data->ParticipantId);
    out.audio_enabled  = (bool)data->bAudioEnabled;
    ctx->callback.call(out);
    delete ctx;
}

static void EOS_CALL eos_rtc_audio_update_sending_volume_callback(
    const EOS_RTCAudio_UpdateSendingVolumeCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;
    gm_structs::EpicRTCAudioUpdateSendingVolumeCallbackInfo out{};
    out.result_code   = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name     = data->RoomName ? std::string(data->RoomName) : std::string();
    out.volume        = (double)data->Volume;
    ctx->callback.call(out);
    delete ctx;
}

static void EOS_CALL eos_rtc_audio_update_receiving_volume_callback(
    const EOS_RTCAudio_UpdateReceivingVolumeCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;
    gm_structs::EpicRTCAudioUpdateReceivingVolumeCallbackInfo out{};
    out.result_code   = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name     = data->RoomName ? std::string(data->RoomName) : std::string();
    out.volume        = (double)data->Volume;
    ctx->callback.call(out);
    delete ctx;
}

static void EOS_CALL eos_rtc_audio_update_participant_volume_callback(
    const EOS_RTCAudio_UpdateParticipantVolumeCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;
    gm_structs::EpicRTCAudioUpdateParticipantVolumeCallbackInfo out{};
    out.result_code    = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id  = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name      = data->RoomName ? std::string(data->RoomName) : std::string();
    out.participant_id = eos_product_user_id_to_string_internal(data->ParticipantId);
    out.volume         = (double)data->Volume;
    ctx->callback.call(out);
    delete ctx;
}

static void EOS_CALL eos_rtc_audio_query_input_devices_callback(
    const EOS_RTCAudio_OnQueryInputDevicesInformationCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;
    gm_structs::EpicRTCAudioQueryInputDevicesCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    ctx->callback.call(out);
    delete ctx;
}

static void EOS_CALL eos_rtc_audio_query_output_devices_callback(
    const EOS_RTCAudio_OnQueryOutputDevicesInformationCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;
    gm_structs::EpicRTCAudioQueryOutputDevicesCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    ctx->callback.call(out);
    delete ctx;
}

static void EOS_CALL eos_rtc_audio_set_input_device_settings_callback(
    const EOS_RTCAudio_OnSetInputDeviceSettingsCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;
    gm_structs::EpicRTCAudioSetInputDeviceSettingsCallbackInfo out{};
    out.result_code    = (gm_enums::EpicResult)data->ResultCode;
    out.real_device_id = data->RealDeviceId ? std::string(data->RealDeviceId) : std::string();
    ctx->callback.call(out);
    delete ctx;
}

static void EOS_CALL eos_rtc_audio_set_output_device_settings_callback(
    const EOS_RTCAudio_OnSetOutputDeviceSettingsCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;
    gm_structs::EpicRTCAudioSetOutputDeviceSettingsCallbackInfo out{};
    out.result_code    = (gm_enums::EpicResult)data->ResultCode;
    out.real_device_id = data->RealDeviceId ? std::string(data->RealDeviceId) : std::string();
    ctx->callback.call(out);
    delete ctx;
}

// ============================================================
// EOS RTC core — Functions
// ============================================================

void eos_rtc_join_room(
    std::string_view local_user_id,
    std::string_view room_name,
    std::string_view client_base_url,
    std::string_view participant_token,
    const GMFunction& callback)
{
    EOS_GUARD();

    EOS_HRTC rtc = eos_rtc_iface();
    if (!rtc) { eos_set_last_error("EOS RTC interface unavailable."); return; }

    std::string rn(room_name);
    std::string cbu(client_base_url);
    std::string pt(participant_token);

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_RTC_JoinRoomOptions opts{};
    opts.ApiVersion              = EOS_RTC_JOINROOM_API_LATEST;
    opts.LocalUserId             = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName                = rn.c_str();
    opts.ClientBaseUrl           = cbu.c_str();
    opts.ParticipantToken        = pt.c_str();
    opts.ParticipantId           = nullptr;
    opts.Flags                   = 0;
    opts.bManualAudioInputEnabled  = EOS_FALSE;
    opts.bManualAudioOutputEnabled = EOS_FALSE;

    EOS_RTC_JoinRoom(rtc, &opts, ctx, &eos_rtc_join_room_callback);
}

void eos_rtc_leave_room(
    std::string_view local_user_id,
    std::string_view room_name,
    const GMFunction& callback)
{
    EOS_GUARD();

    EOS_HRTC rtc = eos_rtc_iface();
    if (!rtc) { eos_set_last_error("EOS RTC interface unavailable."); return; }

    std::string rn(room_name);

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_RTC_LeaveRoomOptions opts{};
    opts.ApiVersion  = EOS_RTC_LEAVEROOM_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName    = rn.c_str();

    EOS_RTC_LeaveRoom(rtc, &opts, ctx, &eos_rtc_leave_room_callback);
}

void eos_rtc_block_participant(
    std::string_view local_user_id,
    std::string_view room_name,
    std::string_view participant_id,
    bool blocked,
    const GMFunction& callback)
{
    EOS_GUARD();

    EOS_HRTC rtc = eos_rtc_iface();
    if (!rtc) { eos_set_last_error("EOS RTC interface unavailable."); return; }

    std::string rn(room_name);

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_RTC_BlockParticipantOptions opts{};
    opts.ApiVersion    = EOS_RTC_BLOCKPARTICIPANT_API_LATEST;
    opts.LocalUserId   = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName      = rn.c_str();
    opts.ParticipantId = eos_product_user_id_from_string_internal(participant_id);
    opts.bBlocked      = blocked ? EOS_TRUE : EOS_FALSE;

    EOS_RTC_BlockParticipant(rtc, &opts, ctx, &eos_rtc_block_participant_callback);
}

bool eos_rtc_set_setting(
    std::string_view setting_name,
    std::string_view setting_value)
{
    EOS_GUARD_RET(false);

    EOS_HRTC rtc = eos_rtc_iface();
    if (!rtc) { eos_set_last_error("EOS RTC interface unavailable."); return false; }

    std::string sn(setting_name);
    std::string sv(setting_value);

    EOS_RTC_SetSettingOptions opts{};
    opts.ApiVersion   = EOS_RTC_SETSETTING_API_LATEST;
    opts.SettingName  = sn.c_str();
    opts.SettingValue = sv.c_str();

    return EOS_RTC_SetSetting(rtc, &opts) == EOS_EResult::EOS_Success;
}

bool eos_rtc_set_room_setting(
    std::string_view local_user_id,
    std::string_view room_name,
    std::string_view setting_name,
    std::string_view setting_value)
{
    EOS_GUARD_RET(false);

    EOS_HRTC rtc = eos_rtc_iface();
    if (!rtc) { eos_set_last_error("EOS RTC interface unavailable."); return false; }

    std::string rn(room_name);
    std::string sn(setting_name);
    std::string sv(setting_value);

    EOS_RTC_SetRoomSettingOptions opts{};
    opts.ApiVersion   = EOS_RTC_SETROOMSETTING_API_LATEST;
    opts.LocalUserId  = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName     = rn.c_str();
    opts.SettingName  = sn.c_str();
    opts.SettingValue = sv.c_str();

    return EOS_RTC_SetRoomSetting(rtc, &opts) == EOS_EResult::EOS_Success;
}

// ============================================================
// EOS RTC core — Notify add/remove
// ============================================================

std::uint64_t eos_rtc_add_notify_disconnected(
    std::string_view local_user_id,
    std::string_view room_name,
    const GMFunction& callback)
{
    eos_clear_last_error();
    EOS_HRTC rtc = eos_rtc_iface();
    if (!rtc) { eos_set_last_error("EOS RTC interface unavailable."); return 0; }

    std::string rn(room_name);
    g_cb_rtc_disconnected = callback;

    EOS_RTC_AddNotifyDisconnectedOptions opts{};
    opts.ApiVersion  = EOS_RTC_ADDNOTIFYDISCONNECTED_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName    = rn.c_str();

    return (std::uint64_t)EOS_RTC_AddNotifyDisconnected(
        rtc, &opts, nullptr, &eos_rtc_disconnected_callback);
}

void eos_rtc_remove_notify_disconnected(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HRTC rtc = eos_rtc_iface();
    if (!rtc) { eos_set_last_error("EOS RTC interface unavailable."); return; }
    EOS_RTC_RemoveNotifyDisconnected(rtc, (EOS_NotificationId)notification_id);
}

std::uint64_t eos_rtc_add_notify_participant_status_changed(
    std::string_view local_user_id,
    std::string_view room_name,
    const GMFunction& callback)
{
    eos_clear_last_error();
    EOS_HRTC rtc = eos_rtc_iface();
    if (!rtc) { eos_set_last_error("EOS RTC interface unavailable."); return 0; }

    std::string rn(room_name);
    g_cb_rtc_participant_status_changed = callback;

    EOS_RTC_AddNotifyParticipantStatusChangedOptions opts{};
    opts.ApiVersion  = EOS_RTC_ADDNOTIFYPARTICIPANTSTATUSCHANGED_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName    = rn.c_str();

    return (std::uint64_t)EOS_RTC_AddNotifyParticipantStatusChanged(
        rtc, &opts, nullptr, &eos_rtc_participant_status_changed_callback);
}

void eos_rtc_remove_notify_participant_status_changed(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HRTC rtc = eos_rtc_iface();
    if (!rtc) { eos_set_last_error("EOS RTC interface unavailable."); return; }
    EOS_RTC_RemoveNotifyParticipantStatusChanged(rtc, (EOS_NotificationId)notification_id);
}

std::uint64_t eos_rtc_add_notify_room_statistics_updated(
    std::string_view local_user_id,
    std::string_view room_name,
    const GMFunction& callback)
{
    eos_clear_last_error();
    EOS_HRTC rtc = eos_rtc_iface();
    if (!rtc) { eos_set_last_error("EOS RTC interface unavailable."); return 0; }

    std::string rn(room_name);
    g_cb_rtc_room_statistics_updated = callback;

    EOS_RTC_AddNotifyRoomStatisticsUpdatedOptions opts{};
    opts.ApiVersion  = EOS_RTC_ADDNOTIFYROOMSTATISTICSUPDATED_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName    = rn.c_str();

    return (std::uint64_t)EOS_RTC_AddNotifyRoomStatisticsUpdated(
        rtc, &opts, nullptr, &eos_rtc_room_statistics_updated_callback);
}

void eos_rtc_remove_notify_room_statistics_updated(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HRTC rtc = eos_rtc_iface();
    if (!rtc) { eos_set_last_error("EOS RTC interface unavailable."); return; }
    EOS_RTC_RemoveNotifyRoomStatisticsUpdated(rtc, (EOS_NotificationId)notification_id);
}

// ============================================================
// EOS RTC Audio — Functions
// ============================================================

void eos_rtc_audio_update_sending(
    std::string_view local_user_id,
    std::string_view room_name,
    gm_enums::EpicRTCAudioStatus audio_status,
    const GMFunction& callback)
{
    EOS_GUARD();

    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return; }

    std::string rn(room_name);
    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_RTCAudio_UpdateSendingOptions opts{};
    opts.ApiVersion  = EOS_RTCAUDIO_UPDATESENDING_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName    = rn.c_str();
    opts.AudioStatus = (EOS_ERTCAudioStatus)audio_status;

    EOS_RTCAudio_UpdateSending(audio, &opts, ctx, &eos_rtc_audio_update_sending_callback);
}

void eos_rtc_audio_update_receiving(
    std::string_view local_user_id,
    std::string_view room_name,
    std::string_view participant_id,
    bool audio_enabled,
    const GMFunction& callback)
{
    EOS_GUARD();

    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return; }

    std::string rn(room_name);
    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_RTCAudio_UpdateReceivingOptions opts{};
    opts.ApiVersion    = EOS_RTCAUDIO_UPDATERECEIVING_API_LATEST;
    opts.LocalUserId   = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName      = rn.c_str();
    opts.ParticipantId = eos_product_user_id_from_string_internal(participant_id);
    opts.bAudioEnabled = audio_enabled ? EOS_TRUE : EOS_FALSE;

    EOS_RTCAudio_UpdateReceiving(audio, &opts, ctx, &eos_rtc_audio_update_receiving_callback);
}

void eos_rtc_audio_update_sending_volume(
    std::string_view local_user_id,
    std::string_view room_name,
    double volume,
    const GMFunction& callback)
{
    EOS_GUARD();

    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return; }

    std::string rn(room_name);
    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_RTCAudio_UpdateSendingVolumeOptions opts{};
    opts.ApiVersion  = EOS_RTCAUDIO_UPDATESENDINGVOLUME_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName    = rn.c_str();
    opts.Volume      = (float)volume;

    EOS_RTCAudio_UpdateSendingVolume(audio, &opts, ctx, &eos_rtc_audio_update_sending_volume_callback);
}

void eos_rtc_audio_update_receiving_volume(
    std::string_view local_user_id,
    std::string_view room_name,
    double volume,
    const GMFunction& callback)
{
    EOS_GUARD();

    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return; }

    std::string rn(room_name);
    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_RTCAudio_UpdateReceivingVolumeOptions opts{};
    opts.ApiVersion  = EOS_RTCAUDIO_UPDATERECEIVINGVOLUME_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName    = rn.c_str();
    opts.Volume      = (float)volume;

    EOS_RTCAudio_UpdateReceivingVolume(audio, &opts, ctx, &eos_rtc_audio_update_receiving_volume_callback);
}

void eos_rtc_audio_update_participant_volume(
    std::string_view local_user_id,
    std::string_view room_name,
    std::string_view participant_id,
    double volume,
    const GMFunction& callback)
{
    EOS_GUARD();

    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return; }

    std::string rn(room_name);
    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_RTCAudio_UpdateParticipantVolumeOptions opts{};
    opts.ApiVersion    = EOS_RTCAUDIO_UPDATEPARTICIPANTVOLUME_API_LATEST;
    opts.LocalUserId   = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName      = rn.c_str();
    opts.ParticipantId = eos_product_user_id_from_string_internal(participant_id);
    opts.Volume        = (float)volume;

    EOS_RTCAudio_UpdateParticipantVolume(audio, &opts, ctx, &eos_rtc_audio_update_participant_volume_callback);
}

std::int64_t eos_rtc_audio_get_input_devices_count()
{
    EOS_GUARD_RET(0);

    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return 0; }

    EOS_RTCAudio_GetInputDevicesCountOptions opts{};
    opts.ApiVersion = EOS_RTCAUDIO_GETINPUTDEVICESCOUNT_API_LATEST;

    return (std::int64_t)EOS_RTCAudio_GetInputDevicesCount(audio, &opts);
}

gm_structs::EpicRTCAudioInputDeviceInfo eos_rtc_audio_copy_input_device_info_by_index(std::int64_t index)
{
    gm_structs::EpicRTCAudioInputDeviceInfo out{};
    EOS_GUARD_RET(out);

    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return out; }

    EOS_RTCAudio_CopyInputDeviceInformationByIndexOptions opts{};
    opts.ApiVersion  = EOS_RTCAUDIO_COPYINPUTDEVICEINFORMATIONBYINDEX_API_LATEST;
    opts.DeviceIndex = (uint32_t)index;

    EOS_RTCAudio_InputDeviceInformation* info = nullptr;
    EOS_EResult result = EOS_RTCAudio_CopyInputDeviceInformationByIndex(audio, &opts, &info);
    if (result != EOS_EResult::EOS_Success || !info) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_RTCAudio_CopyInputDeviceInformationByIndex failed.");
        return out;
    }

    out.default_device = (bool)info->bDefaultDevice;
    out.device_id      = info->DeviceId   ? std::string(info->DeviceId)   : std::string();
    out.device_name    = info->DeviceName ? std::string(info->DeviceName) : std::string();
    EOS_RTCAudio_InputDeviceInformation_Release(info);
    return out;
}

std::int64_t eos_rtc_audio_get_output_devices_count()
{
    EOS_GUARD_RET(0);

    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return 0; }

    EOS_RTCAudio_GetOutputDevicesCountOptions opts{};
    opts.ApiVersion = EOS_RTCAUDIO_GETOUTPUTDEVICESCOUNT_API_LATEST;

    return (std::int64_t)EOS_RTCAudio_GetOutputDevicesCount(audio, &opts);
}

gm_structs::EpicRTCAudioOutputDeviceInfo eos_rtc_audio_copy_output_device_info_by_index(std::int64_t index)
{
    gm_structs::EpicRTCAudioOutputDeviceInfo out{};
    EOS_GUARD_RET(out);

    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return out; }

    EOS_RTCAudio_CopyOutputDeviceInformationByIndexOptions opts{};
    opts.ApiVersion  = EOS_RTCAUDIO_COPYOUTPUTDEVICEINFORMATIONBYINDEX_API_LATEST;
    opts.DeviceIndex = (uint32_t)index;

    EOS_RTCAudio_OutputDeviceInformation* info = nullptr;
    EOS_EResult result = EOS_RTCAudio_CopyOutputDeviceInformationByIndex(audio, &opts, &info);
    if (result != EOS_EResult::EOS_Success || !info) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_RTCAudio_CopyOutputDeviceInformationByIndex failed.");
        return out;
    }

    out.default_device = (bool)info->bDefaultDevice;
    out.device_id      = info->DeviceId   ? std::string(info->DeviceId)   : std::string();
    out.device_name    = info->DeviceName ? std::string(info->DeviceName) : std::string();
    EOS_RTCAudio_OutputDeviceInformation_Release(info);
    return out;
}

void eos_rtc_audio_query_input_devices(const GMFunction& callback)
{
    EOS_GUARD();

    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return; }

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_RTCAudio_QueryInputDevicesInformationOptions opts{};
    opts.ApiVersion = EOS_RTCAUDIO_QUERYINPUTDEVICESINFORMATION_API_LATEST;

    EOS_RTCAudio_QueryInputDevicesInformation(audio, &opts, ctx, &eos_rtc_audio_query_input_devices_callback);
}

void eos_rtc_audio_query_output_devices(const GMFunction& callback)
{
    EOS_GUARD();

    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return; }

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_RTCAudio_QueryOutputDevicesInformationOptions opts{};
    opts.ApiVersion = EOS_RTCAUDIO_QUERYOUTPUTDEVICESINFORMATION_API_LATEST;

    EOS_RTCAudio_QueryOutputDevicesInformation(audio, &opts, ctx, &eos_rtc_audio_query_output_devices_callback);
}

void eos_rtc_audio_set_input_device_settings(
    std::string_view local_user_id,
    std::string_view real_device_id,
    bool platform_aec,
    const GMFunction& callback)
{
    EOS_GUARD();

    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return; }

    std::string did(real_device_id);
    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_RTCAudio_SetInputDeviceSettingsOptions opts{};
    opts.ApiVersion   = EOS_RTCAUDIO_SETINPUTDEVICESETTINGS_API_LATEST;
    opts.LocalUserId  = eos_product_user_id_from_string_internal(local_user_id);
    opts.RealDeviceId = did.empty() ? nullptr : did.c_str();
    opts.bPlatformAEC = platform_aec ? EOS_TRUE : EOS_FALSE;

    EOS_RTCAudio_SetInputDeviceSettings(audio, &opts, ctx, &eos_rtc_audio_set_input_device_settings_callback);
}

void eos_rtc_audio_set_output_device_settings(
    std::string_view local_user_id,
    std::string_view real_device_id,
    const GMFunction& callback)
{
    EOS_GUARD();

    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return; }

    std::string did(real_device_id);
    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_RTCAudio_SetOutputDeviceSettingsOptions opts{};
    opts.ApiVersion   = EOS_RTCAUDIO_SETOUTPUTDEVICESETTINGS_API_LATEST;
    opts.LocalUserId  = eos_product_user_id_from_string_internal(local_user_id);
    opts.RealDeviceId = did.empty() ? nullptr : did.c_str();

    EOS_RTCAudio_SetOutputDeviceSettings(audio, &opts, ctx, &eos_rtc_audio_set_output_device_settings_callback);
}

// ============================================================
// EOS RTC Audio — Notify add/remove
// ============================================================

std::uint64_t eos_rtc_audio_add_notify_participant_updated(
    std::string_view local_user_id,
    std::string_view room_name,
    const GMFunction& callback)
{
    eos_clear_last_error();
    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return 0; }

    std::string rn(room_name);
    g_cb_rtc_audio_participant_updated = callback;

    EOS_RTCAudio_AddNotifyParticipantUpdatedOptions opts{};
    opts.ApiVersion  = EOS_RTCAUDIO_ADDNOTIFYPARTICIPANTUPDATED_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName    = rn.c_str();

    return (std::uint64_t)EOS_RTCAudio_AddNotifyParticipantUpdated(
        audio, &opts, nullptr, &eos_rtc_audio_participant_updated_callback);
}

void eos_rtc_audio_remove_notify_participant_updated(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return; }
    EOS_RTCAudio_RemoveNotifyParticipantUpdated(audio, (EOS_NotificationId)notification_id);
}

std::uint64_t eos_rtc_audio_add_notify_audio_devices_changed(const GMFunction& callback)
{
    eos_clear_last_error();
    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return 0; }

    g_cb_rtc_audio_devices_changed = callback;

    EOS_RTCAudio_AddNotifyAudioDevicesChangedOptions opts{};
    opts.ApiVersion = EOS_RTCAUDIO_ADDNOTIFYAUDIODEVICESCHANGED_API_LATEST;

    return (std::uint64_t)EOS_RTCAudio_AddNotifyAudioDevicesChanged(
        audio, &opts, nullptr, &eos_rtc_audio_devices_changed_callback);
}

void eos_rtc_audio_remove_notify_audio_devices_changed(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return; }
    EOS_RTCAudio_RemoveNotifyAudioDevicesChanged(audio, (EOS_NotificationId)notification_id);
}

std::uint64_t eos_rtc_audio_add_notify_audio_input_state(
    std::string_view local_user_id,
    std::string_view room_name,
    const GMFunction& callback)
{
    eos_clear_last_error();
    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return 0; }

    std::string rn(room_name);
    g_cb_rtc_audio_input_state = callback;

    EOS_RTCAudio_AddNotifyAudioInputStateOptions opts{};
    opts.ApiVersion  = EOS_RTCAUDIO_ADDNOTIFYAUDIOINPUTSTATE_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName    = rn.c_str();

    return (std::uint64_t)EOS_RTCAudio_AddNotifyAudioInputState(
        audio, &opts, nullptr, &eos_rtc_audio_input_state_callback);
}

void eos_rtc_audio_remove_notify_audio_input_state(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return; }
    EOS_RTCAudio_RemoveNotifyAudioInputState(audio, (EOS_NotificationId)notification_id);
}

std::uint64_t eos_rtc_audio_add_notify_audio_output_state(
    std::string_view local_user_id,
    std::string_view room_name,
    const GMFunction& callback)
{
    eos_clear_last_error();
    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return 0; }

    std::string rn(room_name);
    g_cb_rtc_audio_output_state = callback;

    EOS_RTCAudio_AddNotifyAudioOutputStateOptions opts{};
    opts.ApiVersion  = EOS_RTCAUDIO_ADDNOTIFYAUDIOOUTPUTSTATE_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName    = rn.c_str();

    return (std::uint64_t)EOS_RTCAudio_AddNotifyAudioOutputState(
        audio, &opts, nullptr, &eos_rtc_audio_output_state_callback);
}

void eos_rtc_audio_remove_notify_audio_output_state(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return; }
    EOS_RTCAudio_RemoveNotifyAudioOutputState(audio, (EOS_NotificationId)notification_id);
}
