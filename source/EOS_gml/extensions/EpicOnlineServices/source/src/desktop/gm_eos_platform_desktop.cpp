#include "native/gm_eos_platform_hooks.h"

// Windows, macOS and Linux need none of the three hooks: EOS_Initialize takes no
// system options, the caller's cache_directory (GameMaker's working_directory) is
// already writable, and EOS_Auth_Login needs no presentation context.

void* eos_platform_initialize_options_create(EOS_InitializeOptions&)
{
    return nullptr;
}

void eos_platform_initialize_options_free(void*)
{
}

std::string eos_platform_cache_dir()
{
    return {};
}

void* eos_platform_auth_credentials_options_create()
{
    return nullptr;
}

void eos_platform_auth_credentials_options_free(void*)
{
}
