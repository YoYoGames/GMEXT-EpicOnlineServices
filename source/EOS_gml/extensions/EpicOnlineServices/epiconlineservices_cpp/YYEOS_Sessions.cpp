
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

double EpicGames_ActiveSession_CopyInfo(char* SessionName)
{
	EOS_Sessions_CopyActiveSessionHandleOptions HOptions = {0};
	HOptions.ApiVersion = EOS_SESSIONS_COPYACTIVESESSIONHANDLE_API_LATEST;
	HOptions.SessionName = SessionName;
	EOS_HActiveSession HActiveSession = 0;
	EOS_Sessions_CopyActiveSessionHandle(HSessions, &HOptions, &HActiveSession);

	EOS_ActiveSession_CopyInfoOptions Options = {0};
	Options.ApiVersion = EOS_ACTIVESESSION_COPYINFO_API_LATEST;
	EOS_ActiveSession_Info* OutActiveSessionInfo;
	EOS_ActiveSession_CopyInfo(HActiveSession,&Options, &OutActiveSessionInfo);

	OutActiveSessionInfo->ApiVersion = EOS_ACTIVESESSION_INFO_API_LATEST;
	OutActiveSessionInfo->LocalUserId;
	OutActiveSessionInfo->SessionDetails;
	OutActiveSessionInfo->SessionName;
	OutActiveSessionInfo->State;

	EOS_ActiveSession_Info_Release(OutActiveSessionInfo);

	return 0.0;
}

char* EpicGames_ActiveSession_GetRegisteredPlayerByIndex(char* SessionName)
{ 
	EOS_Sessions_CopyActiveSessionHandleOptions HOptions = {0};
	HOptions.ApiVersion = EOS_SESSIONS_COPYACTIVESESSIONHANDLE_API_LATEST;
	HOptions.SessionName = SessionName;
	EOS_HActiveSession HActiveSession = 0;
	EOS_Sessions_CopyActiveSessionHandle(HSessions, &HOptions, &HActiveSession);

	EOS_ActiveSession_GetRegisteredPlayerByIndexOptions Options = {0};
	EOS_ProductUserId ProductUserId = EOS_ActiveSession_GetRegisteredPlayerByIndex(HActiveSession, &Options);
	
	return productID_toString(ProductUserId);
} 

double EpicGames_ActiveSession_GetRegisteredPlayerCount(char* SessionName)
{ 
	EOS_Sessions_CopyActiveSessionHandleOptions HOptions = {0};
	HOptions.ApiVersion = EOS_SESSIONS_COPYACTIVESESSIONHANDLE_API_LATEST;
	HOptions.SessionName = SessionName;
	EOS_HActiveSession HActiveSession = 0;

	EOS_Sessions_CopyActiveSessionHandle(HSessions, &HOptions, &HActiveSession);

	EOS_ActiveSession_GetRegisteredPlayerCountOptions* Options = {0};
	uint32_t count = EOS_ActiveSession_GetRegisteredPlayerCount(HActiveSession,Options);

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

	EOS_EResult result = EOS_SessionDetails_CopyInfo(Handle, &Options, &OutSessionInfo);
	
	if (EOS_EResult::EOS_Success == result)
	{
		//TODO
		OutSessionInfo->ApiVersion;
		OutSessionInfo->HostAddress;
		OutSessionInfo->NumOpenPublicConnections;
		OutSessionInfo->OwnerServerClientId;
		OutSessionInfo->OwnerUserId;
		OutSessionInfo->SessionId;
		OutSessionInfo->Settings;

		EOS_SessionDetails_Info_Release(OutSessionInfo);
	}
	else
	{
	}

	return 0.0; 
} 

