// ##### extgen :: Auto-generated file do not edit!! #####

#pragma once
#include <cstdint>
#include <string_view>
#include <vector>
#include <array>
#include <optional>
#include "core/GMExtWire.h"

namespace gm_consts
{
}


namespace gm_enums
{
    enum class EpicResult : std::int64_t
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
    };

    enum class EpicAntiCheatClientMode : std::int64_t
    {
        Invalid = 0,
        ClientServer = 1,
        PeerToPeer = 2
    };

    enum class EpicAntiCheatClientViolationType : std::int64_t
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
    };

    enum class EpicAntiCheatCommonClientType : std::int64_t
    {
        ProtectedClient = 0,
        UnprotectedClient = 1,
        AIBot = 2
    };

    enum class EpicAntiCheatCommonClientPlatform : std::int64_t
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
    };

    enum class EpicAntiCheatCommonClientAction : std::int64_t
    {
        Invalid = 0,
        RemovePlayer = 1
    };

    enum class EpicAntiCheatCommonClientActionReason : std::int64_t
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
    };

    enum class EpicAntiCheatCommonClientAuthStatus : std::int64_t
    {
        Invalid = 0,
        LocalAuthComplete = 1,
        RemoteAuthComplete = 2
    };

    enum class EpicAntiCheatCommonClientFlags : std::int64_t
    {
        None = 0
    };

    enum class EpicAntiCheatCommonClientInput : std::int64_t
    {
        Unknown = 0,
        MouseKeyboard = 1,
        Gamepad = 2,
        TouchInput = 3
    };

    enum class EpicAntiCheatCommonEventType : std::int64_t
    {
        Invalid = 0,
        GameEvent = 1,
        PlayerEvent = 2
    };

    enum class EpicAntiCheatCommonEventParamType : std::int64_t
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
    };

    enum class EpicAntiCheatCommonGameRoundCompetitionType : std::int64_t
    {
        None = 0,
        Casual = 1,
        Ranked = 2,
        Competitive = 3
    };

    enum class EpicAntiCheatCommonPlayerMovementState : std::int64_t
    {
        None = 0,
        Crouching = 1,
        Prone = 2,
        Mounted = 3,
        Swimming = 4,
        Falling = 5,
        Flying = 6,
        OnLadder = 7
    };

    enum class EpicAntiCheatCommonPlayerTakeDamageSource : std::int64_t
    {
        None = 0,
        Player = 1,
        NonPlayerCharacter = 2,
        World = 3
    };

    enum class EpicAntiCheatCommonPlayerTakeDamageType : std::int64_t
    {
        None = 0,
        PointDamage = 1,
        RadialDamage = 2,
        DamageOverTime = 3
    };

    enum class EpicAntiCheatCommonPlayerTakeDamageResult : std::int64_t
    {
        None = 0,
        DownedDeprecated = 1,
        EliminatedDeprecated = 2,
        NormalToDowned = 3,
        NormalToEliminated = 4,
        DownedToEliminated = 5
    };

    enum class EpicLoginCredentialType : std::int64_t
    {
        Password = 0,
        ExchangeCode = 1,
        PersistentAuth = 2,
        DeviceCode = 3,
        Developer = 4,
        RefreshToken = 5,
        AccountPortal = 6,
        ExternalAuth = 7
    };

    enum class EpicAuthTokenType : std::int64_t
    {
        Client = 0,
        User = 1
    };

    enum class EpicAuthScopeFlags : std::int64_t
    {
        NoFlags = 0,
        BasicProfile = 1,
        FriendsList = 2,
        Presence = 4,
        FriendsManagement = 8,
        Email = 16,
        Country = 32
    };

    enum class EpicLinkAccountFlags : std::int64_t
    {
        NoFlags = 0,
        NintendoNsaId = 1
    };

    enum class Epicname : std::int64_t
    {
    };

    enum class EpicLoginStatus : std::int64_t
    {
        NotLoggedIn = 0,
        UsingLocalProfile = 1,
        LoggedIn = 2
    };

    enum class EpicAttributeType : std::int64_t
    {
        Boolean = 0,
        Int64 = 1,
        Double = 2,
        String = 3
    };

    enum class EpicComparisonOp : std::int64_t
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
    };

    enum class EpicExternalAccountType : std::int64_t
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
    };

    enum class EpicExternalCredentialType : std::int64_t
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
    };

    enum class EpicRequestToJoinResponse : std::int64_t
    {
        Accepted = 0,
        Rejected = 1
    };

    enum class EpicOwnershipStatus : std::int64_t
    {
        NotOwned = 0,
        Owned = 1
    };

    enum class EpicEcomItemType : std::int64_t
    {
        Durable = 0,
        Consumable = 1,
        Other = 2
    };

    enum class EpicCheckoutOrientation : std::int64_t
    {
        Default = 0,
        Portrait = 1,
        Landscape = 2
    };

    enum class EpicFriendsStatus : std::int64_t
    {
        NotFriends = 0,
        InviteSent = 1,
        InviteReceived = 2,
        Friends = 3
    };

    enum class EpicIntegratedPlatformManagementFlags : std::int64_t
    {
        Disabled = 1,
        LibraryManagedByApplication = 2,
        LibraryManagedBySDK = 4,
        DisablePresenceMirroring = 8,
        DisableSDKManagedSessions = 16,
        PreferEOSIdentity = 32,
        PreferIntegratedIdentity = 64,
        ApplicationManagedIdentityLogin = 128
    };

    enum class EpicIntegratedPlatformPreLogoutAction : std::int64_t
    {
        ProcessLogoutImmediately = 0,
        DeferLogout = 1
    };

    enum class EpicKWSPermissionStatus : std::int64_t
    {
        Granted = 0,
        Rejected = 1,
        Pending = 2
    };

    enum class EpicLeaderboardAggregation : std::int64_t
    {
        Min = 0,
        Max = 1,
        Sum = 2,
        Latest = 3
    };

    enum class EpicLobbyPermissionLevel : std::int64_t
    {
        PublicAdvertised = 0,
        JoinViaPresence = 1,
        InviteOnly = 2
    };

    enum class EpicLobbyAttributeVisibility : std::int64_t
    {
        Public = 0,
        Private = 1
    };

    enum class EpicLobbyMemberStatus : std::int64_t
    {
        Joined = 0,
        Left = 1,
        Disconnected = 2,
        Kicked = 3,
        Promoted = 4,
        Closed = 5
    };

    enum class EpicLobbyRTCRoomJoinActionType : std::int64_t
    {
        AutomaticJoin = 0,
        ManualJoin = 1
    };

    enum class EpicLogLevel : std::int64_t
    {
        Off = 0,
        Fatal = 100,
        Error = 200,
        Warning = 300,
        Info = 400,
        Verbose = 500,
        VeryVerbose = 600
    };

    enum class EpicLogCategory : std::int64_t
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
    };

    enum class EpicUserControllerType : std::int64_t
    {
        Unknown = 0,
        MouseKeyboard = 1,
        GamepadControl = 2,
        TouchControl = 3
    };

    enum class EpicMetricsAccountIdType : std::int64_t
    {
        Epic = 0,
        External = 1
    };

    enum class EpicModEnumerationType : std::int64_t
    {
        Installed = 0,
        AllAvailable = 1
    };

    enum class EpicNATType : std::int64_t
    {
        Unknown = 0,
        Open = 1,
        Moderate = 2,
        Strict = 3
    };

    enum class EpicPacketReliability : std::int64_t
    {
        UnreliableUnordered = 0,
        ReliableUnordered = 1,
        ReliableOrdered = 2
    };

    enum class EpicConnectionEstablishedType : std::int64_t
    {
        NewConnection = 0,
        Reconnection = 1
    };

    enum class EpicNetworkConnectionType : std::int64_t
    {
        NoConnection = 0,
        DirectConnection = 1,
        RelayedConnection = 2
    };

    enum class EpicConnectionClosedReason : std::int64_t
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
    };

    enum class EpicRelayControl : std::int64_t
    {
        NoRelays = 0,
        AllowRelays = 1,
        ForceRelays = 2
    };

    enum class EpicPlayerDataStorageReadResult : std::int64_t
    {
        ContinueReading = 1,
        FailRequest = 2,
        CancelRequest = 3
    };

    enum class EpicPlayerDataStorageWriteResult : std::int64_t
    {
        ContinueWriting = 1,
        CompleteRequest = 2,
        FailRequest = 3,
        CancelRequest = 4
    };

    enum class EpicPresenceStatus : std::int64_t
    {
        Offline = 0,
        Online = 1,
        Away = 2,
        ExtendedAway = 3,
        DoNotDisturb = 4
    };

    enum class EpicPlayerReportsCategory : std::int64_t
    {
        Invalid = 0,
        Cheating = 1,
        Exploiting = 2,
        OffensiveProfile = 3,
        VerbalAbuse = 4,
        Scamming = 5,
        Spamming = 6,
        Other = 7
    };

    enum class EpicRTCAudioStatus : std::int64_t
    {
        Unsupported = 0,
        Enabled = 1,
        Disabled = 2,
        AdminDisabled = 3,
        NotListeningDisabled = 4
    };

    enum class EpicRTCAudioInputStatus : std::int64_t
    {
        Idle = 0,
        Recording = 1,
        RecordingSilent = 2,
        RecordingDisconnected = 3,
        Failed = 4
    };

    enum class EpicRTCAudioOutputStatus : std::int64_t
    {
        Idle = 0,
        Playing = 1,
        Failed = 2
    };

    enum class EpicRTCDataStatus : std::int64_t
    {
        Unsupported = 0,
        Enabled = 1,
        Disabled = 2
    };

    enum class EpicRTCParticipantStatus : std::int64_t
    {
        Joined = 0,
        Left = 1
    };

    enum class EpicSanctionAppealReason : std::int64_t
    {
        Invalid = 0,
        IncorrectSanction = 1,
        CompromisedAccount = 2,
        UnfairPunishment = 3,
        AppealForForgiveness = 4
    };

    enum class EpicOnlineSessionState : std::int64_t
    {
        NoSession = 0,
        Creating = 1,
        Pending = 2,
        Starting = 3,
        InProgress = 4,
        Ending = 5,
        Ended = 6,
        Destroying = 7
    };

    enum class EpicSessionAttributeAdvertisementType : std::int64_t
    {
        DontAdvertise = 0,
        Advertise = 1
    };

    enum class EpicOnlineSessionPermissionLevel : std::int64_t
    {
        PublicAdvertised = 0,
        JoinViaPresence = 1,
        InviteOnly = 2
    };

    enum class EpicTitleStorageReadResult : std::int64_t
    {
        ContinueReading = 1,
        FailRequest = 2,
        CancelRequest = 3
    };

    enum class EpicRTCBackgroundMode : std::int64_t
    {
        LeaveRooms = 0,
        KeepRoomsAlive = 1
    };

    enum class EpicApplicationStatus : std::int64_t
    {
        BackgroundConstrained = 0,
        BackgroundUnconstrained = 1,
        BackgroundSuspended = 2,
        Foreground = 3
    };

    enum class EpicNetworkStatus : std::int64_t
    {
        Disabled = 0,
        Offline = 1,
        Online = 2
    };

    enum class EpicDesktopCrossplayStatus : std::int64_t
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
    };

    enum class EpicUINotificationLocation : std::int64_t
    {
        TopLeft = 0,
        TopRight = 1,
        BottomLeft = 2,
        BottomRight = 3
    };

}


