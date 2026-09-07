// Functions


/**
 * @function eos_titlestorage_query_file
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_QueryFile](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-title-storage-query-file)
 *
 * Requests the metadata for a specific file in title storage, updating the local metadata cache with the results. This does not download the file's contents - call ${function.eos_titlestorage_read_file} for that.
 *
 * @param {String} local_user_id The Product User ID of the user making the request. May be `""` - see the `local_user_id` note on ${module.title_storage}.
 * @param {String} filename The name of the file to query.
 * @param {Function} [callback] A function to call once the request completes. See the `callback` event below.
 *
 * @event callback
 * @desc Called once, when the query completes.
 * @member {Struct.EpicTitleStorageQueryFileCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_titlestorage_query_file_list
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_QueryFileList](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-title-storage-query-file-list)
 *
 * Requests the metadata for every file in title storage tagged with any of the given tags, updating the local metadata cache. Use ${function.eos_titlestorage_get_file_metadata_count} and ${function.eos_titlestorage_copy_file_metadata_at_index} to read the results once the callback fires.
 *
 * @param {String} local_user_id The Product User ID of the user making the request. May be `""` - see the `local_user_id` note on ${module.title_storage}.
 * @param {Array[String]} tags Tags previously assigned to files in the Dev Portal, used to filter which files are returned. Pass an empty array to match every file.
 * @param {Function} [callback] A function to call once the request completes. See the `callback` event below.
 *
 * @event callback
 * @desc Called once, when the query completes.
 * @member {Struct.EpicTitleStorageQueryFileListCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_titlestorage_query_file_list(local_user_id, ["patch-notes"], function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         show_debug_message($"{_result.file_count} title storage file(s) found");
 *     }
 * });
 * ```
 * The above code queries every title storage file tagged `"patch-notes"`.
 * @function_end
 */

/**
 * @function eos_titlestorage_get_file_metadata_count
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_GetFileMetadataCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-title-storage-get-file-metadata-count)
 *
 * Gets the number of files with cached metadata, following the most recent ${function.eos_titlestorage_query_file}/${function.eos_titlestorage_query_file_list} call. Returns `0` if nothing has been queried yet.
 *
 * @param {String} local_user_id The Product User ID of the user making the request. May be `""` - see the `local_user_id` note on ${module.title_storage}.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_titlestorage_copy_file_metadata_at_index
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_CopyFileMetadataAtIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-title-storage-copy-file-metadata-at-index)
 *
 * Fetches a locally cached metadata struct for a file, by index. `index` must be less than the value returned by ${function.eos_titlestorage_get_file_metadata_count}.
 *
 * [[Note: This reads from the local cache populated by the last query call - it does not talk to the backend.]]
 *
 * @param {String} local_user_id The Product User ID of the user making the request. May be `""` - see the `local_user_id` note on ${module.title_storage}.
 * @param {Real} index Index into the cached file list, from `0` to ${function.eos_titlestorage_get_file_metadata_count} - 1.
 *
 * @returns {Struct.EpicTitleStorageFileMetadata}
 *
 * [[Note: Returns `undefined` if `index` is out of range or the underlying SDK call fails - check ${function.eos_api_last_error} for details.]]
 *
 * @function_end
 */

/**
 * @function eos_titlestorage_copy_file_metadata_by_filename
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_CopyFileMetadataByFilename](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-title-storage-copy-file-metadata-by-filename)
 *
 * Fetches a locally cached metadata struct for a file, by filename.
 *
 * [[Note: This reads from the local cache populated by the last query call - it does not talk to the backend.]]
 *
 * @param {String} local_user_id The Product User ID of the user making the request. May be `""` - see the `local_user_id` note on ${module.title_storage}.
 * @param {String} filename The name of the file to look up.
 *
 * @returns {Struct.EpicTitleStorageFileMetadata}
 *
 * [[Note: Returns `undefined` if this filename has no cached metadata (nothing has been queried for it yet) - check ${function.eos_api_last_error} for details.]]
 *
 * @function_end
 */