double EpicGames_SessionDetails_CopySessionAttributeByIndex(double AttrIndex)
{ 
	EOS_HSessionDetails Handle = 0;
	EOS_SessionDetails_CopySessionAttributeByIndexOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONDETAILS_COPYSESSIONATTRIBUTEBYINDEX_API_LATEST;
	Options.AttrIndex = AttrIndex;
	EOS_SessionDetails_Attribute* OutSessionAttribute;

	EOS_SessionDetails_CopySessionAttributeByIndex(Handle,&Options, &OutSessionAttribute);

	//TODO
	OutSessionAttribute->AdvertisementType;
	OutSessionAttribute->Data->Key;
	OutSessionAttribute->Data->Value;
	OutSessionAttribute->Data->ValueType;

	return 0.0;
} 
double EpicGames_SessionDetails_CopySessionAttributeByKey(char* AttrKey)
{ 
	EOS_HSessionDetails Handle = 0; 
	EOS_SessionDetails_CopySessionAttributeByKeyOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONDETAILS_COPYSESSIONATTRIBUTEBYKEY_API_LATEST;
	Options.AttrKey = AttrKey;
	EOS_SessionDetails_Attribute* OutSessionAttribute;

	EOS_SessionDetails_CopySessionAttributeByKey(Handle,&Options,&OutSessionAttribute);
	
	//TODO
	OutSessionAttribute->AdvertisementType;
	OutSessionAttribute->Data->Key;
	OutSessionAttribute->Data->Value;
	OutSessionAttribute->Data->ValueType;

	return 0.0; 
}

double EpicGames_SessionDetails_GetSessionAttributeCount() 
{ 
	EOS_HSessionDetails Handle = 0;
	EOS_SessionDetails_GetSessionAttributeCountOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONDETAILS_GETSESSIONATTRIBUTECOUNT_API_LATEST;

	return EOS_SessionDetails_GetSessionAttributeCount(Handle,&Options);
}


double EpicGames_SessionDetails_Release()
{ 
	EOS_HSessionDetails SessionHandle = 0;

	EOS_SessionDetails_Release(SessionHandle);

	return 0.0; 
} 

double EpicGames_SessionModification_AddAttribute(double AdvertisementType, double SessionAttribute)
{ 
	EOS_HSessionModification Handle = 0;
	EOS_SessionModification_AddAttributeOptions Options = {0};
	Options.AdvertisementType = (EOS_ESessionAttributeAdvertisementType) AdvertisementType;
	Options.ApiVersion = EOS_SESSIONMODIFICATION_ADDATTRIBUTE_API_LATEST;
	//Options.SessionAttribute = SessionAttribute;//TODO
	EOS_EResult result = EOS_SessionModification_AddAttribute(Handle, &Options);

	return (double)result;
}

double EpicGames_SessionModification_Release() 
{ 
	EOS_HSessionModification SessionModificationHandle = 0;

	EOS_SessionModification_Release(SessionModificationHandle);

	return 0.0; 
}

double EpicGames_SessionModification_RemoveAttribute(char* Key)
{ 
	EOS_HSessionModification Handle = 0;
	EOS_SessionModification_RemoveAttributeOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONMODIFICATION_REMOVEATTRIBUTE_API_LATEST;
	Options.Key = Key;
	return (double) EOS_SessionModification_RemoveAttribute(Handle,&Options);
	
} 

double EpicGames_SessionModification_SetAllowedPlatformIds()
{ 
	EOS_HSessionModification Handle = 0;
	EOS_SessionModification_SetAllowedPlatformIdsOptions Options = {0};
	//TODO
	Options.AllowedPlatformIds;
	Options.AllowedPlatformIdsCount;
	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETALLOWEDPLATFORMIDS_API_LATEST;
	return (double)EOS_SessionModification_SetAllowedPlatformIds(Handle, &Options);
}

double EpicGames_SessionModification_SetBucketId(char* BucketId)
{ 
	EOS_HSessionModification Handle = 0;
	EOS_SessionModification_SetBucketIdOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETBUCKETID_API_LATEST;
	Options.BucketId = BucketId;
	return (double)EOS_SessionModification_SetBucketId(Handle, &Options);
} 

double EpicGames_SessionModification_SetHostAddress(char* HostAddress)
{
	EOS_HSessionModification Handle = 0;
	EOS_SessionModification_SetHostAddressOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETHOSTADDRESS_API_LATEST;
	Options.HostAddress = HostAddress;
	return (double)EOS_SessionModification_SetHostAddress(Handle, &Options);
}

