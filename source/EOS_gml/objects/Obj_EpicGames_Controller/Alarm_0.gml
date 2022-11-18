
alarm[0] = RefreshPeriod_AccountID

var struct = EpicGames_Auth_CopyUserAuthToken(AccountID)

EpicGames_Auth_Login(
	EpicGames_LCT_RefreshToken,
	EpicGames_AS_BasicProfile | EpicGames_AS_FriendsList | EpicGames_AS_Presence,
	"",
	struct.RefreshToken,
	noone
	)
