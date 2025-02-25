//double SDKEpicGames_ActiveSession_CopyInfo(char* SessionName, char* buff_ret)
function EpicGames_ActiveSession_CopyInfo(SessionName)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_ActiveSession_CopyInfo(SessionName,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//double SDKEpicGames_SessionDetails_CopyInfo
function EpicGames_SessionDetails_CopyInfo()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_SessionDetails_CopyInfo(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//double SDKEpicGames_SessionDetails_CopySessionAttributeByIndex(double AttrIndex, char* buff_ret)
function EpicGames_SessionDetails_CopySessionAttributeByIndex(AttrIndex)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_SessionDetails_CopySessionAttributeByIndex(AttrIndex,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//double SDKEpicGames_SessionDetails_CopySessionAttributeByKey(char* AttrKey,char* buff_ret)
function EpicGames_SessionDetails_CopySessionAttributeByKey(AttrKey)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_SessionDetails_CopySessionAttributeByKey(AttrKey,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//double SDKEpicGames_SessionModification_AddAttribute(double AdvertisementType, double SessionAttribute, char* buff_args)
function EpicGames_SessionModification_AddAttribute(AdvertisementType,SessionAttribute,Attribute)
{
	var _args = [
		[Attribute, undefined], // struct
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_SessionModification_AddAttribute(AdvertisementType,SessionAttribute,_args_buffer_address)
}

//double SDKEpicGames_SessionModification_SetAllowedPlatformIds
function EpicGames_SessionModification_SetAllowedPlatformIds(array_ids)
{
	var _args = [
		[array_ids, buffer_u8], // struct
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_SessionModification_SetAllowedPlatformIds(_args_buffer_address)
}

//SDKEpicGames_Sessions_CopySessionHandleByUiEventId
function EpicGames_Sessions_CopySessionHandleByUiEventId(UiEventId)
{
	var _args = [
		[UiEventId ,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Sessions_CopySessionHandleByUiEventId(_args_buffer_address)
}

//double SDKEpicGames_Sessions_CreateSessionModification
function EpicGames_Sessions_CreateSessionModification(AllowedPlatformIds,PresenceEnabled,bSanctionsEnabled,BucketId,LocalUserId,MaxPlayers,SessionId,SessionName)
{
	var _args = [
		[AllowedPlatformIds, buffer_u32],//0,Array
		[PresenceEnabled, buffer_bool],//1
		[bSanctionsEnabled, buffer_bool],//2
		[BucketId, buffer_string],//3
		[LocalUserId, buffer_string],//4
		[MaxPlayers, buffer_f32],//5
		[SessionId, buffer_string],//6
		[SessionName, buffer_string],//7
	]
	
	show_debug_message(_args)
	
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Sessions_CreateSessionModification(_args_buffer_address)
}

//double SDKEpicGames_Sessions_RegisterPlayers(char* SessionName, char* buff_args)
function EpicGames_Sessions_RegisterPlayers(SessionName,array_product_ids)
{
	var _args = [
		[array_product_ids, undefined], // array
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Sessions_RegisterPlayers(SessionName,_args_buffer_address)
}

//double SDKEpicGames_Sessions_UnregisterPlayers(char* SessionName, char* buff_args)
function EpicGames_Sessions_UnregisterPlayers(SessionName,array_product_ids)
{
	var _args = [
		[array_product_ids, undefined], // array
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return EpicGames_Sessions_UnregisterPlayers(SessionName,_args_buffer_address)
}

//double SDKEpicGames_SessionSearch_SetParameter(double comparisonOp,char* buff_args)
function EpicGames_SessionSearch_SetParameter(comparisonOp,Attribute)
{
	var _args = [
		[Attribute, undefined], // Struct
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_SessionSearch_SetParameter(comparisonOp,_args_buffer_address)
}






//SDKEpicGames_Sessions_AddNotifyJoinSessionAccepted
function EpicGames_Sessions_AddNotifyJoinSessionAccepted()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_Sessions_AddNotifyJoinSessionAccepted(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//SDKEpicGames_Sessions_AddNotifyLeaveSessionRequested
function EpicGames_Sessions_AddNotifyLeaveSessionRequested()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_Sessions_AddNotifyLeaveSessionRequested(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}
//SDKEpicGames_Sessions_AddNotifySendSessionNativeInviteRequested
function EpicGames_Sessions_AddNotifySendSessionNativeInviteRequested()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_Sessions_AddNotifySendSessionNativeInviteRequested(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}
//SDKEpicGames_Sessions_AddNotifySessionInviteAccepted
function EpicGames_Sessions_AddNotifySessionInviteAccepted()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_Sessions_AddNotifySessionInviteAccepted(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}
//SDKEpicGames_Sessions_AddNotifySessionInviteReceived
function EpicGames_Sessions_AddNotifySessionInviteReceived()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_Sessions_AddNotifySessionInviteReceived(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//SDKEpicGames_Sessions_AddNotifySessionInviteRejected
function EpicGames_Sessions_AddNotifySessionInviteRejected()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_Sessions_AddNotifySessionInviteRejected(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}


//SDKEpicGames_Sessions_RemoveNotifyJoinSessionAccepted
function EpicGames_Sessions_RemoveNotifyJoinSessionAccepted(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Sessions_RemoveNotifyJoinSessionAccepted(_args_buffer_address)
}

//SDKEpicGames_Sessions_RemoveNotifyLeaveSessionRequested
function EpicGames_Sessions_RemoveNotifyLeaveSessionRequested(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Sessions_RemoveNotifyLeaveSessionRequested(_args_buffer_address)
}

//SDKEpicGames_Sessions_RemoveNotifySendSessionNativeInviteRequested
function EpicGames_Sessions_RemoveNotifySendSessionNativeInviteRequested(notificationId)
{
		var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Sessions_RemoveNotifySendSessionNativeInviteRequested(_args_buffer_address)
}

//SDKEpicGames_Sessions_RemoveNotifySessionInviteAccepted
function EpicGames_Sessions_RemoveNotifySessionInviteAccepted(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Sessions_RemoveNotifySessionInviteAccepted(_args_buffer_address)
}

//SDKEpicGames_Sessions_RemoveNotifySessionInviteReceived
function EpicGames_Sessions_RemoveNotifySessionInviteReceived(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Sessions_RemoveNotifySessionInviteReceived(_args_buffer_address)
}

//SDKEpicGames_Sessions_RemoveNotifySessionInviteRejected
function EpicGames_Sessions_RemoveNotifySessionInviteRejected(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Sessions_RemoveNotifySessionInviteRejected(_args_buffer_address)
}



//double SDKEpicGames_P2P_GetPacketQueueInfo
function EpicGames_P2P_GetPacketQueueInfo()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_P2P_GetPacketQueueInfo(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//double SDKEpicGames_P2P_GetPortRange
function EpicGames_P2P_GetPortRange()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_P2P_GetPortRange(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//double SDKEpicGames_P2P_ReceivePacket(char* buff_ret,char* LocalUserId,double MaxDataSizeBytes,double RequestedChannel)
function EpicGames_P2P_ReceivePacket(buffAdress,LocalUserId,MaxDataSizeBytes,RequestedChannel)
{	
	return SDKEpicGames_P2P_ReceivePacket(buffAdress,LocalUserId,MaxDataSizeBytes,RequestedChannel)
}

//double SDKEpicGames_P2P_SendPacket(char* buff_data, double len)
function EpicGames_P2P_SendPacket(buff,buff_len,AllowDelayedDelivery,DisableAutoAcceptConnection,Channel,LocalUserId,Reliability,RemoteUserId,SocketName)
{
	var _args = [
		[AllowDelayedDelivery,buffer_bool],
		[DisableAutoAcceptConnection,buffer_bool],
		[Channel,buffer_f32],
		[LocalUserId,buffer_string],
		[Reliability,buffer_u8],
		[RemoteUserId,buffer_string],
		[SocketName,buffer_string],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_P2P_SendPacket(_args_buffer_address,buffer_get_address(buff),buff_len)
}

//SDKEpicGames_P2P_AddNotifyIncomingPacketQueueFull
function EpicGames_P2P_AddNotifyIncomingPacketQueueFull()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_P2P_AddNotifyIncomingPacketQueueFull(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//SDKEpicGames_P2P_AddNotifyPeerConnectionClosed
function EpicGames_P2P_AddNotifyPeerConnectionClosed(LocalUserId, SocketName)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_P2P_AddNotifyPeerConnectionClosed(LocalUserId, SocketName,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//SDKEpicGames_P2P_AddNotifyPeerConnectionEstablished
function EpicGames_P2P_AddNotifyPeerConnectionEstablished(LocalUserId, SocketName)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_P2P_AddNotifyPeerConnectionEstablished(LocalUserId, SocketName,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//SDKEpicGames_P2P_AddNotifyPeerConnectionInterrupted
function EpicGames_P2P_AddNotifyPeerConnectionInterrupted(LocalUserId, SocketName)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_P2P_AddNotifyPeerConnectionInterrupted(LocalUserId, SocketName,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//SDKEpicGames_P2P_AddNotifyPeerConnectionRequest
function EpicGames_P2P_AddNotifyPeerConnectionRequest(LocalUserId, SocketName)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_P2P_AddNotifyPeerConnectionRequest(LocalUserId, SocketName,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}



//SDKEpicGames_P2P_RemoveNotifyIncomingPacketQueueFull
function EpicGames_P2P_RemoveNotifyIncomingPacketQueueFull(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_P2P_RemoveNotifyIncomingPacketQueueFull(_args_buffer_address)
}

//SDKEpicGames_P2P_RemoveNotifyPeerConnectionClosed
function EpicGames_P2P_RemoveNotifyPeerConnectionClosed(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_P2P_RemoveNotifyPeerConnectionClosed(_args_buffer_address)
}

//SDKEpicGames_P2P_RemoveNotifyPeerConnectionEstablished
function EpicGames_P2P_RemoveNotifyPeerConnectionEstablished(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_P2P_RemoveNotifyPeerConnectionEstablished(_args_buffer_address)
}

//SDKEpicGames_P2P_RemoveNotifyPeerConnectionInterrupted
function EpicGames_P2P_RemoveNotifyPeerConnectionInterrupted(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_P2P_RemoveNotifyPeerConnectionInterrupted(_args_buffer_address)
}

//SDKEpicGames_P2P_RemoveNotifyPeerConnectionRequest
function EpicGames_P2P_RemoveNotifyPeerConnectionRequest(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_P2P_RemoveNotifyPeerConnectionRequest(_args_buffer_address)
}







//SDKEpicGames_Lobby_AddNotifyJoinLobbyAccepted
function EpicGames_Lobby_AddNotifyJoinLobbyAccepted()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_Lobby_AddNotifyJoinLobbyAccepted(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//SDKEpicGames_Lobby_AddNotifyLeaveLobbyRequested
function EpicGames_Lobby_AddNotifyLeaveLobbyRequested()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_Lobby_AddNotifyLeaveLobbyRequested(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//SDKEpicGames_Lobby_AddNotifyLobbyInviteAccepted
function EpicGames_Lobby_AddNotifyLobbyInviteAccepted()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_Lobby_AddNotifyLobbyInviteAccepted(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//SDKEpicGames_Lobby_AddNotifyLobbyInviteReceived
function EpicGames_Lobby_AddNotifyLobbyInviteReceived()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_Lobby_AddNotifyLobbyInviteReceived(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//SDKEpicGames_Lobby_AddNotifyLobbyInviteRejected
function EpicGames_Lobby_AddNotifyLobbyInviteRejected()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_Lobby_AddNotifyLobbyInviteRejected(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//SDKEpicGames_Lobby_AddNotifyLobbyMemberStatusReceived
function EpicGames_Lobby_AddNotifyLobbyMemberStatusReceived()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_Lobby_AddNotifyLobbyMemberStatusReceived(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//SDKEpicGames_Lobby_AddNotifyLobbyMemberUpdateReceived
function EpicGames_Lobby_AddNotifyLobbyMemberUpdateReceived()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_Lobby_AddNotifyLobbyMemberUpdateReceived(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//SDKEpicGames_Lobby_AddNotifyLobbyUpdateReceived
function EpicGames_Lobby_AddNotifyLobbyUpdateReceived()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_Lobby_AddNotifyLobbyUpdateReceived(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//SDKEpicGames_Lobby_AddNotifyRTCRoomConnectionChanged
function EpicGames_Lobby_AddNotifyRTCRoomConnectionChanged()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_Lobby_AddNotifyRTCRoomConnectionChanged(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//SDKEpicGames_Lobby_AddNotifySendLobbyNativeInviteRequested
function EpicGames_Lobby_AddNotifySendLobbyNativeInviteRequested()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_Lobby_AddNotifySendLobbyNativeInviteRequested(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//SDKEpicGames_Lobby_CopyLobbyDetailsHandleByUiEventId
function EpicGames_Lobby_CopyLobbyDetailsHandleByUiEventId(UiEventId)
{
	var _args = [
		[UiEventId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Lobby_CopyLobbyDetailsHandleByUiEventId(_args_buffer_address)
}

//SDKEpicGames_Lobby_CreateLobby
function EpicGames_Lobby_CreateLobby(AllowedPlatformIds,bAllowInvites,bCrossplayOptOut,bDisableHostMigration,bEnableJoinById,bEnableRTCRoom,bPresenceEnabled)
{
	var _args = [
		[AllowedPlatformIds,buffer_u32],//array
		[bAllowInvites,buffer_bool],
		[bCrossplayOptOut,buffer_bool],
		[bDisableHostMigration,buffer_bool],
		[bEnableJoinById,buffer_bool],
		[bEnableRTCRoom,buffer_bool],
		[bPresenceEnabled,buffer_bool]
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Lobby_CreateLobby(_args_buffer_address)
}

//SDKEpicGames_Lobby_JoinLobby
function EpicGames_Lobby_JoinLobby(bCrossplayOptOut,bPresenceEnabled,bLocalAudioDeviceInputStartsMuted,bUseManualAudioInput,bUseManualAudioOutput,Flags,LocalUserId)
{
	var _args = [
			[bCrossplayOptOut,buffer_bool],
			[bPresenceEnabled,buffer_bool],
			[bLocalAudioDeviceInputStartsMuted,buffer_bool],
			[bUseManualAudioInput,buffer_bool],
			[bUseManualAudioOutput,buffer_bool],
			[Flags,buffer_u32],
			[LocalUserId,buffer_string]
		]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Lobby_JoinLobby(_args_buffer_address)
}
//SDKEpicGames_Lobby_JoinLobbyById
function EpicGames_Lobby_JoinLobbyById(bCrossplayOptOut,bPresenceEnabled,LobbyId,bLocalAudioDeviceInputStartsMuted,bUseManualAudioInput,bUseManualAudioOutput,Flags,LocalUserId)
{
	var _args = [
			[bCrossplayOptOut,buffer_bool],
			[bPresenceEnabled,buffer_bool],
			[LobbyId,buffer_string]
			[bLocalAudioDeviceInputStartsMuted,buffer_bool],
			[bUseManualAudioInput,buffer_bool],
			[bUseManualAudioOutput,buffer_bool],
			[Flags,buffer_u32],
			[LocalUserId,buffer_string]
		]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Lobby_JoinLobbyById(_args_buffer_address)
}

//SDKEpicGames_Lobby_RemoveNotifyJoinLobbyAccepted
function EpicGames_Lobby_RemoveNotifyJoinLobbyAccepted(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Lobby_RemoveNotifyJoinLobbyAccepted(_args_buffer_address)
}

//SDKEpicGames_Lobby_RemoveNotifyLeaveLobbyRequested
function EpicGames_Lobby_RemoveNotifyLeaveLobbyRequested(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Lobby_RemoveNotifyLeaveLobbyRequested(_args_buffer_address)
}

//SDKEpicGames_Lobby_RemoveNotifyLobbyInviteAccepted
function EpicGames_Lobby_RemoveNotifyLobbyInviteAccepted(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Lobby_RemoveNotifyLobbyInviteAccepted(_args_buffer_address)
}

//SDKEpicGames_Lobby_RemoveNotifyLobbyInviteReceived
function EpicGames_Lobby_RemoveNotifyLobbyInviteReceived(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Lobby_RemoveNotifyLobbyInviteReceived(_args_buffer_address)
}

//SDKEpicGames_Lobby_RemoveNotifyLobbyInviteRejected
function EpicGames_Lobby_RemoveNotifyLobbyInviteRejected(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Lobby_RemoveNotifyLobbyInviteRejected(_args_buffer_address)
}

//SDKEpicGames_Lobby_RemoveNotifyLobbyMemberStatusReceived
function EpicGames_Lobby_RemoveNotifyLobbyMemberStatusReceived(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Lobby_RemoveNotifyLobbyMemberStatusReceived(_args_buffer_address)
}

//SDKEpicGames_Lobby_RemoveNotifyLobbyMemberUpdateReceived
function EpicGames_Lobby_RemoveNotifyLobbyMemberUpdateReceived(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Lobby_RemoveNotifyLobbyMemberUpdateReceived(_args_buffer_address)
}

//SDKEpicGames_Lobby_RemoveNotifyLobbyUpdateReceived
function EpicGames_Lobby_RemoveNotifyLobbyUpdateReceived(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Lobby_RemoveNotifyLobbyUpdateReceived(_args_buffer_address)
}

//SDKEpicGames_Lobby_RemoveNotifyRTCRoomConnectionChanged
function EpicGames_Lobby_RemoveNotifyRTCRoomConnectionChanged(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Lobby_RemoveNotifyRTCRoomConnectionChanged(_args_buffer_address)
}

//SDKEpicGames_Lobby_RemoveNotifySendLobbyNativeInviteRequested
function EpicGames_Lobby_RemoveNotifySendLobbyNativeInviteRequested(notificationId)
{
	var _args = [
		[notificationId,buffer_u64],
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_Lobby_RemoveNotifySendLobbyNativeInviteRequested(_args_buffer_address)
}

//SDKEpicGames_LobbyModification_AddAttribute
function EpicGames_LobbyModification_AddAttribute(Attribute)
{
	var _args = [
		[Attribute,undefined],//struct
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_LobbyModification_AddAttribute(_args_buffer_address)
}

//SDKEpicGames_LobbyModification_AddMemberAttribute
function EpicGames_LobbyModification_AddMemberAttribute(Visibility,Attribute)
{
	var _args = [
		[Attribute,undefined],//struct
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_LobbyModification_AddMemberAttribute(Visibility,_args_buffer_address)
}

//SDKEpicGames_LobbyModification_SetAllowedPlatformIds
function EpicGames_LobbyModification_SetAllowedPlatformIds(AllowedPlatformIds)
{
	var _args = [
		[AllowedPlatformIds,undefined],//Array
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_LobbyModification_SetAllowedPlatformIds(_args_buffer_address)

}

//SDKEpicGames_LobbySearch_SetParameter
function EpicGames_LobbySearch_SetParameter(ComparisonOp,Attribute)
{
	var _args = [
		[Attribute,undefined],//struct
	]
	
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_LobbySearch_SetParameter(ComparisonOp,_args_buffer_address)
}

