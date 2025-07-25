// Functions


/**
 * @function eos_user_info_copy_external_user_info_by_account_id
 * @desc **Epic Online Services Function:** [EOS_UserInfo_CopyExternalUserInfoByAccountId](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UserInfo/EOS_UserInfo_CopyExternalUserInfoByAccountId/index.html)
 * 
 * This function fetches an external user info for a given external account ID.
 * 
 * [[Note: Requires a previous call to ${function.eos_user_info_query_user_info_by_external_account} to store values in cache.]]
 * 
 * @param {string} account_id The Epic Account ID of the local player requesting the information
 * @param {string} account_id_target The Epic Account ID of the player whose information is being retrieved
 * @param {string} account_id_external The external account ID associated with the (external) user info to retrieve from the cache
 * 
 * @returns {struct.ExternalUserInfo}
 * 
 * @example
 * ```gml
 * var _struct = eos_user_info_copy_external_user_info_by_account_id(account_id, account_id_target, account_id_external);
 * 
 * if (_struct.status == EOS_RESULT.SUCCESS)
 * {
 *      var _display_name = _struct.display_name;
 * }
 * ```
 * The above code shows an example of how the function should be used. The external user info data is returned given the provided account_id.
 * @function_end
 */

/**
 * @function eos_user_info_copy_external_user_info_by_account_type
 * @desc **Epic Online Services Function:** [EOS_UserInfo_CopyExternalUserInfoByAccountType](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UserInfo/EOS_UserInfo_CopyExternalUserInfoByAccountType/index.html)
 * 
 * This function fetches an external user info for a given external account type.
 * 
 * [[Note: Requires a previous call to ${function.eos_user_info_query_user_info_by_external_account} to store values in cache.]]
 * 
 * @param {string} account_id The Epic Account ID of the local player requesting the information
 * @param {string} account_id_target The Epic Account ID of the player whose information is being retrieved
 * @param {constant.EOS_EXTERNAL_ACCOUNT_TYPE} account_type Account type of the external user info to retrieve from the cache
 * 
 * @returns {struct.ExternalUserInfo}
 * 
 * @example
 * ```gml
 * var _struct = eos_user_info_copy_external_user_info_by_account_type(account_id, account_id_target, accountType);
 * 
 * if (_struct.status == EOS_RESULT.SUCCESS)
 * {
 *      var _display_name = _struct.display_name;
 * }
 * ```
 * The above code shows an example of how the function should be used. The external user info data is returned given the provided account type.
 * @function_end
 */

/**
 * @function eos_user_info_copy_external_user_info_by_index
 * @desc **Epic Online Services Function:** [EOS_UserInfo_CopyExternalUserInfoByIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UserInfo/EOS_UserInfo_CopyExternalUserInfoByIndex/index.html)
 * 
 * This function fetches an external user info from a given index.
 * 
 * [[Note: Requires a previous call to ${function.eos_user_info_query_user_info_by_external_account} to store values in cache.]]
 * 
 * @param {string} account_id The Epic Account ID of the local player requesting the information
 * @param {string} account_id_target The Epic Account ID of the player whose information is being retrieved
 * @param {real} index Index of the external user info to retrieve from the cache
 * 
 * @returns {struct.ExternalUserInfo}
 * 
 * @example
 * ```gml
 * var _count = eos_user_info_get_external_user_info_count(account_id, account_id_target);
 * for(var i = 0 ; i < _count ; i ++)
 * {
 *     var _struct = eos_user_info_copy_external_user_info_by_index(i);
 *     var _display_name = _struct.display_name;
 * }
 * ```
 * The above code shows an example of how the function should be used. The external user info data is returned given the provided index (from a cached array).
 * @function_end
 */

/**
 * @function eos_user_info_copy_user_info
 * @desc **Epic Online Services Function:** [EOS_UserInfo_CopyUserInfo](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UserInfo/EOS_UserInfo_CopyUserInfo/index.html)
 * 
 * This function is used to immediately retrieve a copy of user information based on an Epic Account ID, cached by a previous call to ${function.eos_user_info_query_user_info}.
 * 
 * @param {string} account_id The Epic Account ID of the local player requesting the information
 * @param {string} account_id_target The Epic Account ID of the player whose information is being retrieved
 * 
 * @returns {struct.UserInfo}
 * 
 * @example
 * ```gml
 * var _struct = eos_user_info_copy_user_info(account_id, account_id_target);
 * if (_struct.status == EOS_RESULT.SUCCESS)
 * {
 *      var _nickname = _struct.nickname;
 * }
 * ```
 * The above code shows an example of how the function should be used. The user info data is returned given the provided account ID.
 * @function_end
 */

