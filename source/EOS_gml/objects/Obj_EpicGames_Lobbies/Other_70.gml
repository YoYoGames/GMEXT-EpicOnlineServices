
switch(async_load[?"type"])
{
	case "EpicGames_Lobby_CreateLobby":
		if(async_load[?"status"] == EpicGames_Success)
		{
			LobbyId = async_load[?"LobbyId"]
			var RTCRoomName = EpicGames_Lobby_GetRTCRoomName(userID,LobbyId)
			show_debug_message("RTCRoomName: " + RTCRoomName)
			instance_create_depth(0,0,0,Obj_RTC,{RoomName: RTCRoomName})
			instance_create_depth(0,0,0,Obj_EpicGames_Lobbies_P2P)
			
			show_debug_message("Lobby_UpdateLobbyModification: " + string(EpicGames_Lobby_UpdateLobbyModification(LobbyId,userID)))
			show_debug_message("LobbyModification_AddAttribute: " + string(EpicGames_LobbyModification_AddAttribute(EOS_LobbyAttributeVisibility.PUBLIC,{Key:"lobbyname",ValueType: EOS_AttributeType.STRING,Value: "Test Name"})))
			EpicGames_Lobby_UpdateLobby()
			EpicGames_LobbyModification_Release()
		}
	break
	
	case "EpicGames_Lobby_UpdateLobby":
		
	break
	
	case "EpicGames_Lobby_LeaveLobby":
		if(async_load[?"status"] == EpicGames_Success)
		{
			with(Obj_RTC) instance_destroy()
			with(Obj_EpicGames_Lobbies_P2P) instance_destroy()
		}
	break
	
	case "EpicGames_Lobby_JoinLobby":
	case "EpicGames_Lobby_JoinLobbyById":
		if(async_load[?"status"] == EpicGames_Success)
		{
	        LobbyId = async_load[?"LobbyId"]
			
			var RTCRoomName = EpicGames_Lobby_GetRTCRoomName(userID,LobbyId)
			
			show_debug_message("RTCRoomName: " + RTCRoomName)
			
			instance_create_depth(0,0,0,Obj_RTC,{RoomName: RTCRoomName})
	        instance_create_depth(0,0,0,Obj_EpicGames_Lobbies_P2P)
			
	        if(EpicGames_Lobby_CopyLobbyDetailsHandle(LobbyId,userID) == EpicGames_Success)
	        {
				show_debug_message(EpicGames_LobbyDetails_CopyAttributeByKey("lobbyname"))
				
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
		}

    break 
	
	case "EpicGames_Lobby_AddNotifyJoinLobbyAccepted":
	break
	
	case "EpicGames_Lobby_AddNotifyLeaveLobbyRequested":
	break
	
	case "EpicGames_Lobby_AddNotifyLobbyInviteAccepted":
	
		if(EpicGames_Lobby_CopyLobbyDetailsHandleByInviteId(async_load[?"InviteId"]) == EpicGames_Success)
		{
			EpicGames_Lobby_JoinLobby(userID,true,true,true,false,false,false,0/*EOS_RTC_JOINROOMFLAGS_ENABLE_DATACHANNEL or EOS_RTC_JOINROOMFLAGS_ENABLE_ECHO*/)
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
		
		if(count == 0)
			show_message_async("No Lobbies Found")
		
		for(var a = 0 ; a < count ; a++)
		{
			EpicGames_LobbySearch_CopySearchResultByIndex(a)
			var struct = EpicGames_LobbyDetails_CopyInfo()
			var attribute = EpicGames_LobbyDetails_CopyAttributeByKey("lobbyname")
			EpicGames_LobbyDetails_Release()
			
			var ins = instance_create_depth(100,500+a*100,0,Obj_EpicGames_Lobby,struct)
			ins.text = attribute.Value
		}
		EpicGames_LobbySearch_Release()
		
	break
}
