
eos_stats_query_stats(global.product_user_id,global.product_user_id,-1,-1,
	function(data){

		//YYStructAddDouble(&Struct, "status", (double)result);
		//	YYStructAddString(&Struct, "status_message", eos_e_result_to_string(result));
		
		show_debug_message(data)
		
		if(data.result_code != EpicResult.Success)
			{return}
		
		var count = eos_stats_get_stats_count(global.product_user_id,global.product_user_id)
		show_debug_message("eos_stats_get_stats_count: " + string(count))
		for(var a = 0 ; a < count ; a++)
		{
			var struct = eos_stats_copy_stat_by_index(global.product_user_id,global.product_user_id,a)
			show_debug_message(struct)
			var ins = instance_create_depth(300,300+a*80,0,obj_eos_stat,{data: struct})
		}
	})
