
// Sessions Interface
// Interface to handle session - based matchmaking

// Functions
// EOS_ActiveSession_CopyInfo
// EOS_ActiveSession_GetRegisteredPlayerByIndex
// EOS_ActiveSession_GetRegisteredPlayerCount
// EOS_ActiveSession_Info_Release
// EOS_ActiveSession_Release
// EOS_SessionDetails_Attribute_Release
// EOS_SessionDetails_CopyInfo
// EOS_SessionDetails_CopySessionAttributeByIndex
// EOS_SessionDetails_CopySessionAttributeByKey
// EOS_SessionDetails_GetSessionAttributeCount
// EOS_SessionDetails_Info_Release
// EOS_SessionDetails_Release
// EOS_SessionModification_AddAttribute
// EOS_SessionModification_Release
// EOS_SessionModification_RemoveAttribute
// EOS_SessionModification_SetAllowedPlatformIds
// EOS_SessionModification_SetBucketId
// EOS_SessionModification_SetHostAddress
// EOS_SessionModification_SetInvitesAllowed
// EOS_SessionModification_SetJoinInProgressAllowed
// EOS_SessionModification_SetMaxPlayers
// EOS_SessionModification_SetPermissionLevel
// EOS_Sessions_AddNotifyJoinSessionAccepted
// EOS_Sessions_AddNotifyLeaveSessionRequested
// EOS_Sessions_AddNotifySendSessionNativeInviteRequested
// EOS_Sessions_AddNotifySessionInviteAccepted
// EOS_Sessions_AddNotifySessionInviteReceived
// EOS_Sessions_AddNotifySessionInviteRejected
// EOS_Sessions_CopyActiveSessionHandle
// EOS_Sessions_CopySessionHandleByInviteId
// EOS_Sessions_CopySessionHandleByUiEventId
// EOS_Sessions_CopySessionHandleForPresence
// EOS_Sessions_CreateSessionModification
// EOS_Sessions_CreateSessionSearch
// EOS_Sessions_DestroySession
// EOS_Sessions_DumpSessionState
// EOS_Sessions_EndSession
// EOS_Sessions_GetInviteCount
// EOS_Sessions_GetInviteIdByIndex
// EOS_Sessions_IsUserInSession
// EOS_Sessions_JoinSession
// EOS_Sessions_QueryInvites
// EOS_Sessions_RegisterPlayers
// EOS_Sessions_RejectInvite
// EOS_Sessions_RemoveNotifyJoinSessionAccepted
// EOS_Sessions_RemoveNotifyLeaveSessionRequested
// EOS_Sessions_RemoveNotifySendSessionNativeInviteRequested
// EOS_Sessions_RemoveNotifySessionInviteAccepted
// EOS_Sessions_RemoveNotifySessionInviteReceived
// EOS_Sessions_RemoveNotifySessionInviteRejected
// EOS_Sessions_SendInvite
// EOS_Sessions_StartSession
// EOS_Sessions_UnregisterPlayers
// EOS_Sessions_UpdateSession
// EOS_Sessions_UpdateSessionModification
// EOS_SessionSearch_CopySearchResultByIndex
// EOS_SessionSearch_Find
// EOS_SessionSearch_GetSearchResultCount
// EOS_SessionSearch_Release
// EOS_SessionSearch_RemoveParameter
// EOS_SessionSearch_SetMaxResults
// EOS_SessionSearch_SetParameter
// EOS_SessionSearch_SetSessionId
// EOS_SessionSearch_SetTargetUserId
// EOS_SessionSearch_SetTargetUserIdOptions

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include "eos_sessions.h"

EOS_HSessions HSessions = 0;
void eos_sessions_init()
{
	HSessions = EOS_Platform_GetSessionsInterface(PlatformHandle);
}