/**
 * @function eos_user_info_get_external_user_info_count
 * @desc **Epic Online Services Function:** [EOS_UserInfo_GetExternalUserInfoCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UserInfo/EOS_UserInfo_GetExternalUserInfoCount/index.html)
 * 
 * This function fetches the number of external user information that are cached locally.
 * 
 * [[Note: Requires a previous call to ${function.eos_user_info_query_user_info_by_external_account} to store values in cache.]]
 * 
 * @param {string} account_id The Epic Account ID of the local player requesting the information
 * @param {string} account_id_target The Epic Account ID of the player whose information is being retrieved
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _count = eos_user_info_get_external_user_info_count(account_id, account_id_target);
 * for(var i = 0 ; i < _count ; i ++)
 * {
 *     var _struct = eos_user_info_copy_external_user_info_by_index(i);
 *     var _display_name = _struct._display_name;
 * }
 * ```
 * The above code shows an example of how the function should be used. After a successful call to ${function.eos_user_info_query_user_info_by_external_account}, the function ${function.eos_user_info_get_external_user_info_count} will return the number of entries in the query array which can then be accessed using the ${function.eos_user_info_copy_external_user_info_by_index} function.
 * @function_end
 */

/**
 * @function eos_user_info_query_user_info
 * @desc **Epic Online Services Function:** [EOS_UserInfo_QueryUserInfo](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UserInfo/EOS_UserInfo_QueryUserInfo/index.html)
 * 
 * This function is used to start an asynchronous query to retrieve information, such as display name, about another account.
 * Once the callback has been fired with a successful ${constant.EOS_RESULT}, it is possible to call the function:
 * 
 * ${function.eos_user_info_copy_user_info}
 * 
 * to receive a ${struct.UserInfo} containing the available information.
 * 
 * @param {string} account_id The Epic Account ID of the local player requesting the information
 * @param {string} account_id_target The Epic Account ID of the player whose information is being retrieved
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_user_info_query_user_info"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_user_info_query_user_info();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_user_info_query_user_info")
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
 * @function eos_user_info_query_user_info_by_display_name
 * @desc **Epic Online Services Function:** [EOS_UserInfo_QueryUserInfoByDisplayName](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UserInfo/EOS_UserInfo_QueryUserInfoByDisplayName/index.html)
 * 
 * This function is used to start an asynchronous query to retrieve user information by display name. This can be useful for getting the account_id for a display name.
 * Once the callback has been fired with a successful ${constant.EOS_RESULT}, it is possible to call the function:
 * 
 * * ${function.eos_user_info_copy_user_info}
 * 
 * to receive a ${struct.UserInfo} containing the available information.
 * 
 * @param {string} account_id The Epic Account ID of the local player requesting the information
 * @param {string} display_name Display name of the player being queried
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_user_info_query_user_info_by_display_name"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_user_info_query_user_info_by_display_name();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_user_info_query_user_info_by_display_name")
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
 * @function eos_user_info_query_user_info_by_external_account
 * @desc **Epic Online Services Function:** [EOS_UserInfo_QueryUserInfoByExternalAccount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UserInfo/EOS_UserInfo_QueryUserInfoByExternalAccount/index.html)
 * 
 * This function is used to start an asynchronous query to retrieve user information by external accounts. This can be useful for getting the account_id for external accounts.
 * Once the callback has been fired with a successful ${constant.EOS_RESULT}, it is possible to call one of the following functions:
 * 
 * * ${function.eos_user_info_copy_external_user_info_by_account_id}
 * * ${function.eos_user_info_copy_external_user_info_by_account_type}
 * * ${function.eos_user_info_copy_external_user_info_by_index}
 * 
 * to receive a ${struct.ExternalUserInfo} containing the available information.
 * 
 * @param {string} account_id The Epic Account ID of the local player requesting the information
 * @param {string} external_account_id External account ID of the user whose information is being retrieved
 * @param {constant.EOS_EXTERNAL_ACCOUNT_TYPE} account_type Account type of the external user info to query
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_user_info_query_user_info_by_external_account"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_user_info_query_user_info_by_external_account();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_user_info_query_user_info_by_external_account")
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
 * @function_end
 */

