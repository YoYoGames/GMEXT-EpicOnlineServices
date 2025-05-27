
enum EOS_PLAYER_REPORTS_CATEGORY
{
	/** Not used */
	Invalid = 0,
	/** The reported player is cheating */
	Cheating = 1,
	/** The reported player is exploiting the game */
	Exploiting = 2,
	/** The reported player has an offensive profile, name, etc */
	OffensiveProfile = 3,
	/** The reported player is being abusive in chat */
	VerbalAbuse = 4,
	/** The reported player is scamming other players */
	Scamming = 5,
	/** The reported player is spamming chat */
	Spamming = 6,
	/** The player is being reported for something else */
	Other = 7
}

/** Max length of a report message text, not including the null terminator. */
#macro EOS_REPORTS_REPORTMESSAGE_MAX_LENGTH 512

/** Max length of a report context JSON payload, not including the null terminator. */
#macro EOS_REPORTS_REPORTCONTEXT_MAX_LENGTH 4096

