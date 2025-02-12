
//Sessions Interface
//Interface to handle session - based matchmaking


//Functions
//EOS_ActiveSession_CopyInfo
//EOS_ActiveSession_GetRegisteredPlayerByIndex
//EOS_ActiveSession_GetRegisteredPlayerCount
//EOS_ActiveSession_Info_Release
//EOS_ActiveSession_Release
//EOS_SessionDetails_Attribute_Release
//EOS_SessionDetails_CopyInfo
//EOS_SessionDetails_CopySessionAttributeByIndex
//EOS_SessionDetails_CopySessionAttributeByKey
//EOS_SessionDetails_GetSessionAttributeCount
//EOS_SessionDetails_Info_Release
//EOS_SessionDetails_Release
//EOS_SessionModification_AddAttribute
//EOS_SessionModification_Release
//EOS_SessionModification_RemoveAttribute
//EOS_SessionModification_SetAllowedPlatformIds
//EOS_SessionModification_SetBucketId
//EOS_SessionModification_SetHostAddress
//EOS_SessionModification_SetInvitesAllowed
//EOS_SessionModification_SetJoinInProgressAllowed
//EOS_SessionModification_SetMaxPlayers
//EOS_SessionModification_SetPermissionLevel
//EOS_Sessions_AddNotifyJoinSessionAccepted
//EOS_Sessions_AddNotifyLeaveSessionRequested
//EOS_Sessions_AddNotifySendSessionNativeInviteRequested
//EOS_Sessions_AddNotifySessionInviteAccepted
//EOS_Sessions_AddNotifySessionInviteReceived
//EOS_Sessions_AddNotifySessionInviteRejected
//EOS_Sessions_CopyActiveSessionHandle
//EOS_Sessions_CopySessionHandleByInviteId
//EOS_Sessions_CopySessionHandleByUiEventId
//EOS_Sessions_CopySessionHandleForPresence
//EOS_Sessions_CreateSessionModification
//EOS_Sessions_CreateSessionSearch
//EOS_Sessions_DestroySession
//EOS_Sessions_DumpSessionState
//EOS_Sessions_EndSession
//EOS_Sessions_GetInviteCount
//EOS_Sessions_GetInviteIdByIndex
//EOS_Sessions_IsUserInSession
//EOS_Sessions_JoinSession
//EOS_Sessions_QueryInvites
//EOS_Sessions_RegisterPlayers
//EOS_Sessions_RejectInvite
//EOS_Sessions_RemoveNotifyJoinSessionAccepted
//EOS_Sessions_RemoveNotifyLeaveSessionRequested
//EOS_Sessions_RemoveNotifySendSessionNativeInviteRequested
//EOS_Sessions_RemoveNotifySessionInviteAccepted
//EOS_Sessions_RemoveNotifySessionInviteReceived
//EOS_Sessions_RemoveNotifySessionInviteRejected
//EOS_Sessions_SendInvite
//EOS_Sessions_StartSession
//EOS_Sessions_UnregisterPlayers
//EOS_Sessions_UpdateSession
//EOS_Sessions_UpdateSessionModification
//EOS_SessionSearch_CopySearchResultByIndex
//EOS_SessionSearch_Find
//EOS_SessionSearch_GetSearchResultCount
//EOS_SessionSearch_Release
//EOS_SessionSearch_RemoveParameter
//EOS_SessionSearch_SetMaxResults
//EOS_SessionSearch_SetParameter
//EOS_SessionSearch_SetSessionId
//EOS_SessionSearch_SetTargetUserId
//EOS_SessionSearch_SetTargetUserIdOptions

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include "eos_sessions.h"

EOS_HSessions HSessions; 
double EpicGames_Sessions_Init()
{
	HSessions = EOS_Platform_GetSessionsInterface(PlatformHandle);
	return 0.0;
}

