#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_auth.h>

#include <cstdint>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

using namespace gm::wire;
using namespace gm_structs;
using namespace gm_enums;

// ============================================================
// Internal helpers
// ============================================================

static EOS_ContinuanceToken g_eos_auth_continuance_token = nullptr;

struct EOSAsyncCallbackContext
{
    std::optional<GMFunction> callback;
};

static EOS_HAuth eos_auth_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetAuthInterface(p) : nullptr;
}

static std::string eos_auth_result_string(EOS_EResult result)
{
    const char* s = EOS_EResult_ToString(result);
    return s ? std::string(s) : std::string();
}

template <typename Fn>
static std::string eos_auth_copy_string_with_fixed_retry(Fn&& call_fn, size_t initial_capacity = 256)
{
    std::vector<char> buffer(initial_capacity, '\0');
    int32_t length = (int32_t)buffer.size();

    EOS_EResult result = call_fn(buffer.data(), &length);
    if (result == EOS_EResult::EOS_LimitExceeded && length > 0)
    {
        buffer.assign((size_t)length, '\0');
        result = call_fn(buffer.data(), &length);
    }

    if (result != EOS_EResult::EOS_Success)
        return std::string();

    return std::string(buffer.data());
}

static EOS_EpicAccountId eos_epic_account_id_from_string_internal(std::string_view account_id)
{
    std::string value(account_id);
    if (value.empty())
        return nullptr;
    return EOS_EpicAccountId_FromString(value.c_str());
}

static std::string eos_epic_account_id_to_string_internal(EOS_EpicAccountId account_id)
{
    if (!account_id)
        return std::string();

    return eos_auth_copy_string_with_fixed_retry(
        [&](char* out_buffer, int32_t* inout_len) -> EOS_EResult
        {
            return EOS_EpicAccountId_ToString(account_id, out_buffer, inout_len);
        });
}

static gm_structs::EpicAuthLoginCallbackInfo eos_auth_login_info_from_native(const EOS_Auth_LoginCallbackInfo* p)
{
    gm_structs::EpicAuthLoginCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.local_user_id = eos_epic_account_id_to_string_internal(p->LocalUserId);
    out.selected_account_id = eos_epic_account_id_to_string_internal(p->SelectedAccountId);
    out.has_continuance_token = (p->ContinuanceToken != nullptr);

    return out;
}

static gm_structs::EpicAuthLogoutCallbackInfo eos_auth_logout_info_from_native(const EOS_Auth_LogoutCallbackInfo* p)
{
    gm_structs::EpicAuthLogoutCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.local_user_id = eos_epic_account_id_to_string_internal(p->LocalUserId);

    return out;
}

static gm_structs::EpicAuthLinkAccountCallbackInfo eos_auth_link_account_info_from_native(const EOS_Auth_LinkAccountCallbackInfo* p)
{
    gm_structs::EpicAuthLinkAccountCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.local_user_id = eos_epic_account_id_to_string_internal(p->LocalUserId);
    out.selected_account_id = eos_epic_account_id_to_string_internal(p->SelectedAccountId);

    return out;
}

static gm_structs::EpicAuthDeletePersistentAuthCallbackInfo eos_auth_delete_persistent_auth_info_from_native(const EOS_Auth_DeletePersistentAuthCallbackInfo* p)
{
    gm_structs::EpicAuthDeletePersistentAuthCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    return out;
}

static gm_structs::EpicAuthVerifyUserAuthCallbackInfo eos_auth_verify_user_auth_info_from_native(const EOS_Auth_VerifyUserAuthCallbackInfo* p)
{
    gm_structs::EpicAuthVerifyUserAuthCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    return out;
}

static void EOS_CALL eos_auth_login_callback_native(const EOS_Auth_LoginCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    g_eos_auth_continuance_token = data->ContinuanceToken;
    if (ctx->callback) ctx->callback.value().call(eos_auth_login_info_from_native(data));
    delete ctx;
}

static void EOS_CALL eos_auth_logout_callback_native(const EOS_Auth_LogoutCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    if (ctx->callback) ctx->callback.value().call(eos_auth_logout_info_from_native(data));
    delete ctx;
}

