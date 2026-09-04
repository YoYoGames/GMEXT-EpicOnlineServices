#include "native/gm_eos_platform_hooks.h"

#include <eos_Android.h>

#include <cstdlib>
#include <new>

// Android requires system-specific init options; EOS_Initialize returns
// EOS_UnexpectedError if SystemInitializeOptions is null on this platform. The
// struct has to outlive the EOS_Initialize call, which now happens in the caller,
// so it is heap-allocated and freed once that call returns.
void* eos_platform_initialize_options_create(EOS_InitializeOptions& opts)
{
    auto* android_opts = new (std::nothrow) EOS_Android_InitializeOptions{};
    if (!android_opts)
        return nullptr;

    android_opts->ApiVersion = EOS_ANDROID_INITIALIZEOPTIONS_API_LATEST;
    android_opts->Reserved = nullptr;
    android_opts->OptionalInternalDirectory = nullptr;
    android_opts->OptionalExternalDirectory = nullptr;

    opts.SystemInitializeOptions = android_opts;
    return android_opts;
}

void eos_platform_initialize_options_free(void* handle)
{
    delete static_cast<EOS_Android_InitializeOptions*>(handle);
}

// Android's runtime sets TMPDIR to the app's private cache dir
// (e.g. /data/user/0/<pkg>/cache). GameMaker's working_directory is "assets/"
// (read-only APK assets), which EOS cannot write to.
std::string eos_platform_cache_dir()
{
    if (const char* tmp = std::getenv("TMPDIR"); tmp && *tmp)
        return std::string(tmp);
    return {};
}

// Android uses the standard credential types; no system auth options are needed.
void* eos_platform_auth_credentials_options_create()
{
    return nullptr;
}

void eos_platform_auth_credentials_options_free(void*)
{
}
