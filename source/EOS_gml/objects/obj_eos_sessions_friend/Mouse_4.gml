
show_debug_message($"eos_sessions_send_invite: session={obj_eos_sessions.SessionName} to={data.user_id}")

eos_sessions_send_invite(obj_eos_sessions.SessionName, global.product_user_id, data.user_id, function(_info)
{
	// EpicSessionsSendInviteCallbackInfo: .result_code
	show_debug_message("send_invite: " + eos_api_result_to_string(_info.result_code))
})
