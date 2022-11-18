
//Leaderboards Interface
//Interface to handle online leaderboards

//EOS_Leaderboards_CopyLeaderboardDefinitionByIndex
//EOS_Leaderboards_CopyLeaderboardDefinitionByLeaderboardId
//EOS_Leaderboards_CopyLeaderboardRecordByIndex
//EOS_Leaderboards_CopyLeaderboardRecordByUserId
//EOS_Leaderboards_CopyLeaderboardUserScoreByIndex
//EOS_Leaderboards_CopyLeaderboardUserScoreByUserId
//EOS_Leaderboards_GetLeaderboardDefinitionCount
//EOS_Leaderboards_GetLeaderboardRecordCount
//EOS_Leaderboards_GetLeaderboardUserScoreCount
//EOS_Leaderboards_QueryLeaderboardDefinitions
//EOS_Leaderboards_QueryLeaderboardRanks
//EOS_Leaderboards_QueryLeaderboardUserScores

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include <eos_leaderboards.h>

EOS_HLeaderboards HLeaderboards;
void EpicGames_Leaderboards_Init()
{
	HLeaderboards = EOS_Platform_GetLeaderboardsInterface(PlatformHandle);
}

RValue LeaderboardsDefinitionToStruct(EOS_Leaderboards_Definition* leaderboard, EOS_EResult result)
{
	RValue Struct = { 0 };
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	if (result != EOS_EResult::EOS_Success)
		return Struct;

	if (leaderboard->LeaderboardId)
		YYStructAddString(&Struct, "LeaderboardId", leaderboard->LeaderboardId);

	if (leaderboard->StatName)
		YYStructAddString(&Struct, "StatName", leaderboard->StatName);

	if (leaderboard->StartTime)
		YYStructAddDouble(&Struct, "StartTime", leaderboard->StartTime);

	if (leaderboard->EndTime)
		YYStructAddDouble(&Struct, "EndTime", leaderboard->EndTime);

	EOS_Leaderboards_Definition_Release(leaderboard);

	return Struct;
}

