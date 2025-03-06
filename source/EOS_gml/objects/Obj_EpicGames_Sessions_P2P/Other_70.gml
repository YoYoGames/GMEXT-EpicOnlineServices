
event_inherited();

switch(async_load[?"type"])
{
	case "EpicGames_P2P_AddNotifyPeerConnectionClosed":
		
		if(owner)
		{
			show_debug_message("EpicGames_Sessions_UnregisterPlayers: " + async_load[?"RemoteUserId"])
			EpicGames_Sessions_UnregisterPlayers(Obj_EpicGames_Session.SessionName,[async_load[?"RemoteUserId"]])
		}
		
	break
	
	case "EpicGames_P2P_AddNotifyPeerConnectionEstablished":
		
		//async_load[?"ConnectionType"]
		//async_load[?"NetworkType"]
		//async_load[?"SocketId"]
		
		if(owner)
		{
			show_debug_message("EpicGames_Sessions_RegisterPlayers: " + async_load[?"RemoteUserId"])
			EpicGames_Sessions_RegisterPlayers(Obj_EpicGames_Session.SessionName,[async_load[?"RemoteUserId"]])
		}
		
	break
}
