#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_rtc.h>
#include <eos_rtc_audio.h>

#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>
#include <mutex>

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

struct EOSNotifyCallbackContext
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

static const char k_b64_chars[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static std::string eos_rtc_audio_base64_encode(const void* data, size_t len)
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
// Notify callback storage — id-keyed, one heap ctx per registration
// (see gm_eos_p2p.cpp for the reference pattern this follows)
// ============================================================

static std::mutex g_notify_mutex;

static std::unordered_map<uint64_t, EOSNotifyCallbackContext*> g_rtc_disconnected_callbacks;
static std::unordered_map<uint64_t, EOSNotifyCallbackContext*> g_rtc_participant_status_changed_callbacks;
static std::unordered_map<uint64_t, EOSNotifyCallbackContext*> g_rtc_room_statistics_updated_callbacks;

static std::unordered_map<uint64_t, EOSNotifyCallbackContext*> g_rtc_audio_participant_updated_callbacks;
static std::unordered_map<uint64_t, EOSNotifyCallbackContext*> g_rtc_audio_devices_changed_callbacks;
static std::unordered_map<uint64_t, EOSNotifyCallbackContext*> g_rtc_audio_input_state_callbacks;
static std::unordered_map<uint64_t, EOSNotifyCallbackContext*> g_rtc_audio_output_state_callbacks;

// AudioBeforeSend/AudioBeforeRender may fire off the main thread (eos_rtc_audio.h:211,239) — the
// only two callbacks in this file where that's true. g_notify_mutex additionally guards reading
// ctx->callback inside those two callbacks (not just add/remove), so the read can't race a
// concurrent remove_notify's delete.
static std::unordered_map<uint64_t, EOSNotifyCallbackContext*> g_rtc_audio_before_send_callbacks;
static std::unordered_map<uint64_t, EOSNotifyCallbackContext*> g_rtc_audio_before_render_callbacks;

// ============================================================
// RTC core notify callbacks
// ============================================================

static void EOS_CALL eos_rtc_disconnected_callback(
    const EOS_RTC_DisconnectedCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSNotifyCallbackContext*>(data->ClientData);
    if (!ctx || !ctx->callback) return;
    gm_structs::EpicRTCDisconnectedCallbackInfo out{};
    out.result_code   = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name     = data->RoomName ? std::string(data->RoomName) : std::string();
    ctx->callback.call(out);
}

static void EOS_CALL eos_rtc_participant_status_changed_callback(
    const EOS_RTC_ParticipantStatusChangedCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSNotifyCallbackContext*>(data->ClientData);
    if (!ctx || !ctx->callback) return;
    gm_structs::EpicRTCParticipantStatusChangedCallbackInfo out{};
    out.local_user_id          = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name              = data->RoomName ? std::string(data->RoomName) : std::string();
    out.participant_id         = eos_product_user_id_to_string_internal(data->ParticipantId);
    out.participant_status     = (gm_enums::EpicRTCParticipantStatus)data->ParticipantStatus;
    out.participant_in_blocklist = (bool)data->bParticipantInBlocklist;

    std::vector<gm_structs::EpicRTCParticipantMetadata> participant_metadata;
    for (uint32_t i = 0; i < data->ParticipantMetadataCount; ++i) {
        gm_structs::EpicRTCParticipantMetadata meta{};
        meta.key   = data->ParticipantMetadata[i].Key ? std::string(data->ParticipantMetadata[i].Key) : std::string();
        meta.value = data->ParticipantMetadata[i].Value ? std::string(data->ParticipantMetadata[i].Value) : std::string();
        participant_metadata.push_back(meta);
    }
    out.participant_metadata = participant_metadata;

    ctx->callback.call(out);
}

static void EOS_CALL eos_rtc_room_statistics_updated_callback(
    const EOS_RTC_RoomStatisticsUpdatedInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSNotifyCallbackContext*>(data->ClientData);
    if (!ctx || !ctx->callback) return;
    gm_structs::EpicRTCRoomStatisticsUpdatedInfo out{};
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name     = data->RoomName ? std::string(data->RoomName) : std::string();
    out.statistic     = data->Statistic ? std::string(data->Statistic) : std::string();
    ctx->callback.call(out);
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

    std::vector<gm_structs::EpicRTCOption> room_options;
    for (uint32_t i = 0; i < data->RoomOptionsCount; ++i) {
        gm_structs::EpicRTCOption opt{};
        opt.key   = data->RoomOptions[i].Key ? std::string(data->RoomOptions[i].Key) : std::string();
        opt.value = data->RoomOptions[i].Value ? std::string(data->RoomOptions[i].Value) : std::string();
        room_options.push_back(opt);
    }
    out.room_options = room_options;

    if (ctx->callback) ctx->callback.value().call(out);
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
    if (ctx->callback) ctx->callback.value().call(out);
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
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

// ============================================================
// RTC audio notify callbacks
// ============================================================

static void EOS_CALL eos_rtc_audio_participant_updated_callback(
    const EOS_RTCAudio_ParticipantUpdatedCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSNotifyCallbackContext*>(data->ClientData);
    if (!ctx || !ctx->callback) return;
    gm_structs::EpicRTCAudioParticipantUpdatedCallbackInfo out{};
    out.local_user_id  = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name      = data->RoomName ? std::string(data->RoomName) : std::string();
    out.participant_id = eos_product_user_id_to_string_internal(data->ParticipantId);
    out.speaking       = (bool)data->bSpeaking;
    out.audio_status   = (gm_enums::EpicRTCAudioStatus)data->AudioStatus;
    ctx->callback.call(out);
}

static void EOS_CALL eos_rtc_audio_devices_changed_callback(
    const EOS_RTCAudio_AudioDevicesChangedCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSNotifyCallbackContext*>(data->ClientData);
    if (!ctx || !ctx->callback) return;
    gm_structs::EpicRTCAudioDevicesChangedCallbackInfo out{};
    out.triggered = true;
    ctx->callback.call(out);
}

static void EOS_CALL eos_rtc_audio_input_state_callback(
    const EOS_RTCAudio_AudioInputStateCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSNotifyCallbackContext*>(data->ClientData);
    if (!ctx || !ctx->callback) return;
    gm_structs::EpicRTCAudioInputStateCallbackInfo out{};
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name     = data->RoomName ? std::string(data->RoomName) : std::string();
    out.status        = (gm_enums::EpicRTCAudioInputStatus)data->Status;
    ctx->callback.call(out);
}

static void EOS_CALL eos_rtc_audio_output_state_callback(
    const EOS_RTCAudio_AudioOutputStateCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSNotifyCallbackContext*>(data->ClientData);
    if (!ctx || !ctx->callback) return;
    gm_structs::EpicRTCAudioOutputStateCallbackInfo out{};
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name     = data->RoomName ? std::string(data->RoomName) : std::string();
    out.status        = (gm_enums::EpicRTCAudioOutputStatus)data->Status;
    ctx->callback.call(out);
}

static void EOS_CALL eos_rtc_audio_before_send_callback(
    const EOS_RTCAudio_AudioBeforeSendCallbackInfo* data)
{
    if (!data) return;

    // May run on an SDK-owned thread (eos_rtc_audio.h:211). Copy the callback out under the lock
    // so this can't race remove_notify's delete of ctx, then call GML outside the lock so a
    // reentrant call back into this extension can't deadlock on g_notify_mutex.
    GMFunction cb;
    {
        std::lock_guard<std::mutex> lock(g_notify_mutex);
        auto* ctx = static_cast<EOSNotifyCallbackContext*>(data->ClientData);
        if (!ctx) return;
        cb = ctx->callback;
    }
    if (!cb) return;

    gm_structs::EpicRTCAudioBeforeSendCallbackInfo out{};
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name     = data->RoomName ? std::string(data->RoomName) : std::string();

    if (data->Buffer) {
        out.sample_rate = data->Buffer->SampleRate;
        out.channels = data->Buffer->Channels;
        out.frames_count = data->Buffer->FramesCount;
        if (data->Buffer->Frames && data->Buffer->FramesCount > 0 && data->Buffer->Channels > 0) {
            size_t byte_count = (size_t)data->Buffer->FramesCount * (size_t)data->Buffer->Channels * sizeof(int16_t);
            out.data = eos_rtc_audio_base64_encode(data->Buffer->Frames, byte_count);
        }
    }

    cb.call(out);
}

static void EOS_CALL eos_rtc_audio_before_render_callback(
    const EOS_RTCAudio_AudioBeforeRenderCallbackInfo* data)
{
    if (!data) return;

    GMFunction cb;
    {
        std::lock_guard<std::mutex> lock(g_notify_mutex);
        auto* ctx = static_cast<EOSNotifyCallbackContext*>(data->ClientData);
        if (!ctx) return;
        cb = ctx->callback;
    }
    if (!cb) return;

    gm_structs::EpicRTCAudioBeforeRenderCallbackInfo out{};
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.room_name     = data->RoomName ? std::string(data->RoomName) : std::string();
    out.participant_id = eos_product_user_id_to_string_internal(data->ParticipantId);

    if (data->Buffer) {
        out.sample_rate = data->Buffer->SampleRate;
        out.channels = data->Buffer->Channels;
        out.frames_count = data->Buffer->FramesCount;
        if (data->Buffer->Frames && data->Buffer->FramesCount > 0 && data->Buffer->Channels > 0) {
            size_t byte_count = (size_t)data->Buffer->FramesCount * (size_t)data->Buffer->Channels * sizeof(int16_t);
            out.data = eos_rtc_audio_base64_encode(data->Buffer->Frames, byte_count);
        }
    }

    cb.call(out);
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
    if (ctx->callback) ctx->callback.value().call(out);
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
    if (ctx->callback) ctx->callback.value().call(out);
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
    if (ctx->callback) ctx->callback.value().call(out);
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
    if (ctx->callback) ctx->callback.value().call(out);
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
    if (ctx->callback) ctx->callback.value().call(out);
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
    if (ctx->callback) ctx->callback.value().call(out);
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
    if (ctx->callback) ctx->callback.value().call(out);
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
    if (ctx->callback) ctx->callback.value().call(out);
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
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

static void EOS_CALL eos_rtc_audio_register_platform_user_callback(
    const EOS_RTCAudio_OnRegisterPlatformUserCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;
    gm_structs::EpicRTCAudioRegisterPlatformUserCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

static void EOS_CALL eos_rtc_audio_unregister_platform_user_callback(
    const EOS_RTCAudio_OnUnregisterPlatformUserCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;
    gm_structs::EpicRTCAudioUnregisterPlatformUserCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    if (ctx->callback) ctx->callback.value().call(out);
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
    bool manual_audio_input,
    bool manual_audio_output,
    const std::optional<gm::wire::GMFunction>& callback)
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
    opts.bManualAudioInputEnabled  = manual_audio_input ? EOS_TRUE : EOS_FALSE;
    opts.bManualAudioOutputEnabled = manual_audio_output ? EOS_TRUE : EOS_FALSE;

    EOS_RTC_JoinRoom(rtc, &opts, ctx, &eos_rtc_join_room_callback);
}

void eos_rtc_leave_room(
    std::string_view local_user_id,
    std::string_view room_name,
    const std::optional<gm::wire::GMFunction>& callback)
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
    const std::optional<gm::wire::GMFunction>& callback)
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
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();
    EOS_HRTC rtc = eos_rtc_iface();
    if (!rtc) { eos_set_last_error("EOS RTC interface unavailable."); return 0; }

    std::string rn(room_name);
    auto* ctx = new EOSNotifyCallbackContext{callback.value_or(GMFunction{})};

    EOS_RTC_AddNotifyDisconnectedOptions opts{};
    opts.ApiVersion  = EOS_RTC_ADDNOTIFYDISCONNECTED_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName    = rn.c_str();

    EOS_NotificationId id = EOS_RTC_AddNotifyDisconnected(
        rtc, &opts, ctx, &eos_rtc_disconnected_callback);

    if (id == EOS_INVALID_NOTIFICATIONID) {
        delete ctx;
        eos_set_last_error("EOS_RTC_AddNotifyDisconnected returned invalid ID.");
        return 0;
    }

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    g_rtc_disconnected_callbacks[(uint64_t)id] = ctx;
    return (uint64_t)id;
}

void eos_rtc_remove_notify_disconnected(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HRTC rtc = eos_rtc_iface();
    if (rtc) EOS_RTC_RemoveNotifyDisconnected(rtc, (EOS_NotificationId)notification_id);

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    auto it = g_rtc_disconnected_callbacks.find(notification_id);
    if (it != g_rtc_disconnected_callbacks.end()) {
        delete it->second;
        g_rtc_disconnected_callbacks.erase(it);
    }
}

std::uint64_t eos_rtc_add_notify_participant_status_changed(
    std::string_view local_user_id,
    std::string_view room_name,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();
    EOS_HRTC rtc = eos_rtc_iface();
    if (!rtc) { eos_set_last_error("EOS RTC interface unavailable."); return 0; }

    std::string rn(room_name);
    auto* ctx = new EOSNotifyCallbackContext{callback.value_or(GMFunction{})};

    EOS_RTC_AddNotifyParticipantStatusChangedOptions opts{};
    opts.ApiVersion  = EOS_RTC_ADDNOTIFYPARTICIPANTSTATUSCHANGED_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName    = rn.c_str();

    EOS_NotificationId id = EOS_RTC_AddNotifyParticipantStatusChanged(
        rtc, &opts, ctx, &eos_rtc_participant_status_changed_callback);

    if (id == EOS_INVALID_NOTIFICATIONID) {
        delete ctx;
        eos_set_last_error("EOS_RTC_AddNotifyParticipantStatusChanged returned invalid ID.");
        return 0;
    }

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    g_rtc_participant_status_changed_callbacks[(uint64_t)id] = ctx;
    return (uint64_t)id;
}

void eos_rtc_remove_notify_participant_status_changed(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HRTC rtc = eos_rtc_iface();
    if (rtc) EOS_RTC_RemoveNotifyParticipantStatusChanged(rtc, (EOS_NotificationId)notification_id);

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    auto it = g_rtc_participant_status_changed_callbacks.find(notification_id);
    if (it != g_rtc_participant_status_changed_callbacks.end()) {
        delete it->second;
        g_rtc_participant_status_changed_callbacks.erase(it);
    }
}

std::uint64_t eos_rtc_add_notify_room_statistics_updated(
    std::string_view local_user_id,
    std::string_view room_name,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();
    EOS_HRTC rtc = eos_rtc_iface();
    if (!rtc) { eos_set_last_error("EOS RTC interface unavailable."); return 0; }

    std::string rn(room_name);
    auto* ctx = new EOSNotifyCallbackContext{callback.value_or(GMFunction{})};

    EOS_RTC_AddNotifyRoomStatisticsUpdatedOptions opts{};
    opts.ApiVersion  = EOS_RTC_ADDNOTIFYROOMSTATISTICSUPDATED_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName    = rn.c_str();

    EOS_NotificationId id = EOS_RTC_AddNotifyRoomStatisticsUpdated(
        rtc, &opts, ctx, &eos_rtc_room_statistics_updated_callback);

    if (id == EOS_INVALID_NOTIFICATIONID) {
        delete ctx;
        eos_set_last_error("EOS_RTC_AddNotifyRoomStatisticsUpdated returned invalid ID.");
        return 0;
    }

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    g_rtc_room_statistics_updated_callbacks[(uint64_t)id] = ctx;
    return (uint64_t)id;
}

void eos_rtc_remove_notify_room_statistics_updated(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HRTC rtc = eos_rtc_iface();
    if (rtc) EOS_RTC_RemoveNotifyRoomStatisticsUpdated(rtc, (EOS_NotificationId)notification_id);

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    auto it = g_rtc_room_statistics_updated_callbacks.find(notification_id);
    if (it != g_rtc_room_statistics_updated_callbacks.end()) {
        delete it->second;
        g_rtc_room_statistics_updated_callbacks.erase(it);
    }
}

// ============================================================
// EOS RTC Audio — Functions
// ============================================================

void eos_rtc_audio_update_sending(
    std::string_view local_user_id,
    std::string_view room_name,
    gm_enums::EpicRTCAudioStatus audio_status,
    const std::optional<gm::wire::GMFunction>& callback)
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
    const std::optional<gm::wire::GMFunction>& callback)
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
    const std::optional<gm::wire::GMFunction>& callback)
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
    const std::optional<gm::wire::GMFunction>& callback)
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
    const std::optional<gm::wire::GMFunction>& callback)
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

