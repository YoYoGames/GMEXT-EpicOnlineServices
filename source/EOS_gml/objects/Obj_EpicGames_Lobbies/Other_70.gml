
switch(async_load[?"type"])
{
	case "EpicGames_Lobby_CreateLobby":
		LobbyId = async_load[?"LobbyId"]
	break
	
	
	case "EpicGames_Lobby_AddNotifyJoinLobbyAccepted":
	break
	
	case "EpicGames_Lobby_AddNotifyLeaveLobbyRequested":
	break
	
	case "EpicGames_Lobby_AddNotifyLobbyInviteAccepted":
	
		if(EpicGames_Lobby_CopyLobbyDetailsHandleByInviteId(async_load[?"InviteId"]) == EpicGames_Success)
		{
			EpicGames_Lobby_JoinLobby(true,true,true,false,false,0,userID)
			
			EpicGames_LobbyDetails_Release()
		}
		
	break
	
	case "EpicGames_Lobby_AddNotifyLobbyInviteReceived":
	break
	
	case "EpicGames_Lobby_AddNotifyLobbyInviteRejected":
		EpicGames_Lobby_RejectInvite(async_load[?"InviteId"],userID)
	break
	
	case "EpicGames_Lobby_AddNotifyLobbyMemberStatusReceived":
	break
	
	case "EpicGames_Lobby_AddNotifyLobbyMemberUpdateReceived":
	break
	
	case "EpicGames_Lobby_AddNotifyLobbyUpdateReceived":
	break
	
	case "EpicGames_Lobby_AddNotifyRTCRoomConnectionChanged":
	break
	
	case "EpicGames_Lobby_AddNotifySendLobbyNativeInviteRequested":
	break
}
