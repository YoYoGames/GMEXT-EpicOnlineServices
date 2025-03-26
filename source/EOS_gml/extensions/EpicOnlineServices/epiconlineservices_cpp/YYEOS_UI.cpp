//
// EOS_UI_AcknowledgeEventId
// EOS_UI_AddNotifyDisplaySettingsUpdated
// EOS_UI_GetFriendsVisible
// EOS_UI_GetNotificationLocationPreference
// EOS_UI_GetToggleFriendsKey
// EOS_UI_HideFriends
// EOS_UI_IsValidKeyCombination
// EOS_UI_RemoveNotifyDisplaySettingsUpdated
// EOS_UI_SetDisplayPreference
// EOS_UI_SetToggleFriendsKey
// EOS_UI_ShowFriends

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include <eos_ui.h>

EOS_HUI HUI;
void eos_ui_init()
{
	HUI = EOS_Platform_GetUIInterface(PlatformHandle);
}

void AcknowledgeEventId(EOS_UI_EventId JoinUiEvent, EOS_EResult Result)
{
	if (JoinUiEvent != EOS_UI_EVENTID_INVALID)
	{
		EOS_UI_AcknowledgeEventIdOptions Options = {};
		Options.ApiVersion = EOS_UI_ACKNOWLEDGECORRELATIONID_API_LATEST;
		Options.UiEventId = JoinUiEvent;
		Options.Result = Result;

		EOS_UI_AcknowledgeEventId(HUI, &Options);

		JoinUiEvent = EOS_UI_EVENTID_INVALID;
	}
}

void EOS_CALL OnDisplaySettingsUpdated(const EOS_UI_OnDisplaySettingsUpdatedCallbackInfo *UpdatedData)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_ui_add_notify_display_settings_updated");
	DsMapAddDouble(map, "is_exclusive_input", UpdatedData->bIsExclusiveInput ? 1.0 : 0.0);
	DsMapAddDouble(map, "is_visible", UpdatedData->bIsVisible);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void eos_ui_add_notify_display_settings_updated(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_int64;

	EOS_UI_AddNotifyDisplaySettingsUpdatedOptions Options = {};
	Options.ApiVersion = EOS_UI_ADDNOTIFYDISPLAYSETTINGSUPDATED_API_LATEST;

	EOS_NotificationId DisplayUpdateNotificationId = EOS_UI_AddNotifyDisplaySettingsUpdated(HUI, &Options, nullptr, OnDisplaySettingsUpdated);

	Result.kind = VALUE_INT64;
	Result.v64 = static_cast<int64_t>(DisplayUpdateNotificationId);
}

YYEXPORT void eos_ui_get_friends_visible(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_bool;

	eos_ensure_argc(1);

	const char *user = YYGetString(arg, 0);

	EOS_UI_GetFriendsVisibleOptions Options = {0};
	Options.ApiVersion = EOS_UI_GETFRIENDSVISIBLE_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);

	Result.kind = VALUE_BOOL;
	Result.val = EOS_UI_GetFriendsVisible(HUI, &Options);
}

YYEXPORT void eos_ui_get_notification_location_preference(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	Result.kind = VALUE_REAL;
	Result.val = (double)EOS_UI_GetNotificationLocationPreference(HUI);
}

YYEXPORT void eos_ui_get_toggle_friends_key(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_int32;

	EOS_UI_GetToggleFriendsKeyOptions Options = {0};
	Options.ApiVersion = EOS_UI_GETTOGGLEFRIENDSKEY_API_LATEST;

	Result.kind = VALUE_INT32;
	Result.v32 = (int32)EOS_UI_GetToggleFriendsKey(HUI, &Options);
}

void EOS_CALL HideFriends(const EOS_UI_HideFriendsCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "HideFriends");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_ui_hide_friends(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	const char *user = YYGetString(arg, 0);

	EOS_UI_HideFriendsOptions Options = {0};
	Options.ApiVersion = EOS_UI_HIDEFRIENDS_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);

	callback *mcallback = getCallbackData();

	EOS_UI_HideFriends(HUI, &Options, mcallback, HideFriends);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

YYEXPORT void eos_ui_is_valid_key_combination(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_bool;

	eos_ensure_argc(1);

	int32 keycombination = YYGetInt32(arg, 0);

	Result.kind = VALUE_BOOL;
	Result.val = EOS_UI_IsValidKeyCombination(HUI, (EOS_UI_EKeyCombination)keycombination);
}

YYEXPORT void eos_ui_remove_notify_display_settings_updated(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_bool;

	eos_ensure_argc(1);

	int64 DisplayUpdateNotificationId = YYGetInt64(arg, 0);

	EOS_UI_RemoveNotifyDisplaySettingsUpdated(HUI, DisplayUpdateNotificationId);
}

YYEXPORT void eos_ui_set_display_preference(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(1);

	int32_t Location = YYGetInt32(arg, 0);

	EOS_UI_SetDisplayPreferenceOptions Options = {};
	Options.ApiVersion = EOS_UI_SETDISPLAYPREFERENCE_API_LATEST;
	Options.NotificationLocation = (EOS_UI_ENotificationLocation)Location;

	const EOS_EResult result = EOS_UI_SetDisplayPreference(HUI, &Options);

	return_EOS_EResult(&Result, result);
}

YYEXPORT void eos_ui_set_toggle_friends_key(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(1);

	int32_t KeyCombination = YYGetInt32(arg, 0);

	EOS_UI_SetToggleFriendsKeyOptions Options = {};
	Options.ApiVersion = EOS_UI_SETTOGGLEFRIENDSKEY_API_LATEST;
	Options.KeyCombination = (EOS_UI_EKeyCombination)KeyCombination;

	EOS_EResult EResult = EOS_UI_SetToggleFriendsKey(HUI, &Options);

	return_EOS_EResult(&Result, EResult);
}

void EOS_CALL ShowFriendsCallbackFn(const EOS_UI_ShowFriendsCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_ui_show_friends");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_ui_show_friends(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	const char *user = YYGetString(arg, 0);

	EOS_UI_ShowFriendsOptions Options = {};
	Options.ApiVersion = EOS_UI_SHOWFRIENDS_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);

	callback *mcallback = getCallbackData();

	EOS_UI_ShowFriends(HUI, &Options, mcallback, ShowFriendsCallbackFn);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}
