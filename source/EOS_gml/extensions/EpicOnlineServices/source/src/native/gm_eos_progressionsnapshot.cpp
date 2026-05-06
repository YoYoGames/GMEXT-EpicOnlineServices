#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_progressionsnapshot.h>

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

static EOS_HProgressionSnapshot eos_progressionsnapshot_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetProgressionSnapshotInterface(p) : nullptr;
}

static EOS_ProductUserId eos_product_user_id_from_string_internal(std::string_view id)
{
    std::string v(id);
    if (v.empty()) return nullptr;
    return EOS_ProductUserId_FromString(v.c_str());
}

// ============================================================
// Native callbacks
// ============================================================

static void EOS_CALL eos_progressionsnapshot_submit_callback_native(
    const EOS_ProgressionSnapshot_SubmitSnapshotCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicProgressionSnapshotSubmitSnapshotCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

static void EOS_CALL eos_progressionsnapshot_delete_callback_native(
    const EOS_ProgressionSnapshot_DeleteSnapshotCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicProgressionSnapshotDeleteSnapshotCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

// ============================================================
// EOS Progression Snapshot
// ============================================================

std::int64_t eos_progression_snapshot_begin_snapshot(std::string_view local_user_id)
{
    EOS_GUARD_RET(-1);

    EOS_HProgressionSnapshot iface = eos_progressionsnapshot_iface();
    if (!iface) {
        eos_set_last_error("EOS ProgressionSnapshot interface unavailable.");
        return -1;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_ProgressionSnapshot_BeginSnapshot: invalid local_user_id.");
        return -1;
    }

    EOS_ProgressionSnapshot_BeginSnapshotOptions opts{};
    opts.ApiVersion = EOS_PROGRESSIONSNAPSHOT_BEGINSNAPSHOT_API_LATEST;
    opts.LocalUserId = local_user;

    uint32_t snapshot_id = 0;
    EOS_EResult result = EOS_ProgressionSnapshot_BeginSnapshot(iface, &opts, &snapshot_id);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_ProgressionSnapshot_BeginSnapshot failed.");
        return -1;
    }

    return (std::int64_t)snapshot_id;
}

gm_enums::EpicResult eos_progression_snapshot_add_progression(
    std::int64_t snapshot_id,
    std::string_view key,
    std::string_view value)
{
    EOS_GUARD_RET((gm_enums::EpicResult)EOS_EResult::EOS_InvalidState);

    EOS_HProgressionSnapshot iface = eos_progressionsnapshot_iface();
    if (!iface) {
        eos_set_last_error("EOS ProgressionSnapshot interface unavailable.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidState;
    }

    std::string key_str(key);
    std::string value_str(value);

    EOS_ProgressionSnapshot_AddProgressionOptions opts{};
    opts.ApiVersion = EOS_PROGRESSIONSNAPSHOT_ADDPROGRESSION_API_LATEST;
    opts.SnapshotId = (uint32_t)snapshot_id;
    opts.Key = key_str.c_str();
    opts.Value = value_str.c_str();

    EOS_EResult result = EOS_ProgressionSnapshot_AddProgression(iface, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_ProgressionSnapshot_AddProgression failed.");
    }
    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_progression_snapshot_end_snapshot(std::int64_t snapshot_id)
{
    EOS_GUARD_RET((gm_enums::EpicResult)EOS_EResult::EOS_InvalidState);

    EOS_HProgressionSnapshot iface = eos_progressionsnapshot_iface();
    if (!iface) {
        eos_set_last_error("EOS ProgressionSnapshot interface unavailable.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidState;
    }

    EOS_ProgressionSnapshot_EndSnapshotOptions opts{};
    opts.ApiVersion = EOS_PROGRESSIONSNAPSHOT_ENDSNAPSHOT_API_LATEST;
    opts.SnapshotId = (uint32_t)snapshot_id;

    EOS_EResult result = EOS_ProgressionSnapshot_EndSnapshot(iface, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_ProgressionSnapshot_EndSnapshot failed.");
    }
    return (gm_enums::EpicResult)result;
}

void eos_progression_snapshot_submit_snapshot(
    std::int64_t snapshot_id,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HProgressionSnapshot iface = eos_progressionsnapshot_iface();
    if (!iface) {
        eos_set_last_error("EOS ProgressionSnapshot interface unavailable.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_ProgressionSnapshot_SubmitSnapshotOptions opts{};
    opts.ApiVersion = EOS_PROGRESSIONSNAPSHOT_SUBMITSNAPSHOT_API_LATEST;
    opts.SnapshotId = (uint32_t)snapshot_id;

    EOS_ProgressionSnapshot_SubmitSnapshot(
        iface, &opts, ctx, &eos_progressionsnapshot_submit_callback_native);
}

void eos_progression_snapshot_delete_snapshot(
    std::string_view local_user_id,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HProgressionSnapshot iface = eos_progressionsnapshot_iface();
    if (!iface) {
        eos_set_last_error("EOS ProgressionSnapshot interface unavailable.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_ProgressionSnapshot_DeleteSnapshot: invalid local_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_ProgressionSnapshot_DeleteSnapshotOptions opts{};
    opts.ApiVersion = EOS_PROGRESSIONSNAPSHOT_DELETESNAPSHOT_API_LATEST;
    opts.LocalUserId = local_user;

    EOS_ProgressionSnapshot_DeleteSnapshot(
        iface, &opts, ctx, &eos_progressionsnapshot_delete_callback_native);
}
