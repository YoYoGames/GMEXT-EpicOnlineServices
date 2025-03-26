
switch(async_load[?"type"])
{
	case "EpicGames_Lobby_CreateLobby":
		if(async_load[?"status"] == EpicGames_Success)
		{
			LobbyId = async_load[?"LobbyId"]
			
			request_update_members()//EpicGames_Connect_QueryProductUserIdMappings
			
			var RTCRoomName = EpicGames_Lobby_GetRTCRoomName(userID,LobbyId)
			show_debug_message("RTCRoomName: " + RTCRoomName)
			instance_create_depth(0,0,0,Obj_RTC,{RoomName: RTCRoomName})
			instance_create_depth(0,0,0,Obj_EpicGames_Lobbies_P2P)
			
			EpicGames_Lobby_UpdateLobbyModification(LobbyId,userID)
			EpicGames_LobbyModification_AddAttribute(EOS_LobbyAttributeVisibility.PUBLIC,{Key:"lobbyname",ValueType: EOS_AttributeType.STRING,Value: requestMyName + "'s Lobby"})
			EpicGames_Lobby_UpdateLobby()
			EpicGames_LobbyModification_Release()
		}
	break
	
	case "EpicGames_Lobby_UpdateLobby":
		
	break
	
	case "EpicGames_Lobby_LeaveLobby":
		if(async_load[?"status"] == EpicGames_Success)
		{
			LobbyId = ""
			
			with(Obj_RTC) instance_destroy()
			with(Obj_EpicGames_Lobbies_P2P) instance_destroy()
			with(Obj_EpicGames_Lobby_Member) instance_destroy()
		}
	break
	
	case "EpicGames_Lobby_JoinLobby":
	case "EpicGames_Lobby_JoinLobbyById":
		if(async_load[?"status"] == EpicGames_Success)
		{
	        LobbyId = async_load[?"LobbyId"]
			
			request_update_members()//EpicGames_Connect_QueryProductUserIdMappings
			
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
					if(user_id != userID)
					{
		                var buff = buffer_create(256,buffer_fixed,1)
		                buffer_write(buff,buffer_u8,1)
		                EpicGames_P2P_SendPacket(buff,buffer_tell(buff),true,false,noone,userID,true,user_id,Obj_EpicGames_Lobbies_P2P.socketName)
		                buffer_delete(buff)
					}
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
		
		if(async_load[?"TargetUserId"] == userID)
		{
			switch(async_load[?"CurrentStatus"])
			{
				case EOS_LobbyMemberStatus.DISCONNECTED:
				case EOS_LobbyMemberStatus.CLOSED:
				case EOS_LobbyMemberStatus.LEFT:
					show_message_async("DISCONNECTED...")
					LobbyId = ""
					with(Obj_EpicGames_Lobby_Member) instance_destroy()
					with(Obj_RTC) instance_destroy()
					with(Obj_EpicGames_Lobbies_P2P) instance_destroy()
				break
				
				case EOS_LobbyMemberStatus.PROMOTED:
					show_message_async("I was PROMOTED :)")
				break
				case EOS_LobbyMemberStatus.KICKED:
					show_message_async("I was KICKED D:")
					LobbyId = ""
					with(Obj_EpicGames_Lobby_Member) instance_destroy()
					with(Obj_RTC) instance_destroy()
					with(Obj_EpicGames_Lobbies_P2P) instance_destroy()
				break
			}
		}
		else
		{
			switch(async_load[?"CurrentStatus"])
			{
				case EOS_LobbyMemberStatus.JOINED:
					request_update_members()
				break
				
				case EOS_LobbyMemberStatus.DISCONNECTED:
				case EOS_LobbyMemberStatus.KICKED:
				case EOS_LobbyMemberStatus.LEFT:
					request_update_members()//EpicGames_Connect_QueryProductUserIdMappings
					Obj_EpicGames_P2P.disconnect(async_load[?"TargetUserId"])
				break
				
				
			}
		}
		
	
	break
	
	case "EpicGames_Connect_QueryProductUserIdMappings":
		
		if(requestMyName == async_load[?"identifier"])
		{
			var _struct = EpicGames_Connect_CopyProductUserExternalAccountByIndex(userID,0)
			requestMyName = _struct.DisplayName
			
			return
		}
		
		with(Obj_EpicGames_Lobby_Member)
			instance_destroy()
				
		for(var b = 0 ; b < array_length(members_array) ; b++)
		{
			var count = EpicGames_Connect_GetProductUserExternalAccountCount(members_array[b])
			
			for(var a = 0 ; a < count ; a++)
			{
				_struct = EpicGames_Connect_CopyProductUserExternalAccountByIndex(members_array[b],a)
				show_debug_message("_struct")
				show_debug_message(_struct)
				//{ status_message : "EOS_Success", status : 0, LastLoginTime : 1742492836, DisplayName : "jzavala93", AccountIdType : 0, AccountId : "36b64afd62f145688696ea77e7bc9280", userID : "0002aa1d3fc94d919daa174d8e3c4a27" }
				instance_create_depth(300,220+b*100,0,Obj_EpicGames_Lobby_Member,_struct)
				
				break//I only need one account per user :), but leave it as for() it's a good demostration....
			}
		}
		
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
			
			var ins = instance_create_depth(Obj_EpicGames_Lobbies_Search.x,Obj_EpicGames_Lobbies_Search.y+100+a*100,0,Obj_EpicGames_Lobby,struct)
			ins.text = attribute.Value
		}
		EpicGames_LobbySearch_Release()
		
	break
	
	case "EpicGames_RTCAudio_AddNotifyParticipantUpdated":
		
		with(Obj_EpicGames_Lobby_Member)
		if(async_load[?"ParticipantId"] == id.userID)
		{
			Speaking = async_load[?"Speaking"]
			AudioStatus = async_load[?"AudioStatus"]
		}
		//LocalUserId
		//RoomName
		//Speaking
		
	break
	
	case "EpicGames_Lobby_QueryInvites":
		
		if(EpicGames_Lobby_GetInviteCount() == 0)
			show_message_async("No Invitations... :(")
			
		for(var a = 0 ; a < EpicGames_Lobby_GetInviteCount(userID) ; a++)
		{
			var inviteId = EpicGames_Lobby_GetInviteIdByIndex(userID,a)
			EpicGames_Lobby_CopyLobbyDetailsHandleByInviteId(inviteId)
			
			var struct = EpicGames_LobbyDetails_CopyInfo()
			var attribute = EpicGames_LobbyDetails_CopyAttributeByKey("lobbyname")
			EpicGames_LobbyDetails_Release()
			
			var ins = instance_create_depth(Obj_EpicGames_Lobby_Invitations.x,Obj_EpicGames_Lobby_Invitations.y+100+a*100,0,Obj_EpicGames_Lobby,struct)
			ins.text = attribute.Value
		}
		
	break
}
