
var result = EpicGames_Sessions_CreateSessionSearch(10)
show_debug_message($"CreateSessionSearch {EpicGames_Result_ToString(result)}")

var BucketId = "GameMode:Region:MapName"

EpicGames_SessionSearch_SetParameter(EOS_ComparisonOp.EQUAL,{Key:"bucket",ValueType: EOS_AttributeType.STRING,Value: BucketId})
EpicGames_SessionSearch_Find(userID)

