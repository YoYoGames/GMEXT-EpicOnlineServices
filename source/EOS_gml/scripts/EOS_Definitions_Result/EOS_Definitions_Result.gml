// Copyright Epic Games = Inc. All Rights Reserved.

// This file is not intended to be included directly. Include eos_common.h instead.

enum EOS_RESULT
{
    /** Successful result. no further error processing needed */
    SUCCESS = 0,
    
    /** Failed due to no connection */
    NO_CONNECTION = 1,
    /** Failed login due to invalid credentials */
    INVALID_CREDENTIALS = 2,
    /** Failed due to invalid or missing user */
    INVALID_USER = 3,
    /** Failed due to invalid or missing authentication token for user (e.g. not logged in, */
    INVALID_AUTH = 4,
    /** Failed due to invalid access */
    ACCESS_DENIED = 5,
    /** If the client does not possess the permission required */
    MISSING_PERMISSIONS = 6,
    /** If the token provided does not represent an account */
    TOKEN_NOT_ACCOUNT = 7,
    /** Throttled due to too many requests */
    TOO_MANY_REQUESTS = 8,
    /** Async request was already pending */
    ALREADY_PENDING = 9,
    /** Invalid parameters specified for request */
    INVALID_PARAMETERS = 10,
    /** Invalid request */
    INVALID_REQUEST = 11,
    /** Failed due to unable to parse or recognize a backend response */
    UNRECOGNIZED_RESPONSE = 12,
    /** Incompatible client for backend version */
    INCOMPATIBLE_VERSION = 13,
    /** Not configured correctly for use */
    NOT_CONFIGURED = 14,
    /** Already configured for use. */
    ALREADY_CONFIGURED = 15,
    /** Feature not available on this implementation */
    NOT_IMPLEMENTED = 16,
    /** Operation was canceled (likely by user, */
    CANCELED = 17,
    /** The requested information was not found */
    NOT_FOUND = 18,
    /** An error occurred during an asynchronous operation = and it will be retried. Callbacks receiving this result will be called again in the future. */
    OPERATION_WILL_RETRY = 19,
    /** The request had no effect */
    NO_CHANGE = 20,
    /** The request attempted to use multiple or inconsistent API versions */
    VERSION_MISMATCH = 21,
    /** A maximum limit was exceeded on the client = different from EOS_TooManyRequests */
    LIMIT_EXCEEDED = 22,
    /** Feature or client ID performing the operation has been disabled. */
    DISABLED = 23,
    /** Duplicate entry not allowed */
    DUPLICATE_NOT_ALLOWED = 24,
    /** Required parameters are missing. DEPRECATED: This error is no longer used. */
    MISSING_PARAMETERS_DEPRECATED = 25,
    /** Sandbox ID is invalid */
    INVALID_SANDBOX_ID = 26,
    /** Request timed out */
    TIMED_OUT = 27,
    /** A query returned some but not all of the requested results. */
    PARTIAL_RESULT = 28,
    /** Client is missing the whitelisted role */
    MISSING_ROLE = 29,
    /** Client is missing the whitelisted feature */
    MISSING_FEATURE = 30,
    /** The sandbox given to the backend is invalid */
    INVALID_SANDBOX = 31,
    /** The deployment given to the backend is invalid */
    INVALID_DEPLOYMENT = 32,
    /** The product ID specified to the backend is invalid */
    INVALID_PRODUCT = 33,
    /** The product user ID specified to the backend is invalid */
    INVALID_PRODUCT_USER_ID = 34,
    /** There was a failure with the backend service */
    SERVICE_FAILURE = 35,
    /** Cache directory is not set in platform options. */
    CACHE_DIRECTORY_MISSING = 36,
    /** Cache directory is not accessible. */
    CACHE_DIRECTORY_INVALID = 37,
    /** The request failed because resource was in an invalid state */
    INVALID_STATE = 38,
    /** Request is in progress */
    REQUEST_IN_PROGRESS = 39,
    /** Application is suspended */
    APPLICATION_SUSPENDED = 40,
    /** Network is disconnected */
    NETWORKD_IS_CONNECTED = 41,
    
