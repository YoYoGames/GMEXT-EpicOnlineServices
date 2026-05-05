#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_ui.h>

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

static EOS_HUI eos_ui_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetUIInterface(p) : nullptr;
}

template <typename Fn>
static std::string eos_ui_copy_string_with_fixed_retry(Fn&& call_fn, size_t initial_capacity = 256)
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

    return eos_ui_copy_string_with_fixed_retry(
        [&](char* out_buffer, int32_t* inout_len) -> EOS_EResult
        {
            return EOS_EpicAccountId_ToString(account_id, out_buffer, inout_len);
        });
}

static gm_structs::EpicUIShowFriendsCallbackInfo eos_ui_show_friends_info_from_native(
    const EOS_UI_ShowFriendsCallbackInfo* p)
{
    gm_structs::EpicUIShowFriendsCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.local_user_id = eos_epic_account_id_to_string_internal(p->LocalUserId);
    return out;
}

static gm_structs::EpicUIShowNativeProfileCallbackInfo eos_ui_show_native_profile_info_from_native(
    const EOS_UI_ShowNativeProfileCallbackInfo* p)
{
    gm_structs::EpicUIShowNativeProfileCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.local_user_id = eos_epic_account_id_to_string_internal(p->LocalUserId);
    out.target_user_id = eos_epic_account_id_to_string_internal(p->TargetUserId);
    return out;
}

static void EOS_CALL eos_ui_show_friends_callback_native(const EOS_UI_ShowFriendsCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(eos_ui_show_friends_info_from_native(data));
    delete ctx;
}

static void EOS_CALL eos_ui_show_native_profile_callback_native(const EOS_UI_ShowNativeProfileCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(eos_ui_show_native_profile_info_from_native(data));
    delete ctx;
}

// ============================================================
// EOS UI (Part 1)
// ============================================================

