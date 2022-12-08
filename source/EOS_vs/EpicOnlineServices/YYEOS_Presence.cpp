

//EOS_Presence_AddNotifyJoinGameAccepted
//EOS_Presence_AddNotifyOnPresenceChanged
//EOS_Presence_CopyPresence
//EOS_Presence_CreatePresenceModification
//EOS_Presence_GetJoinInfo
//EOS_Presence_HasPresence
//EOS_Presence_QueryPresence
//EOS_Presence_RemoveNotifyJoinGameAccepted
//EOS_Presence_RemoveNotifyOnPresenceChanged
//EOS_Presence_SetPresence
//EOS_PresenceModification_DeleteData
//EOS_PresenceModification_SetData
//EOS_PresenceModification_SetJoinInfo
//EOS_PresenceModification_SetRawRichText
//EOS_PresenceModification_SetStatus


#include "pch.h"
#include "YYEpicOnlineServices.h"
#include <eos_presence.h>

EOS_HPresence HPresence;
void EpicGames_Presence_Init()
{
	HPresence = EOS_Platform_GetPresenceInterface(PlatformHandle);
}

void EOS_CALL AddNotifyJoinGameAccepted(const EOS_Presence_JoinGameAcceptedCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Presence_AddNotifyJoinGameAccepted");
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "JoinInfo", Data->JoinInfo);
	DsMapAddDouble(map, "UiEventId", (double)Data->UiEventId);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Presence_AddNotifyJoinGameAccepted(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_BOOL

	EOS_Presence_AddNotifyJoinGameAcceptedOptions Options = { 0 };
	Options.ApiVersion = EOS_PRESENCE_ADDNOTIFYJOINGAMEACCEPTED_API_LATEST;

	EOS_Presence_AddNotifyJoinGameAccepted(HPresence, &Options, NULL, AddNotifyJoinGameAccepted);

	Result.kind = VALUE_BOOL;
	Result.val = true;
}

