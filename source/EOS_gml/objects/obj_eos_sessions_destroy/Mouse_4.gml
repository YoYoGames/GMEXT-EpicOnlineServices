
eos_sessions_destroy_session(obj_eos_sessions.SessionName, function(_info)
{
	// EpicSessionsDestroySessionCallbackInfo: .result_code
	show_debug_message("destroy_session: " + eos_api_result_to_string(_info.result_code))
	if(_info.result_code != EpicResult.Success) {return}

	with(obj_eos_sessions_p2p)
		instance_destroy()
})
