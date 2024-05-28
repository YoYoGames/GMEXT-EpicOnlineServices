// Functions


/**
 * @function EpicGames_PlayerDataStorage_CopyFileMetadataAtIndex
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorage_CopyFileMetadataAtIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/PlayerDataStorage/EOS_PlayerDataStorage_CopyFileMetadataAtIndex/index.html)
 * 
 * This function gets the cached copy of a file's metadata by index. The metadata will be for the last retrieved or successfully saved version, and will not include any local changes that have not been committed by calling ${function.EpicGames_PlayerDataStorage_WriteFile}.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_PlayerDataStorage_QueryFileList} to store values in cache.]]
 * 
 * @param {string} userID The Product User ID of the local user who is requesting file metadata
 * @param {real} index The index to get metadata for
 * 
 * @returns {struct.PlayerFileMetadata}
 * 
 * @example
 * ```gml
 * var _count = EpicGames_PlayerDataStorage_GetFileMetadataCount(userID);
 * for(var i = 0 ; i < _count; i++)
 * {
 *     var _struct = EpicGames_PlayerDataStorage_CopyFileMetadataAtIndex(userID, i);
 *     Filename = _struct.Filename;
 * }
 * ```
 * The above code shows an example of how the function should be used. The player file metadata is returned providing an index.
 * @function_end
 */

/**
 * @function EpicGames_PlayerDataStorage_CopyFileMetadataByFilename
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorage_CopyFileMetadataByFilename](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/PlayerDataStorage/EOS_PlayerDataStorage_CopyFileMetadataByFilename/index.html)
 * 
 * This function creates the cached copy of a file's metadata by filename. The metadata will be for the last retrieved or successfully saved version, and will not include any changes that have not completed writing.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_PlayerDataStorage_QueryFileList} to store values in cache.]]
 * 
 * @param {string} userID The Product User ID of the local user who is requesting file metadata
 * @param {string} filename The file's name to get metadata for
 * 
 * @returns {struct.PlayerFileMetadata}
 * 
 * @example
 * ```gml
 * var _struct = EpicGames_PlayerDataStorage_CopyFileMetadataByFilename(userID, filename);
 * if(_struct.status == EpicGames_Success)
 * {
 *     var _filename = _struct.Filename;
 * }
 * ```
 * The above code shows an example of how the function should be used. The player file metadata is returned for a provided filename.
 * @function_end
 */

/**
 * @function EpicGames_PlayerDataStorage_DeleteCache
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorage_DeleteCache](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/PlayerDataStorage/EOS_PlayerDataStorage_DeleteCache/index.html)
 * 
 * This function clears previously cached file data. This operation will be done asynchronously. All cached files except those corresponding to the transfers in progress will be removed.
 * 
 * [[Warning: Use this with care. The cache system generally tries to clear old and unused cached files from time to time. Unnecessarily clearing the cache can degrade performance as the SDK will have to re-download data.]]
 * 
 * @param {string} userID Product User ID of the local user who is deleting his cache
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type `"EpicGames_PlayerDataStorage_DeleteCache"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_PlayerDataStorage_DeleteCache(userID);
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_PlayerDataStorage_DeleteCache")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EpicGames_Success)
 *     {
 *         show_debug_message(async_load[? "type"] + " succeeded!");
 *     }
 *     else
 *     {
 *          show_debug_message(async_load[? "type"] + " failed: " + async_load[? "status_message"]);
 *     }
 * }
 * ```
 * The code above matches the response against the correct event **type** and logs the success of the task.
 * @function_end
 */

