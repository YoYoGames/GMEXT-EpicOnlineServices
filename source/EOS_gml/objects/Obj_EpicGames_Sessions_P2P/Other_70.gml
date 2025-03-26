
event_inherited();

switch(async_load[? "type"])
{
	case "eos_p2_p_add_notify_peer_connection_closed":
		
		if(owner)
		{
			show_debug_message("eos_sessions_unregister_players: " + async_load[? "remote_user_id"])
			eos_sessions_unregister_players(Obj_EpicGames_Session.SessionName,[async_load[? "remote_user_id"]])
		}
		
	break
	
	case "eos_p2_p_add_notify_peer_connection_established":
		
		//async_load[? "connection_type"]
		//async_load[? "network_type"]
		//async_load[? "socket_id"]
		
		if(owner)
		{
			show_debug_message("eos_sessions_register_players: " + async_load[? "remote_user_id"])
			eos_sessions_register_players(Obj_EpicGames_Session.SessionName,[async_load[? "remote_user_id"]])
		}
		
	break
}
