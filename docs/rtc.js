
RTC REFERENCE PAGE: https://dev.epicgames.com/docs/api-ref/interfaces/rtc

------------------------------------------------------------------------------------

int64 eos_rtc_add_notify_disconnected(String local_user_id, String room_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-add-notify-disconnected

ASYNC

	string -> type"eos_rtc_add_notify_disconnected");
	string -> "local_user_id"
	string -> "room_name"
	real -> "status"
	string -> "status_message"
	
------------------------------------------------------------------------------------

int64 eos_rtc_add_notify_participant_status_changed(local_user_id, room_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-add-notify-participant-status-Stringnged

ASYNC

	string -> type"eos_rtc_add_notify_participant_status_Stringnged");
	string -> "local_user_id"
	string -> "room_name"
	real -> "participant_in_blocklist"
	string -> "participant_id"
	real -> "participant_status"
	// TODO
	data->ParticipantMetadata;
	data->ParticipantMetadataCount;


------------------------------------------------------------------------------------


int64 eos_rtc_add_notify_room_statistics_updated(char* local_user_id,char* room_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-add-notify-room-statistics-updated

ASYNC

	string -> type"eos_rtc_add_notify_room_statistics_updated");
	string -> "local_user_id"
	string -> "room_name"
	string -> "statistic"


------------------------------------------------------------------------------------

double eos_rtc_block_participant(double blocked,char* local_user_id,char* participant_id,char* room_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-add-notify-room-statistics-updated

ASYNC

	string -> type"eos_rtc_block_participant");
	real -> "identifier"
	string -> "local_user_id"
	string -> "participant_id"
	real -> "blocked"


------------------------------------------------------------------------------------

// double eos_rtc_get_audio_interface()
//{
//	HRTCAudio = EOS_RTC_GetAudioInterface(HRTC);
//	return 0.0;
// }

// double eos_rtc_get_data_interface()
//{
//	EOS_HRTCData HRTCData = EOS_RTC_GetDataInterface(HRTC);
//	return 0.0;
// }


------------------------------------------------------------------------------------

double eos_rtc_join_room(string local_user_id, String room_name,String participant_id, String participant_token, bool manual_audio_input_enabled, bool manual_audio_output_enabled, String client_base_url, flags)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-join-room

ASYNC 

	string -> type"eos_rtc_join_room");
	real -> "identifier"
	string -> "local_user_id"
	string -> "room_name"
	// TODO: ARRAY of STRUCT
	// real -> "room_options_count"
	// real -> "room_options_count"

------------------------------------------------------------------------------------

double eos_rtc_leave_room(char* local_user_id,char* room_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-leave-room

	string -> type"eos_rtc_leave_room");
	real -> "identifier"
	string -> "local_user_id"
	string -> "room_name"

	// TODO: ARRAY of STRUCT
	// real -> "room_options_count"
	// real -> "room_options_count"


------------------------------------------------------------------------------------

