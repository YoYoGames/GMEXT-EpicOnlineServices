
// EOS_PlayerDataStorage_CopyFileMetadataAtIndex
// EOS_PlayerDataStorage_CopyFileMetadataByFilename
// EOS_PlayerDataStorage_DeleteCache
// EOS_PlayerDataStorage_DeleteFile
// EOS_PlayerDataStorage_DuplicateFile
// EOS_PlayerDataStorage_GetFileMetadataCount
// EOS_PlayerDataStorage_QueryFile
// EOS_PlayerDataStorage_QueryFileList
// EOS_PlayerDataStorage_ReadFile
// EOS_PlayerDataStorage_WriteFile
// EOS_PlayerDataStorageFileTransferRequest_CancelRequest
// EOS_PlayerDataStorageFileTransferRequest_GetFilename
// EOS_PlayerDataStorageFileTransferRequest_GetFileRequestState

// Player Data Storage Interface
// Interface to handle cloud - based data management

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include "eos_playerdatastorage.h"

#include <vector>
#include <unordered_map>
#include <string>
#include <codecvt>

#include <fstream>
#include <iostream>
#include <algorithm>
#include <mutex>

const size_t MaxChunkSize = 4096;

EOS_HPlayerDataStorage HPlayerDataStorage;
void eos_player_data_storage_init()
{
	HPlayerDataStorage = EOS_Platform_GetPlayerDataStorageInterface(PlatformHandle);
}

RValue _FileMetadataToStruct(EOS_PlayerDataStorage_FileMetadata *file, EOS_EResult result)
{
	RValue Struct = {0};
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	if (result == EOS_EResult::EOS_Success)
	{
		YYStructAddString(&Struct, "filename", file->Filename);
		YYStructAddDouble(&Struct, "size", file->FileSizeBytes);
		YYStructAddString(&Struct, "md5_hash", file->MD5Hash);
		YYStructAddDouble(&Struct, "size_unencrypted", file->UnencryptedDataSizeBytes);
		YYStructAddInt64(&Struct, "last_modified_time", file->LastModifiedTime);
	}

	EOS_PlayerDataStorage_FileMetadata_Release(file);

	return Struct;
}

