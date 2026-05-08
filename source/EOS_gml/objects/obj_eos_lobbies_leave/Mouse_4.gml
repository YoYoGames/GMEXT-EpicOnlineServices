
with(obj_eos_lobbies)
{
	if(lobby_id == "") return

	eos_lobby_leave_lobby(lobby_id, global.product_user_id, method(self, function(_info)
	{
		// EpicLobbyLeaveLobbyCallbackInfo: .result_code, .lobby_id
		if(_info.result_code != EpicResult.Success)
		{
			show_debug_message("eos_lobby_leave_lobby failed: " + eos_api_result_to_string(_info.result_code))
			return
		}

		lobby_id = ""
		with(obj_rtc) instance_destroy()
		with(obj_eos_lobbies_p2p) instance_destroy()
		with(obj_eos_lobbies_member) instance_destroy()
	}))
}
