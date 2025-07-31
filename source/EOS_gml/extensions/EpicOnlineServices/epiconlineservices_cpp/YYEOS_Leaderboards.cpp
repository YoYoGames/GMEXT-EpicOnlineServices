
// Leaderboards Interface
// Interface to handle online leaderboards

// EOS_Leaderboards_CopyLeaderboardDefinitionByIndex
// EOS_Leaderboards_CopyLeaderboardDefinitionByLeaderboardId
// EOS_Leaderboards_CopyLeaderboardRecordByIndex
// EOS_Leaderboards_CopyLeaderboardRecordByUserId
// EOS_Leaderboards_CopyLeaderboardUserScoreByIndex
// EOS_Leaderboards_CopyLeaderboardUserScoreByUserId
// EOS_Leaderboards_GetLeaderboardDefinitionCount
// EOS_Leaderboards_GetLeaderboardRecordCount
// EOS_Leaderboards_GetLeaderboardUserScoreCount
// EOS_Leaderboards_QueryLeaderboardDefinitions
// EOS_Leaderboards_QueryLeaderboardRanks
// EOS_Leaderboards_QueryLeaderboardUserScores

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include <eos_leaderboards.h>

EOS_HLeaderboards HLeaderboards;
void eos_leaderboards_init()
{
	HLeaderboards = EOS_Platform_GetLeaderboardsInterface(PlatformHandle);
}

RValue LeaderboardsDefinitionToStruct(EOS_Leaderboards_Definition *leaderboard, EOS_EResult result)
{
	RValue Struct = {0};
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	if (result != EOS_EResult::EOS_Success)
		return Struct;

	if (leaderboard->LeaderboardId)
		YYStructAddString(&Struct, "leaderboard_id", leaderboard->LeaderboardId);

	if (leaderboard->StatName)
		YYStructAddString(&Struct, "stat_name", leaderboard->StatName);

	if (leaderboard->StartTime)
		YYStructAddInt64(&Struct, "start_time", leaderboard->StartTime);

	if (leaderboard->EndTime)
		YYStructAddInt64(&Struct, "end_time", leaderboard->EndTime);

	EOS_Leaderboards_Definition_Release(leaderboard);

	return Struct;
}

