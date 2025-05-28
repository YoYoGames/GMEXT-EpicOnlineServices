// Functions

/**
 * @function eos_auth_add_notify_login_status_changed
 * @desc **Epic Online Services Function:** [EOS_Auth_AddNotifyLoginStatusChanged](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_AddNotifyLoginStatusChanged/index.html)
 * 
 * This function registers to receive login status updates.
 * 
 * @event social
 * @member {string} type The string `"eos_auth_add_notify_login_status_changed"`
 * @member {constant.EOS_LOGIN_STATUS} current_status The status at the time of the notification
 * @member {constant.EOS_LOGIN_STATUS} prev_status The status prior to the change
 * @event_end
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * identifier = eos_auth_add_notify_login_status_changed();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_auth_add_notify_login_status_changed")
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
 * @function eos_auth_copy_id_token
 * @desc **Epic Online Services Function:** [EOS_Auth_CopyIdToken](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_CopyIdToken/index.html)
 * 
 * This function fetches an ID token for an Epic Account ID. ID tokens are used to securely verify user identities with online services. The most common use case is using an ID token to authenticate the local user by their selected account ID, which is the account ID that should be used to access any game-scoped data for the current application. An ID token for the selected account ID of a locally authenticated user will always be readily available. To retrieve it for the selected account ID, you can use ${function.eos_auth_copy_id_token} directly after a successful user login.
 * 
 * @param {string} account_id The Epic Account ID of the user being queried.
 * 
 * @returns {struct.IdWebTokenInfo}
 * 
 * @example
 * ```gml
 * var _struct = eos_auth_copy_id_token(account_id);
 * if(_struct.status == EOS_RESULT.SUCCESS)
 * {
 *     json_web_token = _struct.json_web_token;
 * }
 * ```
 * The above code shows an example of how the function should be used. The token associated with the provided account ID is returned inside the struct, alongside other useful information.
 * @function_end
 */

/**
 * @function eos_auth_copy_user_auth_token
 * @desc **Epic Online Services Function:** [EOS_Auth_CopyUserAuthToken](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_CopyUserAuthToken/index.html)
 * 
 * This function fetches a user auth token for an Epic Account ID. A user authentication token allows any code with possession (backend/client) to perform certain actions on behalf of the user. Because of this, for the purposes of user identity verification, the ${function.eos_auth_copy_id_token} should be used instead.
 * 
 * @param {string} account_id The Epic Account ID of the user being queried
 * 
 * @returns {struct.AuthTokenInfo}
 * 
 * @example
 * ```gml
 * var _struct = eos_auth_copy_user_auth_token(account_id);
 * if(_struct.status == EOS_RESULT.SUCCESS)
 * {
 *      var _access_token = _struct.access_token;
 * }
 * ```
 * The above code shows an example of how the function should be used. The access token associated with the provided account ID is returned inside the struct alongside other useful information.
 * @function_end
 */

/**
 * @function eos_auth_delete_persistent_auth
 * @desc **Epic Online Services Function:** [EOS_Auth_DeletePersistentAuth](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_DeletePersistentAuth/index.html)
 * 
 * This function deletes a previously received and locally stored persistent auth access token for the currently logged in user of the local device. On Desktop and Mobile platforms, the access token is deleted from the keychain of the local user and a backend request is made to revoke the token on the authentication server. On Console platforms, even though the caller is responsible for storing and deleting the access token on the local device, this function should still be called with the access token before its deletion to make the best effort in attempting to also revoke it on the authentication server. If the function would fail on Console, the caller should still proceed as normal to delete the access token locally as intended.
 * 
 * @param {string} refresh_token A long-lived refresh token that is used with the `EOS_LoginCredentialType.PersistentAuth` login type and is to be revoked from the authentication server. Only used on Console platforms. On Desktop and Mobile platforms, set this parameter to `undefined`.
 * 
 * @example
 * ```gml
 * eos_auth_delete_persistent_auth(refresh_token);
 * ```
 * The above code shows an example of how the function should be used. The refresh token provided will be revoked and invalidated.
 * @function_end
 */

