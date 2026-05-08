
eos_lobby_query_invites(global.product_user_id, function(_info)
{
	// EpicLobbyQueryInvitesCallbackInfo: .result_code, .local_user_id
	if(_info.result_code != EpicResult.Success)
	{
		show_debug_message("eos_lobby_query_invites failed: " + eos_api_result_to_string(_info.result_code))
		return
	}

	var _count = eos_lobby_get_invite_count(global.product_user_id)
	if(_count == 0)
	{
		show_message_async("No Invitations... :(")
		return
	}

	for(var a = 0; a < _count; a++)
	{
		var _invite_id = eos_lobby_get_invite_id_by_index(global.product_user_id, a)
		show_debug_message($"Invite #{a}: {_invite_id}")

		var _details_id = eos_lobby_copy_lobby_details_handle_by_invite_id(_invite_id)
		if(_details_id == 0) continue

		var _struct    = eos_lobby_details_copy_info(_details_id)
		var _attribute = eos_lobby_details_copy_attribute_by_key(_details_id, "lobbyname")
		eos_lobby_details_release(_details_id)

		var _ins = instance_create_depth(x, y + 100 + a * 100, 0, obj_eos_lobbies_lobby, _struct)
		// Show the lobby name if the host set one; fall back to lobby_id.
		_ins.text = (is_struct(_attribute) && struct_exists(_attribute, "value") && _attribute.value != "")
			? _attribute.value
			: _struct.lobby_id
	}
})
