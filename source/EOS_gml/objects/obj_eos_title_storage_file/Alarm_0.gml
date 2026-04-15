
request = eos_title_storage_read_file(global.product_user_id,filename,working_directory+filename)
ins_cancel = instance_create_depth(x+600,y,0,obj_eos_title_storage_file_cancel,{filename: filename})

