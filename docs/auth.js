// Functions

/**
 * @function EpicGames_Auth_AddNotifyLoginStatusChanged
 * @desc **Epic Online Services Function:** [EOS_Auth_AddNotifyLoginStatusChanged](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_AddNotifyLoginStatusChanged/index.html)
 * 
 * This function registers to receive login status updates.
 * 
 * @event social
 * @member {string} type The string `"EpicGames_Auth_AddNotifyLoginStatusChanged"`
 * @member {constant.EpicGames_Login_Status} CurrentStatus The status at the time of the notification
 * @member {constant.EpicGames_Login_Status} PrevStatus The status prior to the change
 * @event_end
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * identifier = EpicGames_Auth_AddNotifyLoginStatusChanged();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Auth_AddNotifyLoginStatusChanged")
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
 * @function EpicGames_Auth_CopyIdToken
 * @desc **Epic Online Services Function:** [EOS_Auth_CopyIdToken](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_CopyIdToken/index.html)
 * 
 * This function fetches an ID token for an Epic Account ID. ID tokens are used to securely verify user identities with online services. The most common use case is using an ID token to authenticate the local user by their selected account ID, which is the account ID that should be used to access any game-scoped data for the current application. An ID token for the selected account ID of a locally authenticated user will always be readily available. To retrieve it for the selected account ID, you can use ${function.EpicGames_Auth_CopyIdToken} directly after a successful user login.
 * 
 * @param {string} accountID The Epic Account ID of the user being queried.
 * 
 * @returns {struct.IdWebTokenInfo}
 * 
 * @example
 * ```gml
 * var _struct = EpicGames_Auth_CopyIdToken(accountID);
 * if(_struct.status == EpicGames_Success)
 * {
 *     JsonWebToken = _struct.JsonWebToken;
 * }
 * ```
 * The above code shows an example of how the function should be used. The token associated with the provided account ID is returned inside the struct, alongside other useful information.
 * @function_end
 */

/**
 * @function EpicGames_Auth_CopyUserAuthToken
 * @desc **Epic Online Services Function:** [EOS_Auth_CopyUserAuthToken](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_CopyUserAuthToken/index.html)
 * 
 * This function fetches a user auth token for an Epic Account ID. A user authentication token allows any code with possession (backend/client) to perform certain actions on behalf of the user. Because of this, for the purposes of user identity verification, the ${function.EpicGames_Auth_CopyIdToken} should be used instead.
 * @param {string} accountID The Epic Account ID of the user being queried
 * 
 * @returns {struct.AuthTokenInfo}
 * 
 * @example
 * ```gml
 * var _struct = EpicGames_Auth_CopyUserAuthToken(accountID);
 * if(_struct.status == EpicGames_Success)
 * {
 *      var _access_token = _struct.AccessToken;
 * }
 * ```
 * The above code shows an example of how the function should be used. The access token associated with the provided account ID is returned inside the struct alongside other useful information.
 * @function_end
 */

/**
 * @function EpicGames_Auth_DeletePersistentAuth
 * @desc **Epic Online Services Function:** [EOS_Auth_DeletePersistentAuth](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_DeletePersistentAuth/index.html)
 * 
 * This function deletes a previously received and locally stored persistent auth access token for the currently logged in user of the local device. On Desktop and Mobile platforms, the access token is deleted from the keychain of the local user and a backend request is made to revoke the token on the authentication server. On Console platforms, even though the caller is responsible for storing and deleting the access token on the local device, this function should still be called with the access token before its deletion to make the best effort in attempting to also revoke it on the authentication server. If the function would fail on Console, the caller should still proceed as normal to delete the access token locally as intended.
 * 
 * @param {string} refreshToken A long-lived refresh token that is used with the `EpicGames_LCT_PersistentAuth` login type and is to be revoked from the authentication server. Only used on Console platforms. On Desktop and Mobile platforms, set this parameter to `undefined`.
 * 
 * @example
 * ```gml
 * EpicGames_Auth_DeletePersistentAuth(refreshtoken);
 * ```
 * The above code shows an example of how the function should be used. The refresh token provided will be revoked and invalidated.
 * @function_end
 */

