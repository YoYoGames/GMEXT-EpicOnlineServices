#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_playerdatastorage.h>

#include <cstdint>
#include <cstring>
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

struct EOSPDSReadContext
{
    std::optional<GMFunction> callback;
    std::optional<GMFunction> progress_callback;
    std::string local_user_id;
    std::string filename;
    std::string output_path;
    std::vector<uint8_t> data;
};

struct EOSPDSWriteContext
{
    std::optional<GMFunction> callback;
    std::optional<GMFunction> progress_callback;
    std::string local_user_id;
    std::string filename;
    std::vector<uint8_t> data;
    size_t write_offset = 0;
};

static void eos_pds_write_entire_file(const std::string& path, const std::vector<uint8_t>& buf)
{
    std::ofstream f(path, std::ios::binary | std::ios::trunc);
    if (!f.is_open()) return;
    if (!buf.empty())
        f.write(reinterpret_cast<const char*>(buf.data()), static_cast<std::streamsize>(buf.size()));
}

static std::vector<uint8_t> eos_pds_read_entire_file(const std::string& path)
{
    std::vector<uint8_t> out;
    std::ifstream f(path, std::ios::binary | std::ios::ate);
    if (!f.is_open()) return out;
    std::streamsize sz = f.tellg();
    if (sz <= 0) return out;
    out.resize((size_t)sz);
    f.seekg(0, std::ios::beg);
    f.read(reinterpret_cast<char*>(out.data()), sz);
    return out;
}

static EOS_HPlayerDataStorage eos_pds_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetPlayerDataStorageInterface(p) : nullptr;
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

// ---- FileMetadata conversion ----

static gm_structs::EpicPlayerDataStorageFileMetadata eos_pds_metadata_from_native(
    const EOS_PlayerDataStorage_FileMetadata* m)
{
    gm_structs::EpicPlayerDataStorageFileMetadata out{};
    if (!m) return out;
    out.file_size_bytes = (int64_t)m->FileSizeBytes;
    out.md5_hash = m->MD5Hash ? std::string(m->MD5Hash) : std::string();
    out.filename = m->Filename ? std::string(m->Filename) : std::string();
    out.last_modified_time = m->LastModifiedTime;
    out.unencrypted_data_size_bytes = (int64_t)m->UnencryptedDataSizeBytes;
    return out;
}

// ============================================================
// Native callbacks
// ============================================================

