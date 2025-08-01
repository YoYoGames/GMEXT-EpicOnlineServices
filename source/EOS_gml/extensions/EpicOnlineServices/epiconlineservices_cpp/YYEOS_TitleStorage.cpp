
// EOS_TitleStorage_CopyFileMetadataAtIndex
// EOS_TitleStorage_CopyFileMetadataByFilename
// EOS_TitleStorage_DeleteCache
// EOS_TitleStorage_GetFileMetadataCount
// EOS_TitleStorage_QueryFile
// EOS_TitleStorage_QueryFileList
// EOS_TitleStorage_ReadFile
// EOS_TitleStorageFileTransferRequest_CancelRequest
// EOS_TitleStorageFileTransferRequest_GetFilename
// EOS_TitleStorageFileTransferRequest_GetFileRequestState

// Title Storage Interface
// Interface to download encrypted data shared by all players from the cloud

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include "eos_titlestorage.h"

#include <vector>
#include <unordered_map>
#include <string>
#include <codecvt>

#include <fstream>
#include <vector>
#include <iostream>
#include <mutex>

const size_t MaxChunkSize = 4096;

EOS_HTitleStorage HTitleStorage;
void eos_title_storage_init()
{
	HTitleStorage = EOS_Platform_GetTitleStorageInterface(PlatformHandle);
}

RValue FileMetadataToStruct(EOS_TitleStorage_FileMetadata *file, EOS_EResult result)
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
	}

	EOS_TitleStorage_FileMetadata_Release(file);

	return Struct;
}

YYEXPORT void eos_title_storage_copy_file_metadata_at_index(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	uint32_t index = YYGetUint32(arg, 1);

	EOS_TitleStorage_CopyFileMetadataAtIndexOptions Options = {0};
	Options.ApiVersion = EOS_TITLESTORAGE_COPYFILEMETADATAATINDEXOPTIONS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);
	Options.Index = index;

	EOS_TitleStorage_FileMetadata *file;
	EOS_EResult result = EOS_TitleStorage_CopyFileMetadataAtIndex(HTitleStorage, &Options, &file);

	RValue Struct = FileMetadataToStruct(file, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_title_storage_copy_file_metadata_by_filename(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *name = YYGetString(arg, 1);

	EOS_TitleStorage_CopyFileMetadataByFilenameOptions Options = {0};
	Options.ApiVersion = EOS_TITLESTORAGE_COPYFILEMETADATABYFILENAMEOPTIONS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);
	Options.Filename = name;

	EOS_TitleStorage_FileMetadata *file;
	EOS_EResult result = EOS_TitleStorage_CopyFileMetadataByFilename(HTitleStorage, &Options, &file);

	RValue Struct = FileMetadataToStruct(file, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

void EOS_CALL DeleteCache(const EOS_TitleStorage_DeleteCacheCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_title_storage_delete_cache");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_title_storage_delete_cache(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	const char *user = YYGetString(arg, 0);

	EOS_TitleStorage_DeleteCacheOptions Options = {0};
	Options.ApiVersion = EOS_TITLESTORAGE_DELETECACHEOPTIONS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);

	callback *mcallback = getCallbackData();

	EOS_TitleStorage_DeleteCache(HTitleStorage, &Options, mcallback, DeleteCache);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

YYEXPORT void eos_title_storage_get_file_metadata_count(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	const char *user = YYGetString(arg, 0);

	EOS_TitleStorage_GetFileMetadataCountOptions Options = {0};
	Options.ApiVersion = EOS_TITLESTORAGE_GETFILEMETADATACOUNTOPTIONS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);

	Result.kind = VALUE_REAL;
	Result.val = EOS_TitleStorage_GetFileMetadataCount(HTitleStorage, &Options);
}

void EOS_CALL QueryFile(const EOS_TitleStorage_QueryFileCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_title_storage_query_file");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_title_storage_query_file(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *file = YYGetString(arg, 1);

	EOS_TitleStorage_QueryFileOptions Options = {0};
	Options.ApiVersion = EOS_TITLESTORAGE_QUERYFILEOPTIONS_API_LATEST;
	Options.Filename = file;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);

	callback *mcallback = getCallbackData();

	EOS_TitleStorage_QueryFile(HTitleStorage, &Options, mcallback, QueryFile);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL QueryFileList(const EOS_TitleStorage_QueryFileListCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_title_storage_query_file_list");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback*>(data->ClientData);
}

YYEXPORT void eos_title_storage_query_file_list(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);

	std::vector<const char*> Tags;
	if (KIND_RValue(&arg[1]) == VALUE_STRING)
	{
		Tags.push_back(YYGetString(arg, 1));
	}
	else if (KIND_RValue(&arg[1]) == VALUE_ARRAY)
	{

		auto vec = _SW_GetArrayOfStrings(arg, 1, "eos_title_storage_query_file_list");
		for (const auto &e : vec)
		{
			Tags.push_back(e);
		}
	}

	callback* mcallback = getCallbackData();

	EOS_TitleStorage_QueryFileListOptions Options = {0};
	Options.ApiVersion = EOS_TITLESTORAGE_QUERYFILELISTOPTIONS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);
	Options.ListOfTagsCount = static_cast<uint32_t>(Tags.size());
	Options.ListOfTags = Tags.data();

	EOS_TitleStorage_QueryFileList(HTitleStorage, &Options, mcallback, QueryFileList);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