func double __eos_active_session_copy_info(char* session_name, char* buff_ret)
{
	StructStream _struct = {};
	eos_not_init_return_buffer(buff_ret, _struct);

	EOS_Sessions_CopyActiveSessionHandleOptions HOptions = {0};
	HOptions.ApiVersion = EOS_SESSIONS_COPYACTIVESESSIONHANDLE_API_LATEST;
	HOptions.SessionName = session_name;
	EOS_HActiveSession HActiveSession;
	EOS_EResult result = EOS_Sessions_CopyActiveSessionHandle(HSessions, &HOptions, &HActiveSession);

	if (result != EOS_EResult::EOS_Success)
	{
		_struct.writeTo(buff_ret);
		return (double)result;
	}

	EOS_ActiveSession_CopyInfoOptions Options = {0};
	Options.ApiVersion = EOS_ACTIVESESSION_COPYINFO_API_LATEST;
	EOS_ActiveSession_Info *OutActiveSessionInfo;
	result = EOS_ActiveSession_CopyInfo(HActiveSession, &Options, &OutActiveSessionInfo);

	if (result != EOS_EResult::EOS_Success)
	{
		_struct.writeTo(buff_ret);
		return (double)result;
	}

	OutActiveSessionInfo->ApiVersion = EOS_ACTIVESESSION_INFO_API_LATEST;

	_struct.addKeyValue("local_user_id", (const char* )productID_toString(OutActiveSessionInfo->LocalUserId));

	StructStream _struct_session_details = {};
	if (OutActiveSessionInfo->SessionDetails->HostAddress != nullptr)
		_struct_session_details.addKeyValue("host_address", OutActiveSessionInfo->SessionDetails->HostAddress);
	if (OutActiveSessionInfo->SessionDetails->OwnerServerClientId != nullptr)
		_struct_session_details.addKeyValue("owner_server_client_id", OutActiveSessionInfo->SessionDetails->OwnerServerClientId);
	if (OutActiveSessionInfo->SessionDetails->OwnerUserId != nullptr)
		_struct_session_details.addKeyValue("owner_user_id", (const char*)productID_toString(OutActiveSessionInfo->SessionDetails->OwnerUserId));
	if (OutActiveSessionInfo->SessionDetails->SessionId != nullptr)
		_struct_session_details.addKeyValue("session_id", OutActiveSessionInfo->SessionDetails->SessionId);

	_struct_session_details.addKeyValue("num_open_public_connections", OutActiveSessionInfo->SessionDetails->NumOpenPublicConnections);

	StructStream _struct_settings = {};

	ArrayStream _array = {};
	for (uint32_t a = 0; a < OutActiveSessionInfo->SessionDetails->Settings->AllowedPlatformIdsCount; a++)
		_array << OutActiveSessionInfo->SessionDetails->Settings->AllowedPlatformIds[a];

	_struct_settings.addKeyValue("allowed_platform_ids", _array);
	_struct_settings.addKeyValue("allow_join_in_progress", OutActiveSessionInfo->SessionDetails->Settings->bAllowJoinInProgress);
	_struct_settings.addKeyValue("invites_allowed", OutActiveSessionInfo->SessionDetails->Settings->bInvitesAllowed);
	_struct_settings.addKeyValue("sanctions_enabled", OutActiveSessionInfo->SessionDetails->Settings->bSanctionsEnabled);
	_struct_settings.addKeyValue("bucket_id", (const char* )OutActiveSessionInfo->SessionDetails->Settings->BucketId);
	_struct_settings.addKeyValue("num_public_connections", OutActiveSessionInfo->SessionDetails->Settings->NumPublicConnections);
	_struct_settings.addKeyValue("permission_level", (int)OutActiveSessionInfo->SessionDetails->Settings->PermissionLevel);

	_struct_session_details.addKeyValue("settings", _struct_settings);
	_struct.addKeyValue("details", _struct_session_details);

	_struct.addKeyValue("session_name", (const char* )OutActiveSessionInfo->SessionName);
	_struct.addKeyValue("state", (double)OutActiveSessionInfo->State);

	_struct.writeTo(buff_ret);

	EOS_ActiveSession_Info_Release(OutActiveSessionInfo);

	EOS_ActiveSession_Release(HActiveSession);

	return 0.0;
}

func char* eos_active_session_get_registered_player_by_index(char* session_name, double player_index)
{
	eos_not_init_return((char*)"");

	EOS_Sessions_CopyActiveSessionHandleOptions HOptions = {0};
	HOptions.ApiVersion = EOS_SESSIONS_COPYACTIVESESSIONHANDLE_API_LATEST;
	HOptions.SessionName = session_name;
	EOS_HActiveSession HActiveSession;
	EOS_Sessions_CopyActiveSessionHandle(HSessions, &HOptions, &HActiveSession);

	EOS_ActiveSession_GetRegisteredPlayerByIndexOptions Options = {0};
	Options.PlayerIndex = static_cast<uint32_t>(player_index);
	EOS_ProductUserId ProductUserId = EOS_ActiveSession_GetRegisteredPlayerByIndex(HActiveSession, &Options);

	EOS_ActiveSession_Release(HActiveSession);

	return productID_toString(ProductUserId);
}

func double eos_active_session_get_registered_player_count(char* session_name)
{
	eos_not_init_return(-1);

	EOS_Sessions_CopyActiveSessionHandleOptions HOptions = {0};
	HOptions.ApiVersion = EOS_SESSIONS_COPYACTIVESESSIONHANDLE_API_LATEST;
	HOptions.SessionName = session_name;
	EOS_HActiveSession HActiveSession;

	EOS_EResult result = EOS_Sessions_CopyActiveSessionHandle(HSessions, &HOptions, &HActiveSession);

	if (result != EOS_EResult::EOS_Success)
		return 0;

	EOS_ActiveSession_GetRegisteredPlayerCountOptions *Options = {0};
	uint32_t count = EOS_ActiveSession_GetRegisteredPlayerCount(HActiveSession, Options);

	EOS_ActiveSession_Release(HActiveSession);

	return count;
}

//func double eos_active_session_release()
//{
//	EOS_HActiveSession ActiveSessionHandle = 0;
//	EOS_ActiveSession_Release(ActiveSessionHandle);
//	return 0.0;
//}

