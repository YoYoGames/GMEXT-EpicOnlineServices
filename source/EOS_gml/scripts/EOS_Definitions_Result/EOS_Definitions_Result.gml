// Copyright Epic Games = Inc. All Rights Reserved.

// This file is not intended to be included directly. Include eos_common.h instead.

enum EOS_Result
{
    /** Successful result. no further error processing needed */
    Success = 0,
    
    /** Failed due to no connection */
    NoConnection = 1,
    /** Failed login due to invalid credentials */
    InvalidCredentials = 2,
    /** Failed due to invalid or missing user */
    InvalidUser = 3,
    /** Failed due to invalid or missing authentication token for user (e.g. not logged in, */
    InvalidAuth = 4,
    /** Failed due to invalid access */
    AccessDenied = 5,
    /** If the client does not possess the permission required */
    MissingPermissions = 6,
    /** If the token provided does not represent an account */
    Token_Not_Account = 7,
    /** Throttled due to too many requests */
    TooManyRequests = 8,
    /** Async request was already pending */
    AlreadyPending = 9,
    /** Invalid parameters specified for request */
    InvalidParameters = 10,
    /** Invalid request */
    InvalidRequest = 11,
    /** Failed due to unable to parse or recognize a backend response */
    UnrecognizedResponse = 12,
    /** Incompatible client for backend version */
    IncompatibleVersion = 13,
    /** Not configured correctly for use */
    NotConfigured = 14,
    /** Already configured for use. */
    AlreadyConfigured = 15,
    /** Feature not available on this implementation */
    NotImplemented = 16,
    /** Operation was canceled (likely by user, */
    Canceled = 17,
    /** The requested information was not found */
    NotFound = 18,
    /** An error occurred during an asynchronous operation = and it will be retried. Callbacks receiving this result will be called again in the future. */
    OperationWillRetry = 19,
    /** The request had no effect */
    NoChange = 20,
    /** The request attempted to use multiple or inconsistent API versions */
    VersionMismatch = 21,
    /** A maximum limit was exceeded on the client = different from EOS_TooManyRequests */
    LimitExceeded = 22,
    /** Feature or client ID performing the operation has been disabled. */
    Disabled = 23,
    /** Duplicate entry not allowed */
    DuplicateNotAllowed = 24,
    /** Required parameters are missing. DEPRECATED: This error is no longer used. */
    MissingParameters_DEPRECATED = 25,
    /** Sandbox ID is invalid */
    InvalidSandboxId = 26,
    /** Request timed out */
    TimedOut = 27,
    /** A query returned some but not all of the requested results. */
    PartialResult = 28,
    /** Client is missing the whitelisted role */
    Missing_Role = 29,
    /** Client is missing the whitelisted feature */
    Missing_Feature = 30,
    /** The sandbox given to the backend is invalid */
    Invalid_Sandbox = 31,
    /** The deployment given to the backend is invalid */
    Invalid_Deployment = 32,
    /** The product ID specified to the backend is invalid */
    Invalid_Product = 33,
    /** The product user ID specified to the backend is invalid */
    Invalid_ProductUserID = 34,
    /** There was a failure with the backend service */
    ServiceFailure = 35,
    /** Cache directory is not set in platform options. */
    CacheDirectoryMissing = 36,
    /** Cache directory is not accessible. */
    CacheDirectoryInvalid = 37,
    /** The request failed because resource was in an invalid state */
    InvalidState = 38,
    /** Request is in progress */
    RequestInProgress = 39,
    /** Application is suspended */
    ApplicationSuspended = 40,
    /** Network is disconnected */
    NetworkDisconnected = 41,
    
