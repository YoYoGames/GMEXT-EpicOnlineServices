
with(obj_eos_session)
    instance_destroy()

if(variable_global_exists("session_search_id") && global.session_search_id != 0)
{
	eos_sessions_session_search_release(global.session_search_id)
	global.session_search_id = 0
}

global.session_search_id = eos_sessions_create_session_search(10)
show_debug_message($"CreateSessionSearch id={global.session_search_id}")

var BucketId = "GameMode:Region:MapName"

eos_sessions_session_search_set_parameter(global.session_search_id, "bucket", BucketId, EpicComparisonOp.Equal)
eos_sessions_session_search_find(global.session_search_id, global.product_user_id)
