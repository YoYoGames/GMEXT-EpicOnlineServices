
with(Obj_EpicGames_PlayerDataStorage_File_Upload)
	instance_destroy()

var ins = instance_create_depth(bbox_left,300,0,Obj_EpicGames_PlayerDataStorage_File_Upload)
ins.filename = "GMicon.png"

var ins = instance_create_depth(bbox_left,300+100,0,Obj_EpicGames_PlayerDataStorage_File_Upload)
ins.filename = "text.txt"

var ins = instance_create_depth(bbox_left,300+200,0,Obj_EpicGames_PlayerDataStorage_File_Upload)
ins.filename = "YoYo_Opera.png"

