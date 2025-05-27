
/**
 * A character buffer of this size is large enough to fit a successful output of EOS_EpicAccountId_ToString. This length does not include the null-terminator.
 * The EpicAccountId data structure is opaque in nature and no assumptions of its structure should be inferred
 */
#macro EOS_EPICACCOUNTID_MAX_LENGTH 32


/** A character buffer of this size is large enough to fit a successful output of EOS_ProductUserId_ToString. This length does not include the null-terminator. */
#macro EOS_PRODUCTUSERID_MAX_LENGTH 32

/** An invalid notification ID */
#macro EOS_INVALID_NOTIFICATIONID 0/*((EOS_NotificationId)0)*/

/** The most recent version of the EOS_PageQuery structs. */
#macro EOS_PAGEQUERY_API_LATEST 1

/** DEPRECATED! Use EOS_PAGEQUERY_API_LATEST instead. */
#macro EOS_PAGINATION_API_LATEST EOS_PAGEQUERY_API_LATEST

/** The default MaxCount used for a EOS_PageQuery when the API allows the EOS_PageQuery to be omitted. */
#macro EOS_PAGEQUERY_MAXCOUNT_DEFAULT 10

/** The maximum MaxCount used for a EOS_PageQuery. */
#macro EOS_PAGEQUERY_MAXCOUNT_MAXIMUM 100


/**
 * All possible states of a local user
 *
 * @see EOS_Auth_AddNotifyLoginStatusChanged
 * @see EOS_Auth_GetLoginStatus
 * @see EOS_Auth_Login
 * @see EOS_Connect_AddNotifyLoginStatusChanged
 * @see EOS_Connect_GetLoginStatus
 * @see EOS_Connect_Login
 */
enum EOS_LOGING_STATUS{
	/** Player has not logged in or chosen a local profile */
	NOT_LOGGED_IN = 0,
	/** Player is using a local profile but is not logged in */
	USING_LOCAL_PROFILE = 1,
	/** Player has been validated by the platform specific authentication service */
	LOGGED_IN = 2
}

/**
 * Supported types of data that can be stored with inside an attribute (used by sessions/lobbies/etc)
 *
 * @see EOS_LobbySearch_SetParameter
 * @see EOS_SessionSearch_SetParameter
 */
enum EOS_ATTRIBUTE_TYPE{
	/** Boolean value (true/false) */
	BOOLEAN = 0,
	/** 64 bit integers */
	INT64 = 1,
	/** Double/floating point precision */
	DOUBLE = 2,
	/** UTF8 Strings */
	STRING = 3
}


/**
 * All comparison operators associated with parameters in a search query
 *
 * @see EOS_LobbySearch_SetParameter
 * @see EOS_SessionSearch_SetParameter
 */
enum EOS_COMPARISON_OP{
	/** Value must equal the one stored on the lobby/session */
	EQUAL = 0,
	/** Value must not equal the one stored on the lobby/session */
	NOTEQUAL = 1,
	/** Value must be strictly greater than the one stored on the lobby/session */
	GREATERTHAN = 2,
	/** Value must be greater than or equal to the one stored on the lobby/session */
	GREATERTHANOREQUAL = 3,
	/** Value must be strictly less than the one stored on the lobby/session */
	LESSTHAN = 4,
	/** Value must be less than or equal to the one stored on the lobby/session */
	LESSTHANOREQUAL = 5,
	/** Prefer values nearest the one specified ie. abs(SearchValue-SessionValue) closest to 0 */
	DISTANCE = 6,
	/** Value stored on the lobby/session may be any from a specified list */
	ANYOF = 7,
	/** Value stored on the lobby/session may NOT be any from a specified list */
	NOTANYOF = 8,
	/** This one value is a part of a collection */
	ONEOF = 9,
	/** This one value is NOT part of a collection */
	NOTONEOF = 10,
	/** This value is a CASE SENSITIVE substring of an attribute stored on the lobby/session */
	CONTAINS = 11
}

/**
 * All supported external account providers
 *
 * @see EOS_Connect_QueryExternalAccountMappings
 */
