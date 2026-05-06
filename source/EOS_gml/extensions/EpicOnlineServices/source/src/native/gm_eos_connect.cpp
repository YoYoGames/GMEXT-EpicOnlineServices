#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_connect.h>

#include <cstdint>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

using namespace gm::wire;
using namespace gm_structs;
using namespace gm_enums;

// ============================================================
// Internal helpers / state
// ============================================================

struct EOSAsyncCallbackContext
{
    std::optional<GMFunction> callback;
};

static EOS_ContinuanceToken g_eos_connect_continuance_token = nullptr;


static EOS_HConnect eos_connect_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetConnectInterface(p) : nullptr;
}

static std::string eos_connect_result_string(EOS_EResult result)
{
    const char* s = EOS_EResult_ToString(result);
    return s ? std::string(s) : std::string();
}

template <typename Fn>
static std::string eos_connect_copy_string_with_fixed_retry(Fn&& call_fn, size_t initial_capacity = 256)
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

static EOS_ProductUserId eos_product_user_id_from_string_internal(std::string_view product_user_id)
{
    std::string value(product_user_id);
    if (value.empty())
        return nullptr;
    return EOS_ProductUserId_FromString(value.c_str());
}

static std::string eos_product_user_id_to_string_internal(EOS_ProductUserId product_user_id)
{
    if (!product_user_id)
        return std::string();

    return eos_connect_copy_string_with_fixed_retry(
        [&](char* out_buffer, int32_t* inout_len) -> EOS_EResult
        {
            return EOS_ProductUserId_ToString(product_user_id, out_buffer, inout_len);
        });
}

// ============================================================
// Native -> GM callback conversion
// ============================================================

static gm_structs::EpicConnectLoginCallbackInfo eos_connect_login_info_from_native(const EOS_Connect_LoginCallbackInfo* p)
{
    gm_structs::EpicConnectLoginCallbackInfo out{};
    if (!p) return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(p->LocalUserId);
    out.has_continuance_token = (p->ContinuanceToken != nullptr);
    return out;
}

static gm_structs::EpicConnectCreateUserCallbackInfo eos_connect_create_user_info_from_native(const EOS_Connect_CreateUserCallbackInfo* p)
{
    gm_structs::EpicConnectCreateUserCallbackInfo out{};
    if (!p) return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(p->LocalUserId);
    return out;
}

static gm_structs::EpicConnectLinkAccountCallbackInfo eos_connect_link_account_info_from_native(const EOS_Connect_LinkAccountCallbackInfo* p)
{
    gm_structs::EpicConnectLinkAccountCallbackInfo out{};
    if (!p) return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(p->LocalUserId);
    return out;
}

static gm_structs::EpicConnectUnlinkAccountCallbackInfo eos_connect_unlink_account_info_from_native(const EOS_Connect_UnlinkAccountCallbackInfo* p)
{
    gm_structs::EpicConnectUnlinkAccountCallbackInfo out{};
    if (!p) return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(p->LocalUserId);
    return out;
}

static gm_structs::EpicConnectCreateDeviceIdCallbackInfo eos_connect_create_device_id_info_from_native(
    const EOS_Connect_CreateDeviceIdCallbackInfo* p,
    std::string_view device_model)
{
    gm_structs::EpicConnectCreateDeviceIdCallbackInfo out{};
    if (!p) return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.device_model = std::string(device_model);
    return out;
}

static gm_structs::EpicConnectDeleteDeviceIdCallbackInfo eos_connect_delete_device_id_info_from_native(const EOS_Connect_DeleteDeviceIdCallbackInfo* p)
{
    gm_structs::EpicConnectDeleteDeviceIdCallbackInfo out{};
    if (!p) return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    return out;
}

static gm_structs::EpicConnectTransferDeviceIdAccountCallbackInfo eos_connect_transfer_device_id_account_info_from_native(
    const EOS_Connect_TransferDeviceIdAccountCallbackInfo* p)
{
    gm_structs::EpicConnectTransferDeviceIdAccountCallbackInfo out{};
    if (!p) return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(p->LocalUserId);
    return out;
}

