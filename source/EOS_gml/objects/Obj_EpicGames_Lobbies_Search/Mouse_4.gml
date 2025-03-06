
var result = EpicGames_Lobby_CreateLobbySearch(10)
show_debug_message($"CreateLobbySearch {EpicGames_Result_ToString(result)}")

var BucketId = "ABC"
	///** Value must equal the one stored on the lobby/session */
	//EOS_CO_EQUAL = 0,
	///** Value must not equal the one stored on the lobby/session */
	//EOS_CO_NOTEQUAL = 1,
	///** Value must be strictly greater than the one stored on the lobby/session */
	//EOS_CO_GREATERTHAN = 2,
	///** Value must be greater than or equal to the one stored on the lobby/session */
	//EOS_CO_GREATERTHANOREQUAL = 3,
	///** Value must be strictly less than the one stored on the lobby/session */
	//EOS_CO_LESSTHAN = 4,
	///** Value must be less than or equal to the one stored on the lobby/session */
	//EOS_CO_LESSTHANOREQUAL = 5,
	///** Prefer values nearest the one specified ie. abs(SearchValue-SessionValue) closest to 0 */
	//EOS_CO_DISTANCE = 6,
	///** Value stored on the lobby/session may be any from a specified list */
	//EOS_CO_ANYOF = 7,
	///** Value stored on the lobby/session may NOT be any from a specified list */
	//EOS_CO_NOTANYOF = 8,
	///** This one value is a part of a collection */
	//EOS_CO_ONEOF = 9,
	///** This one value is NOT part of a collection */
	//EOS_CO_NOTONEOF = 10,
	///** This value is a CASE SENSITIVE substring of an attribute stored on the lobby/session */
	//EOS_CO_CONTAINS = 11
EpicGames_LobbySearch_SetParameter(0,{Key:"bucket",ValueType:3,Value: BucketId})
EpicGames_LobbySearch_Find(userID)