enum EOS_ExternalAccountType
{
	/** External account is associated with Epic Games */
	EPIC = 0,
	/** External account is associated with Steam */
	STEAM = 1,
	/** External account is associated with PlayStation(TM)Network */
	PSN = 2,
	/** External account is associated with Xbox Live */
	XBL = 3,
	/** External account is associated with Discord */
	DISCORD = 4,
	/** External account is associated with GOG */
	GOG = 5,
	/**
	 * External account is associated with Nintendo
	 *
	 * With both EOS Connect and EOS UserInfo APIs, the associated account type is Nintendo Service Account ID.
	 * Local user authentication is possible using Nintendo Account ID, while the account type does not get exposed to the SDK in queries related to linked accounts information.
	 */
	NINTENDO = 6,
	/** External account is associated with Uplay */
	UPLAY = 7,
	/** External account is associated with an OpenID Provider */
	OPENID = 8,
	/** External account is associated with Apple */
	APPLE = 9,
	/** External account is associated with Google */
	GOOGLE = 10,
	/** External account is associated with Oculus */
	OCULUS = 11,
	/** External account is associated with itch.io */
	ITCHIO = 12,
	/** External account is associated with Amazon */
	AMAZON = 13,
	/** External account is associated with Viveport */
	VIVEPORT = 14
}

/**
 * List of the supported identity providers to authenticate a user.
 *
 * The type of authentication token is specific to each provider.
 * Tokens in string format should be passed as-is to the function.
 * Tokens retrieved as raw byte arrays should be converted into a hex-encoded UTF-8 string (e.g. "FA87097A..") before being passed to the function.
 * EOS_ByteArray_ToString can be used for this conversion.
 *
 * @see EOS_Auth_Login
 * @see EOS_Connect_Login
 */
