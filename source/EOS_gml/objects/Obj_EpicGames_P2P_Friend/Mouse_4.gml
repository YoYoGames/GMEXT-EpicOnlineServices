
var buff = buffer_create(256,buffer_fixed,1)
buffer_write(buff,buffer_u8,1)
var result = eos_p2p_send_packet(buff,buffer_tell(buff),true,false,noone,userID,true,id.UserID,Obj_EpicGames_P2P.socketName)
show_debug_message(eos_result_to_string(result))
buffer_delete(buff)

