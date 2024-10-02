
//Stats Interface
//Interface for managing stats.

//EOS_Stats_CopyStatByIndex
//EOS_Stats_CopyStatByName
//EOS_Stats_GetStatsCount
//EOS_Stats_IngestStat
//EOS_Stats_QueryStats

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include "eos_stats.h"

EOS_HStats HStats;
void EpicGames_Stats_Init()
{
	HStats = EOS_Platform_GetStatsInterface(PlatformHandle);
}

RValue StatToStruct(EOS_Stats_Stat* Stat, EOS_EResult result)
{
	RValue Struct = { 0 };
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	if (result != EOS_EResult::EOS_Success)
		return Struct;

	if (Stat->Name)
		YYStructAddString(&Struct, "Name", Stat->Name);

	// Note: Undefined = EOS_STATS_QUERYSTATS_API_LATEST
	if (Stat->StartTime)
		YYStructAddDouble(&Struct, "StartTime", Stat->StartTime);

	if (Stat->EndTime)
		YYStructAddDouble(&Struct, "EndTime", Stat->EndTime);

	if (Stat->Value)
		YYStructAddDouble(&Struct, "Value", Stat->Value);

	EOS_Stats_Stat_Release(Stat);
	
	return Struct;
}

YYEXPORT void EpicGames_Stats_CopyStatByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_STRUCT

	const char* target = YYGetString(arg, 0);
	int index = (int)YYGetReal(arg, 1);

	EOS_Stats_Stat* Stat = NULL;
	EOS_Stats_CopyStatByIndexOptions CopyByIndexOptions = {};
	CopyByIndexOptions.ApiVersion = EOS_STATS_COPYSTATBYINDEX_API_LATEST;
	CopyByIndexOptions.TargetUserId = EOS_ProductUserId_FromString(target);
	CopyByIndexOptions.StatIndex = index;

	EOS_EResult CopyStatResult = EOS_Stats_CopyStatByIndex(HStats, &CopyByIndexOptions, &Stat);

	RValue Struct = StatToStruct(Stat, CopyStatResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void EpicGames_Stats_CopyStatByName(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_STRUCT

	const char* target = YYGetString(arg, 0);
	const char* name = YYGetString(arg, 1);

	EOS_Stats_Stat* Stat = NULL;
	EOS_Stats_CopyStatByNameOptions CopyByNameOptions = {};
	CopyByNameOptions.ApiVersion = EOS_STATS_COPYSTATBYNAME_API_LATEST;
	CopyByNameOptions.TargetUserId = EOS_ProductUserId_FromString(target);
	CopyByNameOptions.Name = name;

	EOS_EResult CopyStatResult = EOS_Stats_CopyStatByName(HStats, &CopyByNameOptions, &Stat);

	RValue Struct = StatToStruct(Stat, CopyStatResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void EpicGames_Stats_GetStatsCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_INT32

	const char* target = YYGetString(arg, 0);

	EOS_Stats_GetStatCountOptions StatCountOptions = {};
	StatCountOptions.ApiVersion = EOS_STATS_GETSTATCOUNT_API_LATEST;
	StatCountOptions.TargetUserId = EOS_ProductUserId_FromString(target);

	uint32_t StatsCount = EOS_Stats_GetStatsCount(HStats, &StatCountOptions);

	Result.kind = VALUE_INT32;
	Result.v32 = (int32)StatsCount;
}

void EOS_CALL StatsIngestCallbackFn(const EOS_Stats_IngestStatCompleteCallbackInfo* Data)
{
	//assert(Data != NULL);
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Stats_IngestStat");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Stats_IngestStat(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	const char* locaUserId = YYGetString(arg, 0);
	const char* target = YYGetString(arg, 1);
	const char* statName = YYGetString(arg, 2);
	int32 amount = YYGetInt32(arg, 3);

	EOS_Stats_IngestStatOptions StatsIngestOptions = {};
	StatsIngestOptions.ApiVersion = EOS_STATS_INGESTSTAT_API_LATEST;
	StatsIngestOptions.LocalUserId = EOS_ProductUserId_FromString(locaUserId);
	StatsIngestOptions.TargetUserId = EOS_ProductUserId_FromString(target);
	StatsIngestOptions.StatsCount = 1;

	EOS_Stats_IngestData* IngestData = new EOS_Stats_IngestData[StatsIngestOptions.StatsCount];

	IngestData[0].ApiVersion = EOS_STATS_INGESTDATA_API_LATEST;
	IngestData[0].StatName = statName;
	IngestData[0].IngestAmount = amount;

	StatsIngestOptions.Stats = IngestData;

	callback* mcallback = getCallbackData();

	EOS_Stats_IngestStat(HStats, &StatsIngestOptions, mcallback, StatsIngestCallbackFn);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL StatsQueryCallbackFn(const EOS_Stats_OnQueryStatsCompleteCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Stats_QueryStats");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Stats_QueryStats(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	const char* user = YYGetString(arg, 0);
	const char* target = YYGetString(arg, 1);
	int64 startTime = YYGetReal(arg, 2);
	int64 endTime = YYGetReal(arg, 3);

	EOS_Stats_QueryStatsOptions StatsQueryOptions = {};
	StatsQueryOptions.ApiVersion = EOS_STATS_QUERYSTATS_API_LATEST;
	StatsQueryOptions.LocalUserId = EOS_ProductUserId_FromString(user);
	StatsQueryOptions.TargetUserId = EOS_ProductUserId_FromString(target);

	// Optional params
	if(startTime > 0)
		StatsQueryOptions.StartTime = startTime;
	else
		StatsQueryOptions.StartTime = EOS_STATS_TIME_UNDEFINED;

	if(endTime > 0)
		StatsQueryOptions.EndTime = endTime;
	else
		StatsQueryOptions.EndTime = EOS_STATS_TIME_UNDEFINED;

	StatsQueryOptions.StatNamesCount = 0;
	StatsQueryOptions.StatNames = NULL;
	//StatsQueryOptions.StatNames[0] = ;//TODO?

	callback* mcallback = getCallbackData();

	EOS_Stats_QueryStats(HStats, &StatsQueryOptions, mcallback, StatsQueryCallbackFn);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

