// Functions


/**
 * @function eos_get_version
 * @desc **Epic Online Services Function:** [EOS_Friends_AcceptInvite](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Friends/EOS_Friends_AcceptInvite/index.html)
 * 
 * This function gets the version of the EOSSDK binary.
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * show_debug_message($"EpicOnlineServices Version: {eos_get_version()}");
 * ```
 * The above code shows an example of how the function should be used. The function ${function.eos_get_version} will return the current version of the SDK.
 * @function_end
 */

/**
 * @function eos_logging_set_log_level
 * @desc **Epic Online Services Function:** [EOS_Logging_SetLogLevel](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/NoInterface/EOS_Logging_SetLogLevel/index.html)
 * 
 * This function sets the logging level for the specified logging category.
 * 
 * [[Note: By default all log categories will callback for Warnings, Errors, and Fatals.]]
 * 
 * @param {constant.eos_logging_category} category The specific log category to configure. Use `EOS_LC_ALL_CATEGORIES` to configure all categories simultaneously to the same log level. Check the constants under ${constant.eos_logging_category}.
 * @param {constant.eos_logging_level} logLevel the log level to use for the log category. Check the constants under ${constant.eos_logging_level}.
 * 
 * @example
 * ```gml
 * eos_logging_set_log_level(EOS_LC_ALL_CATEGORIES, EOS_LOG_OFF);
 * ```
 * The above code shows an example of how the function should be used. This will turn off logging for all categories.
 * @function_end
 */

/**
 * @function eos_shutdown
 * @desc **Epic Online Services Function:** [EOS_Shutdown](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/NoInterface/EOS_Shutdown/index.html)
 * 
 * This function shuts down the Epic Online Services SDK. Once this function has been called, no more SDK calls are permitted.
 * Calling anything after ${function.eos_shutdown} will result in undefined behaviour. 
 * 
 * 1. `EOS_SUCCESS` is the returned status if the SDK is successfully torn down.
 * 2. `EOS_NOT_CONFIGURED` is returned status if the extension didn't initialise correctly.
 * 3. `EOS_UNEXPECTED_ERROR` is returned status if ${function.eos_shutdown} has already been called.
 * 
 * 
 * [[Warning: This should be called at the end of your game.]]
 * 
 * @returns {struct.EpicResult}
 * 
 * @example
 * ```gml
 * var _struct = eos_shutdown();
 * if(_struct.status == EOS_SUCCESS)
 * {
 *      show_debug_message("Shutdown Success");
 * }
 * else
 * {
 *      show_debug_message("Shutdown Failed");
 * }
 * ```
 * The above code shows an example of how the function should be used. This should be called at the end of your game.
 * @function_end
 */

// Constants

