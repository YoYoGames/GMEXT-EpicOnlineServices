
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
	DsMapAddDouble(map, "ui_event_id", (double)Data->UiEventId);

	CreateAsyncEventWithDSMap(map, 70);
}

func double EpicGames_Lobby_AddNotifyJoinLobbyAccepted()
{
	EOS_Lobby_AddNotifyJoinLobbyAcceptedOptions Options = { 0 };
	
	//callback* mcallback = getCallbackData();

	return EOS_Lobby_AddNotifyJoinLobbyAccepted(HLobby, &Options, NULL/*mcallback*/, Lobby_OnJoinLobbyAcceptedCallback);

	//return mcallback->identifier;

	return 0.0;
}

void EOS_CALL Lobby_AddNotifyLeaveLobbyRequested(const EOS_Lobby_LeaveLobbyRequestedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_AddNotifyLeaveLobbyRequested");
	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));
	DsMapAddString(map, "LobbyId", Data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);
}

func double EpicGames_Lobby_AddNotifyLeaveLobbyRequested()
{
	EOS_Lobby_AddNotifyLeaveLobbyRequestedOptions Options = { 0 };

	//callback* mcallback = getCallbackData();

	return EOS_Lobby_AddNotifyLeaveLobbyRequested(HLobby, &Options, NULL/*mcallback*/, Lobby_AddNotifyLeaveLobbyRequested);

	//return mcallback->identifier;

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

func double EpicGames_Lobby_AddNotifyLobbyInviteAccepted()
{
	EOS_Lobby_AddNotifyLobbyInviteAcceptedOptions Options = { 0 };

	//callback* mcallback = getCallbackData();

	return EOS_Lobby_AddNotifyLobbyInviteAccepted(HLobby, &Options, NULL/*mcallback*/, Lobby_OnLobbyInviteAcceptedCallback);

	//return mcallback->identifier;

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

func double EpicGames_Lobby_AddNotifyLobbyInviteReceived()
{
	EOS_Lobby_AddNotifyLobbyInviteReceivedOptions Options = { 0 };

	//callback* mcallback = getCallbackData();

	return EOS_Lobby_AddNotifyLobbyInviteReceived(HLobby, &Options, NULL/*mcallback*/, Lobby_AddNotifyLobbyInviteReceivedCallback);

	//return mcallback->identifier;

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

func double EpicGames_Lobby_AddNotifyLobbyInviteRejected()
{
	EOS_Lobby_AddNotifyLobbyInviteRejectedOptions Options = { 0 };

	//callback* mcallback = getCallbackData();

	return EOS_Lobby_AddNotifyLobbyInviteRejected(HLobby, &Options, NULL/*mcallback*/, Lobby_AddNotifyLobbyInviteRejectedCallback);

	//return mcallback->identifier;

	return 0.0;
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

func double EpicGames_Lobby_AddNotifyLobbyMemberStatusReceived()
{
	EOS_Lobby_AddNotifyLobbyMemberStatusReceivedOptions Options = { 0 };

	//callback* mcallback = getCallbackData();

	return EOS_Lobby_AddNotifyLobbyMemberStatusReceived(HLobby, &Options, NULL/*mcallback*/, Lobby_AddNotifyLobbyMemberStatusReceivedCallback);

	//return mcallback->identifier;

	return 0.0;
} 

void EOS_CALL Lobby_AddNotifyLobbyMemberUpdateReceivedCallback(const EOS_Lobby_LobbyMemberUpdateReceivedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_AddNotifyLobbyMemberUpdateReceived");
	
	DsMapAddString(map, "TargetUserId", productID_toString(Data->TargetUserId));
	DsMapAddString(map, "LobbyId", Data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);
}

func double EpicGames_Lobby_AddNotifyLobbyMemberUpdateReceived()
{
	EOS_Lobby_AddNotifyLobbyMemberUpdateReceivedOptions Options = { 0 };

	//callback* mcallback = getCallbackData();

	return EOS_Lobby_AddNotifyLobbyMemberUpdateReceived(HLobby, &Options, NULL/*mcallback*/, Lobby_AddNotifyLobbyMemberUpdateReceivedCallback);

	//return mcallback->identifier;

	return 0.0;
} 

void EOS_CALL Lobby_AddNotifyLobbyUpdateReceivedCallback(const EOS_Lobby_LobbyUpdateReceivedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_AddNotifyLobbyUpdateReceived");
	DsMapAddString(map, "LobbyId", Data->LobbyId);

	CreateAsyncEventWithDSMap(map, 70);
}

func double EpicGames_Lobby_AddNotifyLobbyUpdateReceived()
{
	EOS_Lobby_AddNotifyLobbyUpdateReceivedOptions Options = { 0 };

	//callback* mcallback = getCallbackData();

	return EOS_Lobby_AddNotifyLobbyUpdateReceived(HLobby, &Options, NULL/*mcallback*/, Lobby_AddNotifyLobbyUpdateReceivedCallback);

	//return mcallback->identifier;

	return 0.0;
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

func double EpicGames_Lobby_AddNotifyRTCRoomConnectionChanged()
{
	EOS_Lobby_AddNotifyRTCRoomConnectionChangedOptions Options = { 0 };

	//callback* mcallback = getCallbackData();

	return EOS_Lobby_AddNotifyRTCRoomConnectionChanged(HLobby, &Options, NULL/*mcallback*/, Lobby_AddNotifyRTCRoomConnectionChangedCallback);

	//return mcallback->identifier;

	return 0.0;
} 

void EOS_CALL Lobby_AddNotifySendLobbyNativeInviteRequestedCallback(const EOS_Lobby_SendLobbyNativeInviteRequestedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Lobby_AddNotifySendLobbyNativeInviteRequested");
	
	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));
	DsMapAddString(map, "LobbyId", Data->LobbyId);

	DsMapAddString(map, "LocalUserId", Data->TargetNativeAccountType);
	DsMapAddString(map, "LobbyId", Data->TargetUserNativeAccountId);
	DsMapAddDouble(map, "UiEventId", Data->UiEventId);

	CreateAsyncEventWithDSMap(map, 70);
}

func double EpicGames_Lobby_AddNotifySendLobbyNativeInviteRequested()
{
	EOS_Lobby_AddNotifySendLobbyNativeInviteRequestedOptions Options = { 0 };

	//callback* mcallback = getCallbackData();

	return EOS_Lobby_AddNotifySendLobbyNativeInviteRequested(HLobby, &Options, NULL/*mcallback*/, Lobby_AddNotifySendLobbyNativeInviteRequestedCallback);

	//return mcallback->identifier;

	return 0.0;
} 

func double EpicGames_Lobby_Attribute_Release()
{
	EOS_Lobby_Attribute LobbyAttribute = {0};
	EOS_Lobby_Attribute_Release(&LobbyAttribute);
	return 0.0;
} 

func double EpicGames_Lobby_CopyLobbyDetailsHandle()
{
	EOS_Lobby_CopyLobbyDetailsHandleOptions Options; 
	EOS_HLobbyDetails OutLobbyDetailsHandle;

	EOS_Lobby_CopyLobbyDetailsHandle(HLobby,&Options,&OutLobbyDetailsHandle);

	return 0.0;
} 

func double EpicGames_Lobby_CopyLobbyDetailsHandleByInviteId()
{
	EOS_Lobby_CopyLobbyDetailsHandleByInviteIdOptions Options = {0};
	EOS_HLobbyDetails OutLobbyDetailsHandle;

	EOS_Lobby_CopyLobbyDetailsHandleByInviteId(HLobby,&Options, &OutLobbyDetailsHandle);

	return 0.0;
} 

func double EpicGames_Lobby_CopyLobbyDetailsHandleByUiEventId()
{
	EOS_Lobby_CopyLobbyDetailsHandleByUiEventIdOptions Options = { 0 };
	EOS_HLobbyDetails OutLobbyDetailsHandle;

	EOS_Lobby_CopyLobbyDetailsHandleByUiEventId(HLobby,&Options, &OutLobbyDetailsHandle);

	return 0.0;
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

func double EpicGames_Lobby_CreateLobby()
{
	EOS_Lobby_CreateLobbyOptions Options = { 0 };

	callback* mcallback = getCallbackData();
	EOS_Lobby_CreateLobby(HLobby,&Options, mcallback,Lobby_CreateLobbyCallback);

	return mcallback->identifier;
} 

func double EpicGames_Lobby_CreateLobbySearch()
{
	EOS_Lobby_CreateLobbySearchOptions Options = {0};
	EOS_HLobbySearch OutLobbySearchHandle;

	EOS_Lobby_CreateLobbySearch(HLobby,&Options, &OutLobbySearchHandle);

	return 0.0;
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

func double EpicGames_Lobby_DestroyLobby()
{
	EOS_Lobby_DestroyLobbyOptions Options = {0};
	EOS_Lobby_OnDestroyLobbyCallback CompletionDelegate;

	callback* mcallback = getCallbackData();

	EOS_Lobby_DestroyLobby(HLobby,&Options, mcallback, Lobby_DestroyLobbyCallback);

	return mcallback->identifier;
} 

func double EpicGames_Lobby_GetConnectString()
{
	//EOS_HLobby Handle, const EOS_Lobby_GetConnectStringOptions* Options, char* OutBuffer, uint32_t* InOutBufferLength

	//EOS_Lobby_GetConnectString()

	return 0.0;
} 

func double EpicGames_Lobby_GetInviteCount()
{
	const EOS_Lobby_GetInviteCountOptions Options;
	EOS_Lobby_GetInviteCount(HLobby,&Options);
	return 0.0;
} 

func double EpicGames_Lobby_GetInviteIdByIndex()
{
	//EOS_Lobby_GetInviteIdByIndexOptions* Options;, 
	//char* OutBuffer,
	//int32_t* InOutBufferLength;
	//EOS_Lobby_GetInviteIdByIndex(HLobby, &Options);
	return 0.0;
} 

func double EpicGames_Lobby_GetRTCRoomName()
{
	//EOS_Lobby_GetRTCRoomNameOptions* Options, char* OutBuffer, uint32_t* InOutBufferLength
	//EOS_Lobby_GetRTCRoomName()

	return 0.0;
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


func double EpicGames_Lobby_HardMuteMember()
{
	EOS_Lobby_HardMuteMemberOptions Options = {0};

	EOS_Lobby_OnHardMuteMemberCallback CompletionDelegate;

	callback* mcallback = getCallbackData();

	EOS_Lobby_HardMuteMember(HLobby,&Options, mcallback,Lobby_HardMuteMemberCallback);

	return mcallback->identifier;

	return 0.0;
} 

func double EpicGames_Lobby_IsRTCRoomConnected()
{
	EOS_Lobby_IsRTCRoomConnectedOptions Options = {0};
	EOS_Bool bOutIsConnected;

	EOS_Lobby_IsRTCRoomConnected(HLobby,&Options,&bOutIsConnected);

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

func double EpicGames_Lobby_JoinLobby()
{
	EOS_Lobby_JoinLobbyOptions Options;

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

func double EpicGames_Lobby_JoinLobbyById()
{
	EOS_HLobby Handle;
	EOS_Lobby_JoinLobbyByIdOptions Options = {0};

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

func double EpicGames_Lobby_KickMember()
{
	const EOS_Lobby_KickMemberOptions Options = {0};

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

func double EpicGames_Lobby_LeaveLobby()
{
	EOS_Lobby_LeaveLobbyOptions Options = { 0 };

	callback* mcallback = getCallbackData();

	EOS_Lobby_LeaveLobby(HLobby,&Options, mcallback,Lobby_LeaveLobbyCallback);
	
	return mcallback->identifier;
} 

func double EpicGames_Lobby_ParseConnectString()
{
	//const EOS_Lobby_ParseConnectStringOptions* Options, char* OutBuffer, uint32_t* InOutBufferLength
	//EOS_Lobby_ParseConnectString()

	return 0.0;
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

func double EpicGames_Lobby_PromoteMember()
{
	EOS_Lobby_PromoteMemberOptions Options = { 0 };  
	
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

func double EpicGames_Lobby_QueryInvites()
{
	EOS_Lobby_QueryInvitesOptions Options = { 0 };

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

func double EpicGames_Lobby_RejectInvite()
{
	EOS_Lobby_RejectInviteOptions  Options = { 0 }; 

	callback* mcallback = getCallbackData();

	EOS_Lobby_RejectInvite(HLobby,&Options, mcallback, Lobby_RejectInviteCallback);

	return mcallback->identifier;
} 

func double EpicGames_Lobby_RemoveNotifyJoinLobbyAccepted()
{
	EOS_NotificationId InId = 0;
	EOS_Lobby_RemoveNotifyJoinLobbyAccepted(HLobby, InId);
	return 0.0;
} 

func double EpicGames_Lobby_RemoveNotifyLeaveLobbyRequested()
{
	EOS_NotificationId InId = 0;
	EOS_Lobby_RemoveNotifyLeaveLobbyRequested(HLobby, InId);
	return 0.0;
} 

func double EpicGames_Lobby_RemoveNotifyLobbyInviteAccepted()
{
	EOS_NotificationId InId = 0;
	EOS_Lobby_RemoveNotifyLobbyInviteAccepted(HLobby, InId);
	return 0.0;
} 

func double EpicGames_Lobby_RemoveNotifyLobbyInviteReceived()
{
	EOS_NotificationId InId = 0;
	EOS_Lobby_RemoveNotifyLobbyInviteReceived(HLobby, InId);
	return 0.0;
} 

func double EpicGames_Lobby_RemoveNotifyLobbyInviteRejected()
{
	EOS_NotificationId InId = 0;
	EOS_Lobby_RemoveNotifyLobbyInviteRejected(HLobby, InId);
	return 0.0;
} 

func double EpicGames_Lobby_RemoveNotifyLobbyMemberStatusReceived()
{
	EOS_NotificationId InId = 0;
	EOS_Lobby_RemoveNotifyLobbyMemberStatusReceived(HLobby, InId);
	return 0.0;
} 

func double EpicGames_Lobby_RemoveNotifyLobbyMemberUpdateReceived()
{
	EOS_NotificationId InId = 0;
	EOS_Lobby_RemoveNotifyLobbyMemberUpdateReceived(HLobby, InId);
	return 0.0;
} 

func double EpicGames_Lobby_RemoveNotifyLobbyUpdateReceived()
{
	EOS_NotificationId InId = 0;
	EOS_Lobby_RemoveNotifyLobbyUpdateReceived(HLobby, InId);
	return 0.0;
} 

func double EpicGames_Lobby_RemoveNotifyRTCRoomConnectionChanged()
{
	EOS_NotificationId InId = 0;
	EOS_Lobby_RemoveNotifyRTCRoomConnectionChanged(HLobby, InId);
	return 0.0;
} 

func double EpicGames_Lobby_RemoveNotifySendLobbyNativeInviteRequested()
{
	EOS_NotificationId InId = 0;
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

func double EpicGames_Lobby_SendInvite()
{
	EOS_Lobby_SendInviteOptions Options = {0};

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

func double EpicGames_Lobby_UpdateLobby()
{
	EOS_Lobby_UpdateLobbyOptions Options = {0};

	callback* mcallback = getCallbackData();
	
	EOS_Lobby_UpdateLobby(HLobby, &Options, mcallback, Lobby_UpdateLobbyCallback);

	return mcallback->identifier;
} 

func double EpicGames_Lobby_UpdateLobbyModification()
{
	EOS_Lobby_UpdateLobbyModificationOptions Options = { 0 };

	EOS_HLobbyModification OutLobbyModificationHandle;

	EOS_Lobby_UpdateLobbyModification(HLobby,&Options,&OutLobbyModificationHandle);

	return 0;
} 

func double EpicGames_LobbyDetails_CopyAttributeByIndex()
{
	const EOS_LobbyDetails_CopyAttributeByIndexOptions Options = {0};
	EOS_Lobby_Attribute* OutAttribute = 0;

	EOS_HLobbyDetails Handle = 0;

	EOS_LobbyDetails_CopyAttributeByIndex(Handle,&Options, &OutAttribute);

	return 0.0;
} 

func double EpicGames_LobbyDetails_CopyAttributeByKey()
{
	EOS_HLobbyDetails Handle = 0; 
	EOS_LobbyDetails_CopyAttributeByKeyOptions Options = {0};
	EOS_Lobby_Attribute* OutAttribute = 0;

	EOS_LobbyDetails_CopyAttributeByKey(Handle,&Options,&OutAttribute);

	return 0.0;
} 

func double EpicGames_LobbyDetails_CopyInfo()
{
	EOS_HLobbyDetails Handle = 0;
	EOS_LobbyDetails_CopyInfoOptions Options = {0};
	EOS_LobbyDetails_Info* OutLobbyDetailsInfo;
	EOS_LobbyDetails_CopyInfo(Handle,&Options,&OutLobbyDetailsInfo);

	return 0.0;
} 

func double EpicGames_LobbyDetails_CopyMemberAttributeByIndex()
{
	EOS_HLobbyDetails Handle = 0;
	EOS_LobbyDetails_CopyMemberAttributeByIndexOptions Options = {0};
	EOS_Lobby_Attribute* OutAttribute;

	EOS_LobbyDetails_CopyMemberAttributeByIndex(Handle,&Options,&OutAttribute);
	return 0.0;
} 

func double EpicGames_LobbyDetails_CopyMemberAttributeByKey()
{
	EOS_HLobbyDetails Handle = 0; 
	EOS_LobbyDetails_CopyMemberAttributeByKeyOptions Options;
	EOS_Lobby_Attribute* OutAttribute;

	EOS_LobbyDetails_CopyMemberAttributeByKey(Handle, &Options, &OutAttribute);
	return 0.0;
} 

func double EpicGames_LobbyDetails_CopyMemberInfo()
{
	EOS_HLobbyDetails Handle = 0;
	EOS_LobbyDetails_CopyMemberInfoOptions Options;
	EOS_LobbyDetails_MemberInfo* OutLobbyDetailsMemberInfo;

	EOS_LobbyDetails_CopyMemberInfo(Handle, &Options, &OutLobbyDetailsMemberInfo);
	return 0.0;
} 

func double EpicGames_LobbyDetails_GetAttributeCount()
{
	EOS_HLobbyDetails Handle = 0;
	EOS_LobbyDetails_GetAttributeCountOptions Options = {0};

	return EOS_LobbyDetails_GetAttributeCount(Handle,&Options);
} 

func char* EpicGames_LobbyDetails_GetLobbyOwner()
{
	EOS_HLobbyDetails Handle = 0;
	EOS_LobbyDetails_GetLobbyOwnerOptions Options = { 0 };
	EOS_ProductUserId p = EOS_LobbyDetails_GetLobbyOwner(Handle,&Options);

	return productID_toString(p);
} 

func double EpicGames_LobbyDetails_GetMemberAttributeCount()
{
	EOS_HLobbyDetails Handle = 0;
	EOS_LobbyDetails_GetMemberAttributeCountOptions Options = { 0 };

	return EOS_LobbyDetails_GetMemberAttributeCount(Handle,&Options);
} 

func char* EpicGames_LobbyDetails_GetMemberByIndex()
{
	EOS_HLobbyDetails Handle = 0;
	EOS_LobbyDetails_GetMemberByIndexOptions Options = {0};

	EOS_ProductUserId p = EOS_LobbyDetails_GetMemberByIndex(Handle,&Options);
	return productID_toString(p);
} 

func double EpicGames_LobbyDetails_GetMemberCount()
{
	EOS_HLobbyDetails Handle = 0;
	EOS_LobbyDetails_GetMemberCountOptions Options = {0};
	return EOS_LobbyDetails_GetMemberCount(Handle,&Options);
} 

func double EpicGames_LobbyDetails_Info_Release()
{
	EOS_LobbyDetails_Info LobbyDetailsInfo = { 0 };
	EOS_LobbyDetails_Info_Release(&LobbyDetailsInfo);

	return 0.0;
}

func double EpicGames_LobbyDetails_MemberInfo_Release()
{
	EOS_LobbyDetails_MemberInfo LobbyDetailsMemberInfo = {0};

	EOS_LobbyDetails_MemberInfo_Release(&LobbyDetailsMemberInfo);

	return 0.0;
} 

func double EpicGames_LobbyDetails_Release()
{
	EOS_HLobbyDetails LobbyHandle = 0;

	EOS_LobbyDetails_Release(LobbyHandle);

	return 0.0;
} 

func double EpicGames_LobbyModification_AddAttribute()
{
	EOS_HLobbyModification Handle = 0; 
	EOS_LobbyModification_AddAttributeOptions Options = {0};
	EOS_LobbyModification_AddAttribute(Handle,&Options);

	return 0.0;
} 

func double EpicGames_LobbyModification_AddMemberAttribute()
{
	EOS_HLobbyModification Handle = 0;
	EOS_LobbyModification_AddMemberAttributeOptions Options = {0};
	EOS_LobbyModification_AddMemberAttribute(Handle,&Options);

	return 0.0;
} 

func double EpicGames_LobbyModification_Release()
{
	EOS_HLobbyModification LobbyModificationHandle = 0;

	EOS_LobbyModification_Release(LobbyModificationHandle);

	return 0.0;
} 

func double EpicGames_LobbyModification_RemoveAttribute()
{
	EOS_HLobbyModification Handle = 0;
	EOS_LobbyModification_RemoveAttributeOptions Options = {0};

	EOS_LobbyModification_RemoveAttribute(Handle,&Options);

	return 0.0;
} 

func double EpicGames_LobbyModification_RemoveMemberAttribute()
{
	EOS_HLobbyModification Handle = 0;
	EOS_LobbyModification_RemoveMemberAttributeOptions Options = {0};

	EOS_LobbyModification_RemoveMemberAttribute(Handle, &Options);

	return 0.0;
} 

func double EpicGames_LobbyModification_SetAllowedPlatformIds()
{
	EOS_HLobbyModification Handle = 0;
	EOS_LobbyModification_SetAllowedPlatformIdsOptions* Options = {0};

	EOS_LobbyModification_SetAllowedPlatformIds(Handle, Options);

	return 0.0;
} 

func double EpicGames_LobbyModification_SetBucketId()
{
	EOS_HLobbyModification Handle = 0; 
	EOS_LobbyModification_SetBucketIdOptions Options = { 0 };
	EOS_LobbyModification_SetBucketId(Handle,&Options);

	return 0.0;
} 

func double EpicGames_LobbyModification_SetInvitesAllowed()
{
	EOS_HLobbyModification Handle = 0; 
	EOS_LobbyModification_SetInvitesAllowedOptions Options = {0};
	EOS_LobbyModification_SetInvitesAllowed(Handle,&Options);

	return 0.0;
} 

func double EpicGames_LobbyModification_SetMaxMembers()
{
	EOS_HLobbyModification Handle = 0; 
	EOS_LobbyModification_SetMaxMembersOptions Options = { 0 };
	
	EOS_LobbyModification_SetMaxMembers(Handle, &Options);
	return 0.0;
} 

func double EpicGames_LobbyModification_SetPermissionLevel()
{
	EOS_HLobbyModification Handle = 0; 
	EOS_LobbyModification_SetPermissionLevelOptions Options = {0};

	EOS_LobbyModification_SetPermissionLevel(Handle,&Options);

	return 0.0;
} 

func double EpicGames_LobbySearch_CopySearchResultByIndex()
{
	EOS_HLobbySearch Handle = 0;
	const EOS_LobbySearch_CopySearchResultByIndexOptions Options = {0};
	EOS_HLobbyDetails OutLobbyDetailsHandle = 0;

	EOS_LobbySearch_CopySearchResultByIndex(Handle,&Options, &OutLobbyDetailsHandle);

	return 0.0;
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

func double EpicGames_LobbySearch_Find()
{
	EOS_HLobbySearch Handle = 0;
	EOS_LobbySearch_FindOptions Options = { 0 };
	
	callback* mcallback = getCallbackData();

	EOS_LobbySearch_Find(Handle,&Options,mcallback, LobbySearch_FindCallback);

	return mcallback->identifier;
} 

func double EpicGames_LobbySearch_GetSearchResultCount()
{
	EOS_HLobbySearch Handle = 0;
	EOS_LobbySearch_GetSearchResultCountOptions Options = { 0 };

	return EOS_LobbySearch_GetSearchResultCount(Handle,&Options);
} 

func double EpicGames_LobbySearch_Release()
{
	EOS_HLobbySearch LobbySearchHandle = 0;
	EOS_LobbySearch_Release(LobbySearchHandle);

	return 0.0;
} 

func double EpicGames_LobbySearch_RemoveParameter()
{
	EOS_HLobbySearch Handle = 0;
	EOS_LobbySearch_RemoveParameterOptions Options = {0};

	EOS_LobbySearch_RemoveParameter(Handle, &Options);
	return 0.0;
} 

func double EpicGames_LobbySearch_SetLobbyId()
{
	EOS_HLobbySearch Handle = 0;
	EOS_LobbySearch_SetLobbyIdOptions Options = {0};

	EOS_LobbySearch_SetLobbyId(Handle,&Options);

	return 0.0;
} 

func double EpicGames_LobbySearch_SetMaxResults()
{
	EOS_HLobbySearch Handle = 0;
	EOS_LobbySearch_SetMaxResultsOptions Options = { 0 };

	EOS_LobbySearch_SetMaxResults(Handle, &Options);

	return 0.0;
} 

func double EpicGames_LobbySearch_SetParameter()
{
	EOS_HLobbySearch Handle = 0;
	EOS_LobbySearch_SetParameterOptions Options = { 0 };

	EOS_LobbySearch_SetParameter(Handle, &Options);

	return 0.0;
} 

func double EpicGames_LobbySearch_SetTargetUserId()
{
	EOS_HLobbySearch Handle = 0;
	EOS_LobbySearch_SetTargetUserIdOptions Options = { 0 };

	EOS_LobbySearch_SetTargetUserId(Handle, &Options);

	return 0.0;
} 


