
with(Obj_EpicGames_Leaderboard_Definition)
	instance_destroy()
	
with(Obj_EpicGames_Leaderboard_Rank)
	instance_destroy()

stat_selected = "Leaderboard_Stat"
agregation_seleted = EOS_LA_LATEST

//stat_selected = "Leaderboard_Stat_2"
//agregation_seleted = EOS_LA_MAX

eos_friends_query_friends(AccountID)

//eos_leaderboards_query_leaderboard_user_score(userID,userID,"YYEpicTest_Leaderboard","Leaderboard_Stat",EOS_LA_MAX,0,0);
