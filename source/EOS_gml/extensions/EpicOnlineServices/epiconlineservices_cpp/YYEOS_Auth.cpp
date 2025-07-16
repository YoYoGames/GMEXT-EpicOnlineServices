
// EOS_Auth_AddNotifyLoginStatusChanged
// EOS_Auth_CopyIdToken
// EOS_Auth_CopyUserAuthToken
// EOS_Auth_DeletePersistentAuth
// EOS_Auth_GetLoggedInAccountByIndex
// EOS_Auth_GetLoggedInAccountsCount
// EOS_Auth_GetLoginStatus
// EOS_Auth_GetMergedAccountByIndex
// EOS_Auth_GetMergedAccountsCount
// EOS_Auth_GetSelectedAccountId
// EOS_Auth_LinkAccount
// EOS_Auth_Login
// EOS_Auth_Logout
// EOS_Auth_QueryIdToken
// EOS_Auth_RemoveNotifyLoginStatusChanged
// EOS_Auth_VerifyIdToken
// EOS_Auth_VerifyUserAuth

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include <eos_auth.h>
#include <eos_auth_types.h>
#include "YYEpicOnlineServices.h"

EOS_HAuth HAuth;

void EOS_CALL LoginStatusChangedCb(const EOS_Auth_LoginStatusChangedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_auth_add_notify_login_status_changed");
	DsMapAddDouble(map, "current_status", (double)data->CurrentStatus);
	DsMapAddDouble(map, "prev_status", (double)data->PrevStatus);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void eos_auth_add_notify_login_status_changed(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_int64;

	EOS_Auth_AddNotifyLoginStatusChangedOptions LoginStatusChangedOptions{};
	LoginStatusChangedOptions.ApiVersion = EOS_AUTH_ADDNOTIFYLOGINSTATUSCHANGED_API_LATEST;
	auto LoginStatusChangedId = EOS_Auth_AddNotifyLoginStatusChanged(HAuth, &LoginStatusChangedOptions, NULL, LoginStatusChangedCb);

	Result.kind = VALUE_INT64;
	Result.v64 = static_cast<int64_t>(LoginStatusChangedId);
}

YYEXPORT void eos_auth_copy_id_token(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(1);

	const char* user = YYGetString(arg, 0);

	EOS_Auth_CopyIdTokenOptions Options = {0};
	Options.ApiVersion = EOS_AUTH_COPYIDTOKEN_API_LATEST;
	Options.AccountId = EOS_EpicAccountId_FromString(user);

	EOS_Auth_IdToken *IdToken = NULL;
	EOS_EResult result = EOS_Auth_CopyIdToken(HAuth, &Options, &IdToken);

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

	if (IdToken->AccountId)
	{
		static char TempBuffer[EOS_EPICACCOUNTID_MAX_LENGTH + 1];
		int32_t TempBufferSize = sizeof(TempBuffer);
		EOS_EResult EResult = EOS_EpicAccountId_ToString(IdToken->AccountId, TempBuffer, &TempBufferSize);
		YYStructAddString(&Struct, "account_id", TempBuffer);
	}

	EOS_Auth_IdToken_Release(IdToken);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_auth_copy_user_auth_token(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(1);

	arg->kind = VALUE_STRING;
	const char* str_AccountId = YYGetString(arg, 0);

	RValue authStruct = {0};
	YYStructCreate(&authStruct);

	EOS_Auth_Token *UserAuthToken = nullptr;
	EOS_Auth_CopyUserAuthTokenOptions CopyTokenOptions = {0};
	CopyTokenOptions.ApiVersion = EOS_AUTH_COPYUSERAUTHTOKEN_API_LATEST;
	EOS_EResult ResultCode = EOS_Auth_CopyUserAuthToken(HAuth, &CopyTokenOptions, EOS_EpicAccountId_FromString(str_AccountId), &UserAuthToken);
	if (ResultCode == EOS_EResult::EOS_Success)
	{
		static char TempBuffer[EOS_EPICACCOUNTID_MAX_LENGTH + 1];
		int32_t TempBufferSize = sizeof(TempBuffer);
		EOS_EResult EResult = EOS_EpicAccountId_ToString(UserAuthToken->AccountId, TempBuffer, &TempBufferSize);

		YYStructAddDouble(&authStruct, "status", (double)EResult);
		YYStructAddString(&authStruct, "status_message", EOS_EResult_ToString(EResult));
		YYStructAddString(&authStruct, "account_id", TempBuffer);
		YYStructAddString(&authStruct, "access_token", UserAuthToken->AccessToken);
		// DsMapAddInt64(map, "api_version", (int64)UserAuthToken->ApiVersion);
		YYStructAddString(&authStruct, "app", UserAuthToken->App);
		YYStructAddDouble(&authStruct, "auth_type", (double)UserAuthToken->AuthType);
		YYStructAddString(&authStruct, "client_id", UserAuthToken->ClientId);
		YYStructAddString(&authStruct, "expires_at", UserAuthToken->ExpiresAt);
		YYStructAddDouble(&authStruct, "expires_in", UserAuthToken->ExpiresIn);
		YYStructAddString(&authStruct, "refresh_token", UserAuthToken->RefreshToken);
		YYStructAddString(&authStruct, "refresh_expires_at", UserAuthToken->RefreshExpiresAt);
		YYStructAddDouble(&authStruct, "refresh_expires_in", UserAuthToken->RefreshExpiresIn);

		EOS_Auth_Token_Release(UserAuthToken);
	}

	COPY_RValue(&Result, &authStruct);
	FREE_RValue(&authStruct);
}

void EOS_CALL DeletePersistentAuthCompleteCallbackFn(const EOS_Auth_DeletePersistentAuthCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_auth_delete_persistent_auth");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_auth_delete_persistent_auth(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	const char* refreshtoken = YYGetString(arg, 0);

	EOS_Auth_DeletePersistentAuthOptions Options = {};
	Options.ApiVersion = EOS_AUTH_DELETEPERSISTENTAUTH_API_LATEST;
	Options.RefreshToken = strcmp(refreshtoken, "") == 0 ? nullptr : refreshtoken;

	callback *mcallback = getCallbackData();

	EOS_Auth_DeletePersistentAuth(HAuth, &Options, mcallback, DeletePersistentAuthCompleteCallbackFn);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

YYEXPORT void eos_auth_get_logged_in_account_by_index(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_string;

	eos_ensure_argc(1);

	int32_t AccountIdx = YYGetInt32(arg, 0);

	EOS_EpicAccountId accountID = EOS_Auth_GetLoggedInAccountByIndex(HAuth, AccountIdx);
	YYCreateString(&Result, AccountID_toString(accountID));
}

YYEXPORT void eos_auth_get_logged_in_accounts_count(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_int32;

	Result.kind = VALUE_INT32;
	Result.v32 = EOS_Auth_GetLoggedInAccountsCount(HAuth);
}

YYEXPORT void eos_auth_get_login_status(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	const char* accountID = YYGetString(arg, 0);

	Result.kind = VALUE_REAL;
	Result.val = (double)EOS_Auth_GetLoginStatus(HAuth, EOS_EpicAccountId_FromString(accountID));
}

YYEXPORT void eos_auth_get_merged_account_by_index(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_string;

	eos_ensure_argc(2);

	const char* accountID = YYGetString(arg, 0);
	int32 index = YYGetInt32(arg, 1);

	EOS_EpicAccountId account = EOS_Auth_GetMergedAccountByIndex(HAuth, EOS_EpicAccountId_FromString(accountID), index);
	YYCreateString(&Result, AccountID_toString(account));
}

YYEXPORT void eos_auth_get_merged_accounts_count(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	const char* accountID = YYGetString(arg, 0);

	Result.kind = VALUE_REAL;
	Result.val = EOS_Auth_GetMergedAccountsCount(HAuth, EOS_EpicAccountId_FromString(accountID));
}

YYEXPORT void eos_auth_get_selected_account_id(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_string;

	eos_ensure_argc(1);

	const char* accountID = YYGetString(arg, 0);

	EOS_EpicAccountId account = NULL;
	EOS_EResult result = EOS_Auth_GetSelectedAccountId(HAuth, EOS_EpicAccountId_FromString(accountID), &account);

	YYCreateString(&Result, AccountID_toString(account));
}

void EOS_CALL LinkAccountCompleteCallbackFn(const EOS_Auth_LinkAccountCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_auth_link_account");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddString(map, "account_id", AccountID_toString(data->LocalUserId));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_auth_link_account(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	if (ContinuanceToken == nullptr)
	{
		DebugConsoleOutput("mContinuanceToken Error\n");
		return;
	}

	const char* accountID = YYGetString(arg, 0);
	double scope_flags = YYGetReal(arg, 1);

	EOS_Auth_LinkAccountOptions Options{};
	Options.ApiVersion = EOS_AUTH_LINKACCOUNT_API_LATEST;
	Options.LinkAccountFlags = (EOS_ELinkAccountFlags)scope_flags; // EOS_ELinkAccountFlags::EOS_LA_NoFlags;
	Options.ContinuanceToken = ContinuanceToken;
	Options.LocalUserId = EOS_EpicAccountId_FromString(accountID);

	callback *mcallback = getCallbackData();

	EOS_Auth_LinkAccount(HAuth, &Options, mcallback, LinkAccountCompleteCallbackFn);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL LoginCompleteCallbackFn(const EOS_Auth_LoginCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_auth_login");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

	if (data->ResultCode == EOS_EResult::EOS_Success)
	{
		ContinuanceToken = data->ContinuanceToken;
		// data->PinGrantInfo;

		static char accountID[EOS_EPICACCOUNTID_MAX_LENGTH + 1];
		int32_t LocalUserId_size = sizeof(accountID);
		if (EOS_EpicAccountId_ToString(data->LocalUserId, accountID, &LocalUserId_size) == EOS_EResult::EOS_Success)
			DsMapAddString(map, "account_id", accountID);

		static char SelectedAccountId[EOS_EPICACCOUNTID_MAX_LENGTH + 1];
		int32_t SelectedAccountId_size = sizeof(SelectedAccountId);
		if (EOS_EpicAccountId_ToString(data->SelectedAccountId, SelectedAccountId, &SelectedAccountId_size) == EOS_EResult::EOS_Success)
			DsMapAddString(map, "selected_account_id", SelectedAccountId);
	}

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_auth_login(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	double type = YYGetReal(arg, 0);
	double scope_flags = YYGetReal(arg, 1);
	const char* Id = argc < 3 ? nullptr : YYGetString(arg, 2);
	const char* Token = argc < 4 ? nullptr : YYGetString(arg, 3);
	int32_t ExternalType = argc < 5 ? -1 : YYGetInt32(arg, 4);

	HAuth = EOS_Platform_GetAuthInterface(PlatformHandle);
	if (HAuth == nullptr)
	{
		Result.kind = VALUE_REAL;
		Result.val = -1.0;
		return;
	}

	EOS_Auth_Credentials Credentials = {};
	Credentials.ApiVersion = EOS_AUTH_CREDENTIALS_API_LATEST;

	EOS_Auth_LoginOptions LoginOptions;
	memset(&LoginOptions, 0, sizeof(LoginOptions));
	LoginOptions.ApiVersion = EOS_AUTH_LOGIN_API_LATEST;
	LoginOptions.ScopeFlags = (EOS_EAuthScopeFlags)scope_flags; // EOS_EAuthScopeFlags::EOS_AS_BasicProfile | EOS_EAuthScopeFlags::EOS_AS_FriendsList | EOS_EAuthScopeFlags::EOS_AS_Presence;
	Credentials.Type = (EOS_ELoginCredentialType)type;			// EOS_ELoginCredentialType::EOS_LCT_AccountPortal;

	if (Id && *Id)
	{
		Credentials.Id = Id;
	}
	if (Token && *Token)
	{
		Credentials.Token = Token;
	}

	if (ExternalType >= 0)
	{
		Credentials.ExternalType = (EOS_EExternalCredentialType)ExternalType;
	}

	LoginOptions.Credentials = &Credentials;

	callback *mcallback = getCallbackData();

	EOS_Auth_Login(HAuth, &LoginOptions, mcallback, LoginCompleteCallbackFn);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL LogoutCompleteCallbackFn(const EOS_Auth_LogoutCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_auth_logout");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_auth_logout(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	const char* user = YYGetString(arg, 0);

	EOS_Auth_LogoutOptions LogoutOptions;
	LogoutOptions.ApiVersion = EOS_AUTH_LOGOUT_API_LATEST;
	LogoutOptions.LocalUserId = EOS_EpicAccountId_FromString(user);

	callback *mcallback = getCallbackData();

	EOS_Auth_Logout(HAuth, &LogoutOptions, mcallback, LogoutCompleteCallbackFn);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL QueryIdToken(const EOS_Auth_QueryIdTokenCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_auth_query_id_token");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_auth_query_id_token(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char* user = YYGetString(arg, 0);
	const char* target = YYGetString(arg, 1);

	EOS_Auth_QueryIdTokenOptions Options = {0};
	Options.ApiVersion = EOS_AUTH_QUERYIDTOKEN_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.TargetAccountId = EOS_EpicAccountId_FromString(target);

	callback *mcallback = getCallbackData();

	EOS_Auth_QueryIdToken(HAuth, &Options, mcallback, QueryIdToken);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

YYEXPORT void eos_auth_remove_notify_login_status_changed(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	int64_t accountID = YYGetInt64(arg, 0);
	EOS_Auth_RemoveNotifyLoginStatusChanged(HAuth, static_cast<uint64_t>(accountID));

	Result.kind = VALUE_REAL;
	Result.val = 1.0;
}

void EOS_CALL VerifyIdToken(const EOS_Auth_VerifyIdTokenCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_auth_verify_id_token");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_auth_verify_id_token(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char* target = YYGetString(arg, 0);
	const char* JsonWebToken = YYGetString(arg, 1);

	EOS_Auth_IdToken *IdToken = {0};
	IdToken->AccountId = EOS_EpicAccountId_FromString(target);
	IdToken->ApiVersion = EOS_AUTH_IDTOKEN_API_LATEST;
	IdToken->JsonWebToken = JsonWebToken;

	EOS_Auth_VerifyIdTokenOptions Options;
	Options.ApiVersion = EOS_AUTH_VERIFYIDTOKEN_API_LATEST;
	Options.IdToken = IdToken;

	callback *mcallback = getCallbackData();

	EOS_Auth_VerifyIdToken(HAuth, &Options, mcallback, VerifyIdToken);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL VerifyUserAuth(const EOS_Auth_VerifyUserAuthCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_auth_verify_user_auth");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_auth_verify_user_auth(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(10);

	const char* AccessToken = YYGetString(arg, 0);
	const char* AccountId = YYGetString(arg, 1);
	// const char* ApiVersion =
	const char* App = YYGetString(arg, 2);
	double AuthType = YYGetReal(arg, 3);
	const char* ClientId = YYGetString(arg, 4);
	const char* ExpiresAt = YYGetString(arg, 5);
	double ExpiresIn = YYGetReal(arg, 6);
	const char* RefreshExpiresAt = YYGetString(arg, 7);
	double RefreshExpiresIn = YYGetReal(arg, 8);
	const char* RefreshToken = YYGetString(arg, 9);

	EOS_Auth_Token Token = {0};
	Token.AccessToken = AccessToken;
	Token.AccountId = EOS_EpicAccountId_FromString(AccountId);
	Token.ApiVersion = EOS_AUTH_TOKEN_API_LATEST;
	Token.App = App;
	Token.AuthType = (EOS_EAuthTokenType)AuthType;
	Token.ClientId = ClientId;
	Token.ExpiresAt = ExpiresAt;
	Token.ExpiresIn = ExpiresIn;
	Token.RefreshExpiresAt = RefreshExpiresAt;
	Token.RefreshExpiresIn = RefreshExpiresIn;
	Token.RefreshToken = RefreshToken;

	EOS_Auth_VerifyUserAuthOptions Options = {0};
	Options.ApiVersion = EOS_AUTH_VERIFYUSERAUTH_API_LATEST;
	Options.AuthToken = &Token;

	callback *mcallback = getCallbackData();

	EOS_Auth_VerifyUserAuth(HAuth, &Options, mcallback, VerifyUserAuth);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}
