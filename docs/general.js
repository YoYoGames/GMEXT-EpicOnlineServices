// Functions


/**
 * @function EpicGames_GetVersion
 * @desc **Epic Online Services Function:** [EOS_Friends_AcceptInvite](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Friends/EOS_Friends_AcceptInvite/index.html)
 * 
 * This function gets the version of the EOSSDK binary.
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * show_debug_message($"EpicOnlineServices Version: {EpicGames_GetVersion()}");
 * ```
 * The above code shows an example of how the function should be used. The function ${function.EpicGames_GetVersion} will return the current version of the SDK.
 * @function_end
 */

/**
 * @function EpicGames_Logging_SetLogLevel
 * @desc **Epic Online Services Function:** [EOS_Logging_SetLogLevel](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/NoInterface/EOS_Logging_SetLogLevel/index.html)
 * 
 * This function sets the logging level for the specified logging category.
 * 
 * [[Note: By default all log categories will callback for Warnings, Errors, and Fatals.]]
 * 
 * @param {constant.EpicGames_Logging_Category} category The specific log category to configure. Use `EpicGames_LC_ALL_CATEGORIES` to configure all categories simultaneously to the same log level. Check the constants under ${constant.EpicGames_Logging_Category}.
 * @param {constant.EpicGames_Logging_Level} logLevel the log level to use for the log category. Check the constants under ${constant.EpicGames_Logging_Level}.
 * 
 * @example
 * ```gml
 * EpicGames_Logging_SetLogLevel(EpicGames_LC_ALL_CATEGORIES, EpicGames_LOG_Off);
 * ```
 * The above code shows an example of how the function should be used. This will turn off logging for all categories.
 * @function_end
 */