static gm_structs::EpicConnectLogoutCallbackInfo eos_connect_logout_info_from_native(const EOS_Connect_LogoutCallbackInfo* p)
{
    gm_structs::EpicConnectLogoutCallbackInfo out{};
    if (!p) return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(p->LocalUserId);
    return out;
}

// ============================================================
// Native callbacks
// ============================================================

static std::string g_connect_create_device_model;

static void EOS_CALL eos_connect_login_callback_native(const EOS_Connect_LoginCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    g_eos_connect_continuance_token = data->ContinuanceToken;
    if (ctx->callback) ctx->callback.value().call(eos_connect_login_info_from_native(data));
    delete ctx;
}

static void EOS_CALL eos_connect_create_user_callback_native(const EOS_Connect_CreateUserCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    g_eos_connect_continuance_token = nullptr;
    if (ctx->callback) ctx->callback.value().call(eos_connect_create_user_info_from_native(data));
    delete ctx;
}

static void EOS_CALL eos_connect_link_account_callback_native(const EOS_Connect_LinkAccountCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    g_eos_connect_continuance_token = nullptr;
    if (ctx->callback) ctx->callback.value().call(eos_connect_link_account_info_from_native(data));
    delete ctx;
}

static void EOS_CALL eos_connect_unlink_account_callback_native(const EOS_Connect_UnlinkAccountCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    if (ctx->callback) ctx->callback.value().call(eos_connect_unlink_account_info_from_native(data));
    delete ctx;
}

static void EOS_CALL eos_connect_create_device_id_callback_native(const EOS_Connect_CreateDeviceIdCallbackInfo* data)
{
    if (!data)
        return;

        //TODO
    // auto* ctx = static_cast<EOSConnectCreateDeviceIdContext*>(data->ClientData);
    // if (!ctx)
    //     return;

    // ctx->callback.call(eos_connect_create_device_id_info_from_native(data, ctx->device_model));

    // delete ctx;
}

static void EOS_CALL eos_connect_delete_device_id_callback_native(const EOS_Connect_DeleteDeviceIdCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    if (ctx->callback) ctx->callback.value().call(eos_connect_delete_device_id_info_from_native(data));
    delete ctx;
}

static void EOS_CALL eos_connect_transfer_device_id_account_callback_native(const EOS_Connect_TransferDeviceIdAccountCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    if (ctx->callback) ctx->callback.value().call(eos_connect_transfer_device_id_account_info_from_native(data));
    delete ctx;
}

static void EOS_CALL eos_connect_logout_callback_native(const EOS_Connect_LogoutCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    if (ctx->callback) ctx->callback.value().call(eos_connect_logout_info_from_native(data));
    delete ctx;
}

// ============================================================
// EOS Connect (Part 1)
// ============================================================

