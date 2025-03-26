//__eos_active_session_copy_info(SessionName)
function eos_active_session_copy_info(SessionName)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_active_session_copy_info(SessionName,_return_buffer_address)
	
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

//__eos_session_details_copy_session_attribute_by_index(AttrIndex)
function eos_session_details_copy_session_attribute_by_index(AttrIndex)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_session_details_copy_session_attribute_by_index(AttrIndex,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_session_details_copy_session_attribute_by_key(AttrKey,buff_ret)
function eos_session_details_copy_session_attribute_by_key(AttrKey)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_session_details_copy_session_attribute_by_key(AttrKey,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_session_modification_add_attribute(AdvertisementType, SessionAttribute, buff_args)
function eos_session_modification_add_attribute(AdvertisementType,SessionAttribute,Attribute)
{
	var _args = [
		[Attribute, undefined], // struct
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_session_modification_add_attribute(AdvertisementType,SessionAttribute,_args_buffer_address)
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
function eos_sessions_copy_session_handle_by_ui_event_id(UiEventId)
{
	var _args = [
		[UiEventId ,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_sessions_copy_session_handle_by_ui_event_id(_args_buffer_address)
}

//__eos_sessions_create_session_modification
function eos_sessions_create_session_modification(AllowedPlatformIds,PresenceEnabled,bSanctionsEnabled,BucketId,LocalUserId,MaxPlayers,SessionId,SessionName)
{
	var _args = [
		[AllowedPlatformIds, buffer_u32],//0,Array
		[PresenceEnabled, buffer_bool],//1
		[bSanctionsEnabled, buffer_bool],//2
		[BucketId, buffer_string],//3
		[LocalUserId, buffer_string],//4
		[MaxPlayers, buffer_f32],//5
		[SessionId, buffer_string],//6
		[SessionName, buffer_string],//7
	]
	
	show_debug_message(_args)
	
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_sessions_create_session_modification(_args_buffer_address)
}

//__eos_sessions_register_players(SessionName, buff_args)
function eos_sessions_register_players(SessionName,array_product_ids)
{
	var _args = [
		[array_product_ids, undefined], // array
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_sessions_register_players(SessionName,_args_buffer_address)
}

//__eos_sessions_unregister_players(SessionName, buff_args)
function eos_sessions_unregister_players(SessionName,array_product_ids)
{
	var _args = [
		[array_product_ids, undefined], // array
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return eos_sessions_unregister_players(SessionName,_args_buffer_address)
}

//__eos_session_search_set_parameter(comparisonOp,buff_args)
function eos_session_search_set_parameter(comparisonOp,Attribute)
{
	var _args = [
		[Attribute, undefined], // Struct
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_session_search_set_parameter(comparisonOp,_args_buffer_address)
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
function eos_sessions_remove_notify_join_session_accepted(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_sessions_remove_notify_join_session_accepted(_args_buffer_address)
}

//__eos_sessions_remove_notify_leave_session_requested
function eos_sessions_remove_notify_leave_session_requested(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_sessions_remove_notify_leave_session_requested(_args_buffer_address)
}

//__eos_sessions_remove_notify_send_session_native_invite_requested
function eos_sessions_remove_notify_send_session_native_invite_requested(notificationId)
{
		var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_sessions_remove_notify_send_session_native_invite_requested(_args_buffer_address)
}

//__eos_sessions_remove_notify_session_invite_accepted
function eos_sessions_remove_notify_session_invite_accepted(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_sessions_remove_notify_session_invite_accepted(_args_buffer_address)
}

//__eos_sessions_remove_notify_session_invite_received
function eos_sessions_remove_notify_session_invite_received(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_sessions_remove_notify_session_invite_received(_args_buffer_address)
}

//__eos_sessions_remove_notify_session_invite_rejected
function eos_sessions_remove_notify_session_invite_rejected(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
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

//__eos_p2p_receive_packet(buff_ret,LocalUserId,MaxDataSizeBytes,RequestedChannel)
function eos_p2p_receive_packet(buffAdress,LocalUserId,MaxDataSizeBytes,RequestedChannel)
{	
	return __eos_p2p_receive_packet(buffAdress,LocalUserId,MaxDataSizeBytes,RequestedChannel)
}

//__eos_p2p_send_packet(buff_data, len)
function eos_p2p_send_packet(buff,buff_len,AllowDelayedDelivery,DisableAutoAcceptConnection,Channel,LocalUserId,Reliability,RemoteUserId,SocketName)
{
	var _args = [
		[AllowDelayedDelivery,buffer_bool],
		[DisableAutoAcceptConnection,buffer_bool],
		[Channel,buffer_f32],
		[LocalUserId,buffer_string],
		[Reliability,buffer_u8],
		[RemoteUserId,buffer_string],
		[SocketName,buffer_string],
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
function eos_p2p_add_notify_peer_connection_closed(LocalUserId, SocketName)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_p2p_add_notify_peer_connection_closed(LocalUserId, SocketName,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_p2p_add_notify_peer_connection_established
function eos_p2p_add_notify_peer_connection_established(LocalUserId, SocketName)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_p2p_add_notify_peer_connection_established(LocalUserId, SocketName,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_p2p_add_notify_peer_connection_interrupted
function eos_p2p_add_notify_peer_connection_interrupted(LocalUserId, SocketName)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_p2p_add_notify_peer_connection_interrupted(LocalUserId, SocketName,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_p2p_add_notify_peer_connection_request
function eos_p2p_add_notify_peer_connection_request(LocalUserId, SocketName)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_p2p_add_notify_peer_connection_request(LocalUserId, SocketName,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}



//__eos_p2p_remove_notify_incoming_packet_queue_full
function eos_p2p_remove_notify_incoming_packet_queue_full(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_p2p_remove_notify_incoming_packet_queue_full(_args_buffer_address)
}

//__eos_p2p_remove_notify_peer_connection_closed
function eos_p2p_remove_notify_peer_connection_closed(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_p2p_remove_notify_peer_connection_closed(_args_buffer_address)
}

//__eos_p2p_remove_notify_peer_connection_established
function eos_p2p_remove_notify_peer_connection_established(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_p2p_remove_notify_peer_connection_established(_args_buffer_address)
}

//__eos_p2p_remove_notify_peer_connection_interrupted
function eos_p2p_remove_notify_peer_connection_interrupted(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_p2p_remove_notify_peer_connection_interrupted(_args_buffer_address)
}

//__eos_p2p_remove_notify_peer_connection_request
function eos_p2p_remove_notify_peer_connection_request(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
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
function eos_lobby_details_copy_attribute_by_key(AttrKey)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	var result = __eos_lobby_details_copy_attribute_by_key(AttrKey,_return_buffer_address)
	
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

//__eos_lobby_details_copy_member_attribute_by_index(double index, char *TargetUserId, char* buff_ret)
function eos_lobby_details_copy_member_attribute_by_index(index,TargetUserId)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_lobby_details_copy_member_attribute_by_index(index,TargetUserId,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_lobby_details_copy_member_info(char *TargetUserId,char* buff_ret)
function eos_lobby_details_copy_member_info(TargetUserId)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_lobby_details_copy_member_info(TargetUserId,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_lobby_copy_lobby_details_handle_by_ui_event_id
function eos_lobby_copy_lobby_details_handle_by_ui_event_id(UiEventId)
{
	var _args = [
		[UiEventId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_copy_lobby_details_handle_by_ui_event_id(_args_buffer_address)
}

//__eos_lobby_create_lobby
function eos_lobby_create_lobby(LocalUserId,AllowedPlatformIds,LobbyId,BucketId,MaxLobbyMembers,PermissionLevel,bAllowInvites,bCrossplayOptOut,bDisableHostMigration,bEnableJoinById,bPresenceEnabled,bEnableRTCRoom,Flags,bUseManualAudioInput,bUseManualAudioOutput,bLocalAudioDeviceInputStartsMuted)
{
	var _args = [
		[LocalUserId,buffer_string],
		[AllowedPlatformIds, buffer_u32],//0,Array
		[LobbyId,buffer_string],
		[BucketId,buffer_string],
		[MaxLobbyMembers,buffer_f64],
		[PermissionLevel, buffer_u8],
		[bAllowInvites,buffer_bool],
		[bCrossplayOptOut,buffer_bool],
		[bDisableHostMigration,buffer_bool],
		[bEnableJoinById,buffer_bool],
		[bPresenceEnabled,buffer_bool],
		[bEnableRTCRoom,buffer_bool],
		[Flags,buffer_u32],
		[bUseManualAudioInput,buffer_bool],
		[bUseManualAudioOutput,buffer_bool],
		[bLocalAudioDeviceInputStartsMuted,buffer_bool],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_create_lobby(_args_buffer_address)
}

//__eos_lobby_join_lobby
function eos_lobby_join_lobby(LocalUserId,bCrossplayOptOut,bPresenceEnabled,bEnableRTCRoom,bLocalAudioDeviceInputStartsMuted,bUseManualAudioInput,bUseManualAudioOutput,Flags)
{
	var _args = [
			[LocalUserId,buffer_string],
			[bCrossplayOptOut,buffer_bool],
			[bPresenceEnabled,buffer_bool],
			[bEnableRTCRoom,buffer_bool],
			[bLocalAudioDeviceInputStartsMuted,buffer_bool],
			[bUseManualAudioInput,buffer_bool],
			[bUseManualAudioOutput,buffer_bool],
			[Flags,buffer_u32],
		]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_join_lobby(_args_buffer_address)
}

//__eos_lobby_join_lobby_by_id
function eos_lobby_join_lobby_by_id(LocalUserId,bCrossplayOptOut,bPresenceEnabled,LobbyId,bEnableRTCRoom,bLocalAudioDeviceInputStartsMuted,bUseManualAudioInput,bUseManualAudioOutput,Flags)
{
	var _args = [
			[LocalUserId,buffer_string],
			[bCrossplayOptOut,buffer_bool],
			[bPresenceEnabled,buffer_bool],
			[LobbyId,buffer_string],
			[bEnableRTCRoom,buffer_bool],
			[bLocalAudioDeviceInputStartsMuted,buffer_bool],
			[bUseManualAudioInput,buffer_bool],
			[bUseManualAudioOutput,buffer_bool],
			[Flags,buffer_u32],
			
		]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_join_lobby_by_id(_args_buffer_address)
}

//__eos_lobby_remove_notify_join_lobby_accepted
function eos_lobby_remove_notify_join_lobby_accepted(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_remove_notify_join_lobby_accepted(_args_buffer_address)
}

//__eos_lobby_remove_notify_leave_lobby_requested
function eos_lobby_remove_notify_leave_lobby_requested(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_remove_notify_leave_lobby_requested(_args_buffer_address)
}

//__eos_lobby_remove_notify_lobby_invite_accepted
function eos_lobby_remove_notify_lobby_invite_accepted(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_remove_notify_lobby_invite_accepted(_args_buffer_address)
}

//__eos_lobby_remove_notify_lobby_invite_received
function eos_lobby_remove_notify_lobby_invite_received(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_remove_notify_lobby_invite_received(_args_buffer_address)
}

//__eos_lobby_remove_notify_lobby_invite_rejected
function eos_lobby_remove_notify_lobby_invite_rejected(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_remove_notify_lobby_invite_rejected(_args_buffer_address)
}

//__eos_lobby_remove_notify_lobby_member_status_received
function eos_lobby_remove_notify_lobby_member_status_received(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_remove_notify_lobby_member_status_received(_args_buffer_address)
}

//__eos_lobby_remove_notify_lobby_member_update_received
function eos_lobby_remove_notify_lobby_member_update_received(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_remove_notify_lobby_member_update_received(_args_buffer_address)
}

//__eos_lobby_remove_notify_lobby_update_received
function eos_lobby_remove_notify_lobby_update_received(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_remove_notify_lobby_update_received(_args_buffer_address)
}

//__eos_lobby_remove_notify_rtc_room_connection_changed
function eos_lobby_remove_notify_rtc_room_connection_changed(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_remove_notify_rtc_room_connection_changed(_args_buffer_address)
}

//__eos_lobby_remove_notify_send_lobby_native_invite_requested
function eos_lobby_remove_notify_send_lobby_native_invite_requested(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_remove_notify_send_lobby_native_invite_requested(_args_buffer_address)
}

//func double __eos_lobby_details_copy_attribute_by_index(double index, char* buff_ret)
function eos_lobby_details_copy_attribute_by_index(index,TargetUserId)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_lobby_details_copy_attribute_by_index(index,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_lobby_modification_add_attribute
function eos_lobby_modification_add_attribute(Visibility,Attribute)
{
	var _args = [
		[Attribute,undefined],//struct
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_modification_add_attribute(Visibility,_args_buffer_address)
}

//__eos_lobby_modification_add_member_attribute
function eos_lobby_modification_add_member_attribute(Visibility,Attribute)
{
	var _args = [
		[Attribute,undefined],//struct
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_modification_add_member_attribute(Visibility,_args_buffer_address)
}

//__eos_lobby_modification_set_allowed_platform_ids
function eos_lobby_modification_set_allowed_platform_ids(AllowedPlatformIds)
{
	var _args = [
		[AllowedPlatformIds,undefined],//Array
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_modification_set_allowed_platform_ids(_args_buffer_address)

}

//__eos_lobby_search_set_parameter
function eos_lobby_search_set_parameter(ComparisonOp,Attribute)
{
	var _args = [
		[Attribute,undefined],//struct
	]
	
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_lobby_search_set_parameter(ComparisonOp,_args_buffer_address)
}


//////////////////// RTC


//__eos_rtc_add_notify_disconnected
function eos_rtc_add_notify_disconnected(LocalUserId, RoomName)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_add_notify_disconnected(RoomName, LocalUserId,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_add_notify_participant_status_changed
function eos_rtc_add_notify_participant_status_changed(LocalUserId, RoomName)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_add_notify_participant_status_changed(RoomName, LocalUserId,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_add_notify_room_statistics_updated
function eos_rtc_add_notify_room_statistics_updated(LocalUserId, RoomName)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_add_notify_room_statistics_updated(RoomName, LocalUserId,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_join_room
function eos_rtc_join_room(bManualAudioInputEnabled,bManualAudioOutputEnabled,ClientBaseUrl,Flags,LocalUserId,ParticipantId,ParticipantToken,RoomName)
{
	var _args = [
		[LocalUserId,buffer_string],
		[RoomName,buffer_string],
		[ParticipantId,buffer_string],
		[ParticipantToken,buffer_string],
		[bManualAudioInputEnabled,buffer_bool],
		[bManualAudioOutputEnabled,buffer_bool],
		[ClientBaseUrl,buffer_string],
		[Flags,buffer_u32],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_join_room(_args_buffer_address)
}

//__eos_rtc_remove_notify_disconnected
function eos_rtc_remove_notify_disconnected(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_remove_notify_disconnected(_args_buffer_address)
}

//__eos_rtc_remove_notify_participant_status_changed
function eos_rtc_remove_notify_participant_status_changed(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_remove_notify_participant_status_changed(_args_buffer_address)
}

//__eos_rtc_remove_notify_room_statistics_updated
function eos_rtc_remove_notify_room_statistics_updated(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_remove_notify_room_statistics_updated(_args_buffer_address)
}

//__eos_rtc_admin_copy_user_token_by_index(double QueryId, double UserTokenIndex,char* buff_ret)
function eos_rtc_admin_copy_user_token_by_index(QueryId,UserTokenIndex)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_admin_copy_user_token_by_index(QueryId,UserTokenIndex,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}
//__eos_rtc_admin_copy_user_token_by_user_id(double QueryId, char *TargetUserId)
function eos_rtc_admin_copy_user_token_by_user_id(QueryId,TargetUserId)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_admin_copy_user_token_by_user_id(QueryId,TargetUserId,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_admin_query_join_room_token
function eos_rtc_admin_query_join_room_token(LocalUserId,RoomName,array_ids,array_ips)
{
	var _args = [
		[LocalUserId,buffer_string],
		[RoomName,buffer_string],
		[array_ids,buffer_string],//array
		[array_ips,buffer_string]//array
	]
	
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_admin_query_join_room_token(_args_buffer_address)
}

//__eos_rtc_audio_add_notify_audio_before_render
function eos_rtc_audio_add_notify_audio_before_render(LocalUserId,RoomName, bUnmixedAudio)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_audio_add_notify_audio_before_render(LocalUserId,RoomName, bUnmixedAudio,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_audio_add_notify_audio_before_send
function eos_rtc_audio_add_notify_audio_before_send(LocalUserId, RoomName)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_audio_add_notify_audio_before_send(LocalUserId, RoomName, _return_buffer_address)
	
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
function eos_rtc_audio_add_notify_audio_input_state(LocalUserId, RoomName)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_audio_add_notify_audio_input_state(LocalUserId, RoomName,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_audio_add_notify_audio_output_state
function eos_rtc_audio_add_notify_audio_output_state(LocalUserId, RoomName)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_audio_add_notify_audio_output_state(LocalUserId, RoomName,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_audio_add_notify_participant_updated
function eos_rtc_audio_add_notify_participant_updated(LocalUserId, RoomName)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_audio_add_notify_participant_updated(LocalUserId, RoomName,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_audio_copy_input_device_information_by_index(double DeviceIndex,char* buff_ret)
function eos_rtc_audio_copy_input_device_information_by_index(DeviceIndex)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_audio_copy_input_device_information_by_index(DeviceIndex,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//func double __eos_rtc_audio_copy_output_device_information_by_index(double DeviceIndex, char* buff_ret)
function eos_rtc_audio_copy_output_device_information_by_index(DeviceIndex)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_audio_copy_output_device_information_by_index(DeviceIndex,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_audio_remove_notify_audio_before_render
function eos_rtc_audio_remove_notify_audio_before_render(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_audio_remove_notify_audio_before_render(_args_buffer_address)
}

//__eos_rtc_audio_remove_notify_audio_before_send
function eos_rtc_audio_remove_notify_audio_before_send(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_audio_remove_notify_audio_before_send(_args_buffer_address)
}

//__eos_rtc_audio_remove_notify_audio_devices_changed
function eos_rtc_audio_remove_notify_audio_devices_changed(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_audio_remove_notify_audio_devices_changed(_args_buffer_address)
}

//__eos_rtc_audio_remove_notify_audio_input_state
function eos_rtc_audio_remove_notify_audio_input_state(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_audio_remove_notify_audio_input_state(_args_buffer_address)
}

//__eos_rtc_audio_remove_notify_audio_output_state
function eos_rtc_audio_remove_notify_audio_output_state(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_audio_remove_notify_audio_output_state(_args_buffer_address)
}

//__eos_rtc_audio_remove_notify_participant_updated
function eos_rtc_audio_remove_notify_participant_updated(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_audio_remove_notify_participant_updated(_args_buffer_address)
}

//__eos_rtc_data_add_notify_data_received
function eos_rtc_data_add_notify_data_received(LocalUserId, RoomName)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_data_add_notify_data_received(LocalUserId, RoomName,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_data_add_notify_participant_updated
function eos_rtc_data_add_notify_participant_updated(LocalUserId, RoomName)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	__eos_rtc_data_add_notify_participant_updated(LocalUserId, RoomName,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//__eos_rtc_data_remove_notify_data_received
function eos_rtc_data_remove_notify_data_received(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_data_remove_notify_data_received(_args_buffer_address)
}

//__eos_rtc_data_remove_notify_participant_updated
function eos_rtc_data_remove_notify_participant_updated(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return __eos_rtc_data_remove_notify_participant_updated(_args_buffer_address)
}

//__eos_rtc_data_send_data
function eos_rtc_data_send_data(buff,Length, LocalUserId, RoomName)
{
	return __eos_rtc_data_send_data(buffer_get_address(buff),Length,LocalUserId,RoomName)
}