std::optional<gm_structs::EpicRTCAudioInputDeviceInfo> eos_rtc_audio_copy_input_device_info_by_index(std::int64_t index)
{
    EOS_GUARD_RET(std::nullopt);

    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return std::nullopt; }

    EOS_RTCAudio_CopyInputDeviceInformationByIndexOptions opts{};
    opts.ApiVersion  = EOS_RTCAUDIO_COPYINPUTDEVICEINFORMATIONBYINDEX_API_LATEST;
    opts.DeviceIndex = (uint32_t)index;

    EOS_RTCAudio_InputDeviceInformation* info = nullptr;
    EOS_EResult result = EOS_RTCAudio_CopyInputDeviceInformationByIndex(audio, &opts, &info);
    if (result != EOS_EResult::EOS_Success || !info) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_RTCAudio_CopyInputDeviceInformationByIndex failed.");
        return std::nullopt;
    }

    gm_structs::EpicRTCAudioInputDeviceInfo out{};
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

std::optional<gm_structs::EpicRTCAudioOutputDeviceInfo> eos_rtc_audio_copy_output_device_info_by_index(std::int64_t index)
{
    EOS_GUARD_RET(std::nullopt);

    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return std::nullopt; }

    EOS_RTCAudio_CopyOutputDeviceInformationByIndexOptions opts{};
    opts.ApiVersion  = EOS_RTCAUDIO_COPYOUTPUTDEVICEINFORMATIONBYINDEX_API_LATEST;
    opts.DeviceIndex = (uint32_t)index;

    EOS_RTCAudio_OutputDeviceInformation* info = nullptr;
    EOS_EResult result = EOS_RTCAudio_CopyOutputDeviceInformationByIndex(audio, &opts, &info);
    if (result != EOS_EResult::EOS_Success || !info) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_RTCAudio_CopyOutputDeviceInformationByIndex failed.");
        return std::nullopt;
    }

    gm_structs::EpicRTCAudioOutputDeviceInfo out{};
    out.default_device = (bool)info->bDefaultDevice;
    out.device_id      = info->DeviceId   ? std::string(info->DeviceId)   : std::string();
    out.device_name    = info->DeviceName ? std::string(info->DeviceName) : std::string();
    EOS_RTCAudio_OutputDeviceInformation_Release(info);
    return out;
}

