
var struct = eos_metrics_begin_player_session(
		AccountID,
		"YYEpicGames",
		EOS_METRIC_ACCOUNT_ID_TYPE.Epic,
		EOS_USER_CONTROLLER_TYPE.MouseKeyboard,
		"No Server",
		"AnyRandomIDString")

show_debug_message("eos_metrics_begin_player_session: " + string(struct.status_message))

