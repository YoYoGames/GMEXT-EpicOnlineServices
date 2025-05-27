
enum EOS_PLAYER_REPORTS_CATEGORY
{
	/** Not used */
	INVALID = 0,
	/** The reported player is cheating */
	CHEATING = 1,
	/** The reported player is exploiting the game */
	EXPLOITING = 2,
	/** The reported player has an offensive profile, name, etc */
	OFFENSIVE_PROFILE = 3,
	/** The reported player is being abusive in chat */
	VERBAL_ABUSE = 4,
	/** The reported player is scamming other players */
	SCAMMING = 5,
	/** The reported player is spamming chat */
	SPAMMING = 6,
	/** The player is being reported for something else */
	OTHER = 7
}

/** Max length of a report message text, not including the null terminator. */
#macro EOS_REPORTS_REPORTMESSAGE_MAX_LENGTH 512

/** Max length of a report context JSON payload, not including the null terminator. */
#macro EOS_REPORTS_REPORTCONTEXT_MAX_LENGTH 4096

