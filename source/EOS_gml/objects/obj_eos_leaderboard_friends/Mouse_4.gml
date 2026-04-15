
with(obj_eos_leaderboard_definition)
	instance_destroy()
	
with(obj_eos_leaderboard_rank)
	instance_destroy()

stat_selected = "Leaderboard_Stat"
agregation_seleted = EOS_LEADERBOARD_AGGREGATION.LATEST;

//stat_selected = "Leaderboard_Stat_2"
//agregation_seleted = EOS_LEADERBOARD_AGGREGATION.Max

eos_friends_query_friends(global.epic_account_id)

//eos_leaderboards_query_leaderboard_user_score(global.product_user_id,global.product_user_id,"YYEpicTest_Leaderboard","Leaderboard_Stat",EOS_LEADERBOARD_AGGREGATION.Max,0,0);
