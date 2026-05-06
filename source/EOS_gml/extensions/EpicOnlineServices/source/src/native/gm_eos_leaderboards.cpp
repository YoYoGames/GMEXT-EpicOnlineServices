#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_leaderboards.h>

#include <cstdint>
#include <optional>
#include <string>
#include <string_view>

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

static EOS_HLeaderboards eos_leaderboards_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetLeaderboardsInterface(p) : nullptr;
}

static EOS_ProductUserId eos_product_user_id_from_string_internal(std::string_view product_user_id)
{
    std::string value(product_user_id);
    if (value.empty())
        return nullptr;
    return EOS_ProductUserId_FromString(value.c_str());
}

static gm_structs::EpicLeaderboardsQueryDefinitionsCallbackInfo
eos_leaderboards_query_definitions_info_from_native(
    const EOS_Leaderboards_OnQueryLeaderboardDefinitionsCompleteCallbackInfo* p)
{
    gm_structs::EpicLeaderboardsQueryDefinitionsCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    return out;
}

static gm_structs::EpicLeaderboardsQueryRanksCallbackInfo
eos_leaderboards_query_ranks_info_from_native(
    const EOS_Leaderboards_OnQueryLeaderboardRanksCompleteCallbackInfo* p)
{
    gm_structs::EpicLeaderboardsQueryRanksCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    return out;
}

static gm_structs::EpicLeaderboardsQueryUserScoresCallbackInfo
eos_leaderboards_query_user_scores_info_from_native(
    const EOS_Leaderboards_OnQueryLeaderboardUserScoresCompleteCallbackInfo* p)
{
    gm_structs::EpicLeaderboardsQueryUserScoresCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    return out;
}

static void EOS_CALL eos_leaderboards_query_definitions_callback_native(
    const EOS_Leaderboards_OnQueryLeaderboardDefinitionsCompleteCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    if (ctx->callback) ctx->callback.value().call(
        eos_leaderboards_query_definitions_info_from_native(data)
    );
    delete ctx;
}

static void EOS_CALL eos_leaderboards_query_ranks_callback_native(
    const EOS_Leaderboards_OnQueryLeaderboardRanksCompleteCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    if (ctx->callback) ctx->callback.value().call(
        eos_leaderboards_query_ranks_info_from_native(data)
    );
    delete ctx;
}

static void EOS_CALL eos_leaderboards_query_user_scores_callback_native(
    const EOS_Leaderboards_OnQueryLeaderboardUserScoresCompleteCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    if (ctx->callback) ctx->callback.value().call(
        eos_leaderboards_query_user_scores_info_from_native(data)
    );
    delete ctx;
}

// ============================================================
// EOS Leaderboards (Part 1)
// ============================================================

