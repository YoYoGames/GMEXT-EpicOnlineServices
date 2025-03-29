
	DsMapAddString(map, "type", "eos_rtc_add_notify_disconnected");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));

func double __eos_rtc_add_notify_disconnected(char* RoomName,char* LocalUserId,char* buff_ret)

	DsMapAddString(map, "type", "eos_rtc_add_notify_participant_status_changed");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddDouble(map, "participant_in_blocklist", (double)data->bParticipantInBlocklist);
	DsMapAddString(map, "participant_id", productID_toString(data->ParticipantId));
	DsMapAddDouble(map, "participant_status", (double)data->ParticipantStatus);
	// TODO
	data->ParticipantMetadata;
	data->ParticipantMetadataCount;

func double __eos_rtc_add_notify_participant_status_changed(char* LocalUserId,char* RoomName,char* buff_ret)

	DsMapAddString(map, "type", "eos_rtc_add_notify_room_statistics_updated");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddString(map, "statistic", data->Statistic);

func double __eos_rtc_add_notify_room_statistics_updated(char* LocalUserId,char* RoomName,char* buff_ret)

	DsMapAddString(map, "type", "eos_rtc_block_participant");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "participant_id", productID_toString(data->ParticipantId));
	DsMapAddDouble(map, "blocked", data->bBlocked ? 1.0 : 0.0);

func double eos_rtc_block_participant(double bBlocked,char* LocalUserId,char* ParticipantId,char* RoomName)

// func double eos_rtc_get_audio_interface()
//{
//	HRTCAudio = EOS_RTC_GetAudioInterface(HRTC);
//	return 0.0;
// }

// func double eos_rtc_get_data_interface()
//{
//	EOS_HRTCData HRTCData = EOS_RTC_GetDataInterface(HRTC);
//	return 0.0;
// }

	DsMapAddString(map, "type", "eos_rtc_join_room");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	// TODO: ARRAY of STRUCT
	// DsMapAddDouble(map, "room_options_count", data->RoomOptionsCount);
	// DsMapAddDouble(map, "room_options_count", data->RoomOptions.);

func double __eos_rtc_join_room(char* buff_args)

	DsMapAddString(map, "type", "eos_rtc_leave_room");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);

	// TODO: ARRAY of STRUCT
	// DsMapAddDouble(map, "room_options_count", data->RoomOptionsCount);
	// DsMapAddDouble(map, "room_options_count", data->RoomOptions.);

func double eos_rtc_leave_room(char* LocalUserId,char* RoomName)

func double __eos_rtc_remove_notify_disconnected(char* buff_args)

func double __eos_rtc_remove_notify_participant_status_changed(char* buff_args)

func double __eos_rtc_remove_notify_room_statistics_updated(char* buff_args)

func double eos_rtc_set_room_setting(char* LocalUserId,char* RoomName,char* SettingName,char* SettingValue)

func double eos_rtc_set_setting(char* SettingName,char* SettingValue)

func double __eos_rtc_admin_copy_user_token_by_index(double QueryId, double UserTokenIndex,char* buff_ret)

func double __eos_rtc_admin_copy_user_token_by_user_id(double QueryId,char* TargetUserId)

	DsMapAddString(map, "type", "eos_rtc_admin_kick");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

func double eos_rtc_admin_kick(char* RoomName,char* TargetUserId)

	DsMapAddString(map, "type", "eos_rtc_admin_query_join_room_token");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddString(map, "client_base_url", data->ClientBaseUrl);
	DsMapAddDouble(map, "query_id", data->QueryId);
	DsMapAddDouble(map, "token_count", data->TokenCount);

func double __eos_rtc_admin_query_join_room_token(char* buff_args)

	DsMapAddString(map, "type", "eos_rtc_admin_set_participant_hard_mute");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));

func double eos_rtc_admin_set_participant_hard_mute()

	DsMapAddString(map, "type", "eos_rtc_audio_add_notify_audio_before_render");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddString(map, "participant_id", productID_toString(data->ParticipantId));
	// TODO
	data->Buffer;

func double __eos_rtc_audio_add_notify_audio_before_render(char* LocalUserId,char* RoomName, double bUnmixedAudio,char* buff_ret)

	DsMapAddString(map, "type", "eos_rtc_audio_add_notify_audio_before_send");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	// TODO
	data->Buffer;

func double __eos_rtc_audio_add_notify_audio_before_send(char* LocalUserId,char* RoomName,char* buff_ret)

	DsMapAddString(map, "type", "eos_rtc_audio_add_notify_audio_devices_changed");
	CreateAsyncEventWithDSMap(map, 70);

func double __eos_rtc_audio_add_notify_audio_devices_changed(char* buff_ret)

	DsMapAddString(map, "type", "eos_rtc_audio_add_notify_audio_input_state");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddDouble(map, "status", (double)data->Status);

func double __eos_rtc_audio_add_notify_audio_input_state(char* LocalUserId,char* RoomName,char* buff_ret)

	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_audio_add_notify_audio_output_state");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddDouble(map, "status", (double)data->Status);

func double __eos_rtc_audio_add_notify_audio_output_state(char* LocalUserId,char* RoomName,char* buff_ret)


	DsMapAddString(map, "type", "eos_rtc_audio_add_notify_participant_updated");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddDouble(map, "speaking", data->bSpeaking);
	DsMapAddDouble(map, "audio_status", (double)data->AudioStatus);
	DsMapAddString(map, "participant_id", productID_toString(data->ParticipantId));

func double __eos_rtc_audio_add_notify_participant_updated(char* LocalUserId,char* RoomName,char* buff_ret)

