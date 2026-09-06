
eos_sessions_start_session(obj_eos_sessions.SessionName, function(_info)
{
	// EpicSessionsStartSessionCallbackInfo: .result_code
	show_debug_message("start_session: " + eos_api_result_to_string(_info.result_code))
})
