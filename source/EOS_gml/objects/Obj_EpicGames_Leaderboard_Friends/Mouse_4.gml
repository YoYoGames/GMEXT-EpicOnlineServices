
with(Obj_EpicGames_Leaderboard_Definition)
	instance_destroy()
	
with(Obj_EpicGames_Leaderboard_Rank)
	instance_destroy()

stat_selected = "Leaderboard_Stat"
agregation_seleted = EOS_LeaderboardAggregation.Latest;

//stat_selected = "Leaderboard_Stat_2"
//agregation_seleted = EOS_LeaderboardAggregation.Max

eos_friends_query_friends(AccountID)

//eos_leaderboards_query_leaderboard_user_score(userID,userID,"YYEpicTest_Leaderboard","Leaderboard_Stat",EOS_LeaderboardAggregation.Max,0,0);