YYEXPORT void eos_player_data_storage_copy_file_metadata_at_index(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	uint32_t index = YYGetUint32(arg, 1);

	EOS_PlayerDataStorage_CopyFileMetadataAtIndexOptions Options = {0};
	Options.ApiVersion = EOS_PLAYERDATASTORAGE_COPYFILEMETADATAATINDEXOPTIONS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);
	Options.Index = index;

	EOS_PlayerDataStorage_FileMetadata *file;
	EOS_EResult result = EOS_PlayerDataStorage_CopyFileMetadataAtIndex(HPlayerDataStorage, &Options, &file);
	RValue Struct = _FileMetadataToStruct(file, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_player_data_storage_copy_file_metadata_by_filename(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *name = YYGetString(arg, 1);

	EOS_PlayerDataStorage_CopyFileMetadataByFilenameOptions Options = {0};
	Options.ApiVersion = EOS_PLAYERDATASTORAGE_COPYFILEMETADATABYFILENAMEOPTIONS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);
	Options.Filename = name;

	EOS_PlayerDataStorage_FileMetadata *file;
	EOS_EResult result = EOS_PlayerDataStorage_CopyFileMetadataByFilename(HPlayerDataStorage, &Options, &file);
	RValue Struct = _FileMetadataToStruct(file, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

void EOS_CALL DeleteCache(const EOS_PlayerDataStorage_DeleteCacheCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_player_data_storage_delete_cache");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_player_data_storage_delete_cache(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	const char *user = YYGetString(arg, 0);

	EOS_PlayerDataStorage_DeleteCacheOptions Options = {0};
	Options.ApiVersion = EOS_PLAYERDATASTORAGE_DELETECACHEOPTIONS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);

	callback *mcallback = getCallbackData();

	EOS_PlayerDataStorage_DeleteCache(HPlayerDataStorage, &Options, mcallback, DeleteCache);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL DeleteFile(const EOS_PlayerDataStorage_DeleteFileCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_player_data_storage_delete_file");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_player_data_storage_delete_file(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *filename = YYGetString(arg, 1);

	EOS_PlayerDataStorage_DeleteFileOptions Options = {0};
	Options.ApiVersion = EOS_PLAYERDATASTORAGE_DELETEFILEOPTIONS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);
	Options.Filename = filename;

	callback *mcallback = getCallbackData();

	EOS_PlayerDataStorage_DeleteFile(HPlayerDataStorage, &Options, mcallback, DeleteFile);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL OnFileCopied(const EOS_PlayerDataStorage_DuplicateFileCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_player_data_storage_duplicate_file");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_player_data_storage_duplicate_file(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(3);

	const char *user = YYGetString(arg, 0);
	const char *source = YYGetString(arg, 1);
	const char *destination = YYGetString(arg, 2);

	EOS_PlayerDataStorage_DuplicateFileOptions Options;
	Options.ApiVersion = EOS_PLAYERDATASTORAGE_DUPLICATEFILEOPTIONS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);
	Options.SourceFilename = source;
	Options.DestinationFilename = destination;

	callback *mcallback = getCallbackData();

	EOS_PlayerDataStorage_DuplicateFile(HPlayerDataStorage, &Options, mcallback, OnFileCopied);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

YYEXPORT void eos_player_data_storage_get_file_metadata_count(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_bool;

	eos_ensure_argc(1);

	const char *user = YYGetString(arg, 0);
	EOS_PlayerDataStorage_GetFileMetadataCountOptions Options = {0};
	Options.ApiVersion = EOS_PLAYERDATASTORAGE_GETFILEMETADATACOUNTOPTIONS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);

	int32_t count;
	EOS_PlayerDataStorage_GetFileMetadataCount(HPlayerDataStorage, &Options, &count);

	Result.kind = VALUE_BOOL;
	Result.val = count;
}

void EOS_CALL QueryFile(const EOS_PlayerDataStorage_QueryFileCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_player_data_storage_query_file");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_player_data_storage_query_file(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *filename = YYGetString(arg, 1);

	EOS_PlayerDataStorage_QueryFileOptions Options;
	Options.ApiVersion = EOS_PLAYERDATASTORAGE_QUERYFILEOPTIONS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);
	Options.Filename = filename;

	callback *mcallback = getCallbackData();

	EOS_PlayerDataStorage_QueryFile(HPlayerDataStorage, &Options, mcallback, QueryFile);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL QueryFileList(const EOS_PlayerDataStorage_QueryFileListCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_player_data_storage_query_file_list");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddDouble(map, "filename", data->FileCount);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_player_data_storage_query_file_list(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	const char *user = YYGetString(arg, 0);

	EOS_PlayerDataStorage_QueryFileListOptions Options;
	Options.ApiVersion = EOS_PLAYERDATASTORAGE_QUERYFILELISTOPTIONS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);

	callback *mcallback = getCallbackData();

	EOS_PlayerDataStorage_QueryFileList(HPlayerDataStorage, &Options, mcallback, QueryFileList);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}


struct FTransferInProgress_PDS {
    bool bDownload = true;  // true = read (download); false = write (upload)
    size_t TotalSize = 0;
    size_t CurrentIndex = 0;
    std::vector<char> Data;
    EOS_HPlayerDataStorageFileTransferRequest Handle = nullptr;
    std::string output_path; // for read, full file path to write at completion

    bool Done() const { return TotalSize > 0 && CurrentIndex >= TotalSize; }
};

static std::mutex g_pdsMutex;
static std::unordered_map<std::string, FTransferInProgress_PDS> TransfersInProgressPDS;

static void write_entire_file(const std::string& path, const std::vector<char>& buf) {
    std::ofstream f(path, std::ios::binary | std::ios::trunc);
    if (f && !buf.empty()) {
        f.write(buf.data(), static_cast<std::streamsize>(buf.size()));
    }
}

static std::vector<unsigned char> readBinaryFile_(const char* filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) return {};
    file.seekg(0, std::ios::end);
    std::streampos end = file.tellg();
    if (end <= 0) return {};
    std::vector<unsigned char> data(static_cast<size_t>(end));
    file.seekg(0, std::ios::beg);
    file.read(reinterpret_cast<char*>(data.data()), end);
    return data;
}

