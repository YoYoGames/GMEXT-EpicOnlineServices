var _args = [
	[true, buffer_bool],
	[false, buffer_bool],
	//[BucketId, buffer_string],
	//[LocalUserId, buffer_string],
	//[MaxPlayers, buffer_f32],
	//[SessionId, buffer_string],
	//[SessionName, buffer_string],
]
	
var _args_buffer_address = ext_pack_args(_args);
	
SDKEpicGames_Sessions_CreateSessionModification(_args_buffer_address)
	