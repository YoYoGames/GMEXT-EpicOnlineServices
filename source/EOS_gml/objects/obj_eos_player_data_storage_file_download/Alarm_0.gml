
show_debug_message("Path: " + working_directory+filename)
request = eos_player_data_storage_read_file(global.product_user_id,filename,working_directory+filename)
ins_cancel = instance_create_depth(x+600,y,0,obj_eos_player_data_storage_file_download_cancel,{filename: filename})