double EpicGames_SessionModification_SetInvitesAllowed(double bInvitesAllowed)
{ 
	EOS_HSessionModification Handle = 0;
	EOS_SessionModification_SetInvitesAllowedOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETINVITESALLOWED_API_LATEST;
	Options.bInvitesAllowed = bInvitesAllowed > 0.5;
	return (double)EOS_SessionModification_SetInvitesAllowed(Handle,&Options);
} 

double EpicGames_SessionModification_SetJoinInProgressAllowed(double bAllowJoinInProgress)
{ 
	EOS_HSessionModification Handle = 0;
	EOS_SessionModification_SetJoinInProgressAllowedOptions Options = { 0 };
	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETJOININPROGRESSALLOWED_API_LATEST;
	Options.bAllowJoinInProgress = bAllowJoinInProgress>0.5;
	return (double)EOS_SessionModification_SetJoinInProgressAllowed(Handle,&Options);
}

double EpicGames_SessionModification_SetMaxPlayers(double MaxPlayers)
{ 
	EOS_HSessionModification Handle = 0;
	EOS_SessionModification_SetMaxPlayersOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETMAXPLAYERS_API_LATEST;
	Options.MaxPlayers = (int) MaxPlayers;
	return (double)EOS_SessionModification_SetMaxPlayers(Handle,&Options);
}

double EpicGames_SessionModification_SetPermissionLevel(double PermissionLevel)
{ 
	EOS_HSessionModification Handle = 0;
	EOS_SessionModification_SetPermissionLevelOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONMODIFICATION_SETPERMISSIONLEVEL_API_LATEST;
	Options.PermissionLevel = (EOS_EOnlineSessionPermissionLevel) PermissionLevel;
	return (double)EOS_SessionModification_SetPermissionLevel(Handle,&Options);
}

