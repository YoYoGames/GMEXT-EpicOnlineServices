
with(obj_eos_lobbies_lobby)
	instance_destroy()

var result = eos_lobby_create_lobby_search(10)
show_debug_message($"CreateLobbySearch {eos_api_result_to_string(result)}")

var BucketId = "GameMode:Region:MapName"

eos_lobby_search_set_parameter(EpicComparisonOp.Equal,{key:"bucket",value_type: EpicAttributeType.String,value: BucketId})
eos_lobby_search_find(global.product_user_id)
