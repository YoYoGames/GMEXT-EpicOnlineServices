
with(obj_eos_leaderboard_rank)
	instance_destroy()

eos_leaderboards_query_ranks(global.product_user_id,data.leaderboard_id,function(data){

		with(obj_eos_leaderboard_definition)
			instance_destroy()
		
		var count = eos_leaderboards_get_record_count()
		for(var a = 0 ; a < count ; a++)
		{
			var struct = eos_leaderboards_copy_record_by_index(a)
			instance_create_depth(400,300+a*80,0,obj_eos_leaderboard_rank,{data:struct})
		}
	})


