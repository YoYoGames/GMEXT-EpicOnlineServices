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

static std::string eos_platform_result_string(EOS_EResult result)
{
    const char* s = EOS_EResult_ToString(result);
    return s ? std::string(s) : std::string();
}

// Keep all EOS_Platform_Get*Interface helpers internal.
// These are for later section files and do NOT belong in spec.

static EOS_HAchievements eos_achievements_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetAchievementsInterface(p) : nullptr;
}

static EOS_HAuth eos_auth_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetAuthInterface(p) : nullptr;
}

static EOS_HConnect eos_connect_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetConnectInterface(p) : nullptr;
}

static EOS_HEcom eos_ecom_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetEcomInterface(p) : nullptr;
}

static EOS_HFriends eos_friends_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetFriendsInterface(p) : nullptr;
}

static EOS_HIntegratedPlatform eos_integratedplatform_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetIntegratedPlatformInterface(p) : nullptr;
}

static EOS_HKWS eos_kws_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetKWSInterface(p) : nullptr;
}

static EOS_HLeaderboards eos_leaderboards_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetLeaderboardsInterface(p) : nullptr;
}

static EOS_HLobby eos_lobby_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetLobbyInterface(p) : nullptr;
}

static EOS_HMetrics eos_metrics_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetMetricsInterface(p) : nullptr;
}

static EOS_HMods eos_mods_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetModsInterface(p) : nullptr;
}

static EOS_HP2P eos_p2p_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetP2PInterface(p) : nullptr;
}

static EOS_HPlayerDataStorage eos_playerdatastorage_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetPlayerDataStorageInterface(p) : nullptr;
}

static EOS_HPresence eos_presence_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetPresenceInterface(p) : nullptr;
}

static EOS_HRTC eos_rtc_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetRTCInterface(p) : nullptr;
}

static EOS_HSanctions eos_sanctions_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetSanctionsInterface(p) : nullptr;
}

static EOS_HSessions eos_sessions_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetSessionsInterface(p) : nullptr;
}

static EOS_HStats eos_stats_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetStatsInterface(p) : nullptr;
}

static EOS_HTitleStorage eos_titlestorage_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetTitleStorageInterface(p) : nullptr;
}

static EOS_HUI eos_ui_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetUIInterface(p) : nullptr;
}

static EOS_HUserInfo eos_userinfo_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetUserInfoInterface(p) : nullptr;
}

// ============================================================
// EOS Platform
// ============================================================

bool eos_platform_is_created()
{
    return eos_platform_get() != nullptr;
}

gm_enums::EpicResult eos_platform_create(
    bool is_server,
    std::string_view product_id,
    std::string_view sandbox_id,
    std::string_view deployment_id,
    std::string_view client_id,
    std::string_view client_secret)
{
    eos_clear_last_error();

    if (!eos_api_is_initialized()) {
        eos_set_last_error("EOS SDK not initialized.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_NotConfigured;
    }

    if (eos_platform_is_created()) {
        eos_set_last_error("EOS platform already created.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_AlreadyConfigured;
    }

    std::string product_id_storage(product_id);
    std::string sandbox_id_storage(sandbox_id);
    std::string deployment_id_storage(deployment_id);
    std::string client_id_storage(client_id);
    std::string client_secret_storage(client_secret);

    if (product_id_storage.empty()) {
        eos_set_last_error("EOS_Platform_Create: product_id is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    if (sandbox_id_storage.empty()) {
        eos_set_last_error("EOS_Platform_Create: sandbox_id is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    if (deployment_id_storage.empty()) {
        eos_set_last_error("EOS_Platform_Create: deployment_id is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    if (client_id_storage.empty()) {
        eos_set_last_error("EOS_Platform_Create: client_id is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    if (client_secret_storage.empty()) {
        eos_set_last_error("EOS_Platform_Create: client_secret is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_Platform_Options opts{};
    opts.ApiVersion = EOS_PLATFORM_OPTIONS_API_LATEST;
    opts.bIsServer = is_server ? EOS_TRUE : EOS_FALSE;
    opts.ProductId = product_id_storage.c_str();
    opts.SandboxId = sandbox_id_storage.c_str();
    opts.DeploymentId = deployment_id_storage.c_str();
    opts.ClientCredentials.ClientId = client_id_storage.c_str();
    opts.ClientCredentials.ClientSecret = client_secret_storage.c_str();

    EOS_HPlatform platform = EOS_Platform_Create(&opts);
    if (!platform) {
        eos_set_last_error("EOS_Platform_Create failed.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_UnexpectedError;
    }

    eos_platform_set(platform);
    return (gm_enums::EpicResult)EOS_EResult::EOS_Success;
}

void eos_platform_release()
{
    eos_clear_last_error();

    EOS_HPlatform platform = eos_platform_get();
    if (!platform)
        return;

    EOS_Platform_Release(platform);
    eos_platform_set(nullptr);
}

void eos_platform_tick()
{
    EOS_HPlatform platform = eos_platform_get();
    if (!platform)
        return;

    EOS_Platform_Tick(platform);
}

gm_enums::EpicResult eos_platform_check_for_launcher_and_restart()
{
    eos_clear_last_error();

    EOS_HPlatform platform = eos_platform_get();
    if (!platform)
        return (gm_enums::EpicResult)EOS_EResult::EOS_UnexpectedError;

    const EOS_EResult result = EOS_Platform_CheckForLauncherAndRestart(platform);
    if (result != EOS_EResult::EOS_Success) {
        eos_set_last_error(eos_platform_result_string(result));
    }

    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_platform_set_network_status(gm_enums::EpicNetworkStatus status)
{
    eos_clear_last_error();

    EOS_HPlatform platform = eos_platform_get();
    if (!platform) {
        eos_set_last_error("EOS platform not created.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_NotConfigured;
    }

    const EOS_EResult result =
        EOS_Platform_SetNetworkStatus(platform, (EOS_ENetworkStatus)status);

    if (result != EOS_EResult::EOS_Success) {
        eos_set_last_error(eos_platform_result_string(result));
    }

    return (gm_enums::EpicResult)result;
}