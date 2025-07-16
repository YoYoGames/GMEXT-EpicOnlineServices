
show_debug_message("User: " + userID)
show_debug_message("Account: " + AccountID)

with(Obj_EpicGames_PlayerDataStorage_File_Download)
	instance_destroy()

eos_player_data_storage_query_file_list(userID)
