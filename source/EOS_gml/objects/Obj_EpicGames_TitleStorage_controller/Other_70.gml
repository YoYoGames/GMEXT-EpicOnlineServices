
if(async_load[? "type"] == "eos_title_storage_query_file_list")
{
	var count = eos_title_storage_get_file_metadata_count(userID)
	for(var a = 0 ; a < count ; a++)
	{
		var struct = eos_title_storage_copy_file_metadata_at_index(userID,a)
		if(struct.status == EOS_RESULT.SUCCESS)
		{
			instance_create_depth(bbox_left,300+a*100,0,Obj_EpicGames_TitleStorage_File,struct)
		}
	}
}