func double __eos_rtc_audio_copy_input_device_information_by_index(double DeviceIndex,char* buff_ret)

func double __eos_rtc_audio_copy_output_device_information_by_index(double DeviceIndex,char* buff_ret)

EOS_RTCAudio_AudioInputDeviceInfo *AudioInputDeviceInfo;
func double eos_rtc_audio_get_audio_input_device_by_index(double DeviceInfoIndex)

func double eos_rtc_audio_get_audio_input_devices_count()

func double eos_rtc_audio_get_audio_output_device_by_index(double DeviceInfoIndex)

func double eos_rtc_audio_get_audio_output_devices_count()

func double eos_rtc_audio_get_input_devices_count()

func double eos_rtc_audio_get_output_devices_count()

	DsMapAddString(map, "type", "eos_rtc_audio_query_input_devices_information");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

func double eos_rtc_audio_query_input_devices_information()

	DsMapAddString(map, "type", "eos_rtc_audio_query_output_devices_information");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

func double eos_rtc_audio_query_output_devices_information()

func double eos_rtc_audio_register_platform_audio_user(char* UserId)

func double eos_rtc_audio_register_platform_user(char* UserId)

func double __eos_rtc_audio_remove_notify_audio_before_render(char* buff_args)

func double __eos_rtc_audio_remove_notify_audio_before_send(char* buff_args)

func double __eos_rtc_audio_remove_notify_audio_devices_changed(char* buff_args)

func double __eos_rtc_audio_remove_notify_audio_input_state(char* buff_args)

func double __eos_rtc_audio_remove_notify_audio_output_state(char* buff_args)

func double __eos_rtc_audio_remove_notify_participant_updated(char* buff_args)

func double eos_rtc_audio_send_audio(char* buff_args,char* buff_data)

func double eos_rtc_audio_set_audio_input_settings(double bPlatformAEC,char* DeviceId,char* LocalUserId, double Volume)

func double eos_rtc_audio_set_audio_output_settings(char* DeviceId,char* LocalUserId, double Volume)

	DsMapAddString(map, "type", "eos_rtc_audio_set_input_device_settings");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "real_device_id", data->RealDeviceId);

func double eos_rtc_audio_set_input_device_settings(double bPlatformAEC,char* LocalUserId,char* RealDeviceId)

	DsMapAddString(map, "type", "eos_rtc_audio_set_output_device_settings");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "real_device_id", data->RealDeviceId);

func double eos_rtc_audio_set_output_device_settings(char* LocalUserId,char* RealDeviceId)

func double eos_rtc_audio_unregister_platform_audio_user(char* UserId)

	DsMapAddString(map, "type", "eos_rtc_audio_unregister_platform_user");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "platform_user_id", data->PlatformUserId);
	CreateAsyncEventWithDSMap(map, 70);

func double eos_rtc_audio_unregister_platform_user(char* PlatformUserId)

	DsMapAddString(map, "type", "eos_rtc_audio_unregister_platform_user");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "participant_id", productID_toString(data->ParticipantId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddDouble(map, "volume", data->Volume);

func double eos_rtc_audio_update_participant_volume(char* LocalUserId,char* ParticipantId,char* RoomName, double Volume)

	DsMapAddString(map, "type", "eos_rtc_audio_update_receiving");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "participant_id", productID_toString(data->ParticipantId));
	DsMapAddString(map, "status_message", data->RoomName);
	DsMapAddDouble(map, "audio_enabled", data->bAudioEnabled ? 1.0 : 0.0);

func double eos_rtc_audio_update_receiving(char* LocalUserId,char* ParticipantId,char* RoomName, double bAudioEnabled)

	DsMapAddString(map, "type", "eos_rtc_audio_update_receiving_volume");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

func double eos_rtc_audio_update_receiving_volume(char* LocalUserId,char* RoomName, double Volume)

	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_audio_update_sending");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddDouble(map, "audio_status", (double)data->AudioStatus);
	CreateAsyncEventWithDSMap(map, 70);

func double eos_rtc_audio_update_sending(char* LocalUserId,char* RoomName, double AudioStatus)


	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_audio_update_sending_volume");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

func double eos_rtc_audio_update_sending_volume(char* LocalUserId,char* RoomName, double Volume)

	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_data_add_notify_data_received");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddString(map, "participant_id", productID_toString(data->ParticipantId));
	// TODO
	data->Data;
	data->DataLengthBytes;


func double __eos_rtc_data_add_notify_data_received(char* LocalUserId,char* RoomName,char* buff_ret)

	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_rtc_data_add_notify_participant_updated");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "room_name", data->RoomName);
	DsMapAddString(map, "participant_id", productID_toString(data->ParticipantId));
	DsMapAddDouble(map, "data_status", (double)data->DataStatus);

func double __eos_rtc_data_add_notify_participant_updated(char* LocalUserId,char* RoomName,char* buff_ret)

func double __eos_rtc_data_remove_notify_data_received(char* buff_args)

func double __eos_rtc_data_remove_notify_participant_updated(char* buff_args)

func double __eos_rtc_data_send_data(char* buff_data, double Length,char* LocalUserId,char* RoomName)

void EOS_CALL RTCData_UpdateReceiving(const EOS_RTCData_UpdateReceivingCallbackInfo *data)

func double eos_rtc_data_update_receiving(char* LocalUserId,char* ParticipantId,char* RoomName, double bDataEnabled)

void EOS_CALL RTCData_UpdateSending(const EOS_RTCData_UpdateSendingCallbackInfo *data)

func double eos_rtc_data_update_sending(char* LocalUserId,char* RoomName, double bDataEnabled)

