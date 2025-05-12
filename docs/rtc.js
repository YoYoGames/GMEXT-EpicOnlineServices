/**
 * @module rtc
 * @title RTC
 * @desc **Epic Online Services Interface**: [RTC Interface](https://dev.epicgames.com/docs/api-ref/interfaces/rtc)
 * 
 * Guides: https://dev.epicgames.com/docs/game-services/real-time-communication-interface/rtc-data-interface, https://dev.epicgames.com/docs/game-services/real-time-communication-interface/voice
 * 
 * @section_func
 * @ref eos_rtc_*
 * @section_end
 * 
 * @module_end
 */


/**
 * @func eos_rtc_add_notify_disconnected
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-add-notify-disconnected)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} room_name 
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_add_notify_disconnected"
 * @member {string} "local_user_id"
 * @member {string} "room_name"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_add_notify_participant_status_changed
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-add-notify-participant-status-changed)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} room_name 
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_add_notify_participant_status_changed"
 * @member {string} "local_user_id"
 * @member {string} "room_name"
 * @member {bool} "participant_in_blocklist"
 * @member {string} "participant_id"
 * @member {real} "participant_status"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_add_notify_room_statistics_updated
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-add-notify-room-statistics-updated)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} room_name 
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_add_notify_room_statistics_updated"
 * @member {string} "local_user_id"
 * @member {string} "room_name"
 * @member {string} "statistic"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_block_participant
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-add-notify-room-statistics-updated)
 * 
 * 
 *
 * @param {real} blocked 
 * @param {string} local_user_id 
 * @param {string} participant_id 
 * @param {string} room_name 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_block_participant"
 * @member {real} "identifier"
 * @member {string} "local_user_id"
 * @member {string} "participant_id"
 * @member {bool} "blocked"
 * @event_end
 * 
 * @func_end
 */

// real eos_rtc_get_audio_interface()
//{
//	HRTCAudio = EOS_RTC_GetAudioInterface(HRTC
//	return 0.0;
// }

// real eos_rtc_get_data_interface()
//{
//	EOS_HRTCData HRTCData = EOS_RTC_GetDataInterface(HRTC
//	return 0.0;
// }