EOS_HSessionDetails mHSessionDetails = 0;
func double __eos_session_details_copy_info(char* buff_ret)
{
	StructStream _struct = {};
	eos_not_init_return_buffer(buff_ret, _struct);

	EOS_SessionDetails_CopyInfoOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONDETAILS_COPYINFO_API_LATEST;
	EOS_SessionDetails_Info *OutSessionInfo;

	EOS_EResult result = EOS_SessionDetails_CopyInfo(mHSessionDetails, &Options, &OutSessionInfo);

	if (EOS_EResult::EOS_Success == result)
	{
		if (OutSessionInfo->HostAddress != nullptr)
			_struct.addKeyValue("host_address", (const char*)OutSessionInfo->HostAddress);
		if (OutSessionInfo->OwnerUserId != nullptr)
			_struct.addKeyValue("owner_user_id", (const char*)productID_toString(OutSessionInfo->OwnerUserId));
		if (OutSessionInfo->OwnerServerClientId != nullptr)
			_struct.addKeyValue("owner_server_client_id", (const char*)OutSessionInfo->OwnerServerClientId);
		if (OutSessionInfo->SessionId != nullptr)
			_struct.addKeyValue("session_id", (const char*)OutSessionInfo->SessionId);

		_struct.addKeyValue("num_open_public_connections", OutSessionInfo->NumOpenPublicConnections);

		StructStream _struct_settings = {};

		ArrayStream _array = {};
		for (uint32_t a = 0; a < OutSessionInfo->Settings->AllowedPlatformIdsCount; a++)
			_array << OutSessionInfo->Settings->AllowedPlatformIds[a];

		_struct_settings.addKeyValue("allowed_platform_ids", _array);
		_struct_settings.addKeyValue("allow_join_in_progress", OutSessionInfo->Settings->bAllowJoinInProgress);
		_struct_settings.addKeyValue("invites_allowed", OutSessionInfo->Settings->bInvitesAllowed);
		_struct_settings.addKeyValue("sanctions_enabled", OutSessionInfo->Settings->bSanctionsEnabled);
		_struct_settings.addKeyValue("bucket_id", (const char* )OutSessionInfo->Settings->BucketId);
		_struct_settings.addKeyValue("num_public_connections", OutSessionInfo->Settings->NumPublicConnections);
		_struct_settings.addKeyValue("permission_level", (int)OutSessionInfo->Settings->PermissionLevel);

		_struct.addKeyValue("settings", _struct_settings);

		_struct.writeTo(buff_ret);

		EOS_SessionDetails_Info_Release(OutSessionInfo);
	}
	else
	{
		_struct.writeTo(buff_ret);
	}

	return (double)result;
}

void SessionDetailsAtrribute2StructStream(EOS_SessionDetails_Attribute *OutSessionAttribute, StructStream &outputSteam)
{
	outputSteam.addKeyValue("advertisement_type", (int)OutSessionAttribute->AdvertisementType);
	outputSteam.addKeyValue("key", OutSessionAttribute->Data->Key);
	switch (OutSessionAttribute->Data->ValueType)
	{
	case EOS_EAttributeType::EOS_AT_BOOLEAN:
		outputSteam.addKeyValue("value", (bool)OutSessionAttribute->Data->Value.AsBool);
		break;
	case EOS_EAttributeType::EOS_AT_DOUBLE:
		outputSteam.addKeyValue("value", OutSessionAttribute->Data->Value.AsDouble);
		break;
	case EOS_EAttributeType::EOS_AT_INT64:
		outputSteam.addKeyValue("value", OutSessionAttribute->Data->Value.AsInt64);
		break;
	case EOS_EAttributeType::EOS_AT_STRING:
		outputSteam.addKeyValue("value", OutSessionAttribute->Data->Value.AsUtf8);
		break;
	}
}

func double __eos_session_details_copy_session_attribute_by_index(double attr_index,char* buff_ret)
{
	StructStream _struct = {};
	eos_not_init_return_buffer(buff_ret, _struct);

	EOS_SessionDetails_CopySessionAttributeByIndexOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONDETAILS_COPYSESSIONATTRIBUTEBYINDEX_API_LATEST;
	Options.AttrIndex = (uint32_t)attr_index;
	EOS_SessionDetails_Attribute *OutSessionAttribute;

	EOS_SessionDetails_CopySessionAttributeByIndex(mHSessionDetails, &Options, &OutSessionAttribute);

	SessionDetailsAtrribute2StructStream(OutSessionAttribute, _struct);
	_struct.writeTo(buff_ret);

	return 0.0;
}

func double __eos_session_details_copy_session_attribute_by_key(char* attr_key,char* buff_ret)
{
	StructStream _struct = {};
	eos_not_init_return_buffer(buff_ret, _struct);

	EOS_SessionDetails_CopySessionAttributeByKeyOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONDETAILS_COPYSESSIONATTRIBUTEBYKEY_API_LATEST;
	Options.AttrKey = attr_key;
	EOS_SessionDetails_Attribute *OutSessionAttribute;

	EOS_SessionDetails_CopySessionAttributeByKey(mHSessionDetails, &Options, &OutSessionAttribute);

	SessionDetailsAtrribute2StructStream(OutSessionAttribute, _struct);
	_struct.writeTo(buff_ret);

	return 0.0;
}

func double eos_session_details_get_session_attribute_count()
{
	eos_not_init_return(-1);

	EOS_SessionDetails_GetSessionAttributeCountOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONDETAILS_GETSESSIONATTRIBUTECOUNT_API_LATEST;

	return EOS_SessionDetails_GetSessionAttributeCount(mHSessionDetails, &Options);
}

func double eos_session_details_release()
{
	eos_not_init_return(-1);

	EOS_SessionDetails_Release(mHSessionDetails);

	return 0.0;
}

