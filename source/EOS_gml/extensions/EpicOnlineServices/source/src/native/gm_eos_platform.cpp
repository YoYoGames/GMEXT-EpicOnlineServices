#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"
#include "core/GMExtUtils.h"

#include <eos_sdk.h>

#include <algorithm>
#include <cctype>
#include <string>
#include <string_view>

#if defined(__ANDROID__)
#include <android/log.h>
#include <cstdlib>
#define EOS_ANDROID_LOG(...) __android_log_print(ANDROID_LOG_INFO, "yoyo", __VA_ARGS__)
#endif

using namespace gm::wire;
using namespace gm_structs;
using namespace gm_enums;

#if defined(__ANDROID__)
// On Android, GameMaker's working_directory is "assets/" (read-only APK assets),
// which EOS_Platform_Create cannot use for its writable cache. The Android
// runtime sets the TMPDIR environment variable to the app's private cache dir
// (e.g. /data/user/0/<pkg>/cache), which is writable -- no JNI required.
static std::string eos_android_cache_dir()
{
    if (const char* tmp = std::getenv("TMPDIR"); tmp && *tmp)
        return std::string(tmp);
    return {};
}
#endif // __ANDROID__

// ============================================================
// Extension options
// ============================================================

static constexpr const char* k_ext_name = "EpicOnlineServices";

static std::string eos_get_ext_option(const char* key)
{
    return gm::ExtUtils::GetExtensionOption(k_ext_name, key);
}

static bool eos_get_ext_option_bool(const char* key)
{
    std::string v = eos_get_ext_option(key);
    std::transform(v.begin(), v.end(), v.begin(),
        [](unsigned char c){ return (char)std::tolower(c); });
    return v == "true" || v == "1" || v == "yes";
}

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

gm_enums::EpicResult eos_platform_create(std::string_view cache_directory)
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

    // All credentials come from extension options; only cache_directory is runtime-supplied.
    const std::string product_id_storage      = eos_get_ext_option("ProductId");
    const std::string sandbox_id_storage      = eos_get_ext_option("SandboxId");
    const std::string deployment_id_storage   = eos_get_ext_option("DeploymentId");
    const std::string client_id_storage       = eos_get_ext_option("ClientCredentialsId");
    const std::string client_secret_storage   = eos_get_ext_option("ClientCredentialsSecret");
    const std::string encryption_key_storage  = eos_get_ext_option("EncryptionKey");
    std::string       cache_directory_storage(cache_directory);
    const bool        is_server               = eos_get_ext_option_bool("IsServer");

#if defined(__ANDROID__)
    // GameMaker's working_directory is the read-only "assets/" path on Android,
    // which EOS cannot write to. Override with the app's real writable cache dir.
    {
        const std::string android_cache = eos_android_cache_dir();
        if (!android_cache.empty()) {
            cache_directory_storage = android_cache;
            EOS_ANDROID_LOG("[EOS] platform CacheDirectory (android) = %s",
                            cache_directory_storage.c_str());
        } else {
            EOS_ANDROID_LOG("[EOS] WARNING: could not resolve Android cache dir; "
                            "using '%s' (EOS_Platform_Create will likely fail)",
                            cache_directory_storage.c_str());
        }
    }
#endif

    if (product_id_storage.empty()) {
        eos_set_last_error("EOS_Platform_Create: extension option 'ProductId' is empty.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    if (sandbox_id_storage.empty()) {
        eos_set_last_error("EOS_Platform_Create: extension option 'SandboxId' is empty.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    if (deployment_id_storage.empty()) {
        eos_set_last_error("EOS_Platform_Create: extension option 'DeploymentId' is empty.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    if (client_id_storage.empty()) {
        eos_set_last_error("EOS_Platform_Create: extension option 'ClientCredentialsId' is empty.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    if (client_secret_storage.empty()) {
        eos_set_last_error("EOS_Platform_Create: extension option 'ClientCredentialsSecret' is empty.");
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
    opts.EncryptionKey = encryption_key_storage.empty() ? nullptr : encryption_key_storage.c_str();
    opts.CacheDirectory = cache_directory_storage.empty() ? nullptr : cache_directory_storage.c_str();

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