    /** Account locked due to login failures */
    Auth_AccountLocked = 1001,
    /** Account locked by update operation. */
    Auth_AccountLockedForUpdate = 1002,
    /** Refresh token used was invalid */
    Auth_InvalidRefreshToken = 1003,
    /** Invalid access token = typically when switching between backend environments */
    Auth_InvalidToken = 1004,
    /** Invalid bearer token */
    Auth_AuthenticationFailure = 1005,
    /** Invalid platform token */
    Auth_InvalidPlatformToken = 1006,
    /** Auth parameters are not associated with this account */
    Auth_WrongAccount = 1007,
    /** Auth parameters are not associated with this client */
    Auth_WrongClient = 1008,
    /** Full account is required */
    Auth_FullAccountRequired = 1009,
    /** Headless account is required */
    Auth_HeadlessAccountRequired = 1010,
    /** Password reset is required */
    Auth_PasswordResetRequired = 1011,
    /** Password was previously used and cannot be reused */
    Auth_PasswordCannotBeReused = 1012,
    /** Authorization code/exchange code has expired */
    Auth_Expired = 1013,
    /** Consent has not been given by the user */
    Auth_ScopeConsentRequired = 1014,
    /** The application has no profile on the backend */
    Auth_ApplicationNotFound = 1015,
    /** The requested consent wasn't found on the backend */
    Auth_ScopeNotFound = 1016,
    /** This account has been denied access to login */
    Auth_AccountFeatureRestricted = 1017,
    /** The overlay failed to load the Account Portal. This can range from general overlay failure = to overlay failed to connect to the web server = to overlay failed to render the web page. */
    Auth_AccountPortalLoadError = 1018,
    /** An attempted login has failed due to the user needing to take corrective action on their account. */
    Auth_CorrectiveActionRequired = 1019,
    
    /** Pin grant code initiated */
    Auth_PinGrantCode = 1020,
    /** Pin grant code attempt expired */
    Auth_PinGrantExpired = 1021,
    /** Pin grant code attempt pending */
    Auth_PinGrantPending = 1022,
    
    /** External auth source did not yield an account */
    Auth_ExternalAuthNotLinked = 1030,
    /** External auth access revoked */
    Auth_ExternalAuthRevoked = 1032,
    /** External auth token cannot be interpreted */
    Auth_ExternalAuthInvalid = 1033,
    /** External auth cannot be linked to his account due to restrictions */
    Auth_ExternalAuthRestricted = 1034,
    /** External auth cannot be used for login */
    Auth_ExternalAuthCannotLogin = 1035,
    /** External auth is expired */
    Auth_ExternalAuthExpired = 1036,
    /** External auth cannot be removed since it's the last possible way to login */
    Auth_ExternalAuthIsLastLoginType = 1037,
    
    /** Exchange code not found */
    Auth_ExchangeCodeNotFound = 1040,
    /** Originating exchange code session has expired */
    Auth_OriginatingExchangeCodeSessionExpired = 1041,
    
    /** The account has been disabled and cannot be used for authentication */
    Auth_AccountNotActive = 1050,
    
    /** MFA challenge required */
    Auth_MFARequired = 1060,
    
    /** Parental locks are in place */
    Auth_ParentalControls = 1070,
    
    /** Korea real ID association required but missing */
    Auth_NoRealId = 1080,
    
    /** Silent login failed when EOS_LF_NO_USER_INTERFACE was specified = and user interaction is needed before the user can be logged in. */
    Auth_UserInterfaceRequired = 1090,
    
    /** An outgoing friend invitation is awaiting acceptance; sending another invite to the same user is erroneous */
    Friends_InviteAwaitingAcceptance = 2000,
    /** There is no friend invitation to accept/reject */
    Friends_NoInvitation = 2001,
    /** Users are already friends = so sending another invite is erroneous */
    Friends_AlreadyFriends = 2003,
    /** Users are not friends = so deleting the friend is erroneous */
    Friends_NotFriends = 2004,
    /** Remote user has too many invites to receive new invites */
    Friends_TargetUserTooManyInvites = 2005,
    /** Local user has too many invites to send new invites */
    Friends_LocalUserTooManyInvites = 2006,
    /** Remote user has too many friends to make a new friendship */
    Friends_TargetUserFriendLimitExceeded = 2007,
    /** Local user has too many friends to make a new friendship */
    Friends_LocalUserFriendLimitExceeded = 2008,
    