/**
 * @function eos_auth_get_login_status
 * @desc **Epic Online Services Function:** [EOS_Auth_GetLoginStatus](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_GetLoginStatus/index.html)
 * 
 * This function fetches the EpicGames login status for an Epic Account ID.
 * 
 * @param {string} account_id The Epic Account ID of the user being queried
 * 
 * @returns {constant.EOS_LOGIN_STATUS}
 * 
 * @example
 * ```gml
 * switch(eos_auth_get_login_status(account_id))
 * {
 *     case EOS_LOGIN_STATUS.NOT_LOGGED_IN:
 *         draw_text(100, 190, "Login Status: Not Logged In");
 *         break;
 * 
 *     case EOS_LOGIN_STATUS.USING_LOCAL_PROFILE:
 *         draw_text(100, 190, "Login Status: Using Local Profile");
 *         break;
 * 
 *     case EOS_LOGIN_STATUS.LOGGED_IN:
 *         draw_text(100, 190, "Login Status: Logged In");
 *         break;
 * }
 * ```
 * The above code shows an example of how the function should be used. A login status constant is returned and checked against the provided built-in constants.
 * @function_end
 */

/**
 * @function eos_auth_get_selected_account_id
 * @desc **Epic Online Services Function:** [EOS_Auth_GetSelectedAccountId](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_GetSelectedAccountId/index.html)
 * 
 * This function fetches the selected account ID to the current application for a local authenticated user.
 * 
 * @param {string} account The selected account ID corresponding to the given account ID
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * var _account_id = eos_auth_get_selected_account_id(account_id);
 * ```
 * The above code shows an example of how the function should be used.
 * @function_end
 */

