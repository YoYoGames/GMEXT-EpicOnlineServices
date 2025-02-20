
switch(async_load[?"type"])
{
	case "EpicGames_Sessions_UpdateSession":
	
		var result = EpicGames_Sessions_SendInvite(userID,SessionName,"0002aaccc4764605a9e585fda4b11c78")
		show_debug_message(result)
		
	break
}
