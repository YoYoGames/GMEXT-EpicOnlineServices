
//NAT P2P Interface
//Interface to sendand receive data between users, and related networking functionality.

//Functions
//EOS_P2P_AcceptConnection
//EOS_P2P_AddNotifyIncomingPacketQueueFull
//EOS_P2P_AddNotifyPeerConnectionClosed
//EOS_P2P_AddNotifyPeerConnectionEstablished
//EOS_P2P_AddNotifyPeerConnectionInterrupted
//EOS_P2P_AddNotifyPeerConnectionRequest
//EOS_P2P_ClearPacketQueue
//EOS_P2P_CloseConnection
//EOS_P2P_CloseConnections
//EOS_P2P_GetNATType
//EOS_P2P_GetNextReceivedPacketSize
//EOS_P2P_GetPacketQueueInfo
//EOS_P2P_GetPortRange
//EOS_P2P_GetRelayControl
//EOS_P2P_QueryNATType
//EOS_P2P_ReceivePacket
//EOS_P2P_RemoveNotifyIncomingPacketQueueFull
//EOS_P2P_RemoveNotifyPeerConnectionClosed
//EOS_P2P_RemoveNotifyPeerConnectionEstablished
//EOS_P2P_RemoveNotifyPeerConnectionInterrupted
//EOS_P2P_RemoveNotifyPeerConnectionRequest
//EOS_P2P_SendPacket
//EOS_P2P_SetPacketQueueSize
//EOS_P2P_SetPortRange
//EOS_P2P_SetRelayControl
//EOS_P2P_SetRelayControlOptions

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include "eos_p2p.h"

EOS_HP2P HP2P;
double EpicGames_P2P_Init()
{
	HP2P = EOS_Platform_GetP2PInterface(PlatformHandle);
	return 0.0;
}

double EpicGames_P2P_AcceptConnection() 
{ 
	EOS_P2P_AcceptConnectionOptions Options = {0};
	Options.ApiVersion;
	Options.LocalUserId;
	Options.RemoteUserId;
	Options.SocketId;

	EOS_P2P_AcceptConnection(HP2P,&Options);
	return 0.0; 
} 

