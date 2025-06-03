
var struct = eos_metrics_begin_player_session(
		AccountID,
		"YYEpicGames",
		EOS_METRICS_ACCOUNT_ID_TYPE.EPIC,
		EOS_USER_CONTROLLER_TYPE.MOUSE_KEYBOARD,
		"No Server",
		"AnyRandomIDString")

show_debug_message("eos_metrics_begin_player_session: " + string(struct.status_message))

