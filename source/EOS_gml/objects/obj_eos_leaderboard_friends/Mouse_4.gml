
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

					//Map by ProductUserId (what leaderboard scores are keyed by) without
					//losing the display-name info struct we already fetched per friend.
					friends_by_puid = {}
					friends_user_ids = []
					for(var c = 0 ; c < array_length(friends_account_ids) ; c++)
					{
						var user_id = eos_connect_get_external_account_mapping(global.product_user_id,0,friends_account_ids[c])
						var friend_struct = struct_get(friends,friends_account_ids[c])
						struct_set(friend_struct,"user_id",user_id)
						struct_set(friends_by_puid,user_id,friend_struct)
						friends_user_ids[c] = user_id
					}

					//add me :) - need to fetch my own display name too, since
					//EpicLeaderboardUserScore only contains user_id/score, no name.
					eos_user_info_query_user_info(global.epic_account_id,global.epic_account_id,function(_self_data){
						if(_self_data.result_code != EpicResult.Success)
							return 0

						var my_struct = eos_user_info_copy_user_info(global.epic_account_id,global.epic_account_id)
						struct_set(my_struct,"user_id",global.product_user_id)
						struct_set(friends_by_puid,global.product_user_id,my_struct)
						array_push(friends_user_ids,global.product_user_id)

						show_debug_message($"friends_by_puid: {friends_by_puid}")

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
							EOS_LEADERBOARDS_TIME_UNDEFINED,
							EOS_LEADERBOARDS_TIME_UNDEFINED,
							function(data){
							    if(data.result_code != EpicResult.Success)
							        return 0

							    // Get the count of cached scores
							    var score_count = eos_leaderboards_get_user_score_count(stat_selected)
							    show_debug_message($"Total scores cached: {score_count}")

							    // Collect first, since this queries specific friends' scores (not the
							    // global leaderboard) -- the SDK doesn't hand back a rank here, and the
							    // results aren't guaranteed sorted, so rank has to be computed locally
							    // by sorting the collected scores before creating any UI.
							    var _entries = []
							    for(var i = 0; i < score_count; i++)
							    {
							        var user_score = eos_leaderboards_copy_user_score_by_index(stat_selected, i)
							        var friend_info = struct_get(friends_by_puid, user_score.user_id)

							        if(friend_info != undefined)
							        {
							            array_push(_entries, {
							                user_id: user_score.user_id,
							                score: user_score.score,
							                user_display_name: friend_info.display_name
							            })
							        }
							    }

							    // Higher score = better rank.
							    array_sort(_entries, function(_a, _b) { return _b.score - _a.score })

							    for(var i = 0; i < array_length(_entries); i++)
							    {
							        var _entry = _entries[i]
							        show_debug_message($"Friend rank {i + 1}: {_entry.user_display_name} score={_entry.score}")

							        var friend_ins = instance_create_depth(
							            500,
							            200 + friend_counter_index * 80,
							            0,
							            obj_eos_leaderboard_rank,//friend_object,
							            {
							                data: {
							                    user_id: _entry.user_id,
							                    rank: i + 1,
							                    score: _entry.score,
							                    user_display_name: _entry.user_display_name
							                }
							            }
							        )
							        friend_counter_index++
							    }
							}
						)
					})
				})
			})
				
			struct_set(friends,Friend_AccountID,{})
		}
	})

