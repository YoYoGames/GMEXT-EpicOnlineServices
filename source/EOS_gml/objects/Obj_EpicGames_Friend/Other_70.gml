
if(async_load[?"type"] != "EpicGames_UserInfo_QueryUserInfo") return;

show_debug_message(json_encode(async_load))

if(async_load[?"identifier"] == request)
{
	var struct = EpicGames_UserInfo_CopyUserInfo(AccountID,mAccountID)
	if(struct.status = EpicGames_Success)
	{
		DisplayName = struct.DisplayName
		//struct.PreferredLanguage
		//struct.UserId
	}
	else show_debug_message("ERROR!!!")
}