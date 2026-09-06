// Functions


/**
 * @function eos_playerdatastorage_query_file
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorage_QueryFile](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-player-data-storage-query-file)
 *
 * Requests the metadata for a specific file in the requesting user's player data storage, updating the local metadata cache with the results. This does not download the file's contents - call ${function.eos_playerdatastorage_read_file} for that once you know the file exists via ${function.eos_playerdatastorage_copy_file_metadata_by_filename}.
 *
 * @param {String} local_user_id The Product User ID of the user who owns the file to query.
 * @param {String} filename The name of the file to query.
 * @param {Function} [callback] A function to call once the request completes. See the `callback` event below.
 *
 * @event callback
 * @desc Called once, when the query completes.
 * @member {Struct.EpicPlayerDataStorageQueryFileCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_playerdatastorage_query_file(local_user_id, "save1.dat", function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         var _meta = eos_playerdatastorage_copy_file_metadata_by_filename(local_user_id, "save1.dat");
 *         show_debug_message($"save1.dat is {_meta.file_size_bytes} bytes");
 *     }
 * });
 * ```
 * The above code queries a single file's metadata, then reads it back out of the local cache once the query succeeds.
 * @function_end
 */

/**
 * @function eos_playerdatastorage_query_file_list
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorage_QueryFileList](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-player-data-storage-query-file-list)
 *
 * Requests the metadata for every file the local user has stored in player data storage, updating the local metadata cache. Use ${function.eos_playerdatastorage_get_file_metadata_count} and ${function.eos_playerdatastorage_copy_file_metadata_at_index} to read the results once the callback fires.
 *
 * @param {String} local_user_id The Product User ID of the user whose file list to query.
 * @param {Function} [callback] A function to call once the request completes. See the `callback` event below.
 *
 * @event callback
 * @desc Called once, when the query completes.
 * @member {Struct.EpicPlayerDataStorageQueryFileListCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_playerdatastorage_get_file_metadata_count
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorage_GetFileMetadataCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-player-data-storage-get-file-metadata-count)
 *
 * Gets the number of files with cached metadata for the given user, following the most recent ${function.eos_playerdatastorage_query_file}/${function.eos_playerdatastorage_query_file_list} call. Returns `0` if the user is invalid or nothing has been queried yet.
 *
 * @param {String} local_user_id The Product User ID of the user whose cached file count to check.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_playerdatastorage_copy_file_metadata_at_index
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorage_CopyFileMetadataAtIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-player-data-storage-copy-file-metadata-at-index)
 *
 * Fetches a locally cached metadata struct for a file, by index. `index` must be less than the value returned by ${function.eos_playerdatastorage_get_file_metadata_count}.
 *
 * [[Note: This reads from the local cache populated by the last query call - it does not talk to the backend.]]
 *
 * @param {String} local_user_id The Product User ID of the user who owns the cached file list.
 * @param {Real} index Index into the cached file list, from `0` to ${function.eos_playerdatastorage_get_file_metadata_count} - 1.
 *
 * @returns {Struct.EpicPlayerDataStorageFileMetadata}
 *
 * [[Note: Returns `undefined` if `index` is out of range or the underlying SDK call fails - check ${function.eos_api_last_error} for details.]]
 *
 * @function_end
 */

/**
 * @function eos_playerdatastorage_copy_file_metadata_by_filename
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorage_CopyFileMetadataByFilename](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-player-data-storage-copy-file-metadata-by-filename)
 *
 * Fetches a locally cached metadata struct for a file, by filename.
 *
 * [[Note: This reads from the local cache populated by the last query call - it does not talk to the backend.]]
 *
 * @param {String} local_user_id The Product User ID of the user who owns the cached file.
 * @param {String} filename The name of the file to look up.
 *
 * @returns {Struct.EpicPlayerDataStorageFileMetadata}
 *
 * [[Note: Returns `undefined` if this filename has no cached metadata (nothing has been queried for it yet) - check ${function.eos_api_last_error} for details.]]
 *
 * @function_end
 */

