
var result = eos_sessions_create_session_search(10)
show_debug_message($"CreateSessionSearch {eos_result_to_string(result)}")

var BucketId = "GameMode:Region:MapName"

eos_session_search_set_parameter(EOS_ComparisonOp.EQUAL,{key:"bucket",value_type: EOS_AttributeType.STRING,value: BucketId})
eos_session_search_find(userID)

