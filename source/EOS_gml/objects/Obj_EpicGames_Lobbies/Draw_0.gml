
//EpicGames_Lobby_CopyLobbyDetailsHandleByInviteId(char* InviteId)
if(EpicGames_Lobby_CopyLobbyDetailsHandle(LobbyId,userID) == EpicGames_Success)
{
	var member_count = EpicGames_LobbyDetails_GetMemberCount()
	draw_text(100,100,member_count)
	
	for(var a = 0 ; a < member_count ; a++)
	{
		var user = EpicGames_LobbyDetails_GetMemberByIndex(a)
		draw_text(300,300+a*100,user)
	}
	
	EpicGames_LobbyDetails_Release()
}

