
switch(async_load[?"type"])
{
	case "EpicGames_Leaderboards_QueryLeaderboardDefinitions":
		
		var count = EpicGames_Leaderboards_GetLeaderboardDefinitionCount()
		
		for(var a = 0 ; a < count ; a++)
		{
			var struct = EpicGames_Leaderboards_CopyLeaderboardDefinitionByIndex(a)
			
			var ins = instance_create_depth(400,300+a*80,0,Obj_EpicGames_Leaderboard_Definition)
			
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
		
		with(Obj_EpicGames_Leaderboard_Definition)
			instance_destroy()
		
		var count = EpicGames_Leaderboards_GetLeaderboardRecordCount()
		
		for(var a = 0 ; a < count ; a++)
		{
			var struct = EpicGames_Leaderboards_CopyLeaderboardRecordByIndex(a)
			
			var ins = instance_create_depth(400,300+a*80,0,Obj_EpicGames_Leaderboard_Rank)
			
			if(variable_struct_exists(struct,"UserId"))
				ins.UserId = struct.UserId

			if(variable_struct_exists(struct,"Rank"))
				ins.Rank = struct.Rank

			if(variable_struct_exists(struct,"Score"))
				ins.Score = struct.Score

			if(variable_struct_exists(struct,"UserDisplayName"))
				ins.UserDisplayName = struct.UserDisplayName
		}
		
	break
}
