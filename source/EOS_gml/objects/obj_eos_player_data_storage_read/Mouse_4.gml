
show_debug_message("User: " + global.product_user_id)
show_debug_message("Account: " + global.epic_account_id)

with(obj_eos_player_data_storage_file_download)
	instance_destroy()

eos_player_data_storage_query_file_list(global.product_user_id)
