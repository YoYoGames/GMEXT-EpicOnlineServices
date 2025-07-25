
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

//EOS_HAchievements HAchievements;
//void EpicGames_Achievements_Init()
//{
//	HAchievements = EOS_Platform_GetAchievementsInterface(PlatformHandle);
//}

void EOS_CALL AchievementsUnlockedReceivedCallbackFn_old(const EOS_Achievements_OnAchievementsUnlockedCallbackV2Info* data)
{
	static char TempBuffer[EOS_PRODUCTUSERID_MAX_LENGTH + 1];
	int32_t TempBufferSize = sizeof(TempBuffer);
	EOS_EResult Result = EOS_ProductUserId_ToString(data->UserId, TempBuffer, &TempBufferSize);

	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Achievements_AddNotifyAchievementsUnlockedV2");
	DsMapAddInt64(map, "UnlockTime", data->UnlockTime);
	DsMapAddString(map, "AchievementId", data->AchievementId);
	DsMapAddString(map, "UserId", TempBuffer);

	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Achievements_AddNotifyAchievementsUnlockedV2(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	eos_not_init_return_rvalue_int64;

	EOS_Achievements_AddNotifyAchievementsUnlockedV2Options AchievementsUnlockedNotifyOptions = {};
	AchievementsUnlockedNotifyOptions.ApiVersion = EOS_ACHIEVEMENTS_ADDNOTIFYACHIEVEMENTSUNLOCKEDV2_API_LATEST;
	EOS_NotificationId AchievementsUnlockedNotificationId = EOS_Achievements_AddNotifyAchievementsUnlockedV2(HAchievements, &AchievementsUnlockedNotifyOptions, nullptr, AchievementsUnlockedReceivedCallbackFn_old);

	Result.kind = VALUE_INT64;
	Result.v64 = static_cast<int64_t>(AchievementsUnlockedNotificationId);
}


RValue EOS_Achievements_DefinitionV2ToMap_old(EOS_Achievements_DefinitionV2* AchievementDef, EOS_EResult result)
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

	RValue StatThresholds{};
	
	YYCreateArray(&StatThresholds);
	for (uint32_t StatIndex = 0; StatIndex < AchievementDef->StatThresholdsCount; ++StatIndex)
	{
		RValue StatThreshold{};
		YYStructCreate(&StatThreshold);

		const auto& thresholds = AchievementDef->StatThresholds[StatIndex];

		YYStructAddString(&Struct, "name", thresholds.Name);
		YYStructAddInt32(&Struct, "threshold", thresholds.Threshold);

		SET_RValue(&StatThresholds, &StatThreshold, NULL, StatIndex);
	}
	YYStructAddRValue(&Struct, "stat_thresholds", &StatThresholds);

	EOS_Achievements_DefinitionV2_Release(AchievementDef);

	return Struct;
}

