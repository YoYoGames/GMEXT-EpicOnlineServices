
#include "pch.h"
#include "YYEpicOnlineServices.h"
#include "eos_rtc.h"
#include "eos_rtc_audio.h"
#include "eos_rtc_data.h"
#include "eos_rtc_admin.h"

//Functions
//EOS_RTC_AddNotifyDisconnected
//EOS_RTC_AddNotifyParticipantStatusChanged
//EOS_RTC_AddNotifyRoomStatisticsUpdated
//EOS_RTC_BlockParticipant
//EOS_RTC_GetAudioInterface
//EOS_RTC_GetDataInterface
//EOS_RTC_JoinRoom
//EOS_RTC_LeaveRoom
//EOS_RTC_RemoveNotifyDisconnected
//EOS_RTC_RemoveNotifyParticipantStatusChanged
//EOS_RTC_RemoveNotifyRoomStatisticsUpdated
//EOS_RTC_SetRoomSetting
//EOS_RTC_SetSetting
//EOS_RTCAdmin_CopyUserTokenByIndex
//EOS_RTCAdmin_CopyUserTokenByUserId
//EOS_RTCAdmin_Kick
//EOS_RTCAdmin_QueryJoinRoomToken
//EOS_RTCAdmin_SetParticipantHardMute
//EOS_RTCAdmin_UserToken_Release
//EOS_RTCAudio_AddNotifyAudioBeforeRender
//EOS_RTCAudio_AddNotifyAudioBeforeSend
//EOS_RTCAudio_AddNotifyAudioDevicesChanged
//EOS_RTCAudio_AddNotifyAudioInputState
//EOS_RTCAudio_AddNotifyAudioOutputState
//EOS_RTCAudio_AddNotifyParticipantUpdated
//EOS_RTCAudio_CopyInputDeviceInformationByIndex
//EOS_RTCAudio_CopyOutputDeviceInformationByIndex
//EOS_RTCAudio_GetAudioInputDeviceByIndex
//EOS_RTCAudio_GetAudioInputDevicesCount
//EOS_RTCAudio_GetAudioOutputDeviceByIndex
//EOS_RTCAudio_GetAudioOutputDevicesCount
//EOS_RTCAudio_GetInputDevicesCount
//EOS_RTCAudio_GetOutputDevicesCount
//EOS_RTCAudio_InputDeviceInformation_Release
//EOS_RTCAudio_OutputDeviceInformation_Release
//EOS_RTCAudio_QueryInputDevicesInformation
//EOS_RTCAudio_QueryOutputDevicesInformation
//EOS_RTCAudio_RegisterPlatformAudioUser
//EOS_RTCAudio_RegisterPlatformUser
//EOS_RTCAudio_RemoveNotifyAudioBeforeRender
//EOS_RTCAudio_RemoveNotifyAudioBeforeSend
//EOS_RTCAudio_RemoveNotifyAudioDevicesChanged
//EOS_RTCAudio_RemoveNotifyAudioInputState
//EOS_RTCAudio_RemoveNotifyAudioOutputState
//EOS_RTCAudio_RemoveNotifyParticipantUpdated
//EOS_RTCAudio_SendAudio
//EOS_RTCAudio_SetAudioInputSettings
//EOS_RTCAudio_SetAudioOutputSettings
//EOS_RTCAudio_SetInputDeviceSettings
//EOS_RTCAudio_SetOutputDeviceSettings
//EOS_RTCAudio_UnregisterPlatformAudioUser
//EOS_RTCAudio_UnregisterPlatformUser
//EOS_RTCAudio_UpdateParticipantVolume
//EOS_RTCAudio_UpdateReceiving
//EOS_RTCAudio_UpdateReceivingVolume
//EOS_RTCAudio_UpdateSending
//EOS_RTCAudio_UpdateSendingVolume
//EOS_RTCData_AddNotifyDataReceived
//EOS_RTCData_AddNotifyParticipantUpdated
//EOS_RTCData_RemoveNotifyDataReceived
//EOS_RTCData_RemoveNotifyParticipantUpdated
//EOS_RTCData_SendData
//EOS_RTCData_UpdateReceiving
//EOS_RTCData_UpdateSending
//EOS_RTCData_OnUpdateSendingCallback

EOS_HRTC HRTC;
EOS_HRTCAudio HRTCAudio;
EOS_HRTCData HRTCData;
EOS_HRTCAdmin HRTCAdmin;

void EpicGames_RTC_Init()
{
	HRTC = EOS_Platform_GetRTCInterface(PlatformHandle);
	HRTCAdmin = EOS_Platform_GetRTCAdminInterface(PlatformHandle);
}