namespace gm_structs
{
    struct EpicLoggingMessage;
    struct EpicAuthLoginCallbackInfo;
    struct EpicAuthLogoutCallbackInfo;
    struct EpicAuthLinkAccountCallbackInfo;
    struct EpicAuthDeletePersistentAuthCallbackInfo;
    struct EpicAuthIdToken;
    struct EpicAuthUserAuthToken;
    struct EpicAuthQueryIdTokenCallbackInfo;
    struct EpicAuthVerifyIdTokenCallbackInfo;
    struct EpicAuthVerifyUserAuthCallbackInfo;
    struct EpicAuthLoginStatusChangedCallbackInfo;
    struct EpicConnectLoginCallbackInfo;
    struct EpicConnectCreateUserCallbackInfo;
    struct EpicConnectLinkAccountCallbackInfo;
    struct EpicConnectUnlinkAccountCallbackInfo;
    struct EpicConnectCreateDeviceIdCallbackInfo;
    struct EpicConnectDeleteDeviceIdCallbackInfo;
    struct EpicConnectTransferDeviceIdAccountCallbackInfo;
    struct EpicConnectLogoutCallbackInfo;
    struct EpicConnectIdToken;
    struct EpicConnectExternalAccountInfo;
    struct EpicConnectVerifyIdTokenCallbackInfo;
    struct EpicConnectQueryExternalAccountMappingsCallbackInfo;
    struct EpicConnectQueryProductUserIdMappingsCallbackInfo;
    struct EpicConnectAuthExpirationCallbackInfo;
    struct EpicConnectLoginStatusChangedCallbackInfo;
    struct EpicFriendsQueryFriendsCallbackInfo;
    struct EpicFriendsFriendsUpdateCallbackInfo;
    struct EpicUserInfo;
    struct EpicUserInfoQueryUserInfoCallbackInfo;
    struct EpicUserInfoExternalUserInfo;
    struct EpicStatsStat;
    struct EpicStatsIngestStatCallbackInfo;
    struct EpicStatsQueryStatsCallbackInfo;
    struct EpicUIShowFriendsCallbackInfo;
    struct EpicUIShowNativeProfileCallbackInfo;
    struct EpicUIDisplaySettingsUpdatedCallbackInfo;
    struct EpicReportsSendPlayerBehaviorReportCallbackInfo;
    struct EpicSanctionsPlayerSanction;
    struct EpicSanctionsQueryActivePlayerSanctionsCallbackInfo;
    struct EpicSanctionsCreatePlayerSanctionAppealCallbackInfo;
    struct EpicAchievementsQueryDefinitionsCallbackInfo;
    struct EpicAchievementsQueryPlayerAchievementsCallbackInfo;
    struct EpicAchievementsDefinition;
    struct EpicPlayerAchievement;
    struct EpicAchievementsUnlockAchievementsCallbackInfo;
    struct EpicAchievementsDefinitionV2;
    struct EpicAchievementsUnlockedV2CallbackInfo;
    struct EpicLeaderboardsQueryDefinitionsCallbackInfo;
    struct EpicLeaderboardsQueryRanksCallbackInfo;
    struct EpicLeaderboardsQueryUserScoresCallbackInfo;
    struct EpicLeaderboardDefinition;
    struct EpicLeaderboardRecord;
    struct EpicLeaderboardUserScore;
    struct EpicPresenceInfo;
    struct EpicPresenceQueryPresenceCallbackInfo;
    struct EpicPresenceSetPresenceCallbackInfo;
    struct EpicPresenceChangedCallbackInfo;
    struct EpicPresenceJoinGameAcceptedCallbackInfo;
    struct EpicSessionsUpdateSessionCallbackInfo;
    struct EpicSessionsDestroySessionCallbackInfo;
    struct EpicSessionsStartSessionCallbackInfo;
    struct EpicSessionsEndSessionCallbackInfo;
    struct EpicSessionsJoinSessionCallbackInfo;
    struct EpicSessionsRegisterPlayersCallbackInfo;
    struct EpicSessionsUnregisterPlayersCallbackInfo;
    struct EpicSessionsFindCallbackInfo;
    struct EpicSessionDetailsInfo;
    struct EpicActiveSessionInfo;
    struct EpicSessionsSessionInviteReceivedCallbackInfo;
    struct EpicSessionsSessionInviteAcceptedCallbackInfo;
    struct EpicSessionsJoinSessionAcceptedCallbackInfo;
    struct EpicLobbyCreateLobbyCallbackInfo;
    struct EpicLobbyDestroyLobbyCallbackInfo;
    struct EpicLobbyJoinLobbyCallbackInfo;
    struct EpicLobbyLeaveLobbyCallbackInfo;
    struct EpicLobbyUpdateLobbyCallbackInfo;
    struct EpicLobbyPromoteMemberCallbackInfo;
    struct EpicLobbyKickMemberCallbackInfo;
    struct EpicLobbySearchFindCallbackInfo;
    struct EpicLobbyDetailsInfo;
    struct EpicLobbyLobbyUpdateReceivedCallbackInfo;
    struct EpicLobbyLobbyMemberUpdateReceivedCallbackInfo;
    struct EpicLobbyLobbyMemberStatusReceivedCallbackInfo;
    struct EpicLobbyJoinLobbyAcceptedCallbackInfo;
    struct EpicLobbyLeaveLobbyRequestedCallbackInfo;
    struct EpicLobbySendLobbyNativeInviteRequestedCallbackInfo;

    struct EpicLoggingMessage
    {
        gm_enums::EpicLogCategory category;
        gm_enums::EpicLogLevel level;
        std::string message;
    };

    struct EpicAuthLoginCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string local_user_id;
        std::string selected_account_id;
        bool has_continuance_token;
    };

    struct EpicAuthLogoutCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string local_user_id;
    };

    struct EpicAuthLinkAccountCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string local_user_id;
        std::string selected_account_id;
    };

    struct EpicAuthDeletePersistentAuthCallbackInfo
    {
        gm_enums::EpicResult result_code;
    };

    struct EpicAuthIdToken
    {
        std::string account_id;
        std::string json_web_token;
    };

    struct EpicAuthUserAuthToken
    {
        std::string app;
        std::string client_id;
        std::string account_id;
        std::string access_token;
        double expires_in;
        std::string expires_at;
        gm_enums::EpicAuthTokenType auth_type;
        std::string refresh_token;
        double refresh_expires_in;
        std::string refresh_expires_at;
    };

    struct EpicAuthQueryIdTokenCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string local_user_id;
        std::string target_account_id;
    };

    struct EpicAuthVerifyIdTokenCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string application_id;
        std::string client_id;
        std::string product_id;
        std::string sandbox_id;
        std::string deployment_id;
        std::string display_name;
        bool is_external_account_info_present;
    };

    struct EpicAuthVerifyUserAuthCallbackInfo
    {
        gm_enums::EpicResult result_code;
    };

    struct EpicAuthLoginStatusChangedCallbackInfo
    {
        std::string local_user_id;
        gm_enums::EpicLoginStatus previous_status;
        gm_enums::EpicLoginStatus current_status;
    };

    struct EpicConnectLoginCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string local_user_id;
        bool has_continuance_token;
    };

    struct EpicConnectCreateUserCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string local_user_id;
    };

    struct EpicConnectLinkAccountCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string local_user_id;
    };

    struct EpicConnectUnlinkAccountCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string local_user_id;
    };

    struct EpicConnectCreateDeviceIdCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string device_model;
    };

    struct EpicConnectDeleteDeviceIdCallbackInfo
    {
        gm_enums::EpicResult result_code;
    };

    struct EpicConnectTransferDeviceIdAccountCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string local_user_id;
    };

    struct EpicConnectLogoutCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string local_user_id;
    };

    struct EpicConnectIdToken
    {
        std::string product_user_id;
        std::string json_web_token;
    };

    struct EpicConnectExternalAccountInfo
    {
        std::string product_user_id;
        std::string display_name;
        std::string account_id;
        gm_enums::EpicExternalAccountType account_id_type;
        std::int64_t last_login_time;
    };

    struct EpicConnectVerifyIdTokenCallbackInfo
    {
        gm_enums::EpicResult result_code;
    };

    struct EpicConnectQueryExternalAccountMappingsCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string local_user_id;
    };

    struct EpicConnectQueryProductUserIdMappingsCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string local_user_id;
    };

    struct EpicConnectAuthExpirationCallbackInfo
    {
        std::string local_user_id;
    };

    struct EpicConnectLoginStatusChangedCallbackInfo
    {
        std::string local_user_id;
        gm_enums::EpicLoginStatus previous_status;
        gm_enums::EpicLoginStatus current_status;
    };

    struct EpicFriendsQueryFriendsCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string local_user_id;
    };

    struct EpicFriendsFriendsUpdateCallbackInfo
    {
        std::string local_user_id;
        std::string target_user_id;
        gm_enums::EpicFriendsStatus previous_status;
        gm_enums::EpicFriendsStatus current_status;
    };

    struct EpicUserInfo
    {
        std::string user_id;
        std::string country;
        std::string display_name;
        std::string preferred_language;
        std::string nickname;
    };

    struct EpicUserInfoQueryUserInfoCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string local_user_id;
        std::string target_user_id;
    };

    struct EpicUserInfoExternalUserInfo
    {
        std::string account_id;
        gm_enums::EpicExternalAccountType account_type;
        std::string display_name;
    };

    struct EpicStatsStat
    {
        std::string name;
        std::int64_t start_time;
        std::int64_t end_time;
        std::int64_t value;
    };

    struct EpicStatsIngestStatCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string local_user_id;
        std::string target_user_id;
    };

    struct EpicStatsQueryStatsCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string local_user_id;
        std::string target_user_id;
    };

    struct EpicUIShowFriendsCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string local_user_id;
    };

    struct EpicUIShowNativeProfileCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string local_user_id;
        std::string target_user_id;
    };

    struct EpicUIDisplaySettingsUpdatedCallbackInfo
    {
        bool is_visible;
        bool is_exclusive_input;
    };

    struct EpicReportsSendPlayerBehaviorReportCallbackInfo
    {
        gm_enums::EpicResult result_code;
    };

    struct EpicSanctionsPlayerSanction
    {
        std::int64_t time_placed;
        std::string action;
        std::int64_t time_expires;
        std::string reference_id;
    };

    struct EpicSanctionsQueryActivePlayerSanctionsCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string target_user_id;
    };

    struct EpicSanctionsCreatePlayerSanctionAppealCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string reference_id;
    };

    struct EpicAchievementsQueryDefinitionsCallbackInfo
    {
        gm_enums::EpicResult result_code;
    };

    struct EpicAchievementsQueryPlayerAchievementsCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string user_id;
        std::string target_user_id;
    };

    struct EpicAchievementsDefinition
    {
        std::string achievement_id;
        std::string display_name;
        std::string description;
        std::string locked_display_name;
        std::string locked_description;
        std::string hidden_description;
        std::string completion_description;
        std::string unlocked_icon_id;
        std::string locked_icon_id;
        bool is_hidden;
        std::int64_t stat_thresholds_count;
    };

    struct EpicPlayerAchievement
    {
        std::string achievement_id;
        double progress;
        std::int64_t unlock_time;
        std::int64_t stat_info_count;
    };

    struct EpicAchievementsUnlockAchievementsCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string user_id;
        std::int64_t achievements_count;
    };

    struct EpicAchievementsDefinitionV2
    {
        std::string achievement_id;
        std::string unlocked_display_name;
        std::string unlocked_description;
        std::string locked_display_name;
        std::string locked_description;
        std::string flavor_text;
        std::string completion_description;
        std::string unlocked_icon_url;
        std::string locked_icon_url;
        bool is_hidden;
        std::int64_t stat_thresholds_count;
    };

    struct EpicAchievementsUnlockedV2CallbackInfo
    {
        std::string user_id;
        std::string achievement_id;
        std::int64_t unlock_time;
    };

    struct EpicLeaderboardsQueryDefinitionsCallbackInfo
    {
        gm_enums::EpicResult result_code;
    };

    struct EpicLeaderboardsQueryRanksCallbackInfo
    {
        gm_enums::EpicResult result_code;
    };

    struct EpicLeaderboardsQueryUserScoresCallbackInfo
    {
        gm_enums::EpicResult result_code;
    };

    struct EpicLeaderboardDefinition
    {
        std::string leaderboard_id;
        std::string stat_name;
        std::int64_t start_time;
        std::int64_t end_time;
        std::string aggregation;
    };

    struct EpicLeaderboardRecord
    {
        std::string user_id;
        std::int64_t rank;
        std::int64_t score;
        std::string user_display_name;
    };

    struct EpicLeaderboardUserScore
    {
        std::string user_id;
        std::int64_t score;
    };

    struct EpicPresenceInfo
    {
        std::string user_id;
        gm_enums::EpicPresenceStatus status;
        std::string product_id;
        std::string product_version;
        std::string platform;
        std::string rich_text;
        std::int64_t records_count;
    };

    struct EpicPresenceQueryPresenceCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string local_user_id;
        std::string target_user_id;
    };

    struct EpicPresenceSetPresenceCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string local_user_id;
    };

    struct EpicPresenceChangedCallbackInfo
    {
        std::string local_user_id;
        std::string presence_user_id;
    };

    struct EpicPresenceJoinGameAcceptedCallbackInfo
    {
        std::string join_info;
        std::string local_user_id;
        std::string target_user_id;
        std::uint64_t ui_event_id;
    };

    struct EpicSessionsUpdateSessionCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string session_name;
    };

    struct EpicSessionsDestroySessionCallbackInfo
    {
        gm_enums::EpicResult result_code;
    };

    struct EpicSessionsStartSessionCallbackInfo
    {
        gm_enums::EpicResult result_code;
    };

    struct EpicSessionsEndSessionCallbackInfo
    {
        gm_enums::EpicResult result_code;
    };

    struct EpicSessionsJoinSessionCallbackInfo
    {
        gm_enums::EpicResult result_code;
    };

    struct EpicSessionsRegisterPlayersCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::vector<std::string> registered_players;
        std::vector<std::string> sanctioned_players;
    };

    struct EpicSessionsUnregisterPlayersCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::vector<std::string> unregistered_players;
    };

    struct EpicSessionsFindCallbackInfo
    {
        gm_enums::EpicResult result_code;
    };

    struct EpicSessionDetailsInfo
    {
        std::string session_id;
        std::string host_address;
        std::string owner_user_id;
        std::int64_t num_open_public_connections;
        std::int64_t settings_count;
    };

    struct EpicActiveSessionInfo
    {
        std::string session_name;
        std::string local_user_id;
        std::string session_id;
        std::string bucket_id;
    };

    struct EpicSessionsSessionInviteReceivedCallbackInfo
    {
        std::string local_user_id;
        std::string target_user_id;
        std::string invite_id;
    };

    struct EpicSessionsSessionInviteAcceptedCallbackInfo
    {
        std::string local_user_id;
        std::string target_user_id;
        std::string invite_id;
    };

    struct EpicSessionsJoinSessionAcceptedCallbackInfo
    {
        std::uint64_t ui_event_id;
    };

    struct EpicLobbyCreateLobbyCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string lobby_id;
    };

    struct EpicLobbyDestroyLobbyCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string lobby_id;
    };

    struct EpicLobbyJoinLobbyCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string lobby_id;
    };

    struct EpicLobbyLeaveLobbyCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string lobby_id;
    };

    struct EpicLobbyUpdateLobbyCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string lobby_id;
    };

    struct EpicLobbyPromoteMemberCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string lobby_id;
    };

    struct EpicLobbyKickMemberCallbackInfo
    {
        gm_enums::EpicResult result_code;
        std::string lobby_id;
    };

    struct EpicLobbySearchFindCallbackInfo
    {
        gm_enums::EpicResult result_code;
    };

    struct EpicLobbyDetailsInfo
    {
        std::string lobby_id;
        std::string bucket_id;
        std::string lobby_owner_user_id;
        std::int64_t available_slots;
        std::int64_t max_members;
        gm_enums::EpicLobbyPermissionLevel permission_level;
        bool allow_invites;
        bool presence_enabled;
    };

    struct EpicLobbyLobbyUpdateReceivedCallbackInfo
    {
        std::string lobby_id;
        std::string local_user_id;
    };

    struct EpicLobbyLobbyMemberUpdateReceivedCallbackInfo
    {
        std::string lobby_id;
        std::string target_user_id;
        std::string local_user_id;
    };

    struct EpicLobbyLobbyMemberStatusReceivedCallbackInfo
    {
        std::string lobby_id;
        std::string target_user_id;
        std::string local_user_id;
        gm_enums::EpicLobbyMemberStatus current_status;
    };

    struct EpicLobbyJoinLobbyAcceptedCallbackInfo
    {
        std::uint64_t ui_event_id;
    };

    struct EpicLobbyLeaveLobbyRequestedCallbackInfo
    {
        std::string lobby_id;
        std::string local_user_id;
    };

    struct EpicLobbySendLobbyNativeInviteRequestedCallbackInfo
    {
        std::string lobby_id;
        std::string local_user_id;
        std::string target_native_account_type;
        std::string target_user_native_account_id;
    };

}

