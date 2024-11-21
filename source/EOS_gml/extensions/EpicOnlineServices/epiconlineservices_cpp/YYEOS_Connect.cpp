
//Connect Interface
//The Connect Interface handles connections between users' accounts under different identity providers.

//EOS_Connect_AddNotifyAuthExpiration
//EOS_Connect_AddNotifyLoginStatusChanged
//EOS_Connect_CopyIdToken
//EOS_Connect_CopyProductUserExternalAccountByAccountId
//EOS_Connect_CopyProductUserExternalAccountByAccountType
//EOS_Connect_CopyProductUserExternalAccountByIndex
//EOS_Connect_CopyProductUserInfo
//EOS_Connect_CreateDeviceId
//EOS_Connect_CreateUser
//EOS_Connect_DeleteDeviceId
//EOS_Connect_ExternalAccountInfo_Release
//EOS_Connect_GetExternalAccountMapping
//EOS_Connect_GetLoggedInUserByIndex
//EOS_Connect_GetLoggedInUsersCount
//EOS_Connect_GetLoginStatus
//EOS_Connect_GetProductUserExternalAccountCount
//EOS_Connect_GetProductUserIdMapping
//EOS_Connect_LinkAccount
//EOS_Connect_Login
//EOS_Connect_QueryExternalAccountMappings
//EOS_Connect_QueryProductUserIdMappings
//EOS_Connect_RemoveNotifyAuthExpiration
//EOS_Connect_RemoveNotifyLoginStatusChanged
//EOS_Connect_TransferDeviceIdAccount
//EOS_Connect_UnlinkAccount
//EOS_Connect_VerifyIdToken

#include "pch.h"
#include "YYEpicOnlineServices.h"

EOS_HConnect HConnect;
void EpicGames_Connect_Init()
{
	HConnect = EOS_Platform_GetConnectInterface(PlatformHandle);
}

