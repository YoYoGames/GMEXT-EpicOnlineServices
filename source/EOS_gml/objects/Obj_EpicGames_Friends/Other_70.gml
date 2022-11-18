
if(async_load[?"type"] == "EpicGames_Friends_QueryFriends")
if(async_load[?"status"] == EpicGames_Success)
{
	var count = EpicGames_Friends_GetFriendsCount(AccountID)
	for(var a = 0 ; a < count ; a ++)
	{
		var Friend_AccountID = EpicGames_Friends_GetFriendAtIndex(AccountID,a)
		var ins = instance_create_depth(100,200,0,Obj_EpicGames_Friend)
		ins.mAccountID = Friend_AccountID
	}
}
