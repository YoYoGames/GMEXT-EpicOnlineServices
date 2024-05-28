// Functions


/**
 * @function EpicGames_UserInfo_CopyExternalUserInfoByAccountId
 * @desc **Epic Online Services Function:** [EOS_UserInfo_CopyExternalUserInfoByAccountId](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UserInfo/EOS_UserInfo_CopyExternalUserInfoByAccountId/index.html)
 * 
 * This function fetches an external user info for a given external account ID.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_UserInfo_QueryUserInfoByExternalAccount} to store values in cache.]]
 * 
 * @param {string} accountID The Epic Account ID of the local player requesting the information
 * @param {string} accountID_target The Epic Account ID of the player whose information is being retrieved
 * @param {string} accountID_external The external account ID associated with the (external) user info to retrieve from the cache; cannot be null
 * 
 * @returns {struct.ExternalUserInfo}
 * 
 * @example
 * ```gml
 * var _struct = EpicGames_UserInfo_CopyExternalUserInfoByAccountId(accountID, accountID_target, accountID_external);
 * 
 * if (_struct.status == EpicGames_Success)
 * {
 *      DisplayName = _struct.DisplayName;
 * }
 * ```
 * The above code shows an example of how the function should be used. The external user info data is returned given the provided accountID.
 * @function_end
 */

/**
 * @function EpicGames_UserInfo_CopyExternalUserInfoByAccountType
 * @desc **Epic Online Services Function:** [EOS_UserInfo_CopyExternalUserInfoByAccountType](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UserInfo/EOS_UserInfo_CopyExternalUserInfoByAccountType/index.html)
 * 
 * This function fetches an external user info for a given external account type.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_UserInfo_QueryUserInfoByExternalAccount} to store values in cache.]]
 * 
 * @param {string} accountID The Epic Account ID of the local player requesting the information
 * @param {string} accountID_target The Epic Account ID of the player whose information is being retrieved
 * @param {constant.EpicGames_ExternalAccountType} accountType Account type of the external user info to retrieve from the cache
 * 
 * @returns {struct.ExternalUserInfo}
 * 
 * @example
 * ```gml
 * var _struct = EpicGames_UserInfo_CopyExternalUserInfoByAccountType(accountID, accountID_target, accountType);
 * 
 * if (_struct.status == EpicGames_Success)
 * {
 *      DisplayName = _struct.DisplayName;
 * }
 * ```
 * The above code shows an example of how the function should be used. The external user info data is returned given the provided account type.
 * @function_end
 */

/**
 * @function EpicGames_UserInfo_CopyExternalUserInfoByIndex
 * @desc **Epic Online Services Function:** [EOS_UserInfo_CopyExternalUserInfoByIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UserInfo/EOS_UserInfo_CopyExternalUserInfoByIndex/index.html)
 * 
 * This function fetches an external user info from a given index.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_UserInfo_QueryUserInfoByExternalAccount} to store values in cache.]]
 * 
 * @param {string} accountID The Epic Account ID of the local player requesting the information
 * @param {string} accountID_target The Epic Account ID of the player whose information is being retrieved
 * @param {real} index Index of the external user info to retrieve from the cache
 * 
 * @returns {struct.ExternalUserInfo}
 * 
 * @example
 * ```gml
 * var _count = EpicGames_UserInfo_GetExternalUserInfoCount(accountID, accountID_target);
 * for(var i = 0 ; i < _count ; i ++)
 * {
 *     var _struct = EpicGames_UserInfo_CopyExternalUserInfoByIndex(i);
 *     DisplayName = _struct.DisplayName;
 * }
 * ```
 * The above code shows an example of how the function should be used. The external user info data is returned given the provided index (from a cached array).
 * @function_end
 */