/**
 * @func eos_rtc_join_room
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-join-room)
 * 
 *
 * 
 * @param {string} local_user_id 
 * @param {string} room_name 
 * @param {string} participant_id 
 * @param {string} participant_token 
 * @param {bool} manual_audio_input_enabled 
 * @param {bool} manual_audio_output_enabled 
 * @param {string} client_base_url 
 * @param {EOS_RTC_JOINROOMFLAGS_ENABLE_ECHO} flags 
 *
 * @returns {real}
 * 
 * @event social
 * @param {string} type the string "eos_rtc_join_room"
 * @param {real} "identifier"
 * @param {string} "local_user_id"
 * @param {string} "room_name"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_leave_room
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-leave-room)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} room_name 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_leave_room"
 * @member {real} "identifier"
 * @member {string} "local_user_id"
 * @member {string} "room_name"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_remove_notify_disconnected
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-remove-notify-disconnected)
 * 
 * 
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_remove_notify_participant_status_changed
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-remove-notify-participant-status-changed)
 * 
 * 
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_remove_notify_room_statistics_updated
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-remove-notify-room-statistics-updated)
 * 
 * 
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_set_room_setting
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-set-room-setting)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} room_name 
 * @param {string} setting_name 
 * @param {string} setting_value 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_set_setting
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-set-room-setting)
 * 
 * 
 *
 * @param {string} setting_name 
 * @param {string} setting_value 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_admin_copy_user_token_by_index
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-set-room-setting)
 * 
 * 
 *
 * @param {real} query_id 
 * @param {real} user_token_index 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_admin_copy_user_token_by_user_id
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-admin-copy-user-token-by-user-id)
 * 
 * 
 *
 * @param {real} query_id 
 * @param {string} target_user_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_admin_kick
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-admin-kick)
 * 
 * 
 *
 * @param {string} room_name 
 * @param {string} target_user_id 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_admin_kick"
 * @member {real} "identifier"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_admin_query_join_room_token
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-admin-query-join-room-token)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} room_name 
 * @param {array} buffer_string 
 * @param {array} array_ips 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_admin_query_join_room_token"
 * @member {real} "identifier"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {string} "client_base_url"
 * @member {real} "query_id"
 * @member {real} "token_count"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_admin_set_participant_hard_mute
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-admin-set-participant-hard-mute)
 * 
 * 
 *
 * @param {real} mute 
 * @param {string} room_name 
 * @param {string} target_user_id 
 *
 * @returns {real}
 * @event social
 * @member {string} type the string "eos_rtc_admin_set_participant_hard_mute"
 * @member {real} "identifier"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_add_notify_audio_before_render
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-add-notify-audio-before-render)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} room_name 
 * @param {bool} unmixed_audio 
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_audio_add_notify_audio_before_render"
 * @member {string} "local_user_id"
 * @member {string} "room_name"
 * @member {string} "participant_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_add_notify_audio_before_send
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-add-notify-audio-before-render)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} room_name 
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_audio_add_notify_audio_before_send"
 * @member {string} "local_user_id"
 * @member {string} "room_name"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_add_notify_audio_devices_changed
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-add-notify-audio-devices-changed)
 *
 * 
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_audio_add_notify_audio_devices_changed"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_add_notify_audio_input_state
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-add-notify-audio-input-state)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} room_name 
 *
 * @returns {int64}
 * @event social
 * @member {string} type the string "eos_rtc_audio_add_notify_audio_input_state"
 * @member {string} "local_user_id"
 * @member {string} "room_name"
 * @member {EOS_Result} "status"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_add_notify_audio_output_state
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-add-notify-audio-output-state)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} room_name 
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_audio_add_notify_audio_output_state"
 * @member {string} "local_user_id"
 * @member {string} "room_name"
 * @member {EOS_Result} "status"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_add_notify_participant_updated
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-add-notify-participant-updated)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} room_name 
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_audio_add_notify_participant_updated"
 * @member {string} "local_user_id"
 * @member {string} "room_name"
 * @member {real} "speaking"
 * @member {real} "audio_status"
 * @member {string} "participant_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @struct DeviceInformation
 * @desc This struct holds information about an audio device.
 * 
 * 
 * 
 * @member {bool} default_device 
 * @member {string} device_id 
 * @member {string} device_name 
 * 
 * @struct_end
 */