/**
 * @function EpicGames_PlayerDataStorage_DeleteFile
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorage_DeleteFile](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/PlayerDataStorage/EOS_PlayerDataStorage_DeleteFile/index.html)
 * 
 * This function deletes an existing file in the cloud. If successful, the file's data will be removed from our local cache.
 * 
 * @param {string} userID The Product User ID of the local user who authorizes deletion of the file; must be the file's owner
 * @param {string} filename The name of the file to delete
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type `"EpicGames_PlayerDataStorage_DeleteFile"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_PlayerDataStorage_DeleteFile(userID, "MyFilename.txt");
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_PlayerDataStorage_DeleteFile")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EpicGames_Success)
 *     {
 *         show_debug_message(async_load[? "type"] + " succeeded!");
 *     }
 *     else
 *     {
 *          show_debug_message(async_load[? "type"] + " failed: " + async_load[? "status_message"]);
 *     }
 * }
 * ```
 * The code above matches the response against the correct event **type** and logs the success of the task.
 * @function_end
 */

/**
 * @function EpicGames_PlayerDataStorage_DuplicateFile
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorage_DuplicateFile](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/PlayerDataStorage/EOS_PlayerDataStorage_DuplicateFile/index.html)
 * 
 * This function copies the data of an existing file to a new filename. This action happens entirely on the server and will not upload the contents of the source destination file from the host. This function paired with a subsequent ${function.EpicGames_PlayerDataStorage_DeleteFile} can be used to rename a file. If successful, the destination file's metadata will be updated in our local cache.
 * 
 * @param {string} userID The Product User ID of the local user who authorized the duplication of the requested file; must be the original file's owner
 * @param {string} source The name of the existing file to duplicate
 * @param {string} destination The name of the new file
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type `"EpicGames_PlayerDataStorage_DuplicateFile"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_PlayerDataStorage_DuplicateFile(userID,"myNiceFile.dat", "myNiceFile2.dat");
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_PlayerDataStorage_DuplicateFile")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EpicGames_Success)
 *     {
 *         show_debug_message(async_load[? "type"] + " succeeded!");
 *     }
 *     else
 *     {
 *          show_debug_message(async_load[? "type"] + " failed: " + async_load[? "status_message"]);
 *     }
 * }
 * ```
 * The code above matches the response against the correct event **type** and logs the success of the task.
 * @function_end
 */

/**
 * @function EpicGames_PlayerDataStorage_GetFileMetadataCount
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorage_GetFileMetadataCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/PlayerDataStorage/EOS_PlayerDataStorage_GetFileMetadataCount/index.html)
 * 
 * This function gets the count of files we have previously queried information for and files we have previously read from / written to.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_PlayerDataStorage_QueryFileList} to store values in cache.]]
 * 
 * @param {string} userID The Product User ID of the local user who is requesting file metadata
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _count = EpicGames_PlayerDataStorage_GetFileMetadataCount(userID);
 * for (var i = 0 ; i < _count; i ++)
 * {
 *     var _struct = EpicGames_PlayerDataStorage_CopyFileMetadataAtIndex(userID, i);
 *     Filename = _struct.Filename;
 * }
 * ```
 * The above code shows an example of how the function should be used. After a successful call to ${function.EpicGames_PlayerDataStorage_QueryFileList}, the function ${function.EpicGames_PlayerDataStorage_GetFileMetadataCount} will return the number of entries in the query array which can then be accessed using the ${function.EpicGames_PlayerDataStorage_CopyFileMetadataAtIndex} function.
 * @function_end
 */

/**
 * @function EpicGames_PlayerDataStorage_QueryFile
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorage_QueryFile](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/PlayerDataStorage/EOS_PlayerDataStorage_QueryFile/index.html)
 * 
 * This function queries a specific file's metadata, such as file names, size, and a MD5 hash of the data. This is not required before a file may be opened, saved, copied, or deleted.
 * 
 * Once a file has been queried, its metadata will be available by the one of the following functions:
 * 
 * * ${function.EpicGames_PlayerDataStorage_CopyFileMetadataAtIndex}
 * * ${function.EpicGames_PlayerDataStorage_CopyFileMetadataByFilename}
 * 
 * @param {string} userID The Product User ID of the local user requesting file metadata
 * @param {string} filename The name of the file being queried
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type `"EpicGames_PlayerDataStorage_QueryFile"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_PlayerDataStorage_QueryFile(userID, "myFile.txt");
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_PlayerDataStorage_QueryFile")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EpicGames_Success)
 *     {
 *         show_debug_message(async_load[? "type"] + " succeeded!");
 *     }
 *     else
 *     {
 *         show_debug_message(async_load[? "type"] + " failed: " + async_load[? "status_message"]);
 *     }
 * }
 * ```
 * The code above matches the response against the correct event **type** and logs the success of the task.
 * @function_end
 */

