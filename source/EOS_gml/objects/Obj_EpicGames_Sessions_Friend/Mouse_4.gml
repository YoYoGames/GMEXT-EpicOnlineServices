
//eos_sessions_send_invite(userID,)
show_debug_message("eos_sessions_send_invite")
show_debug_message(userID)
show_debug_message(Obj_EpicGames_Session.SessionName)
show_debug_message(UserID)
var result = eos_sessions_send_invite(userID,Obj_EpicGames_Session.SessionName,UserID)
show_debug_message(result)
