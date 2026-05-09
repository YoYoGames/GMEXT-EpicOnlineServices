
with(obj_eos_session)
    instance_destroy()

if(variable_global_exists("session_search_id") && global.session_search_id != 0)
{
	eos_sessions_session_search_release(global.session_search_id)
	global.session_search_id = 0
}

global.session_search_id = eos_sessions_create_session_search(10)
show_debug_message($"CreateSessionSearch id={global.session_search_id}")
if(global.session_search_id == 0) {return}

var BucketId = "GameMode:Region:MapName"

eos_sessions_session_search_set_parameter(global.session_search_id, "bucket", BucketId, EpicComparisonOp.Equal)

eos_sessions_session_search_find(global.session_search_id, global.product_user_id, function(_info)
{
	// EpicSessionsFindCallbackInfo: .result_code
	show_debug_message("session_search_find: " + eos_api_result_to_string(_info.result_code))
	if(_info.result_code != EpicResult.Success) {return}

	var _count = eos_sessions_session_search_get_search_result_count(global.session_search_id)
	show_debug_message($"session search results: {_count}")

	for(var a = 0; a < _count; a++)
	{
		var _details_id = eos_sessions_session_search_copy_search_result_by_index(global.session_search_id, a)
		if(_details_id == 0) continue

		var _struct = eos_sessions_session_details_copy_info(_details_id)
		eos_sessions_session_details_release(_details_id)
		show_debug_message(_struct)

		var _ins = instance_create_depth(x, y + 100 + a * 100, 0, obj_eos_session, {data: _struct})
		_ins.text  = _struct.session_id
		_ins.index = a
	}
})
