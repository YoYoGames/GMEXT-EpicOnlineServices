#include "native/gm_eos_platform_hooks.h"

#include "eos_ios_auth.h"

#include <cstdlib>

// iOS needs no system init options; EOS_Initialize takes the defaults.
void* eos_platform_initialize_options_create(EOS_InitializeOptions&)
{
    return nullptr;
}

void eos_platform_initialize_options_free(void*)
{
}

// iOS sandboxes the app; TMPDIR points at <app>/tmp, which is writable, unlike
// GameMaker's working_directory.
std::string eos_platform_cache_dir()
{
    if (const char* tmp = std::getenv("TMPDIR"); tmp && *tmp)
        return std::string(tmp);
    return {};
}

// Account Portal login on iOS 13+ needs a presentation context. The ObjC++ side
// lives in eos_ios_auth.mm so this file stays plain C++.
void* eos_platform_auth_credentials_options_create()
{
    return eos_ios_auth_credentials_options_create();
}

void eos_platform_auth_credentials_options_free(void* options)
{
    eos_ios_auth_credentials_options_free(options);
}
