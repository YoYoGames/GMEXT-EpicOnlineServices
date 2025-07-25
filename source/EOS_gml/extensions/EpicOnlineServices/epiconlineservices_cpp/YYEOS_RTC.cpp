
#include "pch.h"
#include "YYEpicOnlineServices.h"
#include "eos_rtc.h"
#include "eos_rtc_audio.h"
#include "eos_rtc_data.h"
#include "eos_rtc_admin.h"

// Functions
// EOS_RTC_AddNotifyDisconnected
// EOS_RTC_AddNotifyParticipantStatusChanged
// EOS_RTC_AddNotifyRoomStatisticsUpdated
// EOS_RTC_BlockParticipant
// EOS_RTC_GetAudioInterface
// EOS_RTC_GetDataInterface
// EOS_RTC_JoinRoom
// EOS_RTC_LeaveRoom
// EOS_RTC_RemoveNotifyDisconnected
// EOS_RTC_RemoveNotifyParticipantStatusChanged
// EOS_RTC_RemoveNotifyRoomStatisticsUpdated
// EOS_RTC_SetRoomSetting
// EOS_RTC_SetSetting
// EOS_RTCAdmin_CopyUserTokenByIndex
// EOS_RTCAdmin_CopyUserTokenByUserId
// EOS_RTCAdmin_Kick
// EOS_RTCAdmin_QueryJoinRoomToken
// EOS_RTCAdmin_SetParticipantHardMute
// EOS_RTCAdmin_UserToken_Release
// EOS_RTCAudio_AddNotifyAudioBeforeRender
// EOS_RTCAudio_AddNotifyAudioBeforeSend
// EOS_RTCAudio_AddNotifyAudioDevicesChanged
// EOS_RTCAudio_AddNotifyAudioInputState
// EOS_RTCAudio_AddNotifyAudioOutputState
// EOS_RTCAudio_AddNotifyParticipantUpdated
// EOS_RTCAudio_CopyInputDeviceInformationByIndex
// EOS_RTCAudio_CopyOutputDeviceInformationByIndex
// EOS_RTCAudio_GetAudioInputDeviceByIndex
// EOS_RTCAudio_GetAudioInputDevicesCount
// EOS_RTCAudio_GetAudioOutputDeviceByIndex
// EOS_RTCAudio_GetAudioOutputDevicesCount
// EOS_RTCAudio_GetInputDevicesCount
// EOS_RTCAudio_GetOutputDevicesCount
// EOS_RTCAudio_InputDeviceInformation_Release
// EOS_RTCAudio_OutputDeviceInformation_Release
// EOS_RTCAudio_QueryInputDevicesInformation
// EOS_RTCAudio_QueryOutputDevicesInformation
// EOS_RTCAudio_RegisterPlatformAudioUser
// EOS_RTCAudio_RegisterPlatformUser
// EOS_RTCAudio_RemoveNotifyAudioBeforeRender
// EOS_RTCAudio_RemoveNotifyAudioBeforeSend
// EOS_RTCAudio_RemoveNotifyAudioDevicesChanged
// EOS_RTCAudio_RemoveNotifyAudioInputState
// EOS_RTCAudio_RemoveNotifyAudioOutputState
// EOS_RTCAudio_RemoveNotifyParticipantUpdated
// EOS_RTCAudio_SendAudio
// EOS_RTCAudio_SetAudioInputSettings
// EOS_RTCAudio_SetAudioOutputSettings
// EOS_RTCAudio_SetInputDeviceSettings
// EOS_RTCAudio_SetOutputDeviceSettings
// EOS_RTCAudio_UnregisterPlatformAudioUser
// EOS_RTCAudio_UnregisterPlatformUser
// EOS_RTCAudio_UpdateParticipantVolume
// EOS_RTCAudio_UpdateReceiving
// EOS_RTCAudio_UpdateReceivingVolume
// EOS_RTCAudio_UpdateSending
// EOS_RTCAudio_UpdateSendingVolume
// EOS_RTCData_AddNotifyDataReceived
// EOS_RTCData_AddNotifyParticipantUpdated
// EOS_RTCData_RemoveNotifyDataReceived
// EOS_RTCData_RemoveNotifyParticipantUpdated
// EOS_RTCData_SendData
// EOS_RTCData_UpdateReceiving
// EOS_RTCData_UpdateSending
// EOS_RTCData_OnUpdateSendingCallback

EOS_HRTC HRTC;
EOS_HRTCAudio HRTCAudio;
EOS_HRTCData HRTCData;
EOS_HRTCAdmin HRTCAdmin;

void eos_rtc_init()
{
	HRTC = EOS_Platform_GetRTCInterface(PlatformHandle);
	HRTCAdmin = EOS_Platform_GetRTCAdminInterface(PlatformHandle);

	HRTCAudio = EOS_RTC_GetAudioInterface(HRTC);
	HRTCData = EOS_RTC_GetDataInterface(HRTC);
}