namespace gm::wire::codec
{
    template<>
    inline void writeValue<gm_structs::EpicLoggingMessage>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLoggingMessage& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.category);
        gm::wire::codec::writeValue(_buf, obj.level);
        gm::wire::codec::writeValue(_buf, obj.message);
    }

    template<>
    inline gm_structs::EpicLoggingMessage readValue<gm_structs::EpicLoggingMessage>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLoggingMessage obj;
        obj.category = gm::wire::codec::readValue<gm_enums::EpicLogCategory>(_buf);
        obj.level = gm::wire::codec::readValue<gm_enums::EpicLogLevel>(_buf);
        obj.message = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicAuthLoginCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicAuthLoginCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
        gm::wire::codec::writeValue(_buf, obj.selected_account_id);
        gm::wire::codec::writeValue(_buf, obj.has_continuance_token);
    }

    template<>
    inline gm_structs::EpicAuthLoginCallbackInfo readValue<gm_structs::EpicAuthLoginCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicAuthLoginCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.selected_account_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.has_continuance_token = gm::wire::codec::readValue<bool>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicAuthLogoutCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicAuthLogoutCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
    }

    template<>
    inline gm_structs::EpicAuthLogoutCallbackInfo readValue<gm_structs::EpicAuthLogoutCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicAuthLogoutCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicAuthLinkAccountCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicAuthLinkAccountCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
        gm::wire::codec::writeValue(_buf, obj.selected_account_id);
    }

    template<>
    inline gm_structs::EpicAuthLinkAccountCallbackInfo readValue<gm_structs::EpicAuthLinkAccountCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicAuthLinkAccountCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.selected_account_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicAuthDeletePersistentAuthCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicAuthDeletePersistentAuthCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
    }

    template<>
    inline gm_structs::EpicAuthDeletePersistentAuthCallbackInfo readValue<gm_structs::EpicAuthDeletePersistentAuthCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicAuthDeletePersistentAuthCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicAuthIdToken>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicAuthIdToken& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.account_id);
        gm::wire::codec::writeValue(_buf, obj.json_web_token);
    }

    template<>
    inline gm_structs::EpicAuthIdToken readValue<gm_structs::EpicAuthIdToken>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicAuthIdToken obj;
        obj.account_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.json_web_token = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicAuthUserAuthToken>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicAuthUserAuthToken& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.app);
        gm::wire::codec::writeValue(_buf, obj.client_id);
        gm::wire::codec::writeValue(_buf, obj.account_id);
        gm::wire::codec::writeValue(_buf, obj.access_token);
        gm::wire::codec::writeValue(_buf, obj.expires_in);
        gm::wire::codec::writeValue(_buf, obj.expires_at);
        gm::wire::codec::writeValue(_buf, obj.auth_type);
        gm::wire::codec::writeValue(_buf, obj.refresh_token);
        gm::wire::codec::writeValue(_buf, obj.refresh_expires_in);
        gm::wire::codec::writeValue(_buf, obj.refresh_expires_at);
    }

    template<>
    inline gm_structs::EpicAuthUserAuthToken readValue<gm_structs::EpicAuthUserAuthToken>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicAuthUserAuthToken obj;
        obj.app = gm::wire::codec::readValue<std::string>(_buf);
        obj.client_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.account_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.access_token = gm::wire::codec::readValue<std::string>(_buf);
        obj.expires_in = gm::wire::codec::readValue<double>(_buf);
        obj.expires_at = gm::wire::codec::readValue<std::string>(_buf);
        obj.auth_type = gm::wire::codec::readValue<gm_enums::EpicAuthTokenType>(_buf);
        obj.refresh_token = gm::wire::codec::readValue<std::string>(_buf);
        obj.refresh_expires_in = gm::wire::codec::readValue<double>(_buf);
        obj.refresh_expires_at = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicAuthQueryIdTokenCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicAuthQueryIdTokenCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
        gm::wire::codec::writeValue(_buf, obj.target_account_id);
    }

    template<>
    inline gm_structs::EpicAuthQueryIdTokenCallbackInfo readValue<gm_structs::EpicAuthQueryIdTokenCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicAuthQueryIdTokenCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.target_account_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicAuthVerifyIdTokenCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicAuthVerifyIdTokenCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.application_id);
        gm::wire::codec::writeValue(_buf, obj.client_id);
        gm::wire::codec::writeValue(_buf, obj.product_id);
        gm::wire::codec::writeValue(_buf, obj.sandbox_id);
        gm::wire::codec::writeValue(_buf, obj.deployment_id);
        gm::wire::codec::writeValue(_buf, obj.display_name);
        gm::wire::codec::writeValue(_buf, obj.is_external_account_info_present);
    }

    template<>
    inline gm_structs::EpicAuthVerifyIdTokenCallbackInfo readValue<gm_structs::EpicAuthVerifyIdTokenCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicAuthVerifyIdTokenCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.application_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.client_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.product_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.sandbox_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.deployment_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.display_name = gm::wire::codec::readValue<std::string>(_buf);
        obj.is_external_account_info_present = gm::wire::codec::readValue<bool>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicAuthVerifyUserAuthCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicAuthVerifyUserAuthCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
    }

    template<>
    inline gm_structs::EpicAuthVerifyUserAuthCallbackInfo readValue<gm_structs::EpicAuthVerifyUserAuthCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicAuthVerifyUserAuthCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicAuthLoginStatusChangedCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicAuthLoginStatusChangedCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
        gm::wire::codec::writeValue(_buf, obj.previous_status);
        gm::wire::codec::writeValue(_buf, obj.current_status);
    }

    template<>
    inline gm_structs::EpicAuthLoginStatusChangedCallbackInfo readValue<gm_structs::EpicAuthLoginStatusChangedCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicAuthLoginStatusChangedCallbackInfo obj;
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.previous_status = gm::wire::codec::readValue<gm_enums::EpicLoginStatus>(_buf);
        obj.current_status = gm::wire::codec::readValue<gm_enums::EpicLoginStatus>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicConnectLoginCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicConnectLoginCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
        gm::wire::codec::writeValue(_buf, obj.has_continuance_token);
    }

    template<>
    inline gm_structs::EpicConnectLoginCallbackInfo readValue<gm_structs::EpicConnectLoginCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicConnectLoginCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.has_continuance_token = gm::wire::codec::readValue<bool>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicConnectCreateUserCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicConnectCreateUserCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
    }

    template<>
    inline gm_structs::EpicConnectCreateUserCallbackInfo readValue<gm_structs::EpicConnectCreateUserCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicConnectCreateUserCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicConnectLinkAccountCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicConnectLinkAccountCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
    }

    template<>
    inline gm_structs::EpicConnectLinkAccountCallbackInfo readValue<gm_structs::EpicConnectLinkAccountCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicConnectLinkAccountCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicConnectUnlinkAccountCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicConnectUnlinkAccountCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
    }

    template<>
    inline gm_structs::EpicConnectUnlinkAccountCallbackInfo readValue<gm_structs::EpicConnectUnlinkAccountCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicConnectUnlinkAccountCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicConnectCreateDeviceIdCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicConnectCreateDeviceIdCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.device_model);
    }

    template<>
    inline gm_structs::EpicConnectCreateDeviceIdCallbackInfo readValue<gm_structs::EpicConnectCreateDeviceIdCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicConnectCreateDeviceIdCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.device_model = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicConnectDeleteDeviceIdCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicConnectDeleteDeviceIdCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
    }

    template<>
    inline gm_structs::EpicConnectDeleteDeviceIdCallbackInfo readValue<gm_structs::EpicConnectDeleteDeviceIdCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicConnectDeleteDeviceIdCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicConnectTransferDeviceIdAccountCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicConnectTransferDeviceIdAccountCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
    }

    template<>
    inline gm_structs::EpicConnectTransferDeviceIdAccountCallbackInfo readValue<gm_structs::EpicConnectTransferDeviceIdAccountCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicConnectTransferDeviceIdAccountCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicConnectLogoutCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicConnectLogoutCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
    }

    template<>
    inline gm_structs::EpicConnectLogoutCallbackInfo readValue<gm_structs::EpicConnectLogoutCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicConnectLogoutCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicConnectIdToken>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicConnectIdToken& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.product_user_id);
        gm::wire::codec::writeValue(_buf, obj.json_web_token);
    }

    template<>
    inline gm_structs::EpicConnectIdToken readValue<gm_structs::EpicConnectIdToken>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicConnectIdToken obj;
        obj.product_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.json_web_token = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicConnectExternalAccountInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicConnectExternalAccountInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.product_user_id);
        gm::wire::codec::writeValue(_buf, obj.display_name);
        gm::wire::codec::writeValue(_buf, obj.account_id);
        gm::wire::codec::writeValue(_buf, obj.account_id_type);
        gm::wire::codec::writeValue(_buf, obj.last_login_time);
    }

    template<>
    inline gm_structs::EpicConnectExternalAccountInfo readValue<gm_structs::EpicConnectExternalAccountInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicConnectExternalAccountInfo obj;
        obj.product_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.display_name = gm::wire::codec::readValue<std::string>(_buf);
        obj.account_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.account_id_type = gm::wire::codec::readValue<gm_enums::EpicExternalAccountType>(_buf);
        obj.last_login_time = gm::wire::codec::readValue<std::int64_t>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicConnectVerifyIdTokenCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicConnectVerifyIdTokenCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
    }

    template<>
    inline gm_structs::EpicConnectVerifyIdTokenCallbackInfo readValue<gm_structs::EpicConnectVerifyIdTokenCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicConnectVerifyIdTokenCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicConnectQueryExternalAccountMappingsCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicConnectQueryExternalAccountMappingsCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
    }

    template<>
    inline gm_structs::EpicConnectQueryExternalAccountMappingsCallbackInfo readValue<gm_structs::EpicConnectQueryExternalAccountMappingsCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicConnectQueryExternalAccountMappingsCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicConnectQueryProductUserIdMappingsCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicConnectQueryProductUserIdMappingsCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
    }

    template<>
    inline gm_structs::EpicConnectQueryProductUserIdMappingsCallbackInfo readValue<gm_structs::EpicConnectQueryProductUserIdMappingsCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicConnectQueryProductUserIdMappingsCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicConnectAuthExpirationCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicConnectAuthExpirationCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
    }

    template<>
    inline gm_structs::EpicConnectAuthExpirationCallbackInfo readValue<gm_structs::EpicConnectAuthExpirationCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicConnectAuthExpirationCallbackInfo obj;
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicConnectLoginStatusChangedCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicConnectLoginStatusChangedCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
        gm::wire::codec::writeValue(_buf, obj.previous_status);
        gm::wire::codec::writeValue(_buf, obj.current_status);
    }

    template<>
    inline gm_structs::EpicConnectLoginStatusChangedCallbackInfo readValue<gm_structs::EpicConnectLoginStatusChangedCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicConnectLoginStatusChangedCallbackInfo obj;
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.previous_status = gm::wire::codec::readValue<gm_enums::EpicLoginStatus>(_buf);
        obj.current_status = gm::wire::codec::readValue<gm_enums::EpicLoginStatus>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicFriendsQueryFriendsCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicFriendsQueryFriendsCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
    }

    template<>
    inline gm_structs::EpicFriendsQueryFriendsCallbackInfo readValue<gm_structs::EpicFriendsQueryFriendsCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicFriendsQueryFriendsCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicFriendsFriendsUpdateCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicFriendsFriendsUpdateCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
        gm::wire::codec::writeValue(_buf, obj.target_user_id);
        gm::wire::codec::writeValue(_buf, obj.previous_status);
        gm::wire::codec::writeValue(_buf, obj.current_status);
    }

    template<>
    inline gm_structs::EpicFriendsFriendsUpdateCallbackInfo readValue<gm_structs::EpicFriendsFriendsUpdateCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicFriendsFriendsUpdateCallbackInfo obj;
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.target_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.previous_status = gm::wire::codec::readValue<gm_enums::EpicFriendsStatus>(_buf);
        obj.current_status = gm::wire::codec::readValue<gm_enums::EpicFriendsStatus>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicUserInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicUserInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.user_id);
        gm::wire::codec::writeValue(_buf, obj.country);
        gm::wire::codec::writeValue(_buf, obj.display_name);
        gm::wire::codec::writeValue(_buf, obj.preferred_language);
        gm::wire::codec::writeValue(_buf, obj.nickname);
    }

    template<>
    inline gm_structs::EpicUserInfo readValue<gm_structs::EpicUserInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicUserInfo obj;
        obj.user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.country = gm::wire::codec::readValue<std::string>(_buf);
        obj.display_name = gm::wire::codec::readValue<std::string>(_buf);
        obj.preferred_language = gm::wire::codec::readValue<std::string>(_buf);
        obj.nickname = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicUserInfoQueryUserInfoCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicUserInfoQueryUserInfoCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
        gm::wire::codec::writeValue(_buf, obj.target_user_id);
    }

    template<>
    inline gm_structs::EpicUserInfoQueryUserInfoCallbackInfo readValue<gm_structs::EpicUserInfoQueryUserInfoCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicUserInfoQueryUserInfoCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.target_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicUserInfoExternalUserInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicUserInfoExternalUserInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.account_id);
        gm::wire::codec::writeValue(_buf, obj.account_type);
        gm::wire::codec::writeValue(_buf, obj.display_name);
    }

    template<>
    inline gm_structs::EpicUserInfoExternalUserInfo readValue<gm_structs::EpicUserInfoExternalUserInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicUserInfoExternalUserInfo obj;
        obj.account_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.account_type = gm::wire::codec::readValue<gm_enums::EpicExternalAccountType>(_buf);
        obj.display_name = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicStatsStat>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicStatsStat& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.name);
        gm::wire::codec::writeValue(_buf, obj.start_time);
        gm::wire::codec::writeValue(_buf, obj.end_time);
        gm::wire::codec::writeValue(_buf, obj.value);
    }

    template<>
    inline gm_structs::EpicStatsStat readValue<gm_structs::EpicStatsStat>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicStatsStat obj;
        obj.name = gm::wire::codec::readValue<std::string>(_buf);
        obj.start_time = gm::wire::codec::readValue<std::int64_t>(_buf);
        obj.end_time = gm::wire::codec::readValue<std::int64_t>(_buf);
        obj.value = gm::wire::codec::readValue<std::int64_t>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicStatsIngestStatCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicStatsIngestStatCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
        gm::wire::codec::writeValue(_buf, obj.target_user_id);
    }

    template<>
    inline gm_structs::EpicStatsIngestStatCallbackInfo readValue<gm_structs::EpicStatsIngestStatCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicStatsIngestStatCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.target_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicStatsQueryStatsCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicStatsQueryStatsCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
        gm::wire::codec::writeValue(_buf, obj.target_user_id);
    }

    template<>
    inline gm_structs::EpicStatsQueryStatsCallbackInfo readValue<gm_structs::EpicStatsQueryStatsCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicStatsQueryStatsCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.target_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicUIShowFriendsCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicUIShowFriendsCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
    }

    template<>
    inline gm_structs::EpicUIShowFriendsCallbackInfo readValue<gm_structs::EpicUIShowFriendsCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicUIShowFriendsCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicUIShowNativeProfileCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicUIShowNativeProfileCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
        gm::wire::codec::writeValue(_buf, obj.target_user_id);
    }

    template<>
    inline gm_structs::EpicUIShowNativeProfileCallbackInfo readValue<gm_structs::EpicUIShowNativeProfileCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicUIShowNativeProfileCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.target_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicUIDisplaySettingsUpdatedCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicUIDisplaySettingsUpdatedCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.is_visible);
        gm::wire::codec::writeValue(_buf, obj.is_exclusive_input);
    }

    template<>
    inline gm_structs::EpicUIDisplaySettingsUpdatedCallbackInfo readValue<gm_structs::EpicUIDisplaySettingsUpdatedCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicUIDisplaySettingsUpdatedCallbackInfo obj;
        obj.is_visible = gm::wire::codec::readValue<bool>(_buf);
        obj.is_exclusive_input = gm::wire::codec::readValue<bool>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicReportsSendPlayerBehaviorReportCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicReportsSendPlayerBehaviorReportCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
    }

    template<>
    inline gm_structs::EpicReportsSendPlayerBehaviorReportCallbackInfo readValue<gm_structs::EpicReportsSendPlayerBehaviorReportCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicReportsSendPlayerBehaviorReportCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicSanctionsPlayerSanction>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicSanctionsPlayerSanction& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.time_placed);
        gm::wire::codec::writeValue(_buf, obj.action);
        gm::wire::codec::writeValue(_buf, obj.time_expires);
        gm::wire::codec::writeValue(_buf, obj.reference_id);
    }

    template<>
    inline gm_structs::EpicSanctionsPlayerSanction readValue<gm_structs::EpicSanctionsPlayerSanction>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicSanctionsPlayerSanction obj;
        obj.time_placed = gm::wire::codec::readValue<std::int64_t>(_buf);
        obj.action = gm::wire::codec::readValue<std::string>(_buf);
        obj.time_expires = gm::wire::codec::readValue<std::int64_t>(_buf);
        obj.reference_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicSanctionsQueryActivePlayerSanctionsCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicSanctionsQueryActivePlayerSanctionsCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.target_user_id);
    }

    template<>
    inline gm_structs::EpicSanctionsQueryActivePlayerSanctionsCallbackInfo readValue<gm_structs::EpicSanctionsQueryActivePlayerSanctionsCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicSanctionsQueryActivePlayerSanctionsCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.target_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicSanctionsCreatePlayerSanctionAppealCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicSanctionsCreatePlayerSanctionAppealCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.reference_id);
    }

    template<>
    inline gm_structs::EpicSanctionsCreatePlayerSanctionAppealCallbackInfo readValue<gm_structs::EpicSanctionsCreatePlayerSanctionAppealCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicSanctionsCreatePlayerSanctionAppealCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.reference_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicAchievementsQueryDefinitionsCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicAchievementsQueryDefinitionsCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
    }

    template<>
    inline gm_structs::EpicAchievementsQueryDefinitionsCallbackInfo readValue<gm_structs::EpicAchievementsQueryDefinitionsCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicAchievementsQueryDefinitionsCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicAchievementsQueryPlayerAchievementsCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicAchievementsQueryPlayerAchievementsCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.user_id);
        gm::wire::codec::writeValue(_buf, obj.target_user_id);
    }

    template<>
    inline gm_structs::EpicAchievementsQueryPlayerAchievementsCallbackInfo readValue<gm_structs::EpicAchievementsQueryPlayerAchievementsCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicAchievementsQueryPlayerAchievementsCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.target_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicAchievementsDefinition>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicAchievementsDefinition& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.achievement_id);
        gm::wire::codec::writeValue(_buf, obj.display_name);
        gm::wire::codec::writeValue(_buf, obj.description);
        gm::wire::codec::writeValue(_buf, obj.locked_display_name);
        gm::wire::codec::writeValue(_buf, obj.locked_description);
        gm::wire::codec::writeValue(_buf, obj.hidden_description);
        gm::wire::codec::writeValue(_buf, obj.completion_description);
        gm::wire::codec::writeValue(_buf, obj.unlocked_icon_id);
        gm::wire::codec::writeValue(_buf, obj.locked_icon_id);
        gm::wire::codec::writeValue(_buf, obj.is_hidden);
        gm::wire::codec::writeValue(_buf, obj.stat_thresholds_count);
    }

    template<>
    inline gm_structs::EpicAchievementsDefinition readValue<gm_structs::EpicAchievementsDefinition>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicAchievementsDefinition obj;
        obj.achievement_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.display_name = gm::wire::codec::readValue<std::string>(_buf);
        obj.description = gm::wire::codec::readValue<std::string>(_buf);
        obj.locked_display_name = gm::wire::codec::readValue<std::string>(_buf);
        obj.locked_description = gm::wire::codec::readValue<std::string>(_buf);
        obj.hidden_description = gm::wire::codec::readValue<std::string>(_buf);
        obj.completion_description = gm::wire::codec::readValue<std::string>(_buf);
        obj.unlocked_icon_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.locked_icon_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.is_hidden = gm::wire::codec::readValue<bool>(_buf);
        obj.stat_thresholds_count = gm::wire::codec::readValue<std::int64_t>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicPlayerAchievement>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicPlayerAchievement& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.achievement_id);
        gm::wire::codec::writeValue(_buf, obj.progress);
        gm::wire::codec::writeValue(_buf, obj.unlock_time);
        gm::wire::codec::writeValue(_buf, obj.stat_info_count);
    }

    template<>
    inline gm_structs::EpicPlayerAchievement readValue<gm_structs::EpicPlayerAchievement>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicPlayerAchievement obj;
        obj.achievement_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.progress = gm::wire::codec::readValue<double>(_buf);
        obj.unlock_time = gm::wire::codec::readValue<std::int64_t>(_buf);
        obj.stat_info_count = gm::wire::codec::readValue<std::int64_t>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicAchievementsUnlockAchievementsCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicAchievementsUnlockAchievementsCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.user_id);
        gm::wire::codec::writeValue(_buf, obj.achievements_count);
    }

    template<>
    inline gm_structs::EpicAchievementsUnlockAchievementsCallbackInfo readValue<gm_structs::EpicAchievementsUnlockAchievementsCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicAchievementsUnlockAchievementsCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.achievements_count = gm::wire::codec::readValue<std::int64_t>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicAchievementsDefinitionV2>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicAchievementsDefinitionV2& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.achievement_id);
        gm::wire::codec::writeValue(_buf, obj.unlocked_display_name);
        gm::wire::codec::writeValue(_buf, obj.unlocked_description);
        gm::wire::codec::writeValue(_buf, obj.locked_display_name);
        gm::wire::codec::writeValue(_buf, obj.locked_description);
        gm::wire::codec::writeValue(_buf, obj.flavor_text);
        gm::wire::codec::writeValue(_buf, obj.completion_description);
        gm::wire::codec::writeValue(_buf, obj.unlocked_icon_url);
        gm::wire::codec::writeValue(_buf, obj.locked_icon_url);
        gm::wire::codec::writeValue(_buf, obj.is_hidden);
        gm::wire::codec::writeValue(_buf, obj.stat_thresholds_count);
    }

    template<>
    inline gm_structs::EpicAchievementsDefinitionV2 readValue<gm_structs::EpicAchievementsDefinitionV2>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicAchievementsDefinitionV2 obj;
        obj.achievement_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.unlocked_display_name = gm::wire::codec::readValue<std::string>(_buf);
        obj.unlocked_description = gm::wire::codec::readValue<std::string>(_buf);
        obj.locked_display_name = gm::wire::codec::readValue<std::string>(_buf);
        obj.locked_description = gm::wire::codec::readValue<std::string>(_buf);
        obj.flavor_text = gm::wire::codec::readValue<std::string>(_buf);
        obj.completion_description = gm::wire::codec::readValue<std::string>(_buf);
        obj.unlocked_icon_url = gm::wire::codec::readValue<std::string>(_buf);
        obj.locked_icon_url = gm::wire::codec::readValue<std::string>(_buf);
        obj.is_hidden = gm::wire::codec::readValue<bool>(_buf);
        obj.stat_thresholds_count = gm::wire::codec::readValue<std::int64_t>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicAchievementsUnlockedV2CallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicAchievementsUnlockedV2CallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.user_id);
        gm::wire::codec::writeValue(_buf, obj.achievement_id);
        gm::wire::codec::writeValue(_buf, obj.unlock_time);
    }

    template<>
    inline gm_structs::EpicAchievementsUnlockedV2CallbackInfo readValue<gm_structs::EpicAchievementsUnlockedV2CallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicAchievementsUnlockedV2CallbackInfo obj;
        obj.user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.achievement_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.unlock_time = gm::wire::codec::readValue<std::int64_t>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLeaderboardsQueryDefinitionsCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLeaderboardsQueryDefinitionsCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
    }

    template<>
    inline gm_structs::EpicLeaderboardsQueryDefinitionsCallbackInfo readValue<gm_structs::EpicLeaderboardsQueryDefinitionsCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLeaderboardsQueryDefinitionsCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLeaderboardsQueryRanksCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLeaderboardsQueryRanksCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
    }

    template<>
    inline gm_structs::EpicLeaderboardsQueryRanksCallbackInfo readValue<gm_structs::EpicLeaderboardsQueryRanksCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLeaderboardsQueryRanksCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLeaderboardsQueryUserScoresCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLeaderboardsQueryUserScoresCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
    }

    template<>
    inline gm_structs::EpicLeaderboardsQueryUserScoresCallbackInfo readValue<gm_structs::EpicLeaderboardsQueryUserScoresCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLeaderboardsQueryUserScoresCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLeaderboardDefinition>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLeaderboardDefinition& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.leaderboard_id);
        gm::wire::codec::writeValue(_buf, obj.stat_name);
        gm::wire::codec::writeValue(_buf, obj.start_time);
        gm::wire::codec::writeValue(_buf, obj.end_time);
        gm::wire::codec::writeValue(_buf, obj.aggregation);
    }

    template<>
    inline gm_structs::EpicLeaderboardDefinition readValue<gm_structs::EpicLeaderboardDefinition>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLeaderboardDefinition obj;
        obj.leaderboard_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.stat_name = gm::wire::codec::readValue<std::string>(_buf);
        obj.start_time = gm::wire::codec::readValue<std::int64_t>(_buf);
        obj.end_time = gm::wire::codec::readValue<std::int64_t>(_buf);
        obj.aggregation = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLeaderboardRecord>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLeaderboardRecord& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.user_id);
        gm::wire::codec::writeValue(_buf, obj.rank);
        gm::wire::codec::writeValue(_buf, obj.score);
        gm::wire::codec::writeValue(_buf, obj.user_display_name);
    }

    template<>
    inline gm_structs::EpicLeaderboardRecord readValue<gm_structs::EpicLeaderboardRecord>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLeaderboardRecord obj;
        obj.user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.rank = gm::wire::codec::readValue<std::int64_t>(_buf);
        obj.score = gm::wire::codec::readValue<std::int64_t>(_buf);
        obj.user_display_name = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLeaderboardUserScore>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLeaderboardUserScore& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.user_id);
        gm::wire::codec::writeValue(_buf, obj.score);
    }

    template<>
    inline gm_structs::EpicLeaderboardUserScore readValue<gm_structs::EpicLeaderboardUserScore>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLeaderboardUserScore obj;
        obj.user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.score = gm::wire::codec::readValue<std::int64_t>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicPresenceInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicPresenceInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.user_id);
        gm::wire::codec::writeValue(_buf, obj.status);
        gm::wire::codec::writeValue(_buf, obj.product_id);
        gm::wire::codec::writeValue(_buf, obj.product_version);
        gm::wire::codec::writeValue(_buf, obj.platform);
        gm::wire::codec::writeValue(_buf, obj.rich_text);
        gm::wire::codec::writeValue(_buf, obj.records_count);
    }

    template<>
    inline gm_structs::EpicPresenceInfo readValue<gm_structs::EpicPresenceInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicPresenceInfo obj;
        obj.user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.status = gm::wire::codec::readValue<gm_enums::EpicPresenceStatus>(_buf);
        obj.product_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.product_version = gm::wire::codec::readValue<std::string>(_buf);
        obj.platform = gm::wire::codec::readValue<std::string>(_buf);
        obj.rich_text = gm::wire::codec::readValue<std::string>(_buf);
        obj.records_count = gm::wire::codec::readValue<std::int64_t>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicPresenceQueryPresenceCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicPresenceQueryPresenceCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
        gm::wire::codec::writeValue(_buf, obj.target_user_id);
    }

    template<>
    inline gm_structs::EpicPresenceQueryPresenceCallbackInfo readValue<gm_structs::EpicPresenceQueryPresenceCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicPresenceQueryPresenceCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.target_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicPresenceSetPresenceCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicPresenceSetPresenceCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
    }

    template<>
    inline gm_structs::EpicPresenceSetPresenceCallbackInfo readValue<gm_structs::EpicPresenceSetPresenceCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicPresenceSetPresenceCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicPresenceChangedCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicPresenceChangedCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
        gm::wire::codec::writeValue(_buf, obj.presence_user_id);
    }

    template<>
    inline gm_structs::EpicPresenceChangedCallbackInfo readValue<gm_structs::EpicPresenceChangedCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicPresenceChangedCallbackInfo obj;
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.presence_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicPresenceJoinGameAcceptedCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicPresenceJoinGameAcceptedCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.join_info);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
        gm::wire::codec::writeValue(_buf, obj.target_user_id);
        gm::wire::codec::writeValue(_buf, obj.ui_event_id);
    }

    template<>
    inline gm_structs::EpicPresenceJoinGameAcceptedCallbackInfo readValue<gm_structs::EpicPresenceJoinGameAcceptedCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicPresenceJoinGameAcceptedCallbackInfo obj;
        obj.join_info = gm::wire::codec::readValue<std::string>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.target_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.ui_event_id = gm::wire::codec::readValue<std::uint64_t>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicSessionsUpdateSessionCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicSessionsUpdateSessionCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.session_name);
    }

    template<>
    inline gm_structs::EpicSessionsUpdateSessionCallbackInfo readValue<gm_structs::EpicSessionsUpdateSessionCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicSessionsUpdateSessionCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.session_name = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicSessionsDestroySessionCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicSessionsDestroySessionCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
    }

    template<>
    inline gm_structs::EpicSessionsDestroySessionCallbackInfo readValue<gm_structs::EpicSessionsDestroySessionCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicSessionsDestroySessionCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicSessionsStartSessionCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicSessionsStartSessionCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
    }

    template<>
    inline gm_structs::EpicSessionsStartSessionCallbackInfo readValue<gm_structs::EpicSessionsStartSessionCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicSessionsStartSessionCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicSessionsEndSessionCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicSessionsEndSessionCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
    }

    template<>
    inline gm_structs::EpicSessionsEndSessionCallbackInfo readValue<gm_structs::EpicSessionsEndSessionCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicSessionsEndSessionCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicSessionsJoinSessionCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicSessionsJoinSessionCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
    }

    template<>
    inline gm_structs::EpicSessionsJoinSessionCallbackInfo readValue<gm_structs::EpicSessionsJoinSessionCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicSessionsJoinSessionCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicSessionsRegisterPlayersCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicSessionsRegisterPlayersCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.registered_players);
        gm::wire::codec::writeValue(_buf, obj.sanctioned_players);
    }

    template<>
    inline gm_structs::EpicSessionsRegisterPlayersCallbackInfo readValue<gm_structs::EpicSessionsRegisterPlayersCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicSessionsRegisterPlayersCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.registered_players = gm::wire::codec::readVector<std::string>(_buf);
        obj.sanctioned_players = gm::wire::codec::readVector<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicSessionsUnregisterPlayersCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicSessionsUnregisterPlayersCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.unregistered_players);
    }

    template<>
    inline gm_structs::EpicSessionsUnregisterPlayersCallbackInfo readValue<gm_structs::EpicSessionsUnregisterPlayersCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicSessionsUnregisterPlayersCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.unregistered_players = gm::wire::codec::readVector<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicSessionsFindCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicSessionsFindCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
    }

    template<>
    inline gm_structs::EpicSessionsFindCallbackInfo readValue<gm_structs::EpicSessionsFindCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicSessionsFindCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicSessionDetailsInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicSessionDetailsInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.session_id);
        gm::wire::codec::writeValue(_buf, obj.host_address);
        gm::wire::codec::writeValue(_buf, obj.owner_user_id);
        gm::wire::codec::writeValue(_buf, obj.num_open_public_connections);
        gm::wire::codec::writeValue(_buf, obj.settings_count);
    }

    template<>
    inline gm_structs::EpicSessionDetailsInfo readValue<gm_structs::EpicSessionDetailsInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicSessionDetailsInfo obj;
        obj.session_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.host_address = gm::wire::codec::readValue<std::string>(_buf);
        obj.owner_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.num_open_public_connections = gm::wire::codec::readValue<std::int64_t>(_buf);
        obj.settings_count = gm::wire::codec::readValue<std::int64_t>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicActiveSessionInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicActiveSessionInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.session_name);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
        gm::wire::codec::writeValue(_buf, obj.session_id);
        gm::wire::codec::writeValue(_buf, obj.bucket_id);
    }

    template<>
    inline gm_structs::EpicActiveSessionInfo readValue<gm_structs::EpicActiveSessionInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicActiveSessionInfo obj;
        obj.session_name = gm::wire::codec::readValue<std::string>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.session_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.bucket_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicSessionsSessionInviteReceivedCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicSessionsSessionInviteReceivedCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
        gm::wire::codec::writeValue(_buf, obj.target_user_id);
        gm::wire::codec::writeValue(_buf, obj.invite_id);
    }

    template<>
    inline gm_structs::EpicSessionsSessionInviteReceivedCallbackInfo readValue<gm_structs::EpicSessionsSessionInviteReceivedCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicSessionsSessionInviteReceivedCallbackInfo obj;
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.target_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.invite_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicSessionsSessionInviteAcceptedCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicSessionsSessionInviteAcceptedCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
        gm::wire::codec::writeValue(_buf, obj.target_user_id);
        gm::wire::codec::writeValue(_buf, obj.invite_id);
    }

    template<>
    inline gm_structs::EpicSessionsSessionInviteAcceptedCallbackInfo readValue<gm_structs::EpicSessionsSessionInviteAcceptedCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicSessionsSessionInviteAcceptedCallbackInfo obj;
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.target_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.invite_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicSessionsJoinSessionAcceptedCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicSessionsJoinSessionAcceptedCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.ui_event_id);
    }

    template<>
    inline gm_structs::EpicSessionsJoinSessionAcceptedCallbackInfo readValue<gm_structs::EpicSessionsJoinSessionAcceptedCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicSessionsJoinSessionAcceptedCallbackInfo obj;
        obj.ui_event_id = gm::wire::codec::readValue<std::uint64_t>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLobbyCreateLobbyCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLobbyCreateLobbyCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.lobby_id);
    }

    template<>
    inline gm_structs::EpicLobbyCreateLobbyCallbackInfo readValue<gm_structs::EpicLobbyCreateLobbyCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLobbyCreateLobbyCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.lobby_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLobbyDestroyLobbyCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLobbyDestroyLobbyCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.lobby_id);
    }

    template<>
    inline gm_structs::EpicLobbyDestroyLobbyCallbackInfo readValue<gm_structs::EpicLobbyDestroyLobbyCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLobbyDestroyLobbyCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.lobby_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLobbyJoinLobbyCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLobbyJoinLobbyCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.lobby_id);
    }

    template<>
    inline gm_structs::EpicLobbyJoinLobbyCallbackInfo readValue<gm_structs::EpicLobbyJoinLobbyCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLobbyJoinLobbyCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.lobby_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLobbyLeaveLobbyCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLobbyLeaveLobbyCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.lobby_id);
    }

    template<>
    inline gm_structs::EpicLobbyLeaveLobbyCallbackInfo readValue<gm_structs::EpicLobbyLeaveLobbyCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLobbyLeaveLobbyCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.lobby_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLobbyUpdateLobbyCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLobbyUpdateLobbyCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.lobby_id);
    }

    template<>
    inline gm_structs::EpicLobbyUpdateLobbyCallbackInfo readValue<gm_structs::EpicLobbyUpdateLobbyCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLobbyUpdateLobbyCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.lobby_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLobbyPromoteMemberCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLobbyPromoteMemberCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.lobby_id);
    }

    template<>
    inline gm_structs::EpicLobbyPromoteMemberCallbackInfo readValue<gm_structs::EpicLobbyPromoteMemberCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLobbyPromoteMemberCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.lobby_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLobbyKickMemberCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLobbyKickMemberCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
        gm::wire::codec::writeValue(_buf, obj.lobby_id);
    }

    template<>
    inline gm_structs::EpicLobbyKickMemberCallbackInfo readValue<gm_structs::EpicLobbyKickMemberCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLobbyKickMemberCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        obj.lobby_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLobbySearchFindCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLobbySearchFindCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.result_code);
    }

    template<>
    inline gm_structs::EpicLobbySearchFindCallbackInfo readValue<gm_structs::EpicLobbySearchFindCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLobbySearchFindCallbackInfo obj;
        obj.result_code = gm::wire::codec::readValue<gm_enums::EpicResult>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLobbyDetailsInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLobbyDetailsInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.lobby_id);
        gm::wire::codec::writeValue(_buf, obj.bucket_id);
        gm::wire::codec::writeValue(_buf, obj.lobby_owner_user_id);
        gm::wire::codec::writeValue(_buf, obj.available_slots);
        gm::wire::codec::writeValue(_buf, obj.max_members);
        gm::wire::codec::writeValue(_buf, obj.permission_level);
        gm::wire::codec::writeValue(_buf, obj.allow_invites);
        gm::wire::codec::writeValue(_buf, obj.presence_enabled);
    }

    template<>
    inline gm_structs::EpicLobbyDetailsInfo readValue<gm_structs::EpicLobbyDetailsInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLobbyDetailsInfo obj;
        obj.lobby_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.bucket_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.lobby_owner_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.available_slots = gm::wire::codec::readValue<std::int64_t>(_buf);
        obj.max_members = gm::wire::codec::readValue<std::int64_t>(_buf);
        obj.permission_level = gm::wire::codec::readValue<gm_enums::EpicLobbyPermissionLevel>(_buf);
        obj.allow_invites = gm::wire::codec::readValue<bool>(_buf);
        obj.presence_enabled = gm::wire::codec::readValue<bool>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLobbyLobbyUpdateReceivedCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLobbyLobbyUpdateReceivedCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.lobby_id);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
    }

    template<>
    inline gm_structs::EpicLobbyLobbyUpdateReceivedCallbackInfo readValue<gm_structs::EpicLobbyLobbyUpdateReceivedCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLobbyLobbyUpdateReceivedCallbackInfo obj;
        obj.lobby_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLobbyLobbyMemberUpdateReceivedCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLobbyLobbyMemberUpdateReceivedCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.lobby_id);
        gm::wire::codec::writeValue(_buf, obj.target_user_id);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
    }

    template<>
    inline gm_structs::EpicLobbyLobbyMemberUpdateReceivedCallbackInfo readValue<gm_structs::EpicLobbyLobbyMemberUpdateReceivedCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLobbyLobbyMemberUpdateReceivedCallbackInfo obj;
        obj.lobby_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.target_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLobbyLobbyMemberStatusReceivedCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLobbyLobbyMemberStatusReceivedCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.lobby_id);
        gm::wire::codec::writeValue(_buf, obj.target_user_id);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
        gm::wire::codec::writeValue(_buf, obj.current_status);
    }

    template<>
    inline gm_structs::EpicLobbyLobbyMemberStatusReceivedCallbackInfo readValue<gm_structs::EpicLobbyLobbyMemberStatusReceivedCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLobbyLobbyMemberStatusReceivedCallbackInfo obj;
        obj.lobby_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.target_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.current_status = gm::wire::codec::readValue<gm_enums::EpicLobbyMemberStatus>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLobbyJoinLobbyAcceptedCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLobbyJoinLobbyAcceptedCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.ui_event_id);
    }

    template<>
    inline gm_structs::EpicLobbyJoinLobbyAcceptedCallbackInfo readValue<gm_structs::EpicLobbyJoinLobbyAcceptedCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLobbyJoinLobbyAcceptedCallbackInfo obj;
        obj.ui_event_id = gm::wire::codec::readValue<std::uint64_t>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLobbyLeaveLobbyRequestedCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLobbyLeaveLobbyRequestedCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.lobby_id);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
    }

    template<>
    inline gm_structs::EpicLobbyLeaveLobbyRequestedCallbackInfo readValue<gm_structs::EpicLobbyLeaveLobbyRequestedCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLobbyLeaveLobbyRequestedCallbackInfo obj;
        obj.lobby_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

    template<>
    inline void writeValue<gm_structs::EpicLobbySendLobbyNativeInviteRequestedCallbackInfo>(gm::byteio::IByteWriter& _buf, const gm_structs::EpicLobbySendLobbyNativeInviteRequestedCallbackInfo& obj)
    {
        gm::wire::codec::writeValue(_buf, obj.lobby_id);
        gm::wire::codec::writeValue(_buf, obj.local_user_id);
        gm::wire::codec::writeValue(_buf, obj.target_native_account_type);
        gm::wire::codec::writeValue(_buf, obj.target_user_native_account_id);
    }

    template<>
    inline gm_structs::EpicLobbySendLobbyNativeInviteRequestedCallbackInfo readValue<gm_structs::EpicLobbySendLobbyNativeInviteRequestedCallbackInfo>(gm::byteio::BufferReader& _buf)
    {
        gm_structs::EpicLobbySendLobbyNativeInviteRequestedCallbackInfo obj;
        obj.lobby_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.local_user_id = gm::wire::codec::readValue<std::string>(_buf);
        obj.target_native_account_type = gm::wire::codec::readValue<std::string>(_buf);
        obj.target_user_native_account_id = gm::wire::codec::readValue<std::string>(_buf);
        return obj;
    }

}

