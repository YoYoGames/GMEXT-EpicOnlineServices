
var struct = EpicGames_Metrics_BeginPlayerSession(
		AccountID,
		"YYEpicGames",
		EpicGames_MAIT_Epic,
		EpicGames_UCT_MouseKeyboard,
		"No Server",
		"AnyRandomIDString")

show_debug_message("EpicGames_Metrics_BeginPlayerSession: " + string(struct.status_message))

