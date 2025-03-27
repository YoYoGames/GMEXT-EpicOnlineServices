
request = eos_player_data_storage_read_file(userID,filename,working_directory+filename)
ins_cancel = instance_create_depth(x+600,y,0,Obj_EpicGames_PlayerDataStorage_File_Download_Cancel,{filename: filename})

