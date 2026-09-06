#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_metrics.h>

#include <string>
#include <string_view>

using namespace gm::wire;
using namespace gm_structs;
using namespace gm_enums;

// ============================================================
// Internal helpers
// ============================================================

static EOS_HMetrics eos_metrics_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetMetricsInterface(p) : nullptr;
}

// ============================================================
// EOS Metrics
// ============================================================

gm_enums::EpicResult eos_metrics_begin_player_session(
    std::string_view account_id,
    gm_enums::EpicMetricsAccountIdType account_id_type,
    std::string_view display_name,
    gm_enums::EpicUserControllerType controller_type,
    std::string_view server_ip,
    std::string_view game_session_id)
{
    eos_clear_last_error();

    EOS_HMetrics metrics = eos_metrics_iface();
    if (!metrics) {
        eos_set_last_error("EOS Metrics interface unavailable.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_NotConfigured;
    }

    std::string account_id_storage(account_id);
    std::string server_ip_storage(server_ip);
    std::string game_session_id_storage(game_session_id);
    std::string display_name_storage(display_name);

    if (account_id_storage.empty()) {
        eos_set_last_error("EOS_Metrics_BeginPlayerSession: account_id is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_Metrics_BeginPlayerSessionOptions opts{};
    opts.ApiVersion = EOS_METRICS_BEGINPLAYERSESSION_API_LATEST;
    opts.AccountIdType = (EOS_EMetricsAccountIdType)account_id_type;
    opts.ControllerType = (EOS_EUserControllerType)controller_type;
    opts.ServerIp = server_ip_storage.empty() ? nullptr : server_ip_storage.c_str();
    opts.GameSessionId = game_session_id_storage.empty() ? nullptr : game_session_id_storage.c_str();
    opts.DisplayName = display_name_storage.empty() ? nullptr : display_name_storage.c_str();

    if ((int)account_id_type == 0) {
        EOS_EpicAccountId epic_id = EOS_EpicAccountId_FromString(account_id_storage.c_str());
        if (!EOS_EpicAccountId_IsValid(epic_id)) {
            eos_set_last_error("EOS_Metrics_BeginPlayerSession: invalid Epic account_id.");
            return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
        }
        opts.AccountId.Epic = epic_id;
    } else {
        opts.AccountId.External = account_id_storage.c_str();
    }

    const EOS_EResult result = EOS_Metrics_BeginPlayerSession(metrics, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Metrics_BeginPlayerSession failed.");
    }

    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_metrics_end_player_session(
    std::string_view account_id,
    gm_enums::EpicMetricsAccountIdType account_id_type,
    gm_enums::EpicUserControllerType,
    std::string_view,
    std::string_view)
{
    eos_clear_last_error();

    EOS_HMetrics metrics = eos_metrics_iface();
    if (!metrics) {
        eos_set_last_error("EOS Metrics interface unavailable.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_NotConfigured;
    }

    std::string account_id_storage(account_id);

    if (account_id_storage.empty()) {
        eos_set_last_error("EOS_Metrics_EndPlayerSession: account_id is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_Metrics_EndPlayerSessionOptions opts{};
    opts.ApiVersion = EOS_METRICS_ENDPLAYERSESSION_API_LATEST;
    opts.AccountIdType = (EOS_EMetricsAccountIdType)account_id_type;

    if ((int)account_id_type == 0) {
        EOS_EpicAccountId epic_id = EOS_EpicAccountId_FromString(account_id_storage.c_str());
        if (!EOS_EpicAccountId_IsValid(epic_id)) {
            eos_set_last_error("EOS_Metrics_EndPlayerSession: invalid Epic account_id.");
            return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
        }
        opts.AccountId.Epic = epic_id;
    } else {
        opts.AccountId.External = account_id_storage.c_str();
    }

    const EOS_EResult result = EOS_Metrics_EndPlayerSession(metrics, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Metrics_EndPlayerSession failed.");
    }

    return (gm_enums::EpicResult)result;
}