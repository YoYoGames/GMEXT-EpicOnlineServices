
if(file_exists(working_directory + spr_filename))
	spr = sprite_add(working_directory + spr_filename,0,0,0,0,0)
else
	show_message_async($"{spr_filename} doesn't exists")