void EOS_CALL ConnectAuthExpirationCb(const EOS_Connect_AuthExpirationCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Connect_AddNotifyAuthExpiration");
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Connect_AddNotifyAuthExpiration(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	EOS_Connect_AddNotifyAuthExpirationOptions Options{};
	Options.ApiVersion = EOS_CONNECT_ADDNOTIFYAUTHEXPIRATION_API_LATEST;

	callback* mcallback = getCallbackData();

	EOS_NotificationId ConnectAuthExpirationId = EOS_Connect_AddNotifyAuthExpiration(HConnect, &Options, mcallback, ConnectAuthExpirationCb);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL AddNotifyLoginStatusChangedCallback(const EOS_Connect_LoginStatusChangedCallbackInfo* Data)
{
	
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Connect_AddNotifyLoginStatusChanged");
	//DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddDouble(map, "CurrentStatus", (double)Data->CurrentStatus);
	DsMapAddDouble(map, "PreviousStatus", (double)Data->PreviousStatus);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Connect_AddNotifyLoginStatusChanged(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_INT64

	EOS_Connect_AddNotifyLoginStatusChangedOptions Options = { 0 };
	Options.ApiVersion = EOS_CONNECT_ADDNOTIFYLOGINSTATUSCHANGED_API_LATEST;

	EOS_NotificationId id = EOS_Connect_AddNotifyLoginStatusChanged(HConnect, &Options, NULL, AddNotifyLoginStatusChangedCallback);

	Result.kind = VALUE_INT64;
	Result.v64 = id;
}

YYEXPORT void EpicGames_Connect_CopyIdToken(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_STRUCT

	const char* user = YYGetString(arg, 0);

	EOS_Connect_CopyIdTokenOptions Options = { 0 };
	Options.ApiVersion = EOS_CONNECT_COPYIDTOKEN_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);

	EOS_Connect_IdToken* IdToken = NULL;
	EOS_EResult result = EOS_Connect_CopyIdToken(HConnect, &Options, &IdToken);

	RValue Struct = { 0 };
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
		YYStructAddString(&Struct, "JsonWebToken", IdToken->JsonWebToken);

	if (IdToken->ProductUserId)
		YYStructAddString(&Struct, "ProductUserId", productID_toString(IdToken->ProductUserId));
	
	EOS_Connect_IdToken_Release(IdToken);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
	return;
}

RValue ExternalAccountInfoToStuct(EOS_Connect_ExternalAccountInfo* ExternalAccountInfo, EOS_EResult result)
{
	RValue Struct = { 0 };
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	if (result != EOS_EResult::EOS_Success)
		return Struct;

	if (ExternalAccountInfo->DisplayName)
		YYStructAddString(&Struct, "DisplayName", ExternalAccountInfo->DisplayName);

	if (ExternalAccountInfo->LastLoginTime)
		YYStructAddDouble(&Struct, "LastLoginTime", ExternalAccountInfo->LastLoginTime);

	if (ExternalAccountInfo->ProductUserId)
		YYStructAddString(&Struct, "userID", productID_toString(ExternalAccountInfo->ProductUserId));

	if (ExternalAccountInfo->AccountId)
		YYStructAddString(&Struct, "AccountId", ExternalAccountInfo->AccountId);

	//if (ExternalAccountInfo->AccountIdType)
	YYStructAddDouble(&Struct, "AccountIdType", (double)ExternalAccountInfo->AccountIdType);

	if (ExternalAccountInfo->LastLoginTime)
		YYStructAddDouble(&Struct, "LastLoginTime", ExternalAccountInfo->LastLoginTime);

	EOS_Connect_ExternalAccountInfo_Release(ExternalAccountInfo);

	return Struct;
}

YYEXPORT void EpicGames_Connect_CopyProductUserExternalAccountByAccountId(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_STRUCT

	const char* user = YYGetString(arg, 0);
	const char* target = YYGetString(arg, 1);

	EOS_Connect_CopyProductUserExternalAccountByAccountIdOptions Options = { 0 };
	Options.ApiVersion = EOS_CONNECT_COPYPRODUCTUSEREXTERNALACCOUNTBYACCOUNTID_API_LATEST;
	Options.AccountId = user;
	Options.TargetUserId = EOS_ProductUserId_FromString(target);

	EOS_Connect_ExternalAccountInfo* ExternalAccountInfo = NULL;
	EOS_EResult result = EOS_Connect_CopyProductUserExternalAccountByAccountId(HConnect, &Options, &ExternalAccountInfo);

	RValue Struct = ExternalAccountInfoToStuct(ExternalAccountInfo,result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void EpicGames_Connect_CopyProductUserExternalAccountByAccountType(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_STRUCT

	const char* target = YYGetString(arg, 0);
	double accounttype = YYGetReal(arg, 1);

	EOS_Connect_CopyProductUserExternalAccountByAccountTypeOptions Options = { 0 };
	Options.ApiVersion = EOS_CONNECT_COPYPRODUCTUSEREXTERNALACCOUNTBYACCOUNTTYPE_API_LATEST;
	Options.TargetUserId = EOS_ProductUserId_FromString(target);
	Options.AccountIdType = (EOS_EExternalAccountType) accounttype;

	EOS_Connect_ExternalAccountInfo* ExternalAccountInfo = NULL;
	EOS_EResult result = EOS_Connect_CopyProductUserExternalAccountByAccountType(HConnect, &Options, &ExternalAccountInfo);

	RValue Struct = ExternalAccountInfoToStuct(ExternalAccountInfo, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void EpicGames_Connect_CopyProductUserExternalAccountByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_STRUCT

	const char* target = YYGetString(arg, 0);
	double index = YYGetReal(arg, 1);

	EOS_Connect_CopyProductUserExternalAccountByIndexOptions Options = { 0 };
	Options.ApiVersion = EOS_CONNECT_COPYPRODUCTUSEREXTERNALACCOUNTBYINDEX_API_LATEST;
	Options.ExternalAccountInfoIndex = index;
	Options.TargetUserId = EOS_ProductUserId_FromString(target);

	EOS_Connect_ExternalAccountInfo* ExternalAccountInfo = NULL;
	EOS_EResult result = EOS_Connect_CopyProductUserExternalAccountByIndex(HConnect, &Options, &ExternalAccountInfo);

	RValue Struct = ExternalAccountInfoToStuct(ExternalAccountInfo, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void EpicGames_Connect_CopyProductUserInfo(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_STRUCT

	const char* target = YYGetString(arg, 0);

	EOS_Connect_CopyProductUserInfoOptions Options = {0};
	Options.ApiVersion = EOS_CONNECT_COPYPRODUCTUSERINFO_API_LATEST;
	Options.TargetUserId = EOS_ProductUserId_FromString(target);

	EOS_Connect_ExternalAccountInfo* ExternalAccountInfo = NULL;
	EOS_EResult result = EOS_Connect_CopyProductUserInfo(HConnect, &Options, &ExternalAccountInfo);

	RValue Struct = ExternalAccountInfoToStuct(ExternalAccountInfo, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

void EOS_CALL CreateDeviceIdCallback(const EOS_Connect_CreateDeviceIdCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Connect_CreateDeviceId");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Connect_CreateDeviceId(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	const char* DeviceModel = YYGetString(arg, 0);
	
	EOS_Connect_CreateDeviceIdOptions Options = { 0 };
	Options.ApiVersion = EOS_CONNECT_CREATEDEVICEID_API_LATEST;
	Options.DeviceModel = DeviceModel;

	callback* mcallback = getCallbackData();

	EOS_Connect_CreateDeviceId(HConnect, &Options, mcallback, CreateDeviceIdCallback);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL ConnectCreateUserCompleteCb(const EOS_Connect_CreateUserCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Connect_CreateUser");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Connect_CreateUser(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	if (ContinuanceToken == nullptr)
	{
		DebugConsoleOutput("mContinuanceToken Error\n");
		return;
	}

	EOS_Connect_CreateUserOptions Options;
	Options.ApiVersion = EOS_CONNECT_CREATEUSER_API_LATEST;
	Options.ContinuanceToken = ContinuanceToken;

	callback* mcallback = getCallbackData();

	// NOTE: We're not deleting the received context because we're passing it down to another SDK call
	EOS_Connect_CreateUser(HConnect, &Options, mcallback, ConnectCreateUserCompleteCb);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL DeleteCreateUserCompleteCb(const EOS_Connect_DeleteDeviceIdCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Connect_CreateUser");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Connect_DeleteDeviceId(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	EOS_Connect_DeleteDeviceIdOptions Options;
	Options.ApiVersion = EOS_CONNECT_DELETEDEVICEID_API_LATEST;

	callback* mcallback = getCallbackData();

	// NOTE: We're not deleting the received context because we're passing it down to another SDK call
	EOS_Connect_DeleteDeviceId(HConnect, &Options, mcallback, DeleteCreateUserCompleteCb);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

YYEXPORT void EpicGames_Connect_GetExternalAccountMapping(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_STRING

	const char* LocalUserId = YYGetString(arg, 0);
	const char* TargetExternalUserId = YYGetString(arg, 1);
	double AccountIdType = YYGetReal(arg, 2);

	EOS_Connect_GetExternalAccountMappingsOptions Options = {};
	Options.ApiVersion = EOS_CONNECT_GETEXTERNALACCOUNTMAPPINGS_API_LATEST;
	Options.AccountIdType = (EOS_EExternalAccountType)AccountIdType;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.TargetExternalUserId = TargetExternalUserId; //EOS_EExternalAccountType::EOS_EAT_EPIC

	EOS_ProductUserId NewMapping = EOS_Connect_GetExternalAccountMapping(HConnect, &Options);
	YYCreateString(&Result, productID_toString(NewMapping));
}

YYEXPORT void EpicGames_Connect_GetLoggedInUserByIndex(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_BOOL

	double index = YYGetReal(arg, 0);
	EOS_ProductUserId ProductUserId = EOS_Connect_GetLoggedInUserByIndex(HConnect, (int)index);
}

YYEXPORT void EpicGames_Connect_GetLoggedInUsersCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_BOOL

	uint32_t NumAccounts = EOS_Connect_GetLoggedInUsersCount(HConnect);

}

YYEXPORT void EpicGames_Connect_GetLoginStatus(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_BOOL

	const char* user = YYGetString(arg, 0);
	EOS_ELoginStatus LoginStatus = EOS_Connect_GetLoginStatus(HConnect, EOS_ProductUserId_FromString(user));
}

YYEXPORT void EpicGames_Connect_GetProductUserExternalAccountCount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_INT32

	const char* target = YYGetString(arg, 0);

	EOS_Connect_GetProductUserExternalAccountCountOptions Options = { 0 };
	Options.ApiVersion = EOS_CONNECT_GETPRODUCTUSEREXTERNALACCOUNTCOUNT_API_LATEST;
	Options.TargetUserId = EOS_ProductUserId_FromString(target);

	Result.kind = VALUE_INT32;
	Result.v32 = EOS_Connect_GetProductUserExternalAccountCount(HConnect,&Options);
}

YYEXPORT void EpicGames_Connect_GetProductUserIdMapping(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_BOOL

	const char* user = YYGetString(arg, 0);
	const char* target = YYGetString(arg, 1);

	EOS_Connect_GetProductUserIdMappingOptions Options = {};
	Options.ApiVersion = EOS_CONNECT_GETEXTERNALACCOUNTMAPPINGS_API_LATEST;
	Options.AccountIdType = EOS_EExternalAccountType::EOS_EAT_EPIC;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);
	Options.TargetProductUserId = EOS_ProductUserId_FromString(target);

	char Buffer[EOS_CONNECT_EXTERNAL_ACCOUNT_ID_MAX_LENGTH];
	int32_t IDStringSize = EOS_CONNECT_EXTERNAL_ACCOUNT_ID_MAX_LENGTH;
	EOS_EResult MappingResult = EOS_Connect_GetProductUserIdMapping(HConnect, &Options, Buffer, &IDStringSize);
}

void EOS_CALL LinkAccount(const EOS_Connect_LinkAccountCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Connect_LinkAccount");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Connect_LinkAccount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	const char* user = YYGetString(arg, 0);

	EOS_Connect_LinkAccountOptions Options = { 0 };
	Options.ApiVersion = EOS_CONNECT_LINKACCOUNT_API_LATEST;
	Options.ContinuanceToken = ContinuanceToken;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);

	callback* mcallback = getCallbackData();

	EOS_Connect_LinkAccount(HConnect,&Options, mcallback, LinkAccount);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL ConnectLoginCompleteCb(const EOS_Connect_LoginCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Connect_Login");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);

	if (Data->ContinuanceToken)
		ContinuanceToken = Data->ContinuanceToken;

	if (Data->ResultCode == EOS_EResult::EOS_Success)
	{
		static char TempBuffer[EOS_PRODUCTUSERID_MAX_LENGTH + 1];
		int32_t TempBufferSize = sizeof(TempBuffer);
		EOS_EResult Result = EOS_ProductUserId_ToString(Data->LocalUserId, TempBuffer, &TempBufferSize);

		DsMapAddString(map, "LocalUserId", TempBuffer);
	}

	g_pYYRunnerInterface->CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Connect_Login(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	double type = YYGetReal(arg, 0);
	const char* AccessToken = YYGetString(arg, 1);
	const char* DisplayName = YYGetString(arg, 2);

	EOS_Connect_Credentials Credentials;
	Credentials.ApiVersion = EOS_CONNECT_CREDENTIALS_API_LATEST;
	Credentials.Token = AccessToken;
	Credentials.Type = (EOS_EExternalCredentialType)type;//EOS_EExternalCredentialType::EOS_ECT_EPIC;

	EOS_Connect_LoginOptions Options = { 0 };
	Options.ApiVersion = EOS_CONNECT_LOGIN_API_LATEST;
	Options.Credentials = &Credentials;

	if(strcmp(DisplayName,"") != 0) //0: equals
	{
		EOS_Connect_UserLoginInfo UserLoginInfo = { 0 };
		UserLoginInfo.ApiVersion = EOS_CONNECT_USERLOGININFO_API_LATEST;
		UserLoginInfo.DisplayName = DisplayName;
		Options.UserLoginInfo = &UserLoginInfo;
	}

	callback* mcallback = getCallbackData();
	//assert(HConnect != nullptr);
	EOS_Connect_Login(HConnect, &Options, mcallback, ConnectLoginCompleteCb);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL OnQueryExternalAccountMappingsCallback(const EOS_Connect_QueryExternalAccountMappingsCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Connect_QueryExternalAccountMappings");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}


YYEXPORT void EpicGames_Connect_QueryExternalAccountMappings(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	const char* userID = YYGetString(arg, 0);
	int accountIdType = (int)YYGetReal(arg, 1);

	//if (KIND_RValue(&arg[2]) == VALUE_ARRAY) {
	std::vector<const char*> vec_Users = _SW_GetArrayOfStrings(arg, 2, "EpicGames_Connect_QueryExternalAccountMappings");
	//}
	
	EOS_Connect_QueryExternalAccountMappingsOptions QueryOptions;
	QueryOptions.ApiVersion = EOS_CONNECT_QUERYEXTERNALACCOUNTMAPPINGS_API_LATEST;
	QueryOptions.AccountIdType = (EOS_EExternalAccountType)accountIdType; //EOS_EExternalAccountType // ::EOS_EAT_EPIC;
	QueryOptions.LocalUserId = EOS_ProductUserId_FromString(userID);

	const char* ExternalAccountId;

	QueryOptions.ExternalAccountIdCount = vec_Users.size();
	QueryOptions.ExternalAccountIds = vec_Users.data();

	EOS_HConnect ConnectHandle = EOS_Platform_GetConnectInterface(PlatformHandle);
	
	callback* mcallback = getCallbackData();

	EOS_Connect_QueryExternalAccountMappings(ConnectHandle, &QueryOptions, mcallback, OnQueryExternalAccountMappingsCallback);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL OnQueryAccountMappingsCallback(const EOS_Connect_QueryProductUserIdMappingsCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Connect_QueryProductUserIdMappings");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Connect_QueryProductUserIdMappings(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	//const char* user = YYGetString(arg, 0);

	//EOS_Connect_QueryProductUserIdMappingsOptions QueryOptions = {};
	//QueryOptions.ApiVersion = EOS_CONNECT_QUERYPRODUCTUSERIDMAPPINGS_API_LATEST;
	//QueryOptions.LocalUserId = EOS_ProductUserId_FromString(user);

	//QueryOptions.ProductUserIdCount = ;
	//QueryOptions.ProductUserIds = ;

	//EOS_HConnect ConnectHandle = EOS_Platform_GetConnectInterface(PlatformHandle);
	
	callback* mcallback = getCallbackData();

	//EOS_Connect_QueryProductUserIdMappings(ConnectHandle, &QueryOptions, mcallback, OnQueryAccountMappingsCallback);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

YYEXPORT void EpicGames_Connect_RemoveNotifyAuthExpiration(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_BOOL

	int64 ConnectAuthExpirationId = YYGetInt64(arg, 0);
	EOS_Connect_RemoveNotifyAuthExpiration(HConnect, ConnectAuthExpirationId);
}

YYEXPORT void EpicGames_Connect_RemoveNotifyLoginStatusChanged(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_BOOL

	int64 RemoveNotifyLoginStatusChangedId = YYGetInt64(arg, 0);
	EOS_Connect_RemoveNotifyLoginStatusChanged(HConnect, RemoveNotifyLoginStatusChangedId);
}

void EOS_CALL TransferDeviceIdAccount(const EOS_Connect_TransferDeviceIdAccountCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Connect_TransferDeviceIdAccount");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Connect_TransferDeviceIdAccount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	const char* LocalDeviceUserId = YYGetString(arg, 0);
	const char* PrimaryLocalUserId = YYGetString(arg, 1);
	const char* ProductUserIdToPreserve = YYGetString(arg, 2);
	
	EOS_Connect_TransferDeviceIdAccountOptions Options = { 0 };
	Options.ApiVersion = EOS_CONNECT_TRANSFERDEVICEIDACCOUNT_API_LATEST;
	Options.LocalDeviceUserId = EOS_ProductUserId_FromString(LocalDeviceUserId);
	Options.PrimaryLocalUserId = EOS_ProductUserId_FromString(PrimaryLocalUserId);
	Options.ProductUserIdToPreserve = EOS_ProductUserId_FromString(ProductUserIdToPreserve);

	callback* mcallback = getCallbackData();

	EOS_Connect_TransferDeviceIdAccount(HConnect, &Options, mcallback, TransferDeviceIdAccount);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL UnlinkAccount(const EOS_Connect_UnlinkAccountCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Connect_UnlinkAccount");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Connect_UnlinkAccount(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	const char* user = YYGetString(arg, 0);

	EOS_Connect_UnlinkAccountOptions Options = { 0 };
	Options.ApiVersion = EOS_CONNECT_VERIFYIDTOKEN_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);

	callback* mcallback = getCallbackData();

	EOS_Connect_UnlinkAccount(HConnect,&Options, mcallback, UnlinkAccount);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL VerifyIdToken(const EOS_Connect_VerifyIdTokenCallbackInfo* Data)
{
	int map = CreateDsMap(0,0);
	DsMapAddString(map, "type", "EpicGames_Connect_VerifyIdToken");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "AccountId", Data->AccountId);
	DsMapAddDouble(map, "AccountIdType", (double)Data->AccountIdType);
	DsMapAddBool(map, "bIsAccountInfoPresent",Data->bIsAccountInfoPresent);
	//DsMapAddDouble(map, "DeviceType", (double)Data->DeviceType);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Connect_VerifyIdToken(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
{
	EOS_NotInitialisedReturn_REAL

	const char* user = YYGetString(arg, 0);
	const char* JsonWebToken = YYGetString(arg, 1);

	EOS_Connect_IdToken IdToken = { 0 };
	IdToken.JsonWebToken = JsonWebToken;
	IdToken.ApiVersion = EOS_CONNECT_VERIFYIDTOKEN_API_LATEST;
	IdToken.ProductUserId = EOS_ProductUserId_FromString(user);

	EOS_Connect_VerifyIdTokenOptions Options = { 0 };
	Options.ApiVersion = EOS_CONNECT_VERIFYIDTOKEN_API_LATEST;
	Options.IdToken = &IdToken;

	callback* mcallback = getCallbackData();

	EOS_Connect_VerifyIdToken(HConnect,&Options, mcallback, VerifyIdToken);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}


