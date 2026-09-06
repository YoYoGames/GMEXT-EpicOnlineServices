#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"
#include "gm_eos_common.h"

#include <eos_sdk.h>
#include <eos_reports.h>

#include <optional>
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
    std::optional<GMFunction> callback;
};

static EOS_HReports eos_reports_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetReportsInterface(p) : nullptr;
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

    if (ctx->callback) ctx->callback.value().call(
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
    const std::optional<gm::wire::GMFunction>& callback)
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