/**
 * @constant eos_result
 * @desc **Epic Online Services Enum:** [EOS_EResult](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-result)
 * 
 * These are all the available constants used as task results, for the entire API.
 * 
 * @member EOS_SUCCESS Successful result. no further error processing needed
 * @member EOS_NO_CONNECTION Failed due to no connection
 * @member EOS_INVALID_CREDENTIALS Failed login due to invalid credentials
 * @member EOS_INVALID_USER Failed due to invalid or missing user
 * @member EOS_INVALID_AUTH Failed due to invalid or missing authentication token for user (e.g. not logged in)
 * @member EOS_ACCESS_DENIED Failed due to invalid access
 * @member EOS_MISSING_PERMISSIONS If the client does not possess the permission required
 * @member EOS_TOKEN_NOT_ACCOUNT If the token provided does not represent an account
 * @member EOS_TOO_MANY_REQUESTS Throttled due to too many requests
 * @member EOS_ALREADY_PENDING Async request was already pending
 * @member EOS_INVALID_PARAMETERS Invalid parameters specified for request
 * @member EOS_INVALID_REQUEST Invalid request
 * @member EOS_UNRECOGNIZED_RESPONSE Failed due to unable to parse or recognize a backend response
 * @member EOS_INCOMPATIBLE_VERSION Incompatible client for backend version
 * @member EOS_NOT_CONFIGURED Not configured correctly for use
 * @member EOS_ALREADY_CONFIGURED Already configured for use.
 * @member EOS_NOT_IMPLEMENTED Feature not available on this implementation
 * @member EOS_CANCELED Operation was canceled (likely by user)
 * @member EOS_NOT_FOUND The requested information was not found
 * @member EOS_OPERATION_WILL_RETRY An error occurred during an asynchronous operation, and it will be retried. Callbacks receiving this result will be called again in the future.
 * @member EOS_NO_CHANGE The request had no effect
 * @member EOS_VERSION_MISMATCH The request attempted to use multiple or inconsistent API versions
 * @member EOS_LIMIT_EXCEEDED A maximum limit was exceeded on the client, different from `EOS_TOO_MANY_REQUESTS`
 * @member EOS_DISABLED Feature or client ID performing the operation has been disabled.
 * @member EOS_DUPLICATE_NOT_ALLOWED Duplicate entry not allowed
 * @member EOS_INVALID_SANDBOX_ID Sandbox ID is invalid
 * @member EOS_TIMED_OUT Request timed out
 * @member EOS_PARTIAL_RESULT A query returned some but not all of the requested results.
 * @member EOS_MISSING_ROLE Client is missing the white-listed role
 * @member EOS_MISSING_FEATURE Client is missing the white-listed feature
 * @member EOS_INVALID_SANDBOX The sandbox given to the backend is invalid
 * @member EOS_INVALID_DEPLOYMENT The deployment given to the backend is invalid
 * @member EOS_INVALID_PRODUCT The product ID specified to the backend is invalid
 * @member EOS_INVALID_PRODUCTUserID The product user ID specified to the backend is invalid
 * @member EOS_SERVICE_FAILURE There was a failure with the backend service
 * @member EOS_CACHE_DIRECTORY_MISSING Cache directory is not set in platform options.
 * @member EOS_CACHE_DIRECTORY_INVALID Cache directory is not accessible.
 * @member EOS_INVALID_STATE The request failed because resource was in an invalid state
 * @member EOS_REQUEST_IN_PROGRESS Request is in progress
 * @member EOS_AUTH_ACCOUNT_LOCKED Account locked due to login failures
 * @member EOS_AUTH_ACCOUNT_LOCKEDForUpdate Account locked by update operation.
 * @member EOS_AUTH_INVALID_REFRESH_TOKEN Refresh token used was invalid
 * @member EOS_AUTH_INVALID_TOKEN Invalid access token, typically when switching between backend environments
 * @member EOS_AUTH_AUTHENTICATION_FAILURE Invalid bearer token
 * @member EOS_AUTH_INVALID_PLATFORM_TOKEN Invalid platform token
 * @member EOS_AUTH_WRONG_ACCOUNT Auth parameters are not associated with this account
 * @member EOS_AUTH_WRONG_CLIENT Auth parameters are not associated with this client
 * @member EOS_AUTH_FULL_ACCOUNT_REQUIRED Full account is required
 * @member EOS_AUTH_HEADLESS_ACCOUNT_REQUIRED Headless account is required
 * @member EOS_AUTH_PASSWORD_RESET_REQUIRED Password reset is required
 * @member EOS_AUTH_PASSWORD_CANNOT_BE_REUSED Password was previously used and cannot be reused
 * @member EOS_AUTH_EXPIRED Authorization code/exchange code has expired
 * @member EOS_AUTH_SCOPE_CONSENT_REQUIRED Consent has not been given by the user
 * @member EOS_AUTH_APPLICATION_NOT_FOUND The application has no profile on the backend
 * @member EOS_AUTH_SCOPE_NOT_FOUND The requested consent wasn't found on the backend
 * @member EOS_AUTH_ACCOUNT_FEATURE_RESTRICTED This account has been denied access to login
 * @member EOS_AUTH_PIN_GRANT_CODE Pin grant code initiated
 * @member EOS_AUTH_PIN_GRANT_EXPIRED Pin grant code attempt expired
 * @member EOS_AUTH_PIN_GRANT_PENDING Pin grant code attempt pending
 * @member EOS_AUTH_EXTERNAL_AUTH_NOT_LINKED External auth source did not yield an account
 * @member EOS_AUTH_EXTERNAL_AUTH_REVOKED External auth access revoked
 * @member EOS_AUTH_EXTERNAL_AUTH_INVALID External auth token cannot be interpreted
 * @member EOS_AUTH_EXTERNAL_AUTH_RESTRICTED External auth cannot be linked to his account due to restrictions
 * @member EOS_AUTH_EXTERNAL_AUTH_CANNOT_LOGIN External auth cannot be used for login
 * @member EOS_AUTH_EXTERNAL_AUTH_EXPIRED External auth is expired
 * @member EOS_AUTH_EXTERNAL_AUTH_IS_LAST_LOGIN_TYPE External auth cannot be removed since it's the last possible way to login
 * @member EOS_AUTH_EXCHANGE_CODE_NOT_FOUND Exchange code not found
 * @member EOS_AUTH_ORIGINATING_EXCHANGE_CODE_SESSION_EXPIRED Originating exchange code session has expired
 * @member EOS_AUTH_PERSISTENT_AUTH_ACCOUNT_NOT_ACTIVE The account has been disabled and cannot be used for authentication
 * @member EOS_AUTH_M_F_A_REQUIRED MFA challenge required
 * @member EOS_AUTH_PARENTAL_CONTROLS Parental locks are in place
 * @member EOS_AUTH_NO_REAL_ID Korea real ID association required but missing
 * @member EOS_FRIENDS_INVITE_AWAITING_ACCEPTANCE An outgoing friend invitation is waiting acceptance; sending another invite to the same user is erroneous
 * @member EOS_FRIENDS_NO_INVITATION There is no friend invitation to accept/reject
 * @member EOS_FRIENDS_ALREADY_FRIENDS Users are already friends, so sending another invite is erroneous
 * @member EOS_FRIENDS_NOT_FRIENDS Users are not friends, so deleting the friend is erroneous
 * @member EOS_FRIENDS_TARGET_USER_TOO_MANY_INVITES Remote user has too many invites to receive new invites
 * @member EOS_FRIENDS_LOCAL_USER_TOO_MANY_INVITES Local user has too many invites to send new invites
 * @member EOS_FRIENDS_TARGET_USER_FRIEND_LIMIT_EXCEEDED Remote user has too many friends to make a new friendship
 * @member EOS_FRIENDS_LOCAL_USER_FRIEND_LIMIT_EXCEEDED Local user has too many friends to make a new friendship
 * @member EOS_PRESENCE_DATA_INVALID Request data was null or invalid
 * @member EOS_PRESENCE_DATA_LENGTH_INVALID Request contained too many or too few unique data items, or the request would overflow the maximum amount of data allowed
 * @member EOS_PRESENCE_DATA_KEY_INVALID Request contained data with an invalid key
 * @member EOS_PRESENCE_DATA_KEY_LENGTH_INVALID Request contained data with a key too long or too short
 * @member EOS_PRESENCE_DATA_VALUE_INVALID Request contained data with an invalid value
 * @member EOS_PRESENCE_DATA_VALUE_LENGTH_INVALID Request contained data with a value too long
 * @member EOS_PRESENCE_RICH_TEXT_INVALID Request contained an invalid rich text string
 * @member EOS_PRESENCE_RICH_TEXT_LENGTH_INVALID Request contained a rich text string that was too long
 * @member EOS_PRESENCE_STATUS_INVALID Request contained an invalid status state
 * @member EOS_ECOM_ENTITLEMENT_STALE The entitlement retrieved is stale, re-query for updated information
 * @member EOS_ECOM_CATALOG_OFFER_STALE The offer retrieved is stale, re-query for updated information
 * @member EOS_ECOM_CATALOG_ITEM_STALE The item or associated structure retrieved is stale, re-query for updated information
 * @member EOS_ECOM_CATALOG_OFFER_PRICE_INVALID The one or more offers has an invalid price. This may be caused by the price setup.
 * @member EOS_ECOM_CHECKOUT_LOAD_ERROR The checkout page failed to load
 * @member EOS_SESSIONS_SESSION_IN_PROGRESS Session is already in progress
 * @member EOS_SESSIONS_TOO_MANY_PLAYERS Too many players to register with this session
 * @member EOS_SESSIONS_NO_PERMISSION Client has no permissions to access this session
 * @member EOS_SESSIONS_SESSION_ALREADY_EXISTS Session already exists in the system
 * @member EOS_SESSIONS_INVALID_LOCK Session lock required for operation
 * @member EOS_SESSIONS_INVALID_SESSION Invalid session reference
 * @member EOS_SESSIONS_SANDBOX_NOT_ALLOWED Sandbox ID associated with auth didn't match
 * @member EOS_SESSIONS_INVITE_FAILED Invite failed to send
 * @member EOS_SESSIONS_INVITE_NOT_FOUND Invite was not found with the service
 * @member EOS_SESSIONS_UPSERT_NOT_ALLOWED This client may not modify the session
 * @member EOS_SESSIONS_AGGREGATION_FAILED Backend nodes unavailable to process request
 * @member EOS_SESSIONS_HOST_AT_CAPACITY Individual backend node is as capacity
 * @member EOS_SESSIONS_SANDBOX_AT_CAPACITY Sandbox on node is at capacity
 * @member EOS_SESSIONS_SESSION_NOT_ANONYMOUS An anonymous operation was attempted on a non anonymous session
 * @member EOS_SESSIONS_OUT_OF_SYNC Session is currently out of sync with the backend, data is saved locally but needs to sync with backend
 * @member EOS_SESSIONS_TOO_MANY_INVITES User has received too many invites
 * @member EOS_SESSIONS_PRESENCE_SESSION_EXISTS Presence session already exists for the client
 * @member EOS_SESSIONS_DEPLOYMENT_AT_CAPACITY Deployment on node is at capacity
 * @member EOS_SESSIONS_NOT_ALLOWED Session operation not allowed
 * @member eos_sessions_player_sanctioned Session operation not allowed
 * @member EOS_PLAYER_DATA_STORAGE_FILENAME_INVALID Request filename was invalid
 * @member EOS_PLAYER_DATA_STORAGE_FILENAME_LENGTH_INVALID Request filename was too long
 * @member EOS_PLAYER_DATA_STORAGE_FILENAME_INVALIDChars Request filename contained invalid characters
 * @member EOS_PLAYER_DATA_STORAGE_FILE_SIZE_TOO_LARGE Request operation would grow file too large
 * @member EOS_PLAYER_DATA_STORAGE_FILE_SIZE_INVALID Request file length is not valid
 * @member EOS_PLAYER_DATA_STORAGE_FILE_HANDLE_INVALID Request file handle is not valid
 * @member EOS_PLAYER_DATA_STORAGE_DATA_INVALID Request data is invalid
 * @member EOS_PLAYER_DATA_STORAGE_DATA_LENGTH_INVALID Request data length was invalid
 * @member EOS_PLAYER_DATA_STORAGE_START_INDEX_INVALID Request start index was invalid
 * @member EOS_PLAYER_DATA_STORAGE_REQUEST_IN_PROGRESS Request is in progress
 * @member EOS_PLAYER_DATA_STORAGE_USER_THROTTLED User is marked as throttled which means he can't perform some operations because limits are exceeded.
 * @member EOS_PLAYER_DATA_STORAGE_ENCRYPTION_KEY_NOT_SET Encryption key is not set during SDK init.
 * @member EOS_PLAYER_DATA_STORAGE_USER_ERROR_FROM_DATA_CALLBACK User data callback returned error (eos_player_data_storage_e_write_result::eos_w_r_fail_request or eos_player_data_storage_e_read_result::eos_r_r_fail_request)
 * @member EOS_PLAYER_DATA_STORAGE_FILE_HEADER_HAS_NEWER_VERSION User is trying to read file that has header from newer version of SDK. Game/SDK needs to be updated.
 * @member EOS_PLAYER_DATA_STORAGE_FILE_CORRUPTED The file is corrupted. In some cases retry can fix the issue.
 * @member EOS_CONNECT_EXTERNAL_TOKEN_VALIDATION_FAILED EOS Auth service deemed the external token invalid
 * @member EOS_CONNECT_USER_ALREADY_EXISTS EOS Auth user already exists
 * @member EOS_CONNECT_AUTH_EXPIRED EOS Auth expired
 * @member EOS_CONNECT_INVALID_TOKEN EOS Auth invalid token
 * @member EOS_CONNECT_UNSUPPORTED_TOKEN_TYPE EOS Auth doesn't support this token type
 * @member EOS_CONNECT_LINK_ACCOUNT_FAILED EOS Auth Account link failure
 * @member EOS_CONNECT_EXTERNAL_SERVICE_UNAVAILABLE EOS Auth External service for validation was unavailable
 * @member EOS_CONNECT_EXTERNAL_SERVICE_CONFIGURATION_FAILURE EOS Auth External Service configuration failure with Dev Portal
 * @member EOS_UI_SOCIAL_OVERLAY_LOAD_ERROR The social overlay page failed to load
 * @member EOS_LOBBY_NOT_OWNER Client has no permissions to modify this lobby
 * @member EOS_LOBBY_INVALID_LOCK Lobby lock required for operation
 * @member EOS_LOBBY_LOBBY_ALREADY_EXISTS Lobby already exists in the system
 * @member EOS_LOBBY_SESSION_IN_PROGRESS Lobby is already in progress
 * @member EOS_LOBBY_TOO_MANY_PLAYERS Too many players to register with this lobby
 * @member EOS_LOBBY_NO_PERMISSION Client has no permissions to access this lobby
 * @member EOS_LOBBY_INVALID_SESSION Invalid lobby session reference
 * @member EOS_LOBBY_SANDBOX_NOT_ALLOWED Sandbox ID associated with auth didn't match
 * @member EOS_LOBBY_INVITE_FAILED Invite failed to send
 * @member EOS_LOBBY_INVITE_NOT_FOUND Invite was not found with the service
 * @member EOS_LOBBY_UPSERT_NOT_ALLOWED This client may not modify the lobby
 * @member EOS_LOBBY_AGGREGATION_FAILED Backend nodes unavailable to process request
 * @member EOS_LOBBY_HOST_AT_CAPACITY Individual backend node is as capacity
 * @member EOS_LOBBY_SANDBOX_AT_CAPACITY Sandbox on node is at capacity
 * @member EOS_LOBBY_TOO_MANY_INVITES User has received too many invites
 * @member EOS_LOBBY_DEPLOYMENT_AT_CAPACITY Deployment on node is at capacity
 * @member EOS_LOBBY_NOT_ALLOWED Lobby operation not allowed
 * @member EOS_LOBBY_MEMBER_UPDATE_ONLY While restoring a lost connection lobby ownership changed and only local member data was updated
 * @member EOS_LOBBY_PRESENCE_LOBBY_EXISTS Presence lobby already exists for the client
 * @member EOS_TITLE_STORAGE_USER_ERROR_FROM_DATA_CALLBACK User callback that receives data from storage returned error.
 * @member EOS_TITLE_STORAGE_ENCRYPTION_KEY_NOT_SET User forgot to set Encryption key during platform init. Title Storage can't work without it.
 * @member EOS_TITLE_STORAGE_FILE_CORRUPTED Downloaded file is corrupted.
 * @member EOS_TITLE_STORAGE_FILE_HEADER_HAS_NEWER_VERSION Downloaded file's format is newer than client SDK version.
 * @member EOS_MODS_MOD_SDK_PROCESS_IS_ALREADY_RUNNING ModSdk process is already running. This error comes from the EOSSDK.
 * @member EOS_MODS_MOD_SDK_COMMAND_IS_EMPTY ModSdk command is empty. Either the ModSdk configuration file is missing or the manifest location is empty.
 * @member EOS_MODS_MOD_SDK_PROCESS_CREATION_FAILED Creation of the ModSdk process failed. This error comes from the SDK.
 * @member EOS_MODS_CRITICAL_ERROR A critical error occurred in the external ModSdk process that we were unable to resolve.
 * @member EOS_MODS_TOOL_INTERNAL_ERROR A internal error occurred in the external ModSdk process that we were unable to resolve.
 * @member EOS_MODS_I_P_C_FAILURE A IPC failure occurred in the external ModSdk process.
 * @member EOS_MODS_INVALID_I_P_C_RESPONSE A invalid IPC response received in the external ModSdk process.
 * @member EOS_MODS_U_R_I_LAUNCH_FAILURE A URI Launch failure occurred in the external ModSdk process.
 * @member EOS_MODS_MOD_IS_NOT_INSTALLED Attempting to perform an action with a mod that is not installed. This error comes from the external ModSdk process.
 * @member EOS_MODS_USER_DOES_NOT_OWN_THE_GAME Attempting to perform an action on a game that the user doesn't own. This error comes from the external ModSdk process.
 * @member EOS_MODS_OFFER_REQUEST_BY_ID_INVALID_RESULT Invalid result of the request to get the offer for the mod. This error comes from the external ModSdk process.
 * @member EOS_MODS_COULD_NOT_FIND_OFFER Could not find the offer for the mod. This error comes from the external ModSdk process.
 * @member EOS_MODS_OFFER_REQUEST_BY_ID_FAILURE Request to get the offer for the mod failed. This error comes from the external ModSdk process.
 * @member EOS_MODS_PURCHASE_FAILURE Request to purchase the mod failed. This error comes from the external ModSdk process.
 * @member EOS_MODS_INVALID_GAME_INSTALL_INFO Attempting to perform an action on a game that is not installed or is partially installed. This error comes from the external ModSdk process.
 * @member EOS_MODS_CANNOT_GET_MANIFEST_LOCATION Failed to get manifest location. Either the ModSdk configuration file is missing or the manifest location is empty
 * @member EOS_MODS_UNSUPPORTED_O_S Attempting to perform an action with a mod that does not support the current operating system.
 * @member EOS_ANTI_CHEAT_CLIENT_PROTECTION_NOT_AVAILABLE The anti-cheat client protection is not available. Check that the game was started using the anti-cheat bootstrapper.
 * @member EOS_ANTI_CHEAT_INVALID_MODE The current anti-cheat mode is incorrect for using this API
 * @member EOS_ANTI_CHEAT_CLIENT_PRODUCT_ID_MISMATCH The ProductId provided to the anti-cheat client helper executable does not match what was used to initialize the EOS SDK
 * @member EOS_ANTI_CHEAT_CLIENT_SANDBOX_ID_MISMATCH The SandboxId provided to the anti-cheat client helper executable does not match what was used to initialize the EOS SDK
 * @member EOS_ANTI_CHEAT_PROTECT_MESSAGE_SESSION_KEY_REQUIRED (ProtectMessage/UnprotectMessage) No session key is available, but it is required to complete this operation
 * @member EOS_ANTI_CHEAT_PROTECT_MESSAGE_VALIDATION_FAILED (ProtectMessage/UnprotectMessage) Message integrity is invalid
 * @member EOS_ANTI_CHEAT_PROTECT_MESSAGE_INITIALIZATION_FAILED (ProtectMessage/UnprotectMessage) Initialization failed
 * @member EOS_ANTI_CHEAT_PEER_ALREADY_REGISTERED (RegisterPeer) Peer is already registered
 * @member EOS_ANTI_CHEAT_PEER_NOT_FOUND (UnregisterPeer) Peer does not exist
 * @member EOS_ANTI_CHEAT_PEER_NOT_PROTECTED (ReceiveMessageFromPeer) Invalid call: Peer is not protected
 * @member EOS_ANTI_CHEAT_CLIENT_DEPLOYMENT_ID_MISMATCH The DeploymentId provided to the anti-cheat client helper executable does not match what was used to initialize the EOS SDK
 * @member EOS_ANTI_CHEAT_DEVICE_ID_AUTH_IS_NOT_SUPPORTED EOS Connect DeviceID auth method is not supported for anti-cheat
 * @member EOS_RTC_TOO_MANY_PARTICIPANTS EOS RTC room cannot accept more participants
 * @member EOS_RTC_ROOM_ALREADY_EXISTS EOS RTC room already exists
 * @member EOS_RTC_USER_KICKED The user kicked out from the room
 * @member EOS_RTC_USER_BANNED The user is banned
 * @member EOS_RTC_ROOM_WAS_LEFT EOS RTC room was left successfully
 * @member EOS_RTC_RECONNECTION_TIMEGATE_EXPIRED Connection dropped due to long timeout
 * @member EOS_PROGRESSION_SNAPSHOT_SNAPSHOT_ID_UNAVAILABLE The number of available Snapshot IDs have all been exhausted.
 * @member EOS_KWS_PARENT_EMAIL_MISSING The KWS user does not have a parental email associated with the account. The parent account was unlinked or deleted
 * @member EOS_KWS_USER_GRADUATED The KWS user is no longer a minor and trying to update the parent email
 * @member EOS_ANDROID_JAVA_V_M_NOT_STORED EOS Android VM not stored
 * @constant_end
 */

