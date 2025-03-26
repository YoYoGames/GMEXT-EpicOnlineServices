
var struct = eos_metrics_begin_player_session(
		AccountID,
		"YYEpicGames",
		EOS_MAIT_EPIC,
		EOS_UCT_MOUSE_KEYBOARD,
		"No Server",
		"AnyRandomIDString")

show_debug_message("eos_metrics_begin_player_session: " + string(struct.status_message))