namespace gm::wire::details
{
    template<>
    struct gm_struct_traits<gm_structs::EpicLoggingMessage>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 0;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicAuthLoginCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 1;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicAuthLogoutCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 2;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicAuthLinkAccountCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 3;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicAuthDeletePersistentAuthCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 4;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicAuthIdToken>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 5;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicAuthUserAuthToken>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 6;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicAuthQueryIdTokenCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 7;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicAuthVerifyIdTokenCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 8;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicAuthVerifyUserAuthCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 9;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicAuthLoginStatusChangedCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 10;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicConnectLoginCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 11;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicConnectCreateUserCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 12;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicConnectLinkAccountCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 13;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicConnectUnlinkAccountCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 14;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicConnectCreateDeviceIdCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 15;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicConnectDeleteDeviceIdCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 16;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicConnectTransferDeviceIdAccountCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 17;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicConnectLogoutCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 18;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicConnectIdToken>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 19;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicConnectExternalAccountInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 20;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicConnectVerifyIdTokenCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 21;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicConnectQueryExternalAccountMappingsCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 22;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicConnectQueryProductUserIdMappingsCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 23;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicConnectAuthExpirationCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 24;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicConnectLoginStatusChangedCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 25;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicFriendsQueryFriendsCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 26;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicFriendsFriendsUpdateCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 27;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicUserInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 28;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicUserInfoQueryUserInfoCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 29;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicUserInfoExternalUserInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 30;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicStatsStat>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 31;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicStatsIngestStatCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 32;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicStatsQueryStatsCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 33;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicUIShowFriendsCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 34;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicUIShowNativeProfileCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 35;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicUIDisplaySettingsUpdatedCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 36;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicReportsSendPlayerBehaviorReportCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 37;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicSanctionsPlayerSanction>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 38;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicSanctionsQueryActivePlayerSanctionsCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 39;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicSanctionsCreatePlayerSanctionAppealCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 40;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicAchievementsQueryDefinitionsCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 41;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicAchievementsQueryPlayerAchievementsCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 42;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicAchievementsDefinition>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 43;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicPlayerAchievement>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 44;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicAchievementsUnlockAchievementsCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 45;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicAchievementsDefinitionV2>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 46;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicAchievementsUnlockedV2CallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 47;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLeaderboardsQueryDefinitionsCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 48;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLeaderboardsQueryRanksCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 49;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLeaderboardsQueryUserScoresCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 50;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLeaderboardDefinition>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 51;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLeaderboardRecord>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 52;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLeaderboardUserScore>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 53;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicPresenceInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 54;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicPresenceQueryPresenceCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 55;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicPresenceSetPresenceCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 56;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicPresenceChangedCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 57;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicPresenceJoinGameAcceptedCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 58;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicSessionsUpdateSessionCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 59;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicSessionsDestroySessionCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 60;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicSessionsStartSessionCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 61;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicSessionsEndSessionCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 62;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicSessionsJoinSessionCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 63;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicSessionsRegisterPlayersCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 64;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicSessionsUnregisterPlayersCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 65;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicSessionsFindCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 66;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicSessionDetailsInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 67;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicActiveSessionInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 68;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicSessionsSessionInviteReceivedCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 69;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicSessionsSessionInviteAcceptedCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 70;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicSessionsJoinSessionAcceptedCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 71;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLobbyCreateLobbyCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 72;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLobbyDestroyLobbyCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 73;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLobbyJoinLobbyCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 74;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLobbyLeaveLobbyCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 75;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLobbyUpdateLobbyCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 76;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLobbyPromoteMemberCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 77;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLobbyKickMemberCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 78;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLobbySearchFindCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 79;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLobbyDetailsInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 80;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLobbyLobbyUpdateReceivedCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 81;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLobbyLobbyMemberUpdateReceivedCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 82;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLobbyLobbyMemberStatusReceivedCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 83;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLobbyJoinLobbyAcceptedCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 84;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLobbyLeaveLobbyRequestedCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 85;
    };

    template<>
    struct gm_struct_traits<gm_structs::EpicLobbySendLobbyNativeInviteRequestedCallbackInfo>
    {
        static constexpr bool is_gm_struct = true;
        static constexpr std::uint32_t codec_id = 86;
    };

}

