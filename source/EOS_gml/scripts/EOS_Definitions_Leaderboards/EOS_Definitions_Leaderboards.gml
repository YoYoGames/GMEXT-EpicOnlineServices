
/** Timestamp value representing an undefined time for EOS_HLeaderboards. */
#macro EOS_LEADERBOARDS_TIME_UNDEFINED -1


/**
 * An enumeration of the different leaderboard aggregation types.
 */
enum EOS_LeaderboardAggregation
{
	/** Minimum */
	Min = 0,
	/** Maximum */
	Max = 1,
	/** Sum */
	Sum = 2,
	/** Latest */
	Latest = 3
}
