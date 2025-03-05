
//EpicGames_Sessions_SendInvite(userID,)
show_debug_message("EpicGames_Sessions_SendInvite")
show_debug_message(userID)
show_debug_message(Obj_EpicGames_Session.SessionName)
show_debug_message(UserID)
var result = EpicGames_Sessions_SendInvite(userID,Obj_EpicGames_Session.SessionName,UserID)
show_debug_message(result)