    /** Account locked due to login failures */
    AUTH_ACCOUNT_LOCKED = 1001,
    /** Account locked by update operation. */
    AUTH_ACCOUNT_LOCKED_FOR_UPDATE = 1002,
    /** Refresh token used was invalid */
    AUTH_INVALID_REFRESH_TOKEN = 1003,
    /** Invalid access token = typically when switching between backend environments */
    AUTH_INVALID_TOKEN = 1004,
    /** Invalid bearer token */
    AUTH_AUTHENTICATION_FAILURE = 1005,
    /** Invalid platform token */
    AUTH_INVALID_PLATFORM_TOKEN = 1006,
    /** Auth parameters are not associated with this account */
    AUTH_WRON_GACCOUNT = 1007,
    /** Auth parameters are not associated with this client */
    AUTH_WRONG_CLIENT = 1008,
    /** Full account is required */
    AUTH_FULL_ACCOUNT_REQUIRED = 1009,
    /** Headless account is required */
    AUTH_HEADLESS_ACCOUNT_REQUIRED = 1010,
    /** Password reset is required */
    AUTH_PASSWORD_RESET_REQUIRED = 1011,
    /** Password was previously used and cannot be reused */
    AUTH_PASSWORD_CANNOT_BE_REUSED = 1012,
    /** Authorization code/exchange code has expired */
    AUTH_EXPIRED = 1013,
    /** Consent has not been given by the user */
    AUTH_SCOPE_CONSENT_REQUIRED = 1014,
    /** The application has no profile on the backend */
    AUTH_APPLICATION_NOT_FOUND = 1015,
    /** The requested consent wasn't found on the backend */
    AUTH_SCOPE_NOT_FOUND = 1016,
    /** This account has been denied access to login */
    AUTH_ACCOUNT_FEATURE_RESTRICTED = 1017,
    /** The overlay failed to load the Account Portal. This can range from general overlay failure = to overlay failed to connect to the web server = to overlay failed to render the web page. */
    AUTH_ACCOUNT_PORTAL_LOAD_ERROR = 1018,
    /** An attempted login has failed due to the user needing to take corrective action on their account. */
    AUTH_CORRECTIVEACTION_REQUIRED = 1019,
    
    /** Pin grant code initiated */
    AUTH_PIN_GRANT_CODE = 1020,
    /** Pin grant code attempt expired */
    AUTH_PIN_GRANT_EXPIRED = 1021,
    /** Pin grant code attempt pending */
    AUTH_PIN_GRANT_PENDING = 1022,
    
    /** External auth source did not yield an account */
    AUTH_EXTERNAL_AUTH_NOT_LINKED = 1030,
    /** External auth access revoked */
    AUTH_EXTERNAL_AUTH_REVOKED = 1032,
    /** External auth token cannot be interpreted */
    AUTH_EXTERNAL_AUTH_INVALID = 1033,
    /** External auth cannot be linked to his account due to restrictions */
    AUTH_EXTERNAL_AUTH_RESTRICTED = 1034,
    /** External auth cannot be used for login */
    AUTH_EXTERNAL_AUTH_CANNOT_LOGIN = 1035,
    /** External auth is expired */
    AUTH_EXTERNAL_AUTH_EXPIRED = 1036,
    /** External auth cannot be removed since it's the last possible way to login */
    AUTH_EXTERNAL_AUTH_IS_LAST_LOGIN_TYPE = 1037,
    
    /** Exchange code not found */
    AUTH_EXCHANGE_CODE_NOT_FOUND = 1040,
    /** Originating exchange code session has expired */
    AUTH_ORIGINATING_EXCHANGE_CODE_SESSION_EXPIRED = 1041,
    
    /** The account has been disabled and cannot be used for authentication */
    AUTH_ACCOUNT_NOT_ACTIVE = 1050,
    
    /** MFA challenge required */
    AUTH_MFA_REQUIRED = 1060,
    
    /** Parental locks are in place */
    AUTH_PARENTAL_CONTROLS = 1070,
    
    /** Korea real ID association required but missing */
    AUTH_NO_REAL_ID = 1080,
    
    /** Silent login failed when EOS_LF_NO_USER_INTERFACE was specified = and user interaction is needed before the user can be logged in. */
    AUTH_USER_INTERFACE_REQUIRED = 1090,
    
