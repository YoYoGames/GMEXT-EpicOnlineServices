
// Connect Interface
// The Connect Interface handles connections between users' accounts under different identity providers.

// EOS_Connect_AddNotifyAuthExpiration
// EOS_Connect_AddNotifyLoginStatusChanged
// EOS_Connect_CopyIdToken
// EOS_Connect_CopyProductUserExternalAccountByAccountId
// EOS_Connect_CopyProductUserExternalAccountByAccountType
// EOS_Connect_CopyProductUserExternalAccountByIndex
// EOS_Connect_CopyProductUserInfo
// EOS_Connect_CreateDeviceId
// EOS_Connect_CreateUser
// EOS_Connect_DeleteDeviceId
// EOS_Connect_ExternalAccountInfo_Release
// EOS_Connect_GetExternalAccountMapping
// EOS_Connect_GetLoggedInUserByIndex
// EOS_Connect_GetLoggedInUsersCount
// EOS_Connect_GetLoginStatus
// EOS_Connect_GetProductUserExternalAccountCount
// EOS_Connect_GetProductUserIdMapping
// EOS_Connect_LinkAccount
// EOS_Connect_Login
// EOS_Connect_QueryExternalAccountMappings
// EOS_Connect_QueryProductUserIdMappings
// EOS_Connect_RemoveNotifyAuthExpiration
// EOS_Connect_RemoveNotifyLoginStatusChanged
// EOS_Connect_TransferDeviceIdAccount
// EOS_Connect_UnlinkAccount
// EOS_Connect_VerifyIdToken

#include "pch.h"
#include "YYEpicOnlineServices.h"

EOS_HConnect HConnect;
void eos_connect_init()
{
	HConnect = EOS_Platform_GetConnectInterface(PlatformHandle);
}

void EOS_CALL ConnectAuthExpirationCb(const EOS_Connect_AuthExpirationCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_connect_add_notify_auth_expiration");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void eos_connect_add_notify_auth_expiration(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_int64;

	EOS_Connect_AddNotifyAuthExpirationOptions Options{};
	Options.ApiVersion = EOS_CONNECT_ADDNOTIFYAUTHEXPIRATION_API_LATEST;
	EOS_NotificationId ConnectAuthExpirationId = EOS_Connect_AddNotifyAuthExpiration(HConnect, &Options, nullptr, ConnectAuthExpirationCb);

	Result.kind = VALUE_INT64;
	Result.v64 = static_cast<int64_t>(ConnectAuthExpirationId);
}

void EOS_CALL AddNotifyLoginStatusChangedCallback(const EOS_Connect_LoginStatusChangedCallbackInfo *data)
{

	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_connect_add_notify_login_status_changed");
	DsMapAddDouble(map, "current_status", (double)data->CurrentStatus);
	DsMapAddDouble(map, "previous_status", (double)data->PreviousStatus);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void eos_connect_add_notify_login_status_changed(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_int64;

	EOS_Connect_AddNotifyLoginStatusChangedOptions Options = {0};
	Options.ApiVersion = EOS_CONNECT_ADDNOTIFYLOGINSTATUSCHANGED_API_LATEST;

	EOS_NotificationId id = EOS_Connect_AddNotifyLoginStatusChanged(HConnect, &Options, NULL, AddNotifyLoginStatusChangedCallback);

	Result.kind = VALUE_INT64;
	Result.v64 = static_cast<int64_t>(id);
}

YYEXPORT void eos_connect_copy_id_token(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(1);

	const char *user = YYGetString(arg, 0);

	EOS_Connect_CopyIdTokenOptions Options = {0};
	Options.ApiVersion = EOS_CONNECT_COPYIDTOKEN_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);

	EOS_Connect_IdToken *IdToken = NULL;
	EOS_EResult result = EOS_Connect_CopyIdToken(HConnect, &Options, &IdToken);

	RValue Struct = {0};
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	if (result != EOS_EResult::EOS_Success)
	{
		COPY_RValue(&Result, &Struct);
		FREE_RValue(&Struct);
		return;
	}

	if (IdToken->JsonWebToken)
		YYStructAddString(&Struct, "json_web_token", IdToken->JsonWebToken);

	if (IdToken->ProductUserId)
		YYStructAddString(&Struct, "product_user_id", productID_toString(IdToken->ProductUserId));

	EOS_Connect_IdToken_Release(IdToken);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
	return;
}

