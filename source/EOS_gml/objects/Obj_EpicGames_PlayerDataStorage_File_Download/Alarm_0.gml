
request = EpicGames_PlayerDataStorage_ReadFile(userID,Filename,working_directory+Filename)
ins_cancel = instance_create_depth(x+600,y,0,Obj_EpicGames_PlayerDataStorage_File_Download_Cancel)
ins_cancel.Filename = Filename