/**
 * @function eos_auth_link_account
 * @desc **Epic Online Services Function:** [EOS_Auth_LinkAccount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_LinkAccount/index.html)
 * 
 * This function links an external account by continuing the previous login attempt with a continuance token. On Desktop and Mobile platforms, the user will be presented the Epic Account Portal to resolve their identity. On Console, the user will login to their Epic Account using an external device, e.g. a mobile device or a desktop PC, by browsing to the presented authentication URL and entering the device code presented by the game on the console. On success, the user will be logged in at the completion of this action. This will commit this external account to the Epic Account and cannot be undone in the SDK.
 * 
 * @param {string} account_id The Epic Account ID of the logged in local user whose Epic Account will be linked with the local Nintendo NSA ID Account. By default set to `undefined`.
 * @param {constant.EOS_AUTH_SCOPE_FLAGS} scope_flags Combination of the enumeration flags to specify how the account linking operation will be performed
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_auth_link_account"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {string} account_id The Epic Account ID used upon calling the function that generated this callback
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @example
 * ```gml
 * var _scope_flags = EOS_AUTH_SCOPE_FLAGS.BASIC_PROFILE | EOS_AUTH_SCOPE_FLAGS.FRIENDS_LIST | EOS_AUTH_SCOPE_FLAGS.PRESENCE;
 * identifier = eos_auth_login(account_id, _scope_flags);
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_auth_link_account")
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
 * @function eos_auth_login
 * @desc **Epic Online Services Function:** [EOS_Auth_Login](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_Login/index.html)
 * 
 * This function logs in / authenticates with user credentials.
 * 
 * [[Note: The permissions that you pass must correspond exactly to the ones you set in the [Developer Portal](https://dev.epicgames.com/docs/dev-portal). See [Permissions](https://dev.epicgames.com/docs/epic-account-services/getting-started#permissions).]]
 * 
 * @param {constant.EOS_LOGIN_CREDENTIAL_TYPE} type Type of login. Needed to identify the auth method to use.
 * @param {constant.EOS_AUTH_SCOPE_FLAGS} scope_flags Auth scope flags are permissions to request from the user while they are logging in. This is a bitwise-or union (pipe symbol `|`) of ${constant.EOS_AUTH_SCOPE_FLAGS}). These must correspond exactly to the ones you set in the [Developer Portal](https://dev.epicgames.com/docs/dev-portal)
 * @param {string} id ID of the user logging in, based on ${constant.EOS_LOGIN_CREDENTIAL_TYPE}
 * @param {string} token Credentials or token related to the user logging in
 * @param {constant.EOS_EXTERNAL_CREDENTIAL_TYPE} external_type Type of external login. Needed to identify the external auth method to use. Used when login type is set to `EOS_LOGIN_CREDENTIAL_TYPE.EXTERNAL_AUTH`, ignored otherwise (see the External Login Flow Guide on the ${page.logging_in} page for more details). Note that you must still pass a value for this parameter when not using an external auth method.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_auth_login"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @member {string} account_id The Epic Account ID of the local user who has logged in
 * @member {string} [selected_account_id] The Epic Account ID that has been previously selected to be used for the current application. Applications should use this ID to authenticate with online backend services that store game-scoped data for users. Only when `status` is success
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_auth_login(
 *                 EOS_LOGIN_CREDENTIAL_TYPE.EXCHANGE_CODE,
 *                 EOS_AUTH_SCOPE_FLAGS.BASIC_PROFILE | EOS_AUTH_SCOPE_FLAGS.FRIENDS_LIST | EOS_AUTH_SCOPE_FLAGS.PRESENCE,
 *                 "",
 *                 code,
 *                 -1);
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_auth_login")
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
 * @function eos_auth_logout
 * @desc **Epic Online Services Function:** [EOS_Auth_Logout](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_Logout/index.html)
 * 
 * This function signs the player out of the online service.
 * 
 * @param {string} account_id The Epic Account ID of the local user who is being logged out
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_auth_logout"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_auth_logout(account_id);
 * ```
 * The code sample above save the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_auth_logout")
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
 * @function eos_auth_query_id_token
 * @desc **Epic Online Services Function:** [EOS_Auth_QueryIdToken](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_QueryIdToken/index.html)
 * 
 * This function queries the backend for an ID token that describes one of the merged account IDs of a local authenticated user. The ID token can be used to impersonate a merged account ID when communicating with online services. An ID token for the selected account ID of a locally authenticated user will always be readily available and does not need to be queried explicitly.
 * 
 * @param {string} account_id The Epic Account ID of the local authenticated user
 * @param {string} account_id_target The target Epic Account ID for which to query an ID token. This account ID may be the same as the input local_user_id or another merged account ID associated with the local user's Epic account. An ID token for the selected account ID of a locally authenticated user will always be readily available. To retrieve it for the selected account ID, you can use ${function.eos_auth_copy_id_token} directly after a successful user login.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_auth_query_id_token"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 *
 * @example
 * 
 * ```gml
 * identifier = eos_auth_query_id_token(account_id, account_id);
 * ```
 * The code sample above save the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_auth_query_id_token")
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
 * @function eos_auth_remove_notify_login_status_changed
 * @desc **Epic Online Services Function:** [EOS_Auth_RemoveNotifyLoginStatusChanged](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_RemoveNotifyLoginStatusChanged/index.html)
 * 
 * This function unregisters from receiving login status updates.
 * 
 * @param {real} id handle ID representing the registered callback (from ${function.eos_auth_add_notify_login_status_changed})
 * 
 * @example
 * ```gml
 * var _handle = eos_auth_add_notify_login_status_changed();
 * //...
 * //...later
 * //...
 * eos_auth_remove_notify_login_status_changed(_handle);
 * ```
 * The code sample above enables the login status notifications (${function.eos_auth_add_notify_login_status_changed}) and later disables them by referring to the previously generated handle.
 * @function_end
 */

/**
 * @function eos_auth_verify_id_token
 * @desc **Epic Online Services Function:** [EOS_Auth_VerifyIdToken](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_VerifyIdToken/index.html)
 * 
 * This function verifies a given ID token for authenticity and validity.
 * 
 * @param {string} account_id The Epic Account ID of the local user who is being verified
 * @param {string} json_web_token The ID token to verify
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_auth_verify_id_token"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_auth_verify_id_token(account_id, json_web_token);
 * ```
 * The code sample above keeps a handle that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_auth_verify_id_token")
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

// Constants

/**
 * @constant EOS_AUTH_SCOPE_FLAGS
 * @desc **Epic Online Services Enum:** [EOS_EAuthScopeFlags](https://dev.epicgames.com/docs/api-ref/enums/eos-e-auth-scope-flags)
 * 
 * List of the supported scope flags associated with the login API calls:
 * 
 * @member NO_FLAGS No flags
 * @member BASIC_PROFILE Permissions to see your account ID, display name, language and count
 * @member FRIENDS_LIST Permissions to see a list of your friends who use this application
 * @member PRESENCE Permissions to set your online presence and see presence of your friend
 * @member FRIENDS_MANAGEMENT Permissions to manage the Epic friends list. This scope is restricted to Epic first party products, and attempting to use it will result in authentication failure.
 * @member EMAIL Permissions to see email in the response when fetching information for a user. This scope is restricted to Epic first party products, and attempting to use it will result in authentication failure.
 * @member COUNTRY Permissions to see your country
 * @constant_end
 */

