// Functions


/**
 * @function EpicGames_TitleStorage_CopyFileMetadataAtIndex
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_CopyFileMetadataAtIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/TitleStorage/EOS_TitleStorage_CopyFileMetadataAtIndex/index.html)
 * 
 * This function gets the cached copy of a file's metadata by index. The metadata will be for the last retrieved version.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_TitleStorage_QueryFileList} to store values in cache.]]
 * 
 * @param {string} userID Product User ID of the local user who is requesting file metadata (optional)
 * @param {real} index The index to get data for
 * 
 * @returns {struct.TitleFileMetadata}
 * 
 * @example
 * ```gml
 * var _count = EpicGames_TitleStorage_GetFileMetadataCount(userID);
 * for(var i = 0 ; i < _count ; i ++)
 * {
 *     var _struct = EpicGames_TitleStorage_CopyFileMetadataAtIndex(userID, i);
 *     Filename = _struct.Filename;
 * }
 * ```
 * The above code shows an example of how the function should be used. The title file metadata is returned for the provided file index.
 * @function_end
 */

/**
 * @function EpicGames_TitleStorage_CopyFileMetadataByFilename
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_CopyFileMetadataByFilename](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/TitleStorage/EOS_TitleStorage_CopyFileMetadataByFilename/index.html)
 * 
 * This function creates a cached copy of a file's metadata by filename. The metadata will be for the last retrieved or successfully saved version, and will not include any changes that have not completed writing.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_TitleStorage_QueryFileList} to store values in cache.]]
 * 
 * @param {string} userID Product User ID of the local user who is requesting file metadata (optional)
 * @param {string} name The file's name to get data for
 * @returns {struct.TitleFileMetadata}
 * 
 * @example
 * ```gml
 * var _struct = EpicGames_TitleStorage_CopyFileMetadataByFilename(userID, i);
 * if(_struct.status == EpicGames_Success)
 * {
 *     Filename = _struct.Filename;
 * }
 * ```
 * The above code shows an example of how the function should be used. The title file metadata is returned for the provided file name.
 * @function_end
 */

/**
 * @function EpicGames_TitleStorage_DeleteCache
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_DeleteCache](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/TitleStorage/EOS_TitleStorage_DeleteCache/index.html)
 * 
 * This function clears previously cached file data. This operation will be done asynchronously. All cached files except those corresponding to the transfers in progress will be removed.
 * 
 * [[Warning: Use this with care. Cache system generally tries to clear old and unused cached files from time to time. Unnecessarily clearing the cache can degrade performance as the SDK will have to re-download data.]]
 * 
 * @param {string} userID Product User ID of the local user who is deleting his cache (optional)
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_TitleStorage_DeleteCache"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_TitleStorage_DeleteCache(userID);
 * ```
 * The code sample above saves the identifier that can be used inside an ${event.social} event.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_TitleStorage_DeleteCache")
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
 * @function EpicGames_TitleStorage_GetFileMetadataCount
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_GetFileMetadataCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/TitleStorage/EOS_TitleStorage_GetFileMetadataCount/index.html)
 * 
 * This function gets the count of files we have previously queried information for and files we have previously read from / written to.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_TitleStorage_QueryFileList} to store values in cache.]]
 * 
 * @param {string} userID The Product User ID of the local user who is requesting file metadata.
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _count = EpicGames_TitleStorage_GetFileMetadataCount(userID);
 * for(var i = 0 ; i < _count ; i ++)
 * {
 *     var _struct = EpicGames_TitleStorage_CopyFileMetadataAtIndex(userID, i);
 *     Filename = _struct.Filename;
 * }
 * ```
 * The above code shows an example of how the function should be used. After a successful call to ${function.EpicGames_TitleStorage_QueryFileList}, the function ${function.EpicGames_TitleStorage_GetFileMetadataCount} will return the number of entries in the query array which can then be accessed using the ${function.EpicGames_TitleStorage_CopyFileMetadataAtIndex} function.
 * @function_end
 */

