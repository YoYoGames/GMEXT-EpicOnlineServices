
event_inherited();

mDisplayName = ""
requestMyName = eos_connect_query_product_user_id_mappings(global.product_user_id,EpicExternalAccountType.Epic,[global.product_user_id])

text = "Lobby"

lobby_id = ""

notifyJoinLobbyAccepted = eos_lobby_add_notify_join_lobby_accepted()
notifyLeaveLobbyRequested = eos_lobby_add_notify_leave_lobby_requested(global.product_user_id)
notifyLobbyInviteAccepted = eos_lobby_add_notify_lobby_invite_accepted()
notifyLobbyInviteReceived = eos_lobby_add_notify_lobby_invite_received()
notifyLobbyInviteRejected = eos_lobby_add_notify_lobby_invite_rejected()
notifyLobbyMemberStatusReceived = eos_lobby_add_notify_lobby_member_status_received(global.product_user_id)
notifyLobbyMemberUpdateReceived = eos_lobby_add_notify_lobby_member_update_received(global.product_user_id)
notifyLobbyUpdateReceived = eos_lobby_add_notify_lobby_update_received(global.product_user_id)
//notifyRTCRoomConnectionChanged = eos_lobby_add_notify_rtc_room_connection_changed()//TODO?
notifySendLobbyNativeInviteRequested = eos_lobby_add_notify_send_lobby_native_invite_requested(global.product_user_id)

function request_update_members()
{
	var _lobby_details_handle = eos_lobby_copy_lobby_details_handle(lobby_id,global.product_user_id)
	if(_lobby_details_handle)
	{
		/*var*/ members_array = []
		var member_count = eos_lobby_details_get_member_count(_lobby_details_handle)
		for(var a = 0 ; a < member_count ; a++)
		{
			var user = eos_lobby_details_get_member_by_index(_lobby_details_handle,a)
			array_push(members_array,user)
		}
		
		eos_lobby_details_release(_lobby_details_handle)
			
		show_debug_message(members_array)
		eos_connect_query_product_user_id_mappings(global.product_user_id,members_array)
	}
}