void EOS_CALL RTC_AddNotifyDisconnected(const EOS_RTC_DisconnectedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_RTC_AddNotifyDisconnected");
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));
	DsMapAddString(map, "RoomName", Data->RoomName);
	DsMapAddDouble(map, "status", (double)Data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(Data->ResultCode));

	CreateAsyncEventWithDSMap(map, 70);
}

func double EpicGames_RTC_AddNotifyDisconnected(char* RoomName, char* LocalUserId, char* buff_ret)
{ 

	callback* mcallback = getCallbackData();

	EOS_RTC_AddNotifyDisconnectedOptions Options = {};
	Options.ApiVersion = EOS_RTC_ADDNOTIFYDISCONNECTED_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.RoomName = RoomName;

	uint64 ret = EOS_RTC_AddNotifyDisconnected(HRTC,&Options,mcallback, RTC_AddNotifyDisconnected);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);

	return mcallback->identifier;
}

void EOS_CALL RTC_AddNotifyParticipantStatusChanged(const EOS_RTC_ParticipantStatusChangedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_RTC_AddNotifyParticipantStatusChanged");
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));
	DsMapAddString(map, "RoomName", Data->RoomName);
	DsMapAddDouble(map, "bParticipantInBlocklist", (double)Data->bParticipantInBlocklist);
	DsMapAddString(map, "ParticipantId", productID_toString(Data->ParticipantId));
	DsMapAddDouble(map, "ParticipantStatus", (double)Data->ParticipantStatus);
	//TODO
	Data->ParticipantMetadata;
	Data->ParticipantMetadataCount;

	CreateAsyncEventWithDSMap(map, 70);
}


func double EpicGames_RTC_AddNotifyParticipantStatusChanged(char* LocalUserId, char* RoomName, char* buff_ret)
{ 
	callback* mcallback = getCallbackData();

	EOS_RTC_AddNotifyParticipantStatusChangedOptions Options = { 0 };
	Options.ApiVersion = EOS_RTC_ADDNOTIFYPARTICIPANTSTATUSCHANGED_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.RoomName = RoomName;

	uint64 ret = EOS_RTC_AddNotifyParticipantStatusChanged(HRTC,&Options,mcallback, RTC_AddNotifyParticipantStatusChanged);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);

	return mcallback->identifier;
} 

void EOS_CALL RTC_AddNotifyRoomStatisticsUpdated(const EOS_RTC_RoomStatisticsUpdatedInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_RTC_AddNotifyRoomStatisticsUpdated");
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));
	DsMapAddString(map, "RoomName", Data->RoomName);
	DsMapAddString(map, "Statistic", Data->Statistic);

	CreateAsyncEventWithDSMap(map, 70);
}

func double EpicGames_RTC_AddNotifyRoomStatisticsUpdated(char* LocalUserId, char* RoomName, char* buff_ret)
{ 
	callback* mcallback = getCallbackData();

	EOS_RTC_AddNotifyRoomStatisticsUpdatedOptions Options = {0};
	Options.ApiVersion = EOS_RTC_ADDNOTIFYROOMSTATISTICSUPDATED_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.RoomName = RoomName;

	uint64 ret = EOS_RTC_AddNotifyRoomStatisticsUpdated(HRTC,&Options,mcallback, RTC_AddNotifyRoomStatisticsUpdated);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);

	return mcallback->identifier;
}

func double EpicGames_RTC_BlockParticipant() { return 0.0; } 
func double EpicGames_RTC_GetAudioInterface() { return 0.0; } 
func double EpicGames_RTC_GetDataInterface() { return 0.0; } 
func double EpicGames_RTC_JoinRoom() { return 0.0; } 
func double EpicGames_RTC_LeaveRoom() { return 0.0; } 

func double EpicGames_RTC_RemoveNotifyDisconnected(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTC_RemoveNotifyDisconnected(HRTC, InId);

	return 0.0;
} 

func double EpicGames_RTC_RemoveNotifyParticipantStatusChanged(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTC_RemoveNotifyParticipantStatusChanged(HRTC, InId);

	return 0.0;
} 

func double EpicGames_RTC_RemoveNotifyRoomStatisticsUpdated(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTC_RemoveNotifyRoomStatisticsUpdated(HRTC, InId);

	return 0.0;
} 