/**
 * @function eos_playerdatastorage_duplicate_file
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorage_DuplicateFile](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-player-data-storage-duplicate-file)
 *
 * Copies an existing file already stored in player data storage to a new file, without needing to download and re-upload its contents yourself.
 *
 * @param {String} local_user_id The Product User ID of the user who owns both files.
 * @param {String} source_filename The name of the existing file to copy from.
 * @param {String} destination_filename The name of the new file to create.
 * @param {Function} [callback] A function to call once the request completes. See the `callback` event below.
 *
 * @event callback
 * @desc Called once, when the duplicate operation completes.
 * @member {Struct.EpicPlayerDataStorageDuplicateFileCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_playerdatastorage_delete_file
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorage_DeleteFile](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-player-data-storage-delete-file)
 *
 * Deletes an existing file from the requesting user's player data storage.
 *
 * @param {String} local_user_id The Product User ID of the user who owns the file.
 * @param {String} filename The name of the file to delete.
 * @param {Function} [callback] A function to call once the request completes. See the `callback` event below.
 *
 * @event callback
 * @desc Called once, when the delete operation completes.
 * @member {Struct.EpicPlayerDataStorageDeleteFileCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_playerdatastorage_read_file
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorage_ReadFile](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-player-data-storage-read-file)
 *
 * Downloads a file from player data storage straight to a local path on disk, streaming it in chunks rather than buffering the whole thing in memory.
 *
 * [[Note: `output_path` is a real filesystem path, not a GML buffer - the extension writes the downloaded bytes to disk itself. Load the file back into your game with GML's own file functions once the `callback` fires with `EpicResult.Success`.]]
 *
 * [[Warning: If the transfer fails or is cancelled part-way through, the extension removes the partially-written file at `output_path` rather than leaving a corrupt fragment behind - it will never silently replace a previously-good file at that path with a broken one.]]
 *
 * @param {String} local_user_id The Product User ID of the user who owns the file.
 * @param {String} filename The name of the file to read.
 * @param {String} output_path Local filesystem path the downloaded file is written to.
 * @param {Function} [callback] A function to call once the download completes (success or failure). See the `callback` event below.
 * @param {Function} [progress_callback] A function to call repeatedly while the download is in progress. See the `callback_progress` event below.
 *
 * @event callback
 * @desc Called once, when the download finishes or fails.
 * @member {Struct.EpicPlayerDataStorageReadFileCallbackInfo} result
 * @event_end
 *
 * @event callback_progress
 * @desc Called zero or more times while the download is in progress, before the `callback` event fires.
 * @member {Struct.EpicPlayerDataStorageReadFileProgressCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_playerdatastorage_read_file(local_user_id, "save1.dat", working_directory + "save1.dat",
 * function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         show_debug_message("save1.dat downloaded");
 *     }
 * },
 * function(_progress)
 * {
 *     show_debug_message($"{_progress.bytes_transferred} / {_progress.total_file_size_bytes} bytes");
 * });
 * ```
 * The above code downloads `save1.dat` to the game's working directory, printing progress as it comes in.
 * @function_end
 */

/**
 * @function eos_playerdatastorage_write_file
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorage_WriteFile](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-player-data-storage-write-file)
 *
 * Uploads a local file on disk to player data storage, streaming it in chunks.
 *
 * [[Note: `input_path` is a real filesystem path, not a GML buffer - the extension reads the file itself before uploading. An empty or unreadable `input_path` fails immediately (${function.eos_api_last_error} is set) without starting a transfer or firing `callback`.]]
 *
 * @param {String} local_user_id The Product User ID of the user who will own the file.
 * @param {String} filename The name to give the file in player data storage.
 * @param {String} input_path Local filesystem path of the file to upload.
 * @param {Function} [callback] A function to call once the upload completes (success or failure). See the `callback` event below.
 * @param {Function} [progress_callback] A function to call repeatedly while the upload is in progress. See the `callback_progress` event below.
 *
 * @event callback
 * @desc Called once, when the upload finishes or fails.
 * @member {Struct.EpicPlayerDataStorageWriteFileCallbackInfo} result
 * @event_end
 *
 * @event callback_progress
 * @desc Called zero or more times while the upload is in progress, before the `callback` event fires.
 * @member {Struct.EpicPlayerDataStorageWriteFileProgressCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_playerdatastorage_file_transfer_request_cancel_request
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorageFileTransferRequest_CancelRequest](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-player-data-storage-file-transfer-request-cancel-request)
 *
 * Cancels an in-progress ${function.eos_playerdatastorage_read_file} or ${function.eos_playerdatastorage_write_file} transfer for the given filename. The transfer's `callback` will still fire, reporting a non-success result code.
 *
 * @param {String} filename The filename of the transfer to cancel, as passed to ${function.eos_playerdatastorage_read_file}/${function.eos_playerdatastorage_write_file}.
 *
 * [[Note: Fails silently (sets ${function.eos_api_last_error}) if there is no active transfer for this filename.]]
 *
 * @function_end
 */

