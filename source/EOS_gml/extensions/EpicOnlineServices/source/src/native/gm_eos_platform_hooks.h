#pragma once

#include <string>

#include <eos_sdk.h>

// Per-target behaviour EOS needs, kept out of the shared core.
//
// Exactly one implementation is compiled: src/desktop, src/android or src/ios.
// src/android and src/ios are picked up by the generated src/CMakeLists.txt's own
// per-platform globs; src/desktop is added by third_party/CMakeLists.txt, which is
// the author-editable file. A missing or duplicated implementation is a link
// error rather than a silent fallback, which is the point of declaring the seam
// here instead of branching on macros at each call site.
//
// This follows ios/eos_ios_auth.h, which already does the same for the ObjC parts
// of Account Portal login.

// Fills opts.SystemInitializeOptions and returns an owner that must stay alive
// until EOS_Initialize has returned, then be passed to the _free below. Returns
// nullptr where the platform needs no system options, leaving opts untouched.
void* eos_platform_initialize_options_create(EOS_InitializeOptions& opts);
void eos_platform_initialize_options_free(void* handle);

// The writable cache directory EOS_Platform_Create should use. Empty means the
// platform has nothing to offer and the caller-supplied path stands.
std::string eos_platform_cache_dir();

// EOS_Auth_Credentials::SystemAuthCredentialsOptions for EOS_Auth_Login, or
// nullptr where none is needed. Free after EOS_Auth_Login returns; EOS copies
// the options during the call.
void* eos_platform_auth_credentials_options_create();
void eos_platform_auth_credentials_options_free(void* options);
