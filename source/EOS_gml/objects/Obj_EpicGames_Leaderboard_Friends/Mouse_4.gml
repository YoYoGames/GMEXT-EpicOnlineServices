
with(Obj_EpicGames_Leaderboard_Definition)
	instance_destroy()
	
with(Obj_EpicGames_Leaderboard_Rank)
	instance_destroy()

StatSelected = "Leaderboard_Stat"
AgregationSeleted = EpicGames_LA_Latest

//StatSelected = "Leaderboard_Stat_2"
//AgregationSeleted = EpicGames_LA_Max

EpicGames_Friends_QueryFriends(AccountID)

//EpicGames_Leaderboards_QueryLeaderboardUserScore(userID,userID,"YYEpicTest_Leaderboard","Leaderboard_Stat",EpicGames_LA_Max,0,0);
