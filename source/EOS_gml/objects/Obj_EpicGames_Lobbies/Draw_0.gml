
//EpicGames_Lobby_CopyLobbyDetailsHandleByInviteId(char* InviteId)
if(EpicGames_Lobby_CopyLobbyDetailsHandle(LobbyId,userID) == EpicGames_Success)
{
	//EpicGames_LobbyDetails_GetMemberByIndex()
	draw_text(100,100,EpicGames_LobbyDetails_GetMemberCount())
	
	EpicGames_LobbyDetails_Release()
}

