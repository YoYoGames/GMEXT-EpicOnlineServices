
// Sanctions Interface
// Manage punitive actions taken against your users including temporary or permanent bans from gameplay or communication.

// EOS_Sanctions_CopyPlayerSanctionByIndex
// EOS_Sanctions_GetPlayerSanctionCount
// EOS_Sanctions_QueryActivePlayerSanctions

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include <eos_sanctions.h>

//EOS_HSanctions HSanctions;
void EpicGames_Sanctions_Init()
{
	HSanctions = EOS_Platform_GetSanctionsInterface(PlatformHandle);
}

YYEXPORT void EpicGames_Sanctions_CopyPlayerSanctionByIndex(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(2);

	const char *target = YYGetString(arg, 0);
	uint32_t index = YYGetUint32(arg, 1);

	EOS_Sanctions_CopyPlayerSanctionByIndexOptions Options = {0};
	Options.ApiVersion = EOS_SANCTIONS_COPYPLAYERSANCTIONBYINDEX_API_LATEST;
	Options.SanctionIndex = index;
	Options.TargetUserId = EOS_ProductUserId_FromString(target);

	EOS_Sanctions_PlayerSanction *OutSanction;
	EOS_Sanctions_CopyPlayerSanctionByIndex(HSanctions, &Options, &OutSanction);

	RValue Struct = {0};
	YYStructCreate(&Struct);

	YYStructAddString(&Struct, "Action", OutSanction->Action);
	YYStructAddString(&Struct, "ReferenceId", OutSanction->ReferenceId);
	YYStructAddInt64(&Struct, "TimeExpires", OutSanction->TimeExpires);
	YYStructAddInt64(&Struct, "TimePlaced", OutSanction->TimePlaced);

	EOS_Sanctions_PlayerSanction_Release(OutSanction);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void EpicGames_Sanctions_GetPlayerSanctionCount(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_bool;

	eos_ensure_argc(1);

	const char *target = YYGetString(arg, 0);

	EOS_Sanctions_GetPlayerSanctionCountOptions Options = {0};
	Options.ApiVersion = EOS_SANCTIONS_GETPLAYERSANCTIONCOUNT_API_LATEST;
	Options.TargetUserId = EOS_ProductUserId_FromString(target);

	Result.kind = VALUE_BOOL;
	Result.val = true;
	EOS_Sanctions_GetPlayerSanctionCount(HSanctions, &Options);
}

void EOS_CALL QueryActivePlayerSanctions_old(const EOS_Sanctions_QueryActivePlayerSanctionsCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Sanctions_QueryActivePlayerSanctions");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void EpicGames_Sanctions_QueryActivePlayerSanctions(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *target = YYGetString(arg, 1);

	EOS_Sanctions_QueryActivePlayerSanctionsOptions Options = {0};
	Options.ApiVersion = EOS_SANCTIONS_QUERYACTIVEPLAYERSANCTIONS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);
	Options.TargetUserId = EOS_ProductUserId_FromString(target);

	callback *mcallback = getCallbackData();

	EOS_Sanctions_QueryActivePlayerSanctions(HSanctions, &Options, mcallback, QueryActivePlayerSanctions_old);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}
