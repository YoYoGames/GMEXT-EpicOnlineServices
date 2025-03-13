
switch(async_load[?"type"])
{
	case "EpicGames_Lobby_CreateLobby":
		LobbyId = async_load[?"LobbyId"]
		instance_create_depth(0,0,0,Obj_EpicGames_Lobbies_P2P)
	break
	
	case "EpicGames_Lobby_JoinLobby":
        LobbyId = async_load[?"LobbyId"]
        instance_create_depth(0,0,0,Obj_EpicGames_Lobbies_P2P)


        if(EpicGames_Lobby_CopyLobbyDetailsHandle(LobbyId,userID) == EpicGames_Success)
        {
            var count = EpicGames_LobbyDetails_GetMemberCount()

            show_debug_message($"Joined, now setup P2P: {count}")
            for(var a = 0 ; a < count ; a++)
            {
                var user_id = EpicGames_LobbyDetails_GetMemberByIndex(a)
                var buff = buffer_create(256,buffer_fixed,1)
                buffer_write(buff,buffer_u8,1)
                EpicGames_P2P_SendPacket(buff,buffer_tell(buff),true,false,noone,userID,true,user_id,Obj_EpicGames_Lobbies_P2P.socketName)
                buffer_delete(buff)
            }

            EpicGames_LobbyDetails_Release()
        }

    break 
	
	case "EpicGames_Lobby_AddNotifyJoinLobbyAccepted":
	break
	
	case "EpicGames_Lobby_AddNotifyLeaveLobbyRequested":
	break
	
	case "EpicGames_Lobby_AddNotifyLobbyInviteAccepted":
	
		if(EpicGames_Lobby_CopyLobbyDetailsHandleByInviteId(async_load[?"InviteId"]) == EpicGames_Success)
		{
			EpicGames_Lobby_JoinLobby(userID,true,true,true,false,false,false,0)
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
	
	case "EpicGames_LobbySearch_Find":
		
		var count = EpicGames_LobbySearch_GetSearchResultCount()
		show_debug_message(count)
		for(var a = 0 ; a < count ; a++)
		{
			EpicGames_LobbySearch_CopySearchResultByIndex(a)
			show_debug_message(EpicGames_LobbyDetails_CopyInfo())
			EpicGames_LobbyDetails_Release()
		}
		EpicGames_LobbySearch_Release()
		
	break
}
