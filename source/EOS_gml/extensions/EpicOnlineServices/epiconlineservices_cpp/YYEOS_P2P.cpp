
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
void EpicGames_P2P_Init()
{
	HP2P = EOS_Platform_GetP2PInterface(PlatformHandle);
}

func double EpicGames_P2P_AcceptConnection(char* LocalUserId,char* RemoteUserId,char* SocketName)
{ 
	EOS_P2P_AcceptConnectionOptions Options = {0};
	Options.ApiVersion = EOS_P2P_ACCEPTCONNECTION_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.RemoteUserId = EOS_ProductUserId_FromString(RemoteUserId);
	EOS_P2P_SocketId SocketId = { 0 };// EOS_P2P_SocketId();
	SocketId.ApiVersion = EOS_P2P_SOCKETID_API_LATEST;
	strcpy(SocketId.SocketName, SocketName);
	Options.SocketId = &SocketId;

	return (double) EOS_P2P_AcceptConnection(HP2P,&Options);
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
	//DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

func double EpicGames_P2P_AddNotifyIncomingPacketQueueFull()
{ 
	EOS_P2P_AddNotifyIncomingPacketQueueFullOptions Options = {0};
	Options.ApiVersion = EOS_P2P_ADDNOTIFYINCOMINGPACKETQUEUEFULL_API_LATEST;

	//callback* mcallback = getCallbackData();

	return (double) EOS_P2P_AddNotifyIncomingPacketQueueFull(HP2P, &Options, NULL/*mcallback*/, P2P_OnIncomingPacketQueueFullCallback);

	//return mcallback->identifier;
} 

void EOS_CALL P2P_OnRemoteConnectionClosedCallback(const EOS_P2P_OnRemoteConnectionClosedInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_P2P_AddNotifyPeerConnectionClosed");
	DsMapAddString(map, "account_id", productID_toString(Data->LocalUserId));
	DsMapAddDouble(map, "Reason", (double)Data->Reason);
	DsMapAddString(map, "RemoteUserId", productID_toString(Data->RemoteUserId));
	DsMapAddString(map, "SocketName", Data->SocketId->SocketName);
	//DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

func double EpicGames_P2P_AddNotifyPeerConnectionClosed(char* LocalUserId, char* SocketName)
{ 
	EOS_P2P_AddNotifyPeerConnectionClosedOptions Options = {0};
	Options.ApiVersion = EOS_P2P_ADDNOTIFYPEERCONNECTIONCLOSED_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	EOS_P2P_SocketId SocketId = { 0 };// EOS_P2P_SocketId();
	SocketId.ApiVersion = EOS_P2P_SOCKETID_API_LATEST;
	strcpy(SocketId.SocketName, SocketName);
	Options.SocketId = &SocketId;

	//callback* mcallback = getCallbackData();

	return (double) EOS_P2P_AddNotifyPeerConnectionClosed(HP2P,&Options, NULL/*mcallback*/, P2P_OnRemoteConnectionClosedCallback);

	//return mcallback->identifier;
} 

void EOS_CALL P2P_OnPeerConnectionEstablishedCallback(const EOS_P2P_OnPeerConnectionEstablishedInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_P2P_AddNotifyPeerConnectionEstablished");
	DsMapAddString(map, "account_id", productID_toString(Data->LocalUserId));
	DsMapAddDouble(map, "status", (double)Data->ConnectionType);
	//DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

func double EpicGames_P2P_AddNotifyPeerConnectionEstablished(char* LocalUserId, char* SocketName)
{ 
	EOS_P2P_AddNotifyPeerConnectionEstablishedOptions Options = {0};
	Options.ApiVersion = EOS_P2P_ADDNOTIFYPEERCONNECTIONESTABLISHED_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	EOS_P2P_SocketId SocketId = { 0 };// EOS_P2P_SocketId();
	SocketId.ApiVersion = EOS_P2P_SOCKETID_API_LATEST;
	strcpy(SocketId.SocketName, SocketName);
	Options.SocketId = &SocketId;
	
	EOS_P2P_OnPeerConnectionEstablishedCallback ConnectionEstablishedHandler;

	//callback* mcallback = getCallbackData();

	return (double)EOS_P2P_AddNotifyPeerConnectionEstablished(HP2P,&Options,NULL/*mcallback*/, P2P_OnPeerConnectionEstablishedCallback);

	//return mcallback->identifier;
} 

void EOS_CALL P2P_OnPeerConnectionInterruptedCallback(const EOS_P2P_OnPeerConnectionInterruptedInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_P2P_AddNotifyPeerConnectionInterrupted");
	DsMapAddString(map, "account_id", productID_toString(Data->LocalUserId));
	//DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "RemoteUserId", productID_toString(Data->RemoteUserId));
	DsMapAddString(map, "SocketName", Data->SocketId->SocketName);
	CreateAsyncEventWithDSMap(map, 70);
}

func double EpicGames_P2P_AddNotifyPeerConnectionInterrupted(char* LocalUserId,char* SocketName)
{ 
	EOS_P2P_AddNotifyPeerConnectionInterruptedOptions Options = {0};
	Options.ApiVersion = EOS_P2P_ADDNOTIFYPEERCONNECTIONINTERRUPTED_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	EOS_P2P_SocketId SocketId = { 0 };// EOS_P2P_SocketId();
	SocketId.ApiVersion = EOS_P2P_SOCKETID_API_LATEST;
	strcpy(SocketId.SocketName, SocketName);
	Options.SocketId = &SocketId;

	//callback* mcallback = getCallbackData();

	return (double) EOS_P2P_AddNotifyPeerConnectionInterrupted(HP2P,&Options,NULL/*mcallback*/, P2P_OnPeerConnectionInterruptedCallback);

	//return mcallback->identifier;
} 

void EOS_CALL P2P_OnIncomingConnectionRequestCallback(const EOS_P2P_OnIncomingConnectionRequestInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_P2P_AddNotifyPeerConnectionRequest");
	DsMapAddString(map, "account_id", productID_toString(Data->LocalUserId));
	DsMapAddString(map, "RemoteUserId", productID_toString(Data->RemoteUserId));
	DsMapAddString(map, "SocketName", Data->SocketId->SocketName);
	//DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}

func double EpicGames_P2P_AddNotifyPeerConnectionRequest(char* LocalUserId, char* SocketName)
{ 
	EOS_P2P_AddNotifyPeerConnectionRequestOptions Options = { 0 }; 
	Options.ApiVersion = EOS_P2P_ADDNOTIFYPEERCONNECTIONREQUEST_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	EOS_P2P_SocketId SocketId = { 0 };// EOS_P2P_SocketId();
	SocketId.ApiVersion = EOS_P2P_SOCKETID_API_LATEST;
	strcpy(SocketId.SocketName, SocketName);
	Options.SocketId = &SocketId;


	//callback* mcallback = getCallbackData();
	return (double) EOS_P2P_AddNotifyPeerConnectionRequest(HP2P,&Options,NULL/*mcallback*/, P2P_OnIncomingConnectionRequestCallback);

	//return mcallback->identifier;
} 

func double EpicGames_P2P_ClearPacketQueue(char* LocalUserId,char* RemoteUserId,char* SocketName)
{ 
	EOS_P2P_ClearPacketQueueOptions Options = {0};
	Options.ApiVersion = EOS_P2P_CLEARPACKETQUEUE_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	EOS_P2P_SocketId SocketId = { 0 };// EOS_P2P_SocketId();
	SocketId.ApiVersion = EOS_P2P_SOCKETID_API_LATEST;
	strcpy(SocketId.SocketName, SocketName);
	Options.SocketId = &SocketId;
	Options.RemoteUserId = EOS_ProductUserId_FromString(RemoteUserId);

	return (double) EOS_P2P_ClearPacketQueue(HP2P,&Options);
} 

func double EpicGames_P2P_CloseConnection(char* LocalUserId, char* RemoteUserId, char* SocketName)
{ 
	EOS_P2P_CloseConnectionOptions Options = { 0 };
	Options.ApiVersion = EOS_P2P_CLOSECONNECTION_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	EOS_P2P_SocketId SocketId = { 0 };// EOS_P2P_SocketId();
	SocketId.ApiVersion = EOS_P2P_SOCKETID_API_LATEST;
	strcpy(SocketId.SocketName, SocketName);
	Options.SocketId = &SocketId;
	Options.RemoteUserId = EOS_ProductUserId_FromString(RemoteUserId);

	return (double)EOS_P2P_CloseConnection(HP2P,&Options);
} 

func double EpicGames_P2P_CloseConnections(char* LocalUserId, char* SocketName)
{ 
	EOS_P2P_CloseConnectionsOptions Options = { 0 };
	Options.ApiVersion = EOS_P2P_CLOSECONNECTIONS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	EOS_P2P_SocketId SocketId = { 0 };// EOS_P2P_SocketId();
	SocketId.ApiVersion = EOS_P2P_SOCKETID_API_LATEST;
	strcpy(SocketId.SocketName, SocketName);
	Options.SocketId = &SocketId;
	return (double)EOS_P2P_CloseConnections(HP2P,&Options);
} 

func double EpicGames_P2P_GetNATType()
{ 
	EOS_P2P_GetNATTypeOptions Options = {0};
	Options.ApiVersion = EOS_P2P_GETNATTYPE_API_LATEST;

	EOS_ENATType OutNATType;

	EOS_P2P_GetNATType(HP2P, &Options, &OutNATType);

	return (double)OutNATType;
} 

func double EpicGames_P2P_GetNextReceivedPacketSize(char* LocalUserId)
{ 
	EOS_P2P_GetNextReceivedPacketSizeOptions Options = { 0 }; 
	Options.ApiVersion = EOS_P2P_GETNEXTRECEIVEDPACKETSIZE_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.RequestedChannel = NULL;

	uint32_t OutPacketSizeBytes;

	EOS_P2P_GetNextReceivedPacketSize(HP2P,&Options,&OutPacketSizeBytes);

	return OutPacketSizeBytes;
} 

func double SDKEpicGames_P2P_GetPacketQueueInfo(char* buff_ret)
{ 
	EOS_P2P_GetPacketQueueInfoOptions Options = {0};
	Options.ApiVersion = EOS_P2P_GETPACKETQUEUEINFO_API_LATEST;

	EOS_P2P_PacketQueueInfo OutPacketQueueInfo;

	EOS_EResult result = EOS_P2P_GetPacketQueueInfo(HP2P,&Options,&OutPacketQueueInfo);

	if (EOS_EResult::EOS_Success == result)
	{
		StructStream _struct = {};
		_struct.addKeyValue("IncomingPacketQueueCurrentPacketCount", (double)OutPacketQueueInfo.IncomingPacketQueueCurrentPacketCount);
		_struct.addKeyValue("IncomingPacketQueueCurrentSizeBytes", (double)OutPacketQueueInfo.IncomingPacketQueueCurrentSizeBytes);
		_struct.addKeyValue("IncomingPacketQueueMaxSizeBytes", (double)OutPacketQueueInfo.IncomingPacketQueueMaxSizeBytes);
		_struct.addKeyValue("OutgoingPacketQueueCurrentPacketCount", (double)OutPacketQueueInfo.OutgoingPacketQueueCurrentPacketCount);
		_struct.addKeyValue("OutgoingPacketQueueCurrentSizeBytes", (double)OutPacketQueueInfo.OutgoingPacketQueueCurrentSizeBytes);
		_struct.addKeyValue("OutgoingPacketQueueMaxSizeBytes", (double)OutPacketQueueInfo.OutgoingPacketQueueMaxSizeBytes);
		_struct.writeTo(buff_ret);
	}
	else
	{
		StructStream _struct = {};
		_struct.writeTo(buff_ret);
	}

	return 0.0; 
} 

func double SDKEpicGames_P2P_GetPortRange(char* buff_ret)
{ 
	EOS_P2P_GetPortRangeOptions Options = {0};
	Options.ApiVersion = EOS_P2P_GETPORTRANGE_API_LATEST;
	uint16_t OutPort;
	uint16_t OutNumAdditionalPortsToTry;

	EOS_EResult result = EOS_P2P_GetPortRange(HP2P, &Options,&OutPort, &OutNumAdditionalPortsToTry);

	if (EOS_EResult::EOS_Success == result)
	{
		StructStream _struct = {};
		_struct.addKeyValue("OutPort", (int)OutPort);
		_struct.addKeyValue("OutNumAdditionalPortsToTry", (int)OutNumAdditionalPortsToTry);
		_struct.writeTo(buff_ret);
	}
	else
	{
		StructStream _struct = {};
		_struct.writeTo(buff_ret);
	}

	return 0.0; 
} 

func double EpicGames_P2P_GetRelayControl()
{ 
	EOS_P2P_GetRelayControlOptions Options = {0};
	Options.ApiVersion = EOS_P2P_GETRELAYCONTROL_API_LATEST;

	EOS_ERelayControl OutRelayControl;
	
	EOS_EResult result = EOS_P2P_GetRelayControl(HP2P,&Options, &OutRelayControl);

	if (EOS_EResult::EOS_Success == result)
	{
		return (double)OutRelayControl;
	}
	else
	{
		return -4;
	}
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

func double EpicGames_P2P_QueryNATType()
{ 
	EOS_P2P_QueryNATTypeOptions Options = {0};
	Options.ApiVersion = EOS_P2P_QUERYNATTYPE_API_LATEST;

	callback* mcallback = getCallbackData();

	EOS_P2P_QueryNATType(HP2P, &Options, mcallback, P2P_OnQueryNATTypeCompleteCallback);

	return mcallback->identifier;
} 

func double SDKEpicGames_P2P_ReceivePacket(char* buff_ret,char* LocalUserId,double MaxDataSizeBytes,double RequestedChannel)
{ 
	EOS_P2P_ReceivePacketOptions Options = {0};
	Options.ApiVersion = EOS_P2P_RECEIVEPACKET_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.MaxDataSizeBytes = MaxDataSizeBytes;
	if (RequestedChannel >= 0)
		Options.RequestedChannel = (const uint8_t*)&RequestedChannel;
	else
		Options.RequestedChannel = NULL;

	EOS_ProductUserId OutPeerId;
	EOS_P2P_SocketId OutSocketId;
	uint8_t OutChannel;
	//void* OutData;
	uint32_t OutBytesWritten;
	
	EOS_EResult result = EOS_P2P_ReceivePacket(HP2P,&Options,&OutPeerId,&OutSocketId,&OutChannel,buff_ret, &OutBytesWritten);

	if (result == EOS_EResult::EOS_Success)
	{
		return OutBytesWritten;
	}
	else
	{
		return -4;
	}
} 

func double EpicGames_P2P_RemoveNotifyIncomingPacketQueueFull(double NotificationId)
{ 
	EOS_NotificationId _NotificationId = NotificationId;
	EOS_P2P_RemoveNotifyIncomingPacketQueueFull(HP2P, _NotificationId);
	return 0.0; 
}

func double EpicGames_P2P_RemoveNotifyPeerConnectionClosed(double NotificationId)
{ 
	EOS_NotificationId _NotificationId = NotificationId;
	EOS_P2P_RemoveNotifyPeerConnectionClosed(HP2P, _NotificationId);
	return 0.0; 
} 

func double EpicGames_P2P_RemoveNotifyPeerConnectionEstablished(double NotificationId)
{ 
	EOS_NotificationId _NotificationId = NotificationId;
	EOS_P2P_RemoveNotifyPeerConnectionEstablished(HP2P, _NotificationId);
	return 0.0;
}

func double EpicGames_P2P_RemoveNotifyPeerConnectionInterrupted(double NotificationId)
{ 
	EOS_NotificationId _NotificationId = NotificationId;
	EOS_P2P_RemoveNotifyPeerConnectionInterrupted(HP2P, _NotificationId);
	return 0.0; 
} 

func double EpicGames_P2P_RemoveNotifyPeerConnectionRequest(double NotificationId)
{ 
	EOS_NotificationId _NotificationId = NotificationId;
	EOS_P2P_RemoveNotifyPeerConnectionRequest(HP2P, _NotificationId);
	return 0.0; 
} 

func double SDKEpicGames_P2P_SendPacket(char* buff_data, double len)
{ 
	EOS_P2P_SendPacketOptions Options = { 0 };
	Options.ApiVersion = EOS_P2P_SENDPACKET_API_LATEST;
	Options.bAllowDelayedDelivery;
	Options.bDisableAutoAcceptConnection;
	Options.Channel;
	Options.Data = buff_data;
	Options.DataLengthBytes = len;
	Options.LocalUserId;
	Options.Reliability;
	Options.RemoteUserId;

	EOS_P2P_SocketId socket = {0};
	socket.ApiVersion = EOS_P2P_SOCKETID_API_LATEST;
	socket.SocketName;
	Options.SocketId = &socket;

	EOS_P2P_SendPacket(HP2P,&Options);

	return 0.0; 
} 

func double EpicGames_P2P_SetPacketQueueSize(double IncomingPacketQueueMaxSizeBytes, double OutgoingPacketQueueMaxSizeBytes)
{ 
	EOS_P2P_SetPacketQueueSizeOptions Options = {0};
	Options.ApiVersion = EOS_P2P_SETPACKETQUEUESIZE_API_LATEST;
	Options.IncomingPacketQueueMaxSizeBytes = IncomingPacketQueueMaxSizeBytes;
	Options.OutgoingPacketQueueMaxSizeBytes = OutgoingPacketQueueMaxSizeBytes;

	return (double) EOS_P2P_SetPacketQueueSize(HP2P, &Options);
} 

func double EpicGames_P2P_SetPortRange(double Port,double MaxAdditionalPortsToTry)
{ 
	EOS_P2P_SetPortRangeOptions Options = {0};
	Options.ApiVersion = EOS_P2P_SETPORTRANGE_API_LATEST;
	Options.MaxAdditionalPortsToTry = MaxAdditionalPortsToTry;
	Options.Port = Port;

	return (double) EOS_P2P_SetPortRange(HP2P, &Options);
} 

func double EpicGames_P2P_SetRelayControl(double RelayControl)
{ 
	EOS_P2P_SetRelayControlOptions Options;
	Options.ApiVersion = EOS_P2P_SETRELAYCONTROL_API_LATEST;
	Options.RelayControl = (EOS_ERelayControl) RelayControl;

	return (double) EOS_P2P_SetRelayControl(HP2P, &Options);
} 


