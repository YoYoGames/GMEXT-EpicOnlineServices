
//Lobbies Interface
//Interface to handle lobbies

//EOS_Lobby_AddNotifyJoinLobbyAccepted
//EOS_Lobby_AddNotifyLeaveLobbyRequested
//EOS_Lobby_AddNotifyLobbyInviteAccepted
//EOS_Lobby_AddNotifyLobbyInviteReceived
//EOS_Lobby_AddNotifyLobbyInviteRejected
//EOS_Lobby_AddNotifyLobbyMemberStatusReceived
//EOS_Lobby_AddNotifyLobbyMemberUpdateReceived
//EOS_Lobby_AddNotifyLobbyUpdateReceived
//EOS_Lobby_AddNotifyRTCRoomConnectionChanged
//EOS_Lobby_AddNotifySendLobbyNativeInviteRequested
//EOS_Lobby_Attribute_Release
//EOS_Lobby_CopyLobbyDetailsHandle
//EOS_Lobby_CopyLobbyDetailsHandleByInviteId
//EOS_Lobby_CopyLobbyDetailsHandleByUiEventId
//EOS_Lobby_CreateLobby
//EOS_Lobby_CreateLobbySearch
//EOS_Lobby_DestroyLobby
//EOS_Lobby_GetConnectString
//EOS_Lobby_GetInviteCount
//EOS_Lobby_GetInviteIdByIndex
//EOS_Lobby_GetRTCRoomName
//EOS_Lobby_HardMuteMember
//EOS_Lobby_IsRTCRoomConnected
//EOS_Lobby_JoinLobby
//EOS_Lobby_JoinLobbyById
//EOS_Lobby_KickMember
//EOS_Lobby_LeaveLobby
//EOS_Lobby_ParseConnectString
//EOS_Lobby_PromoteMember
//EOS_Lobby_QueryInvites
//EOS_Lobby_RejectInvite
//EOS_Lobby_RemoveNotifyJoinLobbyAccepted
//EOS_Lobby_RemoveNotifyLeaveLobbyRequested
//EOS_Lobby_RemoveNotifyLobbyInviteAccepted
//EOS_Lobby_RemoveNotifyLobbyInviteReceived
//EOS_Lobby_RemoveNotifyLobbyInviteRejected
//EOS_Lobby_RemoveNotifyLobbyMemberStatusReceived
//EOS_Lobby_RemoveNotifyLobbyMemberUpdateReceived
//EOS_Lobby_RemoveNotifyLobbyUpdateReceived
//EOS_Lobby_RemoveNotifyRTCRoomConnectionChanged
//EOS_Lobby_RemoveNotifySendLobbyNativeInviteRequested
//EOS_Lobby_SendInvite
//EOS_Lobby_UpdateLobby
//EOS_Lobby_UpdateLobbyModification
//EOS_LobbyDetails_CopyAttributeByIndex
//EOS_LobbyDetails_CopyAttributeByKey
//EOS_LobbyDetails_CopyInfo
//EOS_LobbyDetails_CopyMemberAttributeByIndex
//EOS_LobbyDetails_CopyMemberAttributeByKey
//EOS_LobbyDetails_CopyMemberInfo
//EOS_LobbyDetails_GetAttributeCount
//EOS_LobbyDetails_GetLobbyOwner
//EOS_LobbyDetails_GetMemberAttributeCount
//EOS_LobbyDetails_GetMemberByIndex
//EOS_LobbyDetails_GetMemberCount
//EOS_LobbyDetails_Info_Release
//EOS_LobbyDetails_MemberInfo_Release
//EOS_LobbyDetails_Release
//EOS_LobbyModification_AddAttribute
//EOS_LobbyModification_AddMemberAttribute
//EOS_LobbyModification_Release
//EOS_LobbyModification_RemoveAttribute
//EOS_LobbyModification_RemoveMemberAttribute
//EOS_LobbyModification_SetAllowedPlatformIds
//EOS_LobbyModification_SetBucketId
//EOS_LobbyModification_SetInvitesAllowed
//EOS_LobbyModification_SetMaxMembers
//EOS_LobbyModification_SetPermissionLevel
//EOS_LobbySearch_CopySearchResultByIndex
//EOS_LobbySearch_Find
//EOS_LobbySearch_GetSearchResultCount
//EOS_LobbySearch_Release
//EOS_LobbySearch_RemoveParameter
//EOS_LobbySearch_SetLobbyId
//EOS_LobbySearch_SetMaxResults
//EOS_LobbySearch_SetParameter
//EOS_LobbySearch_SetTargetUserId
//EOS_LobbySearch_SetTargetUserIdOptions

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include "eos_lobby.h"

EOS_HLobby HLobby;
void EpicGames_Lobby_Init()
{
	HLobby = EOS_Platform_GetLobbyInterface(PlatformHandle);
}


void EOS_CALL Lobby_OnJoinLobbyAcceptedCallback(const EOS_Lobby_JoinLobbyAcceptedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_AddNotifyJoinLobbyAccepted");
	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));
	DsMapAddInt64(map, "ui_event_id", (int64)Data->UiEventId);
	
	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double SDKEpicGames_Lobby_AddNotifyJoinLobbyAccepted(char* buff_ret)
{
	EOS_Lobby_AddNotifyJoinLobbyAcceptedOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBY_ADDNOTIFYJOINLOBBYACCEPTED_API_LATEST;

	uint64 ret = EOS_Lobby_AddNotifyJoinLobbyAccepted(HLobby, &Options, NULL/*mcallback*/, Lobby_OnJoinLobbyAcceptedCallback);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);

	return 0;
}

void EOS_CALL Lobby_AddNotifyLeaveLobbyRequested(const EOS_Lobby_LeaveLobbyRequestedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_AddNotifyLeaveLobbyRequested");
	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));
	DsMapAddString(map, "LobbyId", Data->LobbyId);
	
	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double SDKEpicGames_Lobby_AddNotifyLeaveLobbyRequested(char* buff_ret)
{
	EOS_Lobby_AddNotifyLeaveLobbyRequestedOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBY_ADDNOTIFYLEAVELOBBYREQUESTED_API_LATEST;

	uint64 ret = EOS_Lobby_AddNotifyLeaveLobbyRequested(HLobby, &Options, NULL/*mcallback*/, Lobby_AddNotifyLeaveLobbyRequested);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);
	
	return 0.0;
}

