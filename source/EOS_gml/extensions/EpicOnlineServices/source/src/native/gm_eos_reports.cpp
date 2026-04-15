#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_reports.h>

#include <string>
#include <string_view>
#include <vector>

using namespace gm::wire;
using namespace gm_structs;
using namespace gm_enums;

// ============================================================
// Internal helpers / state
// ============================================================

struct EOSAsyncCallbackContext
{
    GMFunction callback;
};

static EOS_HReports eos_reports_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetReportsInterface(p) : nullptr;
}

template <typename Fn>
static std::string eos_reports_copy_string_with_fixed_retry(Fn&& call_fn, size_t initial_capacity = 256)
{
    std::vector<char> buffer(initial_capacity, '\0');
    int32_t length = (int32_t)buffer.size();

    EOS_EResult result = call_fn(buffer.data(), &length);
    if (result == EOS_EResult::EOS_LimitExceeded && length > 0)
    {
        buffer.assign((size_t)length, '\0');
        result = call_fn(buffer.data(), &length);
    }

    if (result != EOS_EResult::EOS_Success)
        return std::string();

    return std::string(buffer.data());
}

static EOS_ProductUserId eos_product_user_id_from_string_internal(std::string_view product_user_id)
{
    std::string value(product_user_id);
    if (value.empty())
        return nullptr;
    return EOS_ProductUserId_FromString(value.c_str());
}

static std::string eos_product_user_id_to_string_internal(EOS_ProductUserId product_user_id)
{
    if (!product_user_id)
        return std::string();

    return eos_reports_copy_string_with_fixed_retry(
        [&](char* out_buffer, int32_t* inout_len) -> EOS_EResult
        {
            return EOS_ProductUserId_ToString(product_user_id, out_buffer, inout_len);
        });
}

static gm_structs::EpicReportsSendPlayerBehaviorReportCallbackInfo
eos_reports_send_player_behavior_report_info_from_native(
    const EOS_Reports_SendPlayerBehaviorReportCompleteCallbackInfo* p)
{
    gm_structs::EpicReportsSendPlayerBehaviorReportCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;

    return out;
}

static void EOS_CALL eos_reports_send_player_behavior_report_callback_native(
    const EOS_Reports_SendPlayerBehaviorReportCompleteCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_reports_send_player_behavior_report_info_from_native(data)
    );
    delete ctx;
}

// ============================================================
// EOS Reports
// ============================================================

void eos_reports_send_player_behavior_report(
    std::string_view reporter_user_id,
    std::string_view reported_user_id,
    gm_enums::EpicPlayerReportsCategory category,
    std::string_view message,
    std::string_view context,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HReports reports = eos_reports_iface();
    if (!reports) {
        eos_set_last_error("EOS Reports interface unavailable.");
        return;
    }

    EOS_ProductUserId reporter = eos_product_user_id_from_string_internal(reporter_user_id);
    EOS_ProductUserId reported = eos_product_user_id_from_string_internal(reported_user_id);

    if (!reporter) {
        eos_set_last_error("EOS_Reports_SendPlayerBehaviorReport: invalid reporter_user_id.");
        return;
    }

    if (!reported) {
        eos_set_last_error("EOS_Reports_SendPlayerBehaviorReport: invalid reported_user_id.");
        return;
    }

    std::string message_storage(message);
    std::string context_storage(context);

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Reports_SendPlayerBehaviorReportOptions opts{};
    opts.ApiVersion = EOS_REPORTS_SENDPLAYERBEHAVIORREPORT_API_LATEST;
    opts.ReporterUserId = reporter;
    opts.ReportedUserId = reported;
    opts.Category = (EOS_EPlayerReportsCategory)category;
    opts.Message = message_storage.empty() ? nullptr : message_storage.c_str();
    opts.Context = context_storage.empty() ? nullptr : context_storage.c_str();

    EOS_Reports_SendPlayerBehaviorReport(
        reports,
        &opts,
        ctx,
        &eos_reports_send_player_behavior_report_callback_native
    );
}