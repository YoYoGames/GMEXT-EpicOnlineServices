
// One-shot read; the C++ side streams chunks to a buffer, writes the file on
// completion, then fires `callback`. `progress_callback` fires per chunk.

ins_cancel = instance_create_depth(x + 600, y, 0, obj_eos_player_data_storage_file_download_cancel, {filename: filename})

eos_playerdatastorage_read_file(
    global.product_user_id,
    filename,
    working_directory + filename,
    method(self, function(_info)
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
    }),
    method(self, function(_info)
    {
        // EpicPlayerDataStorageReadFileProgressCallbackInfo: bytes_transferred, total_file_size_bytes
        if (_info.total_file_size_bytes > 0)
            porcent = 100 * _info.bytes_transferred / _info.total_file_size_bytes
    })
)
