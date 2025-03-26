
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
		YYStructAddString(&Struct, "m_d5_hash", file->MD5Hash);
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
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_title_storage_query_file_list(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);

	std::vector<const char *> Tags;
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

	EOS_TitleStorage_QueryFileListOptions Options = {0};
	Options.ApiVersion = EOS_TITLESTORAGE_QUERYFILELISTOPTIONS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);
	Options.ListOfTagsCount = static_cast<uint32_t>(Tags.size());
	Options.ListOfTags = Tags.data();

	callback *mcallback = getCallbackData();

	EOS_TitleStorage_QueryFileList(HTitleStorage, &Options, mcallback, QueryFileList);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

struct FTransferInProgress
{
	bool bDownload = true;
	size_t TotalSize = 0;
	size_t CurrentIndex = 0;
	std::vector<char> Data;
	EOS_HTitleStorageFileTransferRequest handler = {0};

	bool Done() const { return TotalSize == CurrentIndex; }
};

std::unordered_map</*std::wstring*/ /*const char**/ std::string, FTransferInProgress> TransfersInProgress;
EOS_TitleStorage_EReadResult ReceiveData_TitleStorage(const EOS_TitleStorage_ReadFileDataCallbackInfo *Data_)
{
	const char *FileName = Data_->Filename;
	/*std::wstring*/ std::string path = ((callback *)(Data_->ClientData))->string;
	const void *data = Data_->DataChunk;
	size_t NumBytes = Data_->DataChunkLengthBytes;
	size_t TotalSize = Data_->TotalFileSizeBytes;

	if (!data)
	{
		// FDebugLog::LogError(L"[EOS SDK] Title storage: could not receive data: Data pointer is null.");
		return EOS_TitleStorage_EReadResult::EOS_TS_RR_FailRequest;
	}

	auto Iter = TransfersInProgress.find(/*stringToWstring*/ (FileName));
	if (Iter != TransfersInProgress.end())
	{
		FTransferInProgress &Transfer = Iter->second;

		if (!Transfer.bDownload)
		{
			// FDebugLog::LogError(L"[EOS SDK] Title storage: can't load file data: download/upload mismatch.");
			return EOS_TitleStorage_EReadResult::EOS_TS_RR_FailRequest;
		}

		// First update
		if (Transfer.CurrentIndex == 0 && Transfer.TotalSize == 0)
		{
			Transfer.TotalSize = TotalSize;

			if (Transfer.TotalSize == 0)
			{
				return EOS_TitleStorage_EReadResult::EOS_TS_RR_ContinueReading;
			}

			Transfer.Data.resize(TotalSize);
		}

		// Make sure we have enough space
		if (Transfer.TotalSize - Transfer.CurrentIndex >= NumBytes)
		{
			memcpy(static_cast<void *>(&Transfer.Data[Transfer.CurrentIndex]), data, NumBytes);
			Transfer.CurrentIndex += NumBytes;

			// std::string path = "C:/Users/chuyz/Desktop/Here/";
			// std::string filename = FileName;
			std::ofstream file(path /*path+filename*/, std::ios::binary);
			for (const char p : Transfer.Data)
				file.write(&p, sizeof(p));

			// DebugConsoleOutput("HERE: EOS_TitleStorage_EReadResult::EOS_TS_RR_ContinueReading");
			return EOS_TitleStorage_EReadResult::EOS_TS_RR_ContinueReading;
		}
		else
		{
			// FDebugLog::LogError(L"[EOS SDK] Title storage: could not receive data: too much of it.");
			return EOS_TitleStorage_EReadResult::EOS_TS_RR_FailRequest;
		}
	}
	//	DebugConsoleOutput("HERE: EOS_TitleStorage_EReadResult::EOS_TS_RR_CancelRequest");
	return EOS_TitleStorage_EReadResult::EOS_TS_RR_CancelRequest;
}

void EOS_CALL OnFileReceived(const EOS_TitleStorage_ReadFileCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_title_storage_read_file_on_file_received");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "filename", data->Filename);
	CreateAsyncEventWithDSMap(map, 70);
}

EOS_TitleStorage_EReadResult EOS_CALL OnFileDataReceived(const EOS_TitleStorage_ReadFileDataCallbackInfo *data)
{
	const char *file = data->Filename;

	auto Iter = TransfersInProgress.find(/*stringToWstring*/ (file));

	FTransferInProgress &Transfer = Iter->second;
	EOS_HTitleStorageFileTransferRequest Handle = Transfer.handler;
	// EOS_TitleStorageFileTransferRequest_CancelRequest(Handle);

	// return FGame::Get().GetTitleStorage()->ReceiveData(FStringUtils::Widen(data->Filename), data->DataChunk, data->DataChunkLengthBytes, data->TotalFileSizeBytes);
	if (data)
		return ReceiveData_TitleStorage(data);

	return EOS_TitleStorage_EReadResult::EOS_TS_RR_FailRequest;
}

void EOS_CALL OnFileTransferProgressUpdated(const EOS_TitleStorage_FileTransferProgressCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_title_storage_read_file_on_file_transfer_progress_updated");
	DsMapAddString(map, "filename", data->Filename);
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddInt64(map, "bytes_transferred", data->BytesTransferred);
	DsMapAddInt64(map, "total_file_size_bytes", data->TotalFileSizeBytes);
	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void eos_title_storage_read_file(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(3);

	const char *user = YYGetString(arg, 0);
	const char *file = YYGetString(arg, 1);
	const char *path = YYGetString(arg, 2);

	EOS_TitleStorage_ReadFileOptions Options = {};
	Options.ApiVersion = EOS_TITLESTORAGE_READFILEOPTIONS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);
	Options.Filename = file;
	Options.ReadChunkLengthBytes = MaxChunkSize;
	Options.ReadFileDataCallback = OnFileDataReceived;
	Options.FileTransferProgressCallback = OnFileTransferProgressUpdated;

	callback *mcallback = getCallbackData(path);
	EOS_HTitleStorageFileTransferRequest Handle = EOS_TitleStorage_ReadFile(HTitleStorage, &Options, mcallback, OnFileReceived);

	FTransferInProgress NewTransfer;
	NewTransfer.bDownload = true;
	NewTransfer.handler = Handle;

	TransfersInProgress[/*stringToWstring*/ (file)] = NewTransfer;

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

YYEXPORT void eos_title_storage_file_transfer_request_cancel_request(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_bool;

	eos_ensure_argc(1);

	const char *file = YYGetString(arg, 0);
	auto Iter = TransfersInProgress.find(/*stringToWstring*/ (file));
	FTransferInProgress &Transfer = Iter->second;
	EOS_TitleStorageFileTransferRequest_CancelRequest(Transfer.handler);
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
