
var _opts = new EpicLobbyCreateLobbyOptions()
_opts.bucket_id                         = "GameMode:Region:MapName"
_opts.allow_invites                     = true
_opts.disable_host_migration            = true
_opts.local_user_id                     = global.product_user_id
_opts.max_lobby_members                 = 10
_opts.permission_level                  = EpicLobbyPermissionLevel.PublicAdvertised
_opts.presence_enabled                  = true
_opts.rejoin_after_kick_requires_invite = false
_opts.enable_join_by_id                 = true
_opts.enable_rtc_room                   = false

show_debug_message($"_opts: {_opts}")

eos_lobby_create_lobby(_opts, method(self, function(_info)
{
	// EpicLobbyCreateLobbyCallbackInfo: .result_code, .lobby_id
	show_debug_message("eos_lobby_create_lobby: " + eos_api_result_to_string(_info.result_code))
	if(_info.result_code != EpicResult.Success) return

	with(obj_eos_lobbies)
	{
		lobby_id = _info.lobby_id

		request_update_members()

		var RTCRoomName = eos_lobby_get_rtc_room_name(global.product_user_id, lobby_id)
		show_debug_message($"RTCRoomName: {RTCRoomName}")
		if(is_string(RTCRoomName) && RTCRoomName != "")
			instance_create_depth(0, 0, 0, obj_rtc, {RoomName: RTCRoomName})
		else
			show_debug_message("eos_lobby_get_rtc_room_name returned no room — RTC features will not start")

		instance_create_depth(0, 0, 0, obj_eos_lobbies_p2p)

		// Tag the lobby with a display name attribute so search can show it.
		var _mod_id = eos_lobby_update_lobby_modification(lobby_id, global.product_user_id)
		if(_mod_id != 0)
		{
			var _attr = new EpicLobbyModificationAddAttributeOptions()
			_attr.key        = "lobbyname"
			_attr.value      = mDisplayName + "'s Lobby"
			_attr.visibility = EpicLobbyAttributeVisibility.Public
			eos_lobby_lobby_modification_add_attribute(_mod_id, _attr)

			eos_lobby_update_lobby(lobby_id, _mod_id)
			eos_lobby_lobby_modification_release(_mod_id)
		}
	}
}))
