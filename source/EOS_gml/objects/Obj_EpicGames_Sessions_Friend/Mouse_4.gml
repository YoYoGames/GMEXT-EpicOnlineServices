
//eos_sessions_send_invite(userID,)
show_debug_message("eos_sessions_send_invite")
show_debug_message(Obj_EpicGames_Sessions.SessionName)
var result = eos_sessions_send_invite(userID,Obj_EpicGames_Sessions.SessionName,user_id)
show_debug_message(result)
