
event_inherited();

text = "P2P"

socketName = "mySocket" + eos_create_code()

buff_recv = buffer_create(256,buffer_fixed,1)

notifyIncomingPacketQueueFull = EpicGames_P2P_AddNotifyIncomingPacketQueueFull()
notifyPeerConnectionClosed = EpicGames_P2P_AddNotifyPeerConnectionClosed(userID,socketName)
notifyPeerConnectionEstablished = EpicGames_P2P_AddNotifyPeerConnectionEstablished(userID,socketName)
notifyPeerConnectionInterrupted = EpicGames_P2P_AddNotifyPeerConnectionInterrupted(userID,socketName)
notifyPeerConnectionRequest = EpicGames_P2P_AddNotifyPeerConnectionRequest(userID,socketName)

EstablishedProductIDs = []



function disconnect(target)
{
	for(var a = 0 ; a < array_length(EstablishedProductIDs) ; a++)
	if(EstablishedProductIDs[a] == target)
	{
		show_debug_message("disconnect p2p: " + target)
		EpicGames_P2P_ClearPacketQueue(userID,EstablishedProductIDs[a],socketName)
		EpicGames_P2P_CloseConnection(userID,EstablishedProductIDs[a],socketName)
		array_delete(EstablishedProductIDs,a,1)
		break
	}
}
