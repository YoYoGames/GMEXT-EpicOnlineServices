// Functions

/**
 * @function EpicGames_Connect_AddNotifyAuthExpiration
 * @desc **Epic Online Services Function:** [EOS_Connect_AddNotifyAuthExpiration](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Connect/EOS_Connect_AddNotifyAuthExpiration/index.html)
 * 
 * This function registers to receive upcoming authentication expiration notifications. Notification is approximately 10 minutes prior to expiration. Call ${function.EpicGames_Connect_Login} again with valid third-party credentials to refresh access.
 * 
 * @event social
 * @member {string} type The string `"EpicGames_Connect_AddNotifyAuthExpiration"`
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_Connect_AddNotifyAuthExpiration();
 * ```
 * The code sample above save the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Connect_AddNotifyAuthExpiration")
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
 * @function EpicGames_Connect_AddNotifyLoginStatusChanged
 * @desc **Epic Online Services Function:** [EOS_Connect_AddNotifyLoginStatusChanged](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Connect/EOS_Connect_AddNotifyLoginStatusChanged/index.html)
 * 
 * This function registers to receive user login status updates.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_Connect_AddNotifyLoginStatusChanged"`
 * @member {constant.EpicGames_Login_Status} CurrentStatus The status at the time of the notification
 * @member {constant.EpicGames_Login_Status} PrevStatus The status prior to the change
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_Connect_AddNotifyLoginStatusChanged();
 * ```
 * The code sample above save the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Connect_AddNotifyLoginStatusChanged")
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
 * @function EpicGames_Connect_CopyIdToken
 * @desc **Epic Online Services Function:** [EOS_Connect_CopyIdToken](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Connect/EOS_Connect_CopyIdToken/index.html)
 * 
 * This function fetches an ID token for a Product User ID.
 * 
 * @param {string} user The local Product User ID whose ID token should be copied.
 * 
 * @returns {struct.IdToken}
 * 
 * @example
 * ```gml
 * var _struct = EpicGames_Connect_CopyIdToken(user);
 * if(_struct.status = EpicGames_Success)
 * {
 *     JsonWebToken = _struct.JsonWebToken;
 * }
 * ```
 * The above code shows an example of how the function should be used. The JWT associated with the provided product user ID is returned inside the struct, alongside other useful information.
 * @function_end
 */

/**
 * @function EpicGames_Connect_CopyProductUserInfo
 * @desc **Epic Online Services Function:** [EOS_Connect_CopyProductUserInfo](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Connect/EOS_Connect_CopyProductUserInfo/index.html)
 * 
 * This function fetches information about a Product User, using the external account that they most recently logged in with as the reference.
 * 
 * @param {real} userID_target Product user ID to look for when copying external account info from the cache.
 * 
 * @returns {struct.ExternalAccountInfo}
 * 
 * @example
 * ```gml
 * var _struct = EpicGames_Connect_CopyProductUserInfo(userID_target);
 * if(_struct.status == EpicGames_Success)
 * {
 *     // access the data here
 * }
 * ```
 * The above code shows an example of how the function should be used.
 * @function_end
 */

/**
 * @function EpicGames_Connect_CreateUser
 * @desc **Epic Online Services Function:** [EOS_Connect_CreateUser](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Connect/EOS_Connect_CreateUser/index.html)
 * 
 * This function creates an account association with the Epic Online Services as a product user given their external auth credentials.
 * 
 * @event social
 * @member {string} type The string `"EpicGames_Connect_CreateUser"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @member {string} [LocalUserId] If the operation succeeded, this is the Product User ID of the local user who was created.
 * @event_end
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * identifier = EpicGames_Connect_CreateUser();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Connect_CreateUser")
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
 * @function EpicGames_Connect_GetLoginStatus
 * @desc **Epic Online Services Function:** [EOS_Connect_GetLoginStatus](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Connect/EOS_Connect_GetLoginStatus/index.html)
 * 
 * This function fetches the login status for a Product User ID. This Product User ID is considered logged in as long as the underlying access token has not expired.
 * 
 * @param {string} user The Product User ID of the user being queried.
 * 
 * @returns {real} EpicGames Login Status
 * 
 * @example
 * ```gml
 * if(EpicGames_Connect_GetLoginStatus(user) == EpicGames_LS_LoggedIn)
 *     show_debug_message(user + ": is logged");
 * else
 *     show_debug_message(user + ": not logged");
 * ```
 * The above code shows an example of how the function should be used. A login status constant is returned and checked against the provided built-in constants.
 * @function_end
 */

