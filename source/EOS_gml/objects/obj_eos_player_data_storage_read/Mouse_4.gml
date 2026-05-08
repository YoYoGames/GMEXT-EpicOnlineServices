
show_debug_message("User: " + global.product_user_id)
show_debug_message("Account: " + global.epic_account_id)

with(obj_eos_player_data_storage_file_download)
	instance_destroy()

eos_playerdatastorage_query_file_list(global.product_user_id, function(_info)
{
	// _info is an EpicPlayerDataStorageQueryFileListCallbackInfo:
	//   .result_code (EpicResult)
	//   .local_user_id (string)
	//   .file_count (int64)

	if (_info.result_code != EpicResult.Success)
	{
		show_debug_message("query_file_list failed: " + eos_api_result_to_string(_info.result_code))
		return
	}

	show_debug_message($"DOWNLOADING FILES ({_info.file_count})")
	var count = eos_playerdatastorage_get_file_metadata_count(global.product_user_id)
	for (var a = 0; a < count; a++)
	{
		var struct = eos_playerdatastorage_copy_file_metadata_at_index(global.product_user_id, a)
		show_debug_message($"{a}: {struct}")
		instance_create_depth(100, 300 + a * 100, 0, obj_eos_player_data_storage_file_download, struct)
	}
})
