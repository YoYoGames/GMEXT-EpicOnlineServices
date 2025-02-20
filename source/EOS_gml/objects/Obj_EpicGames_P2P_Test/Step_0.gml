
event_inherited();

if(EpicGames_P2P_GetNextReceivedPacketSize())
{
	EpicGames_P2P_ReceivePacket(buffer_get_address(buff_recv),userID,256,noone)
	buffer_seek(buff_recv,buffer_seek_start,0)
	show_debug_message(buffer_read(buff_recv,buffer_string))
}
