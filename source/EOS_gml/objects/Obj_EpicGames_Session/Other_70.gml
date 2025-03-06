
switch(async_load[?"type"])
{
	case "EpicGames_Sessions_UpdateSession":
		
		if(async_load[?"status"] == EpicGames_Success)
		{
			instance_create_depth(0,0,0,Obj_EpicGames_Sessions_P2P,{owner: true})
			
			EpicGames_Sessions_RegisterPlayers(SessionName,[userID])
		}
		
	break
	
	case "EpicGames_Sessions_AddNotifyJoinSessionAccepted":
		
	break
	
	case "EpicGames_Sessions_AddNotifyLeaveSessionRequested":
		
	break
	
	case "EpicGames_Sessions_AddNotifySendSessionNativeInviteRequested":
		
	break
	
	case "EpicGames_Sessions_AddNotifySessionInviteAccepted":
		
		EpicGames_Sessions_CopySessionHandleByInviteId(async_load[?"invite_id"])
		EpicGames_Sessions_JoinSession(true,userID,SessionName)
		EpicGames_SessionDetails_Release()
		
	break
	
	case "EpicGames_Sessions_AddNotifySessionInviteReceived":
		
		show_message_async("Session Invite Received")
		
	break
	
	case "EpicGames_Sessions_AddNotifySessionInviteRejected":
		
		EpicGames_Sessions_RejectInvite(userID,async_load[?"invite_id"])
		
	break
	
case "EpicGames_Sessions_JoinSession":

        if(async_load[?"status"] == EpicGames_Success)
        {
            instance_create_depth(0,0,0,Obj_EpicGames_Sessions_P2P,{owner: false})
			
            var _struct = EpicGames_ActiveSession_CopyInfo(SessionName)
            var buff = buffer_create(256,buffer_fixed,1)
            buffer_write(buff,buffer_u8,1)
            EpicGames_P2P_SendPacket(buff,buffer_tell(buff),true,false,noone,userID,true,_struct.Details.OwnerUserId,Obj_EpicGames_Sessions_P2P.socketName)
            buffer_delete(buff)
        }

    break
	
	case "EpicGames_Sessions_RejectInvite":
	break
	
	case "EpicGames_Sessions_DestroySession":
		
		if(async_load[?"status"] == EpicGames_Success)
		{
			with(Obj_EpicGames_Sessions_P2P)
				instance_destroy()
		}
		
	break
}
