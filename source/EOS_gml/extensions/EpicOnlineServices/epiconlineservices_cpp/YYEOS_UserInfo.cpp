
// EOS_UserInfo_CopyExternalUserInfoByAccountId
// EOS_UserInfo_CopyExternalUserInfoByAccountType
// EOS_UserInfo_CopyExternalUserInfoByIndex
// EOS_UserInfo_CopyUserInfo
// EOS_UserInfo_GetExternalUserInfoCount
// EOS_UserInfo_QueryUserInfo
// EOS_UserInfo_QueryUserInfoByDisplayName
// EOS_UserInfo_QueryUserInfoByExternalAccount

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include <eos_userinfo.h>

EOS_HUserInfo HUserInfo;
void eos_user_info_init()
{
	HUserInfo = EOS_Platform_GetUserInfoInterface(PlatformHandle);
}

RValue ExternalUserInfoToString(EOS_UserInfo_ExternalUserInfo *UserInfo, EOS_EResult Result)
{
	RValue Struct = {0};
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)Result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(Result));

	if (Result != EOS_EResult::EOS_Success)
		return Struct;

	if (UserInfo->DisplayName)
		YYStructAddString(&Struct, "display_name", UserInfo->DisplayName);

	if (UserInfo->AccountId)
		YYStructAddString(&Struct, "account_id", UserInfo->AccountId);

	YYStructAddDouble(&Struct, "account_type", (double)UserInfo->AccountType);

	// if (UserInfo->ApiVersion)
	//	YYStructAddDouble(&Struct, "api_version", UserInfo->ApiVersion);

	EOS_UserInfo_ExternalUserInfo_Release(UserInfo);

	return Struct;
}

