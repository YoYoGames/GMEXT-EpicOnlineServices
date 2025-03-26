
switch(async_load[? "type"])
{
	case "eos_p2_p_add_notify_incoming_packet_queue_full":
	break
	
	case "eos_p2_p_add_notify_peer_connection_closed":
		
		disconnect(async_load[? "remote_user_id"])
		
	break
	
	case "eos_p2_p_add_notify_peer_connection_established":
		
		//async_load[? "connection_type"]
		//async_load[? "network_type"]
		//async_load[? "socket_id"]
		
		array_push(EstablishedProductIDs,async_load[? "remote_user_id"])
		
	break
	
	case "eos_p2_p_add_notify_peer_connection_interrupted":
	break
	
	case "eos_p2_p_add_notify_peer_connection_request":
		
		var result = eos_p2_p_accept_connection(userID,async_load[? "remote_user_id"],"OtherSocket")
		show_debug_message("eos_p2_p_accept_connection: " + eos_result_to_string(result))
		
		var buff = buffer_create(256,buffer_fixed,1)
		buffer_write(buff,buffer_u8,1)
		eos_p2_p_send_packet(buff,buffer_tell(buff),true,false,noone,userID,true,async_load[? "remote_user_id"],socketName)
		buffer_delete(buff)
		
	break
}