EOS_Sessions_AttributeData SessionsAttributeDataFromStruct(std::map<std::string, const uint8_t *> &Attribute)
{
	EOS_Sessions_AttributeData mSessionAttribute = {0};

	mSessionAttribute.ApiVersion = EOS_SESSIONS_ATTRIBUTEDATA_API_LATEST;
	mSessionAttribute.Key = YYGetString(Attribute["key"]);

	switch ((int)YYGetReal(Attribute["value_type"]))
	{
	case 0:
		mSessionAttribute.ValueType = EOS_EAttributeType::EOS_AT_BOOLEAN;
		mSessionAttribute.Value.AsBool = YYGetBool(Attribute["value"]);
		break;
	case 1:
		mSessionAttribute.ValueType = EOS_EAttributeType::EOS_AT_INT64;
		mSessionAttribute.Value.AsInt64 = YYGetUint64(Attribute["value"]);
		break;
	case 2:
		mSessionAttribute.ValueType = EOS_EAttributeType::EOS_AT_DOUBLE;
		mSessionAttribute.Value.AsDouble = YYGetReal(Attribute["value"]);
		break;
	case 3:
		mSessionAttribute.ValueType = EOS_EAttributeType::EOS_AT_STRING;
		mSessionAttribute.Value.AsUtf8 = YYGetString(Attribute["value"]);
		break;
	}

	return mSessionAttribute;
}

EOS_HSessionModification mHSessionModification = 0;

func double __eos_session_modification_add_attribute(double advertisement_type,char* buff_args)
{
	eos_not_init_return(-1);

	EOS_SessionModification_AddAttributeOptions Options = {0};
	Options.AdvertisementType = (EOS_ESessionAttributeAdvertisementType)advertisement_type;
	Options.ApiVersion = EOS_SESSIONMODIFICATION_ADDATTRIBUTE_API_LATEST;

	auto args = buffer_unpack((uint8_t *)buff_args);
	auto Attribute = YYGetStruct(args[0]);

	EOS_Sessions_AttributeData mAttributeData = SessionsAttributeDataFromStruct(Attribute);

	Options.SessionAttribute = &mAttributeData;

	EOS_EResult result = EOS_SessionModification_AddAttribute(mHSessionModification, &Options);

	return (double)result;
}

func double eos_session_modification_release()
{
	eos_not_init_return(-1);

	EOS_SessionModification_Release(mHSessionModification);

	return 0.0;
}

func double eos_session_modification_remove_attribute(char* key)
{
	eos_not_init_return(-1);

	EOS_SessionModification_RemoveAttributeOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONMODIFICATION_REMOVEATTRIBUTE_API_LATEST;
	Options.Key = key;
	return (double)EOS_SessionModification_RemoveAttribute(mHSessionModification, &Options);
}

func double __eos_session_modification_set_allowed_platform_ids(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	auto array_ids = YYGetArray(args[0]);

	EOS_SessionModification_SetAllowedPlatformIdsOptions Options = {0};

	if (!array_ids.empty())
	{
		std::vector<uint32_t> ids = VectorUInt32FromVector(array_ids);
		Options.AllowedPlatformIds = ids.data();
		Options.AllowedPlatformIdsCount = (uint32_t)ids.size();
	}

	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETALLOWEDPLATFORMIDS_API_LATEST;
	return (double)EOS_SessionModification_SetAllowedPlatformIds(mHSessionModification, &Options);
}

func double eos_session_modification_set_bucket_id(char* bucket_id)
{
	eos_not_init_return(-1);

	EOS_SessionModification_SetBucketIdOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETBUCKETID_API_LATEST;
	Options.BucketId = bucket_id;
	return (double)EOS_SessionModification_SetBucketId(mHSessionModification, &Options);
}

func double eos_session_modification_set_host_address(char* host_address)
{
	eos_not_init_return(-1);

	EOS_SessionModification_SetHostAddressOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETHOSTADDRESS_API_LATEST;
	Options.HostAddress = host_address;
	return (double)EOS_SessionModification_SetHostAddress(mHSessionModification, &Options);
}

func double eos_session_modification_set_invites_allowed(double invites_allowed)
{
	eos_not_init_return(-1);

	EOS_SessionModification_SetInvitesAllowedOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETINVITESALLOWED_API_LATEST;
	Options.bInvitesAllowed = invites_allowed > 0.5;
	return (double)EOS_SessionModification_SetInvitesAllowed(mHSessionModification, &Options);
}

func double eos_session_modification_set_join_in_progress_allowed(double allow_join_in_progress)
{
	eos_not_init_return(-1);

	EOS_SessionModification_SetJoinInProgressAllowedOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETJOININPROGRESSALLOWED_API_LATEST;
	Options.bAllowJoinInProgress = allow_join_in_progress > 0.5;
	return (double)EOS_SessionModification_SetJoinInProgressAllowed(mHSessionModification, &Options);
}

func double eos_session_modification_set_max_players(double max_players)
{
	eos_not_init_return(-1);

	EOS_SessionModification_SetMaxPlayersOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETMAXPLAYERS_API_LATEST;
	Options.MaxPlayers = (int)max_players;
	return (double)EOS_SessionModification_SetMaxPlayers(mHSessionModification, &Options);
}

func double eos_session_modification_set_permission_level(double permission_level)
{
	eos_not_init_return(-1);

	EOS_SessionModification_SetPermissionLevelOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETPERMISSIONLEVEL_API_LATEST;
	Options.PermissionLevel = (EOS_EOnlineSessionPermissionLevel)permission_level;
	return (double)EOS_SessionModification_SetPermissionLevel(mHSessionModification, &Options);
}

