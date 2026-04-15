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

    EOS_UI_ReportInputStateOptions opts{};
    opts.ApiVersion = EOS_UI_REPORTINPUTSTATE_API_LATEST;
    //TODO
	EOS_UI_EInputStateButtonFlags ButtonDownFlags;
	EOS_Bool bAcceptIsFaceButtonRight;
	EOS_Bool bMouseButtonDown;
	uint32_t MousePosX;
	uint32_t MousePosY;
	uint32_t GamepadIndex;
	float LeftStickX;
	float LeftStickY;
	float RightStickX;
	float RightStickY;
	float LeftTrigger;
	float RightTrigger;

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