void eos_leaderboards_query_definitions(
    std::string_view local_user_id,
    int64_t start_time,
    int64_t end_time,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HLeaderboards leaderboards = eos_leaderboards_iface();
    if (!leaderboards) {
        eos_set_last_error("EOS Leaderboards interface unavailable.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Leaderboards_QueryLeaderboardDefinitions: invalid local_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Leaderboards_QueryLeaderboardDefinitionsOptions opts{};
    opts.ApiVersion = EOS_LEADERBOARDS_QUERYLEADERBOARDDEFINITIONS_API_LATEST;
    opts.LocalUserId = local_user;
    opts.StartTime = start_time;
    opts.EndTime = end_time;

    EOS_Leaderboards_QueryLeaderboardDefinitions(
        leaderboards,
        &opts,
        ctx,
        &eos_leaderboards_query_definitions_callback_native
    );
}

void eos_leaderboards_query_ranks(
    std::string_view local_user_id,
    std::string_view leaderboard_id,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HLeaderboards leaderboards = eos_leaderboards_iface();
    if (!leaderboards) {
        eos_set_last_error("EOS Leaderboards interface unavailable.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Leaderboards_QueryLeaderboardRanks: invalid local_user_id.");
        return;
    }

    std::string leaderboard_id_storage(leaderboard_id);
    if (leaderboard_id_storage.empty()) {
        eos_set_last_error("EOS_Leaderboards_QueryLeaderboardRanks: leaderboard_id is required.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Leaderboards_QueryLeaderboardRanksOptions opts{};
    opts.ApiVersion = EOS_LEADERBOARDS_QUERYLEADERBOARDRANKS_API_LATEST;
    opts.LocalUserId = local_user;
    opts.LeaderboardId = leaderboard_id_storage.c_str();

    EOS_Leaderboards_QueryLeaderboardRanks(
        leaderboards,
        &opts,
        ctx,
        &eos_leaderboards_query_ranks_callback_native
    );
}

void eos_leaderboards_query_user_scores(
    std::string_view local_user_id,
    std::string_view stat_name,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HLeaderboards leaderboards = eos_leaderboards_iface();
    if (!leaderboards) {
        eos_set_last_error("EOS Leaderboards interface unavailable.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Leaderboards_QueryLeaderboardUserScores: invalid local_user_id.");
        return;
    }

    std::string stat_name_storage(stat_name);
    if (stat_name_storage.empty()) {
        eos_set_last_error("EOS_Leaderboards_QueryLeaderboardUserScores: stat_name is required.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    const char* stat_names[1];
    stat_names[0] = stat_name_storage.c_str();

    EOS_Leaderboards_QueryLeaderboardUserScoresOptions opts{};
    opts.ApiVersion = EOS_LEADERBOARDS_QUERYLEADERBOARDUSERSCORES_API_LATEST;
    opts.LocalUserId = local_user;
    opts.UserIds = nullptr;
    opts.UserIdsCount = 0;
    opts.StatInfo = nullptr;
    opts.StatInfoCount = 0;
    opts.StartTime = EOS_LEADERBOARDS_TIME_UNDEFINED;
    opts.EndTime = EOS_LEADERBOARDS_TIME_UNDEFINED;

    // If your SDK revision uses a stat-info array rather than raw names,
    // this is the one block to adapt.
    EOS_Leaderboards_UserScoresQueryStatInfo stat_info{};
    stat_info.ApiVersion = EOS_LEADERBOARDS_USERSCORESQUERYSTATINFO_API_LATEST;
    stat_info.StatName = stat_names[0];
    stat_info.Aggregation = EOS_ELeaderboardAggregation::EOS_LA_Latest;

    opts.StatInfo = &stat_info;
    opts.StatInfoCount = 1;

    EOS_Leaderboards_QueryLeaderboardUserScores(
        leaderboards,
        &opts,
        ctx,
        &eos_leaderboards_query_user_scores_callback_native
    );
}

int64_t eos_leaderboards_get_definition_count()
{
    eos_clear_last_error();

    EOS_HLeaderboards leaderboards = eos_leaderboards_iface();
    if (!leaderboards) {
        eos_set_last_error("EOS Leaderboards interface unavailable.");
        return 0;
    }

    EOS_Leaderboards_GetLeaderboardDefinitionCountOptions opts{};
    opts.ApiVersion = EOS_LEADERBOARDS_GETLEADERBOARDDEFINITIONCOUNT_API_LATEST;

    return (int64_t)EOS_Leaderboards_GetLeaderboardDefinitionCount(leaderboards, &opts);
}

int64_t eos_leaderboards_get_record_count()
{
    eos_clear_last_error();

    EOS_HLeaderboards leaderboards = eos_leaderboards_iface();
    if (!leaderboards) {
        eos_set_last_error("EOS Leaderboards interface unavailable.");
        return 0;
    }

    EOS_Leaderboards_GetLeaderboardRecordCountOptions opts{};
    opts.ApiVersion = EOS_LEADERBOARDS_GETLEADERBOARDRECORDCOUNT_API_LATEST;

    return (int64_t)EOS_Leaderboards_GetLeaderboardRecordCount(leaderboards, &opts);
}

int64_t eos_leaderboards_get_user_score_count()
{
    eos_clear_last_error();

    EOS_HLeaderboards leaderboards = eos_leaderboards_iface();
    if (!leaderboards) {
        eos_set_last_error("EOS Leaderboards interface unavailable.");
        return 0;
    }

    EOS_Leaderboards_GetLeaderboardUserScoreCountOptions opts{};
    opts.ApiVersion = EOS_LEADERBOARDS_GETLEADERBOARDUSERSCORECOUNT_API_LATEST;

    return (int64_t)EOS_Leaderboards_GetLeaderboardUserScoreCount(leaderboards, &opts);
}

// ============================================================
// EOS Leaderboards (Part 2)
// ============================================================

template <typename Fn>
static std::string eos_leaderboards_copy_string_with_fixed_retry(Fn&& call_fn, size_t initial_capacity = 256)
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

static std::string eos_leaderboards_product_user_id_to_string_internal(EOS_ProductUserId product_user_id)
{
    if (!product_user_id)
        return std::string();

    return eos_leaderboards_copy_string_with_fixed_retry(
        [&](char* out_buffer, int32_t* inout_len) -> EOS_EResult
        {
            return EOS_ProductUserId_ToString(product_user_id, out_buffer, inout_len);
        });
}

static gm_structs::EpicLeaderboardDefinition eos_leaderboards_definition_from_native(
    const EOS_Leaderboards_Definition* p)
{
    gm_structs::EpicLeaderboardDefinition out{};
    if (!p)
        return out;

    out.leaderboard_id = p->LeaderboardId ? std::string(p->LeaderboardId) : std::string();
    out.stat_name = p->StatName ? std::string(p->StatName) : std::string();
    out.start_time = p->StartTime;
    out.end_time = p->EndTime;

    // Keep aggregation readable in GML without needing another enum right now.
    switch (p->Aggregation)
    {
        case EOS_ELeaderboardAggregation::EOS_LA_Min:    out.aggregation = "Min"; break;
        case EOS_ELeaderboardAggregation::EOS_LA_Max:    out.aggregation = "Max"; break;
        case EOS_ELeaderboardAggregation::EOS_LA_Sum:    out.aggregation = "Sum"; break;
        case EOS_ELeaderboardAggregation::EOS_LA_Latest: out.aggregation = "Latest"; break;
        default:                                         out.aggregation = ""; break;
    }

    return out;
}

static gm_structs::EpicLeaderboardRecord eos_leaderboards_record_from_native(
    const EOS_Leaderboards_LeaderboardRecord* p)
{
    gm_structs::EpicLeaderboardRecord out{};
    if (!p)
        return out;

    out.user_id = eos_leaderboards_product_user_id_to_string_internal(p->UserId);
    out.rank = (int64_t)p->Rank;
    out.score = (int64_t)p->Score;
    out.user_display_name = p->UserDisplayName ? std::string(p->UserDisplayName) : std::string();

    return out;
}

static gm_structs::EpicLeaderboardUserScore eos_leaderboards_user_score_from_native(
    const EOS_Leaderboards_LeaderboardUserScore* p)
{
    gm_structs::EpicLeaderboardUserScore out{};
    if (!p)
        return out;

    out.user_id = eos_leaderboards_product_user_id_to_string_internal(p->UserId);
    out.score = (int64_t)p->Score;

    return out;
}

gm_structs::EpicLeaderboardDefinition eos_leaderboards_copy_definition_by_index(int64_t index)
{
    eos_clear_last_error();

    gm_structs::EpicLeaderboardDefinition out{};

    EOS_HLeaderboards leaderboards = eos_leaderboards_iface();
    if (!leaderboards) {
        eos_set_last_error("EOS Leaderboards interface unavailable.");
        return out;
    }

    EOS_Leaderboards_CopyLeaderboardDefinitionByIndexOptions opts{};
    opts.ApiVersion = EOS_LEADERBOARDS_COPYLEADERBOARDDEFINITIONBYINDEX_API_LATEST;
    opts.LeaderboardIndex = (uint32_t)index;

    EOS_Leaderboards_Definition* def = nullptr;
    const EOS_EResult result = EOS_Leaderboards_CopyLeaderboardDefinitionByIndex(
        leaderboards, &opts, &def);

    if (result != EOS_EResult::EOS_Success || def == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Leaderboards_CopyLeaderboardDefinitionByIndex failed.");
        return out;
    }

    out = eos_leaderboards_definition_from_native(def);
    EOS_Leaderboards_Definition_Release(def);
    return out;
}

gm_structs::EpicLeaderboardDefinition eos_leaderboards_copy_definition_by_id(std::string_view leaderboard_id)
{
    eos_clear_last_error();

    gm_structs::EpicLeaderboardDefinition out{};

    EOS_HLeaderboards leaderboards = eos_leaderboards_iface();
    if (!leaderboards) {
        eos_set_last_error("EOS Leaderboards interface unavailable.");
        return out;
    }

    std::string leaderboard_id_storage(leaderboard_id);
    if (leaderboard_id_storage.empty()) {
        eos_set_last_error("EOS_Leaderboards_CopyLeaderboardDefinitionByLeaderboardId: leaderboard_id is required.");
        return out;
    }

    EOS_Leaderboards_CopyLeaderboardDefinitionByLeaderboardIdOptions opts{};
    opts.ApiVersion = EOS_LEADERBOARDS_COPYLEADERBOARDDEFINITIONBYLEADERBOARDID_API_LATEST;
    opts.LeaderboardId = leaderboard_id_storage.c_str();

    EOS_Leaderboards_Definition* def = nullptr;
    const EOS_EResult result = EOS_Leaderboards_CopyLeaderboardDefinitionByLeaderboardId(
        leaderboards, &opts, &def);

    if (result != EOS_EResult::EOS_Success || def == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Leaderboards_CopyLeaderboardDefinitionByLeaderboardId failed.");
        return out;
    }

    out = eos_leaderboards_definition_from_native(def);
    EOS_Leaderboards_Definition_Release(def);
    return out;
}

gm_structs::EpicLeaderboardRecord eos_leaderboards_copy_record_by_index(int64_t index)
{
    eos_clear_last_error();

    gm_structs::EpicLeaderboardRecord out{};

    EOS_HLeaderboards leaderboards = eos_leaderboards_iface();
    if (!leaderboards) {
        eos_set_last_error("EOS Leaderboards interface unavailable.");
        return out;
    }

    EOS_Leaderboards_CopyLeaderboardRecordByIndexOptions opts{};
    opts.ApiVersion = EOS_LEADERBOARDS_COPYLEADERBOARDRECORDBYINDEX_API_LATEST;
    opts.LeaderboardRecordIndex = (uint32_t)index;

    EOS_Leaderboards_LeaderboardRecord* record = nullptr;
    const EOS_EResult result = EOS_Leaderboards_CopyLeaderboardRecordByIndex(
        leaderboards, &opts, &record);

    if (result != EOS_EResult::EOS_Success || record == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Leaderboards_CopyLeaderboardRecordByIndex failed.");
        return out;
    }

    out = eos_leaderboards_record_from_native(record);
    EOS_Leaderboards_LeaderboardRecord_Release(record);
    return out;
}

gm_structs::EpicLeaderboardRecord eos_leaderboards_copy_record_by_user_id(std::string_view user_id)
{
    eos_clear_last_error();

    gm_structs::EpicLeaderboardRecord out{};

    EOS_HLeaderboards leaderboards = eos_leaderboards_iface();
    if (!leaderboards) {
        eos_set_last_error("EOS Leaderboards interface unavailable.");
        return out;
    }

    EOS_ProductUserId user = eos_product_user_id_from_string_internal(user_id);
    if (!user) {
        eos_set_last_error("EOS_Leaderboards_CopyLeaderboardRecordByUserId: invalid user_id.");
        return out;
    }

    EOS_Leaderboards_CopyLeaderboardRecordByUserIdOptions opts{};
    opts.ApiVersion = EOS_LEADERBOARDS_COPYLEADERBOARDRECORDBYUSERID_API_LATEST;
    opts.UserId = user;

    EOS_Leaderboards_LeaderboardRecord* record = nullptr;
    const EOS_EResult result = EOS_Leaderboards_CopyLeaderboardRecordByUserId(
        leaderboards, &opts, &record);

    if (result != EOS_EResult::EOS_Success || record == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Leaderboards_CopyLeaderboardRecordByUserId failed.");
        return out;
    }

    out = eos_leaderboards_record_from_native(record);
    EOS_Leaderboards_LeaderboardRecord_Release(record);
    return out;
}

gm_structs::EpicLeaderboardUserScore eos_leaderboards_copy_user_score_by_index(int64_t index)
{
    eos_clear_last_error();

    gm_structs::EpicLeaderboardUserScore out{};

    EOS_HLeaderboards leaderboards = eos_leaderboards_iface();
    if (!leaderboards) {
        eos_set_last_error("EOS Leaderboards interface unavailable.");
        return out;
    }

    EOS_Leaderboards_CopyLeaderboardUserScoreByIndexOptions opts{};
    opts.ApiVersion = EOS_LEADERBOARDS_COPYLEADERBOARDUSERSCOREBYINDEX_API_LATEST;
    opts.LeaderboardUserScoreIndex = (uint32_t)index;

    EOS_Leaderboards_LeaderboardUserScore* score = nullptr;
    const EOS_EResult result = EOS_Leaderboards_CopyLeaderboardUserScoreByIndex(
        leaderboards, &opts, &score);

    if (result != EOS_EResult::EOS_Success || score == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Leaderboards_CopyLeaderboardUserScoreByIndex failed.");
        return out;
    }

    out = eos_leaderboards_user_score_from_native(score);
    EOS_Leaderboards_LeaderboardUserScore_Release(score);
    return out;
}

