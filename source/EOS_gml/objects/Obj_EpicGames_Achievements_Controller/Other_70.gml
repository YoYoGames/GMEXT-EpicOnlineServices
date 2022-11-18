
switch(async_load[?"type"])
{	
	case "EpicGames_Achievements_QueryDefinitions":
		
		if(async_load[?"status"] != EpicGames_Success)
			exit
		
		EpicGames_Achievements_QueryPlayerAchievements(userID,userID)
		
		var count = EpicGames_Achievements_GetAchievementDefinitionCount()
		for(var a = 0 ; a < count ; a++)
		{
			var struct = EpicGames_Achievements_CopyAchievementDefinitionV2ByIndex(a)
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
	
	case "EpicGames_Achievements_QueryPlayerAchievements":
		
		if(async_load[?"status"] != EpicGames_Success)
			exit
	
		var count = EpicGames_Achievements_GetPlayerAchievementCount(userID)
		for(var a = 0 ; a < count ; a++)
		{
			var struct = EpicGames_Achievements_CopyPlayerAchievementByIndex(userID,userID,a)
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