/**
 * @function eos_titlestorage_read_file
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_ReadFile](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-title-storage-read-file)
 *
 * Downloads a file from title storage straight to a local path on disk, streaming it in chunks rather than buffering the whole thing in memory.
 *
 * [[Note: `output_path` is a real filesystem path, not a GML buffer - the extension writes the downloaded bytes to disk itself. Load the file back into your game with GML's own file functions once the `callback` fires with `EpicResult.Success`.]]
 *
 * [[Warning: If the transfer fails or is cancelled part-way through, the extension removes the partially-written file at `output_path` rather than leaving a corrupt fragment behind - it will never silently replace a previously-good file at that path with a broken one.]]
 *
 * @param {String} local_user_id The Product User ID of the user making the request. May be `""` - see the `local_user_id` note on ${module.title_storage}.
 * @param {String} filename The name of the file to read.
 * @param {String} output_path Local filesystem path the downloaded file is written to.
 * @param {Function} [callback] A function to call once the download completes (success or failure). See the `callback` event below.
 * @param {Function} [progress_callback] A function to call repeatedly while the download is in progress. See the `Callback - progress` event below.
 *
 * @event callback
 * @desc Called once, when the download finishes or fails.
 * @member {Struct.EpicTitleStorageReadFileCallbackInfo} result
 * @event_end
 *
 * @event callback:progress
 * @desc Called zero or more times while the download is in progress, before the `callback` event fires.
 * @member {Struct.EpicTitleStorageReadFileProgressCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_titlestorage_file_transfer_request_cancel_request
 * @desc **Epic Online Services Function:** [EOS_TitleStorageFileTransferRequest_CancelRequest](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-title-storage-file-transfer-request-cancel-request)
 *
 * Cancels an in-progress ${function.eos_titlestorage_read_file} transfer for the given filename. The transfer's `callback` will still fire, reporting a non-success result code.
 *
 * @param {String} filename The filename of the transfer to cancel, as passed to ${function.eos_titlestorage_read_file}.
 *
 * [[Note: Fails silently (sets ${function.eos_api_last_error}) if there is no active transfer for this filename.]]
 *
 * @function_end
 */

/**
 * @function eos_titlestorage_delete_cache
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_DeleteCache](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-title-storage-delete-cache)
 *
 * Removes previously cached data for a given user from the local filesystem cache used internally by the SDK. This does not touch the copies stored on Epic's backend.
 *
 * @param {String} local_user_id The Product User ID of the user making the request. May be `""` - see the `local_user_id` note on ${module.title_storage}.
 * @param {Function} [callback] A function to call once the request completes. See the `callback` event below.
 *
 * @event callback
 * @desc Called once, when the cache-clear operation completes.
 * @member {Struct.EpicTitleStorageDeleteCacheCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

// Structs

/**
 * @struct EpicTitleStorageFileMetadata
 * @desc Cached metadata for a single file in title storage, as last reported by ${function.eos_titlestorage_query_file}/${function.eos_titlestorage_query_file_list}.
 *
 * @member {Real} file_size_bytes Size, in bytes, of the file as stored (possibly encrypted) in the cloud.
 * @member {String} md5_hash MD5 hash of the file's contents.
 * @member {String} filename Name of the file.
 * @member {Real} unencrypted_data_size_bytes Size, in bytes, of the file's contents once decrypted.
 *
 * @struct_end
 */

/**
 * @struct EpicTitleStorageQueryFileCallbackInfo
 * @desc Result of a call to ${function.eos_titlestorage_query_file}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the query succeeded; an error code otherwise.
 * @member {String} local_user_id The Product User ID that made the request.
 *
 * @struct_end
 */

/**
 * @struct EpicTitleStorageQueryFileListCallbackInfo
 * @desc Result of a call to ${function.eos_titlestorage_query_file_list}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the query succeeded; an error code otherwise.
 * @member {String} local_user_id The Product User ID that made the request.
 * @member {Real} file_count Number of files found, matching what ${function.eos_titlestorage_get_file_metadata_count} will return.
 *
 * @struct_end
 */

