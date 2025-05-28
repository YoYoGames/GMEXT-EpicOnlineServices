
/** Timestamp value representing an undefined time for EOS_HLeaderboards. */
#macro EOS_LEADERBOARDS_TIME_UNDEFINED -1


/**
 * An enumeration of the different leaderboard aggregation types.
 */
enum EOS_LEADERBOARD_AGGREGATION
{
	/** Minimum */
	MIN = 0,
	/** Maximum */
	MAX = 1,
	/** Sum */
	SUM = 2,
	/** Latest */
	LATEST = 3
}
