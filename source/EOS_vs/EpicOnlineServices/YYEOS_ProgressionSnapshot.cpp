
//EOS_ProgressionSnapshot_AddProgression
//EOS_ProgressionSnapshot_BeginSnapshot
//EOS_ProgressionSnapshot_DeleteSnapshot
//EOS_ProgressionSnapshot_EndSnapshot
//EOS_ProgressionSnapshot_SubmitSnapshot

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include <eos_progressionsnapshot.h>

EOS_HProgressionSnapshot HProgressionSnapshot;
void EpicGames_ProgressionSnapshot_Init()
{
	HProgressionSnapshot = EOS_Platform_GetProgressionSnapshotInterface(PlatformHandle);
}

YYEXPORT void EpicGames_ProgressionSnapshot_AddProgression(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	int32 SnapshotId = YYGetInt32(arg, 0);
	const char* Key = YYGetString(arg, 1);
	const char* Value = YYGetString(arg, 2);

	EOS_ProgressionSnapshot_AddProgressionOptions Options = {0};
	Options.ApiVersion = EOS_PROGRESSIONSNAPSHOT_ADDPROGRESSION_API_LATEST;
	Options.SnapshotId = SnapshotId;
	Options.Key = Key;
	Options.Value = Value;
	EOS_ProgressionSnapshot_AddProgression(HProgressionSnapshot, &Options);
}

YYEXPORT void EpicGames_ProgressionSnapshot_BeginSnapshot(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	const char* user = YYGetString(arg, 0);

	EOS_ProgressionSnapshot_BeginSnapshotOptions Options = { 0 };
	Options.ApiVersion = EOS_PROGRESSIONSNAPSHOT_BEGINSNAPSHOT_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);
	
	uint32_t OutSnapshotId;
	EOS_EResult result = EOS_ProgressionSnapshot_BeginSnapshot(HProgressionSnapshot, &Options ,&OutSnapshotId);

	Result.kind = VALUE_INT32;

	if (result == EOS_EResult::EOS_Success)
		Result.v32 = OutSnapshotId;
	else
		Result.v32 = -4;
}

void EOS_CALL DeleteSnapshot(const EOS_ProgressionSnapshot_DeleteSnapshotCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_ProgressionSnapshot_DeleteSnapshot");
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_ProgressionSnapshot_DeleteSnapshot(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	const char* user = YYGetString(arg, 0);

	EOS_ProgressionSnapshot_DeleteSnapshotOptions Options = { 0 };
	Options.ApiVersion = EOS_PROGRESSIONSNAPSHOT_DELETESNAPSHOT_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);

	callback* mcallback = getCallbackData();

	EOS_ProgressionSnapshot_DeleteSnapshot(HProgressionSnapshot, &Options, mcallback, DeleteSnapshot);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

YYEXPORT void EpicGames_ProgressionSnapshot_EndSnapshot(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	int32 SnapshotId = YYGetInt32(arg, 0);

	EOS_ProgressionSnapshot_EndSnapshotOptions Options = { 0 };
	Options.ApiVersion = EOS_PROGRESSIONSNAPSHOT_ENDSNAPSHOT_API_LATEST;
	Options.SnapshotId = SnapshotId;

	uint32_t OutSnapshotId;
	EOS_EResult result = EOS_ProgressionSnapshot_EndSnapshot(HProgressionSnapshot, &Options);

	Result.kind = VALUE_INT32;

	RValue Struct = { 0 };
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

void EOS_CALL SubmitSnapshot(const EOS_ProgressionSnapshot_SubmitSnapshotCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_ProgressionSnapshot_SubmitSnapshot");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_ProgressionSnapshot_SubmitSnapshot(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	int32 SnapshotId = YYGetInt32(arg, 0);

	EOS_ProgressionSnapshot_SubmitSnapshotOptions Options = { 0 };
	Options.ApiVersion = EOS_PROGRESSIONSNAPSHOT_SUBMITSNAPSHOT_API_LATEST;
	Options.SnapshotId = SnapshotId;

	callback* mcallback = getCallbackData();

	EOS_ProgressionSnapshot_SubmitSnapshot(HProgressionSnapshot, &Options, mcallback, SubmitSnapshot);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}
