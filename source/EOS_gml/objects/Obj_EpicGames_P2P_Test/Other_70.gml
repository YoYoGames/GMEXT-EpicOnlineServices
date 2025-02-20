
switch(async_load[?"type"])
{
	case "EpicGames_Connect_Login":

		EpicGames_P2P_AddNotifyIncomingPacketQueueFull()
		EpicGames_P2P_AddNotifyPeerConnectionClosed(userID,socketName)
		EpicGames_P2P_AddNotifyPeerConnectionEstablished(userID,socketName)
		EpicGames_P2P_AddNotifyPeerConnectionInterrupted(userID,socketName)
		EpicGames_P2P_AddNotifyPeerConnectionRequest(userID,socketName)

	break
	
	case "EpicGames_P2P_AddNotifyPeerConnectionRequest":
		
		EpicGames_P2P_AcceptConnection(userID,async_load[?"RemoteUserId"],"Socket_" + async_load[?"RemoteUserId"])
		
		
	break
}