/**
 * @function EpicGames_Auth_GetLoginStatus
 * @desc **Epic Online Services Function:** [EOS_Auth_GetLoginStatus](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_GetLoginStatus/index.html)
 * 
 * This function fetches the EpicGames login status for an Epic Account ID.
 * 
 * @param {string} accountId The Epic Account ID of the user being queried
 * 
 * @returns {constant.EpicGames_Login_Status}
 * 
 * @example
 * ```gml
 * switch(EpicGames_Auth_GetLoginStatus(AccountID))
 * {
 *     case EpicGames_LS_NotLoggedIn:
 *         draw_text(100, 190, "LoginStatus: NotLoggedIn");
 *         break;
 * 
 *     case EpicGames_LS_UsingLocalProfile:
 *         draw_text(100, 190, "LoginStatus: UsingLocalProfile");
 *         break;
 * 
 *     case EpicGames_LS_LoggedIn:
 *         draw_text(100, 190, "LoginStatus: LoggedIn");
 *         break;
 * }
 * ```
 * The above code shows an example of how the function should be used. A login status constant is returned and checked against the provided built-in constants.
 * @function_end
 */

/**
 * @function EpicGames_Auth_GetSelectedAccountId
 * @desc **Epic Online Services Function:** [EOS_Auth_GetSelectedAccountId](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_GetSelectedAccountId/index.html)
 * 
 * This function fetches the selected account ID to the current application for a local authenticated user.
 * 
 * @param {string} account The selected account ID corresponding to the given account ID.
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * var _account_ID = EpicGames_Auth_GetSelectedAccountId(accountID);
 * ```
 * The above code shows an example of how the function should be used.
 * @function_end
 */

/**
 * @function EpicGames_Auth_LinkAccount
 * @desc **Epic Online Services Function:** [EOS_Auth_LinkAccount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_LinkAccount/index.html)
 * 
 * This function links an external account by continuing the previous login attempt with a continuance token. On Desktop and Mobile platforms, the user will be presented the Epic Account Portal to resolve their identity. On Console, the user will login to their Epic Account using an external device, e.g. a mobile device or a desktop PC, by browsing to the presented authentication URL and entering the device code presented by the game on the console. On success, the user will be logged in at the completion of this action. This will commit this external account to the Epic Account and cannot be undone in the SDK.
 * 
 * @param {string} accountID The Epic Account ID of the logged in local user whose Epic Account will be linked with the local Nintendo NSA ID Account. By default set to `undefined`.
 * @param {constant.EpicGames_Scope_Flags} scope_flags Combination of the enumeration flags to specify how the account linking operation will be performed.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_Auth_LinkAccount"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {string} AccountID The Epic Account ID used upon calling the function that generated this callback.
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * var _scope_flags = EpicGames_AS_BasicProfile | EpicGames_AS_FriendsList | EpicGames_AS_Presence;
 * identifier = EpicGames_Auth_Login(accountID, _scope_flags);
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Auth_LinkAccount")
 * if(async_load[? "identifier"] == identifier)
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
 * @function EpicGames_Auth_Login
 * @desc **Epic Online Services Function:** [EOS_Auth_Login](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_Login/index.html)
 * 
 * This function logs in / authenticates with user credentials.
 * 
 * [[Note: The permissions that you pass must correspond exactly to the ones you set in the [Developer Portal](https://dev.epicgames.com/docs/dev-portal). See [Permissions](https://dev.epicgames.com/docs/epic-account-services/getting-started#permissions).]]
 * 
 * @param {constant.EpicGames_Login_Credential_Type} type Type of login. Needed to identify the auth method to use.
 * @param {constant.EpicGames_Scope_Flags} scope_flags Auth scope flags are permissions to request from the user while they are logging in. This is a bitwise-or union (pipe symbol `|`) of ${constant.EpicGames_Scope_Flags}). These must correspond exactly to the ones you set in the [Developer Portal](https://dev.epicgames.com/docs/dev-portal)
 * @param {string} id ID of the user logging in, based on ${constant.EpicGames_Login_Credential_Type}
 * @param {string} token Credentials or token related to the user logging in
 * @param {constant.EpicGames_External_Credential_Type} external_type Type of external login. Needed to identify the external auth method to use. Used when login type is set to `EpicGames_LCT_ExternalAuth`, ignored otherwise (see the External Login Flow Guide on the ${page.logging_in} page for more details). Note that you must still pass a value for this parameter when not using an external auth method.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_Auth_Login"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @member {string} AccountID The Epic Account ID of the local user who has logged in
 * @member {string} [SelectedAccountId] The Epic Account ID that has been previously selected to be used for the current application. Applications should use this ID to authenticate with online backend services that store game-scoped data for users. Only when status is success
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_Auth_Login(
 *                 EpicGames_LCT_ExchangeCode,
 *                 EpicGames_AS_BasicProfile | EpicGames_AS_FriendsList | EpicGames_AS_Presence,
 *                 "",
 *                 code,
 *                 -1);
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Auth_Login")
 * if(async_load[? "identifier"] == identifier)
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
 * @function EpicGames_Auth_Logout
 * @desc **Epic Online Services Function:** [EOS_Auth_Logout](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_Logout/index.html)
 * 
 * This function signs the player out of the online service.
 * 
 * @param {string} accountID The Epic Account ID of the local user who is being logged out
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_Auth_Logout"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_Auth_Logout(accountID);
 * ```
 * The code sample above save the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Auth_Logout")
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
 * @function EpicGames_Auth_QueryIdToken
 * @desc **Epic Online Services Function:** [EOS_Auth_QueryIdToken](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_QueryIdToken/index.html)
 * 
 * This function queries the backend for an ID token that describes one of the merged account IDs of a local authenticated user. The ID token can be used to impersonate a merged account ID when communicating with online services. An ID token for the selected account ID of a locally authenticated user will always be readily available and does not need to be queried explicitly.
 * 
 * @param {string} accountID The Epic Account ID of the local authenticated user.
 * @param {string} accountID_target The target Epic Account ID for which to query an ID token. This account ID may be the same as the input LocalUserId or another merged account ID associated with the local user's Epic account. An ID token for the selected account ID of a locally authenticated user will always be readily available. To retrieve it for the selected account ID, you can use ${function.EpicGames_Auth_CopyIdToken} directly after a successful user login.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_Auth_QueryIdToken"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 *
 * @example
 * 
 * ```gml
 * identifier = EpicGames_Auth_QueryIdToken(accountID, accountID);
 * ```
 * The code sample above save the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Auth_QueryIdToken")
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
 * @function EpicGames_Auth_RemoveNotifyLoginStatusChanged
 * @desc **Epic Online Services Function:** [EOS_Auth_RemoveNotifyLoginStatusChanged](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_RemoveNotifyLoginStatusChanged/index.html)
 * 
 * This function unregisters from receiving login status updates.
 * 
 * @param {real} id handle ID representing the registered callback (from ${function.EpicGames_Auth_AddNotifyLoginStatusChanged})
 * 
 * @example
 * ```gml
 * var _handle = EpicGames_Auth_AddNotifyLoginStatusChanged();
 * //...
 * //...later
 * //...
 * EpicGames_Auth_RemoveNotifyLoginStatusChanged(_handle);
 * ```
 * The code sample above enables the login status notifications (${function.EpicGames_Auth_AddNotifyLoginStatusChanged}) and later disables them by refering to the previously generated handle.
 * @function_end
 */

