
// Lobbies Interface
// Interface to handle lobbies

// EOS_Lobby_AddNotifyJoinLobbyAccepted
// EOS_Lobby_AddNotifyLeaveLobbyRequested
// EOS_Lobby_AddNotifyLobbyInviteAccepted
// EOS_Lobby_AddNotifyLobbyInviteReceived
// EOS_Lobby_AddNotifyLobbyInviteRejected
// EOS_Lobby_AddNotifyLobbyMemberStatusReceived
// EOS_Lobby_AddNotifyLobbyMemberUpdateReceived
// EOS_Lobby_AddNotifyLobbyUpdateReceived
// EOS_Lobby_AddNotifyRTCRoomConnectionChanged
// EOS_Lobby_AddNotifySendLobbyNativeInviteRequested
// EOS_Lobby_Attribute_Release
// EOS_Lobby_CopyLobbyDetailsHandle
// EOS_Lobby_CopyLobbyDetailsHandleByInviteId
// EOS_Lobby_CopyLobbyDetailsHandleByUiEventId
// EOS_Lobby_CreateLobby
// EOS_Lobby_CreateLobbySearch
// EOS_Lobby_DestroyLobby
// EOS_Lobby_GetConnectString
// EOS_Lobby_GetInviteCount
// EOS_Lobby_GetInviteIdByIndex
// EOS_Lobby_GetRTCRoomName
// EOS_Lobby_HardMuteMember
// EOS_Lobby_IsRTCRoomConnected
// EOS_Lobby_JoinLobby
// EOS_Lobby_JoinLobbyById
// EOS_Lobby_KickMember
// EOS_Lobby_LeaveLobby
// EOS_Lobby_ParseConnectString
// EOS_Lobby_PromoteMember
// EOS_Lobby_QueryInvites
// EOS_Lobby_RejectInvite
// EOS_Lobby_RemoveNotifyJoinLobbyAccepted
// EOS_Lobby_RemoveNotifyLeaveLobbyRequested
// EOS_Lobby_RemoveNotifyLobbyInviteAccepted
// EOS_Lobby_RemoveNotifyLobbyInviteReceived
// EOS_Lobby_RemoveNotifyLobbyInviteRejected
// EOS_Lobby_RemoveNotifyLobbyMemberStatusReceived
// EOS_Lobby_RemoveNotifyLobbyMemberUpdateReceived
// EOS_Lobby_RemoveNotifyLobbyUpdateReceived
// EOS_Lobby_RemoveNotifyRTCRoomConnectionChanged
// EOS_Lobby_RemoveNotifySendLobbyNativeInviteRequested
// EOS_Lobby_SendInvite
// EOS_Lobby_UpdateLobby
// EOS_Lobby_UpdateLobbyModification
// EOS_LobbyDetails_CopyAttributeByIndex
// EOS_LobbyDetails_CopyAttributeByKey
// EOS_LobbyDetails_CopyInfo
// EOS_LobbyDetails_CopyMemberAttributeByIndex
// EOS_LobbyDetails_CopyMemberAttributeByKey
// EOS_LobbyDetails_CopyMemberInfo
// EOS_LobbyDetails_GetAttributeCount
// EOS_LobbyDetails_GetLobbyOwner
// EOS_LobbyDetails_GetMemberAttributeCount
// EOS_LobbyDetails_GetMemberByIndex
// EOS_LobbyDetails_GetMemberCount
// EOS_LobbyDetails_Info_Release
// EOS_LobbyDetails_MemberInfo_Release
// EOS_LobbyDetails_Release
// EOS_LobbyModification_AddAttribute
// EOS_LobbyModification_AddMemberAttribute
// EOS_LobbyModification_Release
// EOS_LobbyModification_RemoveAttribute
// EOS_LobbyModification_RemoveMemberAttribute
// EOS_LobbyModification_SetAllowedPlatformIds
// EOS_LobbyModification_SetBucketId
// EOS_LobbyModification_SetInvitesAllowed
// EOS_LobbyModification_SetMaxMembers
// EOS_LobbyModification_SetPermissionLevel
// EOS_LobbySearch_CopySearchResultByIndex
// EOS_LobbySearch_Find
// EOS_LobbySearch_GetSearchResultCount
// EOS_LobbySearch_Release
// EOS_LobbySearch_RemoveParameter
// EOS_LobbySearch_Setlobby_id
// EOS_LobbySearch_SetMaxResults
// EOS_LobbySearch_SetParameter
// EOS_LobbySearch_Settarget_user_id
// EOS_LobbySearch_Settarget_user_idOptions

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include "eos_lobby.h"

EOS_HLobbyDetails mHLobbyDetails = nullptr;
#define eos_assert_lobby_details(value)               \
	if (!mHLobbyDetails)                              \
	{                                                 \
		TRACE("Couldn't find lobby details handle."); \
		return value;                                 \
	}
#define eos_assert_not_lobby_details(value)                   \
	if (mHLobbyDetails)                                       \
	{                                                         \
		TRACE("Previous lobby details handle not released."); \
		return value;                                         \
	}

EOS_HLobbySearch mHLobbySearch = nullptr;
#define eos_assert_lobby_search(value)                                            \
	if (!mHLobbySearch)                                                           \
	{                                                                             \
		DebugConsoleOutput("%s :: Couldn't find lobby search handle.", __func__); \
		return value;                                                             \
	}
#define eos_assert_not_lobby_search(value)                                               \
	if (mHLobbySearch)                                                                   \
	{                                                                                    \
		DebugConsoleOutput("%s :: Previous lobby search handle not release.", __func__); \
		return value;                                                                    \
	}

EOS_HLobbyModification mHLobbyModification = nullptr;
#define eos_assert_lobby_modification(value)               \
	if (!mHLobbyModification)                              \
	{                                                      \
		TRACE("Couldn't find lobby modification handle."); \
		return value;                                      \
	}
#define eos_assert_not_lobby_modification(value)                   \
	if (mHLobbyModification)                                       \
	{                                                              \
		TRACE("Previous lobby modification handle not released."); \
		return value;                                              \
	}

EOS_HLobby HLobby;
void eos_lobby_init()
{
	HLobby = EOS_Platform_GetLobbyInterface(PlatformHandle);
}