/**
 * @constant EOS_EXTERNAL_CREDENTIAL_TYPE
 * @desc **Epic Online Services Constant:** [EOS_EExternalCredentialType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-external-credential-type)
 * 
 * List of the supported identity providers to authenticate a user. The type of authentication token is specific to each provider. Tokens in string format should be passed as-is to the function.
 * 
 * @member EPIC Epic Account Services Token Using ID Token is preferred, retrieved with ${function.eos_auth_copy_id_token} that returns **JsonWebToken**. Using Auth Token is supported for backwards compatibility, retrieved with ${function.eos_auth_copy_user_auth_token} that returns **access_token**. Supported with ${function.eos_connect_login}.
 * @member STEAM_APP_TICKET Steam Encrypted App Ticket Generated using the **RequestEncryptedAppTicket** API of Steamworks SDK. The retrieved App is then passed into the ${function.eos_auth_login} or ${function.eos_connect_login} APIs.
 * @member STEAM_SESSION_TICKET Steam Auth Session Ticket generated using the ISteamUser::GetAuthTicketForWebApi API of Steamworks SDK.
 * @member PSN_ID_TOKEN PlayStation(TM)Network ID Token Retrieved from the PlayStation(R) SDK. Please see first-party documentation for additional information. Supported with ${function.eos_auth_login}, ${function.eos_connect_login}.
 * @member XBL_XSTS_TOKEN Xbox Live XSTS Token Retrieved from the GDK and XDK. Please see first-party documentation for additional information. Supported with ${function.eos_auth_login}, ${function.eos_connect_login}.
 * @member DISCORD_ACCESS_TOKEN Discord Access Token Retrieved using the **GetOAuth2Token** API of Discord SDK. Supported with ${function.eos_auth_login}.
 * @member GOG_SESSION_TICKET GOG Galaxy Encrypted App Ticket Generated using the **RequestEncryptedAppTicket** API of GOG Galaxy SDK. The retrieved App is then passed into the ${function.eos_auth_login} API.
 * @member NINTENDO_ID_TOKEN Nintendo Account ID Token Identifies a Nintendo user account and is acquired through web flow authentication where the local user logs in using their email address/sign-in ID and password. This is the common Nintendo account that users login with outside the Nintendo Switch device. Supported with ${function.eos_auth_login}, ${function.eos_connect_login}.
 * @member NINTENDO_NSA_ID_TOKEN Nintendo Service Account ID Token (NSA ID) The NSA ID identifies uniquely the local Nintendo Switch device. The authentication token is acquired locally without explicit user credentials. As such, it is the primary authentication method for seamless login on Nintendo Switch. The NSA ID is not exposed directly to the user and does not provide any means for login outside the local device. Because of this, Nintendo Switch users will need to link their Nintendo Account or another external user account to their Product User ID in order to share their game progression across other platforms. Otherwise, the user will not be able to login to their existing Product User ID on another platform due to missing login credentials to use. It is recommended that the game explicitly communicates this restriction to the user so that they will know to add the first linked external account on the Nintendo Switch device and then proceed with login on another platform. In addition to sharing cross-platform game progression, linking the Nintendo Account or another external account will allow preserving the game progression permanently. Otherwise, the game progression will be tied only to the local device. In case the user loses access to their local device, they will not be able to recover the game progression if it is only associated with this account type. Supported with ${function.eos_auth_login}, ${function.eos_connect_login}.
 * @member UPLAY_ACCESS_TOKEN Uplay Access Token
 * @member OPENID_ACCESS_TOKEN OpenID Provider Access Token Supported with ${function.eos_connect_login}.
 * @member DEVICEID_ACCESS_TOKEN Device ID access token that identifies the current locally logged in user profile on the local device. The local user profile here refers to the operating system user login, for example the user's Windows Account or on a mobile device the default active user profile. This credential type is used to automatically login the local user using the EOS Connect Device ID feature. The intended use of the Device ID feature is to allow automatically logging in the user on a mobile device and to allow playing the game without requiring the user to necessarily login using a real user account at all. This makes a seamless first-time experience possible and allows linking the local device with a real external user account at a later time, sharing the same eos_product_user_id that is being used with the Device ID feature. Supported with ${function.eos_connect_login}.
 * @member APPLE_ID_TOKEN Apple ID Token; Supported with ${function.eos_connect_login}.
 * @member GOOGLE_ID_TOKEN Google ID Token; Supported with ${function.eos_connect_login}.
 * @member OCULUS_USERID_NONCE Oculus User ID and Nonce (call **ovr_User_GetUserProof** , to retrieve the nonce). Then pass the local User ID and the Nonce as a "{UserID}{Nonce}" formatted string for the ${function.eos_connect_login} Token parameter. Note that in order to successfully retrieve a valid non-zero ID for the local user using **ovr_User_GetUser** , your Oculus App needs to be configured in the Oculus Developer Dashboard to have the User ID feature enabled. Supported with ${function.eos_connect_login}.
 * @member ITCHIO_JWT itch.io JWT Access Token. Use the itch.io app manifest to receive a JWT access token for the local user via the ITCHIO_API_KEY process environment variable. The itch.io access token is valid for 7 days after which the game needs to be restarted by the user as otherwise EOS Connect authentication session can no longer be refreshed. Supported with ${function.eos_connect_login}.
 * @member ITCHIO_KEY itch.io Key Access Token. This access token type is retrieved through the OAuth 2.0 authentication flow for the itch.io application. Supported with ${function.eos_connect_login}.
 * @member EPIC_ID_TOKEN Epic Games ID Token. Acquired using ${function.eos_auth_copy_id_token} that returns **json_web_token**. Supported with ${function.eos_connect_login}.
 * @member AMAZON_ACCESS_TOKEN Amazon Access Token. Supported with ${function.eos_connect_login}.
 * @member VIVEPORT_USER_TOKEN VIVEPORT User Session Token
 * @constant_end
 */