double eos_test();
std::string eos_api_last_error();
bool eos_api_is_initialized();
gm_enums::EpicResult eos_api_initialize(std::string_view product_name, std::string_view product_version);
gm_enums::EpicResult eos_api_shutdown();
std::string eos_api_get_version();
std::string eos_api_result_to_string(gm_enums::EpicResult result);
bool eos_api_result_is_operation_complete(gm_enums::EpicResult result);
std::string eos_api_application_status_to_string(gm_enums::EpicApplicationStatus status);
std::string eos_api_network_status_to_string(gm_enums::EpicNetworkStatus status);
bool eos_api_epic_account_id_is_valid(std::string_view account_id);
bool eos_api_product_user_id_is_valid(std::string_view product_user_id);
bool eos_platform_is_created();
gm_enums::EpicResult eos_platform_create(bool is_server, std::string_view product_id, std::string_view sandbox_id, std::string_view deployment_id, std::string_view client_id, std::string_view client_secret);
void eos_platform_release();
void eos_platform_tick();
gm_enums::EpicResult eos_platform_check_for_launcher_and_restart();
gm_enums::EpicResult eos_platform_set_network_status(gm_enums::EpicNetworkStatus status);
void eos_logging_set_callback(const gm::wire::GMFunction& callback);
void eos_logging_clear_callback();
gm_enums::EpicResult eos_logging_set_log_level(gm_enums::EpicLogCategory log_category, gm_enums::EpicLogLevel log_level);
void eos_auth_login(std::string_view credentials_id, std::string_view credentials_token, gm_enums::EpicLoginCredentialType credentials_type, gm_enums::EpicExternalCredentialType external_credential_type, gm_enums::EpicAuthScopeFlags scope_flags, const gm::wire::GMFunction& callback);
void eos_auth_logout(std::string_view local_user_id, const gm::wire::GMFunction& callback);
void eos_auth_link_account(std::string_view local_user_id, gm_enums::EpicLinkAccountFlags link_account_flags, const gm::wire::GMFunction& callback);
void eos_auth_delete_persistent_auth(const gm::wire::GMFunction& callback);
std::int64_t eos_auth_get_logged_in_accounts_count();
std::string eos_auth_get_logged_in_account_by_index(std::int64_t index);
gm_enums::EpicLoginStatus eos_auth_get_login_status(std::string_view local_user_id);
gm_structs::EpicAuthIdToken eos_auth_copy_id_token(std::string_view local_user_id, std::string_view target_account_id);
gm_structs::EpicAuthUserAuthToken eos_auth_copy_user_auth_token(std::string_view local_user_id);
void eos_auth_query_id_token(std::string_view local_user_id, std::string_view target_account_id, const gm::wire::GMFunction& callback);
void eos_auth_verify_id_token(std::string_view json_web_token, const gm::wire::GMFunction& callback);
void eos_auth_verify_user_auth(std::string_view access_token, const gm::wire::GMFunction& callback);
std::uint64_t eos_auth_add_notify_login_status_changed(const gm::wire::GMFunction& callback);
void eos_auth_remove_notify_login_status_changed(std::uint64_t notification_id);
void eos_connect_login(std::string_view token, gm_enums::EpicExternalCredentialType external_credential_type, std::string_view display_name, const gm::wire::GMFunction& callback);
void eos_connect_create_user(const gm::wire::GMFunction& callback);
void eos_connect_link_account(std::string_view local_user_id, const gm::wire::GMFunction& callback);
void eos_connect_unlink_account(std::string_view local_user_id, const gm::wire::GMFunction& callback);
void eos_connect_create_device_id(std::string_view device_model, const gm::wire::GMFunction& callback);
void eos_connect_delete_device_id(const gm::wire::GMFunction& callback);
void eos_connect_transfer_device_id_account(std::string_view primary_local_user_id, std::string_view local_device_user_id, const gm::wire::GMFunction& callback);
void eos_connect_logout(std::string_view local_user_id, const gm::wire::GMFunction& callback);
std::int64_t eos_connect_get_logged_in_users_count();
std::string eos_connect_get_logged_in_user_by_index(std::int64_t index);
gm_enums::EpicLoginStatus eos_connect_get_login_status(std::string_view local_user_id);
gm_structs::EpicConnectIdToken eos_connect_copy_id_token(std::string_view local_user_id);
gm_structs::EpicConnectExternalAccountInfo eos_connect_copy_product_user_info(std::string_view target_user_id);
gm_structs::EpicConnectExternalAccountInfo eos_connect_copy_product_user_external_account_by_index(std::string_view target_user_id, std::int64_t index);
gm_structs::EpicConnectExternalAccountInfo eos_connect_copy_product_user_external_account_by_account_type(std::string_view target_user_id, gm_enums::EpicExternalAccountType account_id_type);
gm_structs::EpicConnectExternalAccountInfo eos_connect_copy_product_user_external_account_by_account_id(std::string_view target_user_id, std::string_view account_id);
std::string eos_connect_get_product_user_id_mapping(std::string_view local_user_id, gm_enums::EpicExternalAccountType account_id_type, std::string_view target_external_user_id);
std::string eos_connect_get_external_account_mapping(std::string_view local_user_id, gm_enums::EpicExternalAccountType account_id_type, std::string_view target_external_user_id);
void eos_connect_verify_id_token(std::string_view json_web_token, const gm::wire::GMFunction& callback);
void eos_connect_query_external_account_mappings(std::string_view local_user_id, gm_enums::EpicExternalAccountType account_id_type, const std::vector<std::string_view>& target_external_user_ids, const gm::wire::GMFunction& callback);
void eos_connect_query_product_user_id_mappings(std::string_view local_user_id, gm_enums::EpicExternalAccountType account_id_type, const std::vector<std::string_view>& target_product_user_ids, const gm::wire::GMFunction& callback);
std::uint64_t eos_connect_add_notify_auth_expiration(const gm::wire::GMFunction& callback);
void eos_connect_remove_notify_auth_expiration(std::uint64_t notification_id);
std::uint64_t eos_connect_add_notify_login_status_changed(const gm::wire::GMFunction& callback);
void eos_connect_remove_notify_login_status_changed(std::uint64_t notification_id);
void eos_friends_query_friends(std::string_view local_user_id, const gm::wire::GMFunction& callback);
std::int64_t eos_friends_get_friends_count(std::string_view local_user_id);
std::string eos_friends_get_friend_at_index(std::string_view local_user_id, std::int64_t index);
gm_enums::EpicFriendsStatus eos_friends_get_status(std::string_view local_user_id, std::string_view target_user_id);
std::uint64_t eos_friends_add_notify_friends_update(const gm::wire::GMFunction& callback);
void eos_friends_remove_notify_friends_update(std::uint64_t notification_id);
void eos_user_info_query_user_info(std::string_view local_user_id, std::string_view target_user_id, const gm::wire::GMFunction& callback);
gm_structs::EpicUserInfo eos_user_info_copy_user_info(std::string_view local_user_id, std::string_view target_user_id);
gm_enums::EpicExternalAccountType eos_user_info_get_local_platform_type();
std::string eos_user_info_copy_best_display_name(std::string_view local_user_id, std::string_view target_user_id);
gm_structs::EpicUserInfoExternalUserInfo eos_user_info_copy_external_user_info_by_index(std::string_view local_user_id, std::string_view target_user_id, std::int64_t index);
gm_structs::EpicUserInfoExternalUserInfo eos_user_info_copy_external_user_info_by_account_type(std::string_view local_user_id, std::string_view target_user_id, gm_enums::EpicExternalAccountType account_type);
gm_structs::EpicUserInfoExternalUserInfo eos_user_info_copy_external_user_info_by_account_id(std::string_view local_user_id, std::string_view target_user_id, std::string_view account_id);
void eos_stats_ingest_stat(std::string_view local_user_id, std::string_view target_user_id, std::string_view stat_name, std::int64_t ingest_amount, const gm::wire::GMFunction& callback);
void eos_stats_query_stats(std::string_view local_user_id, std::string_view target_user_id, std::int64_t start_time, std::int64_t end_time, const gm::wire::GMFunction& callback);
std::int64_t eos_stats_get_stats_count(std::string_view target_user_id);
gm_structs::EpicStatsStat eos_stats_copy_stat_by_index(std::string_view target_user_id, std::int64_t index);
gm_structs::EpicStatsStat eos_stats_copy_stat_by_name(std::string_view target_user_id, std::string_view name);
void eos_ui_show_friends(std::string_view local_user_id, const gm::wire::GMFunction& callback);
void eos_ui_show_native_profile(std::string_view local_user_id, std::string_view target_user_id, const gm::wire::GMFunction& callback);
void eos_ui_acknowledge_event_id(std::uint64_t ui_event_id);
void eos_ui_set_display_preference(gm_enums::EpicUINotificationLocation notification_location);
void eos_ui_report_input_state(bool button_down, bool button_up, bool button_left, bool button_right, bool button_accept, bool button_cancel);
std::uint64_t eos_ui_add_notify_display_settings_updated(const gm::wire::GMFunction& callback);
void eos_ui_remove_notify_display_settings_updated(std::uint64_t notification_id);
gm_enums::EpicResult eos_metrics_begin_player_session(std::string_view product_user_id, gm_enums::EpicMetricsAccountIdType account_id_type, gm_enums::EpicUserControllerType controller_type, std::string_view server_ip, std::string_view game_session_id);
gm_enums::EpicResult eos_metrics_end_player_session(std::string_view product_user_id, gm_enums::EpicMetricsAccountIdType account_id_type, gm_enums::EpicUserControllerType controller_type, std::string_view server_ip, std::string_view game_session_id);
void eos_reports_send_player_behavior_report(std::string_view reporter_user_id, std::string_view reported_user_id, gm_enums::EpicPlayerReportsCategory category, std::string_view message, std::string_view context, const gm::wire::GMFunction& callback);
void eos_sanctions_query_active_player_sanctions(std::string_view target_user_id, const gm::wire::GMFunction& callback);
std::int64_t eos_sanctions_get_player_sanction_count(std::string_view target_user_id);
gm_structs::EpicSanctionsPlayerSanction eos_sanctions_copy_player_sanction_by_index(std::string_view target_user_id, std::int64_t index);
void eos_sanctions_create_player_sanction_appeal(std::string_view local_user_id, std::string_view reference_id, gm_enums::EpicSanctionAppealReason reason, const gm::wire::GMFunction& callback);
void eos_achievements_query_definitions(std::string_view local_user_id, const gm::wire::GMFunction& callback);
void eos_achievements_query_player_achievements(std::string_view local_user_id, std::string_view target_user_id, const gm::wire::GMFunction& callback);
std::int64_t eos_achievements_get_achievement_definition_count();
std::int64_t eos_achievements_get_player_achievement_count(std::string_view local_user_id, std::string_view target_user_id);
gm_structs::EpicAchievementsDefinition eos_achievements_copy_achievement_definition_by_index(std::int64_t index);
gm_structs::EpicAchievementsDefinitionV2 eos_achievements_copy_achievement_definition_v2_by_index(std::int64_t index);
gm_structs::EpicAchievementsDefinition eos_achievements_copy_achievement_definition_by_id(std::string_view achievement_id);
gm_structs::EpicPlayerAchievement eos_achievements_copy_player_achievement_by_index(std::string_view local_user_id, std::string_view target_user_id, std::int64_t index);
gm_structs::EpicPlayerAchievement eos_achievements_copy_player_achievement_by_id(std::string_view local_user_id, std::string_view target_user_id, std::string_view achievement_id);
void eos_achievements_unlock_achievements(std::string_view user_id, const std::vector<std::string_view>& achievement_ids, const gm::wire::GMFunction& callback);
std::uint64_t eos_achievements_add_notify_achievements_unlocked_v2(const gm::wire::GMFunction& callback);
void eos_achievements_remove_notify_achievements_unlocked(std::uint64_t notification_id);
void eos_leaderboards_query_definitions(std::string_view local_user_id, std::int64_t start_time, std::int64_t end_time, const gm::wire::GMFunction& callback);
void eos_leaderboards_query_ranks(std::string_view local_user_id, std::string_view leaderboard_id, const gm::wire::GMFunction& callback);
void eos_leaderboards_query_user_scores(std::string_view local_user_id, std::string_view stat_name, const gm::wire::GMFunction& callback);
std::int64_t eos_leaderboards_get_definition_count();
std::int64_t eos_leaderboards_get_record_count();
std::int64_t eos_leaderboards_get_user_score_count();
gm_structs::EpicLeaderboardDefinition eos_leaderboards_copy_definition_by_index(std::int64_t index);
gm_structs::EpicLeaderboardDefinition eos_leaderboards_copy_definition_by_id(std::string_view leaderboard_id);
gm_structs::EpicLeaderboardRecord eos_leaderboards_copy_record_by_index(std::int64_t index);
gm_structs::EpicLeaderboardRecord eos_leaderboards_copy_record_by_user_id(std::string_view user_id);
gm_structs::EpicLeaderboardUserScore eos_leaderboards_copy_user_score_by_index(std::int64_t index);
void eos_presence_query_presence(std::string_view local_user_id, std::string_view target_user_id, const gm::wire::GMFunction& callback);
bool eos_presence_has_presence(std::string_view local_user_id, std::string_view target_user_id);
gm_structs::EpicPresenceInfo eos_presence_copy_presence(std::string_view local_user_id, std::string_view target_user_id);
std::uint64_t eos_presence_create_presence_modification(std::string_view local_user_id);
void eos_presence_modification_release(std::uint64_t modification_id);
gm_enums::EpicResult eos_presence_modification_set_status(std::uint64_t modification_id, gm_enums::EpicPresenceStatus status);
gm_enums::EpicResult eos_presence_modification_set_raw_rich_text(std::uint64_t modification_id, std::string_view rich_text);
gm_enums::EpicResult eos_presence_modification_set_data(std::uint64_t modification_id, std::string_view key, std::string_view value);
gm_enums::EpicResult eos_presence_modification_delete_data(std::uint64_t modification_id, std::string_view key);
void eos_presence_set_presence(std::string_view local_user_id, std::uint64_t modification_id, const gm::wire::GMFunction& callback);
std::uint64_t eos_presence_add_notify_on_presence_changed(const gm::wire::GMFunction& callback);
void eos_presence_remove_notify_on_presence_changed(std::uint64_t notification_id);
std::uint64_t eos_presence_add_notify_join_game_accepted(const gm::wire::GMFunction& callback);
void eos_presence_remove_notify_join_game_accepted(std::uint64_t notification_id);
std::uint64_t eos_sessions_create_session_modification(std::string_view session_name, std::string_view session_id, std::string_view bucket_id, std::int64_t max_players, std::string_view local_user_id, bool presence_enabled, bool sanctions_enabled, const std::vector<std::uint32_t>& allowed_platform_ids);
void eos_sessions_session_modification_release(std::uint64_t modification_id);
void eos_sessions_update_session(std::uint64_t modification_id, const gm::wire::GMFunction& callback);
void eos_sessions_destroy_session(std::string_view session_name, const gm::wire::GMFunction& callback);
void eos_sessions_start_session(std::string_view session_name, const gm::wire::GMFunction& callback);
void eos_sessions_end_session(std::string_view session_name, const gm::wire::GMFunction& callback);
void eos_sessions_join_session(std::string_view session_name, std::string_view local_user_id, const gm::wire::GMFunction& callback);
void eos_sessions_register_players(std::string_view session_name, const std::vector<std::string_view>& target_user_ids, const gm::wire::GMFunction& callback);
void eos_sessions_unregister_players(std::string_view session_name, const std::vector<std::string_view>& target_user_ids, const gm::wire::GMFunction& callback);
std::uint64_t eos_sessions_create_session_search(std::int64_t max_search_results);
void eos_sessions_session_search_release(std::uint64_t search_id);
gm_enums::EpicResult eos_sessions_session_search_set_session_id(std::uint64_t search_id, std::string_view session_id);
gm_enums::EpicResult eos_sessions_session_search_set_target_user_id(std::uint64_t search_id, std::string_view target_user_id);
void eos_sessions_session_search_find(std::uint64_t search_id, std::string_view local_user_id, const gm::wire::GMFunction& callback);
std::uint64_t eos_sessions_session_search_copy_search_result_by_index(std::uint64_t search_id, std::int64_t index);
void eos_sessions_session_details_release(std::uint64_t session_details_id);
std::uint64_t eos_sessions_copy_active_session_handle(std::string_view session_name);
void eos_sessions_active_session_release(std::uint64_t active_session_id);
gm_structs::EpicActiveSessionInfo eos_sessions_active_session_copy_info(std::uint64_t active_session_id);
std::uint64_t eos_sessions_copy_session_handle_by_invite_id(std::string_view invite_id);
std::uint64_t eos_sessions_copy_session_handle_by_ui_event_id(std::uint64_t ui_event_id);
gm_structs::EpicSessionDetailsInfo eos_sessions_session_details_copy_info(std::uint64_t session_details_id);
std::uint64_t eos_sessions_add_notify_session_invite_received(const gm::wire::GMFunction& callback);
void eos_sessions_remove_notify_session_invite_received(std::uint64_t notification_id);
std::uint64_t eos_sessions_add_notify_session_invite_accepted(const gm::wire::GMFunction& callback);
void eos_sessions_remove_notify_session_invite_accepted(std::uint64_t notification_id);
std::uint64_t eos_sessions_add_notify_join_session_accepted(const gm::wire::GMFunction& callback);
void eos_sessions_remove_notify_join_session_accepted(std::uint64_t notification_id);
void eos_lobby_create_lobby(std::string_view local_user_id, std::int64_t max_lobby_members, gm_enums::EpicLobbyPermissionLevel permission_level, bool presence_enabled, bool allow_invites, std::string_view bucket_id, const gm::wire::GMFunction& callback);
void eos_lobby_destroy_lobby(std::string_view lobby_id, std::string_view local_user_id, const gm::wire::GMFunction& callback);
void eos_lobby_join_lobby(std::string_view lobby_id, std::string_view local_user_id, bool presence_enabled, const gm::wire::GMFunction& callback);
void eos_lobby_leave_lobby(std::string_view lobby_id, std::string_view local_user_id, const gm::wire::GMFunction& callback);
std::uint64_t eos_lobby_update_lobby_modification(std::string_view lobby_id, std::string_view local_user_id);
void eos_lobby_lobby_modification_release(std::uint64_t modification_id);
void eos_lobby_update_lobby(std::string_view lobby_id, std::uint64_t modification_id, const gm::wire::GMFunction& callback);
gm_enums::EpicResult eos_lobby_lobby_modification_set_permission_level(std::uint64_t modification_id, gm_enums::EpicLobbyPermissionLevel permission_level);
gm_enums::EpicResult eos_lobby_lobby_modification_set_max_members(std::uint64_t modification_id, std::int64_t max_members);
gm_enums::EpicResult eos_lobby_lobby_modification_set_bucket_id(std::uint64_t modification_id, std::string_view bucket_id);
gm_enums::EpicResult eos_lobby_lobby_modification_set_invites_allowed(std::uint64_t modification_id, bool invites_allowed);
gm_enums::EpicResult eos_lobby_lobby_modification_add_attribute(std::uint64_t modification_id, std::string_view key, std::string_view value, gm_enums::EpicLobbyAttributeVisibility visibility);
gm_enums::EpicResult eos_lobby_lobby_modification_remove_attribute(std::uint64_t modification_id, std::string_view key);
gm_enums::EpicResult eos_lobby_lobby_modification_add_member_attribute(std::uint64_t modification_id, std::string_view key, std::string_view value, gm_enums::EpicLobbyAttributeVisibility visibility);
gm_enums::EpicResult eos_lobby_lobby_modification_remove_member_attribute(std::uint64_t modification_id, std::string_view key);
void eos_lobby_promote_member(std::string_view lobby_id, std::string_view local_user_id, std::string_view target_user_id, const gm::wire::GMFunction& callback);
void eos_lobby_kick_member(std::string_view lobby_id, std::string_view local_user_id, std::string_view target_user_id, const gm::wire::GMFunction& callback);
std::uint64_t eos_lobby_create_lobby_search(std::int64_t max_results);
void eos_lobby_lobby_search_release(std::uint64_t search_id);
gm_enums::EpicResult eos_lobby_lobby_search_set_lobby_id(std::uint64_t search_id, std::string_view lobby_id);
gm_enums::EpicResult eos_lobby_lobby_search_set_target_user_id(std::uint64_t search_id, std::string_view target_user_id);
gm_enums::EpicResult eos_lobby_lobby_search_set_parameter(std::uint64_t search_id, std::string_view key, std::string_view value, gm_enums::EpicComparisonOp comparison_op);
gm_enums::EpicResult eos_lobby_lobby_search_remove_parameter(std::uint64_t search_id, std::string_view key, gm_enums::EpicComparisonOp comparison_op);
gm_enums::EpicResult eos_lobby_lobby_search_set_max_results(std::uint64_t search_id, std::int64_t max_results);
void eos_lobby_lobby_search_find(std::uint64_t search_id, std::string_view local_user_id, const gm::wire::GMFunction& callback);
std::int64_t eos_lobby_lobby_search_get_search_result_count(std::uint64_t search_id);
std::uint64_t eos_lobby_lobby_search_copy_search_result_by_index(std::uint64_t search_id, std::int64_t index);
void eos_lobby_details_release(std::uint64_t lobby_details_id);
std::uint64_t eos_lobby_copy_lobby_details_handle(std::string_view lobby_id, std::string_view local_user_id);
gm_structs::EpicLobbyDetailsInfo eos_lobby_details_copy_info(std::uint64_t lobby_details_id);
std::int64_t eos_lobby_details_get_member_count(std::uint64_t lobby_details_id);
std::string eos_lobby_details_get_member_by_index(std::uint64_t lobby_details_id, std::int64_t index);
std::string eos_lobby_details_get_lobby_owner(std::uint64_t lobby_details_id);
std::uint64_t eos_lobby_add_notify_lobby_update_received(std::string_view local_user_id, const gm::wire::GMFunction& callback);
void eos_lobby_remove_notify_lobby_update_received(std::uint64_t notification_id);
std::uint64_t eos_lobby_add_notify_lobby_member_update_received(std::string_view local_user_id, const gm::wire::GMFunction& callback);
void eos_lobby_remove_notify_lobby_member_update_received(std::uint64_t notification_id);
std::uint64_t eos_lobby_add_notify_lobby_member_status_received(std::string_view local_user_id, const gm::wire::GMFunction& callback);
void eos_lobby_remove_notify_lobby_member_status_received(std::uint64_t notification_id);
std::uint64_t eos_lobby_add_notify_join_lobby_accepted(const gm::wire::GMFunction& callback);
void eos_lobby_remove_notify_join_lobby_accepted(std::uint64_t notification_id);
std::uint64_t eos_lobby_add_notify_leave_lobby_requested(std::string_view local_user_id, const gm::wire::GMFunction& callback);
void eos_lobby_remove_notify_leave_lobby_requested(std::uint64_t notification_id);
std::uint64_t eos_lobby_add_notify_send_lobby_native_invite_requested(std::string_view local_user_id, const gm::wire::GMFunction& callback);
void eos_lobby_remove_notify_send_lobby_native_invite_requested(std::uint64_t notification_id);