double eos_rtc_remove_notify_disconnected(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-remove-notify-disconnected

------------------------------------------------------------------------------------

double eos_rtc_remove_notify_participant_status_Stringnged(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-remove-notify-participant-status-Stringnged

------------------------------------------------------------------------------------

double eos_rtc_remove_notify_room_statistics_updated(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-remove-notify-room-statistics-updated

------------------------------------------------------------------------------------

double eos_rtc_set_room_setting(char* local_user_id,char* room_name,char* setting_name,char* setting_value)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-set-room-setting

------------------------------------------------------------------------------------

double eos_rtc_set_setting(char* setting_name,char* setting_value)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-set-room-setting

------------------------------------------------------------------------------------

double eos_rtc_admin_copy_user_token_by_index(double query_id, double user_token_index)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-set-room-setting

------------------------------------------------------------------------------------

double eos_rtc_admin_copy_user_token_by_user_id(double query_id,char* target_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-admin-copy-user-token-by-user-id

------------------------------------------------------------------------------------

double eos_rtc_admin_kick(char* room_name,char* target_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-admin-kick

	string -> type"eos_rtc_admin_kick");
	real -> "identifier"


------------------------------------------------------------------------------------

double eos_rtc_admin_query_join_room_token(String local_user_id,String room_name, Array buffer_string, Array array_ips)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-admin-query-join-room-token

	string -> type"eos_rtc_admin_query_join_room_token");
	real -> "identifier"
	real -> "status"
	string -> "status_message"
	string -> "client_base_url"
	real -> "query_id"
	real -> "token_count"


------------------------------------------------------------------------------------

double eos_rtc_admin_set_participant_hard_mute(double mute, char* room_name, char* target_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-admin-set-participant-hard-mute

	string -> type"eos_rtc_admin_set_participant_hard_mute");
	real -> "identifier"
	real -> "status"
	string -> "status_message"


------------------------------------------------------------------------------------

int64 eos_rtc_audio_add_notify_audio_before_render(char* local_user_id,char* room_name, bool unmixed_audio)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-add-notify-audio-before-render

ASYNC
	string -> type"eos_rtc_audio_add_notify_audio_before_render");
	string -> "local_user_id"
	string -> "room_name"
	string -> "participant_id"
	// TODO
	data->Buffer;


------------------------------------------------------------------------------------

int64 eos_rtc_audio_add_notify_audio_before_send(char* local_user_id,char* room_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-add-notify-audio-before-render

ASYNC
	string -> type"eos_rtc_audio_add_notify_audio_before_send");
	string -> "local_user_id"
	string -> "room_name"
	// TODO
	data->Buffer;


------------------------------------------------------------------------------------

int64 eos_rtc_audio_add_notify_audio_devices_changed()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-add-notify-audio-devices-Stringnged

ASYNC
	string -> type"eos_rtc_audio_add_notify_audio_devices_Stringnged");
	CreateAsyncEventWithDSMap(map


------------------------------------------------------------------------------------

int64 eos_rtc_audio_add_notify_audio_input_state(local_user_id, room_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-add-notify-audio-input-state

	string -> type"eos_rtc_audio_add_notify_audio_input_state");
	string -> "local_user_id"
	string -> "room_name"
	real -> "status"


------------------------------------------------------------------------------------

int64 eos_rtc_audio_add_notify_audio_output_state(local_user_id, room_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-add-notify-audio-output-state

ASYNC
	string -> type"eos_rtc_audio_add_notify_audio_output_state");
	string -> "local_user_id"
	string -> "room_name"
	real -> "status"


------------------------------------------------------------------------------------

int64 eos_rtc_audio_add_notify_participant_updated(local_user_id, room_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-add-notify-participant-updated

ASYNC

	string -> type"eos_rtc_audio_add_notify_participant_updated");
	string -> "local_user_id"
	string -> "room_name"
	real -> "speaking"
	real -> "audio_status"
	string -> "participant_id"


------------------------------------------------------------------------------------

Struct {default_device:bool,device_id:string,device_name:string} eos_rtc_audio_copy_input_device_information_by_index(double device_index)

https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-copy-input-device-information-by-index

------------------------------------------------------------------------------------

Struct {default_device:bool,device_id:string,device_name:string} eos_rtc_audio_copy_output_device_information_by_index(double device_index)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-copy-output-device-information-by-index

------------------------------------------------------------------------------------

double eos_rtc_audio_get_audio_input_device_by_index(double device_info_index)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-get-audio-input-device-by-index

------------------------------------------------------------------------------------

double eos_rtc_audio_get_audio_input_devices_count()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-get-audio-input-devices-count

------------------------------------------------------------------------------------

double eos_rtc_audio_get_audio_output_device_by_index(double device_info_index)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-get-audio-output-device-by-index

------------------------------------------------------------------------------------

double eos_rtc_audio_get_audio_output_devices_count()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-get-output-devices-count

------------------------------------------------------------------------------------

double eos_rtc_audio_get_input_devices_count()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-get-input-devices-count

------------------------------------------------------------------------------------

double eos_rtc_audio_get_output_devices_count()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-get-output-devices-count

------------------------------------------------------------------------------------

double eos_rtc_audio_query_input_devices_information()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-query-input-devices-information

ASYNC
	string -> type"eos_rtc_audio_query_input_devices_information");
	real -> "status"
	string -> "status_message"
	real -> "identifier"


------------------------------------------------------------------------------------

double eos_rtc_audio_query_output_devices_information()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-query-output-devices-information

ASYNC

	string -> type"eos_rtc_audio_query_output_devices_information");
	real -> "status"
	string -> "status_message"
	real -> "identifier"

------------------------------------------------------------------------------------

