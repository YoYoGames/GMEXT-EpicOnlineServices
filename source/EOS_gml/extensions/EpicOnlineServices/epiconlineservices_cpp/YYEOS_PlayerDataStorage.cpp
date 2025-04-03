
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
		YYStructAddString(&Struct, "m_d5_hash", file->MD5Hash);
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

struct FTransferInProgress__old
{
	bool bDownload = true;
	size_t TotalSize = 0;
	size_t CurrentIndex = 0;
	std::vector<char> Data;
	EOS_HPlayerDataStorageFileTransferRequest Handler = {0};

	bool Done() const { return TotalSize == CurrentIndex; }
};

std::unordered_map</*std::wstring*/ /*const char**/ std::string, FTransferInProgress__old> TransfersInProgress_;
void EOS_CALL OnFileReceived(const EOS_PlayerDataStorage_ReadFileCallbackInfo *data)
{
	auto Iter = TransfersInProgress_.find(/*stringToWstring*/ (data->Filename));
	FTransferInProgress__old &Transfer = Iter->second;
	EOS_PlayerDataStorageFileTransferRequest_Release(Transfer.Handler);

	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_player_data_storage_read_file_on_file_received");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "filename", data->Filename);
	CreateAsyncEventWithDSMap(map, 70);
}

EOS_PlayerDataStorage_EReadResult ReceiveData_PlayerDataStorage(const EOS_PlayerDataStorage_ReadFileDataCallbackInfo *Data_)
{
	const char *FileName = Data_->Filename;
	/*std::wstring path*/ /*const char**/ std::string path = ((callback *)(Data_->ClientData))->string;
	const void *data = Data_->DataChunk;
	size_t NumBytes = Data_->DataChunkLengthBytes;
	size_t TotalSize = Data_->TotalFileSizeBytes;

	if (!data)
	{
		DebugConsoleOutput("[EOS SDK] Title storage: could not receive data: data pointer is null.");
		return EOS_PlayerDataStorage_EReadResult::EOS_RR_FailRequest;
	}

	auto Iter = TransfersInProgress_.find(/*stringToWstring*/ (FileName));
	if (Iter != TransfersInProgress_.end())
	{
		FTransferInProgress__old &Transfer = Iter->second;

		if (!Transfer.bDownload)
		{
			DebugConsoleOutput("[EOS SDK] Title storage: can't load file data: download/upload mismatch.");
			return EOS_PlayerDataStorage_EReadResult::EOS_RR_FailRequest;
		}

		// First update
		if (Transfer.CurrentIndex == 0 && Transfer.TotalSize == 0)
		{
			Transfer.TotalSize = TotalSize;

			if (Transfer.TotalSize == 0)
			{
				return EOS_PlayerDataStorage_EReadResult::EOS_RR_ContinueReading;
			}

			Transfer.Data.resize(TotalSize);
		}

		// Make sure we have enough space
		if (Transfer.TotalSize - Transfer.CurrentIndex >= NumBytes)
		{
			memcpy(static_cast<void *>(&Transfer.Data[Transfer.CurrentIndex]), data, NumBytes);
			Transfer.CurrentIndex += NumBytes;

			// DebugConsoleOutput("PATHS:\n%ls\n", ((callback*)(Data_->ClientData))->string);
			
			std::ofstream file(path /*path + filename*/, std::ios::binary);
			for (const char p : Transfer.Data)
				file.write(&p, sizeof(p));

			return EOS_PlayerDataStorage_EReadResult::EOS_RR_ContinueReading;
		}
		else
		{
			DebugConsoleOutput("[EOS SDK] Title storage: could not receive data: too much of it.");
			return EOS_PlayerDataStorage_EReadResult::EOS_RR_FailRequest;
		}
	}

	return EOS_PlayerDataStorage_EReadResult::EOS_RR_CancelRequest;
}

EOS_PlayerDataStorage_EReadResult EOS_CALL OnFileDataReceived(const EOS_PlayerDataStorage_ReadFileDataCallbackInfo *data)
{
	if (data)
		return ReceiveData_PlayerDataStorage(data);

	return EOS_PlayerDataStorage_EReadResult::EOS_RR_FailRequest;
}

