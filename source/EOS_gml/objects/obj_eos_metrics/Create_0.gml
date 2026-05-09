
var struct = eos_metrics_begin_player_session(
		global.product_user_id,
		global.epic_account_id,
		EpicUserControllerType.MouseKeyboard,
		"No Server",
		"AnyRandomIDString"
		)

show_debug_message("eos_metrics_begin_player_session: " + string(struct.status_message))

