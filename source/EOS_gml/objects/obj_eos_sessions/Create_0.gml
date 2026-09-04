
event_inherited()

text = "Sessions"
SessionName = "mySession"

/// @desc Join a session under our single fixed LOCAL name (SessionName),
/// tearing down any stale local session with that name first so a fast
/// leave -> rejoin can't fail with "session already exists" (the leave's
/// destroy_session is async and may not have completed yet).
/// The caller's `_on_joined` callback owns `_details_id` and must release it.
/// If preconditions fail we release the handle here, because the join
/// callback (which normally releases it) won't fire.
function join_session_clean(_details_id, _on_joined)
{
	if(_details_id == 0 || !is_string(global.product_user_id) || global.product_user_id == "")
	{
		if(_details_id != 0) eos_sessions_session_details_release(_details_id)
		show_debug_message("join_session_clean: missing details handle or product_user_id")
		return false
	}

	var _join = method({ details_id: _details_id, on_joined: _on_joined }, function()
	{
		eos_sessions_join_session(obj_eos_sessions.SessionName, details_id, global.product_user_id, true, on_joined)
	})

	// Stale local session lingering under our name? Destroy it, then join from
	// the destroy callback. Otherwise join immediately.
	var _existing = eos_sessions_copy_active_session_handle(SessionName)
	if(_existing != 0)
	{
		eos_sessions_active_session_release(_existing)
		eos_sessions_destroy_session(SessionName, _join)
	}
	else
	{
		_join()
	}
	return true
}

// ============================================================
// Persistent notifications - wired at registration. One-shot
// results (create/destroy/start/end/join/update/etc.) are wired
// at their call sites in obj_eos_sessions_* / obj_eos_session.
// ============================================================

notifyJoinSessionAccepted = eos_sessions_add_notify_join_session_accepted(function(_info)
{
	// EpicSessionsJoinSessionAcceptedCallbackInfo: .ui_event_id
	show_debug_message("notifyJoinSessionAccepted fired")

	// Copy the session details handle from the overlay event, then join_session - same
	// pattern as notifySessionInviteAccepted below, just a different handle source.
	// Don't release it until the join callback returns - the SDK reads from it during join.
	var _details_id = eos_sessions_copy_session_handle_by_ui_event_id(_info.ui_event_id)
	if(_details_id == 0)
	{
		show_debug_message("could not copy session handle from ui_event_id")
		// MUST acknowledge or the social overlay UI hangs.
		eos_ui_acknowledge_event_id(_info.ui_event_id, EpicResult.InvalidParameters)
		return
	}

	var _ctx = { details_id: _details_id, ui_event_id: _info.ui_event_id }

	var _started = join_session_clean(_details_id, method(_ctx, function(_join_info)
	{
		// EpicSessionsJoinSessionCallbackInfo: .result_code
		eos_sessions_session_details_release(details_id)

		// MUST acknowledge or the social overlay UI hangs - report the real outcome now
		// that we know it, instead of before the join even started.
		eos_ui_acknowledge_event_id(ui_event_id, _join_info.result_code)

		if(_join_info.result_code != EpicResult.Success)
		{
			show_debug_message($"join_session failed: {eos_api_result_to_string(_join_info.result_code)}")
			return
		}
		instance_create_depth(0, 0, 0, obj_eos_sessions_p2p, {owner: false})

		// Register ourselves on the session roster so the host's count reflects us.
		eos_sessions_register_players(obj_eos_sessions.SessionName, [global.product_user_id], function(_reg)
		{
			show_debug_message($"register_players (overlay-joiner): {eos_api_result_to_string(_reg.result_code)}")
		})

		// Hello packet so P2P opens both ways.
		var _handle = eos_sessions_copy_active_session_handle(obj_eos_sessions.SessionName)
		if(_handle != 0)
		{
			var _info_struct = eos_sessions_active_session_copy_info(_handle)
			eos_sessions_active_session_release(_handle)

			var _buff = buffer_create(256, buffer_fixed, 1)
			buffer_write(_buff, buffer_u8, 1)
			eos_p2p_send_packet(global.product_user_id, _info_struct.owner_user_id, obj_eos_sessions_p2p.socketName, 0, _buff, buffer_tell(_buff), true, EpicPacketReliability.ReliableOrdered, false)
			buffer_delete(_buff)
		}
	}))

	if(!_started)
	{
		// join_session_clean's own precondition failed synchronously - its callback never
		// fires, so acknowledge here or the overlay UI hangs forever.
		eos_ui_acknowledge_event_id(_info.ui_event_id, EpicResult.InvalidParameters)
	}
})