void eos_rtc_audio_query_input_devices(const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return; }

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_RTCAudio_QueryInputDevicesInformationOptions opts{};
    opts.ApiVersion = EOS_RTCAUDIO_QUERYINPUTDEVICESINFORMATION_API_LATEST;

    EOS_RTCAudio_QueryInputDevicesInformation(audio, &opts, ctx, &eos_rtc_audio_query_input_devices_callback);
}

void eos_rtc_audio_query_output_devices(const std::optional<gm::wire::GMFunction>& callback)
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
    const std::optional<gm::wire::GMFunction>& callback)
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
    const std::optional<gm::wire::GMFunction>& callback)
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

bool eos_rtc_audio_send_audio(
    std::string_view local_user_id,
    std::string_view room_name,
    std::uint32_t sample_rate,
    std::uint32_t channels,
    std::uint32_t frames_count,
    gm::wire::GMBuffer frames)
{
    EOS_GUARD_RET(false);

    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return false; }

    std::string rn(room_name);

    if (channels == 0 || frames_count == 0) {
        eos_set_last_error("EOS_RTCAudio_SendAudio: channels and frames_count must be greater than 0.");
        return false;
    }

    size_t required_bytes = (size_t)frames_count * (size_t)channels * sizeof(int16_t);
    if (frames.length() < required_bytes) {
        eos_set_last_error("EOS_RTCAudio_SendAudio: frames buffer is too small for the specified frames_count and channels.");
        return false;
    }

    EOS_RTCAudio_AudioBuffer audio_buffer{};
    audio_buffer.ApiVersion = EOS_RTCAUDIO_AUDIOBUFFER_API_LATEST;
    audio_buffer.Frames = (int16_t*)frames.data();
    audio_buffer.FramesCount = frames_count;
    audio_buffer.SampleRate = sample_rate;
    audio_buffer.Channels = channels;

    EOS_RTCAudio_SendAudioOptions opts{};
    opts.ApiVersion  = EOS_RTCAUDIO_SENDAUDIO_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName    = rn.c_str();
    opts.Buffer      = &audio_buffer;

    EOS_EResult result = EOS_RTCAudio_SendAudio(audio, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_RTCAudio_SendAudio failed.");
    }
    return result == EOS_EResult::EOS_Success;
}