/**
 * @function EpicGames_Auth_VerifyIdToken
 * @desc **Epic Online Services Function:** [EOS_Auth_VerifyIdToken](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Auth/EOS_Auth_VerifyIdToken/index.html)
 * 
 * This function verifies a given ID token for authenticity and validity.
 * 
 * @param {string} accountID The Epic Account ID of the local user who is being verified
 * @param {string} JsonWebToken The ID token to verify.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_Auth_VerifyIdToken"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_Auth_VerifyIdToken(accountID, JsonWebToken);
 * ```
 * The code sample above keeps a handle that can be used inside a ${event.social}.
 * 
 * ```gml
 * if(async_load[? "type"] == "EpicGames_Auth_VerifyIdToken")
 * if(async_load[? "identifier"] == identifier)
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

// Constants

/**
 * @constant EpicGames_Scope_Flags
 * @desc **Epic Online Services Enum:** [EOS_EAuthScopeFlags](https://dev.epicgames.com/docs/api-ref/enums/eos-e-auth-scope-flags)
 * 
 * List of the supported scope flags associated with the login API calls:
 * 
 * @member EpicGames_AS_NoFlags
 * @member EpicGames_AS_BasicProfile Permissions to see your account ID, display name, language and count
 * @member EpicGames_AS_FriendsList Permissions to see a list of your friends who use this application
 * @member EpicGames_AS_Presence Permissions to set your online presence and see presence of your friend
 * @member EpicGames_AS_FriendsManagement Permissions to manage the Epic friends list. This scope is restricted to Epic first party products, and attempting to use it will result in authentication failure.
 * @member EpicGames_AS_Email Permissions to see email in the response when fetching information for a user. This scope is restricted to Epic first party products, and attempting to use it will result in authentication failure.
 * @member EpicGames_AS_Country Permissions to see your country
 * @constant_end
 */

