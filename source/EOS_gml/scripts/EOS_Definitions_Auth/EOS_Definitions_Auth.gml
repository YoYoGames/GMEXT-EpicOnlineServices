
enum EOS_LoginCredentialType
{
	/**
	 * Login using account email address and password.
	 *
	 * @note Use of this login method is restricted and cannot be used in general.
	 */
	Password = 0,
	/**
	 * A short-lived one-time use exchange code to login the local user.
	 *
	 * @details Typically retrieved via command-line parameters provided by a launcher that generated the exchange code for this application.
	 * When started, the application is expected to consume the exchange code by using the EOS_Auth_Login API as soon as possible.
	 * This is needed in order to authenticate the local user before the exchange code would expire.
	 * Attempting to consume an already expired exchange code will return EOS_EResult::EOS_Auth_ExchangeCodeNotFound error by the EOS_Auth_Login API.
	 */
	ExchangeCode = 1,
	/**
	 * Used by standalone applications distributed outside the supported game platforms such as Epic Games Store or Steam, and on Nintendo Switch.
	 *
	 * Persistent Auth is used in conjunction with the EOS_LCT_AccountPortal login method for automatic login of the local user across multiple runs of the application.
	 *
	 * Standalone applications implement the login sequence as follows:
	 * 1. Application calls EOS_Auth_Login with EOS_LCT_PersistentAuth, using a previously stored Epic refresh token for an automatic user login.
	 * 2. If automatic login fails, the application discards the Epic refresh token used as defunct, and proceeds to call EOS_Auth_Login with EOS_LCT_AccountPortal to prompt the user for manual login.
	 *
	 * @note On Desktop and Mobile platforms, the persistent refresh token is automatically managed by the SDK that stores it in the keychain of the currently logged in user of the local device.
	 * On Nintendo Switch, after a successful login the refresh token must be retrieved using the EOS_Auth_CopyUserAuthToken API and stored by the application specifically for the active Nintendo Switch user.
	 *
	 * @see EOS_LCT_AccountPortal
	 */
	PersistentAuth = 2,
	/**
	 * Not supported. Superseded by EOS_LCT_ExternalAuth login method.
	 *
	 * @see EOS_LCT_ExternalAuth
	 */
	DeviceCode = 3,
	/**
	 * Login with named credentials hosted by the EOS SDK Developer Authentication Tool.
	 *
	 * @note Used for development purposes only.
	 */
	Developer = 4,
	/**
	 * Refresh token that was retrieved from a previous call to EOS_Auth_Login API in another local process context.
	 * Mainly used in conjunction with custom desktop launcher applications.
	 *
	 * @details Can be used for example when launching the game from Epic Games Launcher and having an intermediate process
	 * in-between that requires authenticating the user before eventually starting the actual game client application.
	 * In such scenario, an intermediate launcher will log in the user by consuming the exchange code it received from the
	 * Epic Games Launcher. To allow the game client to also authenticate the user, it can copy the refresh token using the
	 * EOS_Auth_CopyUserAuthToken API and pass it via launch parameters to the started game client. The game client can then
	 * use the refresh token to log in the user.
	 */
	RefreshToken = 5,
	/**
	 * Used by standalone applications distributed outside the supported game platforms such as Epic Games Store or Steam, and on Nintendo Switch.
	 *
	 * Login using the built-in user onboarding experience provided by the SDK, which will automatically store a persistent
	 * refresh token to enable automatic user login for consecutive application runs on the local device. Applications are
	 * expected to attempt automatic login using the EOS_LCT_PersistentAuth login method, and fall back to EOS_LCT_AccountPortal
	 * to prompt users for manual login.
	 *
	 * @note On Windows, using this login method requires applications to be started through the EOS Bootstrapper application
	 * and to have the local Epic Online Services redistributable installed on the local system. See EOS_Platform_GetDesktopCrossplayStatus
	 * for adding a readiness check prior to calling EOS_Auth_Login.
	 *
	 * @see EOS_LCT_PersistentAuth
	 */
	AccountPortal = 6,
	/**
	 * Login using external account provider credentials, such as PlayStation(TM)Network, Steam, and Xbox Live.
	 *
	 * This is the intended login method on PlayStation® and Xbox console devices.
	 * On Desktop and Mobile, used when launched through any of the commonly supported platform clients.
	 *
	 * @details The user is seamlessly logged in to their Epic account using an external account access token.
	 * If the local platform account is already linked with the user's Epic account, the login will succeed and EOS_EResult::EOS_Success is returned.
	 * When the local platform account has not been linked with an Epic account yet,
	 * EOS_EResult::EOS_InvalidUser is returned and the EOS_ContinuanceToken will be set in the EOS_Auth_LoginCallbackInfo data.
	 * If EOS_EResult::EOS_InvalidUser is returned,
	 * the application should proceed to call the EOS_Auth_LinkAccount API with the EOS_ContinuanceToken to continue with the external account login
	 * and to link the external account at the end of the login flow.
	 *
	 * @details Login flow when the platform user account has not been linked with an Epic account yet:
	 * 1. Game calls EOS_Auth_Login with the EOS_LCT_ExternalAuth credential type.
	 * 2. EOS_Auth_Login returns EOS_EResult::EOS_InvalidUser with a non-null EOS_ContinuanceToken in the EOS_Auth_LoginCallbackInfo data.
	 * 3. Game calls EOS_Auth_LinkAccount with the EOS_ContinuanceToken to initiate the login flow for linking the platform account with the user's Epic account.
	 * 4. The user is taken automatically to the Epic accounts user onboarding flow managed by the SDK.
	 * 5. Once the user completes the login, cancels it or if the login flow times out, EOS_Auth_LinkAccount invokes the completion callback to the caller.
	 *    - If the user was logged in successfully, EOS_EResult::EOS_Success is returned in the EOS_Auth_LoginCallbackInfo. Otherwise, an error result code is returned accordingly.
	 *
	 * @note On Windows, using this login method requires applications to be started through the EOS Bootstrapper application
	 * and to have the local Epic Online Services redistributable installed on the local system. See EOS_Platform_GetDesktopCrossplayStatus
	 * for adding a readiness check prior to calling EOS_Auth_Login.
	 */
	ExternalAuth = 7
}