void EOS_CALL Lobby_OnLobbyInviteAcceptedCallback(const EOS_Lobby_LobbyInviteAcceptedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_AddNotifyLobbyInviteAccepted");
	//DsMapAddDouble(map, "status", (double)Data->ResultCode);
	//DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	//DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));
	DsMapAddString(map, "LobbyId", Data->LobbyId);
	DsMapAddString(map, "InviteId", Data->InviteId);
	DsMapAddString(map, "TargetUserId", productID_toString(Data->TargetUserId));
	
	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double SDKEpicGames_Lobby_AddNotifyLobbyInviteAccepted(char* buff_ret)
{
	EOS_Lobby_AddNotifyLobbyInviteAcceptedOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBY_ADDNOTIFYLOBBYINVITEACCEPTED_API_LATEST;

	uint64 ret = EOS_Lobby_AddNotifyLobbyInviteAccepted(HLobby, &Options, NULL/*mcallback*/, Lobby_OnLobbyInviteAcceptedCallback);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL Lobby_AddNotifyLobbyInviteReceivedCallback(const EOS_Lobby_LobbyInviteReceivedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_AddNotifyLobbyInviteReceived");
	//DsMapAddDouble(map, "status", (double)Data->ResultCode);
	//DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	//DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);

	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));
	DsMapAddString(map, "InviteId", Data->InviteId);
	DsMapAddString(map, "TargetUserId", productID_toString(Data->TargetUserId));
	
	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double SDKEpicGames_Lobby_AddNotifyLobbyInviteReceived(char* buff_ret)
{
	EOS_Lobby_AddNotifyLobbyInviteReceivedOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBY_ADDNOTIFYLOBBYINVITERECEIVED_API_LATEST;

	uint64 ret = EOS_Lobby_AddNotifyLobbyInviteReceived(HLobby, &Options, NULL/*mcallback*/, Lobby_AddNotifyLobbyInviteReceivedCallback);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL Lobby_AddNotifyLobbyInviteRejectedCallback(const EOS_Lobby_LobbyInviteRejectedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_AddNotifyLobbyInviteRejected");

	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));
	DsMapAddString(map, "LobbyId", Data->LobbyId);
	DsMapAddString(map, "InviteId", Data->InviteId);
	DsMapAddString(map, "TargetUserId", productID_toString(Data->TargetUserId));

	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double SDKEpicGames_Lobby_AddNotifyLobbyInviteRejected(char* buff_ret)
{
	EOS_Lobby_AddNotifyLobbyInviteRejectedOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBY_ADDNOTIFYLOBBYINVITEREJECTED_API_LATEST;

	uint64 ret = EOS_Lobby_AddNotifyLobbyInviteRejected(HLobby, &Options, NULL/*mcallback*/, Lobby_AddNotifyLobbyInviteRejectedCallback);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);

	return 0;
}

void EOS_CALL Lobby_AddNotifyLobbyMemberStatusReceivedCallback(const EOS_Lobby_LobbyMemberStatusReceivedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_AddNotifyLobbyMemberStatusReceived");

	DsMapAddString(map, "TargetUserId", productID_toString(Data->TargetUserId));
	DsMapAddString(map, "LobbyId", Data->LobbyId);
	DsMapAddDouble(map, "CurrentStatus", (double) Data->CurrentStatus);

	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double SDKEpicGames_Lobby_AddNotifyLobbyMemberStatusReceived(char* buff_ret)
{
	EOS_Lobby_AddNotifyLobbyMemberStatusReceivedOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBY_ADDNOTIFYLOBBYMEMBERSTATUSRECEIVED_API_LATEST;

	uint64 ret = EOS_Lobby_AddNotifyLobbyMemberStatusReceived(HLobby, &Options, NULL/*mcallback*/, Lobby_AddNotifyLobbyMemberStatusReceivedCallback);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);

	return 0;
}

void EOS_CALL Lobby_AddNotifyLobbyMemberUpdateReceivedCallback(const EOS_Lobby_LobbyMemberUpdateReceivedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_AddNotifyLobbyMemberUpdateReceived");
	
	DsMapAddString(map, "TargetUserId", productID_toString(Data->TargetUserId));
	DsMapAddString(map, "LobbyId", Data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double SDKEpicGames_Lobby_AddNotifyLobbyMemberUpdateReceived(char* buff_ret)
{
	EOS_Lobby_AddNotifyLobbyMemberUpdateReceivedOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBY_ADDNOTIFYLOBBYMEMBERUPDATERECEIVED_API_LATEST;

	uint64 ret = EOS_Lobby_AddNotifyLobbyMemberUpdateReceived(HLobby, &Options, NULL/*mcallback*/, Lobby_AddNotifyLobbyMemberUpdateReceivedCallback);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);

	return 0;
}

void EOS_CALL Lobby_AddNotifyLobbyUpdateReceivedCallback(const EOS_Lobby_LobbyUpdateReceivedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_AddNotifyLobbyUpdateReceived");
	DsMapAddString(map, "LobbyId", Data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double SDKEpicGames_Lobby_AddNotifyLobbyUpdateReceived(char* buff_ret)
{
	EOS_Lobby_AddNotifyLobbyUpdateReceivedOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBY_ADDNOTIFYLOBBYUPDATERECEIVED_API_LATEST;

	uint64 ret = EOS_Lobby_AddNotifyLobbyUpdateReceived(HLobby, &Options, NULL/*mcallback*/, Lobby_AddNotifyLobbyUpdateReceivedCallback);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);

	return 0;
}

void EOS_CALL Lobby_AddNotifyRTCRoomConnectionChangedCallback(const EOS_Lobby_RTCRoomConnectionChangedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_AddNotifyRTCRoomConnectionChanged");

	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));
	DsMapAddString(map, "LobbyId", Data->LobbyId);
	DsMapAddDouble(map, "DisconnectReason", (double)Data->DisconnectReason);
	DsMapAddDouble(map, "isConnected", Data->bIsConnected?1.0:0.0);

	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double SDKEpicGames_Lobby_AddNotifyRTCRoomConnectionChanged(char* buff_ret)
{
	EOS_Lobby_AddNotifyRTCRoomConnectionChangedOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBY_ADDNOTIFYRTCROOMCONNECTIONCHANGED_API_LATEST;
	//Options.LobbyId_DEPRECATED;
	//Options.LocalUserId_DEPRECATED;

	uint64 ret = EOS_Lobby_AddNotifyRTCRoomConnectionChanged(HLobby, &Options, NULL/*mcallback*/, Lobby_AddNotifyRTCRoomConnectionChangedCallback);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);

	return 0;
}

void EOS_CALL Lobby_AddNotifySendLobbyNativeInviteRequestedCallback(const EOS_Lobby_SendLobbyNativeInviteRequestedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_AddNotifySendLobbyNativeInviteRequested");
	
	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));
	DsMapAddString(map, "LobbyId", Data->LobbyId);

	DsMapAddString(map, "LocalUserId", Data->TargetNativeAccountType);
	DsMapAddString(map, "LobbyId", Data->TargetUserNativeAccountId);
	DsMapAddInt64(map, "UiEventId", (int64) Data->UiEventId);

	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double SDKEpicGames_Lobby_AddNotifySendLobbyNativeInviteRequested(char* buff_ret)
{
	EOS_Lobby_AddNotifySendLobbyNativeInviteRequestedOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBY_ADDNOTIFYSENDLOBBYNATIVEINVITEREQUESTED_API_LATEST;

	uint64 ret = EOS_Lobby_AddNotifySendLobbyNativeInviteRequested(HLobby, &Options, NULL/*mcallback*/, Lobby_AddNotifySendLobbyNativeInviteRequestedCallback);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);

	return 0;
}

