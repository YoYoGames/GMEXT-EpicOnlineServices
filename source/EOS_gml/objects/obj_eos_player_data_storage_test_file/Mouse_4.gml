
if(file_exists(global.eos_storage_dir + spr_filename))
	spr = sprite_add(global.eos_storage_dir + spr_filename,0,0,0,0,0)
else
	show_message_async($"{spr_filename} doesn't exists")

