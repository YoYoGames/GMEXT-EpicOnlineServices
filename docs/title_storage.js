// Functions


/**
 * @function eos_title_storage_copy_file_metadata_at_index
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_CopyFileMetadataAtIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/TitleStorage/EOS_TitleStorage_CopyFileMetadataAtIndex/index.html)
 * 
 * This function gets the cached copy of a file's metadata by index. The metadata will be for the last retrieved version.
 * 
 * [[Note: Requires a previous call to ${function.eos_title_storage_query_file_list} to store values in cache.]]
 * 
 * @param {string} user_id Product User ID of the local user who is requesting file metadata (optional)
 * @param {real} index The index to get data for
 * 
 * @returns {struct.TitleFileMetadata}
 * 
 * @example
 * ```gml
 * var _count = eos_title_storage_get_file_metadata_count(user_id);
 * for(var i = 0 ; i < _count ; i ++)
 * {
 *     var _struct = eos_title_storage_copy_file_metadata_at_index(user_id, i);
 *     var _filename = _struct.filename;
 * }
 * ```
 * The above code shows an example of how the function should be used. The title file metadata is returned for the provided file index.
 * @function_end
 */

/**
 * @function eos_title_storage_copy_file_metadata_by_filename
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_CopyFileMetadataByFilename](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/TitleStorage/EOS_TitleStorage_CopyFileMetadataByFilename/index.html)
 * 
 * This function creates a cached copy of a file's metadata by filename. The metadata will be for the last retrieved or successfully saved version, and will not include any changes that have not completed writing.
 * 
 * [[Note: Requires a previous call to ${function.eos_title_storage_query_file_list} to store values in cache.]]
 * 
 * @param {string} user_id Product User ID of the local user who is requesting file metadata (optional)
 * @param {string} name The file's name to get data for
 * @returns {struct.TitleFileMetadata}
 * 
 * @example
 * ```gml
 * var _struct = eos_title_storage_copy_file_metadata_by_filename(user_id, "TheFile");
 * if(_struct.status == EOS_RESULT.SUCCESS)
 * {
 *     var _filename = _struct.filename;
 * }
 * ```
 * The above code shows an example of how the function should be used. The title file metadata is returned for the provided file name.
 * @function_end
 */

/**
 * @function eos_title_storage_delete_cache
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_DeleteCache](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/TitleStorage/EOS_TitleStorage_DeleteCache/index.html)
 * 
 * This function clears previously cached file data. This operation will be done asynchronously. All cached files except those corresponding to the transfers in progress will be removed.
 * 
 * [[Warning: Use this with care. The cache system generally tries to clear old and unused cached files from time to time. Unnecessarily clearing the cache can degrade performance as the SDK will have to re-download data.]]
 * 
 * @param {string} [user_id] Product User ID of the local user who is deleting his cache (optional)
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_title_storage_delete_cache"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_title_storage_delete_cache(user_id);
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_title_storage_delete_cache")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EOS_RESULT.SUCCESS)
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
 * @function eos_title_storage_get_file_metadata_count
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_GetFileMetadataCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/TitleStorage/EOS_TitleStorage_GetFileMetadataCount/index.html)
 * 
 * This function gets the count of files we have previously queried information for and files we have previously read from / written to.
 * 
 * [[Note: Requires a previous call to ${function.eos_title_storage_query_file_list} to store values in cache.]]
 * 
 * @param {string} user_id The Product User ID of the local user who is requesting file metadata.
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _count = eos_title_storage_get_file_metadata_count(user_id);
 * for(var i = 0 ; i < _count ; i ++)
 * {
 *     var _struct = eos_title_storage_copy_file_metadata_at_index(user_id, i);
 *     var _filename = _struct.filename;
 * }
 * ```
 * The above code shows an example of how the function should be used. After a successful call to ${function.eos_title_storage_query_file_list}, the function ${function.eos_title_storage_get_file_metadata_count} will return the number of entries in the query array which can then be accessed using the ${function.eos_title_storage_copy_file_metadata_at_index} function.
 * @function_end
 */

