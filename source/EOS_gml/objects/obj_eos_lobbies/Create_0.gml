
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
	if(lobby_id == "") {return}

	var _details = eos_lobby_copy_lobby_details_handle(lobby_id, global.product_user_id)
	if(!_details) {return}

	members_array = []
	var _count = eos_lobby_details_get_member_count(_details)
	for(var a = 0; a < _count; a++)
		array_push(members_array, eos_lobby_details_get_member_by_index(_details, a))
	eos_lobby_details_release(_details)

	show_debug_message($"[members] request_update_members: count={_count} array={members_array}")

	eos_connect_query_product_user_id_mappings(global.product_user_id, members_array, function(_info)
	{
		if(_info.result_code != EpicResult.Success)
		{
			show_debug_message($"[members] query_product_user_id_mappings failed: {eos_api_result_to_string(_info.result_code)}")
			{return}
		}

		show_debug_message($"[members] rebuild: array={members_array}")

		with(obj_eos_lobbies_member)
			instance_destroy()

		for(var b = 0; b < array_length(members_array); b++)
		{
			var _account_count = eos_connect_get_product_user_external_account_count(members_array[b])
			show_debug_message($"[members]  - {members_array[b]} has {_account_count} external accounts")

			for(var c = 0; c < _account_count; c++)
			{
				var _struct = eos_connect_copy_product_user_external_account_by_index(members_array[b], c)
				show_debug_message($"[members]    -> {_struct}")
				instance_create_depth(300, 220 + b * 100, 0, obj_eos_lobbies_member, {data: _struct})
				break // only the first account is needed for display
			}
		}
	})
}

// Look up our own display name once at startup.
eos_connect_query_product_user_id_mappings(global.product_user_id, [global.product_user_id], function(_info)
{
	if(_info.result_code != EpicResult.Success) {return}
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
		{return}
	}

	var _details = eos_lobby_details_copy_info(_details_id)
	eos_lobby_details_release(_details_id)

	var _opts = new EpicLobbyJoinLobbyByIdOptions()
	_opts.lobby_id         = _details.lobby_id
	_opts.local_user_id    = global.product_user_id
	_opts.presence_enabled = true
	
	//We are accepting automatically.... probably not the best idea on production
	eos_lobby_join_lobby_by_id(_opts, function(_info)
	{
		// EpicLobbyJoinLobbyCallbackInfo: .result_code, .lobby_id
		if(_info.result_code != EpicResult.Success)
		{
			show_debug_message("eos_lobby_join_lobby_by_id failed: " + eos_api_result_to_string(_info.result_code))
			return
		}

		with(obj_eos_lobbies)
		{
			lobby_id = _info.lobby_id

			request_update_members()

			var RTCRoomName = eos_lobby_get_rtc_room_name(global.product_user_id, lobby_id)
			if(is_string(RTCRoomName) && RTCRoomName != "")
				instance_create_depth(0, 0, 0, obj_rtc, {RoomName: RTCRoomName})
			else
				show_debug_message($"eos_lobby_get_rtc_room_name returned: {RTCRoomName}")

			instance_create_depth(0, 0, 0, obj_eos_lobbies_p2p)

			// Send a "hello" packet to every other member so P2P opens both ways.
			var _details = eos_lobby_copy_lobby_details_handle(lobby_id, global.product_user_id)
			if(_details)
			{
				show_debug_message(eos_lobby_details_copy_attribute_by_key(_details, "lobbyname"))

				var _count = eos_lobby_details_get_member_count(_details)
				show_debug_message($"Joined, now setup P2P: {_count}")
				for(var a = 0; a < _count; a++)
				{
					var _user_id = eos_lobby_details_get_member_by_index(_details, a)
					if(_user_id == global.product_user_id) continue

					var _buff = buffer_create(256, buffer_fixed, 1)
					buffer_write(_buff, buffer_u8, 1)
					eos_p2p_send_packet(global.product_user_id, _user_id, obj_eos_lobbies_p2p.socketName, 0, _buff, buffer_tell(_buff), true, EpicPacketReliability.ReliableOrdered, false)
					buffer_delete(_buff)
				}
				eos_lobby_details_release(_details)
			}
		}
	})

})

notifyLobbyInviteReceived = eos_lobby_add_notify_lobby_invite_received(function(_info)
{
	// EpicLobbyLobbyInviteReceivedCallbackInfo: .invite_id, .local_user_id, .target_user_id
})

notifyLobbyInviteRejected = eos_lobby_add_notify_lobby_invite_rejected(function(_info)
{
	// EpicLobbyLobbyInviteRejectedCallbackInfo: .invite_id, .local_user_id, .target_user_id
	// This fires AFTER the local user has already rejected an invite — don't call
	// reject_invite again from here (the rejection already happened, and re-calling
	// it would fail or re-fire the notification).
	show_debug_message($"lobby invite {_info.invite_id} rejected by local user")
})

notifyLobbyMemberStatusReceived = eos_lobby_add_notify_lobby_member_status_received(global.product_user_id, function(_info)
{
	// EpicLobbyLobbyMemberStatusReceivedCallbackInfo:
	//   .lobby_id, .target_user_id, .local_user_id, .current_status (EpicLobbyMemberStatus)
	show_debug_message($"[member_status] target={_info.target_user_id} local={global.product_user_id} status={_info.current_status} same={_info.target_user_id == global.product_user_id}")

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
	//   .ui_event_id, .lobby_id, .local_user_id, .target_native_account_type, .target_user_native_account_id
	// MUST acknowledge or the social overlay UI hangs.
	eos_ui_acknowledge_event_id(_info.ui_event_id, EpicResult.Success)
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
