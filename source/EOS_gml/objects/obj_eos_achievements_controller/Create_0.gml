

eos_achievements_query_definitions(global.product_user_id, function(data) {
    show_debug_message("Query callback result: " + string(data.result_code))
    
    if (data.result_code != EpicResult.Success) {
        show_debug_message("Query FAILED: " + string(data.result_code))
        exit
    }
    
    var count = eos_achievements_get_achievement_definition_count()
    show_debug_message("Achievement count: " + string(count))
    
    for (var a = 0; a < count; a++) {
        var _data = eos_achievements_copy_achievement_definition_v2_by_index(a)
        
        // Debug each field individually
        show_debug_message("Index " + string(a) + ":")
        show_debug_message("  - achievement_id: " + string(_data.achievement_id))
        show_debug_message("  - unlocked_display_name: " + string(_data.unlocked_display_name))
        show_debug_message("  - unlocked_icon_url: " + string(_data.unlocked_icon_url))
        
        var ins = instance_create_depth(300+a*300, room_height/2, 0, obj_eos_achievement, {data: _data})
    }
	
	
	//Now let's check our achievements state
	eos_achievements_query_player_achievements(global.product_user_id,global.product_user_id,function(data){

		show_debug_message("=== PLAYER ACHIEVEMENTS QUERY ===")
		show_debug_message($"Query Result: {data.result_code}")

		if(data.result_code != EpicResult.Success) {
			show_debug_message("Player achievements query FAILED: " + string(data.result_code))
			show_debug_message("Last error: " + eos_get_last_error())
			exit
		}

		var count = eos_achievements_get_player_achievement_count(global.product_user_id, global.product_user_id)
		show_debug_message("Player achievement count: " + string(count))

		for(var a = 0; a < count; a++) {
			var struct = eos_achievements_copy_player_achievement_by_index(global.product_user_id, global.product_user_id, a)

			show_debug_message("Index " + string(a) + ":")
			show_debug_message("  - achievement_id: " + string(struct.achievement_id))
			show_debug_message("  - unlock_time: " + string(struct.unlock_time))
			show_debug_message("  - progress: " + string(struct.progress))

			if(struct.achievement_id != "" && struct.unlock_time > 0) {
				with(obj_eos_achievement) {
					if(id.data.achievement_id == struct.achievement_id) {
						locked = false
						show_debug_message("Setting achievement " + string(struct.achievement_id) + " to UNLOCKED")
						break
					}
				}
			}
		}
	})
})