void EOS_CALL P2P_OnIncomingPacketQueueFullCallback(const EOS_P2P_OnIncomingPacketQueueFullInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_P2P_AddNotifyIncomingPacketQueueFull");
	DsMapAddDouble(map, "OverflowPacketChannel", (double)Data->OverflowPacketChannel);
	DsMapAddString(map, "OverflowPacketLocalUserId", productID_toString(Data->OverflowPacketLocalUserId));
	DsMapAddDouble(map, "OverflowPacketSizeBytes", (double)Data->OverflowPacketSizeBytes);
	DsMapAddDouble(map, "PacketQueueCurrentSizeBytes", (double)Data->PacketQueueCurrentSizeBytes);
	DsMapAddDouble(map, "PacketQueueMaxSizeBytes", (double)Data->PacketQueueMaxSizeBytes);
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_P2P_AddNotifyIncomingPacketQueueFull() 
{ 
	EOS_P2P_AddNotifyIncomingPacketQueueFullOptions Options = {0};

	callback* mcallback = getCallbackData();

	EOS_P2P_AddNotifyIncomingPacketQueueFull(HP2P, &Options, mcallback, P2P_OnIncomingPacketQueueFullCallback);

	return mcallback->identifier;
} 

void EOS_CALL P2P_OnRemoteConnectionClosedCallback(const EOS_P2P_OnRemoteConnectionClosedInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_P2P_AddNotifyPeerConnectionClosed");
	DsMapAddString(map, "account_id", productID_toString(Data->LocalUserId));//TODO: ????account_id????
	DsMapAddDouble(map, "Reason", (double)Data->Reason);
	DsMapAddString(map, "RemoteUserId", productID_toString(Data->RemoteUserId));
	DsMapAddString(map, "SocketName", Data->SocketId->SocketName);
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_P2P_AddNotifyPeerConnectionClosed() 
{ 
	EOS_P2P_AddNotifyPeerConnectionClosedOptions Options = {0};
	Options.ApiVersion;
	Options.LocalUserId;
	Options.SocketId;

	callback* mcallback = getCallbackData();

	EOS_P2P_AddNotifyPeerConnectionClosed(HP2P,&Options, mcallback, P2P_OnRemoteConnectionClosedCallback);

	return mcallback->identifier;
} 

void EOS_CALL P2P_OnPeerConnectionEstablishedCallback(const EOS_P2P_OnPeerConnectionEstablishedInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_P2P_AddNotifyPeerConnectionEstablished");
	DsMapAddString(map, "account_id", productID_toString(Data->LocalUserId));//TODO: ????account_id????
	DsMapAddDouble(map, "status", (double)Data->ConnectionType);
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_P2P_AddNotifyPeerConnectionEstablished() 
{ 
	const EOS_P2P_AddNotifyPeerConnectionEstablishedOptions Options = {0};
	
	EOS_P2P_OnPeerConnectionEstablishedCallback ConnectionEstablishedHandler;

	callback* mcallback = getCallbackData();

	EOS_P2P_AddNotifyPeerConnectionEstablished(HP2P,&Options,mcallback, P2P_OnPeerConnectionEstablishedCallback);

	return mcallback->identifier;
} 

void EOS_CALL P2P_OnPeerConnectionInterruptedCallback(const EOS_P2P_OnPeerConnectionInterruptedInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_P2P_AddNotifyPeerConnectionInterrupted");
	DsMapAddString(map, "account_id", productID_toString(Data->LocalUserId));//TODO: ????account_id????
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "RemoteUserId", productID_toString(Data->RemoteUserId));
	DsMapAddString(map, "SocketName", Data->SocketId->SocketName);
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_P2P_AddNotifyPeerConnectionInterrupted() 
{ 
	EOS_P2P_AddNotifyPeerConnectionInterruptedOptions Options = {0};
	Options.ApiVersion;
	Options.LocalUserId;
	Options.SocketId;

	callback* mcallback = getCallbackData();

	EOS_P2P_AddNotifyPeerConnectionInterrupted(HP2P,&Options,mcallback, P2P_OnPeerConnectionInterruptedCallback);

	return mcallback->identifier;
} 

void EOS_CALL P2P_OnIncomingConnectionRequestCallback(const EOS_P2P_OnIncomingConnectionRequestInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_P2P_AddNotifyPeerConnectionRequest");
	DsMapAddString(map, "account_id", productID_toString(Data->LocalUserId));
	DsMapAddString(map, "RemoteUserId", productID_toString(Data->RemoteUserId));
	DsMapAddString(map, "SocketName", Data->SocketId->SocketName);
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_P2P_AddNotifyPeerConnectionRequest() 
{ 
	EOS_P2P_AddNotifyPeerConnectionRequestOptions Options = { 0 }; 

	callback* mcallback = getCallbackData();
	EOS_P2P_AddNotifyPeerConnectionRequest(HP2P,&Options,mcallback, P2P_OnIncomingConnectionRequestCallback);

	return mcallback->identifier;
} 

double EpicGames_P2P_ClearPacketQueue() 
{ 
	EOS_P2P_ClearPacketQueueOptions Options = {0};
	Options.ApiVersion;
	Options.LocalUserId;
	Options.RemoteUserId;
	Options.SocketId;

	EOS_P2P_ClearPacketQueue(HP2P,&Options);

	return 0.0; 
} 

double EpicGames_P2P_CloseConnection() 
{ 
	EOS_P2P_CloseConnectionOptions Options = { 0 };
	Options.ApiVersion;
	Options.LocalUserId;
	Options.RemoteUserId;
	Options.SocketId;

	EOS_P2P_CloseConnection(HP2P,&Options);
	return 0.0; 
} 

double EpicGames_P2P_CloseConnections() 
{ 
	EOS_P2P_CloseConnectionsOptions Options = { 0 };
	Options.ApiVersion;
	Options.LocalUserId;
	Options.SocketId;
	EOS_P2P_CloseConnections(HP2P,&Options);
	return 0.0; 
} 

double EpicGames_P2P_GetNATType() 
{ 
	EOS_P2P_GetNATTypeOptions Options; 
	Options.ApiVersion;

	EOS_ENATType OutNATType;

	EOS_P2P_GetNATType(HP2P, &Options, &OutNATType);

	return (double)OutNATType;
} 
double EpicGames_P2P_GetNextReceivedPacketSize() 
{ 
	EOS_P2P_GetNextReceivedPacketSizeOptions Options = { 0 }; 
	Options.ApiVersion;
	Options.LocalUserId;
	Options.RequestedChannel;

	uint32_t OutPacketSizeBytes;

	EOS_P2P_GetNextReceivedPacketSize(HP2P,&Options,&OutPacketSizeBytes);

	return OutPacketSizeBytes;
} 

double EpicGames_P2P_GetPacketQueueInfo() 
{ 
	EOS_P2P_GetPacketQueueInfoOptions Options = {0};
	EOS_P2P_PacketQueueInfo OutPacketQueueInfo;

	EOS_P2P_GetPacketQueueInfo(HP2P,&Options,&OutPacketQueueInfo);

	OutPacketQueueInfo.IncomingPacketQueueCurrentPacketCount;
	OutPacketQueueInfo.IncomingPacketQueueCurrentSizeBytes;
	OutPacketQueueInfo.IncomingPacketQueueMaxSizeBytes;
	OutPacketQueueInfo.OutgoingPacketQueueCurrentPacketCount;
	OutPacketQueueInfo.OutgoingPacketQueueCurrentSizeBytes;
	OutPacketQueueInfo.OutgoingPacketQueueMaxSizeBytes;

	return 0.0; 
} 

double EpicGames_P2P_GetPortRange() 
{ 
	EOS_P2P_GetPortRangeOptions Options = {0};
	Options.ApiVersion;
	uint16_t OutPort;
	uint16_t OutNumAdditionalPortsToTry;

	EOS_P2P_GetPortRange(HP2P, &Options,&OutPort, &OutNumAdditionalPortsToTry);

	return 0.0; 
} 

double EpicGames_P2P_GetRelayControl() 
{ 
	EOS_P2P_GetRelayControlOptions Options = {0};
	Options.ApiVersion;
	EOS_ERelayControl OutRelayControl;
	
	EOS_P2P_GetRelayControl(HP2P,&Options, &OutRelayControl);
	
	return (double) OutRelayControl;
} 

void EOS_CALL P2P_OnQueryNATTypeCompleteCallback(const EOS_P2P_OnQueryNATTypeCompleteInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "");
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddDouble(map, "NATType", (double)Data->NATType);
	CreateAsyncEventWithDSMap(map, 70);
}

double EpicGames_P2P_QueryNATType()
{ 
	const EOS_P2P_QueryNATTypeOptions Options = {0};
	Options.ApiVersion;

	callback* mcallback = getCallbackData();

	EOS_P2P_QueryNATType(HP2P, &Options, mcallback, P2P_OnQueryNATTypeCompleteCallback);

	return mcallback->identifier;
} 

double EpicGames_P2P_ReceivePacket() 
{ 
	EOS_HP2P Handle;
	const EOS_P2P_ReceivePacketOptions* Options;
	EOS_ProductUserId* OutPeerId;
	EOS_P2P_SocketId* OutSocketId;
	uint8_t* OutChannel;
	void* OutData;
	uint32_t* OutBytesWritten;

	//EOS_P2P_ReceivePacket()

	return 0.0; 
} 

double EpicGames_P2P_RemoveNotifyIncomingPacketQueueFull() 
{ 
	EOS_NotificationId NotificationId = 0;
	EOS_P2P_RemoveNotifyIncomingPacketQueueFull(HP2P, NotificationId);
	return 0.0; 
}

double EpicGames_P2P_RemoveNotifyPeerConnectionClosed() 
{ 
	EOS_NotificationId NotificationId = 0;
	EOS_P2P_RemoveNotifyPeerConnectionClosed(HP2P, NotificationId);
	return 0.0; 
} 

double EpicGames_P2P_RemoveNotifyPeerConnectionEstablished() 
{ 
	EOS_NotificationId NotificationId = 0;
	EOS_P2P_RemoveNotifyPeerConnectionEstablished(HP2P, NotificationId);
	return 0.0;
}

double EpicGames_P2P_RemoveNotifyPeerConnectionInterrupted() 
{ 
	EOS_NotificationId NotificationId = 0;
	EOS_P2P_RemoveNotifyPeerConnectionInterrupted(HP2P, NotificationId);
	return 0.0; 
} 
double EpicGames_P2P_RemoveNotifyPeerConnectionRequest() 
{ 
	EOS_NotificationId NotificationId = 0;
	EOS_P2P_RemoveNotifyPeerConnectionRequest(HP2P, NotificationId);
	return 0.0; 
} 

double EpicGames_P2P_SendPacket() 
{ 
	return 0.0; 
} 

double EpicGames_P2P_SetPacketQueueSize() 
{ 
	EOS_P2P_SetPacketQueueSizeOptions Options = {};
	Options.ApiVersion;
	Options.IncomingPacketQueueMaxSizeBytes;
	Options.OutgoingPacketQueueMaxSizeBytes;

	EOS_P2P_SetPacketQueueSize(HP2P, &Options);

	return 0.0; 
} 

double EpicGames_P2P_SetPortRange() 
{ 
	EOS_P2P_SetPortRangeOptions Options = {0};
	EOS_P2P_SetPortRange(HP2P, &Options);

	return 0.0; 
} 

double EpicGames_P2P_SetRelayControl() 
{ 
	EOS_P2P_SetRelayControlOptions Options;
	Options.ApiVersion;
	Options.RelayControl;

	EOS_P2P_SetRelayControl(HP2P, &Options);

	return 0.0; 
} 


