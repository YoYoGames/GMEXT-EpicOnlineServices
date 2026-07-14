
event_inherited();

text = "P2P"

socketName = "mySocket"

buff_recv = buffer_create(256, buffer_fixed, 1)

EstablishedProductIDs = []

function disconnect(target)
{
	var index = array_get_index(EstablishedProductIDs, target)
	if(index >= 0)
	{
		show_debug_message("disconnect p2p: " + target)
		eos_p2p_clear_packet_queue(global.product_user_id, EstablishedProductIDs[index], socketName)
		eos_p2p_close_connection(global.product_user_id, EstablishedProductIDs[index], socketName)
		array_delete(EstablishedProductIDs, index, 1)
	}
}

// ============================================================
// P2P notifications — every notify takes a callback in the new API.
// IDs are stored so CleanUp can release them.
// ============================================================

notifyIncomingPacketQueueFull = eos_p2p_add_notify_incoming_packet_queue_full(function(_info)
{
	// EpicP2PIncomingPacketQueueFullCallbackInfo:
	//   .packet_queue_max_size_bytes, .packet_queue_current_size_bytes,
	//   .overflow_packet_local_user_id, .overflow_packet_channel, .overflow_packet_size_bytes
	show_debug_message($"P2P queue full: cur={_info.packet_queue_current_size_bytes} max={_info.packet_queue_max_size_bytes}")
})

notifyPeerConnectionClosed = eos_p2p_add_notify_peer_connection_closed(global.product_user_id, socketName, function(_info)
{
	// EpicP2PConnectionClosedCallbackInfo: .local_user_id, .remote_user_id, .socket_name, .reason
	disconnect(_info.remote_user_id)
})

notifyPeerConnectionEstablished = eos_p2p_add_notify_peer_connection_established(global.product_user_id, socketName, function(_info)
{
	// EpicP2PConnectionEstablishedCallbackInfo: .local_user_id, .remote_user_id, .socket_name,
	//                                           .connection_type, .network_type
	// Guard against duplicates on reconnect — otherwise we'd send twice and
	// disconnect() would only remove one copy.
	if(array_get_index(EstablishedProductIDs, _info.remote_user_id) < 0)
		array_push(EstablishedProductIDs, _info.remote_user_id)
})

notifyPeerConnectionInterrupted = eos_p2p_add_notify_peer_connection_interrupted(global.product_user_id, socketName, function(_info)
{
	// EpicP2PConnectionInterruptedCallbackInfo: .local_user_id, .remote_user_id, .socket_name
	show_debug_message($"P2P interrupted: {_info.remote_user_id}")
})

notifyPeerConnectionRequest = eos_p2p_add_notify_peer_connection_request(global.product_user_id, socketName, function(_info)
{
	show_debug_message("P2P CONNECTION REQUEST RECEIVED!")
	show_debug_message("Remote user: " + _info.remote_user_id)
	show_debug_message("Socket: " + _info.socket_name)
	
	if (is_undefined(_info)) {
		show_debug_message("ERROR: _info is undefined")
		return
	}
	
	show_debug_message("_info struct: " + string(_info))
	show_debug_message("_info type: " + typeof(_info))
	show_debug_message("Fields: local_user_id=" + string(variable_struct_exists(_info, "local_user_id")))
	show_debug_message("Fields: remote_user_id=" + string(variable_struct_exists(_info, "remote_user_id")))
	show_debug_message("Fields: socket_name=" + string(variable_struct_exists(_info, "socket_name")))
	
	// Now try to access safely
	var remote_id = _info.remote_user_id
	show_debug_message("remote_user_id: " + string(remote_id))
	
	var buff = buffer_create(256, buffer_fixed, 1)
	buffer_write(buff, buffer_u8, 1)
	eos_p2p_send_packet(global.product_user_id, _info.remote_user_id, socketName, 0, buff, buffer_tell(buff), true, EpicPacketReliability.ReliableOrdered, false)
	buffer_delete(buff)
})