/**
 * @constant EpicGames_External_Credential_Type
 * @desc **Epic Online Services Constant:** [EOS_EExternalCredentialType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-external-credential-type)
 * 
 * List of the supported identity providers to authenticate a user. The type of authentication token is specific to each provider. Tokens in string format should be passed as-is to the function.
 * 
 * @member EpicGames_ECT_EPIC Epic Account Services Token Using ID Token is preferred, retrieved with ${function.EpicGames_Auth_CopyIdToken} that returns **JsonWebToken**. Using Auth Token is supported for backwards compatibility, retrieved with ${function.EpicGames_Auth_CopyUserAuthToken} that returns **AccessToken**. Supported with ${function.EpicGames_Connect_Login}.
 * @member EpicGames_ECT_STEAM_APP_TICKET Steam Encrypted App Ticket Generated using the **RequestEncryptedAppTicket** API of Steamworks SDK. The retrieved App is then passed into the ${function.EpicGames_Auth_Login} or ${function.EpicGames_Connect_Login} APIs.
 * @member EpicGames_ECT_STEAM_SESSION_TICKET Steam Auth Session Ticket generated using the ISteamUser::GetAuthTicketForWebApi API of Steamworks SDK.
 * @member EpicGames_ECT_PSN_ID_TOKEN PlayStation(TM)Network ID Token Retrieved from the PlayStation(R) SDK. Please see first-party documentation for additional information. Supported with ${function.EpicGames_Auth_Login}, ${function.EpicGames_Connect_Login}.
 * @member EpicGames_ECT_XBL_XSTS_TOKEN Xbox Live XSTS Token Retrieved from the GDK and XDK. Please see first-party documentation for additional information. Supported with ${function.EpicGames_Auth_Login}, ${function.EpicGames_Connect_Login}.
 * @member EpicGames_ECT_DISCORD_ACCESS_TOKEN Discord Access Token Retrieved using the **GetOAuth2Token** API of Discord SDK. Supported with ${function.EpicGames_Auth_Login}.
 * @member EpicGames_ECT_GOG_SESSION_TICKET GOG Galaxy Encrypted App Ticket Generated using the **RequestEncryptedAppTicket** API of GOG Galaxy SDK. The retrieved App is then passed into the ${function.EpicGames_Auth_Login} API.
 * @member EpicGames_ECT_NINTENDO_ID_TOKEN Nintendo Account ID Token Identifies a Nintendo user account and is acquired through web flow authentication where the local user logs in using their email address/sign-in ID and password. This is the common Nintendo account that users login with outside the Nintendo Switch device. Supported with ${function.EpicGames_Auth_Login}, ${function.EpicGames_Connect_Login}.
 * @member EpicGames_ECT_NINTENDO_NSA_ID_TOKEN Nintendo Service Account ID Token (NSA ID) The NSA ID identifies uniquely the local Nintendo Switch device. The authentication token is acquired locally without explicit user credentials. As such, it is the primary authentication method for seamless login on Nintendo Switch. The NSA ID is not exposed directly to the user and does not provide any means for login outside the local device. Because of this, Nintendo Switch users will need to link their Nintendo Account or another external user account to their Product User ID in order to share their game progression across other platforms. Otherwise, the user will not be able to login to their existing Product User ID on another platform due to missing login credentials to use. It is recommended that the game explicitly communicates this restriction to the user so that they will know to add the first linked external account on the Nintendo Switch device and then proceed with login on another platform. In addition to sharing cross-platform game progression, linking the Nintendo Account or another external account will allow preserving the game progression permanently. Otherwise, the game progression will be tied only to the local device. In case the user loses access to their local device, they will not be able to recover the game progression if it is only associated with this account type. Supported with ${function.EpicGames_Auth_Login}, ${function.EpicGames_Connect_Login}.
 * @member EpicGames_ECT_UPLAY_ACCESS_TOKEN Uplay Access Token
 * @member EpicGames_ECT_OPENID_ACCESS_TOKEN OpenID Provider Access Token Supported with ${function.EpicGames_Connect_Login}.
 * @member EpicGames_ECT_DEVICEID_ACCESS_TOKEN Device ID access token that identifies the current locally logged in user profile on the local device. The local user profile here refers to the operating system user login, for example the user's Windows Account or on a mobile device the default active user profile. This credential type is used to automatically login the local user using the EOS Connect Device ID feature. The intended use of the Device ID feature is to allow automatically logging in the user on a mobile device and to allow playing the game without requiring the user to necessarily login using a real user account at all. This makes a seamless first-time experience possible and allows linking the local device with a real external user account at a later time, sharing the same EpicGames_ProductUserId that is being used with the Device ID feature. Supported with ${function.EpicGames_Connect_Login}.
 * @member EpicGames_ECT_APPLE_ID_TOKEN Apple ID Token; Supported with ${function.EpicGames_Connect_Login}.
 * @member EpicGames_ECT_GOOGLE_ID_TOKEN Google ID Token; Supported with ${function.EpicGames_Connect_Login}.
 * @member EpicGames_ECT_OCULUS_USERID_NONCE Oculus User ID and Nonce (call **ovr_User_GetUserProof** , to retrieve the nonce). Then pass the local User ID and the Nonce as a "{UserID}{Nonce}" formatted string for the ${function.EpicGames_Connect_Login} Token parameter. Note that in order to successfully retrieve a valid non-zero ID for the local user using **ovr_User_GetUser** , your Oculus App needs to be configured in the Oculus Developer Dashboard to have the User ID feature enabled. Supported with ${function.EpicGames_Connect_Login}.
 * @member EpicGames_ECT_ITCHIO_JWT itch.io JWT Access Token. Use the itch.io app manifest to receive a JWT access token for the local user via the ITCHIO_API_KEY process environment variable. The itch.io access token is valid for 7 days after which the game needs to be restarted by the user as otherwise EOS Connect authentication session can no longer be refreshed. Supported with ${function.EpicGames_Connect_Login}.
 * @member EpicGames_ECT_ITCHIO_KEY itch.io Key Access Token. This access token type is retrieved through the OAuth 2.0 authentication flow for the itch.io application. Supported with ${function.EpicGames_Connect_Login}.
 * @member EpicGames_ECT_EPIC_ID_TOKEN Epic Games ID Token. Acquired using ${function.EpicGames_Auth_CopyIdToken} that returns **JsonWebToken**. Supported with ${function.EpicGames_Connect_Login}.
 * @member EpicGames_ECT_AMAZON_ACCESS_TOKEN Amazon Access Token. Supported with ${function.EpicGames_Connect_Login}.
 * @constant_end
 */

