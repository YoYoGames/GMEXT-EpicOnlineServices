
if(async_load[?"type"] == "EpicGames_TitleStorage_QueryFileList")
{
	var count = EpicGames_TitleStorage_GetFileMetadataCount(userID)
	for(var a = 0 ; a < count ; a++)
	{
		var struct = EpicGames_TitleStorage_CopyFileMetadataAtIndex(userID,a)
		if(struct.status == EpicGames_Success)
		{
			var ins = instance_create_depth(bbox_left,300+a*100,0,Obj_EpicGames_TitleStorage_File)
			ins.Filename = struct.Filename
		}
	}
}