/**
 * @function EpicGames_PlayerDataStorage_QueryFileList
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorage_QueryFileList](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/PlayerDataStorage/EOS_PlayerDataStorage_QueryFileList/index.html)
 * 
 * This function queries the file metadata, such as file names, size, and a MD5 hash of the data, for all files owned by this user for this application. This is not required before a file may be opened, saved, copied, or deleted.
 * Once the callback has been fired with a successful ${constant.EpicGames_Result}, it is possible to call one of the following functions:
 * 
 * * ${function.EpicGames_PlayerDataStorage_CopyFileMetadataAtIndex}
 * * ${function.EpicGames_PlayerDataStorage_CopyFileMetadataByFilename}
 * * ${function.EpicGames_PlayerDataStorage_GetFileMetadataCount}
 * 
 * @param {string} userID The Product User ID of the local user who requested file metadata
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type `"EpicGames_PlayerDataStorage_QueryFileList"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_PlayerDataStorage_QueryFileList(userID);
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_PlayerDataStorage_QueryFileList")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EpicGames_Success)
 *     {
 *         show_debug_message(async_load[? "type"] + " succeeded!");
 *     }
 *     else
 *     {
 *         show_debug_message(async_load[? "type"] + " failed: " + async_load[? "status_message"]);
 *     }
 * }
 * ```
 * The code above matches the response against the correct event **type** and logs the success of the task.
 * @function_end
 */

/**
 * @function EpicGames_PlayerDataStorage_ReadFile
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorage_ReadFile](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/PlayerDataStorage/EOS_PlayerDataStorage_ReadFile/index.html)
 * 
 * This function retrieves the contents of a specific file, potentially downloading the contents if we do not have a local copy, from the cloud. This request will occur asynchronously, potentially over multiple frames. All callbacks for this function will come from the same thread that the SDK is ticked from. If specified, the FileTransferProgressCallback will always be called at least once if the request is started successfully.
 * 
 * @param {string} userID The Product User ID of the local user who is reading the requested file
 * @param {string} filename The file name to read; this file must already exist
 * @param {string} path local path where to save the file
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type `"EpicGames_PlayerDataStorage_ReadFile"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_PlayerDataStorage_ReadFile(userID, "MyFavPic.png", "path/to/save/MyFavPic.png");
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_PlayerDataStorage_ReadFile")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EpicGames_Success)
 *     {
 *         show_debug_message(async_load[? "type"] + " succeeded!");
 *     }
 *     else
 *     {
 *          show_debug_message(async_load[? "type"] + " failed: " + async_load[? "status_message"]);
 *     }
 * }
 * ```
 * The code above matches the response against the correct event **type** and logs the success of the task.
 * @function_end
 */

/**
 * @function EpicGames_PlayerDataStorage_WriteFile
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorage_WriteFile](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/PlayerDataStorage/EOS_PlayerDataStorage_WriteFile/index.html)
 * 
 * This function writes new data to a specific file, potentially overwriting any existing file by the same name, to the cloud. This request will occur asynchronously, potentially over multiple frames. All callbacks for this function will come from the same thread that the SDK is ticked from. If specified, the FileTransferProgressCallback will always be called at least once if the request is started successfully.
 * 
 * @param {string} userID The Product User ID of the local user who is writing the requested file to the cloud
 * @param {string} filename The name of the file to write; if this file already exists, the contents will be replaced if the write request completes successfully.
 * @param {string} path Local path of the file to upload
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type `"EpicGames_PlayerDataStorage_WriteFile"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_PlayerDataStorage_WriteFile(userID, "myData.dat", "/path/to/file/myData.dat");
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_PlayerDataStorage_WriteFile")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EpicGames_Success)
 *     {
 *         show_debug_message(async_load[? "type"] + " succeeded!");
 *     }
 *     else
 *     {
 *          show_debug_message(async_load[? "type"] + " failed: " + async_load[? "status_message"]);
 *     }
 * }
 * ```
 * The code above matches the response against the correct event **type** and logs the success of the task.
 * @function_end
 */