yyfunc double EpicGames_Lobby_Attribute_Release()
{
	EOS_Lobby_Attribute LobbyAttribute = {0};
	EOS_Lobby_Attribute_Release(&LobbyAttribute);
	return 0.0;
}

EOS_HLobbyDetails mHLobbyDetails = NULL;
yyfunc double EpicGames_Lobby_CopyLobbyDetailsHandle(char* LobbyId, char* LocalUserId)
{
	EOS_Lobby_CopyLobbyDetailsHandleOptions Options; 
	Options.ApiVersion = EOS_LOBBY_COPYLOBBYDETAILSHANDLE_API_LATEST;
	Options.LobbyId = LobbyId;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);

	EOS_EResult result = EOS_Lobby_CopyLobbyDetailsHandle(HLobby,&Options,&mHLobbyDetails);
	
	return (double)result;
}

yyfunc double EpicGames_Lobby_CopyLobbyDetailsHandleByInviteId(char* InviteId)
{
	EOS_Lobby_CopyLobbyDetailsHandleByInviteIdOptions Options = {0};
	Options.ApiVersion = EOS_LOBBY_COPYLOBBYDETAILSHANDLEBYINVITEID_API_LATEST;
	Options.InviteId = InviteId;

	EOS_EResult result = EOS_Lobby_CopyLobbyDetailsHandleByInviteId(HLobby,&Options, &mHLobbyDetails);

	return (double)result;
}

yyfunc double SDKEpicGames_Lobby_CopyLobbyDetailsHandleByUiEventId(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_UI_EventId InId = YYGetUint64(args[0]);

	EOS_Lobby_CopyLobbyDetailsHandleByUiEventIdOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBY_COPYLOBBYDETAILSHANDLEBYUIEVENTID_API_LATEST;
	Options.UiEventId = InId;

	EOS_EResult result = EOS_Lobby_CopyLobbyDetailsHandleByUiEventId(HLobby,&Options, &mHLobbyDetails);

	return (double)result;
}

void EOS_CALL Lobby_CreateLobbyCallback(const EOS_Lobby_CreateLobbyCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_CreateLobby");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "LobbyId", Data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double SDKEpicGames_Lobby_CreateLobby(char* buff_args)
{
	EOS_Lobby_CreateLobbyOptions Options = { 0 };

	auto args = buffer_unpack((uint8_t*)buff_args);

	Options.ApiVersion = EOS_LOBBY_CREATELOBBY_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(YYGetString(args[0]));
	auto array_ids = YYGetArray(args[1]);
	std::vector<uint32_t> ids = VectorUInt32FromVector(array_ids);
	//Options.AllowedPlatformIds = ids.data();
	//Options.AllowedPlatformIdsCount = ids.size();
	Options.LobbyId = strcmp(YYGetString(args[2]), "") == 0 ? nullptr : YYGetString(args[2]);
	Options.PermissionLevel = EOS_ELobbyPermissionLevel::EOS_LPL_INVITEONLY;
	Options.BucketId = YYGetString(args[3]);
	Options.MaxLobbyMembers = YYGetReal(args[4]);
	Options.bAllowInvites = YYGetBool(args[5]);
	Options.bCrossplayOptOut = YYGetBool(args[6]);
	Options.bDisableHostMigration = YYGetBool(args[7]);
	Options.bEnableJoinById = YYGetBool(args[8]);
	Options.bPresenceEnabled = YYGetBool(args[9]);

	//TODO:
	//Options.bEnableRTCRoom = false;
	//Options.LocalRTCOptions = nullptr;

	Options.bEnableRTCRoom = true;

	EOS_Lobby_LocalRTCOptions LocalRTCOptions = { 0 };
	LocalRTCOptions.ApiVersion = EOS_LOBBY_LOCALRTCOPTIONS_API_LATEST;
	LocalRTCOptions.Flags = EOS_RTC_JOINROOMFLAGS_ENABLE_DATACHANNEL;
	LocalRTCOptions.bUseManualAudioInput = false;
	LocalRTCOptions.bUseManualAudioOutput = false;
	LocalRTCOptions.bLocalAudioDeviceInputStartsMuted = false;

	Options.LocalRTCOptions = &LocalRTCOptions;

	callback* mcallback = getCallbackData();
	EOS_Lobby_CreateLobby(HLobby,&Options, mcallback,Lobby_CreateLobbyCallback);

	return mcallback->identifier;
}

EOS_HLobbySearch mHLobbySearch = NULL;
yyfunc double EpicGames_Lobby_CreateLobbySearch(double MaxResults)
{
	EOS_Lobby_CreateLobbySearchOptions Options = {0};
	Options.ApiVersion = EOS_LOBBY_CREATELOBBYSEARCH_API_LATEST;
	Options.MaxResults = MaxResults;

	EOS_EResult result = EOS_Lobby_CreateLobbySearch(HLobby,&Options, &mHLobbySearch);

	return (double) result;
}

void EOS_CALL Lobby_DestroyLobbyCallback(const EOS_Lobby_DestroyLobbyCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_DestroyLobby");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "LobbyId", Data->LobbyId);
	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double EpicGames_Lobby_DestroyLobby(char* LobbyId, char* LocalUserID)
{
	EOS_Lobby_DestroyLobbyOptions Options = {0};
	Options.ApiVersion = EOS_LOBBY_DESTROYLOBBY_API_LATEST;
	Options.LobbyId = LobbyId;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserID);

	EOS_Lobby_OnDestroyLobbyCallback CompletionDelegate;

	callback* mcallback = getCallbackData();

	EOS_Lobby_DestroyLobby(HLobby,&Options, mcallback, Lobby_DestroyLobbyCallback);

	return mcallback->identifier;
}

yyfunc char* EpicGames_Lobby_GetConnectString(char* LobbyId, char* LocalUserId)
{
	EOS_Lobby_GetConnectStringOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBY_GETCONNECTSTRING_API_LATEST;
	Options.LobbyId = LobbyId;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	char OutBuffer[1024];
	uint32_t InOutBufferLength = 1024;

	EOS_Lobby_GetConnectString(HLobby, &Options,OutBuffer, &InOutBufferLength);

	return OutBuffer;
}

yyfunc double EpicGames_Lobby_GetInviteCount(char* LocalUserID)
{
	EOS_Lobby_GetInviteCountOptions Options = {0};
	Options.ApiVersion = EOS_LOBBY_GETINVITECOUNT_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserID);
	return EOS_Lobby_GetInviteCount(HLobby,&Options);
}

yyfunc char* EpicGames_Lobby_GetInviteIdByIndex(char* LocalUserID,double index)
{
	EOS_Lobby_GetInviteIdByIndexOptions Options = {0};
	Options.ApiVersion = EOS_LOBBY_GETINVITEIDBYINDEX_API_LATEST;
	Options.Index = (double) index;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserID);

	char OutBuffer[1024];
	int32_t InOutBufferLength = 1024;
	EOS_Lobby_GetInviteIdByIndex(HLobby, &Options,OutBuffer,&InOutBufferLength);

	return OutBuffer;
}

