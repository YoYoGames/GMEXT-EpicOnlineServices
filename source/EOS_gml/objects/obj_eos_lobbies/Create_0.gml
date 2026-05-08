
event_inherited()

text       = "Lobby"
lobby_id   = ""
mDisplayName  = ""
members_array = []

// ============================================================
// Helpers
// ============================================================

// Refresh the member list and (re)create obj_eos_lobbies_member tiles.
// Replaces the old async dispatch via "eos_connect_query_product_user_id_mappings".
function request_update_members()
{
	if(lobby_id == "") return

	var _details = eos_lobby_copy_lobby_details_handle(lobby_id, global.product_user_id)
	if(!_details) return

	members_array = []
	var _count = eos_lobby_details_get_member_count(_details)
	for(var a = 0; a < _count; a++)
		array_push(members_array, eos_lobby_details_get_member_by_index(_details, a))
	eos_lobby_details_release(_details)

	// Cache the external account info for each member, then rebuild the UI tiles.
	eos_connect_query_product_user_id_mappings(global.product_user_id, EpicExternalAccountType.Epic, members_array, method(self, function(_info)
	{
		if(_info.result_code != EpicResult.Success) return

		with(obj_eos_lobbies_member)
			instance_destroy()

		for(var b = 0; b < array_length(members_array); b++)
		{
			var _account_count = eos_connect_get_product_user_external_account_count(members_array[b])
			for(var c = 0; c < _account_count; c++)
			{
				var _struct = eos_connect_copy_product_user_external_account_by_index(members_array[b], c)
				show_debug_message(_struct)
				instance_create_depth(300, 220 + b * 100, 0, obj_eos_lobbies_member, {data: _struct})
				break // only the first account is needed for display
			}
		}
	}))
}

// Look up our own display name once at startup.
eos_connect_query_product_user_id_mappings(global.product_user_id, EpicExternalAccountType.Epic, [global.product_user_id], function(_info)
{
	if(_info.result_code != EpicResult.Success) return
	var _struct = eos_connect_copy_product_user_external_account_by_index(global.product_user_id, 0)
	mDisplayName = _struct.display_name
})

// ============================================================
// Persistent notifications — these stay registered until CleanUp.
// (One-shot results like create/join/leave are wired at the call site.)
// ============================================================

notifyJoinLobbyAccepted = eos_lobby_add_notify_join_lobby_accepted(function(_info)
{
	// EpicLobbyJoinLobbyAcceptedCallbackInfo: .ui_event_id
	// (No body in the original example.)
})

notifyLeaveLobbyRequested = eos_lobby_add_notify_leave_lobby_requested(global.product_user_id, function(_info)
{
	// EpicLobbyLeaveLobbyRequestedCallbackInfo: .lobby_id, .local_user_id
	// (No body in the original example.)
})

notifyLobbyInviteAccepted = eos_lobby_add_notify_lobby_invite_accepted(function(_info)
{
	// EpicLobbyLobbyInviteAcceptedCallbackInfo: .invite_id, .local_user_id, .target_user_id
	show_debug_message($"lobby invite accepted: {_info.invite_id}")

	var _details_id = eos_lobby_copy_lobby_details_handle_by_invite_id(_info.invite_id)
	if(_details_id == 0)
	{
		show_debug_message("could not get lobby details from invite")
		return
	}

	var _details = eos_lobby_details_copy_info(_details_id)
	eos_lobby_details_release(_details_id)

	var _opts = new EpicLobbyJoinLobbyOptions()
	_opts.lobby_id         = _details.lobby_id
	_opts.local_user_id    = global.product_user_id
	_opts.presence_enabled = true
	eos_lobby_join_lobby(_opts)
})

notifyLobbyInviteReceived = eos_lobby_add_notify_lobby_invite_received(function(_info)
{
	// EpicLobbyLobbyInviteReceivedCallbackInfo: .invite_id, .local_user_id, .target_user_id
})

notifyLobbyInviteRejected = eos_lobby_add_notify_lobby_invite_rejected(function(_info)
{
	// EpicLobbyLobbyInviteRejectedCallbackInfo: .invite_id, .local_user_id, .target_user_id
	eos_lobby_reject_invite(_info.invite_id, global.product_user_id)
})

notifyLobbyMemberStatusReceived = eos_lobby_add_notify_lobby_member_status_received(global.product_user_id, function(_info)
{
	// EpicLobbyLobbyMemberStatusReceivedCallbackInfo:
	//   .lobby_id, .target_user_id, .local_user_id, .current_status (EpicLobbyMemberStatus)
	if(_info.target_user_id == global.product_user_id)
	{
		switch(_info.current_status)
		{
			case EpicLobbyMemberStatus.Disconnected:
			case EpicLobbyMemberStatus.Closed:
			case EpicLobbyMemberStatus.Left:
				show_message_async("DISCONNECTED...")
				lobby_id = ""
				with(obj_eos_lobbies_member) instance_destroy()
				with(obj_rtc) instance_destroy()
				with(obj_eos_lobbies_p2p) instance_destroy()
			break

			case EpicLobbyMemberStatus.Promoted:
				show_message_async("I was PROMOTED :)")
			break

			case EpicLobbyMemberStatus.Kicked:
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
		switch(_info.current_status)
		{
			case EpicLobbyMemberStatus.Joined:
				request_update_members()
			break

			case EpicLobbyMemberStatus.Disconnected:
			case EpicLobbyMemberStatus.Kicked:
			case EpicLobbyMemberStatus.Left:
				request_update_members()
				if(instance_exists(obj_eos_p2p))
					obj_eos_p2p.disconnect(_info.target_user_id)
			break
		}
	}
})

notifyLobbyMemberUpdateReceived = eos_lobby_add_notify_lobby_member_update_received(global.product_user_id, function(_info)
{
	// EpicLobbyLobbyMemberUpdateReceivedCallbackInfo: .lobby_id, .target_user_id, .local_user_id
})

notifyLobbyUpdateReceived = eos_lobby_add_notify_lobby_update_received(global.product_user_id, function(_info)
{
	// EpicLobbyLobbyUpdateReceivedCallbackInfo: .lobby_id, .local_user_id
})

notifySendLobbyNativeInviteRequested = eos_lobby_add_notify_send_lobby_native_invite_requested(global.product_user_id, function(_info)
{
	// EpicLobbySendLobbyNativeInviteRequestedCallbackInfo:
	//   .lobby_id, .local_user_id, .target_native_account_type, .target_user_native_account_id
})

notifyRTCRoomConnectionChanged = eos_lobby_add_notify_rtc_room_connection_changed(function(_info)
{
	// EpicLobbyRTCRoomConnectionChangedCallbackInfo:
	//   .lobby_id, .local_user_id, .is_connected (bool), .disconnect_reason (EpicResult)
	if(_info.is_connected)
		show_debug_message($"RTC room connected (lobby {_info.lobby_id})")
	else
		show_debug_message($"RTC room disconnected (lobby {_info.lobby_id}): {eos_api_result_to_string(_info.disconnect_reason)}")
})
