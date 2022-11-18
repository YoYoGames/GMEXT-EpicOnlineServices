
if(async_load[?"type"] == "EpicGames_PlayerDataStorage_QueryFileList")
{
	var count = EpicGames_PlayerDataStorage_GetFileMetadataCount(userID)
	for(var a = 0 ; a < count ; a++)
	{
		var struct = EpicGames_PlayerDataStorage_CopyFileMetadataAtIndex(userID,a)
		
		var ins = instance_create_depth(100,300+a*100,0,Obj_EpicGames_PlayerDataStorage_File_Download)
		ins.Filename = struct.Filename
	}
}