void eos_rtc_audio_register_platform_user(
    std::string_view rtc_platform_user_id,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return; }

    std::string uid(rtc_platform_user_id);
    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_RTCAudio_RegisterPlatformUserOptions opts{};
    opts.ApiVersion         = EOS_RTCAUDIO_REGISTERPLATFORMUSER_API_LATEST;
    opts.PlatformUserId     = uid.c_str();

    EOS_RTCAudio_RegisterPlatformUser(audio, &opts, ctx, &eos_rtc_audio_register_platform_user_callback);
}

void eos_rtc_audio_unregister_platform_user(
    std::string_view rtc_platform_user_id,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return; }

    std::string uid(rtc_platform_user_id);
    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_RTCAudio_UnregisterPlatformUserOptions opts{};
    opts.ApiVersion         = EOS_RTCAUDIO_UNREGISTERPLATFORMUSER_API_LATEST;
    opts.PlatformUserId     = uid.c_str();

    EOS_RTCAudio_UnregisterPlatformUser(audio, &opts, ctx, &eos_rtc_audio_unregister_platform_user_callback);
}

// ============================================================
// EOS RTC Audio — Notify add/remove
// ============================================================

std::uint64_t eos_rtc_audio_add_notify_participant_updated(
    std::string_view local_user_id,
    std::string_view room_name,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();
    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return 0; }

    std::string rn(room_name);
    auto* ctx = new EOSNotifyCallbackContext{callback.value_or(GMFunction{})};

    EOS_RTCAudio_AddNotifyParticipantUpdatedOptions opts{};
    opts.ApiVersion  = EOS_RTCAUDIO_ADDNOTIFYPARTICIPANTUPDATED_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName    = rn.c_str();

    EOS_NotificationId id = EOS_RTCAudio_AddNotifyParticipantUpdated(
        audio, &opts, ctx, &eos_rtc_audio_participant_updated_callback);

    if (id == EOS_INVALID_NOTIFICATIONID) {
        delete ctx;
        eos_set_last_error("EOS_RTCAudio_AddNotifyParticipantUpdated returned invalid ID.");
        return 0;
    }

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    g_rtc_audio_participant_updated_callbacks[(uint64_t)id] = ctx;
    return (uint64_t)id;
}

