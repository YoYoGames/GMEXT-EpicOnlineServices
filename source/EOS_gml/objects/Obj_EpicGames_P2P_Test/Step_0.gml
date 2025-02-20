
event_inherited();

if(EpicGames_P2P_GetNextReceivedPacketSize(userID))
{
	var out_bytes_num = EpicGames_P2P_ReceivePacket(buffer_get_address(buff_recv),userID,256,noone)
	buffer_seek(buff_recv,buffer_seek_start,0)
	
	var _case = buffer_read(buff,buffer_u8)//it's game data
	
	switch(_case)
	{
		case 0:
			show_debug_message("Request message")
			var buff = buffer_create(256,buffer_fixed,1)
			buffer_write(buff,buffer_u8,1)
			var result = EpicGames_P2P_SendPacket(buff,buffer_tell(buff),true,false,noone,userID,true,EstablishedProductIDs[a],socketName)
			buffer_delete(buff)
		break
		
		case 1:
			show_debug_message("Response message")
		break
		
		case 2:
			show_debug_message("Game Message")
			
			var _x = buffer_read(buff,buffer_f16)
			var _y = buffer_read(buff,buffer_f16)
			
			instance_create_depth(_x,_y,depth,Obj_EpicGames_P2P_Point)
			
			buffer_delete(buff)
		break
	}
}



for(var a = 0 ; a < array_length(EstablishedProductIDs) ; a++)
{
	var buff = buffer_create(256,buffer_fixed,1)
	buffer_write(buff,buffer_u8,2)//it's game data
	buffer_write(buff,buffer_f16,x)
	buffer_write(buff,buffer_f16,y)
	var result = EpicGames_P2P_SendPacket(buff,buffer_tell(buff),true,false,noone,userID,true,EstablishedProductIDs[a],socketName)
	buffer_delete(buff)
}
