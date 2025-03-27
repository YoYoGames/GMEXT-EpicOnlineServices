
switch(async_load[? "type"])
{	
	case "eos_achievements_query_definitions":
		
		if(async_load[? "status"] != EOS_SUCCESS)
			exit
		
		eos_achievements_query_player_achievements(userID,userID)
		
		var count = eos_achievements_get_achievement_definition_count()
		for(var a = 0 ; a < count ; a++)
		{
			var struct = eos_achievements_copy_achievement_definition_v2_by_index(a)
			var ins = instance_create_depth(300+a*300,room_height/2,0,Obj_EpicGames_Achievement,struct)
		}
		
	break
	
	case "eos_achievements_query_player_achievements":
		
		if(async_load[? "status"] != EOS_SUCCESS)
			exit
	
		var count = eos_achievements_get_player_achievement_count(userID)
		for(var a = 0 ; a < count ; a++)
		{
			var struct = eos_achievements_copy_player_achievement_by_index(userID,userID,a)
			if(struct.unlock_time)
			with(Obj_EpicGames_Achievement)
			if(achievement_id == struct.achievement_id)
			{
				locked = false
				break
			}
		}
	
	break
}
