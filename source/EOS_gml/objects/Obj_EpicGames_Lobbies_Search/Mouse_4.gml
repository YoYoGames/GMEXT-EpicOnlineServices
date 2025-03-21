
with(Obj_EpicGames_Lobby)
	instance_destroy()

var result = EpicGames_Lobby_CreateLobbySearch(10)
show_debug_message($"CreateLobbySearch {EpicGames_Result_ToString(result)}")

var BucketId = "GameMode:Region:MapName"

EpicGames_LobbySearch_SetParameter(EOS_ComparisonOp.EQUAL,{Key:"bucket",ValueType: EOS_AttributeType.STRING,Value: BucketId})
EpicGames_LobbySearch_Find(userID)
