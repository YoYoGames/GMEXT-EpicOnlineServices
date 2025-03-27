
var struct = eos_metrics_begin_player_session(
		AccountID,
		"YYEpicGames",
		EOS_MetricsAccountIdType.Epic,
		EOS_UserControllerType.MouseKeyboard,
		"No Server",
		"AnyRandomIDString")

show_debug_message("eos_metrics_begin_player_session: " + string(struct.status_message))