EOS_PlayerDataStorage_EReadResult ReceiveData_PlayerDataStorage(const EOS_PlayerDataStorage_ReadFileDataCallbackInfo* info)
{
    if (!info) return EOS_PlayerDataStorage_EReadResult::EOS_RR_FailRequest;

    const char* file = info->Filename;
    const void* chunk = info->DataChunk;
    size_t n = info->DataChunkLengthBytes;
    size_t total = info->TotalFileSizeBytes;

    std::lock_guard<std::mutex> lk(g_pdsMutex);
    auto it = TransfersInProgressPDS.find(std::string(file));
    if (it == TransfersInProgressPDS.end())
        return EOS_PlayerDataStorage_EReadResult::EOS_RR_CancelRequest;

    auto& tr = it->second;
    if (!tr.bDownload) return EOS_PlayerDataStorage_EReadResult::EOS_RR_FailRequest;

    if (tr.TotalSize == 0 && total > 0) {
        tr.TotalSize = total;
        tr.Data.resize(tr.TotalSize);
    }

    if (chunk && n > 0) {
        if (tr.CurrentIndex + n > tr.TotalSize) {
            return EOS_PlayerDataStorage_EReadResult::EOS_RR_FailRequest;
        }
        std::memcpy(tr.Data.data() + tr.CurrentIndex, chunk, n);
        tr.CurrentIndex += n;
    }

    return EOS_PlayerDataStorage_EReadResult::EOS_RR_ContinueReading;
}

EOS_PlayerDataStorage_EReadResult EOS_CALL OnFileDataReceived(const EOS_PlayerDataStorage_ReadFileDataCallbackInfo* info)
{
    return info ? ReceiveData_PlayerDataStorage(info)
        : EOS_PlayerDataStorage_EReadResult::EOS_RR_FailRequest;
}

void EOS_CALL OnFileTransferProgressUpdated_read(const EOS_PlayerDataStorage_FileTransferProgressCallbackInfo* data)
{
    int map = CreateDsMap(0, 0);
    DsMapAddString(map, "type", "eos_player_data_storage_read_file_on_file_transfer_progress_updated");
    DsMapAddDouble(map, "identifier", (double)((callback*)data->ClientData)->identifier);
    DsMapAddString(map, "filename", data->Filename);
    DsMapAddInt64(map, "bytes_transferred", data->BytesTransferred);
    DsMapAddInt64(map, "total_file_size_bytes", data->TotalFileSizeBytes);
    CreateAsyncEventWithDSMap(map, 70);
}

void EOS_CALL OnFileReceived(const EOS_PlayerDataStorage_ReadFileCallbackInfo* data)
{
    // Write the file if success, release handle, erase entry.
    {
        std::lock_guard<std::mutex> lk(g_pdsMutex);
        auto it = TransfersInProgressPDS.find(std::string(data->Filename));
        if (it != TransfersInProgressPDS.end()) {
            auto& tr = it->second;
            if (data->ResultCode == EOS_EResult::EOS_Success && tr.Done() && !tr.output_path.empty()) {
                write_entire_file(tr.output_path, tr.Data);
            }
            if (tr.Handle) {
                EOS_PlayerDataStorageFileTransferRequest_Release(tr.Handle);
                tr.Handle = nullptr;
            }
            TransfersInProgressPDS.erase(it);
        }
    }

    int map = CreateDsMap(0, 0);
    DsMapAddString(map, "type", "eos_player_data_storage_read_file_on_file_received");
    DsMapAddDouble(map, "status", (double)data->ResultCode);
    DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
    DsMapAddDouble(map, "identifier", (double)((callback*)data->ClientData)->identifier);
    DsMapAddString(map, "filename", data->Filename);
    CreateAsyncEventWithDSMap(map, 70);

    // Delete ClientData exactly once in the terminal callback.
    delete reinterpret_cast<callback*>(data->ClientData);
}

YYEXPORT void eos_player_data_storage_read_file(RValue& Result, CInstance*, CInstance*, int argc, RValue* arg)
{
    eos_not_init_return_rvalue_real;
    eos_ensure_argc(3);

    const char* user = YYGetString(arg, 0);
    const char* file = YYGetString(arg, 1);
    const char* path = YYGetString(arg, 2); // full output path

    EOS_PlayerDataStorage_ReadFileOptions Options{};
    Options.ApiVersion = EOS_PLAYERDATASTORAGE_READFILEOPTIONS_API_LATEST;
    Options.LocalUserId = EOS_ProductUserId_FromString(user);
    Options.Filename = file;
    Options.ReadChunkLengthBytes = MaxChunkSize;
    Options.ReadFileDataCallback = OnFileDataReceived;
    Options.FileTransferProgressCallback = OnFileTransferProgressUpdated_read;

    callback* mcallback = getCallbackData(path); // freed in OnFileReceived
    EOS_HPlayerDataStorageFileTransferRequest Handle =
        EOS_PlayerDataStorage_ReadFile(HPlayerDataStorage, &Options, mcallback, OnFileReceived);

    {
        std::lock_guard<std::mutex> lk(g_pdsMutex);
        FTransferInProgress_PDS tr;
        tr.bDownload = true;
        tr.Handle = Handle;
        tr.output_path = path;
        TransfersInProgressPDS[std::string(file)] = std::move(tr);
    }

    Result.kind = VALUE_REAL;
    Result.val = (double)mcallback->identifier;
}

