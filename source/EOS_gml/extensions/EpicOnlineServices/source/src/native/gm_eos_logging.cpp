#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_logging.h>

#include <cstdint>
#include <mutex>
#include <optional>
#include <string>

using namespace gm::wire;
using namespace gm_structs;
using namespace gm_enums;

// ============================================================
// Internal callback state
// ============================================================

static gm::wire::GMFunction g_cb_logging = nullptr;
static std::mutex g_cb_logging_mutex;

static inline gm_structs::EpicLoggingMessage logging_from_native(const EOS_LogMessage* p)
{
    gm_structs::EpicLoggingMessage out{};

    if (!p)
        return out;

    out.category = p->Category ? std::string(p->Category) : std::string();
    out.level = (gm_enums::EpicLogLevel)(int)p->Level;
    out.message = p->Message ? std::string(p->Message) : std::string();

    return out;
}

static void EOS_CALL eos_logging_message_hook(const EOS_LogMessage* p)
{
    if (!p) return;

    gm::wire::GMFunction callback;
    {
        std::lock_guard<std::mutex> lock(g_cb_logging_mutex);
        callback = g_cb_logging;
    }

    if (callback)
        callback.call(logging_from_native(p));
}

// ============================================================
// EOS Logging
// ============================================================

void eos_logging_set_callback(const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    {
        std::lock_guard<std::mutex> lock(g_cb_logging_mutex);
        g_cb_logging = callback.value_or(GMFunction{});
    }

    const EOS_EResult result = EOS_Logging_SetCallback(
        g_cb_logging ? &eos_logging_message_hook : nullptr
    );

    if (result != EOS_EResult::EOS_Success)
    {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Logging_SetCallback failed.");
        std::lock_guard<std::mutex> lock(g_cb_logging_mutex);
        g_cb_logging = nullptr;
    }
}

void eos_logging_clear_callback()
{
    eos_clear_last_error();

    {
        std::lock_guard<std::mutex> lock(g_cb_logging_mutex);
        g_cb_logging = nullptr;
    }

    const EOS_EResult result = EOS_Logging_SetCallback(nullptr);
    if (result != EOS_EResult::EOS_Success)
    {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Logging_SetCallback(nullptr) failed.");
    }
}

gm_enums::EpicResult eos_logging_set_log_level(
    gm_enums::EpicLogCategory log_category,
    gm_enums::EpicLogLevel log_level)
{
    eos_clear_last_error();

    const EOS_EResult result = EOS_Logging_SetLogLevel(
        (EOS_ELogCategory)log_category,
        (EOS_ELogLevel)log_level
    );

    if (result != EOS_EResult::EOS_Success)
    {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Logging_SetLogLevel failed.");
    }

    return (gm_enums::EpicResult)result;
}