YYEXPORT void eos_leaderboards_copy_leaderboard_definition_by_index(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(1);

	uint32_t index = YYGetUint32(arg, 0);

	EOS_Leaderboards_Definition *LeaderboardDef = NULL;

	EOS_Leaderboards_CopyLeaderboardDefinitionByIndexOptions CopyOptions = {0};
	CopyOptions.ApiVersion = EOS_LEADERBOARDS_COPYLEADERBOARDDEFINITIONBYINDEX_API_LATEST;
	CopyOptions.LeaderboardIndex = index;

	EOS_EResult CopyLeaderboardDefinitionsResult = EOS_Leaderboards_CopyLeaderboardDefinitionByIndex(HLeaderboards, &CopyOptions, &LeaderboardDef);

	RValue Struct = LeaderboardsDefinitionToStruct(LeaderboardDef, CopyLeaderboardDefinitionsResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_leaderboards_copy_leaderboard_definition_by_leaderboard_id(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(1);

	const char* leaderboardId = YYGetString(arg, 0);

	EOS_Leaderboards_Definition *LeaderboardDef = NULL;

	EOS_Leaderboards_CopyLeaderboardDefinitionByLeaderboardIdOptions CopyOptions = {0};
	CopyOptions.ApiVersion = EOS_LEADERBOARDS_COPYLEADERBOARDDEFINITIONBYLEADERBOARDID_API_LATEST;
	CopyOptions.LeaderboardId = leaderboardId;

	EOS_EResult CopyLeaderboardDefinitionsResult = EOS_Leaderboards_CopyLeaderboardDefinitionByLeaderboardId(HLeaderboards, &CopyOptions, &LeaderboardDef);

	RValue Struct = LeaderboardsDefinitionToStruct(LeaderboardDef, CopyLeaderboardDefinitionsResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

RValue LeaderboardRecordToStruct(EOS_Leaderboards_LeaderboardRecord *leaderboard, EOS_EResult result)
{
	RValue Struct = {0};
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	if (result != EOS_EResult::EOS_Success)
		return Struct;

	static char TempBuffer[EOS_PRODUCTUSERID_MAX_LENGTH + 1];
	int32_t TempBufferSize = sizeof(TempBuffer);
	EOS_EResult Result = EOS_ProductUserId_ToString(leaderboard->UserId, TempBuffer, &TempBufferSize);

	YYStructAddString(&Struct, "user_id", TempBuffer);
	YYStructAddDouble(&Struct, "rank", leaderboard->Rank = leaderboard->Rank);
	YYStructAddDouble(&Struct, "score", leaderboard->Score = leaderboard->Score);
	YYStructAddString(&Struct, "user_display_name", leaderboard->UserDisplayName);

	EOS_Leaderboards_LeaderboardRecord_Release(leaderboard);

	return Struct;
}

YYEXPORT void eos_leaderboards_copy_leaderboard_record_by_index(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(1);

	uint32_t index = YYGetUint32(arg, 0);

	EOS_Leaderboards_GetLeaderboardRecordCountOptions LeaderboardsRecordsCountOptions = {0};
	LeaderboardsRecordsCountOptions.ApiVersion = EOS_LEADERBOARDS_GETLEADERBOARDRECORDCOUNT_API_LATEST;

	uint32_t LeaderboardRecordsCount = EOS_Leaderboards_GetLeaderboardRecordCount(HLeaderboards, &LeaderboardsRecordsCountOptions);

	EOS_Leaderboards_CopyLeaderboardRecordByIndexOptions CopyOptions = {0};
	CopyOptions.ApiVersion = EOS_LEADERBOARDS_COPYLEADERBOARDRECORDBYINDEX_API_LATEST;
	CopyOptions.LeaderboardRecordIndex = index;

	EOS_Leaderboards_LeaderboardRecord *LeaderboardRecord = NULL;
	EOS_EResult CopyLeaderboardRecordResult = EOS_Leaderboards_CopyLeaderboardRecordByIndex(HLeaderboards, &CopyOptions, &LeaderboardRecord);

	RValue Struct = LeaderboardRecordToStruct(LeaderboardRecord, CopyLeaderboardRecordResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_leaderboards_copy_leaderboard_record_by_user_id(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(1);

	const char* userId = YYGetString(arg, 0);

	EOS_Leaderboards_GetLeaderboardRecordCountOptions LeaderboardsRecordsCountOptions = {0};
	LeaderboardsRecordsCountOptions.ApiVersion = EOS_LEADERBOARDS_GETLEADERBOARDRECORDCOUNT_API_LATEST;

	uint32_t LeaderboardRecordsCount = EOS_Leaderboards_GetLeaderboardRecordCount(HLeaderboards, &LeaderboardsRecordsCountOptions);

	EOS_Leaderboards_CopyLeaderboardRecordByUserIdOptions CopyOptions = {0};
	CopyOptions.ApiVersion = EOS_LEADERBOARDS_COPYLEADERBOARDRECORDBYUSERID_API_LATEST;
	CopyOptions.UserId = EOS_ProductUserId_FromString(userId);

	EOS_Leaderboards_LeaderboardRecord *LeaderboardRecord = NULL;
	EOS_EResult CopyLeaderboardRecordResult = EOS_Leaderboards_CopyLeaderboardRecordByUserId(HLeaderboards, &CopyOptions, &LeaderboardRecord);

	RValue Struct = LeaderboardRecordToStruct(LeaderboardRecord, CopyLeaderboardRecordResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

RValue LeaderboardUserScoreToStruct(EOS_Leaderboards_LeaderboardUserScore *leaderboard, EOS_EResult result)
{
	RValue Struct = {0};
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	if (result != EOS_EResult::EOS_Success)
		return Struct;

	YYStructAddString(&Struct, "user_id", productID_toString(leaderboard->UserId));
	YYStructAddDouble(&Struct, "score", leaderboard->Score);

	EOS_Leaderboards_LeaderboardUserScore_Release(leaderboard);

	return Struct;
}

YYEXPORT void eos_leaderboards_copy_leaderboard_user_score_by_index(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(2);

	uint32_t index = YYGetUint32(arg, 0);
	const char* statName = YYGetString(arg, 1);

	EOS_Leaderboards_CopyLeaderboardUserScoreByIndexOptions CopyOptions = {0};
	CopyOptions.ApiVersion = EOS_LEADERBOARDS_COPYLEADERBOARDUSERSCOREBYINDEX_API_LATEST;
	CopyOptions.StatName = statName;

	CopyOptions.LeaderboardUserScoreIndex = index;

	EOS_Leaderboards_LeaderboardUserScore *LeaderboardUserScore = NULL;
	EOS_EResult CopyLeaderboardUserScoreResult = EOS_Leaderboards_CopyLeaderboardUserScoreByIndex(HLeaderboards, &CopyOptions, &LeaderboardUserScore);

	RValue Struct = LeaderboardUserScoreToStruct(LeaderboardUserScore, CopyLeaderboardUserScoreResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_leaderboards_copy_leaderboard_user_score_by_user_id(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(2);

	const char* userId = YYGetString(arg, 0);
	const char* statName = YYGetString(arg, 1);

	EOS_Leaderboards_CopyLeaderboardUserScoreByUserIdOptions CopyOptions = {0};
	CopyOptions.ApiVersion = EOS_LEADERBOARDS_COPYLEADERBOARDUSERSCOREBYUSERID_API_LATEST;
	CopyOptions.StatName = statName;
	CopyOptions.UserId = EOS_ProductUserId_FromString(userId);

	EOS_Leaderboards_LeaderboardUserScore *LeaderboardUserScore = NULL;
	EOS_EResult CopyLeaderboardUserScoreResult = EOS_Leaderboards_CopyLeaderboardUserScoreByUserId(HLeaderboards, &CopyOptions, &LeaderboardUserScore);

	RValue Struct = LeaderboardUserScoreToStruct(LeaderboardUserScore, CopyLeaderboardUserScoreResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_leaderboards_get_leaderboard_definition_count(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_int32;

	EOS_Leaderboards_GetLeaderboardDefinitionCountOptions LeaderboardDefinitionsCountOptions = {0};
	LeaderboardDefinitionsCountOptions.ApiVersion = EOS_LEADERBOARDS_GETLEADERBOARDDEFINITIONCOUNT_API_LATEST;

	uint32_t LeaderboardDefinitionsCount = EOS_Leaderboards_GetLeaderboardDefinitionCount(HLeaderboards, &LeaderboardDefinitionsCountOptions);

	Result.kind = VALUE_INT32;
	Result.v32 = (int32)LeaderboardDefinitionsCount;
}

YYEXPORT void eos_leaderboards_get_leaderboard_record_count(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_int32;

	EOS_Leaderboards_GetLeaderboardRecordCountOptions LeaderboardsRecordsCountOptions = {0};
	LeaderboardsRecordsCountOptions.ApiVersion = EOS_LEADERBOARDS_GETLEADERBOARDRECORDCOUNT_API_LATEST;

	uint32_t LeaderboardRecordsCount = EOS_Leaderboards_GetLeaderboardRecordCount(HLeaderboards, &LeaderboardsRecordsCountOptions);

	Result.kind = VALUE_INT32;
	Result.v32 = (int32)LeaderboardRecordsCount;
}

YYEXPORT void eos_leaderboards_get_leaderboard_user_score_count(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_int32;

	eos_ensure_argc(1);

	const char* statName = YYGetString(arg, 0);

	EOS_Leaderboards_GetLeaderboardUserScoreCountOptions LeaderboardUserScoresCountOptions = {0};
	LeaderboardUserScoresCountOptions.ApiVersion = EOS_LEADERBOARDS_GETLEADERBOARDUSERSCORECOUNT_API_LATEST;
	LeaderboardUserScoresCountOptions.StatName = statName;

	Result.kind = VALUE_INT32;
	Result.v32 = EOS_Leaderboards_GetLeaderboardUserScoreCount(HLeaderboards, &LeaderboardUserScoresCountOptions);
}

void EOS_CALL LeaderboardDefinitionsReceivedCallbackFn(const EOS_Leaderboards_OnQueryLeaderboardDefinitionsCompleteCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_leaderboards_query_leaderboard_definitions");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_leaderboards_query_leaderboard_definitions(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	const char* mProductUserId = YYGetString(arg, 0);
	int64 startTime = argc < 2 ? -1 : YYGetInt64(arg, 1);
	int64 endTime = argc < 3 ? -1 : YYGetInt64(arg, 2);

	EOS_Leaderboards_QueryLeaderboardDefinitionsOptions QueryDefinitionsOptions = {0};
	QueryDefinitionsOptions.ApiVersion = EOS_LEADERBOARDS_QUERYLEADERBOARDDEFINITIONS_API_LATEST;

	if (startTime > 0)
		QueryDefinitionsOptions.StartTime = startTime;
	else
		QueryDefinitionsOptions.StartTime = EOS_LEADERBOARDS_TIME_UNDEFINED;

	if (endTime > 0)
		QueryDefinitionsOptions.EndTime = endTime;
	else
		QueryDefinitionsOptions.EndTime = EOS_LEADERBOARDS_TIME_UNDEFINED;

	QueryDefinitionsOptions.LocalUserId = EOS_ProductUserId_FromString(mProductUserId);

	callback *mcallback = getCallbackData();

	EOS_Leaderboards_QueryLeaderboardDefinitions(HLeaderboards, &QueryDefinitionsOptions, mcallback, LeaderboardDefinitionsReceivedCallbackFn);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL LeaderboardRanksReceivedCallbackFn(const EOS_Leaderboards_OnQueryLeaderboardRanksCompleteCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_leaderboards_query_leaderboard_ranks");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_leaderboards_query_leaderboard_ranks(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char* LocalUserId = YYGetString(arg, 0);
	const char* LeaderboardId = YYGetString(arg, 1);

	EOS_Leaderboards_QueryLeaderboardRanksOptions QueryRanksOptions = {0};
	QueryRanksOptions.ApiVersion = EOS_LEADERBOARDS_QUERYLEADERBOARDRANKS_API_LATEST;
	QueryRanksOptions.LeaderboardId = LeaderboardId;
	QueryRanksOptions.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);

	callback *mcallback = getCallbackData();

	EOS_Leaderboards_QueryLeaderboardRanks(HLeaderboards, &QueryRanksOptions, mcallback, LeaderboardRanksReceivedCallbackFn);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL LeaderboardUserScoresReceivedCallbackFn(const EOS_Leaderboards_OnQueryLeaderboardUserScoresCompleteCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_leaderboards_query_leaderboard_user_scores");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_leaderboards_query_leaderboard_user_score(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(5);

	const char* userID = YYGetString(arg, 0);
	const char* userID_target = YYGetString(arg, 1);
	const char* LeaderboardId = YYGetString(arg, 2); // not in use....
	const char* name = YYGetString(arg, 3);
	double agregation = YYGetReal(arg, 4);
	int64 startTime = argc < 6 ? -1 : YYGetInt64(arg, 5);
	int64 endTime = argc < 7 ? -1 : YYGetInt64(arg, 6);

	EOS_Leaderboards_QueryLeaderboardUserScoresOptions QueryUserScoresOptions = {0};
	QueryUserScoresOptions.LocalUserId = EOS_ProductUserId_FromString(userID);
	QueryUserScoresOptions.ApiVersion = EOS_LEADERBOARDS_QUERYLEADERBOARDUSERSCORES_API_LATEST;
	QueryUserScoresOptions.UserIdsCount = 1;
	EOS_ProductUserId UserData = EOS_ProductUserId_FromString(userID_target);
	QueryUserScoresOptions.UserIds = &UserData;

	QueryUserScoresOptions.StatInfoCount = 1;
	EOS_Leaderboards_UserScoresQueryStatInfo StatInfoData{};
	StatInfoData.StatName = name;
	StatInfoData.Aggregation = (EOS_ELeaderboardAggregation)agregation;

	QueryUserScoresOptions.StatInfo = &StatInfoData;

	if (startTime > 0)
		QueryUserScoresOptions.StartTime = startTime;
	else
		QueryUserScoresOptions.StartTime = EOS_LEADERBOARDS_TIME_UNDEFINED;

	if (endTime > 0)
		QueryUserScoresOptions.EndTime = endTime;
	else
		QueryUserScoresOptions.EndTime = EOS_LEADERBOARDS_TIME_UNDEFINED;

	callback *mcallback = getCallbackData();

	EOS_Leaderboards_QueryLeaderboardUserScores(HLeaderboards, &QueryUserScoresOptions, mcallback, LeaderboardUserScoresReceivedCallbackFn);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

YYEXPORT void eos_leaderboards_query_leaderboard_user_scores(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real

    const char* userID = YYGetString(arg, 0);
	const char* LeaderboardId = YYGetString(arg, 1); // not in use...

    // Convert to std::string for safety (this makes sure the strings survive GameMaker GC)
    auto productUserIds = _SW_GetArrayOfProductUserId(arg, 2, "eos_leaderboards_query_leaderboard_user_scores");

	// const char* name = YYGetString(arg, 3);
	// double agregation = YYGetReal(arg, 4);
	std::vector<EOS_Leaderboards_UserScoresQueryStatInfo> StatInfoData;
	if (KIND_RValue(&arg[3]) == VALUE_ARRAY)
	{
        EOS_Leaderboards_UserScoresQueryStatInfo info{};
        
		std::vector<RValue> vec_StatInfoData = _SW_GetArrayOfRValues(arg, 3, "eos_leaderboards_query_leaderboard_user_scores");
		for (const auto &e : vec_StatInfoData)
		{
			RValue *RValue_StatName = YYStructGetMember((RValue *)&e, "stat_name");
			RValue *RValue_Aggregation = YYStructGetMember((RValue *)&e, "aggregation");
            info.StatName = RValue_StatName->GetString();
            info.Aggregation = (EOS_ELeaderboardAggregation)RValue_Aggregation->val;
            StatInfoData.push_back(info);
		}
	}

	int64 startTime = YYGetInt64(arg, 4);
	int64 endTime = YYGetInt64(arg, 5);

	EOS_Leaderboards_QueryLeaderboardUserScoresOptions QueryUserScoresOptions{};
	QueryUserScoresOptions.LocalUserId = EOS_ProductUserId_FromString(userID);
	QueryUserScoresOptions.ApiVersion = EOS_LEADERBOARDS_QUERYLEADERBOARDUSERSCORES_API_LATEST;
	QueryUserScoresOptions.UserIds = productUserIds.data();
	QueryUserScoresOptions.UserIdsCount = (uint32_t)productUserIds.size();

	// EOS_ProductUserId* UserData = new EOS_ProductUserId[1];
	// UserData[0] = EOS_ProductUserId_FromString(userID_target);

	QueryUserScoresOptions.StatInfoCount = (uint32_t)StatInfoData.size();
	QueryUserScoresOptions.StatInfo = StatInfoData.data();

	if (startTime > 0)
		QueryUserScoresOptions.StartTime = startTime;
	else
		QueryUserScoresOptions.StartTime = EOS_LEADERBOARDS_TIME_UNDEFINED;

	if (endTime > 0)
		QueryUserScoresOptions.EndTime = endTime;
	else
		QueryUserScoresOptions.EndTime = EOS_LEADERBOARDS_TIME_UNDEFINED;

	callback *mcallback = getCallbackData();

	EOS_Leaderboards_QueryLeaderboardUserScores(HLeaderboards, &QueryUserScoresOptions, mcallback, LeaderboardUserScoresReceivedCallbackFn);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}
