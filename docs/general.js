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
 * @function eos_result_to_string
 * @desc This function returns a text representation of the status code passed to it.
 * 
 * @param {constant.EOS_RESULT} result The result code for which to get the text representation
 * 
 * @returns {string}
 * 
 * @function_end
 */

/**
 * @function eos_shutdown
 * @desc **Epic Online Services Function:** [EOS_Shutdown](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/NoInterface/EOS_Shutdown/index.html)
 * 
 * This function shuts down the Epic Online Services SDK. Once this function has been called, no more SDK calls are permitted.
 * Calling anything after ${function.eos_shutdown} will result in undefined behaviour. 
 * 
 * 1. `EOS_RESULT.SUCCESS` is the returned status if the SDK is successfully torn down.
 * 2. `EOS_RESULT.NOT_CONFIGURED` is returned status if the extension didn't initialise correctly.
 * 3. `EOS_RESULT.UNEXPECTED_ERROR` is returned status if ${function.eos_shutdown} has already been called.
 * 
 * 
 * [[Warning: This should be called at the end of your game.]]
 * 
 * @returns {struct.EpicResult}
 * 
 * @example
 * ```gml
 * var _struct = eos_shutdown();
 * if(_struct.status == EOS_RESULT.SUCCESS)
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
 * @constant.EOS_RESULT
 * @desc **Epic Online Services Enum:** [EOS_EResult](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-result)
 * 
 * This enum holds the available constants used as task results, for the entire API.
 * 
 * @member SUCCESS Successful result. no further error processing needed
 * @member NO_CONNECTION Failed due to no connection
 * @member INVALID_CREDENTIALS Failed login due to invalid credentials
 * @member INVALID_USER Failed due to invalid or missing user
 * @member INVALID_AUTH Failed due to invalid or missing authentication token for user (e.g. not logged in)
 * @member ACCESS_DENIED Failed due to invalid access
 * @member MISSING_PERMISSIONS If the client does not possess the permission required
 * @member TOKEN_NOT_ACCOUNT If the token provided does not represent an account
 * @member TOO_MANY_REQUESTS Throttled due to too many requests
 * @member ALREADY_PENDING Async request was already pending
 * @member INVALID_PARAMETERS Invalid parameters specified for request
 * @member INVALID_REQUEST Invalid request
 * @member UNRECOGNIZED_RESPONSE Failed due to unable to parse or recognize a backend response
 * @member INCOMPATIBLE_VERSION Incompatible client for backend version
 * @member NOT_CONFIGURED Not configured correctly for use
 * @member ALREADY_CONFIGURED Already configured for use.
 * @member NOT_IMPLEMENTED Feature not available on this implementation
 * @member CANCELED Operation was canceled (likely by user)
 * @member NOT_FOUND The requested information was not found
 * @member OPERATION_WILL_RETRY An error occurred during an asynchronous operation, and it will be retried. Callbacks receiving this result will be called again in the future.
 * @member NO_CHANGE The request had no effect
 * @member VERSION_MISMATCH The request attempted to use multiple or inconsistent API versions
 * @member LIMIT_EXCEEDED A maximum limit was exceeded on the client, different from `TooManyRequests`
 * @member DISABLED Feature or client ID performing the operation has been disabled.
 * @member DUPLICATE_NOT_ALLOWED Duplicate entry not allowed
 * @member INVALID_SANDBOX_ID Sandbox ID is invalid
 * @member TIMED_OUT Request timed out
 * @member PARTIAL_RESULT A query returned some but not all of the requested results.
 * @member MISSING_ROLE Client is missing the white-listed role
 * @member MISSING_FEATURE Client is missing the white-listed feature
 * @member INVALID_SANDBOX The sandbox given to the backend is invalid
 * @member INVALID_DEPLOYMENT The deployment given to the backend is invalid
 * @member INVALID_PRODUCT The product ID specified to the backend is invalid
 * @member INVALID_PRODUCT_USER_ID The product user ID specified to the backend is invalid
 * @member SERVICE_FAILURE There was a failure with the backend service
 * @member CACHE_DIRECTORY_MISSING Cache directory is not set in platform options.
 * @member CACHE_DIRECTORY_INVALID Cache directory is not accessible.
 * @member INVALID_STATE The request failed because resource was in an invalid state
 * @member REQUEST_IN_PROGRESS Request is in progress
 * @member APPLICATION_SUSPENDED Application is suspended
 * @member NETWORK_DISCONNECTED Network is disconnected
 * @member AUTH_ACCOUNT_LOCKED Account locked due to login failures
 * @member AUTH_ACCOUNT_LOCKED_FOR_UPDATE Account locked by update operation.
 * @member AUTH_INVALID_REFRESH_TOKEN Refresh token used was invalid
 * @member AUTH_INVALID_TOKEN Invalid access token, typically when switching between backend environments
 * @member AUTH_AUTHENTICATION_FAILURE Invalid bearer token
 * @member AUTH_INVALID_PLATFORM_TOKEN Invalid platform token
 * @member AUTH_WRONG_ACCOUNT Auth parameters are not associated with this account
 * @member AUTH_WRONG_CLIENT Auth parameters are not associated with this client
 * @member AUTH_FULL_ACCOUNT_REQUIRED Full account is required
 * @member AUTH_HEADLESS_ACCOUNT_REQUIRED Headless account is required
 * @member AUTH_PASSWORD_RESET_REQUIRED Password reset is required
 * @member AUTH_PASSWORD_CANNOT_BE_REUSED Password was previously used and cannot be reused
 * @member AUTH_EXPIRED Authorization code/exchange code has expired
 * @member AUTH_SCOPE_CONSENT_REQUIRED Consent has not been given by the user
 * @member AUTH_APPLICATION_NOT_FOUND The application has no profile on the backend
 * @member AUTH_SCOPE_NOT_FOUND The requested consent wasn't found on the backend
 * @member AUTH_ACCOUNT_FEATURE_RESTRICTED This account has been denied access to login
 * @member AUTH_PIN_GRANT_CODE Pin grant code initiated
 * @member AUTH_PIN_GRANT_EXPIRED Pin grant code attempt expired
 * @member AUTH_PIN_GRANT_PENDING Pin grant code attempt pending
 * @member AUTH_EXTERNALAUTHNOTLINKED External auth source did not yield an account
 * @member AUTH_EXTERNAL_AUTH_REVOKED External auth access revoked
 * @member AUTH_EXTERNAL_AUTH_INVALID External auth token cannot be interpreted
 * @member AUTH_EXTERNAL_AUTH_RESTRICTED External auth cannot be linked to his account due to restrictions
 * @member AUTH_EXTERNAL_AUTH_CANNOT_LOGIN External auth cannot be used for login
 * @member AUTH_EXTERNAL_AUTH_EXPIRED External auth is expired
 * @member AUTH_EXTERNAL_AUTH_IS_LAST_LOGIN_TYPE External auth cannot be removed since it's the last possible way to login
 * @member AUTH_EXCHANGE_CODE_NOT_FOUND Exchange code not found
 * @member AUTH_ORIGINATING_EXCHANGE_CODE_SESSION_EXPIRED Originating exchange code session has expired
 * @member AUTH_ACCOUNT_NOT_ACTIVE The account has been disabled and cannot be used for authentication
 * @member AUTH_MFA_REQUIRED MFA challenge required
 * @member AUTH_PARENTAL_CONTROLS Parental locks are in place
 * @member AUTH_NO_REAL_ID Korea real ID association required but missing
 * @member FRIENDS_INVITE_AWAITING_ACCEPTANCE An outgoing friend invitation is waiting acceptance; sending another invite to the same user is erroneous
 * @member FRIENDS_NO_INVITATION There is no friend invitation to accept/reject
 * @member FRIENDS_ALREADY_FRIENDS Users are already friends, so sending another invite is erroneous
 * @member FRIENDS_NOT_FRIENDS Users are not friends, so deleting the friend is erroneous
 * @member FRIENDS_TARGET_USER_TOO_MANY_INVITES Remote user has too many invites to receive new invites
 * @member FRIENDS_LOCAL_USER_TOO_MANY_INVITES Local user has too many invites to send new invites
 * @member FRIENDS_TARGET_USER_FRIEND_LIMIT_EXCEEDED Remote user has too many friends to make a new friendship
 * @member FRIENDS_LOCAL_USER_FRIEND_LIMIT_EXCEEDED Local user has too many friends to make a new friendship
 * @member PRESENCE_DATA_INVALID Request data was null or invalid
 * @member PRESENCE_DATALENGTHINVALID Request contained too many or too few unique data items, or the request would overflow the maximum amount of data allowed
 * @member PRESENCE_DATA_KEY_INVALID Request contained data with an invalid key
 * @member PRESENCE_DATA_KEY_LENGTH_INVALID Request contained data with a key too long or too short
 * @member PRESENCE_DATA_VALUE_INVALID Request contained data with an invalid value
 * @member PRESENCE_DATA_VALUE_LENGTH_INVALID Request contained data with a value too long
 * @member PRESENCE_RICH_TEXT_INVALID Request contained an invalid rich text string
 * @member PRESENCE_RICH_TEXT_LENGTH_INVALID Request contained a rich text string that was too long
 * @member PRESENCE_STATUS_INVALID Request contained an invalid status state
 * @member ECOM_ENTITLEMENT_STALE The entitlement retrieved is stale, re-query for updated information
 * @member ECOM_CATALOG_OFFER_STALE The offer retrieved is stale, re-query for updated information
 * @member ECOM_CATALOG_ITEM_STALE The item or associated structure retrieved is stale, re-query for updated information
 * @member ECOM_CATALOG_OFFER_PRICE_INVALID The one or more offers has an invalid price. This may be caused by the price setup.
 * @member ECOM_CHECKOUT_LOAD_ERROR The checkout page failed to load
 * @member ECOM_PURCHASE_PROCESSING The player closed the purchase flow overlay after clicking the purchase button. The purchase may still go through = and the game needs to query unredeemed entitlements for a short time.
 * @member SESSIONS_SESSION_IN_PROGRESS Session is already in progress
 * @member SESSIONS_TOO_MANY_PLAYERS Too many players to register with this session
 * @member SESSIONS_NO_PERMISSION Client has no permissions to access this session
 * @member SESSIONS_SESSION_ALREADY_EXISTS Session already exists in the system
 * @member SESSIONS_INVALID_LOCK Session lock required for operation
 * @member SESSIONS_INVALID_SESSION Invalid session reference
 * @member SESSIONS_SANDBOX_NOT_ALLOWED Sandbox ID associated with auth didn't match
 * @member SESSIONS_INVITE_FAILED Invite failed to send
 * @member SESSIONS_INVITE_NOT_FOUND Invite was not found with the service
 * @member SESSIONS_UPSERT_NOT_ALLOWED This client may not modify the session
 * @member SESSIONS_AGGREGATION_FAILED Backend nodes unavailable to process request
 * @member SESSIONS_HOST_AT_CAPACITY Individual backend node is as capacity
 * @member SESSIONS_SANDBOX_AT_CAPACITY Sandbox on node is at capacity
 * @member SESSIONS_SESSION_NOT_ANONYMOUS An anonymous operation was attempted on a non anonymous session
 * @member SESSIONS_OUT_OF_SYNC Session is currently out of sync with the backend, data is saved locally but needs to sync with backend
 * @member SESSIONS_TOO_MANY_INVITES User has received too many invites
 * @member SESSIONS_PRESENCE_SESSION_EXISTS Presence session already exists for the client
 * @member SESSIONS_DEPLOYMENT_AT_CAPACITY Deployment on node is at capacity
 * @member SESSIONS_NOT_ALLOWED Session operation not allowed
 * @member SESSIONS_PLAYER_SANCTIONED Session operation not allowed
 * @member PLAYER_DATA_STORAGE_FILENAME_INVALID Request filename was invalid
 * @member PLAYER_DATA_STORAGE_FILENAME_LENGTH_INVALID Request filename was too long
 * @member PLAYER_DATA_STORAGE_FILENAME_INVALID_CHARS Request filename contained invalid characters
 * @member PLAYER_DATA_STORAGE_FILESIZE_TOO_LARGE Request operation would grow file too large
 * @member PLAYER_DATA_STORAGE_FILE_SIZE_INVALID Request file length is not valid
 * @member PLAYER_DATA_STORAGE_FILE_HANDLE_INVALID Request file handle is not valid
 * @member PLAYER_DATA_STORAGE_DATA_INVALID Request data is invalid
 * @member PLAYER_DATA_STORAGE_DATA_LENGTH_INVALID Request data length was invalid
 * @member PLAYER_DATA_STORAGE_START_INDEX_INVALID Request start index was invalid
 * @member PLAYER_DATA_STORAGE_REQUEST_IN_PROGRESS Request is in progress
 * @member PLAYER_DATA_STORAGE_USER_THROTTLED User is marked as throttled which means he can't perform some operations because limits are exceeded.
 * @member PLAYER_DATA_STORAGE_ENCRYPTION_KEY_NOT_SET Encryption key is not set during SDK init.
 * @member PLAYER_DATA_STORAGE_USER_ERROR_FROM_DATA_CALLBACK User data callback returned error
 * @member PLAYER_DATA_STORAGE_FILE_HEADER_HAS_NEWER_VERSION User is trying to read file that has header from newer version of SDK. Game/SDK needs to be updated.
 * @member PLAYER_DATA_STORAGE_FILE_CORRUPTED The file is corrupted. In some cases retry can fix the issue.
 * @member CONNECT_EXTERNAL_TOKEN_VALIDATION_FAILED EOS Auth service deemed the external token invalid
 * @member CONNECT_USER_ALREADY_EXISTS EOS Auth user already exists
 * @member CONNECT_AUTH_EXPIRED EOS Auth expired
 * @member CONNECT_INVALID_TOKEN EOS Auth invalid token
 * @member CONNECT_UNSUPPORTED_TOKEN_TYPE EOS Auth doesn't support this token type
 * @member CONNECT_LINK_ACCOUNT_FAILED EOS Auth Account link failure
 * @member CONNECT_EXTERNAL_SERVICE_UNAVAILABLE EOS Auth External service for validation was unavailable
 * @member CONNECT_EXTERNAL_SERVICE_CONFIGURATION_FAILURE EOS Auth External Service configuration failure with Dev Portal
 * @member UI_SOCIAL_OVERLAY_LOAD_ERROR The social overlay page failed to load
 * @member UI_INCONSISTENT_VIRTUAL_MEMORY_FUNCTIONS Virtual Memory Functions are an inconsistent mix of functions and nullptrs
 * @member LOBBY_NOT_OWNER Client has no permissions to modify this lobby
 * @member LOBBY_INVALID_LOCK Lobby lock required for operation
 * @member LOBBY_LOBBY_ALREADY_EXISTS Lobby already exists in the system
 * @member LOBBY_SESSION_IN_PROGRESS Lobby is already in progress
 * @member LOBBY_TOO_MANY_PLAYERS Too many players to register with this lobby
 * @member LOBBY_NO_PERMISSION Client has no permissions to access this lobby
 * @member LOBBY_INVALID_SESSION Invalid lobby session reference
 * @member LOBBY_SANDBOX_NOT_ALLOWED Sandbox ID associated with auth didn't match
 * @member LOBBY_INVITE_FAILED Invite failed to send
 * @member LOBBY_INVITE_NOT_FOUND Invite was not found with the service
 * @member LOBBY_UPSERT_NOT_ALLOWED This client may not modify the lobby
 * @member LOBBY_AGGREGATION_FAILED Backend nodes unavailable to process request
 * @member LOBBY_HOST_AT_CAPACITY Individual backend node is at capacity
 * @member LOBBY_SANDBOX_AT_CAPACITY Sandbox on node is at capacity
 * @member LOBBY_TOO_MANY_INVITES User has received too many invites
 * @member LOBBY_DEPLOYMENT_AT_CAPACITY Deployment on node is at capacity
 * @member LOBBY_NOT_ALLOWED Lobby operation not allowed
 * @member LOBBY_MEMBER_UPDATE_ONLY While restoring a lost connection lobby ownership changed and only local member data was updated
 * @member LOBBY_PRESENCE_LOBBY_EXISTS Presence lobby already exists for the client
 * @member LOBBY_VOICE_NOT_ENABLED Operation requires lobby with voice enabled
 * @member LOBBY_PLATFORM_NOT_ALLOWED The client platform does not match the allowed platform list for the lobby.
 * @member TITLE_STORAGE_USER_ERROR_FROM_DATA_CALLBACK User callback that receives data from storage returned error.
 * @member TITLE_STORAGE_ENCRYPTION_KEY_NOT_SET User forgot to set Encryption key during platform init. Title Storage can't work without it.
 * @member TITLE_STORAGE_FILE_CORRUPTED Downloaded file is corrupted.
 * @member TITLE_STORAGE_FILE_HEADER_HAS_NEWER_VERSION Downloaded file's format is newer than client SDK version.
 * @member MODS_MOD_SDK_PROCESS_IS_ALREADY_RUNNING ModSdk process is already running. This error comes from the EOSSDK.
 * @member MODS_MOD_SDK_COMMAND_IS_EMPTY ModSdk command is empty. Either the ModSdk configuration file is missing or the manifest location is empty.
 * @member MODS_MOD_SDK_PROCESS_CREATION_FAILED Creation of the ModSdk process failed. This error comes from the SDK.
 * @member MODS_CRITICAL_ERROR A critical error occurred in the external ModSdk process that we were unable to resolve.
 * @member MODS_TOOL_INTERNAL_ERROR A internal error occurred in the external ModSdk process that we were unable to resolve.
 * @member MODS_IPC_FAILURE A IPC failure occurred in the external ModSdk process.
 * @member MODS_INVALID_IPC_RESPONSE A invalid IPC response received in the external ModSdk process.
 * @member MODS_URI_LAUNCH_FAILURE A URI Launch failure occurred in the external ModSdk process.
 * @member MODS_MOD_IS_NOT_INSTALLED Attempting to perform an action with a mod that is not installed. This error comes from the external ModSdk process.
 * @member MODS_USER_DOES_NOT_OWN_THEGAME Attempting to perform an action on a game that the user doesn't own. This error comes from the external ModSdk process.
 * @member MODS_OFFER_REQUEST_BY_ID_INVALID_RESULT Invalid result of the request to get the offer for the mod. This error comes from the external ModSdk process.
 * @member MODS_COULD_NOT_FIND_OFFER Could not find the offer for the mod. This error comes from the external ModSdk process.
 * @member MODS_OFFER_REQUEST_BY_ID_FAILURE Request to get the offer for the mod failed. This error comes from the external ModSdk process.
 * @member MODS_PURCHASE_FAILURE Request to purchase the mod failed. This error comes from the external ModSdk process.
 * @member MODS_INVALID_GAME_INSTALL_INFO Attempting to perform an action on a game that is not installed or is partially installed. This error comes from the external ModSdk process.
 * @member MODS_CANNOT_GET_MANIFEST_LOCATION Failed to get manifest location. Either the ModSdk configuration file is missing or the manifest location is empty
 * @member MODS_UNSUPPORTED_OS Attempting to perform an action with a mod that does not support the current operating system.
 * @member ANTICHEAT_CLIENT_PROTECTION_NOT_AVAILABLE The anti-cheat client protection is not available. Check that the game was started using the anti-cheat bootstrapper.
 * @member ANTICHEAT_INVALID_MODE The current anti-cheat mode is incorrect for using this API
 * @member ANTICHEAT_CLIENT_PRODUCTID_MISMATCH The ProductId provided to the anti-cheat client helper executable does not match what was used to initialize the EOS SDK
 * @member ANTICHEAT_CLIENT_SANDBOX_ID_MISMATCH The SandboxId provided to the anti-cheat client helper executable does not match what was used to initialize the EOS SDK
 * @member ANTICHEAT_PROTECT_MESSAGE_SESSION_KEY_REQUIRED (ProtectMessage/UnprotectMessage) No session key is available, but it is required to complete this operation
 * @member ANTICHEAT_PROTECT_MESSAGE_VALIDATION_FAILED (ProtectMessage/UnprotectMessage) Message integrity is invalid
 * @member ANTICHEAT_PROTECT_MESSAGE_INITIALIZATION_FAILED (ProtectMessage/UnprotectMessage) Initialization failed
 * @member ANTICHEAT_PEER_ALREADY_REGISTERED (RegisterPeer) Peer is already registered
 * @member ANTICHEAT_PEER_NOT_FOUND (UnregisterPeer) Peer does not exist
 * @member ANTICHEAT_PEER_NOT_PROTECTED (ReceiveMessageFromPeer) Invalid call: Peer is not protected
 * @member ANTICHEAT_CLIENT_DEPLOYMENT_ID_MISMATCH The DeploymentId provided to the anti-cheat client helper executable does not match what was used to initialize the EOS SDK
 * @member ANTICHEAT_DEVICE_ID_AUTH_IS_NOT_SUPPORTED EOS Connect DeviceID auth method is not supported for anti-cheat
 * @member RTC_TOO_MANY_PARTICIPANTS EOS RTC room cannot accept more participants
 * @member RTC_ROOM_ALREADY_EXISTS EOS RTC room already exists
 * @member RTC_USER_KICKED The user kicked out from the room
 * @member RTC_USER_BANNED The user is banned
 * @member RTC_ROOM_WAS_LEFT EOS RTC room was left successfully
 * @member RTC_RECONNECTION_TIME_GATE_EXPIRED Connection dropped due to long timeout
 * @member RTC_SHUTDOWN_INVOKED EOS RTC room was left due to platform release
 * @member RTC_USERIS_IN_BLOCKLIST EOS RTC operation failed because the user is in the local user's block list
 * @member PROGRESSION_SNAPSHOT_SNAPSHOT_ID_UNAVAILABLE The number of available Snapshot IDs have all been exhausted.
 * @member KWS__PARENT_EMAIL_MISSING The KWS user does not have a parental email associated with the account. The parent account was unlinked or deleted
 * @member KWS_USER_GRADUATED The KWS user is no longer a minor and trying to update the parent email
 * @member ANDROID__JAVA_VM_NOT_STORED EOS Android VM not stored
 * @member ANDROID_RESERVED_MUST_REFERENCE_LOCAL_VM EOS Android if Reserved is set it must reference stored VM
 * @member ANDROID_RESERVED_MUST_BE_NULL EOS Android Reserved must not be provided
 * @member PERMISSION_REQUIRED_PATCH_AVAILABLE Patch required before the user can use the privilege
 * @member PERMISSION_REQUIRED_SYSTEM_UPDATE System update required before the user can use the privilege
 * @member PERMISSION_AGE_RESTRICTION_FAILURE Parental control failure usually
 * @member PERMISSION_ACCOUNT_TYPE_FAILURE Premium Account Subscription required but not available
 * @member PERMISSION_CHAT_RESTRICTION User restricted from chat
 * @member PERMISSION_UGC_RESTRICTION User restricted from User Generated Content
 * @member PERMISSION_ONLINE_PLAY_RESTRICTED Online play is restricted
 * @member DESKTOP_CROSSPLAY_APPLICATION_NOT_BOOTSTRAPPED The application was not launched through the Bootstrapper. Desktop crossplay functionality is unavailable.
 * @member DESKTOP_CROSSPLAY_SERVICE_NOT_INSTALLED The redistributable service is not installed.
 * @member DESKTOP_CROSSPLAY_SERVICE_START_FAILED The desktop crossplay service failed to start.
 * @member DESKTOP_CROSSPLAY_SERVICE_NOT_RUNNING The desktop crossplay service is no longer running for an unknown reason.
 * @member CUSTOM_INVITES_INVITE_FAILED When sending the custom invite failed.
 * @member USER_INFO_BEST_DISPLAY_NAME_INDETERMINATE The best display name could not be safely determined.
 * @member CONSOLE_INIT_CACHE_STORAGE_SIZE_KB_NOT_MULTIPLE_OF_16 CacheStorageSizeKB must be a multiple of 16
 * @member CONSOLE_INIT_CACHE_STORAGE_SIZE_KB_BELOW_MINIMUM_SIZE CacheStorageSizeKB is less than the minimum allowed
 * @member CONSOLE_INIT_CACHE_STORAGE_SIZE_KB_EXCEEDS_MAXIMUM_SIZE CacheStorageSizeKB is greater than the maximum allowed (4000 MB)
 * @member CONSOLE_INIT_CACHE_STORAGE_INDEX_OUT_OF_RANGE CacheStorageIndex is out of its allowed range
 * @member UNEXPECTED_ERROR An unexpected error that we cannot identify has occurred
 * @constant_end
 */