/**
 * @function EpicGames_Connect_Login
 * @desc **Epic Online Services Function:** [EOS_Connect_Login](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Connect/EOS_Connect_Login/index.html)
 * 
 * This function logs in / authenticates given a valid set of external auth credentials.
 * 
 * @param {constant.EpicGames_External_Credential_Type} type Type of external login; identifies the authentication method to use.
 * @param {string} access_token External token associated with the user logging in.
 * @param {string} display_name The user's display name on the identity provider systems.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_Connect_Login"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @member {string} [LocalUserId] If the operation succeeded, this is the Product User ID of the local user who logged in.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_Connect_Login();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Connect_Login")
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
 * @function EpicGames_Connect_RemoveNotifyAuthExpiration
 * @desc **Epic Online Services Function:** [EOS_Connect_RemoveNotifyAuthExpiration](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Connect/EOS_Connect_RemoveNotifyAuthExpiration/index.html)
 * 
 * This function unregisters from receiving expiration notifications.
 * 
 * @param {real} id The handle representing the registered callback (returned by ${function.EpicGames_Connect_AddNotifyAuthExpiration})
 * 
 * @example
 * ```gml
 * AddNotifyAuthExpiration_id = EpicGames_Connect_AddNotifyAuthExpiration();
 * //...
 * //...Later
 * //...
 * EpicGames_Connect_RemoveNotifyAuthExpiration(AddNotifyAuthExpiration_id);
 * ```
 * The code sample above enables the auth expiration notifications (${function.EpicGames_Connect_AddNotifyAuthExpiration}) and later disables them by referring to the previously generated handle.
 * @function_end
 */

/**
 * @function EpicGames_Connect_RemoveNotifyLoginStatusChanged
 * @desc **Epic Online Services Function:** [EOS_Connect_RemoveNotifyLoginStatusChanged](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Connect/EOS_Connect_RemoveNotifyLoginStatusChanged/index.html)
 * 
 * This function unregisters from receiving user login status updates.
 * 
 * @param {real} Id The handle representing the registered callback (returned by ${function.EpicGames_Connect_AddNotifyLoginStatusChanged})
 * 
 * @example
 * ```gml
 * NotifyLoginStatusChanged_id = EpicGames_Connect_AddNotifyLoginStatusChanged();
 * //...
 * //...Later
 * //...
 * EpicGames_Connect_RemoveNotifyLoginStatusChanged(NotifyLoginStatusChanged_id);
 * ```
 * The code sample above enables the login status changed notifications (${function.EpicGames_Connect_AddNotifyLoginStatusChanged}) and later disables them by referring to the previously generated handle.
 * @function_end
 */

// Structs

/**
 * @struct ExternalAccountInfo
 * @desc An external account information is represented by a struct and contains data about a single account.
 * 
 * The status member present in the struct can be represented by one of the following values:
 * 
 * * `EpicGames_Success` if the information is available and was correctly returned;
 * * `EpicGames_InvalidParameters` (extension internal error, should never be returned);
 * * `EpicGames_NotFound` if the achievement definition is not found;
 * * `EpicGames_Invalid_ProductUserID` if any of the userid options are incorrect;
 * 
 * @member {constant.EpicGames_Result} status The result value of the task
 * @member {string} status_message Text representation of the status code
 * @member {string} DisplayName Display name, can be null if not set.
 * @member {string} userID The Product User ID of the target user.
 * @member {string} AccountId External account ID. May be set to an empty string if the AccountIdType of another user belongs to different account system than the local user's authenticated account. The availability of this field is dependent on account system specifics.
 * @member {constant.EpicGames_ExternalAccountType} AccountIdType The identity provider that owns the external account.
 * @member {int64} LastLoginTime The POSIX timestamp for the time the user last logged in.
 * @struct_end
 */

/**
 * @struct IdToken
 * @desc A struct containg information about an ID token.
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {string} JsonWebToken The ID token as a JSON Web Token (JWT) string.
 * @member {string} ProductUserId The Product User ID described by the ID token.
 * @struct_end
 */

/**
 * @module connect
 * @title Connect
 * @desc **Epic Online Services Interface:** [Connect Interface](https://dev.epicgames.com/docs/game-services/eos-connect-interface)
 * 
 * The [Connect Interface](https://dev.epicgames.com/docs/game-services/eos-connect-interface) enables an external identity provider to integrate with and use the **Epic Online Services** (EOS) ecosystem.
 * 
 * @section_func Functions
 * @desc These functions are provided for handling connectivity:
 * 
 * @ref EpicGames_Connect_AddNotifyAuthExpiration
 * @ref EpicGames_Connect_AddNotifyLoginStatusChanged
 * @ref EpicGames_Connect_CopyIdToken
 * @ref EpicGames_Connect_CopyProductUserInfo
 * @ref EpicGames_Connect_CreateUser
 * @ref EpicGames_Connect_GetLoginStatus
 * @ref EpicGames_Connect_Login
 * @ref EpicGames_Connect_RemoveNotifyAuthExpiration
 * @ref EpicGames_Connect_RemoveNotifyLoginStatusChanged
 * @section_end
 *
 * @section_struct Structs
 * @desc These are the structures used by this API:
 * @ref ExternalAccountInfo
 * @ref IdToken
 * @section_end
 * 
 * @module_end
 */