/**
 * @function eos_playerdatastorage_delete_cache
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorage_DeleteCache](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-player-data-storage-delete-cache)
 *
 * Removes previously cached data for a given user from the local filesystem cache used internally by the SDK. This does not touch the copies stored on Epic's backend.
 *
 * @param {String} local_user_id The Product User ID of the user whose local cache to clear.
 * @param {Function} [callback] A function to call once the request completes. See the `callback` event below.
 *
 * @event callback
 * @desc Called once, when the cache-clear operation completes.
 * @member {Struct.EpicPlayerDataStorageDeleteCacheCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

// Structs

/**
 * @struct EpicPlayerDataStorageFileMetadata
 * @desc Cached metadata for a single file in player data storage, as last reported by ${function.eos_playerdatastorage_query_file}/${function.eos_playerdatastorage_query_file_list}.
 *
 * @member {Real} file_size_bytes Size, in bytes, of the file as stored (possibly encrypted) in the cloud.
 * @member {String} md5_hash MD5 hash of the file's contents.
 * @member {String} filename Name of the file.
 * @member {Real} last_modified_time Unix timestamp of the file's last modification.
 * @member {Real} unencrypted_data_size_bytes Size, in bytes, of the file's contents once decrypted.
 *
 * @struct_end
 */

/**
 * @struct EpicPlayerDataStorageQueryFileCallbackInfo
 * @desc Result of a call to ${function.eos_playerdatastorage_query_file}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the query succeeded; an error code otherwise.
 * @member {String} local_user_id The Product User ID of the user who made the request.
 *
 * @struct_end
 */

/**
 * @struct EpicPlayerDataStorageQueryFileListCallbackInfo
 * @desc Result of a call to ${function.eos_playerdatastorage_query_file_list}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the query succeeded; an error code otherwise.
 * @member {String} local_user_id The Product User ID of the user who made the request.
 * @member {Real} file_count Number of files found, matching what ${function.eos_playerdatastorage_get_file_metadata_count} will return.
 *
 * @struct_end
 */

/**
 * @struct EpicPlayerDataStorageDuplicateFileCallbackInfo
 * @desc Result of a call to ${function.eos_playerdatastorage_duplicate_file}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the duplicate succeeded; an error code otherwise.
 * @member {String} local_user_id The Product User ID of the user who made the request.
 *
 * @struct_end
 */

/**
 * @struct EpicPlayerDataStorageDeleteFileCallbackInfo
 * @desc Result of a call to ${function.eos_playerdatastorage_delete_file}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the delete succeeded; an error code otherwise.
 * @member {String} local_user_id The Product User ID of the user who made the request.
 *
 * @struct_end
 */

/**
 * @struct EpicPlayerDataStorageReadFileCallbackInfo
 * @desc Result of a call to ${function.eos_playerdatastorage_read_file}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the file downloaded and was written to disk successfully; an error code otherwise (including if the local write failed or the transfer was cancelled).
 * @member {String} local_user_id The Product User ID of the user who made the request.
 * @member {String} filename The name of the file that was being downloaded.
 *
 * @struct_end
 */

/**
 * @struct EpicPlayerDataStorageWriteFileCallbackInfo
 * @desc Result of a call to ${function.eos_playerdatastorage_write_file}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the file uploaded successfully; an error code otherwise.
 * @member {String} local_user_id The Product User ID of the user who made the request.
 * @member {String} filename The name of the file that was being uploaded.
 *
 * @struct_end
 */

/**
 * @struct EpicPlayerDataStorageReadFileProgressCallbackInfo
 * @desc Progress update for an in-flight ${function.eos_playerdatastorage_read_file} download.
 *
 * @member {String} local_user_id The Product User ID of the user who made the request.
 * @member {String} filename The name of the file being downloaded.
 * @member {Real} bytes_transferred Number of bytes downloaded so far.
 * @member {Real} total_file_size_bytes Total size of the file being downloaded, in bytes.
 *
 * @struct_end
 */

/**
 * @struct EpicPlayerDataStorageWriteFileProgressCallbackInfo
 * @desc Progress update for an in-flight ${function.eos_playerdatastorage_write_file} upload.
 *
 * @member {String} local_user_id The Product User ID of the user who made the request.
 * @member {String} filename The name of the file being uploaded.
 * @member {Real} bytes_transferred Number of bytes uploaded so far.
 * @member {Real} total_file_size_bytes Total size of the file being uploaded, in bytes.
 *
 * @struct_end
 */

