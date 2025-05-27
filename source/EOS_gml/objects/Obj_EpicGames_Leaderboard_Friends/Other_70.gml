
switch(async_load[? "type"])
{	
	case "eos_leaderboards_query_leaderboard_user_scores":
		
		var count = eos_leaderboards_get_leaderboard_user_score_count("Leaderboard_Stat")
		show_debug_message($"count: {count}")
		for(var a = 0 ; a < count ; a++)
		{
			var struct = eos_leaderboards_copy_leaderboard_user_score_by_index(a,"Leaderboard_Stat")
			var ins = instance_create_depth(400,300+a*80,0,Obj_EpicGames_Leaderboard_Rank_Friend,struct)
			show_debug_message("CREATED: " + struct.user_id)
			//array_length(user_id,)
			
			if(variable_struct_exists(struct,"user_id"))
			{
				ins.user_id = struct.user_id
				
				var account_ids = struct_get_names(friends)
				for(var b = 0 ; b < array_length(account_ids) ; b++)
				{
					var user_id = struct_get(friends,account_ids[b])
					if(ins.user_id == user_id)
					{
					    ins.mAccountID = account_ids[a]
						break
					}
				}
			}
			
			if(variable_struct_exists(struct,"score"))
				ins.score = struct.score
			
			var scores = []
			var index = 0
			with(Obj_EpicGames_Leaderboard_Rank_Friend)
			{
				scores[index] = id.score
				index ++
			}
			
			array_sort(scores,false)
			
			with(Obj_EpicGames_Leaderboard_Rank_Friend)
			{
				rank = array_get_index(scores,id.score)+1
				
				y = 100+rank*80
			}			
		}
		
	break
	
	case "eos_friends_query_friends":
		
		with(Obj_EpicGames_Leaderboard_Definition)
			instance_destroy()
		
		if(async_load[? "status"] == EOS_RESULT.Success)
		{
			var count = eos_friends_get_friends_count(AccountID)
			for(var a = 0 ; a < count ; a ++)
			{
				var Friend_AccountID = eos_friends_get_friend_at_index(AccountID,a)
				struct_set(friends,Friend_AccountID,"")
			}
			
			var friends_account_ids = struct_get_names(friends)
			eos_connect_query_external_account_mappings(userID,0,friends_account_ids)
		}
	break
		
	case "eos_connect_query_external_account_mappings":
			
		var friends_account_ids = struct_get_names(friends)
		var friends_user_ids = []
		for(var a = 0 ; a < array_length(friends_account_ids) ; a++)
		{
			var user_id = eos_connect_get_external_account_mapping(userID,friends_account_ids[a],0)
			struct_set(friends,friends_account_ids[a],user_id)
			friends_user_ids[a] = user_id
		}
		
		//add me :)
		struct_set(friends,AccountID,userID)
		array_push(friends_user_ids,userID)
		
		show_debug_message($"friends: {friends}" )
		
		show_debug_message([userID,"",friends_user_ids,[{stat_name: stat_selected, aggregation: agregation_seleted}],0,0])
		eos_leaderboards_query_leaderboard_user_scores(userID,"",friends_user_ids,[{stat_name: stat_selected, aggregation: agregation_seleted}],0,0)
		
	break
}
