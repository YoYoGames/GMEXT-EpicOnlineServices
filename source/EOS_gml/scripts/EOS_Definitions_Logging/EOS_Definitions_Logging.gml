
/**
 * Logging levels. When a log message is output, it has an associated log level.
 * Messages will only be sent to the callback function if the message's associated log level is less than or equal to the configured log level for that category.
 *
 * @see EOS_Logging_SetCallback
 * @see EOS_Logging_SetLogLevel
 */
enum EOS_LOG_LEVEL
{
	OFF = 0,
	FATAL = 100,
	ERROR = 200,
	WARNING = 300,
	INFO = 400,
	VERBOSE = 500,
	VERY_VERBOSE = 600
}

/**
 * Logging Categories
 */
enum EOS_LOG_CATEGORY
{
	/** Low level logs unrelated to specific services */
	CORE = 0,
	/** Logs related to the Auth service */
	AUTH = 1,
	/** Logs related to the Friends service */
	FRIENDS = 2,
	/** Logs related to the Presence service */
	PRESENCE = 3,
	/** Logs related to the UserInfo service */
	USER_INFO = 4,
	/** Logs related to HTTP serialization */
	HTTP_SERIALIZATION = 5,
	/** Logs related to the Ecommerce service */
	ECOM = 6,
	/** Logs related to the P2P service */
	P2P = 7,
	/** Logs related to the Sessions service */
	SESSIONS = 8,
	/** Logs related to rate limiting */
	RATE_LIMITER = 9,
	/** Logs related to the PlayerDataStorage service */
	PLAYER_DATA_STORAGE = 10,
	/** Logs related to sdk analytics */
	ANALYTICS = 11,
	/** Logs related to the messaging service */
	MESSAGING = 12,
	/** Logs related to the Connect service */
	CONNECT = 13,
	/** Logs related to the Overlay */
	OVERLAY = 14,
	/** Logs related to the Achievements service */
	ACHIEVEMENTS = 15,
	/** Logs related to the Stats service */
	STATS = 16,
	/** Logs related to the UI service */
	UI = 17,
	/** Logs related to the lobby service */
	LOBBY = 18,
	/** Logs related to the Leaderboards service */
	LEADERBOARDS = 19,
	/** Logs related to an internal Keychain feature that the authentication interfaces use */
	KEYCHAIN = 20,
	/** Logs related to integrated platforms */
	INTEGRATED_PLATFORM = 21,
	/** Logs related to Title Storage */
	TITLE_STORAGE = 22,
	/** Logs related to the Mods service */
	MODS = 23,
	/** Logs related to the Anti-Cheat service */
	ANTI_CHEAT = 24,
	/** Logs related to reports client. */
	REPORTS = 25,
	/** Logs related to the Sanctions service */
	SANCTIONS = 26,
	/** Logs related to the Progression Snapshot service */
	PROGRESSION_SNAPSHOTS = 27,
	/** Logs related to the Kids Web Services integration */
	KWS = 28,
	/** Logs related to the RTC API */
	RTC = 29,
	/** Logs related to the RTC Admin API */
	RTC_ADMIN = 30,
	/** Logs related to the Custom Invites API */
	CUSTOM_INVITES = 31,

	/** Not a real log category. Used by EOS_Logging_SetLogLevel to set the log level for all categories at the same time */
	//ALL_CATEGORIES = 0x7fffffff
}

