
switch(async_load[?"type"])
{
	case "EpicGames_Friends_QueryFriends":
	
		show_debug_message(json_encode(async_load))

		if(async_load[?"status"] == EpicGames_Success)
		{
			var count = EpicGames_Friends_GetFriendsCount(AccountID)
			for(var a = 0 ; a < count ; a ++)
			{
				var Friend_AccountID = EpicGames_Friends_GetFriendAtIndex(AccountID,a)
				request = EpicGames_UserInfo_QueryUserInfo(AccountID,Friend_AccountID)
			}
		}
		
	break
	
	case "EpicGames_UserInfo_QueryUserInfo":
		
		var struct = EpicGames_UserInfo_CopyUserInfo(AccountID,async_load[?"target"])
		var ins = instance_create_depth(100,200,0,Obj_EpicGames_Friend,struct)
		
	break
}

