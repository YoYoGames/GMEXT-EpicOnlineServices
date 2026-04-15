
eos_achievements_query_definitions(global.product_user_id,function(data){

		if(data.result_code != EpicResult.Success)
			exit
		
		var count = eos_achievements_get_achievement_definition_count()
		for(var a = 0 ; a < count ; a++)
		{
			var _data = eos_achievements_copy_achievement_definition_v2_by_index(a)
			var ins = instance_create_depth(300+a*300,room_height/2,0,obj_eos_achievement,{data:_data})
		}
		
		eos_achievements_query_player_achievements(global.product_user_id,global.product_user_id,function(data){
		
				if(data.result_code != EpicResult.Success)
					exit
				
				var count = eos_achievements_get_player_achievement_count(global.product_user_id,global.product_user_id)
				for(var a = 0 ; a < count ; a++)
				{
					var struct = eos_achievements_copy_player_achievement_by_index(global.product_user_id,global.product_user_id,a)
					if(struct.unlock_time)
					with(obj_eos_achievement)
					if(id.data.achievement_id == struct.achievement_id)
					{
						locked = false
						break
					}
				}
			})
		})

//show_debug_message("Notify: " + string(eos_achievements_add_notify_achievements_unlocked_v2()))