func double EpicGames_RTC_SetRoomSetting() { return 0.0; } 
func double EpicGames_RTC_SetSetting() { return 0.0; } 
func double EpicGames_RTCAdmin_CopyUserTokenByIndex() { return 0.0; } 
func double EpicGames_RTCAdmin_CopyUserTokenByUserId() { return 0.0; } 
func double EpicGames_RTCAdmin_Kick() { return 0.0; } 
func double EpicGames_RTCAdmin_QueryJoinRoomToken() { return 0.0; } 
func double EpicGames_RTCAdmin_SetParticipantHardMute() { return 0.0; } 
func double EpicGames_RTCAdmin_UserToken_Release() { return 0.0; } 

void EOS_CALL RTCAudio_AddNotifyAudioBeforeRender(const EOS_RTCAudio_AudioBeforeRenderCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_RTCAudio_AddNotifyAudioBeforeRender");
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));
	DsMapAddString(map, "RoomName", Data->RoomName);
	DsMapAddString(map, "ParticipantId", productID_toString(Data->ParticipantId));
	//TODO
	Data->Buffer;

	CreateAsyncEventWithDSMap(map, 70);
}


func double EpicGames_RTCAudio_AddNotifyAudioBeforeRender(char* LocalUserId,char* RoomName, double bUnmixedAudio, char* buff_ret)
{ 
	callback* mcallback = getCallbackData();

	EOS_RTCAudio_AddNotifyAudioBeforeRenderOptions Options = { 0 };
	Options.ApiVersion = EOS_RTCAUDIO_ADDNOTIFYAUDIOBEFORERENDER_API_LATEST;
	Options.bUnmixedAudio = bUnmixedAudio>0.5;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.RoomName = RoomName;

	uint64 ret = EOS_RTCAudio_AddNotifyAudioBeforeRender(HRTCAudio,&Options,mcallback, RTCAudio_AddNotifyAudioBeforeRender);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);

	return 0.0;

} 

void EOS_CALL RTCAudio_AddNotifyAudioBeforeSend(const EOS_RTCAudio_AudioBeforeSendCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_RTCAudio_AddNotifyAudioBeforeSend");
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));
	DsMapAddString(map, "RoomName", Data->RoomName);
	//TODO
	Data->Buffer;

	CreateAsyncEventWithDSMap(map, 70);
}


func double EpicGames_RTCAudio_AddNotifyAudioBeforeSend(char* LocalUserId, char* RoomName, char* buff_ret)
{ 
	callback* mcallback = getCallbackData();

	EOS_RTCAudio_AddNotifyAudioBeforeSendOptions Options = { 0 }; 
	Options.ApiVersion = EOS_RTCAUDIO_ADDNOTIFYAUDIOBEFORESEND_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.RoomName = RoomName;

	uint64 ret = EOS_RTCAudio_AddNotifyAudioBeforeSend(HRTCAudio, &Options,mcallback, RTCAudio_AddNotifyAudioBeforeSend);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);

	return mcallback->identifier;
} 

void EOS_CALL RTCAudio_AddNotifyAudioDevicesChanged(const EOS_RTCAudio_AudioDevicesChangedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_RTCAudio_AddNotifyAudioDevicesChanged");
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);
}


func double EpicGames_RTCAudio_AddNotifyAudioDevicesChanged(char* buff_ret)
{ 
	callback* mcallback = getCallbackData();

	EOS_RTCAudio_AddNotifyAudioDevicesChangedOptions Options = { 0 };
	Options.ApiVersion = EOS_RTCAUDIO_ADDNOTIFYAUDIODEVICESCHANGED_API_LATEST;

	uint64 ret = EOS_RTCAudio_AddNotifyAudioDevicesChanged(HRTCAudio,&Options, mcallback,RTCAudio_AddNotifyAudioDevicesChanged);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);

	return mcallback->identifier;
} 

void EOS_CALL RTCAudio_AddNotifyAudioInputState(const EOS_RTCAudio_AudioInputStateCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_RTCAudio_AddNotifyAudioInputState");
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));
	DsMapAddString(map, "RoomName", Data->RoomName);
	DsMapAddDouble(map, "Status", (double)Data->Status);

	CreateAsyncEventWithDSMap(map, 70);
}

func double EpicGames_RTCAudio_AddNotifyAudioInputState(char* LocalUserId, char* RoomName, char* buff_ret)
{ 
	callback* mcallback = getCallbackData();

	EOS_RTCAudio_AddNotifyAudioInputStateOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_ADDNOTIFYAUDIOINPUTSTATE_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.RoomName = RoomName;

	uint64 ret = EOS_RTCAudio_AddNotifyAudioInputState(HRTCAudio,&Options,mcallback, RTCAudio_AddNotifyAudioInputState);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);

	return mcallback->identifier;
} 

