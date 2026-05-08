
eos_lobby_query_invites(global.product_user_id, method(self, function(_info)
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

	//TODO: needs eos_lobby_copy_lobby_details_handle_by_invite_id (not yet exposed
	// in the new extension) to display the invited lobby's name like the old code did.
	// For now we just list the invite IDs.
	for(var a = 0; a < _count; a++)
	{
		var _invite_id = eos_lobby_get_invite_id_by_index(global.product_user_id, a)
		show_debug_message($"Invite #{a}: {_invite_id}")

		var _ins = instance_create_depth(x, y + 100 + a * 100, 0, obj_eos_lobbies_lobby, {})
		_ins.text = _invite_id
	}
}))
