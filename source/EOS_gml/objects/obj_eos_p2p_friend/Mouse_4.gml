
var buff = buffer_create(256,buffer_fixed,1)
buffer_write(buff,buffer_u8,1)
var result = eos_p2p_send_packet(global.product_user_id, data.user_id, obj_eos_p2p.socketName, 0, buff, buffer_tell(buff), true, EpicPacketReliability.ReliableOrdered, false)
show_debug_message(eos_api_result_to_string(result))
buffer_delete(buff)

