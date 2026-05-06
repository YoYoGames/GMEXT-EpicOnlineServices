#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_sanctions.h>

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

static EOS_HSanctions eos_sanctions_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetSanctionsInterface(p) : nullptr;
}

template <typename Fn>
static std::string eos_sanctions_copy_string_with_fixed_retry(Fn&& call_fn, size_t initial_capacity = 256)
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

    return eos_sanctions_copy_string_with_fixed_retry(
        [&](char* out_buffer, int32_t* inout_len) -> EOS_EResult
        {
            return EOS_ProductUserId_ToString(product_user_id, out_buffer, inout_len);
        });
}

static gm_structs::EpicSanctionsPlayerSanction eos_sanctions_player_sanction_from_native(
    const EOS_Sanctions_PlayerSanction* p)
{
    gm_structs::EpicSanctionsPlayerSanction out{};
    if (!p)
        return out;

    out.time_placed = p->TimePlaced;
    out.action = p->Action;
    out.time_expires = p->TimeExpires;
    out.reference_id = p->ReferenceId;

    return out;
}

static gm_structs::EpicSanctionsQueryActivePlayerSanctionsCallbackInfo
eos_sanctions_query_active_player_sanctions_info_from_native(
    const EOS_Sanctions_QueryActivePlayerSanctionsCallbackInfo* p)
{
    gm_structs::EpicSanctionsQueryActivePlayerSanctionsCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.target_user_id = eos_product_user_id_to_string_internal(p->TargetUserId);

    return out;
}

static gm_structs::EpicSanctionsCreatePlayerSanctionAppealCallbackInfo
eos_sanctions_create_player_sanction_appeal_info_from_native(
    const EOS_Sanctions_CreatePlayerSanctionAppealCallbackInfo* p)
{
    gm_structs::EpicSanctionsCreatePlayerSanctionAppealCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.reference_id = p->ReferenceId ? std::string(p->ReferenceId) : std::string();

    return out;
}

static void EOS_CALL eos_sanctions_query_active_player_sanctions_callback_native(
    const EOS_Sanctions_QueryActivePlayerSanctionsCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    if (ctx->callback) ctx->callback.value().call(
        eos_sanctions_query_active_player_sanctions_info_from_native(data)
    );
    delete ctx;
}

static void EOS_CALL eos_sanctions_create_player_sanction_appeal_callback_native(
    const EOS_Sanctions_CreatePlayerSanctionAppealCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    if (ctx->callback) ctx->callback.value().call(
        eos_sanctions_create_player_sanction_appeal_info_from_native(data)
    );
    delete ctx;
}

// ============================================================
// EOS Sanctions
// ============================================================

void eos_sanctions_query_active_player_sanctions(
    std::string_view target_user_id,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HSanctions sanctions = eos_sanctions_iface();
    if (!sanctions) {
        eos_set_last_error("EOS Sanctions interface unavailable.");
        return;
    }

    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);
    if (!target_user) {
        eos_set_last_error("EOS_Sanctions_QueryActivePlayerSanctions: invalid target_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Sanctions_QueryActivePlayerSanctionsOptions opts{};
    opts.ApiVersion = EOS_SANCTIONS_QUERYACTIVEPLAYERSANCTIONS_API_LATEST;
    opts.TargetUserId = target_user;

    EOS_Sanctions_QueryActivePlayerSanctions(
        sanctions,
        &opts,
        ctx,
        &eos_sanctions_query_active_player_sanctions_callback_native
    );
}

int64_t eos_sanctions_get_player_sanction_count(std::string_view target_user_id)
{
    eos_clear_last_error();

    EOS_HSanctions sanctions = eos_sanctions_iface();
    if (!sanctions) {
        eos_set_last_error("EOS Sanctions interface unavailable.");
        return 0;
    }

    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);
    if (!target_user) {
        eos_set_last_error("EOS_Sanctions_GetPlayerSanctionCount: invalid target_user_id.");
        return 0;
    }

    EOS_Sanctions_GetPlayerSanctionCountOptions opts{};
    opts.ApiVersion = EOS_SANCTIONS_GETPLAYERSANCTIONCOUNT_API_LATEST;
    opts.TargetUserId = target_user;

    return (int64_t)EOS_Sanctions_GetPlayerSanctionCount(sanctions, &opts);
}

gm_structs::EpicSanctionsPlayerSanction eos_sanctions_copy_player_sanction_by_index(
    std::string_view target_user_id,
    int64_t index)
{
    eos_clear_last_error();

    gm_structs::EpicSanctionsPlayerSanction out{};

    EOS_HSanctions sanctions = eos_sanctions_iface();
    if (!sanctions) {
        eos_set_last_error("EOS Sanctions interface unavailable.");
        return out;
    }

    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);
    if (!target_user) {
        eos_set_last_error("EOS_Sanctions_CopyPlayerSanctionByIndex: invalid target_user_id.");
        return out;
    }

    EOS_Sanctions_CopyPlayerSanctionByIndexOptions opts{};
    opts.ApiVersion = EOS_SANCTIONS_COPYPLAYERSANCTIONBYINDEX_API_LATEST;
    opts.TargetUserId = target_user;
    opts.SanctionIndex = (uint32_t)index;

    EOS_Sanctions_PlayerSanction* sanction = nullptr;
    const EOS_EResult result = EOS_Sanctions_CopyPlayerSanctionByIndex(sanctions, &opts, &sanction);
    if (result != EOS_EResult::EOS_Success || sanction == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Sanctions_CopyPlayerSanctionByIndex failed.");
        return out;
    }

    out = eos_sanctions_player_sanction_from_native(sanction);
    EOS_Sanctions_PlayerSanction_Release(sanction);
    return out;
}

void eos_sanctions_create_player_sanction_appeal(
    std::string_view local_user_id,
    std::string_view reference_id,
    gm_enums::EpicSanctionAppealReason reason,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HSanctions sanctions = eos_sanctions_iface();
    if (!sanctions) {
        eos_set_last_error("EOS Sanctions interface unavailable.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Sanctions_CreatePlayerSanctionAppeal: invalid local_user_id.");
        return;
    }

    std::string reference_id_storage(reference_id);

    if (reference_id_storage.empty()) {
        eos_set_last_error("EOS_Sanctions_CreatePlayerSanctionAppeal: reference_id is required.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Sanctions_CreatePlayerSanctionAppealOptions opts{};
    opts.ApiVersion = EOS_SANCTIONS_CREATEPLAYERSANCTIONAPPEAL_API_LATEST;
    opts.LocalUserId = local_user;
    opts.ReferenceId = reference_id_storage.c_str();
    opts.Reason = (EOS_ESanctionAppealReason)reason;

    EOS_Sanctions_CreatePlayerSanctionAppeal(
        sanctions,
        &opts,
        ctx,
        &eos_sanctions_create_player_sanction_appeal_callback_native
    );
}