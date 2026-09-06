
var _handle = eos_sessions_copy_active_session_handle(SessionName)
if(_handle != 0)
{
	draw_text(300,100,"RegisteredPlayerCount: " + string(eos_sessions_active_session_get_registered_player_count(_handle)))
	//eos_sessions_active_session_get_registered_player_by_index(_handle, 0)
	eos_sessions_active_session_release(_handle)
}