void eos_connect_login(
    std::string_view token,
    gm_enums::EpicExternalCredentialType external_credential_type,
    std::string_view display_name,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return;
    }

    std::string token_storage(token);
    std::string display_name_storage(display_name);

    if (token_storage.empty()) {
        eos_set_last_error("EOS_Connect_Login: token is required.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Connect_Credentials creds{};
    creds.ApiVersion = EOS_CONNECT_CREDENTIALS_API_LATEST;
    creds.Token = token_storage.c_str();
    creds.Type = (EOS_EExternalCredentialType)external_credential_type;

    EOS_Connect_UserLoginInfo user_login_info{};
    user_login_info.ApiVersion = EOS_CONNECT_USERLOGININFO_API_LATEST;
    user_login_info.DisplayName = display_name_storage.empty() ? nullptr : display_name_storage.c_str();

    EOS_Connect_LoginOptions opts{};
    opts.ApiVersion = EOS_CONNECT_LOGIN_API_LATEST;
    opts.Credentials = &creds;
    opts.UserLoginInfo = display_name_storage.empty() ? nullptr : &user_login_info;

    EOS_Connect_Login(connect, &opts, ctx, &eos_connect_login_callback_native);
}

void eos_connect_create_user(const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return;
    }

    if (!g_eos_connect_continuance_token) {
        eos_set_last_error("EOS_Connect_CreateUser: no stored continuance token.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Connect_CreateUserOptions opts{};
    opts.ApiVersion = EOS_CONNECT_CREATEUSER_API_LATEST;
    opts.ContinuanceToken = g_eos_connect_continuance_token;

    EOS_Connect_CreateUser(connect, &opts, ctx, &eos_connect_create_user_callback_native);
}

void eos_connect_link_account(std::string_view local_user_id, const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Connect_LinkAccount: invalid local_user_id.");
        return;
    }

    if (!g_eos_connect_continuance_token) {
        eos_set_last_error("EOS_Connect_LinkAccount: no stored continuance token.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Connect_LinkAccountOptions opts{};
    opts.ApiVersion = EOS_CONNECT_LINKACCOUNT_API_LATEST;
    opts.LocalUserId = local_user;
    opts.ContinuanceToken = g_eos_connect_continuance_token;

    EOS_Connect_LinkAccount(connect, &opts, ctx, &eos_connect_link_account_callback_native);
}

void eos_connect_unlink_account(std::string_view local_user_id, const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Connect_UnlinkAccount: invalid local_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Connect_UnlinkAccountOptions opts{};
    opts.ApiVersion = EOS_CONNECT_UNLINKACCOUNT_API_LATEST;
    opts.LocalUserId = local_user;

    EOS_Connect_UnlinkAccount(connect, &opts, ctx, &eos_connect_unlink_account_callback_native);
}

void eos_connect_create_device_id(std::string_view device_model, const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return;
    }

    std::string device_model_storage(device_model);
    if (device_model_storage.empty()) {
        eos_set_last_error("EOS_Connect_CreateDeviceId: device_model is required.");
        return;
    }

    g_connect_create_device_model = device_model_storage;
    //TODO
    // auto* ctx = new EOSConnectCreateDeviceIdContext{};
    // ctx->callback = callback;
    // ctx->device_model = device_model_storage;

    // EOS_Connect_CreateDeviceIdOptions opts{};
    // opts.ApiVersion = EOS_CONNECT_CREATEDEVICEID_API_LATEST;
    // opts.DeviceModel = g_connect_create_device_model.c_str();

    // EOS_Connect_CreateDeviceId(connect, &opts, ctx, &eos_connect_create_device_id_callback_native);
}

void eos_connect_delete_device_id(const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Connect_DeleteDeviceIdOptions opts{};
    opts.ApiVersion = EOS_CONNECT_DELETEDEVICEID_API_LATEST;

    EOS_Connect_DeleteDeviceId(connect, &opts, ctx, &eos_connect_delete_device_id_callback_native);
}

void eos_connect_transfer_device_id_account(
    std::string_view primary_local_user_id,
    std::string_view local_device_user_id,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return;
    }

    EOS_ProductUserId primary_local_user = eos_product_user_id_from_string_internal(primary_local_user_id);
    EOS_ProductUserId local_device_user = eos_product_user_id_from_string_internal(local_device_user_id);

    if (!primary_local_user) {
        eos_set_last_error("EOS_Connect_TransferDeviceIdAccount: invalid primary_local_user_id.");
        return;
    }

    if (!local_device_user) {
        eos_set_last_error("EOS_Connect_TransferDeviceIdAccount: invalid local_device_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Connect_TransferDeviceIdAccountOptions opts{};
    opts.ApiVersion = EOS_CONNECT_TRANSFERDEVICEIDACCOUNT_API_LATEST;
    opts.PrimaryLocalUserId = primary_local_user;
    opts.LocalDeviceUserId = local_device_user;

    EOS_Connect_TransferDeviceIdAccount(connect, &opts, ctx, &eos_connect_transfer_device_id_account_callback_native);
}

void eos_connect_logout(std::string_view local_user_id, const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Connect_Logout: invalid local_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Connect_LogoutOptions opts{};
    opts.ApiVersion = EOS_CONNECT_LOGOUT_API_LATEST;
    opts.LocalUserId = local_user;

    EOS_Connect_Logout(connect, &opts, ctx, &eos_connect_logout_callback_native);
}

int64_t eos_connect_get_logged_in_users_count()
{
    eos_clear_last_error();

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return 0;
    }

    return (int64_t)EOS_Connect_GetLoggedInUsersCount(connect);
}

std::string eos_connect_get_logged_in_user_by_index(int64_t index)
{
    eos_clear_last_error();

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return std::string();
    }

    EOS_ProductUserId id = EOS_Connect_GetLoggedInUserByIndex(connect, (int32_t)index);
    if (!id)
        return std::string();

    return eos_product_user_id_to_string_internal(id);
}

gm_enums::EpicLoginStatus eos_connect_get_login_status(std::string_view local_user_id)
{
    eos_clear_last_error();

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return (gm_enums::EpicLoginStatus)0;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Connect_GetLoginStatus: invalid local_user_id.");
        return (gm_enums::EpicLoginStatus)0;
    }

    return (gm_enums::EpicLoginStatus)EOS_Connect_GetLoginStatus(connect, local_user);
}


