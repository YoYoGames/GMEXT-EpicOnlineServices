
//with(obj_eos_title_storage_file)
//	instance_destroy()

//eos_titlestorage_query_file_list(global.product_user_id,["Tag1"])





with(obj_eos_title_storage_file)
    instance_destroy()

show_debug_message($"Try eos_titlestorage_query_file_list(): {global.product_user_id}")
eos_titlestorage_query_file_list(global.product_user_id, ["Tag1"], function(_info)
{
	show_debug_message(_info)
    // _info is an EpicTitleStorageQueryFileListCallbackInfo:
    //   .result_code (EpicResult)
    //   .local_user_id (string)
    //   .file_count (int64)

    if (_info.result_code != EpicResult.Success)
    {
        show_debug_message("query_file_list failed: " + eos_api_result_to_string(_info.result_code));
        return;
    }

	show_debug_message($"DOWNLOADING FILES")
    var count = eos_titlestorage_get_file_metadata_count(global.product_user_id);
    for (var a = 0; a < count; a++)
    {
        var struct = eos_titlestorage_copy_file_metadata_at_index(global.product_user_id, a);
		show_debug_message($"{a}: {struct}")
        instance_create_depth(bbox_left, 300 + a * 100, 0, obj_eos_title_storage_file, struct);
    }
});