/**
 * @function EpicGames_Shutdown
 * @desc **Epic Online Services Function:** [EOS_Shutdown](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/NoInterface/EOS_Shutdown/index.html)
 * 
 * This function shuts down the Epic Online Services SDK. Once this function has been called, no more SDK calls are permitted.
 * Calling anything after ${function.EpicGames_Shutdown} will result in undefined behaviour. 
 * 
 * 1. `EpicGames_Success` is the returned status if the SDK is successfully torn down.
 * 2. `EpicGames_NotConfigured` is returned status if the extension didn't initialise correctly.
 * 3. `EpicGames_UnexpectedError` is returned status if ${function.EpicGames_Shutdown} has already been called.
 * 
 * 
 * [[Warning: This should be called at the end of your game.]]
 * 
 * @returns {struct.EpicResult}
 * 
 * @example
 * ```gml
 * var _struct = EpicGames_Shutdown();
 * if(_struct.status == EpicGames_Success)
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
 * @constant EpicGames_Result
 * @desc **Epic Online Services Enum:** [EOS_EResult](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-result)
 * 
 * These are all the available constants used as task results, for the entire API.
 * 
 * @member EpicGames_Success Successful result. no further error processing needed
 * @member EpicGames_NoConnection Failed due to no connection
 * @member EpicGames_InvalidCredentials Failed login due to invalid credentials
 * @member EpicGames_InvalidUser Failed due to invalid or missing user
 * @member EpicGames_InvalidAuth Failed due to invalid or missing authentication token for user (e.g. not logged in)
 * @member EpicGames_AccessDenied Failed due to invalid access
 * @member EpicGames_MissingPermissions If the client does not possess the permission required
 * @member EpicGames_Token_Not_Account If the token provided does not represent an account
 * @member EpicGames_TooManyRequests Throttled due to too many requests
 * @member EpicGames_AlreadyPending Async request was already pending
 * @member EpicGames_InvalidParameters Invalid parameters specified for request
 * @member EpicGames_InvalidRequest Invalid request
 * @member EpicGames_UnrecognizedResponse Failed due to unable to parse or recognize a backend response
 * @member EpicGames_IncompatibleVersion Incompatible client for backend version
 * @member EpicGames_NotConfigured Not configured correctly for use
 * @member EpicGames_AlreadyConfigured Already configured for use.
 * @member EpicGames_NotImplemented Feature not available on this implementation
 * @member EpicGames_Canceled Operation was canceled (likely by user)
 * @member EpicGames_NotFound The requested information was not found
 * @member EpicGames_OperationWillRetry An error occurred during an asynchronous operation, and it will be retried. Callbacks receiving this result will be called again in the future.
 * @member EpicGames_NoChange The request had no effect
 * @member EpicGames_VersionMismatch The request attempted to use multiple or inconsistent API versions
 * @member EpicGames_LimitExceeded A maximum limit was exceeded on the client, different from `EpicGames_TooManyRequests`
 * @member EpicGames_Disabled Feature or client ID performing the operation has been disabled.
 * @member EpicGames_DuplicateNotAllowed Duplicate entry not allowed
 * @member EpicGames_InvalidSandboxId Sandbox ID is invalid
 * @member EpicGames_TimedOut Request timed out
 * @member EpicGames_PartialResult A query returned some but not all of the requested results.
 * @member EpicGames_Missing_Role Client is missing the white-listed role
 * @member EpicGames_Missing_Feature Client is missing the white-listed feature
 * @member EpicGames_Invalid_Sandbox The sandbox given to the backend is invalid
 * @member EpicGames_Invalid_Deployment The deployment given to the backend is invalid
 * @member EpicGames_Invalid_Product The product ID specified to the backend is invalid
 * @member EpicGames_Invalid_ProductUserID The product user ID specified to the backend is invalid
 * @member EpicGames_ServiceFailure There was a failure with the backend service
 * @member EpicGames_CacheDirectoryMissing Cache directory is not set in platform options.
 * @member EpicGames_CacheDirectoryInvalid Cache directory is not accessible.
 * @member EpicGames_InvalidState The request failed because resource was in an invalid state
 * @member EpicGames_RequestInProgress Request is in progress
 * @member EpicGames_Auth_AccountLocked Account locked due to login failures
 * @member EpicGames_Auth_AccountLockedForUpdate Account locked by update operation.
 * @member EpicGames_Auth_InvalidRefreshToken Refresh token used was invalid
 * @member EpicGames_Auth_InvalidToken Invalid access token, typically when switching between backend environments
 * @member EpicGames_Auth_AuthenticationFailure Invalid bearer token
 * @member EpicGames_Auth_InvalidPlatformToken Invalid platform token
 * @member EpicGames_Auth_WrongAccount Auth parameters are not associated with this account
 * @member EpicGames_Auth_WrongClient Auth parameters are not associated with this client
 * @member EpicGames_Auth_FullAccountRequired Full account is required
 * @member EpicGames_Auth_HeadlessAccountRequired Headless account is required
 * @member EpicGames_Auth_PasswordResetRequired Password reset is required
 * @member EpicGames_Auth_PasswordCannotBeReused Password was previously used and cannot be reused
 * @member EpicGames_Auth_Expired Authorization code/exchange code has expired
 * @member EpicGames_Auth_ScopeConsentRequired Consent has not been given by the user
 * @member EpicGames_Auth_ApplicationNotFound The application has no profile on the backend
 * @member EpicGames_Auth_ScopeNotFound The requested consent wasn't found on the backend
 * @member EpicGames_Auth_AccountFeatureRestricted This account has been denied access to login
 * @member EpicGames_Auth_PinGrantCode Pin grant code initiated
 * @member EpicGames_Auth_PinGrantExpired Pin grant code attempt expired
 * @member EpicGames_Auth_PinGrantPending Pin grant code attempt pending
 * @member EpicGames_Auth_ExternalAuthNotLinked External auth source did not yield an account
 * @member EpicGames_Auth_ExternalAuthRevoked External auth access revoked
 * @member EpicGames_Auth_ExternalAuthInvalid External auth token cannot be interpreted
 * @member EpicGames_Auth_ExternalAuthRestricted External auth cannot be linked to his account due to restrictions
 * @member EpicGames_Auth_ExternalAuthCannotLogin External auth cannot be used for login
 * @member EpicGames_Auth_ExternalAuthExpired External auth is expired
 * @member EpicGames_Auth_ExternalAuthIsLastLoginType External auth cannot be removed since it's the last possible way to login
 * @member EpicGames_Auth_ExchangeCodeNotFound Exchange code not found
 * @member EpicGames_Auth_OriginatingExchangeCodeSessionExpired Originating exchange code session has expired
 * @member EpicGames_Auth_PersistentAuth_AccountNotActive The account has been disabled and cannot be used for authentication
 * @member EpicGames_Auth_MFARequired MFA challenge required
 * @member EpicGames_Auth_ParentalControls Parental locks are in place
 * @member EpicGames_Auth_NoRealId Korea real ID association required but missing
 * @member EpicGames_Friends_InviteAwaitingAcceptance An outgoing friend invitation is waiting acceptance; sending another invite to the same user is erroneous
 * @member EpicGames_Friends_NoInvitation There is no friend invitation to accept/reject
 * @member EpicGames_Friends_AlreadyFriends Users are already friends, so sending another invite is erroneous
 * @member EpicGames_Friends_NotFriends Users are not friends, so deleting the friend is erroneous
 * @member EpicGames_Friends_TargetUserTooManyInvites Remote user has too many invites to receive new invites
 * @member EpicGames_Friends_LocalUserTooManyInvites Local user has too many invites to send new invites
 * @member EpicGames_Friends_TargetUserFriendLimitExceeded Remote user has too many friends to make a new friendship
 * @member EpicGames_Friends_LocalUserFriendLimitExceeded Local user has too many friends to make a new friendship
 * @member EpicGames_Presence_DataInvalid Request data was null or invalid
 * @member EpicGames_Presence_DataLengthInvalid Request contained too many or too few unique data items, or the request would overflow the maximum amount of data allowed
 * @member EpicGames_Presence_DataKeyInvalid Request contained data with an invalid key
 * @member EpicGames_Presence_DataKeyLengthInvalid Request contained data with a key too long or too short
 * @member EpicGames_Presence_DataValueInvalid Request contained data with an invalid value
 * @member EpicGames_Presence_DataValueLengthInvalid Request contained data with a value too long
 * @member EpicGames_Presence_RichTextInvalid Request contained an invalid rich text string
 * @member EpicGames_Presence_RichTextLengthInvalid Request contained a rich text string that was too long
 * @member EpicGames_Presence_StatusInvalid Request contained an invalid status state
 * @member EpicGames_Ecom_EntitlementStale The entitlement retrieved is stale, re-query for updated information
 * @member EpicGames_Ecom_CatalogOfferStale The offer retrieved is stale, re-query for updated information
 * @member EpicGames_Ecom_CatalogItemStale The item or associated structure retrieved is stale, re-query for updated information
 * @member EpicGames_Ecom_CatalogOfferPriceInvalid The one or more offers has an invalid price. This may be caused by the price setup.
 * @member EpicGames_Ecom_CheckoutLoadError The checkout page failed to load
 * @member EpicGames_Sessions_SessionInProgress Session is already in progress
 * @member EpicGames_Sessions_TooManyPlayers Too many players to register with this session
 * @member EpicGames_Sessions_NoPermission Client has no permissions to access this session
 * @member EpicGames_Sessions_SessionAlreadyExists Session already exists in the system
 * @member EpicGames_Sessions_InvalidLock Session lock required for operation
 * @member EpicGames_Sessions_InvalidSession Invalid session reference
 * @member EpicGames_Sessions_SandboxNotAllowed Sandbox ID associated with auth didn't match
 * @member EpicGames_Sessions_InviteFailed Invite failed to send
 * @member EpicGames_Sessions_InviteNotFound Invite was not found with the service
 * @member EpicGames_Sessions_UpsertNotAllowed This client may not modify the session
 * @member EpicGames_Sessions_AggregationFailed Backend nodes unavailable to process request
 * @member EpicGames_Sessions_HostAtCapacity Individual backend node is as capacity
 * @member EpicGames_Sessions_SandboxAtCapacity Sandbox on node is at capacity
 * @member EpicGames_Sessions_SessionNotAnonymous An anonymous operation was attempted on a non anonymous session
 * @member EpicGames_Sessions_OutOfSync Session is currently out of sync with the backend, data is saved locally but needs to sync with backend
 * @member EpicGames_Sessions_TooManyInvites User has received too many invites
 * @member EpicGames_Sessions_PresenceSessionExists Presence session already exists for the client
 * @member EpicGames_Sessions_DeploymentAtCapacity Deployment on node is at capacity
 * @member EpicGames_Sessions_NotAllowed Session operation not allowed
 * @member EpicGames_Sessions_PlayerSanctioned Session operation not allowed
 * @member EpicGames_PlayerDataStorage_FilenameInvalid Request filename was invalid
 * @member EpicGames_PlayerDataStorage_FilenameLengthInvalid Request filename was too long
 * @member EpicGames_PlayerDataStorage_FilenameInvalidChars Request filename contained invalid characters
 * @member EpicGames_PlayerDataStorage_FileSizeTooLarge Request operation would grow file too large
 * @member EpicGames_PlayerDataStorage_FileSizeInvalid Request file length is not valid
 * @member EpicGames_PlayerDataStorage_FileHandleInvalid Request file handle is not valid
 * @member EpicGames_PlayerDataStorage_DataInvalid Request data is invalid
 * @member EpicGames_PlayerDataStorage_DataLengthInvalid Request data length was invalid
 * @member EpicGames_PlayerDataStorage_StartIndexInvalid Request start index was invalid
 * @member EpicGames_PlayerDataStorage_RequestInProgress Request is in progress
 * @member EpicGames_PlayerDataStorage_UserThrottled User is marked as throttled which means he can't perform some operations because limits are exceeded.
 * @member EpicGames_PlayerDataStorage_EncryptionKeyNotSet Encryption key is not set during SDK init.
 * @member EpicGames_PlayerDataStorage_UserErrorFromDataCallback User data callback returned error (EpicGames_PlayerDataStorage_EWriteResult::EpicGames_WR_FailRequest or EpicGames_PlayerDataStorage_EReadResult::EpicGames_RR_FailRequest)
 * @member EpicGames_PlayerDataStorage_FileHeaderHasNewerVersion User is trying to read file that has header from newer version of SDK. Game/SDK needs to be updated.
 * @member EpicGames_PlayerDataStorage_FileCorrupted The file is corrupted. In some cases retry can fix the issue.
 * @member EpicGames_Connect_ExternalTokenValidationFailed EOS Auth service deemed the external token invalid
 * @member EpicGames_Connect_UserAlreadyExists EOS Auth user already exists
 * @member EpicGames_Connect_AuthExpired EOS Auth expired
 * @member EpicGames_Connect_InvalidToken EOS Auth invalid token
 * @member EpicGames_Connect_UnsupportedTokenType EOS Auth doesn't support this token type
 * @member EpicGames_Connect_LinkAccountFailed EOS Auth Account link failure
 * @member EpicGames_Connect_ExternalServiceUnavailable EOS Auth External service for validation was unavailable
 * @member EpicGames_Connect_ExternalServiceConfigurationFailure EOS Auth External Service configuration failure with Dev Portal
 * @member EpicGames_UI_SocialOverlayLoadError The social overlay page failed to load
 * @member EpicGames_Lobby_NotOwner Client has no permissions to modify this lobby
 * @member EpicGames_Lobby_InvalidLock Lobby lock required for operation
 * @member EpicGames_Lobby_LobbyAlreadyExists Lobby already exists in the system
 * @member EpicGames_Lobby_SessionInProgress Lobby is already in progress
 * @member EpicGames_Lobby_TooManyPlayers Too many players to register with this lobby
 * @member EpicGames_Lobby_NoPermission Client has no permissions to access this lobby
 * @member EpicGames_Lobby_InvalidSession Invalid lobby session reference
 * @member EpicGames_Lobby_SandboxNotAllowed Sandbox ID associated with auth didn't match
 * @member EpicGames_Lobby_InviteFailed Invite failed to send
 * @member EpicGames_Lobby_InviteNotFound Invite was not found with the service
 * @member EpicGames_Lobby_UpsertNotAllowed This client may not modify the lobby
 * @member EpicGames_Lobby_AggregationFailed Backend nodes unavailable to process request
 * @member EpicGames_Lobby_HostAtCapacity Individual backend node is as capacity
 * @member EpicGames_Lobby_SandboxAtCapacity Sandbox on node is at capacity
 * @member EpicGames_Lobby_TooManyInvites User has received too many invites
 * @member EpicGames_Lobby_DeploymentAtCapacity Deployment on node is at capacity
 * @member EpicGames_Lobby_NotAllowed Lobby operation not allowed
 * @member EpicGames_Lobby_MemberUpdateOnly While restoring a lost connection lobby ownership changed and only local member data was updated
 * @member EpicGames_Lobby_PresenceLobbyExists Presence lobby already exists for the client
 * @member EpicGames_TitleStorage_UserErrorFromDataCallback User callback that receives data from storage returned error.
 * @member EpicGames_TitleStorage_EncryptionKeyNotSet User forgot to set Encryption key during platform init. Title Storage can't work without it.
 * @member EpicGames_TitleStorage_FileCorrupted Downloaded file is corrupted.
 * @member EpicGames_TitleStorage_FileHeaderHasNewerVersion Downloaded file's format is newer than client SDK version.
 * @member EpicGames_Mods_ModSdkProcessIsAlreadyRunning ModSdk process is already running. This error comes from the EOSSDK.
 * @member EpicGames_Mods_ModSdkCommandIsEmpty ModSdk command is empty. Either the ModSdk configuration file is missing or the manifest location is empty.
 * @member EpicGames_Mods_ModSdkProcessCreationFailed Creation of the ModSdk process failed. This error comes from the SDK.
 * @member EpicGames_Mods_CriticalError A critical error occurred in the external ModSdk process that we were unable to resolve.
 * @member EpicGames_Mods_ToolInternalError A internal error occurred in the external ModSdk process that we were unable to resolve.
 * @member EpicGames_Mods_IPCFailure A IPC failure occurred in the external ModSdk process.
 * @member EpicGames_Mods_InvalidIPCResponse A invalid IPC response received in the external ModSdk process.
 * @member EpicGames_Mods_URILaunchFailure A URI Launch failure occurred in the external ModSdk process.
 * @member EpicGames_Mods_ModIsNotInstalled Attempting to perform an action with a mod that is not installed. This error comes from the external ModSdk process.
 * @member EpicGames_Mods_UserDoesNotOwnTheGame Attempting to perform an action on a game that the user doesn't own. This error comes from the external ModSdk process.
 * @member EpicGames_Mods_OfferRequestByIdInvalidResult Invalid result of the request to get the offer for the mod. This error comes from the external ModSdk process.
 * @member EpicGames_Mods_CouldNotFindOffer Could not find the offer for the mod. This error comes from the external ModSdk process.
 * @member EpicGames_Mods_OfferRequestByIdFailure Request to get the offer for the mod failed. This error comes from the external ModSdk process.
 * @member EpicGames_Mods_PurchaseFailure Request to purchase the mod failed. This error comes from the external ModSdk process.
 * @member EpicGames_Mods_InvalidGameInstallInfo Attempting to perform an action on a game that is not installed or is partially installed. This error comes from the external ModSdk process.
 * @member EpicGames_Mods_CannotGetManifestLocation Failed to get manifest location. Either the ModSdk configuration file is missing or the manifest location is empty
 * @member EpicGames_Mods_UnsupportedOS Attempting to perform an action with a mod that does not support the current operating system.
 * @member EpicGames_AntiCheat_ClientProtectionNotAvailable The anti-cheat client protection is not available. Check that the game was started using the anti-cheat bootstrapper.
 * @member EpicGames_AntiCheat_InvalidMode The current anti-cheat mode is incorrect for using this API
 * @member EpicGames_AntiCheat_ClientProductIdMismatch The ProductId provided to the anti-cheat client helper executable does not match what was used to initialize the EOS SDK
 * @member EpicGames_AntiCheat_ClientSandboxIdMismatch The SandboxId provided to the anti-cheat client helper executable does not match what was used to initialize the EOS SDK
 * @member EpicGames_AntiCheat_ProtectMessageSessionKeyRequired (ProtectMessage/UnprotectMessage) No session key is available, but it is required to complete this operation
 * @member EpicGames_AntiCheat_ProtectMessageValidationFailed (ProtectMessage/UnprotectMessage) Message integrity is invalid
 * @member EpicGames_AntiCheat_ProtectMessageInitializationFailed (ProtectMessage/UnprotectMessage) Initialization failed
 * @member EpicGames_AntiCheat_PeerAlreadyRegistered (RegisterPeer) Peer is already registered
 * @member EpicGames_AntiCheat_PeerNotFound (UnregisterPeer) Peer does not exist
 * @member EpicGames_AntiCheat_PeerNotProtected (ReceiveMessageFromPeer) Invalid call: Peer is not protected
 * @member EpicGames_AntiCheat_ClientDeploymentIdMismatch The DeploymentId provided to the anti-cheat client helper executable does not match what was used to initialize the EOS SDK
 * @member EpicGames_AntiCheat_DeviceIdAuthIsNotSupported EOS Connect DeviceID auth method is not supported for anti-cheat
 * @member EpicGames_RTC_TooManyParticipants EOS RTC room cannot accept more participants
 * @member EpicGames_RTC_RoomAlreadyExists EOS RTC room already exists
 * @member EpicGames_RTC_UserKicked The user kicked out from the room
 * @member EpicGames_RTC_UserBanned The user is banned
 * @member EpicGames_RTC_RoomWasLeft EOS RTC room was left successfully
 * @member EpicGames_RTC_ReconnectionTimegateExpired Connection dropped due to long timeout
 * @member EpicGames_ProgressionSnapshot_SnapshotIdUnavailable The number of available Snapshot IDs have all been exhausted.
 * @member EpicGames_KWS_ParentEmailMissing The KWS user does not have a parental email associated with the account. The parent account was unlinked or deleted
 * @member EpicGames_KWS_UserGraduated The KWS user is no longer a minor and trying to update the parent email
 * @member EpicGames_Android_JavaVMNotStored EOS Android VM not stored
 * @constant_end
 */

