
var buff = buffer_create(256,buffer_fixed,1)
buffer_write(buff,buffer_u8,1)
var result = EpicGames_P2P_SendPacket(buff,buffer_tell(buff),true,false,noone,userID,true,id.AccountID,Obj_EpicGames_P2P_Test.socketName)
show_debug_message(EpicGames_Result_ToString(result))
buffer_delete(buff)
