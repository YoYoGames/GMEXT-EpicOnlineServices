

if (!file_exists(filename)) {
	show_debug_message("[NOTE] First go into the Title Storage and download the files");
	instance_destroy();
	return;
}

request = eos_player_data_storage_write_file(userID,filename,working_directory+filename)
ins_cancel = instance_create_depth(x+600,y,0,Obj_EpicGames_PlayerDataStorage_File_Upload_Cancel,{filename: filename})
