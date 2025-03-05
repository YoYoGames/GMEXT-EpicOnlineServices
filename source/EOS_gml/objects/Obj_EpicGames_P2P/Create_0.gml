
event_inherited();

text = "P2P"

socketName = "mySocket"

buff_recv = buffer_create(256,buffer_fixed,1)

notifyIncomingPacketQueueFull = EpicGames_P2P_AddNotifyIncomingPacketQueueFull()
notifyPeerConnectionClosed = EpicGames_P2P_AddNotifyPeerConnectionClosed(userID,socketName)
notifyPeerConnectionEstablished = EpicGames_P2P_AddNotifyPeerConnectionEstablished(userID,socketName)
notifyPeerConnectionInterrupted = EpicGames_P2P_AddNotifyPeerConnectionInterrupted(userID,socketName)
notifyPeerConnectionRequest = EpicGames_P2P_AddNotifyPeerConnectionRequest(userID,socketName)

EstablishedProductIDs = []