    /** An outgoing friend invitation is awaiting acceptance; sending another invite to the same user is erroneous */
    FRIENDS_INVITE_AWAITING_ACCEPTANCE = 2000,
    /** There is no friend invitation to accept/reject */
    FRIENDS_NO_INVITATION = 2001,
    /** Users are already friends = so sending another invite is erroneous */
    FRIENDS_ALREADY_FRIENDS = 2003,
    /** Users are not friends = so deleting the friend is erroneous */
    FRIENDS_NOT_FRIENDS = 2004,
    /** Remote user has too many invites to receive new invites */
    FRIENDS_TARGET_USER_TOO_MANY_INVITES = 2005,
    /** Local user has too many invites to send new invites */
    FRIENDS_LOCAL_USER_TOO_MANY_INVITES = 2006,
    /** Remote user has too many friends to make a new friendship */
    FRIENDS_TARGET_USER_FRIEND_LIMIT_EXCEEDED = 2007,
    /** Local user has too many friends to make a new friendship */
    FRIENDS_LOCAL_USER_FRIEND_LIMIT_EXCEEDED = 2008,
    
    /** Request data was null or invalid */
    PRESENCE_DATA_INVALID = 3000,
    /** Request contained too many or too few unique data items = or the request would overflow the maximum amount of data allowed */
    PRESENCE_DATA_LENGTH_INVALID = 3001,
    /** Request contained data with an invalid key */
    PRESENCE_DATA_KEY_INVALID = 3002,
    /** Request contained data with a key too long or too short */
    PRESENCE_DATA_KEY_LENGTH_IN_VALID = 3003,
    /** Request contained data with an invalid value */
    PRESENCE_DATA_VALUE_INVALID = 3004,
    /** Request contained data with a value too long */
    PRESENCE_DATA_VALUE_LENGTH_INVALID = 3005,
    /** Request contained an invalid rich text string */
    PRESENCE_RICH_TEXT_INVALID = 3006,
    /** Request contained a rich text string that was too long */
    PRESENCE_RICH_TEXT_LENGTH_INVALID = 3007,
    /** Request contained an invalid status state */
    PRESENCE_STATUS_INVALID = 3008,
    
    /** The entitlement retrieved is stale = requery for updated information */
    ECOM_ENTITLEMENT_STALE = 4000,
    /** The offer retrieved is stale = requery for updated information */
    ECOM_CATALOG_OFFER_STALE = 4001,
    /** The item or associated structure retrieved is stale = requery for updated information */
    ECOM_CATALOG_ITEM_STALE = 4002,
    /** The one or more offers has an invalid price. This may be caused by the price setup. */
    ECOM_CATALOG_OFFER_PRICE_INVALID = 4003,
    /** The checkout page failed to load */
    ECOM_CHECKOUT_LOAD_ERROR = 4004,
    /** The player closed the purchase flow overlay after clicking the purchase button. The purchase may still go through = and the game needs to query unredeemed entitlements for a short time. */
    ECOM_PURCHASE_PROCESSING = 4005,
    
    /** Session is already in progress */
    SESSIONS_SESSION_IN_PROGRESS = 5000,
    /** Too many players to register with this session */
    SESSIONS_TOO_MANY_PLAYERS = 5001,
    /** Client has no permissions to access this session */
    SESSIONS_NO_PERMISSION = 5002,
    /** Session already exists in the system */
    SESSIONS_SESSION_ALREADY_EXISTS = 5003,
    /** Session lock required for operation */
    SESSIONS_INVALID_LOCK = 5004,
    /** Invalid session reference */
    SESSIONS_INVALID_SESSION = 5005,
    /** Sandbox ID associated with auth didn't match */
    SESSIONS_SANDBOX_NOT_ALLOWED = 5006,
    /** Invite failed to send */
    SESSIONS_INVITE_FAILED = 5007,
    /** Invite was not found with the service */
    SESSIONS_INVITE_NOT_FOUND = 5008,
    /** This client may not modify the session */
    SESSIONS_UPSERT_NOT_ALLOWED = 5009,
    /** Backend nodes unavailable to process request */
    SESSIONS_AGGREGATION_FAILED = 5010,
    /** Individual backend node is as capacity */
    SESSIONS_HOST_AT_CAPACITY = 5011,
    /** Sandbox on node is at capacity */
    SESSIONS_SANDBOX_AT_CAPACITY = 5012,
    /** An anonymous operation was attempted on a non anonymous session */
    SESSIONS_SESSION_NOT_ANONYMOUS = 5013,
    /** Session is currently out of sync with the backend = data is saved locally but needs to sync with backend */
    SESSIONS_OUT_OF_SYNC = 5014,
    /** User has received too many invites */
    SESSIONS_TOO_MANY_INVITES = 5015,
    /** Presence session already exists for the client */
    SESSIONS_PRESENCE_SESSION_EXISTS = 5016,
    /** Deployment on node is at capacity */
    SESSIONS_DEPLOYMENTAT_CAPACITY = 5017,
    /** Session operation not allowed */
    SESSIONS_NOT_ALLOWED = 5018,
    /** Session operation not allowed */
    SESSIONS_PLAYER_SANCTIONED = 5019,
    
