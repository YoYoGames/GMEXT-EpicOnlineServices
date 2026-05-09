
//filename = ""
porcent = 0

color_progress = c_green
color_failed = c_red
color_done = c_blue

color_current = color_progress

request = noone


ins_cancel = instance_create_depth(x + 600, y, 0, obj_eos_player_data_storage_file_download_cancel, {filename: filename})

eos_playerdatastorage_read_file(
    global.product_user_id,
    filename,
    working_directory + filename,
    function(_info)
    {
        // EpicPlayerDataStorageReadFileCallbackInfo: result_code, local_user_id, filename
        if (_info.result_code == EpicResult.Success)
            color_current = color_done
        else
        {
            show_debug_message("read_file failed: " + eos_api_result_to_string(_info.result_code))
            color_current = color_failed
        }

        with (ins_cancel)
            instance_destroy()
    },
    function(_info)
    {
        // EpicPlayerDataStorageReadFileProgressCallbackInfo: bytes_transferred, total_file_size_bytes
        if (_info.total_file_size_bytes > 0)
            porcent = 100 * _info.bytes_transferred / _info.total_file_size_bytes
    })


