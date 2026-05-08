
var _opts = new EpicLobbyJoinLobbyByIdOptions()
_opts.lobby_id         = lobby_id
_opts.local_user_id    = global.product_user_id
_opts.presence_enabled = true

eos_lobby_join_lobby_by_id(_opts, method(self, function(_info)
{
	// EpicLobbyJoinLobbyCallbackInfo: .result_code, .lobby_id
	if(_info.result_code != EpicResult.Success)
	{
		show_debug_message("eos_lobby_join_lobby_by_id failed: " + eos_api_result_to_string(_info.result_code))
		return
	}

	with(obj_eos_lobbies)
	{
		lobby_id = _info.lobby_id

		request_update_members()

		var RTCRoomName = eos_lobby_get_rtc_room_name(global.product_user_id, lobby_id)
		if(is_string(RTCRoomName) && RTCRoomName != "")
			instance_create_depth(0, 0, 0, obj_rtc, {RoomName: RTCRoomName})
		else
			show_debug_message($"eos_lobby_get_rtc_room_name returned: {RTCRoomName}")

		instance_create_depth(0, 0, 0, obj_eos_lobbies_p2p)

		// Send a "hello" packet to every other member so P2P opens both ways.
		var _details = eos_lobby_copy_lobby_details_handle(lobby_id, global.product_user_id)
		if(_details)
		{
			show_debug_message(eos_lobby_details_copy_attribute_by_key(_details, "lobbyname"))

			var _count = eos_lobby_details_get_member_count(_details)
			show_debug_message($"Joined, now setup P2P: {_count}")
			for(var a = 0; a < _count; a++)
			{
				var _user_id = eos_lobby_details_get_member_by_index(_details, a)
				if(_user_id == global.product_user_id) continue

				var _buff = buffer_create(256, buffer_fixed, 1)
				buffer_write(_buff, buffer_u8, 1)
				eos_p2p_send_packet(global.product_user_id, _user_id, obj_eos_lobbies_p2p.socketName, 0, _buff, buffer_tell(_buff), true, EpicPacketReliability.ReliableOrdered, false)
				buffer_delete(_buff)
			}
			eos_lobby_details_release(_details)
		}
	}
}))
