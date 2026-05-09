
//filename = ""
porcent = 0

color_progress = c_green
color_failed = c_red
color_done = c_blue

color_current = color_progress

request = noone
ins_cancel = noone;



if (!file_exists(working_directory + filename)) {
	show_debug_message("[NOTE] First go into the Title Storage and download the files");
	instance_destroy();
	return;
}


ins_cancel = instance_create_depth(x + 600, y, 0, obj_eos_player_data_storage_file_upload_cancel, {filename: filename})

eos_playerdatastorage_write_file(
    global.product_user_id,
    filename,
    working_directory + filename,
    function(_info)
    {
        // EpicPlayerDataStorageWriteFileCallbackInfo: result_code, local_user_id, filename
        if (_info.result_code == EpicResult.Success)
            color_current = color_done
        else
        {
            show_debug_message("write_file failed: " + eos_api_result_to_string(_info.result_code))
            color_current = color_failed
        }

        with (ins_cancel)
            instance_destroy()
    },
    function(_info)
    {
        // EpicPlayerDataStorageWriteFileProgressCallbackInfo: bytes_transferred, total_file_size_bytes
        if (_info.total_file_size_bytes > 0)
            porcent = 100 * _info.bytes_transferred / _info.total_file_size_bytes
    })

