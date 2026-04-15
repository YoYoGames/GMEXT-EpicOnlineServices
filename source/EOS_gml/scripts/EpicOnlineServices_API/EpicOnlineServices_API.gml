// ##### extgen :: Auto-generated file do not edit!! #####

// #####################################################################
// # Macros
// #####################################################################

// #####################################################################
// # Enums
// #####################################################################

enum EpicResult
{
    Success = 0,
    NoConnection = 1,
    InvalidCredentials = 2,
    InvalidUser = 3,
    InvalidAuth = 4,
    AccessDenied = 5,
    MissingPermissions = 6,
    Token_Not_Account = 7,
    TooManyRequests = 8,
    AlreadyPending = 9,
    InvalidParameters = 10,
    InvalidRequest = 11,
    UnrecognizedResponse = 12,
    IncompatibleVersion = 13,
    NotConfigured = 14,
    AlreadyConfigured = 15,
    NotImplemented = 16,
    Canceled = 17,
    NotFound = 18,
    OperationWillRetry = 19,
    NoChange = 20,
    VersionMismatch = 21,
    LimitExceeded = 22,
    Disabled = 23,
    DuplicateNotAllowed = 24,
    MissingParameters_DEPRECATED = 25,
    InvalidSandboxId = 26,
    TimedOut = 27,
    PartialResult = 28,
    Missing_Role = 29,
    Missing_Feature = 30,
    Invalid_Sandbox = 31,
    Invalid_Deployment = 32,
    Invalid_Product = 33,
    Invalid_ProductUserID = 34,
    ServiceFailure = 35,
    CacheDirectoryMissing = 36,
    CacheDirectoryInvalid = 37,
    InvalidState = 38,
    RequestInProgress = 39,
    ApplicationSuspended = 40,
    NetworkDisconnected = 41,
    Auth_AccountLocked = 1001,
    Auth_AccountLockedForUpdate = 1002,
    Auth_InvalidRefreshToken = 1003,
    Auth_InvalidToken = 1004,
    Auth_AuthenticationFailure = 1005,
    Auth_InvalidPlatformToken = 1006,
    Auth_WrongAccount = 1007,
    Auth_WrongClient = 1008,
    Auth_FullAccountRequired = 1009,
    Auth_HeadlessAccountRequired = 1010,
    Auth_PasswordResetRequired = 1011,
    Auth_PasswordCannotBeReused = 1012,
    Auth_Expired = 1013,
    Auth_ScopeConsentRequired = 1014,
    Auth_ApplicationNotFound = 1015,
    Auth_ScopeNotFound = 1016,
    Auth_AccountFeatureRestricted = 1017,
    Auth_AccountPortalLoadError = 1018,
    Auth_CorrectiveActionRequired = 1019,
    Auth_PinGrantCode = 1020,
    Auth_PinGrantExpired = 1021,
    Auth_PinGrantPending = 1022,
    Auth_ExternalAuthNotLinked = 1030,
    Auth_ExternalAuthRevoked = 1032,
    Auth_ExternalAuthInvalid = 1033,
    Auth_ExternalAuthRestricted = 1034,
    Auth_ExternalAuthCannotLogin = 1035,
    Auth_ExternalAuthExpired = 1036,
    Auth_ExternalAuthIsLastLoginType = 1037,
    Auth_ExchangeCodeNotFound = 1040,
    Auth_OriginatingExchangeCodeSessionExpired = 1041,
    Auth_AccountNotActive = 1050,
    Auth_MFARequired = 1060,
    Auth_ParentalControls = 1070,
    Auth_NoRealId = 1080,
    Auth_UserInterfaceRequired = 1090,
    Friends_InviteAwaitingAcceptance = 2000,
    Friends_NoInvitation = 2001,
    Friends_AlreadyFriends = 2003,
    Friends_NotFriends = 2004,
    Friends_TargetUserTooManyInvites = 2005,
    Friends_LocalUserTooManyInvites = 2006,
    Friends_TargetUserFriendLimitExceeded = 2007,
    Friends_LocalUserFriendLimitExceeded = 2008,
    Presence_DataInvalid = 3000,
    Presence_DataLengthInvalid = 3001,
    Presence_DataKeyInvalid = 3002,
    Presence_DataKeyLengthInvalid = 3003,
    Presence_DataValueInvalid = 3004,
    Presence_DataValueLengthInvalid = 3005,
    Presence_RichTextInvalid = 3006,
    Presence_RichTextLengthInvalid = 3007,
    Presence_StatusInvalid = 3008,
    Ecom_EntitlementStale = 4000,
    Ecom_CatalogOfferStale = 4001,
    Ecom_CatalogItemStale = 4002,
    Ecom_CatalogOfferPriceInvalid = 4003,
    Ecom_CheckoutLoadError = 4004,
    Ecom_PurchaseProcessing = 4005,
    Sessions_SessionInProgress = 5000,
    Sessions_TooManyPlayers = 5001,
    Sessions_NoPermission = 5002,
    Sessions_SessionAlreadyExists = 5003,
    Sessions_InvalidLock = 5004,
    Sessions_InvalidSession = 5005,
    Sessions_SandboxNotAllowed = 5006,
    Sessions_InviteFailed = 5007,
    Sessions_InviteNotFound = 5008,
    Sessions_UpsertNotAllowed = 5009,
    Sessions_AggregationFailed = 5010,
    Sessions_HostAtCapacity = 5011,
    Sessions_SandboxAtCapacity = 5012,
    Sessions_SessionNotAnonymous = 5013,
    Sessions_OutOfSync = 5014,
    Sessions_TooManyInvites = 5015,
    Sessions_PresenceSessionExists = 5016,
    Sessions_DeploymentAtCapacity = 5017,
    Sessions_NotAllowed = 5018,
    Sessions_PlayerSanctioned = 5019,
    PlayerDataStorage_FilenameInvalid = 6000,
    PlayerDataStorage_FilenameLengthInvalid = 6001,
    PlayerDataStorage_FilenameInvalidChars = 6002,
    PlayerDataStorage_FileSizeTooLarge = 6003,
    PlayerDataStorage_FileSizeInvalid = 6004,
    PlayerDataStorage_FileHandleInvalid = 6005,
    PlayerDataStorage_DataInvalid = 6006,
    PlayerDataStorage_DataLengthInvalid = 6007,
    PlayerDataStorage_StartIndexInvalid = 6008,
    PlayerDataStorage_RequestInProgress = 6009,
    PlayerDataStorage_UserThrottled = 6010,
    PlayerDataStorage_EncryptionKeyNotSet = 6011,
    PlayerDataStorage_UserErrorFromDataCallback = 6012,
    PlayerDataStorage_FileHeaderHasNewerVersion = 6013,
    PlayerDataStorage_FileCorrupted = 6014,
    Connect_ExternalTokenValidationFailed = 7000,
    Connect_UserAlreadyExists = 7001,
    Connect_AuthExpired = 7002,
    Connect_InvalidToken = 7003,
    Connect_UnsupportedTokenType = 7004,
    Connect_LinkAccountFailed = 7005,
    Connect_ExternalServiceUnavailable = 7006,
    Connect_ExternalServiceConfigurationFailure = 7007,
    Connect_LinkAccountFailedMissingNintendoIdAccount_DEPRECATED = 7008,
    UI_SocialOverlayLoadError = 8000,
    UI_InconsistentVirtualMemoryFunctions = 8001,
    Lobby_NotOwner = 9000,
    Lobby_InvalidLock = 9001,
    Lobby_LobbyAlreadyExists = 9002,
    Lobby_SessionInProgress = 9003,
    Lobby_TooManyPlayers = 9004,
    Lobby_NoPermission = 9005,
    Lobby_InvalidSession = 9006,
    Lobby_SandboxNotAllowed = 9007,
    Lobby_InviteFailed = 9008,
    Lobby_InviteNotFound = 9009,
    Lobby_UpsertNotAllowed = 9010,
    Lobby_AggregationFailed = 9011,
    Lobby_HostAtCapacity = 9012,
    Lobby_SandboxAtCapacity = 9013,
    Lobby_TooManyInvites = 9014,
    Lobby_DeploymentAtCapacity = 9015,
    Lobby_NotAllowed = 9016,
    Lobby_MemberUpdateOnly = 9017,
    Lobby_PresenceLobbyExists = 9018,
    Lobby_VoiceNotEnabled = 9019,
    Lobby_PlatformNotAllowed = 9020,
    UnexpectedError = 2147483647
}

enum EpicAntiCheatClientMode
{
    Invalid = 0,
    ClientServer = 1,
    PeerToPeer = 2
}

enum EpicAntiCheatClientViolationType
{
    Invalid = 0,
    IntegrityCatalogNotFound = 1,
    IntegrityCatalogError = 2,
    IntegrityCatalogCertificateRevoked = 3,
    IntegrityCatalogMissingMainExecutable = 4,
    GameFileMismatch = 5,
    RequiredGameFileNotFound = 6,
    UnknownGameFileForbidden = 7,
    SystemFileUntrusted = 8,
    ForbiddenModuleLoaded = 9,
    CorruptedMemory = 10,
    ForbiddenToolDetected = 11,
    InternalAntiCheatViolation = 12,
    CorruptedNetworkMessageFlow = 13,
    VirtualMachineNotAllowed = 14,
    ForbiddenSystemConfiguration = 15
}

enum EpicAntiCheatCommonClientType
{
    ProtectedClient = 0,
    UnprotectedClient = 1,
    AIBot = 2
}

enum EpicAntiCheatCommonClientPlatform
{
    Unknown = 0,
    Windows = 1,
    Mac = 2,
    Linux = 3,
    Xbox = 4,
    PlayStation = 5,
    Nintendo = 6,
    IOS = 7,
    Android = 8
}

enum EpicAntiCheatCommonClientAction
{
    Invalid = 0,
    RemovePlayer = 1
}

enum EpicAntiCheatCommonClientActionReason
{
    Invalid = 0,
    InternalError = 1,
    InvalidMessage = 2,
    AuthenticationFailed = 3,
    NullClient = 4,
    HeartbeatTimeout = 5,
    ClientViolation = 6,
    BackendViolation = 7,
    TemporaryCooldown = 8,
    TemporaryBanned = 9,
    PermanentBanned = 10
}

enum EpicAntiCheatCommonClientAuthStatus
{
    Invalid = 0,
    LocalAuthComplete = 1,
    RemoteAuthComplete = 2
}

enum EpicAntiCheatCommonClientFlags
{
    None = 0
}

enum EpicAntiCheatCommonClientInput
{
    Unknown = 0,
    MouseKeyboard = 1,
    Gamepad = 2,
    TouchInput = 3
}

enum EpicAntiCheatCommonEventType
{
    Invalid = 0,
    GameEvent = 1,
    PlayerEvent = 2
}

enum EpicAntiCheatCommonEventParamType
{
    Invalid = 0,
    ClientHandle = 1,
    String = 2,
    UInt32 = 3,
    Int32 = 4,
    UInt64 = 5,
    Int64 = 6,
    Vector3f = 7,
    Quat = 8,
    Float = 9
}

enum EpicAntiCheatCommonGameRoundCompetitionType
{
    None = 0,
    Casual = 1,
    Ranked = 2,
    Competitive = 3
}

enum EpicAntiCheatCommonPlayerMovementState
{
    None = 0,
    Crouching = 1,
    Prone = 2,
    Mounted = 3,
    Swimming = 4,
    Falling = 5,
    Flying = 6,
    OnLadder = 7
}

enum EpicAntiCheatCommonPlayerTakeDamageSource
{
    None = 0,
    Player = 1,
    NonPlayerCharacter = 2,
    World = 3
}

enum EpicAntiCheatCommonPlayerTakeDamageType
{
    None = 0,
    PointDamage = 1,
    RadialDamage = 2,
    DamageOverTime = 3
}

enum EpicAntiCheatCommonPlayerTakeDamageResult
{
    None = 0,
    DownedDeprecated = 1,
    EliminatedDeprecated = 2,
    NormalToDowned = 3,
    NormalToEliminated = 4,
    DownedToEliminated = 5
}

enum EpicLoginCredentialType
{
    Password = 0,
    ExchangeCode = 1,
    PersistentAuth = 2,
    DeviceCode = 3,
    Developer = 4,
    RefreshToken = 5,
    AccountPortal = 6,
    ExternalAuth = 7
}

enum EpicAuthTokenType
{
    Client = 0,
    User = 1
}

enum EpicAuthScopeFlags
{
    NoFlags = 0,
    BasicProfile = 1,
    FriendsList = 2,
    Presence = 4,
    FriendsManagement = 8,
    Email = 16,
    Country = 32
}

enum EpicLinkAccountFlags
{
    NoFlags = 0,
    NintendoNsaId = 1
}

enum Epicname
{
}

enum EpicLoginStatus
{
    NotLoggedIn = 0,
    UsingLocalProfile = 1,
    LoggedIn = 2
}

enum EpicAttributeType
{
    Boolean = 0,
    Int64 = 1,
    Double = 2,
    String = 3
}

enum EpicComparisonOp
{
    Equal = 0,
    NotEqual = 1,
    GreaterThan = 2,
    GreaterThanOrEqual = 3,
    LessThan = 4,
    LessThanOrEqual = 5,
    Distance = 6,
    AnyOf = 7,
    NotAnyOf = 8,
    OneOf = 9,
    NotOneOf = 10,
    Contains = 11
}

enum EpicExternalAccountType
{
    Epic = 0,
    Steam = 1,
    Psn = 2,
    Xbl = 3,
    Discord = 4,
    Gog = 5,
    Nintendo = 6,
    Uplay = 7,
    OpenId = 8,
    Apple = 9,
    Google = 10,
    Oculus = 11,
    ItchIo = 12,
    Amazon = 13,
    Viveport = 14
}

enum EpicExternalCredentialType
{
    Epic = 0,
    SteamAppTicket = 1,
    PsnIdToken = 2,
    XblXstsToken = 3,
    DiscordAccessToken = 4,
    GogSessionTicket = 5,
    NintendoIdToken = 6,
    NintendoNsaIdToken = 7,
    UplayAccessToken = 8,
    OpenIdAccessToken = 9,
    DeviceIdAccessToken = 10,
    AppleIdToken = 11,
    GoogleIdToken = 12,
    OculusUseridNonce = 13,
    ItchIoJwt = 14,
    ItchIoKey = 15,
    EpicIdToken = 16,
    AmazonAccessToken = 17,
    SteamSessionTicket = 18,
    ViveportUserToken = 19
}

enum EpicRequestToJoinResponse
{
    Accepted = 0,
    Rejected = 1
}

enum EpicOwnershipStatus
{
    NotOwned = 0,
    Owned = 1
}

enum EpicEcomItemType
{
    Durable = 0,
    Consumable = 1,
    Other = 2
}

enum EpicCheckoutOrientation
{
    Default = 0,
    Portrait = 1,
    Landscape = 2
}

enum EpicFriendsStatus
{
    NotFriends = 0,
    InviteSent = 1,
    InviteReceived = 2,
    Friends = 3
}

enum EpicIntegratedPlatformManagementFlags
{
    Disabled = 1,
    LibraryManagedByApplication = 2,
    LibraryManagedBySDK = 4,
    DisablePresenceMirroring = 8,
    DisableSDKManagedSessions = 16,
    PreferEOSIdentity = 32,
    PreferIntegratedIdentity = 64,
    ApplicationManagedIdentityLogin = 128
}

enum EpicIntegratedPlatformPreLogoutAction
{
    ProcessLogoutImmediately = 0,
    DeferLogout = 1
}

enum EpicKWSPermissionStatus
{
    Granted = 0,
    Rejected = 1,
    Pending = 2
}

enum EpicLeaderboardAggregation
{
    Min = 0,
    Max = 1,
    Sum = 2,
    Latest = 3
}

enum EpicLobbyPermissionLevel
{
    PublicAdvertised = 0,
    JoinViaPresence = 1,
    InviteOnly = 2
}

enum EpicLobbyAttributeVisibility
{
    Public = 0,
    Private = 1
}

enum EpicLobbyMemberStatus
{
    Joined = 0,
    Left = 1,
    Disconnected = 2,
    Kicked = 3,
    Promoted = 4,
    Closed = 5
}

enum EpicLobbyRTCRoomJoinActionType
{
    AutomaticJoin = 0,
    ManualJoin = 1
}

enum EpicLogLevel
{
    Off = 0,
    Fatal = 100,
    Error = 200,
    Warning = 300,
    Info = 400,
    Verbose = 500,
    VeryVerbose = 600
}

enum EpicLogCategory
{
    Core = 0,
    Auth = 1,
    Friends = 2,
    Presence = 3,
    UserInfo = 4,
    HttpSerialization = 5,
    Ecom = 6,
    P2P = 7,
    Sessions = 8,
    RateLimiter = 9,
    PlayerDataStorage = 10,
    Analytics = 11,
    Messaging = 12,
    Connect = 13,
    Overlay = 14,
    Achievements = 15,
    Stats = 16,
    UI = 17,
    Lobby = 18,
    Leaderboards = 19,
    Keychain = 20,
    IntegratedPlatform = 21,
    TitleStorage = 22,
    Mods = 23,
    AntiCheat = 24,
    Reports = 25,
    Sanctions = 26,
    ProgressionSnapshots = 27,
    KWS = 28,
    RTC = 29,
    RTCAdmin = 30,
    CustomInvites = 31,
    AllCategories = 2147483647
}

enum EpicUserControllerType
{
    Unknown = 0,
    MouseKeyboard = 1,
    GamepadControl = 2,
    TouchControl = 3
}

enum EpicMetricsAccountIdType
{
    Epic = 0,
    External = 1
}

enum EpicModEnumerationType
{
    Installed = 0,
    AllAvailable = 1
}

enum EpicNATType
{
    Unknown = 0,
    Open = 1,
    Moderate = 2,
    Strict = 3
}

enum EpicPacketReliability
{
    UnreliableUnordered = 0,
    ReliableUnordered = 1,
    ReliableOrdered = 2
}

enum EpicConnectionEstablishedType
{
    NewConnection = 0,
    Reconnection = 1
}

enum EpicNetworkConnectionType
{
    NoConnection = 0,
    DirectConnection = 1,
    RelayedConnection = 2
}

enum EpicConnectionClosedReason
{
    Unknown = 0,
    ClosedByLocalUser = 1,
    ClosedByPeer = 2,
    TimedOut = 3,
    TooManyConnections = 4,
    InvalidMessage = 5,
    InvalidData = 6,
    ConnectionFailed = 7,
    ConnectionClosed = 8,
    NegotiationFailed = 9,
    UnexpectedError = 10,
    ConnectionIgnored = 11
}

enum EpicRelayControl
{
    NoRelays = 0,
    AllowRelays = 1,
    ForceRelays = 2
}

enum EpicPlayerDataStorageReadResult
{
    ContinueReading = 1,
    FailRequest = 2,
    CancelRequest = 3
}

enum EpicPlayerDataStorageWriteResult
{
    ContinueWriting = 1,
    CompleteRequest = 2,
    FailRequest = 3,
    CancelRequest = 4
}

enum EpicPresenceStatus
{
    Offline = 0,
    Online = 1,
    Away = 2,
    ExtendedAway = 3,
    DoNotDisturb = 4
}

enum EpicPlayerReportsCategory
{
    Invalid = 0,
    Cheating = 1,
    Exploiting = 2,
    OffensiveProfile = 3,
    VerbalAbuse = 4,
    Scamming = 5,
    Spamming = 6,
    Other = 7
}

enum EpicRTCAudioStatus
{
    Unsupported = 0,
    Enabled = 1,
    Disabled = 2,
    AdminDisabled = 3,
    NotListeningDisabled = 4
}

enum EpicRTCAudioInputStatus
{
    Idle = 0,
    Recording = 1,
    RecordingSilent = 2,
    RecordingDisconnected = 3,
    Failed = 4
}

enum EpicRTCAudioOutputStatus
{
    Idle = 0,
    Playing = 1,
    Failed = 2
}

enum EpicRTCDataStatus
{
    Unsupported = 0,
    Enabled = 1,
    Disabled = 2
}

enum EpicRTCParticipantStatus
{
    Joined = 0,
    Left = 1
}

enum EpicSanctionAppealReason
{
    Invalid = 0,
    IncorrectSanction = 1,
    CompromisedAccount = 2,
    UnfairPunishment = 3,
    AppealForForgiveness = 4
}

enum EpicOnlineSessionState
{
    NoSession = 0,
    Creating = 1,
    Pending = 2,
    Starting = 3,
    InProgress = 4,
    Ending = 5,
    Ended = 6,
    Destroying = 7
}

enum EpicSessionAttributeAdvertisementType
{
    DontAdvertise = 0,
    Advertise = 1
}

enum EpicOnlineSessionPermissionLevel
{
    PublicAdvertised = 0,
    JoinViaPresence = 1,
    InviteOnly = 2
}

enum EpicTitleStorageReadResult
{
    ContinueReading = 1,
    FailRequest = 2,
    CancelRequest = 3
}

enum EpicRTCBackgroundMode
{
    LeaveRooms = 0,
    KeepRoomsAlive = 1
}

enum EpicApplicationStatus
{
    BackgroundConstrained = 0,
    BackgroundUnconstrained = 1,
    BackgroundSuspended = 2,
    Foreground = 3
}

enum EpicNetworkStatus
{
    Disabled = 0,
    Offline = 1,
    Online = 2
}

enum EpicDesktopCrossplayStatus
{
    Ok = 0,
    ApplicationNotBootstrapped = 1,
    ServiceNotInstalled = 2,
    ServiceStartFailed = 3,
    ServiceNotRunning = 4,
    OverlayDisabled = 5,
    OverlayNotInstalled = 6,
    OverlayTrustCheckFailed = 7,
    OverlayLoadFailed = 8
}

enum EpicUINotificationLocation
{
    TopLeft = 0,
    TopRight = 1,
    BottomLeft = 2,
    BottomRight = 3
}

// #####################################################################
// # Constructors
// #####################################################################

/**
 * @returns {Struct.EpicLoggingMessage} 
 */
function EpicLoggingMessage() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 2544770280;

    self.category = undefined;
    self.level = undefined;
    self.message = undefined;

}

/**
 * @returns {Struct.EpicAuthLoginCallbackInfo} 
 */
function EpicAuthLoginCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 3139004448;

    self.result_code = undefined;
    self.local_user_id = undefined;
    self.selected_account_id = undefined;
    self.has_continuance_token = undefined;

}

/**
 * @returns {Struct.EpicAuthLogoutCallbackInfo} 
 */
function EpicAuthLogoutCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 2665356655;

    self.result_code = undefined;
    self.local_user_id = undefined;

}

/**
 * @returns {Struct.EpicAuthLinkAccountCallbackInfo} 
 */
function EpicAuthLinkAccountCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1132751930;

    self.result_code = undefined;
    self.local_user_id = undefined;
    self.selected_account_id = undefined;

}

/**
 * @returns {Struct.EpicAuthDeletePersistentAuthCallbackInfo} 
 */
function EpicAuthDeletePersistentAuthCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 2046774517;

    self.result_code = undefined;

}

/**
 * @returns {Struct.EpicAuthIdToken} 
 */
function EpicAuthIdToken() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1751511736;

    self.account_id = undefined;
    self.json_web_token = undefined;

}

/**
 * @returns {Struct.EpicAuthUserAuthToken} 
 */
function EpicAuthUserAuthToken() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 4253044112;

    self.app = undefined;
    self.client_id = undefined;
    self.account_id = undefined;
    self.access_token = undefined;
    self.expires_in = undefined;
    self.expires_at = undefined;
    self.auth_type = undefined;
    self.refresh_token = undefined;
    self.refresh_expires_in = undefined;
    self.refresh_expires_at = undefined;

}

/**
 * @returns {Struct.EpicAuthQueryIdTokenCallbackInfo} 
 */
function EpicAuthQueryIdTokenCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 3035104243;

    self.result_code = undefined;
    self.local_user_id = undefined;
    self.target_account_id = undefined;

}

/**
 * @returns {Struct.EpicAuthVerifyIdTokenCallbackInfo} 
 */
function EpicAuthVerifyIdTokenCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 2714618644;

    self.result_code = undefined;
    self.application_id = undefined;
    self.client_id = undefined;
    self.product_id = undefined;
    self.sandbox_id = undefined;
    self.deployment_id = undefined;
    self.display_name = undefined;
    self.is_external_account_info_present = undefined;

}

/**
 * @returns {Struct.EpicAuthVerifyUserAuthCallbackInfo} 
 */
function EpicAuthVerifyUserAuthCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1830036261;

    self.result_code = undefined;

}

/**
 * @returns {Struct.EpicAuthLoginStatusChangedCallbackInfo} 
 */
function EpicAuthLoginStatusChangedCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 643455112;

    self.local_user_id = undefined;
    self.previous_status = undefined;
    self.current_status = undefined;

}

/**
 * @returns {Struct.EpicConnectLoginCallbackInfo} 
 */
function EpicConnectLoginCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1293908136;

    self.result_code = undefined;
    self.local_user_id = undefined;
    self.has_continuance_token = undefined;

}

/**
 * @returns {Struct.EpicConnectCreateUserCallbackInfo} 
 */
function EpicConnectCreateUserCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 3066830286;

    self.result_code = undefined;
    self.local_user_id = undefined;

}

/**
 * @returns {Struct.EpicConnectLinkAccountCallbackInfo} 
 */
function EpicConnectLinkAccountCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 3154103970;

    self.result_code = undefined;
    self.local_user_id = undefined;

}

/**
 * @returns {Struct.EpicConnectUnlinkAccountCallbackInfo} 
 */
function EpicConnectUnlinkAccountCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1969400687;

    self.result_code = undefined;
    self.local_user_id = undefined;

}

/**
 * @returns {Struct.EpicConnectCreateDeviceIdCallbackInfo} 
 */
function EpicConnectCreateDeviceIdCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 71214618;

    self.result_code = undefined;
    self.device_model = undefined;

}

/**
 * @returns {Struct.EpicConnectDeleteDeviceIdCallbackInfo} 
 */
function EpicConnectDeleteDeviceIdCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1424948765;

    self.result_code = undefined;

}

/**
 * @returns {Struct.EpicConnectTransferDeviceIdAccountCallbackInfo} 
 */
function EpicConnectTransferDeviceIdAccountCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 4022429194;

    self.result_code = undefined;
    self.local_user_id = undefined;

}

/**
 * @returns {Struct.EpicConnectLogoutCallbackInfo} 
 */
function EpicConnectLogoutCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 4007944407;

    self.result_code = undefined;
    self.local_user_id = undefined;

}

/**
 * @returns {Struct.EpicConnectIdToken} 
 */
