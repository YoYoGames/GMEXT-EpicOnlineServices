
event_inherited()

text = "Sessions"
SessionName = "mySession"

// ============================================================
// Persistent notifications — wired at registration. One-shot
// results (create/destroy/start/end/join/update/etc.) are wired
// at their call sites in obj_eos_sessions_* / obj_eos_session.
// ============================================================

notifyJoinSessionAccepted = eos_sessions_add_notify_join_session_accepted(function(_info)
{
	// EpicSessionsJoinSessionAcceptedCallbackInfo: .ui_event_id
})

notifyLeaveSessionRequested = eos_sessions_add_notify_leave_session_requested(function(_info)
{
	// EpicSessionsLeaveSessionRequestedCallbackInfo: .session_name, .ui_event_id, ...
})

notifySendSessionNativeInviteRequested = eos_sessions_add_notify_send_session_native_invite_requested(function(_info)
{
	// EpicSessionsSendSessionNativeInviteRequestedCallbackInfo: .session_name, .ui_event_id, ...
})

notifySessionInviteAccepted = eos_sessions_add_notify_session_invite_accepted(function(_info)
{
	// EpicSessionsSessionInviteAcceptedCallbackInfo: .invite_id, .local_user_id, .target_user_id, .session_id
	// The invite handle exists momentarily; copy it just to validate, then join.
	var _details_id = eos_sessions_copy_session_handle_by_invite_id(_info.invite_id)
	if(_details_id == 0)
	{
		show_debug_message("could not copy session handle from invite")
		return
	}
	eos_sessions_session_details_release(_details_id)

	eos_sessions_join_session(obj_eos_sessions.SessionName, global.product_user_id, function(_join_info)
	{
		// EpicSessionsJoinSessionCallbackInfo: .result_code
		if(_join_info.result_code != EpicResult.Success)
		{
			show_debug_message($"join_session failed: {eos_api_result_to_string(_join_info.result_code)}")
			return
		}
		instance_create_depth(0, 0, 0, obj_eos_sessions_p2p, {owner: false})
	})
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
