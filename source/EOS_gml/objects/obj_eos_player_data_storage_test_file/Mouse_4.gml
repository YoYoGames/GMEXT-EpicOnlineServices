
var _path = eos_platform_get_storage_directory() + spr_filename;

if(file_exists(_path))
	spr = sprite_add(_path,0,0,0,0,0)
else
	show_message_async($"{spr_filename} doesn't exists")

