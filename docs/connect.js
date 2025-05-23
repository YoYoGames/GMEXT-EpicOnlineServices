// Functions

/**
 * @function eos_connect_add_notify_auth_expiration
 * @desc **Epic Online Services Function:** [EOS_Connect_AddNotifyAuthExpiration](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Connect/EOS_Connect_AddNotifyAuthExpiration/index.html)
 * 
 * This function registers to receive upcoming authentication expiration notifications. Notification is approximately 10 minutes prior to expiration. Call ${function.eos_connect_login} again with valid third-party credentials to refresh access.
 * 
 * @event social
 * @member {string} type The string `"eos_connect_add_notify_auth_expiration"`
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_connect_add_notify_auth_expiration();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_connect_add_notify_auth_expiration")
 * {
 *     if (async_load[? "status"] == EOS_Result.Success)
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
 * @function eos_connect_add_notify_login_status_changed
 * @desc **Epic Online Services Function:** [EOS_Connect_AddNotifyLoginStatusChanged](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Connect/EOS_Connect_AddNotifyLoginStatusChanged/index.html)
 * 
 * This function registers to receive user login status updates.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_connect_add_notify_login_status_changed"`
 * @member {constant.EOS_LoginStatus} current_status The status at the time of the notification
 * @member {constant.EOS_LoginStatus} previous_status The status prior to the change
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_connect_add_notify_login_status_changed();
 * ```
 * The code sample above save the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_connect_add_notify_login_status_changed")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EOS_Result.Success)
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
 * @function eos_connect_copy_id_token
 * @desc **Epic Online Services Function:** [EOS_Connect_CopyIdToken](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Connect/EOS_Connect_CopyIdToken/index.html)
 * 
 * This function fetches an ID token for a Product User ID.
 * 
 * @param {string} user The local Product User ID whose ID token should be copied
 * 
 * @returns {struct.IdToken}
 * 
 * @example
 * ```gml
 * var _struct = eos_connect_copy_id_token(user);
 * if(_struct.status = EOS_Result.Success)
 * {
 *     json_web_token = _struct.json_web_token;
 * }
 * ```
 * The above code shows an example of how the function should be used. The JWT associated with the provided product user ID is returned inside the struct, alongside other useful information.
 * @function_end
 */

/**
 * @function eos_connect_copy_product_user_info
 * @desc **Epic Online Services Function:** [EOS_Connect_CopyProductUserInfo](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Connect/EOS_Connect_CopyProductUserInfo/index.html)
 * 
 * This function fetches information about a Product User, using the external account that they most recently logged in with as the reference.
 * 
 * @param {string} user_id_target Product user ID to look for when copying external account info from the cache.
 * 
 * @returns {struct.ExternalAccountInfo}
 * 
 * @example
 * ```gml
 * var _struct = eos_connect_copy_product_user_info(user_id_target);
 * if(_struct.status == EOS_Result.Success)
 * {
 *     // access the data here
 * }
 * ```
 * The above code shows an example of how the function should be used.
 * @function_end
 */

/**
 * @function eos_connect_create_user
 * @desc **Epic Online Services Function:** [EOS_Connect_CreateUser](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Connect/EOS_Connect_CreateUser/index.html)
 * 
 * This function creates an account association with the Epic Online Services as a product user given their external auth credentials.
 * 
 * @event social
 * @member {string} type The string `"eos_connect_create_user"`
 * @member {constant.EOS_Result} status The status code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @member {string} [local_user_id] If the operation succeeded, this is the Product User ID of the local user who was created
 * @event_end
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * identifier = eos_connect_create_user();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_connect_create_user")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EOS_Result.Success)
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
 * @function eos_connect_get_login_status
 * @desc **Epic Online Services Function:** [EOS_Connect_GetLoginStatus](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Connect/EOS_Connect_GetLoginStatus/index.html)
 * 
 * This function fetches the login status for a Product User ID. This Product User ID is considered logged in as long as the underlying access token has not expired.
 * 
 * @param {string} user The Product User ID of the user being queried
 * 
 * @returns {real} EpicGames Login Status
 * 
 * @example
 * ```gml
 * if(eos_connect_get_login_status(user) == EOS_LoginStatus.LoggedIn)
 *     show_debug_message(user + ": is logged");
 * else
 *     show_debug_message(user + ": not logged");
 * ```
 * The above code shows an example of how the function should be used. A login status constant is returned and checked against the provided built-in constants.
 * @function_end
 */

