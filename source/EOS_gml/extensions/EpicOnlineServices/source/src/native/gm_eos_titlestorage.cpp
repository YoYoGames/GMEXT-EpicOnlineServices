#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_titlestorage.h>

#include <cstdint>
#include <cstdio>
#include <fstream>
#include <ios>
#include <mutex>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>
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

struct EOSTSReadContext
{
    std::optional<GMFunction> callback;
    std::optional<GMFunction> progress_callback;
    std::string local_user_id;
    std::string filename;
    std::string output_path;
    std::ofstream output_file;
    bool file_open_failed = false;
    bool output_file_opened = false;
    EOS_HTitleStorageFileTransferRequest request = nullptr;
};

static EOS_HTitleStorage eos_ts_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetTitleStorageInterface(p) : nullptr;
}

static std::unordered_map<std::string, EOS_HTitleStorageFileTransferRequest> eos_ts_active_transfers;
static std::mutex eos_ts_transfers_mutex;

static EOS_ProductUserId eos_product_user_id_from_string_internal(std::string_view id)
{
    std::string v(id);
    if (v.empty()) return nullptr;
    return EOS_ProductUserId_FromString(v.c_str());
}

static std::string eos_product_user_id_to_string_internal(EOS_ProductUserId id)
{
    if (!id) return std::string();
    char buf[64] = {};
    int32_t len = (int32_t)sizeof(buf);
    if (EOS_ProductUserId_ToString(id, buf, &len) != EOS_EResult::EOS_Success)
        return std::string();
    return std::string(buf);
}

// ---- FileMetadata conversion ----

static gm_structs::EpicTitleStorageFileMetadata eos_ts_metadata_from_native(
    const EOS_TitleStorage_FileMetadata* m)
{
    gm_structs::EpicTitleStorageFileMetadata out{};
    if (!m) return out;
    out.file_size_bytes = (int64_t)m->FileSizeBytes;
    out.md5_hash = m->MD5Hash ? std::string(m->MD5Hash) : std::string();
    out.filename = m->Filename ? std::string(m->Filename) : std::string();
    out.unencrypted_data_size_bytes = (int64_t)m->UnencryptedDataSizeBytes;
    return out;
}

// ============================================================
// Native callbacks
// ============================================================