EOS_PlayerDataStorage_EWriteResult SendData_PlayerDataStorage(const char* file, void* outBuf, uint32_t* outWritten)
{
    if (!file || !outBuf || !outWritten)
        return EOS_PlayerDataStorage_EWriteResult::EOS_WR_FailRequest;

    std::lock_guard<std::mutex> lk(g_pdsMutex);
    auto it = TransfersInProgressPDS.find(std::string(file));
    if (it == TransfersInProgressPDS.end()) {
        *outWritten = 0;
        return EOS_PlayerDataStorage_EWriteResult::EOS_WR_CancelRequest;
    }
    auto& tr = it->second;
    if (tr.bDownload) {
        *outWritten = 0;
        return EOS_PlayerDataStorage_EWriteResult::EOS_WR_FailRequest;
    }

    if (tr.Done()) {
        *outWritten = 0;
        return EOS_PlayerDataStorage_EWriteResult::EOS_WR_CompleteRequest;
    }

    size_t remaining = tr.TotalSize - tr.CurrentIndex;
    size_t toWrite = remaining > MaxChunkSize ? MaxChunkSize : remaining;
    if (toWrite > 0) {
        std::memcpy(outBuf, tr.Data.data() + tr.CurrentIndex, toWrite);
        tr.CurrentIndex += toWrite;
    }
    *outWritten = static_cast<uint32_t>(toWrite);

    return tr.Done()
        ? EOS_PlayerDataStorage_EWriteResult::EOS_WR_CompleteRequest
        : EOS_PlayerDataStorage_EWriteResult::EOS_WR_ContinueWriting;
}

EOS_PlayerDataStorage_EWriteResult EOS_CALL OnFileDataSend(
    const EOS_PlayerDataStorage_WriteFileDataCallbackInfo* data,
    void* OutDataBuffer, uint32_t* OutDataWritten)
{
    return data ? SendData_PlayerDataStorage(data->Filename, OutDataBuffer, OutDataWritten)
        : EOS_PlayerDataStorage_EWriteResult::EOS_WR_FailRequest;
}

void EOS_CALL OnFileTransferProgressUpdated_write(const EOS_PlayerDataStorage_FileTransferProgressCallbackInfo* data)
{
    // NOTE: Do NOT delete ClientData here; terminal callback will do it.
    int map = CreateDsMap(0, 0);
    DsMapAddString(map, "type", "eos_player_data_storage_write_file_on_file_transfer_progress_updated");
    DsMapAddDouble(map, "identifier", (double)((callback*)data->ClientData)->identifier);
    DsMapAddString(map, "filename", data->Filename);
    DsMapAddInt64(map, "bytes_transferred", data->BytesTransferred);
    DsMapAddInt64(map, "total_file_size_bytes", data->TotalFileSizeBytes);
    CreateAsyncEventWithDSMap(map, 70);
}

void EOS_CALL OnFileSent(const EOS_PlayerDataStorage_WriteFileCallbackInfo* data)
{
    {
        std::lock_guard<std::mutex> lk(g_pdsMutex);
        auto it = TransfersInProgressPDS.find(std::string(data->Filename));
        if (it != TransfersInProgressPDS.end()) {
            if (it->second.Handle) {
                EOS_PlayerDataStorageFileTransferRequest_Release(it->second.Handle);
                it->second.Handle = nullptr;
            }
            TransfersInProgressPDS.erase(it);
        }
    }

    int map = CreateDsMap(0, 0);
    DsMapAddString(map, "type", "eos_player_data_storage_write_file_on_file_sent");
    DsMapAddDouble(map, "identifier", (double)((callback*)data->ClientData)->identifier);
    DsMapAddString(map, "filename", data->Filename);
    DsMapAddDouble(map, "status", (double)data->ResultCode);
    DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
    CreateAsyncEventWithDSMap(map, 70);

    delete reinterpret_cast<callback*>(data->ClientData);
}

