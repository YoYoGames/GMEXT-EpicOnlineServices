#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"
#include "gm_eos_common.h"
#include "gm_eos_platform_hooks.h"
#include "core/GMExtUtils.h"

#include <eos_sdk.h>

#include <algorithm>
#include <cctype>
#include <string>
#include <string_view>

using namespace gm::wire;
using namespace gm_structs;
using namespace gm_enums;

// ============================================================
// Platform cache directory
// ------------------------------------------------------------
// EOS_Platform_Create needs a writable absolute CacheDirectory. On desktop the
// caller-supplied path (GameMaker's working_directory) works, but on mobile that
// path is not a usable writable filesystem dir, so eos_platform_cache_dir()
// resolves it per target - see native/gm_eos_platform_hooks.h. It returns an
// empty string when the platform has nothing to offer, meaning "keep the
// caller-supplied value".
// ============================================================

// The actual directory eos_platform_create() ended up using (the caller's
// cache_directory on desktop, the platform-resolved writable dir on mobile),
// normalised to end with a separator. Exposed to GML via
// eos_platform_get_storage_directory() so callers don't have to track it.
static std::string g_eos_storage_dir;

static std::string eos_platform_with_trailing_sep(std::string dir)
{
    if (!dir.empty() && dir.back() != '/' && dir.back() != '\\')
        dir.push_back('/');
    return dir;
}

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

    // On mobile the caller's path isn't a usable writable dir; use the
    // platform-resolved cache dir instead (empty on desktop = keep caller value).
    if (const std::string platform_cache = eos_platform_cache_dir(); !platform_cache.empty())
        cache_directory_storage = platform_cache;

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

    // Remember the directory we actually used so GML can read it back via
    // eos_platform_get_storage_directory() for file_exists/sprite_add/etc.
    g_eos_storage_dir = eos_platform_with_trailing_sep(cache_directory_storage);

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
    g_eos_storage_dir.clear();
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
        eos_set_last_error(eos_result_string(result));
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
        eos_set_last_error(eos_result_string(result));
    }

    return (gm_enums::EpicResult)result;
}

// Returns the absolute, writable directory (with a trailing separator) that
// eos_platform_create() used: the caller-supplied cache_directory on desktop,
// or the platform-resolved writable dir on Android/iOS (where working_directory
// is the read-only bundle). Both the native file-transfer helpers and
// GameMaker's own file_exists/sprite_add use this same path, so GML callers can
// just prepend it to a filename instead of tracking the directory themselves.
// Returns an empty string if the platform has not been created yet.
std::string eos_platform_get_storage_directory()
{
    eos_clear_last_error();
    return g_eos_storage_dir;
}