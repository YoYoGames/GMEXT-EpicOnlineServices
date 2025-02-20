
event_inherited();

text = "P2P"

socketName = "mySocket"

buff_recv = buffer_create(256,buffer_fixed,1)

EpicGames_P2P_AddNotifyIncomingPacketQueueFull()
EpicGames_P2P_AddNotifyPeerConnectionClosed(userID,socketName)
EpicGames_P2P_AddNotifyPeerConnectionEstablished(userID,socketName)
EpicGames_P2P_AddNotifyPeerConnectionInterrupted(userID,socketName)
EpicGames_P2P_AddNotifyPeerConnectionRequest(userID,socketName)

EstablishedProductIDs = []