/**
 * @function EpicGames_UserInfo_CopyUserInfo
 * @desc **Epic Online Services Function:** [EOS_UserInfo_CopyUserInfo](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UserInfo/EOS_UserInfo_CopyUserInfo/index.html)
 * 
 * This function is used to immediately retrieve a copy of user information based on an Epic Account ID, cached by a previous call to ${function.EpicGames_UserInfo_QueryUserInfo}.
 * 
 * @param {string} accountID The Epic Account ID of the local player requesting the information
 * @param {string} accountID_target The Epic Account ID of the player whose information is being retrieved
 * 
 * @returns {struct.UserInfo}
 * 
 * @example
 * ```gml
 * var _struct = EpicGames_UserInfo_CopyUserInfo(accountID, accountID_target);
 * if (_struct.status == EpicGames_Success)
 * {
 *      nickname = _struct.Nickname;
 * }
 * ```
 * The above code shows an example of how the function should be used. The user info data is returned given the provided account ID.
 * @function_end
 */

/**
 * @function EpicGames_UserInfo_GetExternalUserInfoCount
 * @desc **Epic Online Services Function:** [EOS_UserInfo_GetExternalUserInfoCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UserInfo/EOS_UserInfo_GetExternalUserInfoCount/index.html)
 * 
 * This function fetches the number of external user information that are cached locally.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_UserInfo_QueryUserInfoByExternalAccount} to store values in cache.]]
 * 
 * @param {string} accountID The Epic Account ID of the local player requesting the information
 * @param {string} accountID_target The Epic Account ID of the player whose information is being retrieved
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _count = EpicGames_UserInfo_GetExternalUserInfoCount(accountID, accountID_target);
 * for(var i = 0 ; i < _count ; i ++)
 * {
 *     var _struct = EpicGames_UserInfo_CopyExternalUserInfoByIndex(i);
 *     DisplayName = _struct.DisplayName;
 * }
 * ```
 * The above code shows an example of how the function should be used. After a successful call to ${function.EpicGames_UserInfo_QueryUserInfoByExternalAccount}, the function ${function.EpicGames_UserInfo_GetExternalUserInfoCount} will return the number of entries in the query array which can then be accessed using the ${function.EpicGames_UserInfo_CopyExternalUserInfoByIndex} function.
 * @function_end
 */

/**
 * @function EpicGames_UserInfo_QueryUserInfo
 * @desc **Epic Online Services Function:** [EOS_UserInfo_QueryUserInfo](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UserInfo/EOS_UserInfo_QueryUserInfo/index.html)
 * 
 * This function is used to start an asynchronous query to retrieve information, such as display name, about another account.
 * Once the callback has been fired with a successful ${constant.EpicGames_Result}, it is possible to call the function:
 * 
 * ${function.EpicGames_UserInfo_CopyUserInfo}
 * 
 * to receive an ${struct.UserInfo} containing the available information.
 * 
 * @param {string} accountID The Epic Account ID of the local player requesting the information
 * @param {string} accountID_target The Epic Account ID of the player whose information is being retrieved
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_UserInfo_QueryUserInfo"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_UserInfo_QueryUserInfo();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_UserInfo_QueryUserInfo")
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
 * @function EpicGames_UserInfo_QueryUserInfoByDisplayName
 * @desc **Epic Online Services Function:** [EOS_UserInfo_QueryUserInfoByDisplayName](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UserInfo/EOS_UserInfo_QueryUserInfoByDisplayName/index.html)
 * 
 * This function is used to start an asynchronous query to retrieve user information by display name. This can be useful for getting the AccountId for a display name.
 * Once the callback has been fired with a successful ${constant.EpicGames_Result}, it is possible to call the function:
 * 
 * * ${function.EpicGames_UserInfo_CopyUserInfo}
 * 
 * to receive a ${struct.UserInfo} containing the available information.
 * 
 * @param {string} accountID The Epic Account ID of the local player requesting the information
 * @param {string} DisplayName Display name of the player being queried
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_UserInfo_QueryUserInfoByDisplayName"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_UserInfo_QueryUserInfoByDisplayName();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_UserInfo_QueryUserInfoByDisplayName")
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
 * @function EpicGames_UserInfo_QueryUserInfoByExternalAccount
 * @desc **Epic Online Services Function:** [EOS_UserInfo_QueryUserInfoByExternalAccount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UserInfo/EOS_UserInfo_QueryUserInfoByExternalAccount/index.html)
 * 
 * This function is used to start an asynchronous query to retrieve user information by external accounts. This can be useful for getting the AccountId for external accounts.
 * Once the callback has been fired with a successful ${constant.EpicGames_Result}, it is possible to call one of the following functions:
 * 
 * * ${function.EpicGames_UserInfo_CopyExternalUserInfoByAccountId}
 * * ${function.EpicGames_UserInfo_CopyExternalUserInfoByAccountType}
 * * ${function.EpicGames_UserInfo_CopyExternalUserInfoByIndex}
 * 
 * to receive a ${struct.ExternalUserInfo} containing the available information.
 * 
 * @param {string} accountID The Epic Account ID of the local player requesting the information
 * @param {string} ExternalAccountId External account ID of the user whose information is being retrieved
 * @param {constant.EpicGames_ExternalAccountType} accountType Account type of the external user info to query
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_UserInfo_QueryUserInfoByExternalAccount"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_UserInfo_QueryUserInfoByExternalAccount();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_UserInfo_QueryUserInfoByExternalAccount")
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
 * @function_end
 */

