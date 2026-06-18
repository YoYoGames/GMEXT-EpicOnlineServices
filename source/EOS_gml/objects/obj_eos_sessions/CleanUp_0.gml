//When you no longer need a session, you must destroy it using: eos_sessions_destroy_session()
eos_sessions_destroy_session(SessionName, function(_info)
{
	show_debug_message("destroy_session (cleanup): " + eos_api_result_to_string(_info.result_code))
})

// Tear down everything we spawned for this session so nothing leaks across rooms:
//   - the P2P relay (its own CleanUp closes the EOS connections)
//   - any search-result / session tiles
with(obj_eos_sessions_p2p) instance_destroy()
with(obj_eos_session)      instance_destroy()

// Release the session-search handle (it's a global, so it survives room changes).
if(variable_global_exists("session_search_id") && global.session_search_id != 0)
{
	eos_sessions_session_search_release(global.session_search_id)
	global.session_search_id = 0
}

eos_sessions_remove_notify_join_session_accepted(notifyJoinSessionAccepted)
eos_sessions_remove_notify_leave_session_requested(notifyLeaveSessionRequested)
eos_sessions_remove_notify_send_session_native_invite_requested(notifySendSessionNativeInviteRequested)
eos_sessions_remove_notify_session_invite_accepted(notifySessionInviteAccepted)
eos_sessions_remove_notify_session_invite_received(notifySessionInviteReceived)
eos_sessions_remove_notify_session_invite_rejected(notifySessionInviteRejected)