/**
 * @func eos_rtc_audio_copy_input_device_information_by_index
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_CopyInputDeviceInformationByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-copy-input-device-information-by-index)
 * 
 * 
 * 
 * @param {real} device_index 
 * 
 * @returns {struct.DeviceInformation}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_copy_output_device_information_by_index
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_CopyOutputDeviceInformationByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-copy-output-device-information-by-index)
 * 
 * 
 * 
 * @param {real} device_index 
 * 
 * @returns {struct.DeviceInformation}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_get_audio_input_device_by_index
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_GetAudioInputDeviceByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-get-audio-input-device-by-index)
 * 
 * 
 *
 * @param {real} device_info_index 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_get_audio_input_devices_count
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-get-audio-input-devices-count)
 *
 * 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_get_audio_output_device_by_index
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-get-audio-output-device-by-index)
 *
 * 
 * 
 * @param {real} device_info_index 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_get_audio_output_devices_count
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-get-output-devices-count)
 *
 * 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_get_input_devices_count
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-get-input-devices-count)
 *
 * 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_get_output_devices_count
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-get-output-devices-count)
 *
 * 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_query_input_devices_information
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-query-input-devices-information)
 *
 * 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_audio_query_input_devices_information"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_query_output_devices_information
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-query-output-devices-information)
 *
 * 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_audio_query_output_devices_information"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_register_platform_audio_user
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-register-platform-audio-user)
 * 
 * 
 *
 * @param {string} user_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_register_platform_user
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-register-platform-user)
 * 
 * @param {string} user_id 
 * 
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_remove_notify_audio_before_render
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-remove-notify-audio-before-render)
 * 
 * 
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_remove_notify_audio_before_send
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-remove-notify-audio-before-send)
 * 
 * 
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_remove_notify_audio_devices_changed
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-remove-notify-audio-devices-changed)
 * 
 * 
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_remove_notify_audio_input_state
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-remove-notify-audio-input-state)
 * 
 * 
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_remove_notify_audio_output_state
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-remove-notify-audio-output-state)
 * 
 * 
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_remove_notify_participant_updated
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-remove-notify-participant-updated)
 * 
 * 
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

real eos_rtc_audio_send_audio(string buff_args)


/**
 * @func eos_rtc_audio_set_audio_input_settings
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-set-audio-input-settings)
 * 
 * 
 *
 * @param {bool} platform_aec 
 * @param {string} device_id 
 * @param {string} local_user_id 
 * @param {real} volume 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_set_audio_output_settings
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-set-audio-output-settings)
 * 
 * 
 *
 * @param {string} device_id 
 * @param {string} local_user_id 
 * @param {real} volume 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_set_input_device_settings
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-set-input-device-settings)
 * 
 * 
 *
 * @param {bool} platform_aec 
 * @param {string} local_user_id 
 * @param {string} real_device_id 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_audio_set_input_device_settings"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "real_device_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_set_output_device_settings
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-set-output-device-settings)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} real_device_id 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_audio_set_output_device_settings"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "real_device_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_unregister_platform_audio_user
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-unregister-platform-audio-user)
 *
 * @param {string} user_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_unregister_platform_user
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-unregister-platform-user)
 * 
 * 
 *
 * @param {string} platform_user_id 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_audio_unregister_platform_user"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "platform_user_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_update_participant_volume
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-update-participant-volume)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} participant_id 
 * @param {string} room_name 
 * @param {real} volume 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_audio_unregister_platform_user"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "local_user_id"
 * @member {string} "participant_id"
 * @member {string} "room_name"
 * @member {real} "volume"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_update_receiving
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-update-receiving)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} participant_id 
 * @param {string} room_name 
 * @param {real} audio_enabled 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_audio_update_receiving"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "participant_id"
 * @member {string} "status_message"
 * @member {real} "audio_enabled"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_update_receiving_volume
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-update-receiving-volume)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} room_name 
 * @param {real} volume 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_audio_update_receiving_volume"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_update_sending
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-update-sending)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} room_name 
 * @param {real} audio_status 
 *
 * @returns {real}
 * @event social
 * @member {string} type the string "eos_rtc_audio_update_sending"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "room_name"
 * @member {string} "local_user_id"
 * @member {real} "audio_status"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_update_sending_volume
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-update-sending-volume)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} room_name 
 * @param {real} volume 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_audio_update_sending_volume"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_data_add_notify_data_received
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-data-add-notify-data-received)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} room_name 
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_data_add_notify_data_received"
 * @member {string} "local_user_id"
 * @member {string} "room_name"
 * @member {string} "participant_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_data_add_notify_participant_updated
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-data-add-notify-participant-updated)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} room_name 
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_data_add_notify_participant_updated"
 * @member {string} "local_user_id"
 * @member {string} "room_name"
 * @member {string} "participant_id"
 * @member {real} "data_status"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_data_remove_notify_data_received
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-data-add-notify-data-received)
 * 
 * 
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_data_remove_notify_participant_updated
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-data-remove-notify-participant-updated)
 * 
 * 
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_data_send_data
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-data-send-data)
 * 
 * 
 *
 * @param {buffer} buff 
 * @param {real} length 
 * @param {string} local_user_id 
 * @param {string} room_name 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_data_update_receiving
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-data-update-receiving)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} participant_id 
 * @param {string} room_name 
 * @param {bool} data_enabled 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_data_update_receiving"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "local_user_id"
 * @member {string} "participant_id"
 * @member {string} "room_name"
 * @member {real} "data_enabled"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_data_update_sending
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-data-update-sending)
 * 
 * 
 *
 * @param {string} local_user_id 
 * @param {string} room_name 
 * @param {real} data_enabled 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_data_update_sending"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "local_user_id"
 * @member {string} "room_name"
 * @member {real} "data_enabled"
 * @event_end
 * 
 * @func_end
 */
