//double SDKEpicGames_ActiveSession_CopyInfo(char* SessionName, char* buff_ret)
function EpicGames_ActiveSession_CopyInfo(SessionName)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_ActiveSession_CopyInfo(SessionName,_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//double SDKEpicGames_SessionDetails_CopyInfo(char* buff_ret)
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

//double SDKEpicGames_SessionModification_SetAllowedPlatformIds(char* buff_args)
function EpicGames_SessionModification_SetAllowedPlatformIds(array_ids)
{
	var _args = [
		[array_ids, buffer_u8], // struct
	]
		
	var _args_buffer_address = ext_pack_args(_args);
	
	return SDKEpicGames_SessionModification_SetAllowedPlatformIds(_args_buffer_address)
}

//double SDKEpicGames_Sessions_CreateSessionModification(char* buff_args)
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





//double SDKEpicGames_P2P_GetPacketQueueInfo(char* buff_ret)
function EpicGames_P2P_GetPacketQueueInfo()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_P2P_GetPacketQueueInfo(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//double SDKEpicGames_P2P_GetPortRange(char* buff_ret)
function EpicGames_P2P_GetPortRange()
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_P2P_GetPortRange(_return_buffer_address)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
}

//double SDKEpicGames_P2P_ReceivePacket(char* buff_ret,char* LocalUserId,double MaxDataSizeBytes,double RequestedChannel)
function EpicGames_P2P_ReceivePacket(LocalUserId,MaxDataSizeBytes,RequestedChannel)
{
	var _return_buffer_address = ext_return_buffer_address();
	
	SDKEpicGames_P2P_ReceivePacket(_return_buffer_address,LocalUserId,MaxDataSizeBytes,RequestedChannel)
	
	var _return_value = ext_buffer_unpack(ext_return_buffer());
	
	return _return_value;
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