/**
 * @constant EOS_LOGIN_CREDENTIAL_TYPE
 * @desc **Epic Online Services Enum:** [EOS_ELoginCredentialType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-login-credential-type)
 * 
 * This enum holds all possible types of login methods, availability depends on permissions granted to the client.
 * 
 * @member PASSWORD The argument to be passed in
 * @member EXCHANGE_CODE A short-lived one-time use exchange code to login the local user. When started, the application is expected to consume the exchange code by using the ${function.eos_auth_login} API as soon as possible. This is needed in order to authenticate the local user before the exchange code would expire. Attempting to consume an already expired exchange code will return `EOS_RESULT.AUTH_EXCHANGE_CODE_NOT_FOUND` error by the ${function.eos_auth_login} API.
 * @member PERSISTENT_AUTH Desktop and Mobile only; deprecated on Console platforms in favor of `EOS_LOGIN_CREDENTIAL_TYPE.EXTERNAL_AUTH` login method. Long-lived access token that is stored on the local device to allow persisting a user login session over multiple runs of the application. When using this login type, if an existing access token is not found or it is invalid or otherwise expired, the error result `EOS_RESULT.INVALID_AUTH` is returned. On Console platforms, after a successful login using the `EOS_LOGIN_CREDENTIAL_TYPE.DEVICE_CODE` login type, the persistent access token is retrieved using the ${function.eos_auth_copy_user_auth_token} API and stored by the application for the currently logged in user of the local device.
 * @member DEVICE_CODE Deprecated and no longer used.
 * @member DEVELOPER Login with named credentials hosted by the EOS SDK Developer Authentication Tool.
 * @member REFRESH_TOKEN Refresh token that was retrieved from a previous call to ${function.eos_auth_login} API in another local process context. Mainly used in conjunction with custom launcher applications. in-between that requires authenticating the user before eventually starting the actual game client application. In such scenario, an intermediate launcher will log in the user by consuming the exchange code it received from the Epic Games Launcher. To allow the game client to also authenticate the user, it can copy the refresh token using the ${function.eos_auth_copy_user_auth_token} API and pass it via launch parameters to the started game client. The game client can then use the refresh token to log in the user.
 * @member ACCOUNT_PORTAL Desktop and Mobile only. Initiate a login through the Epic account portal. for example when starting the application through a proprietary ecosystem launcher or otherwise.
 * @member EXTERNAL_AUTH Login using external account provider credentials, such as Steam, PlayStation(TM)Network, Xbox Live, or Nintendo. This is the intended login method on Console. On Desktop and Mobile, used when launched through any of the commonly supported platform clients (see the External Login Flow Guide on the ${page.logging_in} page for more details)
 * @constant_end
 */

