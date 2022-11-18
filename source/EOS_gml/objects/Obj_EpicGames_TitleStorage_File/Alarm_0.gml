
request = EpicGames_TitleStorage_ReadFile(userID,Filename,working_directory+Filename)
ins_cancel = instance_create_depth(x+600,y,0,Obj_EpicGames_TitleStorage_File_Cancel)
ins_cancel.Filename = Filename

