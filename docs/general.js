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
 * @param {constant.EOS_Result} result The result code for which to get the text representation
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
 * @constant EOS_Result
 * @desc **Epic Online Services Enum:** [EOS_EResult](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-result)
 * 
 * This enum holds the available constants used as task results, for the entire API.
 * 
 * @member Success Successful result. no further error processing needed
 * @member NoConnection Failed due to no connection
 * @member InvalidCredentials Failed login due to invalid credentials
 * @member InvalidUser Failed due to invalid or missing user
 * @member InvalidAuth Failed due to invalid or missing authentication token for user (e.g. not logged in)
 * @member AccessDenied Failed due to invalid access
 * @member MissingPermissions If the client does not possess the permission required
 * @member Token_Not_Account If the token provided does not represent an account
 * @member TooManyRequests Throttled due to too many requests
 * @member AlreadyPending Async request was already pending
 * @member InvalidParameters Invalid parameters specified for request
 * @member InvalidRequest Invalid request
 * @member UnrecognizedResponse Failed due to unable to parse or recognize a backend response
 * @member IncompatibleVersion Incompatible client for backend version
 * @member NotConfigured Not configured correctly for use
 * @member AlreadyConfigured Already configured for use.
 * @member NotImplemented Feature not available on this implementation
 * @member Canceled Operation was canceled (likely by user)
 * @member NotFound The requested information was not found
 * @member OperationWillRetry An error occurred during an asynchronous operation, and it will be retried. Callbacks receiving this result will be called again in the future.
 * @member NoChange The request had no effect
 * @member VersionMismatch The request attempted to use multiple or inconsistent API versions
 * @member LimitExceeded A maximum limit was exceeded on the client, different from `TooManyRequests`
 * @member Disabled Feature or client ID performing the operation has been disabled.
 * @member DuplicateNotAllowed Duplicate entry not allowed
 * @member InvalidSandboxId Sandbox ID is invalid
 * @member TimedOut Request timed out
 * @member PartialResult A query returned some but not all of the requested results.
 * @member MissingRole Client is missing the white-listed role
 * @member MissingFeature Client is missing the white-listed feature
 * @member Invalid_Sandbox The sandbox given to the backend is invalid
 * @member Invalid_Deployment The deployment given to the backend is invalid
 * @member Invalid_Product The product ID specified to the backend is invalid
 * @member Invalid_ProductUserID The product user ID specified to the backend is invalid
 * @member ServiceFailure There was a failure with the backend service
 * @member CacheDirectoryMissing Cache directory is not set in platform options.
 * @member CacheDirectoryInvalid Cache directory is not accessible.
 * @member InvalidState The request failed because resource was in an invalid state
 * @member RequestInProgress Request is in progress
 * @member ApplicationSuspended Application is suspended
 * @member NetworkDisconnected Network is disconnected
 * @member Auth_AccountLocked Account locked due to login failures
 * @member Auth_AccountLockedForUpdate Account locked by update operation.
 * @member Auth_InvalidRefreshToken Refresh token used was invalid
 * @member Auth_InvalidToken Invalid access token, typically when switching between backend environments
 * @member Auth_AuthenticationFailure Invalid bearer token
 * @member Auth_InvalidPlatformToken Invalid platform token
 * @member Auth_WrongAccount Auth parameters are not associated with this account
 * @member Auth_WrongClient Auth parameters are not associated with this client
 * @member Auth_FullAccountRequired Full account is required
 * @member Auth_HeadlessAccountRequired Headless account is required
 * @member Auth_PasswordResetRequired Password reset is required
 * @member Auth_PasswordCannotBeReused Password was previously used and cannot be reused
 * @member Auth_Expired Authorization code/exchange code has expired
 * @member Auth_ScopeConsentRequired Consent has not been given by the user
 * @member Auth_ApplicationNotFound The application has no profile on the backend
 * @member Auth_ScopeNotFound The requested consent wasn't found on the backend
 * @member Auth_AccountFeatureRestricted This account has been denied access to login
 * @member Auth_PinGrantCode Pin grant code initiated
 * @member Auth_PinGrantExpired Pin grant code attempt expired
 * @member Auth_PinGrantPending Pin grant code attempt pending
 * @member Auth_ExternalAuthNotLinked External auth source did not yield an account
 * @member Auth_ExternalAuthRevoked External auth access revoked
 * @member Auth_ExternalAuthInvalid External auth token cannot be interpreted
 * @member Auth_ExternalAuthRestricted External auth cannot be linked to his account due to restrictions
 * @member Auth_ExternalAuthCannotLogin External auth cannot be used for login
 * @member Auth_ExternalAuthExpired External auth is expired
 * @member Auth_ExternalAuthIsLastLoginType External auth cannot be removed since it's the last possible way to login
 * @member Auth_ExchangeCodeNotFound Exchange code not found
 * @member Auth_OriginatingExchangeCodeSessionExpired Originating exchange code session has expired
 * @member Auth_AccountNotActive The account has been disabled and cannot be used for authentication
 * @member Auth_MFARequired MFA challenge required
 * @member Auth_ParentalControls Parental locks are in place
 * @member Auth_NoRealId Korea real ID association required but missing
 * @member Friends_InviteAwaitingAcceptance An outgoing friend invitation is waiting acceptance; sending another invite to the same user is erroneous
 * @member Friends_NoInvitation There is no friend invitation to accept/reject
 * @member Friends_AlreadyFriends Users are already friends, so sending another invite is erroneous
 * @member Friends_NotFriends Users are not friends, so deleting the friend is erroneous
 * @member Friends_TargetUserTooManyInvites Remote user has too many invites to receive new invites
 * @member Friends_LocalUserTooManyInvites Local user has too many invites to send new invites
 * @member Friends_TargetUserFriendLimitExceeded Remote user has too many friends to make a new friendship
 * @member Friends_LocalUserFriendLimitExceeded Local user has too many friends to make a new friendship
 * @member Presence_DataInvalid Request data was null or invalid
 * @member Presence_DataLengthInvalid Request contained too many or too few unique data items, or the request would overflow the maximum amount of data allowed
 * @member Presence_DataKeyInvalid Request contained data with an invalid key
 * @member Presence_DataKeyLengthInvalid Request contained data with a key too long or too short
 * @member Presence_DataValueInvalid Request contained data with an invalid value
 * @member Presence_DataValueLengthInvalid Request contained data with a value too long
 * @member Presence_RichTextInvalid Request contained an invalid rich text string
 * @member Presence_RichTextLengthInvalid Request contained a rich text string that was too long
 * @member Presence_StatusInvalid Request contained an invalid status state
 * @member Ecom_EntitlementStale The entitlement retrieved is stale, re-query for updated information
 * @member Ecom_CatalogOfferStale The offer retrieved is stale, re-query for updated information
 * @member Ecom_CatalogItemStale The item or associated structure retrieved is stale, re-query for updated information
 * @member Ecom_CatalogOfferPriceInvalid The one or more offers has an invalid price. This may be caused by the price setup.
 * @member Ecom_CheckoutLoadError The checkout page failed to load
 * @member Ecom_PurchaseProcessing The player closed the purchase flow overlay after clicking the purchase button. The purchase may still go through = and the game needs to query unredeemed entitlements for a short time.
 * @member Sessions_SessionInProgress Session is already in progress
 * @member Sessions_TooManyPlayers Too many players to register with this session
 * @member Sessions_NoPermission Client has no permissions to access this session
 * @member Sessions_SessionAlreadyExists Session already exists in the system
 * @member Sessions_InvalidLock Session lock required for operation
 * @member Sessions_InvalidSession Invalid session reference
 * @member Sessions_SandboxNotAllowed Sandbox ID associated with auth didn't match
 * @member Sessions_InviteFailed Invite failed to send
 * @member Sessions_InviteNotFound Invite was not found with the service
 * @member Sessions_UpsertNotAllowed This client may not modify the session
 * @member Sessions_AggregationFailed Backend nodes unavailable to process request
 * @member Sessions_HostAtCapacity Individual backend node is as capacity
 * @member Sessions_SandboxAtCapacity Sandbox on node is at capacity
 * @member Sessions_SessionNotAnonymous An anonymous operation was attempted on a non anonymous session
 * @member Sessions_OutOfSync Session is currently out of sync with the backend, data is saved locally but needs to sync with backend
 * @member Sessions_TooManyInvites User has received too many invites
 * @member Sessions_PresenceSessionExists Presence session already exists for the client
 * @member Sessions_DeploymentAtCapacity Deployment on node is at capacity
 * @member Sessions_NotAllowed Session operation not allowed
 * @member Sessions_PlayerSanctioned Session operation not allowed
 * @member PlayerDataStorage_FilenameInvalid Request filename was invalid
 * @member PlayerDataStorage_FilenameLengthInvalid Request filename was too long
 * @member PlayerDataStorage_FilenameInvalidchars Request filename contained invalid characters
 * @member PlayerDataStorage_FileSizeTooLarge Request operation would grow file too large
 * @member PlayerDataStorage_FileSizeInvalid Request file length is not valid
 * @member PlayerDataStorage_FileHandleInvalid Request file handle is not valid
 * @member PlayerDataStorage_DataInvalid Request data is invalid
 * @member PlayerDataStorage_DataLengthInvalid Request data length was invalid
 * @member PlayerDataStorage_StartIndexInvalid Request start index was invalid
 * @member PlayerDataStorage_RequestInProgress Request is in progress
 * @member PlayerDataStorage_UserThrottled User is marked as throttled which means he can't perform some operations because limits are exceeded.
 * @member PlayerDataStorage_EncryptionKeyNotSet Encryption key is not set during SDK init.
 * @member PlayerDataStorage_UserErrorFromDataCallback User data callback returned error
 * @member PlayerDataStorage_FileHeaderHasNewerVersion User is trying to read file that has header from newer version of SDK. Game/SDK needs to be updated.
 * @member PlayerDataStorage_FileCorrupted The file is corrupted. In some cases retry can fix the issue.
 * @member Connect_ExternalTokenValidationFailed EOS Auth service deemed the external token invalid
 * @member Connect_UserAlreadyExists EOS Auth user already exists
 * @member Connect_AuthExpired EOS Auth expired
 * @member Connect_InvalidToken EOS Auth invalid token
 * @member Connect_UnsupportedTokenType EOS Auth doesn't support this token type
 * @member Connect_LinkAccountFailed EOS Auth Account link failure
 * @member Connect_ExternalServiceUnavailable EOS Auth External service for validation was unavailable
 * @member Connect_ExternalServiceConfigurationFailure EOS Auth External Service configuration failure with Dev Portal
 * @member UI_SocialOverlayLoadError The social overlay page failed to load
 * @member UI_InconsistentVirtualMemoryFunctions Virtual Memory Functions are an inconsistent mix of functions and nullptrs
 * @member Lobby_NotOwner Client has no permissions to modify this lobby
 * @member Lobby_InvalidLock Lobby lock required for operation
 * @member Lobby_LobbyAlreadyExists Lobby already exists in the system
 * @member Lobby_SessionInProgress Lobby is already in progress
 * @member Lobby_TooManyPlayers Too many players to register with this lobby
 * @member Lobby_NoPermission Client has no permissions to access this lobby
 * @member Lobby_InvalidSession Invalid lobby session reference
 * @member Lobby_SandboxNotAllowed Sandbox ID associated with auth didn't match
 * @member Lobby_InviteFailed Invite failed to send
 * @member Lobby_InviteNotFound Invite was not found with the service
 * @member Lobby_UpsertNotAllowed This client may not modify the lobby
 * @member Lobby_AggregationFailed Backend nodes unavailable to process request
 * @member Lobby_HostAtCapacity Individual backend node is at capacity
 * @member Lobby_SandboxAtCapacity Sandbox on node is at capacity
 * @member Lobby_TooManyInvites User has received too many invites
 * @member Lobby_DeploymentAtCapacity Deployment on node is at capacity
 * @member Lobby_NotAllowed Lobby operation not allowed
 * @member Lobby_MemberUpdateOnly While restoring a lost connection lobby ownership changed and only local member data was updated
 * @member Lobby_PresenceLobbyExists Presence lobby already exists for the client
 * @member Lobby_VoiceNotEnabled Operation requires lobby with voice enabled
 * @member Lobby_PlatformNotAllowed The client platform does not match the allowed platform list for the lobby.
 * @member TitleStorage_UserErrorFromDataCallback User callback that receives data from storage returned error.
 * @member TitleStorage_EncryptionKeyNotSet User forgot to set Encryption key during platform init. Title Storage can't work without it.
 * @member TitleStorage_FileCorrupted Downloaded file is corrupted.
 * @member TitleStorage_FileHeaderHasNewerVersion Downloaded file's format is newer than client SDK version.
 * @member Mods_ModSdkProcessIsAlreadyRunning ModSdk process is already running. This error comes from the EOSSDK.
 * @member Mods_ModSdkCommandIsEmpty ModSdk command is empty. Either the ModSdk configuration file is missing or the manifest location is empty.
 * @member Mods_ModSdkProcessCreationFailed Creation of the ModSdk process failed. This error comes from the SDK.
 * @member Mods_CriticalError A critical error occurred in the external ModSdk process that we were unable to resolve.
 * @member Mods_ToolInternalError A internal error occurred in the external ModSdk process that we were unable to resolve.
 * @member Mods_IPCFailure A IPC failure occurred in the external ModSdk process.
 * @member Mods_InvalidIPCResponse A invalid IPC response received in the external ModSdk process.
 * @member Mods_URILaunchFailure A URI Launch failure occurred in the external ModSdk process.
 * @member Mods_ModIsNotInstalled Attempting to perform an action with a mod that is not installed. This error comes from the external ModSdk process.
 * @member Mods_UserDoesNotOwnTheGame Attempting to perform an action on a game that the user doesn't own. This error comes from the external ModSdk process.
 * @member Mods_OfferRequestByIdInvalidResult Invalid result of the request to get the offer for the mod. This error comes from the external ModSdk process.
 * @member Mods_CouldNotFindOffer Could not find the offer for the mod. This error comes from the external ModSdk process.
 * @member Mods_OfferRequestByIdFailure Request to get the offer for the mod failed. This error comes from the external ModSdk process.
 * @member Mods_PurchaseFailure Request to purchase the mod failed. This error comes from the external ModSdk process.
 * @member Mods_InvalidGameInstallInfo Attempting to perform an action on a game that is not installed or is partially installed. This error comes from the external ModSdk process.
 * @member Mods_CannotGetManifestLocation Failed to get manifest location. Either the ModSdk configuration file is missing or the manifest location is empty
 * @member Mods_UnsupportedOS Attempting to perform an action with a mod that does not support the current operating system.
 * @member AntiCheat_ClientProtectionNotAvailable The anti-cheat client protection is not available. Check that the game was started using the anti-cheat bootstrapper.
 * @member AntiCheat_InvalidMode The current anti-cheat mode is incorrect for using this API
 * @member AntiCheat_ClientProductIdMismatch The ProductId provided to the anti-cheat client helper executable does not match what was used to initialize the EOS SDK
 * @member AntiCheat_ClientSandboxIdMismatch The SandboxId provided to the anti-cheat client helper executable does not match what was used to initialize the EOS SDK
 * @member AntiCheat_ProtectMessageSessionKeyRequired (ProtectMessage/UnprotectMessage) No session key is available, but it is required to complete this operation
 * @member AntiCheat_ProtectMessageValidationFailed (ProtectMessage/UnprotectMessage) Message integrity is invalid
 * @member AntiCheat_ProtectMessageInitializationFailed (ProtectMessage/UnprotectMessage) Initialization failed
 * @member AntiCheat_PeerAlreadyRegistered (RegisterPeer) Peer is already registered
 * @member AntiCheat_PeerNotFound (UnregisterPeer) Peer does not exist
 * @member AntiCheat_PeerNotProtected (ReceiveMessageFromPeer) Invalid call: Peer is not protected
 * @member AntiCheat_ClientDeploymentIdMismatch The DeploymentId provided to the anti-cheat client helper executable does not match what was used to initialize the EOS SDK
 * @member AntiCheat_DeviceIdAuthIsNotSupported EOS Connect DeviceID auth method is not supported for anti-cheat
 * @member RTC_TooManyParticipants EOS RTC room cannot accept more participants
 * @member RTC_RoomAlreadyExists EOS RTC room already exists
 * @member RTC_UserKicked The user kicked out from the room
 * @member RTC_UserBanned The user is banned
 * @member RTC_RoomWasLeft EOS RTC room was left successfully
 * @member RTC_ReconnectionTimegateExpired Connection dropped due to long timeout
 * @member RTC_ShutdownInvoked EOS RTC room was left due to platform release
 * @member RTC_UserIsInBlocklist EOS RTC operation failed because the user is in the local user's block list
 * @member ProgressionSnapshot_SnapshotIdUnavailable The number of available Snapshot IDs have all been exhausted.
 * @member KWS_ParentEmailMissing The KWS user does not have a parental email associated with the account. The parent account was unlinked or deleted
 * @member KWS_UserGraduated The KWS user is no longer a minor and trying to update the parent email
 * @member Android_JavaVMNotStored EOS Android VM not stored
 * @member Android_ReservedMustReferenceLocalVM EOS Android if Reserved is set it must reference stored VM
 * @member Android_ReservedMustBeNull EOS Android Reserved must not be provided
 * @member Permission_RequiredPatchAvailable Patch required before the user can use the privilege
 * @member Permission_RequiredSystemUpdate System update required before the user can use the privilege
 * @member Permission_AgeRestrictionFailure Parental control failure usually
 * @member Permission_AccountTypeFailure Premium Account Subscription required but not available
 * @member Permission_ChatRestriction User restricted from chat
 * @member Permission_UGCRestriction User restricted from User Generated Content
 * @member Permission_OnlinePlayRestricted Online play is restricted
 * @member DesktopCrossplay_ApplicationNotBootstrapped The application was not launched through the Bootstrapper. Desktop crossplay functionality is unavailable.
 * @member DesktopCrossplay_ServiceNotInstalled The redistributable service is not installed.
 * @member DesktopCrossplay_ServiceStartFailed The desktop crossplay service failed to start.
 * @member DesktopCrossplay_ServiceNotRunning The desktop crossplay service is no longer running for an unknown reason.
 * @member CustomInvites_InviteFailed When sending the custom invite failed.
 * @member UserInfo_BestDisplayNameIndeterminate The best display name could not be safely determined.
 * @member ConsoleInit_CacheStorage_SizeKBNotMultipleOf16 CacheStorageSizeKB must be a multiple of 16
 * @member ConsoleInit_CacheStorage_SizeKBBelowMinimumSize CacheStorageSizeKB is less than the minimum allowed
 * @member ConsoleInit_CacheStorage_SizeKBExceedsMaximumSize CacheStorageSizeKB is greater than the maximum allowed (4000 MB)
 * @member ConsoleInit_CacheStorage_IndexOutOfRangeRange CacheStorageIndex is out of its allowed range
 * @member EOS_UnexpectedError An unexpected error that we cannot identify has occurred
 * @constant_end
 */