    /** Request filename was invalid */
    PLAYER_DATA_STORAGE_FILENAME_INVALID = 6000,
    /** Request filename was too long */
    PLAYER_DATA_STORAGE_FILENAME_LENGTH_INVALID = 6001,
    /** Request filename contained invalid characters */
    PLAYER_DATA_STORAGE_FILENAME_INVALID_CHARS = 6002,
    /** Request operation would grow file too large */
    PLAYER_DATA_STORAGE_FILESIZE_TOO_LARGE = 6003,
    /** Request file length is not valid */
    PLAYER_DATA_STORAGE_FILE_SIZE_INVALID = 6004,
    /** Request file handle is not valid */
    PLAYER_DATA_STORAGE_FILE_HANDLE_INVALID = 6005,
    /** Request data is invalid */
    PLAYER_DATA_STORAGE_DATA_INVALID = 6006,
    /** Request data length was invalid */
    PLAYER_DATA_STORAGE_DATA_LENGTH_INVALID = 6007,
    /** Request start index was invalid */
    PLAYER_DATA_STORAGE_START_INDEX_INVALID = 6008,
    /** Request is in progress */
    PLAYER_DATA_STORAGE_REQUEST_IN_PROGRESS = 6009,
    /** User is marked as throttled which means he can't perform some operations because limits are exceeded. */
    PLAYER_DATA_STORAGE_USER_THROTTLED = 6010,
    /** Encryption key is not set during SDK init. */
    PLAYER_DATA_STORAGE_ENCRYPTION_KEY_NOT_SET = 6011,
    /** User data callback returned error (EOS_PlayerDataStorage_EWriteResult::EOS_WR_FailRequest or EOS_PlayerDataStorage_EReadResult::EOS_RR_FailRequest, */
    PLAYER_DATA_STORAGE_USER_ERROR_FROM_DATA_CALLBACK = 6012,
    /** User is trying to read file that has header from newer version of SDK. Game/SDK needs to be updated. */
    PLAYER_DATA_STORAGE_FILE_HEADER_HAS_NEWER_VERSION = 6013,
    /** The file is corrupted. In some cases retry can fix the issue. */
    PLAYER_DATA_STORAGE_FILECORRUPTED = 6014,
    
    /** EOS Auth service deemed the external token invalid */
    CONNECT_EXTERNAL_TOKEN_VALIDATION_FAILED = 7000,
    /** EOS Auth user already exists */
    CONNECT_USER_ALREADY_EXISTS = 7001,
    /** EOS Auth expired */
    CONNECT_AUTH_EXPIRED = 7002,
    /** EOS Auth invalid token */
    CONNECT_INVALID_TOKEN = 7003,
    /** EOS Auth doesn't support this token type */
    CONNECT_UNSUPPORTED_TOKEN_TYPE = 7004,
    /** EOS Auth Account link failure */
    CONNECT_LINK_ACCOUNT_FAILED = 7005,
    /** EOS Auth External service for validation was unavailable */
    CONNECT_EXTERNAL_SERVICE_UNAVAILABLE = 7006,
    /** EOS Auth External Service configuration failure with Dev Portal */
    CONNECT_EXTERNAL_SERVICE_CONFIGURATION_FAILURE = 7007,
    /** EOS Auth Account link failure. Tried to link Nintendo Network Service Account without first linking Nintendo Account. DEPRECATED: The requirement has been removed and this error is no longer used. */
    CONNECT_LINK_ACCOUNT_FAILED_MISSING_NINTENDO_ID_ACCOUNT_DEPRECATED = 7008,
    