/**
 * @constant EpicGames_Login_Credential_Type
 * @desc **Epic Online Services Enum:** [EOS_ELoginCredentialType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-login-credential-type)
 * 
 * These constants represent all possible types of login methods, availability depends on permissions granted to the client.
 * 
 * @member EpicGames_LCT_Password The argument to be passed in
 * @member EpicGames_LCT_ExchangeCode A short-lived one-time use exchange code to login the local user. When started, the application is expected to consume the exchange code by using the ${function.EpicGames_Auth_Login} API as soon as possible. This is needed in order to authenticate the local user before the exchange code would expire. Attempting to consume an already expired exchange code will return `AuthExchangeCodeNotFound` error by the ${function.EpicGames_Auth_Login} API.
 * @member EpicGames_LCT_PersistentAuth Desktop and Mobile only; deprecated on Console platforms in favor of EOS_LCT_ExternalAuth login method. Long-lived access token that is stored on the local device to allow persisting a user login session over multiple runs of the application. When using this login type, if an existing access token is not found or it is invalid or otherwise expired, the error result `EpicGames_InvalidAuth` is returned. On Console platforms, after a successful login using the `EOS_LCT_DeviceCode` login type, the persistent access token is retrieved using the ${function.EpicGames_Auth_CopyUserAuthToken} API and stored by the application for the currently logged in user of the local device.
 * @member EpicGames_LCT_DeviceCode Deprecated and no longer used.
 * @member EpicGames_LCT_Developer Login with named credentials hosted by the EOS SDK Developer Authentication Tool.
 * @member EpicGames_LCT_RefreshToken Refresh token that was retrieved from a previous call to ${function.EpicGames_Auth_Login} API in another local process context. Mainly used in conjunction with custom launcher applications. in-between that requires authenticating the user before eventually starting the actual game client application. In such scenario, an intermediate launcher will log in the user by consuming the exchange code it received from the Epic Games Launcher. To allow the game client to also authenticate the user, it can copy the refresh token using the ${function.EpicGames_Auth_CopyUserAuthToken} API and pass it via launch parameters to the started game client. The game client can then use the refresh token to log in the user.
 * @member EpicGames_LCT_AccountPortal Desktop and Mobile only. Initiate a login through the Epic account portal. for example when starting the application through a proprietary ecosystem launcher or otherwise.
 * @member EpicGames_LCT_ExternalAuth Login using external account provider credentials, such as Steam, PlayStation(TM)Network, Xbox Live, or Nintendo. This is the intended login method on Console. On Desktop and Mobile, used when launched through any of the commonly supported platform clients (see the External Login Flow Guide on the  ${page.logging_in} page for more details)
 * @constant_end
 */