// ============================================================
// EOS Connect (Part 2)
// ============================================================


static gm_structs::EpicConnectIdToken eos_connect_id_token_from_native(const EOS_Connect_IdToken* p)
{
    gm_structs::EpicConnectIdToken out{};
    if (!p)
        return out;

    out.product_user_id = eos_product_user_id_to_string_internal(p->ProductUserId);
    out.json_web_token = p->JsonWebToken ? std::string(p->JsonWebToken) : std::string();

    return out;
}

static gm_structs::EpicConnectExternalAccountInfo eos_connect_external_account_info_from_native(const EOS_Connect_ExternalAccountInfo* p)
{
    gm_structs::EpicConnectExternalAccountInfo out{};
    if (!p)
        return out;

    out.product_user_id = eos_product_user_id_to_string_internal(p->ProductUserId);
    out.display_name = p->DisplayName ? std::string(p->DisplayName) : std::string();
    out.account_id = p->AccountId ? std::string(p->AccountId) : std::string();
    out.account_id_type = (gm_enums::EpicExternalAccountType)p->AccountIdType;
    out.last_login_time = p->LastLoginTime;

    return out;
}


static gm_structs::EpicConnectQueryExternalAccountMappingsCallbackInfo
eos_connect_query_external_account_mappings_info_from_native(
    const EOS_Connect_QueryExternalAccountMappingsCallbackInfo* p)
{
    gm_structs::EpicConnectQueryExternalAccountMappingsCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(p->LocalUserId);
    return out;
}

static gm_structs::EpicConnectQueryProductUserIdMappingsCallbackInfo
eos_connect_query_product_user_id_mappings_info_from_native(
    const EOS_Connect_QueryProductUserIdMappingsCallbackInfo* p)
{
    gm_structs::EpicConnectQueryProductUserIdMappingsCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(p->LocalUserId);
    return out;
}
static gm_structs::EpicConnectVerifyIdTokenCallbackInfo eos_connect_verify_id_token_info_from_native(const EOS_Connect_VerifyIdTokenCallbackInfo* p)
{
    gm_structs::EpicConnectVerifyIdTokenCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    return out;
}


static void EOS_CALL eos_connect_query_external_account_mappings_callback_native(
    const EOS_Connect_QueryExternalAccountMappingsCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    if (ctx->callback) ctx->callback.value().call(
        eos_connect_query_external_account_mappings_info_from_native(data)
    );
    delete ctx;
}

static void EOS_CALL eos_connect_query_product_user_id_mappings_callback_native(
    const EOS_Connect_QueryProductUserIdMappingsCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    if (ctx->callback) ctx->callback.value().call(
        eos_connect_query_product_user_id_mappings_info_from_native(data)
    );
    delete ctx;
}

static void EOS_CALL eos_connect_verify_id_token_callback_native(const EOS_Connect_VerifyIdTokenCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    if (ctx->callback) ctx->callback.value().call(eos_connect_verify_id_token_info_from_native(data));
    delete ctx;
}