void eos_rtc_audio_remove_notify_participant_updated(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (audio) EOS_RTCAudio_RemoveNotifyParticipantUpdated(audio, (EOS_NotificationId)notification_id);

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    auto it = g_rtc_audio_participant_updated_callbacks.find(notification_id);
    if (it != g_rtc_audio_participant_updated_callbacks.end()) {
        delete it->second;
        g_rtc_audio_participant_updated_callbacks.erase(it);
    }
}

std::uint64_t eos_rtc_audio_add_notify_audio_devices_changed(const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();
    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return 0; }

    auto* ctx = new EOSNotifyCallbackContext{callback.value_or(GMFunction{})};

    EOS_RTCAudio_AddNotifyAudioDevicesChangedOptions opts{};
    opts.ApiVersion = EOS_RTCAUDIO_ADDNOTIFYAUDIODEVICESCHANGED_API_LATEST;

    EOS_NotificationId id = EOS_RTCAudio_AddNotifyAudioDevicesChanged(
        audio, &opts, ctx, &eos_rtc_audio_devices_changed_callback);

    if (id == EOS_INVALID_NOTIFICATIONID) {
        delete ctx;
        eos_set_last_error("EOS_RTCAudio_AddNotifyAudioDevicesChanged returned invalid ID.");
        return 0;
    }

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    g_rtc_audio_devices_changed_callbacks[(uint64_t)id] = ctx;
    return (uint64_t)id;
}

