
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
void eos_achievements_init()
{
	HAchievements = EOS_Platform_GetAchievementsInterface(PlatformHandle);
}

void EOS_CALL AchievementsUnlockedReceivedCallbackFn(const EOS_Achievements_OnAchievementsUnlockedCallbackV2Info* data)
{
	static char TempBuffer[EOS_PRODUCTUSERID_MAX_LENGTH + 1];
	int32_t TempBufferSize = sizeof(TempBuffer);
	EOS_EResult Result = EOS_ProductUserId_ToString(data->UserId, TempBuffer, &TempBufferSize);

	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "eos_achievements_add_notify_achievements_unlocked_v2");
	DsMapAddInt64(map, "unlock_time", data->UnlockTime);
	DsMapAddString(map, "achievement_id", data->AchievementId);
	DsMapAddString(map, "user_id", TempBuffer);

	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void eos_achievements_add_notify_achievements_unlocked_v2(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	eos_not_init_return_rvalue_int64;

	EOS_Achievements_AddNotifyAchievementsUnlockedV2Options AchievementsUnlockedNotifyOptions = {};
	AchievementsUnlockedNotifyOptions.ApiVersion = EOS_ACHIEVEMENTS_ADDNOTIFYACHIEVEMENTSUNLOCKEDV2_API_LATEST;
	EOS_NotificationId AchievementsUnlockedNotificationId = EOS_Achievements_AddNotifyAchievementsUnlockedV2(HAchievements, &AchievementsUnlockedNotifyOptions, nullptr, AchievementsUnlockedReceivedCallbackFn);

	Result.kind = VALUE_INT64;
	Result.v64 = static_cast<int64_t>(AchievementsUnlockedNotificationId);
}