/**
 * @constant EpicGames_Login_Status
 * @desc **Epic Online Services Enum:** [EOS_ELoginStatus](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-login-status)
 * 
 * These constants are used to describe the Login status of a given account or connection and are returned by the following functions:
 * 
 * @member EpicGames_LS_NotLoggedIn Player has not logged in or chosen a local profile
 * @member EpicGames_LS_UsingLocalProfile Player is using a local profile but is not logged in
 * @member EpicGames_LS_LoggedIn Player has been validated by the platform-specific authentication service
 * @constant_end
 */

// Structs

/**
 * @struct AuthTokenInfo
 * @desc This struct contains detailed info on an access token used for authentication.
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {string} JsonWebToken The ID token as a JSON Web Token (JWT) string
 * @member {string} AccountId The Epic Account ID associated with this auth token
 * @member {string} AccessToken Access token for the current user login session
 * @member {string} App Name of the app related to the client ID involved with this token
 * @member {real} AuthType Type of auth token (`EpicGames_ATT_Client` or `EpicGames_ATT_User`)
 * @member {string} ClientId Client ID that requested this token
 * @member {string} ExpiresAt Absolute time in UTC before the access token expires, in ISO 8601 format
 * @member {real} ExpiresIn Time before the access token expires, in seconds, relative to the call to ${function.EpicGames_Auth_CopyUserAuthToken}
 * @member {string} RefreshToken Refresh token.
 * @member {string} RefreshExpiresAt Absolute time in UTC before the refresh token expires, in ISO 8601 format
 * @member {real} RefreshExpiresIn Time before the access token expires, in seconds, relative to the call to ${function.EpicGames_Auth_CopyUserAuthToken}
 * @struct_end
 */

/**
 * @struct IdWebTokenInfo
 * @desc This struct contains details on an ID Token in the form of a JSON Web Token string.
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {string} JsonWebToken The ID token as a JSON Web Token (JWT) string.
 * @member {string} AccountId The Epic Account ID described by the ID token. Use EpicGames_EpicAccountId_FromString to populate this field when validating a received ID token.
 * @struct_end
 */

/**
 * @module auth
 * @title Auth
 * @desc **Epic Online Services Interface:** [Auth Interface](https://dev.epicgames.com/docs/epic-account-services/auth-interface)
 * 
 * The Auth Interface lets players (users) log into their Epic Account from your game (product) so they can access the features provided by  **Epic Account Services** (EAS), such as Friends, Presence, UserInfo and Ecom interfaces. The  **[Auth Interface](https://dev.epicgames.com/docs/epic-account-services/auth-interface)**  handles Epic account-related interactions with EOS, providing the ability to authenticate users and obtain access tokens.
 * 
 * @section Guides
 * @desc The following guides are available: 
 * @ref page.logging_in
 * @section_end
 * 
 * @section_func
 * @desc These functions are provided for handling authentication:
 * @ref EpicGames_Auth_AddNotifyLoginStatusChanged
 * @ref EpicGames_Auth_CopyIdToken
 * @ref EpicGames_Auth_CopyUserAuthToken
 * @ref EpicGames_Auth_DeletePersistentAuth
 * @ref EpicGames_Auth_GetLoginStatus
 * @ref EpicGames_Auth_GetSelectedAccountId
 * @ref EpicGames_Auth_LinkAccount
 * @ref EpicGames_Auth_Login
 * @ref EpicGames_Auth_Logout
 * @ref EpicGames_Auth_QueryIdToken
 * @ref EpicGames_Auth_RemoveNotifyLoginStatusChanged
 * @ref EpicGames_Auth_VerifyIdToken
 * @section_end
 * 
 * @section_const
 * @desc These are the constants used by this module:
 * @ref EpicGames_Scope_Flags
 * @ref EpicGames_Login_Credential_Type
 * @ref EpicGames_External_Credential_Type
 * @ref EpicGames_Login_Status
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