yyfunc char* EpicGames_Lobby_GetRTCRoomName(char* LocalUserID,char* LobbyId)
{
	EOS_Lobby_GetRTCRoomNameOptions Options = {0};
	Options.ApiVersion = EOS_LOBBY_GETRTCROOMNAME_API_LATEST;
	Options.LobbyId = LobbyId;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserID);

	char OutBuffer[1024];
	uint32_t InOutBufferLength = 1024;
	EOS_Lobby_GetRTCRoomName(HLobby, &Options, OutBuffer, &InOutBufferLength);

	return OutBuffer;
}

void EOS_CALL Lobby_HardMuteMemberCallback(const EOS_Lobby_HardMuteMemberCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_HardMuteMember");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "LobbyId", Data->LobbyId);
	DsMapAddString(map, "TargetUserId", productID_toString(Data->TargetUserId));

	CreateAsyncEventWithDSMap(map, 70);
}


yyfunc double EpicGames_Lobby_HardMuteMember(double HardMute,char* LobbyId, char* LocalUserId, char* TargetUserId)
{
	EOS_Lobby_HardMuteMemberOptions Options = {0};
	Options.ApiVersion = EOS_LOBBY_HARDMUTEMEMBER_API_LATEST;
	Options.bHardMute = HardMute>0.5;
	Options.LobbyId = LobbyId;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.TargetUserId = EOS_ProductUserId_FromString(TargetUserId);

	EOS_Lobby_OnHardMuteMemberCallback CompletionDelegate;

	callback* mcallback = getCallbackData();

	EOS_Lobby_HardMuteMember(HLobby,&Options, mcallback,Lobby_HardMuteMemberCallback);

	return mcallback->identifier;

	return 0.0;
}

yyfunc double EpicGames_Lobby_IsRTCRoomConnected(char* LobbyId, char* LocalUserId)
{
	EOS_Lobby_IsRTCRoomConnectedOptions Options = {0};
	Options.ApiVersion = EOS_LOBBY_ISRTCROOMCONNECTED_API_LATEST;
	Options.LobbyId = LobbyId;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	EOS_Bool bOutIsConnected;

	EOS_EResult result = EOS_Lobby_IsRTCRoomConnected(HLobby,&Options,&bOutIsConnected);

	if (EOS_EResult::EOS_Success != result)
		return false;

	return bOutIsConnected?1.0:0.0;
}

void EOS_CALL Lobby_JoinLobbyCallback(const EOS_Lobby_JoinLobbyCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_JoinLobby");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "LobbyId", Data->LobbyId);
	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double SDKEpicGames_Lobby_JoinLobby(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);

	EOS_Lobby_JoinLobbyOptions Options;
	Options.ApiVersion = EOS_LOBBY_JOINLOBBY_API_LATEST;
	Options.bCrossplayOptOut = YYGetBool(args[0]);
	Options.bPresenceEnabled = YYGetBool(args[1]);
	Options.LobbyDetailsHandle = mHLobbyDetails;
	
	EOS_Lobby_LocalRTCOptions LocalRTCOptions = {0};
	LocalRTCOptions.ApiVersion = EOS_LOBBY_LOCALRTCOPTIONS_API_LATEST;
	LocalRTCOptions.bLocalAudioDeviceInputStartsMuted = false;
	LocalRTCOptions.bUseManualAudioInput = false;
	LocalRTCOptions.bUseManualAudioOutput = false;
	LocalRTCOptions.Flags = EOS_RTC_JOINROOMFLAGS_ENABLE_DATACHANNEL;
	
	Options.LocalRTCOptions = &LocalRTCOptions;

	//TODO
	//Options.LocalRTCOptions = NULL;

	Options.LocalUserId = EOS_ProductUserId_FromString(YYGetString(args[6]));
	
	callback* mcallback = getCallbackData();
	EOS_Lobby_JoinLobby(HLobby,&Options,mcallback, Lobby_JoinLobbyCallback);
	return mcallback->identifier;
}