gm_structs::EpicConnectIdToken eos_connect_copy_id_token(std::string_view local_user_id)
{
    eos_clear_last_error();

    gm_structs::EpicConnectIdToken out{};

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return out;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Connect_CopyIdToken: invalid local_user_id.");
        return out;
    }

    EOS_Connect_CopyIdTokenOptions opts{};
    opts.ApiVersion = EOS_CONNECT_COPYIDTOKEN_API_LATEST;
    opts.LocalUserId = local_user;

    EOS_Connect_IdToken* token = nullptr;
    const EOS_EResult result = EOS_Connect_CopyIdToken(connect, &opts, &token);
    if (result != EOS_EResult::EOS_Success || token == nullptr) {
        eos_set_last_error(eos_connect_result_string(result));
        return out;
    }

    out = eos_connect_id_token_from_native(token);
    EOS_Connect_IdToken_Release(token);
    return out;
}

gm_structs::EpicConnectExternalAccountInfo eos_connect_copy_product_user_info(std::string_view target_user_id)
{
    eos_clear_last_error();

    gm_structs::EpicConnectExternalAccountInfo out{};

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return out;
    }

    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);

    if (!target_user) {
        eos_set_last_error("EOS_Connect_CopyProductUserInfo: invalid target_user_id.");
        return out;
    }

    EOS_Connect_CopyProductUserInfoOptions opts{};
    opts.ApiVersion = EOS_CONNECT_COPYPRODUCTUSERINFO_API_LATEST;
    opts.TargetUserId = target_user;

    EOS_Connect_ExternalAccountInfo* info = nullptr;
    const EOS_EResult result = EOS_Connect_CopyProductUserInfo(connect, &opts, &info);
    if (result != EOS_EResult::EOS_Success || info == nullptr) {
        eos_set_last_error(eos_connect_result_string(result));
        return out;
    }

    out = eos_connect_external_account_info_from_native(info);
    EOS_Connect_ExternalAccountInfo_Release(info);
    return out;
}

gm_structs::EpicConnectExternalAccountInfo eos_connect_copy_product_user_external_account_by_index(
    std::string_view target_user_id,
    int64_t index)
{
    eos_clear_last_error();

    gm_structs::EpicConnectExternalAccountInfo out{};

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return out;
    }

    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);
    if (!target_user) {
        eos_set_last_error("EOS_Connect_CopyProductUserExternalAccountByIndex: invalid target_user_id.");
        return out;
    }

    EOS_Connect_CopyProductUserExternalAccountByIndexOptions opts{};
    opts.ApiVersion = EOS_CONNECT_COPYPRODUCTUSEREXTERNALACCOUNTBYINDEX_API_LATEST;
    opts.TargetUserId = target_user;
    opts.ExternalAccountInfoIndex = (uint32_t)index;

    EOS_Connect_ExternalAccountInfo* info = nullptr;
    const EOS_EResult result = EOS_Connect_CopyProductUserExternalAccountByIndex(connect, &opts, &info);
    if (result != EOS_EResult::EOS_Success || info == nullptr) {
        eos_set_last_error(eos_connect_result_string(result));
        return out;
    }

    out = eos_connect_external_account_info_from_native(info);
    EOS_Connect_ExternalAccountInfo_Release(info);
    return out;
}

gm_structs::EpicConnectExternalAccountInfo eos_connect_copy_product_user_external_account_by_account_type(
    std::string_view target_user_id,
    gm_enums::EpicExternalAccountType account_id_type)
{
    eos_clear_last_error();

    gm_structs::EpicConnectExternalAccountInfo out{};

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return out;
    }

    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);
    if (!target_user) {
        eos_set_last_error("EOS_Connect_CopyProductUserExternalAccountByAccountType: invalid target_user_id.");
        return out;
    }

    EOS_Connect_CopyProductUserExternalAccountByAccountTypeOptions opts{};
    opts.ApiVersion = EOS_CONNECT_COPYPRODUCTUSEREXTERNALACCOUNTBYACCOUNTTYPE_API_LATEST;
    opts.TargetUserId = target_user;
    opts.AccountIdType = (EOS_EExternalAccountType)account_id_type;

    EOS_Connect_ExternalAccountInfo* info = nullptr;
    const EOS_EResult result = EOS_Connect_CopyProductUserExternalAccountByAccountType(connect, &opts, &info);
    if (result != EOS_EResult::EOS_Success || info == nullptr) {
        eos_set_last_error(eos_connect_result_string(result));
        return out;
    }

    out = eos_connect_external_account_info_from_native(info);
    EOS_Connect_ExternalAccountInfo_Release(info);
    return out;
}

