
with(obj_eos_lobbies_lobby)
	instance_destroy()

var result = eos_lobby_create_lobby_search(10)
show_debug_message($"CreateLobbySearch {EpicResult_to_string(result)}")

var BucketId = "GameMode:Region:MapName"

eos_lobby_search_set_parameter(EOS_COMPARISON_OP.EQUAL,{key:"bucket",value_type: EOS_ATTRIBUTE_TYPE.STRING,value: BucketId})
eos_lobby_search_find(global.product_user_id)