/**
 * @constant eos_logging_category
 * @desc **Epic Online Services Enum:** [EOS_ELogCategory](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-log-category)
 * 
 * These constants represent the available logging categories.
 * 
 * @member EOS_LC_CORE Low level logs unrelated to specific services
 * @member EOS_LC_AUTH Logs related to the Auth service
 * @member EOS_LC_FRIENDS Logs related to the Friends service
 * @member EOS_LC_PRESENCE Logs related to the Presence service
 * @member EOS_LC_USER_INFO Logs related to the UserInfo service
 * @member EOS_LC_HTTP_SERIALIZATION Logs related to HTTP serialization
 * @member EOS_LC_ECOM Logs related to the Ecommerce service
 * @member EOS_LC_P2P Logs related to the P2P service
 * @member EOS_LC_SESSIONS Logs related to the Sessions service
 * @member EOS_LC_RATE_LIMITER Logs related to rate limiting
 * @member EOS_LC_PLAYER_DATA_STORAGE Logs related to the PlayerDataStorage service
 * @member EOS_LC_ANALYTICS Logs related to sdk analytics
 * @member EOS_LC_MESSAGING Logs related to the messaging service
 * @member EOS_LC_CONNECT Logs related to the Connect service
 * @member EOS_LC_OVERLAY Logs related to the Overlay
 * @member EOS_LC_ACHIEVEMENTS Logs related to the Achievements service
 * @member EOS_LC_STATS Logs related to the Stats service
 * @member EOS_LC_UI Logs related to the UI service
 * @member EOS_LC_LOBBY Logs related to the lobby service
 * @member EOS_LC_LEADERBOARDS Logs related to the Leaderboards service
 * @member EOS_LC_KEYCHAIN Logs related to an internal Keychain feature that the authentication interfaces use
 * @member eos_l_c_identity_provider Logs related to external identity providers
 * @member EOS_LC_TITLE_STORAGE Logs related to Title Storage
 * @member EOS_LC_MODS Logs related to the Mods service
 * @member EOS_LC_ANTI_CHEAT Logs related to the Anti-Cheat service
 * @member EOS_LC_REPORTS Logs related to reports client
 * @member EOS_LC_SANCTIONS Logs related to the Sanctions service
 * @member EOS_LC_PROGRESSION_SNAPSHOTS Logs related to the Progression Snapshot service
 * @member EOS_LC_KWS Logs related to the Kids Web Services integration
 * @member EOS_LC_RTC Logs related to the RTC API
 * @member EOS_LC_RTCAdmin Logs related to the RTC Admin API
 * @member eos_l_c_inventory Logs related to the Inventory service
 * @member eos_l_c_receipt_validator Logs related to the Receipt Validator API
 * @member EOS_LC_CUSTOM_INVITES Logs related to the Custom Invites API
 * @member EOS_LC_ALL_CATEGORIES Not a real log category. Used by ${function.eos_logging_set_log_level} to set the log level for all categories at the same time
 * @constant_end
 */