/**
 * @function EpicGames_TitleStorage_QueryFile
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_QueryFile](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/TitleStorage/EOS_TitleStorage_QueryFile/index.html)
 * 
 * This function queries a specific file's metadata, such as file names, size, and a MD5 hash of the data. This is not required before a file may be opened.
 * 
 * Once a file has been queried, its metadata will be available by the ${function.EpicGames_TitleStorage_CopyFileMetadataAtIndex} and ${function.EpicGames_TitleStorage_CopyFileMetadataByFilename} functions.
 * 
 * @param {string} userID Product User ID of the local user requesting file metadata (optional)
 * @param {string} filename The requested file's name
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_TitleStorage_QueryFile"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_TitleStorage_QueryFile(userID, "myFile.dat");
 * ```
 * The code sample above saves the identifier that can be used inside an ${event.social} event.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_TitleStorage_QueryFile")
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
 * @function EpicGames_TitleStorage_QueryFileList
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_QueryFileList](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/TitleStorage/EOS_TitleStorage_QueryFileList/index.html)
 * 
 * This function queries the file metadata, such as file names, size, and a MD5 hash of the data, for all files available for current user based on their settings (such as game role) and tags provided. This is not required before a file can be downloaded by name.
 * 
 * Once the callback has been fired with a successful ${constant.EpicGames_Result}, it is possible to call one of the following functions:
 * 
 * * ${function.EpicGames_TitleStorage_CopyFileMetadataAtIndex}
 * * ${function.EpicGames_TitleStorage_CopyFileMetadataByFilename}
 * * ${function.EpicGames_TitleStorage_GetFileMetadataCount}
 * 
 * @param {string} userID Product User ID of the local user who requested file metadata
 * @param {string} tag List of tags to use for lookup.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_TitleStorage_QueryFileList"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_TitleStorage_QueryFileList(userID, "Tag1");
 * ```
 * The code sample above saves the identifier that can be used inside an ${event.social} event.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_TitleStorage_QueryFileList")
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
 * @function EpicGames_TitleStorage_ReadFile
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_ReadFile](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/TitleStorage/EOS_TitleStorage_ReadFile/index.html)
 * 
 * This function retrieves the contents of a specific file, potentially downloading the contents if we do not have a local copy, from the cloud. This request will occur asynchronously, potentially over multiple frames.
 * 
 * @param {string} userID Product User ID of the local user who is reading the requested file
 * @param {string} filename The file name to read; this file must already exist
 * @param {string} path Local path where save the file
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_TitleStorage_ReadFile"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_TitleStorage_ReadFile(userID, "Preferences.json", "/path/to/save/Preferences.json");
 * ```
 * The code sample above saves the identifier that can be used inside an ${event.social} event.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_TitleStorage_ReadFile")
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
 * @function EpicGames_TitleStorageFileTransferRequest_CancelRequest
 * @desc **Epic Online Services Function:** [EOS_TitleStorageFileTransferRequest_CancelRequest](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/TitleStorage/EOS_TitleStorageFileTransferRequest_CancelRequest/index.html)
 * 
 * This function attempts to cancel this file request in progress. This is a best-effort command and is not guaranteed to be successful if the request has completed before this function is called.
 * 
 * @param {string} filename Filename contained in the process to cancel
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_TitleStorageFileTransferRequest_CancelRequest"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_TitleStorageFileTransferRequest_CancelRequest("myFile.txt");
 * ```
 * The code sample above saves the identifier that can be used inside an ${event.social} event.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_TitleStorageFileTransferRequest_CancelRequest")
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

// Structs

/**
 * @struct TitleFileMetadata
 * @desc  The player file metadata is represented by a struct and contains metadata information for a specific title file.
 * 
 * @member {double} FileSizeBytes The total size of the file in bytes (includes the file header in addition to the file contents)
 * @member {string} MD5Hash The MD5 Hash of the entire file (including additional file header), in hex digits
 * @member {string} Filename The file's name
 * @member {real} UnencryptedDataSizeBytes The size of data (payload) in file in unencrypted (original) form.
 * @struct_end
 */

/**
 * @module Title_Storage
 * @desc **Epic Online Services Interface:** [Title Storage Interface](https://dev.epicgames.com/docs/game-services/title-storage)
 * 
 * The [Title Storage Interface](https://dev.epicgames.com/docs/game-services/title-storage) enables developers using **Epic Online Services** (EOS) to retrieve encrypted data from cloud servers. Data that you store through this interface is accessible to any user on any device where they can log in. While similar to the ${module.Player_Data_Storage}, this interface is specialised to handle game-specific data rather than user-specific data, and can provide different versions of files based on the user's platform, region, or other conditions.
 *
 * @section_func
 * @desc These functions are provided for handling title storage:
 * 
 * @ref EpicGames_TitleStorage_CopyFileMetadataAtIndex
 * @ref EpicGames_TitleStorage_CopyFileMetadataByFilename
 * @ref EpicGames_TitleStorage_DeleteCache
 * @ref EpicGames_TitleStorage_GetFileMetadataCount
 * @ref EpicGames_TitleStorage_QueryFile
 * @ref EpicGames_TitleStorage_QueryFileList
 * @ref EpicGames_TitleStorage_ReadFile
 * @ref EpicGames_TitleStorageFileTransferRequest_CancelRequest
 * 
 * @section_end
 * 
 * @section_struct
 * @desc These are the structures used by this API:
 * 
 * @ref TitleFileMetadata
 * 
 * @section_end
 * 
 * @module_end
 */