static void EOS_CALL eos_auth_link_account_callback_native(const EOS_Auth_LinkAccountCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    g_eos_auth_continuance_token = nullptr;
    if (ctx->callback) ctx->callback.value().call(eos_auth_link_account_info_from_native(data));
    delete ctx;
}

static void EOS_CALL eos_auth_delete_persistent_auth_callback_native(const EOS_Auth_DeletePersistentAuthCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    if (ctx->callback) ctx->callback.value().call(eos_auth_delete_persistent_auth_info_from_native(data));
    delete ctx;
}

// ============================================================
// EOS Auth (Part 1)
// ============================================================

void eos_auth_login(
    std::string_view credentials_id,
    std::string_view credentials_token,
    gm_enums::EpicLoginCredentialType credentials_type,
    gm_enums::EpicExternalCredentialType external_credential_type,
    gm_enums::EpicAuthScopeFlags scope_flags,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HAuth auth = eos_auth_iface();
    if (!auth) {
        eos_set_last_error("EOS Auth interface unavailable.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    std::string id_storage(credentials_id);
    std::string token_storage(credentials_token);

    EOS_Auth_Credentials creds{};
    creds.ApiVersion = EOS_AUTH_CREDENTIALS_API_LATEST;
    creds.Id = id_storage.empty() ? nullptr : id_storage.c_str();
    creds.Token = token_storage.empty() ? nullptr : token_storage.c_str();
    creds.Type = (EOS_ELoginCredentialType)credentials_type;
    creds.ExternalType = (EOS_EExternalCredentialType)external_credential_type;

    EOS_Auth_LoginOptions opts{};
    opts.ApiVersion = EOS_AUTH_LOGIN_API_LATEST;
    opts.Credentials = &creds;
    opts.ScopeFlags = (EOS_EAuthScopeFlags)scope_flags;

    EOS_Auth_Login(auth, &opts, ctx, &eos_auth_login_callback_native);
}

void eos_auth_logout(std::string_view local_user_id, const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HAuth auth = eos_auth_iface();
    if (!auth) {
        eos_set_last_error("EOS Auth interface unavailable.");
        return;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Auth_Logout: invalid local_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Auth_LogoutOptions opts{};
    opts.ApiVersion = EOS_AUTH_LOGOUT_API_LATEST;
    opts.LocalUserId = local_user;

    EOS_Auth_Logout(auth, &opts, ctx, &eos_auth_logout_callback_native);
}

void eos_auth_link_account(
    std::string_view local_user_id,
    gm_enums::EpicLinkAccountFlags link_account_flags,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HAuth auth = eos_auth_iface();
    if (!auth) {
        eos_set_last_error("EOS Auth interface unavailable.");
        return;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Auth_LinkAccount: invalid local_user_id.");
        return;
    }

    if (!g_eos_auth_continuance_token) {
        eos_set_last_error("EOS_Auth_LinkAccount: no stored continuance token.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Auth_LinkAccountOptions opts{};
    opts.ApiVersion = EOS_AUTH_LINKACCOUNT_API_LATEST;
    opts.LocalUserId = local_user;
    opts.ContinuanceToken = g_eos_auth_continuance_token;
    opts.LinkAccountFlags = (EOS_ELinkAccountFlags)link_account_flags;

    EOS_Auth_LinkAccount(auth, &opts, ctx, &eos_auth_link_account_callback_native);
}

void eos_auth_delete_persistent_auth(const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HAuth auth = eos_auth_iface();
    if (!auth) {
        eos_set_last_error("EOS Auth interface unavailable.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Auth_DeletePersistentAuthOptions opts{};
    opts.ApiVersion = EOS_AUTH_DELETEPERSISTENTAUTH_API_LATEST;

    EOS_Auth_DeletePersistentAuth(auth, &opts, ctx, &eos_auth_delete_persistent_auth_callback_native);
}

int64_t eos_auth_get_logged_in_accounts_count()
{
    eos_clear_last_error();

    EOS_HAuth auth = eos_auth_iface();
    if (!auth) {
        eos_set_last_error("EOS Auth interface unavailable.");
        return 0;
    }

    return (int64_t)EOS_Auth_GetLoggedInAccountsCount(auth);
}

std::string eos_auth_get_logged_in_account_by_index(int64_t index)
{
    eos_clear_last_error();

    EOS_HAuth auth = eos_auth_iface();
    if (!auth) {
        eos_set_last_error("EOS Auth interface unavailable.");
        return std::string();
    }

    EOS_EpicAccountId id = EOS_Auth_GetLoggedInAccountByIndex(auth, (int32_t)index);
    if (!id)
        return std::string();

    return eos_epic_account_id_to_string_internal(id);
}

    gm_enums::EpicLoginStatus eos_auth_get_login_status(std::string_view local_user_id)
    {
    eos_clear_last_error();

    EOS_HAuth auth = eos_auth_iface();
    if (!auth) {
        eos_set_last_error("EOS Auth interface unavailable.");
        return (gm_enums::EpicLoginStatus)0;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Auth_GetLoginStatus: invalid local_user_id.");
        return (gm_enums::EpicLoginStatus)0;
    }

    return (gm_enums::EpicLoginStatus)EOS_Auth_GetLoginStatus(auth, local_user);
}


// ============================================================
// EOS Auth (Part 2)
// ============================================================

static gm_structs::EpicAuthIdToken eos_auth_id_token_from_native(const EOS_Auth_IdToken* p)
{
    gm_structs::EpicAuthIdToken out{};
    if (!p)
        return out;

    out.account_id = eos_epic_account_id_to_string_internal(p->AccountId);
    out.json_web_token = p->JsonWebToken ? std::string(p->JsonWebToken) : std::string();

    return out;
}

static gm_structs::EpicAuthUserAuthToken eos_auth_user_auth_token_from_native(const EOS_Auth_Token* p)
{
    gm_structs::EpicAuthUserAuthToken out{};
    if (!p)
        return out;

    out.app = p->App ? std::string(p->App) : std::string();
    out.client_id = p->ClientId ? std::string(p->ClientId) : std::string();
    out.account_id = eos_epic_account_id_to_string_internal(p->AccountId);
    out.access_token = p->AccessToken ? std::string(p->AccessToken) : std::string();
    out.expires_in = (double)p->ExpiresIn;
    out.expires_at = p->ExpiresAt ? std::string(p->ExpiresAt) : std::string();
    out.auth_type = (EpicAuthTokenType)p->AuthType;
    out.refresh_token = p->RefreshToken ? std::string(p->RefreshToken) : std::string();
    out.refresh_expires_in = (double)p->RefreshExpiresIn;
    out.refresh_expires_at = p->RefreshExpiresAt ? std::string(p->RefreshExpiresAt) : std::string();

    return out;
}

static gm_structs::EpicAuthQueryIdTokenCallbackInfo eos_auth_query_id_token_info_from_native(const EOS_Auth_QueryIdTokenCallbackInfo* p)
{
    gm_structs::EpicAuthQueryIdTokenCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.local_user_id = eos_epic_account_id_to_string_internal(p->LocalUserId);
    out.target_account_id = eos_epic_account_id_to_string_internal(p->TargetAccountId);

    return out;
}

static gm_structs::EpicAuthVerifyIdTokenCallbackInfo eos_auth_verify_id_token_info_from_native(const EOS_Auth_VerifyIdTokenCallbackInfo* p)
{
    gm_structs::EpicAuthVerifyIdTokenCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.application_id = p->ApplicationId ? std::string(p->ApplicationId) : std::string();
    out.client_id = p->ClientId ? std::string(p->ClientId) : std::string();
    out.product_id = p->ProductId ? std::string(p->ProductId) : std::string();
    out.sandbox_id = p->SandboxId ? std::string(p->SandboxId) : std::string();
    out.deployment_id = p->DeploymentId ? std::string(p->DeploymentId) : std::string();
    out.display_name = p->DisplayName ? std::string(p->DisplayName) : std::string();
    out.is_external_account_info_present = (p->bIsExternalAccountInfoPresent != 0);

    return out;
}

gm_structs::EpicAuthUserAuthToken eos_auth_copy_user_auth_token(std::string_view local_user_id)
{
    eos_clear_last_error();

    gm_structs::EpicAuthUserAuthToken out{};

    EOS_HAuth auth = eos_auth_iface();
    if (!auth) {
        eos_set_last_error("EOS Auth interface unavailable.");
        return out;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Auth_CopyUserAuthToken: invalid local_user_id.");
        return out;
    }

    EOS_Auth_CopyUserAuthTokenOptions opts{};
    opts.ApiVersion = EOS_AUTH_COPYUSERAUTHTOKEN_API_LATEST;

    EOS_Auth_Token* token = nullptr;
    const EOS_EResult result = EOS_Auth_CopyUserAuthToken(auth, &opts, local_user, &token);
    if (result != EOS_EResult::EOS_Success || token == nullptr) {
        eos_set_last_error(eos_auth_result_string(result));
        return out;
    }

    out = eos_auth_user_auth_token_from_native(token);
    EOS_Auth_Token_Release(token);
    return out;
}

static void EOS_CALL eos_auth_query_id_token_callback_native(const EOS_Auth_QueryIdTokenCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    if (ctx->callback) ctx->callback.value().call(eos_auth_query_id_token_info_from_native(data));
    delete ctx;
}

static void EOS_CALL eos_auth_verify_id_token_callback_native(const EOS_Auth_VerifyIdTokenCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    if (ctx->callback) ctx->callback.value().call(eos_auth_verify_id_token_info_from_native(data));
    delete ctx;
}

static void EOS_CALL eos_auth_verify_user_auth_callback_native(const EOS_Auth_VerifyUserAuthCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

     if (ctx->callback) ctx->callback.value().call(eos_auth_verify_user_auth_info_from_native(data));
    delete ctx;
}

gm_structs::EpicAuthIdToken eos_auth_copy_id_token(std::string_view local_user_id, std::string_view target_account_id)
{
    eos_clear_last_error();

    gm_structs::EpicAuthIdToken out{};

    EOS_HAuth auth = eos_auth_iface();
    if (!auth) {
        eos_set_last_error("EOS Auth interface unavailable.");
        return out;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    EOS_EpicAccountId target_user = eos_epic_account_id_from_string_internal(target_account_id);

    if (!local_user) {
        eos_set_last_error("EOS_Auth_CopyIdToken: invalid local_user_id.");
        return out;
    }

    if (!target_user) {
        eos_set_last_error("EOS_Auth_CopyIdToken: invalid target_account_id.");
        return out;
    }

    EOS_Auth_CopyIdTokenOptions opts{};
    opts.ApiVersion = EOS_AUTH_COPYIDTOKEN_API_LATEST;
    opts.AccountId = target_user;

    EOS_Auth_IdToken* token = nullptr;
    const EOS_EResult result = EOS_Auth_CopyIdToken(auth, &opts, &token);
    if (result != EOS_EResult::EOS_Success || token == nullptr) {
        eos_set_last_error(eos_auth_result_string(result));
        return out;
    }

    out = eos_auth_id_token_from_native(token);
    EOS_Auth_IdToken_Release(token);
    return out;
}

void eos_auth_query_id_token(std::string_view local_user_id, std::string_view target_account_id, const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HAuth auth = eos_auth_iface();
    if (!auth) {
        eos_set_last_error("EOS Auth interface unavailable.");
        return;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    EOS_EpicAccountId target_user = eos_epic_account_id_from_string_internal(target_account_id);

    if (!local_user) {
        eos_set_last_error("EOS_Auth_QueryIdToken: invalid local_user_id.");
        return;
    }

    if (!target_user) {
        eos_set_last_error("EOS_Auth_QueryIdToken: invalid target_account_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Auth_QueryIdTokenOptions opts{};
    opts.ApiVersion = EOS_AUTH_QUERYIDTOKEN_API_LATEST;
    opts.LocalUserId = local_user;
    opts.TargetAccountId = target_user;

    EOS_Auth_QueryIdToken(auth, &opts, ctx, &eos_auth_query_id_token_callback_native);
}

void eos_auth_verify_id_token(std::string_view json_web_token, const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HAuth auth = eos_auth_iface();
    if (!auth) {
        eos_set_last_error("EOS Auth interface unavailable.");
        return;
    }

    std::string jwt_storage(json_web_token);
    if (jwt_storage.empty()) {
        eos_set_last_error("EOS_Auth_VerifyIdToken: json_web_token is required.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Auth_IdToken id_token{};
    id_token.ApiVersion = EOS_AUTH_IDTOKEN_API_LATEST;
    id_token.JsonWebToken = jwt_storage.c_str();

    EOS_Auth_VerifyIdTokenOptions opts{};
    opts.ApiVersion = EOS_AUTH_VERIFYIDTOKEN_API_LATEST;
    opts.IdToken = &id_token;

    EOS_Auth_VerifyIdToken(auth, &opts, ctx, &eos_auth_verify_id_token_callback_native);
}

void eos_auth_verify_user_auth(std::string_view access_token, const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HAuth auth = eos_auth_iface();
    if (!auth) {
        eos_set_last_error("EOS Auth interface unavailable.");
        return;
    }

    std::string access_token_storage(access_token);
    if (access_token_storage.empty()) {
        eos_set_last_error("EOS_Auth_VerifyUserAuth: access_token is required.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Auth_Token token{};
    token.ApiVersion = EOS_AUTH_TOKEN_API_LATEST;
    token.AccessToken = access_token_storage.c_str();

    EOS_Auth_VerifyUserAuthOptions opts{};
    opts.ApiVersion = EOS_AUTH_VERIFYUSERAUTH_API_LATEST;
    opts.AuthToken = &token;

    EOS_Auth_VerifyUserAuth(auth, &opts, ctx, &eos_auth_verify_user_auth_callback_native);
}

// ============================================================
// EOS Auth Notify
// ============================================================

static GMFunction g_cb_auth_login_status_changed = nullptr;

static gm_structs::EpicAuthLoginStatusChangedCallbackInfo
eos_auth_login_status_changed_from_native(
    const EOS_Auth_LoginStatusChangedCallbackInfo* p)
{
    gm_structs::EpicAuthLoginStatusChangedCallbackInfo out{};
    if (!p)
        return out;

    out.local_user_id =
        eos_epic_account_id_to_string_internal(p->LocalUserId);

    out.previous_status = (gm_enums::EpicLoginStatus)p->PrevStatus;
    out.current_status = (gm_enums::EpicLoginStatus)p->CurrentStatus;

    return out;
}

static void EOS_CALL eos_auth_login_status_changed_callback(
    const EOS_Auth_LoginStatusChangedCallbackInfo* data)
{
    if (!data || !g_cb_auth_login_status_changed)
        return;

    g_cb_auth_login_status_changed.call(
        eos_auth_login_status_changed_from_native(data)
    );
}

uint64_t eos_auth_add_notify_login_status_changed(
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HAuth auth = eos_auth_iface();
    if (!auth)
    {
        eos_set_last_error("EOS Auth interface unavailable.");
        return 0;
    }

    g_cb_auth_login_status_changed = callback.value_or(GMFunction{});

    EOS_Auth_AddNotifyLoginStatusChangedOptions opts{};
    opts.ApiVersion = EOS_AUTH_ADDNOTIFYLOGINSTATUSCHANGED_API_LATEST;

    return (uint64_t)EOS_Auth_AddNotifyLoginStatusChanged(
        auth,
        &opts,
        nullptr,
        &eos_auth_login_status_changed_callback
    );
}

void eos_auth_remove_notify_login_status_changed(
    uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HAuth auth = eos_auth_iface();
    if (!auth)
    {
        eos_set_last_error("EOS Auth interface unavailable.");
        return;
    }

    EOS_Auth_RemoveNotifyLoginStatusChanged(
        auth,
        (EOS_NotificationId)notification_id
    );
}