void eos_rtc_audio_remove_notify_audio_devices_changed(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (audio) EOS_RTCAudio_RemoveNotifyAudioDevicesChanged(audio, (EOS_NotificationId)notification_id);

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    auto it = g_rtc_audio_devices_changed_callbacks.find(notification_id);
    if (it != g_rtc_audio_devices_changed_callbacks.end()) {
        delete it->second;
        g_rtc_audio_devices_changed_callbacks.erase(it);
    }
}

std::uint64_t eos_rtc_audio_add_notify_audio_input_state(
    std::string_view local_user_id,
    std::string_view room_name,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();
    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return 0; }

    std::string rn(room_name);
    auto* ctx = new EOSNotifyCallbackContext{callback.value_or(GMFunction{})};

    EOS_RTCAudio_AddNotifyAudioInputStateOptions opts{};
    opts.ApiVersion  = EOS_RTCAUDIO_ADDNOTIFYAUDIOINPUTSTATE_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName    = rn.c_str();

    EOS_NotificationId id = EOS_RTCAudio_AddNotifyAudioInputState(
        audio, &opts, ctx, &eos_rtc_audio_input_state_callback);

    if (id == EOS_INVALID_NOTIFICATIONID) {
        delete ctx;
        eos_set_last_error("EOS_RTCAudio_AddNotifyAudioInputState returned invalid ID.");
        return 0;
    }

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    g_rtc_audio_input_state_callbacks[(uint64_t)id] = ctx;
    return (uint64_t)id;
}