notifyLeaveSessionRequested = eos_sessions_add_notify_leave_session_requested(function(_info)
{
	// EpicSessionsLeaveSessionRequestedCallbackInfo: .session_name, .ui_event_id, ...
})

notifySendSessionNativeInviteRequested = eos_sessions_add_notify_send_session_native_invite_requested(function(_info)
{
	// EpicSessionsSendSessionNativeInviteRequestedCallbackInfo: .session_name, .ui_event_id, ...
	// MUST acknowledge or the social overlay UI hangs.
	// Report what actually happened: a real game sends its own invite here (custom invites,
	// a platform invite, ...) and passes that operation's result. This demo does not send
	// anything, so acknowledging Success would tell the overlay a lie.
	eos_ui_acknowledge_event_id(_info.ui_event_id, EpicResult.NotImplemented)
})

notifySessionInviteAccepted = eos_sessions_add_notify_session_invite_accepted(function(_info)
{
	// EpicSessionsSessionInviteAcceptedCallbackInfo: .invite_id, .local_user_id, .target_user_id, .session_id
	// Copy the session details handle from the invite, then pass it to join_session.
	// Don't release it until the join callback returns - the SDK reads from it during join.
	var _details_id = eos_sessions_copy_session_handle_by_invite_id(_info.invite_id)
	if(_details_id == 0)
	{
		show_debug_message("could not copy session handle from invite")
		return
	}

	// Bound struct carries the handle into the callback (var locals don't close over).
	var _ctx = { details_id: _details_id }

	join_session_clean(_details_id, method(_ctx, function(_join_info)
	{
		// EpicSessionsJoinSessionCallbackInfo: .result_code
		eos_sessions_session_details_release(details_id)

		if(_join_info.result_code != EpicResult.Success)
		{
			show_debug_message($"join_session failed: {eos_api_result_to_string(_join_info.result_code)}")
			return
		}
		instance_create_depth(0, 0, 0, obj_eos_sessions_p2p, {owner: false})

		// Register ourselves on the session roster so the host's count reflects us.
		eos_sessions_register_players(obj_eos_sessions.SessionName, [global.product_user_id], function(_reg)
		{
			show_debug_message($"register_players (invite-joiner): {eos_api_result_to_string(_reg.result_code)}")
		})

		// Hello packet so P2P opens both ways.
		var _handle = eos_sessions_copy_active_session_handle(obj_eos_sessions.SessionName)
		if(_handle != 0)
		{
			var _info_struct = eos_sessions_active_session_copy_info(_handle)
			eos_sessions_active_session_release(_handle)

			var _buff = buffer_create(256, buffer_fixed, 1)
			buffer_write(_buff, buffer_u8, 1)
			eos_p2p_send_packet(global.product_user_id, _info_struct.owner_user_id, obj_eos_sessions_p2p.socketName, 0, _buff, buffer_tell(_buff), true, EpicPacketReliability.ReliableOrdered, false)
			buffer_delete(_buff)
		}
	}))
})

notifySessionInviteReceived = eos_sessions_add_notify_session_invite_received(function(_info)
{
	show_message_async("Session Invite Received")
})

notifySessionInviteRejected = eos_sessions_add_notify_session_invite_rejected(function(_info)
{
	// EpicSessionsSessionInviteRejectedCallbackInfo: .invite_id, .local_user_id, .target_user_id
	eos_sessions_reject_invite(global.product_user_id, _info.invite_id)
})
