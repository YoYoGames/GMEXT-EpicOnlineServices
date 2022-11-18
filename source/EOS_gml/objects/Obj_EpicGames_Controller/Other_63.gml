
if(async_load[?"id"] == request_MFA)
if(async_load[?"status"])
if(async_load[?"result"] != "")
{
	var code = async_load[?"result"]
	
	EpicGames_Auth_Login(
		EpicGames_LCT_ExchangeCode,
		EpicGames_AS_BasicProfile | EpicGames_AS_FriendsList | EpicGames_AS_Presence,
		"",
		code,
		noone)
}
