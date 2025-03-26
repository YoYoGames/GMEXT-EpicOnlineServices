
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
			show_debug_message(struct)
			
			var ins = instance_create_depth(300+a*300,room_height/2,0,Obj_EpicGames_Achievement)
			if(variable_struct_exists(struct,"bIsHidden"))
				ins.bIsHidden = struct.bIsHidden
			if(variable_struct_exists(struct,"AchievementId"))
				ins.AchievementId = struct.AchievementId
			if(variable_struct_exists(struct,"UnlockedDisplayName"))
				ins.UnlockedDisplayName = struct.UnlockedDisplayName
			if(variable_struct_exists(struct,"UnlockedDescription"))
				ins.UnlockedDescription = struct.UnlockedDescription
			if(variable_struct_exists(struct,"LockedDisplayName"))
				ins.LockedDisplayName = struct.LockedDisplayName
			if(variable_struct_exists(struct,"LockedDescription"))
				ins.LockedDescription = struct.LockedDescription
			if(variable_struct_exists(struct,"FlavorText"))
				ins.FlavorText = struct.FlavorText
			if(variable_struct_exists(struct,"UnlockedIconURL"))
				ins.UnlockedIconURL = struct.UnlockedIconURL
			if(variable_struct_exists(struct,"LockedIconURL"))
				ins.LockedIconURL = struct.LockedIconURL
		}
		
	break
	
	case "eos_achievements_query_player_achievements":
		
		if(async_load[? "status"] != EOS_SUCCESS)
			exit
	
		var count = eos_achievements_get_player_achievement_count(userID)
		for(var a = 0 ; a < count ; a++)
		{
			var struct = eos_achievements_copy_player_achievement_by_index(userID,userID,a)
			if(struct.UnlockTime)
			with(Obj_EpicGames_Achievement)
			if(AchievementId == struct.AchievementId)
			{
				locked = false
				break
			}
		}
	
	break
}