/**
 * @function EpicGames_PlayerDataStorageFileTransferRequest_CancelRequest
 * @desc **Epic Online Services Function:** [EOS_PlayerDataStorageFileTransferRequest_CancelRequest](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/PlayerDataStorage/EOS_PlayerDataStorageFileTransferRequest_CancelRequest/index.html)
 * 
 * This function attempts to cancel this file request in progress. This is a best-effort command and is not guaranteed to be successful if the request has completed before this function is called.
 * 
 * @param {string} filename Filename contained in the process to cancel
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type `"EpicGames_PlayerDataStorageFileTransferRequest_CancelRequest"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_PlayerDataStorageFileTransferRequest_CancelRequest("myFile.txt");
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_PlayerDataStorageFileTransferRequest_CancelRequest")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EpicGames_Success)
 *     {
 *         show_debug_message(async_load[? "type"] + " succeeded!");
 *     }
 *     else
 *     {
 *         show_debug_message(async_load[? "type"] + " failed: " + async_load[? "status_message"]);
 *     }
 * }
 * ```
 * The code above matches the response against the correct event **type** and logs the success of the task.
 * @function_end
 */

// Structs

/**
 * @struct PlayerFileMetadata
 * @desc The player file metadata is represented by a struct and contains metadata information for a specific player file.
 *
 * @member {real} FileSizeBytes The total size of the file in bytes (includes the file header in addition to the file contents)
 * @member {string} MD5Hash The MD5 Hash of the entire file (including additional file header), in hex digits
 * @member {string} Filename The file's name
 * @member {real} LastModifiedTime The POSIX timestamp when the file was saved last time.
 * @member {real} UnencryptedDataSizeBytes The size of data (payload) in file in unencrypted (original) form.
 * @struct_end
 */


/**
 * @module player_data_storage
 * @title Player Data Storage
 * @desc **Epic Online Services Interface:** [Player Data Storage Interface](https://dev.epicgames.com/docs/game-services/player-data-storage)
 * 
 * The [Player Data Storage Interface](https://dev.epicgames.com/docs/game-services/player-data-storage) enables developers using **Epic Online Services** (EOS) to save encrypted, user-specific, game-specific data to cloud servers. Data that you store through this interface is accessible to the user on any device where they can log in.
 * 
 * The Player Data Storage Interface supports any file format; typical use cases would include saved games and replay data.
 * 
 * @section_func
 * @desc These functions are provided for handling player data storage:
 * 
 * @ref EpicGames_PlayerDataStorage_CopyFileMetadataAtIndex
 * @ref EpicGames_PlayerDataStorage_CopyFileMetadataByFilename
 * @ref EpicGames_PlayerDataStorage_DeleteCache
 * @ref EpicGames_PlayerDataStorage_DeleteFile
 * @ref EpicGames_PlayerDataStorage_DuplicateFile
 * @ref EpicGames_PlayerDataStorage_GetFileMetadataCount
 * @ref EpicGames_PlayerDataStorage_QueryFile
 * @ref EpicGames_PlayerDataStorage_QueryFileList
 * @ref EpicGames_PlayerDataStorage_ReadFile
 * @ref EpicGames_PlayerDataStorage_WriteFile
 * @ref EpicGames_PlayerDataStorageFileTransferRequest_CancelRequest
 * 
 * @section_end
 * 
 * @section_struct
 * @desc These are the structures used by this API:
 * 
 * @ref PlayerFileMetadata
 * 
 * @section_end
 * 
 * @module_end
 */