enum EOS_EXTERNAL_CREDENTIAL_TYPE
{
	/**
	 * Epic Account Services Token
	 *
	 * Using ID Token is preferred, retrieved with EOS_Auth_CopyIdToken that returns EOS_Auth_IdToken::JsonWebToken.
	 * Using Auth Token is supported for backwards compatibility, retrieved with EOS_Auth_CopyUserAuthToken that returns EOS_Auth_Token::AccessToken.
	 *
	 * Supported with EOS_Connect_Login.
	 *
	 * @see EOS_Auth_CopyIdToken
	 * @see EOS_Auth_CopyUserAuthToken
	 */
	EPIC = 0,
	/**
	 * Steam Encrypted App Ticket
	 * Note that STEAM_APP_TICKET is deprecated for use with EOS_Auth_Login. Use STEAM_SESSION_TICKET instead.
	 *
	 * Generated using the ISteamUser::RequestEncryptedAppTicket API of Steamworks SDK.
	 * For ticket generation parameters, use pDataToInclude(NULL) and cbDataToInclude(0).
	 *
	 * The retrieved App Ticket byte buffer needs to be converted into a hex-encoded UTF-8 string (e.g. "FA87097A..") before passing it to the EOS_Connect_Login API.
	 * EOS_ByteArray_ToString can be used for this conversion.
	 *
	 * Supported with EOS_Connect_Login.
	 *
	 * @see STEAM_SESSION_TICKET
	 */
	STEAM_APP_TICKET = 1,
	/**
	 * PlayStation(TM)Network ID Token
	 *
	 * Retrieved from the PlayStation(R) SDK. Please see first-party documentation for additional information.
	 *
	 * Supported with EOS_Auth_Login, EOS_Connect_Login.
	 */
	PSN_ID_TOKEN = 2,
	/**
	 * Xbox Live XSTS Token
	 *
	 * Retrieved from the GDK and XDK. Please see first-party documentation for additional information.
	 *
	 * Supported with EOS_Auth_Login, EOS_Connect_Login.
	 */
	XBL_XSTS_TOKEN = 3,
	/**
	 * Discord Access Token
	 *
	 * Retrieved using the ApplicationManager::GetOAuth2Token API of Discord SDK.
	 *
	 * Supported with EOS_Connect_Login.
	 */
	DISCORD_ACCESS_TOKEN = 4,
	/**
	 * GOG Galaxy Encrypted App Ticket
	 *
	 * Generated using the IUser::RequestEncryptedAppTicket API of GOG Galaxy SDK.
	 * For ticket generation parameters, use data(NULL) and dataSize(0).
	 *
	 * The retrieved App Ticket byte buffer needs to be converted into a hex-encoded UTF-8 string (e.g. "FA87097A..") before passing it to the EOS_Connect_Login API.
	 * For C/C++ API integration, use the EOS_ByteArray_ToString API for the conversion.
	 * For C# integration, you can use <see cref="Helper.ToHexString" /> for the conversion.
	 *
	 * Supported with EOS_Connect_Login.
	 */
	GOG_SESSION_TICKET = 5,
	/**
	 * Nintendo Account ID Token
	 *
	 * Identifies a Nintendo user account and is acquired through web flow authentication where the local user logs in using their email address/sign-in ID and password.
	 * This is the common Nintendo account that users login with outside the Nintendo Switch device.
	 *
	 * Supported with EOS_Auth_Login, EOS_Connect_Login.
	 */
	NINTENDO_ID_TOKEN = 6,
	/**
	 * Nintendo Service Account ID Token (NSA ID)
	 *
	 * The NSA ID identifies uniquely the local Nintendo Switch device. The authentication token is acquired locally without explicit user credentials.
	 * As such, it is the primary authentication method for seamless login on Nintendo Switch.
	 *
	 * The NSA ID is not exposed directly to the user and does not provide any means for login outside the local device.
	 * Because of this, Nintendo Switch users will need to link their Nintendo Account or another external user account
	 * to their Product User ID in order to share their game progression across other platforms. Otherwise, the user will
	 * not be able to login to their existing Product User ID on another platform due to missing login credentials to use.
	 * It is recommended that the game explicitly communicates this restriction to the user so that they will know to add
	 * the first linked external account on the Nintendo Switch device and then proceed with login on another platform.
	 *
	 * In addition to sharing cross-platform game progression, linking the Nintendo Account or another external account
	 * will allow preserving the game progression permanently. Otherwise, the game progression will be tied only to the
	 * local device. In case the user loses access to their local device, they will not be able to recover the game
	 * progression if it is only associated with this account type.
	 *
	 * Supported with EOS_Auth_Login, EOS_Connect_Login.
	 */
	NINTENDO_NSA_ID_TOKEN = 7,
	/**
	 * Uplay Access Token
	 */
	UPLAY_ACCESS_TOKEN = 8,
	/**
	 * OpenID Provider Access Token
	 *
	 * Supported with EOS_Connect_Login.
	 */
	OPENID_ACCESS_TOKEN = 9,
	/**
	 * Device ID access token that identifies the current locally logged in user profile on the local device.
	 * The local user profile here refers to the operating system user login, for example the user's Windows Account
	 * or on a mobile device the default active user profile.
	 *
	 * This credential type is used to automatically login the local user using the EOS Connect Device ID feature.
	 *
	 * The intended use of the Device ID feature is to allow automatically logging in the user on a mobile device
	 * and to allow playing the game without requiring the user to necessarily login using a real user account at all.
	 * This makes a seamless first-time experience possible and allows linking the local device with a real external
	 * user account at a later time, sharing the same EOS_ProductUserId that is being used with the Device ID feature.
	 *
	 * Supported with EOS_Connect_Login.
	 *
	 * @see EOS_Connect_CreateDeviceId
	 */
	DEVICEID_ACCESS_TOKEN = 10,
	/**
	 * Apple ID Token
	 *
	 * Supported with EOS_Connect_Login.
	 */
	APPLE_ID_TOKEN = 11,
	/**
	 * Google ID Token
	 *
	 * Supported with EOS_Connect_Login.
	 */
	GOOGLE_ID_TOKEN = 12,
	/**
	 * Oculus User ID and Nonce
	 *
	 * Call ovr_User_GetUserProof(), or Platform.User.GetUserProof() if you are using Unity, to retrieve the nonce.
	 * Then pass the local User ID and the Nonce as a "{UserID}|{Nonce}" formatted string for the EOS_Connect_Login Token parameter.
	 *
	 * Note that in order to successfully retrieve a valid non-zero id for the local user using ovr_User_GetUser(),
	 * your Oculus App needs to be configured in the Oculus Developer Dashboard to have the User ID feature enabled.
	 *
	 * Supported with EOS_Connect_Login.
	 */
	OCULUS_USERID_NONCE = 13,
	/**
	 * itch.io JWT Access Token
	 *
	 * Use the itch.io app manifest to receive a JWT access token for the local user via the ITCHIO_API_KEY process environment variable.
	 * The itch.io access token is valid for 7 days after which the game needs to be restarted by the user as otherwise EOS Connect
	 * authentication session can no longer be refreshed.
	 *
	 * Supported with EOS_Connect_Login.
	 */
	ITCHIO_JWT = 14,
	/**
	 * itch.io Key Access Token
	 *
	 * This access token type is retrieved through the OAuth 2.0 authentication flow for the itch.io application.
	 *
	 * Supported with EOS_Connect_Login.
	 */
	ITCHIO_KEY = 15,
	/**
	 * Epic Games ID Token
	 *
	 * Acquired using EOS_Auth_CopyIdToken that returns EOS_Auth_IdToken::JsonWebToken.
	 *
	 * Supported with EOS_Connect_Login.
	 */
	EPIC_ID_TOKEN = 16,
	/**
	 * Amazon Access Token
	 *
	 * Supported with EOS_Connect_Login.
	 */
	AMAZON_ACCESS_TOKEN = 17,
	/**
	 * Steam Auth Session Ticket
	 *
	 * Generated using the ISteamUser::GetAuthTicketForWebApi API of Steamworks SDK.
	 *
	 * @attention
	 * The pchIdentity input parameter of GetAuthTicketForWebApi API must be set to a valid non-empty string value.
	 * The string value used by the game client must match identically to the backend-configured value in EOS Dev Portal.
	 * The recommended value to use is "epiconlineservices" in lowercase, matching the default value for new Steam identity provider credentials in EOS Dev Portal.
	 * This identifier is important for security reasons to prevent session hijacking. Applications must use a dedicated unique identity identifier for Session Tickets passed to the EOS SDK APIs.
	 * Session Tickets using the EOS-assigned identifier must not be used with anything else than the EOS SDK APIs. You must use a different identifier when generating Session Tickets to authenticate with other parties.
	 *
	 * @warning
	 * To update an already live game to use the new GetAuthTicketForWebApi API instead of the deprecated GetAuthSessionTicket API, follow these steps in this order to prevent breaking the live game for players:
	 * 1. Update your game client code to use the new ISteamUser::GetAuthTicketForWebApi API.
	 * 2. Publish the new game client update to end-users.
	 * 3. Update the existing Steam identity provider credentials entry in EOS Dev Portal to use the same identity string identifier as the game client.
	 *
	 * @example
	 * SteamUser()->GetAuthTicketForWebApi("epiconlineservices");
	 *
	 * The retrieved Auth Session Ticket byte buffer needs to be converted into a hex-encoded UTF-8 string (e.g. "FA87097A..") before passing it to the EOS_Auth_Login or EOS_Connect_Login APIs.
	 * EOS_ByteArray_ToString can be used for this conversion.
	 *
	 * Supported with EOS_Auth_Login, EOS_Connect_Login.
	 *
	 * @version 1.15.1+
	 */
	STEAM_SESSION_TICKET = 18,
	/**
	 * VIVEPORT User Session Token
	 *
	 * Supported with EOS_Connect_Login.
	 */
	VIVEPORT_USER_TOKEN = 19
}


#macro EOS_OPT_UNKNOWN 0
#macro EOS_OPT_EPIC 100
#macro EOS_OPT_STEAM 4000
