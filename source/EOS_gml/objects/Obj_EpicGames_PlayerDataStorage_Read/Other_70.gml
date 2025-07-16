
if(async_load[? "type"] == "eos_player_data_storage_query_file_list")
{
	var count = eos_player_data_storage_get_file_metadata_count(userID)
	for(var a = 0 ; a < count ; a++)
	{
        if(a == 2)
        {
    		var struct = eos_player_data_storage_copy_file_metadata_at_index(userID,a)
    		instance_create_depth(100,300+a*100,0,Obj_EpicGames_PlayerDataStorage_File_Download,struct)
        }
	}
}