    /** The social overlay page failed to load */
    UI_SOCIAL_OVERLAY_LOAD_ERROR = 8000,
    /** Virtual Memory Functions are an inconsistent mix of functions and nullptrs */
    UI_INCONSISTENT_VIRTUAL_MEMORY_FUNCTIONS = 8001,
    
    /** Client has no permissions to modify this lobby */
    LOBBY_NOT_OWNER = 9000,
    /** Lobby lock required for operation */
    LOBBY_INVALID_LOCK = 9001,
    /** Lobby already exists in the system */
    LOBBY_LOBBY_ALREADY_EXISTS = 9002,
    /** Lobby is already in progress */
    LOBBY_SESSION_IN_PROGRESS = 9003,
    /** Too many players to register with this lobby */
    LOBBY_TOO_MANY_PLAYERS = 9004,
    /** Client has no permissions to access this lobby */
    LOBBY_NO_PERMISSION = 9005,
    /** Invalid lobby session reference */
    LOBBY_INVALID_SESSION = 9006,
    /** Sandbox ID associated with auth didn't match */
    LOBBY_SANDBOX_NOT_ALLOWED = 9007,
    /** Invite failed to send */
    LOBBY_INVITE_FAILED = 9008,
    /** Invite was not found with the service */
    LOBBY_INVITE_NOT_FOUND = 9009,
    /** This client may not modify the lobby */
    LOBBY_UPSERT_NOT_ALLOWED = 9010,
    /** Backend nodes unavailable to process request */
    LOBBY_AGGREGATION_FAILED = 9011,
    /** Individual backend node is as capacity */
    LOBBY_HOST_AT_CAPACITY = 9012,
    /** Sandbox on node is at capacity */
    LOBBY_SANDBOX_AT_CAPACITY = 9013,
    /** User has received too many invites */
    LOBBY_TOO_MANY_INVITES = 9014,
    /** Deployment on node is at capacity */
    LOBBY_DEPLOYMENT_AT_CAPACITY = 9015,
    /** Lobby operation not allowed */
    LOBBY_NOT_ALLOWED = 9016,
    /** While restoring a lost connection lobby ownership changed and only local member data was updated */
    LOBBY_MEMBER_UPDATE_ONLY = 9017,
    /** Presence lobby already exists for the client */
    LOBBY_PRESENCE_LOBBY_EXISTS = 9018,
    /** Operation requires lobby with voice enabled */
    LOBBY_VOICE_NOT_ENABLED = 9019,
    /** The client platform does not match the allowed platform list for the lobby. */
    LOBBY_PLATFORM_NOT_ALLOWED = 9020,
    
    /** User callback that receives data from storage returned error. */
    TITLE_STORAGE_USER_ERROR_FROM_DATA_CALLBACK = 10000,
    /** User forgot to set Encryption key during platform init. Title Storage can't work without it. */
    TITLE_STORAGE_ENCRYPTION_KEY_NOT_SET = 10001,
    /** Downloaded file is corrupted. */
    TITLE_STORAGE_FILE_CORRUPTED = 10002,
    /** Downloaded file's format is newer than client SDK version. */
    TITLE_STORAGE_FILE_HEADER_HAS_NEWER_VERSION = 10003,
    