function EpicConnectIdToken() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 2383220416;

    self.product_user_id = undefined;
    self.json_web_token = undefined;

}

/**
 * @returns {Struct.EpicConnectExternalAccountInfo} 
 */
function EpicConnectExternalAccountInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 11263560;

    self.product_user_id = undefined;
    self.display_name = undefined;
    self.account_id = undefined;
    self.account_id_type = undefined;
    self.last_login_time = undefined;

}

/**
 * @returns {Struct.EpicConnectVerifyIdTokenCallbackInfo} 
 */
function EpicConnectVerifyIdTokenCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 3320198844;

    self.result_code = undefined;

}

/**
 * @returns {Struct.EpicConnectQueryExternalAccountMappingsCallbackInfo} 
 */
function EpicConnectQueryExternalAccountMappingsCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 351749604;

    self.result_code = undefined;
    self.local_user_id = undefined;

}

/**
 * @returns {Struct.EpicConnectQueryProductUserIdMappingsCallbackInfo} 
 */
function EpicConnectQueryProductUserIdMappingsCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 2282420771;

    self.result_code = undefined;
    self.local_user_id = undefined;

}

/**
 * @returns {Struct.EpicConnectAuthExpirationCallbackInfo} 
 */
function EpicConnectAuthExpirationCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 3341381898;

    self.local_user_id = undefined;

}

/**
 * @returns {Struct.EpicConnectLoginStatusChangedCallbackInfo} 
 */
function EpicConnectLoginStatusChangedCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1430081632;

    self.local_user_id = undefined;
    self.previous_status = undefined;
    self.current_status = undefined;

}

/**
 * @returns {Struct.EpicFriendsQueryFriendsCallbackInfo} 
 */
function EpicFriendsQueryFriendsCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 350841263;

    self.result_code = undefined;
    self.local_user_id = undefined;
    self.target_user_id = undefined;

}

/**
 * @returns {Struct.EpicFriendsFriendsUpdateCallbackInfo} 
 */
function EpicFriendsFriendsUpdateCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 2115382564;

    self.local_user_id = undefined;
    self.target_user_id = undefined;
    self.previous_status = undefined;
    self.current_status = undefined;

}

/**
 * @returns {Struct.EpicUserInfo} 
 */
function EpicUserInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1683777391;

    self.user_id = undefined;
    self.country = undefined;
    self.display_name = undefined;
    self.preferred_language = undefined;
    self.nickname = undefined;

}

/**
 * @returns {Struct.EpicUserInfoQueryUserInfoCallbackInfo} 
 */
function EpicUserInfoQueryUserInfoCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1836305293;

    self.result_code = undefined;
    self.local_user_id = undefined;
    self.target_user_id = undefined;

}

/**
 * @returns {Struct.EpicUserInfoExternalUserInfo} 
 */
function EpicUserInfoExternalUserInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1005653235;

    self.account_id = undefined;
    self.account_type = undefined;
    self.display_name = undefined;

}

/**
 * @returns {Struct.EpicStatsStat} 
 */
function EpicStatsStat() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 3006552545;

    self.name = undefined;
    self.start_time = undefined;
    self.end_time = undefined;
    self.value = undefined;

}

/**
 * @returns {Struct.EpicStatsIngestStatCallbackInfo} 
 */
function EpicStatsIngestStatCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 702629062;

    self.result_code = undefined;
    self.local_user_id = undefined;
    self.target_user_id = undefined;

}

/**
 * @returns {Struct.EpicStatsQueryStatsCallbackInfo} 
 */
function EpicStatsQueryStatsCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1432143255;

    self.result_code = undefined;
    self.local_user_id = undefined;
    self.target_user_id = undefined;

}

/**
 * @returns {Struct.EpicUIShowFriendsCallbackInfo} 
 */
function EpicUIShowFriendsCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 429504239;

    self.result_code = undefined;
    self.local_user_id = undefined;

}

/**
 * @returns {Struct.EpicUIShowNativeProfileCallbackInfo} 
 */
function EpicUIShowNativeProfileCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 2358945394;

    self.result_code = undefined;
    self.local_user_id = undefined;
    self.target_user_id = undefined;

}

/**
 * @returns {Struct.EpicUIDisplaySettingsUpdatedCallbackInfo} 
 */
function EpicUIDisplaySettingsUpdatedCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1853825207;

    self.is_visible = undefined;
    self.notification_location = undefined;

}

/**
 * @returns {Struct.EpicReportsSendPlayerBehaviorReportCallbackInfo} 
 */
function EpicReportsSendPlayerBehaviorReportCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 4159615247;

    self.result_code = undefined;
    self.reporter_user_id = undefined;
    self.reported_user_id = undefined;

}

/**
 * @returns {Struct.EpicSanctionsPlayerSanction} 
 */
function EpicSanctionsPlayerSanction() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 960613414;

    self.time_placed = undefined;
    self.action = undefined;
    self.time_expires = undefined;
    self.reference_id = undefined;
    self.justification = undefined;

}

/**
 * @returns {Struct.EpicSanctionsQueryActivePlayerSanctionsCallbackInfo} 
 */
function EpicSanctionsQueryActivePlayerSanctionsCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 640171590;

    self.result_code = undefined;
    self.target_user_id = undefined;

}

/**
 * @returns {Struct.EpicSanctionsCreatePlayerSanctionAppealCallbackInfo} 
 */
function EpicSanctionsCreatePlayerSanctionAppealCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 3457110082;

    self.result_code = undefined;
    self.local_user_id = undefined;
    self.reference_id = undefined;

}

/**
 * @returns {Struct.EpicAchievementsQueryDefinitionsCallbackInfo} 
 */
function EpicAchievementsQueryDefinitionsCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 963574889;

    self.result_code = undefined;

}

/**
 * @returns {Struct.EpicAchievementsQueryPlayerAchievementsCallbackInfo} 
 */
function EpicAchievementsQueryPlayerAchievementsCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 202425218;

    self.result_code = undefined;
    self.user_id = undefined;
    self.target_user_id = undefined;

}

/**
 * @returns {Struct.EpicAchievementsDefinition} 
 */
function EpicAchievementsDefinition() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 321906837;

    self.achievement_id = undefined;
    self.unlocked_display_name = undefined;
    self.unlocked_description = undefined;
    self.locked_display_name = undefined;
    self.locked_description = undefined;
    self.flavor_text = undefined;
    self.completion_description = undefined;
    self.unlocked_icon_url = undefined;
    self.locked_icon_url = undefined;
    self.is_hidden = undefined;
    self.stat_thresholds_count = undefined;

}

/**
 * @returns {Struct.EpicPlayerAchievement} 
 */
function EpicPlayerAchievement() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1273934528;

    self.achievement_id = undefined;
    self.progress = undefined;
    self.unlock_time = undefined;
    self.stat_info_count = undefined;

}

/**
 * @returns {Struct.EpicAchievementsUnlockAchievementsCallbackInfo} 
 */
function EpicAchievementsUnlockAchievementsCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 163643235;

    self.result_code = undefined;
    self.user_id = undefined;
    self.achievements_count = undefined;

}

/**
 * @returns {Struct.EpicAchievementsDefinitionV2} 
 */
function EpicAchievementsDefinitionV2() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1226382737;

    self.achievement_id = undefined;
    self.unlocked_display_name = undefined;
    self.unlocked_description = undefined;
    self.locked_display_name = undefined;
    self.locked_description = undefined;
    self.flavor_text = undefined;
    self.completion_description = undefined;
    self.unlocked_icon_url = undefined;
    self.locked_icon_url = undefined;
    self.is_hidden = undefined;
    self.stat_thresholds_count = undefined;

}

/**
 * @returns {Struct.EpicAchievementsUnlockedV2CallbackInfo} 
 */
function EpicAchievementsUnlockedV2CallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 4019062398;

    self.user_id = undefined;
    self.achievement_id = undefined;
    self.unlock_time = undefined;

}

/**
 * @returns {Struct.EpicLeaderboardsQueryDefinitionsCallbackInfo} 
 */
function EpicLeaderboardsQueryDefinitionsCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 2321716729;

    self.result_code = undefined;

}

/**
 * @returns {Struct.EpicLeaderboardsQueryRanksCallbackInfo} 
 */
function EpicLeaderboardsQueryRanksCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 430442548;

    self.result_code = undefined;

}

/**
 * @returns {Struct.EpicLeaderboardsQueryUserScoresCallbackInfo} 
 */
function EpicLeaderboardsQueryUserScoresCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 604033539;

    self.result_code = undefined;

}

/**
 * @returns {Struct.EpicLeaderboardDefinition} 
 */
function EpicLeaderboardDefinition() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 2387405018;

    self.leaderboard_id = undefined;
    self.stat_name = undefined;
    self.start_time = undefined;
    self.end_time = undefined;
    self.aggregation = undefined;

}

/**
 * @returns {Struct.EpicLeaderboardRecord} 
 */
function EpicLeaderboardRecord() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1204262510;

    self.user_id = undefined;
    self.rank = undefined;
    self.score = undefined;
    self.user_display_name = undefined;

}

/**
 * @returns {Struct.EpicLeaderboardUserScore} 
 */
function EpicLeaderboardUserScore() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 2642129982;

    self.user_id = undefined;
    self.stat_name = undefined;
    self.score = undefined;

}

/**
 * @returns {Struct.EpicPresenceInfo} 
 */
function EpicPresenceInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 3479760485;

    self.user_id = undefined;
    self.status = undefined;
    self.product_id = undefined;
    self.product_version = undefined;
    self.platform = undefined;
    self.rich_text = undefined;
    self.records_count = undefined;

}

/**
 * @returns {Struct.EpicPresenceQueryPresenceCallbackInfo} 
 */
function EpicPresenceQueryPresenceCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 621721397;

    self.result_code = undefined;
    self.local_user_id = undefined;
    self.target_user_id = undefined;

}

/**
 * @returns {Struct.EpicPresenceSetPresenceCallbackInfo} 
 */
function EpicPresenceSetPresenceCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1660898965;

    self.result_code = undefined;
    self.local_user_id = undefined;

}

/**
 * @returns {Struct.EpicPresenceChangedCallbackInfo} 
 */
function EpicPresenceChangedCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1205124856;

    self.local_user_id = undefined;
    self.presence_user_id = undefined;

}

/**
 * @returns {Struct.EpicPresenceJoinGameAcceptedCallbackInfo} 
 */
function EpicPresenceJoinGameAcceptedCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 4124063953;

    self.join_info = undefined;
    self.local_user_id = undefined;
    self.target_user_id = undefined;
    self.ui_event_id = undefined;

}

/**
 * @returns {Struct.EpicSessionsUpdateSessionCallbackInfo} 
 */
function EpicSessionsUpdateSessionCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1754948111;

    self.result_code = undefined;
    self.session_name = undefined;

}

/**
 * @returns {Struct.EpicSessionsDestroySessionCallbackInfo} 
 */
function EpicSessionsDestroySessionCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1372850476;

    self.result_code = undefined;
    self.session_name = undefined;

}

/**
 * @returns {Struct.EpicSessionsStartSessionCallbackInfo} 
 */
function EpicSessionsStartSessionCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1019343938;

    self.result_code = undefined;
    self.session_name = undefined;

}

/**
 * @returns {Struct.EpicSessionsEndSessionCallbackInfo} 
 */
function EpicSessionsEndSessionCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1091212169;

    self.result_code = undefined;
    self.session_name = undefined;

}

/**
 * @returns {Struct.EpicSessionsJoinSessionCallbackInfo} 
 */
function EpicSessionsJoinSessionCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 2120184376;

    self.result_code = undefined;
    self.session_name = undefined;

}

/**
 * @returns {Struct.EpicSessionsRegisterPlayersCallbackInfo} 
 */
function EpicSessionsRegisterPlayersCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 3155548645;

    self.result_code = undefined;
    self.session_name = undefined;

}

/**
 * @returns {Struct.EpicSessionsUnregisterPlayersCallbackInfo} 
 */
function EpicSessionsUnregisterPlayersCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 2359374832;

    self.result_code = undefined;
    self.session_name = undefined;

}

/**
 * @returns {Struct.EpicSessionsFindCallbackInfo} 
 */
function EpicSessionsFindCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1379390445;

    self.result_code = undefined;

}

/**
 * @returns {Struct.EpicSessionDetailsInfo} 
 */
function EpicSessionDetailsInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 2935789082;

    self.session_id = undefined;
    self.host_address = undefined;
    self.bucket_id = undefined;
    self.session_owner_user_id = undefined;
    self.num_open_public_connections = undefined;
    self.settings_count = undefined;

}

/**
 * @returns {Struct.EpicActiveSessionInfo} 
 */
function EpicActiveSessionInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 996543382;

    self.session_name = undefined;
    self.local_user_id = undefined;
    self.session_id = undefined;
    self.bucket_id = undefined;

}

/**
 * @returns {Struct.EpicSessionsSessionInviteReceivedCallbackInfo} 
 */
function EpicSessionsSessionInviteReceivedCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1505067074;

    self.local_user_id = undefined;
    self.target_user_id = undefined;
    self.invite_id = undefined;

}

/**
 * @returns {Struct.EpicSessionsSessionInviteAcceptedCallbackInfo} 
 */
function EpicSessionsSessionInviteAcceptedCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 3586805024;

    self.local_user_id = undefined;
    self.target_user_id = undefined;
    self.invite_id = undefined;

}

/**
 * @returns {Struct.EpicSessionsJoinSessionAcceptedCallbackInfo} 
 */
function EpicSessionsJoinSessionAcceptedCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 2596263193;

    self.ui_event_id = undefined;

}

/**
 * @returns {Struct.EpicLobbyCreateLobbyCallbackInfo} 
 */
function EpicLobbyCreateLobbyCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 2224110395;

    self.result_code = undefined;
    self.lobby_id = undefined;
    self.local_user_id = undefined;

}

/**
 * @returns {Struct.EpicLobbyDestroyLobbyCallbackInfo} 
 */
function EpicLobbyDestroyLobbyCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 361601117;

    self.result_code = undefined;
    self.lobby_id = undefined;
    self.local_user_id = undefined;

}

/**
 * @returns {Struct.EpicLobbyJoinLobbyCallbackInfo} 
 */
function EpicLobbyJoinLobbyCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 361541383;

    self.result_code = undefined;
    self.lobby_id = undefined;
    self.local_user_id = undefined;

}

/**
 * @returns {Struct.EpicLobbyLeaveLobbyCallbackInfo} 
 */
function EpicLobbyLeaveLobbyCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 3943378766;

    self.result_code = undefined;
    self.lobby_id = undefined;
    self.local_user_id = undefined;

}

/**
 * @returns {Struct.EpicLobbyUpdateLobbyCallbackInfo} 
 */
function EpicLobbyUpdateLobbyCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 3549428012;

    self.result_code = undefined;
    self.lobby_id = undefined;
    self.local_user_id = undefined;

}

/**
 * @returns {Struct.EpicLobbyPromoteMemberCallbackInfo} 
 */
function EpicLobbyPromoteMemberCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 178186193;

    self.result_code = undefined;
    self.lobby_id = undefined;
    self.local_user_id = undefined;
    self.target_user_id = undefined;

}

/**
 * @returns {Struct.EpicLobbyKickMemberCallbackInfo} 
 */
function EpicLobbyKickMemberCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 3733861207;

    self.result_code = undefined;
    self.lobby_id = undefined;
    self.local_user_id = undefined;
    self.target_user_id = undefined;

}

/**
 * @returns {Struct.EpicLobbySearchFindCallbackInfo} 
 */
function EpicLobbySearchFindCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1995381572;

    self.result_code = undefined;

}

/**
 * @returns {Struct.EpicLobbyDetailsInfo} 
 */
function EpicLobbyDetailsInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 2127442566;

    self.lobby_id = undefined;
    self.bucket_id = undefined;
    self.lobby_owner_user_id = undefined;
    self.available_slots = undefined;
    self.max_members = undefined;
    self.permission_level = undefined;
    self.allow_invites = undefined;
    self.presence_enabled = undefined;

}

/**
 * @returns {Struct.EpicLobbyLobbyUpdateReceivedCallbackInfo} 
 */
function EpicLobbyLobbyUpdateReceivedCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 1115531689;

    self.lobby_id = undefined;
    self.local_user_id = undefined;

}

/**
 * @returns {Struct.EpicLobbyLobbyMemberUpdateReceivedCallbackInfo} 
 */
function EpicLobbyLobbyMemberUpdateReceivedCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 3295821363;

    self.lobby_id = undefined;
    self.target_user_id = undefined;
    self.local_user_id = undefined;

}

/**
 * @returns {Struct.EpicLobbyLobbyMemberStatusReceivedCallbackInfo} 
 */
function EpicLobbyLobbyMemberStatusReceivedCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 3267317324;

    self.lobby_id = undefined;
    self.target_user_id = undefined;
    self.local_user_id = undefined;
    self.current_status = undefined;

}

/**
 * @returns {Struct.EpicLobbyJoinLobbyAcceptedCallbackInfo} 
 */
function EpicLobbyJoinLobbyAcceptedCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 2332569210;

    self.ui_event_id = undefined;

}

/**
 * @returns {Struct.EpicLobbyLeaveLobbyRequestedCallbackInfo} 
 */
function EpicLobbyLeaveLobbyRequestedCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 3837709192;

    self.lobby_id = undefined;
    self.local_user_id = undefined;

}

/**
 * @returns {Struct.EpicLobbySendLobbyNativeInviteRequestedCallbackInfo} 
 */
function EpicLobbySendLobbyNativeInviteRequestedCallbackInfo() constructor
{
    /**
     * Internally generated hash for quick validation
     * @ignore 
     */
    static __uid = 193408739;

    self.lobby_id = undefined;
    self.local_user_id = undefined;
    self.target_native_account_type = undefined;
    self.target_user_native_account_id = undefined;

}

// #####################################################################
// # Codecs
// #####################################################################

/**
 * @func __EpicLoggingMessage_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLoggingMessage} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLoggingMessage_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: category, type: enum EpicLogCategory

        if (!is_numeric(self.category)) show_error($"{_where} :: self.category expected number", true);
        buffer_write(_buffer, buffer_u64, self.category);

        // field: level, type: enum EpicLogLevel

        if (!is_numeric(self.level)) show_error($"{_where} :: self.level expected number", true);
        buffer_write(_buffer, buffer_u64, self.level);

        // field: message, type: String
        if (!is_string(self.message)) show_error($"{_where} :: self.message expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.message));
        buffer_write(_buffer, buffer_string, self.message);

    }
}

/**
 * @func __EpicLoggingMessage_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLoggingMessage} 
 * @ignore 
 */
function __EpicLoggingMessage_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLoggingMessage();
    with (_inst)
    {
        // field: category, type: enum EpicLogCategory
        self.category = buffer_read(_buffer, buffer_u64);

        // field: level, type: enum EpicLogLevel
        self.level = buffer_read(_buffer, buffer_u64);

        // field: message, type: String
        buffer_read(_buffer, buffer_u32);
        self.message = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicAuthLoginCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicAuthLoginCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicAuthLoginCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: selected_account_id, type: String
        if (!is_string(self.selected_account_id)) show_error($"{_where} :: self.selected_account_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.selected_account_id));
        buffer_write(_buffer, buffer_string, self.selected_account_id);

        // field: has_continuance_token, type: Bool
        if (!is_bool(self.has_continuance_token)) show_error($"{_where} :: self.has_continuance_token expected bool", true);
        buffer_write(_buffer, buffer_bool, self.has_continuance_token);

    }
}

/**
 * @func __EpicAuthLoginCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicAuthLoginCallbackInfo} 
 * @ignore 
 */
function __EpicAuthLoginCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicAuthLoginCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: selected_account_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.selected_account_id = buffer_read(_buffer, buffer_string);

        // field: has_continuance_token, type: Bool
        self.has_continuance_token = buffer_read(_buffer, buffer_bool);

    }

    return _inst;
}

/**
 * @func __EpicAuthLogoutCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicAuthLogoutCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicAuthLogoutCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

    }
}

/**
 * @func __EpicAuthLogoutCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicAuthLogoutCallbackInfo} 
 * @ignore 
 */
function __EpicAuthLogoutCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicAuthLogoutCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicAuthLinkAccountCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicAuthLinkAccountCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicAuthLinkAccountCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: selected_account_id, type: String
        if (!is_string(self.selected_account_id)) show_error($"{_where} :: self.selected_account_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.selected_account_id));
        buffer_write(_buffer, buffer_string, self.selected_account_id);

    }
}

/**
 * @func __EpicAuthLinkAccountCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicAuthLinkAccountCallbackInfo} 
 * @ignore 
 */
function __EpicAuthLinkAccountCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicAuthLinkAccountCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: selected_account_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.selected_account_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicAuthDeletePersistentAuthCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicAuthDeletePersistentAuthCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicAuthDeletePersistentAuthCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

    }
}

/**
 * @func __EpicAuthDeletePersistentAuthCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicAuthDeletePersistentAuthCallbackInfo} 
 * @ignore 
 */
function __EpicAuthDeletePersistentAuthCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicAuthDeletePersistentAuthCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicAuthIdToken_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicAuthIdToken} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicAuthIdToken_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: account_id, type: String
        if (!is_string(self.account_id)) show_error($"{_where} :: self.account_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.account_id));
        buffer_write(_buffer, buffer_string, self.account_id);

        // field: json_web_token, type: String
        if (!is_string(self.json_web_token)) show_error($"{_where} :: self.json_web_token expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.json_web_token));
        buffer_write(_buffer, buffer_string, self.json_web_token);

    }
}

/**
 * @func __EpicAuthIdToken_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicAuthIdToken} 
 * @ignore 
 */
function __EpicAuthIdToken_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicAuthIdToken();
    with (_inst)
    {
        // field: account_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.account_id = buffer_read(_buffer, buffer_string);

        // field: json_web_token, type: String
        buffer_read(_buffer, buffer_u32);
        self.json_web_token = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicAuthUserAuthToken_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicAuthUserAuthToken} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicAuthUserAuthToken_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: app, type: String
        if (!is_string(self.app)) show_error($"{_where} :: self.app expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.app));
        buffer_write(_buffer, buffer_string, self.app);

        // field: client_id, type: String
        if (!is_string(self.client_id)) show_error($"{_where} :: self.client_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.client_id));
        buffer_write(_buffer, buffer_string, self.client_id);

        // field: account_id, type: String
        if (!is_string(self.account_id)) show_error($"{_where} :: self.account_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.account_id));
        buffer_write(_buffer, buffer_string, self.account_id);

        // field: access_token, type: String
        if (!is_string(self.access_token)) show_error($"{_where} :: self.access_token expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.access_token));
        buffer_write(_buffer, buffer_string, self.access_token);

        // field: expires_in, type: Float64
        if (!is_numeric(self.expires_in)) show_error($"{_where} :: self.expires_in expected number", true);
        buffer_write(_buffer, buffer_f64, self.expires_in);

        // field: expires_at, type: String
        if (!is_string(self.expires_at)) show_error($"{_where} :: self.expires_at expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.expires_at));
        buffer_write(_buffer, buffer_string, self.expires_at);

        // field: auth_type, type: String
        if (!is_string(self.auth_type)) show_error($"{_where} :: self.auth_type expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.auth_type));
        buffer_write(_buffer, buffer_string, self.auth_type);

        // field: refresh_token, type: String
        if (!is_string(self.refresh_token)) show_error($"{_where} :: self.refresh_token expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.refresh_token));
        buffer_write(_buffer, buffer_string, self.refresh_token);

        // field: refresh_expires_in, type: Float64
        if (!is_numeric(self.refresh_expires_in)) show_error($"{_where} :: self.refresh_expires_in expected number", true);
        buffer_write(_buffer, buffer_f64, self.refresh_expires_in);

        // field: refresh_expires_at, type: String
        if (!is_string(self.refresh_expires_at)) show_error($"{_where} :: self.refresh_expires_at expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.refresh_expires_at));
        buffer_write(_buffer, buffer_string, self.refresh_expires_at);

    }
}

/**
 * @func __EpicAuthUserAuthToken_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicAuthUserAuthToken} 
 * @ignore 
 */
function __EpicAuthUserAuthToken_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicAuthUserAuthToken();
    with (_inst)
    {
        // field: app, type: String
        buffer_read(_buffer, buffer_u32);
        self.app = buffer_read(_buffer, buffer_string);

        // field: client_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.client_id = buffer_read(_buffer, buffer_string);

        // field: account_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.account_id = buffer_read(_buffer, buffer_string);

        // field: access_token, type: String
        buffer_read(_buffer, buffer_u32);
        self.access_token = buffer_read(_buffer, buffer_string);

        // field: expires_in, type: Float64
        self.expires_in = buffer_read(_buffer, buffer_f64);

        // field: expires_at, type: String
        buffer_read(_buffer, buffer_u32);
        self.expires_at = buffer_read(_buffer, buffer_string);

        // field: auth_type, type: String
        buffer_read(_buffer, buffer_u32);
        self.auth_type = buffer_read(_buffer, buffer_string);

        // field: refresh_token, type: String
        buffer_read(_buffer, buffer_u32);
        self.refresh_token = buffer_read(_buffer, buffer_string);

        // field: refresh_expires_in, type: Float64
        self.refresh_expires_in = buffer_read(_buffer, buffer_f64);

        // field: refresh_expires_at, type: String
        buffer_read(_buffer, buffer_u32);
        self.refresh_expires_at = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicAuthQueryIdTokenCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicAuthQueryIdTokenCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicAuthQueryIdTokenCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: target_account_id, type: String
        if (!is_string(self.target_account_id)) show_error($"{_where} :: self.target_account_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.target_account_id));
        buffer_write(_buffer, buffer_string, self.target_account_id);

    }
}

/**
 * @func __EpicAuthQueryIdTokenCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicAuthQueryIdTokenCallbackInfo} 
 * @ignore 
 */
function __EpicAuthQueryIdTokenCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicAuthQueryIdTokenCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: target_account_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.target_account_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicAuthVerifyIdTokenCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicAuthVerifyIdTokenCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicAuthVerifyIdTokenCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: application_id, type: String
        if (!is_string(self.application_id)) show_error($"{_where} :: self.application_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.application_id));
        buffer_write(_buffer, buffer_string, self.application_id);

        // field: client_id, type: String
        if (!is_string(self.client_id)) show_error($"{_where} :: self.client_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.client_id));
        buffer_write(_buffer, buffer_string, self.client_id);

        // field: product_id, type: String
        if (!is_string(self.product_id)) show_error($"{_where} :: self.product_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.product_id));
        buffer_write(_buffer, buffer_string, self.product_id);

        // field: sandbox_id, type: String
        if (!is_string(self.sandbox_id)) show_error($"{_where} :: self.sandbox_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.sandbox_id));
        buffer_write(_buffer, buffer_string, self.sandbox_id);

        // field: deployment_id, type: String
        if (!is_string(self.deployment_id)) show_error($"{_where} :: self.deployment_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.deployment_id));
        buffer_write(_buffer, buffer_string, self.deployment_id);

        // field: display_name, type: String
        if (!is_string(self.display_name)) show_error($"{_where} :: self.display_name expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.display_name));
        buffer_write(_buffer, buffer_string, self.display_name);

        // field: is_external_account_info_present, type: Bool
        if (!is_bool(self.is_external_account_info_present)) show_error($"{_where} :: self.is_external_account_info_present expected bool", true);
        buffer_write(_buffer, buffer_bool, self.is_external_account_info_present);

    }
}

/**
 * @func __EpicAuthVerifyIdTokenCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicAuthVerifyIdTokenCallbackInfo} 
 * @ignore 
 */
function __EpicAuthVerifyIdTokenCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicAuthVerifyIdTokenCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: application_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.application_id = buffer_read(_buffer, buffer_string);

        // field: client_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.client_id = buffer_read(_buffer, buffer_string);

        // field: product_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.product_id = buffer_read(_buffer, buffer_string);

        // field: sandbox_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.sandbox_id = buffer_read(_buffer, buffer_string);

        // field: deployment_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.deployment_id = buffer_read(_buffer, buffer_string);

        // field: display_name, type: String
        buffer_read(_buffer, buffer_u32);
        self.display_name = buffer_read(_buffer, buffer_string);

        // field: is_external_account_info_present, type: Bool
        self.is_external_account_info_present = buffer_read(_buffer, buffer_bool);

    }

    return _inst;
}

/**
 * @func __EpicAuthVerifyUserAuthCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicAuthVerifyUserAuthCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicAuthVerifyUserAuthCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

    }
}

/**
 * @func __EpicAuthVerifyUserAuthCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicAuthVerifyUserAuthCallbackInfo} 
 * @ignore 
 */
function __EpicAuthVerifyUserAuthCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicAuthVerifyUserAuthCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicAuthLoginStatusChangedCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicAuthLoginStatusChangedCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicAuthLoginStatusChangedCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: previous_status, type: enum EpicLoginStatus

        if (!is_numeric(self.previous_status)) show_error($"{_where} :: self.previous_status expected number", true);
        buffer_write(_buffer, buffer_u64, self.previous_status);

        // field: current_status, type: enum EpicLoginStatus

        if (!is_numeric(self.current_status)) show_error($"{_where} :: self.current_status expected number", true);
        buffer_write(_buffer, buffer_u64, self.current_status);

    }
}

/**
 * @func __EpicAuthLoginStatusChangedCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicAuthLoginStatusChangedCallbackInfo} 
 * @ignore 
 */
function __EpicAuthLoginStatusChangedCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicAuthLoginStatusChangedCallbackInfo();
    with (_inst)
    {
        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: previous_status, type: enum EpicLoginStatus
        self.previous_status = buffer_read(_buffer, buffer_u64);

        // field: current_status, type: enum EpicLoginStatus
        self.current_status = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicConnectLoginCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicConnectLoginCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicConnectLoginCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: has_continuance_token, type: Bool
        if (!is_bool(self.has_continuance_token)) show_error($"{_where} :: self.has_continuance_token expected bool", true);
        buffer_write(_buffer, buffer_bool, self.has_continuance_token);

    }
}

/**
 * @func __EpicConnectLoginCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicConnectLoginCallbackInfo} 
 * @ignore 
 */
function __EpicConnectLoginCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicConnectLoginCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: has_continuance_token, type: Bool
        self.has_continuance_token = buffer_read(_buffer, buffer_bool);

    }

    return _inst;
}

/**
 * @func __EpicConnectCreateUserCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicConnectCreateUserCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicConnectCreateUserCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

    }
}

/**
 * @func __EpicConnectCreateUserCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicConnectCreateUserCallbackInfo} 
 * @ignore 
 */
function __EpicConnectCreateUserCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicConnectCreateUserCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicConnectLinkAccountCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicConnectLinkAccountCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicConnectLinkAccountCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

    }
}

/**
 * @func __EpicConnectLinkAccountCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicConnectLinkAccountCallbackInfo} 
 * @ignore 
 */
function __EpicConnectLinkAccountCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicConnectLinkAccountCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicConnectUnlinkAccountCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicConnectUnlinkAccountCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicConnectUnlinkAccountCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

    }
}