/**
 * @function eos_connect_login
 * @desc **Epic Online Services Function:** [EOS_Connect_Login](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Connect/EOS_Connect_Login/index.html)
 * 
 * This function logs in / authenticates given a valid set of external auth credentials.
 * 
 * @param {constant.EOS_ExternalCredentialType} type Type of external login; identifies the authentication method to use.
 * @param {string} access_token External token associated with the user logging in
 * @param {string} display_name The user's display name on the identity provider systems
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_connect_login"`
 * @member {constant.EOS_Result} status The status code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @member {string} [local_user_id] If the operation succeeded, this is the Product User ID of the local user who logged in.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_connect_login();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_connect_login")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EOS_Result.Success)
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
 * @function eos_connect_remove_notify_auth_expiration
 * @desc **Epic Online Services Function:** [EOS_Connect_RemoveNotifyAuthExpiration](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Connect/EOS_Connect_RemoveNotifyAuthExpiration/index.html)
 * 
 * This function unregisters from receiving expiration notifications.
 * 
 * @param {real} id The handle representing the registered callback (returned by ${function.eos_connect_add_notify_auth_expiration})
 * 
 * @example
 * ```gml
 * add_notify_auth_expiration_id = eos_connect_add_notify_auth_expiration();
 * //...
 * //...Later
 * //...
 * eos_connect_remove_notify_auth_expiration(add_notify_auth_expiration_id);
 * ```
 * The code sample above enables the auth expiration notifications (${function.eos_connect_add_notify_auth_expiration}) and later disables them by referring to the previously generated handle.
 * @function_end
 */

/**
 * @function eos_connect_remove_notify_login_status_changed
 * @desc **Epic Online Services Function:** [EOS_Connect_RemoveNotifyLoginStatusChanged](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Connect/EOS_Connect_RemoveNotifyLoginStatusChanged/index.html)
 * 
 * This function unregisters from receiving user login status updates.
 * 
 * @param {real} id The handle representing the registered callback (returned by ${function.eos_connect_add_notify_login_status_changed})
 * 
 * @example
 * ```gml
 * notify_login_status_changed_id = eos_connect_add_notify_login_status_changed();
 * //...
 * //...Later
 * //...
 * eos_connect_remove_notify_login_status_changed(notify_login_status_changed_id);
 * ```
 * The code sample above enables the login status changed notifications (${function.eos_connect_add_notify_login_status_changed}) and later disables them by referring to the previously generated handle.
 * @function_end
 */

// Structs

/**
 * @struct ExternalAccountInfo
 * @desc An external account information is represented by a struct and contains data about a single account.
 * 
 * The status member present in the struct can be represented by one of the following values:
 * 
 * * `EOS_Result.Success` if the information is available and was correctly returned;
 * * `EOS_Result.InvalidParameters` (extension internal error, should never be returned);
 * * `EOS_Result.NotFound` if the achievement definition is not found;
 * * `EOS_Result.Invalid_ProductUserID` if any of the user ID options are incorrect;
 * 
 * @member {constant.EOS_Result} status The result value of the task
 * @member {string} status_message Text representation of the status code
 * @member {string} display_name Display name, can not be present in the struct if not set
 * @member {string} user_id The Product User ID of the target user
 * @member {string} account_id External account ID. May be set to an empty string if the `account_id_type` of another user belongs to different account system than the local user's authenticated account. The availability of this field is dependent on account system specifics.
 * @member {constant.eos_external_account_type} account_id_type The identity provider that owns the external account
 * @member {int64} last_login_time The POSIX timestamp for the time the user last logged in
 * @struct_end
 */

/**
 * @struct IdToken
 * @desc A struct containing information about an ID token.
 * @member {constant.EOS_Result} status The status code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {string} json_web_token The ID token as a JSON Web Token (JWT) string
 * @member {string} product_user_id The Product User ID described by the ID token
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
 * @ref eos_connect_add_notify_auth_expiration
 * @ref eos_connect_add_notify_login_status_changed
 * @ref eos_connect_copy_id_token
 * @ref eos_connect_copy_product_user_info
 * @ref eos_connect_create_user
 * @ref eos_connect_get_login_status
 * @ref eos_connect_login
 * @ref eos_connect_remove_notify_auth_expiration
 * @ref eos_connect_remove_notify_login_status_changed
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
