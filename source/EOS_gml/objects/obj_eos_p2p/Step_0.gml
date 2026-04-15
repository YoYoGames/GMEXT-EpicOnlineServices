
event_inherited();

var max_loops = 5;
while(eos_p2p_get_next_received_packet_size(global.product_user_id,noone))
{
	var out_bytes_num = eos_p2p_receive_packet(buff_recv,global.product_user_id,256,noone)
	buffer_seek(buff_recv,buffer_seek_start,0)
	
	var _case = buffer_read(buff_recv,buffer_u8)//it's game data
	
	switch(_case)
	{
		case 1:
			show_debug_message("Response message")
		break
		
		case 2:
			//show_debug_message("Game Message")
			
			var _x = buffer_read(buff_recv,buffer_f16)
			var _y = buffer_read(buff_recv,buffer_f16)
			
			instance_create_depth(_x,_y,depth,obj_eos_p2p_point)
		break
	}
	
	max_loops --
	if(!max_loops)
		break
}



var buff = buffer_create(256,buffer_fixed,1)
buffer_write(buff,buffer_u8,2)//it's game data
buffer_write(buff,buffer_f16,mouse_x)
buffer_write(buff,buffer_f16,mouse_y)
for(var a = 0 ; a < array_length(EstablishedProductIDs) ; a++)
{
	var result = eos_p2p_send_packet(buff,buffer_tell(buff),true,false,noone,global.product_user_id,true,EstablishedProductIDs[a],socketName)
	//show_debug_message("Send: " + string(result))
}
buffer_delete(buff)

instance_create_depth(mouse_x,mouse_y,depth,obj_eos_p2p_point)
