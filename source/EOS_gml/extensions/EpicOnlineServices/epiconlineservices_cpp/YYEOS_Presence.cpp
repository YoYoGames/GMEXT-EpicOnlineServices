

// EOS_Presence_AddNotifyJoinGameAccepted
// EOS_Presence_AddNotifyOnPresenceChanged
// EOS_Presence_CopyPresence
// EOS_Presence_CreatePresenceModification
// EOS_Presence_GetJoinInfo
// EOS_Presence_HasPresence
// EOS_Presence_QueryPresence
// EOS_Presence_RemoveNotifyJoinGameAccepted
// EOS_Presence_RemoveNotifyOnPresenceChanged
// EOS_Presence_SetPresence
// EOS_PresenceModification_DeleteData
// EOS_PresenceModification_SetData
// EOS_PresenceModification_SetJoinInfo
// EOS_PresenceModification_SetRawRichText
// EOS_PresenceModification_SetStatus

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include <eos_presence.h>

EOS_HPresence HPresence;
void eos_presence_init()
{
	HPresence = EOS_Platform_GetPresenceInterface(PlatformHandle);
}

void EOS_CALL AddNotifyJoinGameAccepted(const EOS_Presence_JoinGameAcceptedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_presence_add_notify_join_game_accepted");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "join_info", data->JoinInfo);
	DsMapAddDouble(map, "ui_event_id", (double)data->UiEventId);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void eos_presence_add_notify_join_game_accepted(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_int64;

	EOS_Presence_AddNotifyJoinGameAcceptedOptions Options = {0};
	Options.ApiVersion = EOS_PRESENCE_ADDNOTIFYJOINGAMEACCEPTED_API_LATEST;

	auto notificationId = EOS_Presence_AddNotifyJoinGameAccepted(HPresence, &Options, nullptr, AddNotifyJoinGameAccepted);

	Result.kind = VALUE_INT64;
	Result.v64 = static_cast<int64_t>(notificationId);
}

void EOS_CALL AddNotifyOnPresenceChanged(const EOS_Presence_PresenceChangedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_presence_add_notify_on_presence_changed");
	DsMapAddString(map, "presence_user_id", AccountID_toString(data->PresenceUserId));
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void eos_presence_add_notify_on_presence_changed(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_int64;

	EOS_Presence_AddNotifyOnPresenceChangedOptions Options = {0};
	Options.ApiVersion = EOS_PRESENCE_ADDNOTIFYONPRESENCECHANGED_API_LATEST;
	auto notificationId = EOS_Presence_AddNotifyOnPresenceChanged(HPresence, &Options, nullptr, AddNotifyOnPresenceChanged);

	Result.kind = VALUE_INT64;
	Result.v64 = static_cast<int64_t>(notificationId);
}

YYEXPORT void eos_presence_copy_presence(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(2);

	const char *local = YYGetString(arg, 0);
	const char *target = YYGetString(arg, 1);

	EOS_Presence_CopyPresenceOptions Options = {0};
	Options.ApiVersion = EOS_PRESENCE_COPYPRESENCE_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(local);
	Options.TargetUserId = EOS_EpicAccountId_FromString(target);

	EOS_Presence_Info *info = nullptr;

	EOS_EResult result = EOS_Presence_CopyPresence(HPresence, &Options, &info);

	RValue Struct = {0};
	YYStructCreate(&Struct);

	if (result != EOS_EResult::EOS_Success)
	{
		COPY_RValue(&Result, &Struct);
		FREE_RValue(&Struct);
		return;
	}

	if (info->ApiVersion)
		YYStructAddDouble(&Struct, "api_version", (double)info->ApiVersion);

	// if (info->Platform)
	// if (info->ProductVersion)

	if (info->ProductId)
		YYStructAddString(&Struct, "product_id", info->ProductId);

	if (info->ProductName)
		YYStructAddString(&Struct, "product_name", info->ProductName);

	if (info->Records)
	{
	}

	if (info->RecordsCount)
		YYStructAddDouble(&Struct, "records_count", (double)info->RecordsCount);

	if (info->RichText)
		YYStructAddString(&Struct, "rich_text", info->RichText);

	YYStructAddDouble(&Struct, "api_version", (double)info->Status);

	if (info->UserId)
	{
		static char TempBuffer[EOS_EPICACCOUNTID_MAX_LENGTH + 1];
		int32_t TempBufferSize = sizeof(TempBuffer);
		EOS_EResult EResult = EOS_EpicAccountId_ToString(info->UserId, TempBuffer, &TempBufferSize);

		YYStructAddString(&Struct, "user_id", TempBuffer);
	}

	EOS_Presence_Info_Release(info);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

EOS_HPresenceModification EOS_Presence_CreatePresenceModification(const char *user)
{
	EOS_Presence_CreatePresenceModificationOptions Options = {0};
	Options.ApiVersion = EOS_PRESENCE_CREATEPRESENCEMODIFICATION_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);

	EOS_HPresenceModification presenceModification = nullptr;
	EOS_Presence_CreatePresenceModification(HPresence, &Options, &presenceModification);

	return presenceModification;
}

YYEXPORT void eos_presence_get_join_info(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_string;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *target = YYGetString(arg, 1);

	EOS_Presence_GetJoinInfoOptions GetJoinInfoOptions = {};
	GetJoinInfoOptions.ApiVersion = EOS_PRESENCE_GETJOININFO_API_LATEST;
	GetJoinInfoOptions.LocalUserId = EOS_EpicAccountId_FromString(user);
	GetJoinInfoOptions.TargetUserId = EOS_EpicAccountId_FromString(target);

	char JoinInfoBuffer[EOS_PRESENCEMODIFICATION_JOININFO_MAX_LENGTH + 1];
	int32_t BufferLength = EOS_PRESENCEMODIFICATION_JOININFO_MAX_LENGTH;

	EOS_EResult GetJoinInfoResult = EOS_Presence_GetJoinInfo(HPresence, &GetJoinInfoOptions, JoinInfoBuffer, &BufferLength);

	YYCreateString(&Result, JoinInfoBuffer);
}

YYEXPORT void eos_presence_has_presence(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_bool;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *target = YYGetString(arg, 1);

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

void EOS_CALL QueryPresence(const EOS_Presence_QueryPresenceCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_presence_query_presence");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_presence_query_presence(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *target = YYGetString(arg, 1);

	EOS_Presence_QueryPresenceOptions Options = {0};
	Options.ApiVersion = EOS_PRESENCE_QUERYPRESENCE_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.TargetUserId = EOS_EpicAccountId_FromString(target);

	callback *mcallback = getCallbackData();

	EOS_Presence_QueryPresence(HPresence, &Options, mcallback, QueryPresence);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

YYEXPORT void eos_presence_remove_notify_join_game_accepted(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_bool;

	eos_ensure_argc(1);

	int64 id = YYGetInt64(arg, 0);
	EOS_Presence_RemoveNotifyJoinGameAccepted(HPresence, (EOS_NotificationId)id);
}

YYEXPORT void eos_presence_remove_notify_on_presence_changed(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_bool;

	eos_ensure_argc(1);

	int64 id = YYGetInt64(arg, 0);
	EOS_Presence_RemoveNotifyOnPresenceChanged(HPresence, id);
}
//
// void EOS_CALL SetPresence(const EOS_Presence_SetPresenceCallbackInfo* data)
//{
//	int map = CreateDsMap(0);
//	DsMapAddString(map, "type", "eos_auth_query_id_token");
//	DsMapAddDouble(map, "status", (double)data->ResultCode);
//	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
//	//DsMapAddDouble(map, "identifier", (double)((callback*)(data->ClientData))->identifier);
//	CreateAsyncEventWithDSMap(map, 70);
//}
//
// YYEXPORT void eos_presence_set_presence(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//	const char* user = YYGetString(arg, 0);
//
//	EOS_Presence_SetPresenceOptions Options = { 0 };
//	Options.ApiVersion = EOS_PRESENCE_SETPRESENCE_API_LATEST;
//	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
//	Options.PresenceModificationHandle = EOS_Presence_CreatePresenceModification(user);
//
//	EOS_Presence_SetPresence(HPresence, &Options, nullptr, SetPresence);
//}

void EOS_CALL DeleteData(const EOS_Presence_SetPresenceCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_presence_modification_delete_data");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_presence_modification_delete_data(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *key = YYGetString(arg, 1);

	EOS_PresenceModification_DataRecordId record{};
	record.ApiVersion = EOS_PRESENCEMODIFICATION_DATARECORDID_API_LATEST;
	record.Key = key;

	EOS_PresenceModification_DeleteDataOptions Options{};
	Options.ApiVersion = EOS_PRESENCEMODIFICATION_DELETEDATA_API_LATEST;
	Options.Records = &record;
	Options.RecordsCount = 1;

	EOS_HPresenceModification HPresenceModification = EOS_Presence_CreatePresenceModification(user);

	EOS_PresenceModification_DeleteData(HPresenceModification, &Options);

	EOS_Presence_SetPresenceOptions Options_ = {0};
	Options_.ApiVersion = EOS_PRESENCE_SETPRESENCE_API_LATEST;
	Options_.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options_.PresenceModificationHandle = HPresenceModification; // EOS_Presence_CreatePresenceModification(user);

	callback *mcallback = getCallbackData();

	EOS_Presence_SetPresence(HPresence, &Options_, mcallback, DeleteData);
	EOS_PresenceModification_Release(HPresenceModification);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL SetData(const EOS_Presence_SetPresenceCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_presence_modification_set_data");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_presence_modification_set_data(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(3);

	const char *user = YYGetString(arg, 0);
	const char *key = YYGetString(arg, 1);
	const char *value = YYGetString(arg, 2);

	EOS_Presence_DataRecord record{};
	record.ApiVersion = EOS_PRESENCEMODIFICATION_DATARECORDID_API_LATEST;
	record.Key = key;
	record.Value = value;

	EOS_PresenceModification_SetDataOptions Options{};
	Options.ApiVersion = EOS_PRESENCEMODIFICATION_SETDATA_API_LATEST;
	Options.RecordsCount = 1;
	Options.Records = &record;

	EOS_HPresenceModification HPresenceModification = EOS_Presence_CreatePresenceModification(user);

	EOS_PresenceModification_SetData(HPresenceModification, &Options);

	EOS_Presence_SetPresenceOptions Options_ = {0};
	Options_.ApiVersion = EOS_PRESENCE_SETPRESENCE_API_LATEST;
	Options_.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options_.PresenceModificationHandle = HPresenceModification; // EOS_Presence_CreatePresenceModification(user);

	callback *mcallback = getCallbackData();

	EOS_Presence_SetPresence(HPresence, &Options_, mcallback, SetData);

	EOS_PresenceModification_Release(HPresenceModification);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL SetJoinInfo(const EOS_Presence_SetPresenceCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_presence_modification_set_join_info");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_presence_modification_set_join_info(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *info = YYGetString(arg, 1);

	EOS_PresenceModification_SetJoinInfoOptions Options = {0};
	Options.ApiVersion = EOS_PRESENCEMODIFICATION_SETJOININFO_API_LATEST;
	Options.JoinInfo = info;

	EOS_HPresenceModification HPresenceModification = EOS_Presence_CreatePresenceModification(user);
	EOS_PresenceModification_SetJoinInfo(HPresenceModification, &Options);

	EOS_Presence_SetPresenceOptions Options_ = {0};
	Options_.ApiVersion = EOS_PRESENCE_SETPRESENCE_API_LATEST;
	Options_.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options_.PresenceModificationHandle = HPresenceModification; // EOS_Presence_CreatePresenceModification(user);

	callback *mcallback = getCallbackData();

	EOS_Presence_SetPresence(HPresence, &Options_, mcallback, SetJoinInfo);

	EOS_PresenceModification_Release(HPresenceModification);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL SetRawRichText(const EOS_Presence_SetPresenceCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_presence_modification_set_raw_rich_text");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_presence_modification_set_raw_rich_text(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *text = YYGetString(arg, 1);

	EOS_PresenceModification_SetRawRichTextOptions Options = {0};
	Options.ApiVersion = EOS_PRESENCEMODIFICATION_SETRAWRICHTEXT_API_LATEST;
	Options.RichText = text;

	EOS_HPresenceModification HPresenceModification = EOS_Presence_CreatePresenceModification(user);
	EOS_EResult result = EOS_PresenceModification_SetRawRichText(HPresenceModification, &Options);

	EOS_Presence_SetPresenceOptions Options_ = {0};
	Options_.ApiVersion = EOS_PRESENCE_SETPRESENCE_API_LATEST;
	Options_.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options_.PresenceModificationHandle = HPresenceModification; // EOS_Presence_CreatePresenceModification(user);

	callback *mcallback = getCallbackData();

	EOS_Presence_SetPresence(HPresence, &Options_, mcallback, SetRawRichText);

	EOS_PresenceModification_Release(HPresenceModification);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL SetStatus(const EOS_Presence_SetPresenceCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_presence_modification_set_status");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_presence_modification_set_status(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	int32_t status = YYGetInt32(arg, 1);

	EOS_PresenceModification_SetStatusOptions Options = {};
	Options.ApiVersion = EOS_PRESENCEMODIFICATION_SETSTATUS_API_LATEST;
	Options.Status = (EOS_Presence_EStatus)status;

	EOS_HPresenceModification HPresenceModification = EOS_Presence_CreatePresenceModification(user);
	EOS_PresenceModification_SetStatus(HPresenceModification, &Options);

	EOS_Presence_SetPresenceOptions Options_ = {0};
	Options_.ApiVersion = EOS_PRESENCE_SETPRESENCE_API_LATEST;
	Options_.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options_.PresenceModificationHandle = HPresenceModification; // EOS_Presence_CreatePresenceModification(user);

	callback *mcallback = getCallbackData();

	EOS_Presence_SetPresence(HPresence, &Options_, mcallback, SetStatus);

	EOS_PresenceModification_Release(HPresenceModification);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}