void eos_rtc_audio_remove_notify_audio_input_state(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (audio) EOS_RTCAudio_RemoveNotifyAudioInputState(audio, (EOS_NotificationId)notification_id);

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    auto it = g_rtc_audio_input_state_callbacks.find(notification_id);
    if (it != g_rtc_audio_input_state_callbacks.end()) {
        delete it->second;
        g_rtc_audio_input_state_callbacks.erase(it);
    }
}

std::uint64_t eos_rtc_audio_add_notify_audio_output_state(
    std::string_view local_user_id,
    std::string_view room_name,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();
    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return 0; }

    std::string rn(room_name);
    auto* ctx = new EOSNotifyCallbackContext{callback.value_or(GMFunction{})};

    EOS_RTCAudio_AddNotifyAudioOutputStateOptions opts{};
    opts.ApiVersion  = EOS_RTCAUDIO_ADDNOTIFYAUDIOOUTPUTSTATE_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName    = rn.c_str();

    EOS_NotificationId id = EOS_RTCAudio_AddNotifyAudioOutputState(
        audio, &opts, ctx, &eos_rtc_audio_output_state_callback);

    if (id == EOS_INVALID_NOTIFICATIONID) {
        delete ctx;
        eos_set_last_error("EOS_RTCAudio_AddNotifyAudioOutputState returned invalid ID.");
        return 0;
    }

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    g_rtc_audio_output_state_callbacks[(uint64_t)id] = ctx;
    return (uint64_t)id;
}

void eos_rtc_audio_remove_notify_audio_output_state(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (audio) EOS_RTCAudio_RemoveNotifyAudioOutputState(audio, (EOS_NotificationId)notification_id);

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    auto it = g_rtc_audio_output_state_callbacks.find(notification_id);
    if (it != g_rtc_audio_output_state_callbacks.end()) {
        delete it->second;
        g_rtc_audio_output_state_callbacks.erase(it);
    }
}

