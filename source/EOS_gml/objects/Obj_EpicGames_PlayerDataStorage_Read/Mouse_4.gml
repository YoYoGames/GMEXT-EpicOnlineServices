
show_debug_message("User: " + userID)
show_debug_message("Account: " + AccountID)

with(Obj_EpicGames_PlayerDataStorage_File_Download)
	instance_destroy()

EpicGames_PlayerDataStorage_QueryFileList(userID)
