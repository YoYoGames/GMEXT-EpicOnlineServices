
switch(async_load[?"type"])
{
	case "EpicGames_Lobby_CreateLobby":
		LobbyId = async_load[?"LobbyId"]
		instance_create_depth(0,0,0,Obj_EpicGames_Lobbies_P2P)
	break
	
	case "EpicGames_Lobby_JoinLobby":
		LobbyId = async_load[?"LobbyId"]
		instance_create_depth(0,0,0,Obj_EpicGames_Lobbies_P2P)
		
		
		var count = EpicGames_LobbyDetails_GetMemberCount()
		for(var a = 0 ; a < count ; a++)
		{
			var user_id = EpicGames_LobbyDetails_GetMemberByIndex(a)
            var _struct = EpicGames_ActiveSession_CopyInfo(Obj_EpicGames_Session.SessionName)
            var buff = buffer_create(256,buffer_fixed,1)
            buffer_write(buff,buffer_u8,1)
            EpicGames_P2P_SendPacket(buff,buffer_tell(buff),true,false,noone,user_id,true,_struct.Details.OwnerUserId,Obj_EpicGames_Sessions_P2P.socketName)
            buffer_delete(buff)
		}
		
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
	
		//continue here
	
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
