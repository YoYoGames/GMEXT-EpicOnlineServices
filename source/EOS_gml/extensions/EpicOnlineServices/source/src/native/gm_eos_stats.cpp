#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_stats.h>

#include <cstdint>
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

static EOS_HStats eos_stats_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetStatsInterface(p) : nullptr;
}

template <typename Fn>
static std::string eos_stats_copy_string_with_fixed_retry(Fn&& call_fn, size_t initial_capacity = 256)
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

    return eos_stats_copy_string_with_fixed_retry(
        [&](char* out_buffer, int32_t* inout_len) -> EOS_EResult
        {
            return EOS_ProductUserId_ToString(product_user_id, out_buffer, inout_len);
        });
}

static gm_structs::EpicStatsStat eos_stats_stat_from_native(const EOS_Stats_Stat* p)
{
    gm_structs::EpicStatsStat out{};
    if (!p)
        return out;

    out.name = p->Name ? std::string(p->Name) : std::string();
    out.start_time = p->StartTime;
    out.end_time = p->EndTime;
    out.value = p->Value;

    return out;
}

static gm_structs::EpicStatsIngestStatCallbackInfo eos_stats_ingest_stat_info_from_native(
    const EOS_Stats_IngestStatCompleteCallbackInfo* p)
{
    gm_structs::EpicStatsIngestStatCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(p->LocalUserId);
    out.target_user_id = eos_product_user_id_to_string_internal(p->TargetUserId);

    return out;
}

static gm_structs::EpicStatsQueryStatsCallbackInfo eos_stats_query_stats_info_from_native(
    const EOS_Stats_OnQueryStatsCompleteCallbackInfo* p)
{
    gm_structs::EpicStatsQueryStatsCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(p->LocalUserId);
    out.target_user_id = eos_product_user_id_to_string_internal(p->TargetUserId);

    return out;
}

static void EOS_CALL eos_stats_ingest_stat_callback_native(
    const EOS_Stats_IngestStatCompleteCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    if (ctx->callback) ctx->callback.value().call(
        eos_stats_ingest_stat_info_from_native(data)
    );
    delete ctx;
}

static void EOS_CALL eos_stats_query_stats_callback_native(
    const EOS_Stats_OnQueryStatsCompleteCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    if (ctx->callback) ctx->callback.value().call(
        eos_stats_query_stats_info_from_native(data)
    );
    delete ctx;
}

// ============================================================
// EOS Stats (Part 1)
// ============================================================