gm_structs::EpicConnectExternalAccountInfo eos_connect_copy_product_user_external_account_by_account_id(
    std::string_view target_user_id,
    std::string_view account_id)
{
    eos_clear_last_error();

    gm_structs::EpicConnectExternalAccountInfo out{};

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return out;
    }

    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);
    if (!target_user) {
        eos_set_last_error("EOS_Connect_CopyProductUserExternalAccountByAccountId: invalid target_user_id.");
        return out;
    }

    std::string account_id_storage(account_id);
    if (account_id_storage.empty()) {
        eos_set_last_error("EOS_Connect_CopyProductUserExternalAccountByAccountId: account_id is required.");
        return out;
    }

    EOS_Connect_CopyProductUserExternalAccountByAccountIdOptions opts{};
    opts.ApiVersion = EOS_CONNECT_COPYPRODUCTUSEREXTERNALACCOUNTBYACCOUNTID_API_LATEST;
    opts.TargetUserId = target_user;
    opts.AccountId = account_id_storage.c_str();

    EOS_Connect_ExternalAccountInfo* info = nullptr;
    const EOS_EResult result = EOS_Connect_CopyProductUserExternalAccountByAccountId(connect, &opts, &info);
    if (result != EOS_EResult::EOS_Success || info == nullptr) {
        eos_set_last_error(eos_connect_result_string(result));
        return out;
    }

    out = eos_connect_external_account_info_from_native(info);
    EOS_Connect_ExternalAccountInfo_Release(info);
    return out;
}

std::string eos_connect_get_product_user_id_mapping(
    std::string_view local_user_id,
    gm_enums::EpicExternalAccountType account_id_type,
    std::string_view target_external_user_id)
{
    eos_clear_last_error();

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return std::string();
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Connect_GetProductUserIdMapping: invalid local_user_id.");
        return std::string();
    }

    std::string target_external_user_id_storage(target_external_user_id);
    if (target_external_user_id_storage.empty()) {
        eos_set_last_error("EOS_Connect_GetProductUserIdMapping: target_external_user_id is required.");
        return std::string();
    }

    EOS_Connect_GetProductUserIdMappingOptions opts{};
    opts.ApiVersion = EOS_CONNECT_GETPRODUCTUSERIDMAPPING_API_LATEST;
    opts.LocalUserId = local_user;
    opts.AccountIdType = (EOS_EExternalAccountType)account_id_type;
    //TODO
    // opts.TargetExternalUserId = target_external_user_id_storage.c_str();

    return eos_connect_copy_string_with_fixed_retry(
        [&](char* out_buffer, int32_t* inout_len) -> EOS_EResult
        {
            return EOS_Connect_GetProductUserIdMapping(connect, &opts, out_buffer, inout_len);
        });
}

std::string eos_connect_get_external_account_mapping(
    std::string_view local_user_id,
    gm_enums::EpicExternalAccountType account_id_type,
    std::string_view target_external_user_id)
{
    eos_clear_last_error();

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return std::string();
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Connect_GetExternalAccountMapping: invalid local_user_id.");
        return std::string();
    }

    std::string target_external_user_id_storage(target_external_user_id);
    if (target_external_user_id_storage.empty()) {
        eos_set_last_error("EOS_Connect_GetExternalAccountMapping: target_external_user_id is required.");
        return std::string();
    }

    EOS_Connect_GetExternalAccountMappingsOptions opts{};
    opts.ApiVersion = EOS_CONNECT_GETEXTERNALACCOUNTMAPPINGS_API_LATEST;
    opts.LocalUserId = local_user;
    opts.AccountIdType = (EOS_EExternalAccountType)account_id_type;
    //TODO
    // opts.TargetExternalUserIds = nullptr;
    // opts.TargetExternalUserIdsCount = 0;

    // EOS_GetExternalAccountMapping is indexed through queried mappings; this wrapper
    // returns the first direct match from a queried single target if your SDK supports it.
    // If your SDK expects cached query results only, move this to the query-mappings pass.
    // EOS_ProductUserId id = EOS_Connect_GetExternalAccountMapping(
    //     connect,
    //     local_user,
    //     (EOS_EExternalAccountType)account_id_type,
    //     target_external_user_id_storage.c_str());

    // return eos_product_user_id_to_string_internal(id);

    return "";
}

