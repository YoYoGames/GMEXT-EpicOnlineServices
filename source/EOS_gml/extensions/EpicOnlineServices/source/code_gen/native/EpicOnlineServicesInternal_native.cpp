// ##### extgen :: Auto-generated file do not edit!! #####

#include "EpicOnlineServicesInternal_native.h"
#include "EpicOnlineServicesInternal_exports.h"

using namespace gm_structs;
using namespace gm::wire::codec;

static gm::runtime::DispatchQueue __dispatch_queue;

// Internal function used for fetching dispatched function calls to GML
GMEXPORT double __EXT_NATIVE__EpicOnlineServices_invocation_handler(char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferWriter __bw{ __ret_buffer, static_cast<size_t>(__ret_buffer_length) };
    return __dispatch_queue.fetch(__bw);
}

GMEXPORT double __EXT_NATIVE__eos_test()
{
    auto&& __result = eos_test();
    return static_cast<double>(__result);
}

GMEXPORT char* __EXT_NATIVE__eos_api_last_error()
{
    static std::string __result;
    __result = eos_api_last_error();
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__eos_api_is_initialized()
{
    auto&& __result = eos_api_is_initialized();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__eos_api_initialize(char* product_name, char* product_version, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_api_initialize(product_name, product_version);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_api_shutdown(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_api_shutdown();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT char* __EXT_NATIVE__eos_api_get_version()
{
    static std::string __result;
    __result = eos_api_get_version();
    return (char*)__result.c_str();
}

GMEXPORT char* __EXT_NATIVE__eos_api_result_to_string(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: result, type: enum EpicResult
    gm_enums::EpicResult result = gm::wire::codec::readValue<gm_enums::EpicResult>(__br);

    static std::string __result;
    __result = eos_api_result_to_string(result);
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__eos_api_result_is_operation_complete(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: result, type: enum EpicResult
    gm_enums::EpicResult result = gm::wire::codec::readValue<gm_enums::EpicResult>(__br);

    auto&& __result = eos_api_result_is_operation_complete(result);
    return static_cast<double>(__result);
}

GMEXPORT char* __EXT_NATIVE__eos_api_application_status_to_string(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: status, type: enum EpicApplicationStatus
    gm_enums::EpicApplicationStatus status = gm::wire::codec::readValue<gm_enums::EpicApplicationStatus>(__br);

    static std::string __result;
    __result = eos_api_application_status_to_string(status);
    return (char*)__result.c_str();
}

GMEXPORT char* __EXT_NATIVE__eos_api_network_status_to_string(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: status, type: enum EpicNetworkStatus
    gm_enums::EpicNetworkStatus status = gm::wire::codec::readValue<gm_enums::EpicNetworkStatus>(__br);

    static std::string __result;
    __result = eos_api_network_status_to_string(status);
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__eos_api_epic_account_id_is_valid(char* account_id)
{
    auto&& __result = eos_api_epic_account_id_is_valid(account_id);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__eos_api_product_user_id_is_valid(char* product_user_id)
{
    auto&& __result = eos_api_product_user_id_is_valid(product_user_id);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__eos_platform_is_created()
{
    auto&& __result = eos_platform_is_created();
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__eos_platform_create(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: is_server, type: Bool
    bool is_server = gm::wire::codec::readValue<bool>(__br);

    // field: product_id, type: String
    std::string_view product_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: sandbox_id, type: String
    std::string_view sandbox_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: deployment_id, type: String
    std::string_view deployment_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: client_id, type: String
    std::string_view client_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: client_secret, type: String
    std::string_view client_secret = gm::wire::codec::readValue<std::string_view>(__br);

    auto&& __result = eos_platform_create(is_server, product_id, sandbox_id, deployment_id, client_id, client_secret);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_platform_release()
{
    eos_platform_release();
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_platform_tick()
{
    eos_platform_tick();
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_platform_check_for_launcher_and_restart(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_platform_check_for_launcher_and_restart();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_platform_set_network_status(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: status, type: enum EpicNetworkStatus
    gm_enums::EpicNetworkStatus status = gm::wire::codec::readValue<gm_enums::EpicNetworkStatus>(__br);

    auto&& __result = eos_platform_set_network_status(status);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_logging_set_callback(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_logging_set_callback(callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_logging_clear_callback()
{
    eos_logging_clear_callback();
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_logging_set_log_level(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: log_category, type: enum EpicLogCategory
    gm_enums::EpicLogCategory log_category = gm::wire::codec::readValue<gm_enums::EpicLogCategory>(__br);

    // field: log_level, type: enum EpicLogLevel
    gm_enums::EpicLogLevel log_level = gm::wire::codec::readValue<gm_enums::EpicLogLevel>(__br);

    auto&& __result = eos_logging_set_log_level(log_category, log_level);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_auth_login(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: credentials_id, type: String
    std::string_view credentials_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: credentials_token, type: String
    std::string_view credentials_token = gm::wire::codec::readValue<std::string_view>(__br);

    // field: credentials_type, type: enum EpicLoginCredentialType
    gm_enums::EpicLoginCredentialType credentials_type = gm::wire::codec::readValue<gm_enums::EpicLoginCredentialType>(__br);

    // field: external_credential_type, type: enum EpicExternalCredentialType
    gm_enums::EpicExternalCredentialType external_credential_type = gm::wire::codec::readValue<gm_enums::EpicExternalCredentialType>(__br);

    // field: scope_flags, type: enum EpicAuthScopeFlags
    gm_enums::EpicAuthScopeFlags scope_flags = gm::wire::codec::readValue<gm_enums::EpicAuthScopeFlags>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_auth_login(credentials_id, credentials_token, credentials_type, external_credential_type, scope_flags, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_auth_logout(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_auth_logout(local_user_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_auth_link_account(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: link_account_flags, type: enum EpicLinkAccountFlags
    gm_enums::EpicLinkAccountFlags link_account_flags = gm::wire::codec::readValue<gm_enums::EpicLinkAccountFlags>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_auth_link_account(local_user_id, link_account_flags, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_auth_delete_persistent_auth(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_auth_delete_persistent_auth(callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_auth_get_logged_in_accounts_count(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_auth_get_logged_in_accounts_count();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: Int64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT char* __EXT_NATIVE__eos_auth_get_logged_in_account_by_index(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: index, type: Int64
    std::int64_t index = gm::wire::codec::readValue<std::int64_t>(__br);

    static std::string __result;
    __result = eos_auth_get_logged_in_account_by_index(index);
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__eos_auth_get_login_status(char* local_user_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_auth_get_login_status(local_user_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicLoginStatus
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_auth_copy_id_token(char* local_user_id, char* target_account_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_auth_copy_id_token(local_user_id, target_account_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicAuthIdToken
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_auth_copy_user_auth_token(char* local_user_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_auth_copy_user_auth_token(local_user_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicAuthUserAuthToken
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_auth_query_id_token(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: target_account_id, type: String
    std::string_view target_account_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_auth_query_id_token(local_user_id, target_account_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_auth_verify_id_token(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: json_web_token, type: String
    std::string_view json_web_token = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_auth_verify_id_token(json_web_token, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_auth_verify_user_auth(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: access_token, type: String
    std::string_view access_token = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_auth_verify_user_auth(access_token, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_auth_add_notify_login_status_changed(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = eos_auth_add_notify_login_status_changed(callback);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_auth_remove_notify_login_status_changed(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: notification_id, type: UInt64
    std::uint64_t notification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_auth_remove_notify_login_status_changed(notification_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_connect_login(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: token, type: String
    std::string_view token = gm::wire::codec::readValue<std::string_view>(__br);

    // field: external_credential_type, type: enum EpicExternalCredentialType
    gm_enums::EpicExternalCredentialType external_credential_type = gm::wire::codec::readValue<gm_enums::EpicExternalCredentialType>(__br);

    // field: display_name, type: String
    std::string_view display_name = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_connect_login(token, external_credential_type, display_name, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_connect_create_user(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_connect_create_user(callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_connect_link_account(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_connect_link_account(local_user_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_connect_unlink_account(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_connect_unlink_account(local_user_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_connect_create_device_id(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: device_model, type: String
    std::string_view device_model = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_connect_create_device_id(device_model, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_connect_delete_device_id(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_connect_delete_device_id(callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_connect_transfer_device_id_account(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: primary_local_user_id, type: String
    std::string_view primary_local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: local_device_user_id, type: String
    std::string_view local_device_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_connect_transfer_device_id_account(primary_local_user_id, local_device_user_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_connect_logout(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_connect_logout(local_user_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_connect_get_logged_in_users_count(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_connect_get_logged_in_users_count();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: Int64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT char* __EXT_NATIVE__eos_connect_get_logged_in_user_by_index(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: index, type: Int64
    std::int64_t index = gm::wire::codec::readValue<std::int64_t>(__br);

    static std::string __result;
    __result = eos_connect_get_logged_in_user_by_index(index);
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__eos_connect_get_login_status(char* local_user_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_connect_get_login_status(local_user_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicLoginStatus
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_connect_copy_id_token(char* local_user_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_connect_copy_id_token(local_user_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicConnectIdToken
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_connect_copy_product_user_info(char* target_user_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_connect_copy_product_user_info(target_user_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicConnectExternalAccountInfo
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_connect_copy_product_user_external_account_by_index(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: target_user_id, type: String
    std::string_view target_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: index, type: Int64
    std::int64_t index = gm::wire::codec::readValue<std::int64_t>(__br);

    auto&& __result = eos_connect_copy_product_user_external_account_by_index(target_user_id, index);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicConnectExternalAccountInfo
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_connect_copy_product_user_external_account_by_account_type(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: target_user_id, type: String
    std::string_view target_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: account_id_type, type: enum EpicExternalAccountType
    gm_enums::EpicExternalAccountType account_id_type = gm::wire::codec::readValue<gm_enums::EpicExternalAccountType>(__br);

    auto&& __result = eos_connect_copy_product_user_external_account_by_account_type(target_user_id, account_id_type);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicConnectExternalAccountInfo
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_connect_copy_product_user_external_account_by_account_id(char* target_user_id, char* account_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_connect_copy_product_user_external_account_by_account_id(target_user_id, account_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicConnectExternalAccountInfo
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT char* __EXT_NATIVE__eos_connect_get_product_user_id_mapping(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: account_id_type, type: enum EpicExternalAccountType
    gm_enums::EpicExternalAccountType account_id_type = gm::wire::codec::readValue<gm_enums::EpicExternalAccountType>(__br);

    // field: target_external_user_id, type: String
    std::string_view target_external_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    static std::string __result;
    __result = eos_connect_get_product_user_id_mapping(local_user_id, account_id_type, target_external_user_id);
    return (char*)__result.c_str();
}

GMEXPORT char* __EXT_NATIVE__eos_connect_get_external_account_mapping(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: account_id_type, type: enum EpicExternalAccountType
    gm_enums::EpicExternalAccountType account_id_type = gm::wire::codec::readValue<gm_enums::EpicExternalAccountType>(__br);

    // field: target_external_user_id, type: String
    std::string_view target_external_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    static std::string __result;
    __result = eos_connect_get_external_account_mapping(local_user_id, account_id_type, target_external_user_id);
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__eos_connect_verify_id_token(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: json_web_token, type: String
    std::string_view json_web_token = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_connect_verify_id_token(json_web_token, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_connect_query_external_account_mappings(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: account_id_type, type: enum EpicExternalAccountType
    gm_enums::EpicExternalAccountType account_id_type = gm::wire::codec::readValue<gm_enums::EpicExternalAccountType>(__br);

    // field: target_external_user_ids, type: String[]
    std::vector<std::string_view> target_external_user_ids = gm::wire::codec::readVector<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_connect_query_external_account_mappings(local_user_id, account_id_type, target_external_user_ids, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_connect_query_product_user_id_mappings(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: account_id_type, type: enum EpicExternalAccountType
    gm_enums::EpicExternalAccountType account_id_type = gm::wire::codec::readValue<gm_enums::EpicExternalAccountType>(__br);

    // field: target_product_user_ids, type: String[]
    std::vector<std::string_view> target_product_user_ids = gm::wire::codec::readVector<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_connect_query_product_user_id_mappings(local_user_id, account_id_type, target_product_user_ids, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_connect_add_notify_auth_expiration(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = eos_connect_add_notify_auth_expiration(callback);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_connect_remove_notify_auth_expiration(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: notification_id, type: UInt64
    std::uint64_t notification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_connect_remove_notify_auth_expiration(notification_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_connect_add_notify_login_status_changed(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = eos_connect_add_notify_login_status_changed(callback);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_connect_remove_notify_login_status_changed(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: notification_id, type: UInt64
    std::uint64_t notification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_connect_remove_notify_login_status_changed(notification_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_friends_query_friends(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_friends_query_friends(local_user_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_friends_get_friends_count(char* local_user_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_friends_get_friends_count(local_user_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: Int64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT char* __EXT_NATIVE__eos_friends_get_friend_at_index(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: index, type: Int64
    std::int64_t index = gm::wire::codec::readValue<std::int64_t>(__br);

    static std::string __result;
    __result = eos_friends_get_friend_at_index(local_user_id, index);
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__eos_friends_get_status(char* local_user_id, char* target_user_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_friends_get_status(local_user_id, target_user_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicFriendsStatus
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_friends_add_notify_friends_update(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = eos_friends_add_notify_friends_update(callback);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_friends_remove_notify_friends_update(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: notification_id, type: UInt64
    std::uint64_t notification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_friends_remove_notify_friends_update(notification_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_user_info_query_user_info(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: target_user_id, type: String
    std::string_view target_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_user_info_query_user_info(local_user_id, target_user_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_user_info_copy_user_info(char* local_user_id, char* target_user_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_user_info_copy_user_info(local_user_id, target_user_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicUserInfo
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_user_info_get_local_platform_type(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_user_info_get_local_platform_type();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicExternalAccountType
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT char* __EXT_NATIVE__eos_user_info_copy_best_display_name(char* local_user_id, char* target_user_id)
{
    static std::string __result;
    __result = eos_user_info_copy_best_display_name(local_user_id, target_user_id);
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__eos_user_info_copy_external_user_info_by_index(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: target_user_id, type: String
    std::string_view target_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: index, type: Int64
    std::int64_t index = gm::wire::codec::readValue<std::int64_t>(__br);

    auto&& __result = eos_user_info_copy_external_user_info_by_index(local_user_id, target_user_id, index);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicUserInfoExternalUserInfo
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_user_info_copy_external_user_info_by_account_type(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: target_user_id, type: String
    std::string_view target_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: account_type, type: enum EpicExternalAccountType
    gm_enums::EpicExternalAccountType account_type = gm::wire::codec::readValue<gm_enums::EpicExternalAccountType>(__br);

    auto&& __result = eos_user_info_copy_external_user_info_by_account_type(local_user_id, target_user_id, account_type);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicUserInfoExternalUserInfo
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_user_info_copy_external_user_info_by_account_id(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: target_user_id, type: String
    std::string_view target_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: account_id, type: String
    std::string_view account_id = gm::wire::codec::readValue<std::string_view>(__br);

    auto&& __result = eos_user_info_copy_external_user_info_by_account_id(local_user_id, target_user_id, account_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicUserInfoExternalUserInfo
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_stats_ingest_stat(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: target_user_id, type: String
    std::string_view target_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: stat_name, type: String
    std::string_view stat_name = gm::wire::codec::readValue<std::string_view>(__br);

    // field: ingest_amount, type: Int64
    std::int64_t ingest_amount = gm::wire::codec::readValue<std::int64_t>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_stats_ingest_stat(local_user_id, target_user_id, stat_name, ingest_amount, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_stats_query_stats(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: target_user_id, type: String
    std::string_view target_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: start_time, type: Int64
    std::int64_t start_time = gm::wire::codec::readValue<std::int64_t>(__br);

    // field: end_time, type: Int64
    std::int64_t end_time = gm::wire::codec::readValue<std::int64_t>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_stats_query_stats(local_user_id, target_user_id, start_time, end_time, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_stats_get_stats_count(char* target_user_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_stats_get_stats_count(target_user_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: Int64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_stats_copy_stat_by_index(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: target_user_id, type: String
    std::string_view target_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: index, type: Int64
    std::int64_t index = gm::wire::codec::readValue<std::int64_t>(__br);

    auto&& __result = eos_stats_copy_stat_by_index(target_user_id, index);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicStatsStat
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_stats_copy_stat_by_name(char* target_user_id, char* name, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_stats_copy_stat_by_name(target_user_id, name);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicStatsStat
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_ui_show_friends(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_ui_show_friends(local_user_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_ui_show_native_profile(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: target_user_id, type: String
    std::string_view target_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_ui_show_native_profile(local_user_id, target_user_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_ui_acknowledge_event_id(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: ui_event_id, type: UInt64
    std::uint64_t ui_event_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_ui_acknowledge_event_id(ui_event_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_ui_set_display_preference(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: notification_location, type: enum EpicUINotificationLocation
    gm_enums::EpicUINotificationLocation notification_location = gm::wire::codec::readValue<gm_enums::EpicUINotificationLocation>(__br);

    eos_ui_set_display_preference(notification_location);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_ui_report_input_state(double button_down, double button_up, double button_left, double button_right, double button_accept, double button_cancel)
{
    eos_ui_report_input_state(static_cast<bool>(button_down), static_cast<bool>(button_up), static_cast<bool>(button_left), static_cast<bool>(button_right), static_cast<bool>(button_accept), static_cast<bool>(button_cancel));
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_ui_add_notify_display_settings_updated(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = eos_ui_add_notify_display_settings_updated(callback);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_ui_remove_notify_display_settings_updated(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: notification_id, type: UInt64
    std::uint64_t notification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_ui_remove_notify_display_settings_updated(notification_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_metrics_begin_player_session(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: product_user_id, type: String
    std::string_view product_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: account_id_type, type: enum EpicMetricsAccountIdType
    gm_enums::EpicMetricsAccountIdType account_id_type = gm::wire::codec::readValue<gm_enums::EpicMetricsAccountIdType>(__br);

    // field: controller_type, type: enum EpicUserControllerType
    gm_enums::EpicUserControllerType controller_type = gm::wire::codec::readValue<gm_enums::EpicUserControllerType>(__br);

    // field: server_ip, type: String
    std::string_view server_ip = gm::wire::codec::readValue<std::string_view>(__br);

    // field: game_session_id, type: String
    std::string_view game_session_id = gm::wire::codec::readValue<std::string_view>(__br);

    auto&& __result = eos_metrics_begin_player_session(product_user_id, account_id_type, controller_type, server_ip, game_session_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_metrics_end_player_session(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: product_user_id, type: String
    std::string_view product_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: account_id_type, type: enum EpicMetricsAccountIdType
    gm_enums::EpicMetricsAccountIdType account_id_type = gm::wire::codec::readValue<gm_enums::EpicMetricsAccountIdType>(__br);

    // field: controller_type, type: enum EpicUserControllerType
    gm_enums::EpicUserControllerType controller_type = gm::wire::codec::readValue<gm_enums::EpicUserControllerType>(__br);

    // field: server_ip, type: String
    std::string_view server_ip = gm::wire::codec::readValue<std::string_view>(__br);

    // field: game_session_id, type: String
    std::string_view game_session_id = gm::wire::codec::readValue<std::string_view>(__br);

    auto&& __result = eos_metrics_end_player_session(product_user_id, account_id_type, controller_type, server_ip, game_session_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_reports_send_player_behavior_report(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: reporter_user_id, type: String
    std::string_view reporter_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: reported_user_id, type: String
    std::string_view reported_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: category, type: enum EpicPlayerReportsCategory
    gm_enums::EpicPlayerReportsCategory category = gm::wire::codec::readValue<gm_enums::EpicPlayerReportsCategory>(__br);

    // field: message, type: String
    std::string_view message = gm::wire::codec::readValue<std::string_view>(__br);

    // field: context, type: String
    std::string_view context = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_reports_send_player_behavior_report(reporter_user_id, reported_user_id, category, message, context, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sanctions_query_active_player_sanctions(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: target_user_id, type: String
    std::string_view target_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_sanctions_query_active_player_sanctions(target_user_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sanctions_get_player_sanction_count(char* target_user_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_sanctions_get_player_sanction_count(target_user_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: Int64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sanctions_copy_player_sanction_by_index(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: target_user_id, type: String
    std::string_view target_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: index, type: Int64
    std::int64_t index = gm::wire::codec::readValue<std::int64_t>(__br);

    auto&& __result = eos_sanctions_copy_player_sanction_by_index(target_user_id, index);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicSanctionsPlayerSanction
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sanctions_create_player_sanction_appeal(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: reference_id, type: String
    std::string_view reference_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: reason, type: enum EpicSanctionAppealReason
    gm_enums::EpicSanctionAppealReason reason = gm::wire::codec::readValue<gm_enums::EpicSanctionAppealReason>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_sanctions_create_player_sanction_appeal(local_user_id, reference_id, reason, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_achievements_query_definitions(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_achievements_query_definitions(local_user_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_achievements_query_player_achievements(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: target_user_id, type: String
    std::string_view target_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_achievements_query_player_achievements(local_user_id, target_user_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_achievements_get_achievement_definition_count(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_achievements_get_achievement_definition_count();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: Int64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_achievements_get_player_achievement_count(char* local_user_id, char* target_user_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_achievements_get_player_achievement_count(local_user_id, target_user_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: Int64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_achievements_copy_achievement_definition_by_index(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: index, type: Int64
    std::int64_t index = gm::wire::codec::readValue<std::int64_t>(__br);

    auto&& __result = eos_achievements_copy_achievement_definition_by_index(index);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicAchievementsDefinition
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_achievements_copy_achievement_definition_v2_by_index(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: index, type: Int64
    std::int64_t index = gm::wire::codec::readValue<std::int64_t>(__br);

    auto&& __result = eos_achievements_copy_achievement_definition_v2_by_index(index);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicAchievementsDefinitionV2
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_achievements_copy_achievement_definition_by_id(char* achievement_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_achievements_copy_achievement_definition_by_id(achievement_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicAchievementsDefinition
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_achievements_copy_player_achievement_by_index(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: target_user_id, type: String
    std::string_view target_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: index, type: Int64
    std::int64_t index = gm::wire::codec::readValue<std::int64_t>(__br);

    auto&& __result = eos_achievements_copy_player_achievement_by_index(local_user_id, target_user_id, index);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicPlayerAchievement
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_achievements_copy_player_achievement_by_id(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: target_user_id, type: String
    std::string_view target_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: achievement_id, type: String
    std::string_view achievement_id = gm::wire::codec::readValue<std::string_view>(__br);

    auto&& __result = eos_achievements_copy_player_achievement_by_id(local_user_id, target_user_id, achievement_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicPlayerAchievement
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_achievements_unlock_achievements(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: user_id, type: String
    std::string_view user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: achievement_ids, type: String[]
    std::vector<std::string_view> achievement_ids = gm::wire::codec::readVector<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_achievements_unlock_achievements(user_id, achievement_ids, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_achievements_add_notify_achievements_unlocked_v2(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = eos_achievements_add_notify_achievements_unlocked_v2(callback);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_achievements_remove_notify_achievements_unlocked(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: notification_id, type: UInt64
    std::uint64_t notification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_achievements_remove_notify_achievements_unlocked(notification_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_leaderboards_query_definitions(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: start_time, type: Int64
    std::int64_t start_time = gm::wire::codec::readValue<std::int64_t>(__br);

    // field: end_time, type: Int64
    std::int64_t end_time = gm::wire::codec::readValue<std::int64_t>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_leaderboards_query_definitions(local_user_id, start_time, end_time, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_leaderboards_query_ranks(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: leaderboard_id, type: String
    std::string_view leaderboard_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_leaderboards_query_ranks(local_user_id, leaderboard_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_leaderboards_query_user_scores(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: stat_name, type: String
    std::string_view stat_name = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_leaderboards_query_user_scores(local_user_id, stat_name, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_leaderboards_get_definition_count(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_leaderboards_get_definition_count();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: Int64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_leaderboards_get_record_count(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_leaderboards_get_record_count();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: Int64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_leaderboards_get_user_score_count(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_leaderboards_get_user_score_count();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: Int64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_leaderboards_copy_definition_by_index(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: index, type: Int64
    std::int64_t index = gm::wire::codec::readValue<std::int64_t>(__br);

    auto&& __result = eos_leaderboards_copy_definition_by_index(index);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicLeaderboardDefinition
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_leaderboards_copy_definition_by_id(char* leaderboard_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_leaderboards_copy_definition_by_id(leaderboard_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicLeaderboardDefinition
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_leaderboards_copy_record_by_index(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: index, type: Int64
    std::int64_t index = gm::wire::codec::readValue<std::int64_t>(__br);

    auto&& __result = eos_leaderboards_copy_record_by_index(index);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicLeaderboardRecord
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_leaderboards_copy_record_by_user_id(char* user_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_leaderboards_copy_record_by_user_id(user_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicLeaderboardRecord
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_leaderboards_copy_user_score_by_index(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: index, type: Int64
    std::int64_t index = gm::wire::codec::readValue<std::int64_t>(__br);

    auto&& __result = eos_leaderboards_copy_user_score_by_index(index);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicLeaderboardUserScore
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_presence_query_presence(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: target_user_id, type: String
    std::string_view target_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_presence_query_presence(local_user_id, target_user_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_presence_has_presence(char* local_user_id, char* target_user_id)
{
    auto&& __result = eos_presence_has_presence(local_user_id, target_user_id);
    return static_cast<double>(__result);
}

GMEXPORT double __EXT_NATIVE__eos_presence_copy_presence(char* local_user_id, char* target_user_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_presence_copy_presence(local_user_id, target_user_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicPresenceInfo
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_presence_create_presence_modification(char* local_user_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_presence_create_presence_modification(local_user_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_presence_modification_release(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: modification_id, type: UInt64
    std::uint64_t modification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_presence_modification_release(modification_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_presence_modification_set_status(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: modification_id, type: UInt64
    std::uint64_t modification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: status, type: enum EpicPresenceStatus
    gm_enums::EpicPresenceStatus status = gm::wire::codec::readValue<gm_enums::EpicPresenceStatus>(__br);

    auto&& __result = eos_presence_modification_set_status(modification_id, status);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_presence_modification_set_raw_rich_text(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: modification_id, type: UInt64
    std::uint64_t modification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: rich_text, type: String
    std::string_view rich_text = gm::wire::codec::readValue<std::string_view>(__br);

    auto&& __result = eos_presence_modification_set_raw_rich_text(modification_id, rich_text);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_presence_modification_set_data(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: modification_id, type: UInt64
    std::uint64_t modification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: key, type: String
    std::string_view key = gm::wire::codec::readValue<std::string_view>(__br);

    // field: value, type: String
    std::string_view value = gm::wire::codec::readValue<std::string_view>(__br);

    auto&& __result = eos_presence_modification_set_data(modification_id, key, value);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_presence_modification_delete_data(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: modification_id, type: UInt64
    std::uint64_t modification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: key, type: String
    std::string_view key = gm::wire::codec::readValue<std::string_view>(__br);

    auto&& __result = eos_presence_modification_delete_data(modification_id, key);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_presence_set_presence(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: modification_id, type: UInt64
    std::uint64_t modification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_presence_set_presence(local_user_id, modification_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_presence_add_notify_on_presence_changed(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = eos_presence_add_notify_on_presence_changed(callback);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_presence_remove_notify_on_presence_changed(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: notification_id, type: UInt64
    std::uint64_t notification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_presence_remove_notify_on_presence_changed(notification_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_presence_add_notify_join_game_accepted(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = eos_presence_add_notify_join_game_accepted(callback);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_presence_remove_notify_join_game_accepted(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: notification_id, type: UInt64
    std::uint64_t notification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_presence_remove_notify_join_game_accepted(notification_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_create_session_modification(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: session_name, type: String
    std::string_view session_name = gm::wire::codec::readValue<std::string_view>(__br);

    // field: session_id, type: String
    std::string_view session_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: bucket_id, type: String
    std::string_view bucket_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: max_players, type: Int64
    std::int64_t max_players = gm::wire::codec::readValue<std::int64_t>(__br);

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: presence_enabled, type: Bool
    bool presence_enabled = gm::wire::codec::readValue<bool>(__br);

    // field: sanctions_enabled, type: Bool
    bool sanctions_enabled = gm::wire::codec::readValue<bool>(__br);

    // field: allowed_platform_ids, type: UInt32[]
    std::vector<std::uint32_t> allowed_platform_ids = gm::wire::codec::readVector<std::uint32_t>(__br);

    auto&& __result = eos_sessions_create_session_modification(session_name, session_id, bucket_id, max_players, local_user_id, presence_enabled, sanctions_enabled, allowed_platform_ids);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_session_modification_release(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: modification_id, type: UInt64
    std::uint64_t modification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_sessions_session_modification_release(modification_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_update_session(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: modification_id, type: UInt64
    std::uint64_t modification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_sessions_update_session(modification_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_destroy_session(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: session_name, type: String
    std::string_view session_name = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_sessions_destroy_session(session_name, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_start_session(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: session_name, type: String
    std::string_view session_name = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_sessions_start_session(session_name, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_end_session(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: session_name, type: String
    std::string_view session_name = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_sessions_end_session(session_name, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_join_session(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: session_name, type: String
    std::string_view session_name = gm::wire::codec::readValue<std::string_view>(__br);

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_sessions_join_session(session_name, local_user_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_register_players(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: session_name, type: String
    std::string_view session_name = gm::wire::codec::readValue<std::string_view>(__br);

    // field: target_user_ids, type: String[]
    std::vector<std::string_view> target_user_ids = gm::wire::codec::readVector<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_sessions_register_players(session_name, target_user_ids, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_unregister_players(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: session_name, type: String
    std::string_view session_name = gm::wire::codec::readValue<std::string_view>(__br);

    // field: target_user_ids, type: String[]
    std::vector<std::string_view> target_user_ids = gm::wire::codec::readVector<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_sessions_unregister_players(session_name, target_user_ids, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_create_session_search(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: max_search_results, type: Int64
    std::int64_t max_search_results = gm::wire::codec::readValue<std::int64_t>(__br);

    auto&& __result = eos_sessions_create_session_search(max_search_results);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_session_search_release(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: search_id, type: UInt64
    std::uint64_t search_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_sessions_session_search_release(search_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_session_search_set_session_id(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: search_id, type: UInt64
    std::uint64_t search_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: session_id, type: String
    std::string_view session_id = gm::wire::codec::readValue<std::string_view>(__br);

    auto&& __result = eos_sessions_session_search_set_session_id(search_id, session_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_session_search_set_target_user_id(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: search_id, type: UInt64
    std::uint64_t search_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: target_user_id, type: String
    std::string_view target_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    auto&& __result = eos_sessions_session_search_set_target_user_id(search_id, target_user_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_session_search_find(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: search_id, type: UInt64
    std::uint64_t search_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_sessions_session_search_find(search_id, local_user_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_session_search_copy_search_result_by_index(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: search_id, type: UInt64
    std::uint64_t search_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: index, type: Int64
    std::int64_t index = gm::wire::codec::readValue<std::int64_t>(__br);

    auto&& __result = eos_sessions_session_search_copy_search_result_by_index(search_id, index);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_session_details_release(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: session_details_id, type: UInt64
    std::uint64_t session_details_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_sessions_session_details_release(session_details_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_copy_active_session_handle(char* session_name, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_sessions_copy_active_session_handle(session_name);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_active_session_release(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: active_session_id, type: UInt64
    std::uint64_t active_session_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_sessions_active_session_release(active_session_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_active_session_copy_info(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: active_session_id, type: UInt64
    std::uint64_t active_session_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    auto&& __result = eos_sessions_active_session_copy_info(active_session_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicActiveSessionInfo
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_copy_session_handle_by_invite_id(char* invite_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_sessions_copy_session_handle_by_invite_id(invite_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_copy_session_handle_by_ui_event_id(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: ui_event_id, type: UInt64
    std::uint64_t ui_event_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    auto&& __result = eos_sessions_copy_session_handle_by_ui_event_id(ui_event_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_session_details_copy_info(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: session_details_id, type: UInt64
    std::uint64_t session_details_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    auto&& __result = eos_sessions_session_details_copy_info(session_details_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicSessionDetailsInfo
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_add_notify_session_invite_received(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = eos_sessions_add_notify_session_invite_received(callback);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_remove_notify_session_invite_received(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: notification_id, type: UInt64
    std::uint64_t notification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_sessions_remove_notify_session_invite_received(notification_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_add_notify_session_invite_accepted(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = eos_sessions_add_notify_session_invite_accepted(callback);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_remove_notify_session_invite_accepted(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: notification_id, type: UInt64
    std::uint64_t notification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_sessions_remove_notify_session_invite_accepted(notification_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_add_notify_join_session_accepted(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = eos_sessions_add_notify_join_session_accepted(callback);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_sessions_remove_notify_join_session_accepted(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: notification_id, type: UInt64
    std::uint64_t notification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_sessions_remove_notify_join_session_accepted(notification_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_create_lobby(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: max_lobby_members, type: Int64
    std::int64_t max_lobby_members = gm::wire::codec::readValue<std::int64_t>(__br);

    // field: permission_level, type: enum EpicLobbyPermissionLevel
    gm_enums::EpicLobbyPermissionLevel permission_level = gm::wire::codec::readValue<gm_enums::EpicLobbyPermissionLevel>(__br);

    // field: presence_enabled, type: Bool
    bool presence_enabled = gm::wire::codec::readValue<bool>(__br);

    // field: allow_invites, type: Bool
    bool allow_invites = gm::wire::codec::readValue<bool>(__br);

    // field: bucket_id, type: String
    std::string_view bucket_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_lobby_create_lobby(local_user_id, max_lobby_members, permission_level, presence_enabled, allow_invites, bucket_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_destroy_lobby(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: lobby_id, type: String
    std::string_view lobby_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_lobby_destroy_lobby(lobby_id, local_user_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_join_lobby(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: lobby_id, type: String
    std::string_view lobby_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: presence_enabled, type: Bool
    bool presence_enabled = gm::wire::codec::readValue<bool>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_lobby_join_lobby(lobby_id, local_user_id, presence_enabled, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_leave_lobby(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: lobby_id, type: String
    std::string_view lobby_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_lobby_leave_lobby(lobby_id, local_user_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_update_lobby_modification(char* lobby_id, char* local_user_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_lobby_update_lobby_modification(lobby_id, local_user_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_lobby_modification_release(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: modification_id, type: UInt64
    std::uint64_t modification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_lobby_lobby_modification_release(modification_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_update_lobby(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: lobby_id, type: String
    std::string_view lobby_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: modification_id, type: UInt64
    std::uint64_t modification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_lobby_update_lobby(lobby_id, modification_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_lobby_modification_set_permission_level(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: modification_id, type: UInt64
    std::uint64_t modification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: permission_level, type: enum EpicLobbyPermissionLevel
    gm_enums::EpicLobbyPermissionLevel permission_level = gm::wire::codec::readValue<gm_enums::EpicLobbyPermissionLevel>(__br);

    auto&& __result = eos_lobby_lobby_modification_set_permission_level(modification_id, permission_level);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_lobby_modification_set_max_members(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: modification_id, type: UInt64
    std::uint64_t modification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: max_members, type: Int64
    std::int64_t max_members = gm::wire::codec::readValue<std::int64_t>(__br);

    auto&& __result = eos_lobby_lobby_modification_set_max_members(modification_id, max_members);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_lobby_modification_set_bucket_id(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: modification_id, type: UInt64
    std::uint64_t modification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: bucket_id, type: String
    std::string_view bucket_id = gm::wire::codec::readValue<std::string_view>(__br);

    auto&& __result = eos_lobby_lobby_modification_set_bucket_id(modification_id, bucket_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_lobby_modification_set_invites_allowed(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: modification_id, type: UInt64
    std::uint64_t modification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: invites_allowed, type: Bool
    bool invites_allowed = gm::wire::codec::readValue<bool>(__br);

    auto&& __result = eos_lobby_lobby_modification_set_invites_allowed(modification_id, invites_allowed);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_lobby_modification_add_attribute(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: modification_id, type: UInt64
    std::uint64_t modification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: key, type: String
    std::string_view key = gm::wire::codec::readValue<std::string_view>(__br);

    // field: value, type: String
    std::string_view value = gm::wire::codec::readValue<std::string_view>(__br);

    // field: visibility, type: enum EpicLobbyAttributeVisibility
    gm_enums::EpicLobbyAttributeVisibility visibility = gm::wire::codec::readValue<gm_enums::EpicLobbyAttributeVisibility>(__br);

    auto&& __result = eos_lobby_lobby_modification_add_attribute(modification_id, key, value, visibility);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_lobby_modification_remove_attribute(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: modification_id, type: UInt64
    std::uint64_t modification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: key, type: String
    std::string_view key = gm::wire::codec::readValue<std::string_view>(__br);

    auto&& __result = eos_lobby_lobby_modification_remove_attribute(modification_id, key);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_lobby_modification_add_member_attribute(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: modification_id, type: UInt64
    std::uint64_t modification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: key, type: String
    std::string_view key = gm::wire::codec::readValue<std::string_view>(__br);

    // field: value, type: String
    std::string_view value = gm::wire::codec::readValue<std::string_view>(__br);

    // field: visibility, type: enum EpicLobbyAttributeVisibility
    gm_enums::EpicLobbyAttributeVisibility visibility = gm::wire::codec::readValue<gm_enums::EpicLobbyAttributeVisibility>(__br);

    auto&& __result = eos_lobby_lobby_modification_add_member_attribute(modification_id, key, value, visibility);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_lobby_modification_remove_member_attribute(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: modification_id, type: UInt64
    std::uint64_t modification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: key, type: String
    std::string_view key = gm::wire::codec::readValue<std::string_view>(__br);

    auto&& __result = eos_lobby_lobby_modification_remove_member_attribute(modification_id, key);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_promote_member(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: lobby_id, type: String
    std::string_view lobby_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: target_user_id, type: String
    std::string_view target_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_lobby_promote_member(lobby_id, local_user_id, target_user_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_kick_member(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: lobby_id, type: String
    std::string_view lobby_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: target_user_id, type: String
    std::string_view target_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_lobby_kick_member(lobby_id, local_user_id, target_user_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_create_lobby_search(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: max_results, type: Int64
    std::int64_t max_results = gm::wire::codec::readValue<std::int64_t>(__br);

    auto&& __result = eos_lobby_create_lobby_search(max_results);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_lobby_search_release(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: search_id, type: UInt64
    std::uint64_t search_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_lobby_lobby_search_release(search_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_lobby_search_set_lobby_id(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: search_id, type: UInt64
    std::uint64_t search_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: lobby_id, type: String
    std::string_view lobby_id = gm::wire::codec::readValue<std::string_view>(__br);

    auto&& __result = eos_lobby_lobby_search_set_lobby_id(search_id, lobby_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_lobby_search_set_target_user_id(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: search_id, type: UInt64
    std::uint64_t search_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: target_user_id, type: String
    std::string_view target_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    auto&& __result = eos_lobby_lobby_search_set_target_user_id(search_id, target_user_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_lobby_search_set_parameter(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: search_id, type: UInt64
    std::uint64_t search_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: key, type: String
    std::string_view key = gm::wire::codec::readValue<std::string_view>(__br);

    // field: value, type: String
    std::string_view value = gm::wire::codec::readValue<std::string_view>(__br);

    // field: comparison_op, type: enum EpicComparisonOp
    gm_enums::EpicComparisonOp comparison_op = gm::wire::codec::readValue<gm_enums::EpicComparisonOp>(__br);

    auto&& __result = eos_lobby_lobby_search_set_parameter(search_id, key, value, comparison_op);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_lobby_search_remove_parameter(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: search_id, type: UInt64
    std::uint64_t search_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: key, type: String
    std::string_view key = gm::wire::codec::readValue<std::string_view>(__br);

    // field: comparison_op, type: enum EpicComparisonOp
    gm_enums::EpicComparisonOp comparison_op = gm::wire::codec::readValue<gm_enums::EpicComparisonOp>(__br);

    auto&& __result = eos_lobby_lobby_search_remove_parameter(search_id, key, comparison_op);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_lobby_search_set_max_results(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: search_id, type: UInt64
    std::uint64_t search_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: max_results, type: Int64
    std::int64_t max_results = gm::wire::codec::readValue<std::int64_t>(__br);

    auto&& __result = eos_lobby_lobby_search_set_max_results(search_id, max_results);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum EpicResult
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_lobby_search_find(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: search_id, type: UInt64
    std::uint64_t search_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    eos_lobby_lobby_search_find(search_id, local_user_id, callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_lobby_search_get_search_result_count(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: search_id, type: UInt64
    std::uint64_t search_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    auto&& __result = eos_lobby_lobby_search_get_search_result_count(search_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: Int64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_lobby_search_copy_search_result_by_index(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: search_id, type: UInt64
    std::uint64_t search_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: index, type: Int64
    std::int64_t index = gm::wire::codec::readValue<std::int64_t>(__br);

    auto&& __result = eos_lobby_lobby_search_copy_search_result_by_index(search_id, index);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_details_release(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: lobby_details_id, type: UInt64
    std::uint64_t lobby_details_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_lobby_details_release(lobby_details_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_copy_lobby_details_handle(char* lobby_id, char* local_user_id, char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = eos_lobby_copy_lobby_details_handle(lobby_id, local_user_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_details_copy_info(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: lobby_details_id, type: UInt64
    std::uint64_t lobby_details_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    auto&& __result = eos_lobby_details_copy_info(lobby_details_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: struct EpicLobbyDetailsInfo
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_details_get_member_count(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: lobby_details_id, type: UInt64
    std::uint64_t lobby_details_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    auto&& __result = eos_lobby_details_get_member_count(lobby_details_id);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: Int64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT char* __EXT_NATIVE__eos_lobby_details_get_member_by_index(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: lobby_details_id, type: UInt64
    std::uint64_t lobby_details_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    // field: index, type: Int64
    std::int64_t index = gm::wire::codec::readValue<std::int64_t>(__br);

    static std::string __result;
    __result = eos_lobby_details_get_member_by_index(lobby_details_id, index);
    return (char*)__result.c_str();
}

GMEXPORT char* __EXT_NATIVE__eos_lobby_details_get_lobby_owner(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: lobby_details_id, type: UInt64
    std::uint64_t lobby_details_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    static std::string __result;
    __result = eos_lobby_details_get_lobby_owner(lobby_details_id);
    return (char*)__result.c_str();
}

GMEXPORT double __EXT_NATIVE__eos_lobby_add_notify_lobby_update_received(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = eos_lobby_add_notify_lobby_update_received(local_user_id, callback);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_remove_notify_lobby_update_received(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: notification_id, type: UInt64
    std::uint64_t notification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_lobby_remove_notify_lobby_update_received(notification_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_add_notify_lobby_member_update_received(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = eos_lobby_add_notify_lobby_member_update_received(local_user_id, callback);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_remove_notify_lobby_member_update_received(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: notification_id, type: UInt64
    std::uint64_t notification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_lobby_remove_notify_lobby_member_update_received(notification_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_add_notify_lobby_member_status_received(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = eos_lobby_add_notify_lobby_member_status_received(local_user_id, callback);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_remove_notify_lobby_member_status_received(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: notification_id, type: UInt64
    std::uint64_t notification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_lobby_remove_notify_lobby_member_status_received(notification_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_add_notify_join_lobby_accepted(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = eos_lobby_add_notify_join_lobby_accepted(callback);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_remove_notify_join_lobby_accepted(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: notification_id, type: UInt64
    std::uint64_t notification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_lobby_remove_notify_join_lobby_accepted(notification_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_add_notify_leave_lobby_requested(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = eos_lobby_add_notify_leave_lobby_requested(local_user_id, callback);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_remove_notify_leave_lobby_requested(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: notification_id, type: UInt64
    std::uint64_t notification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_lobby_remove_notify_leave_lobby_requested(notification_id);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_add_notify_send_lobby_native_invite_requested(char* __arg_buffer, double __arg_buffer_length, char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: local_user_id, type: String
    std::string_view local_user_id = gm::wire::codec::readValue<std::string_view>(__br);

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    auto&& __result = eos_lobby_add_notify_send_lobby_native_invite_requested(local_user_id, callback);
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: UInt64
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT double __EXT_NATIVE__eos_lobby_remove_notify_send_lobby_native_invite_requested(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: notification_id, type: UInt64
    std::uint64_t notification_id = gm::wire::codec::readValue<std::uint64_t>(__br);

    eos_lobby_remove_notify_send_lobby_native_invite_requested(notification_id);
    return 0;
}

