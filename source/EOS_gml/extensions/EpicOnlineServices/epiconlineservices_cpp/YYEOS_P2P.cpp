
// NAT P2P Interface
// Interface to sendand receive data between users, and related networking functionality.

// Functions
// EOS_P2P_AcceptConnection
// EOS_P2P_AddNotifyIncomingPacketQueueFull
// EOS_P2P_AddNotifyPeerConnectionClosed
// EOS_P2P_AddNotifyPeerConnectionEstablished
// EOS_P2P_AddNotifyPeerConnectionInterrupted
// EOS_P2P_AddNotifyPeerConnectionRequest
// EOS_P2P_ClearPacketQueue
// EOS_P2P_CloseConnection
// EOS_P2P_CloseConnections
// EOS_P2P_GetNATType
// EOS_P2P_GetNextReceivedPacketSize
// EOS_P2P_GetPacketQueueInfo
// EOS_P2P_GetPortRange
// EOS_P2P_GetRelayControl
// EOS_P2P_QueryNATType
// EOS_P2P_ReceivePacket
// EOS_P2P_RemoveNotifyIncomingPacketQueueFull
// EOS_P2P_RemoveNotifyPeerConnectionClosed
// EOS_P2P_RemoveNotifyPeerConnectionEstablished
// EOS_P2P_RemoveNotifyPeerConnectionInterrupted
// EOS_P2P_RemoveNotifyPeerConnectionRequest
// EOS_P2P_SendPacket
// EOS_P2P_SetPacketQueueSize
// EOS_P2P_SetPortRange
// EOS_P2P_SetRelayControl
// EOS_P2P_SetRelayControlOptions

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include "eos_p2p.h"

inline void FillSocketId(EOS_P2P_SocketId &SocketId, const char* socketName)
{
	// Zero the entire struct and set the API version
	memset(&SocketId, 0, sizeof(SocketId));
	SocketId.ApiVersion = EOS_P2P_SOCKETID_API_LATEST;

	// Safely copy up to EOS_P2P_SOCKETID_SOCKETNAME_SIZE - 1
	if (socketName)
	{
		strncpy(SocketId.SocketName, socketName, EOS_P2P_SOCKETID_SOCKETNAME_SIZE - 1);
		// Ensure it�s null-terminated
		SocketId.SocketName[EOS_P2P_SOCKETID_SOCKETNAME_SIZE - 1] = '\0';
	}
}

EOS_HP2P HP2P;
void eos_p2p_init()
{
	HP2P = EOS_Platform_GetP2PInterface(PlatformHandle);
}

func double eos_p2p_accept_connection(char* LocalUserId,char* RemoteUserId,char* SocketName)
{
	eos_not_init_return(-1);

	EOS_P2P_AcceptConnectionOptions Options = {0};
	Options.ApiVersion = EOS_P2P_ACCEPTCONNECTION_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.RemoteUserId = EOS_ProductUserId_FromString(RemoteUserId);
	EOS_P2P_SocketId SocketId{};
	FillSocketId(SocketId, SocketName);
	Options.SocketId = &SocketId;

	return (double)EOS_P2P_AcceptConnection(HP2P, &Options);
}

