#pragma once

#include <atomic>
#include <cstdint>
#include <mutex>
#include <string>
#include <string_view>

// Use the EOS umbrella header, not eos_result.h directly.
#include <eos_sdk.h>

void eos_set_last_error(std::string_view msg);
void eos_clear_last_error();
std::string eos_api_last_error();

bool eos_api_is_initialized();
void eos_set_initialized(bool v);

inline bool eos_guard_failed()
{
    eos_clear_last_error();
    if (!eos_api_is_initialized()) {
        eos_set_last_error("EOS SDK not initialized");
        return true;
    }
    return false;
}

#define EOS_GUARD()         \
    do {                    \
        if (eos_guard_failed()) \
            return;         \
    } while (0)

#define EOS_GUARD_RET(expr) \
    do {                    \
        if (eos_guard_failed()) \
            return expr;    \
    } while (0)

extern std::atomic<bool> g_eos_initialized;

EOS_HPlatform eos_platform_get();
void eos_platform_set(EOS_HPlatform handle);