/**
 * @constant EOS_ComparisonOp
 * @desc **Epic Online Services Enum:** [EOS_EComparisonOp](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-comparison-op)
 * 
 * @member EQUAL Value must equal the one stored on the lobby/session
 * @member NOTEQUAL Value must not equal the one stored on the lobby/session
 * @member GREATERTHAN Value must be strictly greater than the one stored on the lobby/session
 * @member GREATERTHANOREQUAL Value must be greater than or equal to the one stored on the lobby/session
 * @member LESSTHAN Value must be strictly less than the one stored on the lobby/session
 * @member LESSTHANOREQUAL Value must be less than or equal to the one stored on the lobby/session
 * @member DISTANCE Prefer values nearest the one specified ie. abs(SearchValue-SessionValue) closest to 0
 * @member ANYOF Value stored on the lobby/session may be any from a specified list
 * @member NOTANYOF Value stored on the lobby/session may NOT be any from a specified list
 * @member ONEOF This one value is a part of a collection
 * @member NOTONEOF This one value is NOT part of a collection
 * @member CONTAINS This value is a CASE SENSITIVE substring of an attribute stored on the lobby/session
 * 
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
 * @member EOS_LC_IDENTITY_PROVIDER Logs related to external identity providers
 * @member EOS_LC_TITLE_STORAGE Logs related to Title Storage
 * @member EOS_LC_MODS Logs related to the Mods service
 * @member EOS_LC_ANTI_CHEAT Logs related to the Anti-Cheat service
 * @member EOS_LC_REPORTS Logs related to reports client
 * @member EOS_LC_SANCTIONS Logs related to the Sanctions service
 * @member EOS_LC_PROGRESSION_SNAPSHOTS Logs related to the Progression Snapshot service
 * @member EOS_LC_KWS Logs related to the Kids Web Services integration
 * @member EOS_LC_RTC Logs related to the RTC API
 * @member EOS_LC_RTCAdmin Logs related to the RTC Admin API
 * @member EOS_LC_INVENTORY Logs related to the Inventory service
 * @member EOS_LC_RECEIPT_VALIDATOR Logs related to the Receipt Validator API
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
 * @member {constant.EOS_Result} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
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
 * @ref EOS_Result
 * @ref eos_logging_category
 * @ref eos_logging_level
 * @ref EOS_INVALID_NOTIFICATIONID
 * @ref EOS_ComparisonOp
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
