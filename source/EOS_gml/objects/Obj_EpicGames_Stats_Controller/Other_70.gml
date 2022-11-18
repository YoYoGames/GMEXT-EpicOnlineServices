
switch(async_load[?"type"])
{	
	case "EpicGames_Stats_QueryStats":
		
		//YYStructAddDouble(&Struct, "status", (double)result);
		//	YYStructAddString(&Struct, "status_message", EpicGames_EResult_ToString(result));
			
		var count = EpicGames_Stats_GetStatsCount(userID)
		show_debug_message("EpicGames_Stats_GetStatsCount: " + string(count))
		for(var a = 0 ; a < count ; a++)
		{
			var struct = EpicGames_Stats_CopyStatByIndex(userID,a)
			show_debug_message(struct)
			
			var ins = instance_create_depth(300,300+a*80,0,Obj_EpicGames_Stat)
			
			if(variable_struct_exists(struct,"Name"))
				ins.Name = struct.Name

			// Note: Undefined = EpicGames_STATS_QUERYSTATS_API_LATEST
			if(variable_struct_exists(struct,"StartTime"))
				ins.StartTime = struct.StartTime

			if(variable_struct_exists(struct,"EndTime"))
				ins.EndTime = struct.EndTime

			if(variable_struct_exists(struct,"Value"))
				ins.Value = struct.Value
		}
		
	break
}