struct FTransferInProgress {
	bool bDownload = true;
	size_t TotalSize = 0;
	size_t CurrentIndex = 0;
	std::vector<char> Data;
	EOS_HTitleStorageFileTransferRequest handle = nullptr;
	std::string output_path;   // full path to write
	bool Done() const { return CurrentIndex >= TotalSize && TotalSize > 0; }
};

static std::mutex g_tsMutex;
static std::unordered_map<std::string, FTransferInProgress> TransfersInProgress;

static void write_entire_file(const std::string& path, const std::vector<char>& buf) {
	std::ofstream f(path, std::ios::binary | std::ios::trunc);
	f.write(buf.data(), static_cast<std::streamsize>(buf.size()));
}

EOS_TitleStorage_EReadResult ReceiveData_TitleStorage(const EOS_TitleStorage_ReadFileDataCallbackInfo* info)
{
	const char* file = info->Filename;
	const void* chunk = info->DataChunk;
	size_t n = info->DataChunkLengthBytes;
	size_t total = info->TotalFileSizeBytes;

	if (!chunk && n > 0) return EOS_TitleStorage_EReadResult::EOS_TS_RR_FailRequest;

	std::lock_guard<std::mutex> lk(g_tsMutex);
	auto it = TransfersInProgress.find(file);
	if (it == TransfersInProgress.end())
		return EOS_TitleStorage_EReadResult::EOS_TS_RR_CancelRequest;

	auto& tr = it->second;

	if (!tr.bDownload) return EOS_TitleStorage_EReadResult::EOS_TS_RR_FailRequest;

	if (tr.TotalSize == 0) {
		tr.TotalSize = total;
		if (tr.TotalSize > 0) tr.Data.resize(tr.TotalSize);
	}

	if (n > 0) {
		if (tr.CurrentIndex + n > tr.TotalSize) return EOS_TitleStorage_EReadResult::EOS_TS_RR_FailRequest;
		std::memcpy(tr.Data.data() + tr.CurrentIndex, chunk, n);
		tr.CurrentIndex += n;
	}

	// Keep reading until EOS signals completion through the final callback.
	return EOS_TitleStorage_EReadResult::EOS_TS_RR_ContinueReading;
}

void EOS_CALL OnFileReceived(const EOS_TitleStorage_ReadFileCallbackInfo* info)
{
	// Result of the transfer (success/fail/cancel)
	std::string file = info->Filename;

	// If EOS invokes this off-main-thread, consider dispatching the DSMap work to the main thread.
	{
		std::lock_guard<std::mutex> lk(g_tsMutex);
		auto it = TransfersInProgress.find(file);
		if (it != TransfersInProgress.end()) {
			auto& tr = it->second;
			if (info->ResultCode == EOS_EResult::EOS_Success && tr.Done()) {
				write_entire_file(tr.output_path, tr.Data);
			}
			if (tr.handle) {
				EOS_TitleStorageFileTransferRequest_Release(tr.handle);
				tr.handle = nullptr;
			}
			TransfersInProgress.erase(it);
		}
	}

	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_title_storage_read_file_on_file_received");
	DsMapAddDouble(map, "status", (double)info->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(info->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)info->ClientData)->identifier);
	DsMapAddString(map, "filename", info->Filename);
	CreateAsyncEventWithDSMap(map, 70);

	// Free the client data now that we're done
	delete reinterpret_cast<callback*>(info->ClientData);
}