/**
 * @constant EOS_LOGIN_STATUS
 * @desc **Epic Online Services Enum:** [EOS_ELoginStatus](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-login-status)
 * 
 * These constants are used to describe the Login status of a given account or connection and are returned by the following functions:
 * 
 * @member NOT_LOGGED_IN Player has not logged in or chosen a local profile
 * @member USING_LOCAL_PROFILE Player is using a local profile but is not logged in
 * @member LOGGED_IN Player has been validated by the platform-specific authentication service
 * @constant_end
 */

// Structs

/**
 * @struct AuthTokenInfo
 * @desc This struct contains detailed info on an access token used for authentication.
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {string} json_web_token The ID token as a JSON Web Token (JWT) string
 * @member {string} account_id The Epic Account ID associated with this auth token
 * @member {string} access_token Access token for the current user login session
 * @member {string} app Name of the app related to the client ID involved with this token
 * @member {real} auth_type Type of auth token (`EOS_AUTH_TOKEN_TYPE.CLIENT` or `EOS_AUTH_TOKEN_TYPE.USER`)
 * @member {string} client_id Client ID that requested this token
 * @member {string} expires_at Absolute time in UTC before the access token expires, in ISO 8601 format
 * @member {real} expires_in Time before the access token expires, in seconds, relative to the call to ${function.eos_auth_copy_user_auth_token}
 * @member {string} refresh_token Refresh token
 * @member {string} refresh_expires_at Absolute time in UTC before the refresh token expires, in ISO 8601 format
 * @member {real} refresh_expires_in Time before the access token expires, in seconds, relative to the call to ${function.eos_auth_copy_user_auth_token}
 * @struct_end
 */

/**
 * @struct IdWebTokenInfo
 * @desc This struct contains details on an ID Token in the form of a JSON Web Token string.
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {string} json_web_token The ID token as a JSON Web Token (JWT) string
 * @member {string} account_id The Epic Account ID described by the ID token
 * @struct_end
 */

/**
 * @module auth
 * @title Auth
 * @desc **Epic Online Services Interface:** [Auth Interface](https://dev.epicgames.com/docs/epic-account-services/auth-interface)
 * 
 * The Auth Interface lets players (users) log into their Epic Account from your game (product) so they can access the features provided by  **Epic Account Services** (EAS), such as Friends, Presence, UserInfo and Ecom interfaces. The **[Auth Interface](https://dev.epicgames.com/docs/epic-account-services/auth-interface)**  handles Epic account-related interactions with EOS, providing the ability to authenticate users and obtain access tokens.
 * 
 * @section Guides
 * @desc The following guides are available: 
 * @ref page.logging_in
 * @section_end
 * 
 * @section_func
 * @desc These functions are provided for handling authentication:
 * @ref eos_auth_add_notify_login_status_changed
 * @ref eos_auth_copy_id_token
 * @ref eos_auth_copy_user_auth_token
 * @ref eos_auth_delete_persistent_auth
 * @ref eos_auth_get_login_status
 * @ref eos_auth_get_selected_account_id
 * @ref eos_auth_link_account
 * @ref eos_auth_login
 * @ref eos_auth_logout
 * @ref eos_auth_query_id_token
 * @ref eos_auth_remove_notify_login_status_changed
 * @ref eos_auth_verify_id_token
 * @section_end
 * 
 * @section_const
 * @desc These are the constants used by this module:
 * @ref EOS_AUTH_SCOPE_FLAGS
 * @ref EOS_LOGIN_CREDENTIAL_TYPE
 * @ref EOS_EXTERNAL_CREDENTIAL_TYPE
 * @ref EOS_LOGIN_STATUS
 * @section_end
 * 
 * @section_struct
 * @desc These are the structs used by this module:
 * @ref AuthTokenInfo
 * @ref IdWebTokenInfo
 * @section_end
 * 
 * @module_end
 */
