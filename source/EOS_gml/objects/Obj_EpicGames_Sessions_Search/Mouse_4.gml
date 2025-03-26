
var result = eos_sessions_create_session_search(10)
show_debug_message($"CreateSessionSearch {eos_result_to_string(result)}")

var BucketId = "GameMode:Region:MapName"

eos_session_search_set_parameter(EOS_ComparisonOp.EQUAL,{Key:"bucket",ValueType: EOS_AttributeType.STRING,Value: BucketId})
eos_session_search_find(userID)