void eos_stats_ingest_stat(
    std::string_view local_user_id,
    std::string_view target_user_id,
    std::string_view stat_name,
    int64_t ingest_amount,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HStats stats = eos_stats_iface();
    if (!stats) {
        eos_set_last_error("EOS Stats interface unavailable.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);
    std::string stat_name_storage(stat_name);

    if (!local_user) {
        eos_set_last_error("EOS_Stats_IngestStat: invalid local_user_id.");
        return;
    }

    if (!target_user) {
        eos_set_last_error("EOS_Stats_IngestStat: invalid target_user_id.");
        return;
    }

    if (stat_name_storage.empty()) {
        eos_set_last_error("EOS_Stats_IngestStat: stat_name is required.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Stats_IngestData ingest_data{};
    ingest_data.ApiVersion = EOS_STATS_INGESTDATA_API_LATEST;
    ingest_data.StatName = stat_name_storage.c_str();
    ingest_data.IngestAmount = (int32_t)ingest_amount;

    EOS_Stats_IngestStatOptions opts{};
    opts.ApiVersion = EOS_STATS_INGESTSTAT_API_LATEST;
    opts.LocalUserId = local_user;
    opts.TargetUserId = target_user;
    opts.Stats = &ingest_data;
    opts.StatsCount = 1;

    EOS_Stats_IngestStat(stats, &opts, ctx, &eos_stats_ingest_stat_callback_native);
}

void eos_stats_query_stats(
    std::string_view local_user_id,
    std::string_view target_user_id,
    int64_t start_time,
    int64_t end_time,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HStats stats = eos_stats_iface();
    if (!stats) {
        eos_set_last_error("EOS Stats interface unavailable.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);

    if (!local_user) {
        eos_set_last_error("EOS_Stats_QueryStats: invalid local_user_id.");
        return;
    }

    if (!target_user) {
        eos_set_last_error("EOS_Stats_QueryStats: invalid target_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Stats_QueryStatsOptions opts{};
    opts.ApiVersion = EOS_STATS_QUERYSTATS_API_LATEST;
    opts.LocalUserId = local_user;
    opts.TargetUserId = target_user;
    opts.StartTime = start_time;
    opts.EndTime = end_time;
    opts.StatNames = nullptr;
    opts.StatNamesCount = 0;

    EOS_Stats_QueryStats(stats, &opts, ctx, &eos_stats_query_stats_callback_native);
}

int64_t eos_stats_get_stats_count(std::string_view target_user_id)
{
    eos_clear_last_error();

    EOS_HStats stats = eos_stats_iface();
    if (!stats) {
        eos_set_last_error("EOS Stats interface unavailable.");
        return 0;
    }

    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);

    if (!target_user) {
        eos_set_last_error("EOS_Stats_GetStatsCount: invalid target_user_id.");
        return 0;
    }

    EOS_Stats_GetStatCountOptions opts{};
    opts.ApiVersion = EOS_STATS_GETSTATSCOUNT_API_LATEST;
    opts.TargetUserId = target_user;

    return (int64_t)EOS_Stats_GetStatsCount(stats, &opts);
}

gm_structs::EpicStatsStat eos_stats_copy_stat_by_index(
    std::string_view target_user_id,
    int64_t index)
{
    eos_clear_last_error();

    gm_structs::EpicStatsStat out{};

    EOS_HStats stats = eos_stats_iface();
    if (!stats) {
        eos_set_last_error("EOS Stats interface unavailable.");
        return out;
    }

    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);

    if (!target_user) {
        eos_set_last_error("EOS_Stats_CopyStatByIndex: invalid target_user_id.");
        return out;
    }

    EOS_Stats_CopyStatByIndexOptions opts{};
    opts.ApiVersion = EOS_STATS_COPYSTATBYINDEX_API_LATEST;
    opts.TargetUserId = target_user;
    opts.StatIndex = (uint32_t)index;

    EOS_Stats_Stat* stat = nullptr;
    const EOS_EResult result = EOS_Stats_CopyStatByIndex(stats, &opts, &stat);
    if (result != EOS_EResult::EOS_Success || stat == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Stats_CopyStatByIndex failed.");
        return out;
    }

    out = eos_stats_stat_from_native(stat);
    EOS_Stats_Stat_Release(stat);
    return out;
}

gm_structs::EpicStatsStat eos_stats_copy_stat_by_name(
    std::string_view target_user_id,
    std::string_view name)
{
    eos_clear_last_error();

    gm_structs::EpicStatsStat out{};

    EOS_HStats stats = eos_stats_iface();
    if (!stats) {
        eos_set_last_error("EOS Stats interface unavailable.");
        return out;
    }

    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);
    std::string name_storage(name);

    if (!target_user) {
        eos_set_last_error("EOS_Stats_CopyStatByName: invalid target_user_id.");
        return out;
    }

    if (name_storage.empty()) {
        eos_set_last_error("EOS_Stats_CopyStatByName: name is required.");
        return out;
    }

    EOS_Stats_CopyStatByNameOptions opts{};
    opts.ApiVersion = EOS_STATS_COPYSTATBYNAME_API_LATEST;
    opts.TargetUserId = target_user;
    opts.Name = name_storage.c_str();

    EOS_Stats_Stat* stat = nullptr;
    const EOS_EResult result = EOS_Stats_CopyStatByName(stats, &opts, &stat);
    if (result != EOS_EResult::EOS_Success || stat == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Stats_CopyStatByName failed.");
        return out;
    }

    out = eos_stats_stat_from_native(stat);
    EOS_Stats_Stat_Release(stat);
    return out;
}