    /** Request data was null or invalid */
    Presence_DataInvalid = 3000,
    /** Request contained too many or too few unique data items = or the request would overflow the maximum amount of data allowed */
    Presence_DataLengthInvalid = 3001,
    /** Request contained data with an invalid key */
    Presence_DataKeyInvalid = 3002,
    /** Request contained data with a key too long or too short */
    Presence_DataKeyLengthInvalid = 3003,
    /** Request contained data with an invalid value */
    Presence_DataValueInvalid = 3004,
    /** Request contained data with a value too long */
    Presence_DataValueLengthInvalid = 3005,
    /** Request contained an invalid rich text string */
    Presence_RichTextInvalid = 3006,
    /** Request contained a rich text string that was too long */
    Presence_RichTextLengthInvalid = 3007,
    /** Request contained an invalid status state */
    Presence_StatusInvalid = 3008,
    
    /** The entitlement retrieved is stale = requery for updated information */
    Ecom_EntitlementStale = 4000,
    /** The offer retrieved is stale = requery for updated information */
    Ecom_CatalogOfferStale = 4001,
    /** The item or associated structure retrieved is stale = requery for updated information */
    Ecom_CatalogItemStale = 4002,
    /** The one or more offers has an invalid price. This may be caused by the price setup. */
    Ecom_CatalogOfferPriceInvalid = 4003,
    /** The checkout page failed to load */
    Ecom_CheckoutLoadError = 4004,
    /** The player closed the purchase flow overlay after clicking the purchase button. The purchase may still go through = and the game needs to query unredeemed entitlements for a short time. */
    Ecom_PurchaseProcessing = 4005,
    
    /** Session is already in progress */
    Sessions_SessionInProgress = 5000,
    /** Too many players to register with this session */
    Sessions_TooManyPlayers = 5001,
    /** Client has no permissions to access this session */
    Sessions_NoPermission = 5002,
    /** Session already exists in the system */
    Sessions_SessionAlreadyExists = 5003,
    /** Session lock required for operation */
    Sessions_InvalidLock = 5004,
    /** Invalid session reference */
    Sessions_InvalidSession = 5005,
    /** Sandbox ID associated with auth didn't match */
    Sessions_SandboxNotAllowed = 5006,
    /** Invite failed to send */
    Sessions_InviteFailed = 5007,
    /** Invite was not found with the service */
    Sessions_InviteNotFound = 5008,
    /** This client may not modify the session */
    Sessions_UpsertNotAllowed = 5009,
    /** Backend nodes unavailable to process request */
    Sessions_AggregationFailed = 5010,
    /** Individual backend node is as capacity */
    Sessions_HostAtCapacity = 5011,
    /** Sandbox on node is at capacity */
    Sessions_SandboxAtCapacity = 5012,
    /** An anonymous operation was attempted on a non anonymous session */
    Sessions_SessionNotAnonymous = 5013,
    /** Session is currently out of sync with the backend = data is saved locally but needs to sync with backend */
    Sessions_OutOfSync = 5014,
    /** User has received too many invites */
    Sessions_TooManyInvites = 5015,
    /** Presence session already exists for the client */
    Sessions_PresenceSessionExists = 5016,
    /** Deployment on node is at capacity */
    Sessions_DeploymentAtCapacity = 5017,
    /** Session operation not allowed */
    Sessions_NotAllowed = 5018,
    /** Session operation not allowed */
    Sessions_PlayerSanctioned = 5019,
    
    /** Request filename was invalid */
    PlayerDataStorage_FilenameInvalid = 6000,
    /** Request filename was too long */
    PlayerDataStorage_FilenameLengthInvalid = 6001,
    /** Request filename contained invalid characters */
    PlayerDataStorage_FilenameInvalidChars = 6002,
    /** Request operation would grow file too large */
    PlayerDataStorage_FileSizeTooLarge = 6003,
    /** Request file length is not valid */
    PlayerDataStorage_FileSizeInvalid = 6004,
    /** Request file handle is not valid */
    PlayerDataStorage_FileHandleInvalid = 6005,
    /** Request data is invalid */
    PlayerDataStorage_DataInvalid = 6006,
    /** Request data length was invalid */
    PlayerDataStorage_DataLengthInvalid = 6007,
    /** Request start index was invalid */
    PlayerDataStorage_StartIndexInvalid = 6008,
    /** Request is in progress */
    PlayerDataStorage_RequestInProgress = 6009,
    /** User is marked as throttled which means he can't perform some operations because limits are exceeded. */
    PlayerDataStorage_UserThrottled = 6010,
    /** Encryption key is not set during SDK init. */
    PlayerDataStorage_EncryptionKeyNotSet = 6011,
    /** User data callback returned error (EOS_PlayerDataStorage_EWriteResult::EOS_WR_FailRequest or EOS_PlayerDataStorage_EReadResult::EOS_RR_FailRequest, */
    PlayerDataStorage_UserErrorFromDataCallback = 6012,
    /** User is trying to read file that has header from newer version of SDK. Game/SDK needs to be updated. */
    PlayerDataStorage_FileHeaderHasNewerVersion = 6013,
    /** The file is corrupted. In some cases retry can fix the issue. */
    PlayerDataStorage_FileCorrupted = 6014,
    
