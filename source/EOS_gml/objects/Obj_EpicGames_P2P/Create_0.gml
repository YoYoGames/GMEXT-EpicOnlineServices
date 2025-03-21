
event_inherited();

text = "P2P"

socketName = "mySocket"

buff_recv = buffer_create(256,buffer_fixed,1)

notifyIncomingPacketQueueFull = EpicGames_P2P_AddNotifyIncomingPacketQueueFull()
notifyPeerConnectionClosed = EpicGames_P2P_AddNotifyPeerConnectionClosed(userID,socketName)
notifyPeerConnectionEstablished = EpicGames_P2P_AddNotifyPeerConnectionEstablished(userID,socketName)
notifyPeerConnectionInterrupted = EpicGames_P2P_AddNotifyPeerConnectionInterrupted(userID,socketName)
notifyPeerConnectionRequest = EpicGames_P2P_AddNotifyPeerConnectionRequest(userID,socketName)

EstablishedProductIDs = []

function disconnect(target)
{
	var index = array_get_index(EstablishedProductIDs,target)
	if(index >= 0)
	{
		show_debug_message("disconnect p2p: " + target)
		EpicGames_P2P_ClearPacketQueue(userID,EstablishedProductIDs[index],socketName)
		EpicGames_P2P_CloseConnection(userID,EstablishedProductIDs[index],socketName)
		array_delete(EstablishedProductIDs,index,1)
	}
}