EOS_TitleStorage_EReadResult EOS_CALL OnFileDataReceived(const EOS_TitleStorage_ReadFileDataCallbackInfo* info)
{
	if (!info) return EOS_TitleStorage_EReadResult::EOS_TS_RR_FailRequest;

	// If you need to support cancel mid-stream, you can lookup and cancel here using the handle.
	return ReceiveData_TitleStorage(info);
}

void EOS_CALL OnFileTransferProgressUpdated(const EOS_TitleStorage_FileTransferProgressCallbackInfo* info)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_title_storage_read_file_on_file_transfer_progress_updated");
	DsMapAddString(map, "filename", info->Filename);
	DsMapAddDouble(map, "identifier", (double)((callback*)info->ClientData)->identifier);
	DsMapAddInt64(map, "bytes_transferred", info->BytesTransferred);
	DsMapAddInt64(map, "total_file_size_bytes", info->TotalFileSizeBytes);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void eos_title_storage_read_file(RValue& Result, CInstance*, CInstance*, int argc, RValue* arg)
{
	eos_not_init_return_rvalue_real;
	eos_ensure_argc(3);

	const char* user = YYGetString(arg, 0);
	const char* file = YYGetString(arg, 1);
	const char* out_path = YYGetString(arg, 2); // should be full file path

	EOS_TitleStorage_ReadFileOptions opt{};
	opt.ApiVersion = EOS_TITLESTORAGE_READFILEOPTIONS_API_LATEST;
	opt.LocalUserId = EOS_ProductUserId_FromString(user);
	opt.Filename = file;
	opt.ReadChunkLengthBytes = MaxChunkSize;
	opt.ReadFileDataCallback = OnFileDataReceived;
	opt.FileTransferProgressCallback = OnFileTransferProgressUpdated;

	auto* cb = getCallbackData(out_path); // allocates; freed in OnFileReceived
	EOS_HTitleStorageFileTransferRequest h =
		EOS_TitleStorage_ReadFile(HTitleStorage, &opt, cb, OnFileReceived);

	{
		std::lock_guard<std::mutex> lk(g_tsMutex);
		FTransferInProgress tr;
		tr.bDownload = true;
		tr.handle = h;
		tr.output_path = out_path; // full path
		TransfersInProgress[std::string(file)] = std::move(tr);
	}

	Result.kind = VALUE_REAL;
	Result.val = (double)cb->identifier;
}

YYEXPORT void eos_title_storage_file_transfer_request_cancel_request(RValue& Result, CInstance*, CInstance*, int argc, RValue* arg)
{
	eos_not_init_return_rvalue_bool;
	eos_ensure_argc(1);

	const char* file = YYGetString(arg, 0);
	bool ok = false;
	{
		std::lock_guard<std::mutex> lk(g_tsMutex);
		auto it = TransfersInProgress.find(file);
		if (it != TransfersInProgress.end()) {
			if (it->second.handle) {
				EOS_TitleStorageFileTransferRequest_CancelRequest(it->second.handle);
				EOS_TitleStorageFileTransferRequest_Release(it->second.handle);
				it->second.handle = nullptr;
			}
			TransfersInProgress.erase(it);
			ok = true;
		}
	}
	Result.kind = VALUE_BOOL;
	Result.val = ok ? 1.0 : 0.0;
}

// YYEXPORT void eos_title_storage_file_transfer_request_get_filename(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//	const char* file = YYGetString(arg, 0);
//	auto Iter = TransfersInProgress.find(stringToWstring(file));
//	FTransferInProgress& Transfer = Iter->second;
//	EOS_HTitleStorageFileTransferRequest Handle = Transfer.handler;
//	//EOS_TitleStorageFileTransferRequest_GetFilename(Handle, );
// }

YYEXPORT void eos_title_storage_file_transfer_request_get_file_request_state(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	// const char* file = YYGetString(arg, 0);
	// auto Iter = TransfersInProgress.find(stringToWstring(file));
	// FTransferInProgress& Transfer = Iter->second;
	// EOS_EResult result = EOS_TitleStorageFileTransferRequest_GetFileRequestState(Transfer.handler);

	// RValue Struct = { 0 };
	// YYStructCreate(&Struct);

	// YYStructAddDouble(&Struct, "status", (double)result);
	// YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	// COPY_RValue(&Result, &Struct);
	// FREE_RValue(&Struct);
}
