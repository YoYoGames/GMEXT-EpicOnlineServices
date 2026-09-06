
show_debug_message(SessionName)

var _handle = eos_sessions_copy_active_session_handle(SessionName)
if(_handle != 0)
{
	show_debug_message(eos_sessions_active_session_copy_info(_handle))
	eos_sessions_active_session_release(_handle)
}