void EOS_CALL Lobby_OnJoinLobbyAcceptedCallback(const EOS_Lobby_JoinLobbyAcceptedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_add_notify_join_lobby_accepted");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddInt64(map, "ui_event_id", (int64)data->UiEventId);

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_lobby_add_notify_join_lobby_accepted(char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_Lobby_AddNotifyJoinLobbyAcceptedOptions Options{};
	Options.ApiVersion = EOS_LOBBY_ADDNOTIFYJOINLOBBYACCEPTED_API_LATEST;

	uint64 notificationId = EOS_Lobby_AddNotifyJoinLobbyAccepted(HLobby, &Options, nullptr, Lobby_OnJoinLobbyAcceptedCallback);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0;
}

void EOS_CALL Lobby_AddNotifyLeaveLobbyRequested(const EOS_Lobby_LeaveLobbyRequestedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_add_notify_leave_lobby_requested");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "lobby_id", data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_lobby_add_notify_leave_lobby_requested(char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_Lobby_AddNotifyLeaveLobbyRequestedOptions Options{};
	Options.ApiVersion = EOS_LOBBY_ADDNOTIFYLEAVELOBBYREQUESTED_API_LATEST;

	uint64 notificationId = EOS_Lobby_AddNotifyLeaveLobbyRequested(HLobby, &Options, nullptr, Lobby_AddNotifyLeaveLobbyRequested);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL Lobby_OnLobbyInviteAcceptedCallback(const EOS_Lobby_LobbyInviteAcceptedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_add_notify_lobby_invite_accepted");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "lobby_id", data->LobbyId);
	DsMapAddString(map, "invite_id", data->InviteId);
	DsMapAddString(map, "target_user_id", productID_toString(data->TargetUserId));

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_lobby_add_notify_lobby_invite_accepted(char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_Lobby_AddNotifyLobbyInviteAcceptedOptions Options{};
	Options.ApiVersion = EOS_LOBBY_ADDNOTIFYLOBBYINVITEACCEPTED_API_LATEST;

	uint64 notificationId = EOS_Lobby_AddNotifyLobbyInviteAccepted(HLobby, &Options, nullptr, Lobby_OnLobbyInviteAcceptedCallback);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL Lobby_AddNotifyLobbyInviteReceivedCallback(const EOS_Lobby_LobbyInviteReceivedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_add_notify_lobby_invite_received");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "invite_id", data->InviteId);
	DsMapAddString(map, "target_user_id", productID_toString(data->TargetUserId));

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_lobby_add_notify_lobby_invite_received(char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_Lobby_AddNotifyLobbyInviteReceivedOptions Options{};
	Options.ApiVersion = EOS_LOBBY_ADDNOTIFYLOBBYINVITERECEIVED_API_LATEST;

	uint64 notificationId = EOS_Lobby_AddNotifyLobbyInviteReceived(HLobby, &Options, nullptr, Lobby_AddNotifyLobbyInviteReceivedCallback);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL Lobby_AddNotifyLobbyInviteRejectedCallback(const EOS_Lobby_LobbyInviteRejectedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_add_notify_lobby_invite_rejected");

	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "lobby_id", data->LobbyId);
	DsMapAddString(map, "invite_id", data->InviteId);
	DsMapAddString(map, "target_user_id", productID_toString(data->TargetUserId));

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_lobby_add_notify_lobby_invite_rejected(char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_Lobby_AddNotifyLobbyInviteRejectedOptions Options{};
	Options.ApiVersion = EOS_LOBBY_ADDNOTIFYLOBBYINVITEREJECTED_API_LATEST;

	uint64 notificationId = EOS_Lobby_AddNotifyLobbyInviteRejected(HLobby, &Options, nullptr, Lobby_AddNotifyLobbyInviteRejectedCallback);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0;
}

void EOS_CALL Lobby_AddNotifyLobbyMemberStatusReceivedCallback(const EOS_Lobby_LobbyMemberStatusReceivedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_add_notify_lobby_member_status_received");

	DsMapAddString(map, "target_user_id", productID_toString(data->TargetUserId));
	DsMapAddString(map, "lobby_id", data->LobbyId);
	DsMapAddDouble(map, "current_status", (double)data->CurrentStatus);

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_lobby_add_notify_lobby_member_status_received(char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_Lobby_AddNotifyLobbyMemberStatusReceivedOptions Options{};
	Options.ApiVersion = EOS_LOBBY_ADDNOTIFYLOBBYMEMBERSTATUSRECEIVED_API_LATEST;

	uint64 notificationId = EOS_Lobby_AddNotifyLobbyMemberStatusReceived(HLobby, &Options, nullptr, Lobby_AddNotifyLobbyMemberStatusReceivedCallback);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0;
}

void EOS_CALL Lobby_AddNotifyLobbyMemberUpdateReceivedCallback(const EOS_Lobby_LobbyMemberUpdateReceivedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_add_notify_lobby_member_update_received");

	DsMapAddString(map, "target_user_id", productID_toString(data->TargetUserId));
	DsMapAddString(map, "lobby_id", data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_lobby_add_notify_lobby_member_update_received(char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_Lobby_AddNotifyLobbyMemberUpdateReceivedOptions Options{};
	Options.ApiVersion = EOS_LOBBY_ADDNOTIFYLOBBYMEMBERUPDATERECEIVED_API_LATEST;

	uint64 notificationId = EOS_Lobby_AddNotifyLobbyMemberUpdateReceived(HLobby, &Options, nullptr, Lobby_AddNotifyLobbyMemberUpdateReceivedCallback);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0;
}

void EOS_CALL Lobby_AddNotifyLobbyUpdateReceivedCallback(const EOS_Lobby_LobbyUpdateReceivedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_add_notify_lobby_update_received");
	DsMapAddString(map, "lobby_id", data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_lobby_add_notify_lobby_update_received(char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_Lobby_AddNotifyLobbyUpdateReceivedOptions Options{};
	Options.ApiVersion = EOS_LOBBY_ADDNOTIFYLOBBYUPDATERECEIVED_API_LATEST;

	uint64 notificationId = EOS_Lobby_AddNotifyLobbyUpdateReceived(HLobby, &Options, nullptr, Lobby_AddNotifyLobbyUpdateReceivedCallback);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0;
}

void EOS_CALL Lobby_AddNotifyRTCRoomConnectionChangedCallback(const EOS_Lobby_RTCRoomConnectionChangedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_add_notify_rtc_room_connection_changed");

	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "lobby_id", data->LobbyId);
	DsMapAddDouble(map, "disconnect_reason", (double)data->DisconnectReason);
	DsMapAddDouble(map, "is_connected", data->bIsConnected ? 1.0 : 0.0);

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_lobby_add_notify_rtc_room_connection_changed(char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_Lobby_AddNotifyRTCRoomConnectionChangedOptions Options{};
	Options.ApiVersion = EOS_LOBBY_ADDNOTIFYRTCROOMCONNECTIONCHANGED_API_LATEST;
	// Options.lobby_id_DEPRECATED;
	// Options.local_user_id_DEPRECATED;

	uint64 notificationId = EOS_Lobby_AddNotifyRTCRoomConnectionChanged(HLobby, &Options, nullptr, Lobby_AddNotifyRTCRoomConnectionChangedCallback);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0;
}

void EOS_CALL Lobby_AddNotifySendLobbyNativeInviteRequestedCallback(const EOS_Lobby_SendLobbyNativeInviteRequestedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_add_notify_send_lobby_native_invite_requested");

	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "lobby_id", data->LobbyId);

	DsMapAddString(map, "local_user_id", data->TargetNativeAccountType);
	DsMapAddString(map, "lobby_id", data->TargetUserNativeAccountId);
	DsMapAddInt64(map, "ui_event_id", (int64)data->UiEventId);

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_lobby_add_notify_send_lobby_native_invite_requested(char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_Lobby_AddNotifySendLobbyNativeInviteRequestedOptions Options{};
	Options.ApiVersion = EOS_LOBBY_ADDNOTIFYSENDLOBBYNATIVEINVITEREQUESTED_API_LATEST;

	uint64 notificationId = EOS_Lobby_AddNotifySendLobbyNativeInviteRequested(HLobby, &Options, nullptr, Lobby_AddNotifySendLobbyNativeInviteRequestedCallback);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0;
}

//func double eos_lobby_attribute_release()
//{
//	EOS_Lobby_Attribute LobbyAttribute{};
//	EOS_Lobby_Attribute_Release(&LobbyAttribute);
//	return 0.0;
//}

func double eos_lobby_copy_lobby_details_handle(char* lobby_id,char* local_user_id)
{
	eos_not_init_return(-1);

	eos_assert_not_lobby_details(-1);

	EOS_Lobby_CopyLobbyDetailsHandleOptions Options;
	Options.ApiVersion = EOS_LOBBY_COPYLOBBYDETAILSHANDLE_API_LATEST;
	Options.LobbyId = lobby_id;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);

	EOS_EResult result = EOS_Lobby_CopyLobbyDetailsHandle(HLobby, &Options, &mHLobbyDetails);

	return (double)result;
}

func double eos_lobby_copy_lobby_details_handle_by_invite_id(char* invite_id)
{
	eos_not_init_return(-1);

	eos_assert_not_lobby_details(-1);

	EOS_Lobby_CopyLobbyDetailsHandleByInviteIdOptions Options{};
	Options.ApiVersion = EOS_LOBBY_COPYLOBBYDETAILSHANDLEBYINVITEID_API_LATEST;
	Options.InviteId = invite_id;

	EOS_EResult result = EOS_Lobby_CopyLobbyDetailsHandleByInviteId(HLobby, &Options, &mHLobbyDetails);

	return (double)result;
}

func double __eos_lobby_copy_lobby_details_handle_by_ui_event_id(char* buff_args)
{
	eos_not_init_return(-1);

	eos_assert_not_lobby_details(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_UI_EventId InId = YYGetUint64(args[0]);

	EOS_Lobby_CopyLobbyDetailsHandleByUiEventIdOptions Options{};
	Options.ApiVersion = EOS_LOBBY_COPYLOBBYDETAILSHANDLEBYUIEVENTID_API_LATEST;
	Options.UiEventId = InId;

	EOS_EResult result = EOS_Lobby_CopyLobbyDetailsHandleByUiEventId(HLobby, &Options, &mHLobbyDetails);

	return (double)result;
}

void EOS_CALL Lobby_CreateLobbyCallback(const EOS_Lobby_CreateLobbyCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_create_lobby");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "lobby_id", data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double __eos_lobby_create_lobby(char* buff_args)
{
	eos_not_init_return(-1);

	EOS_Lobby_CreateLobbyOptions Options{};

	auto args = buffer_unpack((uint8_t *)buff_args);

	Options.ApiVersion = EOS_LOBBY_CREATELOBBY_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(YYGetString(args[0]));
	auto array_ids = YYGetArray(args[1]);
	std::vector<uint32_t> ids = VectorUInt32FromVector(array_ids);
	Options.AllowedPlatformIds = ids.data();
	Options.AllowedPlatformIdsCount = (uint32_t)ids.size();
	Options.LobbyId = strcmp(YYGetString(args[2]), "") == 0 ? nullptr : YYGetString(args[2]);
	Options.BucketId = YYGetString(args[3]);
	Options.MaxLobbyMembers = YYGetUint32(args[4]);
	Options.PermissionLevel = (EOS_ELobbyPermissionLevel)YYGetUint8(args[5]); // EOS_ELobbyPermissionLevel::EOS_LPL_INVITEONLY;
	Options.bAllowInvites = YYGetBool(args[6]);
	Options.bCrossplayOptOut = YYGetBool(args[7]);
	Options.bDisableHostMigration = YYGetBool(args[8]);
	Options.bEnableJoinById = YYGetBool(args[9]);
	Options.bPresenceEnabled = YYGetBool(args[10]);

	Options.bEnableRTCRoom = YYGetBool(args[11]);

	if (Options.bEnableRTCRoom)
	{
		EOS_Lobby_LocalRTCOptions LocalRTCOptions{};
		LocalRTCOptions.ApiVersion = EOS_LOBBY_LOCALRTCOPTIONS_API_LATEST;
		LocalRTCOptions.Flags = YYGetUint32(args[12]);							 // EOS_RTC_JOINROOMFLAGS_ENABLE_DATACHANNEL;
		LocalRTCOptions.bUseManualAudioInput = YYGetBool(args[13]);				 // false;
		LocalRTCOptions.bUseManualAudioOutput = YYGetBool(args[14]);			 // false;
		LocalRTCOptions.bLocalAudioDeviceInputStartsMuted = YYGetBool(args[15]); // false;

		Options.LocalRTCOptions = &LocalRTCOptions;
	}
	else
		Options.LocalRTCOptions = nullptr;

	callback *mcallback = getCallbackData();
	EOS_Lobby_CreateLobby(HLobby, &Options, mcallback, Lobby_CreateLobbyCallback);

	return mcallback->identifier;
}

func double eos_lobby_create_lobby_search(double max_results)
{
	eos_not_init_return(-1);

	eos_assert_not_lobby_search(-1);

	EOS_Lobby_CreateLobbySearchOptions Options{};
	Options.ApiVersion = EOS_LOBBY_CREATELOBBYSEARCH_API_LATEST;
	Options.MaxResults = (uint32_t)max_results;

	EOS_EResult result = EOS_Lobby_CreateLobbySearch(HLobby, &Options, &mHLobbySearch);

	return (double)result;
}

void EOS_CALL Lobby_DestroyLobbyCallback(const EOS_Lobby_DestroyLobbyCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_destroy_lobby");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "lobby_id", data->LobbyId);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_lobby_destroy_lobby(char* lobby_id,char* local_user_id)
{
	eos_not_init_return(-1);

	EOS_Lobby_DestroyLobbyOptions Options{};
	Options.ApiVersion = EOS_LOBBY_DESTROYLOBBY_API_LATEST;
	Options.LobbyId = lobby_id;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);

	callback *mcallback = getCallbackData();

	EOS_Lobby_DestroyLobby(HLobby, &Options, mcallback, Lobby_DestroyLobbyCallback);

	return mcallback->identifier;
}

func char* eos_lobby_get_connect_string(char* lobby_id,char* local_user_id)
{
	eos_not_init_return((char* )"");

	static char TempBuffer[EOS_LOBBY_GETCONNECTSTRING_BUFFER_SIZE];
	uint32_t TempBufferSize = sizeof(TempBuffer);

	EOS_Lobby_GetConnectStringOptions Options{};
	Options.ApiVersion = EOS_LOBBY_GETCONNECTSTRING_API_LATEST;
	Options.LobbyId = lobby_id;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);

	EOS_Lobby_GetConnectString(HLobby, &Options, TempBuffer, &TempBufferSize);

	return TempBuffer;
}

func double eos_lobby_get_invite_count(char* local_user_id)
{
	eos_not_init_return(-1);

	EOS_Lobby_GetInviteCountOptions Options{};
	Options.ApiVersion = EOS_LOBBY_GETINVITECOUNT_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	return EOS_Lobby_GetInviteCount(HLobby, &Options);
}

func char* eos_lobby_get_invite_id_by_index(char* local_user_id, double index)
{
	eos_not_init_return((char* )"");

	static char TempBuffer[EOS_LOBBY_INVITEID_MAX_LENGTH];
	int32_t TempBufferSize = sizeof(TempBuffer);

	EOS_Lobby_GetInviteIdByIndexOptions Options{};
	Options.ApiVersion = EOS_LOBBY_GETINVITEIDBYINDEX_API_LATEST;
	Options.Index = (uint32_t)index;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);

	EOS_Lobby_GetInviteIdByIndex(HLobby, &Options, TempBuffer, &TempBufferSize);

	return TempBuffer;
}

func char* eos_lobby_get_rtc_room_name(char* local_user_id,char* lobby_id)
{
	eos_not_init_return((char* )"");

	static char TempBuffer[1024];
	uint32_t TempBufferSize = sizeof(TempBuffer);

	EOS_Lobby_GetRTCRoomNameOptions Options{};
	Options.ApiVersion = EOS_LOBBY_GETRTCROOMNAME_API_LATEST;
	Options.LobbyId = lobby_id;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);

	EOS_Lobby_GetRTCRoomName(HLobby, &Options, TempBuffer, &TempBufferSize);

	return TempBuffer;
}

void EOS_CALL Lobby_HardMuteMemberCallback(const EOS_Lobby_HardMuteMemberCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_hard_mute_member");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "lobby_id", data->LobbyId);
	DsMapAddString(map, "target_user_id", productID_toString(data->TargetUserId));

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_lobby_hard_mute_member(double hard_mute,char* lobby_id,char* local_user_id,char* target_user_id)
{
	eos_not_init_return(-1);

	EOS_Lobby_HardMuteMemberOptions Options{};
	Options.ApiVersion = EOS_LOBBY_HARDMUTEMEMBER_API_LATEST;
	Options.bHardMute = hard_mute > 0.5;
	Options.LobbyId = lobby_id;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.TargetUserId = EOS_ProductUserId_FromString(target_user_id);

	callback *mcallback = getCallbackData();

	EOS_Lobby_HardMuteMember(HLobby, &Options, mcallback, Lobby_HardMuteMemberCallback);

	return mcallback->identifier;
}

func double eos_lobby_is_rtc_room_connected(char* lobby_id,char* local_user_id)
{
	eos_not_init_return(-1);

	EOS_Lobby_IsRTCRoomConnectedOptions Options{};
	Options.ApiVersion = EOS_LOBBY_ISRTCROOMCONNECTED_API_LATEST;
	Options.LobbyId = lobby_id;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	EOS_Bool bOutIsConnected;

	EOS_EResult result = EOS_Lobby_IsRTCRoomConnected(HLobby, &Options, &bOutIsConnected);

	if (EOS_EResult::EOS_Success != result)
		return false;

	return bOutIsConnected ? 1.0 : 0.0;
}

void EOS_CALL Lobby_JoinLobbyCallback(const EOS_Lobby_JoinLobbyCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_join_lobby");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "lobby_id", data->LobbyId);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double __eos_lobby_join_lobby(char* buff_args)
{
	eos_not_init_return(-1);

	eos_assert_lobby_details(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);

	EOS_Lobby_JoinLobbyOptions Options{};
	Options.ApiVersion = EOS_LOBBY_JOINLOBBY_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(YYGetString(args[0]));
	Options.bCrossplayOptOut = YYGetBool(args[1]);
	Options.bPresenceEnabled = YYGetBool(args[2]);
	Options.LobbyDetailsHandle = mHLobbyDetails;

	bool bEnableRTCRoom = YYGetBool(args[3]);

	if (bEnableRTCRoom)
	{
		EOS_Lobby_LocalRTCOptions LocalRTCOptions{};
		LocalRTCOptions.ApiVersion = EOS_LOBBY_LOCALRTCOPTIONS_API_LATEST;
		LocalRTCOptions.bLocalAudioDeviceInputStartsMuted = YYGetBool(args[4]);
		LocalRTCOptions.bUseManualAudioInput = YYGetBool(args[5]);
		LocalRTCOptions.bUseManualAudioOutput = YYGetBool(args[6]);
		LocalRTCOptions.Flags = YYGetUint32(args[7]); // EOS_RTC_JOINROOMFLAGS_ENABLE_DATACHANNEL

		Options.LocalRTCOptions = &LocalRTCOptions;
	}
	else
		Options.LocalRTCOptions = nullptr;

	callback *mcallback = getCallbackData();
	EOS_Lobby_JoinLobby(HLobby, &Options, mcallback, Lobby_JoinLobbyCallback);
	return mcallback->identifier;
}

void EOS_CALL Lobby_JoinLobbyByIdCallback(const EOS_Lobby_JoinLobbyByIdCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_join_lobby_by_id");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

	DsMapAddString(map, "lobby_id", data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double __eos_lobby_join_lobby_by_id(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);

	EOS_Lobby_JoinLobbyByIdOptions Options{};
	Options.ApiVersion = EOS_LOBBY_JOINLOBBYBYID_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(YYGetString(args[0]));
	Options.bCrossplayOptOut = YYGetBool(args[1]);
	Options.bPresenceEnabled = YYGetBool(args[2]);
	Options.LobbyId = YYGetString(args[3]);

	bool bEnableRTCRoom = YYGetBool(args[4]);

	if (bEnableRTCRoom)
	{
		EOS_Lobby_LocalRTCOptions LocalRTCOptions{};
		LocalRTCOptions.ApiVersion = EOS_LOBBY_LOCALRTCOPTIONS_API_LATEST;
		LocalRTCOptions.bLocalAudioDeviceInputStartsMuted = YYGetBool(args[5]);
		LocalRTCOptions.bUseManualAudioInput = YYGetBool(args[6]);
		LocalRTCOptions.bUseManualAudioOutput = YYGetBool(args[7]);
		LocalRTCOptions.Flags = YYGetUint32(args[8]); // EOS_RTC_JOINROOMFLAGS_ENABLE_DATACHANNEL

		Options.LocalRTCOptions = &LocalRTCOptions;
	}
	else
		Options.LocalRTCOptions = nullptr;

	callback *mcallback = getCallbackData();

	EOS_Lobby_JoinLobbyById(HLobby, &Options, mcallback, Lobby_JoinLobbyByIdCallback);

	return mcallback->identifier;
}

void EOS_CALL Lobby_KickMemberCallback(const EOS_Lobby_KickMemberCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_kick_member");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "lobby_id", data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_lobby_kick_member(char* lobby_id,char* local_user_id,char* target_user_id)
{
	eos_not_init_return(-1);

	EOS_Lobby_KickMemberOptions Options{};
	Options.ApiVersion = EOS_LOBBY_KICKMEMBER_API_LATEST;
	Options.LobbyId = lobby_id;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.TargetUserId = EOS_ProductUserId_FromString(target_user_id);

	callback *mcallback = getCallbackData();

	EOS_Lobby_KickMember(HLobby, &Options, mcallback, Lobby_KickMemberCallback);

	return mcallback->identifier;
}

void EOS_CALL Lobby_LeaveLobbyCallback(const EOS_Lobby_LeaveLobbyCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_leave_lobby");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "lobby_id", data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_lobby_leave_lobby(char* lobby_id,char* local_user_id)
{
	eos_not_init_return(-1);

	EOS_Lobby_LeaveLobbyOptions Options{};
	Options.ApiVersion = EOS_LOBBY_LEAVELOBBY_API_LATEST;
	Options.LobbyId = lobby_id;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);

	callback *mcallback = getCallbackData();

	EOS_Lobby_LeaveLobby(HLobby, &Options, mcallback, Lobby_LeaveLobbyCallback);

	return mcallback->identifier;
}

func char* eos_lobby_parse_connect_string()
{
	eos_not_init_return((char* )"");

	static char TempBuffer[EOS_LOBBY_GETCONNECTSTRING_BUFFER_SIZE];
	uint32_t TempBufferSize = sizeof(TempBuffer);

	EOS_Lobby_ParseConnectStringOptions Options{};
	Options.ApiVersion = EOS_LOBBY_GETCONNECTSTRING_API_LATEST;

	EOS_Lobby_ParseConnectString(HLobby, &Options, TempBuffer, &TempBufferSize);

	return TempBuffer;
}

void EOS_CALL Lobby_PromoteMemberCallback(const EOS_Lobby_PromoteMemberCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_promote_member");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "lobby_id", data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_lobby_promote_member(char* lobby_id,char* local_user_id,char* target_user_id)
{
	eos_not_init_return(-1);

	EOS_Lobby_PromoteMemberOptions Options{};
	Options.ApiVersion = EOS_LOBBY_PROMOTEMEMBER_API_LATEST;
	Options.LobbyId = lobby_id;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.TargetUserId = EOS_ProductUserId_FromString(target_user_id);

	callback *mcallback = getCallbackData();

	EOS_Lobby_PromoteMember(HLobby, &Options, mcallback, Lobby_PromoteMemberCallback);

	return mcallback->identifier;
}

void EOS_CALL Lobby_QueryInvitesCallback(const EOS_Lobby_QueryInvitesCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_query_invites");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_lobby_query_invites(char* local_user_id)
{
	eos_not_init_return(-1);

	EOS_Lobby_QueryInvitesOptions Options{};
	Options.ApiVersion = EOS_LOBBY_QUERYINVITES_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);

	callback *mcallback = getCallbackData();

	EOS_Lobby_QueryInvites(HLobby, &Options, mcallback, Lobby_QueryInvitesCallback);

	return mcallback->identifier;
}

void EOS_CALL Lobby_RejectInviteCallback(const EOS_Lobby_RejectInviteCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_reject_invite");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

	DsMapAddString(map, "status_message", data->InviteId);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_lobby_reject_invite(char* invite_id,char* local_user_id)
{
	eos_not_init_return(-1);

	EOS_Lobby_RejectInviteOptions Options{};
	Options.ApiVersion = EOS_LOBBY_REJECTINVITE_API_LATEST;
	Options.InviteId = invite_id;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);

	callback *mcallback = getCallbackData();

	EOS_Lobby_RejectInvite(HLobby, &Options, mcallback, Lobby_RejectInviteCallback);

	return mcallback->identifier;
}

func double __eos_lobby_remove_notify_join_lobby_accepted(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Lobby_RemoveNotifyJoinLobbyAccepted(HLobby, InId);
	return 0.0;
}

func double __eos_lobby_remove_notify_leave_lobby_requested(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Lobby_RemoveNotifyLeaveLobbyRequested(HLobby, InId);
	return 0.0;
}

func double __eos_lobby_remove_notify_lobby_invite_accepted(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Lobby_RemoveNotifyLobbyInviteAccepted(HLobby, InId);
	return 0.0;
}

func double __eos_lobby_remove_notify_lobby_invite_received(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Lobby_RemoveNotifyLobbyInviteReceived(HLobby, InId);
	return 0.0;
}

func double __eos_lobby_remove_notify_lobby_invite_rejected(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Lobby_RemoveNotifyLobbyInviteRejected(HLobby, InId);
	return 0.0;
}

func double __eos_lobby_remove_notify_lobby_member_status_received(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Lobby_RemoveNotifyLobbyMemberStatusReceived(HLobby, InId);
	return 0.0;
}

func double __eos_lobby_remove_notify_lobby_member_update_received(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Lobby_RemoveNotifyLobbyMemberUpdateReceived(HLobby, InId);
	return 0.0;
}

func double __eos_lobby_remove_notify_lobby_update_received(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Lobby_RemoveNotifyLobbyUpdateReceived(HLobby, InId);
	return 0.0;
}

func double __eos_lobby_remove_notify_rtc_room_connection_changed(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Lobby_RemoveNotifyRTCRoomConnectionChanged(HLobby, InId);
	return 0.0;
}

func double __eos_lobby_remove_notify_send_lobby_native_invite_requested(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Lobby_RemoveNotifySendLobbyNativeInviteRequested(HLobby, InId);
	return 0.0;
}

void EOS_CALL Lobby_SendInviteCallback(const EOS_Lobby_SendInviteCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_send_invite");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

	DsMapAddString(map, "lobby_id", data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_lobby_send_invite(char* lobby_id,char* local_user_id,char* target_user_id)
{
	eos_not_init_return(-1);

	EOS_Lobby_SendInviteOptions Options{};
	Options.ApiVersion = EOS_LOBBY_SENDINVITE_API_LATEST;
	Options.LobbyId = lobby_id;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.TargetUserId = EOS_ProductUserId_FromString(target_user_id);

	callback *mcallback = getCallbackData();

	EOS_Lobby_SendInvite(HLobby, &Options, mcallback, Lobby_SendInviteCallback);

	return mcallback->identifier;
}

void EOS_CALL Lobby_UpdateLobbyCallback(const EOS_Lobby_UpdateLobbyCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_update_lobby");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

	DsMapAddString(map, "lobby_id", data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_lobby_update_lobby()
{
	eos_not_init_return(-1);

	eos_assert_lobby_modification(-1);

	EOS_Lobby_UpdateLobbyOptions Options{};
	Options.ApiVersion = EOS_LOBBY_UPDATELOBBY_API_LATEST;
	Options.LobbyModificationHandle = mHLobbyModification;

	callback *mcallback = getCallbackData();

	EOS_Lobby_UpdateLobby(HLobby, &Options, mcallback, Lobby_UpdateLobbyCallback);

	return mcallback->identifier;
}

func double eos_lobby_update_lobby_modification(char* lobby_id,char* local_user_id)
{
	eos_not_init_return(-1);

	eos_assert_not_lobby_modification(-1);

	EOS_Lobby_UpdateLobbyModificationOptions Options{};
	Options.ApiVersion = EOS_LOBBY_UPDATELOBBYMODIFICATION_API_LATEST;
	Options.LobbyId = lobby_id;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);

	EOS_EResult result = EOS_Lobby_UpdateLobbyModification(HLobby, &Options, &mHLobbyModification);
	
	return (double)result;
}

void LobbyAtrribute2StructStream(EOS_Lobby_Attribute* OutLobbyAttribute, StructStream* outputSteam)
{
	outputSteam->addKeyValue("visibility", (double)OutLobbyAttribute->Visibility);
	outputSteam->addKeyValue("key", (const char*)OutLobbyAttribute->Data->Key);
	switch (OutLobbyAttribute->Data->ValueType)
	{
	case EOS_EAttributeType::EOS_AT_BOOLEAN:
		outputSteam->addKeyValue("value", (bool)OutLobbyAttribute->Data->Value.AsBool);
		break;
	case EOS_EAttributeType::EOS_AT_DOUBLE:
		outputSteam->addKeyValue("value", (double)OutLobbyAttribute->Data->Value.AsDouble);
		break;
	case EOS_EAttributeType::EOS_AT_INT64:
		outputSteam->addKeyValue("value", /*(int64)*/ (int)OutLobbyAttribute->Data->Value.AsInt64);
		break; // TODO: int64
	case EOS_EAttributeType::EOS_AT_STRING:
		outputSteam->addKeyValue("value", (const char*)OutLobbyAttribute->Data->Value.AsUtf8);
		break;
	}
}

func double __eos_lobby_details_copy_attribute_by_index(double index,char* buff_ret)
{
	StructStream _struct = {};
	eos_not_init_return_buffer(buff_ret, _struct);

	eos_assert_lobby_details(-1);

	EOS_LobbyDetails_CopyAttributeByIndexOptions Options{};
	Options.ApiVersion = EOS_LOBBYDETAILS_COPYATTRIBUTEBYINDEX_API_LATEST;
	Options.AttrIndex = (uint32_t)index;
	EOS_Lobby_Attribute *OutAttribute = 0;

	EOS_EResult result = EOS_LobbyDetails_CopyAttributeByIndex(mHLobbyDetails, &Options, &OutAttribute);

	if (result == EOS_EResult::EOS_Success)
		LobbyAtrribute2StructStream(OutAttribute, &_struct);

	_struct.writeTo(buff_ret);

	EOS_Lobby_Attribute_Release(OutAttribute);

	return (double)result;
}

func double __eos_lobby_details_copy_attribute_by_key(char* attr_key,char* buff_ret)
{
	StructStream _struct = {};
	eos_not_init_return_buffer(buff_ret, _struct);

	eos_assert_lobby_details(-1);

	EOS_LobbyDetails_CopyAttributeByKeyOptions Options{};
	Options.ApiVersion = EOS_LOBBYDETAILS_COPYATTRIBUTEBYKEY_API_LATEST;
	Options.AttrKey = attr_key;

	EOS_Lobby_Attribute *OutAttribute = 0;

	EOS_EResult result = EOS_LobbyDetails_CopyAttributeByKey(mHLobbyDetails, &Options, &OutAttribute);

	if (result == EOS_EResult::EOS_Success)
		LobbyAtrribute2StructStream(OutAttribute, &_struct);

	_struct.writeTo(buff_ret);

	EOS_Lobby_Attribute_Release(OutAttribute);

	return (double)result;
}

func double __eos_lobby_details_copy_info(char* buff_ret)
{
	StructStream _struct = {};
	eos_not_init_return_buffer(buff_ret, _struct);

	eos_assert_lobby_details(-1);

	EOS_LobbyDetails_CopyInfoOptions Options{};
	Options.ApiVersion = EOS_LOBBYDETAILS_COPYINFO_API_LATEST;

	EOS_LobbyDetails_Info *OutLobbyDetailsInfo;
	EOS_EResult result = EOS_LobbyDetails_CopyInfo(mHLobbyDetails, &Options, &OutLobbyDetailsInfo);

	if (EOS_EResult::EOS_Success == result)
	{
		_struct.addKeyValue("available_slots", OutLobbyDetailsInfo->AvailableSlots);
		_struct.addKeyValue("allow_host_migration", OutLobbyDetailsInfo->bAllowHostMigration);
		_struct.addKeyValue("allow_invites", OutLobbyDetailsInfo->bAllowInvites);
		_struct.addKeyValue("allow_join_by_id", OutLobbyDetailsInfo->bAllowJoinById);
		_struct.addKeyValue("presence_enabled", OutLobbyDetailsInfo->bPresenceEnabled);
		_struct.addKeyValue("rejoin_after_kick_requires_invite", OutLobbyDetailsInfo->bRejoinAfterKickRequiresInvite);
		_struct.addKeyValue("rtc_room_enabled", OutLobbyDetailsInfo->bRTCRoomEnabled);

		if (OutLobbyDetailsInfo->BucketId != nullptr)
			_struct.addKeyValue("bucket_id", (const char* )OutLobbyDetailsInfo->BucketId);
		if (OutLobbyDetailsInfo->LobbyId != nullptr)
			_struct.addKeyValue("lobby_id", (const char* )OutLobbyDetailsInfo->LobbyId);
		if (OutLobbyDetailsInfo->LobbyOwnerUserId != nullptr)
			_struct.addKeyValue("lobby_owner_user_id", (const char* )productID_toString(OutLobbyDetailsInfo->LobbyOwnerUserId));
		_struct.addKeyValue("max_members", OutLobbyDetailsInfo->MaxMembers);
		_struct.addKeyValue("permission_level", (double)OutLobbyDetailsInfo->PermissionLevel);

		_struct.writeTo(buff_ret);

		EOS_LobbyDetails_Info_Release(OutLobbyDetailsInfo);
	}
	else
	{
		_struct.writeTo(buff_ret);
	}

	return (double)result;
}

func double __eos_lobby_details_copy_member_attribute_by_index(double index,char* target_user_id,char* buff_ret)
{
	StructStream _struct = {};
	eos_not_init_return_buffer(buff_ret, _struct);

	eos_assert_lobby_details(-1);

	EOS_LobbyDetails_CopyMemberAttributeByIndexOptions Options{};
	Options.ApiVersion = EOS_LOBBYDETAILS_COPYMEMBERATTRIBUTEBYINDEX_API_LATEST;
	Options.AttrIndex = (uint32_t)index;
	Options.TargetUserId = EOS_ProductUserId_FromString(target_user_id);

	// This needs to be returned in a struct (needs return buffer)
	EOS_Lobby_Attribute *OutAttribute;
	EOS_EResult result = EOS_LobbyDetails_CopyMemberAttributeByIndex(mHLobbyDetails, &Options, &OutAttribute);

	if (result == EOS_EResult::EOS_Success)
		LobbyAtrribute2StructStream(OutAttribute, &_struct);

	_struct.writeTo(buff_ret);

	// This needs to be released afterwards
	EOS_Lobby_Attribute_Release(OutAttribute);

	return (double)result;
}

func double eos_lobby_details_copy_member_attribute_by_key(char* attr_key,char* target_user_id)
{
	eos_not_init_return(-1);

	eos_assert_lobby_details(-1);

	EOS_LobbyDetails_CopyMemberAttributeByKeyOptions Options{};
	Options.ApiVersion = EOS_LOBBYDETAILS_COPYMEMBERATTRIBUTEBYKEY_API_LATEST;
	Options.AttrKey = attr_key;
	Options.TargetUserId = EOS_ProductUserId_FromString(target_user_id);

	// This needs to be returned in a struct (needs return buffer)
	EOS_Lobby_Attribute *OutAttribute;
	EOS_EResult result = EOS_LobbyDetails_CopyMemberAttributeByKey(mHLobbyDetails, &Options, &OutAttribute);

	// This needs to be released afterwards
	EOS_Lobby_Attribute_Release(OutAttribute);

	return (double)result;
}

func double __eos_lobby_details_copy_member_info(char* target_user_id,char* buff_ret)
{
	StructStream _struct = {};
	eos_not_init_return_buffer(buff_ret, _struct);

	eos_assert_lobby_details(-1);

	EOS_LobbyDetails_CopyMemberInfoOptions Options{};
	Options.ApiVersion = EOS_LOBBYDETAILS_COPYMEMBERINFO_API_LATEST;
	Options.TargetUserId = EOS_ProductUserId_FromString(target_user_id);

	// This needs to be returned in a struct (needs return buffer)
	EOS_LobbyDetails_MemberInfo *OutLobbyDetailsMemberInfo;
	EOS_EResult result = EOS_LobbyDetails_CopyMemberInfo(mHLobbyDetails, &Options, &OutLobbyDetailsMemberInfo);

	if (result == EOS_EResult::EOS_Success)
	{
		_struct.addKeyValue("allows_crossplay", (bool)OutLobbyDetailsMemberInfo->bAllowsCrossplay);
		_struct.addKeyValue("platform", (double)OutLobbyDetailsMemberInfo->Platform);
		_struct.addKeyValue("user_id", (const char*)productID_toString(OutLobbyDetailsMemberInfo->UserId));

		_struct.writeTo(buff_ret);
	}

	_struct.writeTo(buff_ret);

	// This needs to be released afterwards
	EOS_LobbyDetails_MemberInfo_Release(OutLobbyDetailsMemberInfo); 

	return (double)result;
}

func double eos_lobby_details_get_attribute_count()
{
	eos_not_init_return(-1);

	eos_assert_lobby_details(-1);

	EOS_LobbyDetails_GetAttributeCountOptions Options{};
	Options.ApiVersion = EOS_LOBBYDETAILS_GETATTRIBUTECOUNT_API_LATEST;

	return EOS_LobbyDetails_GetAttributeCount(mHLobbyDetails, &Options);
}

func char* eos_lobby_details_get_lobby_owner()
{
	eos_not_init_return((char* )"");

	eos_assert_lobby_details((char* )"");

	EOS_LobbyDetails_GetLobbyOwnerOptions Options{};
	Options.ApiVersion = EOS_LOBBYDETAILS_GETLOBBYOWNER_API_LATEST;
	EOS_ProductUserId p = EOS_LobbyDetails_GetLobbyOwner(mHLobbyDetails, &Options);

	return productID_toString(p);
}

func double eos_lobby_details_get_member_attribute_count(char* target_user_id)
{
	eos_not_init_return(-1);

	EOS_LobbyDetails_GetMemberAttributeCountOptions Options{};
	Options.ApiVersion = EOS_LOBBYDETAILS_GETMEMBERATTRIBUTECOUNT_API_LATEST;
	Options.TargetUserId = EOS_ProductUserId_FromString(target_user_id);

	return EOS_LobbyDetails_GetMemberAttributeCount(mHLobbyDetails, &Options);
}

func char* eos_lobby_details_get_member_by_index(double index)
{
	eos_not_init_return((char* )"");

	eos_assert_lobby_details((char* )"");

	EOS_LobbyDetails_GetMemberByIndexOptions Options{};
	Options.ApiVersion = EOS_LOBBYDETAILS_GETMEMBERBYINDEX_API_LATEST;
	Options.MemberIndex = (uint32_t)index;

	EOS_ProductUserId p = EOS_LobbyDetails_GetMemberByIndex(mHLobbyDetails, &Options);
	return productID_toString(p);
}

func double eos_lobby_details_get_member_count()
{
	eos_not_init_return(-1);

	eos_assert_lobby_details(-1);

	EOS_LobbyDetails_GetMemberCountOptions Options{};
	Options.ApiVersion = EOS_LOBBYDETAILS_GETMEMBERCOUNT_API_LATEST;

	return EOS_LobbyDetails_GetMemberCount(mHLobbyDetails, &Options);
}

//func double eos_lobby_details_info_release()
//{
//	eos_not_init_return(-1);
//	// EOS_LobbyDetails_Info_Release();
//
//	return 0.0;
//}

//func double eos_lobby_details_member_info_release(double AllowsCrossplay, double Platform,char* UserId)
//{
//	eos_not_init_return(-1);
//
//	// TODO :: This function is not necessary
//	// EOS_LobbyDetails_MemberInfo_Release(&LobbyDetailsMemberInfo);
//
//	return 0.0;
//}

func double eos_lobby_details_release()
{
	eos_not_init_return(-1);

	eos_assert_lobby_details(-1);

	EOS_LobbyDetails_Release(mHLobbyDetails);
	mHLobbyDetails = nullptr;

	return 0.0;
}

EOS_Lobby_AttributeData AttributeDataFromStruct(std::map<std::string, const uint8_t *> &Attribute)
{
	EOS_Lobby_AttributeData mSessionAttribute{};

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

func double __eos_lobby_modification_add_attribute(double visibility,char* buff_args)
{
	eos_not_init_return(-1);

	eos_assert_lobby_modification(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	auto Attribute = YYGetStruct(args[0]);

	EOS_Lobby_AttributeData mAttributeData = AttributeDataFromStruct(Attribute);

	EOS_LobbyModification_AddAttributeOptions Options{};
	Options.ApiVersion = EOS_LOBBYMODIFICATION_ADDATTRIBUTE_API_LATEST;
	Options.Attribute = &mAttributeData;
	Options.Visibility = (EOS_ELobbyAttributeVisibility)visibility;

	EOS_EResult result = EOS_LobbyModification_AddAttribute(mHLobbyModification, &Options);

	return (double)result;
}

func double __eos_lobby_modification_add_member_attribute(double visibility,char* buff_args)
{
	eos_not_init_return(-1);

	eos_assert_lobby_modification(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	auto Attribute = YYGetStruct(args[0]);

	EOS_Lobby_AttributeData mAttributeData = AttributeDataFromStruct(Attribute);

	EOS_LobbyModification_AddMemberAttributeOptions Options{};
	Options.ApiVersion = EOS_LOBBYMODIFICATION_ADDMEMBERATTRIBUTE_API_LATEST;
	Options.Attribute = &mAttributeData;
	Options.Visibility = (EOS_ELobbyAttributeVisibility)visibility;
	EOS_EResult result = EOS_LobbyModification_AddMemberAttribute(mHLobbyModification, &Options);

	return (double)result;
}

func double eos_lobby_modification_release()
{
	eos_not_init_return(-1);

	eos_assert_lobby_modification(-1);

	EOS_LobbyModification_Release(mHLobbyModification);
	mHLobbyModification = NULL;

	return 0.0;
}

func double eos_lobby_modification_remove_attribute(char* key)
{
	eos_not_init_return(-1);

	eos_assert_lobby_modification(-1);

	EOS_LobbyModification_RemoveAttributeOptions Options{};
	Options.ApiVersion = EOS_LOBBYMODIFICATION_REMOVEATTRIBUTE_API_LATEST;
	Options.Key = key;

	EOS_EResult result = EOS_LobbyModification_RemoveAttribute(mHLobbyModification, &Options);

	return (double)result;
}

func double eos_lobby_modification_remove_member_attribute(char* key)
{
	eos_not_init_return(-1);

	eos_assert_lobby_modification(-1);

	EOS_LobbyModification_RemoveMemberAttributeOptions Options{};
	Options.ApiVersion = EOS_LOBBYMODIFICATION_REMOVEMEMBERATTRIBUTE_API_LATEST;
	Options.Key = key;

	EOS_EResult result = EOS_LobbyModification_RemoveMemberAttribute(mHLobbyModification, &Options);

	return (double)result;
}

func double __eos_lobby_modification_set_allowed_platform_ids(char* buff_args)
{
	eos_not_init_return(-1);

	eos_assert_lobby_modification(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);

	EOS_LobbyModification_SetAllowedPlatformIdsOptions Options{};
	Options.ApiVersion = EOS_LOBBYMODIFICATION_SETALLOWEDPLATFORMIDS_API_LATEST;

	auto array_ids = YYGetArray(args[0]);
	std::vector<uint32_t> ids = VectorUInt32FromVector(array_ids);

	Options.AllowedPlatformIds = ids.data();
	Options.AllowedPlatformIdsCount = (uint32_t)ids.size();

	EOS_EResult result = EOS_LobbyModification_SetAllowedPlatformIds(mHLobbyModification, &Options);

	return (double)result;
}

func double eos_lobby_modification_set_bucket_id(char* bucket_id)
{
	eos_not_init_return(-1);

	eos_assert_lobby_modification(-1);

	EOS_LobbyModification_SetBucketIdOptions Options{};
	Options.ApiVersion = EOS_LOBBYMODIFICATION_SETBUCKETID_API_LATEST;
	Options.BucketId = bucket_id;

	EOS_EResult result = EOS_LobbyModification_SetBucketId(mHLobbyModification, &Options);

	return (double)result;
}

func double eos_lobby_modification_set_invites_allowed(double invites_allowed)
{
	eos_not_init_return(-1);

	eos_assert_lobby_modification(-1);

	EOS_LobbyModification_SetInvitesAllowedOptions Options{};
	Options.ApiVersion = EOS_LOBBYMODIFICATION_SETINVITESALLOWED_API_LATEST;
	Options.bInvitesAllowed = (EOS_Bool)invites_allowed;

	EOS_EResult result = EOS_LobbyModification_SetInvitesAllowed(mHLobbyModification, &Options);

	return (double)result;
}

func double eos_lobby_modification_set_max_members(double max_members)
{
	eos_not_init_return(-1);

	eos_assert_lobby_modification(-1);

	EOS_LobbyModification_SetMaxMembersOptions Options{};
	Options.ApiVersion = EOS_LOBBYMODIFICATION_SETMAXMEMBERS_API_LATEST;
	Options.MaxMembers = (uint32_t)max_members;

	EOS_EResult result = EOS_LobbyModification_SetMaxMembers(mHLobbyModification, &Options);
	return (double)result;
}

func double eos_lobby_modification_set_permission_level(double PermissionLevel)
{
	eos_not_init_return(-1);

	eos_assert_lobby_modification(-1);

	EOS_LobbyModification_SetPermissionLevelOptions Options{};
	Options.ApiVersion = EOS_LOBBYMODIFICATION_SETPERMISSIONLEVEL_API_LATEST;
	Options.PermissionLevel = (EOS_ELobbyPermissionLevel)PermissionLevel;

	EOS_EResult result = EOS_LobbyModification_SetPermissionLevel(mHLobbyModification, &Options);

	return (double)result;
}

func double eos_lobby_search_copy_search_result_by_index(double index)
{
	eos_not_init_return(-1);

	eos_assert_lobby_search(-1);

	EOS_LobbySearch_CopySearchResultByIndexOptions Options{};
	Options.ApiVersion = EOS_LOBBYSEARCH_COPYSEARCHRESULTBYINDEX_API_LATEST;
	Options.LobbyIndex = (uint32_t)index;

	EOS_EResult result = EOS_LobbySearch_CopySearchResultByIndex(mHLobbySearch, &Options, &mHLobbyDetails);

	return (double)result;
}

void EOS_CALL LobbySearch_FindCallback(const EOS_LobbySearch_FindCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_lobby_search_find");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_lobby_search_find(char* local_user_id)
{
	eos_not_init_return(-1);

	eos_assert_lobby_search(-1);

	EOS_LobbySearch_FindOptions Options{};
	Options.ApiVersion = EOS_LOBBYSEARCH_FIND_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);

	callback *mcallback = getCallbackData();

	EOS_LobbySearch_Find(mHLobbySearch, &Options, mcallback, LobbySearch_FindCallback);

	return mcallback->identifier;
}

func double eos_lobby_search_get_search_result_count()
{
	eos_not_init_return(-1);

	eos_assert_lobby_search(-1);

	EOS_LobbySearch_GetSearchResultCountOptions Options{};
	Options.ApiVersion = EOS_LOBBYSEARCH_GETSEARCHRESULTCOUNT_API_LATEST;

	return EOS_LobbySearch_GetSearchResultCount(mHLobbySearch, &Options);
}

func double eos_lobby_search_release()
{
	eos_not_init_return(-1);

	eos_assert_lobby_search(-1);

	EOS_LobbySearch_Release(mHLobbySearch);
	mHLobbySearch = nullptr;

	return 0.0;
}

func double eos_lobby_search_remove_parameter(char* key, double comparison_op)
{
	eos_not_init_return(-1);

	eos_assert_lobby_search(-1);

	EOS_LobbySearch_RemoveParameterOptions Options{};
	Options.ApiVersion = EOS_LOBBYSEARCH_REMOVEPARAMETER_API_LATEST;
	Options.ComparisonOp = (EOS_EComparisonOp)comparison_op;
	Options.Key = key;

	EOS_LobbySearch_RemoveParameter(mHLobbySearch, &Options);
	return 0.0;
}

func double eos_lobby_search_set_lobby_id(char* lobby_id)
{
	eos_not_init_return(-1);

	eos_assert_lobby_search(-1);

	EOS_LobbySearch_SetLobbyIdOptions Options{};
	Options.ApiVersion = EOS_LOBBYSEARCH_SETLOBBYID_API_LATEST;
	Options.LobbyId = lobby_id;

	EOS_EResult result = EOS_LobbySearch_SetLobbyId(mHLobbySearch, &Options);

	return (double)result;
}

func double eos_lobby_search_set_max_results(double max_results)
{
	eos_not_init_return(-1);

	eos_assert_lobby_search(-1);

	EOS_LobbySearch_SetMaxResultsOptions Options{};
	Options.ApiVersion = EOS_LOBBYSEARCH_SETMAXRESULTS_API_LATEST;
	Options.MaxResults = (uint32_t)max_results;

	EOS_EResult result = EOS_LobbySearch_SetMaxResults(mHLobbySearch, &Options);

	return (double)result;
}

func double __eos_lobby_search_set_parameter(double ComparisonOp,char* buff_args)
{
	eos_not_init_return(-1);

	eos_assert_lobby_search(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	auto Attribute = YYGetStruct(args[0]);

	EOS_Lobby_AttributeData mAttributeData = AttributeDataFromStruct(Attribute);

	EOS_LobbySearch_SetParameterOptions Options{};
	Options.ApiVersion = EOS_LOBBYSEARCH_SETPARAMETER_API_LATEST;
	Options.ComparisonOp = (EOS_EComparisonOp)ComparisonOp;
	Options.Parameter = &mAttributeData;

	EOS_EResult result = EOS_LobbySearch_SetParameter(mHLobbySearch, &Options);

	return (double)result;
}

func double eos_lobby_search_set_target_user_id(char* target_user_id)
{
	eos_not_init_return(-1);

	eos_assert_lobby_search(-1);

	EOS_LobbySearch_SetTargetUserIdOptions Options{};
	Options.ApiVersion = EOS_LOBBYSEARCH_SETTARGETUSERID_API_LATEST;
	Options.TargetUserId = EOS_ProductUserId_FromString(target_user_id);

	EOS_EResult result = EOS_LobbySearch_SetTargetUserId(mHLobbySearch, &Options);

	return (double)result;
}
