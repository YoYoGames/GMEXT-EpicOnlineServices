
/**
 * An enumeration of the different friendship statuses.
 */
enum EOS_FRIENDS_STATUS
{
	/** The two accounts have no friendship status. */
	NotFriends = 0,

	/** 
	 * The local account has sent a friend invite to the other account.
	 *
	 * NOTE: EOS_FS_InviteSent is not returned by EOS_Friends_GetStatus or in EOS_Friends_AddNotifyFriendsUpdate callbacks unless
	 *       the local account was logged in with the EOS_AS_FriendsManagement authentication scope. Friend invites are managed
	 *       automatically by the Social Overlay.
	 */
	InviteSent = 1,

	/** 
	 * The other account has sent a friend invite to the local account.
	 *
	 * NOTE: EOS_FS_InviteReceived is not returned by EOS_Friends_GetStatus or in EOS_Friends_AddNotifyFriendsUpdate callbacks unless
	 *       the local account was logged in with the EOS_AS_FriendsManagement authentication scope. Friend invites are managed
	 *       automatically by the Social Overlay.
	 */
	InviteReceived = 2,

	/** The accounts have accepted friendship. */
	Friends = 3
}