void EOS_CALL Lobby_JoinLobbyByIdCallback(const EOS_Lobby_JoinLobbyByIdCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_JoinLobbyById");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);

	DsMapAddString(map, "LobbyId", Data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double SDKEpicGames_Lobby_JoinLobbyById(char* buff_args)
{

	auto args = buffer_unpack((uint8_t*)buff_args);
	
	EOS_Lobby_JoinLobbyByIdOptions Options = {0};
	Options.ApiVersion = EOS_LOBBY_JOINLOBBYBYID_API_LATEST;
	Options.bCrossplayOptOut = YYGetBool(args[0]);
	Options.bPresenceEnabled = YYGetBool(args[1]);
	Options.LobbyId = YYGetString(args[2]);
	
	EOS_Lobby_LocalRTCOptions LocalRTCOptions = { 0 };
	LocalRTCOptions.ApiVersion = EOS_LOBBY_LOCALRTCOPTIONS_API_LATEST;
	LocalRTCOptions.bLocalAudioDeviceInputStartsMuted = YYGetBool(args[3]);
	LocalRTCOptions.bUseManualAudioInput = YYGetBool(args[4]);
	LocalRTCOptions.bUseManualAudioOutput = YYGetBool(args[5]);
	LocalRTCOptions.Flags = YYGetUint32(args[6]);

	Options.LocalRTCOptions = &LocalRTCOptions;

	Options.LocalUserId = EOS_ProductUserId_FromString(YYGetString(args[7]));

	callback* mcallback = getCallbackData();

	EOS_Lobby_JoinLobbyById(HLobby,&Options, mcallback, Lobby_JoinLobbyByIdCallback);

	return mcallback->identifier;
}

void EOS_CALL Lobby_KickMemberCallback(const EOS_Lobby_KickMemberCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_KickMember");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);

	DsMapAddString(map, "LobbyId", Data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double EpicGames_Lobby_KickMember(char* LobbyId, char* LocalUserId,char* TargetUserId)
{
	EOS_Lobby_KickMemberOptions Options = {0};
	Options.ApiVersion = EOS_LOBBY_KICKMEMBER_API_LATEST;
	Options.LobbyId = LobbyId;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.TargetUserId = EOS_ProductUserId_FromString(TargetUserId);

	callback* mcallback = getCallbackData();

	EOS_Lobby_KickMember(HLobby,&Options, mcallback, Lobby_KickMemberCallback);

	return mcallback->identifier;
}

void EOS_CALL Lobby_LeaveLobbyCallback(const EOS_Lobby_LeaveLobbyCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_LeaveLobby");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);

	DsMapAddString(map, "LobbyId", Data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double EpicGames_Lobby_LeaveLobby(char* LobbyId, char* LocalUserId)
{
	EOS_Lobby_LeaveLobbyOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBY_LEAVELOBBY_API_LATEST;
	Options.LobbyId = LobbyId;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);

	callback* mcallback = getCallbackData();

	EOS_Lobby_LeaveLobby(HLobby,&Options, mcallback,Lobby_LeaveLobbyCallback);
	
	return mcallback->identifier;
}

yyfunc char* EpicGames_Lobby_ParseConnectString()
{
	EOS_Lobby_ParseConnectStringOptions Options = { 0 }; 
	char OutBuffer[1024];
	uint32_t InOutBufferLength = 1024;

	EOS_Lobby_ParseConnectString(HLobby,&Options, OutBuffer, &InOutBufferLength);

	return OutBuffer;
}

void EOS_CALL Lobby_PromoteMemberCallback(const EOS_Lobby_PromoteMemberCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_PromoteMember");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);

	DsMapAddString(map, "LobbyId", Data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double EpicGames_Lobby_PromoteMember(char* LobbyId, char* LocalUserId, char* TargetUserId)
{
	EOS_Lobby_PromoteMemberOptions Options = { 0 };  
	Options.ApiVersion = EOS_LOBBY_PROMOTEMEMBER_API_LATEST;
	Options.LobbyId = LobbyId;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.TargetUserId = EOS_ProductUserId_FromString(TargetUserId);
	
	callback* mcallback = getCallbackData();

	EOS_Lobby_PromoteMember(HLobby,&Options,mcallback, Lobby_PromoteMemberCallback);

	return mcallback->identifier;
}

void EOS_CALL Lobby_QueryInvitesCallback(const EOS_Lobby_QueryInvitesCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_QueryInvites");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);

	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));

	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double EpicGames_Lobby_QueryInvites(char* LocalUserId)
{
	EOS_Lobby_QueryInvitesOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBY_QUERYINVITES_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);

	callback* mcallback = getCallbackData();

	EOS_Lobby_QueryInvites(HLobby, &Options, mcallback, Lobby_QueryInvitesCallback);

	return mcallback->identifier;
}

void EOS_CALL Lobby_RejectInviteCallback(const EOS_Lobby_RejectInviteCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_RejectInvite");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);

	DsMapAddString(map, "status_message", Data->InviteId);

	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double EpicGames_Lobby_RejectInvite(char* InviteId, char* LocalUserId)
{
	EOS_Lobby_RejectInviteOptions  Options = { 0 }; 
	Options.ApiVersion = EOS_LOBBY_REJECTINVITE_API_LATEST;
	Options.InviteId = InviteId;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);

	callback* mcallback = getCallbackData();

	EOS_Lobby_RejectInvite(HLobby,&Options, mcallback, Lobby_RejectInviteCallback);

	return mcallback->identifier;
}

yyfunc double SDKEpicGames_Lobby_RemoveNotifyJoinLobbyAccepted(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId  = YYGetUint64(args[0]);

	EOS_Lobby_RemoveNotifyJoinLobbyAccepted(HLobby, InId);
	return 0.0;
}

yyfunc double SDKEpicGames_Lobby_RemoveNotifyLeaveLobbyRequested(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Lobby_RemoveNotifyLeaveLobbyRequested(HLobby, InId);
	return 0.0;
}

yyfunc double SDKEpicGames_Lobby_RemoveNotifyLobbyInviteAccepted(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Lobby_RemoveNotifyLobbyInviteAccepted(HLobby, InId);
	return 0.0;
}

yyfunc double SDKEpicGames_Lobby_RemoveNotifyLobbyInviteReceived(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Lobby_RemoveNotifyLobbyInviteReceived(HLobby, InId);
	return 0.0;
}

yyfunc double SDKEpicGames_Lobby_RemoveNotifyLobbyInviteRejected(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Lobby_RemoveNotifyLobbyInviteRejected(HLobby, InId);
	return 0.0;
}

yyfunc double SDKEpicGames_Lobby_RemoveNotifyLobbyMemberStatusReceived(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Lobby_RemoveNotifyLobbyMemberStatusReceived(HLobby, InId);
	return 0.0;
}

yyfunc double SDKEpicGames_Lobby_RemoveNotifyLobbyMemberUpdateReceived(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Lobby_RemoveNotifyLobbyMemberUpdateReceived(HLobby, InId);
	return 0.0;
}

yyfunc double SDKEpicGames_Lobby_RemoveNotifyLobbyUpdateReceived(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Lobby_RemoveNotifyLobbyUpdateReceived(HLobby, InId);
	return 0.0;
}

yyfunc double SDKEpicGames_Lobby_RemoveNotifyRTCRoomConnectionChanged(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Lobby_RemoveNotifyRTCRoomConnectionChanged(HLobby, InId);
	return 0.0;
}

yyfunc double SDKEpicGames_Lobby_RemoveNotifySendLobbyNativeInviteRequested(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_Lobby_RemoveNotifySendLobbyNativeInviteRequested(HLobby, InId);
	return 0.0;
}

void EOS_CALL Lobby_SendInviteCallback(const EOS_Lobby_SendInviteCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_SendInvite");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);

	DsMapAddString(map, "LobbyId", Data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double EpicGames_Lobby_SendInvite(char* LobbyId,char* LocalUserId,char* TargetUserId)
{
	EOS_Lobby_SendInviteOptions Options = {0};
	Options.ApiVersion = EOS_LOBBY_SENDINVITE_API_LATEST;
	Options.LobbyId = LobbyId;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.TargetUserId = EOS_ProductUserId_FromString(TargetUserId);

	callback* mcallback = getCallbackData();

	EOS_Lobby_SendInvite(HLobby,&Options,mcallback, Lobby_SendInviteCallback);
	
	return mcallback->identifier;
}

void EOS_CALL Lobby_UpdateLobbyCallback(const EOS_Lobby_UpdateLobbyCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_UpdateLobby");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);

	DsMapAddString(map, "LobbyId", Data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);
}

EOS_HLobbyModification mLobbyModification = NULL;
yyfunc double EpicGames_Lobby_UpdateLobby()
{
	EOS_Lobby_UpdateLobbyOptions Options = {0};
	Options.ApiVersion = EOS_LOBBY_UPDATELOBBY_API_LATEST;
	Options.LobbyModificationHandle = mLobbyModification;

	callback* mcallback = getCallbackData();
	
	EOS_Lobby_UpdateLobby(HLobby, &Options, mcallback, Lobby_UpdateLobbyCallback);

	return mcallback->identifier;
}

yyfunc double EpicGames_Lobby_UpdateLobbyModification(char* LobbyId, char* LocalUserId)
{
	EOS_Lobby_UpdateLobbyModificationOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBY_UPDATELOBBYMODIFICATION_API_LATEST;
	Options.LobbyId = LobbyId;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);

	EOS_EResult result = EOS_Lobby_UpdateLobbyModification(HLobby,&Options,&mLobbyModification);

	return (double) result;
}

yyfunc double EpicGames_LobbyDetails_CopyAttributeByIndex(double index)
{
	EOS_LobbyDetails_CopyAttributeByIndexOptions Options = {0};
	Options.ApiVersion = EOS_LOBBYDETAILS_COPYATTRIBUTEBYINDEX_API_LATEST;
	Options.AttrIndex = index;
	EOS_Lobby_Attribute* OutAttribute = 0;

	EOS_HLobbyDetails Handle = mHLobbyDetails;

	EOS_EResult result = EOS_LobbyDetails_CopyAttributeByIndex(Handle,&Options, &OutAttribute);

	return (double) result;
}

yyfunc double EpicGames_LobbyDetails_CopyAttributeByKey(char* AttrKey)
{
	EOS_HLobbyDetails Handle = mHLobbyDetails;
	EOS_LobbyDetails_CopyAttributeByKeyOptions Options = {0};
	Options.ApiVersion = EOS_LOBBYDETAILS_COPYATTRIBUTEBYKEY_API_LATEST;
	Options.AttrKey = AttrKey;

	EOS_Lobby_Attribute* OutAttribute = 0;

	EOS_EResult result = EOS_LobbyDetails_CopyAttributeByKey(Handle,&Options,&OutAttribute);

	return (double) result;
}

yyfunc double SDKEpicGames_LobbyDetails_CopyInfo(char* buff_ret)
{
	EOS_LobbyDetails_CopyInfoOptions Options = {0};
	Options.ApiVersion = EOS_LOBBYDETAILS_COPYINFO_API_LATEST;

	EOS_LobbyDetails_Info* OutLobbyDetailsInfo;
	EOS_EResult result = EOS_LobbyDetails_CopyInfo(mHLobbyDetails,&Options,&OutLobbyDetailsInfo);

	if (EOS_EResult::EOS_Success == result)
	{
		StructStream _struct = {};

		_struct.addKeyValue("AvailableSlots", OutLobbyDetailsInfo->AvailableSlots);
		_struct.addKeyValue("bAllowHostMigration", OutLobbyDetailsInfo->bAllowHostMigration);
		_struct.addKeyValue("bAllowInvites", OutLobbyDetailsInfo->bAllowInvites);
		_struct.addKeyValue("bAllowJoinById", OutLobbyDetailsInfo->bAllowJoinById);
		_struct.addKeyValue("bPresenceEnabled", OutLobbyDetailsInfo->bPresenceEnabled);
		_struct.addKeyValue("bRejoinAfterKickRequiresInvite", OutLobbyDetailsInfo->bRejoinAfterKickRequiresInvite);
		_struct.addKeyValue("bRTCRoomEnabled", OutLobbyDetailsInfo->bRTCRoomEnabled);

		if (OutLobbyDetailsInfo->BucketId != NULL)
			_struct.addKeyValue("BucketId", (const char*)OutLobbyDetailsInfo->BucketId);
		if (OutLobbyDetailsInfo->LobbyId != NULL)
			_struct.addKeyValue("LobbyId", (const char*)OutLobbyDetailsInfo->LobbyId);
		if (OutLobbyDetailsInfo->LobbyOwnerUserId != NULL)
			_struct.addKeyValue("LobbyOwnerUserId", (const char*) productID_toString(OutLobbyDetailsInfo->LobbyOwnerUserId));
		_struct.addKeyValue("MaxMembers", OutLobbyDetailsInfo->MaxMembers);
		_struct.addKeyValue("PermissionLevel", (double) OutLobbyDetailsInfo->PermissionLevel);

		_struct.writeTo(buff_ret);

		EOS_LobbyDetails_Info_Release(OutLobbyDetailsInfo);
	}
	else
	{
		StructStream _struct = {};
		_struct.writeTo(buff_ret);
	}

	return (double) result;
}

yyfunc double EpicGames_LobbyDetails_CopyMemberAttributeByIndex(double index, char* TargetUserId)
{
	EOS_HLobbyDetails Handle = mHLobbyDetails;
	EOS_LobbyDetails_CopyMemberAttributeByIndexOptions Options = {0};
	Options.ApiVersion = EOS_LOBBYDETAILS_COPYMEMBERATTRIBUTEBYINDEX_API_LATEST;
	Options.AttrIndex = index;
	Options.TargetUserId = EOS_ProductUserId_FromString(TargetUserId);

	EOS_Lobby_Attribute* OutAttribute;

	EOS_EResult result = EOS_LobbyDetails_CopyMemberAttributeByIndex(Handle,&Options,&OutAttribute);
	return (double) result;
}

yyfunc double EpicGames_LobbyDetails_CopyMemberAttributeByKey(char* AttrKey,char* TargetUserId)
{
	EOS_HLobbyDetails Handle = mHLobbyDetails;
	EOS_LobbyDetails_CopyMemberAttributeByKeyOptions Options = {0};
	Options.ApiVersion = EOS_LOBBYDETAILS_COPYMEMBERATTRIBUTEBYKEY_API_LATEST;
	Options.AttrKey = AttrKey;
	Options.TargetUserId = EOS_ProductUserId_FromString(TargetUserId);

	EOS_Lobby_Attribute* OutAttribute;

	EOS_EResult result = EOS_LobbyDetails_CopyMemberAttributeByKey(Handle, &Options, &OutAttribute);
	return (double) result;
}

yyfunc double EpicGames_LobbyDetails_CopyMemberInfo(char* TargetUserId)
{
	EOS_HLobbyDetails Handle = mHLobbyDetails;
	EOS_LobbyDetails_CopyMemberInfoOptions Options = {0};
	Options.ApiVersion = EOS_LOBBYDETAILS_COPYMEMBERINFO_API_LATEST;
	Options.TargetUserId = EOS_ProductUserId_FromString(TargetUserId);

	EOS_LobbyDetails_MemberInfo* OutLobbyDetailsMemberInfo;

	EOS_EResult result = EOS_LobbyDetails_CopyMemberInfo(Handle, &Options, &OutLobbyDetailsMemberInfo);
	return (double) result;
}

yyfunc double EpicGames_LobbyDetails_GetAttributeCount()
{
	EOS_HLobbyDetails Handle = mHLobbyDetails;
	EOS_LobbyDetails_GetAttributeCountOptions Options = {0};
	Options.ApiVersion = EOS_LOBBYDETAILS_GETATTRIBUTECOUNT_API_LATEST;

	return EOS_LobbyDetails_GetAttributeCount(Handle,&Options);
}

yyfunc char* EpicGames_LobbyDetails_GetLobbyOwner()
{
	EOS_HLobbyDetails Handle = mHLobbyDetails;
	EOS_LobbyDetails_GetLobbyOwnerOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBYDETAILS_GETLOBBYOWNER_API_LATEST;
	EOS_ProductUserId p = EOS_LobbyDetails_GetLobbyOwner(Handle,&Options);

	return productID_toString(p);
}

yyfunc double EpicGames_LobbyDetails_GetMemberAttributeCount(char* TargetUserId)
{
	EOS_HLobbyDetails Handle = mHLobbyDetails;
	EOS_LobbyDetails_GetMemberAttributeCountOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBYDETAILS_GETMEMBERATTRIBUTECOUNT_API_LATEST;
	Options.TargetUserId = EOS_ProductUserId_FromString(TargetUserId);

	return EOS_LobbyDetails_GetMemberAttributeCount(Handle,&Options);
}

yyfunc char* EpicGames_LobbyDetails_GetMemberByIndex(double index)
{
	EOS_HLobbyDetails Handle = mHLobbyDetails;
	EOS_LobbyDetails_GetMemberByIndexOptions Options = {0};
	Options.ApiVersion = EOS_LOBBYDETAILS_GETMEMBERBYINDEX_API_LATEST;
	Options.MemberIndex = index;

	EOS_ProductUserId p = EOS_LobbyDetails_GetMemberByIndex(Handle,&Options);
	return productID_toString(p);
}

yyfunc double EpicGames_LobbyDetails_GetMemberCount()
{
	EOS_HLobbyDetails Handle = mHLobbyDetails;
	EOS_LobbyDetails_GetMemberCountOptions Options = {0};
	Options.ApiVersion = EOS_LOBBYDETAILS_GETMEMBERCOUNT_API_LATEST;

	return EOS_LobbyDetails_GetMemberCount(Handle,&Options);
}

yyfunc double EpicGames_LobbyDetails_Info_Release()
{
	EOS_LobbyDetails_Info LobbyDetailsInfo = { 0 };
	EOS_LobbyDetails_Info_Release(&LobbyDetailsInfo);

	return 0.0;
}

yyfunc double EpicGames_LobbyDetails_MemberInfo_Release(double AllowsCrossplay, double Platform, char* UserId)
{
	EOS_LobbyDetails_MemberInfo LobbyDetailsMemberInfo = {0};
	LobbyDetailsMemberInfo.ApiVersion = EOS_LOBBYDETAILS_MEMBERINFO_API_LATEST;
	LobbyDetailsMemberInfo.bAllowsCrossplay = AllowsCrossplay;
	LobbyDetailsMemberInfo.Platform = (double)Platform;
	LobbyDetailsMemberInfo.UserId = EOS_ProductUserId_FromString(UserId);

	EOS_LobbyDetails_MemberInfo_Release(&LobbyDetailsMemberInfo);

	return 0.0;
}

yyfunc double EpicGames_LobbyDetails_Release()
{
	EOS_HLobbyDetails LobbyHandle = mHLobbyDetails;
	EOS_LobbyDetails_Release(LobbyHandle);
	mHLobbyDetails = NULL;

	return 0.0;
}

EOS_Lobby_AttributeData AttributeDataFromStruct(std::map<std::string, const uint8_t*> Attribute)
{
	EOS_Lobby_AttributeData mSessionAttribute = { 0 };

	mSessionAttribute.ApiVersion = EOS_SESSIONS_ATTRIBUTEDATA_API_LATEST;
	mSessionAttribute.Key = YYGetString(Attribute["Key"]);

	switch ((int)YYGetReal(Attribute["ValueType"]))
	{
	case 0: mSessionAttribute.ValueType = EOS_EAttributeType::EOS_AT_BOOLEAN; mSessionAttribute.Value.AsBool = YYGetBool(Attribute["Value"]); break;
	case 1: mSessionAttribute.ValueType = EOS_EAttributeType::EOS_AT_INT64; mSessionAttribute.Value.AsInt64 = YYGetUint64(Attribute["Value"]); break;
	case 2: mSessionAttribute.ValueType = EOS_EAttributeType::EOS_AT_DOUBLE; mSessionAttribute.Value.AsDouble = YYGetReal(Attribute["Value"]); break;
	case 3: mSessionAttribute.ValueType = EOS_EAttributeType::EOS_AT_STRING; mSessionAttribute.Value.AsUtf8 = YYGetString(Attribute["Value"]); break;
	}

	return mSessionAttribute;
}


yyfunc double SDKEpicGames_LobbyModification_AddAttribute(double Visibility,char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	auto Attribute = YYGetStruct(args[0]);

	EOS_Lobby_AttributeData mAttributeData = AttributeDataFromStruct(Attribute);
	
	EOS_HLobbyModification Handle = mLobbyModification;
	EOS_LobbyModification_AddAttributeOptions Options = {0};
	Options.ApiVersion = EOS_LOBBYMODIFICATION_ADDATTRIBUTE_API_LATEST;
	Options.Attribute = &mAttributeData;
	Options.Visibility = (EOS_ELobbyAttributeVisibility)Visibility;

	EOS_EResult result = EOS_LobbyModification_AddAttribute(Handle,&Options);

	return (double)result;
}

yyfunc double SDKEpicGames_LobbyModification_AddMemberAttribute(double Visibility, char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	auto Attribute = YYGetStruct(args[0]);

	EOS_Lobby_AttributeData mAttributeData = AttributeDataFromStruct(Attribute);

	EOS_HLobbyModification Handle = mLobbyModification;
	EOS_LobbyModification_AddMemberAttributeOptions Options = {0};
	Options.ApiVersion = EOS_LOBBYMODIFICATION_ADDMEMBERATTRIBUTE_API_LATEST;
	Options.Attribute = &mAttributeData;
	Options.Visibility = (EOS_ELobbyAttributeVisibility)Visibility;
	EOS_EResult result = EOS_LobbyModification_AddMemberAttribute(Handle,&Options);

	return (double)result;
}

yyfunc double EpicGames_LobbyModification_Release()
{
	EOS_HLobbyModification LobbyModificationHandle = mLobbyModification;

	EOS_LobbyModification_Release(LobbyModificationHandle);

	return 0.0;
}

yyfunc double EpicGames_LobbyModification_RemoveAttribute(char* Key)
{
	EOS_HLobbyModification Handle = mLobbyModification;
	EOS_LobbyModification_RemoveAttributeOptions Options = {0};
	Options.ApiVersion = EOS_LOBBYMODIFICATION_REMOVEATTRIBUTE_API_LATEST;
	Options.Key = Key;

	EOS_EResult result = EOS_LobbyModification_RemoveAttribute(Handle,&Options);

	return (double) result;
}

yyfunc double EpicGames_LobbyModification_RemoveMemberAttribute(char* Key)
{
	EOS_HLobbyModification Handle = mLobbyModification;
	EOS_LobbyModification_RemoveMemberAttributeOptions Options = {0};
	Options.ApiVersion = EOS_LOBBYMODIFICATION_REMOVEMEMBERATTRIBUTE_API_LATEST;
	Options.Key = Key;

	EOS_EResult result = EOS_LobbyModification_RemoveMemberAttribute(Handle, &Options);

	return (double) result;
}

yyfunc double SDKEpicGames_LobbyModification_SetAllowedPlatformIds(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);

	EOS_HLobbyModification Handle = mLobbyModification;
	EOS_LobbyModification_SetAllowedPlatformIdsOptions Options = {0};
	Options.ApiVersion = EOS_LOBBYMODIFICATION_SETALLOWEDPLATFORMIDS_API_LATEST;

	auto array_ids = YYGetArray(args[0]);
	std::vector<uint32_t> ids = VectorUInt32FromVector(array_ids);

	Options.AllowedPlatformIds = ids.data();
	Options.AllowedPlatformIdsCount = ids.size();
	
	EOS_EResult result = EOS_LobbyModification_SetAllowedPlatformIds(Handle, &Options);

	return (double) result;
}

yyfunc double EpicGames_LobbyModification_SetBucketId(char* BucketId)
{
	EOS_HLobbyModification Handle = mLobbyModification;
	EOS_LobbyModification_SetBucketIdOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBYMODIFICATION_SETBUCKETID_API_LATEST;
	Options.BucketId = BucketId;

	EOS_EResult result = EOS_LobbyModification_SetBucketId(Handle,&Options);

	return (double)result;
}

yyfunc double EpicGames_LobbyModification_SetInvitesAllowed(double InvitesAllowed)
{
	EOS_HLobbyModification Handle = mLobbyModification;
	EOS_LobbyModification_SetInvitesAllowedOptions Options = {0};
	Options.ApiVersion = EOS_LOBBYMODIFICATION_SETINVITESALLOWED_API_LATEST;
	Options.bInvitesAllowed = InvitesAllowed>0.5;

	EOS_EResult result = EOS_LobbyModification_SetInvitesAllowed(Handle,&Options);

	return (double) result;
}

yyfunc double EpicGames_LobbyModification_SetMaxMembers(double MaxMembers)
{
	EOS_HLobbyModification Handle = mLobbyModification;
	EOS_LobbyModification_SetMaxMembersOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBYMODIFICATION_SETMAXMEMBERS_API_LATEST;
	Options.MaxMembers = MaxMembers;
	
	EOS_EResult result = EOS_LobbyModification_SetMaxMembers(Handle, &Options);
	return (double) result;
}

yyfunc double EpicGames_LobbyModification_SetPermissionLevel(double PermissionLevel)
{
	EOS_HLobbyModification Handle = mLobbyModification;
	EOS_LobbyModification_SetPermissionLevelOptions Options = {0};
	Options.ApiVersion = EOS_LOBBYMODIFICATION_SETPERMISSIONLEVEL_API_LATEST;
	Options.PermissionLevel = (EOS_ELobbyPermissionLevel)PermissionLevel;

	EOS_EResult result = EOS_LobbyModification_SetPermissionLevel(Handle,&Options);

	return (double) result;
}

yyfunc double EpicGames_LobbySearch_CopySearchResultByIndex(double Index)
{
	EOS_HLobbySearch Handle = mHLobbySearch;
	EOS_LobbySearch_CopySearchResultByIndexOptions Options = {0};
	Options.ApiVersion = EOS_LOBBYSEARCH_COPYSEARCHRESULTBYINDEX_API_LATEST;
	Options.LobbyIndex = Index;

	EOS_EResult result = EOS_LobbySearch_CopySearchResultByIndex(Handle,&Options, &mHLobbyDetails);

	return (double) result;
}

void EOS_CALL LobbySearch_FindCallback(const EOS_LobbySearch_FindCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_LobbySearch_Find");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);

	CreateAsyncEventWithDSMap(map, 70);
}

yyfunc double EpicGames_LobbySearch_Find(char* LocalUserId)
{
	EOS_HLobbySearch Handle = mHLobbySearch;
	EOS_LobbySearch_FindOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBYSEARCH_FIND_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	
	callback* mcallback = getCallbackData();

	EOS_LobbySearch_Find(Handle,&Options,mcallback, LobbySearch_FindCallback);

	return mcallback->identifier;
}

yyfunc double EpicGames_LobbySearch_GetSearchResultCount()
{
	EOS_HLobbySearch Handle = mHLobbySearch;
	EOS_LobbySearch_GetSearchResultCountOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBYSEARCH_GETSEARCHRESULTCOUNT_API_LATEST;

	return EOS_LobbySearch_GetSearchResultCount(Handle,&Options);
}

yyfunc double EpicGames_LobbySearch_Release()
{
	EOS_HLobbySearch LobbySearchHandle = mHLobbySearch;
	EOS_LobbySearch_Release(LobbySearchHandle);
	mHLobbySearch = NULL;

	return 0.0;
}

yyfunc double EpicGames_LobbySearch_RemoveParameter(char* Key, double ComparisonOp)
{
	EOS_HLobbySearch Handle = mHLobbySearch;
	EOS_LobbySearch_RemoveParameterOptions Options = {0};
	Options.ApiVersion = EOS_LOBBYSEARCH_REMOVEPARAMETER_API_LATEST;
	Options.ComparisonOp = (EOS_EComparisonOp) ComparisonOp;
	Options.Key = Key;

	EOS_LobbySearch_RemoveParameter(Handle, &Options);
	return 0.0;
}

yyfunc double EpicGames_LobbySearch_SetLobbyId(char* LobbyId)
{
	EOS_HLobbySearch Handle = mHLobbySearch;
	EOS_LobbySearch_SetLobbyIdOptions Options = {0};
	Options.ApiVersion = EOS_LOBBYSEARCH_SETLOBBYID_API_LATEST;
	Options.LobbyId = LobbyId;

	EOS_EResult result = EOS_LobbySearch_SetLobbyId(Handle,&Options);

	return (double) result;
}

yyfunc double EpicGames_LobbySearch_SetMaxResults(double MaxResults)
{
	EOS_HLobbySearch Handle = mHLobbySearch;
	EOS_LobbySearch_SetMaxResultsOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBYSEARCH_SETMAXRESULTS_API_LATEST;
	Options.MaxResults = MaxResults;

	EOS_EResult result = EOS_LobbySearch_SetMaxResults(Handle, &Options);

	return (double) result;
}

yyfunc double SDKEpicGames_LobbySearch_SetParameter(double ComparisonOp,char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	auto Attribute = YYGetStruct(args[0]);

	EOS_Lobby_AttributeData mAttributeData = AttributeDataFromStruct(Attribute);

	EOS_HLobbySearch Handle = mHLobbySearch;
	EOS_LobbySearch_SetParameterOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBYSEARCH_SETPARAMETER_API_LATEST;
	Options.ComparisonOp = (EOS_EComparisonOp)ComparisonOp;
	Options.Parameter = &mAttributeData;

	EOS_EResult result = EOS_LobbySearch_SetParameter(Handle, &Options);

	return (double) result;
}

yyfunc double EpicGames_LobbySearch_SetTargetUserId(char* TargetUserId)
{
	EOS_HLobbySearch Handle = mHLobbySearch;
	EOS_LobbySearch_SetTargetUserIdOptions Options = { 0 };
	Options.ApiVersion = EOS_LOBBYSEARCH_SETTARGETUSERID_API_LATEST;
	Options.TargetUserId = EOS_ProductUserId_FromString(TargetUserId);

	EOS_EResult result = EOS_LobbySearch_SetTargetUserId(Handle, &Options);

	return (double) result;
}


