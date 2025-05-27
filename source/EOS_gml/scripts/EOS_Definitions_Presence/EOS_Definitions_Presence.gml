
enum EOS_PRESENCE_STATUS
{
	/** The status of the account is offline or not known */
	Offline = 0,
	/** The status of the account is online */
	Online = 1,
	/** The status of the account is away */
	Away = 2,
	/** The status of the account is away, and has been away for a while */
	ExtendedAway = 3,
	/** The status of the account is do-not-disturb */
	DoNotDisturb = 4
}

/**
 * The maximum of allowed individual pieces of data a user may have. This value is subject to change and data structures should be designed to allow for greater
 * numbers than this.
 */
#macro EOS_PRESENCE_DATA_MAX_KEYS 32

/**
 * The maximum allowed length a data's key may be. This value is subject to change and data structures should be designed to allow for greater numbers than this.
 */
#macro EOS_PRESENCE_DATA_MAX_KEY_LENGTH 64

/**
 * The maximum allowed length a data's value may be. This value is subject to change and data structures should be designed to allow for greater numbers than this.
 */
#macro EOS_PRESENCE_DATA_MAX_VALUE_LENGTH 255

/**
 * The maximum allowed length a user's rich text string may be. This value is subject to change and data structures should be designed to allow for greater numbers
 * than this.
 */
#macro EOS_PRESENCE_RICH_TEXT_MAX_VALUE_LENGTH 255

/**
 * The presence key used to specify the local platform's presence string on platforms that use tokenized presence.
 * For use with EOS_PresenceModification_SetData.
 *
 * @see EOS_PresenceModification_SetData
 * @see EOS_Presence_DataRecord
 */
#macro EOS_PRESENCE_KEY_PLATFORM_PRESENCE "EOS_PlatformPresence"