/**
 * @function eos_title_storage_query_file
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_QueryFile](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/TitleStorage/EOS_TitleStorage_QueryFile/index.html)
 * 
 * This function queries a specific file's metadata, such as file names, size, and a MD5 hash of the data. This is not required before a file may be opened.
 * 
 * Once a file has been queried, its metadata will be available by the ${function.eos_title_storage_copy_file_metadata_at_index} and ${function.eos_title_storage_copy_file_metadata_by_filename} functions.
 * 
 * @param {string} user_id Product User ID of the local user requesting file metadata
 * @param {string} filename The requested file's name
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_title_storage_query_file"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_title_storage_query_file(user_id, "myFile.dat");
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_title_storage_query_file")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EOS_RESULT.SUCCESS)
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
 * @function eos_title_storage_query_file_list
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_QueryFileList](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/TitleStorage/EOS_TitleStorage_QueryFileList/index.html)
 * 
 * This function queries the file metadata, such as file names, size, and a MD5 hash of the data, for all files available for current user based on their settings (such as game role) and tags provided. This is not required before a file can be downloaded by name.
 * 
 * Once the callback has been fired with a successful ${constant.EOS_RESULT}, it is possible to call one of the following functions:
 * 
 * * ${function.eos_title_storage_copy_file_metadata_at_index}
 * * ${function.eos_title_storage_copy_file_metadata_by_filename}
 * * ${function.eos_title_storage_get_file_metadata_count}
 * 
 * @param {string} user_id Product User ID of the local user who requested file metadata
 * @param {string|array} tag List of tags to use for lookup, either a ${type.string} (single tag) or an ${type.array} of strings (multiple tags)
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_title_storage_query_file_list"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_title_storage_query_file_list(user_id, "Tag1");
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_title_storage_query_file_list")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EOS_RESULT.SUCCESS)
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
 * @function eos_title_storage_read_file
 * @desc **Epic Online Services Function:** [EOS_TitleStorage_ReadFile](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/TitleStorage/EOS_TitleStorage_ReadFile/index.html)
 * 
 * This function retrieves the contents of a specific file, potentially downloading the contents if we do not have a local copy, from the cloud. This request will occur asynchronously, potentially over multiple frames.
 * 
 * @param {string} user_id Product User ID of the local user who is reading the requested file
 * @param {string} filename The file name to read; this file must already exist
 * @param {string} path Local path where save the file
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_title_storage_read_file"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_title_storage_read_file(user_id, "Preferences.json", "/path/to/save/Preferences.json");
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_title_storage_read_file")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EOS_RESULT.SUCCESS)
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
 * @function eos_title_storage_file_transfer_request_cancel_request
 * @desc **Epic Online Services Function:** [EOS_TitleStorageFileTransferRequest_CancelRequest](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/TitleStorage/EOS_TitleStorageFileTransferRequest_CancelRequest/index.html)
 * 
 * This function attempts to cancel this file request in progress. This is a best-effort command and is not guaranteed to be successful if the request has completed before this function is called.
 * 
 * @param {string} filename Filename contained in the process to cancel
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_title_storage_file_transfer_request_cancel_request"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_title_storage_file_transfer_request_cancel_request("myFile.txt");
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_title_storage_file_transfer_request_cancel_request")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EOS_RESULT.SUCCESS)
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
 * @struct TitleFileMetadata
 * @desc  The player file metadata is represented by a struct and contains metadata information for a specific title file.
 * 
 * @member {constant.EOS_RESULT} status The status code of the request
 * @member {string} status_message A text representation of the status code
 * @member {string} [filename] The file's name
 * @member {real} [size] The total size of the file in bytes (includes the file header in addition to the file contents)
 * @member {string} [md5_hash] The MD5 Hash of the entire file (including additional file header), in hex digits
 * @member {real} [size_unencrypted] The size of data (payload) in file in unencrypted (original) form.
 * @struct_end
 */

/**
 * @module title_storage
 * @title Title Storage
 * @desc **Epic Online Services Interface:** [Title Storage Interface](https://dev.epicgames.com/docs/game-services/title-storage)
 * 
 * The [Title Storage Interface](https://dev.epicgames.com/docs/game-services/title-storage) enables developers using **Epic Online Services** (EOS) to retrieve encrypted data from cloud servers. Data that you store through this interface is accessible to any user on any device where they can log in. While similar to the ${module.player_data_storage}, this interface is specialised to handle game-specific data rather than user-specific data, and can provide different versions of files based on the user's platform, region, or other conditions.
 *
 * @section_func
 * @desc These functions are provided for handling title storage:
 * 
 * @ref eos_title_storage_copy_file_metadata_at_index
 * @ref eos_title_storage_copy_file_metadata_by_filename
 * @ref eos_title_storage_delete_cache
 * @ref eos_title_storage_get_file_metadata_count
 * @ref eos_title_storage_query_file
 * @ref eos_title_storage_query_file_list
 * @ref eos_title_storage_read_file
 * @ref eos_title_storage_file_transfer_request_cancel_request
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
