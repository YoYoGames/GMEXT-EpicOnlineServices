
// Click an invitation tile → resolve the invite into a session details handle,
// then join the session. Same flow as obj_eos_session for search results, but
// the handle comes from copy_session_handle_by_invite_id instead.

if(invite_id == "")
{
	show_debug_message("invitation tile has no invite_id")
	return
}

var _details_id = eos_sessions_copy_session_handle_by_invite_id(invite_id)
if(_details_id == 0)
{
	show_debug_message($"copy_session_handle_by_invite_id failed for {invite_id}")
	return
}

var _struct = eos_sessions_session_details_copy_info(_details_id)
show_debug_message(_struct)

// Carry the details handle and the session id through `method(struct, fn)` —
// anonymous functions don't close over `var` locals when bound to a struct.
var _ctx = {
	details_id: _details_id,
	session_id: data.session_id,
	invite_id:  invite_id,
}

// Use the server-side session_id as the local SessionName so it's unique.
eos_sessions_join_session(data.session_id, _details_id, global.product_user_id, true, method(_ctx, function(_info)
{
	// EpicSessionsJoinSessionCallbackInfo: .result_code
	show_debug_message($"join_session (invite {invite_id}): {eos_api_result_to_string(_info.result_code)}")

	// Safe to release now — the SDK has consumed the handle during join.
	eos_sessions_session_details_release(details_id)

	if(_info.result_code != EpicResult.Success) {return}

	instance_create_depth(0, 0, 0, obj_eos_sessions_p2p, {owner: false})

	// Add ourselves to the session's official roster so the host's count reflects us.
	eos_sessions_register_players(session_id, [global.product_user_id], function(_reg)
	{
		show_debug_message($"register_players (invite-joiner): {eos_api_result_to_string(_reg.result_code)} registered={_reg.registered_players}")
	})

	// Hello packet so P2P opens both ways.
	var _handle = eos_sessions_copy_active_session_handle(session_id)
	if(_handle != 0)
	{
		var _info_struct = eos_sessions_active_session_copy_info(_handle)
		eos_sessions_active_session_release(_handle)

		var _buff = buffer_create(256, buffer_fixed, 1)
		buffer_write(_buff, buffer_u8, 1)
		eos_p2p_send_packet(global.product_user_id, _info_struct.owner_user_id, obj_eos_sessions_p2p.socketName, 0, _buff, buffer_tell(_buff), true, EpicPacketReliability.ReliableOrdered, false)
		buffer_delete(_buff)
	}
}))