YYEXPORT void EpicGames_Leaderboards_CopyLeaderboardDefinitionByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	double index = YYGetReal(arg, 0);

	EOS_Leaderboards_Definition* LeaderboardDef = NULL;

	EOS_Leaderboards_CopyLeaderboardDefinitionByIndexOptions CopyOptions = { 0 };
	CopyOptions.ApiVersion = EOS_LEADERBOARDS_COPYLEADERBOARDDEFINITIONBYINDEX_API_LATEST;
	CopyOptions.LeaderboardIndex = index;

	EOS_EResult CopyLeaderboardDefinitionsResult = EOS_Leaderboards_CopyLeaderboardDefinitionByIndex(HLeaderboards, &CopyOptions, &LeaderboardDef);

	RValue Struct = LeaderboardsDefinitionToStruct(LeaderboardDef, CopyLeaderboardDefinitionsResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void EpicGames_Leaderboards_CopyLeaderboardDefinitionByLeaderboardId(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	const char* leaderboardId = YYGetString(arg, 0);

	EOS_Leaderboards_Definition* LeaderboardDef = NULL;

	EOS_Leaderboards_CopyLeaderboardDefinitionByLeaderboardIdOptions CopyOptions = { 0 };
	CopyOptions.ApiVersion = EOS_LEADERBOARDS_COPYLEADERBOARDDEFINITIONBYLEADERBOARDID_API_LATEST;
	CopyOptions.LeaderboardId = leaderboardId;

	EOS_EResult CopyLeaderboardDefinitionsResult = EOS_Leaderboards_CopyLeaderboardDefinitionByLeaderboardId(HLeaderboards, &CopyOptions, &LeaderboardDef);

	RValue Struct = LeaderboardsDefinitionToStruct(LeaderboardDef, CopyLeaderboardDefinitionsResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

RValue LeaderboardRecordToStruct(EOS_Leaderboards_LeaderboardRecord* leaderboard, EOS_EResult result)
{
	RValue Struct = { 0 };
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	if (result != EOS_EResult::EOS_Success)
		return Struct;
	
	static char TempBuffer[EOS_PRODUCTUSERID_MAX_LENGTH + 1];
	int32_t TempBufferSize = sizeof(TempBuffer);
	EOS_EResult Result = EOS_ProductUserId_ToString(leaderboard->UserId, TempBuffer, &TempBufferSize);

	YYStructAddString(&Struct, "UserId", TempBuffer);
	YYStructAddDouble(&Struct, "Rank", leaderboard->Rank = leaderboard->Rank);
	YYStructAddDouble(&Struct, "Score", leaderboard->Score = leaderboard->Score);
	YYStructAddString(&Struct, "UserDisplayName", leaderboard->UserDisplayName);

	EOS_Leaderboards_LeaderboardRecord_Release(leaderboard);

	return Struct;
}

YYEXPORT void EpicGames_Leaderboards_CopyLeaderboardRecordByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	double index = YYGetReal(arg, 0);

	EOS_Leaderboards_GetLeaderboardRecordCountOptions LeaderboardsRecordsCountOptions = { 0 };
	LeaderboardsRecordsCountOptions.ApiVersion = EOS_LEADERBOARDS_GETLEADERBOARDRECORDCOUNT_API_LATEST;

	uint32_t LeaderboardRecordsCount = EOS_Leaderboards_GetLeaderboardRecordCount(HLeaderboards, &LeaderboardsRecordsCountOptions);

	EOS_Leaderboards_CopyLeaderboardRecordByIndexOptions CopyOptions = { 0 };
	CopyOptions.ApiVersion = EOS_LEADERBOARDS_COPYLEADERBOARDRECORDBYINDEX_API_LATEST;
	CopyOptions.LeaderboardRecordIndex = index;
		
	EOS_Leaderboards_LeaderboardRecord* LeaderboardRecord = NULL;
	EOS_EResult CopyLeaderboardRecordResult = EOS_Leaderboards_CopyLeaderboardRecordByIndex(HLeaderboards, &CopyOptions, &LeaderboardRecord);

	RValue Struct = LeaderboardRecordToStruct(LeaderboardRecord, CopyLeaderboardRecordResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void EpicGames_Leaderboards_CopyLeaderboardRecordByUserId(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	const char* userId = YYGetString(arg, 0);

	EOS_Leaderboards_GetLeaderboardRecordCountOptions LeaderboardsRecordsCountOptions = { 0 };
	LeaderboardsRecordsCountOptions.ApiVersion = EOS_LEADERBOARDS_GETLEADERBOARDRECORDCOUNT_API_LATEST;

	uint32_t LeaderboardRecordsCount = EOS_Leaderboards_GetLeaderboardRecordCount(HLeaderboards, &LeaderboardsRecordsCountOptions);

	EOS_Leaderboards_CopyLeaderboardRecordByUserIdOptions CopyOptions = { 0 };
	CopyOptions.ApiVersion = EOS_LEADERBOARDS_COPYLEADERBOARDRECORDBYUSERID_API_LATEST;
	CopyOptions.UserId = EOS_ProductUserId_FromString(userId);

	EOS_Leaderboards_LeaderboardRecord* LeaderboardRecord = NULL;
	EOS_EResult CopyLeaderboardRecordResult = EOS_Leaderboards_CopyLeaderboardRecordByUserId(HLeaderboards, &CopyOptions, &LeaderboardRecord);

	RValue Struct = LeaderboardRecordToStruct(LeaderboardRecord, CopyLeaderboardRecordResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

RValue LeaderboardUserScoreToStruct(EOS_Leaderboards_LeaderboardUserScore* leaderboard, EOS_EResult result)
{
	RValue Struct = { 0 };
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	if (result != EOS_EResult::EOS_Success)
		return Struct;

	YYStructAddString(&Struct, "UserId", productID_toString(leaderboard->UserId));
	YYStructAddDouble(&Struct, "Score", leaderboard->Score);
	
	EOS_Leaderboards_LeaderboardUserScore_Release(leaderboard);

	return Struct;
}

YYEXPORT void EpicGames_Leaderboards_CopyLeaderboardUserScoreByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	double index = YYGetReal(arg, 0);
	const char* statName = YYGetString(arg, 1);

	EOS_Leaderboards_CopyLeaderboardUserScoreByIndexOptions CopyOptions = { 0 };
	CopyOptions.ApiVersion = EOS_LEADERBOARDS_COPYLEADERBOARDUSERSCOREBYINDEX_API_LATEST;
	CopyOptions.StatName = statName;

	CopyOptions.LeaderboardUserScoreIndex = index;

	EOS_Leaderboards_LeaderboardUserScore* LeaderboardUserScore = NULL;
	EOS_EResult CopyLeaderboardUserScoreResult = EOS_Leaderboards_CopyLeaderboardUserScoreByIndex(HLeaderboards, &CopyOptions, &LeaderboardUserScore);

	RValue Struct = LeaderboardUserScoreToStruct(LeaderboardUserScore, CopyLeaderboardUserScoreResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void EpicGames_Leaderboards_CopyLeaderboardUserScoreByUserId(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	const char* userId = YYGetString(arg, 0);
	const char* statName = YYGetString(arg, 1);

	EOS_Leaderboards_CopyLeaderboardUserScoreByUserIdOptions CopyOptions = { 0 };
	CopyOptions.ApiVersion = EOS_LEADERBOARDS_COPYLEADERBOARDUSERSCOREBYUSERID_API_LATEST;
	CopyOptions.StatName = statName;
	CopyOptions.UserId = EOS_ProductUserId_FromString(userId);

	EOS_Leaderboards_LeaderboardUserScore* LeaderboardUserScore = NULL;
	EOS_EResult CopyLeaderboardUserScoreResult = EOS_Leaderboards_CopyLeaderboardUserScoreByUserId(HLeaderboards, &CopyOptions, &LeaderboardUserScore);

	RValue Struct = LeaderboardUserScoreToStruct(LeaderboardUserScore, CopyLeaderboardUserScoreResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void EpicGames_Leaderboards_GetLeaderboardDefinitionCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_Leaderboards_GetLeaderboardDefinitionCountOptions LeaderboardDefinitionsCountOptions = { 0 };
	LeaderboardDefinitionsCountOptions.ApiVersion = EOS_LEADERBOARDS_GETLEADERBOARDDEFINITIONCOUNT_API_LATEST;

	uint32_t LeaderboardDefinitionsCount = EOS_Leaderboards_GetLeaderboardDefinitionCount(HLeaderboards, &LeaderboardDefinitionsCountOptions);

	Result.kind = VALUE_INT32;
	Result.v32 = (int32)LeaderboardDefinitionsCount;
}

YYEXPORT void EpicGames_Leaderboards_GetLeaderboardRecordCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_Leaderboards_GetLeaderboardRecordCountOptions LeaderboardsRecordsCountOptions = { 0 };
	LeaderboardsRecordsCountOptions.ApiVersion = EOS_LEADERBOARDS_GETLEADERBOARDRECORDCOUNT_API_LATEST;

	uint32_t LeaderboardRecordsCount = EOS_Leaderboards_GetLeaderboardRecordCount(HLeaderboards, &LeaderboardsRecordsCountOptions);

	Result.kind = VALUE_INT32;
	Result.v32 = (int32)LeaderboardRecordsCount;
}

YYEXPORT void EpicGames_Leaderboards_GetLeaderboardUserScoreCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	const char* statName = YYGetString(arg, 0);

	EOS_Leaderboards_GetLeaderboardUserScoreCountOptions LeaderboardUserScoresCountOptions = { 0 };
	LeaderboardUserScoresCountOptions.ApiVersion = EOS_LEADERBOARDS_GETLEADERBOARDUSERSCORECOUNT_API_LATEST;
	LeaderboardUserScoresCountOptions.StatName = statName;

	Result.kind = VALUE_INT32;
	Result.v32 = EOS_Leaderboards_GetLeaderboardUserScoreCount(HLeaderboards, &LeaderboardUserScoresCountOptions);
}

void EOS_CALL LeaderboardDefinitionsReceivedCallbackFn(const EOS_Leaderboards_OnQueryLeaderboardDefinitionsCompleteCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Leaderboards_QueryLeaderboardDefinitions");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Leaderboards_QueryLeaderboardDefinitions(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	const char* mProductUserId = YYGetString(arg, 0);
	int64 startTime = YYGetInt64(arg, 1);
	int64 endTime = YYGetInt64(arg, 2);

	EOS_Leaderboards_QueryLeaderboardDefinitionsOptions QueryDefinitionsOptions = { 0 };
	QueryDefinitionsOptions.ApiVersion = EOS_LEADERBOARDS_QUERYLEADERBOARDDEFINITIONS_API_LATEST;
	
	if(startTime > 0)
		QueryDefinitionsOptions.StartTime = startTime;
	else
		QueryDefinitionsOptions.StartTime = EOS_LEADERBOARDS_TIME_UNDEFINED;

	if(endTime > 0)
		QueryDefinitionsOptions.EndTime = endTime;
	else
		QueryDefinitionsOptions.EndTime = EOS_LEADERBOARDS_TIME_UNDEFINED;

	QueryDefinitionsOptions.LocalUserId = EOS_ProductUserId_FromString(mProductUserId);

	callback* mcallback = getCallbackData();

	EOS_Leaderboards_QueryLeaderboardDefinitions(HLeaderboards, &QueryDefinitionsOptions, mcallback, LeaderboardDefinitionsReceivedCallbackFn);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL LeaderboardRanksReceivedCallbackFn(const EOS_Leaderboards_OnQueryLeaderboardRanksCompleteCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Leaderboards_QueryLeaderboardRanks");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);

	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Leaderboards_QueryLeaderboardRanks(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	const char* LocalUserId = YYGetString(arg, 0);
	const char* LeaderboardId = YYGetString(arg, 1);

	EOS_Leaderboards_QueryLeaderboardRanksOptions QueryRanksOptions = { 0 };
	QueryRanksOptions.ApiVersion = EOS_LEADERBOARDS_QUERYLEADERBOARDRANKS_API_LATEST;
	QueryRanksOptions.LeaderboardId = LeaderboardId;
	QueryRanksOptions.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);

	callback* mcallback = getCallbackData();

	EOS_Leaderboards_QueryLeaderboardRanks(HLeaderboards, &QueryRanksOptions, mcallback, LeaderboardRanksReceivedCallbackFn);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL LeaderboardUserScoresReceivedCallbackFn(const EOS_Leaderboards_OnQueryLeaderboardUserScoresCompleteCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Leaderboards_QueryLeaderboardUserScores");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);

	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Leaderboards_QueryLeaderboardUserScore(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	const char* userID = YYGetString(arg, 0);
	const char* userID_target = YYGetString(arg, 1);
	const char* LeaderboardId = YYGetString(arg, 2);
	const char* name = YYGetString(arg, 3);
	double agregation = YYGetReal(arg, 4);
	int64 startTime = YYGetInt64(arg, 5);
	int64 endTime = YYGetInt64(arg, 6);

	EOS_Leaderboards_QueryLeaderboardUserScoresOptions QueryUserScoresOptions = { 0 };
	QueryUserScoresOptions.LocalUserId = EOS_ProductUserId_FromString(userID);
	QueryUserScoresOptions.ApiVersion = EOS_LEADERBOARDS_QUERYLEADERBOARDUSERSCORES_API_LATEST;
	QueryUserScoresOptions.UserIdsCount = 1;
	EOS_ProductUserId* UserData = new EOS_ProductUserId[1];
	UserData[0] = EOS_ProductUserId_FromString(userID_target);
	QueryUserScoresOptions.UserIds = UserData;

	QueryUserScoresOptions.StatInfoCount = 1;
	EOS_Leaderboards_UserScoresQueryStatInfo* StatInfoData = new EOS_Leaderboards_UserScoresQueryStatInfo[1];
	StatInfoData[0].StatName = name;
	StatInfoData[0].Aggregation = (EOS_ELeaderboardAggregation)agregation;

	QueryUserScoresOptions.StatInfo = StatInfoData;

	if(startTime > 0)
		QueryUserScoresOptions.StartTime = startTime;
	else
		QueryUserScoresOptions.StartTime = EOS_LEADERBOARDS_TIME_UNDEFINED;

	if (endTime > 0)
		QueryUserScoresOptions.EndTime = endTime;
	else
		QueryUserScoresOptions.EndTime = EOS_LEADERBOARDS_TIME_UNDEFINED;
	
	callback* mcallback = getCallbackData();

	EOS_Leaderboards_QueryLeaderboardUserScores(HLeaderboards, &QueryUserScoresOptions, mcallback, LeaderboardUserScoresReceivedCallbackFn);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}
