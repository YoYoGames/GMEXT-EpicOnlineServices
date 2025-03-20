
event_inherited();

text = "Lobby"

LobbyId = ""

notifyJoinLobbyAccepted = EpicGames_Lobby_AddNotifyJoinLobbyAccepted()
notifyLeaveLobbyRequested = EpicGames_Lobby_AddNotifyLeaveLobbyRequested()
notifyLobbyInviteAccepted = EpicGames_Lobby_AddNotifyLobbyInviteAccepted()
notifyLobbyInviteReceived = EpicGames_Lobby_AddNotifyLobbyInviteReceived()
notifyLobbyInviteRejected = EpicGames_Lobby_AddNotifyLobbyInviteRejected()
notifyLobbyMemberStatusReceived = EpicGames_Lobby_AddNotifyLobbyMemberStatusReceived()
notifyLobbyMemberUpdateReceived = EpicGames_Lobby_AddNotifyLobbyMemberUpdateReceived()
notifyLobbyUpdateReceived = EpicGames_Lobby_AddNotifyLobbyUpdateReceived()
notifyRTCRoomConnectionChanged = EpicGames_Lobby_AddNotifyRTCRoomConnectionChanged()
notifySendLobbyNativeInviteRequested = EpicGames_Lobby_AddNotifySendLobbyNativeInviteRequested()

function request_update_members()
{
	var result = EpicGames_Lobby_CopyLobbyDetailsHandle(LobbyId,userID)
	show_debug_message("request_update_members: " + string(result))
	
	if(EpicGames_Lobby_CopyLobbyDetailsHandle(LobbyId,userID) == EpicGames_Success)
	{
		/*var*/ members_array = []
		var member_count = EpicGames_LobbyDetails_GetMemberCount()
		for(var a = 0 ; a < member_count ; a++)
		{
			var user = EpicGames_LobbyDetails_GetMemberByIndex(a)
			array_push(members_array,user)
		}
		
		EpicGames_LobbyDetails_Release()
			
		show_debug_message(members_array)
		EpicGames_Connect_QueryProductUserIdMappings(userID,members_array)
	}
}

