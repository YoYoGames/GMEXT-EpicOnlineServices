
switch(async_load[? "type"])
{
	case "eos_leaderboards_query_leaderboard_definitions":
		
		var count = eos_leaderboards_get_leaderboard_definition_count()
		
		for(var a = 0 ; a < count ; a++)
		{
			var struct = eos_leaderboards_copy_leaderboard_definition_by_index(a)
			instance_create_depth(400,300+a*80,0,Obj_EpicGames_Leaderboard_Definition,struct)
		}
		
	break
	
	case "eos_leaderboards_query_leaderboard_ranks":
		
		with(Obj_EpicGames_Leaderboard_Definition)
			instance_destroy()
		
		var count = eos_leaderboards_get_leaderboard_record_count()
		
		for(var a = 0 ; a < count ; a++)
		{
			var struct = eos_leaderboards_copy_leaderboard_record_by_index(a)
			instance_create_depth(400,300+a*80,0,Obj_EpicGames_Leaderboard_Rank,struct)
		}
		
	break
}
