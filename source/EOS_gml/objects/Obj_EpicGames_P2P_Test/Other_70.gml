
switch(async_load[?"type"])
{
	
	case "EpicGames_P2P_AddNotifyIncomingPacketQueueFull":
	break
	
	case "EpicGames_P2P_AddNotifyPeerConnectionClosed":
		
		var index = array_get_index(EstablishedProductIDs,async_load[?"RemoteUserId"])
		array_delete(EstablishedProductIDs,index,1)
	
	break
	
	case "EpicGames_P2P_AddNotifyPeerConnectionEstablished":
		
		async_load[?"ConnectionType"]
		async_load[?"NetworkType"]
		async_load[?"SocketId"]
		
		array_push(EstablishedProductIDs,async_load[?"RemoteUserId"])
		
	break
	
	case "EpicGames_P2P_AddNotifyPeerConnectionInterrupted":
	break
	
	case "EpicGames_P2P_AddNotifyPeerConnectionRequest":
		
		var result = EpicGames_P2P_AcceptConnection(userID,async_load[?"RemoteUserId"],"OtherSocket")
		show_debug_message("EpicGames_P2P_AcceptConnection: " + EpicGames_Result_ToString(result))
		
		var buff = buffer_create(256,buffer_fixed,1)
		buffer_write(buff,buffer_string,"HelloWorld")
		EpicGames_P2P_SendPacket(buff,buffer_tell(buff),true,false,noone,userID,true,async_load[?"RemoteUserId"],socketName)
		buffer_delete(buff)
		
	break
}