void EOS_CALL AddNotifyOnPresenceChanged(const EOS_Presence_PresenceChangedCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Presence_AddNotifyOnPresenceChanged");
	DsMapAddString(map, "PresenceUserId", AccountID_toString(Data->PresenceUserId));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Presence_AddNotifyOnPresenceChanged(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	EOS_Presence_AddNotifyOnPresenceChangedOptions Options = { 0 };
	Options.ApiVersion = EOS_PRESENCE_ADDNOTIFYONPRESENCECHANGED_API_LATEST;

	callback* mcallback = getCallbackData();

	EOS_Presence_AddNotifyOnPresenceChanged(HPresence, &Options, mcallback, AddNotifyOnPresenceChanged);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

YYEXPORT void EpicGames_Presence_CopyPresence(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_STRUCT

	const char* local = YYGetString(arg, 0);
	const char* target = YYGetString(arg, 1);

	EOS_Presence_CopyPresenceOptions Options = {0};
	Options.ApiVersion = EOS_PRESENCE_COPYPRESENCE_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(local);
	Options.TargetUserId = EOS_EpicAccountId_FromString(target);

	EOS_Presence_Info* info = NULL;

	EOS_EResult result = EOS_Presence_CopyPresence(HPresence,&Options,&info);

	RValue Struct = { 0 };
	YYStructCreate(&Struct);

	if (result != EOS_EResult::EOS_Success)
	{
		COPY_RValue(&Result, &Struct);
		FREE_RValue(&Struct);
		return;
	}
	
	if (info->ApiVersion)
		YYStructAddDouble(&Struct, "ApiVersion", (double)info->ApiVersion);
	
	//if (info->Platform)
	//if (info->ProductVersion)

	if (info->ProductId)
		YYStructAddString(&Struct, "ProductId", info->ProductId);

	if (info->ProductName)
		YYStructAddString(&Struct, "ProductName", info->ProductName);
	
	if (info->Records)
	{
	}

	if (info->RecordsCount)
		YYStructAddDouble(&Struct, "RecordsCount", (double)info->RecordsCount);

	if (info->RichText)
		YYStructAddString(&Struct, "RichText", info->RichText);
	
	YYStructAddDouble(&Struct, "ApiVersion", (double)info->Status);

	if (info->UserId)
	{
		static char TempBuffer[EOS_EPICACCOUNTID_MAX_LENGTH + 1];
		int32_t TempBufferSize = sizeof(TempBuffer);
		EOS_EResult EResult = EOS_EpicAccountId_ToString(info->UserId, TempBuffer, &TempBufferSize);

		YYStructAddString(&Struct, "UserId", TempBuffer);
	}
	
	EOS_Presence_Info_Release(info);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

EOS_HPresenceModification EOS_Presence_CreatePresenceModification(const char* user)
{
	EOS_Presence_CreatePresenceModificationOptions Options = { 0 };
	Options.ApiVersion = EOS_PRESENCE_CREATEPRESENCEMODIFICATION_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);

	EOS_HPresenceModification presenceModification = NULL;
	EOS_Presence_CreatePresenceModification(HPresence, &Options, &presenceModification);

	return presenceModification;
}

YYEXPORT void EpicGames_Presence_GetJoinInfo(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_STRING

	const char* user = YYGetString(arg, 0);
	const char* target = YYGetString(arg, 1);

	EOS_Presence_GetJoinInfoOptions GetJoinInfoOptions = {};
	GetJoinInfoOptions.ApiVersion = EOS_PRESENCE_GETJOININFO_API_LATEST;
	GetJoinInfoOptions.LocalUserId = EOS_EpicAccountId_FromString(user);
	GetJoinInfoOptions.TargetUserId = EOS_EpicAccountId_FromString(target);

	char JoinInfoBuffer[EOS_PRESENCEMODIFICATION_JOININFO_MAX_LENGTH + 1];
	int32_t BufferLength = EOS_PRESENCEMODIFICATION_JOININFO_MAX_LENGTH;

	EOS_EResult GetJoinInfoResult = EOS_Presence_GetJoinInfo(HPresence, &GetJoinInfoOptions, JoinInfoBuffer, &BufferLength);

	YYCreateString(&Result, JoinInfoBuffer);
}

YYEXPORT void EpicGames_Presence_HasPresence(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_BOOL

	const char* user = YYGetString(arg, 0);
	const char* target = YYGetString(arg, 1);

	EOS_Presence_HasPresenceOptions Options = {0};
	Options.ApiVersion = EOS_PRESENCE_HASPRESENCE_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.TargetUserId = EOS_EpicAccountId_FromString(target);

	Result.kind = VALUE_BOOL;
	if (EOS_Presence_HasPresence(HPresence, &Options) == EOS_TRUE)
		Result.val = true;
	else
		Result.val = false;
}

void EOS_CALL QueryPresence(const EOS_Presence_QueryPresenceCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Presence_QueryPresence");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Presence_QueryPresence(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	const char* user = YYGetString(arg, 0);
	const char* target = YYGetString(arg, 1);

	EOS_Presence_QueryPresenceOptions Options = { 0 };
	Options.ApiVersion = EOS_PRESENCE_QUERYPRESENCE_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.TargetUserId = EOS_EpicAccountId_FromString(target);

	callback* mcallback = getCallbackData();

	EOS_Presence_QueryPresence(HPresence,&Options, mcallback, QueryPresence);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

YYEXPORT void EpicGames_Presence_RemoveNotifyJoinGameAccepted(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_BOOL

	int64 id = YYGetInt64(arg, 0);
	EOS_Presence_RemoveNotifyJoinGameAccepted(HPresence, (EOS_NotificationId)id);
}

YYEXPORT void EpicGames_Presence_RemoveNotifyOnPresenceChanged(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_BOOL

	int64 id = YYGetInt64(arg, 0);
	EOS_Presence_RemoveNotifyOnPresenceChanged(HPresence, id);
}
//
//void EOS_CALL SetPresence(const EOS_Presence_SetPresenceCallbackInfo* Data)
//{
//	int map = CreateDsMap(0);
//	DsMapAddString(map, "type", "EpicGames_Auth_QueryIdToken");
//	DsMapAddDouble(map, "status", (double)Data->ResultCode);
//	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
//	//DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
//	CreateAsyncEventWithDSMap(map, 70);
//}
//
//YYEXPORT void EpicGames_Presence_SetPresence(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//	const char* user = YYGetString(arg, 0);
//
//	EOS_Presence_SetPresenceOptions Options = { 0 };
//	Options.ApiVersion = EOS_PRESENCE_SETPRESENCE_API_LATEST;
//	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
//	Options.PresenceModificationHandle = EOS_Presence_CreatePresenceModification(user);
//
//	EOS_Presence_SetPresence(HPresence, &Options, NULL, SetPresence);
//}


void EOS_CALL DeleteData(const EOS_Presence_SetPresenceCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_PresenceModification_DeleteData");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_PresenceModification_DeleteData(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	const char* user = YYGetString(arg, 0);
	const char* key = YYGetString(arg, 1);

	EOS_PresenceModification_DataRecordId* record = new EOS_PresenceModification_DataRecordId[1];
	record[0].ApiVersion = EOS_PRESENCEMODIFICATION_DATARECORDID_API_LATEST;
	record[0].Key = key;

	EOS_PresenceModification_DeleteDataOptions Options = {0};
	Options.ApiVersion = EOS_PRESENCEMODIFICATION_DELETEDATA_API_LATEST;
	Options.Records = record;
	Options.RecordsCount = 1;

	EOS_HPresenceModification HPresenceModification = EOS_Presence_CreatePresenceModification(user);

	EOS_PresenceModification_DeleteData(HPresenceModification, &Options);

	EOS_Presence_SetPresenceOptions Options_ = { 0 };
	Options_.ApiVersion = EOS_PRESENCE_SETPRESENCE_API_LATEST;
	Options_.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options_.PresenceModificationHandle = HPresenceModification; //EOS_Presence_CreatePresenceModification(user);

	callback* mcallback = getCallbackData();

	EOS_Presence_SetPresence(HPresence, &Options_, mcallback, DeleteData);
	EOS_PresenceModification_Release(HPresenceModification);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}


void EOS_CALL SetData(const EOS_Presence_SetPresenceCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_PresenceModification_SetData");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_PresenceModification_SetData(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	const char* user = YYGetString(arg, 0);
	const char* key = YYGetString(arg, 1);
	const char* value = YYGetString(arg, 2);

	EOS_Presence_DataRecord* record = new EOS_Presence_DataRecord[1];
	record[0].ApiVersion = EOS_PRESENCEMODIFICATION_DATARECORDID_API_LATEST;
	record[0].Key = key;
	record[0].Value = value;

	EOS_PresenceModification_SetDataOptions Options = {0};
	Options.ApiVersion = EOS_PRESENCEMODIFICATION_SETDATA_API_LATEST;
	Options.RecordsCount = 1;
	Options.Records = record;

	EOS_HPresenceModification HPresenceModification = EOS_Presence_CreatePresenceModification(user);

	EOS_PresenceModification_SetData(HPresenceModification,&Options);

	EOS_Presence_SetPresenceOptions Options_ = { 0 };
	Options_.ApiVersion = EOS_PRESENCE_SETPRESENCE_API_LATEST;
	Options_.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options_.PresenceModificationHandle = HPresenceModification; //EOS_Presence_CreatePresenceModification(user);
	
	callback* mcallback = getCallbackData();

	EOS_Presence_SetPresence(HPresence, &Options_, mcallback, SetData);
	
	EOS_PresenceModification_Release(HPresenceModification);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL SetJoinInfo(const EOS_Presence_SetPresenceCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_PresenceModification_SetJoinInfo");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}


YYEXPORT void EpicGames_PresenceModification_SetJoinInfo(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	const char* user = YYGetString(arg, 0);
	const char* info = YYGetString(arg, 1);

	EOS_PresenceModification_SetJoinInfoOptions Options = { 0 };
	Options.ApiVersion = EOS_PRESENCEMODIFICATION_SETJOININFO_API_LATEST;
	Options.JoinInfo = info;

	EOS_HPresenceModification HPresenceModification = EOS_Presence_CreatePresenceModification(user);
	EOS_PresenceModification_SetJoinInfo(HPresenceModification, &Options);

	EOS_Presence_SetPresenceOptions Options_ = { 0 };
	Options_.ApiVersion = EOS_PRESENCE_SETPRESENCE_API_LATEST;
	Options_.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options_.PresenceModificationHandle = HPresenceModification; //EOS_Presence_CreatePresenceModification(user);

	callback* mcallback = getCallbackData();

	EOS_Presence_SetPresence(HPresence, &Options_, mcallback, SetJoinInfo);

	EOS_PresenceModification_Release(HPresenceModification);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL SetRawRichText(const EOS_Presence_SetPresenceCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_PresenceModification_SetRawRichText");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}


YYEXPORT void EpicGames_PresenceModification_SetRawRichText(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	const char* user = YYGetString(arg, 0);
	const char* text = YYGetString(arg, 1);

	EOS_PresenceModification_SetRawRichTextOptions Options = {0};
	Options.ApiVersion = EOS_PRESENCEMODIFICATION_SETRAWRICHTEXT_API_LATEST;
	Options.RichText = text;
	
	EOS_HPresenceModification HPresenceModification = EOS_Presence_CreatePresenceModification(user);
	EOS_EResult result = EOS_PresenceModification_SetRawRichText(HPresenceModification, &Options);

	EOS_Presence_SetPresenceOptions Options_ = { 0 };
	Options_.ApiVersion = EOS_PRESENCE_SETPRESENCE_API_LATEST;
	Options_.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options_.PresenceModificationHandle = HPresenceModification; //EOS_Presence_CreatePresenceModification(user);

	callback* mcallback = getCallbackData();

	EOS_Presence_SetPresence(HPresence, &Options_, mcallback, SetRawRichText);

	EOS_PresenceModification_Release(HPresenceModification);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL SetStatus(const EOS_Presence_SetPresenceCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_PresenceModification_SetStatus");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}


YYEXPORT void EpicGames_PresenceModification_SetStatus(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	const char* user = YYGetString(arg, 0);
	double status = YYGetReal(arg, 1);

	EOS_PresenceModification_SetStatusOptions Options = {};
	Options.ApiVersion = EOS_PRESENCEMODIFICATION_SETSTATUS_API_LATEST;
	Options.Status = (EOS_Presence_EStatus)status;

	EOS_HPresenceModification HPresenceModification = EOS_Presence_CreatePresenceModification(user);
	EOS_PresenceModification_SetStatus(HPresenceModification, &Options);

	EOS_Presence_SetPresenceOptions Options_ = { 0 };
	Options_.ApiVersion = EOS_PRESENCE_SETPRESENCE_API_LATEST;
	Options_.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options_.PresenceModificationHandle = HPresenceModification; //EOS_Presence_CreatePresenceModification(user);

	callback* mcallback = getCallbackData();

	EOS_Presence_SetPresence(HPresence, &Options_, mcallback, SetStatus);

	EOS_PresenceModification_Release(HPresenceModification);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}