RValue EOS_Achievements_DefinitionV2ToMap(EOS_Achievements_DefinitionV2* AchievementDef, EOS_EResult result)
{
	RValue Struct = { 0 };
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	if (result != EOS_EResult::EOS_Success)
		return Struct;

	
	YYStructAddString(&Struct, "achievement_id", AchievementDef->AchievementId);

	if (AchievementDef->bIsHidden)
		YYStructAddDouble(&Struct, "is_hidden", (double)AchievementDef->bIsHidden);

	if (AchievementDef->UnlockedDisplayName)
		YYStructAddString(&Struct, "unlocked_display_name", AchievementDef->UnlockedDisplayName);

	if (AchievementDef->UnlockedDescription)
		YYStructAddString(&Struct, "unlocked_description", AchievementDef->UnlockedDescription);

	if (AchievementDef->LockedDisplayName)
		YYStructAddString(&Struct, "locked_display_name", AchievementDef->LockedDisplayName);

	if (AchievementDef->LockedDescription)
		YYStructAddString(&Struct, "locked_description", AchievementDef->LockedDescription);

	if (AchievementDef->FlavorText)
		YYStructAddString(&Struct, "flavor_text", AchievementDef->FlavorText);

	if (AchievementDef->UnlockedIconURL)
		YYStructAddString(&Struct, "unlocked_icon_url", AchievementDef->UnlockedIconURL);

	if (AchievementDef->LockedIconURL)
		YYStructAddString(&Struct, "locked_icon_url", AchievementDef->LockedIconURL);

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

YYEXPORT void eos_achievements_copy_achievement_definition_v2_by_achievement_id(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(1);

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

YYEXPORT void eos_achievements_copy_achievement_definition_v2_by_index(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
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
		YYStructAddString(&Struct, "achievement_id", AchievementDef->AchievementId);

	//if(AchievementDef->ApiVersion)
	//	DsMapAddInt64(map_achievement, "api_version", (int64)AchievementDef->ApiVersion);

	if (AchievementDef->Description)
		YYStructAddString(&Struct, "description", AchievementDef->Description);

	if (AchievementDef->DisplayName)
		YYStructAddString(&Struct, "display_name", AchievementDef->DisplayName);

	if (AchievementDef->FlavorText)
		YYStructAddString(&Struct, "flavor_text", AchievementDef->FlavorText);

	if (AchievementDef->IconURL)
		YYStructAddString(&Struct, "icon_url", AchievementDef->IconURL);

	if (AchievementDef->Progress)
		YYStructAddDouble(&Struct, "progress", AchievementDef->Progress);

	RValue stats = { 0 };
	YYCreateArray(&stats);

	for (int i = 0; i < AchievementDef->StatInfoCount; i++) {
		auto value = AchievementDef->StatInfo[i];

		RValue statInfo = { 0 };
		YYStructCreate(&statInfo);

		YYStructAddString(&statInfo, "name", value.Name);
		YYStructAddInt32(&statInfo, "api_version", value.ApiVersion);
		YYStructAddInt32(&statInfo, "current_value", value.CurrentValue);
		YYStructAddInt32(&statInfo, "threshold_value", value.ThresholdValue);

		SET_RValue(&stats, &statInfo, NULL, i);
	}
	YYStructAddRValue(&Struct, "stat_info", &stats);

	if (AchievementDef->StatInfoCount)
		YYStructAddInt32(&Struct, "stat_info_count", AchievementDef->StatInfoCount);

	if (AchievementDef->UnlockTime)
		YYStructAddInt64(&Struct, "unlock_time", AchievementDef->UnlockTime);

	// Release
	EOS_Achievements_PlayerAchievement_Release(AchievementDef);

	return Struct;
}

YYEXPORT void eos_achievements_copy_player_achievement_by_achievement_id(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
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

	RValue Struct = PlayerAchievementToMap(Achievement, CopyAchievementResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_achievements_copy_player_achievement_by_index(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
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

	RValue Struct = PlayerAchievementToMap(Achievement, CopyAchievementResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_achievements_get_achievement_definition_count(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	eos_not_init_return_rvalue_int32;

	EOS_Achievements_GetAchievementDefinitionCountOptions AchievementDefinitionsCountOptions = {};
	AchievementDefinitionsCountOptions.ApiVersion = EOS_ACHIEVEMENTS_GETACHIEVEMENTDEFINITIONCOUNT_API_LATEST;

	Result.kind = VALUE_INT32;
	Result.v32 = EOS_Achievements_GetAchievementDefinitionCount(HAchievements, &AchievementDefinitionsCountOptions);
}

YYEXPORT void eos_achievements_get_player_achievement_count(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
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

void EOS_CALL AchievementDefinitionsReceivedCallbackFn(const EOS_Achievements_OnQueryDefinitionsCompleteCallbackInfo* data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "eos_achievements_query_definitions");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback*>(data->ClientData);
}
YYEXPORT void eos_achievements_query_definitions(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	eos_not_init_return_rvalue_string;

	eos_ensure_argc(1);

	const char* mProductUserId = YYGetString(arg, 0);

	EOS_Achievements_QueryDefinitionsOptions QueryDefinitionsOptions = {};
	QueryDefinitionsOptions.ApiVersion = EOS_ACHIEVEMENTS_QUERYDEFINITIONS_API_LATEST;

	QueryDefinitionsOptions.LocalUserId = EOS_ProductUserId_FromString(mProductUserId);

	callback* mcallback = getCallbackData();

	EOS_Achievements_QueryDefinitions(HAchievements, &QueryDefinitionsOptions, mcallback, AchievementDefinitionsReceivedCallbackFn);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL PlayerAchievementsReceivedCallbackFn(const EOS_Achievements_OnQueryPlayerAchievementsCompleteCallbackInfo* data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "eos_achievements_query_player_achievements");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback*>(data->ClientData);
}

YYEXPORT void eos_achievements_query_player_achievements(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
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

	EOS_Achievements_QueryPlayerAchievements(HAchievements, &QueryPlayerAchievementsOptions, mcallback, PlayerAchievementsReceivedCallbackFn);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL UnlockAchievementsReceivedCallbackFn(const EOS_Achievements_OnUnlockAchievementsCompleteCallbackInfo* data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "eos_achievements_unlock_achievement");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback*>(data->ClientData);
}

//EOS_Achievements_UnlockAchievements
YYEXPORT void eos_achievements_unlock_achievement(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
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

	EOS_Achievements_UnlockAchievements(HAchievements, &UnlockAchievementsOptions, mcallback, UnlockAchievementsReceivedCallbackFn);

	//delete[] UnlockAchievementsOptions.AchievementIds;	

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}


YYEXPORT void eos_achievements_remove_notify_achievements_unlocked(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	eos_not_init_return_rvalue_bool;

	eos_ensure_argc(1);

	int64 AchievementsUnlockedNotificationId = YYGetInt64(arg, 0);

	EOS_Achievements_RemoveNotifyAchievementsUnlocked(HAchievements, AchievementsUnlockedNotificationId);
	AchievementsUnlockedNotificationId = EOS_INVALID_NOTIFICATIONID;

	Result.kind = VALUE_BOOL;
	Result.val = true;
}