void EOS_CALL OnFileTransferProgressUpdated_read(const EOS_PlayerDataStorage_FileTransferProgressCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_player_data_storage_read_file_on_file_transfer_progress_updated");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "filename", data->Filename);
	DsMapAddDouble(map, "bytes_transferred", data->BytesTransferred);
	DsMapAddDouble(map, "total_file_size_bytes", data->TotalFileSizeBytes);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_player_data_storage_read_file(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(3);

	const char *user = YYGetString(arg, 0);
	const char *file = YYGetString(arg, 1);
	const char *path = YYGetString(arg, 2);

	EOS_PlayerDataStorage_ReadFileOptions Options;
	Options.ApiVersion = EOS_PLAYERDATASTORAGE_READFILEOPTIONS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);
	Options.Filename = file;
	Options.ReadChunkLengthBytes = MaxChunkSize;

	Options.ReadFileDataCallback = OnFileDataReceived;
	Options.FileTransferProgressCallback = OnFileTransferProgressUpdated_read;
	callback *mcallback = getCallbackData(path);

	EOS_HPlayerDataStorageFileTransferRequest Handle = EOS_PlayerDataStorage_ReadFile(HPlayerDataStorage, &Options, mcallback, OnFileReceived);

	FTransferInProgress__old NewTransfer;
	NewTransfer.bDownload = true;
	NewTransfer.Handler = Handle;
	TransfersInProgress_[/*stringToWstring*/ (file)] = NewTransfer;

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

EOS_PlayerDataStorage_EWriteResult SendData(const char *FileName, void *data, uint32_t *BytesWritten)
{
	DebugConsoleOutput("[EOS SDK] EOS_PlayerDataStorage_EWriteResult\n");
	if (!data || !BytesWritten)
	{
		DebugConsoleOutput("[EOS SDK] Player data storage: could not send data: pointer is null.\n");
		return EOS_PlayerDataStorage_EWriteResult::EOS_WR_FailRequest;
	}
	auto Iter = TransfersInProgress_.find(/*stringToWstring*/ (FileName));
	if (Iter != TransfersInProgress_.end())
	{
		FTransferInProgress__old &Transfer = Iter->second;

		if (Transfer.bDownload)
		{
			DebugConsoleOutput("[EOS SDK] Player data storage: can't send file data: download/upload mismatch.\n");
			return EOS_PlayerDataStorage_EWriteResult::EOS_WR_FailRequest;
		}
		if (Transfer.Done())
		{
			*BytesWritten = 0;
			DebugConsoleOutput("[EOS SDK] EOS_PlayerDataStorage_EWriteResult COMPLETE\n");
			return EOS_PlayerDataStorage_EWriteResult::EOS_WR_CompleteRequest;
		}
		size_t BytesToWrite;
		if (MaxChunkSize < Transfer.TotalSize - Transfer.CurrentIndex)
			BytesToWrite = MaxChunkSize;
		else
			BytesToWrite = Transfer.TotalSize - Transfer.CurrentIndex;
		if (BytesToWrite > 0)
		{
			memcpy(data, static_cast<const void *>(&Transfer.Data[Transfer.CurrentIndex]), BytesToWrite);
		}
		*BytesWritten = static_cast<uint32_t>(BytesToWrite);

		Transfer.CurrentIndex += BytesToWrite;
		if (Transfer.Done())
		{
			// DebugConsoleOutput("[EOS SDK] EOS_PlayerDataStorage_EWriteResult EOS_WR_CompleteRequest\n");
			return EOS_PlayerDataStorage_EWriteResult::EOS_WR_CompleteRequest;
		}
		else
		{
			// DebugConsoleOutput("[EOS SDK] EOS_PlayerDataStorage_EWriteResult EOS_WR_ContinueWriting\n");
			return EOS_PlayerDataStorage_EWriteResult::EOS_WR_ContinueWriting;
		}
	}
	else
	{
		DebugConsoleOutput("[EOS SDK] Player data storage: could not send data as this file is not being uploaded at the moment.\n");
		*BytesWritten = 0;
		return EOS_PlayerDataStorage_EWriteResult::EOS_WR_CancelRequest;
	}
}

EOS_PlayerDataStorage_EWriteResult EOS_CALL OnFileDataSend(const EOS_PlayerDataStorage_WriteFileDataCallbackInfo *data, void *OutDataBuffer, uint32_t *OutDataWritten)
{
	if (data)
		return SendData(data->Filename, OutDataBuffer, OutDataWritten);

	return EOS_PlayerDataStorage_EWriteResult::EOS_WR_FailRequest;
}

void EOS_CALL OnFileTransferProgressUpdated_write(const EOS_PlayerDataStorage_FileTransferProgressCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_player_data_storage_write_file_on_file_transfer_progress_updated");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "filename", data->Filename);
	DsMapAddDouble(map, "bytes_transferred", data->BytesTransferred);
	DsMapAddDouble(map, "total_file_size_bytes", data->TotalFileSizeBytes);
	CreateAsyncEventWithDSMap(map, 70);
}

void EOS_CALL OnFileSent(const EOS_PlayerDataStorage_WriteFileCallbackInfo *data)
{
	auto Iter = TransfersInProgress_.find(/*stringToWstring*/ (data->Filename));
	FTransferInProgress__old &Transfer = Iter->second;
	EOS_PlayerDataStorageFileTransferRequest_Release(Transfer.Handler);

	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_player_data_storage_write_file_on_file_sent");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "filename", data->Filename);
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

std::vector<unsigned char> readBinaryFile_(const char *filename)
{
	// open the file:
	std::streampos fileSize;
	std::ifstream file(filename, std::ios::binary);

	// get its size:
	file.seekg(0, std::ios::end);
	fileSize = file.tellg();
	file.seekg(0, std::ios::beg);

	// read the data:
	std::vector</*BYTE*/ unsigned char> fileData(fileSize);
	file.read((char *)&fileData[0], fileSize);
	return fileData;
}

YYEXPORT void eos_player_data_storage_write_file(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(3);

	const char *user = YYGetString(arg, 0);
	const char *file = YYGetString(arg, 1);
	const char *path = YYGetString(arg, 2);

	EOS_PlayerDataStorage_WriteFileOptions Options;
	Options.ApiVersion = EOS_PLAYERDATASTORAGE_WRITEFILEOPTIONS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(user);
	Options.Filename = file;
	Options.ChunkLengthBytes = MaxChunkSize;
	Options.WriteFileDataCallback = OnFileDataSend;
	Options.FileTransferProgressCallback = OnFileTransferProgressUpdated_write;

	callback *mcallback = getCallbackData();

	EOS_HPlayerDataStorageFileTransferRequest Handle = EOS_PlayerDataStorage_WriteFile(HPlayerDataStorage, &Options, mcallback, OnFileSent);

	if (!Handle)
	{
		return;
	}

	FTransferInProgress__old NewTransfer;
	NewTransfer.bDownload = false;

	// std::string NarrowFileData = "YoyoGames X Opera X EpicGames";
	std::vector<unsigned char> v = readBinaryFile_(path);

	NewTransfer.TotalSize = v.size();  // NarrowFileData.size();
	NewTransfer.Data.resize(v.size()); //(NarrowFileData.size());
	NewTransfer.Handler = Handle;

	if (NewTransfer.TotalSize > 0)
	{
		// memcpy(static_cast<void*>(&NewTransfer.Data[0]), static_cast<const void*>(&NarrowFileData[0]), NarrowFileData.size());
		std::copy(v.begin(), v.end(), &NewTransfer.Data[0]);
	}
	NewTransfer.CurrentIndex = 0;

	TransfersInProgress_[/*stringToWstring*/ (file)] = NewTransfer;

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

YYEXPORT void eos_player_data_storage_file_transfer_request_cancel_request(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_bool;

	eos_ensure_argc(1);

	const char *file = YYGetString(arg, 0);
	auto Iter = TransfersInProgress_.find(/*stringToWstring*/ (file));
	FTransferInProgress__old &Transfer = Iter->second;
	EOS_PlayerDataStorageFileTransferRequest_CancelRequest(Transfer.Handler);
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
