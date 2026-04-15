

if (!file_exists(filename)) {
	show_debug_message("[NOTE] First go into the Title Storage and download the files");
	instance_destroy();
	return;
}

request = eos_player_data_storage_write_file(global.product_user_id,filename,working_directory+filename)
ins_cancel = instance_create_depth(x+600,y,0,obj_eos_player_data_storage_file_upload_cancel,{filename: filename})