std::uint64_t eos_rtc_audio_add_notify_audio_before_send(
    std::string_view local_user_id,
    std::string_view room_name,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();
    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return 0; }

    std::string rn(room_name);
    auto* ctx = new EOSNotifyCallbackContext{callback.value_or(GMFunction{})};

    EOS_RTCAudio_AddNotifyAudioBeforeSendOptions opts{};
    opts.ApiVersion  = EOS_RTCAUDIO_ADDNOTIFYAUDIOBEFORESEND_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName    = rn.c_str();

    EOS_NotificationId id = EOS_RTCAudio_AddNotifyAudioBeforeSend(
        audio, &opts, ctx, &eos_rtc_audio_before_send_callback);

    if (id == EOS_INVALID_NOTIFICATIONID) {
        delete ctx;
        eos_set_last_error("EOS_RTCAudio_AddNotifyAudioBeforeSend returned invalid ID.");
        return 0;
    }

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    g_rtc_audio_before_send_callbacks[(uint64_t)id] = ctx;
    return (uint64_t)id;
}

void eos_rtc_audio_remove_notify_audio_before_send(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (audio) EOS_RTCAudio_RemoveNotifyAudioBeforeSend(audio, (EOS_NotificationId)notification_id);

    // Locked so this can't delete ctx while eos_rtc_audio_before_send_callback (possibly running
    // on an SDK thread right now) is mid-copy of ctx->callback.
    std::lock_guard<std::mutex> lock(g_notify_mutex);
    auto it = g_rtc_audio_before_send_callbacks.find(notification_id);
    if (it != g_rtc_audio_before_send_callbacks.end()) {
        delete it->second;
        g_rtc_audio_before_send_callbacks.erase(it);
    }
}

std::uint64_t eos_rtc_audio_add_notify_audio_before_render(
    std::string_view local_user_id,
    std::string_view room_name,
    bool unmixed_audio,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();
    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (!audio) { eos_set_last_error("EOS RTCAudio interface unavailable."); return 0; }

    std::string rn(room_name);
    auto* ctx = new EOSNotifyCallbackContext{callback.value_or(GMFunction{})};

    EOS_RTCAudio_AddNotifyAudioBeforeRenderOptions opts{};
    opts.ApiVersion  = EOS_RTCAUDIO_ADDNOTIFYAUDIOBEFORERENDER_API_LATEST;
    opts.LocalUserId = eos_product_user_id_from_string_internal(local_user_id);
    opts.RoomName    = rn.c_str();
    opts.bUnmixedAudio = unmixed_audio ? EOS_TRUE : EOS_FALSE;

    EOS_NotificationId id = EOS_RTCAudio_AddNotifyAudioBeforeRender(
        audio, &opts, ctx, &eos_rtc_audio_before_render_callback);

    if (id == EOS_INVALID_NOTIFICATIONID) {
        delete ctx;
        eos_set_last_error("EOS_RTCAudio_AddNotifyAudioBeforeRender returned invalid ID.");
        return 0;
    }

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    g_rtc_audio_before_render_callbacks[(uint64_t)id] = ctx;
    return (uint64_t)id;
}

void eos_rtc_audio_remove_notify_audio_before_render(std::uint64_t notification_id)
{
    eos_clear_last_error();
    EOS_HRTCAudio audio = eos_rtc_audio_iface();
    if (audio) EOS_RTCAudio_RemoveNotifyAudioBeforeRender(audio, (EOS_NotificationId)notification_id);

    // Same reasoning as remove_notify_audio_before_send: locked so this can't delete ctx while
    // the callback (possibly on an SDK thread) is mid-copy of ctx->callback.
    std::lock_guard<std::mutex> lock(g_notify_mutex);
    auto it = g_rtc_audio_before_render_callbacks.find(notification_id);
    if (it != g_rtc_audio_before_render_callbacks.end()) {
        delete it->second;
        g_rtc_audio_before_render_callbacks.erase(it);
    }
}
