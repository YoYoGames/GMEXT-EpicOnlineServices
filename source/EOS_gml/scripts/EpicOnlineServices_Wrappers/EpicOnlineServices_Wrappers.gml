//__eos_active_session_copy_info(session_name)
function eos_active_session_copy_info(session_name)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_active_session_copy_info(session_name,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_session_details_copy_info
function eos_session_details_copy_info()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_session_details_copy_info(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_session_details_copy_session_attribute_by_index(attribute_index)
function eos_session_details_copy_session_attribute_by_index(attribute_index)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_session_details_copy_session_attribute_by_index(attribute_index,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_session_details_copy_session_attribute_by_key(attribute_key,buff_ret)
function eos_session_details_copy_session_attribute_by_key(attribute_key)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_session_details_copy_session_attribute_by_key(attribute_key,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_session_modification_add_attribute(AdvertisementType, Sessionattribute, buff_args)
function eos_session_modification_add_attribute(AdvertisementType,Sessionattribute,attribute)
{
	var _args = [
		[attribute, undefined], // struct
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_session_modification_add_attribute(AdvertisementType,Sessionattribute,_args_buffer_address)
}

//__eos_session_modification_set_allowed_platform_ids
function eos_session_modification_set_allowed_platform_ids(array_ids)
{
	var _args = [
		[array_ids, buffer_u8], // struct
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_session_modification_set_allowed_platform_ids(_args_buffer_address)
}

//__eos_sessions_copy_session_handle_by_ui_event_id
function eos_sessions_copy_session_handle_by_ui_event_id(ui_event_id)
{
	var _args = [
		[ui_event_id ,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_sessions_copy_session_handle_by_ui_event_id(_args_buffer_address)
}

//__eos_sessions_create_session_modification
function eos_sessions_create_session_modification(allowed_platform_ids,presence_enabled,sanctions_enabled,bucket_id,local_user_id,max_players,session_id,session_name)
{
	var _args = [
		[allowed_platform_ids, buffer_u32],//0,Array
		[presence_enabled, buffer_bool],//1
		[sanctions_enabled, buffer_bool],//2
		[bucket_id, buffer_string],//3
		[local_user_id, buffer_string],//4
		[max_players, buffer_f32],//5
		[session_id, buffer_string],//6
		[session_name, buffer_string],//7
	]
	
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_sessions_create_session_modification(_args_buffer_address)
}

//__eos_sessions_register_players(session_name, buff_args)
function eos_sessions_register_players(session_name,array_product_ids)
{
	var _args = [
		[array_product_ids, undefined], // array
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_sessions_register_players(session_name,_args_buffer_address)
}

//__eos_sessions_unregister_players(session_name, buff_args)
function eos_sessions_unregister_players(session_name,array_product_ids)
{
	var _args = [
		[array_product_ids, undefined], // array
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return eos_sessions_unregister_players(session_name,_args_buffer_address)
}

//__eos_session_search_set_parameter(comparison_op,buff_args)
function eos_session_search_set_parameter(comparison_op,attribute)
{
	var _args = [
		[attribute, undefined], // Struct
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_session_search_set_parameter(comparison_op,_args_buffer_address)
}






//__eos_sessions_add_notify_join_session_accepted
function eos_sessions_add_notify_join_session_accepted()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_sessions_add_notify_join_session_accepted(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_sessions_add_notify_leave_session_requested
function eos_sessions_add_notify_leave_session_requested()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_sessions_add_notify_leave_session_requested(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}
//__eos_sessions_add_notify_send_session_native_invite_requested
function eos_sessions_add_notify_send_session_native_invite_requested()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_sessions_add_notify_send_session_native_invite_requested(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}
//__eos_sessions_add_notify_session_invite_accepted
function eos_sessions_add_notify_session_invite_accepted()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_sessions_add_notify_session_invite_accepted(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}
//__eos_sessions_add_notify_session_invite_received
function eos_sessions_add_notify_session_invite_received()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_sessions_add_notify_session_invite_received(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_sessions_add_notify_session_invite_rejected
function eos_sessions_add_notify_session_invite_rejected()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_sessions_add_notify_session_invite_rejected(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}


//__eos_sessions_remove_notify_join_session_accepted
function eos_sessions_remove_notify_join_session_accepted(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_sessions_remove_notify_join_session_accepted(_args_buffer_address)
}

//__eos_sessions_remove_notify_leave_session_requested
function eos_sessions_remove_notify_leave_session_requested(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_sessions_remove_notify_leave_session_requested(_args_buffer_address)
}

//__eos_sessions_remove_notify_send_session_native_invite_requested
function eos_sessions_remove_notify_send_session_native_invite_requested(notification_id)
{
		var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_sessions_remove_notify_send_session_native_invite_requested(_args_buffer_address)
}

//__eos_sessions_remove_notify_session_invite_accepted
function eos_sessions_remove_notify_session_invite_accepted(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_sessions_remove_notify_session_invite_accepted(_args_buffer_address)
}

//__eos_sessions_remove_notify_session_invite_received
function eos_sessions_remove_notify_session_invite_received(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_sessions_remove_notify_session_invite_received(_args_buffer_address)
}

//__eos_sessions_remove_notify_session_invite_rejected
function eos_sessions_remove_notify_session_invite_rejected(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_sessions_remove_notify_session_invite_rejected(_args_buffer_address)
}



//__eos_p2p_get_packet_queue_info
function eos_p2p_get_packet_queue_info()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_p2p_get_packet_queue_info(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_p2p_get_port_range
function eos_p2p_get_port_range()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_p2p_get_port_range(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_p2p_receive_packet(buff_ret,local_user_id,max_data_size_bytes,requested_channel)
function eos_p2p_receive_packet(buff,local_user_id,max_data_size_bytes,requested_channel)
{	
	return __eos_p2p_receive_packet(buffer_get_address(buff),local_user_id,max_data_size_bytes,requested_channel)
}

//__eos_p2p_send_packet(buff_data, len)
function eos_p2p_send_packet(buff,buff_len,allow_delayed_delivery,disable_auto_accept_connection,channel,local_user_id,reliability,remote_user_id,socket_name)
{
	var _args = [
		[allow_delayed_delivery,buffer_bool],
		[disable_auto_accept_connection,buffer_bool],
		[channel,buffer_f32],
		[local_user_id,buffer_string],
		[reliability,buffer_u8],
		[remote_user_id,buffer_string],
		[socket_name,buffer_string],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_p2p_send_packet(_args_buffer_address,buffer_get_address(buff),buff_len)
}

//__eos_p2p_add_notify_incoming_packet_queue_full
function eos_p2p_add_notify_incoming_packet_queue_full()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_p2p_add_notify_incoming_packet_queue_full(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_p2p_add_notify_peer_connection_closed
function eos_p2p_add_notify_peer_connection_closed(local_user_id, socket_name)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_p2p_add_notify_peer_connection_closed(local_user_id, socket_name,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_p2p_add_notify_peer_connection_established
function eos_p2p_add_notify_peer_connection_established(local_user_id, socket_name)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_p2p_add_notify_peer_connection_established(local_user_id, socket_name,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_p2p_add_notify_peer_connection_interrupted
function eos_p2p_add_notify_peer_connection_interrupted(local_user_id, socket_name)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_p2p_add_notify_peer_connection_interrupted(local_user_id, socket_name,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_p2p_add_notify_peer_connection_request
function eos_p2p_add_notify_peer_connection_request(local_user_id, socket_name)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_p2p_add_notify_peer_connection_request(local_user_id, socket_name,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}



//__eos_p2p_remove_notify_incoming_packet_queue_full
function eos_p2p_remove_notify_incoming_packet_queue_full(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_p2p_remove_notify_incoming_packet_queue_full(_args_buffer_address)
}

//__eos_p2p_remove_notify_peer_connection_closed
function eos_p2p_remove_notify_peer_connection_closed(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_p2p_remove_notify_peer_connection_closed(_args_buffer_address)
}

//__eos_p2p_remove_notify_peer_connection_established
function eos_p2p_remove_notify_peer_connection_established(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_p2p_remove_notify_peer_connection_established(_args_buffer_address)
}

//__eos_p2p_remove_notify_peer_connection_interrupted
function eos_p2p_remove_notify_peer_connection_interrupted(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_p2p_remove_notify_peer_connection_interrupted(_args_buffer_address)
}

//__eos_p2p_remove_notify_peer_connection_request
function eos_p2p_remove_notify_peer_connection_request(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_p2p_remove_notify_peer_connection_request(_args_buffer_address)
}







//__eos_lobby_add_notify_join_lobby_accepted
function eos_lobby_add_notify_join_lobby_accepted()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_lobby_add_notify_join_lobby_accepted(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_lobby_add_notify_leave_lobby_requested
function eos_lobby_add_notify_leave_lobby_requested()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_lobby_add_notify_leave_lobby_requested(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_lobby_add_notify_lobby_invite_accepted
function eos_lobby_add_notify_lobby_invite_accepted()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_lobby_add_notify_lobby_invite_accepted(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_lobby_add_notify_lobby_invite_received
function eos_lobby_add_notify_lobby_invite_received()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_lobby_add_notify_lobby_invite_received(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_lobby_add_notify_lobby_invite_rejected
function eos_lobby_add_notify_lobby_invite_rejected()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_lobby_add_notify_lobby_invite_rejected(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_lobby_add_notify_lobby_member_status_received
function eos_lobby_add_notify_lobby_member_status_received()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_lobby_add_notify_lobby_member_status_received(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_lobby_add_notify_lobby_member_update_received
function eos_lobby_add_notify_lobby_member_update_received()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_lobby_add_notify_lobby_member_update_received(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_lobby_add_notify_lobby_update_received
function eos_lobby_add_notify_lobby_update_received()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_lobby_add_notify_lobby_update_received(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_lobby_add_notify_rtc_room_connection_changed
function eos_lobby_add_notify_rtc_room_connection_changed()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_lobby_add_notify_rtc_room_connection_changed(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_lobby_add_notify_send_lobby_native_invite_requested
function eos_lobby_add_notify_send_lobby_native_invite_requested()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_lobby_add_notify_send_lobby_native_invite_requested(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_lobby_details_copy_attribute_by_key
function eos_lobby_details_copy_attribute_by_key(attribute_key)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	var result = __eos_lobby_details_copy_attribute_by_key(attribute_key,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_lobby_details_copy_info
function eos_lobby_details_copy_info()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	var result = __eos_lobby_details_copy_info(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_lobby_details_copy_member_attribute_by_index(double index, char *target_user_id, char* buff_ret)
function eos_lobby_details_copy_member_attribute_by_index(index,target_user_id)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_lobby_details_copy_member_attribute_by_index(index,target_user_id,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_lobby_details_copy_member_info(char *target_user_id,char* buff_ret)
function eos_lobby_details_copy_member_info(target_user_id)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_lobby_details_copy_member_info(target_user_id,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_lobby_copy_lobby_details_handle_by_ui_event_id
function eos_lobby_copy_lobby_details_handle_by_ui_event_id(ui_event_id)
{
	var _args = [
		[ui_event_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_copy_lobby_details_handle_by_ui_event_id(_args_buffer_address)
}

//__eos_lobby_create_lobby
function eos_lobby_create_lobby(local_user_id,allowed_platform_ids,lobby_id,bucket_id,max_lobby_members,permission_level,allow_invites,crossplay_opt_out,disable_host_migration,enable_join_by_id,presence_enabled,enable_rtc_room,flags,use_manual_audio_input,use_manual_audio_output,local_audio_device_input_starts_muted)
{
	var _args = [
		[local_user_id,buffer_string],
		[allowed_platform_ids, buffer_u32],//0,Array
		[lobby_id,buffer_string],
		[bucket_id,buffer_string],
		[max_lobby_members,buffer_f64],
		[permission_level, buffer_u8],
		[allow_invites,buffer_bool],
		[crossplay_opt_out,buffer_bool],
		[disable_host_migration,buffer_bool],
		[enable_join_by_id,buffer_bool],
		[presence_enabled,buffer_bool],
		[enable_rtc_room,buffer_bool],
		[flags,buffer_u32],
		[use_manual_audio_input,buffer_bool],
		[use_manual_audio_output,buffer_bool],
		[local_audio_device_input_starts_muted,buffer_bool],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_create_lobby(_args_buffer_address)
}

//__eos_lobby_join_lobby
function eos_lobby_join_lobby(local_user_id,crossplay_opt_out,presence_enabled,enable_rtc_room,local_audio_device_input_starts_muted,use_manual_audio_input,use_manual_audio_output,flags)
{
	var _args = [
			[local_user_id,buffer_string],
			[crossplay_opt_out,buffer_bool],
			[presence_enabled,buffer_bool],
			[enable_rtc_room,buffer_bool],
			[local_audio_device_input_starts_muted,buffer_bool],
			[use_manual_audio_input,buffer_bool],
			[use_manual_audio_output,buffer_bool],
			[flags,buffer_u32],
		]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_join_lobby(_args_buffer_address)
}

//__eos_lobby_join_lobby_by_id
function eos_lobby_join_lobby_by_id(local_user_id,crossplay_opt_out,presence_enabled,lobby_id,enable_rtc_room,local_audio_device_input_starts_muted,use_manual_audio_input,use_manual_audio_output,flags)
{
	var _args = [
			[local_user_id,buffer_string],
			[crossplay_opt_out,buffer_bool],
			[presence_enabled,buffer_bool],
			[lobby_id,buffer_string],
			[enable_rtc_room,buffer_bool],
			[local_audio_device_input_starts_muted,buffer_bool],
			[use_manual_audio_input,buffer_bool],
			[use_manual_audio_output,buffer_bool],
			[flags,buffer_u32],
			
		]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_join_lobby_by_id(_args_buffer_address)
}

//__eos_lobby_remove_notify_join_lobby_accepted
function eos_lobby_remove_notify_join_lobby_accepted(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_remove_notify_join_lobby_accepted(_args_buffer_address)
}

//__eos_lobby_remove_notify_leave_lobby_requested
function eos_lobby_remove_notify_leave_lobby_requested(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_remove_notify_leave_lobby_requested(_args_buffer_address)
}

//__eos_lobby_remove_notify_lobby_invite_accepted
function eos_lobby_remove_notify_lobby_invite_accepted(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_remove_notify_lobby_invite_accepted(_args_buffer_address)
}

//__eos_lobby_remove_notify_lobby_invite_received
function eos_lobby_remove_notify_lobby_invite_received(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_remove_notify_lobby_invite_received(_args_buffer_address)
}

//__eos_lobby_remove_notify_lobby_invite_rejected
function eos_lobby_remove_notify_lobby_invite_rejected(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_remove_notify_lobby_invite_rejected(_args_buffer_address)
}

//__eos_lobby_remove_notify_lobby_member_status_received
function eos_lobby_remove_notify_lobby_member_status_received(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_remove_notify_lobby_member_status_received(_args_buffer_address)
}

//__eos_lobby_remove_notify_lobby_member_update_received
function eos_lobby_remove_notify_lobby_member_update_received(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_remove_notify_lobby_member_update_received(_args_buffer_address)
}

//__eos_lobby_remove_notify_lobby_update_received
function eos_lobby_remove_notify_lobby_update_received(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_remove_notify_lobby_update_received(_args_buffer_address)
}

//__eos_lobby_remove_notify_rtc_room_connection_changed
function eos_lobby_remove_notify_rtc_room_connection_changed(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_remove_notify_rtc_room_connection_changed(_args_buffer_address)
}

//__eos_lobby_remove_notify_send_lobby_native_invite_requested
function eos_lobby_remove_notify_send_lobby_native_invite_requested(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_remove_notify_send_lobby_native_invite_requested(_args_buffer_address)
}

//func double __eos_lobby_details_copy_attribute_by_index(double index, char* buff_ret)
function eos_lobby_details_copy_attribute_by_index(index,target_user_id)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_lobby_details_copy_attribute_by_index(index,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_lobby_modification_add_attribute
function eos_lobby_modification_add_attribute(visibility,attribute)
{
	var _args = [
		[attribute,undefined],//struct
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_modification_add_attribute(visibility,_args_buffer_address)
}

//__eos_lobby_modification_add_member_attribute
function eos_lobby_modification_add_member_attribute(visibility,attribute)
{
	var _args = [
		[attribute,undefined],//struct
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_modification_add_member_attribute(visibility,_args_buffer_address)
}

//__eos_lobby_modification_set_allowed_platform_ids
function eos_lobby_modification_set_allowed_platform_ids(allowed_platform_ids)
{
	var _args = [
		[allowed_platform_ids,undefined],//Array
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_modification_set_allowed_platform_ids(_args_buffer_address)

}

//__eos_lobby_search_set_parameter
function eos_lobby_search_set_parameter(comparison_op,attribute)
{
	var _args = [
		[attribute,undefined],//struct
	]
	
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_search_set_parameter(comparison_op,_args_buffer_address)
}


//////////////////// RTC


//__eos_rtc_add_notify_disconnected
function eos_rtc_add_notify_disconnected(local_user_id, room_name)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_add_notify_disconnected(room_name, local_user_id,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_add_notify_participant_status_changed
function eos_rtc_add_notify_participant_status_changed(local_user_id, room_name)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_add_notify_participant_status_changed(room_name, local_user_id,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_add_notify_room_statistics_updated
function eos_rtc_add_notify_room_statistics_updated(local_user_id, room_name)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_add_notify_room_statistics_updated(room_name, local_user_id,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_join_room
function eos_rtc_join_room(manual_audio_input_enabled,manual_audio_output_enabled,client_base_url,flags,local_user_id,participant_id,participant_token,room_name)
{
	var _args = [
		[local_user_id,buffer_string],
		[room_name,buffer_string],
		[participant_id,buffer_string],
		[participant_token,buffer_string],
		[manual_audio_input_enabled,buffer_bool],
		[manual_audio_output_enabled,buffer_bool],
		[client_base_url,buffer_string],
		[flags,buffer_u32],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_join_room(_args_buffer_address)
}

//__eos_rtc_remove_notify_disconnected
function eos_rtc_remove_notify_disconnected(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_remove_notify_disconnected(_args_buffer_address)
}

//__eos_rtc_remove_notify_participant_status_changed
function eos_rtc_remove_notify_participant_status_changed(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_remove_notify_participant_status_changed(_args_buffer_address)
}

//__eos_rtc_remove_notify_room_statistics_updated
function eos_rtc_remove_notify_room_statistics_updated(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_remove_notify_room_statistics_updated(_args_buffer_address)
}

//__eos_rtc_admin_copy_user_token_by_user_id(double query_id, char *target_user_id)
function eos_rtc_admin_copy_user_token_by_user_id(query_id,target_user_id)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_admin_copy_user_token_by_user_id(query_id,target_user_id,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_admin_query_join_room_token
function eos_rtc_admin_query_join_room_token(local_user_id,room_name,array_ids,array_ips)
{
	var _args = [
		[local_user_id,buffer_string],
		[room_name,buffer_string],
		[array_ids,buffer_string],//array
		[array_ips,buffer_string]//array
	]
	
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_admin_query_join_room_token(_args_buffer_address)
}

//__eos_rtc_audio_add_notify_audio_before_render
function eos_rtc_audio_add_notify_audio_before_render(local_user_id,room_name, unmixed_audio)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_audio_add_notify_audio_before_render(local_user_id,room_name, unmixed_audio,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_audio_add_notify_audio_before_send
function eos_rtc_audio_add_notify_audio_before_send(local_user_id, room_name)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_audio_add_notify_audio_before_send(local_user_id, room_name, _return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_audio_add_notify_audio_devices_changed
function eos_rtc_audio_add_notify_audio_devices_changed()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_audio_add_notify_audio_devices_changed(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_audio_add_notify_audio_input_state
function eos_rtc_audio_add_notify_audio_input_state(local_user_id, room_name)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_audio_add_notify_audio_input_state(local_user_id, room_name,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_audio_add_notify_audio_output_state
function eos_rtc_audio_add_notify_audio_output_state(local_user_id, room_name)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_audio_add_notify_audio_output_state(local_user_id, room_name,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_audio_add_notify_participant_updated
function eos_rtc_audio_add_notify_participant_updated(local_user_id, room_name)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_audio_add_notify_participant_updated(local_user_id, room_name,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_audio_copy_input_device_information_by_index(double device_index,char* buff_ret)
function eos_rtc_audio_copy_input_device_information_by_index(device_index)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_audio_copy_input_device_information_by_index(device_index,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//func double __eos_rtc_audio_copy_output_device_information_by_index(double device_index, char* buff_ret)
function eos_rtc_audio_copy_output_device_information_by_index(device_index)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_audio_copy_output_device_information_by_index(device_index,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_audio_remove_notify_audio_before_render
function eos_rtc_audio_remove_notify_audio_before_render(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_audio_remove_notify_audio_before_render(_args_buffer_address)
}

//__eos_rtc_audio_remove_notify_audio_before_send
function eos_rtc_audio_remove_notify_audio_before_send(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_audio_remove_notify_audio_before_send(_args_buffer_address)
}

//__eos_rtc_audio_remove_notify_audio_devices_changed
function eos_rtc_audio_remove_notify_audio_devices_changed(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_audio_remove_notify_audio_devices_changed(_args_buffer_address)
}

//__eos_rtc_audio_remove_notify_audio_input_state
function eos_rtc_audio_remove_notify_audio_input_state(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_audio_remove_notify_audio_input_state(_args_buffer_address)
}

//__eos_rtc_audio_remove_notify_audio_output_state
function eos_rtc_audio_remove_notify_audio_output_state(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_audio_remove_notify_audio_output_state(_args_buffer_address)
}

//__eos_rtc_audio_remove_notify_participant_updated
function eos_rtc_audio_remove_notify_participant_updated(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_audio_remove_notify_participant_updated(_args_buffer_address)
}

//__eos_rtc_audio_send_audio
function eos_rtc_audio_send_audio(channels,frames_count,sample_rate,local_user_id,room_name)
{
	var _args = [
		[channels,buffer_u32],
        [frames_count,buffer_u32],
        [sample_rate,buffer_u32],
        [local_user_id,buffer_string],
        [room_name,buffer_string],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_audio_send_audio(_args_buffer_address)
}


//__eos_rtc_data_add_notify_data_received
function eos_rtc_data_add_notify_data_received(local_user_id, room_name)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_data_add_notify_data_received(local_user_id, room_name,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_data_add_notify_participant_updated
function eos_rtc_data_add_notify_participant_updated(local_user_id, room_name)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_data_add_notify_participant_updated(local_user_id, room_name,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_data_remove_notify_data_received
function eos_rtc_data_remove_notify_data_received(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_data_remove_notify_data_received(_args_buffer_address)
}

//__eos_rtc_data_remove_notify_participant_updated
function eos_rtc_data_remove_notify_participant_updated(notification_id)
{
	var _args = [
		[notification_id,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_data_remove_notify_participant_updated(_args_buffer_address)
}

//__eos_rtc_data_send_data
function eos_rtc_data_send_data(buff,Length, local_user_id, room_name)
{
	return __eos_rtc_data_send_data(buffer_get_address(buff),Length,local_user_id,room_name)
}
