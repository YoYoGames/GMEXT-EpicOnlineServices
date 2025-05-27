
switch(async_load[? "type"])
{
	case "eos_sessions_update_session":
		
		if(async_load[? "status"] == EOS_RESULT.Success)
		{
			instance_create_depth(0,0,0,Obj_EpicGames_Sessions_P2P,{owner: true})
			
			eos_sessions_register_players(SessionName,[userID])
		}
		
	break
	
	case "eos_sessions_add_notify_join_session_accepted":
		
	break
	
	case "eos_sessions_add_notify_leave_session_requested":
		
	break
	
	case "eos_sessions_add_notify_send_session_native_invite_requested":
		
	break
	
	case "eos_sessions_add_notify_session_invite_accepted":
		
		eos_sessions_copy_session_handle_by_invite_id(async_load[? "invite_id"])
		eos_sessions_join_session(true,userID,SessionName)
		eos_session_details_release()
		
	break
	
	case "eos_sessions_add_notify_session_invite_received":
		
		show_message_async("Session Invite Received")
		
	break
	
	case "eos_sessions_add_notify_session_invite_rejected":
		
		eos_sessions_reject_invite(userID,async_load[? "invite_id"])
		
	break
	
case "eos_sessions_join_session":

        if(async_load[? "status"] == EOS_RESULT.Success)
        {
            instance_create_depth(0,0,0,Obj_EpicGames_Sessions_P2P,{owner: false})
			
            var _struct = eos_active_session_copy_info(SessionName)
            var buff = buffer_create(256,buffer_fixed,1)
            buffer_write(buff,buffer_u8,1)
            eos_p2p_send_packet(buff,buffer_tell(buff),true,false,noone,userID,true,_struct.details.owner_user_id,Obj_EpicGames_Sessions_P2P.socketName)
            buffer_delete(buff)
        }

    break
	
	case "eos_sessions_reject_invite":
	break
	
	case "eos_sessions_destroy_session":
		
		if(async_load[? "status"] == EOS_RESULT.Success)
		{
			with(Obj_EpicGames_Sessions_P2P)
				instance_destroy()
		}
		
	break
	
	
	case "eos_session_search_find":
		
		var count = eos_session_search_get_search_result_count()
		show_debug_message(count)
		for(var a = 0 ; a < count ; a++)
		{
            //{ session_id : "01822382001931934", settings : { allowed_platform_ids : [  ], allow_join_in_progress : 1, invites_allowed : 1, sanctions_enabled : 1, bucket_id : "GameMode:Region:MapName", num_public_connections : 3, permission_level : 0 }, host_address : "201.143.74.141", num_open_public_connections : 3, owner_user_id : "0002aaccc4764605a9e585fda4b11c78" }
			eos_session_search_copy_search_result_by_index(a)
            var struct = eos_session_details_copy_info()
			show_debug_message(struct)
            var ins = instance_create_depth(Obj_EpicGames_Sessions_Search.x,Obj_EpicGames_Sessions_Search.y+100+a*100,0,Obj_EpicGames_Session,struct)
			ins.text = struct.session_id
            ins.index = a
			eos_session_details_release()
		}
		//eos_session_search_release()
		
	break
}
