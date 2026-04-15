
var buff = buffer_create(256,buffer_fixed,1)
buffer_write(buff,buffer_u8,1)
var result = eos_p2p_send_packet(buff,buffer_tell(buff),true,false,noone,global.product_user_id,true,user_id,obj_eos_p2p.socketName)
show_debug_message(EpicResult_to_string(result))
buffer_delete(buff)