    /** ModSdk process is already running. This error comes from the EOSSDK. */
    MODS_MOD_SDK_PROCESS_IS_ALREADY_RUNNING = 11000,
    /** ModSdk command is empty. Either the ModSdk configuration file is missing or the manifest location is empty. */
    MODS_MOD_SDK_COMMAND_IS_EMPTY = 11001,
    /** Creation of the ModSdk process failed. This error comes from the SDK. */
    MODS_MOD_SDK_PROCESS_CREATION_FAILED = 11002,
    /** A critical error occurred in the external ModSdk process that we were unable to resolve. */
    MODS_CRITICAL_ERROR = 11003,
    /** A internal error occurred in the external ModSdk process that we were unable to resolve. */
    MODS_TOOL_INTERNAL_ERROR = 11004,
    /** A IPC failure occurred in the external ModSdk process. */
    MODS_IPC_FAILURE = 11005,
    /** A invalid IPC response received in the external ModSdk process. */
    MODS_INVALID_IPC_RESPONSE = 11006,
    /** A URI Launch failure occurred in the external ModSdk process. */
    MODS_URI_LAUNCH_FAILURE = 11007,
    /** Attempting to perform an action with a mod that is not installed. This error comes from the external ModSdk process. */
    MODS_MOD_IS_NOT_INSTALLED = 11008,
    /** Attempting to perform an action on a game that the user doesn't own. This error comes from the external ModSdk process. */
    MODS_USER_DOES_NOT_OWN_THE_GAME = 11009,
    /** Invalid result of the request to get the offer for the mod. This error comes from the external ModSdk process. */
    MODS_OFFER_REQUEST_BY_ID_INVALID_RESULT = 11010,
    /** Could not find the offer for the mod. This error comes from the external ModSdk process. */
    MODS_COULD_NOT_FIND_OFFER = 11011,
    /** Request to get the offer for the mod failed. This error comes from the external ModSdk process. */
    MODS_OFFER_REQUEST_BY_ID_FAILURE = 11012,
    /** Request to purchase the mod failed. This error comes from the external ModSdk process. */
    MODS_PURCHASE_FAILURE = 11013,
    /** Attempting to perform an action on a game that is not installed or is partially installed. This error comes from the external ModSdk process. */
    MODS_INVALID_GAME_INSTALL_INFO = 11014,
    /** Failed to get manifest location. Either the ModSdk configuration file is missing or the manifest location is empty */
    MODS_CANNOT_GET_MANIFEST_LOCATION = 11015,
    /** Attempting to perform an action with a mod that does not support the current operating system. */
    MODS_UNSUPPORTED_OS = 11016,
    
    /** The anti-cheat client protection is not available. Check that the game was started using the anti-cheat bootstrapper. */
    ANTICHEAT_CLIENT_PROTECTION_NOT_AVAILABLE = 12000,
    /** The current anti-cheat mode is incorrect for using this API */
    ANTICHEAT_INVALID_MODE = 12001,
    /** The ProductId provided to the anti-cheat client helper executable does not match what was used to initialize the EOS SDK */
    ANTICHEAT_CLIENT_PRODUCTID_MISMATCH = 12002,
    /** The SandboxId provided to the anti-cheat client helper executable does not match what was used to initialize the EOS SDK */
    ANTICHEAT_CLIENT_SANDBOX_ID_MISMATCH = 12003,
    /** (ProtectMessage/UnprotectMessage, No session key is available = but it is required to complete this operation */
    ANTICHEAT_PROTECT_MESSAGE_SESSION_KEY_REQUIRED = 12004,
    /** (ProtectMessage/UnprotectMessage, Message integrity is invalid */
    ANTICHEAT_PROTECT_MESSAGE_VALIDATION_FAILED = 12005,
    /** (ProtectMessage/UnprotectMessage, Initialization failed */
    ANTICHEAT_PROTECT_MESSAGE_INITIALIZATION_FAILED = 12006,
    /** (RegisterPeer, Peer is already registered */
    ANTICHEAT_PEER_ALREADY_REGISTERED = 12007,
    /** (UnregisterPeer, Peer does not exist */
    ANTICHEAT_PEER_NOT_FOUND = 12008,
    /** (ReceiveMessageFromPeer, Invalid call: Peer is not protected */
    ANTICHEAT_PEER_NOT_PROTECTED = 12009,
    /** The DeploymentId provided to the anti-cheat client helper executable does not match what was used to initialize the EOS SDK */
    ANTICHEAT_CLIENT_DEPLOYMENT_ID_MISMATCH = 12010,
    /** EOS Connect DeviceID auth method is not supported for anti-cheat */
    ANTICHEAT_DEVICE_ID_AUTH_IS_NOT_SUPPORTED = 12011,
    
