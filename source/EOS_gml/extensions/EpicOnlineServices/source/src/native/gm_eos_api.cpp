#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>

#include <string>
#include <string_view>

using namespace gm::wire;
using namespace gm_structs;
using namespace gm_enums;

// ============================================================
// Internal helpers
// ============================================================

static std::string eos_result_string(EOS_EResult result)
{
    const char* s = EOS_EResult_ToString(result);
    return s ? std::string(s) : std::string();
}

static EOS_EpicAccountId eos_epic_account_id_from_string_internal(std::string_view account_id)
{
    std::string value(account_id);
    if (value.empty())
        return nullptr;
    return EOS_EpicAccountId_FromString(value.c_str());
}

static EOS_ProductUserId eos_product_user_id_from_string_internal(std::string_view product_user_id)
{
    std::string value(product_user_id);
    if (value.empty())
        return nullptr;
    return EOS_ProductUserId_FromString(value.c_str());
}

// ============================================================
// EOS API (No Interface)
// ============================================================

gm_enums::EpicResult eos_api_initialize(std::string_view product_name, std::string_view product_version)
{
    eos_clear_last_error();

    if (eos_api_is_initialized())
        return (gm_enums::EpicResult)EOS_EResult::EOS_Success;

    std::string product_name_storage(product_name);
    std::string product_version_storage(product_version);

    if (product_name_storage.empty()) {
        eos_set_last_error("EOS_Initialize: product_name is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    if (product_version_storage.empty()) {
        eos_set_last_error("EOS_Initialize: product_version is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_InitializeOptions opts{};
    opts.ApiVersion = EOS_INITIALIZE_API_LATEST;
    opts.ProductName = product_name_storage.c_str();
    opts.ProductVersion = product_version_storage.c_str();

    const EOS_EResult result = EOS_Initialize(&opts);
    if (result != EOS_EResult::EOS_Success) {
        eos_set_last_error(eos_result_string(result));
        eos_set_initialized(false);
        return (gm_enums::EpicResult)result;
    }

    eos_set_initialized(true);
    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_api_shutdown()
{
    eos_clear_last_error();

    const EOS_EResult result = EOS_Shutdown();
    if (result != EOS_EResult::EOS_Success) {
        eos_set_last_error(eos_result_string(result));
        return (gm_enums::EpicResult)result;
    }

    eos_set_initialized(false);
    return (gm_enums::EpicResult)result;
}

std::string eos_api_get_version()
{
    // Keep stub if EOS_GetVersion is not available in your SDK setup yet.
    // const char* s = EOS_GetVersion();
    // return s ? std::string(s) : std::string();
    return "";
}

std::string eos_api_result_to_string(gm_enums::EpicResult result)
{
    const char* s = EOS_EResult_ToString((EOS_EResult)result);
    return s ? std::string(s) : std::string();
}

bool eos_api_result_is_operation_complete(gm_enums::EpicResult result)
{
    return EOS_EResult_IsOperationComplete((EOS_EResult)result) != 0;
}

std::string eos_api_application_status_to_string(gm_enums::EpicApplicationStatus status)
{
    const char* s = EOS_EApplicationStatus_ToString((EOS_EApplicationStatus)status);
    return s ? std::string(s) : std::string();
}

std::string eos_api_network_status_to_string(gm_enums::EpicNetworkStatus status)
{
    const char* s = EOS_ENetworkStatus_ToString((EOS_ENetworkStatus)status);
    return s ? std::string(s) : std::string();
}

bool eos_api_epic_account_id_is_valid(std::string_view account_id)
{
    eos_clear_last_error();

    EOS_EpicAccountId id = eos_epic_account_id_from_string_internal(account_id);
    if (!id)
        return false;

    return EOS_EpicAccountId_IsValid(id) != 0;
}

bool eos_api_product_user_id_is_valid(std::string_view product_user_id)
{
    eos_clear_last_error();

    EOS_ProductUserId id = eos_product_user_id_from_string_internal(product_user_id);
    if (!id)
        return false;

    return EOS_ProductUserId_IsValid(id) != 0;
}