/**
 * @constant eos_logging_level
 * @desc **Epic Online Services Enum:** [EOS_ELogLevel](https://dev.epicgames.com/docs/api-ref/enums/eos-e-log-level)
 * 
 * These constants represent the available logging levels. When a log message is output, it has an associated log level. Messages will only be sent to the callback function if the message is associated log level is less than or equal to the configured log level for that category.
 * 
 * @member EOS_LOG_OFF
 * @member EOS_LOG_FATAL
 * @member EOS_LOG_ERROR
 * @member EOS_LOG_WARNING
 * @member EOS_LOG_INFO
 * @member EOS_LOG_VERBOSE
 * @member EOS_LOG_VERY_VERBOSE
 * @constant_end
 */

// Structs

/**
 * @struct EpicResult
 * @desc A struct containing a result's status code and its representation in text.
 * 
 * @member {constant.eos_result} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code.
 * 
 * @struct_end
 */


/**
 * @module general
 * @title General
 * @desc This module provides miscellaneous/debug functions.
 * 
 * @section_func
 * @desc Provided functions:
 * 
 * @ref eos_get_version
 * @ref eos_logging_set_log_level
 * @ref eos_shutdown
 * 
 * @section_end
 * 
 * @section_const
 * @desc These are the constants used by this API:
 * 
 * @ref eos_result
 * @ref eos_logging_category
 * @ref eos_logging_level
 * 
 * @section_end
 * 
 * @section_struct
 * @desc These are the structs used this API:
 * 
 * @ref EpicResult
 * 
 * @section_end
 * 
 * @module_end
 */
