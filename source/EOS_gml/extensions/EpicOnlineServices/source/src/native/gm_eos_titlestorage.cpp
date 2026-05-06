#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_titlestorage.h>

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

struct EOSTSReadContext
{
    std::optional<GMFunction> callback;
    std::string local_user_id;
    std::string filename;
    std::vector<uint8_t> data;
};

static EOS_HTitleStorage eos_ts_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetTitleStorageInterface(p) : nullptr;
}

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

// ---- Base64 ----

static const char k_b64_chars[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static std::string base64_encode(const void* data, size_t len)
{
    const auto* src = static_cast<const uint8_t*>(data);
    std::string out;
    out.reserve(((len + 2) / 3) * 4);
    for (size_t i = 0; i < len; i += 3) {
        uint32_t b = (uint32_t)src[i] << 16;
        if (i + 1 < len) b |= (uint32_t)src[i + 1] << 8;
        if (i + 2 < len) b |= src[i + 2];
        out += k_b64_chars[(b >> 18) & 0x3f];
        out += k_b64_chars[(b >> 12) & 0x3f];
        out += (i + 1 < len) ? k_b64_chars[(b >> 6) & 0x3f] : '=';
        out += (i + 2 < len) ? k_b64_chars[b & 0x3f] : '=';
    }
    return out;
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
    if (data->DataChunk && data->DataChunkLengthBytes > 0) {
        const auto* src = static_cast<const uint8_t*>(data->DataChunk);
        ctx->data.insert(ctx->data.end(), src, src + data->DataChunkLengthBytes);
    }
    return EOS_TitleStorage_EReadResult::EOS_TS_RR_ContinueReading;
}

static void EOS_CALL eos_ts_read_file_callback_native(
    const EOS_TitleStorage_ReadFileCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSTSReadContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicTitleStorageReadFileCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = ctx->local_user_id;
    out.filename = ctx->filename;
    if (data->ResultCode == EOS_EResult::EOS_Success && !ctx->data.empty())
        out.data = base64_encode(ctx->data.data(), ctx->data.size());
    if (ctx->callback) ctx->callback.value().call(out);
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
    std::vector<const char*> tag_ptrs;
    tag_ptrs.reserve(tags.size());
    for (const auto& t : tags)
        tag_ptrs.push_back(t.data());

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

gm_structs::EpicTitleStorageFileMetadata eos_titlestorage_copy_file_metadata_at_index(
    std::string_view local_user_id,
    int64_t index)
{
    gm_structs::EpicTitleStorageFileMetadata out{};
    EOS_GUARD_RET(out);

    EOS_HTitleStorage ts = eos_ts_iface();
    if (!ts) { eos_set_last_error("EOS TitleStorage interface unavailable."); return out; }

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
        return out;
    }
    out = eos_ts_metadata_from_native(meta);
    EOS_TitleStorage_FileMetadata_Release(meta);
    return out;
}

gm_structs::EpicTitleStorageFileMetadata eos_titlestorage_copy_file_metadata_by_filename(
    std::string_view local_user_id,
    std::string_view filename)
{
    gm_structs::EpicTitleStorageFileMetadata out{};
    EOS_GUARD_RET(out);

    EOS_HTitleStorage ts = eos_ts_iface();
    if (!ts) { eos_set_last_error("EOS TitleStorage interface unavailable."); return out; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    std::string fn(filename);
    if (fn.empty()) {
        eos_set_last_error("EOS_TitleStorage_CopyFileMetadataByFilename: filename required.");
        return out;
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
        return out;
    }
    out = eos_ts_metadata_from_native(meta);
    EOS_TitleStorage_FileMetadata_Release(meta);
    return out;
}

// ============================================================
// EOS Title Storage — File read & cache
// ============================================================

void eos_titlestorage_read_file(
    std::string_view local_user_id,
    std::string_view filename,
    const std::optional<gm::wire::GMFunction>& callback)
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
    ctx->local_user_id = eos_product_user_id_to_string_internal(local_user);
    ctx->filename = fn;

    EOS_TitleStorage_ReadFileOptions opts{};
    opts.ApiVersion = EOS_TITLESTORAGE_READFILE_API_LATEST;
    opts.LocalUserId = local_user; // optional
    opts.Filename = fn.c_str();
    opts.ReadChunkLengthBytes = 4096;
    opts.ReadFileDataCallback = &eos_ts_read_data_callback;
    opts.FileTransferProgressCallback = nullptr;

    EOS_HTitleStorageFileTransferRequest req = EOS_TitleStorage_ReadFile(
        ts, &opts, ctx, &eos_ts_read_file_callback_native);

    if (!req) {
        eos_set_last_error("EOS_TitleStorage_ReadFile: failed to start transfer.");
        delete ctx;
    }
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
