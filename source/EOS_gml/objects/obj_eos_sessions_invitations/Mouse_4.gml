
// Clear any previously listed invitation tiles.
with(obj_eos_sessions_invitation)
	instance_destroy()

eos_sessions_query_invites(global.product_user_id, function(_info)
{
	// EpicSessionsQueryInvitesCallbackInfo: .result_code, .local_user_id
	if(_info.result_code != EpicResult.Success)
	{
		show_debug_message("eos_sessions_query_invites failed: " + eos_api_result_to_string(_info.result_code))
		return
	}

	var _count = eos_sessions_get_invite_count(global.product_user_id)
	if(_count == 0)
	{
		show_message_async("No Session Invitations... :(")
		return
	}

	for(var a = 0; a < _count; a++)
	{
		var _invite_id = eos_sessions_get_invite_id_by_index(global.product_user_id, a)
		show_debug_message($"Session Invite #{a}: {_invite_id}")

		// Pull the session details so we can label the tile with something useful.
		var _details_id = eos_sessions_copy_session_handle_by_invite_id(_invite_id)
		if(_details_id == 0) continue

		var _struct = eos_sessions_session_details_copy_info(_details_id)
		eos_sessions_session_details_release(_details_id)

		// Spawn one invitation tile per pending invite. The tile's Mouse_4
		// re-resolves the invite handle on click and joins.
		var _ins = instance_create_depth(x, y + 100 + a * 100, 0, obj_eos_sessions_invitation, {data: _struct})
		_ins.text      = $"[invite] {_struct.session_id}"
		_ins.invite_id = _invite_id
	}
})