    /** EOS Auth service deemed the external token invalid */
    Connect_ExternalTokenValidationFailed = 7000,
    /** EOS Auth user already exists */
    Connect_UserAlreadyExists = 7001,
    /** EOS Auth expired */
    Connect_AuthExpired = 7002,
    /** EOS Auth invalid token */
    Connect_InvalidToken = 7003,
    /** EOS Auth doesn't support this token type */
    Connect_UnsupportedTokenType = 7004,
    /** EOS Auth Account link failure */
    Connect_LinkAccountFailed = 7005,
    /** EOS Auth External service for validation was unavailable */
    Connect_ExternalServiceUnavailable = 7006,
    /** EOS Auth External Service configuration failure with Dev Portal */
    Connect_ExternalServiceConfigurationFailure = 7007,
    /** EOS Auth Account link failure. Tried to link Nintendo Network Service Account without first linking Nintendo Account. DEPRECATED: The requirement has been removed and this error is no longer used. */
    Connect_LinkAccountFailedMissingNintendoIdAccount_DEPRECATED = 7008,
    
    /** The social overlay page failed to load */
    UI_SocialOverlayLoadError = 8000,
    /** Virtual Memory Functions are an inconsistent mix of functions and nullptrs */
    UI_InconsistentVirtualMemoryFunctions = 8001,
    
    /** Client has no permissions to modify this lobby */
    Lobby_NotOwner = 9000,
    /** Lobby lock required for operation */
    Lobby_InvalidLock = 9001,
    /** Lobby already exists in the system */
    Lobby_LobbyAlreadyExists = 9002,
    /** Lobby is already in progress */
    Lobby_SessionInProgress = 9003,
    /** Too many players to register with this lobby */
    Lobby_TooManyPlayers = 9004,
    /** Client has no permissions to access this lobby */
    Lobby_NoPermission = 9005,
    /** Invalid lobby session reference */
    Lobby_InvalidSession = 9006,
    /** Sandbox ID associated with auth didn't match */
    Lobby_SandboxNotAllowed = 9007,
    /** Invite failed to send */
    Lobby_InviteFailed = 9008,
    /** Invite was not found with the service */
    Lobby_InviteNotFound = 9009,
    /** This client may not modify the lobby */
    Lobby_UpsertNotAllowed = 9010,
    /** Backend nodes unavailable to process request */
    Lobby_AggregationFailed = 9011,
    /** Individual backend node is as capacity */
    Lobby_HostAtCapacity = 9012,
    /** Sandbox on node is at capacity */
    Lobby_SandboxAtCapacity = 9013,
    /** User has received too many invites */
    Lobby_TooManyInvites = 9014,
    /** Deployment on node is at capacity */
    Lobby_DeploymentAtCapacity = 9015,
    /** Lobby operation not allowed */
    Lobby_NotAllowed = 9016,
    /** While restoring a lost connection lobby ownership changed and only local member data was updated */
    Lobby_MemberUpdateOnly = 9017,
    /** Presence lobby already exists for the client */
    Lobby_PresenceLobbyExists = 9018,
    /** Operation requires lobby with voice enabled */
    Lobby_VoiceNotEnabled = 9019,
    /** The client platform does not match the allowed platform list for the lobby. */
    Lobby_PlatformNotAllowed = 9020,
    