/**
 * Types of auth tokens
 *
 * @see EOS_Auth_CopyUserAuthToken
 * @see EOS_Auth_Token
 */
enum EOS_AuthTokenType
{
	/** Auth token is for a validated client */
	Client = 0,
	/** Auth token is for a validated user */
	User = 1
}


/** Flags that describe user permissions */
enum EOS_AuthScopeFlags
{
	NoFlags = 0x0,
	/** Permissions to see your account ID, display name, and language */
	BasicProfile = 0x1,
	/** Permissions to see a list of your friends who use this application */
	FriendsList = 0x2,
	/** Permissions to set your online presence and see presence of your friends */
	Presence = 0x4,
	/** Permissions to manage the Epic friends list. This scope is restricted to Epic first party products, and attempting to use it will result in authentication failures. */
	FriendsManagement = 0x8,
	/** Permissions to see email in the response when fetching information for a user. This scope is restricted to Epic first party products, and attempting to use it will result in authentication failures. */
	Email = 0x10,
	/** Permissions to see your country */
	Country = 0x20
}

/** Optional login flags used in EOS_Auth_Login. */

/**
 * Specify login to be performed without SDK provided user interface.
 *
 * By default, and without this flag, the SDK uses the overlay or a system browser to show user interfaces during login
 * when the user needs to perform some action. With this flag, an error such as EOS_Auth_UserInterfaceRequired is returned
 * to the login callback, and no user interface is shown in those cases.
 */
#macro EOS_LF_NO_USER_INTERFACE 0x00001


/**
 * Flags used to describe how the account linking operation is to be performed.
 *
 * @see EOS_Auth_LinkAccount
 */
enum EOS_LinkAccountFlags
{
	/**
	 * Default flag used for a standard account linking operation.
	 *
	 * This flag is set when using a continuance token received from a previous call to the EOS_Auth_Login API,
	 * when the local user has not yet been successfully logged in to an Epic Account yet.
	 */
	NoFlags = 0x0,
	/**
	 * Specified when the EOS_ContinuanceToken describes a Nintendo NSA ID account type.
	 *
	 * This flag is used only with, and must be set, when the continuance token was received from a previous call
	 * to the EOS_Auth_Login API using the EOS_EExternalCredentialType::EOS_ECT_NINTENDO_NSA_ID_TOKEN login type.
	 */
	NintendoNsaId = 0x1
}

