
if(async_load[? "type"] == "eos_title_storage_query_file_list")
{
	var count = eos_title_storage_get_file_metadata_count(global.product_user_id)
	for(var a = 0 ; a < count ; a++)
	{
		var struct = eos_title_storage_copy_file_metadata_at_index(global.product_user_id,a)
		if(struct.status == EpicResult.Success)
		{
			instance_create_depth(bbox_left,300+a*100,0,obj_eos_title_storage_file,struct)
		}
	}
}
