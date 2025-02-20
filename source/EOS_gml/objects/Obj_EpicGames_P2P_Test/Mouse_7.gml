


var buff = buffer_create(256,buffer_fixed,1)
buffer_write(buff,buffer_string,"HelloWorld")
var result = EpicGames_P2P_SendPacket(buff,buffer_tell(buff),true,false,noone,userID,true,"0002aaccc4764605a9e585fda4b11c78",socketName)
show_debug_message(EpicGames_Result_ToString(result))
buffer_delete(buff)