RValue ExternalAccountInfoToStuct(EOS_Connect_ExternalAccountInfo *ExternalAccountInfo, EOS_EResult result)
{
	RValue Struct = {0};
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	if (result != EOS_EResult::EOS_Success)
		return Struct;

	if (ExternalAccountInfo->DisplayName)
		YYStructAddString(&Struct, "display_name", ExternalAccountInfo->DisplayName);

	if (ExternalAccountInfo->LastLoginTime)
		YYStructAddInt64(&Struct, "last_login_time", ExternalAccountInfo->LastLoginTime);

	if (ExternalAccountInfo->ProductUserId)
		YYStructAddString(&Struct, "user_id", productID_toString(ExternalAccountInfo->ProductUserId));

	if (ExternalAccountInfo->AccountId)
		YYStructAddString(&Struct, "account_id", ExternalAccountInfo->AccountId);

	// if (ExternalAccountInfo->AccountIdType)
	YYStructAddDouble(&Struct, "account_id_type", (double)ExternalAccountInfo->AccountIdType);

	if (ExternalAccountInfo->LastLoginTime)
		YYStructAddInt64(&Struct, "last_login_time", ExternalAccountInfo->LastLoginTime);

	EOS_Connect_ExternalAccountInfo_Release(ExternalAccountInfo);

	return Struct;
}

