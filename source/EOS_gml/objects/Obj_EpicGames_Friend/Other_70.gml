
if(async_load[?"type"] == "EpicGames_UserInfo_QueryUserInfo")
if(async_load[?"identifier"] == request)
{
	var struct = EpicGames_UserInfo_CopyUserInfo(AccountID,mAccountID)
	if(struct.status = EpicGames_Success)
	{
		DisplayName = struct.DisplayName
		//struct.PreferredLanguage
		//struct.UserId
	}
}