void eos_ui_show_friends(std::string_view local_user_id, const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HUI ui = eos_ui_iface();
    if (!ui) {
        eos_set_last_error("EOS UI interface unavailable.");
        return;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_UI_ShowFriends: invalid local_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_UI_ShowFriendsOptions opts{};
    opts.ApiVersion = EOS_UI_SHOWFRIENDS_API_LATEST;
    opts.LocalUserId = local_user;

    EOS_UI_ShowFriends(ui, &opts, ctx, &eos_ui_show_friends_callback_native);
}

void eos_ui_show_native_profile(
    std::string_view local_user_id,
    std::string_view target_user_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HUI ui = eos_ui_iface();
    if (!ui) {
        eos_set_last_error("EOS UI interface unavailable.");
        return;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    EOS_EpicAccountId target_user = eos_epic_account_id_from_string_internal(target_user_id);

    if (!local_user) {
        eos_set_last_error("EOS_UI_ShowNativeProfile: invalid local_user_id.");
        return;
    }

    if (!target_user) {
        eos_set_last_error("EOS_UI_ShowNativeProfile: invalid target_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_UI_ShowNativeProfileOptions opts{};
    opts.ApiVersion = EOS_UI_SHOWNATIVEPROFILE_API_LATEST;
    opts.LocalUserId = local_user;
    opts.TargetUserId = target_user;

    EOS_UI_ShowNativeProfile(ui, &opts, ctx, &eos_ui_show_native_profile_callback_native);
}

void eos_ui_acknowledge_event_id(uint64_t ui_event_id)
{
    eos_clear_last_error();

    EOS_HUI ui = eos_ui_iface();
    if (!ui) {
        eos_set_last_error("EOS UI interface unavailable.");
        return;
    }

    EOS_UI_AcknowledgeEventIdOptions opts{};
    opts.ApiVersion = EOS_UI_ACKNOWLEDGEEVENTID_API_LATEST;
    opts.UiEventId = (EOS_UI_EventId)ui_event_id;

    EOS_UI_AcknowledgeEventId(ui, &opts);
}

void eos_ui_set_display_preference(gm_enums::EpicUINotificationLocation notification_location)
{
    eos_clear_last_error();

    EOS_HUI ui = eos_ui_iface();
    if (!ui) {
        eos_set_last_error("EOS UI interface unavailable.");
        return;
    }

    EOS_UI_SetDisplayPreferenceOptions opts{};
    opts.ApiVersion = EOS_UI_SETDISPLAYPREFERENCE_API_LATEST;
    opts.NotificationLocation = (EOS_UI_ENotificationLocation)notification_location;

    EOS_UI_SetDisplayPreference(ui, &opts);
}

void eos_ui_report_input_state(bool button_down, bool button_up, bool button_left, bool button_right, bool button_accept, bool button_cancel)
{
    eos_clear_last_error();

    EOS_HUI ui = eos_ui_iface();
    if (!ui) {
        eos_set_last_error("EOS UI interface unavailable.");
        return;
    }

    using Flags = EOS_UI_EInputStateButtonFlags;
    Flags flags = Flags::EOS_UISBF_None;
    if (button_down)   flags = flags | Flags::EOS_UISBF_DPad_Down;
    if (button_up)     flags = flags | Flags::EOS_UISBF_DPad_Up;
    if (button_left)   flags = flags | Flags::EOS_UISBF_DPad_Left;
    if (button_right)  flags = flags | Flags::EOS_UISBF_DPad_Right;
    if (button_accept) flags = flags | Flags::EOS_UISBF_FaceButton_Bottom;
    if (button_cancel) flags = flags | Flags::EOS_UISBF_FaceButton_Right;

    EOS_UI_ReportInputStateOptions opts{};
    opts.ApiVersion = EOS_UI_REPORTINPUTSTATE_API_LATEST;
    opts.ButtonDownFlags = flags;
    opts.bAcceptIsFaceButtonRight = EOS_FALSE;
    opts.bMouseButtonDown = EOS_FALSE;
    opts.MousePosX = 0;
    opts.MousePosY = 0;
    opts.GamepadIndex = 0;
    opts.LeftStickX = 0.0f;
    opts.LeftStickY = 0.0f;
    opts.RightStickX = 0.0f;
    opts.RightStickY = 0.0f;
    opts.LeftTrigger = 0.0f;
    opts.RightTrigger = 0.0f;

    EOS_UI_ReportInputState(ui, &opts);
}

// ============================================================
// EOS UI (Part 2)
// ============================================================

static GMFunction g_cb_ui_display_settings_updated = nullptr;

static gm_structs::EpicUIDisplaySettingsUpdatedCallbackInfo eos_ui_display_settings_updated_info_from_native(
    const EOS_UI_OnDisplaySettingsUpdatedCallbackInfo* p)
{
    gm_structs::EpicUIDisplaySettingsUpdatedCallbackInfo out{};
    if (!p)
        return out;

    out.is_visible = p->bIsVisible;
    out.is_exclusive_input = p->bIsExclusiveInput;
    return out;
}

static void EOS_CALL eos_ui_display_settings_updated_callback_native(
    const EOS_UI_OnDisplaySettingsUpdatedCallbackInfo* data)
{
    if (!data || !g_cb_ui_display_settings_updated)
        return;

    g_cb_ui_display_settings_updated.call(
        eos_ui_display_settings_updated_info_from_native(data)
    );
}

uint64_t eos_ui_add_notify_display_settings_updated(const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HUI ui = eos_ui_iface();
    if (!ui) {
        eos_set_last_error("EOS UI interface unavailable.");
        return 0;
    }

    g_cb_ui_display_settings_updated = callback;

    EOS_UI_AddNotifyDisplaySettingsUpdatedOptions opts{};
    opts.ApiVersion = EOS_UI_ADDNOTIFYDISPLAYSETTINGSUPDATED_API_LATEST;

    return (uint64_t)EOS_UI_AddNotifyDisplaySettingsUpdated(
        ui,
        &opts,
        nullptr,
        &eos_ui_display_settings_updated_callback_native
    );
}

void eos_ui_remove_notify_display_settings_updated(uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HUI ui = eos_ui_iface();
    if (!ui) {
        eos_set_last_error("EOS UI interface unavailable.");
        return;
    }

    EOS_UI_RemoveNotifyDisplaySettingsUpdated(
        ui,
        (EOS_NotificationId)notification_id
    );
}

// ============================================================
// EOS UI (Part 3) — Additional functions
// ============================================================

static void EOS_CALL eos_ui_hide_friends_callback_native(const EOS_UI_HideFriendsCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicUIHideFriendsCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_epic_account_id_to_string_internal(data->LocalUserId);
    ctx->callback.call(out);
    delete ctx;
}

static void EOS_CALL eos_ui_show_block_player_callback_native(
    const EOS_UI_OnShowBlockPlayerCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicUIShowBlockPlayerCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_epic_account_id_to_string_internal(data->LocalUserId);
    out.target_user_id = eos_epic_account_id_to_string_internal(data->TargetUserId);
    ctx->callback.call(out);
    delete ctx;
}

static void EOS_CALL eos_ui_show_report_player_callback_native(
    const EOS_UI_OnShowReportPlayerCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicUIShowReportPlayerCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_epic_account_id_to_string_internal(data->LocalUserId);
    out.target_user_id = eos_epic_account_id_to_string_internal(data->TargetUserId);
    ctx->callback.call(out);
    delete ctx;
}

void eos_ui_hide_friends(std::string_view local_user_id, const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HUI ui = eos_ui_iface();
    if (!ui) {
        eos_set_last_error("EOS UI interface unavailable.");
        return;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_UI_HideFriends: invalid local_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_UI_HideFriendsOptions opts{};
    opts.ApiVersion = EOS_UI_HIDEFRIENDS_API_LATEST;
    opts.LocalUserId = local_user;

    EOS_UI_HideFriends(ui, &opts, ctx, &eos_ui_hide_friends_callback_native);
}

bool eos_ui_get_friends_visible(std::string_view local_user_id)
{
    eos_clear_last_error();

    EOS_HUI ui = eos_ui_iface();
    if (!ui) {
        eos_set_last_error("EOS UI interface unavailable.");
        return false;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_UI_GetFriendsVisible: invalid local_user_id.");
        return false;
    }

    EOS_UI_GetFriendsVisibleOptions opts{};
    opts.ApiVersion = EOS_UI_GETFRIENDSVISIBLE_API_LATEST;
    opts.LocalUserId = local_user;

    return EOS_UI_GetFriendsVisible(ui, &opts) == EOS_TRUE;
}

bool eos_ui_get_friends_exclusive_input(std::string_view local_user_id)
{
    eos_clear_last_error();

    EOS_HUI ui = eos_ui_iface();
    if (!ui) {
        eos_set_last_error("EOS UI interface unavailable.");
        return false;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_UI_GetFriendsExclusiveInput: invalid local_user_id.");
        return false;
    }

    EOS_UI_GetFriendsExclusiveInputOptions opts{};
    opts.ApiVersion = EOS_UI_GETFRIENDSEXCLUSIVEINPUT_API_LATEST;
    opts.LocalUserId = local_user;

    return EOS_UI_GetFriendsExclusiveInput(ui, &opts) == EOS_TRUE;
}

gm_enums::EpicResult eos_ui_pause_social_overlay(bool is_paused)
{
    eos_clear_last_error();

    EOS_HUI ui = eos_ui_iface();
    if (!ui) {
        eos_set_last_error("EOS UI interface unavailable.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_UI_PauseSocialOverlayOptions opts{};
    opts.ApiVersion = EOS_UI_PAUSESOCIALOVERLAY_API_LATEST;
    opts.bIsPaused = is_paused ? EOS_TRUE : EOS_FALSE;

    const EOS_EResult result = EOS_UI_PauseSocialOverlay(ui, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_UI_PauseSocialOverlay failed.");
    }
    return (gm_enums::EpicResult)result;
}

bool eos_ui_is_social_overlay_paused()
{
    eos_clear_last_error();

    EOS_HUI ui = eos_ui_iface();
    if (!ui) {
        eos_set_last_error("EOS UI interface unavailable.");
        return false;
    }

    EOS_UI_IsSocialOverlayPausedOptions opts{};
    opts.ApiVersion = EOS_UI_ISSOCIALOVERLAYPAUSED_API_LATEST;

    return EOS_UI_IsSocialOverlayPaused(ui, &opts) == EOS_TRUE;
}

gm_enums::EpicUINotificationLocation eos_ui_get_notification_location_preference()
{
    eos_clear_last_error();

    EOS_HUI ui = eos_ui_iface();
    if (!ui) {
        eos_set_last_error("EOS UI interface unavailable.");
        return (gm_enums::EpicUINotificationLocation)EOS_UI_ENotificationLocation::EOS_UNL_TopLeft;
    }

    return (gm_enums::EpicUINotificationLocation)EOS_UI_GetNotificationLocationPreference(ui);
}

void eos_ui_show_block_player(
    std::string_view local_user_id,
    std::string_view target_user_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HUI ui = eos_ui_iface();
    if (!ui) {
        eos_set_last_error("EOS UI interface unavailable.");
        return;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    EOS_EpicAccountId target_user = eos_epic_account_id_from_string_internal(target_user_id);

    if (!local_user) {
        eos_set_last_error("EOS_UI_ShowBlockPlayer: invalid local_user_id.");
        return;
    }
    if (!target_user) {
        eos_set_last_error("EOS_UI_ShowBlockPlayer: invalid target_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_UI_ShowBlockPlayerOptions opts{};
    opts.ApiVersion = EOS_UI_SHOWBLOCKPLAYER_API_LATEST;
    opts.LocalUserId = local_user;
    opts.TargetUserId = target_user;

    EOS_UI_ShowBlockPlayer(ui, &opts, ctx, &eos_ui_show_block_player_callback_native);
}

void eos_ui_show_report_player(
    std::string_view local_user_id,
    std::string_view target_user_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HUI ui = eos_ui_iface();
    if (!ui) {
        eos_set_last_error("EOS UI interface unavailable.");
        return;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    EOS_EpicAccountId target_user = eos_epic_account_id_from_string_internal(target_user_id);

    if (!local_user) {
        eos_set_last_error("EOS_UI_ShowReportPlayer: invalid local_user_id.");
        return;
    }
    if (!target_user) {
        eos_set_last_error("EOS_UI_ShowReportPlayer: invalid target_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_UI_ShowReportPlayerOptions opts{};
    opts.ApiVersion = EOS_UI_SHOWREPORTPLAYER_API_LATEST;
    opts.LocalUserId = local_user;
    opts.TargetUserId = target_user;

    EOS_UI_ShowReportPlayer(ui, &opts, ctx, &eos_ui_show_report_player_callback_native);
}