YYEXPORT void EpicGames_Achievements_CopyAchievementDefinitionV2ByAchievementId(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(1);

	const char* AchievementId = YYGetString(arg, 0);

	EOS_Achievements_CopyAchievementDefinitionV2ByAchievementIdOptions CopyOptions = {};
	CopyOptions.ApiVersion = EOS_ACHIEVEMENTS_COPYDEFINITIONV2BYACHIEVEMENTID_API_LATEST;
	CopyOptions.AchievementId = AchievementId;

	EOS_Achievements_DefinitionV2* AchievementDef = NULL;
	EOS_EResult CopyAchievementDefinitionsResult = EOS_Achievements_CopyAchievementDefinitionV2ByAchievementId(HAchievements, &CopyOptions, &AchievementDef);

	RValue Struct = EOS_Achievements_DefinitionV2ToMap_old(AchievementDef, CopyAchievementDefinitionsResult);
	
	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void EpicGames_Achievements_CopyAchievementDefinitionV2ByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(1);

	double AchievementId = YYGetReal(arg, 0);

	EOS_Achievements_CopyAchievementDefinitionV2ByIndexOptions CopyOptions = {};
	CopyOptions.ApiVersion = EOS_ACHIEVEMENTS_COPYDEFINITIONV2BYACHIEVEMENTID_API_LATEST;
	CopyOptions.AchievementIndex = (int) AchievementId;

	int map_achievement = CreateDsMap(0,0);
	Result.kind = VALUE_REAL;
	Result.val = map_achievement;

	EOS_Achievements_DefinitionV2* AchievementDef = NULL;
	EOS_EResult CopyAchievementDefinitionsResult = EOS_Achievements_CopyAchievementDefinitionV2ByIndex(HAchievements, &CopyOptions, &AchievementDef);

	RValue Struct = EOS_Achievements_DefinitionV2ToMap_old(AchievementDef, CopyAchievementDefinitionsResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

RValue PlayerAchievementToMap_old(EOS_Achievements_PlayerAchievement* AchievementDef, EOS_EResult result)
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

	RValue stats = { 0 };
	YYCreateArray(&stats);

	for (int i = 0; i < AchievementDef->StatInfoCount; i++) {
		auto value = AchievementDef->StatInfo[i];

		RValue statInfo = { 0 };
		YYStructCreate(&statInfo);

		YYStructAddString(&statInfo, "Name", value.Name);
		YYStructAddInt32(&statInfo, "ApiVersion", value.ApiVersion);
		YYStructAddInt32(&statInfo, "CurrentValue", value.CurrentValue);
		YYStructAddInt32(&statInfo, "ThresholdValue", value.ThresholdValue);

		SET_RValue(&stats, &statInfo, NULL, i);
	}
	YYStructAddRValue(&Struct, "StatInfo", &stats);

	if (AchievementDef->StatInfoCount)
		YYStructAddInt32(&Struct, "StatInfoCount", AchievementDef->StatInfoCount);

	if (AchievementDef->UnlockTime)
		YYStructAddInt64(&Struct, "UnlockTime", AchievementDef->UnlockTime);

	// Release
	EOS_Achievements_PlayerAchievement_Release(AchievementDef);

	return Struct;
}

YYEXPORT void EpicGames_Achievements_CopyPlayerAchievementByAchievementId(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(3);

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

	RValue Struct = PlayerAchievementToMap_old(Achievement, CopyAchievementResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void EpicGames_Achievements_CopyPlayerAchievementByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(3);

	const char* local = YYGetString(arg, 0);
	const char* target = YYGetString(arg, 1);
	uint32_t index = YYGetUint32(arg, 2);

	EOS_Achievements_CopyPlayerAchievementByIndexOptions CopyOptions = {};
	CopyOptions.ApiVersion = EOS_ACHIEVEMENTS_COPYPLAYERACHIEVEMENTBYINDEX_API_LATEST;
	CopyOptions.LocalUserId = EOS_ProductUserId_FromString(local);
	CopyOptions.TargetUserId = EOS_ProductUserId_FromString(target);
	CopyOptions.AchievementIndex = index;

	EOS_Achievements_PlayerAchievement* Achievement = NULL;
	EOS_EResult CopyAchievementResult = EOS_Achievements_CopyPlayerAchievementByIndex(HAchievements, &CopyOptions, &Achievement);

	RValue Struct = PlayerAchievementToMap_old(Achievement, CopyAchievementResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void EpicGames_Achievements_GetAchievementDefinitionCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	eos_not_init_return_rvalue_int32;

	EOS_Achievements_GetAchievementDefinitionCountOptions AchievementDefinitionsCountOptions = {};
	AchievementDefinitionsCountOptions.ApiVersion = EOS_ACHIEVEMENTS_GETACHIEVEMENTDEFINITIONCOUNT_API_LATEST;

	Result.kind = VALUE_INT32;
	Result.v32 = EOS_Achievements_GetAchievementDefinitionCount(HAchievements, &AchievementDefinitionsCountOptions);
}

YYEXPORT void EpicGames_Achievements_GetPlayerAchievementCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	eos_not_init_return_rvalue_int32;

	eos_ensure_argc(1);

	const char* mProductUserId = YYGetString(arg, 0);

	EOS_Achievements_GetPlayerAchievementCountOptions AchievementsCountOptions = {};
	AchievementsCountOptions.ApiVersion = EOS_ACHIEVEMENTS_GETPLAYERACHIEVEMENTCOUNT_API_LATEST;
	AchievementsCountOptions.UserId = EOS_ProductUserId_FromString(mProductUserId);

	Result.kind = VALUE_INT32;
	Result.v32 = EOS_Achievements_GetPlayerAchievementCount(HAchievements, &AchievementsCountOptions);
}

void EOS_CALL AchievementDefinitionsReceivedCallbackFn_old(const EOS_Achievements_OnQueryDefinitionsCompleteCallbackInfo* data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Achievements_QueryDefinitions");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback*>(data->ClientData);
}
YYEXPORT void EpicGames_Achievements_QueryDefinitions(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	eos_not_init_return_rvalue_string;

	eos_ensure_argc(1);

	const char* mProductUserId = YYGetString(arg, 0);

	EOS_Achievements_QueryDefinitionsOptions QueryDefinitionsOptions = {};
	QueryDefinitionsOptions.ApiVersion = EOS_ACHIEVEMENTS_QUERYDEFINITIONS_API_LATEST;

	QueryDefinitionsOptions.LocalUserId = EOS_ProductUserId_FromString(mProductUserId);

	callback* mcallback = getCallbackData();

	EOS_Achievements_QueryDefinitions(HAchievements, &QueryDefinitionsOptions, mcallback, AchievementDefinitionsReceivedCallbackFn_old);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL PlayerAchievementsReceivedCallbackFn_old(const EOS_Achievements_OnQueryPlayerAchievementsCompleteCallbackInfo* data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Achievements_QueryPlayerAchievements");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback*>(data->ClientData);
}

YYEXPORT void EpicGames_Achievements_QueryPlayerAchievements(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char* mProductUserId = YYGetString(arg, 0);
	const char* targetUserID = YYGetString(arg, 1);

	EOS_Achievements_QueryPlayerAchievementsOptions QueryPlayerAchievementsOptions = {};
	QueryPlayerAchievementsOptions.ApiVersion = EOS_ACHIEVEMENTS_QUERYPLAYERACHIEVEMENTS_API_LATEST;
	QueryPlayerAchievementsOptions.LocalUserId = EOS_ProductUserId_FromString(mProductUserId);
	QueryPlayerAchievementsOptions.TargetUserId = EOS_ProductUserId_FromString(targetUserID);

	callback* mcallback = getCallbackData();

	EOS_Achievements_QueryPlayerAchievements(HAchievements, &QueryPlayerAchievementsOptions, mcallback, PlayerAchievementsReceivedCallbackFn_old);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL UnlockAchievementsReceivedCallbackFn_old(const EOS_Achievements_OnUnlockAchievementsCompleteCallbackInfo* data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Achievements_UnlockAchievement");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback*>(data->ClientData);
}

//EOS_Achievements_UnlockAchievements
YYEXPORT void EpicGames_Achievements_UnlockAchievement(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char* mProductUserId = YYGetString(arg, 0);
	const char* AchievementId = YYGetString(arg, 1);

	EOS_Achievements_UnlockAchievementsOptions UnlockAchievementsOptions = {};
	UnlockAchievementsOptions.ApiVersion = EOS_ACHIEVEMENTS_UNLOCKACHIEVEMENTS_API_LATEST;
	UnlockAchievementsOptions.UserId = EOS_ProductUserId_FromString(mProductUserId);
	UnlockAchievementsOptions.AchievementsCount = 1;
	UnlockAchievementsOptions.AchievementIds = new const char* [1];
	UnlockAchievementsOptions.AchievementIds[0] = AchievementId;//NarrowIDs[0].c_str();

	callback* mcallback = getCallbackData();

	EOS_Achievements_UnlockAchievements(HAchievements, &UnlockAchievementsOptions, mcallback, UnlockAchievementsReceivedCallbackFn_old);

	//delete[] UnlockAchievementsOptions.AchievementIds;	

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}


YYEXPORT void EpicGames_Achievements_RemoveNotifyAchievementsUnlocked(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	eos_not_init_return_rvalue_bool;

	eos_ensure_argc(1);

	int64 AchievementsUnlockedNotificationId = YYGetInt64(arg, 0);

	EOS_Achievements_RemoveNotifyAchievementsUnlocked(HAchievements, AchievementsUnlockedNotificationId);
	AchievementsUnlockedNotificationId = EOS_INVALID_NOTIFICATIONID;

	Result.kind = VALUE_BOOL;
	Result.val = true;
}
