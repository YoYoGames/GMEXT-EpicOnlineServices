
with(Obj_EpicGames_Session)
    instance_destroy()

eos_session_search_release()
var result = eos_sessions_create_session_search(10)
show_debug_message($"CreateSessionSearch {EOS_RESULT_to_string(result)}")

var BucketId = "GameMode:Region:MapName"

eos_session_search_set_parameter(EOS_COMPARISON_OP.EQUAL,{key:"bucket",value_type: EOS_ATTRIBUTE_TYPE.STRING,value: BucketId})
eos_session_search_find(userID)

