
porcent = 0

color_progress = c_green
color_failed = c_red
color_done = c_blue

color_current = color_progress

request = noone


// Single call kicks off the full transfer. The C++ side streams the chunks
// into a buffer and writes the entire file to disk on completion.
// No alarm loop / repeated calls needed — the callback fires once when done.

ins_cancel = instance_create_depth(x + 600, y, 0, obj_eos_title_storage_file_cancel, {filename: filename})

eos_titlestorage_read_file(
    global.product_user_id,
    filename,
    working_directory + filename,
    function(_info)
    {
		show_debug_message($"eos_titlestorage_read_file: {_info}")
		
        // Completion — fires once. The file is already on disk by this point.
        // _info is an EpicTitleStorageReadFileCallbackInfo:
        //   .result_code (EpicResult)
        //   .local_user_id (string)
        //   .filename (string)
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
		show_debug_message($"eos_titlestorage_read_file: {_info}")
		
        // Progress — fires once per chunk while the transfer is running.
        // _info is an EpicTitleStorageReadFileProgressCallbackInfo:
        //   .local_user_id (string)
        //   .filename (string)
        //   .bytes_transferred (int64)
        //   .total_file_size_bytes (int64)
        if (_info.total_file_size_bytes > 0)
            porcent = 100 * _info.bytes_transferred / _info.total_file_size_bytes
    }
)
