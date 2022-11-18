
switch(async_load[?"type"])
{	
	
	case "EpicGames_Leaderboards_QueryLeaderboardUserScores":
		
		var struct = EpicGames_Leaderboards_CopyLeaderboardUserScoreByUserId(userID,"Leaderboard_Stat")
		show_debug_message("Leaderboard_Stat: " + string(struct.Score))
		
		for(var a = 0 ; a < EpicGames_Leaderboards_GetLeaderboardUserScoreCount("Leaderboard_Stat") ; a++)
		{
			var struct = EpicGames_Leaderboards_CopyLeaderboardUserScoreByIndex(a,"Leaderboard_Stat")
			show_debug_message("Leaderboard_Stat: " + string(struct.Score))
		}
		
	break
	
	case "EpicGames_Leaderboards_QueryLeaderboardDefinitions":
		
		var count = EpicGames_Leaderboards_GetLeaderboardDefinitionCount()
		show_debug_message("Leaderboard Count: " + string(count))
		for(var a = 0 ; a < count ; a++)
		{
			var struct = EpicGames_Leaderboards_CopyLeaderboardDefinitionByIndex(a)
			show_debug_message(struct)
			var ins = instance_create_depth(400,300+a*80,0,Obj_EpicGames_Leaderbaord_Definition)
			
			if(variable_struct_exists(struct,"LeaderboardId"))
				ins.LeaderboardId = struct.LeaderboardId

			if(variable_struct_exists(struct,"StatName"))
				ins.StatName = struct.StatName

			if(variable_struct_exists(struct,"StartTime"))
				ins.StartTime = struct.StartTime

			if(variable_struct_exists(struct,"EndTime"))
				ins.EndTime = struct.EndTime
		}
		
	break
	
	case "EpicGames_Leaderboards_QueryLeaderboardRanks":
		
		with(Obj_EpicGames_Leaderbaord_Definition)
			instance_destroy()
		
		var count = EpicGames_Leaderboards_GetLeaderboardRecordCount()
		show_debug_message("RecordCount: " + string(count))
		for(var a = 0 ; a < count ; a++)
		{
			var struct = EpicGames_Leaderboards_CopyLeaderboardRecordByIndex(a)
			show_debug_message(struct)
			var ins = instance_create_depth(400,300+a*80,0,Obj_EpicGames_Leaderbaord_Rank)
			
			if(variable_struct_exists(struct,"UserId"))
				ins.UserId = struct.UserId

			if(variable_struct_exists(struct,"Rank"))
				ins.Rank = struct.Rank

			if(variable_struct_exists(struct,"Score"))
				ins.Score = struct.Score

			if(variable_struct_exists(struct,"UserDisplayName"))
				ins.UserDisplayName = struct.UserDisplayName
		}
		
		//show_debug_message("ScoreCount: " + string(EOS_Leaderboards_GetLeaderboardUserScoreCount()))
		//show_debug_message(EpicGames_Leaderboards_CopyLeaderboardUserScoreByIndex(0))
		
	break
}
