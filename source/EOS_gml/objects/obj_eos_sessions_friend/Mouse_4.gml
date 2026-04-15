
//eos_sessions_send_invite(global.product_user_id,)
show_debug_message("eos_sessions_send_invite")
show_debug_message(obj_eos_sessions.SessionName)
var result = eos_sessions_send_invite(global.product_user_id,obj_eos_sessions.SessionName,user_id)
show_debug_message(result)
