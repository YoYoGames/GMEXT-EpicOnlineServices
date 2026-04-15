
switch(async_load[? "type"])
{
	case "eos_lobby_create_lobby":
		show_debug_message("eos_lobby_create_lobby: " + EpicResult_to_string(async_load[? "status"]))
		if(async_load[? "status"] == EpicResult.Success)
		{
			lobby_id = async_load[? "lobby_id"]
			
			request_update_members()//eos_connect_query_product_user_id_mappings
			
			var RTCRoomName = eos_lobby_get_rtc_room_name(global.product_user_id,lobby_id)
			show_debug_message("RTCRoomName: " + RTCRoomName)
			instance_create_depth(0,0,0,obj_rtc,{RoomName: RTCRoomName})
			instance_create_depth(0,0,0,obj_eos_lobbies_p2p)
			
			eos_lobby_update_lobby_modification(lobby_id,global.product_user_id)
			eos_lobby_modification_add_attribute(EOS_LOBBY_ATTRIBUTE_VISIBILITY.PUBLIC,{key:"lobbyname",value_type: EOS_ATTRIBUTE_TYPE.STRING,value: requestMyName + "'s Lobby"})
			eos_lobby_update_lobby()
			eos_lobby_modification_release()
		}
	break
	
	case "eos_lobby_update_lobby":
		
	break
	
	case "eos_lobby_leave_lobby":
		if(async_load[? "status"] == EpicResult.Success)
		{
			lobby_id = ""
			
			with(obj_rtc) instance_destroy()
			with(obj_eos_lobbies_p2p) instance_destroy()
			with(obj_eos_lobbies_member) instance_destroy()
		}
	break
	
	case "eos_lobby_join_lobby":
	case "eos_lobby_join_lobby_by_id":
		if(async_load[? "status"] == EpicResult.Success)
		{
	        lobby_id = async_load[? "lobby_id"]
			
			request_update_members()//eos_connect_query_product_user_id_mappings
			
			var RTCRoomName = eos_lobby_get_rtc_room_name(global.product_user_id,lobby_id)
			
			show_debug_message("RTCRoomName: " + RTCRoomName)
			
			instance_create_depth(0,0,0,obj_rtc,{RoomName: RTCRoomName})
	        instance_create_depth(0,0,0,obj_eos_lobbies_p2p)
			
	        if(eos_lobby_copy_lobby_details_handle(lobby_id,global.product_user_id) == EpicResult.Success)
	        {
				show_debug_message(eos_lobby_details_copy_attribute_by_key("lobbyname"))
				
	            var count = eos_lobby_details_get_member_count()
				
	            show_debug_message($"Joined, now setup P2P: {count}")
	            for(var a = 0 ; a < count ; a++)
	            {
	                var _user_id = eos_lobby_details_get_member_by_index(a)
					if(_user_id != global.product_user_id)
					{
		                var buff = buffer_create(256,buffer_fixed,1)
		                buffer_write(buff,buffer_u8,1)
		                eos_p2p_send_packet(buff,buffer_tell(buff),true,false,noone,global.product_user_id,true,_user_id,obj_eos_lobbies_p2p.socketName)
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
	
		if(eos_lobby_copy_lobby_details_handle_by_invite_id(async_load[? "invite_id"]) == EpicResult.Success)
		{
			eos_lobby_join_lobby(global.product_user_id,true,true,true,false,false,false,0/*EOS_RTC_JOINROOMFLAGS_ENABLE_DATACHANNEL or EOS_RTC_JOINROOMFLAGS_ENABLE_ECHO*/)
			eos_lobby_details_release()
		}
		
	break
	
	case "eos_lobby_add_notify_lobby_invite_received":
	break
	
	case "eos_lobby_add_notify_lobby_invite_rejected":
		eos_lobby_reject_invite(async_load[? "invite_id"],global.product_user_id)
	break
	
	case "eos_lobby_add_notify_lobby_member_status_received":
		
		if(async_load[? "target_user_id"] == global.product_user_id)
		{
			switch(async_load[? "current_status"])
			{
				case EOS_LOBBY_MEMBER_STATUS.DISCONNECTED:
				case EOS_LOBBY_MEMBER_STATUS.CLOSED:
				case EOS_LOBBY_MEMBER_STATUS.LEFT:
					show_message_async("DISCONNECTED...")
					lobby_id = ""
					with(obj_eos_lobbies_member) instance_destroy()
					with(obj_rtc) instance_destroy()
					with(obj_eos_lobbies_p2p) instance_destroy()
				break
				
				case EOS_LOBBY_MEMBER_STATUS.PROMOTED:
					show_message_async("I was PROMOTED :)")
				break
				case EOS_LOBBY_MEMBER_STATUS.KICKED:
					show_message_async("I was KICKED D:")
					lobby_id = ""
					with(obj_eos_lobbies_member) instance_destroy()
					with(obj_rtc) instance_destroy()
					with(obj_eos_lobbies_p2p) instance_destroy()
				break
			}
		}
		else
		{
			switch(async_load[? "current_status"])
			{
				case EOS_LOBBY_MEMBER_STATUS.JOINED:
					request_update_members()
				break
				
				case EOS_LOBBY_MEMBER_STATUS.DISCONNECTED:
				case EOS_LOBBY_MEMBER_STATUS.KICKED:
				case EOS_LOBBY_MEMBER_STATUS.LEFT:
					request_update_members()//eos_connect_query_product_user_id_mappings
					obj_eos_p2p.disconnect(async_load[? "target_user_id"])
				break
				
				
			}
		}
		
	
	break
	
	case "eos_connect_query_product_user_id_mappings":
		
		if(requestMyName == async_load[? "identifier"])
		{
			var _struct = eos_connect_copy_product_user_external_account_by_index(global.product_user_id,0)
			requestMyName = _struct.display_name
			
			return
		}
		
		with(obj_eos_lobbies_member)
			instance_destroy()
				
		for(var b = 0 ; b < array_length(members_array) ; b++)
		{
			var count = eos_connect_get_product_user_external_account_count(members_array[b])
			
			for(var a = 0 ; a < count ; a++)
			{
				_struct = eos_connect_copy_product_user_external_account_by_index(members_array[b],a)
				show_debug_message(_struct)
				instance_create_depth(300,220+b*100,0,obj_eos_lobbies_member,_struct)
				
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
			
			var ins = instance_create_depth(obj_eos_lobbies_search.x,obj_eos_lobbies_search.y+100+a*100,0,obj_eos_lobbies_lobby,struct)
			ins.text = attribute.value
		}
		eos_lobby_search_release()
		
	break
	
	case "eos_rtc_audio_add_notify_participant_updated":
		
		with(obj_eos_lobbies_member)
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
			
		for(var a = 0 ; a < eos_lobby_get_invite_count(global.product_user_id) ; a++)
		{
			var inviteId = eos_lobby_get_invite_id_by_index(global.product_user_id,a)
			eos_lobby_copy_lobby_details_handle_by_invite_id(inviteId)
			
			var struct = eos_lobby_details_copy_info()
			var attribute = eos_lobby_details_copy_attribute_by_key("lobbyname")
			eos_lobby_details_release()
			
			var ins = instance_create_depth(obj_eos_lobbies_invitations.x,obj_eos_lobbies_invitations.y+100+a*100,0,obj_eos_lobbies_lobby,struct)
			ins.text = attribute.value
		}
		
	break
}
