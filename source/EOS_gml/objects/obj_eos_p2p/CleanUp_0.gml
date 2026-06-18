
eos_p2p_remove_notify_incoming_packet_queue_full(notifyIncomingPacketQueueFull)
eos_p2p_remove_notify_peer_connection_closed(notifyPeerConnectionClosed)
eos_p2p_remove_notify_peer_connection_established(notifyPeerConnectionEstablished)
eos_p2p_remove_notify_peer_connection_interrupted(notifyPeerConnectionInterrupted)
eos_p2p_remove_notify_peer_connection_request(notifyPeerConnectionRequest)

show_debug_message("CLEAN UP")
// Iterate backwards: disconnect() does array_delete on EstablishedProductIDs,
// so going forwards would skip every other peer and leave connections open.
for(var a = array_length(EstablishedProductIDs) - 1 ; a >= 0 ; a--)
{
	disconnect(EstablishedProductIDs[a])
}