/**
 * @func __EpicConnectUnlinkAccountCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicConnectUnlinkAccountCallbackInfo} 
 * @ignore 
 */
function __EpicConnectUnlinkAccountCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicConnectUnlinkAccountCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicConnectCreateDeviceIdCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicConnectCreateDeviceIdCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicConnectCreateDeviceIdCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: device_model, type: String
        if (!is_string(self.device_model)) show_error($"{_where} :: self.device_model expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.device_model));
        buffer_write(_buffer, buffer_string, self.device_model);

    }
}

/**
 * @func __EpicConnectCreateDeviceIdCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicConnectCreateDeviceIdCallbackInfo} 
 * @ignore 
 */
function __EpicConnectCreateDeviceIdCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicConnectCreateDeviceIdCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: device_model, type: String
        buffer_read(_buffer, buffer_u32);
        self.device_model = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicConnectDeleteDeviceIdCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicConnectDeleteDeviceIdCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicConnectDeleteDeviceIdCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

    }
}

/**
 * @func __EpicConnectDeleteDeviceIdCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicConnectDeleteDeviceIdCallbackInfo} 
 * @ignore 
 */
function __EpicConnectDeleteDeviceIdCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicConnectDeleteDeviceIdCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicConnectTransferDeviceIdAccountCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicConnectTransferDeviceIdAccountCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicConnectTransferDeviceIdAccountCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

    }
}

/**
 * @func __EpicConnectTransferDeviceIdAccountCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicConnectTransferDeviceIdAccountCallbackInfo} 
 * @ignore 
 */
function __EpicConnectTransferDeviceIdAccountCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicConnectTransferDeviceIdAccountCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicConnectLogoutCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicConnectLogoutCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicConnectLogoutCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

    }
}

/**
 * @func __EpicConnectLogoutCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicConnectLogoutCallbackInfo} 
 * @ignore 
 */
function __EpicConnectLogoutCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicConnectLogoutCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicConnectIdToken_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicConnectIdToken} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicConnectIdToken_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: product_user_id, type: String
        if (!is_string(self.product_user_id)) show_error($"{_where} :: self.product_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.product_user_id));
        buffer_write(_buffer, buffer_string, self.product_user_id);

        // field: json_web_token, type: String
        if (!is_string(self.json_web_token)) show_error($"{_where} :: self.json_web_token expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.json_web_token));
        buffer_write(_buffer, buffer_string, self.json_web_token);

    }
}

/**
 * @func __EpicConnectIdToken_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicConnectIdToken} 
 * @ignore 
 */
function __EpicConnectIdToken_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicConnectIdToken();
    with (_inst)
    {
        // field: product_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.product_user_id = buffer_read(_buffer, buffer_string);

        // field: json_web_token, type: String
        buffer_read(_buffer, buffer_u32);
        self.json_web_token = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicConnectExternalAccountInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicConnectExternalAccountInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicConnectExternalAccountInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: product_user_id, type: String
        if (!is_string(self.product_user_id)) show_error($"{_where} :: self.product_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.product_user_id));
        buffer_write(_buffer, buffer_string, self.product_user_id);

        // field: display_name, type: String
        if (!is_string(self.display_name)) show_error($"{_where} :: self.display_name expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.display_name));
        buffer_write(_buffer, buffer_string, self.display_name);

        // field: account_id, type: String
        if (!is_string(self.account_id)) show_error($"{_where} :: self.account_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.account_id));
        buffer_write(_buffer, buffer_string, self.account_id);

        // field: account_id_type, type: enum EpicExternalAccountType

        if (!is_numeric(self.account_id_type)) show_error($"{_where} :: self.account_id_type expected number", true);
        buffer_write(_buffer, buffer_u64, self.account_id_type);

        // field: last_login_time, type: Int64
        if (!is_numeric(self.last_login_time)) show_error($"{_where} :: self.last_login_time expected number", true);
        buffer_write(_buffer, buffer_u64, self.last_login_time);

    }
}

/**
 * @func __EpicConnectExternalAccountInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicConnectExternalAccountInfo} 
 * @ignore 
 */
function __EpicConnectExternalAccountInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicConnectExternalAccountInfo();
    with (_inst)
    {
        // field: product_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.product_user_id = buffer_read(_buffer, buffer_string);

        // field: display_name, type: String
        buffer_read(_buffer, buffer_u32);
        self.display_name = buffer_read(_buffer, buffer_string);

        // field: account_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.account_id = buffer_read(_buffer, buffer_string);

        // field: account_id_type, type: enum EpicExternalAccountType
        self.account_id_type = buffer_read(_buffer, buffer_u64);

        // field: last_login_time, type: Int64
        self.last_login_time = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicConnectVerifyIdTokenCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicConnectVerifyIdTokenCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicConnectVerifyIdTokenCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

    }
}

/**
 * @func __EpicConnectVerifyIdTokenCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicConnectVerifyIdTokenCallbackInfo} 
 * @ignore 
 */
function __EpicConnectVerifyIdTokenCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicConnectVerifyIdTokenCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicConnectQueryExternalAccountMappingsCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicConnectQueryExternalAccountMappingsCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicConnectQueryExternalAccountMappingsCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

    }
}

/**
 * @func __EpicConnectQueryExternalAccountMappingsCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicConnectQueryExternalAccountMappingsCallbackInfo} 
 * @ignore 
 */
function __EpicConnectQueryExternalAccountMappingsCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicConnectQueryExternalAccountMappingsCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicConnectQueryProductUserIdMappingsCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicConnectQueryProductUserIdMappingsCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicConnectQueryProductUserIdMappingsCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

    }
}

/**
 * @func __EpicConnectQueryProductUserIdMappingsCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicConnectQueryProductUserIdMappingsCallbackInfo} 
 * @ignore 
 */
function __EpicConnectQueryProductUserIdMappingsCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicConnectQueryProductUserIdMappingsCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicConnectAuthExpirationCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicConnectAuthExpirationCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicConnectAuthExpirationCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

    }
}

/**
 * @func __EpicConnectAuthExpirationCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicConnectAuthExpirationCallbackInfo} 
 * @ignore 
 */
function __EpicConnectAuthExpirationCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicConnectAuthExpirationCallbackInfo();
    with (_inst)
    {
        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicConnectLoginStatusChangedCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicConnectLoginStatusChangedCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicConnectLoginStatusChangedCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: previous_status, type: enum EpicLoginStatus

        if (!is_numeric(self.previous_status)) show_error($"{_where} :: self.previous_status expected number", true);
        buffer_write(_buffer, buffer_u64, self.previous_status);

        // field: current_status, type: enum EpicLoginStatus

        if (!is_numeric(self.current_status)) show_error($"{_where} :: self.current_status expected number", true);
        buffer_write(_buffer, buffer_u64, self.current_status);

    }
}

/**
 * @func __EpicConnectLoginStatusChangedCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicConnectLoginStatusChangedCallbackInfo} 
 * @ignore 
 */
function __EpicConnectLoginStatusChangedCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicConnectLoginStatusChangedCallbackInfo();
    with (_inst)
    {
        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: previous_status, type: enum EpicLoginStatus
        self.previous_status = buffer_read(_buffer, buffer_u64);

        // field: current_status, type: enum EpicLoginStatus
        self.current_status = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicFriendsQueryFriendsCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicFriendsQueryFriendsCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicFriendsQueryFriendsCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: target_user_id, type: String
        if (!is_string(self.target_user_id)) show_error($"{_where} :: self.target_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.target_user_id));
        buffer_write(_buffer, buffer_string, self.target_user_id);

    }
}

/**
 * @func __EpicFriendsQueryFriendsCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicFriendsQueryFriendsCallbackInfo} 
 * @ignore 
 */
function __EpicFriendsQueryFriendsCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicFriendsQueryFriendsCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: target_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.target_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicFriendsFriendsUpdateCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicFriendsFriendsUpdateCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicFriendsFriendsUpdateCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: target_user_id, type: String
        if (!is_string(self.target_user_id)) show_error($"{_where} :: self.target_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.target_user_id));
        buffer_write(_buffer, buffer_string, self.target_user_id);

        // field: previous_status, type: enum EpicFriendsStatus

        if (!is_numeric(self.previous_status)) show_error($"{_where} :: self.previous_status expected number", true);
        buffer_write(_buffer, buffer_u64, self.previous_status);

        // field: current_status, type: enum EpicFriendsStatus

        if (!is_numeric(self.current_status)) show_error($"{_where} :: self.current_status expected number", true);
        buffer_write(_buffer, buffer_u64, self.current_status);

    }
}

/**
 * @func __EpicFriendsFriendsUpdateCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicFriendsFriendsUpdateCallbackInfo} 
 * @ignore 
 */
function __EpicFriendsFriendsUpdateCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicFriendsFriendsUpdateCallbackInfo();
    with (_inst)
    {
        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: target_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.target_user_id = buffer_read(_buffer, buffer_string);

        // field: previous_status, type: enum EpicFriendsStatus
        self.previous_status = buffer_read(_buffer, buffer_u64);

        // field: current_status, type: enum EpicFriendsStatus
        self.current_status = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicUserInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicUserInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicUserInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: user_id, type: String
        if (!is_string(self.user_id)) show_error($"{_where} :: self.user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.user_id));
        buffer_write(_buffer, buffer_string, self.user_id);

        // field: country, type: String
        if (!is_string(self.country)) show_error($"{_where} :: self.country expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.country));
        buffer_write(_buffer, buffer_string, self.country);

        // field: display_name, type: String
        if (!is_string(self.display_name)) show_error($"{_where} :: self.display_name expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.display_name));
        buffer_write(_buffer, buffer_string, self.display_name);

        // field: preferred_language, type: String
        if (!is_string(self.preferred_language)) show_error($"{_where} :: self.preferred_language expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.preferred_language));
        buffer_write(_buffer, buffer_string, self.preferred_language);

        // field: nickname, type: String
        if (!is_string(self.nickname)) show_error($"{_where} :: self.nickname expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.nickname));
        buffer_write(_buffer, buffer_string, self.nickname);

    }
}

/**
 * @func __EpicUserInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicUserInfo} 
 * @ignore 
 */
function __EpicUserInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicUserInfo();
    with (_inst)
    {
        // field: user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.user_id = buffer_read(_buffer, buffer_string);

        // field: country, type: String
        buffer_read(_buffer, buffer_u32);
        self.country = buffer_read(_buffer, buffer_string);

        // field: display_name, type: String
        buffer_read(_buffer, buffer_u32);
        self.display_name = buffer_read(_buffer, buffer_string);

        // field: preferred_language, type: String
        buffer_read(_buffer, buffer_u32);
        self.preferred_language = buffer_read(_buffer, buffer_string);

        // field: nickname, type: String
        buffer_read(_buffer, buffer_u32);
        self.nickname = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicUserInfoQueryUserInfoCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicUserInfoQueryUserInfoCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicUserInfoQueryUserInfoCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: target_user_id, type: String
        if (!is_string(self.target_user_id)) show_error($"{_where} :: self.target_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.target_user_id));
        buffer_write(_buffer, buffer_string, self.target_user_id);

    }
}

/**
 * @func __EpicUserInfoQueryUserInfoCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicUserInfoQueryUserInfoCallbackInfo} 
 * @ignore 
 */
function __EpicUserInfoQueryUserInfoCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicUserInfoQueryUserInfoCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: target_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.target_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicUserInfoExternalUserInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicUserInfoExternalUserInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicUserInfoExternalUserInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: account_id, type: String
        if (!is_string(self.account_id)) show_error($"{_where} :: self.account_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.account_id));
        buffer_write(_buffer, buffer_string, self.account_id);

        // field: account_type, type: enum EpicExternalAccountType

        if (!is_numeric(self.account_type)) show_error($"{_where} :: self.account_type expected number", true);
        buffer_write(_buffer, buffer_u64, self.account_type);

        // field: display_name, type: String
        if (!is_string(self.display_name)) show_error($"{_where} :: self.display_name expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.display_name));
        buffer_write(_buffer, buffer_string, self.display_name);

    }
}

/**
 * @func __EpicUserInfoExternalUserInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicUserInfoExternalUserInfo} 
 * @ignore 
 */
function __EpicUserInfoExternalUserInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicUserInfoExternalUserInfo();
    with (_inst)
    {
        // field: account_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.account_id = buffer_read(_buffer, buffer_string);

        // field: account_type, type: enum EpicExternalAccountType
        self.account_type = buffer_read(_buffer, buffer_u64);

        // field: display_name, type: String
        buffer_read(_buffer, buffer_u32);
        self.display_name = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicStatsStat_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicStatsStat} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicStatsStat_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: name, type: String
        if (!is_string(self.name)) show_error($"{_where} :: self.name expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.name));
        buffer_write(_buffer, buffer_string, self.name);

        // field: start_time, type: Int64
        if (!is_numeric(self.start_time)) show_error($"{_where} :: self.start_time expected number", true);
        buffer_write(_buffer, buffer_u64, self.start_time);

        // field: end_time, type: Int64
        if (!is_numeric(self.end_time)) show_error($"{_where} :: self.end_time expected number", true);
        buffer_write(_buffer, buffer_u64, self.end_time);

        // field: value, type: Int64
        if (!is_numeric(self.value)) show_error($"{_where} :: self.value expected number", true);
        buffer_write(_buffer, buffer_u64, self.value);

    }
}

/**
 * @func __EpicStatsStat_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicStatsStat} 
 * @ignore 
 */
function __EpicStatsStat_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicStatsStat();
    with (_inst)
    {
        // field: name, type: String
        buffer_read(_buffer, buffer_u32);
        self.name = buffer_read(_buffer, buffer_string);

        // field: start_time, type: Int64
        self.start_time = buffer_read(_buffer, buffer_u64);

        // field: end_time, type: Int64
        self.end_time = buffer_read(_buffer, buffer_u64);

        // field: value, type: Int64
        self.value = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicStatsIngestStatCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicStatsIngestStatCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicStatsIngestStatCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: target_user_id, type: String
        if (!is_string(self.target_user_id)) show_error($"{_where} :: self.target_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.target_user_id));
        buffer_write(_buffer, buffer_string, self.target_user_id);

    }
}

/**
 * @func __EpicStatsIngestStatCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicStatsIngestStatCallbackInfo} 
 * @ignore 
 */
function __EpicStatsIngestStatCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicStatsIngestStatCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: target_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.target_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicStatsQueryStatsCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicStatsQueryStatsCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicStatsQueryStatsCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: target_user_id, type: String
        if (!is_string(self.target_user_id)) show_error($"{_where} :: self.target_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.target_user_id));
        buffer_write(_buffer, buffer_string, self.target_user_id);

    }
}

/**
 * @func __EpicStatsQueryStatsCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicStatsQueryStatsCallbackInfo} 
 * @ignore 
 */
function __EpicStatsQueryStatsCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicStatsQueryStatsCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: target_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.target_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicUIShowFriendsCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicUIShowFriendsCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicUIShowFriendsCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

    }
}

/**
 * @func __EpicUIShowFriendsCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicUIShowFriendsCallbackInfo} 
 * @ignore 
 */
function __EpicUIShowFriendsCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicUIShowFriendsCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicUIShowNativeProfileCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicUIShowNativeProfileCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicUIShowNativeProfileCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: target_user_id, type: String
        if (!is_string(self.target_user_id)) show_error($"{_where} :: self.target_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.target_user_id));
        buffer_write(_buffer, buffer_string, self.target_user_id);

    }
}

/**
 * @func __EpicUIShowNativeProfileCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicUIShowNativeProfileCallbackInfo} 
 * @ignore 
 */
function __EpicUIShowNativeProfileCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicUIShowNativeProfileCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: target_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.target_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicUIDisplaySettingsUpdatedCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicUIDisplaySettingsUpdatedCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicUIDisplaySettingsUpdatedCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: is_visible, type: Bool
        if (!is_bool(self.is_visible)) show_error($"{_where} :: self.is_visible expected bool", true);
        buffer_write(_buffer, buffer_bool, self.is_visible);

        // field: notification_location, type: enum EpicUINotificationLocation

        if (!is_numeric(self.notification_location)) show_error($"{_where} :: self.notification_location expected number", true);
        buffer_write(_buffer, buffer_u64, self.notification_location);

    }
}

/**
 * @func __EpicUIDisplaySettingsUpdatedCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicUIDisplaySettingsUpdatedCallbackInfo} 
 * @ignore 
 */
function __EpicUIDisplaySettingsUpdatedCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicUIDisplaySettingsUpdatedCallbackInfo();
    with (_inst)
    {
        // field: is_visible, type: Bool
        self.is_visible = buffer_read(_buffer, buffer_bool);

        // field: notification_location, type: enum EpicUINotificationLocation
        self.notification_location = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicReportsSendPlayerBehaviorReportCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicReportsSendPlayerBehaviorReportCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicReportsSendPlayerBehaviorReportCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: reporter_user_id, type: String
        if (!is_string(self.reporter_user_id)) show_error($"{_where} :: self.reporter_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.reporter_user_id));
        buffer_write(_buffer, buffer_string, self.reporter_user_id);

        // field: reported_user_id, type: String
        if (!is_string(self.reported_user_id)) show_error($"{_where} :: self.reported_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.reported_user_id));
        buffer_write(_buffer, buffer_string, self.reported_user_id);

    }
}

/**
 * @func __EpicReportsSendPlayerBehaviorReportCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicReportsSendPlayerBehaviorReportCallbackInfo} 
 * @ignore 
 */
function __EpicReportsSendPlayerBehaviorReportCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicReportsSendPlayerBehaviorReportCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: reporter_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.reporter_user_id = buffer_read(_buffer, buffer_string);

        // field: reported_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.reported_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicSanctionsPlayerSanction_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicSanctionsPlayerSanction} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicSanctionsPlayerSanction_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: time_placed, type: String
        if (!is_string(self.time_placed)) show_error($"{_where} :: self.time_placed expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.time_placed));
        buffer_write(_buffer, buffer_string, self.time_placed);

        // field: action, type: String
        if (!is_string(self.action)) show_error($"{_where} :: self.action expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.action));
        buffer_write(_buffer, buffer_string, self.action);

        // field: time_expires, type: String
        if (!is_string(self.time_expires)) show_error($"{_where} :: self.time_expires expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.time_expires));
        buffer_write(_buffer, buffer_string, self.time_expires);

        // field: reference_id, type: String
        if (!is_string(self.reference_id)) show_error($"{_where} :: self.reference_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.reference_id));
        buffer_write(_buffer, buffer_string, self.reference_id);

        // field: justification, type: String
        if (!is_string(self.justification)) show_error($"{_where} :: self.justification expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.justification));
        buffer_write(_buffer, buffer_string, self.justification);

    }
}

/**
 * @func __EpicSanctionsPlayerSanction_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicSanctionsPlayerSanction} 
 * @ignore 
 */
function __EpicSanctionsPlayerSanction_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicSanctionsPlayerSanction();
    with (_inst)
    {
        // field: time_placed, type: String
        buffer_read(_buffer, buffer_u32);
        self.time_placed = buffer_read(_buffer, buffer_string);

        // field: action, type: String
        buffer_read(_buffer, buffer_u32);
        self.action = buffer_read(_buffer, buffer_string);

        // field: time_expires, type: String
        buffer_read(_buffer, buffer_u32);
        self.time_expires = buffer_read(_buffer, buffer_string);

        // field: reference_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.reference_id = buffer_read(_buffer, buffer_string);

        // field: justification, type: String
        buffer_read(_buffer, buffer_u32);
        self.justification = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicSanctionsQueryActivePlayerSanctionsCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicSanctionsQueryActivePlayerSanctionsCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicSanctionsQueryActivePlayerSanctionsCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: target_user_id, type: String
        if (!is_string(self.target_user_id)) show_error($"{_where} :: self.target_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.target_user_id));
        buffer_write(_buffer, buffer_string, self.target_user_id);

    }
}

/**
 * @func __EpicSanctionsQueryActivePlayerSanctionsCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicSanctionsQueryActivePlayerSanctionsCallbackInfo} 
 * @ignore 
 */
function __EpicSanctionsQueryActivePlayerSanctionsCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicSanctionsQueryActivePlayerSanctionsCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: target_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.target_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicSanctionsCreatePlayerSanctionAppealCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicSanctionsCreatePlayerSanctionAppealCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicSanctionsCreatePlayerSanctionAppealCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: reference_id, type: String
        if (!is_string(self.reference_id)) show_error($"{_where} :: self.reference_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.reference_id));
        buffer_write(_buffer, buffer_string, self.reference_id);

    }
}

/**
 * @func __EpicSanctionsCreatePlayerSanctionAppealCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicSanctionsCreatePlayerSanctionAppealCallbackInfo} 
 * @ignore 
 */
function __EpicSanctionsCreatePlayerSanctionAppealCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicSanctionsCreatePlayerSanctionAppealCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: reference_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.reference_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicAchievementsQueryDefinitionsCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicAchievementsQueryDefinitionsCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicAchievementsQueryDefinitionsCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

    }
}

/**
 * @func __EpicAchievementsQueryDefinitionsCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicAchievementsQueryDefinitionsCallbackInfo} 
 * @ignore 
 */
function __EpicAchievementsQueryDefinitionsCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicAchievementsQueryDefinitionsCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicAchievementsQueryPlayerAchievementsCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicAchievementsQueryPlayerAchievementsCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicAchievementsQueryPlayerAchievementsCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: user_id, type: String
        if (!is_string(self.user_id)) show_error($"{_where} :: self.user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.user_id));
        buffer_write(_buffer, buffer_string, self.user_id);

        // field: target_user_id, type: String
        if (!is_string(self.target_user_id)) show_error($"{_where} :: self.target_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.target_user_id));
        buffer_write(_buffer, buffer_string, self.target_user_id);

    }
}

/**
 * @func __EpicAchievementsQueryPlayerAchievementsCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicAchievementsQueryPlayerAchievementsCallbackInfo} 
 * @ignore 
 */
function __EpicAchievementsQueryPlayerAchievementsCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicAchievementsQueryPlayerAchievementsCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.user_id = buffer_read(_buffer, buffer_string);

        // field: target_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.target_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicAchievementsDefinition_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicAchievementsDefinition} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicAchievementsDefinition_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: achievement_id, type: String
        if (!is_string(self.achievement_id)) show_error($"{_where} :: self.achievement_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.achievement_id));
        buffer_write(_buffer, buffer_string, self.achievement_id);

        // field: unlocked_display_name, type: String
        if (!is_string(self.unlocked_display_name)) show_error($"{_where} :: self.unlocked_display_name expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.unlocked_display_name));
        buffer_write(_buffer, buffer_string, self.unlocked_display_name);

        // field: unlocked_description, type: String
        if (!is_string(self.unlocked_description)) show_error($"{_where} :: self.unlocked_description expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.unlocked_description));
        buffer_write(_buffer, buffer_string, self.unlocked_description);

        // field: locked_display_name, type: String
        if (!is_string(self.locked_display_name)) show_error($"{_where} :: self.locked_display_name expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.locked_display_name));
        buffer_write(_buffer, buffer_string, self.locked_display_name);

        // field: locked_description, type: String
        if (!is_string(self.locked_description)) show_error($"{_where} :: self.locked_description expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.locked_description));
        buffer_write(_buffer, buffer_string, self.locked_description);

        // field: flavor_text, type: String
        if (!is_string(self.flavor_text)) show_error($"{_where} :: self.flavor_text expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.flavor_text));
        buffer_write(_buffer, buffer_string, self.flavor_text);

        // field: completion_description, type: String
        if (!is_string(self.completion_description)) show_error($"{_where} :: self.completion_description expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.completion_description));
        buffer_write(_buffer, buffer_string, self.completion_description);

        // field: unlocked_icon_url, type: String
        if (!is_string(self.unlocked_icon_url)) show_error($"{_where} :: self.unlocked_icon_url expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.unlocked_icon_url));
        buffer_write(_buffer, buffer_string, self.unlocked_icon_url);

        // field: locked_icon_url, type: String
        if (!is_string(self.locked_icon_url)) show_error($"{_where} :: self.locked_icon_url expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.locked_icon_url));
        buffer_write(_buffer, buffer_string, self.locked_icon_url);

        // field: is_hidden, type: Bool
        if (!is_bool(self.is_hidden)) show_error($"{_where} :: self.is_hidden expected bool", true);
        buffer_write(_buffer, buffer_bool, self.is_hidden);

        // field: stat_thresholds_count, type: Int64
        if (!is_numeric(self.stat_thresholds_count)) show_error($"{_where} :: self.stat_thresholds_count expected number", true);
        buffer_write(_buffer, buffer_u64, self.stat_thresholds_count);

    }
}

/**
 * @func __EpicAchievementsDefinition_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicAchievementsDefinition} 
 * @ignore 
 */
function __EpicAchievementsDefinition_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicAchievementsDefinition();
    with (_inst)
    {
        // field: achievement_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.achievement_id = buffer_read(_buffer, buffer_string);

        // field: unlocked_display_name, type: String
        buffer_read(_buffer, buffer_u32);
        self.unlocked_display_name = buffer_read(_buffer, buffer_string);

        // field: unlocked_description, type: String
        buffer_read(_buffer, buffer_u32);
        self.unlocked_description = buffer_read(_buffer, buffer_string);

        // field: locked_display_name, type: String
        buffer_read(_buffer, buffer_u32);
        self.locked_display_name = buffer_read(_buffer, buffer_string);

        // field: locked_description, type: String
        buffer_read(_buffer, buffer_u32);
        self.locked_description = buffer_read(_buffer, buffer_string);

        // field: flavor_text, type: String
        buffer_read(_buffer, buffer_u32);
        self.flavor_text = buffer_read(_buffer, buffer_string);

        // field: completion_description, type: String
        buffer_read(_buffer, buffer_u32);
        self.completion_description = buffer_read(_buffer, buffer_string);

        // field: unlocked_icon_url, type: String
        buffer_read(_buffer, buffer_u32);
        self.unlocked_icon_url = buffer_read(_buffer, buffer_string);

        // field: locked_icon_url, type: String
        buffer_read(_buffer, buffer_u32);
        self.locked_icon_url = buffer_read(_buffer, buffer_string);

        // field: is_hidden, type: Bool
        self.is_hidden = buffer_read(_buffer, buffer_bool);

        // field: stat_thresholds_count, type: Int64
        self.stat_thresholds_count = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicPlayerAchievement_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicPlayerAchievement} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicPlayerAchievement_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: achievement_id, type: String
        if (!is_string(self.achievement_id)) show_error($"{_where} :: self.achievement_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.achievement_id));
        buffer_write(_buffer, buffer_string, self.achievement_id);

        // field: progress, type: Float64
        if (!is_numeric(self.progress)) show_error($"{_where} :: self.progress expected number", true);
        buffer_write(_buffer, buffer_f64, self.progress);

        // field: unlock_time, type: Int64
        if (!is_numeric(self.unlock_time)) show_error($"{_where} :: self.unlock_time expected number", true);
        buffer_write(_buffer, buffer_u64, self.unlock_time);

        // field: stat_info_count, type: Int64
        if (!is_numeric(self.stat_info_count)) show_error($"{_where} :: self.stat_info_count expected number", true);
        buffer_write(_buffer, buffer_u64, self.stat_info_count);

    }
}

/**
 * @func __EpicPlayerAchievement_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicPlayerAchievement} 
 * @ignore 
 */
function __EpicPlayerAchievement_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicPlayerAchievement();
    with (_inst)
    {
        // field: achievement_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.achievement_id = buffer_read(_buffer, buffer_string);

        // field: progress, type: Float64
        self.progress = buffer_read(_buffer, buffer_f64);

        // field: unlock_time, type: Int64
        self.unlock_time = buffer_read(_buffer, buffer_u64);

        // field: stat_info_count, type: Int64
        self.stat_info_count = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicAchievementsUnlockAchievementsCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicAchievementsUnlockAchievementsCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicAchievementsUnlockAchievementsCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: user_id, type: String
        if (!is_string(self.user_id)) show_error($"{_where} :: self.user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.user_id));
        buffer_write(_buffer, buffer_string, self.user_id);

        // field: achievements_count, type: Int64
        if (!is_numeric(self.achievements_count)) show_error($"{_where} :: self.achievements_count expected number", true);
        buffer_write(_buffer, buffer_u64, self.achievements_count);

    }
}

/**
 * @func __EpicAchievementsUnlockAchievementsCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicAchievementsUnlockAchievementsCallbackInfo} 
 * @ignore 
 */
function __EpicAchievementsUnlockAchievementsCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicAchievementsUnlockAchievementsCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.user_id = buffer_read(_buffer, buffer_string);

        // field: achievements_count, type: Int64
        self.achievements_count = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicAchievementsDefinitionV2_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicAchievementsDefinitionV2} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicAchievementsDefinitionV2_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: achievement_id, type: String
        if (!is_string(self.achievement_id)) show_error($"{_where} :: self.achievement_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.achievement_id));
        buffer_write(_buffer, buffer_string, self.achievement_id);

        // field: unlocked_display_name, type: String
        if (!is_string(self.unlocked_display_name)) show_error($"{_where} :: self.unlocked_display_name expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.unlocked_display_name));
        buffer_write(_buffer, buffer_string, self.unlocked_display_name);

        // field: unlocked_description, type: String
        if (!is_string(self.unlocked_description)) show_error($"{_where} :: self.unlocked_description expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.unlocked_description));
        buffer_write(_buffer, buffer_string, self.unlocked_description);

        // field: locked_display_name, type: String
        if (!is_string(self.locked_display_name)) show_error($"{_where} :: self.locked_display_name expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.locked_display_name));
        buffer_write(_buffer, buffer_string, self.locked_display_name);

        // field: locked_description, type: String
        if (!is_string(self.locked_description)) show_error($"{_where} :: self.locked_description expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.locked_description));
        buffer_write(_buffer, buffer_string, self.locked_description);

        // field: flavor_text, type: String
        if (!is_string(self.flavor_text)) show_error($"{_where} :: self.flavor_text expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.flavor_text));
        buffer_write(_buffer, buffer_string, self.flavor_text);

        // field: completion_description, type: String
        if (!is_string(self.completion_description)) show_error($"{_where} :: self.completion_description expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.completion_description));
        buffer_write(_buffer, buffer_string, self.completion_description);

        // field: unlocked_icon_url, type: String
        if (!is_string(self.unlocked_icon_url)) show_error($"{_where} :: self.unlocked_icon_url expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.unlocked_icon_url));
        buffer_write(_buffer, buffer_string, self.unlocked_icon_url);

        // field: locked_icon_url, type: String
        if (!is_string(self.locked_icon_url)) show_error($"{_where} :: self.locked_icon_url expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.locked_icon_url));
        buffer_write(_buffer, buffer_string, self.locked_icon_url);

        // field: is_hidden, type: Bool
        if (!is_bool(self.is_hidden)) show_error($"{_where} :: self.is_hidden expected bool", true);
        buffer_write(_buffer, buffer_bool, self.is_hidden);

        // field: stat_thresholds_count, type: Int64
        if (!is_numeric(self.stat_thresholds_count)) show_error($"{_where} :: self.stat_thresholds_count expected number", true);
        buffer_write(_buffer, buffer_u64, self.stat_thresholds_count);

    }
}

/**
 * @func __EpicAchievementsDefinitionV2_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicAchievementsDefinitionV2} 
 * @ignore 
 */
function __EpicAchievementsDefinitionV2_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicAchievementsDefinitionV2();
    with (_inst)
    {
        // field: achievement_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.achievement_id = buffer_read(_buffer, buffer_string);

        // field: unlocked_display_name, type: String
        buffer_read(_buffer, buffer_u32);
        self.unlocked_display_name = buffer_read(_buffer, buffer_string);

        // field: unlocked_description, type: String
        buffer_read(_buffer, buffer_u32);
        self.unlocked_description = buffer_read(_buffer, buffer_string);

        // field: locked_display_name, type: String
        buffer_read(_buffer, buffer_u32);
        self.locked_display_name = buffer_read(_buffer, buffer_string);

        // field: locked_description, type: String
        buffer_read(_buffer, buffer_u32);
        self.locked_description = buffer_read(_buffer, buffer_string);

        // field: flavor_text, type: String
        buffer_read(_buffer, buffer_u32);
        self.flavor_text = buffer_read(_buffer, buffer_string);

        // field: completion_description, type: String
        buffer_read(_buffer, buffer_u32);
        self.completion_description = buffer_read(_buffer, buffer_string);

        // field: unlocked_icon_url, type: String
        buffer_read(_buffer, buffer_u32);
        self.unlocked_icon_url = buffer_read(_buffer, buffer_string);

        // field: locked_icon_url, type: String
        buffer_read(_buffer, buffer_u32);
        self.locked_icon_url = buffer_read(_buffer, buffer_string);

        // field: is_hidden, type: Bool
        self.is_hidden = buffer_read(_buffer, buffer_bool);

        // field: stat_thresholds_count, type: Int64
        self.stat_thresholds_count = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicAchievementsUnlockedV2CallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicAchievementsUnlockedV2CallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicAchievementsUnlockedV2CallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: user_id, type: String
        if (!is_string(self.user_id)) show_error($"{_where} :: self.user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.user_id));
        buffer_write(_buffer, buffer_string, self.user_id);

        // field: achievement_id, type: String
        if (!is_string(self.achievement_id)) show_error($"{_where} :: self.achievement_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.achievement_id));
        buffer_write(_buffer, buffer_string, self.achievement_id);

        // field: unlock_time, type: Int64
        if (!is_numeric(self.unlock_time)) show_error($"{_where} :: self.unlock_time expected number", true);
        buffer_write(_buffer, buffer_u64, self.unlock_time);

    }
}

/**
 * @func __EpicAchievementsUnlockedV2CallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicAchievementsUnlockedV2CallbackInfo} 
 * @ignore 
 */
function __EpicAchievementsUnlockedV2CallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicAchievementsUnlockedV2CallbackInfo();
    with (_inst)
    {
        // field: user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.user_id = buffer_read(_buffer, buffer_string);

        // field: achievement_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.achievement_id = buffer_read(_buffer, buffer_string);

        // field: unlock_time, type: Int64
        self.unlock_time = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicLeaderboardsQueryDefinitionsCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLeaderboardsQueryDefinitionsCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLeaderboardsQueryDefinitionsCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

    }
}

/**
 * @func __EpicLeaderboardsQueryDefinitionsCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLeaderboardsQueryDefinitionsCallbackInfo} 
 * @ignore 
 */
function __EpicLeaderboardsQueryDefinitionsCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLeaderboardsQueryDefinitionsCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicLeaderboardsQueryRanksCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLeaderboardsQueryRanksCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLeaderboardsQueryRanksCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

    }
}

/**
 * @func __EpicLeaderboardsQueryRanksCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLeaderboardsQueryRanksCallbackInfo} 
 * @ignore 
 */
function __EpicLeaderboardsQueryRanksCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLeaderboardsQueryRanksCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicLeaderboardsQueryUserScoresCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLeaderboardsQueryUserScoresCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLeaderboardsQueryUserScoresCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

    }
}

/**
 * @func __EpicLeaderboardsQueryUserScoresCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLeaderboardsQueryUserScoresCallbackInfo} 
 * @ignore 
 */
function __EpicLeaderboardsQueryUserScoresCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLeaderboardsQueryUserScoresCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicLeaderboardDefinition_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLeaderboardDefinition} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLeaderboardDefinition_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: leaderboard_id, type: String
        if (!is_string(self.leaderboard_id)) show_error($"{_where} :: self.leaderboard_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.leaderboard_id));
        buffer_write(_buffer, buffer_string, self.leaderboard_id);

        // field: stat_name, type: String
        if (!is_string(self.stat_name)) show_error($"{_where} :: self.stat_name expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.stat_name));
        buffer_write(_buffer, buffer_string, self.stat_name);

        // field: start_time, type: String
        if (!is_string(self.start_time)) show_error($"{_where} :: self.start_time expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.start_time));
        buffer_write(_buffer, buffer_string, self.start_time);

        // field: end_time, type: String
        if (!is_string(self.end_time)) show_error($"{_where} :: self.end_time expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.end_time));
        buffer_write(_buffer, buffer_string, self.end_time);

        // field: aggregation, type: String
        if (!is_string(self.aggregation)) show_error($"{_where} :: self.aggregation expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.aggregation));
        buffer_write(_buffer, buffer_string, self.aggregation);

    }
}

/**
 * @func __EpicLeaderboardDefinition_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLeaderboardDefinition} 
 * @ignore 
 */
function __EpicLeaderboardDefinition_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLeaderboardDefinition();
    with (_inst)
    {
        // field: leaderboard_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.leaderboard_id = buffer_read(_buffer, buffer_string);

        // field: stat_name, type: String
        buffer_read(_buffer, buffer_u32);
        self.stat_name = buffer_read(_buffer, buffer_string);

        // field: start_time, type: String
        buffer_read(_buffer, buffer_u32);
        self.start_time = buffer_read(_buffer, buffer_string);

        // field: end_time, type: String
        buffer_read(_buffer, buffer_u32);
        self.end_time = buffer_read(_buffer, buffer_string);

        // field: aggregation, type: String
        buffer_read(_buffer, buffer_u32);
        self.aggregation = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicLeaderboardRecord_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLeaderboardRecord} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLeaderboardRecord_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: user_id, type: String
        if (!is_string(self.user_id)) show_error($"{_where} :: self.user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.user_id));
        buffer_write(_buffer, buffer_string, self.user_id);

        // field: rank, type: Int64
        if (!is_numeric(self.rank)) show_error($"{_where} :: self.rank expected number", true);
        buffer_write(_buffer, buffer_u64, self.rank);

        // field: score, type: Int64
        if (!is_numeric(self.score)) show_error($"{_where} :: self.score expected number", true);
        buffer_write(_buffer, buffer_u64, self.score);

        // field: user_display_name, type: String
        if (!is_string(self.user_display_name)) show_error($"{_where} :: self.user_display_name expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.user_display_name));
        buffer_write(_buffer, buffer_string, self.user_display_name);

    }
}

/**
 * @func __EpicLeaderboardRecord_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLeaderboardRecord} 
 * @ignore 
 */
function __EpicLeaderboardRecord_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLeaderboardRecord();
    with (_inst)
    {
        // field: user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.user_id = buffer_read(_buffer, buffer_string);

        // field: rank, type: Int64
        self.rank = buffer_read(_buffer, buffer_u64);

        // field: score, type: Int64
        self.score = buffer_read(_buffer, buffer_u64);

        // field: user_display_name, type: String
        buffer_read(_buffer, buffer_u32);
        self.user_display_name = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicLeaderboardUserScore_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLeaderboardUserScore} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLeaderboardUserScore_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: user_id, type: String
        if (!is_string(self.user_id)) show_error($"{_where} :: self.user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.user_id));
        buffer_write(_buffer, buffer_string, self.user_id);

        // field: stat_name, type: String
        if (!is_string(self.stat_name)) show_error($"{_where} :: self.stat_name expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.stat_name));
        buffer_write(_buffer, buffer_string, self.stat_name);

        // field: score, type: Int64
        if (!is_numeric(self.score)) show_error($"{_where} :: self.score expected number", true);
        buffer_write(_buffer, buffer_u64, self.score);

    }
}

/**
 * @func __EpicLeaderboardUserScore_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLeaderboardUserScore} 
 * @ignore 
 */
function __EpicLeaderboardUserScore_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLeaderboardUserScore();
    with (_inst)
    {
        // field: user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.user_id = buffer_read(_buffer, buffer_string);

        // field: stat_name, type: String
        buffer_read(_buffer, buffer_u32);
        self.stat_name = buffer_read(_buffer, buffer_string);

        // field: score, type: Int64
        self.score = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicPresenceInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicPresenceInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicPresenceInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: user_id, type: String
        if (!is_string(self.user_id)) show_error($"{_where} :: self.user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.user_id));
        buffer_write(_buffer, buffer_string, self.user_id);

        // field: status, type: enum EpicPresenceStatus

        if (!is_numeric(self.status)) show_error($"{_where} :: self.status expected number", true);
        buffer_write(_buffer, buffer_u64, self.status);

        // field: product_id, type: String
        if (!is_string(self.product_id)) show_error($"{_where} :: self.product_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.product_id));
        buffer_write(_buffer, buffer_string, self.product_id);

        // field: product_version, type: String
        if (!is_string(self.product_version)) show_error($"{_where} :: self.product_version expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.product_version));
        buffer_write(_buffer, buffer_string, self.product_version);

        // field: platform, type: String
        if (!is_string(self.platform)) show_error($"{_where} :: self.platform expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.platform));
        buffer_write(_buffer, buffer_string, self.platform);

        // field: rich_text, type: String
        if (!is_string(self.rich_text)) show_error($"{_where} :: self.rich_text expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.rich_text));
        buffer_write(_buffer, buffer_string, self.rich_text);

        // field: records_count, type: Int64
        if (!is_numeric(self.records_count)) show_error($"{_where} :: self.records_count expected number", true);
        buffer_write(_buffer, buffer_u64, self.records_count);

    }
}

/**
 * @func __EpicPresenceInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicPresenceInfo} 
 * @ignore 
 */
function __EpicPresenceInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicPresenceInfo();
    with (_inst)
    {
        // field: user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.user_id = buffer_read(_buffer, buffer_string);

        // field: status, type: enum EpicPresenceStatus
        self.status = buffer_read(_buffer, buffer_u64);

        // field: product_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.product_id = buffer_read(_buffer, buffer_string);

        // field: product_version, type: String
        buffer_read(_buffer, buffer_u32);
        self.product_version = buffer_read(_buffer, buffer_string);

        // field: platform, type: String
        buffer_read(_buffer, buffer_u32);
        self.platform = buffer_read(_buffer, buffer_string);

        // field: rich_text, type: String
        buffer_read(_buffer, buffer_u32);
        self.rich_text = buffer_read(_buffer, buffer_string);

        // field: records_count, type: Int64
        self.records_count = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicPresenceQueryPresenceCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicPresenceQueryPresenceCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicPresenceQueryPresenceCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: target_user_id, type: String
        if (!is_string(self.target_user_id)) show_error($"{_where} :: self.target_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.target_user_id));
        buffer_write(_buffer, buffer_string, self.target_user_id);

    }
}

/**
 * @func __EpicPresenceQueryPresenceCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicPresenceQueryPresenceCallbackInfo} 
 * @ignore 
 */
function __EpicPresenceQueryPresenceCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicPresenceQueryPresenceCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: target_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.target_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicPresenceSetPresenceCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicPresenceSetPresenceCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicPresenceSetPresenceCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

    }
}

/**
 * @func __EpicPresenceSetPresenceCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicPresenceSetPresenceCallbackInfo} 
 * @ignore 
 */
function __EpicPresenceSetPresenceCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicPresenceSetPresenceCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicPresenceChangedCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicPresenceChangedCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicPresenceChangedCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: presence_user_id, type: String
        if (!is_string(self.presence_user_id)) show_error($"{_where} :: self.presence_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.presence_user_id));
        buffer_write(_buffer, buffer_string, self.presence_user_id);

    }
}

/**
 * @func __EpicPresenceChangedCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicPresenceChangedCallbackInfo} 
 * @ignore 
 */
function __EpicPresenceChangedCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicPresenceChangedCallbackInfo();
    with (_inst)
    {
        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: presence_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.presence_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicPresenceJoinGameAcceptedCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicPresenceJoinGameAcceptedCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicPresenceJoinGameAcceptedCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: join_info, type: String
        if (!is_string(self.join_info)) show_error($"{_where} :: self.join_info expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.join_info));
        buffer_write(_buffer, buffer_string, self.join_info);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: target_user_id, type: String
        if (!is_string(self.target_user_id)) show_error($"{_where} :: self.target_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.target_user_id));
        buffer_write(_buffer, buffer_string, self.target_user_id);

        // field: ui_event_id, type: UInt64
        if (!is_numeric(self.ui_event_id)) show_error($"{_where} :: self.ui_event_id expected number", true);
        buffer_write(_buffer, buffer_u64, self.ui_event_id);

    }
}

/**
 * @func __EpicPresenceJoinGameAcceptedCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicPresenceJoinGameAcceptedCallbackInfo} 
 * @ignore 
 */
function __EpicPresenceJoinGameAcceptedCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicPresenceJoinGameAcceptedCallbackInfo();
    with (_inst)
    {
        // field: join_info, type: String
        buffer_read(_buffer, buffer_u32);
        self.join_info = buffer_read(_buffer, buffer_string);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: target_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.target_user_id = buffer_read(_buffer, buffer_string);

        // field: ui_event_id, type: UInt64
        self.ui_event_id = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicSessionsUpdateSessionCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicSessionsUpdateSessionCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicSessionsUpdateSessionCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: session_name, type: String
        if (!is_string(self.session_name)) show_error($"{_where} :: self.session_name expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.session_name));
        buffer_write(_buffer, buffer_string, self.session_name);

    }
}

/**
 * @func __EpicSessionsUpdateSessionCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicSessionsUpdateSessionCallbackInfo} 
 * @ignore 
 */
function __EpicSessionsUpdateSessionCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicSessionsUpdateSessionCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: session_name, type: String
        buffer_read(_buffer, buffer_u32);
        self.session_name = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicSessionsDestroySessionCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicSessionsDestroySessionCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicSessionsDestroySessionCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: session_name, type: String
        if (!is_string(self.session_name)) show_error($"{_where} :: self.session_name expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.session_name));
        buffer_write(_buffer, buffer_string, self.session_name);

    }
}

/**
 * @func __EpicSessionsDestroySessionCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicSessionsDestroySessionCallbackInfo} 
 * @ignore 
 */
function __EpicSessionsDestroySessionCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicSessionsDestroySessionCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: session_name, type: String
        buffer_read(_buffer, buffer_u32);
        self.session_name = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicSessionsStartSessionCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicSessionsStartSessionCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicSessionsStartSessionCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: session_name, type: String
        if (!is_string(self.session_name)) show_error($"{_where} :: self.session_name expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.session_name));
        buffer_write(_buffer, buffer_string, self.session_name);

    }
}

/**
 * @func __EpicSessionsStartSessionCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicSessionsStartSessionCallbackInfo} 
 * @ignore 
 */
function __EpicSessionsStartSessionCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicSessionsStartSessionCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: session_name, type: String
        buffer_read(_buffer, buffer_u32);
        self.session_name = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicSessionsEndSessionCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicSessionsEndSessionCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicSessionsEndSessionCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: session_name, type: String
        if (!is_string(self.session_name)) show_error($"{_where} :: self.session_name expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.session_name));
        buffer_write(_buffer, buffer_string, self.session_name);

    }
}

/**
 * @func __EpicSessionsEndSessionCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicSessionsEndSessionCallbackInfo} 
 * @ignore 
 */
function __EpicSessionsEndSessionCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicSessionsEndSessionCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: session_name, type: String
        buffer_read(_buffer, buffer_u32);
        self.session_name = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicSessionsJoinSessionCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicSessionsJoinSessionCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicSessionsJoinSessionCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: session_name, type: String
        if (!is_string(self.session_name)) show_error($"{_where} :: self.session_name expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.session_name));
        buffer_write(_buffer, buffer_string, self.session_name);

    }
}

/**
 * @func __EpicSessionsJoinSessionCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicSessionsJoinSessionCallbackInfo} 
 * @ignore 
 */
function __EpicSessionsJoinSessionCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicSessionsJoinSessionCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: session_name, type: String
        buffer_read(_buffer, buffer_u32);
        self.session_name = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicSessionsRegisterPlayersCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicSessionsRegisterPlayersCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicSessionsRegisterPlayersCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: session_name, type: String
        if (!is_string(self.session_name)) show_error($"{_where} :: self.session_name expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.session_name));
        buffer_write(_buffer, buffer_string, self.session_name);

    }
}

/**
 * @func __EpicSessionsRegisterPlayersCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicSessionsRegisterPlayersCallbackInfo} 
 * @ignore 
 */
function __EpicSessionsRegisterPlayersCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicSessionsRegisterPlayersCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: session_name, type: String
        buffer_read(_buffer, buffer_u32);
        self.session_name = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicSessionsUnregisterPlayersCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicSessionsUnregisterPlayersCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicSessionsUnregisterPlayersCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: session_name, type: String
        if (!is_string(self.session_name)) show_error($"{_where} :: self.session_name expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.session_name));
        buffer_write(_buffer, buffer_string, self.session_name);

    }
}

/**
 * @func __EpicSessionsUnregisterPlayersCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicSessionsUnregisterPlayersCallbackInfo} 
 * @ignore 
 */
function __EpicSessionsUnregisterPlayersCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicSessionsUnregisterPlayersCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: session_name, type: String
        buffer_read(_buffer, buffer_u32);
        self.session_name = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicSessionsFindCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicSessionsFindCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicSessionsFindCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

    }
}

/**
 * @func __EpicSessionsFindCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicSessionsFindCallbackInfo} 
 * @ignore 
 */
function __EpicSessionsFindCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicSessionsFindCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicSessionDetailsInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicSessionDetailsInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicSessionDetailsInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: session_id, type: String
        if (!is_string(self.session_id)) show_error($"{_where} :: self.session_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.session_id));
        buffer_write(_buffer, buffer_string, self.session_id);

        // field: host_address, type: String
        if (!is_string(self.host_address)) show_error($"{_where} :: self.host_address expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.host_address));
        buffer_write(_buffer, buffer_string, self.host_address);

        // field: bucket_id, type: String
        if (!is_string(self.bucket_id)) show_error($"{_where} :: self.bucket_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.bucket_id));
        buffer_write(_buffer, buffer_string, self.bucket_id);

        // field: session_owner_user_id, type: String
        if (!is_string(self.session_owner_user_id)) show_error($"{_where} :: self.session_owner_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.session_owner_user_id));
        buffer_write(_buffer, buffer_string, self.session_owner_user_id);

        // field: num_open_public_connections, type: Int64
        if (!is_numeric(self.num_open_public_connections)) show_error($"{_where} :: self.num_open_public_connections expected number", true);
        buffer_write(_buffer, buffer_u64, self.num_open_public_connections);

        // field: settings_count, type: Int64
        if (!is_numeric(self.settings_count)) show_error($"{_where} :: self.settings_count expected number", true);
        buffer_write(_buffer, buffer_u64, self.settings_count);

    }
}

/**
 * @func __EpicSessionDetailsInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicSessionDetailsInfo} 
 * @ignore 
 */
function __EpicSessionDetailsInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicSessionDetailsInfo();
    with (_inst)
    {
        // field: session_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.session_id = buffer_read(_buffer, buffer_string);

        // field: host_address, type: String
        buffer_read(_buffer, buffer_u32);
        self.host_address = buffer_read(_buffer, buffer_string);

        // field: bucket_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.bucket_id = buffer_read(_buffer, buffer_string);

        // field: session_owner_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.session_owner_user_id = buffer_read(_buffer, buffer_string);

        // field: num_open_public_connections, type: Int64
        self.num_open_public_connections = buffer_read(_buffer, buffer_u64);

        // field: settings_count, type: Int64
        self.settings_count = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicActiveSessionInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicActiveSessionInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicActiveSessionInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: session_name, type: String
        if (!is_string(self.session_name)) show_error($"{_where} :: self.session_name expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.session_name));
        buffer_write(_buffer, buffer_string, self.session_name);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: session_id, type: String
        if (!is_string(self.session_id)) show_error($"{_where} :: self.session_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.session_id));
        buffer_write(_buffer, buffer_string, self.session_id);

        // field: bucket_id, type: String
        if (!is_string(self.bucket_id)) show_error($"{_where} :: self.bucket_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.bucket_id));
        buffer_write(_buffer, buffer_string, self.bucket_id);

    }
}

/**
 * @func __EpicActiveSessionInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicActiveSessionInfo} 
 * @ignore 
 */
function __EpicActiveSessionInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicActiveSessionInfo();
    with (_inst)
    {
        // field: session_name, type: String
        buffer_read(_buffer, buffer_u32);
        self.session_name = buffer_read(_buffer, buffer_string);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: session_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.session_id = buffer_read(_buffer, buffer_string);

        // field: bucket_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.bucket_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicSessionsSessionInviteReceivedCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicSessionsSessionInviteReceivedCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicSessionsSessionInviteReceivedCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: target_user_id, type: String
        if (!is_string(self.target_user_id)) show_error($"{_where} :: self.target_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.target_user_id));
        buffer_write(_buffer, buffer_string, self.target_user_id);

        // field: invite_id, type: String
        if (!is_string(self.invite_id)) show_error($"{_where} :: self.invite_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.invite_id));
        buffer_write(_buffer, buffer_string, self.invite_id);

    }
}

/**
 * @func __EpicSessionsSessionInviteReceivedCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicSessionsSessionInviteReceivedCallbackInfo} 
 * @ignore 
 */
function __EpicSessionsSessionInviteReceivedCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicSessionsSessionInviteReceivedCallbackInfo();
    with (_inst)
    {
        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: target_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.target_user_id = buffer_read(_buffer, buffer_string);

        // field: invite_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.invite_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicSessionsSessionInviteAcceptedCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicSessionsSessionInviteAcceptedCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicSessionsSessionInviteAcceptedCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: target_user_id, type: String
        if (!is_string(self.target_user_id)) show_error($"{_where} :: self.target_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.target_user_id));
        buffer_write(_buffer, buffer_string, self.target_user_id);

        // field: invite_id, type: String
        if (!is_string(self.invite_id)) show_error($"{_where} :: self.invite_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.invite_id));
        buffer_write(_buffer, buffer_string, self.invite_id);

    }
}

/**
 * @func __EpicSessionsSessionInviteAcceptedCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicSessionsSessionInviteAcceptedCallbackInfo} 
 * @ignore 
 */
function __EpicSessionsSessionInviteAcceptedCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicSessionsSessionInviteAcceptedCallbackInfo();
    with (_inst)
    {
        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: target_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.target_user_id = buffer_read(_buffer, buffer_string);

        // field: invite_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.invite_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicSessionsJoinSessionAcceptedCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicSessionsJoinSessionAcceptedCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicSessionsJoinSessionAcceptedCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: ui_event_id, type: UInt64
        if (!is_numeric(self.ui_event_id)) show_error($"{_where} :: self.ui_event_id expected number", true);
        buffer_write(_buffer, buffer_u64, self.ui_event_id);

    }
}

/**
 * @func __EpicSessionsJoinSessionAcceptedCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicSessionsJoinSessionAcceptedCallbackInfo} 
 * @ignore 
 */
function __EpicSessionsJoinSessionAcceptedCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicSessionsJoinSessionAcceptedCallbackInfo();
    with (_inst)
    {
        // field: ui_event_id, type: UInt64
        self.ui_event_id = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicLobbyCreateLobbyCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLobbyCreateLobbyCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLobbyCreateLobbyCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: lobby_id, type: String
        if (!is_string(self.lobby_id)) show_error($"{_where} :: self.lobby_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.lobby_id));
        buffer_write(_buffer, buffer_string, self.lobby_id);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

    }
}

/**
 * @func __EpicLobbyCreateLobbyCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLobbyCreateLobbyCallbackInfo} 
 * @ignore 
 */
function __EpicLobbyCreateLobbyCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLobbyCreateLobbyCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: lobby_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.lobby_id = buffer_read(_buffer, buffer_string);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicLobbyDestroyLobbyCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLobbyDestroyLobbyCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLobbyDestroyLobbyCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: lobby_id, type: String
        if (!is_string(self.lobby_id)) show_error($"{_where} :: self.lobby_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.lobby_id));
        buffer_write(_buffer, buffer_string, self.lobby_id);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

    }
}

/**
 * @func __EpicLobbyDestroyLobbyCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLobbyDestroyLobbyCallbackInfo} 
 * @ignore 
 */
function __EpicLobbyDestroyLobbyCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLobbyDestroyLobbyCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: lobby_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.lobby_id = buffer_read(_buffer, buffer_string);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicLobbyJoinLobbyCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLobbyJoinLobbyCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLobbyJoinLobbyCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: lobby_id, type: String
        if (!is_string(self.lobby_id)) show_error($"{_where} :: self.lobby_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.lobby_id));
        buffer_write(_buffer, buffer_string, self.lobby_id);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

    }
}

/**
 * @func __EpicLobbyJoinLobbyCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLobbyJoinLobbyCallbackInfo} 
 * @ignore 
 */
function __EpicLobbyJoinLobbyCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLobbyJoinLobbyCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: lobby_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.lobby_id = buffer_read(_buffer, buffer_string);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicLobbyLeaveLobbyCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLobbyLeaveLobbyCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLobbyLeaveLobbyCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: lobby_id, type: String
        if (!is_string(self.lobby_id)) show_error($"{_where} :: self.lobby_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.lobby_id));
        buffer_write(_buffer, buffer_string, self.lobby_id);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

    }
}

/**
 * @func __EpicLobbyLeaveLobbyCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLobbyLeaveLobbyCallbackInfo} 
 * @ignore 
 */
function __EpicLobbyLeaveLobbyCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLobbyLeaveLobbyCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: lobby_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.lobby_id = buffer_read(_buffer, buffer_string);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicLobbyUpdateLobbyCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLobbyUpdateLobbyCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLobbyUpdateLobbyCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: lobby_id, type: String
        if (!is_string(self.lobby_id)) show_error($"{_where} :: self.lobby_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.lobby_id));
        buffer_write(_buffer, buffer_string, self.lobby_id);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

    }
}

/**
 * @func __EpicLobbyUpdateLobbyCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLobbyUpdateLobbyCallbackInfo} 
 * @ignore 
 */
function __EpicLobbyUpdateLobbyCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLobbyUpdateLobbyCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: lobby_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.lobby_id = buffer_read(_buffer, buffer_string);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicLobbyPromoteMemberCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLobbyPromoteMemberCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLobbyPromoteMemberCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: lobby_id, type: String
        if (!is_string(self.lobby_id)) show_error($"{_where} :: self.lobby_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.lobby_id));
        buffer_write(_buffer, buffer_string, self.lobby_id);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: target_user_id, type: String
        if (!is_string(self.target_user_id)) show_error($"{_where} :: self.target_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.target_user_id));
        buffer_write(_buffer, buffer_string, self.target_user_id);

    }
}

/**
 * @func __EpicLobbyPromoteMemberCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLobbyPromoteMemberCallbackInfo} 
 * @ignore 
 */
function __EpicLobbyPromoteMemberCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLobbyPromoteMemberCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: lobby_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.lobby_id = buffer_read(_buffer, buffer_string);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: target_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.target_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicLobbyKickMemberCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLobbyKickMemberCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLobbyKickMemberCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

        // field: lobby_id, type: String
        if (!is_string(self.lobby_id)) show_error($"{_where} :: self.lobby_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.lobby_id));
        buffer_write(_buffer, buffer_string, self.lobby_id);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: target_user_id, type: String
        if (!is_string(self.target_user_id)) show_error($"{_where} :: self.target_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.target_user_id));
        buffer_write(_buffer, buffer_string, self.target_user_id);

    }
}

/**
 * @func __EpicLobbyKickMemberCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLobbyKickMemberCallbackInfo} 
 * @ignore 
 */
function __EpicLobbyKickMemberCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLobbyKickMemberCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

        // field: lobby_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.lobby_id = buffer_read(_buffer, buffer_string);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: target_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.target_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicLobbySearchFindCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLobbySearchFindCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLobbySearchFindCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: result_code, type: enum EpicResult

        if (!is_numeric(self.result_code)) show_error($"{_where} :: self.result_code expected number", true);
        buffer_write(_buffer, buffer_u64, self.result_code);

    }
}

/**
 * @func __EpicLobbySearchFindCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLobbySearchFindCallbackInfo} 
 * @ignore 
 */
function __EpicLobbySearchFindCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLobbySearchFindCallbackInfo();
    with (_inst)
    {
        // field: result_code, type: enum EpicResult
        self.result_code = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicLobbyDetailsInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLobbyDetailsInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLobbyDetailsInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: lobby_id, type: String
        if (!is_string(self.lobby_id)) show_error($"{_where} :: self.lobby_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.lobby_id));
        buffer_write(_buffer, buffer_string, self.lobby_id);

        // field: bucket_id, type: String
        if (!is_string(self.bucket_id)) show_error($"{_where} :: self.bucket_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.bucket_id));
        buffer_write(_buffer, buffer_string, self.bucket_id);

        // field: lobby_owner_user_id, type: String
        if (!is_string(self.lobby_owner_user_id)) show_error($"{_where} :: self.lobby_owner_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.lobby_owner_user_id));
        buffer_write(_buffer, buffer_string, self.lobby_owner_user_id);

        // field: available_slots, type: Int64
        if (!is_numeric(self.available_slots)) show_error($"{_where} :: self.available_slots expected number", true);
        buffer_write(_buffer, buffer_u64, self.available_slots);

        // field: max_members, type: Int64
        if (!is_numeric(self.max_members)) show_error($"{_where} :: self.max_members expected number", true);
        buffer_write(_buffer, buffer_u64, self.max_members);

        // field: permission_level, type: enum EpicLobbyPermissionLevel

        if (!is_numeric(self.permission_level)) show_error($"{_where} :: self.permission_level expected number", true);
        buffer_write(_buffer, buffer_u64, self.permission_level);

        // field: allow_invites, type: Bool
        if (!is_bool(self.allow_invites)) show_error($"{_where} :: self.allow_invites expected bool", true);
        buffer_write(_buffer, buffer_bool, self.allow_invites);

        // field: presence_enabled, type: Bool
        if (!is_bool(self.presence_enabled)) show_error($"{_where} :: self.presence_enabled expected bool", true);
        buffer_write(_buffer, buffer_bool, self.presence_enabled);

    }
}

/**
 * @func __EpicLobbyDetailsInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLobbyDetailsInfo} 
 * @ignore 
 */
function __EpicLobbyDetailsInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLobbyDetailsInfo();
    with (_inst)
    {
        // field: lobby_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.lobby_id = buffer_read(_buffer, buffer_string);

        // field: bucket_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.bucket_id = buffer_read(_buffer, buffer_string);

        // field: lobby_owner_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.lobby_owner_user_id = buffer_read(_buffer, buffer_string);

        // field: available_slots, type: Int64
        self.available_slots = buffer_read(_buffer, buffer_u64);

        // field: max_members, type: Int64
        self.max_members = buffer_read(_buffer, buffer_u64);

        // field: permission_level, type: enum EpicLobbyPermissionLevel
        self.permission_level = buffer_read(_buffer, buffer_u64);

        // field: allow_invites, type: Bool
        self.allow_invites = buffer_read(_buffer, buffer_bool);

        // field: presence_enabled, type: Bool
        self.presence_enabled = buffer_read(_buffer, buffer_bool);

    }

    return _inst;
}

/**
 * @func __EpicLobbyLobbyUpdateReceivedCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLobbyLobbyUpdateReceivedCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLobbyLobbyUpdateReceivedCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: lobby_id, type: String
        if (!is_string(self.lobby_id)) show_error($"{_where} :: self.lobby_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.lobby_id));
        buffer_write(_buffer, buffer_string, self.lobby_id);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

    }
}

/**
 * @func __EpicLobbyLobbyUpdateReceivedCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLobbyLobbyUpdateReceivedCallbackInfo} 
 * @ignore 
 */
function __EpicLobbyLobbyUpdateReceivedCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLobbyLobbyUpdateReceivedCallbackInfo();
    with (_inst)
    {
        // field: lobby_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.lobby_id = buffer_read(_buffer, buffer_string);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicLobbyLobbyMemberUpdateReceivedCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLobbyLobbyMemberUpdateReceivedCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLobbyLobbyMemberUpdateReceivedCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: lobby_id, type: String
        if (!is_string(self.lobby_id)) show_error($"{_where} :: self.lobby_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.lobby_id));
        buffer_write(_buffer, buffer_string, self.lobby_id);

        // field: target_user_id, type: String
        if (!is_string(self.target_user_id)) show_error($"{_where} :: self.target_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.target_user_id));
        buffer_write(_buffer, buffer_string, self.target_user_id);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

    }
}

/**
 * @func __EpicLobbyLobbyMemberUpdateReceivedCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLobbyLobbyMemberUpdateReceivedCallbackInfo} 
 * @ignore 
 */
function __EpicLobbyLobbyMemberUpdateReceivedCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLobbyLobbyMemberUpdateReceivedCallbackInfo();
    with (_inst)
    {
        // field: lobby_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.lobby_id = buffer_read(_buffer, buffer_string);

        // field: target_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.target_user_id = buffer_read(_buffer, buffer_string);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicLobbyLobbyMemberStatusReceivedCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLobbyLobbyMemberStatusReceivedCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLobbyLobbyMemberStatusReceivedCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: lobby_id, type: String
        if (!is_string(self.lobby_id)) show_error($"{_where} :: self.lobby_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.lobby_id));
        buffer_write(_buffer, buffer_string, self.lobby_id);

        // field: target_user_id, type: String
        if (!is_string(self.target_user_id)) show_error($"{_where} :: self.target_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.target_user_id));
        buffer_write(_buffer, buffer_string, self.target_user_id);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: current_status, type: enum EpicLobbyMemberStatus

        if (!is_numeric(self.current_status)) show_error($"{_where} :: self.current_status expected number", true);
        buffer_write(_buffer, buffer_u64, self.current_status);

    }
}

/**
 * @func __EpicLobbyLobbyMemberStatusReceivedCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLobbyLobbyMemberStatusReceivedCallbackInfo} 
 * @ignore 
 */
function __EpicLobbyLobbyMemberStatusReceivedCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLobbyLobbyMemberStatusReceivedCallbackInfo();
    with (_inst)
    {
        // field: lobby_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.lobby_id = buffer_read(_buffer, buffer_string);

        // field: target_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.target_user_id = buffer_read(_buffer, buffer_string);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: current_status, type: enum EpicLobbyMemberStatus
        self.current_status = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicLobbyJoinLobbyAcceptedCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLobbyJoinLobbyAcceptedCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLobbyJoinLobbyAcceptedCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: ui_event_id, type: UInt64
        if (!is_numeric(self.ui_event_id)) show_error($"{_where} :: self.ui_event_id expected number", true);
        buffer_write(_buffer, buffer_u64, self.ui_event_id);

    }
}

/**
 * @func __EpicLobbyJoinLobbyAcceptedCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLobbyJoinLobbyAcceptedCallbackInfo} 
 * @ignore 
 */
function __EpicLobbyJoinLobbyAcceptedCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLobbyJoinLobbyAcceptedCallbackInfo();
    with (_inst)
    {
        // field: ui_event_id, type: UInt64
        self.ui_event_id = buffer_read(_buffer, buffer_u64);

    }

    return _inst;
}

/**
 * @func __EpicLobbyLeaveLobbyRequestedCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLobbyLeaveLobbyRequestedCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLobbyLeaveLobbyRequestedCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: lobby_id, type: String
        if (!is_string(self.lobby_id)) show_error($"{_where} :: self.lobby_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.lobby_id));
        buffer_write(_buffer, buffer_string, self.lobby_id);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

    }
}

/**
 * @func __EpicLobbyLeaveLobbyRequestedCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLobbyLeaveLobbyRequestedCallbackInfo} 
 * @ignore 
 */
function __EpicLobbyLeaveLobbyRequestedCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLobbyLeaveLobbyRequestedCallbackInfo();
    with (_inst)
    {
        // field: lobby_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.lobby_id = buffer_read(_buffer, buffer_string);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

/**
 * @func __EpicLobbySendLobbyNativeInviteRequestedCallbackInfo_encode(_inst, _buffer, _offset, _where)
 * @param {Struct.EpicLobbySendLobbyNativeInviteRequestedCallbackInfo} _inst
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @param {String} _where
 * @ignore 
 */
function __EpicLobbySendLobbyNativeInviteRequestedCallbackInfo_encode(_inst, _buffer, _offset, _where = _GMFUNCTION_)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);
    with (_inst)
    {
        // field: lobby_id, type: String
        if (!is_string(self.lobby_id)) show_error($"{_where} :: self.lobby_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.lobby_id));
        buffer_write(_buffer, buffer_string, self.lobby_id);

        // field: local_user_id, type: String
        if (!is_string(self.local_user_id)) show_error($"{_where} :: self.local_user_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.local_user_id));
        buffer_write(_buffer, buffer_string, self.local_user_id);

        // field: target_native_account_type, type: String
        if (!is_string(self.target_native_account_type)) show_error($"{_where} :: self.target_native_account_type expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.target_native_account_type));
        buffer_write(_buffer, buffer_string, self.target_native_account_type);

        // field: target_user_native_account_id, type: String
        if (!is_string(self.target_user_native_account_id)) show_error($"{_where} :: self.target_user_native_account_id expected string", true);
        buffer_write(_buffer, buffer_u32, string_length(self.target_user_native_account_id));
        buffer_write(_buffer, buffer_string, self.target_user_native_account_id);

    }
}

/**
 * @func __EpicLobbySendLobbyNativeInviteRequestedCallbackInfo_decode(_buffer, _offset)
 * @param {Id.Buffer} _buffer
 * @param {Real} _offset
 * @returns {Struct.EpicLobbySendLobbyNativeInviteRequestedCallbackInfo} 
 * @ignore 
 */
function __EpicLobbySendLobbyNativeInviteRequestedCallbackInfo_decode(_buffer, _offset)
{
    buffer_seek(_buffer, buffer_seek_start, _offset);

    _inst = new EpicLobbySendLobbyNativeInviteRequestedCallbackInfo();
    with (_inst)
    {
        // field: lobby_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.lobby_id = buffer_read(_buffer, buffer_string);

        // field: local_user_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.local_user_id = buffer_read(_buffer, buffer_string);

        // field: target_native_account_type, type: String
        buffer_read(_buffer, buffer_u32);
        self.target_native_account_type = buffer_read(_buffer, buffer_string);

        // field: target_user_native_account_id, type: String
        buffer_read(_buffer, buffer_u32);
        self.target_user_native_account_id = buffer_read(_buffer, buffer_string);

    }

    return _inst;
}

// #####################################################################
// # Functions
// #####################################################################

// Skipping function eos_test (no wrapper is required)


// Skipping function eos_api_last_error (no wrapper is required)


// Skipping function eos_api_is_initialized (no wrapper is required)


/**
 * @param {String} _product_name
 * @param {String} _product_version
 * @returns {Enum.EpicResult} 
 */
function eos_api_initialize(_product_name, _product_version)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_api_initialize(_product_name, _product_version, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @returns {Enum.EpicResult} 
 */
function eos_api_shutdown()
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_api_shutdown(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

// Skipping function eos_api_get_version (no wrapper is required)


/**
 * @param {Enum.EpicResult} _result
 * @returns {String} 
 */
function eos_api_result_to_string(_result)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _result, type: enum EpicResult

    if (!is_numeric(_result)) show_error($"{_GMFUNCTION_} :: _result expected number", true);
    buffer_write(__args_buffer, buffer_u64, _result);

    var _return_value = __eos_api_result_to_string(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Enum.EpicResult} _result
 * @returns {Bool} 
 */
function eos_api_result_is_operation_complete(_result)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _result, type: enum EpicResult

    if (!is_numeric(_result)) show_error($"{_GMFUNCTION_} :: _result expected number", true);
    buffer_write(__args_buffer, buffer_u64, _result);

    var _return_value = __eos_api_result_is_operation_complete(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Enum.EpicApplicationStatus} _status
 * @returns {String} 
 */
function eos_api_application_status_to_string(_status)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _status, type: enum EpicApplicationStatus

    if (!is_numeric(_status)) show_error($"{_GMFUNCTION_} :: _status expected number", true);
    buffer_write(__args_buffer, buffer_u64, _status);

    var _return_value = __eos_api_application_status_to_string(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Enum.EpicNetworkStatus} _status
 * @returns {String} 
 */
function eos_api_network_status_to_string(_status)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _status, type: enum EpicNetworkStatus

    if (!is_numeric(_status)) show_error($"{_GMFUNCTION_} :: _status expected number", true);
    buffer_write(__args_buffer, buffer_u64, _status);

    var _return_value = __eos_api_network_status_to_string(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

// Skipping function eos_api_epic_account_id_is_valid (no wrapper is required)


// Skipping function eos_api_product_user_id_is_valid (no wrapper is required)


// Skipping function eos_platform_is_created (no wrapper is required)


/**
 * @param {Bool} _is_server
 * @param {String} _product_id
 * @param {String} _sandbox_id
 * @param {String} _deployment_id
 * @param {String} _client_id
 * @param {String} _client_secret
 * @returns {Enum.EpicResult} 
 */
function eos_platform_create(_is_server, _product_id, _sandbox_id, _deployment_id, _client_id, _client_secret)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _is_server, type: Bool
    if (!is_bool(_is_server)) show_error($"{_GMFUNCTION_} :: _is_server expected bool", true);
    buffer_write(__args_buffer, buffer_bool, _is_server);

    // param: _product_id, type: String
    if (!is_string(_product_id)) show_error($"{_GMFUNCTION_} :: _product_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_product_id));
    buffer_write(__args_buffer, buffer_string, _product_id);

    // param: _sandbox_id, type: String
    if (!is_string(_sandbox_id)) show_error($"{_GMFUNCTION_} :: _sandbox_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_sandbox_id));
    buffer_write(__args_buffer, buffer_string, _sandbox_id);

    // param: _deployment_id, type: String
    if (!is_string(_deployment_id)) show_error($"{_GMFUNCTION_} :: _deployment_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_deployment_id));
    buffer_write(__args_buffer, buffer_string, _deployment_id);

    // param: _client_id, type: String
    if (!is_string(_client_id)) show_error($"{_GMFUNCTION_} :: _client_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_client_id));
    buffer_write(__args_buffer, buffer_string, _client_id);

    // param: _client_secret, type: String
    if (!is_string(_client_secret)) show_error($"{_GMFUNCTION_} :: _client_secret expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_client_secret));
    buffer_write(__args_buffer, buffer_string, _client_secret);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_platform_create(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

// Skipping function eos_platform_release (no wrapper is required)


// Skipping function eos_platform_tick (no wrapper is required)


/**
 * @returns {Enum.EpicResult} 
 */
function eos_platform_check_for_launcher_and_restart()
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_platform_check_for_launcher_and_restart(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Enum.EpicNetworkStatus} _status
 * @returns {Enum.EpicResult} 
 */
function eos_platform_set_network_status(_status)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _status, type: enum EpicNetworkStatus

    if (!is_numeric(_status)) show_error($"{_GMFUNCTION_} :: _status expected number", true);
    buffer_write(__args_buffer, buffer_u64, _status);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_platform_set_network_status(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Function} _callback
 */
function eos_logging_set_callback(_callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_logging_set_callback(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

// Skipping function eos_logging_clear_callback (no wrapper is required)


/**
 * @param {Enum.EpicLogCategory} _log_category
 * @param {Enum.EpicLogLevel} _log_level
 * @returns {Enum.EpicResult} 
 */
function eos_logging_set_log_level(_log_category, _log_level)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _log_category, type: enum EpicLogCategory

    if (!is_numeric(_log_category)) show_error($"{_GMFUNCTION_} :: _log_category expected number", true);
    buffer_write(__args_buffer, buffer_u64, _log_category);

    // param: _log_level, type: enum EpicLogLevel

    if (!is_numeric(_log_level)) show_error($"{_GMFUNCTION_} :: _log_level expected number", true);
    buffer_write(__args_buffer, buffer_u64, _log_level);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_logging_set_log_level(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {String} _credentials_id
 * @param {String} _credentials_token
 * @param {Enum.EpicLoginCredentialType} _credentials_type
 * @param {Enum.EpicExternalCredentialType} _external_credential_type
 * @param {Enum.EpicAuthScopeFlags} _scope_flags
 * @param {Function} _callback
 */
function eos_auth_login(_credentials_id, _credentials_token, _credentials_type, _external_credential_type, _scope_flags, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _credentials_id, type: String
    if (!is_string(_credentials_id)) show_error($"{_GMFUNCTION_} :: _credentials_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_credentials_id));
    buffer_write(__args_buffer, buffer_string, _credentials_id);

    // param: _credentials_token, type: String
    if (!is_string(_credentials_token)) show_error($"{_GMFUNCTION_} :: _credentials_token expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_credentials_token));
    buffer_write(__args_buffer, buffer_string, _credentials_token);

    // param: _credentials_type, type: enum EpicLoginCredentialType

    if (!is_numeric(_credentials_type)) show_error($"{_GMFUNCTION_} :: _credentials_type expected number", true);
    buffer_write(__args_buffer, buffer_u64, _credentials_type);

    // param: _external_credential_type, type: enum EpicExternalCredentialType

    if (!is_numeric(_external_credential_type)) show_error($"{_GMFUNCTION_} :: _external_credential_type expected number", true);
    buffer_write(__args_buffer, buffer_u64, _external_credential_type);

    // param: _scope_flags, type: enum EpicAuthScopeFlags

    if (!is_numeric(_scope_flags)) show_error($"{_GMFUNCTION_} :: _scope_flags expected number", true);
    buffer_write(__args_buffer, buffer_u64, _scope_flags);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_auth_login(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {Function} _callback
 */
function eos_auth_logout(_local_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_auth_logout(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {Enum.EpicLinkAccountFlags} _link_account_flags
 * @param {Function} _callback
 */
function eos_auth_link_account(_local_user_id, _link_account_flags, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _link_account_flags, type: enum EpicLinkAccountFlags

    if (!is_numeric(_link_account_flags)) show_error($"{_GMFUNCTION_} :: _link_account_flags expected number", true);
    buffer_write(__args_buffer, buffer_u64, _link_account_flags);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_auth_link_account(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 */
function eos_auth_delete_persistent_auth(_callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_auth_delete_persistent_auth(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @returns {Real} 
 */
function eos_auth_get_logged_in_accounts_count()
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_auth_get_logged_in_accounts_count(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _index
 * @returns {String} 
 */
function eos_auth_get_logged_in_account_by_index(_index)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _index, type: Int64
    if (!is_numeric(_index)) show_error($"{_GMFUNCTION_} :: _index expected number", true);
    buffer_write(__args_buffer, buffer_u64, _index);

    var _return_value = __eos_auth_get_logged_in_account_by_index(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @returns {Enum.EpicLoginStatus} 
 */
function eos_auth_get_login_status(_local_user_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_auth_get_login_status(_local_user_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {String} _local_user_id
 * @param {String} _target_account_id
 * @returns {Struct.EpicAuthIdToken} 
 */
function eos_auth_copy_id_token(_local_user_id, _target_account_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_auth_copy_id_token(_local_user_id, _target_account_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicAuthIdToken_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _local_user_id
 * @returns {Struct.EpicAuthUserAuthToken} 
 */
function eos_auth_copy_user_auth_token(_local_user_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_auth_copy_user_auth_token(_local_user_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicAuthUserAuthToken_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _local_user_id
 * @param {String} _target_account_id
 * @param {Function} _callback
 */
function eos_auth_query_id_token(_local_user_id, _target_account_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _target_account_id, type: String
    if (!is_string(_target_account_id)) show_error($"{_GMFUNCTION_} :: _target_account_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_account_id));
    buffer_write(__args_buffer, buffer_string, _target_account_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_auth_query_id_token(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _json_web_token
 * @param {Function} _callback
 */
function eos_auth_verify_id_token(_json_web_token, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _json_web_token, type: String
    if (!is_string(_json_web_token)) show_error($"{_GMFUNCTION_} :: _json_web_token expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_json_web_token));
    buffer_write(__args_buffer, buffer_string, _json_web_token);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_auth_verify_id_token(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _access_token
 * @param {Function} _callback
 */
function eos_auth_verify_user_auth(_access_token, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _access_token, type: String
    if (!is_string(_access_token)) show_error($"{_GMFUNCTION_} :: _access_token expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_access_token));
    buffer_write(__args_buffer, buffer_string, _access_token);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_auth_verify_user_auth(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Real} 
 */
function eos_auth_add_notify_login_status_changed(_callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_auth_add_notify_login_status_changed(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _notification_id
 */
function eos_auth_remove_notify_login_status_changed(_notification_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _notification_id, type: UInt64
    if (!is_numeric(_notification_id)) show_error($"{_GMFUNCTION_} :: _notification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _notification_id);

    var _return_value = __eos_auth_remove_notify_login_status_changed(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _token
 * @param {Enum.EpicExternalCredentialType} _external_credential_type
 * @param {String} _display_name
 * @param {Function} _callback
 */
function eos_connect_login(_token, _external_credential_type, _display_name, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _token, type: String
    if (!is_string(_token)) show_error($"{_GMFUNCTION_} :: _token expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_token));
    buffer_write(__args_buffer, buffer_string, _token);

    // param: _external_credential_type, type: enum EpicExternalCredentialType

    if (!is_numeric(_external_credential_type)) show_error($"{_GMFUNCTION_} :: _external_credential_type expected number", true);
    buffer_write(__args_buffer, buffer_u64, _external_credential_type);

    // param: _display_name, type: String
    if (!is_string(_display_name)) show_error($"{_GMFUNCTION_} :: _display_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_display_name));
    buffer_write(__args_buffer, buffer_string, _display_name);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_connect_login(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 */
function eos_connect_create_user(_callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_connect_create_user(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {Function} _callback
 */
function eos_connect_link_account(_local_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_connect_link_account(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {Function} _callback
 */
function eos_connect_unlink_account(_local_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_connect_unlink_account(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _device_model
 * @param {Function} _callback
 */
function eos_connect_create_device_id(_device_model, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _device_model, type: String
    if (!is_string(_device_model)) show_error($"{_GMFUNCTION_} :: _device_model expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_device_model));
    buffer_write(__args_buffer, buffer_string, _device_model);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_connect_create_device_id(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 */
function eos_connect_delete_device_id(_callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_connect_delete_device_id(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _primary_local_user_id
 * @param {String} _local_device_user_id
 * @param {Function} _callback
 */
function eos_connect_transfer_device_id_account(_primary_local_user_id, _local_device_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _primary_local_user_id, type: String
    if (!is_string(_primary_local_user_id)) show_error($"{_GMFUNCTION_} :: _primary_local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_primary_local_user_id));
    buffer_write(__args_buffer, buffer_string, _primary_local_user_id);

    // param: _local_device_user_id, type: String
    if (!is_string(_local_device_user_id)) show_error($"{_GMFUNCTION_} :: _local_device_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_device_user_id));
    buffer_write(__args_buffer, buffer_string, _local_device_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_connect_transfer_device_id_account(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {Function} _callback
 */
function eos_connect_logout(_local_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_connect_logout(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @returns {Real} 
 */
function eos_connect_get_logged_in_users_count()
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_connect_get_logged_in_users_count(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _index
 * @returns {String} 
 */
function eos_connect_get_logged_in_user_by_index(_index)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _index, type: Int64
    if (!is_numeric(_index)) show_error($"{_GMFUNCTION_} :: _index expected number", true);
    buffer_write(__args_buffer, buffer_u64, _index);

    var _return_value = __eos_connect_get_logged_in_user_by_index(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @returns {Enum.EpicLoginStatus} 
 */
function eos_connect_get_login_status(_local_user_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_connect_get_login_status(_local_user_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {String} _local_user_id
 * @returns {Struct.EpicConnectIdToken} 
 */
function eos_connect_copy_id_token(_local_user_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_connect_copy_id_token(_local_user_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicConnectIdToken_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _target_user_id
 * @returns {Struct.EpicConnectExternalAccountInfo} 
 */
function eos_connect_copy_product_user_info(_target_user_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_connect_copy_product_user_info(_target_user_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicConnectExternalAccountInfo_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _target_user_id
 * @param {Real} _index
 * @returns {Struct.EpicConnectExternalAccountInfo} 
 */
function eos_connect_copy_product_user_external_account_by_index(_target_user_id, _index)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    // param: _index, type: Int64
    if (!is_numeric(_index)) show_error($"{_GMFUNCTION_} :: _index expected number", true);
    buffer_write(__args_buffer, buffer_u64, _index);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_connect_copy_product_user_external_account_by_index(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicConnectExternalAccountInfo_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _target_user_id
 * @param {Enum.EpicExternalAccountType} _account_id_type
 * @returns {Struct.EpicConnectExternalAccountInfo} 
 */
function eos_connect_copy_product_user_external_account_by_account_type(_target_user_id, _account_id_type)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    // param: _account_id_type, type: enum EpicExternalAccountType

    if (!is_numeric(_account_id_type)) show_error($"{_GMFUNCTION_} :: _account_id_type expected number", true);
    buffer_write(__args_buffer, buffer_u64, _account_id_type);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_connect_copy_product_user_external_account_by_account_type(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicConnectExternalAccountInfo_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _target_user_id
 * @param {String} _account_id
 * @returns {Struct.EpicConnectExternalAccountInfo} 
 */
function eos_connect_copy_product_user_external_account_by_account_id(_target_user_id, _account_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_connect_copy_product_user_external_account_by_account_id(_target_user_id, _account_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicConnectExternalAccountInfo_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _local_user_id
 * @param {Enum.EpicExternalAccountType} _account_id_type
 * @param {String} _target_external_user_id
 * @returns {String} 
 */
function eos_connect_get_product_user_id_mapping(_local_user_id, _account_id_type, _target_external_user_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _account_id_type, type: enum EpicExternalAccountType

    if (!is_numeric(_account_id_type)) show_error($"{_GMFUNCTION_} :: _account_id_type expected number", true);
    buffer_write(__args_buffer, buffer_u64, _account_id_type);

    // param: _target_external_user_id, type: String
    if (!is_string(_target_external_user_id)) show_error($"{_GMFUNCTION_} :: _target_external_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_external_user_id));
    buffer_write(__args_buffer, buffer_string, _target_external_user_id);

    var _return_value = __eos_connect_get_product_user_id_mapping(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {Enum.EpicExternalAccountType} _account_id_type
 * @param {String} _target_external_user_id
 * @returns {String} 
 */
function eos_connect_get_external_account_mapping(_local_user_id, _account_id_type, _target_external_user_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _account_id_type, type: enum EpicExternalAccountType

    if (!is_numeric(_account_id_type)) show_error($"{_GMFUNCTION_} :: _account_id_type expected number", true);
    buffer_write(__args_buffer, buffer_u64, _account_id_type);

    // param: _target_external_user_id, type: String
    if (!is_string(_target_external_user_id)) show_error($"{_GMFUNCTION_} :: _target_external_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_external_user_id));
    buffer_write(__args_buffer, buffer_string, _target_external_user_id);

    var _return_value = __eos_connect_get_external_account_mapping(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _json_web_token
 * @param {Function} _callback
 */
function eos_connect_verify_id_token(_json_web_token, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _json_web_token, type: String
    if (!is_string(_json_web_token)) show_error($"{_GMFUNCTION_} :: _json_web_token expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_json_web_token));
    buffer_write(__args_buffer, buffer_string, _json_web_token);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_connect_verify_id_token(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {Enum.EpicExternalAccountType} _account_id_type
 * @param {Array[String]} _target_external_user_ids
 * @param {Function} _callback
 */
function eos_connect_query_external_account_mappings(_local_user_id, _account_id_type, _target_external_user_ids, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _account_id_type, type: enum EpicExternalAccountType

    if (!is_numeric(_account_id_type)) show_error($"{_GMFUNCTION_} :: _account_id_type expected number", true);
    buffer_write(__args_buffer, buffer_u64, _account_id_type);

    // param: _target_external_user_ids, type: String[]
    if (!is_array(_target_external_user_ids)) show_error($"{_GMFUNCTION_} :: _target_external_user_ids expected array", true);
    var _length = array_length(_target_external_user_ids);
    buffer_write(__args_buffer, buffer_u32, _length);
    for (var _i = 0; _i < _length; ++_i)
    {
        if (!is_string(_target_external_user_ids[_i])) show_error($"{_GMFUNCTION_} :: _target_external_user_ids[_i] expected string", true);
        buffer_write(__args_buffer, buffer_u32, string_length(_target_external_user_ids[_i]));
        buffer_write(__args_buffer, buffer_string, _target_external_user_ids[_i]);
    }

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_connect_query_external_account_mappings(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {Enum.EpicExternalAccountType} _account_id_type
 * @param {Array[String]} _target_product_user_ids
 * @param {Function} _callback
 */
function eos_connect_query_product_user_id_mappings(_local_user_id, _account_id_type, _target_product_user_ids, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _account_id_type, type: enum EpicExternalAccountType

    if (!is_numeric(_account_id_type)) show_error($"{_GMFUNCTION_} :: _account_id_type expected number", true);
    buffer_write(__args_buffer, buffer_u64, _account_id_type);

    // param: _target_product_user_ids, type: String[]
    if (!is_array(_target_product_user_ids)) show_error($"{_GMFUNCTION_} :: _target_product_user_ids expected array", true);
    var _length = array_length(_target_product_user_ids);
    buffer_write(__args_buffer, buffer_u32, _length);
    for (var _i = 0; _i < _length; ++_i)
    {
        if (!is_string(_target_product_user_ids[_i])) show_error($"{_GMFUNCTION_} :: _target_product_user_ids[_i] expected string", true);
        buffer_write(__args_buffer, buffer_u32, string_length(_target_product_user_ids[_i]));
        buffer_write(__args_buffer, buffer_string, _target_product_user_ids[_i]);
    }

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_connect_query_product_user_id_mappings(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Real} 
 */
function eos_connect_add_notify_auth_expiration(_callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_connect_add_notify_auth_expiration(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _notification_id
 */
function eos_connect_remove_notify_auth_expiration(_notification_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _notification_id, type: UInt64
    if (!is_numeric(_notification_id)) show_error($"{_GMFUNCTION_} :: _notification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _notification_id);

    var _return_value = __eos_connect_remove_notify_auth_expiration(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Real} 
 */
function eos_connect_add_notify_login_status_changed(_callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_connect_add_notify_login_status_changed(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _notification_id
 */
function eos_connect_remove_notify_login_status_changed(_notification_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _notification_id, type: UInt64
    if (!is_numeric(_notification_id)) show_error($"{_GMFUNCTION_} :: _notification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _notification_id);

    var _return_value = __eos_connect_remove_notify_login_status_changed(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {Function} _callback
 */
function eos_friends_query_friends(_local_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_friends_query_friends(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @returns {Real} 
 */
function eos_friends_get_friends_count(_local_user_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_friends_get_friends_count(_local_user_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {String} _local_user_id
 * @param {Real} _index
 * @returns {String} 
 */
function eos_friends_get_friend_at_index(_local_user_id, _index)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _index, type: Int64
    if (!is_numeric(_index)) show_error($"{_GMFUNCTION_} :: _index expected number", true);
    buffer_write(__args_buffer, buffer_u64, _index);

    var _return_value = __eos_friends_get_friend_at_index(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @returns {Enum.EpicFriendsStatus} 
 */
function eos_friends_get_status(_local_user_id, _target_user_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_friends_get_status(_local_user_id, _target_user_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Function} _callback
 * @returns {Real} 
 */
function eos_friends_add_notify_friends_update(_callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_friends_add_notify_friends_update(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _notification_id
 */
function eos_friends_remove_notify_friends_update(_notification_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _notification_id, type: UInt64
    if (!is_numeric(_notification_id)) show_error($"{_GMFUNCTION_} :: _notification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _notification_id);

    var _return_value = __eos_friends_remove_notify_friends_update(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @param {Function} _callback
 */
function eos_user_info_query_user_info(_local_user_id, _target_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_user_info_query_user_info(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @returns {Struct.EpicUserInfo} 
 */
function eos_user_info_copy_user_info(_local_user_id, _target_user_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_user_info_copy_user_info(_local_user_id, _target_user_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicUserInfo_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @returns {Enum.EpicExternalAccountType} 
 */
function eos_user_info_get_local_platform_type(_local_user_id, _target_user_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_user_info_get_local_platform_type(_local_user_id, _target_user_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

// Skipping function eos_user_info_copy_best_display_name (no wrapper is required)


/**
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @param {Real} _index
 * @returns {Struct.EpicUserInfoExternalUserInfo} 
 */
function eos_user_info_copy_external_user_info_by_index(_local_user_id, _target_user_id, _index)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    // param: _index, type: Int64
    if (!is_numeric(_index)) show_error($"{_GMFUNCTION_} :: _index expected number", true);
    buffer_write(__args_buffer, buffer_u64, _index);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_user_info_copy_external_user_info_by_index(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicUserInfoExternalUserInfo_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @param {Enum.EpicExternalAccountType} _account_type
 * @returns {Struct.EpicUserInfoExternalUserInfo} 
 */
function eos_user_info_copy_external_user_info_by_account_type(_local_user_id, _target_user_id, _account_type)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    // param: _account_type, type: enum EpicExternalAccountType

    if (!is_numeric(_account_type)) show_error($"{_GMFUNCTION_} :: _account_type expected number", true);
    buffer_write(__args_buffer, buffer_u64, _account_type);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_user_info_copy_external_user_info_by_account_type(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicUserInfoExternalUserInfo_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @param {String} _account_id
 * @returns {Struct.EpicUserInfoExternalUserInfo} 
 */
function eos_user_info_copy_external_user_info_by_account_id(_local_user_id, _target_user_id, _account_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    // param: _account_id, type: String
    if (!is_string(_account_id)) show_error($"{_GMFUNCTION_} :: _account_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_account_id));
    buffer_write(__args_buffer, buffer_string, _account_id);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_user_info_copy_external_user_info_by_account_id(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicUserInfoExternalUserInfo_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @param {String} _stat_name
 * @param {Real} _ingest_amount
 * @param {Function} _callback
 */
function eos_stats_ingest_stat(_local_user_id, _target_user_id, _stat_name, _ingest_amount, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    // param: _stat_name, type: String
    if (!is_string(_stat_name)) show_error($"{_GMFUNCTION_} :: _stat_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_stat_name));
    buffer_write(__args_buffer, buffer_string, _stat_name);

    // param: _ingest_amount, type: Int64
    if (!is_numeric(_ingest_amount)) show_error($"{_GMFUNCTION_} :: _ingest_amount expected number", true);
    buffer_write(__args_buffer, buffer_u64, _ingest_amount);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_stats_ingest_stat(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @param {Real} _start_time
 * @param {Real} _end_time
 * @param {Function} _callback
 */
function eos_stats_query_stats(_local_user_id, _target_user_id, _start_time, _end_time, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    // param: _start_time, type: Int64
    if (!is_numeric(_start_time)) show_error($"{_GMFUNCTION_} :: _start_time expected number", true);
    buffer_write(__args_buffer, buffer_u64, _start_time);

    // param: _end_time, type: Int64
    if (!is_numeric(_end_time)) show_error($"{_GMFUNCTION_} :: _end_time expected number", true);
    buffer_write(__args_buffer, buffer_u64, _end_time);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_stats_query_stats(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @returns {Real} 
 */
function eos_stats_get_stats_count(_local_user_id, _target_user_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_stats_get_stats_count(_local_user_id, _target_user_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @param {Real} _index
 * @returns {Struct.EpicStatsStat} 
 */
function eos_stats_copy_stat_by_index(_local_user_id, _target_user_id, _index)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    // param: _index, type: Int64
    if (!is_numeric(_index)) show_error($"{_GMFUNCTION_} :: _index expected number", true);
    buffer_write(__args_buffer, buffer_u64, _index);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_stats_copy_stat_by_index(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicStatsStat_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @param {String} _name
 * @returns {Struct.EpicStatsStat} 
 */
function eos_stats_copy_stat_by_name(_local_user_id, _target_user_id, _name)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    // param: _name, type: String
    if (!is_string(_name)) show_error($"{_GMFUNCTION_} :: _name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_name));
    buffer_write(__args_buffer, buffer_string, _name);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_stats_copy_stat_by_name(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicStatsStat_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _local_user_id
 * @param {Function} _callback
 */
function eos_ui_show_friends(_local_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_ui_show_friends(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @param {Function} _callback
 */
function eos_ui_show_native_profile(_local_user_id, _target_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_ui_show_native_profile(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Real} _ui_event_id
 */
function eos_ui_acknowledge_event_id(_ui_event_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _ui_event_id, type: UInt64
    if (!is_numeric(_ui_event_id)) show_error($"{_GMFUNCTION_} :: _ui_event_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _ui_event_id);

    var _return_value = __eos_ui_acknowledge_event_id(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Enum.EpicUINotificationLocation} _notification_location
 */
function eos_ui_set_display_preference(_notification_location)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _notification_location, type: enum EpicUINotificationLocation

    if (!is_numeric(_notification_location)) show_error($"{_GMFUNCTION_} :: _notification_location expected number", true);
    buffer_write(__args_buffer, buffer_u64, _notification_location);

    var _return_value = __eos_ui_set_display_preference(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

// Skipping function eos_ui_report_input_state (no wrapper is required)


/**
 * @param {Function} _callback
 * @returns {Real} 
 */
function eos_ui_add_notify_display_settings_updated(_callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_ui_add_notify_display_settings_updated(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _notification_id
 */
function eos_ui_remove_notify_display_settings_updated(_notification_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _notification_id, type: UInt64
    if (!is_numeric(_notification_id)) show_error($"{_GMFUNCTION_} :: _notification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _notification_id);

    var _return_value = __eos_ui_remove_notify_display_settings_updated(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _product_user_id
 * @param {Enum.EpicMetricsAccountIdType} _account_id_type
 * @param {Enum.EpicUserControllerType} _controller_type
 * @param {String} _server_ip
 * @param {String} _game_session_id
 * @returns {Enum.EpicResult} 
 */
function eos_metrics_begin_player_session(_product_user_id, _account_id_type, _controller_type, _server_ip, _game_session_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _product_user_id, type: String
    if (!is_string(_product_user_id)) show_error($"{_GMFUNCTION_} :: _product_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_product_user_id));
    buffer_write(__args_buffer, buffer_string, _product_user_id);

    // param: _account_id_type, type: enum EpicMetricsAccountIdType

    if (!is_numeric(_account_id_type)) show_error($"{_GMFUNCTION_} :: _account_id_type expected number", true);
    buffer_write(__args_buffer, buffer_u64, _account_id_type);

    // param: _controller_type, type: enum EpicUserControllerType

    if (!is_numeric(_controller_type)) show_error($"{_GMFUNCTION_} :: _controller_type expected number", true);
    buffer_write(__args_buffer, buffer_u64, _controller_type);

    // param: _server_ip, type: String
    if (!is_string(_server_ip)) show_error($"{_GMFUNCTION_} :: _server_ip expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_server_ip));
    buffer_write(__args_buffer, buffer_string, _server_ip);

    // param: _game_session_id, type: String
    if (!is_string(_game_session_id)) show_error($"{_GMFUNCTION_} :: _game_session_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_game_session_id));
    buffer_write(__args_buffer, buffer_string, _game_session_id);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_metrics_begin_player_session(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {String} _product_user_id
 * @param {Enum.EpicMetricsAccountIdType} _account_id_type
 * @param {Enum.EpicUserControllerType} _controller_type
 * @param {String} _server_ip
 * @param {String} _game_session_id
 * @returns {Enum.EpicResult} 
 */
function eos_metrics_end_player_session(_product_user_id, _account_id_type, _controller_type, _server_ip, _game_session_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _product_user_id, type: String
    if (!is_string(_product_user_id)) show_error($"{_GMFUNCTION_} :: _product_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_product_user_id));
    buffer_write(__args_buffer, buffer_string, _product_user_id);

    // param: _account_id_type, type: enum EpicMetricsAccountIdType

    if (!is_numeric(_account_id_type)) show_error($"{_GMFUNCTION_} :: _account_id_type expected number", true);
    buffer_write(__args_buffer, buffer_u64, _account_id_type);

    // param: _controller_type, type: enum EpicUserControllerType

    if (!is_numeric(_controller_type)) show_error($"{_GMFUNCTION_} :: _controller_type expected number", true);
    buffer_write(__args_buffer, buffer_u64, _controller_type);

    // param: _server_ip, type: String
    if (!is_string(_server_ip)) show_error($"{_GMFUNCTION_} :: _server_ip expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_server_ip));
    buffer_write(__args_buffer, buffer_string, _server_ip);

    // param: _game_session_id, type: String
    if (!is_string(_game_session_id)) show_error($"{_GMFUNCTION_} :: _game_session_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_game_session_id));
    buffer_write(__args_buffer, buffer_string, _game_session_id);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_metrics_end_player_session(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {String} _reporter_user_id
 * @param {String} _reported_user_id
 * @param {Enum.EpicPlayerReportsCategory} _category
 * @param {String} _message
 * @param {String} _context
 * @param {Function} _callback
 */
function eos_reports_send_player_behavior_report(_reporter_user_id, _reported_user_id, _category, _message, _context, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _reporter_user_id, type: String
    if (!is_string(_reporter_user_id)) show_error($"{_GMFUNCTION_} :: _reporter_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_reporter_user_id));
    buffer_write(__args_buffer, buffer_string, _reporter_user_id);

    // param: _reported_user_id, type: String
    if (!is_string(_reported_user_id)) show_error($"{_GMFUNCTION_} :: _reported_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_reported_user_id));
    buffer_write(__args_buffer, buffer_string, _reported_user_id);

    // param: _category, type: enum EpicPlayerReportsCategory

    if (!is_numeric(_category)) show_error($"{_GMFUNCTION_} :: _category expected number", true);
    buffer_write(__args_buffer, buffer_u64, _category);

    // param: _message, type: String
    if (!is_string(_message)) show_error($"{_GMFUNCTION_} :: _message expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_message));
    buffer_write(__args_buffer, buffer_string, _message);

    // param: _context, type: String
    if (!is_string(_context)) show_error($"{_GMFUNCTION_} :: _context expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_context));
    buffer_write(__args_buffer, buffer_string, _context);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_reports_send_player_behavior_report(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _target_user_id
 * @param {Function} _callback
 */
function eos_sanctions_query_active_player_sanctions(_target_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_sanctions_query_active_player_sanctions(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _target_user_id
 * @returns {Real} 
 */
function eos_sanctions_get_player_sanction_count(_target_user_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_sanctions_get_player_sanction_count(_target_user_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {String} _target_user_id
 * @param {Real} _index
 * @returns {Struct.EpicSanctionsPlayerSanction} 
 */
function eos_sanctions_copy_player_sanction_by_index(_target_user_id, _index)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    // param: _index, type: Int64
    if (!is_numeric(_index)) show_error($"{_GMFUNCTION_} :: _index expected number", true);
    buffer_write(__args_buffer, buffer_u64, _index);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_sanctions_copy_player_sanction_by_index(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicSanctionsPlayerSanction_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _local_user_id
 * @param {String} _reference_id
 * @param {Enum.EpicSanctionAppealReason} _reason
 * @param {String} _message
 * @param {Function} _callback
 */
function eos_sanctions_create_player_sanction_appeal(_local_user_id, _reference_id, _reason, _message, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _reference_id, type: String
    if (!is_string(_reference_id)) show_error($"{_GMFUNCTION_} :: _reference_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_reference_id));
    buffer_write(__args_buffer, buffer_string, _reference_id);

    // param: _reason, type: enum EpicSanctionAppealReason

    if (!is_numeric(_reason)) show_error($"{_GMFUNCTION_} :: _reason expected number", true);
    buffer_write(__args_buffer, buffer_u64, _reason);

    // param: _message, type: String
    if (!is_string(_message)) show_error($"{_GMFUNCTION_} :: _message expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_message));
    buffer_write(__args_buffer, buffer_string, _message);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_sanctions_create_player_sanction_appeal(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {Function} _callback
 */
function eos_achievements_query_definitions(_local_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_achievements_query_definitions(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @param {Function} _callback
 */
function eos_achievements_query_player_achievements(_local_user_id, _target_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_achievements_query_player_achievements(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @returns {Real} 
 */
function eos_achievements_get_achievement_definition_count()
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_achievements_get_achievement_definition_count(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @returns {Real} 
 */
function eos_achievements_get_player_achievement_count(_local_user_id, _target_user_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_achievements_get_player_achievement_count(_local_user_id, _target_user_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _index
 * @returns {Struct.EpicAchievementsDefinition} 
 */
function eos_achievements_copy_achievement_definition_by_index(_index)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _index, type: Int64
    if (!is_numeric(_index)) show_error($"{_GMFUNCTION_} :: _index expected number", true);
    buffer_write(__args_buffer, buffer_u64, _index);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_achievements_copy_achievement_definition_by_index(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicAchievementsDefinition_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {Real} _index
 * @returns {Struct.EpicAchievementsDefinitionV2} 
 */
function eos_achievements_copy_achievement_definition_v2_by_index(_index)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _index, type: Int64
    if (!is_numeric(_index)) show_error($"{_GMFUNCTION_} :: _index expected number", true);
    buffer_write(__args_buffer, buffer_u64, _index);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_achievements_copy_achievement_definition_v2_by_index(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicAchievementsDefinitionV2_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _achievement_id
 * @returns {Struct.EpicAchievementsDefinition} 
 */
function eos_achievements_copy_achievement_definition_by_id(_achievement_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_achievements_copy_achievement_definition_by_id(_achievement_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicAchievementsDefinition_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @param {Real} _index
 * @returns {Struct.EpicPlayerAchievement} 
 */
function eos_achievements_copy_player_achievement_by_index(_local_user_id, _target_user_id, _index)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    // param: _index, type: Int64
    if (!is_numeric(_index)) show_error($"{_GMFUNCTION_} :: _index expected number", true);
    buffer_write(__args_buffer, buffer_u64, _index);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_achievements_copy_player_achievement_by_index(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicPlayerAchievement_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @param {String} _achievement_id
 * @returns {Struct.EpicPlayerAchievement} 
 */
function eos_achievements_copy_player_achievement_by_id(_local_user_id, _target_user_id, _achievement_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    // param: _achievement_id, type: String
    if (!is_string(_achievement_id)) show_error($"{_GMFUNCTION_} :: _achievement_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_achievement_id));
    buffer_write(__args_buffer, buffer_string, _achievement_id);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_achievements_copy_player_achievement_by_id(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicPlayerAchievement_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _user_id
 * @param {Array[String]} _achievement_ids
 * @param {Function} _callback
 */
function eos_achievements_unlock_achievements(_user_id, _achievement_ids, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _user_id, type: String
    if (!is_string(_user_id)) show_error($"{_GMFUNCTION_} :: _user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_user_id));
    buffer_write(__args_buffer, buffer_string, _user_id);

    // param: _achievement_ids, type: String[]
    if (!is_array(_achievement_ids)) show_error($"{_GMFUNCTION_} :: _achievement_ids expected array", true);
    var _length = array_length(_achievement_ids);
    buffer_write(__args_buffer, buffer_u32, _length);
    for (var _i = 0; _i < _length; ++_i)
    {
        if (!is_string(_achievement_ids[_i])) show_error($"{_GMFUNCTION_} :: _achievement_ids[_i] expected string", true);
        buffer_write(__args_buffer, buffer_u32, string_length(_achievement_ids[_i]));
        buffer_write(__args_buffer, buffer_string, _achievement_ids[_i]);
    }

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_achievements_unlock_achievements(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Real} 
 */
function eos_achievements_add_notify_achievements_unlocked_v2(_callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_achievements_add_notify_achievements_unlocked_v2(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _notification_id
 */
function eos_achievements_remove_notify_achievements_unlocked(_notification_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _notification_id, type: UInt64
    if (!is_numeric(_notification_id)) show_error($"{_GMFUNCTION_} :: _notification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _notification_id);

    var _return_value = __eos_achievements_remove_notify_achievements_unlocked(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {Real} _start_time
 * @param {Real} _end_time
 * @param {Function} _callback
 */
function eos_leaderboards_query_definitions(_local_user_id, _start_time, _end_time, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _start_time, type: Int64
    if (!is_numeric(_start_time)) show_error($"{_GMFUNCTION_} :: _start_time expected number", true);
    buffer_write(__args_buffer, buffer_u64, _start_time);

    // param: _end_time, type: Int64
    if (!is_numeric(_end_time)) show_error($"{_GMFUNCTION_} :: _end_time expected number", true);
    buffer_write(__args_buffer, buffer_u64, _end_time);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_leaderboards_query_definitions(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {String} _leaderboard_id
 * @param {Function} _callback
 */
function eos_leaderboards_query_ranks(_local_user_id, _leaderboard_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _leaderboard_id, type: String
    if (!is_string(_leaderboard_id)) show_error($"{_GMFUNCTION_} :: _leaderboard_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_leaderboard_id));
    buffer_write(__args_buffer, buffer_string, _leaderboard_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_leaderboards_query_ranks(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {String} _stat_name
 * @param {Function} _callback
 */
function eos_leaderboards_query_user_scores(_local_user_id, _stat_name, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _stat_name, type: String
    if (!is_string(_stat_name)) show_error($"{_GMFUNCTION_} :: _stat_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_stat_name));
    buffer_write(__args_buffer, buffer_string, _stat_name);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_leaderboards_query_user_scores(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @returns {Real} 
 */
function eos_leaderboards_get_definition_count()
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_leaderboards_get_definition_count(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @returns {Real} 
 */
function eos_leaderboards_get_record_count()
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_leaderboards_get_record_count(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @returns {Real} 
 */
function eos_leaderboards_get_user_score_count()
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_leaderboards_get_user_score_count(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _index
 * @returns {Struct.EpicLeaderboardDefinition} 
 */
function eos_leaderboards_copy_definition_by_index(_index)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _index, type: Int64
    if (!is_numeric(_index)) show_error($"{_GMFUNCTION_} :: _index expected number", true);
    buffer_write(__args_buffer, buffer_u64, _index);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_leaderboards_copy_definition_by_index(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicLeaderboardDefinition_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _leaderboard_id
 * @returns {Struct.EpicLeaderboardDefinition} 
 */
function eos_leaderboards_copy_definition_by_id(_leaderboard_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_leaderboards_copy_definition_by_id(_leaderboard_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicLeaderboardDefinition_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {Real} _index
 * @returns {Struct.EpicLeaderboardRecord} 
 */
function eos_leaderboards_copy_record_by_index(_index)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _index, type: Int64
    if (!is_numeric(_index)) show_error($"{_GMFUNCTION_} :: _index expected number", true);
    buffer_write(__args_buffer, buffer_u64, _index);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_leaderboards_copy_record_by_index(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicLeaderboardRecord_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _user_id
 * @returns {Struct.EpicLeaderboardRecord} 
 */
function eos_leaderboards_copy_record_by_user_id(_user_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_leaderboards_copy_record_by_user_id(_user_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicLeaderboardRecord_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {Real} _index
 * @returns {Struct.EpicLeaderboardUserScore} 
 */
function eos_leaderboards_copy_user_score_by_index(_index)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _index, type: Int64
    if (!is_numeric(_index)) show_error($"{_GMFUNCTION_} :: _index expected number", true);
    buffer_write(__args_buffer, buffer_u64, _index);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_leaderboards_copy_user_score_by_index(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicLeaderboardUserScore_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @param {Function} _callback
 */
function eos_presence_query_presence(_local_user_id, _target_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_presence_query_presence(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

// Skipping function eos_presence_has_presence (no wrapper is required)


/**
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @returns {Struct.EpicPresenceInfo} 
 */
function eos_presence_copy_presence(_local_user_id, _target_user_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_presence_copy_presence(_local_user_id, _target_user_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicPresenceInfo_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _local_user_id
 * @returns {Real} 
 */
function eos_presence_create_presence_modification(_local_user_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_presence_create_presence_modification(_local_user_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _modification_id
 */
function eos_presence_modification_release(_modification_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _modification_id, type: UInt64
    if (!is_numeric(_modification_id)) show_error($"{_GMFUNCTION_} :: _modification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _modification_id);

    var _return_value = __eos_presence_modification_release(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Real} _modification_id
 * @param {Enum.EpicPresenceStatus} _status
 * @returns {Enum.EpicResult} 
 */
function eos_presence_modification_set_status(_modification_id, _status)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _modification_id, type: UInt64
    if (!is_numeric(_modification_id)) show_error($"{_GMFUNCTION_} :: _modification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _modification_id);

    // param: _status, type: enum EpicPresenceStatus

    if (!is_numeric(_status)) show_error($"{_GMFUNCTION_} :: _status expected number", true);
    buffer_write(__args_buffer, buffer_u64, _status);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_presence_modification_set_status(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _modification_id
 * @param {String} _rich_text
 * @returns {Enum.EpicResult} 
 */
function eos_presence_modification_set_raw_rich_text(_modification_id, _rich_text)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _modification_id, type: UInt64
    if (!is_numeric(_modification_id)) show_error($"{_GMFUNCTION_} :: _modification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _modification_id);

    // param: _rich_text, type: String
    if (!is_string(_rich_text)) show_error($"{_GMFUNCTION_} :: _rich_text expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_rich_text));
    buffer_write(__args_buffer, buffer_string, _rich_text);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_presence_modification_set_raw_rich_text(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _modification_id
 * @param {String} _key
 * @param {String} _value
 * @returns {Enum.EpicResult} 
 */
function eos_presence_modification_set_data(_modification_id, _key, _value)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _modification_id, type: UInt64
    if (!is_numeric(_modification_id)) show_error($"{_GMFUNCTION_} :: _modification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _modification_id);

    // param: _key, type: String
    if (!is_string(_key)) show_error($"{_GMFUNCTION_} :: _key expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_key));
    buffer_write(__args_buffer, buffer_string, _key);

    // param: _value, type: String
    if (!is_string(_value)) show_error($"{_GMFUNCTION_} :: _value expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_value));
    buffer_write(__args_buffer, buffer_string, _value);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_presence_modification_set_data(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _modification_id
 * @param {String} _key
 * @returns {Enum.EpicResult} 
 */
function eos_presence_modification_delete_data(_modification_id, _key)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _modification_id, type: UInt64
    if (!is_numeric(_modification_id)) show_error($"{_GMFUNCTION_} :: _modification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _modification_id);

    // param: _key, type: String
    if (!is_string(_key)) show_error($"{_GMFUNCTION_} :: _key expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_key));
    buffer_write(__args_buffer, buffer_string, _key);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_presence_modification_delete_data(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {String} _local_user_id
 * @param {Real} _modification_id
 * @param {Function} _callback
 */
function eos_presence_set_presence(_local_user_id, _modification_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _modification_id, type: UInt64
    if (!is_numeric(_modification_id)) show_error($"{_GMFUNCTION_} :: _modification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _modification_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_presence_set_presence(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {Function} _callback
 * @returns {Real} 
 */
function eos_presence_add_notify_on_presence_changed(_local_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_presence_add_notify_on_presence_changed(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _notification_id
 */
function eos_presence_remove_notify_on_presence_changed(_notification_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _notification_id, type: UInt64
    if (!is_numeric(_notification_id)) show_error($"{_GMFUNCTION_} :: _notification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _notification_id);

    var _return_value = __eos_presence_remove_notify_on_presence_changed(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Real} 
 */
function eos_presence_add_notify_join_game_accepted(_callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_presence_add_notify_join_game_accepted(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _notification_id
 */
function eos_presence_remove_notify_join_game_accepted(_notification_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _notification_id, type: UInt64
    if (!is_numeric(_notification_id)) show_error($"{_GMFUNCTION_} :: _notification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _notification_id);

    var _return_value = __eos_presence_remove_notify_join_game_accepted(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _session_name
 * @param {String} _bucket_id
 * @param {Real} _max_players
 * @param {String} _local_user_id
 * @param {Enum.EpicOnlineSessionPermissionLevel} _permission_level
 * @param {Bool} _presence_enabled
 * @param {Bool} _invites_allowed
 * @returns {Real} 
 */
function eos_sessions_create_session_modification(_session_name, _bucket_id, _max_players, _local_user_id, _permission_level, _presence_enabled, _invites_allowed)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _session_name, type: String
    if (!is_string(_session_name)) show_error($"{_GMFUNCTION_} :: _session_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_session_name));
    buffer_write(__args_buffer, buffer_string, _session_name);

    // param: _bucket_id, type: String
    if (!is_string(_bucket_id)) show_error($"{_GMFUNCTION_} :: _bucket_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_bucket_id));
    buffer_write(__args_buffer, buffer_string, _bucket_id);

    // param: _max_players, type: Int64
    if (!is_numeric(_max_players)) show_error($"{_GMFUNCTION_} :: _max_players expected number", true);
    buffer_write(__args_buffer, buffer_u64, _max_players);

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _permission_level, type: enum EpicOnlineSessionPermissionLevel

    if (!is_numeric(_permission_level)) show_error($"{_GMFUNCTION_} :: _permission_level expected number", true);
    buffer_write(__args_buffer, buffer_u64, _permission_level);

    // param: _presence_enabled, type: Bool
    if (!is_bool(_presence_enabled)) show_error($"{_GMFUNCTION_} :: _presence_enabled expected bool", true);
    buffer_write(__args_buffer, buffer_bool, _presence_enabled);

    // param: _invites_allowed, type: Bool
    if (!is_bool(_invites_allowed)) show_error($"{_GMFUNCTION_} :: _invites_allowed expected bool", true);
    buffer_write(__args_buffer, buffer_bool, _invites_allowed);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_sessions_create_session_modification(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _modification_id
 */
function eos_sessions_session_modification_release(_modification_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _modification_id, type: UInt64
    if (!is_numeric(_modification_id)) show_error($"{_GMFUNCTION_} :: _modification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _modification_id);

    var _return_value = __eos_sessions_session_modification_release(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _session_name
 * @param {Real} _modification_id
 * @param {Function} _callback
 */
function eos_sessions_update_session(_session_name, _modification_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _session_name, type: String
    if (!is_string(_session_name)) show_error($"{_GMFUNCTION_} :: _session_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_session_name));
    buffer_write(__args_buffer, buffer_string, _session_name);

    // param: _modification_id, type: UInt64
    if (!is_numeric(_modification_id)) show_error($"{_GMFUNCTION_} :: _modification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _modification_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_sessions_update_session(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _session_name
 * @param {Function} _callback
 */
function eos_sessions_destroy_session(_session_name, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _session_name, type: String
    if (!is_string(_session_name)) show_error($"{_GMFUNCTION_} :: _session_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_session_name));
    buffer_write(__args_buffer, buffer_string, _session_name);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_sessions_destroy_session(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _session_name
 * @param {Function} _callback
 */
function eos_sessions_start_session(_session_name, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _session_name, type: String
    if (!is_string(_session_name)) show_error($"{_GMFUNCTION_} :: _session_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_session_name));
    buffer_write(__args_buffer, buffer_string, _session_name);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_sessions_start_session(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _session_name
 * @param {Function} _callback
 */
function eos_sessions_end_session(_session_name, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _session_name, type: String
    if (!is_string(_session_name)) show_error($"{_GMFUNCTION_} :: _session_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_session_name));
    buffer_write(__args_buffer, buffer_string, _session_name);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_sessions_end_session(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _session_name
 * @param {String} _local_user_id
 * @param {Function} _callback
 */
function eos_sessions_join_session(_session_name, _local_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _session_name, type: String
    if (!is_string(_session_name)) show_error($"{_GMFUNCTION_} :: _session_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_session_name));
    buffer_write(__args_buffer, buffer_string, _session_name);

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_sessions_join_session(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _session_name
 * @param {Array[String]} _target_user_ids
 * @param {Function} _callback
 */
function eos_sessions_register_players(_session_name, _target_user_ids, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _session_name, type: String
    if (!is_string(_session_name)) show_error($"{_GMFUNCTION_} :: _session_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_session_name));
    buffer_write(__args_buffer, buffer_string, _session_name);

    // param: _target_user_ids, type: String[]
    if (!is_array(_target_user_ids)) show_error($"{_GMFUNCTION_} :: _target_user_ids expected array", true);
    var _length = array_length(_target_user_ids);
    buffer_write(__args_buffer, buffer_u32, _length);
    for (var _i = 0; _i < _length; ++_i)
    {
        if (!is_string(_target_user_ids[_i])) show_error($"{_GMFUNCTION_} :: _target_user_ids[_i] expected string", true);
        buffer_write(__args_buffer, buffer_u32, string_length(_target_user_ids[_i]));
        buffer_write(__args_buffer, buffer_string, _target_user_ids[_i]);
    }

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_sessions_register_players(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _session_name
 * @param {Array[String]} _target_user_ids
 * @param {Function} _callback
 */
function eos_sessions_unregister_players(_session_name, _target_user_ids, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _session_name, type: String
    if (!is_string(_session_name)) show_error($"{_GMFUNCTION_} :: _session_name expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_session_name));
    buffer_write(__args_buffer, buffer_string, _session_name);

    // param: _target_user_ids, type: String[]
    if (!is_array(_target_user_ids)) show_error($"{_GMFUNCTION_} :: _target_user_ids expected array", true);
    var _length = array_length(_target_user_ids);
    buffer_write(__args_buffer, buffer_u32, _length);
    for (var _i = 0; _i < _length; ++_i)
    {
        if (!is_string(_target_user_ids[_i])) show_error($"{_GMFUNCTION_} :: _target_user_ids[_i] expected string", true);
        buffer_write(__args_buffer, buffer_u32, string_length(_target_user_ids[_i]));
        buffer_write(__args_buffer, buffer_string, _target_user_ids[_i]);
    }

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_sessions_unregister_players(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Real} _max_search_results
 * @returns {Real} 
 */
function eos_sessions_create_session_search(_max_search_results)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _max_search_results, type: Int64
    if (!is_numeric(_max_search_results)) show_error($"{_GMFUNCTION_} :: _max_search_results expected number", true);
    buffer_write(__args_buffer, buffer_u64, _max_search_results);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_sessions_create_session_search(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _search_id
 */
function eos_sessions_session_search_release(_search_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _search_id, type: UInt64
    if (!is_numeric(_search_id)) show_error($"{_GMFUNCTION_} :: _search_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _search_id);

    var _return_value = __eos_sessions_session_search_release(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Real} _search_id
 * @param {String} _session_id
 * @returns {Enum.EpicResult} 
 */
function eos_sessions_session_search_set_session_id(_search_id, _session_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _search_id, type: UInt64
    if (!is_numeric(_search_id)) show_error($"{_GMFUNCTION_} :: _search_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _search_id);

    // param: _session_id, type: String
    if (!is_string(_session_id)) show_error($"{_GMFUNCTION_} :: _session_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_session_id));
    buffer_write(__args_buffer, buffer_string, _session_id);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_sessions_session_search_set_session_id(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _search_id
 * @param {String} _target_user_id
 * @returns {Enum.EpicResult} 
 */
function eos_sessions_session_search_set_target_user_id(_search_id, _target_user_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _search_id, type: UInt64
    if (!is_numeric(_search_id)) show_error($"{_GMFUNCTION_} :: _search_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _search_id);

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_sessions_session_search_set_target_user_id(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _search_id
 * @param {String} _local_user_id
 * @param {Function} _callback
 */
function eos_sessions_session_search_find(_search_id, _local_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _search_id, type: UInt64
    if (!is_numeric(_search_id)) show_error($"{_GMFUNCTION_} :: _search_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _search_id);

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_sessions_session_search_find(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Real} _search_id
 * @param {Real} _index
 * @returns {Real} 
 */
function eos_sessions_session_search_copy_search_result_by_index(_search_id, _index)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _search_id, type: UInt64
    if (!is_numeric(_search_id)) show_error($"{_GMFUNCTION_} :: _search_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _search_id);

    // param: _index, type: Int64
    if (!is_numeric(_index)) show_error($"{_GMFUNCTION_} :: _index expected number", true);
    buffer_write(__args_buffer, buffer_u64, _index);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_sessions_session_search_copy_search_result_by_index(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _session_details_id
 */
function eos_sessions_session_details_release(_session_details_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _session_details_id, type: UInt64
    if (!is_numeric(_session_details_id)) show_error($"{_GMFUNCTION_} :: _session_details_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _session_details_id);

    var _return_value = __eos_sessions_session_details_release(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _session_name
 * @returns {Real} 
 */
function eos_sessions_copy_active_session_handle(_session_name)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_sessions_copy_active_session_handle(_session_name, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _active_session_id
 */
function eos_sessions_active_session_release(_active_session_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _active_session_id, type: UInt64
    if (!is_numeric(_active_session_id)) show_error($"{_GMFUNCTION_} :: _active_session_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _active_session_id);

    var _return_value = __eos_sessions_active_session_release(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Real} _active_session_id
 * @returns {Struct.EpicActiveSessionInfo} 
 */
function eos_sessions_active_session_copy_info(_active_session_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _active_session_id, type: UInt64
    if (!is_numeric(_active_session_id)) show_error($"{_GMFUNCTION_} :: _active_session_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _active_session_id);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_sessions_active_session_copy_info(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicActiveSessionInfo_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {String} _invite_id
 * @returns {Real} 
 */
function eos_sessions_copy_session_handle_by_invite_id(_invite_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_sessions_copy_session_handle_by_invite_id(_invite_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _ui_event_id
 * @returns {Real} 
 */
function eos_sessions_copy_session_handle_by_ui_event_id(_ui_event_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _ui_event_id, type: UInt64
    if (!is_numeric(_ui_event_id)) show_error($"{_GMFUNCTION_} :: _ui_event_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _ui_event_id);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_sessions_copy_session_handle_by_ui_event_id(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _session_details_id
 * @returns {Struct.EpicSessionDetailsInfo} 
 */
function eos_sessions_session_details_copy_info(_session_details_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _session_details_id, type: UInt64
    if (!is_numeric(_session_details_id)) show_error($"{_GMFUNCTION_} :: _session_details_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _session_details_id);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_sessions_session_details_copy_info(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicSessionDetailsInfo_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {Function} _callback
 * @returns {Real} 
 */
function eos_sessions_add_notify_session_invite_received(_callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_sessions_add_notify_session_invite_received(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _notification_id
 */
function eos_sessions_remove_notify_session_invite_received(_notification_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _notification_id, type: UInt64
    if (!is_numeric(_notification_id)) show_error($"{_GMFUNCTION_} :: _notification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _notification_id);

    var _return_value = __eos_sessions_remove_notify_session_invite_received(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Real} 
 */
function eos_sessions_add_notify_session_invite_accepted(_callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_sessions_add_notify_session_invite_accepted(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _notification_id
 */
function eos_sessions_remove_notify_session_invite_accepted(_notification_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _notification_id, type: UInt64
    if (!is_numeric(_notification_id)) show_error($"{_GMFUNCTION_} :: _notification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _notification_id);

    var _return_value = __eos_sessions_remove_notify_session_invite_accepted(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Real} 
 */
function eos_sessions_add_notify_join_session_accepted(_callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_sessions_add_notify_join_session_accepted(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _notification_id
 */
function eos_sessions_remove_notify_join_session_accepted(_notification_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _notification_id, type: UInt64
    if (!is_numeric(_notification_id)) show_error($"{_GMFUNCTION_} :: _notification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _notification_id);

    var _return_value = __eos_sessions_remove_notify_join_session_accepted(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {Real} _max_lobby_members
 * @param {Enum.EpicLobbyPermissionLevel} _permission_level
 * @param {Bool} _presence_enabled
 * @param {Bool} _allow_invites
 * @param {String} _bucket_id
 * @param {Function} _callback
 */
function eos_lobby_create_lobby(_local_user_id, _max_lobby_members, _permission_level, _presence_enabled, _allow_invites, _bucket_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _max_lobby_members, type: Int64
    if (!is_numeric(_max_lobby_members)) show_error($"{_GMFUNCTION_} :: _max_lobby_members expected number", true);
    buffer_write(__args_buffer, buffer_u64, _max_lobby_members);

    // param: _permission_level, type: enum EpicLobbyPermissionLevel

    if (!is_numeric(_permission_level)) show_error($"{_GMFUNCTION_} :: _permission_level expected number", true);
    buffer_write(__args_buffer, buffer_u64, _permission_level);

    // param: _presence_enabled, type: Bool
    if (!is_bool(_presence_enabled)) show_error($"{_GMFUNCTION_} :: _presence_enabled expected bool", true);
    buffer_write(__args_buffer, buffer_bool, _presence_enabled);

    // param: _allow_invites, type: Bool
    if (!is_bool(_allow_invites)) show_error($"{_GMFUNCTION_} :: _allow_invites expected bool", true);
    buffer_write(__args_buffer, buffer_bool, _allow_invites);

    // param: _bucket_id, type: String
    if (!is_string(_bucket_id)) show_error($"{_GMFUNCTION_} :: _bucket_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_bucket_id));
    buffer_write(__args_buffer, buffer_string, _bucket_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_lobby_create_lobby(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _lobby_id
 * @param {String} _local_user_id
 * @param {Function} _callback
 */
function eos_lobby_destroy_lobby(_lobby_id, _local_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _lobby_id, type: String
    if (!is_string(_lobby_id)) show_error($"{_GMFUNCTION_} :: _lobby_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_lobby_id));
    buffer_write(__args_buffer, buffer_string, _lobby_id);

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_lobby_destroy_lobby(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _lobby_id
 * @param {String} _local_user_id
 * @param {Bool} _presence_enabled
 * @param {Function} _callback
 */
function eos_lobby_join_lobby(_lobby_id, _local_user_id, _presence_enabled, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _lobby_id, type: String
    if (!is_string(_lobby_id)) show_error($"{_GMFUNCTION_} :: _lobby_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_lobby_id));
    buffer_write(__args_buffer, buffer_string, _lobby_id);

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _presence_enabled, type: Bool
    if (!is_bool(_presence_enabled)) show_error($"{_GMFUNCTION_} :: _presence_enabled expected bool", true);
    buffer_write(__args_buffer, buffer_bool, _presence_enabled);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_lobby_join_lobby(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _lobby_id
 * @param {String} _local_user_id
 * @param {Function} _callback
 */
function eos_lobby_leave_lobby(_lobby_id, _local_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _lobby_id, type: String
    if (!is_string(_lobby_id)) show_error($"{_GMFUNCTION_} :: _lobby_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_lobby_id));
    buffer_write(__args_buffer, buffer_string, _lobby_id);

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_lobby_leave_lobby(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _lobby_id
 * @param {String} _local_user_id
 * @returns {Real} 
 */
function eos_lobby_update_lobby_modification(_lobby_id, _local_user_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_update_lobby_modification(_lobby_id, _local_user_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _modification_id
 */
function eos_lobby_lobby_modification_release(_modification_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _modification_id, type: UInt64
    if (!is_numeric(_modification_id)) show_error($"{_GMFUNCTION_} :: _modification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _modification_id);

    var _return_value = __eos_lobby_lobby_modification_release(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _lobby_id
 * @param {Real} _modification_id
 * @param {Function} _callback
 */
function eos_lobby_update_lobby(_lobby_id, _modification_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _lobby_id, type: String
    if (!is_string(_lobby_id)) show_error($"{_GMFUNCTION_} :: _lobby_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_lobby_id));
    buffer_write(__args_buffer, buffer_string, _lobby_id);

    // param: _modification_id, type: UInt64
    if (!is_numeric(_modification_id)) show_error($"{_GMFUNCTION_} :: _modification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _modification_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_lobby_update_lobby(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Real} _modification_id
 * @param {Enum.EpicLobbyPermissionLevel} _permission_level
 * @returns {Enum.EpicResult} 
 */
function eos_lobby_lobby_modification_set_permission_level(_modification_id, _permission_level)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _modification_id, type: UInt64
    if (!is_numeric(_modification_id)) show_error($"{_GMFUNCTION_} :: _modification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _modification_id);

    // param: _permission_level, type: enum EpicLobbyPermissionLevel

    if (!is_numeric(_permission_level)) show_error($"{_GMFUNCTION_} :: _permission_level expected number", true);
    buffer_write(__args_buffer, buffer_u64, _permission_level);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_lobby_modification_set_permission_level(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _modification_id
 * @param {Real} _max_members
 * @returns {Enum.EpicResult} 
 */
function eos_lobby_lobby_modification_set_max_members(_modification_id, _max_members)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _modification_id, type: UInt64
    if (!is_numeric(_modification_id)) show_error($"{_GMFUNCTION_} :: _modification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _modification_id);

    // param: _max_members, type: Int64
    if (!is_numeric(_max_members)) show_error($"{_GMFUNCTION_} :: _max_members expected number", true);
    buffer_write(__args_buffer, buffer_u64, _max_members);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_lobby_modification_set_max_members(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _modification_id
 * @param {String} _bucket_id
 * @returns {Enum.EpicResult} 
 */
function eos_lobby_lobby_modification_set_bucket_id(_modification_id, _bucket_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _modification_id, type: UInt64
    if (!is_numeric(_modification_id)) show_error($"{_GMFUNCTION_} :: _modification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _modification_id);

    // param: _bucket_id, type: String
    if (!is_string(_bucket_id)) show_error($"{_GMFUNCTION_} :: _bucket_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_bucket_id));
    buffer_write(__args_buffer, buffer_string, _bucket_id);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_lobby_modification_set_bucket_id(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _modification_id
 * @param {Bool} _invites_allowed
 * @returns {Enum.EpicResult} 
 */
function eos_lobby_lobby_modification_set_invites_allowed(_modification_id, _invites_allowed)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _modification_id, type: UInt64
    if (!is_numeric(_modification_id)) show_error($"{_GMFUNCTION_} :: _modification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _modification_id);

    // param: _invites_allowed, type: Bool
    if (!is_bool(_invites_allowed)) show_error($"{_GMFUNCTION_} :: _invites_allowed expected bool", true);
    buffer_write(__args_buffer, buffer_bool, _invites_allowed);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_lobby_modification_set_invites_allowed(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _modification_id
 * @param {String} _key
 * @param {String} _value
 * @param {Enum.EpicLobbyAttributeVisibility} _visibility
 * @returns {Enum.EpicResult} 
 */
function eos_lobby_lobby_modification_add_attribute(_modification_id, _key, _value, _visibility)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _modification_id, type: UInt64
    if (!is_numeric(_modification_id)) show_error($"{_GMFUNCTION_} :: _modification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _modification_id);

    // param: _key, type: String
    if (!is_string(_key)) show_error($"{_GMFUNCTION_} :: _key expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_key));
    buffer_write(__args_buffer, buffer_string, _key);

    // param: _value, type: String
    if (!is_string(_value)) show_error($"{_GMFUNCTION_} :: _value expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_value));
    buffer_write(__args_buffer, buffer_string, _value);

    // param: _visibility, type: enum EpicLobbyAttributeVisibility

    if (!is_numeric(_visibility)) show_error($"{_GMFUNCTION_} :: _visibility expected number", true);
    buffer_write(__args_buffer, buffer_u64, _visibility);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_lobby_modification_add_attribute(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _modification_id
 * @param {String} _key
 * @returns {Enum.EpicResult} 
 */
function eos_lobby_lobby_modification_remove_attribute(_modification_id, _key)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _modification_id, type: UInt64
    if (!is_numeric(_modification_id)) show_error($"{_GMFUNCTION_} :: _modification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _modification_id);

    // param: _key, type: String
    if (!is_string(_key)) show_error($"{_GMFUNCTION_} :: _key expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_key));
    buffer_write(__args_buffer, buffer_string, _key);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_lobby_modification_remove_attribute(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _modification_id
 * @param {String} _key
 * @param {String} _value
 * @param {Enum.EpicLobbyAttributeVisibility} _visibility
 * @returns {Enum.EpicResult} 
 */
function eos_lobby_lobby_modification_add_member_attribute(_modification_id, _key, _value, _visibility)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _modification_id, type: UInt64
    if (!is_numeric(_modification_id)) show_error($"{_GMFUNCTION_} :: _modification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _modification_id);

    // param: _key, type: String
    if (!is_string(_key)) show_error($"{_GMFUNCTION_} :: _key expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_key));
    buffer_write(__args_buffer, buffer_string, _key);

    // param: _value, type: String
    if (!is_string(_value)) show_error($"{_GMFUNCTION_} :: _value expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_value));
    buffer_write(__args_buffer, buffer_string, _value);

    // param: _visibility, type: enum EpicLobbyAttributeVisibility

    if (!is_numeric(_visibility)) show_error($"{_GMFUNCTION_} :: _visibility expected number", true);
    buffer_write(__args_buffer, buffer_u64, _visibility);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_lobby_modification_add_member_attribute(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _modification_id
 * @param {String} _key
 * @returns {Enum.EpicResult} 
 */
function eos_lobby_lobby_modification_remove_member_attribute(_modification_id, _key)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _modification_id, type: UInt64
    if (!is_numeric(_modification_id)) show_error($"{_GMFUNCTION_} :: _modification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _modification_id);

    // param: _key, type: String
    if (!is_string(_key)) show_error($"{_GMFUNCTION_} :: _key expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_key));
    buffer_write(__args_buffer, buffer_string, _key);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_lobby_modification_remove_member_attribute(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {String} _lobby_id
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @param {Function} _callback
 */
function eos_lobby_promote_member(_lobby_id, _local_user_id, _target_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _lobby_id, type: String
    if (!is_string(_lobby_id)) show_error($"{_GMFUNCTION_} :: _lobby_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_lobby_id));
    buffer_write(__args_buffer, buffer_string, _lobby_id);

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_lobby_promote_member(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _lobby_id
 * @param {String} _local_user_id
 * @param {String} _target_user_id
 * @param {Function} _callback
 */
function eos_lobby_kick_member(_lobby_id, _local_user_id, _target_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _lobby_id, type: String
    if (!is_string(_lobby_id)) show_error($"{_GMFUNCTION_} :: _lobby_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_lobby_id));
    buffer_write(__args_buffer, buffer_string, _lobby_id);

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_lobby_kick_member(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Real} _max_results
 * @returns {Real} 
 */
function eos_lobby_create_lobby_search(_max_results)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _max_results, type: Int64
    if (!is_numeric(_max_results)) show_error($"{_GMFUNCTION_} :: _max_results expected number", true);
    buffer_write(__args_buffer, buffer_u64, _max_results);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_create_lobby_search(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _search_id
 */
function eos_lobby_lobby_search_release(_search_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _search_id, type: UInt64
    if (!is_numeric(_search_id)) show_error($"{_GMFUNCTION_} :: _search_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _search_id);

    var _return_value = __eos_lobby_lobby_search_release(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Real} _search_id
 * @param {String} _lobby_id
 * @returns {Enum.EpicResult} 
 */
function eos_lobby_lobby_search_set_lobby_id(_search_id, _lobby_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _search_id, type: UInt64
    if (!is_numeric(_search_id)) show_error($"{_GMFUNCTION_} :: _search_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _search_id);

    // param: _lobby_id, type: String
    if (!is_string(_lobby_id)) show_error($"{_GMFUNCTION_} :: _lobby_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_lobby_id));
    buffer_write(__args_buffer, buffer_string, _lobby_id);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_lobby_search_set_lobby_id(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _search_id
 * @param {String} _target_user_id
 * @returns {Enum.EpicResult} 
 */
function eos_lobby_lobby_search_set_target_user_id(_search_id, _target_user_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _search_id, type: UInt64
    if (!is_numeric(_search_id)) show_error($"{_GMFUNCTION_} :: _search_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _search_id);

    // param: _target_user_id, type: String
    if (!is_string(_target_user_id)) show_error($"{_GMFUNCTION_} :: _target_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_target_user_id));
    buffer_write(__args_buffer, buffer_string, _target_user_id);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_lobby_search_set_target_user_id(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _search_id
 * @param {String} _key
 * @param {String} _value
 * @param {Enum.EpicComparisonOp} _comparison_op
 * @returns {Enum.EpicResult} 
 */
function eos_lobby_lobby_search_set_parameter(_search_id, _key, _value, _comparison_op)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _search_id, type: UInt64
    if (!is_numeric(_search_id)) show_error($"{_GMFUNCTION_} :: _search_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _search_id);

    // param: _key, type: String
    if (!is_string(_key)) show_error($"{_GMFUNCTION_} :: _key expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_key));
    buffer_write(__args_buffer, buffer_string, _key);

    // param: _value, type: String
    if (!is_string(_value)) show_error($"{_GMFUNCTION_} :: _value expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_value));
    buffer_write(__args_buffer, buffer_string, _value);

    // param: _comparison_op, type: enum EpicComparisonOp

    if (!is_numeric(_comparison_op)) show_error($"{_GMFUNCTION_} :: _comparison_op expected number", true);
    buffer_write(__args_buffer, buffer_u64, _comparison_op);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_lobby_search_set_parameter(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _search_id
 * @param {String} _key
 * @param {Enum.EpicComparisonOp} _comparison_op
 * @returns {Enum.EpicResult} 
 */
function eos_lobby_lobby_search_remove_parameter(_search_id, _key, _comparison_op)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _search_id, type: UInt64
    if (!is_numeric(_search_id)) show_error($"{_GMFUNCTION_} :: _search_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _search_id);

    // param: _key, type: String
    if (!is_string(_key)) show_error($"{_GMFUNCTION_} :: _key expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_key));
    buffer_write(__args_buffer, buffer_string, _key);

    // param: _comparison_op, type: enum EpicComparisonOp

    if (!is_numeric(_comparison_op)) show_error($"{_GMFUNCTION_} :: _comparison_op expected number", true);
    buffer_write(__args_buffer, buffer_u64, _comparison_op);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_lobby_search_remove_parameter(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _search_id
 * @param {Real} _max_results
 * @returns {Enum.EpicResult} 
 */
function eos_lobby_lobby_search_set_max_results(_search_id, _max_results)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _search_id, type: UInt64
    if (!is_numeric(_search_id)) show_error($"{_GMFUNCTION_} :: _search_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _search_id);

    // param: _max_results, type: Int64
    if (!is_numeric(_max_results)) show_error($"{_GMFUNCTION_} :: _max_results expected number", true);
    buffer_write(__args_buffer, buffer_u64, _max_results);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_lobby_search_set_max_results(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _search_id
 * @param {String} _local_user_id
 * @param {Function} _callback
 */
function eos_lobby_lobby_search_find(_search_id, _local_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _search_id, type: UInt64
    if (!is_numeric(_search_id)) show_error($"{_GMFUNCTION_} :: _search_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _search_id);

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __eos_lobby_lobby_search_find(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Real} _search_id
 * @returns {Real} 
 */
function eos_lobby_lobby_search_get_search_result_count(_search_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _search_id, type: UInt64
    if (!is_numeric(_search_id)) show_error($"{_GMFUNCTION_} :: _search_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _search_id);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_lobby_search_get_search_result_count(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _search_id
 * @param {Real} _index
 * @returns {Real} 
 */
function eos_lobby_lobby_search_copy_search_result_by_index(_search_id, _index)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _search_id, type: UInt64
    if (!is_numeric(_search_id)) show_error($"{_GMFUNCTION_} :: _search_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _search_id);

    // param: _index, type: Int64
    if (!is_numeric(_index)) show_error($"{_GMFUNCTION_} :: _index expected number", true);
    buffer_write(__args_buffer, buffer_u64, _index);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_lobby_search_copy_search_result_by_index(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _lobby_details_id
 */
function eos_lobby_details_release(_lobby_details_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _lobby_details_id, type: UInt64
    if (!is_numeric(_lobby_details_id)) show_error($"{_GMFUNCTION_} :: _lobby_details_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _lobby_details_id);

    var _return_value = __eos_lobby_details_release(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _lobby_id
 * @param {String} _local_user_id
 * @returns {Real} 
 */
function eos_lobby_copy_lobby_details_handle(_lobby_id, _local_user_id)
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_copy_lobby_details_handle(_lobby_id, _local_user_id, buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _lobby_details_id
 * @returns {Struct.EpicLobbyDetailsInfo} 
 */
function eos_lobby_details_copy_info(_lobby_details_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _lobby_details_id, type: UInt64
    if (!is_numeric(_lobby_details_id)) show_error($"{_GMFUNCTION_} :: _lobby_details_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _lobby_details_id);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_details_copy_info(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = __EpicLobbyDetailsInfo_decode(__ret_buffer, buffer_tell(__ret_buffer));
    return _result;
}

/**
 * @param {Real} _lobby_details_id
 * @returns {Real} 
 */
function eos_lobby_details_get_member_count(_lobby_details_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _lobby_details_id, type: UInt64
    if (!is_numeric(_lobby_details_id)) show_error($"{_GMFUNCTION_} :: _lobby_details_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _lobby_details_id);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_details_get_member_count(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _lobby_details_id
 * @param {Real} _index
 * @returns {String} 
 */
function eos_lobby_details_get_member_by_index(_lobby_details_id, _index)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _lobby_details_id, type: UInt64
    if (!is_numeric(_lobby_details_id)) show_error($"{_GMFUNCTION_} :: _lobby_details_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _lobby_details_id);

    // param: _index, type: Int64
    if (!is_numeric(_index)) show_error($"{_GMFUNCTION_} :: _index expected number", true);
    buffer_write(__args_buffer, buffer_u64, _index);

    var _return_value = __eos_lobby_details_get_member_by_index(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Real} _lobby_details_id
 * @returns {String} 
 */
function eos_lobby_details_get_lobby_owner(_lobby_details_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _lobby_details_id, type: UInt64
    if (!is_numeric(_lobby_details_id)) show_error($"{_GMFUNCTION_} :: _lobby_details_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _lobby_details_id);

    var _return_value = __eos_lobby_details_get_lobby_owner(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {Function} _callback
 * @returns {Real} 
 */
function eos_lobby_add_notify_lobby_update_received(_local_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_add_notify_lobby_update_received(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _notification_id
 */
function eos_lobby_remove_notify_lobby_update_received(_notification_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _notification_id, type: UInt64
    if (!is_numeric(_notification_id)) show_error($"{_GMFUNCTION_} :: _notification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _notification_id);

    var _return_value = __eos_lobby_remove_notify_lobby_update_received(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {Function} _callback
 * @returns {Real} 
 */
function eos_lobby_add_notify_lobby_member_update_received(_local_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_add_notify_lobby_member_update_received(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _notification_id
 */
function eos_lobby_remove_notify_lobby_member_update_received(_notification_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _notification_id, type: UInt64
    if (!is_numeric(_notification_id)) show_error($"{_GMFUNCTION_} :: _notification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _notification_id);

    var _return_value = __eos_lobby_remove_notify_lobby_member_update_received(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {Function} _callback
 * @returns {Real} 
 */
function eos_lobby_add_notify_lobby_member_status_received(_local_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_add_notify_lobby_member_status_received(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _notification_id
 */
function eos_lobby_remove_notify_lobby_member_status_received(_notification_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _notification_id, type: UInt64
    if (!is_numeric(_notification_id)) show_error($"{_GMFUNCTION_} :: _notification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _notification_id);

    var _return_value = __eos_lobby_remove_notify_lobby_member_status_received(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {Function} _callback
 * @returns {Real} 
 */
function eos_lobby_add_notify_join_lobby_accepted(_callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_add_notify_join_lobby_accepted(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _notification_id
 */
function eos_lobby_remove_notify_join_lobby_accepted(_notification_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _notification_id, type: UInt64
    if (!is_numeric(_notification_id)) show_error($"{_GMFUNCTION_} :: _notification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _notification_id);

    var _return_value = __eos_lobby_remove_notify_join_lobby_accepted(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {Function} _callback
 * @returns {Real} 
 */
function eos_lobby_add_notify_leave_lobby_requested(_local_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_add_notify_leave_lobby_requested(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _notification_id
 */
function eos_lobby_remove_notify_leave_lobby_requested(_notification_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _notification_id, type: UInt64
    if (!is_numeric(_notification_id)) show_error($"{_GMFUNCTION_} :: _notification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _notification_id);

    var _return_value = __eos_lobby_remove_notify_leave_lobby_requested(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @param {String} _local_user_id
 * @param {Function} _callback
 * @returns {Real} 
 */
function eos_lobby_add_notify_send_lobby_native_invite_requested(_local_user_id, _callback)
{
    static __dispatcher = __EpicOnlineServices_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _local_user_id, type: String
    if (!is_string(_local_user_id)) show_error($"{_GMFUNCTION_} :: _local_user_id expected string", true);
    buffer_write(__args_buffer, buffer_u32, string_length(_local_user_id));
    buffer_write(__args_buffer, buffer_string, _local_user_id);

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __eos_lobby_add_notify_send_lobby_native_invite_requested(buffer_get_address(__args_buffer), buffer_tell(__args_buffer), buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u64);
    return _result;
}

/**
 * @param {Real} _notification_id
 */
function eos_lobby_remove_notify_send_lobby_native_invite_requested(_notification_id)
{
    var __args_buffer = __ext_core_get_args_buffer();

    // param: _notification_id, type: UInt64
    if (!is_numeric(_notification_id)) show_error($"{_GMFUNCTION_} :: _notification_id expected number", true);
    buffer_write(__args_buffer, buffer_u64, _notification_id);

    var _return_value = __eos_lobby_remove_notify_send_lobby_native_invite_requested(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/// @ignore
function __EpicOnlineServices_get_decoders()
{
    static __decoders = [
        __EpicLoggingMessage_decode,
        __EpicAuthLoginCallbackInfo_decode,
        __EpicAuthLogoutCallbackInfo_decode,
        __EpicAuthLinkAccountCallbackInfo_decode,
        __EpicAuthDeletePersistentAuthCallbackInfo_decode,
        __EpicAuthIdToken_decode,
        __EpicAuthUserAuthToken_decode,
        __EpicAuthQueryIdTokenCallbackInfo_decode,
        __EpicAuthVerifyIdTokenCallbackInfo_decode,
        __EpicAuthVerifyUserAuthCallbackInfo_decode,
        __EpicAuthLoginStatusChangedCallbackInfo_decode,
        __EpicConnectLoginCallbackInfo_decode,
        __EpicConnectCreateUserCallbackInfo_decode,
        __EpicConnectLinkAccountCallbackInfo_decode,
        __EpicConnectUnlinkAccountCallbackInfo_decode,
        __EpicConnectCreateDeviceIdCallbackInfo_decode,
        __EpicConnectDeleteDeviceIdCallbackInfo_decode,
        __EpicConnectTransferDeviceIdAccountCallbackInfo_decode,
        __EpicConnectLogoutCallbackInfo_decode,
        __EpicConnectIdToken_decode,
        __EpicConnectExternalAccountInfo_decode,
        __EpicConnectVerifyIdTokenCallbackInfo_decode,
        __EpicConnectQueryExternalAccountMappingsCallbackInfo_decode,
        __EpicConnectQueryProductUserIdMappingsCallbackInfo_decode,
        __EpicConnectAuthExpirationCallbackInfo_decode,
        __EpicConnectLoginStatusChangedCallbackInfo_decode,
        __EpicFriendsQueryFriendsCallbackInfo_decode,
        __EpicFriendsFriendsUpdateCallbackInfo_decode,
        __EpicUserInfo_decode,
        __EpicUserInfoQueryUserInfoCallbackInfo_decode,
        __EpicUserInfoExternalUserInfo_decode,
        __EpicStatsStat_decode,
        __EpicStatsIngestStatCallbackInfo_decode,
        __EpicStatsQueryStatsCallbackInfo_decode,
        __EpicUIShowFriendsCallbackInfo_decode,
        __EpicUIShowNativeProfileCallbackInfo_decode,
        __EpicUIDisplaySettingsUpdatedCallbackInfo_decode,
        __EpicReportsSendPlayerBehaviorReportCallbackInfo_decode,
        __EpicSanctionsPlayerSanction_decode,
        __EpicSanctionsQueryActivePlayerSanctionsCallbackInfo_decode,
        __EpicSanctionsCreatePlayerSanctionAppealCallbackInfo_decode,
        __EpicAchievementsQueryDefinitionsCallbackInfo_decode,
        __EpicAchievementsQueryPlayerAchievementsCallbackInfo_decode,
        __EpicAchievementsDefinition_decode,
        __EpicPlayerAchievement_decode,
        __EpicAchievementsUnlockAchievementsCallbackInfo_decode,
        __EpicAchievementsDefinitionV2_decode,
        __EpicAchievementsUnlockedV2CallbackInfo_decode,
        __EpicLeaderboardsQueryDefinitionsCallbackInfo_decode,
        __EpicLeaderboardsQueryRanksCallbackInfo_decode,
        __EpicLeaderboardsQueryUserScoresCallbackInfo_decode,
        __EpicLeaderboardDefinition_decode,
        __EpicLeaderboardRecord_decode,
        __EpicLeaderboardUserScore_decode,
        __EpicPresenceInfo_decode,
        __EpicPresenceQueryPresenceCallbackInfo_decode,
        __EpicPresenceSetPresenceCallbackInfo_decode,
        __EpicPresenceChangedCallbackInfo_decode,
        __EpicPresenceJoinGameAcceptedCallbackInfo_decode,
        __EpicSessionsUpdateSessionCallbackInfo_decode,
        __EpicSessionsDestroySessionCallbackInfo_decode,
        __EpicSessionsStartSessionCallbackInfo_decode,
        __EpicSessionsEndSessionCallbackInfo_decode,
        __EpicSessionsJoinSessionCallbackInfo_decode,
        __EpicSessionsRegisterPlayersCallbackInfo_decode,
        __EpicSessionsUnregisterPlayersCallbackInfo_decode,
        __EpicSessionsFindCallbackInfo_decode,
        __EpicSessionDetailsInfo_decode,
        __EpicActiveSessionInfo_decode,
        __EpicSessionsSessionInviteReceivedCallbackInfo_decode,
        __EpicSessionsSessionInviteAcceptedCallbackInfo_decode,
        __EpicSessionsJoinSessionAcceptedCallbackInfo_decode,
        __EpicLobbyCreateLobbyCallbackInfo_decode,
        __EpicLobbyDestroyLobbyCallbackInfo_decode,
        __EpicLobbyJoinLobbyCallbackInfo_decode,
        __EpicLobbyLeaveLobbyCallbackInfo_decode,
        __EpicLobbyUpdateLobbyCallbackInfo_decode,
        __EpicLobbyPromoteMemberCallbackInfo_decode,
        __EpicLobbyKickMemberCallbackInfo_decode,
        __EpicLobbySearchFindCallbackInfo_decode,
        __EpicLobbyDetailsInfo_decode,
        __EpicLobbyLobbyUpdateReceivedCallbackInfo_decode,
        __EpicLobbyLobbyMemberUpdateReceivedCallbackInfo_decode,
        __EpicLobbyLobbyMemberStatusReceivedCallbackInfo_decode,
        __EpicLobbyJoinLobbyAcceptedCallbackInfo_decode,
        __EpicLobbyLeaveLobbyRequestedCallbackInfo_decode,
        __EpicLobbySendLobbyNativeInviteRequestedCallbackInfo_decode
    ];
    return __decoders;
}
/// @ignore
function __EpicOnlineServices_get_dispatcher()
{
    static __dispatcher = new __GMNativeFunctionDispatcher(__EpicOnlineServices_invocation_handler, __EpicOnlineServices_get_decoders());
    return __dispatcher;
}