/**
 * @struct EpicPlayerDataStorageDeleteCacheCallbackInfo
 * @desc Result of a call to ${function.eos_playerdatastorage_delete_cache}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the cache was cleared successfully; an error code otherwise.
 * @member {String} local_user_id The Product User ID of the user whose cache was cleared.
 *
 * @struct_end
 */

// Constants

/**
 * @const EpicPlayerDataStorageReadResult
 * @desc **Epic Online Services Enum:** [EOS_PlayerDataStorage_EReadResult](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-player-data-storage-e-read-result) - describes how a single chunk of a file read completed, at the SDK level.
 *
 * [[Note: This extension handles read-chunk streaming to disk internally (see ${function.eos_playerdatastorage_read_file}) - this constant isn't currently surfaced through any GML function or callback parameter, it's documented here for completeness against the generated API surface.]]
 *
 * @member ContinueReading The read operation should continue.
 * @member FailRequest The read operation should terminate in failure.
 * @member CancelRequest The read operation should terminate as cancelled.
 *
 * @const_end
 */

/**
 * @const EpicPlayerDataStorageWriteResult
 * @desc **Epic Online Services Enum:** [EOS_PlayerDataStorage_EWriteResult](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-player-data-storage-e-write-result) - describes how a single chunk of a file write completed, at the SDK level.
 *
 * [[Note: This extension handles write-chunk streaming from disk internally (see ${function.eos_playerdatastorage_write_file}) - this constant isn't currently surfaced through any GML function or callback parameter, it's documented here for completeness against the generated API surface.]]
 *
 * @member ContinueWriting The write operation should continue.
 * @member CompleteRequest The write operation should terminate, complete.
 * @member FailRequest The write operation should terminate in failure.
 * @member CancelRequest The write operation should terminate as cancelled.
 *
 * @const_end
 */


/**
 * @module player_data_storage
 * @title Player Data Storage
 * @desc **Epic Online Services Interface:** [Player Data Storage Interface](https://dev.epicgames.com/docs/game-services/eos-player-data-storage-interface)
 *
 * The Player Data Storage Interface lets you store and retrieve per-player binary files in the cloud, so a player's save data and settings follow them between devices. Files are read from and written to a local path on disk - the extension streams the transfer itself, so you never handle the raw bytes directly in GML.
 *
 * [[Note: Reading/writing files requires an **Encryption Key** to be configured in the extension's Extension Options. See ${page.extension_options}.]]
 *
 * @section_func
 * @desc Provided functions:
 *
 * @ref eos_playerdatastorage_query_file
 * @ref eos_playerdatastorage_query_file_list
 * @ref eos_playerdatastorage_get_file_metadata_count
 * @ref eos_playerdatastorage_copy_file_metadata_at_index
 * @ref eos_playerdatastorage_copy_file_metadata_by_filename
 * @ref eos_playerdatastorage_duplicate_file
 * @ref eos_playerdatastorage_delete_file
 * @ref eos_playerdatastorage_read_file
 * @ref eos_playerdatastorage_write_file
 * @ref eos_playerdatastorage_file_transfer_request_cancel_request
 * @ref eos_playerdatastorage_delete_cache
 *
 * @section_end
 *
 * @section_struct
 * @desc These are the structs used by this API:
 *
 * @ref EpicPlayerDataStorageFileMetadata
 * @ref EpicPlayerDataStorageQueryFileCallbackInfo
 * @ref EpicPlayerDataStorageQueryFileListCallbackInfo
 * @ref EpicPlayerDataStorageDuplicateFileCallbackInfo
 * @ref EpicPlayerDataStorageDeleteFileCallbackInfo
 * @ref EpicPlayerDataStorageReadFileCallbackInfo
 * @ref EpicPlayerDataStorageWriteFileCallbackInfo
 * @ref EpicPlayerDataStorageReadFileProgressCallbackInfo
 * @ref EpicPlayerDataStorageWriteFileProgressCallbackInfo
 * @ref EpicPlayerDataStorageDeleteCacheCallbackInfo
 *
 * @section_end
 *
 * @section_const
 * @desc These are the constants used by this API:
 *
 * @ref EpicPlayerDataStorageReadResult
 * @ref EpicPlayerDataStorageWriteResult
 *
 * @section_end
 *
 * @module_end
 */