void EOS_CALL Sessions_OnJoinSessionAcceptedCallback(const EOS_Sessions_JoinSessionAcceptedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_sessions_add_notify_join_session_accepted");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddInt64(map, "ui_event_id", (int64)data->UiEventId);

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_sessions_add_notify_join_session_accepted(char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_Sessions_AddNotifyJoinSessionAcceptedOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_ADDNOTIFYJOINSESSIONACCEPTED_API_LATEST;

	uint64_t notificationId = EOS_Sessions_AddNotifyJoinSessionAccepted(HSessions, &Options, nullptr /*mcallback*/, Sessions_OnJoinSessionAcceptedCallback);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL Sessions_LeaveSessionRequestedCallbackInfo(const EOS_Sessions_LeaveSessionRequestedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_sessions_add_notify_leave_session_requested");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "session_name", data->SessionName);

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_sessions_add_notify_leave_session_requested(char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_Sessions_AddNotifyLeaveSessionRequestedOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_ADDNOTIFYLEAVESESSIONREQUESTED_API_LATEST;

	uint64_t notificationId = EOS_Sessions_AddNotifyLeaveSessionRequested(HSessions, &Options, nullptr /*mcallback*/, Sessions_LeaveSessionRequestedCallbackInfo);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL Sessions_OnSendSessionNativeInviteRequestedCallback(const EOS_Sessions_SendSessionNativeInviteRequestedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_sessions_add_notify_send_session_native_invite_requested");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "target_native_account_type", data->TargetNativeAccountType);
	DsMapAddString(map, "target_user_native_account_id", data->TargetUserNativeAccountId);
	DsMapAddString(map, "session_id", data->SessionId);
	DsMapAddInt64(map, "ui_event_id", (int64)data->UiEventId);

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_sessions_add_notify_send_session_native_invite_requested(char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_Sessions_AddNotifySendSessionNativeInviteRequestedOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_ADDNOTIFYSENDSESSIONNATIVEINVITEREQUESTED_API_LATEST;
	uint64_t notificationId = EOS_Sessions_AddNotifySendSessionNativeInviteRequested(HSessions, &Options, nullptr /*mcallback*/, Sessions_OnSendSessionNativeInviteRequestedCallback);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL Sessions_SessionInviteAcceptedCallbackInfo(const EOS_Sessions_SessionInviteAcceptedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_sessions_add_notify_session_invite_accepted");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "invite_id", data->InviteId);
	DsMapAddString(map, "session_id", data->SessionId);
	DsMapAddString(map, "target_user_id", productID_toString(data->TargetUserId));

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_sessions_add_notify_session_invite_accepted(char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_Sessions_AddNotifySessionInviteAcceptedOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_ADDNOTIFYSESSIONINVITEACCEPTED_API_LATEST;

	uint64_t notificationId = EOS_Sessions_AddNotifySessionInviteAccepted(HSessions, &Options, nullptr /*mcallback*/, Sessions_SessionInviteAcceptedCallbackInfo);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL Sessions_OnSessionInviteReceivedCallback(const EOS_Sessions_SessionInviteReceivedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_sessions_add_notify_session_invite_received");
	DsMapAddString(map, "invite_id", data->InviteId);
	DsMapAddString(map, "target_user_id", productID_toString(data->TargetUserId));
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_sessions_add_notify_session_invite_received(char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_Sessions_AddNotifySessionInviteReceivedOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_ADDNOTIFYSESSIONINVITERECEIVED_API_LATEST;
	uint64_t notificationId = EOS_Sessions_AddNotifySessionInviteReceived(HSessions, &Options, nullptr /*mcallback*/, Sessions_OnSessionInviteReceivedCallback);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL Sessions_OnSessionInviteRejectedCallback(const EOS_Sessions_SessionInviteRejectedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_sessions_add_notify_session_invite_rejected");
	DsMapAddString(map, "invite_id", data->InviteId);
	DsMapAddString(map, "target_user_id", productID_toString(data->TargetUserId));
	DsMapAddString(map, "session_id", data->SessionId);
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_sessions_add_notify_session_invite_rejected(char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_Sessions_AddNotifySessionInviteRejectedOptions Options = {0};

	uint64_t notificationId = EOS_Sessions_AddNotifySessionInviteRejected(HSessions, &Options, nullptr /*mcallback*/, Sessions_OnSessionInviteRejectedCallback);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

func double eos_sessions_copy_session_handle_by_invite_id(char* invite_id)
{
	eos_not_init_return(-1);

	EOS_Sessions_CopySessionHandleByInviteIdOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_COPYSESSIONHANDLEBYINVITEID_API_LATEST;
	Options.InviteId = invite_id;

	double result = (double)EOS_Sessions_CopySessionHandleByInviteId(HSessions, &Options, &mHSessionDetails);

	return (double)result;
}

func double __eos_sessions_copy_session_handle_by_ui_event_id(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_UI_EventId InId = YYGetUint64(args[0]);

	EOS_Sessions_CopySessionHandleByUiEventIdOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_COPYSESSIONHANDLEBYUIEVENTID_API_LATEST;
	Options.UiEventId = InId;

	double result = (double)EOS_Sessions_CopySessionHandleByUiEventId(HSessions, &Options, &mHSessionDetails);

	return (double)result;
}

func double eos_sessions_copy_session_handle_for_presence(char* local)
{
	eos_not_init_return(-1);

	EOS_Sessions_CopySessionHandleForPresenceOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_COPYSESSIONHANDLEFORPRESENCE_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local);

	double result = (double)EOS_Sessions_CopySessionHandleForPresence(HSessions, &Options, &mHSessionDetails);

	return (double)result;
}

func double __eos_sessions_create_session_modification(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);

	EOS_Sessions_CreateSessionModificationOptions Options{};
	Options.ApiVersion = EOS_SESSIONS_CREATESESSIONMODIFICATION_API_LATEST;

	auto array_ids = YYGetArray(args[0]);

	if (!array_ids.empty())
	{
		std::vector<uint32_t> ids = VectorUInt32FromVector(array_ids);
		Options.AllowedPlatformIds = ids.data();
		Options.AllowedPlatformIdsCount = (uint32_t)ids.size();
	}

	Options.bPresenceEnabled = YYGetBool(args[1]);
	Options.bSanctionsEnabled = YYGetBool(args[2]);
	Options.BucketId = YYGetString(args[3]);
	Options.LocalUserId = EOS_ProductUserId_FromString(YYGetString(args[4]));
	Options.MaxPlayers = YYGetUint32(args[5]);

	const char* session_id = YYGetString(args[6]);
	Options.SessionId = strcmp(session_id, "") == 0 ? nullptr : session_id;

	Options.SessionName = YYGetString(args[7]);
	double result = (double)EOS_Sessions_CreateSessionModification(HSessions, &Options, &mHSessionModification);

	return (double)result;
}

EOS_HSessionSearch mOutSessionSearchHandle = 0;
func double eos_sessions_create_session_search(double max_search_results)
{
	eos_not_init_return(-1);

	EOS_Sessions_CreateSessionSearchOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_CREATESESSIONSEARCH_API_LATEST;
	Options.MaxSearchResults = (uint32_t)max_search_results;
	double result = (double)EOS_Sessions_CreateSessionSearch(HSessions, &Options, &mOutSessionSearchHandle);

	return result;
}

void EOS_CALL Sessions_OnDestroySessionCallback(const EOS_Sessions_DestroySessionCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_sessions_destroy_session");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_sessions_destroy_session(char* session_name)
{
	eos_not_init_return(-1);

	EOS_Sessions_DestroySessionOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_DESTROYSESSION_API_LATEST;
	Options.SessionName = session_name;

	callback *mcallback = getCallbackData();

	EOS_Sessions_DestroySession(HSessions, &Options, mcallback, Sessions_OnDestroySessionCallback);

	return mcallback->identifier;
}

func double eos_sessions_dump_session_state(char* session_name)
{
	eos_not_init_return(-1);

	EOS_Sessions_DumpSessionStateOptions Options{0};
	Options.ApiVersion = EOS_SESSIONS_DUMPSESSIONSTATE_API_LATEST;
	Options.SessionName = session_name;
	return (double)EOS_Sessions_DumpSessionState(HSessions, &Options);
}

void EOS_CALL Sessions_OnEndSessionCallback(const EOS_Sessions_EndSessionCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_sessions_end_session");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_sessions_end_session(char* session_name)
{
	eos_not_init_return(-1);

	EOS_Sessions_EndSessionOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_ENDSESSION_API_LATEST;
	Options.SessionName = session_name;

	callback *mcallback = getCallbackData();

	EOS_Sessions_EndSession(HSessions, &Options, mcallback, Sessions_OnEndSessionCallback);

	return mcallback->identifier;
}

func double eos_sessions_get_invite_count(char* local)
{
	eos_not_init_return(-1);

	EOS_Sessions_GetInviteCountOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_GETINVITECOUNT_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local);

	return EOS_Sessions_GetInviteCount(HSessions, &Options);
}

func char* eos_sessions_get_invite_id_by_index(char* local_user_id, double index)
{
	eos_not_init_return((char*)"");
	
	static char TempBuffer[EOS_SESSIONS_INVITEID_MAX_LENGTH];
	int32_t TempBufferSize = sizeof(TempBuffer);

	EOS_Sessions_GetInviteIdByIndexOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_GETINVITEIDBYINDEX_API_LATEST;
	Options.Index = (int)index;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);

	EOS_Sessions_GetInviteIdByIndex(HSessions, &Options, TempBuffer, &TempBufferSize);

	return TempBuffer;
}

func double eos_sessions_is_user_in_session(char* session_name,char* target_user_id)
{
	eos_not_init_return(-1);

	EOS_Sessions_IsUserInSessionOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_ISUSERINSESSION_API_LATEST;
	Options.SessionName = session_name;
	Options.TargetUserId = EOS_ProductUserId_FromString(target_user_id);

	return (double)EOS_Sessions_IsUserInSession(HSessions, &Options);
}

void EOS_CALL Sessions_OnJoinSessionCallback(const EOS_Sessions_JoinSessionCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_sessions_join_session");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_sessions_join_session(double presence_enabled,char* local_user_id,char* session_name)
{
	eos_not_init_return(-1);

	EOS_Sessions_JoinSessionOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_JOINSESSION_API_LATEST;
	Options.bPresenceEnabled = (EOS_Bool)presence_enabled;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.SessionHandle = mHSessionDetails;
	Options.SessionName = session_name;

	callback *mcallback = getCallbackData();

	EOS_Sessions_JoinSession(HSessions, &Options, mcallback, Sessions_OnJoinSessionCallback);

	return mcallback->identifier;
}

void EOS_CALL Sessions_OnQueryInvitesCallback(const EOS_Sessions_QueryInvitesCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_sessions_query_invites");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_sessions_query_invites(char* target_user_id)
{
	eos_not_init_return(-1);

	EOS_Sessions_QueryInvitesOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_QUERYINVITES_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(target_user_id);

	callback *mcallback = getCallbackData();

	EOS_Sessions_QueryInvites(HSessions, &Options, mcallback, Sessions_OnQueryInvitesCallback);

	return mcallback->identifier;
}

void EOS_CALL Sessions_OnRegisterPlayersCallback(const EOS_Sessions_RegisterPlayersCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_sessions_register_players");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

	RValue registeredPlayers{};
	ProductIdsToArray(registeredPlayers, data->RegisteredPlayers, data->RegisteredPlayersCount);
	DsMapAddRValue(map, "registered_players", &registeredPlayers);

	RValue sanctionedPlayers{};
	ProductIdsToArray(sanctionedPlayers, data->SanctionedPlayers, data->SanctionedPlayersCount);
	DsMapAddRValue(map, "sanctioned_players", &sanctionedPlayers);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double __eos_sessions_register_players(char* session_name,char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	auto array_ids = YYGetArray(args[0]);

	std::vector<EOS_ProductUserId> p_ids = VectorProductIdsFromVector(array_ids);

	EOS_Sessions_RegisterPlayersOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_REGISTERPLAYERS_API_LATEST;
	Options.PlayersToRegister = p_ids.data();
	Options.PlayersToRegisterCount = (uint32_t)p_ids.size();
	Options.SessionName = session_name;

	callback *mcallback = getCallbackData();
	EOS_Sessions_RegisterPlayers(HSessions, &Options, mcallback, Sessions_OnRegisterPlayersCallback);

	return mcallback->identifier;
}

void EOS_CALL Sessions_OnRejectInvite(const EOS_Sessions_RejectInviteCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_sessions_reject_invite");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_sessions_reject_invite(char* local_user_id,char* invite_id)
{
	eos_not_init_return(-1);

	EOS_Sessions_RejectInviteOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_REJECTINVITE_API_LATEST;
	Options.InviteId = invite_id;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);

	callback *mcallback = getCallbackData();
	EOS_Sessions_RejectInvite(HSessions, &Options, mcallback, Sessions_OnRejectInvite);

	return mcallback->identifier;
}

func double __eos_sessions_remove_notify_join_session_accepted(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Sessions_RemoveNotifyJoinSessionAccepted(HSessions, InId);

	return 0.0;
}

func double __eos_sessions_remove_notify_leave_session_requested(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Sessions_RemoveNotifyLeaveSessionRequested(HSessions, InId);
	return 0.0;
}

func double __eos_sessions_remove_notify_send_session_native_invite_requested(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Sessions_RemoveNotifySendSessionNativeInviteRequested(HSessions, InId);
	return 0.0;
}

func double __eos_sessions_remove_notify_session_invite_accepted(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);
	EOS_Sessions_RemoveNotifySessionInviteAccepted(HSessions, InId);

	return 0.0;
}

func double __eos_sessions_remove_notify_session_invite_received(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);
	EOS_Sessions_RemoveNotifySessionInviteReceived(HSessions, InId);

	return 0.0;
}

func double __eos_sessions_remove_notify_session_invite_rejected(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);
	EOS_Sessions_RemoveNotifySessionInviteRejected(HSessions, InId);

	return 0.0;
}

void EOS_CALL Sessions_OnSendInviteCallback(const EOS_Sessions_SendInviteCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_sessions_send_invite");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_sessions_send_invite(char* local_user_id,char* session_name,char* target_user_id)
{
	eos_not_init_return(-1);

	EOS_Sessions_SendInviteOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_SENDINVITE_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.SessionName = session_name;
	Options.TargetUserId = EOS_ProductUserId_FromString(target_user_id);

	callback *mcallback = getCallbackData();
	EOS_Sessions_SendInvite(HSessions, &Options, mcallback, Sessions_OnSendInviteCallback);

	return (double)mcallback->identifier;
}

void EOS_CALL Sessions_OnStartSessionCallback(const EOS_Sessions_StartSessionCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_sessions_start_session");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_sessions_start_session(char* session_name)
{
	eos_not_init_return(-1);

	EOS_Sessions_StartSessionOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_STARTSESSION_API_LATEST;
	Options.SessionName = session_name;

	callback *mcallback = getCallbackData();
	EOS_Sessions_StartSession(HSessions, &Options, mcallback, Sessions_OnStartSessionCallback);

	return mcallback->identifier;
}

void EOS_CALL Sessions_OnUnregisterPlayersCallback(const EOS_Sessions_UnregisterPlayersCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_sessions_unregister_players");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

	RValue unregisteredPlayers{};
	ProductIdsToArray(unregisteredPlayers, data->UnregisteredPlayers, data->UnregisteredPlayersCount);
	DsMapAddRValue(map, "unregistered_players", &unregisteredPlayers);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double __eos_sessions_unregister_players(char* session_name,char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	auto array_ids = YYGetArray(args[0]);

	std::vector<EOS_ProductUserId> p_ids = VectorProductIdsFromVector(array_ids);

	EOS_Sessions_UnregisterPlayersOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_UNREGISTERPLAYERS_API_LATEST;
	Options.PlayersToUnregister = p_ids.data();
	Options.PlayersToUnregisterCount = (uint32_t)p_ids.size();
	Options.SessionName = session_name;

	callback *mcallback = getCallbackData();

	EOS_Sessions_UnregisterPlayers(HSessions, &Options, mcallback, Sessions_OnUnregisterPlayersCallback);

	return mcallback->identifier;
}

void EOS_CALL Sessions_OnUpdateSessionCallback(const EOS_Sessions_UpdateSessionCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_sessions_update_session");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "session_id", data->SessionId);
	DsMapAddString(map, "session_name", data->SessionName);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_sessions_update_session()
{
	eos_not_init_return(-1);

	EOS_Sessions_UpdateSessionOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_UPDATESESSION_API_LATEST;
	Options.SessionModificationHandle = mHSessionModification;

	callback *mcallback = getCallbackData();
	EOS_Sessions_UpdateSession(HSessions, &Options, mcallback, Sessions_OnUpdateSessionCallback);

	return mcallback->identifier;
}

func double eos_sessions_update_session_modification(char* session_name)
{
	eos_not_init_return(-1);

	EOS_Sessions_UpdateSessionModificationOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_UPDATESESSIONMODIFICATION_API_LATEST;
	Options.SessionName = session_name;

	return (double)EOS_Sessions_UpdateSessionModification(HSessions, &Options, &mHSessionModification);
}

func double eos_session_search_copy_search_result_by_index(double session_index)
{
	eos_not_init_return(-1);
	
	EOS_SessionSearch_CopySearchResultByIndexOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONSEARCH_COPYSEARCHRESULTBYINDEX_API_LATEST;
	Options.SessionIndex = (uint32_t)session_index;

	double result = (double)EOS_SessionSearch_CopySearchResultByIndex(mOutSessionSearchHandle, &Options, &mHSessionDetails);

	return result;
}

void EOS_CALL SessionSearch_OnFindCallback(const EOS_SessionSearch_FindCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_session_search_find");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_session_search_find(char* local_user_id)
{
	eos_not_init_return(-1);

	EOS_SessionSearch_FindOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONSEARCH_FIND_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);

	callback *mcallback = getCallbackData();

	EOS_SessionSearch_Find(mOutSessionSearchHandle, &Options, mcallback, SessionSearch_OnFindCallback);

	return mcallback->identifier;
}

func double eos_session_search_get_search_result_count()
{
	eos_not_init_return(-1);

	EOS_SessionSearch_GetSearchResultCountOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONSEARCH_GETSEARCHRESULTCOUNT_API_LATEST;

	return EOS_SessionSearch_GetSearchResultCount(mOutSessionSearchHandle, &Options);
}

func double eos_session_search_release()
{
	EOS_SessionSearch_Release(mOutSessionSearchHandle);
	return 0.0;
}

func double eos_session_search_remove_parameter(char* key, double comparison_op)
{
	eos_not_init_return(-1);

	EOS_SessionSearch_RemoveParameterOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONSEARCH_REMOVEPARAMETER_API_LATEST;
	Options.ComparisonOp = (EOS_EOnlineComparisonOp)comparison_op;
	Options.Key = key;

	return (double)EOS_SessionSearch_RemoveParameter(mOutSessionSearchHandle, &Options);
}

func double eos_session_search_set_max_results(double MaxSearchResults)
{
	eos_not_init_return(-1);

	EOS_SessionSearch_SetMaxResultsOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONSEARCH_SETMAXSEARCHRESULTS_API_LATEST;
	Options.MaxSearchResults = (uint32_t)MaxSearchResults;

	return (double)EOS_SessionSearch_SetMaxResults(mOutSessionSearchHandle, &Options);
}

func double __eos_session_search_set_parameter(double comparisonOp,char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	auto Attribute = YYGetStruct(args[0]);

	EOS_SessionSearch_SetParameterOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONSEARCH_SETPARAMETER_API_LATEST;
	Options.ComparisonOp = (EOS_EComparisonOp)comparisonOp;

	EOS_Sessions_AttributeData mAttributeData = SessionsAttributeDataFromStruct(Attribute);
	Options.Parameter = &mAttributeData;

	return (double)EOS_SessionSearch_SetParameter(mOutSessionSearchHandle, &Options);
}

func double eos_session_search_set_session_id(char* SessionId)
{
	eos_not_init_return(-1);

	EOS_SessionSearch_SetSessionIdOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONSEARCH_SETSESSIONID_API_LATEST;
	Options.SessionId = SessionId;

	return (double)EOS_SessionSearch_SetSessionId(mOutSessionSearchHandle, &Options);
}

func double eos_session_search_set_target_user_id(char* target_user_id)
{
	eos_not_init_return(-1);
	
	EOS_SessionSearch_SetTargetUserIdOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONSEARCH_SETTARGETUSERID_API_LATEST;
	Options.TargetUserId = EOS_ProductUserId_FromString(target_user_id);

	return (double)EOS_SessionSearch_SetTargetUserId(mOutSessionSearchHandle, &Options);
}
