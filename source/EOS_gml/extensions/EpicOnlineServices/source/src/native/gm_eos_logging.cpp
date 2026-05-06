#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_logging.h>

#include <optional>
#include <string>

using namespace gm::wire;
using namespace gm_structs;
using namespace gm_enums;

// ============================================================
// Internal callback state
// ============================================================

static gm::wire::GMFunction g_cb_logging = nullptr;

static inline gm_structs::EpicLoggingMessage logging_from_native(const EOS_LogMessage* p)
{
    gm_structs::EpicLoggingMessage out{};

    if (!p)
        return out;

    out.category = (gm_enums::EpicLogCategory)(int)p->Category;
    out.level = (gm_enums::EpicLogLevel)(int)p->Level;
    out.message = p->Message ? std::string(p->Message) : std::string();

    return out;
}

static void EOS_CALL eos_logging_message_hook(const EOS_LogMessage* p)
{
    if (!p) return;
    if (!g_cb_logging) return;

    g_cb_logging.call(logging_from_native(p));
}

// ============================================================
// EOS Logging
// ============================================================

void eos_logging_set_callback(const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    g_cb_logging = callback.value_or(GMFunction{});

    const EOS_EResult result = EOS_Logging_SetCallback(
        g_cb_logging ? &eos_logging_message_hook : nullptr
    );

    if (result != EOS_EResult::EOS_Success)
    {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Logging_SetCallback failed.");
        g_cb_logging = nullptr;
    }
}

void eos_logging_clear_callback()
{
    eos_clear_last_error();

    g_cb_logging = nullptr;

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