/**
 * @constant EpicGames_Logging_Category
 * @desc **Epic Online Services Enum:** [EOS_ELogCategory](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-log-category)
 * 
 * These constants represent the available logging categories.
 * 
 * @member EpicGames_LC_Core Low level logs unrelated to specific services
 * @member EpicGames_LC_Auth Logs related to the Auth service
 * @member EpicGames_LC_Friends Logs related to the Friends service
 * @member EpicGames_LC_Presence Logs related to the Presence service
 * @member EpicGames_LC_UserInfo Logs related to the UserInfo service
 * @member EpicGames_LC_HttpSerialization Logs related to HTTP serialization
 * @member EpicGames_LC_Ecom Logs related to the Ecommerce service
 * @member EpicGames_LC_P2P Logs related to the P2P service
 * @member EpicGames_LC_Sessions Logs related to the Sessions service
 * @member EpicGames_LC_RateLimiter Logs related to rate limiting
 * @member EpicGames_LC_PlayerDataStorage Logs related to the PlayerDataStorage service
 * @member EpicGames_LC_Analytics Logs related to sdk analytics
 * @member EpicGames_LC_Messaging Logs related to the messaging service
 * @member EpicGames_LC_Connect Logs related to the Connect service
 * @member EpicGames_LC_Overlay Logs related to the Overlay
 * @member EpicGames_LC_Achievements Logs related to the Achievements service
 * @member EpicGames_LC_Stats Logs related to the Stats service
 * @member EpicGames_LC_UI Logs related to the UI service
 * @member EpicGames_LC_Lobby Logs related to the lobby service
 * @member EpicGames_LC_Leaderboards Logs related to the Leaderboards service
 * @member EpicGames_LC_Keychain Logs related to an internal Keychain feature that the authentication interfaces use
 * @member EpicGames_LC_IdentityProvider Logs related to external identity providers
 * @member EpicGames_LC_TitleStorage Logs related to Title Storage
 * @member EpicGames_LC_Mods Logs related to the Mods service
 * @member EpicGames_LC_AntiCheat Logs related to the Anti-Cheat service
 * @member EpicGames_LC_Reports Logs related to reports client
 * @member EpicGames_LC_Sanctions Logs related to the Sanctions service
 * @member EpicGames_LC_ProgressionSnapshots Logs related to the Progression Snapshot service
 * @member EpicGames_LC_KWS Logs related to the Kids Web Services integration
 * @member EpicGames_LC_RTC Logs related to the RTC API
 * @member EpicGames_LC_RTCAdmin Logs related to the RTC Admin API
 * @member EpicGames_LC_Inventory Logs related to the Inventory service
 * @member EpicGames_LC_ReceiptValidator Logs related to the Receipt Validator API
 * @member EpicGames_LC_CustomInvites Logs related to the Custom Invites API
 * @member EpicGames_LC_ALL_CATEGORIES Not a real log category. Used by ${function.EpicGames_Logging_SetLogLevel} to set the log level for all categories at the same time
 * @constant_end
 */

/**
 * @constant EpicGames_Logging_Level
 * @desc **Epic Online Services Enum:** [EOS_ELogLevel](https://dev.epicgames.com/docs/api-ref/enums/eos-e-log-level)
 * 
 * These constants represent the available logging levels. When a log message is output, it has an associated log level. Messages will only be sent to the callback function if the message is associated log level is less than or equal to the configured log level for that category.
 * 
 * @member EpicGames_LOG_Off
 * @member EpicGames_LOG_Fatal
 * @member EpicGames_LOG_Error
 * @member EpicGames_LOG_Warning
 * @member EpicGames_LOG_Info
 * @member EpicGames_LOG_Verbose
 * @member EpicGames_LOG_VeryVerbose
 * @constant_end
 */

// Structs

/**
 * @struct EpicResult
 * @desc A struct containing a result's status code and its representation in text.
 * 
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
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
 * @ref EpicGames_GetVersion
 * @ref EpicGames_Logging_SetLogLevel
 * @ref EpicGames_Shutdown
 * 
 * @section_end
 * 
 * @section_const
 * @desc These are the constants used by this API:
 * 
 * @ref EpicGames_Result
 * @ref EpicGames_Logging_Category
 * @ref EpicGames_Logging_Level
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
