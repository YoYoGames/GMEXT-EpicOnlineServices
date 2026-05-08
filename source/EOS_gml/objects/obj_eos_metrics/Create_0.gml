
var struct = eos_metrics_begin_player_session(
		global.epic_account_id,
		"YYEpicGames",
		EpicMetricsAccountIdType.Epic,
		EpicUserControllerType.MouseKeyboard,
		"No Server",
		"AnyRandomIDString")

show_debug_message("eos_metrics_begin_player_session: " + string(struct.status_message))

