
event_inherited();

text = "P2P"

socketName = "mySocket"

buff_recv = buffer_create(256,buffer_fixed,1)

notifyIncomingPacketQueueFull = eos_p2p_add_notify_incoming_packet_queue_full()
notifyPeerConnectionClosed = eos_p2p_add_notify_peer_connection_closed(userID,socketName)
notifyPeerConnectionEstablished = eos_p2p_add_notify_peer_connection_established(userID,socketName)
notifyPeerConnectionInterrupted = eos_p2p_add_notify_peer_connection_interrupted(userID,socketName)
notifyPeerConnectionRequest = eos_p2p_add_notify_peer_connection_request(userID,socketName)

EstablishedProductIDs = []

function disconnect(target)
{
	var index = array_get_index(EstablishedProductIDs,target)
	if(index >= 0)
	{
		show_debug_message("disconnect p2p: " + target)
		eos_p2p_clear_packet_queue(userID,EstablishedProductIDs[index],socketName)
		eos_p2p_close_connection(userID,EstablishedProductIDs[index],socketName)
		array_delete(EstablishedProductIDs,index,1)
	}
}
