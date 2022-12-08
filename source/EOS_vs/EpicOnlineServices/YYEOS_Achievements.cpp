
//Achievements Interface
//Interface for checkingand unlocking achievements on a user - by - user basis.


//1  EOS_Achievements_AddNotifyAchievementsUnlockedV2
//2  EOS_Achievements_CopyAchievementDefinitionV2ByAchievementId
//3  EOS_Achievements_CopyAchievementDefinitionV2ByIndex
//4  EOS_Achievements_CopyPlayerAchievementByAchievementId
//5  EOS_Achievements_CopyPlayerAchievementByIndex
//6  EOS_Achievements_GetAchievementDefinitionCount
//7  EOS_Achievements_GetPlayerAchievementCount
//8  EOS_Achievements_QueryDefinitions
//9  EOS_Achievements_QueryPlayerAchievements
//10 EOS_Achievements_RemoveNotifyAchievementsUnlocked
//11 EOS_Achievements_UnlockAchievements


#include "pch.h"
#include "YYEpicOnlineServices.h"
#include <eos_achievements.h>
#include <vector>

EOS_HAchievements HAchievements;
void EpicGames_Achievements_Init()
{
	HAchievements = EOS_Platform_GetAchievementsInterface(PlatformHandle);
}

void EOS_CALL AchievementsUnlockedReceivedCallbackFn(const EOS_Achievements_OnAchievementsUnlockedCallbackV2Info* Data)
{
	static char TempBuffer[EOS_PRODUCTUSERID_MAX_LENGTH + 1];
	int32_t TempBufferSize = sizeof(TempBuffer);
	EOS_EResult Result = EOS_ProductUserId_ToString(Data->UserId, TempBuffer, &TempBufferSize);

	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Achievements_AddNotifyAchievementsUnlockedV2");
	DsMapAddInt64(map, "UnlockTime", Data->UnlockTime);
	DsMapAddString(map, "AchievementId", Data->AchievementId);
	DsMapAddString(map, "UserId", TempBuffer);

	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Achievements_AddNotifyAchievementsUnlockedV2(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_BOOL

	EOS_Achievements_AddNotifyAchievementsUnlockedV2Options AchievementsUnlockedNotifyOptions = {};
	AchievementsUnlockedNotifyOptions.ApiVersion = EOS_ACHIEVEMENTS_ADDNOTIFYACHIEVEMENTSUNLOCKEDV2_API_LATEST;
	EOS_NotificationId AchievementsUnlockedNotificationId = EOS_Achievements_AddNotifyAchievementsUnlockedV2(HAchievements, &AchievementsUnlockedNotifyOptions, nullptr, AchievementsUnlockedReceivedCallbackFn);

	Result.kind = VALUE_INT64;
	Result.val = AchievementsUnlockedNotificationId;
}


RValue EOS_Achievements_DefinitionV2ToMap(EOS_Achievements_DefinitionV2* AchievementDef, EOS_EResult result)
{
	RValue Struct = { 0 };
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	if (result != EOS_EResult::EOS_Success)
		return Struct;

	
	YYStructAddString(&Struct, "AchievementId", AchievementDef->AchievementId);

	if (AchievementDef->bIsHidden)
		YYStructAddDouble(&Struct, "bIsHidden", (double)AchievementDef->bIsHidden);

	if (AchievementDef->UnlockedDisplayName)
		YYStructAddString(&Struct, "UnlockedDisplayName", AchievementDef->UnlockedDisplayName);

	if (AchievementDef->UnlockedDescription)
		YYStructAddString(&Struct, "UnlockedDescription", AchievementDef->UnlockedDescription);

	if (AchievementDef->LockedDisplayName)
		YYStructAddString(&Struct, "LockedDisplayName", AchievementDef->LockedDisplayName);

	if (AchievementDef->LockedDescription)
		YYStructAddString(&Struct, "LockedDescription", AchievementDef->LockedDescription);

	if (AchievementDef->FlavorText)
		YYStructAddString(&Struct, "FlavorText", AchievementDef->FlavorText);

	if (AchievementDef->UnlockedIconURL)
		YYStructAddString(&Struct, "UnlockedIconURL", AchievementDef->UnlockedIconURL);

	if (AchievementDef->LockedIconURL)
		YYStructAddString(&Struct, "LockedIconURL", AchievementDef->LockedIconURL);

	for (uint32_t StatIndex = 0; StatIndex < AchievementDef->StatThresholdsCount; ++StatIndex)
	{
		//TODO
		AchievementDef->StatThresholds[StatIndex].Name;
		AchievementDef->StatThresholds[StatIndex].Threshold;
		//StatInfo.emplace_back(StatInfo);
	}

	EOS_Achievements_DefinitionV2_Release(AchievementDef);

	return Struct;
}

YYEXPORT void EpicGames_Achievements_CopyAchievementDefinitionV2ByAchievementId(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_STRUCT

	const char* AchievementId = YYGetString(arg, 0);

	EOS_Achievements_CopyAchievementDefinitionV2ByAchievementIdOptions CopyOptions = {};
	CopyOptions.ApiVersion = EOS_ACHIEVEMENTS_COPYDEFINITIONV2BYACHIEVEMENTID_API_LATEST;
	CopyOptions.AchievementId = AchievementId;

	EOS_Achievements_DefinitionV2* AchievementDef = NULL;
	EOS_EResult CopyAchievementDefinitionsResult = EOS_Achievements_CopyAchievementDefinitionV2ByAchievementId(HAchievements, &CopyOptions, &AchievementDef);

	RValue Struct = EOS_Achievements_DefinitionV2ToMap(AchievementDef, CopyAchievementDefinitionsResult);
	
	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void EpicGames_Achievements_CopyAchievementDefinitionV2ByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_STRUCT

	double AchievementId = YYGetReal(arg, 0);

	EOS_Achievements_CopyAchievementDefinitionV2ByIndexOptions CopyOptions = {};
	CopyOptions.ApiVersion = EOS_ACHIEVEMENTS_COPYDEFINITIONV2BYACHIEVEMENTID_API_LATEST;
	CopyOptions.AchievementIndex = (int) AchievementId;

	int map_achievement = CreateDsMap(0,0);
	Result.kind = VALUE_REAL;
	Result.val = map_achievement;

	EOS_Achievements_DefinitionV2* AchievementDef = NULL;
	EOS_EResult CopyAchievementDefinitionsResult = EOS_Achievements_CopyAchievementDefinitionV2ByIndex(HAchievements, &CopyOptions, &AchievementDef);

	RValue Struct = EOS_Achievements_DefinitionV2ToMap(AchievementDef, CopyAchievementDefinitionsResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

RValue PlayerAchievementToMap(EOS_Achievements_PlayerAchievement* AchievementDef, EOS_EResult result)
{
	RValue Struct = { 0 };
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	if (result != EOS_EResult::EOS_Success)
		return Struct;

	if(AchievementDef->AchievementId)
		YYStructAddString(&Struct, "AchievementId", AchievementDef->AchievementId);

	//if(AchievementDef->ApiVersion)
	//	DsMapAddInt64(map_achievement, "ApiVersion", (int64)AchievementDef->ApiVersion);

	if (AchievementDef->Description)
		YYStructAddString(&Struct, "Description", AchievementDef->Description);

	if (AchievementDef->DisplayName)
		YYStructAddString(&Struct, "DisplayName", AchievementDef->DisplayName);

	if (AchievementDef->FlavorText)
		YYStructAddString(&Struct, "FlavorText", AchievementDef->FlavorText);

	if (AchievementDef->IconURL)
		YYStructAddString(&Struct, "IconURL", AchievementDef->IconURL);

	if (AchievementDef->Progress)
		YYStructAddDouble(&Struct, "Progress", AchievementDef->Progress);

	//TODO
	//if (AchievementDef->StatInfo)
	//	DsMapAddString(map_achievement, "StatInfo", AchievementDef->StatInfo->);//is an struct check it ...

	//if (AchievementDef->StatInfoCount)
	//	DsMapAddInt64(map_achievement, "StatInfoCount",(int64) AchievementDef->StatInfoCount);

	if (AchievementDef->UnlockTime)
		YYStructAddDouble(&Struct, "UnlockTime", (double)AchievementDef->UnlockTime);

	// Release
	EOS_Achievements_PlayerAchievement_Release(AchievementDef);

	return Struct;
}

YYEXPORT void EpicGames_Achievements_CopyPlayerAchievementByAchievementId(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_STRUCT

	const char* local = YYGetString(arg, 0);
	const char* target = YYGetString(arg, 1);
	const char* AchievementId = YYGetString(arg, 2);

	EOS_Achievements_CopyPlayerAchievementByAchievementIdOptions CopyOptions = {0};
	CopyOptions.ApiVersion = EOS_ACHIEVEMENTS_COPYPLAYERACHIEVEMENTBYACHIEVEMENTID_API_LATEST;
	CopyOptions.LocalUserId = EOS_ProductUserId_FromString(local);
	CopyOptions.TargetUserId = EOS_ProductUserId_FromString(target);
	CopyOptions.AchievementId = AchievementId;

	EOS_Achievements_PlayerAchievement* Achievement = NULL;
	EOS_EResult CopyAchievementResult = EOS_Achievements_CopyPlayerAchievementByAchievementId(HAchievements, &CopyOptions, &Achievement);

	RValue Struct = PlayerAchievementToMap(Achievement, CopyAchievementResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void EpicGames_Achievements_CopyPlayerAchievementByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_STRUCT

	const char* local = YYGetString(arg, 0);
	const char* target = YYGetString(arg, 1);
	double index = YYGetReal(arg, 2);

	EOS_Achievements_CopyPlayerAchievementByIndexOptions CopyOptions = {};
	CopyOptions.ApiVersion = EOS_ACHIEVEMENTS_COPYPLAYERACHIEVEMENTBYINDEX_API_LATEST;
	CopyOptions.LocalUserId = EOS_ProductUserId_FromString(local);
	CopyOptions.TargetUserId = EOS_ProductUserId_FromString(target);
	CopyOptions.AchievementIndex = (double)index;

	EOS_Achievements_PlayerAchievement* Achievement = NULL;
	EOS_EResult CopyAchievementResult = EOS_Achievements_CopyPlayerAchievementByIndex(HAchievements, &CopyOptions, &Achievement);

	RValue Struct = PlayerAchievementToMap(Achievement, CopyAchievementResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void EpicGames_Achievements_GetAchievementDefinitionCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_INT32

	EOS_Achievements_GetAchievementDefinitionCountOptions AchievementDefinitionsCountOptions = {};
	AchievementDefinitionsCountOptions.ApiVersion = EOS_ACHIEVEMENTS_GETACHIEVEMENTDEFINITIONCOUNT_API_LATEST;

	Result.kind = VALUE_INT32;
	Result.v32 = EOS_Achievements_GetAchievementDefinitionCount(HAchievements, &AchievementDefinitionsCountOptions);
}

YYEXPORT void EpicGames_Achievements_GetPlayerAchievementCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_INT32

	const char* mProductUserId = YYGetString(arg, 0);

	EOS_Achievements_GetPlayerAchievementCountOptions AchievementsCountOptions = {};
	AchievementsCountOptions.ApiVersion = EOS_ACHIEVEMENTS_GETPLAYERACHIEVEMENTCOUNT_API_LATEST;
	AchievementsCountOptions.UserId = EOS_ProductUserId_FromString(mProductUserId);

	Result.kind = VALUE_INT32;
	Result.v32 = EOS_Achievements_GetPlayerAchievementCount(HAchievements, &AchievementsCountOptions);
}

void EOS_CALL AchievementDefinitionsReceivedCallbackFn(const EOS_Achievements_OnQueryDefinitionsCompleteCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Achievements_QueryDefinitions");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}
YYEXPORT void EpicGames_Achievements_QueryDefinitions(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_STRING

	const char* mProductUserId = YYGetString(arg, 0);

	EOS_Achievements_QueryDefinitionsOptions QueryDefinitionsOptions = {};
	QueryDefinitionsOptions.ApiVersion = EOS_ACHIEVEMENTS_QUERYDEFINITIONS_API_LATEST;

	QueryDefinitionsOptions.LocalUserId = EOS_ProductUserId_FromString(mProductUserId);

	callback* mcallback = getCallbackData();

	EOS_Achievements_QueryDefinitions(HAchievements, &QueryDefinitionsOptions, mcallback, AchievementDefinitionsReceivedCallbackFn);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL PlayerAchievementsReceivedCallbackFn(const EOS_Achievements_OnQueryPlayerAchievementsCompleteCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Achievements_QueryPlayerAchievements");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Achievements_QueryPlayerAchievements(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	const char* mProductUserId = YYGetString(arg, 0);
	const char* targetUserID = YYGetString(arg, 1);

	EOS_Achievements_QueryPlayerAchievementsOptions QueryPlayerAchievementsOptions = {};
	QueryPlayerAchievementsOptions.ApiVersion = EOS_ACHIEVEMENTS_QUERYPLAYERACHIEVEMENTS_API_LATEST;
	QueryPlayerAchievementsOptions.LocalUserId = EOS_ProductUserId_FromString(mProductUserId);
	QueryPlayerAchievementsOptions.TargetUserId = EOS_ProductUserId_FromString(targetUserID);

	callback* mcallback = getCallbackData();

	EOS_Achievements_QueryPlayerAchievements(HAchievements, &QueryPlayerAchievementsOptions, mcallback, PlayerAchievementsReceivedCallbackFn);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL UnlockAchievementsReceivedCallbackFn(const EOS_Achievements_OnUnlockAchievementsCompleteCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Achievements_UnlockAchievement");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

//EOS_Achievements_UnlockAchievements
YYEXPORT void EpicGames_Achievements_UnlockAchievement(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	const char* mProductUserId = YYGetString(arg, 0);
	const char* AchievementId = YYGetString(arg, 1);

	EOS_Achievements_UnlockAchievementsOptions UnlockAchievementsOptions = {};
	UnlockAchievementsOptions.ApiVersion = EOS_ACHIEVEMENTS_UNLOCKACHIEVEMENTS_API_LATEST;
	UnlockAchievementsOptions.UserId = EOS_ProductUserId_FromString(mProductUserId);
	UnlockAchievementsOptions.AchievementsCount = 1;
	UnlockAchievementsOptions.AchievementIds = new const char* [1];
	UnlockAchievementsOptions.AchievementIds[0] = AchievementId;//NarrowIDs[0].c_str();

	callback* mcallback = getCallbackData();

	EOS_Achievements_UnlockAchievements(HAchievements, &UnlockAchievementsOptions, mcallback, UnlockAchievementsReceivedCallbackFn);

	//delete[] UnlockAchievementsOptions.AchievementIds;	

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}


YYEXPORT void EpicGames_Achievements_RemoveNotifyAchievementsUnlocked(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_BOOL

	int64 AchievementsUnlockedNotificationId = YYGetInt64(arg, 0);

	EOS_Achievements_RemoveNotifyAchievementsUnlocked(HAchievements, AchievementsUnlockedNotificationId);
	AchievementsUnlockedNotificationId = EOS_INVALID_NOTIFICATIONID;

	Result.kind = VALUE_BOOL;
	Result.val = true;
}
