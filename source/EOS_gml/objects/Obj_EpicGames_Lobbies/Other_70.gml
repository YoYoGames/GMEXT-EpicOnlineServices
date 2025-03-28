
switch(async_load[? "type"])
{
	case "eos_lobby_create_lobby":
		if(async_load[? "status"] == EOS_Result.Success)
		{
			lobby_id = async_load[? "lobby_id"]
			
			request_update_members()//eos_connect_query_product_user_id_mappings
			
			var RTCRoomName = eos_lobby_get_rtc_room_name(userID,lobby_id)
			show_debug_message("RTCRoomName: " + RTCRoomName)
			instance_create_depth(0,0,0,Obj_RTC,{RoomName: RTCRoomName})
			instance_create_depth(0,0,0,Obj_EpicGames_Lobbies_P2P)
			
			eos_lobby_update_lobby_modification(lobby_id,userID)
			eos_lobby_modification_add_attribute(EOS_LobbyAttributeVisibility.PUBLIC,{key:"lobbyname",value_type: EOS_AttributeType.STRING,value: requestMyName + "'s Lobby"})
			eos_lobby_update_lobby()
			eos_lobby_modification_release()
		}
	break
	
	case "eos_lobby_update_lobby":
		
	break
	
	case "eos_lobby_leave_lobby":
		if(async_load[? "status"] == EOS_Result.Success)
		{
			lobby_id = ""
			
			with(Obj_RTC) instance_destroy()
			with(Obj_EpicGames_Lobbies_P2P) instance_destroy()
			with(Obj_EpicGames_Lobby_Member) instance_destroy()
		}
	break
	
	case "eos_lobby_join_lobby":
	case "eos_lobby_join_lobby_by_id":
		if(async_load[? "status"] == EOS_Result.Success)
		{
	        lobby_id = async_load[? "lobby_id"]
			
			request_update_members()//eos_connect_query_product_user_id_mappings
			
			var RTCRoomName = eos_lobby_get_rtc_room_name(userID,lobby_id)
			
			show_debug_message("RTCRoomName: " + RTCRoomName)
			
			instance_create_depth(0,0,0,Obj_RTC,{RoomName: RTCRoomName})
	        instance_create_depth(0,0,0,Obj_EpicGames_Lobbies_P2P)
			
	        if(eos_lobby_copy_lobby_details_handle(lobby_id,userID) == EOS_Result.Success)
	        {
				show_debug_message(eos_lobby_details_copy_attribute_by_key("lobbyname"))
				
	            var count = eos_lobby_details_get_member_count()
				
	            show_debug_message($"Joined, now setup P2P: {count}")
	            for(var a = 0 ; a < count ; a++)
	            {
	                var _user_id = eos_lobby_details_get_member_by_index(a)
					if(_user_id != userID)
					{
		                var buff = buffer_create(256,buffer_fixed,1)
		                buffer_write(buff,buffer_u8,1)
		                eos_p2p_send_packet(buff,buffer_tell(buff),true,false,noone,userID,true,_user_id,Obj_EpicGames_Lobbies_P2P.socketName)
		                buffer_delete(buff)
					}
	            }
				
	            eos_lobby_details_release()
	        }
		}

    break 
	
	case "eos_lobby_add_notify_join_lobby_accepted":
	break
	
	case "eos_lobby_add_notify_leave_lobby_requested":
	break
	
	case "eos_lobby_add_notify_lobby_invite_accepted":
	
		if(eos_lobby_copy_lobby_details_handle_by_invite_id(async_load[? "invite_id"]) == EOS_Result.Success)
		{
			eos_lobby_join_lobby(userID,true,true,true,false,false,false,0/*EOS_RTC_JOINROOMFLAGS_ENABLE_DATACHANNEL or EOS_RTC_JOINROOMFLAGS_ENABLE_ECHO*/)
			eos_lobby_details_release()
		}
		
	break
	
	case "eos_lobby_add_notify_lobby_invite_received":
	break
	
	case "eos_lobby_add_notify_lobby_invite_rejected":
		eos_lobby_reject_invite(async_load[? "invite_id"],userID)
	break
	
	case "eos_lobby_add_notify_lobby_member_status_received":
		
		if(async_load[? "target_user_id"] == userID)
		{
			switch(async_load[? "current_status"])
			{
				case EOS_LobbyMemberStatus.DISCONNECTED:
				case EOS_LobbyMemberStatus.CLOSED:
				case EOS_LobbyMemberStatus.LEFT:
					show_message_async("DISCONNECTED...")
					lobby_id = ""
					with(Obj_EpicGames_Lobby_Member) instance_destroy()
					with(Obj_RTC) instance_destroy()
					with(Obj_EpicGames_Lobbies_P2P) instance_destroy()
				break
				
				case EOS_LobbyMemberStatus.PROMOTED:
					show_message_async("I was PROMOTED :)")
				break
				case EOS_LobbyMemberStatus.KICKED:
					show_message_async("I was KICKED D:")
					lobby_id = ""
					with(Obj_EpicGames_Lobby_Member) instance_destroy()
					with(Obj_RTC) instance_destroy()
					with(Obj_EpicGames_Lobbies_P2P) instance_destroy()
				break
			}
		}
		else
		{
			switch(async_load[? "current_status"])
			{
				case EOS_LobbyMemberStatus.JOINED:
					request_update_members()
				break
				
				case EOS_LobbyMemberStatus.DISCONNECTED:
				case EOS_LobbyMemberStatus.KICKED:
				case EOS_LobbyMemberStatus.LEFT:
					request_update_members()//eos_connect_query_product_user_id_mappings
					Obj_EpicGames_P2P.disconnect(async_load[? "target_user_id"])
				break
				
				
			}
		}
		
	
	break
	
	case "eos_connect_query_product_user_id_mappings":
		
		if(requestMyName == async_load[? "identifier"])
		{
			var _struct = eos_connect_copy_product_user_external_account_by_index(userID,0)
			requestMyName = _struct.display_name
			
			return
		}
		
		with(Obj_EpicGames_Lobby_Member)
			instance_destroy()
				
		for(var b = 0 ; b < array_length(members_array) ; b++)
		{
			var count = eos_connect_get_product_user_external_account_count(members_array[b])
			
			for(var a = 0 ; a < count ; a++)
			{
				_struct = eos_connect_copy_product_user_external_account_by_index(members_array[b],a)
				show_debug_message(_struct)
				instance_create_depth(300,220+b*100,0,Obj_EpicGames_Lobby_Member,_struct)
				
				break//I only need one account per user :), but leave it as for() it's a good demostration....
			}
		}
		
	break
	
	case "eos_lobby_add_notify_lobby_member_update_received":
	break
	
	case "eos_lobby_add_notify_lobby_update_received":
	break
	
	case "eos_lobby_add_notify_rtc_room_connection_changed":
	break
	
	case "eos_lobby_add_notify_send_lobby_native_invite_requested":
	break
	
	case "eos_lobby_search_find":
		
		var count = eos_lobby_search_get_search_result_count()
		
		if(count == 0)
			show_message_async("No Lobbies Found")
		
		for(var a = 0 ; a < count ; a++)
		{
			eos_lobby_search_copy_search_result_by_index(a)
			var struct = eos_lobby_details_copy_info()
			var attribute = eos_lobby_details_copy_attribute_by_key("lobbyname")
			eos_lobby_details_release()
			
			var ins = instance_create_depth(Obj_EpicGames_Lobbies_Search.x,Obj_EpicGames_Lobbies_Search.y+100+a*100,0,Obj_EpicGames_Lobby,struct)
			ins.text = attribute.value
		}
		eos_lobby_search_release()
		
	break
	
	case "eos_rtc_audio_add_notify_participant_updated":
		
		with(Obj_EpicGames_Lobby_Member)
		if(async_load[? "participant_id"] == user_id)
		{
			Speaking = async_load[? "speaking"]
			AudioStatus = async_load[? "audio_status"]
		}
		//LocalUserId
		//RoomName
		//Speaking
		
	break
	
	case "eos_lobby_query_invites":
		
		if(eos_lobby_get_invite_count() == 0)
			show_message_async("No Invitations... :(")
			
		for(var a = 0 ; a < eos_lobby_get_invite_count(userID) ; a++)
		{
			var inviteId = eos_lobby_get_invite_id_by_index(userID,a)
			eos_lobby_copy_lobby_details_handle_by_invite_id(inviteId)
			
			var struct = eos_lobby_details_copy_info()
			var attribute = eos_lobby_details_copy_attribute_by_key("lobbyname")
			eos_lobby_details_release()
			
			var ins = instance_create_depth(Obj_EpicGames_Lobby_Invitations.x,Obj_EpicGames_Lobby_Invitations.y+100+a*100,0,Obj_EpicGames_Lobby,struct)
			ins.text = attribute.value
		}
		
	break
}
