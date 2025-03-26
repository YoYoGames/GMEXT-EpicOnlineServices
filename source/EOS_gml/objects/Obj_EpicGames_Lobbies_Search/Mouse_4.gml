
with(Obj_EpicGames_Lobby)
	instance_destroy()

var result = eos_lobby_create_lobby_search(10)
show_debug_message($"CreateLobbySearch {eos_result_to_string(result)}")

var BucketId = "GameMode:Region:MapName"

eos_lobby_search_set_parameter(EOS_ComparisonOp.EQUAL,{Key:"bucket",ValueType: EOS_AttributeType.STRING,Value: BucketId})
eos_lobby_search_find(userID)