double EpicGames_ActiveSession_CopyInfo() 
{
	EOS_HActiveSession HActiveSession = 0;

	EOS_ActiveSession_CopyInfoOptions Options = {0};
	Options.ApiVersion = EOS_ACTIVESESSION_COPYINFO_API_LATEST;
	EOS_ActiveSession_Info* OutActiveSessionInfo;
	EOS_ActiveSession_CopyInfo(HActiveSession,&Options, &OutActiveSessionInfo);

	OutActiveSessionInfo->ApiVersion;
	OutActiveSessionInfo->LocalUserId;
	OutActiveSessionInfo->SessionDetails;
	OutActiveSessionInfo->SessionName;
	OutActiveSessionInfo->State;

	EOS_ActiveSession_Info_Release(OutActiveSessionInfo);

	return 0.0;
}

double EpicGames_ActiveSession_GetRegisteredPlayerByIndex() 
{ 
	EOS_HActiveSession Handle = 0;
	EOS_ActiveSession_GetRegisteredPlayerByIndexOptions Options = {};
	EOS_ProductUserId ProductUserId = EOS_ActiveSession_GetRegisteredPlayerByIndex(Handle, &Options);
	
	return 0.0; 
} 

double EpicGames_ActiveSession_GetRegisteredPlayerCount() 
{ 
	EOS_HActiveSession Handle = 0;
	EOS_ActiveSession_GetRegisteredPlayerCountOptions* Options = {0};
	uint32_t count = EOS_ActiveSession_GetRegisteredPlayerCount(Handle,Options);

	return count;
}


double EpicGames_ActiveSession_Release() 
{ 
	EOS_HActiveSession ActiveSessionHandle = 0;
	EOS_ActiveSession_Release(ActiveSessionHandle);
	return 0.0; 
}



double EpicGames_SessionDetails_CopyInfo() 
{ 
	EOS_HSessionDetails Handle = 0;
	EOS_SessionDetails_CopyInfoOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONDETAILS_COPYINFO_API_LATEST;
	EOS_SessionDetails_Info* OutSessionInfo;

	EOS_SessionDetails_CopyInfo(Handle, &Options, &OutSessionInfo);
	OutSessionInfo->ApiVersion;
	OutSessionInfo->HostAddress;
	OutSessionInfo->NumOpenPublicConnections;
	OutSessionInfo->OwnerServerClientId;
	OutSessionInfo->OwnerUserId;
	OutSessionInfo->SessionId;
	OutSessionInfo->Settings;

	EOS_SessionDetails_Info_Release(OutSessionInfo);

	return 0.0; 
} 

double EpicGames_SessionDetails_CopySessionAttributeByIndex() 
{ 
	//EOS_SessionDetails_Attribute_Release()
	return 0.0; 
} 
double EpicGames_SessionDetails_CopySessionAttributeByKey() 
{ 
	//EOS_SessionDetails_Attribute_Release()
	return 0.0; 
}

double EpicGames_SessionDetails_GetSessionAttributeCount() 
{ 
	//EOS_SessionDetails_Attribute_Release()
	return 0.0; 
}


double EpicGames_SessionDetails_Release() //???????????
{ 
	return 0.0; 
} 

double EpicGames_SessionModification_AddAttribute() 
{ 
	EOS_HSessionModification Handle;
	EOS_SessionModification_AddAttributeOptions Options = {0};
	Options.AdvertisementType;
	Options.ApiVersion;
	Options.SessionAttribute;
	EOS_SessionModification_AddAttribute(Handle, &Options);
	return 0.0; 
} 

double EpicGames_SessionModification_Release() 
{ 
	return 0.0; 
}

double EpicGames_SessionModification_RemoveAttribute() 
{ 
	EOS_HSessionModification Handle = 0;
	EOS_SessionModification_RemoveAttributeOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONMODIFICATION_REMOVEATTRIBUTE_API_LATEST;
	Options.Key;
	EOS_SessionModification_RemoveAttribute(Handle,&Options);
	return 0.0; 
} 

double EpicGames_SessionModification_SetAllowedPlatformIds() 
{ 
	EOS_HSessionModification Handle = 0;
	EOS_SessionModification_SetAllowedPlatformIdsOptions Options = {0};
	Options.AllowedPlatformIds;
	Options.AllowedPlatformIdsCount;
	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETALLOWEDPLATFORMIDS_API_LATEST;
	EOS_SessionModification_SetAllowedPlatformIds(Handle, &Options);
	return 0.0; 
}

