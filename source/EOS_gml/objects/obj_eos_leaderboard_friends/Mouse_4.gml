
with(obj_eos_leaderboard_definition)
	instance_destroy()
	
with(obj_eos_leaderboard_rank)
	instance_destroy()

stat_selected = "Leaderboard_Stat"
agregation_seleted = EpicLeaderboardAggregation.Latest;

//stat_selected = "Leaderboard_Stat_2"
//agregation_seleted = EpicLeaderboardAggregation.Max

if(!variable_instance_exists(id,"friend_object"))
	friend_object = obj_eos_friend

friend_counter_index = 0

eos_friends_query_friends(global.epic_account_id,function(data){
	if(data.result_code != EpicResult.Success)
		return 0
	
		friends = {}
		var count = eos_friends_get_friends_count(global.epic_account_id)
		for(var a = 0 ; a < count ; a ++)
		{
			var Friend_AccountID = eos_friends_get_friend_at_index(global.epic_account_id,a)
			request = eos_user_info_query_user_info(global.epic_account_id,Friend_AccountID,function(data){
				
				if(data.result_code != EpicResult.Success)
					return 0
					
				var struct = eos_user_info_copy_user_info(global.epic_account_id,data.target_user_id)
					
				struct_set(friends,data.target_user_id,struct)
				
				var nope = false
				var _arrayName = struct_get_names(friends)
				for(var b = 0 ; b < array_length(_arrayName) ; b++)
					if(struct_names_count(struct_get(friends,_arrayName[b])) == 0)
					{
						nope = true
						break
					}
				if(nope)
					{return}
					
				//Ok, let's request!
				var friends_account_ids = struct_get_names(friends)
				eos_connect_query_external_account_mappings(global.product_user_id,0,friends_account_ids,function(data){
						
					if(data.result_code != EpicResult.Success)
						return 0
						
					var friends_account_ids = struct_get_names(friends)
		
					for(var c = 0 ; c < array_length(friends_account_ids) ; c++)
					{
						var user_id = eos_connect_get_external_account_mapping(global.product_user_id,0,friends_account_ids[c])
						struct_set(struct_get(friends,friends_account_ids[c]),"user_id",user_id)
					}
					
					var friends_account_ids = struct_get_names(friends)
					var friends_user_ids = []
					for(var a = 0 ; a < array_length(friends_account_ids) ; a++)
					{
						var user_id = eos_connect_get_external_account_mapping(global.product_user_id, 0, friends_account_ids[a])
						struct_set(friends,friends_account_ids[a],user_id)
						friends_user_ids[a] = user_id
					}
		
					//add me :)
					struct_set(friends,global.epic_account_id,global.product_user_id)
					array_push(friends_user_ids,global.product_user_id)
		
					show_debug_message($"friends: {friends}")

					var stat_query = new EpicLeaderboardStatQuery()
					stat_query.stat_name = stat_selected
					stat_query.aggregation = agregation_seleted
show_debug_message("eos_leaderboards_query_user_scores")
show_debug_message(friends_user_ids)
show_debug_message(stat_query)

					eos_leaderboards_query_user_scores(
						global.product_user_id,
						friends_user_ids,
						[stat_query],
						0,
						0,
						//function(data){
						//	show_debug_message("Callback")
						//	show_debug_message(data)
						//	show_message_async(data)
						//	if(data.result_code != EpicResult.Success)
						//		return 0
						//	// Leaderboard scores queried successfully
						//}
						function(data){
						    if(data.result_code != EpicResult.Success)
						        return 0

						    // Get the count of cached scores
						    var score_count = eos_leaderboards_get_user_score_count(stat_selected)
						    show_debug_message($"Total scores cached: {score_count}")

						    // Retrieve each score
						    for(var i = 0; i < score_count; i++)
						    {
						        var user_score = eos_leaderboards_copy_user_score_by_index(stat_selected, i)
						        var friend_info = struct_get(friends, user_score.user_id)
        
						        show_debug_message($"Score {i}: User={user_score.user_id}, Score={user_score.score}")
        
						        // Create UI elements for each friend's score
						        if(friend_info != undefined)
						        {
						            var friend_ins = instance_create_depth(
						                x, 
						                y + 100 + friend_counter_index * 80, 
						                0, 
						                friend_object, 
						                {
						                    data: friend_info,
						                    score: user_score.score
						                }
						            )
						            friend_counter_index++
						        }
						    }
						}
					)
				})
			})
				
			struct_set(friends,Friend_AccountID,{})
		}
	})