YYEXPORT void eos_user_info_copy_external_user_info_by_account_id(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(3);

	const char *user = YYGetString(arg, 0);
	const char *target = YYGetString(arg, 1);
	const char *accountId = YYGetString(arg, 2);

	EOS_UserInfo_CopyExternalUserInfoByAccountIdOptions ExternalUserInfoOptions = {};
	ExternalUserInfoOptions.ApiVersion = EOS_USERINFO_COPYEXTERNALUSERINFOBYACCOUNTID_API_LATEST;
	ExternalUserInfoOptions.LocalUserId = EOS_EpicAccountId_FromString(user);
	ExternalUserInfoOptions.TargetUserId = EOS_EpicAccountId_FromString(target);
	ExternalUserInfoOptions.AccountId = accountId;

	EOS_UserInfo_ExternalUserInfo *OutExternalUserInfo = nullptr;
	EOS_EResult CopyResult = EOS_UserInfo_CopyExternalUserInfoByAccountId(HUserInfo, &ExternalUserInfoOptions, &OutExternalUserInfo);

	RValue Struct = ExternalUserInfoToString(OutExternalUserInfo, CopyResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_user_info_copy_external_user_info_by_account_type(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(3);

	const char *user = YYGetString(arg, 0);
	const char *target = YYGetString(arg, 1);
	double accountType = YYGetReal(arg, 2);

	EOS_UserInfo_CopyExternalUserInfoByAccountTypeOptions ExternalUserInfoOptions = {};
	ExternalUserInfoOptions.ApiVersion = EOS_USERINFO_COPYEXTERNALUSERINFOBYACCOUNTTYPE_API_LATEST;
	ExternalUserInfoOptions.LocalUserId = EOS_EpicAccountId_FromString(user);
	ExternalUserInfoOptions.TargetUserId = EOS_EpicAccountId_FromString(target);
	ExternalUserInfoOptions.AccountType = (EOS_EExternalAccountType)accountType;

	EOS_UserInfo_ExternalUserInfo *OutExternalUserInfo = nullptr;
	EOS_EResult CopyResult = EOS_UserInfo_CopyExternalUserInfoByAccountType(HUserInfo, &ExternalUserInfoOptions, &OutExternalUserInfo);

	RValue Struct = ExternalUserInfoToString(OutExternalUserInfo, CopyResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_user_info_copy_external_user_info_by_index(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(3);

	const char *user = YYGetString(arg, 0);
	const char *target = YYGetString(arg, 1);
	uint32_t index = YYGetUint32(arg, 2);

	EOS_UserInfo_CopyExternalUserInfoByIndexOptions ExternalUserInfoOptions = {};
	ExternalUserInfoOptions.ApiVersion = EOS_USERINFO_COPYEXTERNALUSERINFOBYINDEX_API_LATEST;
	ExternalUserInfoOptions.LocalUserId = EOS_EpicAccountId_FromString(user);
	ExternalUserInfoOptions.TargetUserId = EOS_EpicAccountId_FromString(target);
	ExternalUserInfoOptions.Index = index;

	EOS_UserInfo_ExternalUserInfo *OutExternalUserInfo = nullptr;
	EOS_EResult CopyResult = EOS_UserInfo_CopyExternalUserInfoByIndex(HUserInfo, &ExternalUserInfoOptions, &OutExternalUserInfo);

	RValue Struct = ExternalUserInfoToString(OutExternalUserInfo, CopyResult);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

RValue _UserInfoToString(EOS_UserInfo *UserInfo, EOS_EResult Result)
{
	RValue Struct = {0};
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)Result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(Result));

	if (Result != EOS_EResult::EOS_Success)
		return Struct;

	if (UserInfo->DisplayName)
		YYStructAddString(&Struct, "display_name", UserInfo->DisplayName);

	if (UserInfo->Country)
		YYStructAddString(&Struct, "country", UserInfo->Country);

	if (UserInfo->Nickname)
		YYStructAddString(&Struct, "nickname", UserInfo->Nickname);

	if (UserInfo->PreferredLanguage)
		YYStructAddString(&Struct, "preferred_language", UserInfo->PreferredLanguage);

	if (UserInfo->UserId)
		YYStructAddString(&Struct, "account_i_d", AccountID_toString(UserInfo->UserId));

	EOS_UserInfo_Release(UserInfo);

	return Struct;
}

YYEXPORT void eos_user_info_copy_user_info(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *target = YYGetString(arg, 1);

	EOS_HUserInfo UserInfoInterface = EOS_Platform_GetUserInfoInterface(PlatformHandle);
	EOS_UserInfo_CopyUserInfoOptions Options;
	Options.ApiVersion = EOS_FRIENDS_QUERYFRIENDS_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.TargetUserId = EOS_EpicAccountId_FromString(target);

	EOS_UserInfo *UserInfo = nullptr;
	EOS_EResult result = EOS_UserInfo_CopyUserInfo(UserInfoInterface, &Options, &UserInfo);

	RValue Struct = _UserInfoToString(UserInfo, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_user_info_get_external_user_info_count(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_int32;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *target = YYGetString(arg, 1);

	EOS_UserInfo_GetExternalUserInfoCountOptions Options = {};
	Options.ApiVersion = EOS_USERINFO_GETEXTERNALUSERINFOCOUNT_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.TargetUserId = EOS_EpicAccountId_FromString(target);

	uint32_t count = EOS_UserInfo_GetExternalUserInfoCount(HUserInfo, &Options);

	Result.kind = VALUE_INT32;
	Result.v32 = (int32)count;
}

void EOS_CALL userInfo_QueryUserInfoCallback(const EOS_UserInfo_QueryUserInfoCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_user_info_query_user_info");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "target", AccountID_toString(data->TargetUserId));
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_user_info_query_user_info(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char *mProductUserId = YYGetString(arg, 0);
	const char *targetUserID = YYGetString(arg, 1);

	EOS_UserInfo_QueryUserInfoOptions queryUserInfoOptions = {0};
	queryUserInfoOptions.ApiVersion = EOS_USERINFO_QUERYUSERINFO_API_LATEST;
	queryUserInfoOptions.LocalUserId = EOS_EpicAccountId_FromString(mProductUserId);
	queryUserInfoOptions.TargetUserId = EOS_EpicAccountId_FromString(targetUserID);

	callback *mcallback = getCallbackData();

	EOS_UserInfo_QueryUserInfo(HUserInfo, &queryUserInfoOptions, mcallback, userInfo_QueryUserInfoCallback);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL EOS_UserInfo_QueryUserInfoByDisplayNameCallback(const EOS_UserInfo_QueryUserInfoByDisplayNameCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_user_info_query_user_info_by_display_name");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_user_info_query_user_info_by_display_name(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
//(EOS_EpicAccountId LocalUserId, const std::wstring& DisplayName, const EOS_UserInfo_OnQueryUserInfoByDisplayNameCallback CompletionDelegate, std::function<void(const FUserData&)> UserInfoRetrievedCallback)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char *mProductUserId = YYGetString(arg, 0);
	const char *DisplayName = YYGetString(arg, 1);

	EOS_UserInfo_QueryUserInfoByDisplayNameOptions QueryUserInfoOptions = {};
	QueryUserInfoOptions.ApiVersion = EOS_USERINFO_QUERYUSERINFOBYDISPLAYNAME_API_LATEST;
	QueryUserInfoOptions.LocalUserId = EOS_EpicAccountId_FromString(mProductUserId);
	QueryUserInfoOptions.DisplayName = DisplayName;

	callback *mcallback = getCallbackData();

	EOS_UserInfo_QueryUserInfoByDisplayName(HUserInfo, &QueryUserInfoOptions, mcallback, EOS_UserInfo_QueryUserInfoByDisplayNameCallback);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL EOS_UserInfo_QueryUserInfoByExternalAccountCallback(const EOS_UserInfo_QueryUserInfoByExternalAccountCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_user_info_query_user_info_by_external_account");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_user_info_query_user_info_by_external_account(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(3);

	const char *user = YYGetString(arg, 0);
	const char *ExternalAccountId = YYGetString(arg, 1);
	double accountType = YYGetReal(arg, 2);

	EOS_UserInfo_QueryUserInfoByExternalAccountOptions Options = {0};
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.AccountType = (EOS_EExternalAccountType)accountType;
	Options.ExternalAccountId = ExternalAccountId;
	Options.ApiVersion = EOS_USERINFO_QUERYUSERINFOBYEXTERNALACCOUNT_API_LATEST;

	callback *mcallback = getCallbackData();

	EOS_UserInfo_QueryUserInfoByExternalAccount(HUserInfo, &Options, mcallback, EOS_UserInfo_QueryUserInfoByExternalAccountCallback);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}
