
switch(async_load[?"type"])
{	
	case "EpicGames_Leaderboards_QueryLeaderboardUserScores":
		
		var count = EpicGames_Leaderboards_GetLeaderboardUserScoreCount("Leaderboard_Stat")
		show_debug_message($"count: {count}")
		for(var a = 0 ; a < count ; a++)
		{
			var struct = EpicGames_Leaderboards_CopyLeaderboardUserScoreByIndex(a,"Leaderboard_Stat")
			
			var ins = instance_create_depth(400,300+a*80,0,Obj_EpicGames_Leaderboard_Rank_Friend)
			
			//array_length(UserId,)
			
			if(variable_struct_exists(struct,"UserId"))
			{
				ins.UserId = struct.UserId
				
				var account_ids = struct_get_names(friends)
				for(var b = 0 ; b < array_length(account_ids) ; b++)
				{
					var user_id = struct_get(friends,account_ids[b])
					if(ins.UserId == user_id)
					{
					    ins.mAccountID = account_ids[a]
						break
					}
				}
			}
			
			if(variable_struct_exists(struct,"Score"))
				ins.Score = struct.Score
			
			var scores = []
			var index = 0
			with(Obj_EpicGames_Leaderboard_Rank_Friend)
			{
				scores[index] = Score
				index ++
			}
			
			array_sort(scores,false)
			
			with(Obj_EpicGames_Leaderboard_Rank_Friend)
			{
				Rank = array_get_index(scores,Score)
				
				y = 300+Rank*80
			}			
		}
		
	break
	
	case "EpicGames_Friends_QueryFriends":
		
		with(Obj_EpicGames_Leaderboard_Definition)
			instance_destroy()
		
		if(async_load[?"status"] == EpicGames_Success)
		{
			var count = EpicGames_Friends_GetFriendsCount(AccountID)
			for(var a = 0 ; a < count ; a ++)
			{
				var Friend_AccountID = EpicGames_Friends_GetFriendAtIndex(AccountID,a)
				struct_set(friends,Friend_AccountID,"")
			}
			
			var friends_account_ids = struct_get_names(friends)
			EpicGames_Connect_QueryExternalAccountMappings(userID,0,friends_account_ids)
		}
	break
		
	case "EpicGames_Connect_QueryExternalAccountMappings":
			
		var friends_account_ids = struct_get_names(friends)
		var friends_user_ids = []
		for(var a = 0 ; a < array_length(friends_account_ids) ; a++)
		{
			var user_id = EpicGames_Connect_GetExternalAccountMapping(userID,friends_account_ids[a],0)
			struct_set(friends,friends_account_ids[a],user_id)
			friends_user_ids[a] = user_id
		}
		
		//add me :)
		struct_set(friends,AccountID,userID)
		array_push(friends_user_ids,userID)
		
		show_debug_message($"friends: {friends}" )
		
		EpicGames_Leaderboards_QueryLeaderboardUserScores(userID,"",friends_user_ids,[{StatName: StatSelected, Aggregation: AgregationSeleted}],0,0)
			
	break
}
