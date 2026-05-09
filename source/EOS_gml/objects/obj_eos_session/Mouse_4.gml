
// Get the session details handle from the search result. We must keep it alive
// across the eos_sessions_join_session call — the SDK reads from it during join.
var _details_id = eos_sessions_session_search_copy_search_result_by_index(global.session_search_id, index)
if(_details_id == 0)
{
	show_debug_message($"copy_search_result_by_index({index}) returned 0")
	{return}
}

var _struct = eos_sessions_session_details_copy_info(_details_id)
show_debug_message(_struct)

// Carry both the details handle and an instance back-reference through
// `method(struct, fn)` — anonymous functions don't close over `var` locals
// when bound to a struct, so the captured fields are read off `self`.
var _ctx = {
	owner:      self,
	details_id: _details_id,
	session_id: data.session_id,
}

// `data.session_id` is the SERVER-side session id. We use it as the LOCAL
// session name so it stays unique per joined session.
eos_sessions_join_session(data.session_id, _details_id, global.product_user_id, true, method(_ctx, function(_info)
{
	// EpicSessionsJoinSessionCallbackInfo: .result_code
	show_debug_message("join_session: " + eos_api_result_to_string(_info.result_code))

	// Now safe to release the details handle — the SDK has consumed it.
	eos_sessions_session_details_release(details_id)

	if(_info.result_code != EpicResult.Success) {return}

	instance_create_depth(0, 0, 0, obj_eos_sessions_p2p, {owner: false})

	// Send a hello packet to the session host so P2P opens both ways.
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