double EpicGames_SessionModification_SetBucketId() 
{ 
	EOS_HSessionModification Handle;
	EOS_SessionModification_SetBucketIdOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETBUCKETID_API_LATEST;
	Options.BucketId;
	EOS_SessionModification_SetBucketId(Handle, &Options);

	return 0.0; 
} 

double EpicGames_SessionModification_SetHostAddress() 
{
	EOS_HSessionModification Handle = 0;
	EOS_SessionModification_SetHostAddressOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETHOSTADDRESS_API_LATEST;
	Options.HostAddress;
	EOS_SessionModification_SetHostAddress(Handle, &Options);

	return 0.0; 
}

double EpicGames_SessionModification_SetInvitesAllowed() 
{ 
	EOS_HSessionModification Handle;
	EOS_SessionModification_SetInvitesAllowedOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETINVITESALLOWED_API_LATEST;
	Options.bInvitesAllowed;
	EOS_SessionModification_SetInvitesAllowed(Handle,&Options);
	return 0.0; 
} 

double EpicGames_SessionModification_SetJoinInProgressAllowed() 
{ 
	EOS_HSessionModification Handle = 0;
	EOS_SessionModification_SetJoinInProgressAllowedOptions Options = { 0 };
	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETJOININPROGRESSALLOWED_API_LATEST;
	Options.bAllowJoinInProgress;
	EOS_SessionModification_SetJoinInProgressAllowed(Handle,&Options);
	return 0.0; 
}

double EpicGames_SessionModification_SetMaxPlayers() 
{ 
	EOS_HSessionModification Handle = 0;
	EOS_SessionModification_SetMaxPlayersOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETMAXPLAYERS_API_LATEST;
	Options.MaxPlayers;
	EOS_SessionModification_SetMaxPlayers(Handle,&Options);

	return 0.0; 
}

double EpicGames_SessionModification_SetPermissionLevel() 
{ 
	EOS_HSessionModification Handle = 0;
	EOS_SessionModification_SetPermissionLevelOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETPERMISSIONLEVEL_API_LATEST;
	Options.PermissionLevel;
	EOS_SessionModification_SetPermissionLevel(Handle,&Options);
	return 0.0; 
}

void EOS_CALL Sessions_OnJoinSessionAcceptedCallback(const EOS_Sessions_JoinSessionAcceptedCallbackInfo* Data)
{
}

double EpicGames_Sessions_AddNotifyJoinSessionAccepted() 
{
	EOS_Sessions_AddNotifyJoinSessionAcceptedOptions Options = {0};
	
	callback* mcallback = getCallbackData();

	EOS_Sessions_AddNotifyJoinSessionAccepted(HSessions,&Options, mcallback,Sessions_OnJoinSessionAcceptedCallback);
	return mcallback->identifier;
} 

void EOS_CALL Sessions_LeaveSessionRequestedCallbackInfo(const EOS_Sessions_LeaveSessionRequestedCallbackInfo* Data)
{
}

double EpicGames_Sessions_AddNotifyLeaveSessionRequested() 
{ 
	EOS_Sessions_AddNotifyLeaveSessionRequestedOptions Options = {};
	Options.ApiVersion = EOS_SESSIONS_ADDNOTIFYLEAVESESSIONREQUESTED_API_LATEST;
	
	callback* mcallback = getCallbackData();

	EOS_Sessions_AddNotifyLeaveSessionRequested(HSessions,&Options,mcallback, Sessions_LeaveSessionRequestedCallbackInfo);

	return mcallback->identifier;
} 

void EOS_CALL Sessions_OnSendSessionNativeInviteRequestedCallback(const EOS_Sessions_SendSessionNativeInviteRequestedCallbackInfo* Data)
{
}