void EOS_CALL RTC_AddNotifyDisconnected(const EOS_RTC_DisconnectedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_add_notify_disconnected");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_rtc_add_notify_disconnected(char* room_name,char* local_user_id,char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, -1);

	EOS_RTC_AddNotifyDisconnectedOptions Options = {};
	Options.ApiVersion = EOS_RTC_ADDNOTIFYDISCONNECTED_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RoomName = room_name;

	uint64_t notificationId = EOS_RTC_AddNotifyDisconnected(HRTC, &Options, nullptr, RTC_AddNotifyDisconnected);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL RTC_AddNotifyParticipantStatusChanged(const EOS_RTC_ParticipantStatusChangedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_add_notify_participant_status_changed");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddDouble(map, "participant_in_blocklist", data->bParticipantInBlocklist?1.0:0.0);
	DsMapAddString(map, "participant_id", productID_toString(data->ParticipantId));
	DsMapAddDouble(map, "participant_status", (double)data->ParticipantStatus);
	
	RValue ParticipantMetadataArray{};
	YYCreateArray(&ParticipantMetadataArray);
	for (uint32_t i = 0; i < data->ParticipantMetadataCount; ++i)
	{
		RValue Metadata{};
		YYStructCreate(&Metadata);

		const auto& metadata = data->ParticipantMetadata[i];

		YYStructAddString(&Metadata, "key", metadata.Key);
		YYStructAddString(&Metadata, "value", metadata.Value);

		SET_RValue(&ParticipantMetadataArray, &Metadata, nullptr, i);
	}

	DsMapAddRValue(map, "metadata", &ParticipantMetadataArray);
	
	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_rtc_add_notify_participant_status_changed(char* local_user_id,char* room_name,char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, -1);

	EOS_RTC_AddNotifyParticipantStatusChangedOptions Options = {0};
	Options.ApiVersion = EOS_RTC_ADDNOTIFYPARTICIPANTSTATUSCHANGED_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RoomName = room_name;

	uint64_t notificationId = EOS_RTC_AddNotifyParticipantStatusChanged(HRTC, &Options, nullptr, RTC_AddNotifyParticipantStatusChanged);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL RTC_AddNotifyRoomStatisticsUpdated(const EOS_RTC_RoomStatisticsUpdatedInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_add_notify_room_statistics_updated");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddString(map, "statistic", data->Statistic);

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_rtc_add_notify_room_statistics_updated(char* local_user_id,char* room_name,char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, -1);

	EOS_RTC_AddNotifyRoomStatisticsUpdatedOptions Options = {0};
	Options.ApiVersion = EOS_RTC_ADDNOTIFYROOMSTATISTICSUPDATED_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RoomName = room_name;

	uint64_t notificationId = EOS_RTC_AddNotifyRoomStatisticsUpdated(HRTC, &Options, nullptr, RTC_AddNotifyRoomStatisticsUpdated);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL RTC_BlockParticipant(const EOS_RTC_BlockParticipantCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_block_participant");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "participant_id", productID_toString(data->ParticipantId));
	DsMapAddDouble(map, "blocked", data->bBlocked ? 1.0 : 0.0);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_rtc_block_participant(double blocked,char* local_user_id,char* participant_id,char* room_name)
{
	eos_not_init_return(-1);

	callback *mcallback = getCallbackData();
	EOS_RTC_BlockParticipantOptions Options = {0};
	Options.ApiVersion = EOS_RTC_BLOCKPARTICIPANT_API_LATEST;
	Options.bBlocked = blocked > 0.5;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.ParticipantId = EOS_ProductUserId_FromString(participant_id);
	Options.RoomName = room_name;
	EOS_RTC_BlockParticipant(HRTC, &Options, mcallback, RTC_BlockParticipant);
	return mcallback->identifier;
}

//func double eos_rtc_get_audio_interface()
//{
//	auto HRTCAudio = EOS_RTC_GetAudioInterface(HRTC);
//
//	return 0.0;
// }
//
//func double eos_rtc_get_data_interface()
//{
//	EOS_HRTCData HRTCData = EOS_RTC_GetDataInterface(HRTC);
//	return 0.0;
//}

void EOS_CALL RTC_JoinRoom(const EOS_RTC_JoinRoomCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_join_room");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);

	RValue RoomOptionsArray{};
	YYCreateArray(&RoomOptionsArray);
	for (uint32_t i = 0; i < data->RoomOptionsCount; ++i)
	{
		RValue Option{};
		YYStructCreate(&Option);

		const auto& option = data->RoomOptions[i];

		YYStructAddString(&Option, "key", option.Key);
		YYStructAddString(&Option, "value", option.Value);

		SET_RValue(&RoomOptionsArray, &Option, nullptr, i);
	}

	DsMapAddRValue(map, "options", &RoomOptionsArray);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double __eos_rtc_join_room(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	char* local_user_id = (char* )YYGetString(args[0]);
	char* room_name = (char* )YYGetString(args[1]);
	char* participant_id = (char* )YYGetString(args[2]);
	char* ParticipantToken = (char* )YYGetString(args[3]);
	bool bManualAudioInputEnabled = YYGetBool(args[4]);
	bool bManualAudioOutputEnabled = YYGetBool(args[5]);
	char* ClientBaseUrl = (char* )YYGetString(args[6]);
	uint32_t Flags = YYGetUint32(args[7]);

	EOS_RTC_JoinRoomOptions Options = {};
	Options.ApiVersion = EOS_RTC_BLOCKPARTICIPANT_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RoomName = room_name;
	Options.ParticipantId = strcmp(participant_id, "") == 0 ? nullptr : EOS_ProductUserId_FromString(participant_id);
	Options.ParticipantToken = ParticipantToken;
	Options.bManualAudioInputEnabled = bManualAudioInputEnabled;
	Options.bManualAudioOutputEnabled = bManualAudioOutputEnabled;
	Options.ClientBaseUrl = ClientBaseUrl;
	Options.Flags = Flags;

	callback *mcallback = getCallbackData();
	EOS_RTC_JoinRoom(HRTC, &Options, mcallback, RTC_JoinRoom);
	return mcallback->identifier;
}

void EOS_CALL RTC_LeaveRoom(const EOS_RTC_LeaveRoomCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_leave_room");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);

	CreateAsyncEventWithDSMap(map, 70);
}

func double eos_rtc_leave_room(char* local_user_id,char* room_name)
{
	eos_not_init_return(-1);

	EOS_RTC_LeaveRoomOptions Options = {0};
	Options.ApiVersion = EOS_RTC_LEAVEROOM_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RoomName = room_name;

	callback *mcallback = getCallbackData();
	EOS_RTC_LeaveRoom(HRTC, &Options, mcallback, RTC_LeaveRoom);
	return mcallback->identifier;
}

func double __eos_rtc_remove_notify_disconnected(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTC_RemoveNotifyDisconnected(HRTC, InId);

	return 0.0;
}

func double __eos_rtc_remove_notify_participant_status_changed(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTC_RemoveNotifyParticipantStatusChanged(HRTC, InId);

	return 0.0;
}

func double __eos_rtc_remove_notify_room_statistics_updated(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTC_RemoveNotifyRoomStatisticsUpdated(HRTC, InId);

	return 0.0;
}

func double eos_rtc_set_room_setting(char* local_user_id,char* room_name,char* setting_name,char* setting_value)
{
	eos_not_init_return(-1);

	EOS_RTC_SetRoomSettingOptions Options = {0};
	Options.ApiVersion = EOS_RTC_SETROOMSETTING_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RoomName = room_name;
	Options.SettingName = setting_name;
	Options.SettingValue = setting_value;
	EOS_EResult result = EOS_RTC_SetRoomSetting(HRTC, &Options);

	return (double)result;
}

func double eos_rtc_set_setting(char* setting_name,char* setting_value)
{
	eos_not_init_return(-1);

	EOS_RTC_SetSettingOptions Options = {0};
	Options.ApiVersion = EOS_RTC_SETSETTING_API_LATEST;
	Options.SettingName = setting_name;
	Options.SettingValue = setting_value;
	EOS_EResult result = EOS_RTC_SetSetting(HRTC, &Options);

	return (double)result;
}

func double eos_rtc_admin_copy_user_token_by_index(double query_id, double user_token_index)
{
	eos_not_init_return(-1);

	EOS_RTCAdmin_CopyUserTokenByIndexOptions Options = {0};
	Options.ApiVersion = EOS_RTCADMIN_COPYUSERTOKENBYINDEX_API_LATEST;
	Options.QueryId = (uint32_t)query_id;
	Options.UserTokenIndex = (uint32_t)user_token_index;

	EOS_RTCAdmin_UserToken* OutUserToken = {0};
	EOS_EResult result = EOS_RTCAdmin_CopyUserTokenByIndex(HRTCAdmin, &Options, &OutUserToken);

	return (double)result;
}

func double __eos_rtc_admin_copy_user_token_by_user_id(double query_id,char* target_user_id)
{
	eos_not_init_return(-1);

	EOS_RTCAdmin_CopyUserTokenByUserIdOptions Options = {0};
	Options.ApiVersion = EOS_RTCADMIN_COPYUSERTOKENBYUSERID_API_LATEST;
	Options.QueryId = (uint32_t)query_id;
	Options.TargetUserId = EOS_ProductUserId_FromString(target_user_id);

	EOS_RTCAdmin_UserToken* OutUserToken = { 0 };
	EOS_EResult result = EOS_RTCAdmin_CopyUserTokenByUserId(HRTCAdmin, &Options, &OutUserToken);

	return (double)result;
}

void EOS_CALL RTCAdmin_Kick(const EOS_RTCAdmin_KickCompleteCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_admin_kick");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_rtc_admin_kick(char* room_name,char* target_user_id)
{
	eos_not_init_return(-1);

	EOS_RTCAdmin_KickOptions Options = {0};
	Options.ApiVersion = EOS_RTCADMIN_KICK_API_LATEST;
	Options.RoomName = room_name;
	Options.TargetUserId = EOS_ProductUserId_FromString(target_user_id);

	callback *mcallback = getCallbackData();
	EOS_RTCAdmin_Kick(HRTCAdmin, &Options, mcallback, RTCAdmin_Kick);
	return (double)mcallback->identifier;
}

void EOS_CALL RTCAdmin_QueryJoinRoomToken(const EOS_RTCAdmin_QueryJoinRoomTokenCompleteCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_admin_query_join_room_token");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddString(map, "client_base_url", data->ClientBaseUrl);
	DsMapAddDouble(map, "query_id", data->QueryId);
	DsMapAddDouble(map, "token_count", data->TokenCount);
	DsMapAddString(map, "room_name", data->RoomName);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double __eos_rtc_admin_query_join_room_token(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	const char* local_user_id = YYGetString(args[0]);
	const char* room_name = YYGetString(args[1]);
	auto array_ids = YYGetArray(args[2]);
	std::vector<EOS_ProductUserId> p_ids = VectorProductIdsFromVector(array_ids);
	auto array_ips = YYGetArray(args[3]);
	std::vector<const char* > p_ips = VectorStringFromVector(array_ips);

	EOS_RTCAdmin_QueryJoinRoomTokenOptions Options = {0};
	Options.ApiVersion = EOS_RTCADMIN_QUERYJOINROOMTOKEN_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RoomName = room_name;
	Options.TargetUserIds = p_ids.data();
	Options.TargetUserIdsCount = (uint32_t)p_ids.size();
	if (p_ips.size() == 0)
		Options.TargetUserIpAddresses = nullptr;
	else
		Options.TargetUserIpAddresses = p_ips.data();

	callback *mcallback = getCallbackData();
	EOS_RTCAdmin_QueryJoinRoomToken(HRTCAdmin, &Options, mcallback, RTCAdmin_QueryJoinRoomToken);
	return (double)mcallback->identifier;
}

void EOS_CALL RTCAdmin_SetParticipantHardMute(const EOS_RTCAdmin_SetParticipantHardMuteCompleteCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_admin_set_participant_hard_mute");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_rtc_admin_set_participant_hard_mute(double mute, char* room_name, char* target_user_id)
{
	eos_not_init_return(-1);

	EOS_RTCAdmin_SetParticipantHardMuteOptions Options = {0};
	Options.ApiVersion = EOS_RTCADMIN_SETPARTICIPANTHARDMUTE_API_LATEST;
	Options.bMute = mute > 0.5;
	Options.RoomName = room_name;
	Options.TargetUserId = EOS_ProductUserId_FromString(target_user_id);

	callback *mcallback = getCallbackData();
	EOS_RTCAdmin_SetParticipantHardMute(HRTCAdmin, &Options, mcallback, RTCAdmin_SetParticipantHardMute);
	return (double)mcallback->identifier;
}

//func double eos_rtc_admin_user_token_release()
//{
//	EOS_RTCAdmin_UserToken_Release(OutUserToken);
//	return 0.0;
//}

void EOS_CALL RTCAudio_AddNotifyAudioBeforeRender(const EOS_RTCAudio_AudioBeforeRenderCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_audio_add_notify_audio_before_render");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddString(map, "participant_id", productID_toString(data->ParticipantId));

	if (auto buffer = data->Buffer)
	{
		DsMapAddDouble(map, "sample_rate", buffer->SampleRate);
		DsMapAddDouble(map, "channels", buffer->Channels);
		DsMapAddDouble(map, "frame_count", buffer->FramesCount);

		int buff = CreateBuffer(buffer->FramesCount * sizeof(int16_t), eBuffer_Format_Fixed, 1);
		BufferWriteContent(buff, 0, buffer->Frames, buffer->FramesCount * sizeof(int16_t));

		CreateAsyncEventWithDSMapAndBuffer(map, buff, 70);
	}
	else 
	{
		CreateAsyncEventWithDSMap(map, 70);
	}
}

func double __eos_rtc_audio_add_notify_audio_before_render(char* local_user_id,char* room_name, double unmixed_audio,char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, -1);

	EOS_RTCAudio_AddNotifyAudioBeforeRenderOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_ADDNOTIFYAUDIOBEFORERENDER_API_LATEST;
	Options.bUnmixedAudio = unmixed_audio > 0.5;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RoomName = room_name;

	uint64_t notificationId = EOS_RTCAudio_AddNotifyAudioBeforeRender(HRTCAudio, &Options, nullptr, RTCAudio_AddNotifyAudioBeforeRender);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL RTCAudio_AddNotifyAudioBeforeSend(const EOS_RTCAudio_AudioBeforeSendCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_audio_add_notify_audio_before_send");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);

	if (auto buffer = data->Buffer)
	{
		DsMapAddDouble(map, "sample_rate", buffer->SampleRate);
		DsMapAddDouble(map, "channels", buffer->Channels);
		DsMapAddDouble(map, "frame_count", buffer->FramesCount);

		int buff = CreateBuffer(buffer->FramesCount * sizeof(int16_t), eBuffer_Format_Fixed, 1);
		BufferWriteContent(buff, 0, buffer->Frames, buffer->FramesCount * sizeof(int16_t));

		CreateAsyncEventWithDSMapAndBuffer(map, buff, 70);
	}
	else
	{
		CreateAsyncEventWithDSMap(map, 70);
	}
}

func double __eos_rtc_audio_add_notify_audio_before_send(char* local_user_id,char* room_name,char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, -1);

	EOS_RTCAudio_AddNotifyAudioBeforeSendOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_ADDNOTIFYAUDIOBEFORESEND_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RoomName = room_name;

	uint64_t notificationId = EOS_RTCAudio_AddNotifyAudioBeforeSend(HRTCAudio, &Options, nullptr, RTCAudio_AddNotifyAudioBeforeSend);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL RTCAudio_AddNotifyAudioDevicesChanged(const EOS_RTCAudio_AudioDevicesChangedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_audio_add_notify_audio_devices_changed");
	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_rtc_audio_add_notify_audio_devices_changed(char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, -1);

	EOS_RTCAudio_AddNotifyAudioDevicesChangedOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_ADDNOTIFYAUDIODEVICESCHANGED_API_LATEST;

	uint64_t notificationId = EOS_RTCAudio_AddNotifyAudioDevicesChanged(HRTCAudio, &Options, nullptr, RTCAudio_AddNotifyAudioDevicesChanged);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL RTCAudio_AddNotifyAudioInputState(const EOS_RTCAudio_AudioInputStateCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_audio_add_notify_audio_input_state");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddDouble(map, "status", (double)data->Status);

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_rtc_audio_add_notify_audio_input_state(char* local_user_id,char* room_name,char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, -1);

	EOS_RTCAudio_AddNotifyAudioInputStateOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_ADDNOTIFYAUDIOINPUTSTATE_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RoomName = room_name;

	uint64_t notificationId = EOS_RTCAudio_AddNotifyAudioInputState(HRTCAudio, &Options, nullptr, RTCAudio_AddNotifyAudioInputState);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL RTCAudio_AddNotifyAudioOutputState(const EOS_RTCAudio_AudioOutputStateCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_audio_add_notify_audio_output_state");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddDouble(map, "status", (double)data->Status);

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_rtc_audio_add_notify_audio_output_state(char* local_user_id,char* room_name,char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, -1);

	EOS_RTCAudio_AddNotifyAudioOutputStateOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_ADDNOTIFYAUDIOOUTPUTSTATE_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RoomName = room_name;

	uint64_t notificationId = EOS_RTCAudio_AddNotifyAudioOutputState(HRTCAudio, &Options, nullptr, RTCAudio_AddNotifyAudioOutputState);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL RTCAudio_AddNotifyAudioOutputState(const EOS_RTCAudio_ParticipantUpdatedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_audio_add_notify_participant_updated");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddDouble(map, "speaking", data->bSpeaking);
	DsMapAddDouble(map, "audio_status", (double)data->AudioStatus);
	DsMapAddString(map, "participant_id", productID_toString(data->ParticipantId));

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_rtc_audio_add_notify_participant_updated(char* local_user_id,char* room_name,char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, -1);

	EOS_RTCAudio_AddNotifyParticipantUpdatedOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_ADDNOTIFYPARTICIPANTUPDATED_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RoomName = room_name;

	uint64_t notificationId = EOS_RTCAudio_AddNotifyParticipantUpdated(HRTCAudio, &Options, nullptr, RTCAudio_AddNotifyAudioOutputState);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

func double __eos_rtc_audio_copy_input_device_information_by_index(double device_index,char* buff_ret)
{
	eos_not_init_return(-1);

	StructStream _struct = {};
	eos_not_init_return_buffer(buff_ret, _struct);

	EOS_RTCAudio_CopyInputDeviceInformationByIndexOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_COPYINPUTDEVICEINFORMATIONBYINDEX_API_LATEST;
	Options.DeviceIndex = (uint32_t)device_index;

	EOS_RTCAudio_InputDeviceInformation* OutInputDeviceInformation;
	EOS_EResult result = EOS_RTCAudio_CopyInputDeviceInformationByIndex(HRTCAudio, &Options, &OutInputDeviceInformation);

	_struct.addKeyValue("default_device", (double)OutInputDeviceInformation->bDefaultDevice?1.0:0.0);
	_struct.addKeyValue("device_id", OutInputDeviceInformation->DeviceId);
	_struct.addKeyValue("device_name", OutInputDeviceInformation->DeviceName);

	_struct.writeTo(buff_ret);

	EOS_RTCAudio_InputDeviceInformation_Release(OutInputDeviceInformation);

	return (double)result;
}

func double __eos_rtc_audio_copy_output_device_information_by_index(double device_index,char* buff_ret)
{
	eos_not_init_return(-1);

	StructStream _struct = {};
	eos_not_init_return_buffer(buff_ret, _struct);

	EOS_RTCAudio_CopyOutputDeviceInformationByIndexOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_COPYOUTPUTDEVICEINFORMATIONBYINDEX_API_LATEST;
	Options.DeviceIndex = (uint32_t)device_index;

	EOS_RTCAudio_OutputDeviceInformation* OutOutputDeviceInformation;

	EOS_RTCAudio_CopyOutputDeviceInformationByIndex(HRTCAudio, &Options, &OutOutputDeviceInformation);

	_struct.addKeyValue("default_device", (double)OutOutputDeviceInformation->bDefaultDevice ? 1.0 : 0.0);
	_struct.addKeyValue("device_id", OutOutputDeviceInformation->DeviceId);
	_struct.addKeyValue("device_name", OutOutputDeviceInformation->DeviceName);

	_struct.writeTo(buff_ret);

	EOS_RTCAudio_OutputDeviceInformation_Release(OutOutputDeviceInformation);

	return 0.0;
}

EOS_RTCAudio_AudioInputDeviceInfo *AudioInputDeviceInfo;
func double eos_rtc_audio_get_audio_input_device_by_index(double device_info_index)
{
	eos_not_init_return(-1);

	EOS_RTCAudio_GetAudioInputDeviceByIndexOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_GETAUDIOINPUTDEVICEBYINDEX_API_LATEST;
	Options.DeviceInfoIndex = (uint32_t)device_info_index;

	AudioInputDeviceInfo = (EOS_RTCAudio_AudioInputDeviceInfo *)EOS_RTCAudio_GetAudioInputDeviceByIndex(HRTCAudio, &Options);

	return 0.0;
}

func double eos_rtc_audio_get_audio_input_devices_count()
{
	eos_not_init_return(-1);

	EOS_RTCAudio_GetAudioInputDevicesCountOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_GETAUDIOINPUTDEVICESCOUNT_API_LATEST;

	return EOS_RTCAudio_GetAudioInputDevicesCount(HRTCAudio, &Options);
}

func double eos_rtc_audio_get_audio_output_device_by_index(double device_info_index)
{
	eos_not_init_return(-1);

	EOS_RTCAudio_GetAudioOutputDeviceByIndexOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_GETAUDIOOUTPUTDEVICEBYINDEX_API_LATEST;
	Options.DeviceInfoIndex = (uint32_t)device_info_index;
	EOS_RTCAudio_GetAudioOutputDeviceByIndex(HRTCAudio, &Options);
	return 0.0;
}

func double eos_rtc_audio_get_audio_output_devices_count()
{
	eos_not_init_return(-1);

	EOS_RTCAudio_GetAudioOutputDevicesCountOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_GETAUDIOOUTPUTDEVICESCOUNT_API_LATEST;

	return EOS_RTCAudio_GetAudioOutputDevicesCount(HRTCAudio, &Options);
}

func double eos_rtc_audio_get_input_devices_count()
{
	eos_not_init_return(-1);

	EOS_RTCAudio_GetInputDevicesCountOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_GETINPUTDEVICESCOUNT_API_LATEST;

	return EOS_RTCAudio_GetInputDevicesCount(HRTCAudio, &Options);
}

func double eos_rtc_audio_get_output_devices_count()
{
	eos_not_init_return(-1);

	EOS_RTCAudio_GetOutputDevicesCountOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_GETOUTPUTDEVICESCOUNT_API_LATEST;
	return EOS_RTCAudio_GetOutputDevicesCount(HRTCAudio, &Options);
}

//func double eos_rtc_audio_input_device_information_release()
//{
//	eos_not_init_return(-1);
//
//	EOS_RTCAudio_InputDeviceInformation_Release(OutInputDeviceInformation);
//	return 0.0;
//}

//func double eos_rtc_audio_output_device_information_release()
//{
//	eos_not_init_return(-1);
//
//	EOS_RTCAudio_OutputDeviceInformation_Release(OutOutputDeviceInformation);
//	return 0.0;
//}

void EOS_CALL RTCAudio_QueryInputDevicesInformation(const EOS_RTCAudio_OnQueryInputDevicesInformationCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_audio_query_input_devices_information");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_rtc_audio_query_input_devices_information()
{
	eos_not_init_return(-1);

	EOS_RTCAudio_QueryInputDevicesInformationOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_QUERYINPUTDEVICESINFORMATION_API_LATEST;

	callback *mcallback = getCallbackData();
	EOS_RTCAudio_QueryInputDevicesInformation(HRTCAudio, &Options, mcallback, RTCAudio_QueryInputDevicesInformation);

	return mcallback->identifier;
}

void EOS_CALL RTCAudio_QueryOutputDevicesInformation(const EOS_RTCAudio_OnQueryOutputDevicesInformationCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_audio_query_output_devices_information");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_rtc_audio_query_output_devices_information()
{
	eos_not_init_return(-1);

	EOS_RTCAudio_QueryOutputDevicesInformationOptions Options = {};
	callback *mcallback = getCallbackData();
	EOS_RTCAudio_QueryOutputDevicesInformation(HRTCAudio, &Options, mcallback, RTCAudio_QueryOutputDevicesInformation);

	return mcallback->identifier;
}

func double eos_rtc_audio_register_platform_audio_user(char* user_id)
{
	eos_not_init_return(-1);

	EOS_RTCAudio_RegisterPlatformAudioUserOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_REGISTERPLATFORMAUDIOUSER_API_LATEST;
	Options.UserId = user_id;

	EOS_EResult result = EOS_RTCAudio_RegisterPlatformAudioUser(HRTCAudio, &Options);

	return (double)result;
}

func double eos_rtc_audio_register_platform_user(char* user_id)
{
	eos_not_init_return(-1);

	EOS_RTCAudio_RegisterPlatformAudioUserOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_REGISTERPLATFORMAUDIOUSER_API_LATEST;
	Options.UserId = user_id;
	EOS_EResult result = EOS_RTCAudio_RegisterPlatformAudioUser(HRTCAudio, &Options);

	return (double)result;
}

func double __eos_rtc_audio_remove_notify_audio_before_render(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTCAudio_RemoveNotifyAudioBeforeRender(HRTCAudio, InId);

	return 0.0;
}

func double __eos_rtc_audio_remove_notify_audio_before_send(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTCAudio_RemoveNotifyAudioBeforeSend(HRTCAudio, InId);

	return 0.0;
}

func double __eos_rtc_audio_remove_notify_audio_devices_changed(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTCAudio_RemoveNotifyAudioDevicesChanged(HRTCAudio, InId);

	return 0.0;
}

func double __eos_rtc_audio_remove_notify_audio_input_state(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTCAudio_RemoveNotifyAudioInputState(HRTCAudio, InId);

	return 0.0;
}

func double __eos_rtc_audio_remove_notify_audio_output_state(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTCAudio_RemoveNotifyAudioOutputState(HRTCAudio, InId);

	return 0.0;
}

func double __eos_rtc_audio_remove_notify_participant_updated(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTCAudio_RemoveNotifyParticipantUpdated(HRTCAudio, InId);

	return 0.0;
}

func double __eos_rtc_audio_send_audio(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	uint32_t Channels = YYGetUint32(args[0]);
	uint32_t FramesCount = YYGetUint32(args[1]);

	uint32_t buffer_size;
	void* Frames = YYGetBuffer(args[2], buffer_size);

	if (FramesCount > buffer_size)
	{
		return (double)EOS_EResult::EOS_InvalidParameters;
	}

	uint32_t SampleRate = YYGetUint32(args[3]);
	char* local_user_id = (char* )YYGetString(args[4]);
	char* room_name = (char* )YYGetString(args[5]);

	EOS_RTCAudio_SendAudioOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_SENDAUDIO_API_LATEST;
	Options.Buffer->ApiVersion = EOS_RTCAUDIO_AUDIOBUFFER_API_LATEST;
	Options.Buffer->Channels = Channels;
	Options.Buffer->Frames = (int16_t *)Frames;
	Options.Buffer->FramesCount = FramesCount;
	Options.Buffer->SampleRate = SampleRate;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RoomName = room_name;
	EOS_EResult result = EOS_RTCAudio_SendAudio(HRTCAudio, &Options);

	return (double)result;
}

func double eos_rtc_audio_set_audio_input_settings(double platform_aec,char* device_id,char* local_user_id, double volume)
{
	eos_not_init_return(-1);

	EOS_RTCAudio_SetAudioInputSettingsOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_SETAUDIOINPUTSETTINGS_API_LATEST;
	Options.bPlatformAEC = platform_aec > 0.5;
	Options.DeviceId = device_id;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.Volume = (float)volume;
	EOS_EResult result = EOS_RTCAudio_SetAudioInputSettings(HRTCAudio, &Options);

	return (double)result;
}

func double eos_rtc_audio_set_audio_output_settings(char* device_id,char* local_user_id, double volume)
{
	eos_not_init_return(-1);

	EOS_RTCAudio_SetAudioOutputSettingsOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_SETAUDIOOUTPUTSETTINGS_API_LATEST;
	Options.DeviceId = device_id;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.Volume = (float)volume;
	EOS_EResult result = EOS_RTCAudio_SetAudioOutputSettings(HRTCAudio, &Options);
	return (double)result;
}

void EOS_CALL Sessions_OnSendInviteCallback(const EOS_RTCAudio_OnSetInputDeviceSettingsCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_audio_set_input_device_settings");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "real_device_id", data->RealDeviceId);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_rtc_audio_set_input_device_settings(double platform_aec,char* local_user_id,char* real_device_id)
{
	eos_not_init_return(-1);

	EOS_RTCAudio_SetInputDeviceSettingsOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_SETINPUTDEVICESETTINGS_API_LATEST;
	Options.bPlatformAEC = platform_aec > 0.5;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RealDeviceId = real_device_id;

	callback *mcallback = getCallbackData();
	EOS_RTCAudio_SetInputDeviceSettings(HRTCAudio, &Options, mcallback, Sessions_OnSendInviteCallback);

	return (double)mcallback->identifier;
}

void EOS_CALL RTCAudio_SetOutputDeviceSettings(const EOS_RTCAudio_OnSetOutputDeviceSettingsCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_audio_set_output_device_settings");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "real_device_id", data->RealDeviceId);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_rtc_audio_set_output_device_settings(char* local_user_id,char* real_device_id)
{
	eos_not_init_return(-1);

	EOS_RTCAudio_SetOutputDeviceSettingsOptions Options = {};
	Options.ApiVersion = EOS_RTCAUDIO_SETOUTPUTDEVICESETTINGS_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RealDeviceId = real_device_id;

	callback *mcallback = getCallbackData();
	EOS_RTCAudio_SetOutputDeviceSettings(HRTCAudio, &Options, mcallback, RTCAudio_SetOutputDeviceSettings);
	return (double)mcallback->identifier;
}

func double eos_rtc_audio_unregister_platform_audio_user(char* user_id)
{
	eos_not_init_return(-1);

	EOS_RTCAudio_UnregisterPlatformAudioUserOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_UNREGISTERPLATFORMAUDIOUSER_API_LATEST;
	Options.UserId = user_id;
	EOS_EResult result = EOS_RTCAudio_UnregisterPlatformAudioUser(HRTCAudio, &Options);

	return (double)result;
}

void EOS_CALL RTCAudio_UnregisterPlatformUser(const EOS_RTCAudio_OnUnregisterPlatformUserCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_audio_unregister_platform_user");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "platform_user_id", data->PlatformUserId);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_rtc_audio_unregister_platform_user(char* platform_user_id)
{
	eos_not_init_return(-1);

	EOS_RTCAudio_UnregisterPlatformUserOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_UNREGISTERPLATFORMUSER_API_LATEST;
	Options.PlatformUserId = platform_user_id;

	callback *mcallback = getCallbackData();
	EOS_RTCAudio_UnregisterPlatformUser(HRTCAudio, &Options, mcallback, RTCAudio_UnregisterPlatformUser);
	return mcallback->identifier;
}

void EOS_CALL RTCAudio_UpdateParticipantVolume(const EOS_RTCAudio_UpdateParticipantVolumeCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_audio_unregister_platform_user");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "participant_id", productID_toString(data->ParticipantId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddDouble(map, "volume", data->Volume);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_rtc_audio_update_participant_volume(char* local_user_id,char* participant_id,char* room_name, double volume)
{
	eos_not_init_return(-1);

	EOS_RTCAudio_UpdateParticipantVolumeOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_UPDATEPARTICIPANTVOLUME_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.ParticipantId = strcmp(participant_id, "") == 0 ? nullptr : EOS_ProductUserId_FromString(participant_id);
	Options.RoomName = room_name;
	Options.Volume = (float)volume;

	callback *mcallback = getCallbackData();
	EOS_RTCAudio_UpdateParticipantVolume(HRTCAudio, &Options, mcallback, RTCAudio_UpdateParticipantVolume);
	return mcallback->identifier;
}

void EOS_CALL RTCAudio_UpdateReceiving(const EOS_RTCAudio_UpdateReceivingCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_audio_update_receiving");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "participant_id", productID_toString(data->ParticipantId));
	DsMapAddString(map, "status_message", data->RoomName);
	DsMapAddDouble(map, "audio_enabled", data->bAudioEnabled ? 1.0 : 0.0);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_rtc_audio_update_receiving(char* local_user_id,char* participant_id,char* room_name, double audio_enabled)
{
	eos_not_init_return(-1);

	EOS_RTCAudio_UpdateReceivingOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_UPDATERECEIVING_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.ParticipantId = strcmp(participant_id, "") == 0 ? nullptr : EOS_ProductUserId_FromString(participant_id);
	Options.RoomName = room_name;
	Options.bAudioEnabled = audio_enabled > 0.5;

	callback *mcallback = getCallbackData();

	EOS_RTCAudio_UpdateReceiving(HRTCAudio, &Options, mcallback, RTCAudio_UpdateReceiving);

	return mcallback->identifier;
}

void EOS_CALL RTCAudio_UpdateReceivingVolume(const EOS_RTCAudio_UpdateReceivingVolumeCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_audio_update_receiving_volume");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddDouble(map, "volume", data->Volume);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_rtc_audio_update_receiving_volume(char* local_user_id,char* room_name, double volume)
{
	eos_not_init_return(-1);

	EOS_RTCAudio_UpdateReceivingVolumeOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_UPDATERECEIVINGVOLUME_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RoomName = room_name;
	Options.Volume = (float)volume;

	callback *mcallback = getCallbackData();
	EOS_RTCAudio_UpdateReceivingVolume(HRTCAudio, &Options, mcallback, RTCAudio_UpdateReceivingVolume);

	return mcallback->identifier;
}

void EOS_CALL RTCAudio_UpdateSending(const EOS_RTCAudio_UpdateSendingCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_audio_update_sending");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddDouble(map, "audio_status", (double)data->AudioStatus);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_rtc_audio_update_sending(char* local_user_id,char* room_name, double audio_status)
{
	eos_not_init_return(-1);

	EOS_RTCAudio_UpdateSendingOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_UPDATESENDING_API_LATEST;
	Options.AudioStatus = (EOS_ERTCAudioStatus)audio_status;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RoomName = room_name;

	callback *mcallback = getCallbackData();
	EOS_RTCAudio_UpdateSending(HRTCAudio, &Options, mcallback, RTCAudio_UpdateSending);
	return (double)mcallback->identifier;

	return 0.0;
}

void EOS_CALL RTCAudio_UpdateSendingVolume(const EOS_RTCAudio_UpdateSendingVolumeCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_audio_update_sending_volume");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddDouble(map, "volume", data->Volume);
	
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_rtc_audio_update_sending_volume(char* local_user_id,char* room_name, double volume)
{
	eos_not_init_return(-1);

	EOS_RTCAudio_UpdateSendingVolumeOptions Options = {0};
	Options.ApiVersion = EOS_RTCAUDIO_UPDATESENDINGVOLUME_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RoomName = room_name;
	Options.Volume = (float)volume;

	callback *mcallback = getCallbackData();
	EOS_RTCAudio_UpdateSendingVolume(HRTCAudio, &Options, mcallback, RTCAudio_UpdateSendingVolume);

	return (double)mcallback->identifier;
}

void EOS_CALL RTCData_AddNotifyDataReceived(const EOS_RTCData_DataReceivedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_data_add_notify_data_received");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddString(map, "participant_id", productID_toString(data->ParticipantId));

	if (data->Data)
	{
		DsMapAddDouble(map, "data_length", data->DataLengthBytes);

		int buff = CreateBuffer(data->DataLengthBytes, eBuffer_Format_Fixed, 1);
		BufferWriteContent(buff, 0, data->Data, data->DataLengthBytes);

		CreateAsyncEventWithDSMapAndBuffer(map, buff, 70);
	}
	else
	{
		CreateAsyncEventWithDSMap(map, 70);
	}
}

func double __eos_rtc_data_add_notify_data_received(char* local_user_id,char* room_name,char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, -1);

	EOS_RTCData_AddNotifyDataReceivedOptions Options = {0};
	Options.ApiVersion = EOS_RTCDATA_ADDNOTIFYDATARECEIVED_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RoomName = room_name;

	uint64_t notificationId = EOS_RTCData_AddNotifyDataReceived(HRTCData, &Options, nullptr, RTCData_AddNotifyDataReceived);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

void EOS_CALL RTCData_AddNotifyDataReceived(const EOS_RTCData_ParticipantUpdatedCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_data_add_notify_participant_updated");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddString(map, "participant_id", productID_toString(data->ParticipantId));
	DsMapAddDouble(map, "data_status", (double)data->DataStatus);

	CreateAsyncEventWithDSMap(map, 70);
}

func double __eos_rtc_data_add_notify_participant_updated(char* local_user_id,char* room_name,char* buff_ret)
{
	eos_not_init_return_buffer(buff_ret, -1);

	EOS_RTCData_AddNotifyParticipantUpdatedOptions Options = {0};
	Options.ApiVersion = EOS_RTCDATA_ADDNOTIFYPARTICIPANTUPDATED_API_LATEST;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RoomName = room_name;

	uint64_t notificationId = EOS_RTCData_AddNotifyParticipantUpdated(HRTCData, &Options, nullptr, RTCData_AddNotifyDataReceived);

	DataStream data;
	data << notificationId;
	data.writeTo(buff_ret);

	return 0.0;
}

func double __eos_rtc_data_remove_notify_data_received(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTCData_RemoveNotifyDataReceived(HRTCData, InId);

	return 0.0;
}

func double __eos_rtc_data_remove_notify_participant_updated(char* buff_args)
{
	eos_not_init_return(-1);

	auto args = buffer_unpack((uint8_t *)buff_args);
	EOS_NotificationId InId = YYGetUint64(args[0]);

	EOS_RTCData_RemoveNotifyParticipantUpdated(HRTCData, InId);

	return 0.0;
}

func double __eos_rtc_data_send_data(char* buff_data, double length,char* local_user_id,char* room_name)
{
	eos_not_init_return(-1);

	EOS_RTCData_SendDataOptions Options = {0};
	Options.ApiVersion;
	Options.Data = buff_data;
	Options.DataLengthBytes = (uint32_t)length;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RoomName = room_name;
	EOS_EResult result = EOS_RTCData_SendData(HRTCData, &Options);

	return (double)result;
}

void EOS_CALL RTCData_UpdateReceiving(const EOS_RTCData_UpdateReceivingCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_data_update_receiving");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "participant_id", productID_toString(data->ParticipantId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddDouble(map, "data_enabled", (double)data->bDataEnabled ? 1.0 : 0.0);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_rtc_data_update_receiving(char* local_user_id,char* participant_id,char* room_name, double data_enabled)
{
	eos_not_init_return(-1);

	EOS_RTCData_UpdateReceivingOptions Options = {0};
	Options.ApiVersion = EOS_RTCDATA_UPDATERECEIVING_API_LATEST;
	Options.bDataEnabled = data_enabled > 0.5;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.ParticipantId = strcmp(participant_id, "") == 0 ? nullptr : EOS_ProductUserId_FromString(participant_id);
	Options.RoomName = room_name;

	callback *mcallback = getCallbackData();
	EOS_RTCData_UpdateReceiving(HRTCData, &Options, mcallback, RTCData_UpdateReceiving);
	return (double)mcallback->identifier;
}

void EOS_CALL RTCData_UpdateSending(const EOS_RTCData_UpdateSendingCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_data_update_sending");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddDouble(map, "data_enabled", (double)data->bDataEnabled ? 1.0 : 0.0);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

func double eos_rtc_data_update_sending(char* local_user_id,char* room_name, double data_enabled)
{
	eos_not_init_return(-1);

	EOS_RTCData_UpdateSendingOptions Options = {0};
	Options.ApiVersion = EOS_RTCDATA_UPDATESENDING_API_LATEST;
	Options.bDataEnabled = data_enabled > 0.5;
	Options.LocalUserId = EOS_ProductUserId_FromString(local_user_id);
	Options.RoomName = room_name;

	callback *mcallback = getCallbackData();
	EOS_RTCData_UpdateSending(HRTCData, &Options, mcallback, RTCData_UpdateSending);
	return (double)mcallback->identifier;
}