/**
 * @constant EOS_COMPARISON_OP
 * @desc **Epic Online Services Enum:** [EOS_EComparisonOp](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-comparison-op)
 * 
 * @member EQUAL Value must equal the one stored on the lobby/session
 * @member NOT_EQUAL Value must not equal the one stored on the lobby/session
 * @member GREATER_THAN Value must be strictly greater than the one stored on the lobby/session
 * @member GREATER_THAN_OR_EQUAL Value must be greater than or equal to the one stored on the lobby/session
 * @member LESS_THAN Value must be strictly less than the one stored on the lobby/session
 * @member LESS_THAN_OR_EQUAL Value must be less than or equal to the one stored on the lobby/session
 * @member DISTANCE Prefer values nearest the one specified i.e. abs(SearchValue-SessionValue) closest to 0
 * @member ANY_OF Value stored on the lobby/session may be any from a specified list
 * @member NOT_ANY_OF Value stored on the lobby/session may NOT be any from a specified list
 * @member ONE_OF This one value is a part of a collection
 * @member NOT_ONE_OF This one value is NOT part of a collection
 * @member CONTAINS This value is a CASE SENSITIVE substring of an attribute stored on the lobby/session
 * 
 * @constant_end
 */

/**
 * @constant EOS_LOGGING_CATEGORY
 * @desc **Epic Online Services Enum:** [EOS_ELogCategory](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-log-category)
 * 
 * These constants represent the available logging categories.
 * 
 * @member CORE Low level logs unrelated to specific services
 * @member AUTH Logs related to the Auth service
 * @member FRIENDS Logs related to the Friends service
 * @member PRESENCE Logs related to the Presence service
 * @member USER_INFO Logs related to the UserInfo service
 * @member HTTP_SERIALIZATION Logs related to HTTP serialization
 * @member ECOM Logs related to the Ecommerce service
 * @member P2P Logs related to the P2P service
 * @member SESSIONS Logs related to the Sessions service
 * @member RATE_LIMITER Logs related to rate limiting
 * @member PLAYER_DATA_STORAGE Logs related to the PlayerDataStorage service
 * @member ANALYTICS Logs related to sdk analytics
 * @member MESSAGING Logs related to the messaging service
 * @member CONNECT Logs related to the Connect service
 * @member OVERLAY Logs related to the Overlay
 * @member ACHIEVEMENTS Logs related to the Achievements service
 * @member STATS Logs related to the Stats service
 * @member UI Logs related to the UI service
 * @member LOBBY Logs related to the lobby service
 * @member LEADERBOARDS Logs related to the Leaderboards service
 * @member KEYCHAIN Logs related to an internal Keychain feature that the authentication interfaces use
 * @member IDENTITY_PROVIDER Logs related to external identity providers
 * @member TITLE_STORAGE Logs related to Title Storage
 * @member MODS Logs related to the Mods service
 * @member ANTI_CHEAT Logs related to the Anti-Cheat service
 * @member REPORTS Logs related to reports client
 * @member SANCTIONS Logs related to the Sanctions service
 * @member PROGRESSION_SNAPSHOTS Logs related to the Progression Snapshot service
 * @member KWS Logs related to the Kids Web Services integration
 * @member RTC Logs related to the RTC API
 * @member RTCAdmin Logs related to the RTC Admin API
 * @member INVENTORY Logs related to the Inventory service
 * @member RECEIPT_VALIDATOR Logs related to the Receipt Validator API
 * @member CUSTOM_INVITES Logs related to the Custom Invites API
 * @member ALL_CATEGORIES Not a real log category. Used by ${function.eos_logging_set_log_level} to set the log level for all categories at the same time
 * @constant_end
 */

/**
 * @constant EOS_LOGGING_LEVEL
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

/**
 * @constant EOS_INVALID_NOTIFICATIONID
 * @desc This macro represents an invalid notification ID.
 * 
 * @member EOS_INVALID_NOTIFICATIONID 
 * 
 * @constant_end
 */

// Structs

/**
 * @struct EpicResult
 * @desc A struct containing a result's status code and its representation in text.
 * 
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
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
 * @ref eos_result_to_string
 * @ref eos_shutdown
 * 
 * @section_end
 * 
 * @section_const
 * @desc These are the constants used by this API:
 * 
 * @ref EOS_RESULT
 * @ref EOS_LOGGING_CATEGORY
 * @ref EOS_LOGGING_LEVEL
 * @ref EOS_INVALID_NOTIFICATIONID
 * @ref EOS_COMPARISON_OP
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