void EOS_CALL P2P_OnIncomingPacketQueueFullCallback(const EOS_P2P_OnIncomingPacketQueueFullInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_p2p_add_notify_incoming_packet_queue_full");
	DsMapAddDouble(map, "overflow_packet_channel", (double)data->OverflowPacketChannel);
	DsMapAddString(map, "overflow_packet_local_user_id", productID_toString(data->OverflowPacketLocalUserId));
	DsMapAddDouble(map, "overflow_packet_size_bytes", (double)data->OverflowPacketSizeBytes);
	DsMapAddDouble(map, "packet_queue_current_size_bytes", (double)data->PacketQueueCurrentSizeBytes);
	DsMapAddDouble(map, "packet_queue_max_size_bytes", (double)data->PacketQueueMaxSizeBytes);
	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_p2p_add_notify_incoming_packet_queue_full(char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_P2P_AddNotifyIncomingPacketQueueFullOptions Options = {0};
	Options.ApiVersion = EOS_P2P_ADDNOTIFYINCOMINGPACKETQUEUEFULL_API_LATEST;

	uint64 notificationId = EOS_P2P_AddNotifyIncomingPacketQueueFull(HP2P, &Options, nullptr, P2P_OnIncomingPacketQueueFullCallback);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL P2P_OnRemoteConnectionClosedCallback(const EOS_P2P_OnRemoteConnectionClosedInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_p2p_add_notify_peer_connection_closed");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddDouble(map, "reason", (double)data->Reason);
	DsMapAddString(map, "remote_user_id", productID_toString(data->RemoteUserId));
	DsMapAddString(map, "socket_name", data->SocketId->SocketName);
	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_p2p_add_notify_peer_connection_closed(char* LocalUserId,char* SocketName,char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_P2P_AddNotifyPeerConnectionClosedOptions Options = {0};
	Options.ApiVersion = EOS_P2P_ADDNOTIFYPEERCONNECTIONCLOSED_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	EOS_P2P_SocketId SocketId{};
	FillSocketId(SocketId, SocketName);
	Options.SocketId = &SocketId;

	uint64 notificationId = EOS_P2P_AddNotifyPeerConnectionClosed(HP2P, &Options, nullptr, P2P_OnRemoteConnectionClosedCallback);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL P2P_OnPeerConnectionEstablishedCallback(const EOS_P2P_OnPeerConnectionEstablishedInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_p2p_add_notify_peer_connection_established");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddDouble(map, "status", (double)data->ConnectionType);
	DsMapAddDouble(map, "connection_type", (double)data->ConnectionType);
	DsMapAddDouble(map, "network_type", (double)data->NetworkType);
	DsMapAddString(map, "socket_id", data->SocketId->SocketName);
	DsMapAddString(map, "remote_user_id", productID_toString(data->RemoteUserId));
	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_p2p_add_notify_peer_connection_established(char* LocalUserId,char* SocketName,char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_P2P_AddNotifyPeerConnectionEstablishedOptions Options = {0};
	Options.ApiVersion = EOS_P2P_ADDNOTIFYPEERCONNECTIONESTABLISHED_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	EOS_P2P_SocketId SocketId{};
	FillSocketId(SocketId, SocketName);
	Options.SocketId = &SocketId;

	uint64 notificationId = EOS_P2P_AddNotifyPeerConnectionEstablished(HP2P, &Options, nullptr, P2P_OnPeerConnectionEstablishedCallback);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL P2P_OnPeerConnectionInterruptedCallback(const EOS_P2P_OnPeerConnectionInterruptedInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_p2p_add_notify_peer_connection_interrupted");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "remote_user_id", productID_toString(data->RemoteUserId));
	DsMapAddString(map, "socket_name", data->SocketId->SocketName);
	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_p2p_add_notify_peer_connection_interrupted(char* LocalUserId,char* SocketName,char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_P2P_AddNotifyPeerConnectionInterruptedOptions Options = {0};
	Options.ApiVersion = EOS_P2P_ADDNOTIFYPEERCONNECTIONINTERRUPTED_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	EOS_P2P_SocketId SocketId{};
	FillSocketId(SocketId, SocketName);
	Options.SocketId = &SocketId;

	uint64 notificationId = EOS_P2P_AddNotifyPeerConnectionInterrupted(HP2P, &Options, nullptr, P2P_OnPeerConnectionInterruptedCallback);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL P2P_OnIncomingConnectionRequestCallback(const EOS_P2P_OnIncomingConnectionRequestInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_p2p_add_notify_peer_connection_request");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "remote_user_id", productID_toString(data->RemoteUserId));
	DsMapAddString(map, "socket_name", data->SocketId->SocketName);
	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_p2p_add_notify_peer_connection_request(char* LocalUserId,char* SocketName,char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, 0);

	EOS_P2P_AddNotifyPeerConnectionRequestOptions Options = {0};
	Options.ApiVersion = EOS_P2P_ADDNOTIFYPEERCONNECTIONREQUEST_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	EOS_P2P_SocketId SocketId{};
	FillSocketId(SocketId, SocketName);
	Options.SocketId = &SocketId;

	uint64 notificationId = EOS_P2P_AddNotifyPeerConnectionRequest(HP2P, &Options, nullptr, P2P_OnIncomingConnectionRequestCallback);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

func double eos_p2p_clear_packet_queue(char* LocalUserId,char* RemoteUserId,char* SocketName)
{
	eos_not_init_return(-1);

	EOS_P2P_ClearPacketQueueOptions Options = {0};
	Options.ApiVersion = EOS_P2P_CLEARPACKETQUEUE_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	EOS_P2P_SocketId SocketId{};
	FillSocketId(SocketId, SocketName);
	Options.SocketId = &SocketId;
	Options.RemoteUserId = EOS_ProductUserId_FromString(RemoteUserId);

	return (double)EOS_P2P_ClearPacketQueue(HP2P, &Options);
}

func double eos_p2p_close_connection(char* LocalUserId,char* RemoteUserId,char* SocketName)
{
	eos_not_init_return(-1);

	EOS_P2P_CloseConnectionOptions Options = {0};
	Options.ApiVersion = EOS_P2P_CLOSECONNECTION_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	EOS_P2P_SocketId SocketId{};
	FillSocketId(SocketId, SocketName);
	Options.SocketId = &SocketId;
	Options.RemoteUserId = EOS_ProductUserId_FromString(RemoteUserId);

	return (double)EOS_P2P_CloseConnection(HP2P, &Options);
}

func double eos_p2p_close_connections(char* LocalUserId,char* SocketName)
{
	eos_not_init_return(-1);

	EOS_P2P_CloseConnectionsOptions Options = {0};
	Options.ApiVersion = EOS_P2P_CLOSECONNECTIONS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	EOS_P2P_SocketId SocketId{};
	FillSocketId(SocketId, SocketName);
	Options.SocketId = &SocketId;
	return (double)EOS_P2P_CloseConnections(HP2P, &Options);
}

func double eos_p2p_get_n_a_t_type()
{
	eos_not_init_return(-1);

	EOS_P2P_GetNATTypeOptions Options = {0};
	Options.ApiVersion = EOS_P2P_GETNATTYPE_API_LATEST;

	EOS_ENATType OutNATType;

	EOS_P2P_GetNATType(HP2P, &Options, &OutNATType);

	return (double)OutNATType;
}

func double eos_p2p_get_next_received_packet_size(char* LocalUserId)
{
	eos_not_init_return(-1);

	EOS_P2P_GetNextReceivedPacketSizeOptions Options = {0};
	Options.ApiVersion = EOS_P2P_GETNEXTRECEIVEDPACKETSIZE_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.RequestedChannel = nullptr;

	uint32_t OutPacketSizeBytes;

	EOS_P2P_GetNextReceivedPacketSize(HP2P, &Options, &OutPacketSizeBytes);

	return (double)(int32_t)OutPacketSizeBytes;
}

func double __eos_p2p_get_packet_queue_info(char* buff_ret)
{
	StructStream _struct = {};
	eos_not_init_return_buffer(buff_ret, _struct);

	EOS_P2P_GetPacketQueueInfoOptions Options = {0};
	Options.ApiVersion = EOS_P2P_GETPACKETQUEUEINFO_API_LATEST;

	EOS_P2P_PacketQueueInfo OutPacketQueueInfo;

	EOS_EResult result = EOS_P2P_GetPacketQueueInfo(HP2P, &Options, &OutPacketQueueInfo);

	if (EOS_EResult::EOS_Success == result)
	{
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
		_struct.writeTo(buff_ret);
	}

	return 0.0;
}

func double __eos_p2p_get_port_range(char* buff_ret)
{
	StructStream _struct = {};
	eos_not_init_return_buffer(buff_ret, _struct);

	EOS_P2P_GetPortRangeOptions Options = {0};
	Options.ApiVersion = EOS_P2P_GETPORTRANGE_API_LATEST;
	uint16_t OutPort;
	uint16_t OutNumAdditionalPortsToTry;

	EOS_EResult result = EOS_P2P_GetPortRange(HP2P, &Options, &OutPort, &OutNumAdditionalPortsToTry);

	if (EOS_EResult::EOS_Success == result)
	{
		_struct.addKeyValue("OutPort", (int)OutPort);
		_struct.addKeyValue("OutNumAdditionalPortsToTry", (int)OutNumAdditionalPortsToTry);
		_struct.writeTo(buff_ret);
	}
	else
	{
		_struct.writeTo(buff_ret);
	}

	return 0.0;
}

func double eos_p2p_get_relay_control()
{
	eos_not_init_return(-1);

	EOS_P2P_GetRelayControlOptions Options = {0};
	Options.ApiVersion = EOS_P2P_GETRELAYCONTROL_API_LATEST;

	EOS_ERelayControl OutRelayControl;

	EOS_EResult result = EOS_P2P_GetRelayControl(HP2P, &Options, &OutRelayControl);

	if (EOS_EResult::EOS_Success == result)
	{
		return (double)OutRelayControl;
	}
	else
	{
		return -4;
	}
}

void EOS_CALL P2P_OnQueryNATTypeCompleteCallback(const EOS_P2P_OnQueryNATTypeCompleteInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddDouble(map, "n_a_t_type", (double)data->NATType);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_p2p_query_n_a_t_type()
{
	eos_not_init_return(-1);

	EOS_P2P_QueryNATTypeOptions Options = {0};
	Options.ApiVersion = EOS_P2P_QUERYNATTYPE_API_LATEST;

	callback *mcallback = getCallbackData();

	EOS_P2P_QueryNATType(HP2P, &Options, mcallback, P2P_OnQueryNATTypeCompleteCallback);

	return mcallback->identifier;
}

func double __eos_p2p_receive_packet(char* buff_ret,char* LocalUserId, double MaxDataSizeBytes, double RequestedChannel)
{
	eos_not_init_return(-1);

	EOS_P2P_ReceivePacketOptions Options = {0};
	Options.ApiVersion = EOS_P2P_RECEIVEPACKET_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.MaxDataSizeBytes = (uint32_t)MaxDataSizeBytes;
	if (RequestedChannel >= 0)
		Options.RequestedChannel = (const uint8_t *)&RequestedChannel;
	else
		Options.RequestedChannel = nullptr;

	EOS_ProductUserId OutPeerId;
	EOS_P2P_SocketId OutSocketId;
	uint8_t OutChannel;
	// void* OutData;
	uint32_t OutBytesWritten;

	EOS_EResult result = EOS_P2P_ReceivePacket(HP2P, &Options, &OutPeerId, &OutSocketId, &OutChannel, buff_ret, &OutBytesWritten);

	if (result == EOS_EResult::EOS_Success)
	{
		return OutBytesWritten;
	}
	else
	{
		return -4;
	}
}

func double __eos_p2p_remove_notify_incoming_packet_queue_full(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_P2P_RemoveNotifyIncomingPacketQueueFull(HP2P, InId);
	return 0.0;
}

func double __eos_p2p_remove_notify_peer_connection_closed(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_P2P_RemoveNotifyPeerConnectionClosed(HP2P, InId);
	return 0.0;
}

func double __eos_p2p_remove_notify_peer_connection_established(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_P2P_RemoveNotifyPeerConnectionEstablished(HP2P, InId);
	return 0.0;
}

func double __eos_p2p_remove_notify_peer_connection_interrupted(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_P2P_RemoveNotifyPeerConnectionInterrupted(HP2P, InId);
	return 0.0;
}

func double __eos_p2p_remove_notify_peer_connection_request(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_P2P_RemoveNotifyPeerConnectionRequest(HP2P, InId);
	return 0.0;
}

func double __eos_p2p_send_packet(char* buff_args,char* buff_data, double len)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);

	EOS_P2P_SendPacketOptions Options = {0};
	Options.ApiVersion = EOS_P2P_SENDPACKET_API_LATEST;
	Options.bAllowDelayedDelivery = YYGetBool(args[0]);
	Options.bDisableAutoAcceptConnection = YYGetBool(args[1]);
	Options.Channel = YYGetUint8(args[2]);
	Options.Data = buff_data;
	Options.DataLengthBytes = (uint32_t)len;
	Options.LocalUserId = EOS_ProductUserId_FromString(YYGetString(args[3]));
	Options.Reliability = (EOS_EPacketReliability)YYGetUint8(args[4]);
	Options.RemoteUserId = EOS_ProductUserId_FromString(YYGetString(args[5]));

	EOS_P2P_SocketId SocketId{};
	FillSocketId(SocketId, YYGetString(args[6]));
	Options.SocketId = &SocketId;

	double result = (double)EOS_P2P_SendPacket(HP2P, &Options);

	return result;
}

func double eos_p2p_set_packet_queue_size(double IncomingPacketQueueMaxSizeBytes, double OutgoingPacketQueueMaxSizeBytes)
{
	eos_not_init_return(-1);

	EOS_P2P_SetPacketQueueSizeOptions Options = {0};
	Options.ApiVersion = EOS_P2P_SETPACKETQUEUESIZE_API_LATEST;
	Options.IncomingPacketQueueMaxSizeBytes = (uint64_t)IncomingPacketQueueMaxSizeBytes;
	Options.OutgoingPacketQueueMaxSizeBytes = (uint64_t)OutgoingPacketQueueMaxSizeBytes;

	return (double)EOS_P2P_SetPacketQueueSize(HP2P, &Options);
}

func double eos_p2p_set_port_range(double Port, double MaxAdditionalPortsToTry)
{
	eos_not_init_return(-1);

	EOS_P2P_SetPortRangeOptions Options = {0};
	Options.ApiVersion = EOS_P2P_SETPORTRANGE_API_LATEST;
	Options.MaxAdditionalPortsToTry = (uint16_t)MaxAdditionalPortsToTry;
	Options.Port = (uint16_t)Port;

	return (double)EOS_P2P_SetPortRange(HP2P, &Options);
}

func double eos_p2p_set_relay_control(double RelayControl)
{
	eos_not_init_return(-1);

	EOS_P2P_SetRelayControlOptions Options;
	Options.ApiVersion = EOS_P2P_SETRELAYCONTROL_API_LATEST;
	Options.RelayControl = (EOS_ERelayControl)RelayControl;

	return (double)EOS_P2P_SetRelayControl(HP2P, &Options);
}