double eos_rtc_audio_register_platform_audio_user(String user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-register-platform-audio-user

------------------------------------------------------------------------------------

double eos_rtc_audio_register_platform_user(String user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-register-platform-user	

------------------------------------------------------------------------------------

double eos_rtc_audio_remove_notify_audio_before_render(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-remove-notify-audio-before-render

------------------------------------------------------------------------------------

double eos_rtc_audio_remove_notify_audio_before_send(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-remove-notify-audio-before-send

------------------------------------------------------------------------------------

double eos_rtc_audio_remove_notify_audio_devices_Stringnged(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-remove-notify-audio-devices-Stringnged
------------------------------------------------------------------------------------

double eos_rtc_audio_remove_notify_audio_input_state(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-remove-notify-audio-input-state
------------------------------------------------------------------------------------

double eos_rtc_audio_remove_notify_audio_output_state(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-remove-notify-audio-output-state

------------------------------------------------------------------------------------

double eos_rtc_audio_remove_notify_participant_updated(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-remove-notify-participant-updated

------------------------------------------------------------------------------------

double eos_rtc_audio_send_audio(String buff_args)


------------------------------------------------------------------------------------

double eos_rtc_audio_set_audio_input_settings(double platform_aec,char* device_id,char* local_user_id, double volume)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-set-audio-input-settings

------------------------------------------------------------------------------------

double eos_rtc_audio_set_audio_output_settings(char* device_id,char* local_user_id, double volume)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-set-audio-output-settings

------------------------------------------------------------------------------------

double eos_rtc_audio_set_input_device_settings(double platform_aec,char* local_user_id,char* real_device_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-set-input-device-settings

ASYNC

	string -> type"eos_rtc_audio_set_input_device_settings");
	real -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "real_device_id"


------------------------------------------------------------------------------------

double eos_rtc_audio_set_output_device_settings(char* local_user_id,char* real_device_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-set-output-device-settings

ASYNC
	string -> type"eos_rtc_audio_set_output_device_settings");
	real -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "real_device_id"

------------------------------------------------------------------------------------

double eos_rtc_audio_unregister_platform_audio_user(String user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-unregister-platform-audio-user


------------------------------------------------------------------------------------

double eos_rtc_audio_unregister_platform_user(String platform_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-unregister-platform-user

ASYNC
	string -> type"eos_rtc_audio_unregister_platform_user");
	real -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "platform_user_id"

------------------------------------------------------------------------------------

double eos_rtc_audio_update_participant_volume(char* local_user_id,char* participant_id,char* room_name, double volume)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-update-participant-volume

ASYNC
	string -> type"eos_rtc_audio_unregister_platform_user");
	real -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "local_user_id"
	string -> "participant_id"
	string -> "room_name"
	real -> "volume"


------------------------------------------------------------------------------------

double eos_rtc_audio_update_receiving(char* local_user_id,char* participant_id,char* room_name, double audio_enabled)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-update-receiving

ASYNC

	string -> type"eos_rtc_audio_update_receiving");
	real -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "participant_id"
	string -> "status_message"
	real -> "audio_enabled"


------------------------------------------------------------------------------------

double eos_rtc_audio_update_receiving_volume(char* local_user_id,char* room_name, double volume)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-update-receiving-volume

ASYNC

	string -> type"eos_rtc_audio_update_receiving_volume");
	real -> "status"
	string -> "status_message"
	real -> "identifier"


------------------------------------------------------------------------------------

double eos_rtc_audio_update_sending(char* local_user_id,char* room_name, double audio_status)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-update-sending
ASYNC
	string -> type"eos_rtc_audio_update_sending");
	real -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "room_name"
	string -> "local_user_id"
	real -> "audio_status"

------------------------------------------------------------------------------------

double eos_rtc_audio_update_sending_volume(char* local_user_id,char* room_name, double volume)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-update-sending-volume

ASYNC
	string -> type"eos_rtc_audio_update_sending_volume");
	real -> "status"
	string -> "status_message"
	real -> "identifier"


------------------------------------------------------------------------------------

int64 eos_rtc_data_add_notify_data_received(char* local_user_id,char* room_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-data-add-notify-data-received

ASYNC
	string -> type"eos_rtc_data_add_notify_data_received");
	string -> "local_user_id"
	string -> "room_name"
	string -> "participant_id"
	// TODO
	data->Data;
	data->DataLengthBytes;


------------------------------------------------------------------------------------

int64 eos_rtc_data_add_notify_participant_updated(char* local_user_id,char* room_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-data-add-notify-participant-updated

ASYNC
	string -> type"eos_rtc_data_add_notify_participant_updated");
	string -> "local_user_id"
	string -> "room_name"
	string -> "participant_id"
	real -> "data_status"

------------------------------------------------------------------------------------

double eos_rtc_data_remove_notify_data_received(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-data-add-notify-data-received

------------------------------------------------------------------------------------

double eos_rtc_data_remove_notify_participant_updated(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-data-remove-notify-participant-updated

------------------------------------------------------------------------------------

double eos_rtc_data_send_data(buff,Length, local_user_id, room_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-data-send-data

------------------------------------------------------------------------------------

double eos_rtc_data_update_receiving(char* local_user_id,char* participant_id,char* room_name, double data_enabled)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-data-update-receiving

ASYNC
	string -> type"eos_rtc_data_update_receiving");
	real -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "local_user_id"
	string -> "participant_id"
	string -> "room_name"
	real -> "data_enabled"

------------------------------------------------------------------------------------

double eos_rtc_data_update_sending(char* local_user_id,char* room_name, double data_enabled)
https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-data-update-sending

ASYNC
	string -> type"eos_rtc_data_update_sending");
	real -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "local_user_id"
	string -> "room_name"
	real -> "data_enabled"

------------------------------------------------------------------------------------
