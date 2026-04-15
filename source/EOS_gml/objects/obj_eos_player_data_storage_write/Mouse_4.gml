
with(obj_eos_player_data_storage_file_upload)
	instance_destroy()

var ins = instance_create_depth(bbox_left,300,0,obj_eos_player_data_storage_file_upload)
ins.filename = "GMicon.png"

var ins = instance_create_depth(bbox_left,300+100,0,obj_eos_player_data_storage_file_upload)
ins.filename = "text.txt"

var ins = instance_create_depth(bbox_left,300+200,0,obj_eos_player_data_storage_file_upload)
ins.filename = "YoYo_Opera.png"

