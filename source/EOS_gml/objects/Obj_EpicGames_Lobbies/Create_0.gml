
event_inherited();

mDisplayName = ""
requestMyName = eos_connect_query_product_user_id_mappings(userID,[userID])

text = "Lobby"

LobbyId = ""

notifyJoinLobbyAccepted = eos_lobby_add_notify_join_lobby_accepted()
notifyLeaveLobbyRequested = eos_lobby_add_notify_leave_lobby_requested()
notifyLobbyInviteAccepted = eos_lobby_add_notify_lobby_invite_accepted()
notifyLobbyInviteReceived = eos_lobby_add_notify_lobby_invite_received()
notifyLobbyInviteRejected = eos_lobby_add_notify_lobby_invite_rejected()
notifyLobbyMemberStatusReceived = eos_lobby_add_notify_lobby_member_status_received()
notifyLobbyMemberUpdateReceived = eos_lobby_add_notify_lobby_member_update_received()
notifyLobbyUpdateReceived = eos_lobby_add_notify_lobby_update_received()
notifyRTCRoomConnectionChanged = eos_lobby_add_notify_rtc_room_connection_changed()
notifySendLobbyNativeInviteRequested = eos_lobby_add_notify_send_lobby_native_invite_requested()

function request_update_members()
{
	if(eos_lobby_copy_lobby_details_handle(LobbyId,userID) == EOS_SUCCESS)
	{
		/*var*/ members_array = []
		var member_count = eos_lobby_details_get_member_count()
		for(var a = 0 ; a < member_count ; a++)
		{
			var user = eos_lobby_details_get_member_by_index(a)
			array_push(members_array,user)
		}
		
		eos_lobby_details_release()
			
		show_debug_message(members_array)
		eos_connect_query_product_user_id_mappings(userID,members_array)
	}
}