    /** EOS RTC room cannot accept more participants */
    RTC_TOO_MANY_PARTICIPANTS = 13000,
    /** EOS RTC room already exists*/
    RTC_ROOM_ALREADY_EXISTS = 13001,
    /** The user kicked out from the room */
    RTC_USER_KICKED = 13002,
    /** The user is banned */
    RTC_USER_BANNED = 13003,
    /** EOS RTC room was left successfully */
    RTC_ROOM_WAS_LEFT = 13004,
    /** Connection dropped due to long timeout */
    RTC_RECONNECTION_TIME_GATE_EXPIRED = 13005,
    /** EOS RTC room was left due to platform release */
    RTC_SHUTDOWN_INVOKED = 13006,
    /** EOS RTC operation failed because the user is in the local user's block list */
    RTC_USER_IS_IN_BLOCK_LIST = 13007,
    
    /** The number of available Snapshot IDs have all been exhausted. */
    ProgressionSnapshot_SnapshotIdUnavailable = 14000,
    
    /** The KWS user does not have a parental email associated with the account.  The parent account was unlinked or deleted */
    KWS_PARENT_EMAIL_MISSING = 15000,
    /** The KWS user is no longer a minor and trying to update the parent email */
    KWS_USER_GRADUATED = 15001,
    
    /** EOS Android VM not stored */
    ANDROID_JAVA_VM_NOT_STORED = 17000,
    /** EOS Android if Reserved is set it must reference stored VM */
    ANDROID_RESERVED_MUST_REFERENCE_LOCAL_VM = 17001,
    /** EOS Android Reserved must not be provided */
    ANDROID_RESERVED_MUST_BE_NULL = 17002,
    
    /** Patch required before the user can use the privilege */
    PERMISSION_REQUIRED_PATCH_AVAILABLE = 18000,
    /** System update required before the user can use the privilege */
    PERMISSION_REQUIRED_SYSTEM_UPDATE = 18001,
    /** Parental control failure usually */
    PERMISSION_AGE_RESTRICTION_FAILURE = 18002,
    /** Premium Account Subscription required but not available */
    PERMISSION_ACCOUNT_TYPE_FAILURE = 18003,
    /** User restricted from chat */
    PERMISSION_CHAT_RESTRICTION = 18004,
    /** User restricted from User Generated Content */
    PERMISSION_UGC_RESTRICTION = 18005,
    /** Online play is restricted */
    PERMISSION_ONLINE_PLAY_RESTRICTED = 18006,
    
    /** The application was not launched through the Bootstrapper. Desktop crossplay functionality is unavailable. */
    DESKTOP_CROSSPLAY_APPLICATION_NOT_BOOTS_TRAPPED = 19000,
    /** The redistributable service is not installed. */
    DESKTOP_CROSSPLAY_SERVICE_NOT_INSTALLED = 19001,
    /** The desktop crossplay service failed to start. */
    DESKTOP_CROSSPLAY_SERVICE_START_FAILED = 19002,
    /** The desktop crossplay service is no longer running for an unknown reason. */
    DESKTOP_CROSSPLAY_SERVICE_NOT_RUNNING = 19003,
    
    /** When sending the custom invite failed. */
    CUSTOM_INVITES_INVITE_FAILED = 20000,
    
    /** The best display name could not be safely determined. */
    USER_INFO_BEST_DISPLAY_NAME_INDETERMINATE = 22000,
    
    /** OnNetworkRequested_DEPRECATED callback not set when initializing platform */
    CONSOLE_INIT_ON_NETWORK_REQUESTED_DEPRECATED_CALLBACK_NOT_SET = 23000,
    /** CacheStorageSizeKB must be a multiple of 16 **/
    CONSOLE_INIT_CACHE_STORAGE_SIZE_KB_NOT_MULTIPLE_OF_16 = 23001,
    /** CacheStorageSizeKB is less than the minimum allowed **/
    CONSOLE_INIT_CACHE_STORAGE_SIZE_KB_BELOW_MINIMUM_SIZE = 23002,
    /** CacheStorageSizeKB is greater than the maximum allowed (4000 MB, **/
    CONSOLE_INIT_CACHE_STORAGE_SIZE_KB_EXCEEDS_MAXIMUM_SIZE = 23003,
    /** CacheStorageIndex is out of its allowed range **/
    CONSOLE_INIT_CACHE_STORAGE_INDEX_OUT_OF_RANGE = 23004,
    
    /** An unexpected error that we cannot identify has occurred. */
    //EOS_UNEXPECTED_ERROR = 0x7FFFFFFF,
}