YYEXPORT void eos_connect_copy_product_user_external_account_by_account_id(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *target = YYGetString(arg, 1);

	EOS_Connect_CopyProductUserExternalAccountByAccountIdOptions Options = {0};
	Options.ApiVersion = EOS_CONNECT_COPYPRODUCTUSEREXTERNALACCOUNTBYACCOUNTID_API_LATEST;
	Options.AccountId = user;
	Options.TargetUserId = EOS_ProductUserId_FromString(target);

	EOS_Connect_ExternalAccountInfo *ExternalAccountInfo = NULL;
	EOS_EResult result = EOS_Connect_CopyProductUserExternalAccountByAccountId(HConnect, &Options, &ExternalAccountInfo);

	RValue Struct = ExternalAccountInfoToStuct(ExternalAccountInfo, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_connect_copy_product_user_external_account_by_account_type(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(2);

	const char *target = YYGetString(arg, 0);
	double accounttype = YYGetReal(arg, 1);

	EOS_Connect_CopyProductUserExternalAccountByAccountTypeOptions Options = {0};
	Options.ApiVersion = EOS_CONNECT_COPYPRODUCTUSEREXTERNALACCOUNTBYACCOUNTTYPE_API_LATEST;
	Options.TargetUserId = EOS_ProductUserId_FromString(target);
	Options.AccountIdType = (EOS_EExternalAccountType)accounttype;

	EOS_Connect_ExternalAccountInfo *ExternalAccountInfo = NULL;
	EOS_EResult result = EOS_Connect_CopyProductUserExternalAccountByAccountType(HConnect, &Options, &ExternalAccountInfo);

	RValue Struct = ExternalAccountInfoToStuct(ExternalAccountInfo, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_connect_copy_product_user_external_account_by_index(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(2);

	const char *target = YYGetString(arg, 0);
	uint32_t index = YYGetUint32(arg, 1);

	EOS_Connect_CopyProductUserExternalAccountByIndexOptions Options = {0};
	Options.ApiVersion = EOS_CONNECT_COPYPRODUCTUSEREXTERNALACCOUNTBYINDEX_API_LATEST;
	Options.ExternalAccountInfoIndex = index;
	Options.TargetUserId = EOS_ProductUserId_FromString(target);

	EOS_Connect_ExternalAccountInfo *ExternalAccountInfo = NULL;
	EOS_EResult result = EOS_Connect_CopyProductUserExternalAccountByIndex(HConnect, &Options, &ExternalAccountInfo);

	RValue Struct = ExternalAccountInfoToStuct(ExternalAccountInfo, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_connect_copy_product_user_info(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(1);

	const char *target = YYGetString(arg, 0);

	EOS_Connect_CopyProductUserInfoOptions Options = {0};
	Options.ApiVersion = EOS_CONNECT_COPYPRODUCTUSERINFO_API_LATEST;
	Options.TargetUserId = EOS_ProductUserId_FromString(target);

	EOS_Connect_ExternalAccountInfo *ExternalAccountInfo = NULL;
	EOS_EResult result = EOS_Connect_CopyProductUserInfo(HConnect, &Options, &ExternalAccountInfo);

	RValue Struct = ExternalAccountInfoToStuct(ExternalAccountInfo, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

void EOS_CALL CreateDeviceIdCallback(const EOS_Connect_CreateDeviceIdCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_connect_create_device_id");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_connect_create_device_id(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	const char *DeviceModel = YYGetString(arg, 0);

	EOS_Connect_CreateDeviceIdOptions Options = {0};
	Options.ApiVersion = EOS_CONNECT_CREATEDEVICEID_API_LATEST;
	Options.DeviceModel = DeviceModel;

	callback *mcallback = getCallbackData();

	EOS_Connect_CreateDeviceId(HConnect, &Options, mcallback, CreateDeviceIdCallback);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL ConnectCreateUserCompleteCb(const EOS_Connect_CreateUserCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_connect_create_user");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_connect_create_user(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	if (ContinuanceToken == nullptr)
	{
		DebugConsoleOutput("mContinuanceToken Error\n");
		return;
	}

	EOS_Connect_CreateUserOptions Options;
	Options.ApiVersion = EOS_CONNECT_CREATEUSER_API_LATEST;
	Options.ContinuanceToken = ContinuanceToken;

	callback *mcallback = getCallbackData();

	// NOTE: We're not deleting the received context because we're passing it down to another SDK call
	EOS_Connect_CreateUser(HConnect, &Options, mcallback, ConnectCreateUserCompleteCb);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL DeleteCreateUserCompleteCb(const EOS_Connect_DeleteDeviceIdCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_connect_create_user");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_connect_delete_device_id(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	EOS_Connect_DeleteDeviceIdOptions Options;
	Options.ApiVersion = EOS_CONNECT_DELETEDEVICEID_API_LATEST;

	callback *mcallback = getCallbackData();

	// NOTE: We're not deleting the received context because we're passing it down to another SDK call
	EOS_Connect_DeleteDeviceId(HConnect, &Options, mcallback, DeleteCreateUserCompleteCb);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

YYEXPORT void eos_connect_get_external_account_mapping(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_string

		eos_ensure_argc(3);

	const char *LocalUserId = YYGetString(arg, 0);
	const char *TargetExternalUserId = YYGetString(arg, 1);
	double AccountIdType = YYGetReal(arg, 2);

	EOS_Connect_GetExternalAccountMappingsOptions Options = {};
	Options.ApiVersion = EOS_CONNECT_GETEXTERNALACCOUNTMAPPINGS_API_LATEST;
	Options.AccountIdType = (EOS_EExternalAccountType)AccountIdType;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.TargetExternalUserId = TargetExternalUserId; // EOS_EExternalAccountType::EOS_EAT_EPIC

	EOS_ProductUserId NewMapping = EOS_Connect_GetExternalAccountMapping(HConnect, &Options);
	YYCreateString(&Result, productID_toString(NewMapping));
}

YYEXPORT void eos_connect_get_logged_in_user_by_index(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_bool;

	eos_ensure_argc(1);

	int32_t index = YYGetInt32(arg, 0);
	EOS_ProductUserId ProductUserId = EOS_Connect_GetLoggedInUserByIndex(HConnect, index);
}

YYEXPORT void eos_connect_get_logged_in_users_count(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_bool;

	uint32_t NumAccounts = EOS_Connect_GetLoggedInUsersCount(HConnect);
}

YYEXPORT void eos_connect_get_login_status(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_bool;

	eos_ensure_argc(1);

	const char *user = YYGetString(arg, 0);
	EOS_ELoginStatus LoginStatus = EOS_Connect_GetLoginStatus(HConnect, EOS_ProductUserId_FromString(user));
}

YYEXPORT void eos_connect_get_product_user_external_account_count(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_int32;

	eos_ensure_argc(1);

	const char *target = YYGetString(arg, 0);

	EOS_Connect_GetProductUserExternalAccountCountOptions Options = {0};
	Options.ApiVersion = EOS_CONNECT_GETPRODUCTUSEREXTERNALACCOUNTCOUNT_API_LATEST;
	Options.TargetUserId = EOS_ProductUserId_FromString(target);

	Result.kind = VALUE_INT32;
	Result.v32 = EOS_Connect_GetProductUserExternalAccountCount(HConnect, &Options);
}

YYEXPORT void eos_connect_get_product_user_id_mapping(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_bool;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *target = YYGetString(arg, 1);

	EOS_Connect_GetProductUserIdMappingOptions Options = {};
	Options.ApiVersion = EOS_CONNECT_GETEXTERNALACCOUNTMAPPINGS_API_LATEST;
	Options.AccountIdType = EOS_EExternalAccountType::EOS_EAT_EPIC;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);
	Options.TargetProductUserId = EOS_ProductUserId_FromString(target);

	char Buffer[EOS_CONNECT_EXTERNAL_ACCOUNT_ID_MAX_LENGTH];
	int32_t IDStringSize = EOS_CONNECT_EXTERNAL_ACCOUNT_ID_MAX_LENGTH;
	EOS_EResult MappingResult = EOS_Connect_GetProductUserIdMapping(HConnect, &Options, Buffer, &IDStringSize);
}

void EOS_CALL LinkAccount(const EOS_Connect_LinkAccountCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_connect_link_account");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_connect_link_account(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	const char *user = YYGetString(arg, 0);

	EOS_Connect_LinkAccountOptions Options = {0};
	Options.ApiVersion = EOS_CONNECT_LINKACCOUNT_API_LATEST;
	Options.ContinuanceToken = ContinuanceToken;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);

	callback *mcallback = getCallbackData();

	EOS_Connect_LinkAccount(HConnect, &Options, mcallback, LinkAccount);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL ConnectLoginCompleteCb(const EOS_Connect_LoginCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_connect_login");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

	if (data->ContinuanceToken)
		ContinuanceToken = data->ContinuanceToken;

	if (data->ResultCode == EOS_EResult::EOS_Success)
	{
		static char TempBuffer[EOS_PRODUCTUSERID_MAX_LENGTH + 1];
		int32_t TempBufferSize = sizeof(TempBuffer);
		EOS_EResult Result = EOS_ProductUserId_ToString(data->LocalUserId, TempBuffer, &TempBufferSize);

		DsMapAddString(map, "local_user_id", TempBuffer);
	}

	g_pYYRunnerInterface->CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_connect_login(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	int32_t type = YYGetInt32(arg, 0);
	const char *AccessToken = YYGetString(arg, 1);
	const char *DisplayName = argc < 3 ? nullptr : YYGetString(arg, 2);

	EOS_Connect_Credentials Credentials;
	Credentials.ApiVersion = EOS_CONNECT_CREDENTIALS_API_LATEST;
	Credentials.Token = AccessToken;
	Credentials.Type = (EOS_EExternalCredentialType)type; // EOS_EExternalCredentialType::EOS_ECT_EPIC;

	EOS_Connect_LoginOptions Options = {0};
	Options.ApiVersion = EOS_CONNECT_LOGIN_API_LATEST;
	Options.Credentials = &Credentials;

	if (DisplayName && *DisplayName) // not null or empty
	{
		EOS_Connect_UserLoginInfo UserLoginInfo = {0};
		UserLoginInfo.ApiVersion = EOS_CONNECT_USERLOGININFO_API_LATEST;
		UserLoginInfo.DisplayName = DisplayName;
		Options.UserLoginInfo = &UserLoginInfo;
	}

	callback *mcallback = getCallbackData();
	// assert(HConnect != nullptr);
	EOS_Connect_Login(HConnect, &Options, mcallback, ConnectLoginCompleteCb);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL OnQueryExternalAccountMappingsCallback(const EOS_Connect_QueryExternalAccountMappingsCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_connect_query_external_account_mappings");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback*>(data->ClientData);
}

std::vector<std::string> userIds;

YYEXPORT void eos_connect_query_external_account_mappings(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real

		const char *userID = YYGetString(arg, 0);
	int accountIdType = (int)YYGetReal(arg, 1);

	auto vec_Users = _SW_GetArrayOfStrings(arg, 2, "eos_connect_query_external_account_mappings");

	userIds.clear();
	userIds.reserve(vec_Users.size());
	for (auto user : vec_Users) {
		userIds.push_back(user);
	}
	std::vector<const char*> cstrs;
	for (const auto& id : userIds) {
		cstrs.push_back(id.c_str());
	}

    EOS_Connect_QueryExternalAccountMappingsOptions QueryOptions{};
	QueryOptions.ApiVersion = EOS_CONNECT_QUERYEXTERNALACCOUNTMAPPINGS_API_LATEST;
	QueryOptions.AccountIdType = (EOS_EExternalAccountType)accountIdType; // EOS_EExternalAccountType // ::EOS_EAT_EPIC;
	QueryOptions.LocalUserId = EOS_ProductUserId_FromString(userID);

	QueryOptions.ExternalAccountIdCount = (uint32_t)cstrs.size();
	QueryOptions.ExternalAccountIds = cstrs.data();

	EOS_HConnect ConnectHandle = EOS_Platform_GetConnectInterface(PlatformHandle);

	callback* mcallback = getCallbackData();
	EOS_Connect_QueryExternalAccountMappings(ConnectHandle, &QueryOptions, mcallback, OnQueryExternalAccountMappingsCallback);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL OnQueryAccountMappingsCallback(const EOS_Connect_QueryProductUserIdMappingsCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_connect_query_product_user_id_mappings");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_connect_query_product_user_id_mappings(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	std::cout << "EXT eos_connect_query_product_user_id_mappings" << std::endl;
	eos_not_init_return_rvalue_real

		const char *user = YYGetString(arg, 0);
	std::vector<EOS_ProductUserId> productUserIds = _SW_GetArrayOfProductUserId(arg, 1, "eos_connect_query_product_user_id_mappings");

	EOS_Connect_QueryProductUserIdMappingsOptions QueryOptions = {};
	QueryOptions.ApiVersion = EOS_CONNECT_QUERYPRODUCTUSERIDMAPPINGS_API_LATEST;
	QueryOptions.LocalUserId = EOS_ProductUserId_FromString(user);

	QueryOptions.ProductUserIdCount = (uint32_t)productUserIds.size();
	QueryOptions.ProductUserIds = productUserIds.data();

	EOS_HConnect ConnectHandle = EOS_Platform_GetConnectInterface(PlatformHandle);

	callback *mcallback = getCallbackData();

	EOS_Connect_QueryProductUserIdMappings(ConnectHandle, &QueryOptions, mcallback, OnQueryAccountMappingsCallback);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

YYEXPORT void eos_connect_remove_notify_auth_expiration(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_bool;

	eos_ensure_argc(1);

	int64 ConnectAuthExpirationId = YYGetInt64(arg, 0);
	EOS_Connect_RemoveNotifyAuthExpiration(HConnect, ConnectAuthExpirationId);
}

YYEXPORT void eos_connect_remove_notify_login_status_changed(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_bool;

	eos_ensure_argc(1);

	int64 RemoveNotifyLoginStatusChangedId = YYGetInt64(arg, 0);
	EOS_Connect_RemoveNotifyLoginStatusChanged(HConnect, RemoveNotifyLoginStatusChangedId);
}

void EOS_CALL TransferDeviceIdAccount(const EOS_Connect_TransferDeviceIdAccountCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_connect_transfer_device_id_account");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_connect_transfer_device_id_account(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(3);

	const char *LocalDeviceUserId = YYGetString(arg, 0);
	const char *PrimaryLocalUserId = YYGetString(arg, 1);
	const char *ProductUserIdToPreserve = YYGetString(arg, 2);

	EOS_Connect_TransferDeviceIdAccountOptions Options = {0};
	Options.ApiVersion = EOS_CONNECT_TRANSFERDEVICEIDACCOUNT_API_LATEST;
	Options.LocalDeviceUserId = EOS_ProductUserId_FromString(LocalDeviceUserId);
	Options.PrimaryLocalUserId = EOS_ProductUserId_FromString(PrimaryLocalUserId);
	Options.ProductUserIdToPreserve = EOS_ProductUserId_FromString(ProductUserIdToPreserve);

	callback *mcallback = getCallbackData();

	EOS_Connect_TransferDeviceIdAccount(HConnect, &Options, mcallback, TransferDeviceIdAccount);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL UnlinkAccount(const EOS_Connect_UnlinkAccountCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_connect_unlink_account");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_connect_unlink_account(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	const char *user = YYGetString(arg, 0);

	EOS_Connect_UnlinkAccountOptions Options = {0};
	Options.ApiVersion = EOS_CONNECT_VERIFYIDTOKEN_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);

	callback *mcallback = getCallbackData();

	EOS_Connect_UnlinkAccount(HConnect, &Options, mcallback, UnlinkAccount);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL VerifyIdToken(const EOS_Connect_VerifyIdTokenCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_connect_verify_id_token");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "account_id", data->AccountId);
	DsMapAddDouble(map, "account_id_type", (double)data->AccountIdType);
	DsMapAddBool(map, "is_account_info_present", data->bIsAccountInfoPresent);
	// DsMapAddDouble(map, "device_type", (double)data->DeviceType);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_connect_verify_id_token(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *JsonWebToken = YYGetString(arg, 1);

	EOS_Connect_IdToken IdToken = {0};
	IdToken.JsonWebToken = JsonWebToken;
	IdToken.ApiVersion = EOS_CONNECT_VERIFYIDTOKEN_API_LATEST;
	IdToken.ProductUserId = EOS_ProductUserId_FromString(user);

	EOS_Connect_VerifyIdTokenOptions Options = {0};
	Options.ApiVersion = EOS_CONNECT_VERIFYIDTOKEN_API_LATEST;
	Options.IdToken = &IdToken;

	callback *mcallback = getCallbackData();

	EOS_Connect_VerifyIdToken(HConnect, &Options, mcallback, VerifyIdToken);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}