    /** User callback that receives data from storage returned error. */
    TitleStorage_UserErrorFromDataCallback = 10000,
    /** User forgot to set Encryption key during platform init. Title Storage can't work without it. */
    TitleStorage_EncryptionKeyNotSet = 10001,
    /** Downloaded file is corrupted. */
    TitleStorage_FileCorrupted = 10002,
    /** Downloaded file's format is newer than client SDK version. */
    TitleStorage_FileHeaderHasNewerVersion = 10003,
    
    /** ModSdk process is already running. This error comes from the EOSSDK. */
    Mods_ModSdkProcessIsAlreadyRunning = 11000,
    /** ModSdk command is empty. Either the ModSdk configuration file is missing or the manifest location is empty. */
    Mods_ModSdkCommandIsEmpty = 11001,
    /** Creation of the ModSdk process failed. This error comes from the SDK. */
    Mods_ModSdkProcessCreationFailed = 11002,
    /** A critical error occurred in the external ModSdk process that we were unable to resolve. */
    Mods_CriticalError = 11003,
    /** A internal error occurred in the external ModSdk process that we were unable to resolve. */
    Mods_ToolInternalError = 11004,
    /** A IPC failure occurred in the external ModSdk process. */
    Mods_IPCFailure = 11005,
    /** A invalid IPC response received in the external ModSdk process. */
    Mods_InvalidIPCResponse = 11006,
    /** A URI Launch failure occurred in the external ModSdk process. */
    Mods_URILaunchFailure = 11007,
    /** Attempting to perform an action with a mod that is not installed. This error comes from the external ModSdk process. */
    Mods_ModIsNotInstalled = 11008,
    /** Attempting to perform an action on a game that the user doesn't own. This error comes from the external ModSdk process. */
    Mods_UserDoesNotOwnTheGame = 11009,
    /** Invalid result of the request to get the offer for the mod. This error comes from the external ModSdk process. */
    Mods_OfferRequestByIdInvalidResult = 11010,
    /** Could not find the offer for the mod. This error comes from the external ModSdk process. */
    Mods_CouldNotFindOffer = 11011,
    /** Request to get the offer for the mod failed. This error comes from the external ModSdk process. */
    Mods_OfferRequestByIdFailure = 11012,
    /** Request to purchase the mod failed. This error comes from the external ModSdk process. */
    Mods_PurchaseFailure = 11013,
    /** Attempting to perform an action on a game that is not installed or is partially installed. This error comes from the external ModSdk process. */
    Mods_InvalidGameInstallInfo = 11014,
    /** Failed to get manifest location. Either the ModSdk configuration file is missing or the manifest location is empty */
    Mods_CannotGetManifestLocation = 11015,
    /** Attempting to perform an action with a mod that does not support the current operating system. */
    Mods_UnsupportedOS = 11016,
    
    /** The anti-cheat client protection is not available. Check that the game was started using the anti-cheat bootstrapper. */
    AntiCheat_ClientProtectionNotAvailable = 12000,
    /** The current anti-cheat mode is incorrect for using this API */
    AntiCheat_InvalidMode = 12001,
    /** The ProductId provided to the anti-cheat client helper executable does not match what was used to initialize the EOS SDK */
    AntiCheat_ClientProductIdMismatch = 12002,
    /** The SandboxId provided to the anti-cheat client helper executable does not match what was used to initialize the EOS SDK */
    AntiCheat_ClientSandboxIdMismatch = 12003,
    /** (ProtectMessage/UnprotectMessage, No session key is available = but it is required to complete this operation */
    AntiCheat_ProtectMessageSessionKeyRequired = 12004,
    /** (ProtectMessage/UnprotectMessage, Message integrity is invalid */
    AntiCheat_ProtectMessageValidationFailed = 12005,
    /** (ProtectMessage/UnprotectMessage, Initialization failed */
    AntiCheat_ProtectMessageInitializationFailed = 12006,
    /** (RegisterPeer, Peer is already registered */
    AntiCheat_PeerAlreadyRegistered = 12007,
    /** (UnregisterPeer, Peer does not exist */
    AntiCheat_PeerNotFound = 12008,
    /** (ReceiveMessageFromPeer, Invalid call: Peer is not protected */
    AntiCheat_PeerNotProtected = 12009,
    /** The DeploymentId provided to the anti-cheat client helper executable does not match what was used to initialize the EOS SDK */
    AntiCheat_ClientDeploymentIdMismatch = 12010,
    /** EOS Connect DeviceID auth method is not supported for anti-cheat */
    AntiCheat_DeviceIdAuthIsNotSupported = 12011,
    