static void EOS_CALL eos_ts_query_file_callback_native(
    const EOS_TitleStorage_QueryFileCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicTitleStorageQueryFileCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

static void EOS_CALL eos_ts_query_file_list_callback_native(
    const EOS_TitleStorage_QueryFileListCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicTitleStorageQueryFileListCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.file_count = (int64_t)data->FileCount;
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

static void EOS_CALL eos_ts_delete_cache_callback_native(
    const EOS_TitleStorage_DeleteCacheCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicTitleStorageDeleteCacheCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

// Read file streaming callbacks

static EOS_TitleStorage_EReadResult EOS_CALL eos_ts_read_data_callback(
    const EOS_TitleStorage_ReadFileDataCallbackInfo* data)
{
    if (!data || !data->ClientData)
        return EOS_TitleStorage_EReadResult::EOS_TS_RR_FailRequest;

    auto* ctx = static_cast<EOSTSReadContext*>(data->ClientData);
    if (ctx->file_open_failed)
        return EOS_TitleStorage_EReadResult::EOS_TS_RR_FailRequest;

    if (data->DataChunk && data->DataChunkLengthBytes > 0) {
        if (!ctx->output_file.is_open() && !ctx->output_path.empty()) {
            ctx->output_file.open(ctx->output_path, std::ios::binary | std::ios::trunc);
            if (!ctx->output_file.is_open()) {
                ctx->file_open_failed = true;
                return EOS_TitleStorage_EReadResult::EOS_TS_RR_FailRequest;
            }
            ctx->output_file_opened = true;
        }
        if (ctx->output_file.is_open()) {
            ctx->output_file.write(reinterpret_cast<const char*>(data->DataChunk),
                                   static_cast<std::streamsize>(data->DataChunkLengthBytes));
            if (!ctx->output_file.good()) {
                ctx->file_open_failed = true;
                return EOS_TitleStorage_EReadResult::EOS_TS_RR_FailRequest;
            }
        }
    }
    return EOS_TitleStorage_EReadResult::EOS_TS_RR_ContinueReading;
}

static void EOS_CALL eos_ts_read_file_progress_callback_native(
    const EOS_TitleStorage_FileTransferProgressCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSTSReadContext*>(data->ClientData);
    if (!ctx || !ctx->progress_callback) return;

    gm_structs::EpicTitleStorageReadFileProgressCallbackInfo out{};
    out.local_user_id = ctx->local_user_id;
    out.filename = ctx->filename;
    out.bytes_transferred = (int64_t)data->BytesTransferred;
    out.total_file_size_bytes = (int64_t)data->TotalFileSizeBytes;
    ctx->progress_callback.value().call(out);
}

static void EOS_CALL eos_ts_read_file_callback_native(
    const EOS_TitleStorage_ReadFileCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSTSReadContext*>(data->ClientData);
    if (!ctx) return;

    EOS_EResult result_code = data->ResultCode;
    if (ctx->output_file.is_open()) {
        ctx->output_file.close();
    }
    if (ctx->file_open_failed) {
        result_code = EOS_EResult::EOS_UnexpectedError;
        eos_set_last_error("EOS_TitleStorage_ReadFile: failed to write '"
            + ctx->output_path + "' to disk (is the path writable?).");
    }

    // If we truncated output_path to start streaming but didn't finish successfully (failure or
    // cancellation), remove the partial fragment rather than leaving it in place — otherwise a
    // previously-good cached file silently ends up replaced by a corrupt, incomplete one.
    if (ctx->output_file_opened && result_code != EOS_EResult::EOS_Success) {
        std::remove(ctx->output_path.c_str());
    }

    {
        std::lock_guard<std::mutex> lock(eos_ts_transfers_mutex);
        eos_ts_active_transfers.erase(ctx->filename);
    }

    gm_structs::EpicTitleStorageReadFileCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)result_code;
    out.local_user_id = ctx->local_user_id;
    out.filename = ctx->filename;
    if (ctx->callback) ctx->callback.value().call(out);

    if (ctx->request)
        EOS_TitleStorageFileTransferRequest_Release(ctx->request);

    delete ctx;
}

// ============================================================
// EOS Title Storage — Metadata queries
// ============================================================

void eos_titlestorage_query_file(
    std::string_view local_user_id,
    std::string_view filename,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HTitleStorage ts = eos_ts_iface();
    if (!ts) { eos_set_last_error("EOS TitleStorage interface unavailable."); return; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    std::string fn(filename);
    if (fn.empty()) { eos_set_last_error("EOS_TitleStorage_QueryFile: filename required."); return; }

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_TitleStorage_QueryFileOptions opts{};
    opts.ApiVersion = EOS_TITLESTORAGE_QUERYFILE_API_LATEST;
    opts.LocalUserId = local_user; // optional — may be null
    opts.Filename = fn.c_str();

    EOS_TitleStorage_QueryFile(ts, &opts, ctx, &eos_ts_query_file_callback_native);
}

void eos_titlestorage_query_file_list(
    std::string_view local_user_id,
    const std::vector<std::string_view>& tags,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HTitleStorage ts = eos_ts_iface();
    if (!ts) { eos_set_last_error("EOS TitleStorage interface unavailable."); return; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);

    auto* ctx = new EOSAsyncCallbackContext{callback};

    // Build tag pointer array
    std::vector<std::string> tag_strings;
    std::vector<const char*> tag_ptrs;
    tag_strings.reserve(tags.size());
    tag_ptrs.reserve(tags.size());
    for (const auto& t : tags) {
        tag_strings.emplace_back(t);
        tag_ptrs.push_back(tag_strings.back().c_str());
    }

    EOS_TitleStorage_QueryFileListOptions opts{};
    opts.ApiVersion = EOS_TITLESTORAGE_QUERYFILELIST_API_LATEST;
    opts.LocalUserId = local_user; // optional
    opts.ListOfTags = tag_ptrs.empty() ? nullptr : tag_ptrs.data();
    opts.ListOfTagsCount = (uint32_t)tag_ptrs.size();

    EOS_TitleStorage_QueryFileList(ts, &opts, ctx, &eos_ts_query_file_list_callback_native);
}

int64_t eos_titlestorage_get_file_metadata_count(std::string_view local_user_id)
{
    EOS_GUARD_RET(0);

    EOS_HTitleStorage ts = eos_ts_iface();
    if (!ts) { eos_set_last_error("EOS TitleStorage interface unavailable."); return 0; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);

    EOS_TitleStorage_GetFileMetadataCountOptions opts{};
    opts.ApiVersion = EOS_TITLESTORAGE_GETFILEMETADATACOUNT_API_LATEST;
    opts.LocalUserId = local_user; // optional

    return (int64_t)EOS_TitleStorage_GetFileMetadataCount(ts, &opts);
}

std::optional<gm_structs::EpicTitleStorageFileMetadata> eos_titlestorage_copy_file_metadata_at_index(
    std::string_view local_user_id,
    int64_t index)
{
    EOS_GUARD_RET(std::nullopt);

    EOS_HTitleStorage ts = eos_ts_iface();
    if (!ts) {
        eos_set_last_error("EOS TitleStorage interface unavailable.");
        return std::nullopt;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);

    EOS_TitleStorage_CopyFileMetadataAtIndexOptions opts{};
    opts.ApiVersion = EOS_TITLESTORAGE_COPYFILEMETADATAATINDEX_API_LATEST;
    opts.LocalUserId = local_user; // optional
    opts.Index = (uint32_t)index;

    EOS_TitleStorage_FileMetadata* meta = nullptr;
    EOS_EResult result = EOS_TitleStorage_CopyFileMetadataAtIndex(ts, &opts, &meta);
    if (result != EOS_EResult::EOS_Success || !meta) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_TitleStorage_CopyFileMetadataAtIndex failed.");
        return std::nullopt;
    }

    gm_structs::EpicTitleStorageFileMetadata out = eos_ts_metadata_from_native(meta);
    EOS_TitleStorage_FileMetadata_Release(meta);
    return out;
}

std::optional<gm_structs::EpicTitleStorageFileMetadata> eos_titlestorage_copy_file_metadata_by_filename(
    std::string_view local_user_id,
    std::string_view filename)
{
    EOS_GUARD_RET(std::nullopt);

    EOS_HTitleStorage ts = eos_ts_iface();
    if (!ts) {
        eos_set_last_error("EOS TitleStorage interface unavailable.");
        return std::nullopt;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    std::string fn(filename);
    if (fn.empty()) {
        eos_set_last_error("EOS_TitleStorage_CopyFileMetadataByFilename: filename required.");
        return std::nullopt;
    }

    EOS_TitleStorage_CopyFileMetadataByFilenameOptions opts{};
    opts.ApiVersion = EOS_TITLESTORAGE_COPYFILEMETADATABYFILENAME_API_LATEST;
    opts.LocalUserId = local_user; // optional
    opts.Filename = fn.c_str();

    EOS_TitleStorage_FileMetadata* meta = nullptr;
    EOS_EResult result = EOS_TitleStorage_CopyFileMetadataByFilename(ts, &opts, &meta);
    if (result != EOS_EResult::EOS_Success || !meta) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_TitleStorage_CopyFileMetadataByFilename failed.");
        return std::nullopt;
    }

    gm_structs::EpicTitleStorageFileMetadata out = eos_ts_metadata_from_native(meta);
    EOS_TitleStorage_FileMetadata_Release(meta);
    return out;
}

// ============================================================
// EOS Title Storage — File read & cache
// ============================================================

void eos_titlestorage_read_file(
    std::string_view local_user_id,
    std::string_view filename,
    std::string_view output_path,
    const std::optional<gm::wire::GMFunction>& callback,
    const std::optional<gm::wire::GMFunction>& progress_callback)
{
    EOS_GUARD();

    EOS_HTitleStorage ts = eos_ts_iface();
    if (!ts) { eos_set_last_error("EOS TitleStorage interface unavailable."); return; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    std::string fn(filename);
    if (fn.empty()) {
        eos_set_last_error("EOS_TitleStorage_ReadFile: filename required.");
        return;
    }

    auto* ctx = new EOSTSReadContext{};
    ctx->callback = callback;
    ctx->progress_callback = progress_callback;
    ctx->local_user_id = eos_product_user_id_to_string_internal(local_user);
    ctx->filename = fn;
    ctx->output_path = std::string(output_path);

    EOS_TitleStorage_ReadFileOptions opts{};
    opts.ApiVersion = EOS_TITLESTORAGE_READFILE_API_LATEST;
    opts.LocalUserId = local_user; // optional
    opts.Filename = fn.c_str();
    opts.ReadChunkLengthBytes = 4096;
    opts.ReadFileDataCallback = &eos_ts_read_data_callback;
    opts.FileTransferProgressCallback = progress_callback ? &eos_ts_read_file_progress_callback_native : nullptr;

    ctx->request = EOS_TitleStorage_ReadFile(
        ts, &opts, ctx, &eos_ts_read_file_callback_native);

    if (!ctx->request) {
        // EOS still queues the completion callback with our ctx even when it returns null,
        // so we MUST NOT delete ctx here — the callback owns the lifetime.
        eos_set_last_error("EOS_TitleStorage_ReadFile: failed to start transfer.");
        return;
    }

    std::lock_guard<std::mutex> lock(eos_ts_transfers_mutex);
    eos_ts_active_transfers[fn] = ctx->request;
}

void eos_titlestorage_delete_cache(
    std::string_view local_user_id,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HTitleStorage ts = eos_ts_iface();
    if (!ts) { eos_set_last_error("EOS TitleStorage interface unavailable."); return; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_TitleStorage_DeleteCacheOptions opts{};
    opts.ApiVersion = EOS_TITLESTORAGE_DELETECACHE_API_LATEST;
    opts.LocalUserId = local_user; // optional

    EOS_EResult result = EOS_TitleStorage_DeleteCache(ts, &opts, ctx, &eos_ts_delete_cache_callback_native);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_TitleStorage_DeleteCache failed.");
        delete ctx;
    }
}

void eos_titlestorage_file_transfer_request_cancel_request(std::string_view filename)
{
    eos_clear_last_error();

    std::string filename_str(filename);
    if (filename_str.empty()) {
        eos_set_last_error("EOS_TitleStorage_CancelRequest: filename is required.");
        return;
    }

    {
        std::lock_guard<std::mutex> lock(eos_ts_transfers_mutex);
        auto it = eos_ts_active_transfers.find(filename_str);
        if (it == eos_ts_active_transfers.end()) {
            eos_set_last_error("EOS_TitleStorage_CancelRequest: no active transfer for this filename.");
            return;
        }

        EOS_HTitleStorageFileTransferRequest request = it->second;
        EOS_EResult result = EOS_TitleStorageFileTransferRequest_CancelRequest(request);
        if (result != EOS_EResult::EOS_Success) {
            const char* err = EOS_EResult_ToString(result);
            eos_set_last_error(err ? err : "EOS_TitleStorageFileTransferRequest_CancelRequest failed.");
        }

        eos_ts_active_transfers.erase(it);
    }
}
