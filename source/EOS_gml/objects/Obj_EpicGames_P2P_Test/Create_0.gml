
event_inherited();

text = "P2P"

socketName = "mySocket"
show_debug_message("EpicGames_P2P CALLBACKS:")
var result = EpicGames_P2P_AddNotifyIncomingPacketQueueFull()
show_debug_message(EpicGames_Result_ToString(result))
var result = EpicGames_P2P_AddNotifyPeerConnectionClosed(userID,socketName)
show_debug_message(EpicGames_Result_ToString(result))
var result = EpicGames_P2P_AddNotifyPeerConnectionEstablished(userID,socketName)
show_debug_message(EpicGames_Result_ToString(result))
var result = EpicGames_P2P_AddNotifyPeerConnectionInterrupted(userID,socketName)
show_debug_message(EpicGames_Result_ToString(result))
var result = EpicGames_P2P_AddNotifyPeerConnectionRequest(userID,socketName)
show_debug_message(EpicGames_Result_ToString(result))