double EpicGames_Sessions_AddNotifySendSessionNativeInviteRequested() 
{ 
	const EOS_Sessions_AddNotifySendSessionNativeInviteRequestedOptions* Options;
	Options->ApiVersion = EOS_SESSIONS_ADDNOTIFYSENDSESSIONNATIVEINVITEREQUESTED_API_LATEST;
	
	callback* mcallback = getCallbackData();

	EOS_Sessions_AddNotifySendSessionNativeInviteRequested(HSessions,Options, mcallback,Sessions_OnSendSessionNativeInviteRequestedCallback);

	return mcallback->identifier;
}

double EpicGames_Sessions_AddNotifySessionInviteAccepted() 
{ 
	EOS_HSessions Handle;
	const EOS_Sessions_AddNotifySessionInviteAcceptedOptions* Options;
	void* ClientData;
	const EOS_Sessions_OnSessionInviteAcceptedCallback NotificationFn;
	EOS_Sessions_AddNotifySessionInviteAccepted();

	return 0.0; 
} 

double EpicGames_Sessions_AddNotifySessionInviteReceived() { return 0.0; } 
double EpicGames_Sessions_AddNotifySessionInviteRejected() { return 0.0; } 
double EpicGames_Sessions_CopyActiveSessionHandle() { return 0.0; } 
double EpicGames_Sessions_CopySessionHandleByInviteId() { return 0.0; } 
double EpicGames_Sessions_CopySessionHandleByUiEventId() { return 0.0; } 
double EpicGames_Sessions_CopySessionHandleForPresence() { return 0.0; } 
double EpicGames_Sessions_CreateSessionModification() { return 0.0; } 
double EpicGames_Sessions_CreateSessionSearch() { return 0.0; } 
double EpicGames_Sessions_DestroySession() { return 0.0; } 
double EpicGames_Sessions_DumpSessionState() { return 0.0; } 
double EpicGames_Sessions_EndSession() { return 0.0; } 
double EpicGames_Sessions_GetInviteCount() { return 0.0; } 
double EpicGames_Sessions_GetInviteIdByIndex() { return 0.0; } 
double EpicGames_Sessions_IsUserInSession() { return 0.0; } 
double EpicGames_Sessions_JoinSession() { return 0.0; } 
double EpicGames_Sessions_QueryInvites() { return 0.0; } 
double EpicGames_Sessions_RegisterPlayers() { return 0.0; } 
double EpicGames_Sessions_RejectInvite() { return 0.0; } 
double EpicGames_Sessions_RemoveNotifyJoinSessionAccepted() { return 0.0; } 
double EpicGames_Sessions_RemoveNotifyLeaveSessionRequested() { return 0.0; } 
double EpicGames_Sessions_RemoveNotifySendSessionNativeInviteRequested() { return 0.0; } 
double EpicGames_Sessions_RemoveNotifySessionInviteAccepted() { return 0.0; } 
double EpicGames_Sessions_RemoveNotifySessionInviteReceived() { return 0.0; } 
double EpicGames_Sessions_RemoveNotifySessionInviteRejected() { return 0.0; } 
double EpicGames_Sessions_SendInvite() { return 0.0; } 
double EpicGames_Sessions_StartSession() { return 0.0; } 
double EpicGames_Sessions_UnregisterPlayers() { return 0.0; } 
double EpicGames_Sessions_UpdateSession() { return 0.0; } 
double EpicGames_Sessions_UpdateSessionModification() { return 0.0; } 
double EpicGames_SessionSearch_CopySearchResultByIndex() { return 0.0; } 
double EpicGames_SessionSearch_Find() { return 0.0; } 
double EpicGames_SessionSearch_GetSearchResultCount() { return 0.0; } 
double EpicGames_SessionSearch_Release() { return 0.0; } 
double EpicGames_SessionSearch_RemoveParameter() { return 0.0; } 
double EpicGames_SessionSearch_SetMaxResults() { return 0.0; } 
double EpicGames_SessionSearch_SetParameter() { return 0.0; } 
double EpicGames_SessionSearch_SetSessionId() { return 0.0; } 
double EpicGames_SessionSearch_SetTargetUserId() { return 0.0; } 
double EpicGames_SessionSearch_SetTargetUserIdOptions() { return 0.0; } 
