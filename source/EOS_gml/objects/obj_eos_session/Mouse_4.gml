
var _details_id = eos_sessions_session_search_copy_search_result_by_index(global.session_search_id, index)
if(_details_id == 0)
{
	show_debug_message($"copy_search_result_by_index({index}) returned 0")
	return
}

var _struct = eos_sessions_session_details_copy_info(_details_id)
show_debug_message(_struct)
eos_sessions_session_details_release(_details_id)

eos_sessions_join_session(obj_eos_sessions.SessionName, global.product_user_id, function(_info)
{
	// EpicSessionsJoinSessionCallbackInfo: .result_code
	show_debug_message("join_session: " + eos_api_result_to_string(_info.result_code))
	if(_info.result_code != EpicResult.Success) return

	instance_create_depth(0, 0, 0, obj_eos_sessions_p2p, {owner: false})

	// Send a hello packet to the session host so P2P opens both ways.
	var _handle = eos_sessions_copy_active_session_handle(obj_eos_sessions.SessionName)
	if(_handle != 0)
	{
		var _info_struct = eos_sessions_active_session_copy_info(_handle)
		eos_sessions_active_session_release(_handle)

		var _buff = buffer_create(256, buffer_fixed, 1)
		buffer_write(_buff, buffer_u8, 1)
		eos_p2p_send_packet(global.product_user_id, _info_struct.details.owner_user_id, obj_eos_sessions_p2p.socketName, 0, _buff, buffer_tell(_buff), true, EpicPacketReliability.ReliableOrdered, false)
		buffer_delete(_buff)
	}
})