void eos_connect_verify_id_token(std::string_view json_web_token, const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return;
    }

    std::string jwt_storage(json_web_token);
    if (jwt_storage.empty()) {
        eos_set_last_error("EOS_Connect_VerifyIdToken: json_web_token is required.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Connect_IdToken token{};
    token.ApiVersion = EOS_CONNECT_IDTOKEN_API_LATEST;
    token.JsonWebToken = jwt_storage.c_str();

    EOS_Connect_VerifyIdTokenOptions opts{};
    opts.ApiVersion = EOS_CONNECT_VERIFYIDTOKEN_API_LATEST;
    opts.IdToken = &token;

    EOS_Connect_VerifyIdToken(connect, &opts, ctx, &eos_connect_verify_id_token_callback_native);
}


void eos_connect_query_external_account_mappings(
    std::string_view local_user_id,
    gm_enums::EpicExternalAccountType account_id_type,
    const std::vector<std::string_view>& target_external_user_ids,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return;
    }

    EOS_ProductUserId local_user =
        eos_product_user_id_from_string_internal(local_user_id);

    if (!local_user) {
        eos_set_last_error("EOS_Connect_QueryExternalAccountMappings: invalid local_user_id.");
        return;
    }

    if (target_external_user_ids.empty()) {
        eos_set_last_error("EOS_Connect_QueryExternalAccountMappings: empty input.");
        return;
    }

    std::vector<std::string> storage;
    storage.reserve(target_external_user_ids.size());

    std::vector<const char*> ids;
    ids.reserve(target_external_user_ids.size());

    for (auto sv : target_external_user_ids)
        storage.emplace_back(sv);

    for (auto& s : storage)
        ids.push_back(s.c_str());

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Connect_QueryExternalAccountMappingsOptions opts{};
    opts.ApiVersion = EOS_CONNECT_QUERYEXTERNALACCOUNTMAPPINGS_API_LATEST;
    opts.LocalUserId = local_user;
    opts.AccountIdType = (EOS_EExternalAccountType)account_id_type;
    opts.ExternalAccountIds = ids.data();
    opts.ExternalAccountIdCount = (uint32_t)ids.size();

    EOS_Connect_QueryExternalAccountMappings(
        connect,
        &opts,
        ctx,
        &eos_connect_query_external_account_mappings_callback_native
    );
}

