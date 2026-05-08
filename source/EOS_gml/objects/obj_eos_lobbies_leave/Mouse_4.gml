
show_debug_message("[leave] Mouse_4 fired")

if(!instance_exists(obj_eos_lobbies))
{
	show_debug_message("[leave] obj_eos_lobbies does not exist")
	return
}

var _lobbies = obj_eos_lobbies
if(_lobbies.lobby_id == "")
{
	show_debug_message("[leave] lobby_id is empty — nothing to leave")
	return
}

show_debug_message($"[leave] calling eos_lobby_leave_lobby for {_lobbies.lobby_id}")

eos_lobby_leave_lobby(_lobbies.lobby_id, global.product_user_id, method(_lobbies, function(_info)
{
	// EpicLobbyLeaveLobbyCallbackInfo: .result_code, .lobby_id
	show_debug_message($"[leave] callback fired: {eos_api_result_to_string(_info.result_code)} for lobby {_info.lobby_id}")

	if(_info.result_code != EpicResult.Success) return

	lobby_id = ""
	with(obj_rtc) instance_destroy()
	with(obj_eos_lobbies_p2p) instance_destroy()
	with(obj_eos_lobbies_member) instance_destroy()
}))
