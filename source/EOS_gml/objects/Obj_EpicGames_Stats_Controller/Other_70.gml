
switch(async_load[? "type"])
{	
	case "eos_stats_query_stats":
		
		//YYStructAddDouble(&Struct, "status", (double)result);
		//	YYStructAddString(&Struct, "status_message", eos_e_result_to_string(result));
			
		var count = eos_stats_get_stats_count(userID)
		show_debug_message("eos_stats_get_stats_count: " + string(count))
		for(var a = 0 ; a < count ; a++)
		{
			var struct = eos_stats_copy_stat_by_index(userID,a)
			show_debug_message(struct)
			var ins = instance_create_depth(300,300+a*80,0,Obj_EpicGames_Stat,struct)
		}
		
	break
}
