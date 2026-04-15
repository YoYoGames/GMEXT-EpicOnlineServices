
if(async_load[? "type"] == "eos_player_data_storage_query_file_list")
{
	var count = eos_player_data_storage_get_file_metadata_count(global.product_user_id)
	for(var a = 0 ; a < count ; a++)
	{
        if(a == 2)
        {
    		var struct = eos_player_data_storage_copy_file_metadata_at_index(global.product_user_id,a)
    		instance_create_depth(100,300+a*100,0,obj_eos_player_data_storage_file_download,struct)
        }
	}
}
