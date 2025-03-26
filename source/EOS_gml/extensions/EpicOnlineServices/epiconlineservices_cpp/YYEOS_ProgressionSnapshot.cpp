
// EOS_ProgressionSnapshot_AddProgression
// EOS_ProgressionSnapshot_BeginSnapshot
// EOS_ProgressionSnapshot_DeleteSnapshot
// EOS_ProgressionSnapshot_EndSnapshot
// EOS_ProgressionSnapshot_SubmitSnapshot

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include <eos_progressionsnapshot.h>

EOS_HProgressionSnapshot HProgressionSnapshot;
void eos_progression_snapshot_init()
{
	HProgressionSnapshot = EOS_Platform_GetProgressionSnapshotInterface(PlatformHandle);
}

YYEXPORT void eos_progression_snapshot_add_progression(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_bool;

	eos_ensure_argc(3);

	int32 SnapshotId = YYGetInt32(arg, 0);
	const char *Key = YYGetString(arg, 1);
	const char *Value = YYGetString(arg, 2);

	EOS_ProgressionSnapshot_AddProgressionOptions Options = {0};
	Options.ApiVersion = EOS_PROGRESSIONSNAPSHOT_ADDPROGRESSION_API_LATEST;
	Options.SnapshotId = SnapshotId;
	Options.Key = Key;
	Options.Value = Value;
	EOS_ProgressionSnapshot_AddProgression(HProgressionSnapshot, &Options);
}

YYEXPORT void eos_progression_snapshot_begin_snapshot(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_int32;

	eos_ensure_argc(1);

	const char *user = YYGetString(arg, 0);

	EOS_ProgressionSnapshot_BeginSnapshotOptions Options = {0};
	Options.ApiVersion = EOS_PROGRESSIONSNAPSHOT_BEGINSNAPSHOT_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);

	uint32_t OutSnapshotId;
	EOS_EResult result = EOS_ProgressionSnapshot_BeginSnapshot(HProgressionSnapshot, &Options, &OutSnapshotId);

	Result.kind = VALUE_INT32;

	if (result == EOS_EResult::EOS_Success)
		Result.v32 = OutSnapshotId;
	else
		Result.v32 = -4;
}

void EOS_CALL DeleteSnapshot(const EOS_ProgressionSnapshot_DeleteSnapshotCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_progression_snapshot_delete_snapshot");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_progression_snapshot_delete_snapshot(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	const char *user = YYGetString(arg, 0);

	EOS_ProgressionSnapshot_DeleteSnapshotOptions Options = {0};
	Options.ApiVersion = EOS_PROGRESSIONSNAPSHOT_DELETESNAPSHOT_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);

	callback *mcallback = getCallbackData();

	EOS_ProgressionSnapshot_DeleteSnapshot(HProgressionSnapshot, &Options, mcallback, DeleteSnapshot);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

YYEXPORT void eos_progression_snapshot_end_snapshot(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(1);

	int32 SnapshotId = YYGetInt32(arg, 0);

	EOS_ProgressionSnapshot_EndSnapshotOptions Options = {0};
	Options.ApiVersion = EOS_PROGRESSIONSNAPSHOT_ENDSNAPSHOT_API_LATEST;
	Options.SnapshotId = SnapshotId;

	EOS_EResult result = EOS_ProgressionSnapshot_EndSnapshot(HProgressionSnapshot, &Options);

	Result.kind = VALUE_INT32;

	RValue Struct = {0};
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

void EOS_CALL SubmitSnapshot(const EOS_ProgressionSnapshot_SubmitSnapshotCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_progression_snapshot_submit_snapshot");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_progression_snapshot_submit_snapshot(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	int32 SnapshotId = YYGetInt32(arg, 0);

	EOS_ProgressionSnapshot_SubmitSnapshotOptions Options = {0};
	Options.ApiVersion = EOS_PROGRESSIONSNAPSHOT_SUBMITSNAPSHOT_API_LATEST;
	Options.SnapshotId = SnapshotId;

	callback *mcallback = getCallbackData();

	EOS_ProgressionSnapshot_SubmitSnapshot(HProgressionSnapshot, &Options, mcallback, SubmitSnapshot);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}
