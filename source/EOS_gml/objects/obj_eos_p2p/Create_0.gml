
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

notifyIncomingPacketQueueFull = eos_p2p_add_notify_incoming_packet_queue_full(method(self, function(_info)
{
	// EpicP2PIncomingPacketQueueFullCallbackInfo:
	//   .packet_queue_max_size_bytes, .packet_queue_current_size_bytes,
	//   .overflow_packet_local_user_id, .overflow_packet_channel, .overflow_packet_size_bytes
	show_debug_message($"P2P queue full: cur={_info.packet_queue_current_size_bytes} max={_info.packet_queue_max_size_bytes}")
}))

notifyPeerConnectionClosed = eos_p2p_add_notify_peer_connection_closed(global.product_user_id, socketName, method(self, function(_info)
{
	// EpicP2PConnectionClosedCallbackInfo: .local_user_id, .remote_user_id, .socket_name, .reason
	disconnect(_info.remote_user_id)
}))

notifyPeerConnectionEstablished = eos_p2p_add_notify_peer_connection_established(global.product_user_id, socketName, method(self, function(_info)
{
	// EpicP2PConnectionEstablishedCallbackInfo: .local_user_id, .remote_user_id, .socket_name,
	//                                           .connection_type, .network_type
	array_push(EstablishedProductIDs, _info.remote_user_id)
}))

notifyPeerConnectionInterrupted = eos_p2p_add_notify_peer_connection_interrupted(global.product_user_id, socketName, method(self, function(_info)
{
	// EpicP2PConnectionInterruptedCallbackInfo: .local_user_id, .remote_user_id, .socket_name
	show_debug_message($"P2P interrupted: {_info.remote_user_id}")
}))

notifyPeerConnectionRequest = eos_p2p_add_notify_peer_connection_request(global.product_user_id, socketName, method(self, function(_info)
{
	// EpicP2PConnectionRequestCallbackInfo: .local_user_id, .remote_user_id, .socket_name
	var result = eos_p2p_accept_connection(global.product_user_id, _info.remote_user_id, "OtherSocket")
	show_debug_message("eos_p2p_accept_connection: " + eos_api_result_to_string(result))

	var buff = buffer_create(256, buffer_fixed, 1)
	buffer_write(buff, buffer_u8, 1)
	eos_p2p_send_packet(global.product_user_id, _info.remote_user_id, socketName, 0, buff, buffer_tell(buff), true, EpicPacketReliability.ReliableOrdered, false)
	buffer_delete(buff)
}))