void EOS_CALL RTCAudio_AddNotifyAudioOutputState(const EOS_RTCAudio_AudioOutputStateCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_RTCAudio_AddNotifyAudioOutputState");
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));
	DsMapAddString(map, "RoomName", Data->RoomName);
	DsMapAddDouble(map, "Status", (double)Data->Status);

	CreateAsyncEventWithDSMap(map, 70);
}

func double EpicGames_RTCAudio_AddNotifyAudioOutputState(char* LocalUserId, char* RoomName, char* buff_ret)
{ 
	callback* mcallback = getCallbackData();

	EOS_RTCAudio_AddNotifyAudioOutputStateOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_ADDNOTIFYAUDIOOUTPUTSTATE_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.RoomName = RoomName;
	
	uint64 ret = EOS_RTCAudio_AddNotifyAudioOutputState(HRTCAudio,&Options,mcallback, RTCAudio_AddNotifyAudioOutputState);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);

	return mcallback->identifier;
} 

void EOS_CALL RTCAudio_AddNotifyAudioOutputState(const EOS_RTCAudio_ParticipantUpdatedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_RTCAudio_AddNotifyParticipantUpdated");
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));
	DsMapAddString(map, "RoomName", Data->RoomName);
	DsMapAddDouble(map, "Speaking", Data->bSpeaking);
	DsMapAddDouble(map, "AudioStatus", (double)Data->AudioStatus);
	DsMapAddString(map, "ParticipantId", productID_toString(Data->ParticipantId));

	CreateAsyncEventWithDSMap(map, 70);
}

func double EpicGames_RTCAudio_AddNotifyParticipantUpdated(char* LocalUserId, char* RoomName, char* buff_ret)
{ 
	callback* mcallback = getCallbackData();

	EOS_RTCAudio_AddNotifyParticipantUpdatedOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_ADDNOTIFYPARTICIPANTUPDATED_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.RoomName = RoomName;
	
	uint64 ret = EOS_RTCAudio_AddNotifyParticipantUpdated(HRTCAudio,&Options,mcallback, RTCAudio_AddNotifyAudioOutputState);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);

	return mcallback->identifier;
} 

func double EpicGames_RTCAudio_CopyInputDeviceInformationByIndex() { return 0.0; } 
func double EpicGames_RTCAudio_CopyOutputDeviceInformationByIndex() { return 0.0; } 
func double EpicGames_RTCAudio_GetAudioInputDeviceByIndex() { return 0.0; } 
func double EpicGames_RTCAudio_GetAudioInputDevicesCount() { return 0.0; } 
func double EpicGames_RTCAudio_GetAudioOutputDeviceByIndex() { return 0.0; } 
func double EpicGames_RTCAudio_GetAudioOutputDevicesCount() { return 0.0; } 
func double EpicGames_RTCAudio_GetInputDevicesCount() { return 0.0; } 
func double EpicGames_RTCAudio_GetOutputDevicesCount() { return 0.0; } 
func double EpicGames_RTCAudio_InputDeviceInformation_Release() { return 0.0; } 
func double EpicGames_RTCAudio_OutputDeviceInformation_Release() { return 0.0; } 
func double EpicGames_RTCAudio_QueryInputDevicesInformation() { return 0.0; } 
func double EpicGames_RTCAudio_QueryOutputDevicesInformation() { return 0.0; } 
func double EpicGames_RTCAudio_RegisterPlatformAudioUser() { return 0.0; } 
func double EpicGames_RTCAudio_RegisterPlatformUser() { return 0.0; } 

func double EpicGames_RTCAudio_RemoveNotifyAudioBeforeRender(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTCAudio_RemoveNotifyAudioBeforeRender(HRTCAudio, InId);

	return 0.0; 
} 

func double EpicGames_RTCAudio_RemoveNotifyAudioBeforeSend(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTCAudio_RemoveNotifyAudioBeforeSend(HRTCAudio, InId);

	return 0.0; 
} 

func double EpicGames_RTCAudio_RemoveNotifyAudioDevicesChanged(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTCAudio_RemoveNotifyAudioDevicesChanged(HRTCAudio, InId);

	return 0.0; 
} 

func double EpicGames_RTCAudio_RemoveNotifyAudioInputState(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTCAudio_RemoveNotifyAudioInputState(HRTCAudio, InId);

	return 0.0; 
} 

