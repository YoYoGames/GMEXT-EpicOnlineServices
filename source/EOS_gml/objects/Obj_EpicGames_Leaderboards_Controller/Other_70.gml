
switch(async_load[? "type"])
{
	case "eos_leaderboards_query_leaderboard_definitions":
		
		var count = eos_leaderboards_get_leaderboard_definition_count()
		
		for(var a = 0 ; a < count ; a++)
		{
			var struct = eos_leaderboards_copy_leaderboard_definition_by_index(a)
			
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
	
	case "eos_leaderboards_query_leaderboard_ranks":
		
		with(Obj_EpicGames_Leaderboard_Definition)
			instance_destroy()
		
		var count = eos_leaderboards_get_leaderboard_record_count()
		
		for(var a = 0 ; a < count ; a++)
		{
			var struct = eos_leaderboards_copy_leaderboard_record_by_index(a)
			
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