/**
 * @struct EpicTitleStorageReadFileCallbackInfo
 * @desc Result of a call to ${function.eos_titlestorage_read_file}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the file downloaded and was written to disk successfully; an error code otherwise (including if the local write failed or the transfer was cancelled).
 * @member {String} local_user_id The Product User ID that made the request.
 * @member {String} filename The name of the file that was being downloaded.
 *
 * @struct_end
 */

/**
 * @struct EpicTitleStorageReadFileProgressCallbackInfo
 * @desc Progress update for an in-flight ${function.eos_titlestorage_read_file} download.
 *
 * @member {String} local_user_id The Product User ID that made the request.
 * @member {String} filename The name of the file being downloaded.
 * @member {Real} bytes_transferred Number of bytes downloaded so far.
 * @member {Real} total_file_size_bytes Total size of the file being downloaded, in bytes.
 *
 * @struct_end
 */

/**
 * @struct EpicTitleStorageDeleteCacheCallbackInfo
 * @desc Result of a call to ${function.eos_titlestorage_delete_cache}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the cache was cleared successfully; an error code otherwise.
 * @member {String} local_user_id The Product User ID whose cache was cleared.
 *
 * @struct_end
 */

// Constants

/**
 * @const EpicTitleStorageReadResult
 * @desc **Epic Online Services Enum:** [EOS_TitleStorage_EReadResult](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-title-storage-e-read-result) - describes how a single chunk of a file read completed, at the SDK level.
 *
 * [[Note: This extension handles read-chunk streaming to disk internally (see ${function.eos_titlestorage_read_file}) - this constant isn't currently surfaced through any GML function or callback parameter, it's documented here for completeness against the generated API surface.]]
 *
 * @member ContinueReading The read operation should continue.
 * @member FailRequest The read operation should terminate in failure.
 * @member CancelRequest The read operation should terminate as cancelled.
 *
 * @const_end
 */


/**
 * @module title_storage
 * @title Title Storage
 * @desc **Epic Online Services Interface:** [Title Storage Interface](https://dev.epicgames.com/docs/game-services/eos-title-storage-interface)
 *
 * The Title Storage Interface lets you download developer-managed files (patch notes, remote config, DLC manifests, and similar title-wide content) that you upload through the Dev Portal. Unlike ${module.player_data_storage}, this storage is read-only from the game's side and isn't tied to a specific player. Files are downloaded straight to a local path on disk - the extension streams the transfer itself, so you never handle the raw bytes directly in GML.
 *
 * [[Note: `local_user_id` may be passed as an empty string `""` on every function in this module - Title Storage content isn't per-player. Supplying a real Product User ID lets the SDK apply any per-user entitlement checks configured for tagged premium content; leave it empty otherwise.]]
 *
 * [[Note: Reading files requires an **Encryption Key** to be configured in the extension's Extension Options. See ${page.extension_options}.]]
 *
 * @section_func
 * @desc Provided functions:
 *
 * @ref eos_titlestorage_query_file
 * @ref eos_titlestorage_query_file_list
 * @ref eos_titlestorage_get_file_metadata_count
 * @ref eos_titlestorage_copy_file_metadata_at_index
 * @ref eos_titlestorage_copy_file_metadata_by_filename
 * @ref eos_titlestorage_read_file
 * @ref eos_titlestorage_file_transfer_request_cancel_request
 * @ref eos_titlestorage_delete_cache
 *
 * @section_end
 *
 * @section_struct
 * @desc These are the structs used by this API:
 *
 * @ref EpicTitleStorageFileMetadata
 * @ref EpicTitleStorageQueryFileCallbackInfo
 * @ref EpicTitleStorageQueryFileListCallbackInfo
 * @ref EpicTitleStorageReadFileCallbackInfo
 * @ref EpicTitleStorageReadFileProgressCallbackInfo
 * @ref EpicTitleStorageDeleteCacheCallbackInfo
 *
 * @section_end
 *
 * @section_const
 * @desc These are the constants used by this API:
 *
 * @ref EpicTitleStorageReadResult
 *
 * @section_end
 *
 * @module_end
 */