static void EOS_CALL eos_pds_query_file_callback_native(
    const EOS_PlayerDataStorage_QueryFileCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicPlayerDataStorageQueryFileCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

static void EOS_CALL eos_pds_query_file_list_callback_native(
    const EOS_PlayerDataStorage_QueryFileListCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicPlayerDataStorageQueryFileListCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.file_count = (int64_t)data->FileCount;
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

static void EOS_CALL eos_pds_duplicate_file_callback_native(
    const EOS_PlayerDataStorage_DuplicateFileCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicPlayerDataStorageDuplicateFileCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

static void EOS_CALL eos_pds_delete_file_callback_native(
    const EOS_PlayerDataStorage_DeleteFileCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicPlayerDataStorageDeleteFileCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

static void EOS_CALL eos_pds_delete_cache_callback_native(
    const EOS_PlayerDataStorage_DeleteCacheCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicPlayerDataStorageDeleteCacheCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

// Read file streaming callbacks

static EOS_PlayerDataStorage_EReadResult EOS_CALL eos_pds_read_data_callback(
    const EOS_PlayerDataStorage_ReadFileDataCallbackInfo* data)
{
    if (!data || !data->ClientData)
        return EOS_PlayerDataStorage_EReadResult::EOS_RR_FailRequest;

    auto* ctx = static_cast<EOSPDSReadContext*>(data->ClientData);
    if (data->DataChunk && data->DataChunkLengthBytes > 0) {
        const auto* src = static_cast<const uint8_t*>(data->DataChunk);
        ctx->data.insert(ctx->data.end(), src, src + data->DataChunkLengthBytes);
    }
    return EOS_PlayerDataStorage_EReadResult::EOS_RR_ContinueReading;
}

static void EOS_CALL eos_pds_read_file_progress_callback_native(
    const EOS_PlayerDataStorage_FileTransferProgressCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSPDSReadContext*>(data->ClientData);
    if (!ctx || !ctx->progress_callback) return;

    gm_structs::EpicPlayerDataStorageReadFileProgressCallbackInfo out{};
    out.local_user_id = ctx->local_user_id;
    out.filename = ctx->filename;
    out.bytes_transferred = (int64_t)data->BytesTransferred;
    out.total_file_size_bytes = (int64_t)data->TotalFileSizeBytes;
    ctx->progress_callback.value().call(out);
}

static void EOS_CALL eos_pds_read_file_callback_native(
    const EOS_PlayerDataStorage_ReadFileCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSPDSReadContext*>(data->ClientData);
    if (!ctx) return;

    if (data->ResultCode == EOS_EResult::EOS_Success && !ctx->output_path.empty())
        eos_pds_write_entire_file(ctx->output_path, ctx->data);

    gm_structs::EpicPlayerDataStorageReadFileCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = ctx->local_user_id;
    out.filename = ctx->filename;
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

// Write file streaming callbacks

static EOS_PlayerDataStorage_EWriteResult EOS_CALL eos_pds_write_data_callback(
    const EOS_PlayerDataStorage_WriteFileDataCallbackInfo* data,
    void* out_data_buffer,
    uint32_t* out_data_written)
{
    if (!data || !data->ClientData)
        return EOS_PlayerDataStorage_EWriteResult::EOS_WR_FailRequest;

    auto* ctx = static_cast<EOSPDSWriteContext*>(data->ClientData);
    if (ctx->write_offset >= ctx->data.size()) {
        *out_data_written = 0;
        return EOS_PlayerDataStorage_EWriteResult::EOS_WR_CompleteRequest;
    }

    size_t remaining = ctx->data.size() - ctx->write_offset;
    size_t to_write = remaining < (size_t)data->DataBufferLengthBytes
                      ? remaining : (size_t)data->DataBufferLengthBytes;

    std::memcpy(out_data_buffer, ctx->data.data() + ctx->write_offset, to_write);
    *out_data_written = (uint32_t)to_write;
    ctx->write_offset += to_write;

    if (ctx->write_offset >= ctx->data.size())
        return EOS_PlayerDataStorage_EWriteResult::EOS_WR_CompleteRequest;
    return EOS_PlayerDataStorage_EWriteResult::EOS_WR_ContinueWriting;
}

static void EOS_CALL eos_pds_write_file_progress_callback_native(
    const EOS_PlayerDataStorage_FileTransferProgressCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSPDSWriteContext*>(data->ClientData);
    if (!ctx || !ctx->progress_callback) return;

    gm_structs::EpicPlayerDataStorageWriteFileProgressCallbackInfo out{};
    out.local_user_id = ctx->local_user_id;
    out.filename = ctx->filename;
    out.bytes_transferred = (int64_t)data->BytesTransferred;
    out.total_file_size_bytes = (int64_t)data->TotalFileSizeBytes;
    ctx->progress_callback.value().call(out);
}

static void EOS_CALL eos_pds_write_file_callback_native(
    const EOS_PlayerDataStorage_WriteFileCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSPDSWriteContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicPlayerDataStorageWriteFileCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = ctx->local_user_id;
    out.filename = ctx->filename;
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

// ============================================================
// EOS Player Data Storage — Metadata queries
// ============================================================

void eos_playerdatastorage_query_file(
    std::string_view local_user_id,
    std::string_view filename,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HPlayerDataStorage pds = eos_pds_iface();
    if (!pds) { eos_set_last_error("EOS PlayerDataStorage interface unavailable."); return; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) { eos_set_last_error("EOS_PlayerDataStorage_QueryFile: invalid local_user_id."); return; }

    std::string fn(filename);
    if (fn.empty()) { eos_set_last_error("EOS_PlayerDataStorage_QueryFile: filename required."); return; }

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_PlayerDataStorage_QueryFileOptions opts{};
    opts.ApiVersion = EOS_PLAYERDATASTORAGE_QUERYFILE_API_LATEST;
    opts.LocalUserId = local_user;
    opts.Filename = fn.c_str();

    EOS_PlayerDataStorage_QueryFile(pds, &opts, ctx, &eos_pds_query_file_callback_native);
}

void eos_playerdatastorage_query_file_list(
    std::string_view local_user_id,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HPlayerDataStorage pds = eos_pds_iface();
    if (!pds) { eos_set_last_error("EOS PlayerDataStorage interface unavailable."); return; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) { eos_set_last_error("EOS_PlayerDataStorage_QueryFileList: invalid local_user_id."); return; }

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_PlayerDataStorage_QueryFileListOptions opts{};
    opts.ApiVersion = EOS_PLAYERDATASTORAGE_QUERYFILELIST_API_LATEST;
    opts.LocalUserId = local_user;

    EOS_PlayerDataStorage_QueryFileList(pds, &opts, ctx, &eos_pds_query_file_list_callback_native);
}

int64_t eos_playerdatastorage_get_file_metadata_count(std::string_view local_user_id)
{
    EOS_GUARD_RET(0);

    EOS_HPlayerDataStorage pds = eos_pds_iface();
    if (!pds) { eos_set_last_error("EOS PlayerDataStorage interface unavailable."); return 0; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_PlayerDataStorage_GetFileMetadataCount: invalid local_user_id.");
        return 0;
    }

    EOS_PlayerDataStorage_GetFileMetadataCountOptions opts{};
    opts.ApiVersion = EOS_PLAYERDATASTORAGE_GETFILEMETADATACOUNT_API_LATEST;
    opts.LocalUserId = local_user;

    int32_t count = 0;
    EOS_EResult result = EOS_PlayerDataStorage_GetFileMetadataCount(pds, &opts, &count);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_PlayerDataStorage_GetFileMetadataCount failed.");
        return 0;
    }
    return (int64_t)count;
}

gm_structs::EpicPlayerDataStorageFileMetadata eos_playerdatastorage_copy_file_metadata_at_index(
    std::string_view local_user_id,
    int64_t index)
{
    gm_structs::EpicPlayerDataStorageFileMetadata out{};
    EOS_GUARD_RET(out);

    EOS_HPlayerDataStorage pds = eos_pds_iface();
    if (!pds) { eos_set_last_error("EOS PlayerDataStorage interface unavailable."); return out; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_PlayerDataStorage_CopyFileMetadataAtIndex: invalid local_user_id.");
        return out;
    }

    EOS_PlayerDataStorage_CopyFileMetadataAtIndexOptions opts{};
    opts.ApiVersion = EOS_PLAYERDATASTORAGE_COPYFILEMETADATAATINDEX_API_LATEST;
    opts.LocalUserId = local_user;
    opts.Index = (uint32_t)index;

    EOS_PlayerDataStorage_FileMetadata* meta = nullptr;
    EOS_EResult result = EOS_PlayerDataStorage_CopyFileMetadataAtIndex(pds, &opts, &meta);
    if (result != EOS_EResult::EOS_Success || !meta) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_PlayerDataStorage_CopyFileMetadataAtIndex failed.");
        return out;
    }
    out = eos_pds_metadata_from_native(meta);
    EOS_PlayerDataStorage_FileMetadata_Release(meta);
    return out;
}

gm_structs::EpicPlayerDataStorageFileMetadata eos_playerdatastorage_copy_file_metadata_by_filename(
    std::string_view local_user_id,
    std::string_view filename)
{
    gm_structs::EpicPlayerDataStorageFileMetadata out{};
    EOS_GUARD_RET(out);

    EOS_HPlayerDataStorage pds = eos_pds_iface();
    if (!pds) { eos_set_last_error("EOS PlayerDataStorage interface unavailable."); return out; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    std::string fn(filename);
    if (!local_user || fn.empty()) {
        eos_set_last_error("EOS_PlayerDataStorage_CopyFileMetadataByFilename: invalid parameters.");
        return out;
    }

    EOS_PlayerDataStorage_CopyFileMetadataByFilenameOptions opts{};
    opts.ApiVersion = EOS_PLAYERDATASTORAGE_COPYFILEMETADATABYFILENAME_API_LATEST;
    opts.LocalUserId = local_user;
    opts.Filename = fn.c_str();

    EOS_PlayerDataStorage_FileMetadata* meta = nullptr;
    EOS_EResult result = EOS_PlayerDataStorage_CopyFileMetadataByFilename(pds, &opts, &meta);
    if (result != EOS_EResult::EOS_Success || !meta) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_PlayerDataStorage_CopyFileMetadataByFilename failed.");
        return out;
    }
    out = eos_pds_metadata_from_native(meta);
    EOS_PlayerDataStorage_FileMetadata_Release(meta);
    return out;
}

// ============================================================
// EOS Player Data Storage — File operations
// ============================================================

void eos_playerdatastorage_duplicate_file(
    std::string_view local_user_id,
    std::string_view source_filename,
    std::string_view destination_filename,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HPlayerDataStorage pds = eos_pds_iface();
    if (!pds) { eos_set_last_error("EOS PlayerDataStorage interface unavailable."); return; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    std::string src(source_filename), dst(destination_filename);
    if (!local_user || src.empty() || dst.empty()) {
        eos_set_last_error("EOS_PlayerDataStorage_DuplicateFile: invalid parameters.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_PlayerDataStorage_DuplicateFileOptions opts{};
    opts.ApiVersion = EOS_PLAYERDATASTORAGE_DUPLICATEFILE_API_LATEST;
    opts.LocalUserId = local_user;
    opts.SourceFilename = src.c_str();
    opts.DestinationFilename = dst.c_str();

    EOS_PlayerDataStorage_DuplicateFile(pds, &opts, ctx, &eos_pds_duplicate_file_callback_native);
}

void eos_playerdatastorage_delete_file(
    std::string_view local_user_id,
    std::string_view filename,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HPlayerDataStorage pds = eos_pds_iface();
    if (!pds) { eos_set_last_error("EOS PlayerDataStorage interface unavailable."); return; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    std::string fn(filename);
    if (!local_user || fn.empty()) {
        eos_set_last_error("EOS_PlayerDataStorage_DeleteFile: invalid parameters.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_PlayerDataStorage_DeleteFileOptions opts{};
    opts.ApiVersion = EOS_PLAYERDATASTORAGE_DELETEFILE_API_LATEST;
    opts.LocalUserId = local_user;
    opts.Filename = fn.c_str();

    EOS_PlayerDataStorage_DeleteFile(pds, &opts, ctx, &eos_pds_delete_file_callback_native);
}

void eos_playerdatastorage_read_file(
    std::string_view local_user_id,
    std::string_view filename,
    std::string_view output_path,
    const std::optional<gm::wire::GMFunction>& callback,
    const std::optional<gm::wire::GMFunction>& progress_callback)
{
    EOS_GUARD();

    EOS_HPlayerDataStorage pds = eos_pds_iface();
    if (!pds) { eos_set_last_error("EOS PlayerDataStorage interface unavailable."); return; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    std::string fn(filename);
    if (!local_user || fn.empty()) {
        eos_set_last_error("EOS_PlayerDataStorage_ReadFile: invalid parameters.");
        return;
    }

    auto* ctx = new EOSPDSReadContext{};
    ctx->callback = callback;
    ctx->progress_callback = progress_callback;
    ctx->local_user_id = eos_product_user_id_to_string_internal(local_user);
    ctx->filename = fn;
    ctx->output_path = std::string(output_path);

    EOS_PlayerDataStorage_ReadFileOptions opts{};
    opts.ApiVersion = EOS_PLAYERDATASTORAGE_READFILE_API_LATEST;
    opts.LocalUserId = local_user;
    opts.Filename = fn.c_str();
    opts.ReadChunkLengthBytes = 4096;
    opts.ReadFileDataCallback = &eos_pds_read_data_callback;
    opts.FileTransferProgressCallback = progress_callback ? &eos_pds_read_file_progress_callback_native : nullptr;

    EOS_HPlayerDataStorageFileTransferRequest req = EOS_PlayerDataStorage_ReadFile(
        pds, &opts, ctx, &eos_pds_read_file_callback_native);

    if (!req) {
        // EOS still queues the completion callback with our ctx even when it returns null,
        // so we MUST NOT delete ctx here — the callback owns the lifetime.
        eos_set_last_error("EOS_PlayerDataStorage_ReadFile: failed to start transfer.");
    }
}

void eos_playerdatastorage_write_file(
    std::string_view local_user_id,
    std::string_view filename,
    std::string_view input_path,
    const std::optional<gm::wire::GMFunction>& callback,
    const std::optional<gm::wire::GMFunction>& progress_callback)
{
    EOS_GUARD();

    EOS_HPlayerDataStorage pds = eos_pds_iface();
    if (!pds) { eos_set_last_error("EOS PlayerDataStorage interface unavailable."); return; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    std::string fn(filename);
    std::string in_path(input_path);
    if (!local_user || fn.empty() || in_path.empty()) {
        eos_set_last_error("EOS_PlayerDataStorage_WriteFile: invalid parameters.");
        return;
    }

    auto* ctx = new EOSPDSWriteContext{};
    ctx->callback = callback;
    ctx->progress_callback = progress_callback;
    ctx->local_user_id = eos_product_user_id_to_string_internal(local_user);
    ctx->filename = fn;
    ctx->data = eos_pds_read_entire_file(in_path);

    if (ctx->data.empty()) {
        eos_set_last_error("EOS_PlayerDataStorage_WriteFile: input file is empty or could not be read.");
        delete ctx;
        return;
    }

    EOS_PlayerDataStorage_WriteFileOptions opts{};
    opts.ApiVersion = EOS_PLAYERDATASTORAGE_WRITEFILE_API_LATEST;
    opts.LocalUserId = local_user;
    opts.Filename = fn.c_str();
    opts.ChunkLengthBytes = 4096;
    opts.WriteFileDataCallback = &eos_pds_write_data_callback;
    opts.FileTransferProgressCallback = progress_callback ? &eos_pds_write_file_progress_callback_native : nullptr;

    EOS_HPlayerDataStorageFileTransferRequest req = EOS_PlayerDataStorage_WriteFile(
        pds, &opts, ctx, &eos_pds_write_file_callback_native);

    if (!req) {
        // EOS still queues the completion callback with our ctx even when it returns null.
        eos_set_last_error("EOS_PlayerDataStorage_WriteFile: failed to start transfer.");
    }
}

void eos_playerdatastorage_delete_cache(
    std::string_view local_user_id,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HPlayerDataStorage pds = eos_pds_iface();
    if (!pds) { eos_set_last_error("EOS PlayerDataStorage interface unavailable."); return; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_PlayerDataStorage_DeleteCache: invalid local_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_PlayerDataStorage_DeleteCacheOptions opts{};
    opts.ApiVersion = EOS_PLAYERDATASTORAGE_DELETECACHE_API_LATEST;
    opts.LocalUserId = local_user;

    EOS_EResult result = EOS_PlayerDataStorage_DeleteCache(pds, &opts, ctx, &eos_pds_delete_cache_callback_native);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_PlayerDataStorage_DeleteCache failed.");
        delete ctx;
    }
}