    /** EOS RTC room cannot accept more participants */
    RTC_TooManyParticipants = 13000,
    /** EOS RTC room already exists*/
    RTC_RoomAlreadyExists = 13001,
    /** The user kicked out from the room */
    RTC_UserKicked = 13002,
    /** The user is banned */
    RTC_UserBanned = 13003,
    /** EOS RTC room was left successfully */
    RTC_RoomWasLeft = 13004,
    /** Connection dropped due to long timeout */
    RTC_ReconnectionTimegateExpired = 13005,
    /** EOS RTC room was left due to platform release */
    RTC_ShutdownInvoked = 13006,
    /** EOS RTC operation failed because the user is in the local user's block list */
    RTC_UserIsInBlocklist = 13007,
    
    /** The number of available Snapshot IDs have all been exhausted. */
    ProgressionSnapshot_SnapshotIdUnavailable = 14000,
    
    /** The KWS user does not have a parental email associated with the account.  The parent account was unlinked or deleted */
    KWS_ParentEmailMissing = 15000,
    /** The KWS user is no longer a minor and trying to update the parent email */
    KWS_UserGraduated = 15001,
    
    /** EOS Android VM not stored */
    Android_JavaVMNotStored = 17000,
    /** EOS Android if Reserved is set it must reference stored VM */
    Android_ReservedMustReferenceLocalVM = 17001,
    /** EOS Android Reserved must not be provided */
    Android_ReservedMustBeNull = 17002,
    
    /** Patch required before the user can use the privilege */
    Permission_RequiredPatchAvailable = 18000,
    /** System update required before the user can use the privilege */
    Permission_RequiredSystemUpdate = 18001,
    /** Parental control failure usually */
    Permission_AgeRestrictionFailure = 18002,
    /** Premium Account Subscription required but not available */
    Permission_AccountTypeFailure = 18003,
    /** User restricted from chat */
    Permission_ChatRestriction = 18004,
    /** User restricted from User Generated Content */
    Permission_UGCRestriction = 18005,
    /** Online play is restricted */
    Permission_OnlinePlayRestricted = 18006,
    
    /** The application was not launched through the Bootstrapper. Desktop crossplay functionality is unavailable. */
    DesktopCrossplay_ApplicationNotBootstrapped = 19000,
    /** The redistributable service is not installed. */
    DesktopCrossplay_ServiceNotInstalled = 19001,
    /** The desktop crossplay service failed to start. */
    DesktopCrossplay_ServiceStartFailed = 19002,
    /** The desktop crossplay service is no longer running for an unknown reason. */
    DesktopCrossplay_ServiceNotRunning = 19003,
    
    /** When sending the custom invite failed. */
    CustomInvites_InviteFailed = 20000,
    
    /** The best display name could not be safely determined. */
    UserInfo_BestDisplayNameIndeterminate = 22000,
    
    /** OnNetworkRequested_DEPRECATED callback not set when initializing platform */
    ConsoleInit_OnNetworkRequestedDeprecatedCallbackNotSet = 23000,
    /** CacheStorageSizeKB must be a multiple of 16 **/
    ConsoleInit_CacheStorage_SizeKBNotMultipleOf16 = 23001,
    /** CacheStorageSizeKB is less than the minimum allowed **/
    ConsoleInit_CacheStorage_SizeKBBelowMinimumSize = 23002,
    /** CacheStorageSizeKB is greater than the maximum allowed (4000 MB, **/
    ConsoleInit_CacheStorage_SizeKBExceedsMaximumSize = 23003,
    /** CacheStorageIndex is out of its allowed range **/
    ConsoleInit_CacheStorage_IndexOutOfRangeRange = 23004,
    
    /** An unexpected error that we cannot identify has occurred. */
    EOS_UnexpectedError = 0x7FFFFFFF,
}