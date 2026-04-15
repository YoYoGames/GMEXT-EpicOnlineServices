

eos_leaderboards_query_definitions(global.product_user_id, -1/*EOS_LEADERBOARDS_TIME_UNDEFINED*/,-1/*EOS_LEADERBOARDS_TIME_UNDEFINED*/,function(data){		
		var count = eos_leaderboards_get_definition_count()
		for(var a = 0 ; a < count ; a++)
		{
			var struct = eos_leaderboards_copy_definition_by_index(a)
			instance_create_depth(400,300+a*80,0,obj_eos_leaderboard_definition,{data: struct})
		}
	});

