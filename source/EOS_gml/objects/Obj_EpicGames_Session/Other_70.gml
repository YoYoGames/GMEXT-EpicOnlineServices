
switch(async_load[?"type"])
{
	case "EpicGames_Sessions_UpdateSession":
		
	break
	
	case "EpicGames_Sessions_AddNotifyJoinSessionAccepted":
		
	break
	
	case "EpicGames_Sessions_AddNotifyLeaveSessionRequested":
		
	break
	
	case "EpicGames_Sessions_AddNotifySendSessionNativeInviteRequested":
		
	break
	
	case "EpicGames_Sessions_AddNotifySessionInviteAccepted":
	
		EpicGames_Sessions_JoinSession(true,userID,SessionName)
		
	break
	
	case "EpicGames_Sessions_AddNotifySessionInviteReceived":
		
		show_message_async("Session Invite Received")
		
	break
	
	case "EpicGames_Sessions_AddNotifySessionInviteRejected":
		
		EpicGames_Sessions_RejectInvite(userID,async_load[?"invite_id"])
		
	break
	
	case "EpicGames_Sessions_JoinSession":
	break
	
	case "EpicGames_Sessions_RejectInvite":
	break
}
