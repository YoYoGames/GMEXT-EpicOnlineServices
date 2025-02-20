
if(userID == "")
{
	//show_debug_message("EpicGames_Auth_Login CALLED")
	EpicGames_Auth_Login(
		EpicGames_LCT_AccountPortal,
		EpicGames_AS_BasicProfile | EpicGames_AS_FriendsList | EpicGames_AS_Presence,
		"",
		"",
		noone
		)
}
else
	EpicGames_Auth_Logout(AccountID)