// Constants

/**
 * @constant EOS_EXTERNAL_ACCOUNT_TYPE
 * @desc **Epic Online Services Enum:** [EOS_EExternalAccountType](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-external-account-type)
 * 
 * These constants are used to describe the type of an external account or connection.
 * 
 * These constants are also part of the ${struct.ExternalAccountInfo} struct.
 *
 * @member EPIC External account is associated with Epic Games
 * @member STEAM External account is associated with Steam
 * @member PSN External account is associated with PlayStation(TM)Network
 * @member XBL External account is associated with Xbox Live
 * @member DISCORD External account is associated with Discord
 * @member GOG External account is associated with GOG
 * @member NINTENDO External account is associated with Nintendo With both EOS Connect and EOS UserInfo APIs, the associated account type is Nintendo Service Account ID. Local user authentication is possible using Nintendo Account ID, while the account type does not get exposed to the SDK in queries related to linked accounts information.
 * @member UPLAY External account is associated with Uplay
 * @member OPENID External account is associated with an OpenID Provider
 * @member APPLE External account is associated with Apple
 * @member GOOGLE External account is associated with Google
 * @member OCULUS External account is associated with Oculus
 * @member ITCHIO External account is associated with itch.io
 * @member AMAZON External account is associated with Amazon
 * @constant_end
 */

// Structs

/**
 * @struct ExternalUserInfo
 * @desc **Epic Online Services Struct:** [EOS_UserInfo_ExternalUserInfo](https://dev.epicgames.com/docs/api-ref/structs/eos-user-info-external-user-info)
 * 
 * The external user info is represented by a struct and contains information about a single external user info.
 * 
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {string} [display_name] The display name of the external account. May not be present in the struct if not set.
 * @member {string} [account_id] The ID of the external account. May not be present in the struct if not set.
 * @member {constant.EOS_EXTERNAL_ACCOUNT_TYPE} account_type The type of the external account.
 * @struct_end
 */

/**
 * @struct UserInfo
 * @desc **Epic Online Services Struct:** [EOS_UserInfo](https://dev.epicgames.com/docs/api-ref/structs/eos-user-info)
 * 
 * The user info is represented by a struct and contains information about a single user.
 * 
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code.
 * @member {string} [display_name] The display name. This value may not be present in the struct if not set.
 * @member {string} [country] The name of the owner's country. This value may not be present in the struct if not set.
 * @member {string} [nickname] A nickname/alias for the target user assigned by the local user. This value may not be present in the struct if not set.
 * @member {string} [preferred_language] The ISO 639 language code for the user's preferred language. This value may not be present in the struct if not set.
 * @member {string} [account_id] The Epic Account ID of the user
 * @struct_end
 */

/**
 * @module user_info
 * @title User Info
 * @desc **Epic Online Services Interface:** [User Info Interface](https://dev.epicgames.com/docs/epic-account-services/eos-user-info-interface)
 * 
 * Each **Epic Online Services** (EOS) user account has a unique identifier that the service uses internally to refer to the account. The [User Info Interface](https://dev.epicgames.com/docs/epic-account-services/eos-user-info-interface) bridges the gap between the user's account IDentifier and information about the user, such as display name, country and preferred language, and so on. You can retrieve this information for both remote users and logged-in, local users.
 * 
 * @section_func 
 * @desc These functions are provided for handling user info:
 * 
 * @ref eos_user_info_copy_external_user_info_by_account_id
 * @ref eos_user_info_copy_external_user_info_by_account_type
 * @ref eos_user_info_copy_external_user_info_by_index
 * @ref eos_user_info_copy_user_info
 * @ref eos_user_info_get_external_user_info_count
 * @ref eos_user_info_query_user_info
 * @ref eos_user_info_query_user_info_by_display_name
 * @ref eos_user_info_query_user_info_by_external_account
 * 
 * @section_end
 * 
 * @section_struct
 * @desc These are the structures used by this API:
 * 
 * @ref ExternalUserInfo
 * @ref UserInfo
 * 
 * @section_end
 * 
 * @section_const
 * @desc These are the constants used by this API:
 * 
 * @ref EOS_EXTERNAL_ACCOUNT_TYPE
 * 
 * @section_end
 * 
 * @module_end
 */
