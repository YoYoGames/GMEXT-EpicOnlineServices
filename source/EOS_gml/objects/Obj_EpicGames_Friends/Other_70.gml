
switch(async_load[?"type"])
{
	case "EpicGames_Friends_QueryFriends":
		
		if(async_load[?"status"] == EpicGames_Success)
		{
			friends = {}
			var count = EpicGames_Friends_GetFriendsCount(AccountID)
			for(var a = 0 ; a < count ; a ++)
			{
				var Friend_AccountID = EpicGames_Friends_GetFriendAtIndex(AccountID,a)
				request = EpicGames_UserInfo_QueryUserInfo(AccountID,Friend_AccountID)
				struct_set(friends,Friend_AccountID,{})
			}
		}
		
	break
	
	case "EpicGames_UserInfo_QueryUserInfo":
		
		var struct = EpicGames_UserInfo_CopyUserInfo(AccountID,async_load[?"target"])
		
		struct_set(friends,async_load[?"target"],struct)
		
		var _arrayName = struct_get_names(friends)
		for(var a = 0 ; a < array_length(_arrayName) ; a++)
			if(struct_names_count(struct_get(friends,_arrayName[a])) == 0)
				exit
			
		show_debug_message("REQUEST: EpicGames_Connect_QueryExternalAccountMappings")
		
		//Ok, let's request!
		var friends_account_ids = struct_get_names(friends)
		EpicGames_Connect_QueryExternalAccountMappings(userID,0,friends_account_ids)
		
	break
	
	case "EpicGames_Connect_QueryExternalAccountMappings":
			
		var friends_account_ids = struct_get_names(friends)
		
		for(var a = 0 ; a < array_length(friends_account_ids) ; a++)
		{
			var user_id = EpicGames_Connect_GetExternalAccountMapping(userID,friends_account_ids[a],0)
			struct_set(struct_get(friends,friends_account_ids[a]),"UserID",user_id)
		}
		
		struct_foreach(friends,function(_name, _value)
			{
				var ins = instance_create_depth(100,200+friend_counter_index*80,0,friend_object,_value)
				friend_counter_index++
				exit
			})
			
	break
}