// Constants

/**
 * @constant EpicGames_ExternalAccountType
 * @desc **Epic Online Services Enum:** [EOS_EExternalAccountType](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-external-account-type)
 * 
 * These constants are used to describe the type of an external account or connection.
 * 
 * These constants are also part of the ${struct.ExternalAccountInfo} struct.
 *
 * @member EpicGames_EAT_EPIC External account is associated with Epic Games
 * @member EpicGames_EAT_STEAM External account is associated with Steam
 * @member EpicGames_EAT_PSN External account is associated with PlayStation(TM)Network
 * @member EpicGames_EAT_XBL External account is associated with Xbox Live
 * @member EpicGames_EAT_DISCORD External account is associated with Discord
 * @member EpicGames_EAT_GOG External account is associated with GOG
 * @member EpicGames_EAT_NINTENDO External account is associated with Nintendo With both EOS Connect and EOS UserInfo APIs, the associated account type is Nintendo Service Account ID. Local user authentication is possible using Nintendo Account ID, while the account type does not get exposed to the SDK in queries related to linked accounts information.
 * @member EpicGames_EAT_UPLAY External account is associated with Uplay
 * @member EpicGames_EAT_OPENID External account is associated with an OpenID Provider
 * @member EpicGames_EAT_APPLE External account is associated with Apple
 * @member EpicGames_EAT_GOOGLE External account is associated with Google
 * @member EpicGames_EAT_OCULUS External account is associated with Oculus
 * @member EpicGames_EAT_ITCHIO External account is associated with itch.io
 * @member EpicGames_EAT_AMAZON External account is associated with Amazon
 * @constant_end
 */

// Structs

/**
 * @struct ExternalUserInfo
 * @desc The external user info is represented by a struct and contains information about a single external user info.
 * 
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {string} DisplayName The display name of the external account. Can be null.
 * @member {string} AccountId The ID of the external account. Can be null.
 * @member {constant.EpicGames_ExternalAccountType} AccountType The type of the external account.
 * @struct_end
 */

/**
 * @struct UserInfo
 * @desc The user info is represented by a struct and contains information about a single user info.
 * 
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code.
 * @member {string} DisplayName The display name. This may be null.
 * @member {string} Country The name of the owner's country. This may be null.
 * @member {string} Nickname A nickname/alias for the target user assigned by the local user. This may be null.
 * @member {string} PreferredLanguage The ISO 639 language code for the user's preferred language. This may be null.
 * @member {string} AccountID The Epic Account ID of the user
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
 * @ref EpicGames_UserInfo_CopyExternalUserInfoByAccountId
 * @ref EpicGames_UserInfo_CopyExternalUserInfoByAccountType
 * @ref EpicGames_UserInfo_CopyExternalUserInfoByIndex
 * @ref EpicGames_UserInfo_CopyUserInfo
 * @ref EpicGames_UserInfo_GetExternalUserInfoCount
 * @ref EpicGames_UserInfo_QueryUserInfo
 * @ref EpicGames_UserInfo_QueryUserInfoByDisplayName
 * @ref EpicGames_UserInfo_QueryUserInfoByExternalAccount
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
 * @ref EpicGames_ExternalAccountType
 * 
 * @section_end
 * 
 * @module_end
 */
