
with(obj_eos_lobbies_lobby)
	instance_destroy()

// Release any prior search handle so we don't leak.
if(variable_global_exists("lobby_search_id") && global.lobby_search_id != 0)
{
	eos_lobby_lobby_search_release(global.lobby_search_id)
	global.lobby_search_id = 0
}

global.lobby_search_id = eos_lobby_create_lobby_search(10)
show_debug_message($"CreateLobbySearch id={global.lobby_search_id}")
if(global.lobby_search_id == 0) return

var _param = new EpicLobbySearchSetParameterOptions()
_param.key           = "bucket"
_param.value         = "GameMode:Region:MapName"
_param.comparison_op = EpicComparisonOp.Equal
eos_lobby_lobby_search_set_parameter(global.lobby_search_id, _param)

eos_lobby_lobby_search_find(global.lobby_search_id, global.product_user_id, method(self, function(_info)
{
	// EpicLobbySearchFindCallbackInfo: .result_code
	if(_info.result_code != EpicResult.Success)
	{
		show_debug_message("eos_lobby_lobby_search_find failed: " + eos_api_result_to_string(_info.result_code))
		return
	}

	var _count = eos_lobby_lobby_search_get_search_result_count(global.lobby_search_id)

	if(_count == 0)
	{
		show_message_async("No Lobbies Found")
		return
	}

	for(var a = 0; a < _count; a++)
	{
		var _details_id = eos_lobby_lobby_search_copy_search_result_by_index(global.lobby_search_id, a)
		if(_details_id == 0) continue

		var _struct    = eos_lobby_details_copy_info(_details_id)
		var _attribute = eos_lobby_details_copy_attribute_by_key(_details_id, "lobbyname")
		eos_lobby_details_release(_details_id)

		var _ins = instance_create_depth(x, y + 100 + a * 100, 0, obj_eos_lobbies_lobby, _struct)
		_ins.text = _attribute.value
	}
}))