YYEXPORT void eos_player_data_storage_write_file(RValue& Result, CInstance*, CInstance*, int argc, RValue* arg)
{
    eos_not_init_return_rvalue_real;
    eos_ensure_argc(3);

    const char* user = YYGetString(arg, 0);
    const char* file = YYGetString(arg, 1);
    const char* path = YYGetString(arg, 2); // path to local file you want to upload

    // Load file into memory (you can stream from disk if needed)
    std::vector<unsigned char> v = readBinaryFile_(path);

    EOS_PlayerDataStorage_WriteFileOptions Options{};
    Options.ApiVersion = EOS_PLAYERDATASTORAGE_WRITEFILEOPTIONS_API_LATEST;
    Options.LocalUserId = EOS_ProductUserId_FromString(user);
    Options.Filename = file;
    Options.ChunkLengthBytes = MaxChunkSize;
    Options.WriteFileDataCallback = OnFileDataSend;
    Options.FileTransferProgressCallback = OnFileTransferProgressUpdated_write;

    callback* mcallback = getCallbackData(); // freed in OnFileSent

    EOS_HPlayerDataStorageFileTransferRequest Handle =
        EOS_PlayerDataStorage_WriteFile(HPlayerDataStorage, &Options, mcallback, OnFileSent);

    if (!Handle) {
        delete mcallback; // avoid leaking client data if the call failed to start
        Result.kind = VALUE_REAL;
        Result.val = -1.0;
        return;
    }

    {
        std::lock_guard<std::mutex> lk(g_pdsMutex);
        FTransferInProgress_PDS tr;
        tr.bDownload = false;
        tr.Handle = Handle;
        tr.TotalSize = v.size();
        tr.Data.resize(v.size());
        if (!v.empty()) {
            std::memcpy(tr.Data.data(), v.data(), v.size());
        }
        tr.CurrentIndex = 0;
        TransfersInProgressPDS[std::string(file)] = std::move(tr);
    }

    Result.kind = VALUE_REAL;
    Result.val = (double)mcallback->identifier;
}

YYEXPORT void eos_player_data_storage_file_transfer_request_cancel_request(RValue& Result, CInstance*, CInstance*, int argc, RValue* arg)
{
    eos_not_init_return_rvalue_bool;
    eos_ensure_argc(1);

    const char* file = YYGetString(arg, 0);
    bool ok = false;

    {
        std::lock_guard<std::mutex> lk(g_pdsMutex);
        auto it = TransfersInProgressPDS.find(std::string(file));
        if (it != TransfersInProgressPDS.end()) {
            if (it->second.Handle) {
                EOS_PlayerDataStorageFileTransferRequest_CancelRequest(it->second.Handle);
                EOS_PlayerDataStorageFileTransferRequest_Release(it->second.Handle);
                it->second.Handle = nullptr;
            }
            TransfersInProgressPDS.erase(it);
            ok = true;
        }
    }

    Result.kind = VALUE_BOOL;
    Result.val = ok ? 1.0 : 0.0;
}

YYEXPORT void eos_player_data_storage_file_transfer_request_get_filename(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	// EOS_PlayerDataStorageFileTransferRequest_GetFilename
}

YYEXPORT void eos_player_data_storage_file_transfer_request_get_file_request_state(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	// DebugConsoleOutput("eos_player_data_storage_file_transfer_request_get_file_request_state\n");
	// DebugConsoleOutput("1\n");
	// const char* file = YYGetString(arg, 0);
	// auto Iter = TransfersInProgress_.find(stringToWstring(file));
	// if (Iter == TransfersInProgress_.end())
	//{
	//	RValue Struct = { 0 };
	//	YYStructCreate(&Struct);
	//	COPY_RValue(&Result, &Struct);
	//	FREE_RValue(&Struct);

	//	return;
	//}
	// DebugConsoleOutput("2\n");
	// FTransferInProgress__old& Transfer = Iter->second;
	// DebugConsoleOutput("2-3\n");
	// EOS_EResult result = EOS_PlayerDataStorageFileTransferRequest_GetFileRequestState(Transfer.Handler);
	// DebugConsoleOutput("3\n");
	// RValue Struct = { 0 };
	// YYStructCreate(&Struct);
	// DebugConsoleOutput("4\n");
	// YYStructAddDouble(&Struct, "status", (double)result);
	// YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));
	// DebugConsoleOutput("5\n");
	// COPY_RValue(&Result, &Struct);
	// FREE_RValue(&Struct);
	// DebugConsoleOutput("6\n");
}
