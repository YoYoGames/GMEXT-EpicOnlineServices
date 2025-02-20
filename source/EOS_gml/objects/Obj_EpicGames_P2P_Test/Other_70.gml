
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
		
		var result = EpicGames_P2P_AcceptConnection(userID,async_load[?"RemoteUserId"],"OtherSocket")
		show_debug_message("EpicGames_P2P_AcceptConnection: " + EpicGames_Result_ToString(result))
		
	break
}