void eos_connect_query_product_user_id_mappings(
    std::string_view local_user_id,
    gm_enums::EpicExternalAccountType account_id_type,
    const std::vector<std::string_view>& target_product_user_ids,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HConnect connect = eos_connect_iface();
    if (!connect) {
        eos_set_last_error("EOS Connect interface unavailable.");
        return;
    }

    EOS_ProductUserId local_user =
        eos_product_user_id_from_string_internal(local_user_id);

    if (!local_user) {
        eos_set_last_error("EOS_Connect_QueryProductUserIdMappings: invalid local_user_id.");
        return;
    }

    if (target_product_user_ids.empty()) {
        eos_set_last_error("EOS_Connect_QueryProductUserIdMappings: empty input.");
        return;
    }

    std::vector<EOS_ProductUserId> ids;
    ids.reserve(target_product_user_ids.size());

    for (auto sv : target_product_user_ids)
    {
        EOS_ProductUserId id = eos_product_user_id_from_string_internal(sv);
        if (!id) {
            eos_set_last_error("EOS_Connect_QueryProductUserIdMappings: invalid id in array.");
            return;
        }
        ids.push_back(id);
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Connect_QueryProductUserIdMappingsOptions opts{};
    opts.ApiVersion = EOS_CONNECT_QUERYPRODUCTUSERIDMAPPINGS_API_LATEST;
    opts.LocalUserId = local_user;
    // opts.AccountIdType = (EOS_EExternalAccountType)account_id_type;
    opts.ProductUserIds = ids.data();
    opts.ProductUserIdCount = (uint32_t)ids.size();

    EOS_Connect_QueryProductUserIdMappings(
        connect,
        &opts,
        ctx,
        &eos_connect_query_product_user_id_mappings_callback_native
    );
}


// ============================================================
// EOS Connect Notify
// ============================================================

static GMFunction g_cb_connect_auth_expiration = nullptr;
static GMFunction g_cb_connect_login_status_changed = nullptr;

static gm_structs::EpicConnectAuthExpirationCallbackInfo
eos_connect_auth_expiration_from_native(
    const EOS_Connect_AuthExpirationCallbackInfo* p)
{
    gm_structs::EpicConnectAuthExpirationCallbackInfo out{};
    if (!p)
        return out;

    out.local_user_id =
        eos_product_user_id_to_string_internal(p->LocalUserId);

    return out;
}

static gm_structs::EpicConnectLoginStatusChangedCallbackInfo
eos_connect_login_status_changed_from_native(
    const EOS_Connect_LoginStatusChangedCallbackInfo* p)
{
    gm_structs::EpicConnectLoginStatusChangedCallbackInfo out{};
    if (!p)
        return out;

    out.local_user_id =
        eos_product_user_id_to_string_internal(p->LocalUserId);

    out.previous_status =
        (gm_enums::EpicLoginStatus)p->PreviousStatus;

    out.current_status =
        (gm_enums::EpicLoginStatus)p->CurrentStatus;

    return out;
}

static void EOS_CALL eos_connect_auth_expiration_callback(
    const EOS_Connect_AuthExpirationCallbackInfo* data)
{
    if (!data || !g_cb_connect_auth_expiration)
        return;

    g_cb_connect_auth_expiration.call(
        eos_connect_auth_expiration_from_native(data)
    );
}

static void EOS_CALL eos_connect_login_status_changed_callback(
    const EOS_Connect_LoginStatusChangedCallbackInfo* data)
{
    if (!data || !g_cb_connect_login_status_changed)
        return;

    g_cb_connect_login_status_changed.call(
        eos_connect_login_status_changed_from_native(data)
    );
}

uint64_t eos_connect_add_notify_auth_expiration(
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HConnect connect = eos_connect_iface();
    if (!connect)
    {
        eos_set_last_error("EOS Connect interface unavailable.");
        return 0;
    }

    g_cb_connect_auth_expiration = callback.value_or(GMFunction{});

    EOS_Connect_AddNotifyAuthExpirationOptions opts{};
    opts.ApiVersion = EOS_CONNECT_ADDNOTIFYAUTHEXPIRATION_API_LATEST;

    return (uint64_t)EOS_Connect_AddNotifyAuthExpiration(
        connect,
        &opts,
        nullptr,
        &eos_connect_auth_expiration_callback
    );
}

void eos_connect_remove_notify_auth_expiration(
    uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HConnect connect = eos_connect_iface();
    if (!connect)
    {
        eos_set_last_error("EOS Connect interface unavailable.");
        return;
    }

    EOS_Connect_RemoveNotifyAuthExpiration(
        connect,
        (EOS_NotificationId)notification_id
    );
}

uint64_t eos_connect_add_notify_login_status_changed(
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HConnect connect = eos_connect_iface();
    if (!connect)
    {
        eos_set_last_error("EOS Connect interface unavailable.");
        return 0;
    }

    g_cb_connect_login_status_changed = callback.value_or(GMFunction{});

    EOS_Connect_AddNotifyLoginStatusChangedOptions opts{};
    opts.ApiVersion = EOS_CONNECT_ADDNOTIFYLOGINSTATUSCHANGED_API_LATEST;

    return (uint64_t)EOS_Connect_AddNotifyLoginStatusChanged(
        connect,
        &opts,
        nullptr,
        &eos_connect_login_status_changed_callback
    );
}

void eos_connect_remove_notify_login_status_changed(
    uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HConnect connect = eos_connect_iface();
    if (!connect)
    {
        eos_set_last_error("EOS Connect interface unavailable.");
        return;
    }

    EOS_Connect_RemoveNotifyLoginStatusChanged(
        connect,
        (EOS_NotificationId)notification_id
    );
}
