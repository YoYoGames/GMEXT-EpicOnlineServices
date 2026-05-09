
eos_sessions_end_session(obj_eos_sessions.SessionName, function(_info)
{
	// EpicSessionsEndSessionCallbackInfo: .result_code
	show_debug_message("end_session: " + eos_api_result_to_string(_info.result_code))
})