func double EpicGames_RTCAudio_RemoveNotifyAudioOutputState(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTCAudio_RemoveNotifyAudioOutputState(HRTCAudio, InId);

	return 0.0; 
} 

func double EpicGames_RTCAudio_RemoveNotifyParticipantUpdated(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTCAudio_RemoveNotifyParticipantUpdated(HRTCAudio, InId);

	return 0.0; 
} 

func double EpicGames_RTCAudio_SendAudio() { return 0.0; } 
func double EpicGames_RTCAudio_SetAudioInputSettings() { return 0.0; } 
func double EpicGames_RTCAudio_SetAudioOutputSettings() { return 0.0; } 
func double EpicGames_RTCAudio_SetInputDeviceSettings() { return 0.0; } 
func double EpicGames_RTCAudio_SetOutputDeviceSettings() { return 0.0; } 
func double EpicGames_RTCAudio_UnregisterPlatformAudioUser() { return 0.0; } 
func double EpicGames_RTCAudio_UnregisterPlatformUser() { return 0.0; } 
func double EpicGames_RTCAudio_UpdateParticipantVolume() { return 0.0; } 
func double EpicGames_RTCAudio_UpdateReceiving() { return 0.0; } 
func double EpicGames_RTCAudio_UpdateReceivingVolume() { return 0.0; } 
func double EpicGames_RTCAudio_UpdateSending() { return 0.0; } 
func double EpicGames_RTCAudio_UpdateSendingVolume() { return 0.0; } 

void EOS_CALL RTCData_AddNotifyDataReceived(const EOS_RTCData_DataReceivedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_RTCData_AddNotifyDataReceived");
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));
	DsMapAddString(map, "RoomName", Data->RoomName);
	DsMapAddString(map, "ParticipantId", productID_toString(Data->ParticipantId));
	//TODO
	Data->Data;
	Data->DataLengthBytes;
	

	CreateAsyncEventWithDSMap(map, 70);
}

func double EpicGames_RTCData_AddNotifyDataReceived(char* LocalUserId, char* RoomName, char* buff_ret)
{ 
	callback* mcallback = getCallbackData();

	EOS_RTCData_AddNotifyDataReceivedOptions Options = { 0 };
	Options.ApiVersion = EOS_RTCDATA_ADDNOTIFYDATARECEIVED_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.RoomName = RoomName;

	uint64 ret = EOS_RTCData_AddNotifyDataReceived(HRTCData, &Options, mcallback, RTCData_AddNotifyDataReceived);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);

	return mcallback->identifier;
} 

void EOS_CALL RTCData_AddNotifyDataReceived(const EOS_RTCData_ParticipantUpdatedCallbackInfo* Data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_RTCData_AddNotifyParticipantUpdated");
	DsMapAddDouble(map, "identifier", (double)((callback*)(Data->ClientData))->identifier);
	DsMapAddString(map, "LocalUserId", productID_toString(Data->LocalUserId));
	DsMapAddString(map, "RoomName", Data->RoomName);
	DsMapAddString(map, "ParticipantId", productID_toString(Data->ParticipantId));
	DsMapAddDouble(map, "DataStatus", (double)Data->DataStatus);

	CreateAsyncEventWithDSMap(map, 70);
}

func double EpicGames_RTCData_AddNotifyParticipantUpdated(char* LocalUserId, char* RoomName, char* buff_ret)
{ 
	callback* mcallback = getCallbackData();

	EOS_RTCData_AddNotifyParticipantUpdatedOptions Options = { 0 };
	Options.ApiVersion = EOS_RTCDATA_ADDNOTIFYPARTICIPANTUPDATED_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(LocalUserId);
	Options.RoomName = RoomName;

	uint64 ret = EOS_RTCData_AddNotifyParticipantUpdated(HRTCData,&Options,mcallback, RTCData_AddNotifyDataReceived);

	DataStream data;
	data << ret;
	data.writeTo(buff_ret);

	return mcallback->identifier;
}

func double EpicGames_RTCData_RemoveNotifyDataReceived(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTCData_RemoveNotifyDataReceived(HRTCData, InId);

	return 0.0; 
} 

func double EpicGames_RTCData_RemoveNotifyParticipantUpdated(char* buff_args)
{
	auto args = buffer_unpack((uint8_t*)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTCData_RemoveNotifyParticipantUpdated(HRTCData, InId);

	return 0.0; 
} 

func double EpicGames_RTCData_SendData() { return 0.0; } 
func double EpicGames_RTCData_UpdateReceiving() { return 0.0; } 
func double EpicGames_RTCData_UpdateSending() { return 0.0; } 