void EOS_CALL Sessions_OnJoinSessionAcceptedCallback(const EOS_Sessions_JoinSessionAcceptedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Sessions_AddNotifyJoinSessionAccepted");
	//DsMapAddDouble(map, "status", (double)Data->ResultCode);
	//DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "account_id", productID_toString(Data->LocalUserId));//TODO: ????account_id????
	DsMapAddDouble(map, "ui_event_id", (double) Data->UiEventId);
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_Sessions_AddNotifyJoinSessionAccepted() 
{
	EOS_Sessions_AddNotifyJoinSessionAcceptedOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_ADDNOTIFYJOINSESSIONACCEPTED_API_LATEST;
	
	callback* mcallback = getCallbackData();

	EOS_Sessions_AddNotifyJoinSessionAccepted(HSessions,&Options, mcallback,Sessions_OnJoinSessionAcceptedCallback);
	return mcallback->identifier;
} 

void EOS_CALL Sessions_LeaveSessionRequestedCallbackInfo(const EOS_Sessions_LeaveSessionRequestedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Sessions_AddNotifyLeaveSessionRequested");
	//DsMapAddDouble(map, "status", (double)Data->ResultCode);
	//DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	//DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "account_id", productID_toString(Data->LocalUserId));//TODO: ????account_id????
	DsMapAddString(map, "session_name", Data->SessionName);
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_Sessions_AddNotifyLeaveSessionRequested() 
{ 
	EOS_Sessions_AddNotifyLeaveSessionRequestedOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_ADDNOTIFYLEAVESESSIONREQUESTED_API_LATEST;

	//callback* mcallback = getCallbackData();

	return EOS_Sessions_AddNotifyLeaveSessionRequested(HSessions,&Options,NULL/*mcallback*/, Sessions_LeaveSessionRequestedCallbackInfo);

	/*return mcallback->identifier;*/
} 

void EOS_CALL Sessions_OnSendSessionNativeInviteRequestedCallback(const EOS_Sessions_SendSessionNativeInviteRequestedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Sessions_AddNotifySendSessionNativeInviteRequested");
	//DsMapAddDouble(map, "status", (double)Data->ResultCode);
	//DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	//DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "account_id", productID_toString(Data->LocalUserId));//TODO: ????account_id????
	DsMapAddString(map, "target_native_account_type", Data->TargetNativeAccountType);
	DsMapAddString(map, "target_user_native_account_id", Data->TargetUserNativeAccountId);
	DsMapAddString(map, "session_id", Data->SessionId);
	DsMapAddDouble(map, "ui_event_id", (double)Data->UiEventId);
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_Sessions_AddNotifySendSessionNativeInviteRequested() 
{ 
	EOS_Sessions_AddNotifySendSessionNativeInviteRequestedOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_ADDNOTIFYSENDSESSIONNATIVEINVITEREQUESTED_API_LATEST;
	
	//callback* mcallback = getCallbackData();

	return EOS_Sessions_AddNotifySendSessionNativeInviteRequested(HSessions,&Options, NULL/*mcallback*/,Sessions_OnSendSessionNativeInviteRequestedCallback);

	//return mcallback->identifier;
}

void EOS_CALL Sessions_SessionInviteAcceptedCallbackInfo(const EOS_Sessions_SessionInviteAcceptedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Sessions_AddNotifySessionInviteAccepted");
	//DsMapAddDouble(map, "status", (double)Data->ResultCode);
	//DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	//DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "account_id", productID_toString(Data->LocalUserId));//TODO: ????account_id????
	DsMapAddString(map, "invite_id", Data->InviteId);
	DsMapAddString(map, "session_id", Data->SessionId);
	DsMapAddString(map, "target_user_id", productID_toString(Data->TargetUserId));
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_Sessions_AddNotifySessionInviteAccepted() 
{ 
	EOS_Sessions_AddNotifySessionInviteAcceptedOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_ADDNOTIFYSESSIONINVITEACCEPTED_API_LATEST;

	//callback* mcallback = getCallbackData();
	return EOS_Sessions_AddNotifySessionInviteAccepted(HSessions,&Options, NULL/*mcallback*/, Sessions_SessionInviteAcceptedCallbackInfo);

	//return mcallback->identifier;
} 

void EOS_CALL Sessions_OnSessionInviteReceivedCallback(const EOS_Sessions_SessionInviteReceivedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Sessions_AddNotifySessionInviteReceived");
	//DsMapAddDouble(map, "status", (double)Data->ResultCode);
	//DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	//DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "invite_id", Data->InviteId);
	DsMapAddString(map, "target_user_id", productID_toString(Data->TargetUserId));
	DsMapAddString(map, "account_id", productID_toString(Data->LocalUserId));//TODO: ????account_id????
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_Sessions_AddNotifySessionInviteReceived() 
{ 
	EOS_Sessions_AddNotifySessionInviteReceivedOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_ADDNOTIFYSESSIONINVITERECEIVED_API_LATEST;
	//callback* mcallback = getCallbackData();
	
	return EOS_Sessions_AddNotifySessionInviteReceived(HSessions,&Options, NULL/*mcallback*/, Sessions_OnSessionInviteReceivedCallback);

	//return mcallback->identifier;
}

void EOS_CALL Sessions_OnSessionInviteRejectedCallback(const EOS_Sessions_SessionInviteRejectedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Sessions_AddNotifySessionInviteRejected");
	//DsMapAddDouble(map, "status", (double)Data->ResultCode);
	//DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	//DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "invite_id", Data->InviteId);
	DsMapAddString(map, "target_user_id", productID_toString(Data->TargetUserId));
	DsMapAddString(map, "session_id", Data->SessionId);
	DsMapAddString(map, "account_id", productID_toString(Data->LocalUserId));//TODO: ????account_id????
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_Sessions_AddNotifySessionInviteRejected() 
{ 
	EOS_Sessions_AddNotifySessionInviteRejectedOptions Options = {0};

	//callback* mcallback = getCallbackData();
	return EOS_Sessions_AddNotifySessionInviteRejected(HSessions,&Options,NULL/*mcallback*/, Sessions_OnSessionInviteRejectedCallback);

	//return mcallback->identifier;
} 

double EpicGames_Sessions_CopySessionHandleByInviteId(char* InviteId)
{
	EOS_Sessions_CopySessionHandleByInviteIdOptions Options = { 0 }; 
	Options.ApiVersion = EOS_SESSIONS_COPYSESSIONHANDLEBYINVITEID_API_LATEST;
	Options.InviteId = InviteId;

	EOS_HSessionDetails OutSessionHandle;
	double result = (double)EOS_Sessions_CopySessionHandleByInviteId(HSessions,&Options,&OutSessionHandle);

	return (double) result;
	
}

double EpicGames_Sessions_CopySessionHandleByUiEventId(double UiEventId)
{ 
	EOS_Sessions_CopySessionHandleByUiEventIdOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_COPYSESSIONHANDLEBYUIEVENTID_API_LATEST;
	Options.UiEventId = UiEventId;
	
	EOS_HSessionDetails OutSessionHandle;

	double result = (double) EOS_Sessions_CopySessionHandleByUiEventId(HSessions,&Options,&OutSessionHandle);

	return (double)result;
}

double EpicGames_Sessions_CopySessionHandleForPresence(char* local)
{ 
	EOS_Sessions_CopySessionHandleForPresenceOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_COPYSESSIONHANDLEFORPRESENCE_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local);

	EOS_HSessionDetails OutSessionHandle;

	double result = (double)EOS_Sessions_CopySessionHandleForPresence(HSessions,&Options, &OutSessionHandle);

	return (double)result;
} 

double EpicGames_Sessions_CreateSessionModification(char* SessionName,char* BucketId,double MaxPlayers,char* LocalUserId, double bPresenceEnabled,char* SessionId, double bSanctionsEnabled,const uint32_t* AllowedPlatformIds,double AllowedPlatformIdsCount)
{ //TODO
	EOS_Sessions_CreateSessionModificationOptions Options;
	Options.ApiVersion = EOS_SESSIONS_CREATESESSIONMODIFICATION_API_LATEST;
	Options.AllowedPlatformIds;
	Options.AllowedPlatformIdsCount;
	Options.bPresenceEnabled;
	Options.bSanctionsEnabled;
	Options.BucketId;
	Options.LocalUserId;
	Options.MaxPlayers;
	Options.SessionId;
	Options.SessionName;
	EOS_HSessionModification OutSessionModificationHandle;
 
	double result = (double) EOS_Sessions_CreateSessionModification(HSessions,&Options, &OutSessionModificationHandle);

	return (double)result;
}

double EpicGames_Sessions_CreateSessionSearch(double MaxSearchResults)
{ 
	EOS_Sessions_CreateSessionSearchOptions Options = { 0 };
	EOS_HSessionSearch OutSessionSearchHandle;
	Options.ApiVersion = EOS_SESSIONS_CREATESESSIONSEARCH_API_LATEST;
	Options.MaxSearchResults = (double) MaxSearchResults;
	double result = (double)EOS_Sessions_CreateSessionSearch(HSessions,&Options, &OutSessionSearchHandle);

	return result;
}

void EOS_CALL Sessions_OnDestroySessionCallback(const EOS_Sessions_DestroySessionCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Sessions_DestroySession");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_Sessions_DestroySession(char* SessionName)
{ 
	EOS_Sessions_DestroySessionOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_DESTROYSESSION_API_LATEST;
	Options.SessionName = SessionName;
	
	callback* mcallback = getCallbackData();

	EOS_Sessions_OnDestroySessionCallback CompletionDelegate;
	EOS_Sessions_DestroySession(HSessions,&Options, mcallback, Sessions_OnDestroySessionCallback);

	return mcallback->identifier;
} 

double EpicGames_Sessions_DumpSessionState(char* SessionName)
{ 
	EOS_Sessions_DumpSessionStateOptions Options{0};
	Options.ApiVersion = EOS_SESSIONS_DUMPSESSIONSTATE_API_LATEST;
	Options.SessionName = SessionName;
	return (double) EOS_Sessions_DumpSessionState(HSessions, &Options);
} 

void EOS_CALL Sessions_OnEndSessionCallback(const EOS_Sessions_EndSessionCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Sessions_EndSession");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_Sessions_EndSession(char* SessionName)
{ 
	EOS_Sessions_EndSessionOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_ENDSESSION_API_LATEST;
	Options.SessionName = SessionName;

	void* ClientData;
	callback* mcallback = getCallbackData();

	EOS_Sessions_EndSession(HSessions,&Options,mcallback, Sessions_OnEndSessionCallback);

	return mcallback->identifier;
} 

double EpicGames_Sessions_GetInviteCount(char* local) 
{ 
	EOS_Sessions_GetInviteCountOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_GETINVITECOUNT_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local);

	return EOS_Sessions_GetInviteCount(HSessions,&Options);
} 

double EpicGames_Sessions_GetInviteIdByIndex(char* local, double index)
{ 
	//TODO

	EOS_Sessions_GetInviteIdByIndexOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_GETINVITEIDBYINDEX_API_LATEST;
	Options.Index = (int)index;
	Options.LocalUserId = EOS_ProductUserId_FromString(local);

	//char* OutBuffer = "";
	//int32_t* InOutBufferLength = 0;

	//EOS_Sessions_GetInviteIdByIndex(HSessions,&Options,OutBuffer,InOutBufferLength);

	return 0.0; 
} 

double EpicGames_Sessions_IsUserInSession(char* SessionName, char* TargetUserId)
{
	EOS_Sessions_IsUserInSessionOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_ISUSERINSESSION_API_LATEST;
	Options.SessionName = SessionName;
	Options.TargetUserId = EOS_ProductUserId_FromString(TargetUserId);

	return (double) EOS_Sessions_IsUserInSession(HSessions, &Options);
} 

void EOS_CALL Sessions_OnJoinSessionCallback(const EOS_Sessions_JoinSessionCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Sessions_JoinSession");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_Sessions_JoinSession(double PresenceEnabled, char* LocalUserId, char* SessionName)
{ 
	EOS_Sessions_JoinSessionOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_JOINSESSION_API_LATEST;
	Options.bPresenceEnabled = PresenceEnabled;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.SessionHandle;//TODO
	Options.SessionName = SessionName;

	callback* mcallback = getCallbackData();

	EOS_Sessions_JoinSession(HSessions, &Options, mcallback, Sessions_OnJoinSessionCallback);

	return mcallback->identifier;
} 

void EOS_CALL Sessions_OnQueryInvitesCallback(const EOS_Sessions_QueryInvitesCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Sessions_QueryInvites");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "account_id", productID_toString(Data->LocalUserId));//TODO: ????account_id????
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_Sessions_QueryInvites(char* TargetUserId)
{ 
	EOS_Sessions_QueryInvitesOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_QUERYINVITES_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(TargetUserId);

	callback* mcallback = getCallbackData();
	
	EOS_Sessions_QueryInvites(HSessions,&Options, mcallback, Sessions_OnQueryInvitesCallback);

	return mcallback->identifier;
} 

void EOS_CALL Sessions_OnRegisterPlayersCallback(const EOS_Sessions_RegisterPlayersCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Sessions_RegisterPlayers");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "registered_players", (char*)productIds2ArrayStr(Data->RegisteredPlayers, Data->RegisteredPlayersCount));
	DsMapAddString(map, "sanctioned_players", (char*)productIds2ArrayStr(Data->SanctionedPlayers, Data->SanctionedPlayersCount));
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_Sessions_RegisterPlayers() 
{ 
	//TODO
	EOS_Sessions_RegisterPlayersOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_REGISTERPLAYERS_API_LATEST;
	Options.PlayersToRegister;
	Options.PlayersToRegisterCount;
	Options.SessionName;

	callback* mcallback = getCallbackData();

	EOS_Sessions_RegisterPlayers(HSessions,&Options, mcallback,Sessions_OnRegisterPlayersCallback);

	return mcallback->identifier;
} 


void EOS_CALL Sessions_OnRejectInvite(const EOS_Sessions_RejectInviteCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Sessions_RejectInvite");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_Sessions_RejectInvite(char* LocalUserId, char* InviteId)
{ 
	EOS_Sessions_RejectInviteOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_REJECTINVITE_API_LATEST;
	Options.InviteId = InviteId;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);

	callback* mcallback = getCallbackData();
	EOS_Sessions_RejectInvite(HSessions,&Options, mcallback,Sessions_OnRejectInvite);

	return mcallback->identifier;
} 

double EpicGames_Sessions_RemoveNotifyJoinSessionAccepted(double InId)
{ 
	EOS_NotificationId _InId = InId;

	EOS_Sessions_RemoveNotifyJoinSessionAccepted(HSessions, _InId);

	return 0.0; 
} 

double EpicGames_Sessions_RemoveNotifyLeaveSessionRequested(double InId)
{ 
	EOS_NotificationId _InId = InId;
	EOS_Sessions_RemoveNotifyLeaveSessionRequested(HSessions,_InId);
	return 0.0; 
}


double EpicGames_Sessions_RemoveNotifySendSessionNativeInviteRequested(double InId)
{ 
	EOS_NotificationId _InId = InId;
	EOS_Sessions_RemoveNotifySendSessionNativeInviteRequested(HSessions, _InId);
	return 0.0; 
} 

double EpicGames_Sessions_RemoveNotifySessionInviteAccepted(double InId)
{ 
	EOS_NotificationId _InId = InId;
	EOS_Sessions_RemoveNotifySessionInviteAccepted(HSessions, _InId);

	return 0.0; 
} 

double EpicGames_Sessions_RemoveNotifySessionInviteReceived(double InId)
{
	EOS_NotificationId _InId = InId;
	EOS_Sessions_RemoveNotifySessionInviteReceived(HSessions, _InId);

	return 0.0; 
} 

double EpicGames_Sessions_RemoveNotifySessionInviteRejected(double InId)
{ 
	EOS_NotificationId _InId = InId;
	EOS_Sessions_RemoveNotifySessionInviteRejected(HSessions, _InId);
	
	return 0.0; 
} 

void EOS_CALL Sessions_OnSendInviteCallback(const EOS_Sessions_SendInviteCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Sessions_SendInvite");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_Sessions_SendInvite(char* LocalUserId, char* SessionName, char* TargetUserId)
{ 
	EOS_HSessions Handle;
	EOS_Sessions_SendInviteOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_SENDINVITE_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.SessionName = SessionName;
	Options.TargetUserId = EOS_ProductUserId_FromString(TargetUserId);

	callback* mcallback = getCallbackData();
	EOS_Sessions_SendInvite(HSessions,&Options, mcallback, Sessions_OnSendInviteCallback);

	return 0.0; 
} 


void EOS_CALL Sessions_OnStartSessionCallback(const EOS_Sessions_StartSessionCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Sessions_StartSession");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_Sessions_StartSession(char* SessionName)
{ 
	EOS_Sessions_StartSessionOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_STARTSESSION_API_LATEST;
	Options.SessionName = SessionName;

	callback* mcallback = getCallbackData();
	EOS_Sessions_StartSession(HSessions,&Options, mcallback, Sessions_OnStartSessionCallback);

	return mcallback->identifier;
} 


void EOS_CALL Sessions_OnUnregisterPlayersCallback(const EOS_Sessions_UnregisterPlayersCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Sessions_UnregisterPlayers");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "unregistered_players", (char*)productIds2ArrayStr(Data->UnregisteredPlayers,Data->UnregisteredPlayersCount));
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_Sessions_UnregisterPlayers() 
{ 
	//TODO
	EOS_Sessions_UnregisterPlayersOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_UNREGISTERPLAYERS_API_LATEST;
	Options.PlayersToUnregister;
	Options.PlayersToUnregisterCount;
	Options.SessionName;

	callback* mcallback = getCallbackData();

	EOS_Sessions_UnregisterPlayers(HSessions,&Options,mcallback, Sessions_OnUnregisterPlayersCallback);

	return mcallback->identifier;
}


void EOS_CALL Sessions_OnUpdateSessionCallback(const EOS_Sessions_UpdateSessionCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Sessions_UpdateSession");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "session_id", Data->SessionId);
	DsMapAddString(map, "session_name", Data->SessionName);
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_Sessions_UpdateSession()
{ 
	//TODO
	EOS_Sessions_UpdateSessionOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_UPDATESESSION_API_LATEST;
	Options.SessionModificationHandle;

	callback* mcallback = getCallbackData();
	EOS_Sessions_UpdateSession(HSessions,&Options, mcallback, Sessions_OnUpdateSessionCallback);

	return mcallback->identifier;
} 

double EpicGames_Sessions_UpdateSessionModification(char* SessionName)
{ 
	EOS_Sessions_UpdateSessionModificationOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONS_UPDATESESSIONMODIFICATION_API_LATEST;
	Options.SessionName = SessionName;

	EOS_HSessionModification OutSessionModificationHandle;

	return (double) EOS_Sessions_UpdateSessionModification(HSessions,&Options,&OutSessionModificationHandle);
}

double EpicGames_SessionSearch_CopySearchResultByIndex(double SessionIndex)
{ 
	EOS_HSessionSearch Handle = 0;

	EOS_SessionSearch_CopySearchResultByIndexOptions Options = { 0 };
	Options.ApiVersion = EOS_SESSIONSEARCH_COPYSEARCHRESULTBYINDEX_API_LATEST;
	Options.SessionIndex = SessionIndex;
	EOS_HSessionDetails OutSessionHandle;

	double result = (double)EOS_SessionSearch_CopySearchResultByIndex(Handle,&Options, &OutSessionHandle);

	//OutSessionHandle.

	return result; 
} 

void EOS_CALL SessionSearch_OnFindCallback(const EOS_SessionSearch_FindCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_SessionSearch_Find");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_SessionSearch_Find(char* LocalUserId)
{ 
	EOS_HSessionSearch Handle = 0;
	EOS_SessionSearch_FindOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONSEARCH_FIND_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	
	callback* mcallback = getCallbackData();

	EOS_SessionSearch_Find(Handle, &Options, mcallback, SessionSearch_OnFindCallback);

	return mcallback->identifier;
} 

double EpicGames_SessionSearch_GetSearchResultCount() 
{ 
	EOS_HSessionSearch Handle = 0;
	EOS_SessionSearch_GetSearchResultCountOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONSEARCH_GETSEARCHRESULTCOUNT_API_LATEST;

	return EOS_SessionSearch_GetSearchResultCount(Handle, &Options);
}

double EpicGames_SessionSearch_Release() //TODO
{ 
	EOS_HSessionSearch SessionSearchHandle = 0;
	EOS_SessionSearch_Release(SessionSearchHandle);
	return 0.0; 
} 

double EpicGames_SessionSearch_RemoveParameter(char* Key, double ComparisonOp)
{ 
	EOS_HSessionSearch Handle = 0;
	EOS_SessionSearch_RemoveParameterOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONSEARCH_REMOVEPARAMETER_API_LATEST;
	Options.ComparisonOp = (EOS_EOnlineComparisonOp) ComparisonOp;
	Options.Key = Key;

	return (double) EOS_SessionSearch_RemoveParameter(Handle,&Options);
} 

double EpicGames_SessionSearch_SetMaxResults(double MaxSearchResults)
{ 
	EOS_HSessionSearch Handle = 0;
	EOS_SessionSearch_SetMaxResultsOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONSEARCH_SETMAXSEARCHRESULTS_API_LATEST;
	Options.MaxSearchResults = MaxSearchResults;

	return (double) EOS_SessionSearch_SetMaxResults(Handle,&Options);
} 

double EpicGames_SessionSearch_SetParameter() 
{ 
	//TODO
	EOS_HSessionSearch Handle = 0;
	EOS_SessionSearch_SetParameterOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONSEARCH_SETPARAMETER_API_LATEST;
	//Options.ComparisonOp = ;
	//Options.Parameter = ;

	return (double) EOS_SessionSearch_SetParameter(Handle, &Options);
} 

double EpicGames_SessionSearch_SetSessionId(char* SessionId)
{ 
	EOS_HSessionSearch Handle = 0;
	EOS_SessionSearch_SetSessionIdOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONSEARCH_SETSESSIONID_API_LATEST;
	Options.SessionId = SessionId;

	return (double)EOS_SessionSearch_SetSessionId(Handle,&Options);
} 

double EpicGames_SessionSearch_SetTargetUserId(char* TargetUserId)
{ 
	EOS_HSessionSearch Handle = 0;
	EOS_SessionSearch_SetTargetUserIdOptions Options = {0};
	Options.ApiVersion = EOS_SESSIONSEARCH_SETTARGETUSERID_API_LATEST;
	Options.TargetUserId = EOS_ProductUserId_FromString(TargetUserId);

	return (double)EOS_SessionSearch_SetTargetUserId(Handle, &Options);
}


