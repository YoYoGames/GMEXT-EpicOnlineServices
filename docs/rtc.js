/**
 * @module rtc
 * @title RTC
 * @desc **Epic Online Services Interface**: [RTC Interface](https://dev.epicgames.com/docs/api-ref/interfaces/rtc)
 * 
 * Integrate the Real-time Communication (RTC) Data Interface into your game to use the features of the Epic Online Services (EOS) RTC Data service. Use the RTC Data Interface to allow players to send data messages to each other in a voice chat room.
 * 
 * [[Note: The RTC-data service restricts the amount of data that a player can send. See the [RTC-data Service Limits](https://dev.epicgames.com/docs/game-services/real-time-communication-interface/rtc-data-interface#rtc-data-service-limits) section of this document for details.]]
 * 
 * [[Note: See the [RTC Data Interface](https://dev.epicgames.com/docs/game-services/real-time-communication-interface/rtc-data-interface) for a more detailed introduction.]]
 * 
 * @section_func
 * @ref eos_rtc_*
 * @section_end
 * 
 * @section_struct
 * @ref AudioInputDeviceInformation
 * @ref AudioOutputDeviceInformation
 * @section_end
 * 
 * @section_const
 * @ref EOS_RTC*
 * @section_end
 * 
 * @module_end
 */


/**
 * @func eos_rtc_add_notify_disconnected
 * @desc **Epic Online Services Function:** [EOS_RTC_AddNotifyDisconnected](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-add-notify-disconnected)
 * 
 * This function registers to receive notifications when disconnected from the room. If the returned notification ID is valid, you must call ${function.eos_rtc_remove_notify_disconnected} when you no longer wish to have the ${event.social} called. This function will always return `EOS_INVALID_NOTIFICATIONID` when used with lobby RTC room. To be notified of the connection status of a Lobby-managed RTC room, use the ${function.eos_lobby_add_notify_rtc_room_connection_changed} function instead.
 *
 * @param {string} local_user_id The Product User ID of the user trying to request this operation.
 * @param {string} room_name The room this event is registered on.
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_add_notify_disconnected"`
 * @member {string} local_user_id The Product User ID of the user who initiated this request.
 * @member {string} room_name The room associated with this event.
 * @member {constant.EOS_Result} status This holds: `EOS_Result.`EOS_Result.Success`` The room was left cleanly. `EOS_Result.NoConnection`: There was a network issue connecting to the server (retryable). `EOS_Result.RTC_UserKicked`: The user has been kicked by the server (retryable). `EOS_Result.ServiceFailure`: A known error occurred during interaction with the server (retryable). `EOS_Result.UnexpectedError` Unexpected error (retryable).
 * @member {string} status_message Text representation of the status code
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_add_notify_participant_status_changed
 * @desc **Epic Online Services Function:** [EOS_RTC_AddNotifyParticipantStatusChanged](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-add-notify-participant-status-changed)
 * 
 * This function registers to receive notifications when a participant's status changes (e.g.: join or leave the room), or when the participant is added or removed from an applicable block list (e.g.: Epic block list and/or current platform's block list). If the returned notification ID is valid, you must call ${function.eos_rtc_remove_notify_participant_status_changed} when you no longer wish to have the ${event.social} triggered. If you register to this notification before joining a room, you will receive a notification for every member already in the room when you join said room. This allows you to know who is already in the room when you join. To be used effectively with a Lobby-managed RTC room, this should be registered during the ${function.eos_lobby_create_lobby} or ${function.eos_lobby_join_lobby} completion callbacks when the ResultCode is `EOS_Result.Success`. If this notification is registered after that point, it is possible to miss notifications for already-existing room participants. You can use this notification to detect internal automatic RTC blocks due to block lists. When a participant joins a room and while the system resolves the block list status of said participant, the participant is set to blocked and you'll receive a notification with `participant_status` set to EOS_RTCPS_Joined and `participant_in_blocklist` set to `true`. Once the block list status is resolved, if the player is not in any applicable block list(s), it is then unblocked and a new notification is sent with `participant_status` set to EOS_RTCPS_Joined and `participant_in_blocklist` set to `false`.
 * 
 * [[Note: This notification is also raised when the local user joins the room, but NOT when the local user leaves the room.]]
 *
 * @param {string} local_user_id The Product User ID of the user trying to request this operation.
 * @param {string} room_name The room this event is registered on.
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_add_notify_participant_status_changed"`
 * @member {string} local_user_id The Product User ID of the user who initiated this request.
 * @member {string} room_name The room associated with this event.
 * @member {bool} participant_in_blocklist The participant's block list status, if `participant_status` is `EOS_RTCParticipantStatus.Joined`. This is set to `true` if the participant is in any of the local user's applicable block lists, such as Epic block list or any of the current platform's block lists. It can be used to detect when an internal automatic RTC block is applied because of trust and safety restrictions.
 * @member {string} participant_id The participant whose status changed.
 * @member {constant.EOS_RTCParticipantStatus} participant_status What status change occurred
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_add_notify_room_statistics_updated
 * @desc **Epic Online Services Function:** [EOS_RTC_AddNotifyRoomStatisticsUpdated](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-add-notify-room-statistics-updated)
 * 
 * This function registers to receive notifications to receiving periodical statistics update. If the returned notification ID is valid, you must call ${function.eos_rtc_remove_notify_room_statistics_updated} when you no longer wish to have the ${event.social} called.
 * 
 * @param {string} local_user_id The Product User ID of the user trying to request this operation
 * @param {string} room_name The room this event is registered on
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_add_notify_room_statistics_updated"`
 * @member {string} local_user_id The Product User ID of the user who initiated this request
 * @member {string} room_name The room associated with this event
 * @member {string} statistic Statistics in JSON format
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_block_participant
 * @desc **Epic Online Services Function:** [EOS_RTC_BlockParticipant](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-block-participant)
 * 
 * You can use this function to block a participant already connected to the room. After blocking them no media will be sent or received between that user and the local user. This method can be used after receiving the OnParticipantStatusChanged notification.
 * 
 * The function returns an async identifier.
 *
 * @param {bool} blocked Block or unblock the participant
 * @param {string} local_user_id The Product User ID of the user trying to request this operation
 * @param {string} participant_id The Product User ID of the participant to block
 * @param {string} room_name The room the users should be blocked on
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_block_participant"`
 * @member {real} identifier The async identifier returned by the call to the function
 * @member {string} local_user_id The Product User ID of the user who initiated this request
 * @member {string} participant_id The Product User ID of the participant being blocked
 * @member {bool} blocked The block state that should have been set
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
 * @desc **Epic Online Services Function:** [EOS_RTC_JoinRoom](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-join-room)
 * 
 * You can use this function to join a room. This function does not need to be called for the Lobby RTC Room system; doing so will return EOS_AccessDenied. The lobby system will automatically join and leave RTC Rooms for all lobbies that have RTC rooms enabled.
 * 
 * The function returns an async identifier.
 * 
 * @param {string} local_user_id The product user id of the user trying to request this operation.
 * @param {string} room_name The room the user would like to join.
 * @param {string} participant_id The participant id used to join the room. If set to NULL the LocalUserId will be used instead.
 * @param {string} participant_token Authorization credential token to join the room.
 * @param {bool} manual_audio_input_enabled Enable or disable Manual Audio Input. If manual audio input is enabled audio recording is not started and the audio buffers must be passed manually using ${function.eos_rtc_audio_send_audio}.
 * @param {bool} manual_audio_output_enabled Enable or disable Manual Audio Output. If manual audio output is enabled audio rendering is not started and the audio buffers must be received with ${function.eos_rtc_audio_add_notify_audio_before_render} and rendered manually.
 * @param {string} client_base_url The room the user would like to join.
 * @param {constant.EOS_RTC_JOINROOMFLAGS} flags Join room flags, e.g., `EOS_RTC_JOINROOMFLAGS_ENABLE_ECHO`. This is a bitwise-or union of the defined flags.
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_join_room"`
 * @member {real} identifier The async identifier returned by the call to the function
 * @member {string} local_user_id The Product User ID of the user who initiated this request
 * @member {string} room_name The room the user was trying to join
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_leave_room
 * @desc **Epic Online Services Function:** [EOS_RTC_LeaveRoom](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-leave-room)
 * 
 * You can use this function to leave a room and clean up all the resources associated with it. This function has to always be called when the room is abandoned even if the user is already disconnected for other reasons. This function does not need to called for the Lobby RTC Room system; doing so will return EOS_AccessDenied. The lobby system will automatically join and leave RTC Rooms for all lobbies that have RTC rooms enabled.
 * 
 * The function returns an async identifier.
 * 
 * @param {string} local_user_id Product User ID of the user requesting to leave the room
 * @param {string} room_name The room to leave
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_leave_room"`
 * @member {real} identifier The async identifier returned by the call to the function
 * @member {string} local_user_id The Product User ID of the user who initiated this request
 * @member {string} room_name The room the user was trying to leave
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_remove_notify_disconnected
 * @desc **Epic Online Services Function:** [EOS_RTC_RemoveNotifyDisconnected](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-remove-notify-disconnected)
 * 
 * This function unregisters a previously bound notification handler from receiving room disconnection notifications.
 *
 * @param {real} notification_id The Notification ID representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_rtc_remove_notify_participant_status_changed
 * @desc **Epic Online Services Function:** [EOS_RTC_RemoveNotifyParticipantStatusChanged](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-remove-notify-participant-status-changed)
 * 
 * This function unregisters a previously bound notification handler from receiving participant status change notifications.
 *
 * @param {real} notification_id The Notification ID representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_rtc_remove_notify_room_statistics_updated
 * @desc **Epic Online Services Function:** [EOS_RTC_RemoveNotifyRoomStatisticsUpdated](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-remove-notify-room-statistics-updated)
 * 
 * This function unregisters a previously bound notification handler from receiving periodical statistics update notifications.
 *
 * @param {real} notification_id The Notification ID representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_rtc_set_room_setting
 * @desc **Epic Online Services Function:** [EOS_RTC_SetRoomSetting](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-set-room-setting)
 * 
 * You can use this function to control settings for the specific room.
 * 
 * The available values of `setting_name` are:
 * 
 * * `"DisableEchoCancelation"`: Disables the use of echo cancellation for the audio channel. Default `"False"`.
 * * `"DisableNoiseSupression"`: Disables the use of noise suppression for the audio channel. Default `"False"`.
 * * `"DisableAutoGainControl"`: Disables the use of auto gain control for the audio channel. Default `"False"`.
 * * `"DisableDtx"`: Allows to disable the use of DTX. Default `"False"`.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` when the setting is successfully set
 * * `EOS_Result.NotFound` when the setting is unknown
 * * `EOS_Result.InvalidParameters` when the value is invalid
 *
 * @param {string} local_user_id The Product User ID of the user trying to request this operation
 * @param {string} room_name The room the setting will be applied to
 * @param {string} setting_name The setting that should be set
 * @param {string} setting_value The value to set the setting to
 *
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_set_setting
 * @desc **Epic Online Services Function:** [EOS_RTC_SetSetting](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-set-setting)
 * 
 * You can use this function to control settings.
 * 
 * * `"DisableEchoCancelation"`: Disables the use of echo cancellation for the audio channel. Default `"False"`.
 * * `"DisableNoiseSupression"`: Disables the use of noise suppression for the audio channel. Default `"False"`.
 * * `"DisableAutoGainControl"`: Disables the use of auto gain control for the audio channel. Default `"False"`.
 * * `"DisableDtx"`: Allows to disable the use of DTX. Default `"False"`.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` when the setting is successfully set
 * * `EOS_Result.NotFound` when the setting is unknown
 * * `EOS_Result.InvalidParameters` when the value is invalid
 *
 * @param {string} setting_name The setting that should be set
 * @param {string} setting_value The value to set the setting to
 *
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_admin_copy_user_token_by_index
 * @desc **Epic Online Services Function:** [EOS_RTCAdmin_CopyUserTokenByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-admin-copy-user-token-by-index)
 * 
 * This function fetches a user token when called inside of the OnQueryJoinRoomTokenComplete callback, initiating the query.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` if the information is available
 * * `EOS_Result.NotFound` if the user token is not found
 * 
 * @param {real} query_id The query identifier received as part of a previous query
 * @param {real} user_token_index The Product User ID for the user whose user token we're copying
 *
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_admin_copy_user_token_by_user_id
 * @desc **Epic Online Services Function:** [EOS_RTCAdmin_CopyUserTokenByUserId](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-admin-copy-user-token-by-user-id)
 * 
 * This function fetches a user token for a given user ID when called inside of the OnQueryJoinRoomTokenComplete callback.
 * 
 * @param {real} query_id The query identifier received as part of a previous query
 * @param {string} target_user_id The Product User ID for the user whose user token we're copying
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_admin_kick
 * @desc **Epic Online Services Function:** [EOS_RTCAdmin_Kick](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-admin-kick)
 * 
 * This function starts an asynchronous task that removes a participant from a room and revokes their token.
 * 
 * The function returns an async identifier.
 *
 * @param {string} room_name The room name to kick the participant from
 * @param {string} target_user_id The product User ID of the participant to kick from the room
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_admin_kick"`
 * @member {real} identifier The identifier returned by the function
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_admin_query_join_room_token
 * @desc **Epic Online Services Function:** [EOS_RTCAdmin_QueryJoinRoomToken](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-admin-query-join-room-token)
 * 
 * This function queries for a list of user tokens for joining a room. Each query generates a query ID (see the ${event.social}) which should be used to retrieve the tokens from inside the callback. This query ID and query result itself are only valid for the duration of the callback.
 * 
 * The function returns an async identifier.
 *
 * @param {string} local_user_id The product User ID for the local user who is querying join room tokens
 * @param {string} room_name The room name to request a token for
 * @param {array} array_ids An array of Product User IDs indicating the users to retrieve a token for
 * @param {array} array_ips An array of IP Addresses, one for each of the users to query tokens for. If you pass an empty array, IP Addresses will be ignored. IPv4 format: `"0.0.0.0"`, IPv6 format: `"0:0:0:0:0:0:0:0"`
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_admin_query_join_room_token"`
 * @member {real} identifier The identifier returned by the function
 * @member {constant.EOS_Result} status The result code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {string} client_base_url URL passed to backend to join room
 * @member {real} query_id If the query completed successfully, this contains an identifier that should be used to retrieve the tokens. This identifier is only valid for the duration of the callback.
 * @member {real} token_count How many tokens received as result of the query
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_admin_set_participant_hard_mute
 * @desc **Epic Online Services Function:** [EOS_RTCAdmin_SetParticipantHardMute](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-admin-set-participant-hard-mute)
 * 
 * This function starts an asynchronous task that remotely mutes/unmutes a room participant. This remotely mutes the specified participant, so no audio is sent from that participant to any other participant in the room.
 * 
 * The function returns an async identifier.
 *
 * @param {bool} mute The hard mute status (mute on or off)
 * @param {string} room_name The room to kick the participant from
 * @param {string} target_user_id The product User ID of the participant to hard mute for every participant in the room
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_admin_set_participant_hard_mute"`
 * @member {real} identifier The identifier returned by the function
 * @member {constant.EOS_Result} status The result code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_add_notify_audio_before_render
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_AddNotifyAudioBeforeRender](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-add-notify-audio-before-render)
 * 
 * This function registers to receive notifications with remote audio buffers before they are rendered. This gives you access to the audio data received, allowing for example the implementation of custom filters/effects. If the returned notification ID is valid, you must call ${function.eos_rtc_audio_remove_notify_audio_before_render} when you no longer wish to have the ${event.social} called.
 * 
 * The function returns a notification ID representing the registered callback if successful, an invalid notification ID if not.
 *
 * @param {string} local_user_id The Product User ID of the user trying to request this operation.
 * @param {string} room_name The room this event is registered on.
 * @param {bool} unmixed_audio Mixed audio or unmixed audio.
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_audio_add_notify_audio_before_render"`
 * @member {string} local_user_id The Product User ID of the user who initiated this request.
 * @member {string} room_name The room associated with this event.
 * @member {string} participant_id The Product User ID of the participant if `unmixed_audio` was set to `true` when setting the notifications, or empty if `unmixed_audio` was set to `false` and thus the buffer is the mixed audio of all participants
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_add_notify_audio_before_send
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_AddNotifyAudioBeforeSend](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-add-notify-audio-before-send)
 * 
 * This function registers to receive notifications when local audio buffers are about to be encoded and sent. This gives you access to the audio data about to be sent, allowing for example the implementation of custom filters/effects. If the returned notification ID is valid, you must call ${function.eos_rtc_audio_remove_notify_audio_before_send} when you no longer wish to have the ${event.social} called.
 * 
 * @param {string} local_user_id The Product User ID of the user trying to request this operation
 * @param {string} room_name The room this event is registered on
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_audio_add_notify_audio_before_send"`
 * @member {string} local_user_id The Product User ID of the user who initiated this request
 * @member {string} room_name The room associated with this event
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_add_notify_audio_devices_changed
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_AddNotifyAudioDevicesChanged](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-add-notify-audio-devices-changed)
 *
 * This function registers to receive notifications when an audio device is added or removed to the system. If the returned notification ID is valid, you must call ${function.eos_rtc_audio_remove_notify_audio_devices_changed} when you no longer wish to have the ${event.social} called.
 * 
 * The library will try to use user selected audio device while following these rules:
 * 
 * * if none of the audio devices has been available and connected before - the library will try to use it;
 * * if user selected device failed for some reason, default device will be used instead (and user selected device will be memorized);
 * * if user selected a device but it was not used for some reason (and default was used instead), when devices selection is triggered we will try to use user selected device again;
 * * triggers to change a device: when new audio device appears or disappears - library will try to use previously user selected;
 * * if for any reason, a device cannot be used - the library will fallback to using default;
 * * if a configuration of the current audio device has been changed, it will be restarted.
 * 
 * The function returns an async identifier.
 * 
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_audio_add_notify_audio_devices_changed"`
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_add_notify_audio_input_state
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_AddNotifyAudioInputState](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-add-notify-audio-input-state)
 * 
 * This function registers to receive notifications when audio input state changed. If the returned notification ID is valid, you must call ${function.eos_rtc_audio_remove_notify_audio_input_state} when you no longer wish to have the ${event.social} called.
 * 
 * The function returns the notification ID representing the registered callback if successful, an invalid notification ID if not.
 *
 * @param {string} local_user_id The Product User ID of the user trying to request this operation
 * @param {string} room_name The room this event is registered on
 *
 * @returns {int64}
 * @event social
 * @member {string} type the string `"eos_rtc_audio_add_notify_audio_input_state"`
 * @member {string} local_user_id The Product User ID of the user who initiated this request
 * @member {string} room_name The room associated with this event
 * @member {constant.EOS_RTCAudioInputStatus} status The status of the audio input
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_add_notify_audio_output_state
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_AddNotifyAudioOutputState](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-add-notify-audio-output-state)
 * 
 * This function registers to receive notifications when audio output state changed. If the returned notification ID is valid, you must call ${function.eos_rtc_audio_remove_notify_audio_output_state} when you no longer wish to have the ${event.social} called.
 *
 * @param {string} local_user_id The Product User ID of the user trying to request this operation
 * @param {string} room_name The room this event is registered on
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_audio_add_notify_audio_output_state"`
 * @member {string} local_user_id The Product User ID of the user who initiated this request
 * @member {string} room_name The room associated with this event
 * @member {constant.EOS_RTCAudioOutputStatus} status The status of the audio output
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_add_notify_participant_updated
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_AddNotifyParticipantUpdated](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-add-notify-participant-updated)
 * 
 * This function registers to receive notifications when a room participant audio status is updated (e.g. when mute state changes or speaking flag changes). The notification is raised when the participant's audio status is updated. In order not to miss any participant status changes, applications need to add the notification before joining a room. If the returned notification ID is valid, you must call ${function.eos_rtc_audio_remove_notify_participant_updated} when you no longer wish to have the ${event.social} called.
 * 
 * The function returns a notification ID representing the registered callback if successful, an invalid notification ID if not.
 *
 * @param {string} local_user_id The Product User ID of the user trying to request this operation
 * @param {string} room_name The room this event is registered on
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_audio_add_notify_participant_updated"`
 * @member {string} local_user_id The Product User ID of the user who initiated this request
 * @member {string} room_name The room associated with this event
 * @member {real} speaking The participant speaking / non-speaking status
 * @member {constant.EOS_RTCAudioStatus} audio_status The participant audio status (enabled, disabled)
 * @member {string} participant_id The participant updated
 * @event_end
 * 
 * @func_end
 */

/**
 * @struct AudioInputDeviceInformation
 * @desc **Epic Online Services Struct:** [EOS_RTCAudio_InputDeviceInformation](https://dev.epicgames.com/docs/api-ref/structs/eos-rtc-audio-input-device-information)
 * 
 * This struct holds information about an audio input device.
 * 
 * @member {bool} default_device True if this is the default audio input device in the system.
 * @member {string} device_id The persistent unique ID of the audio input device. The value can be cached - invalidated only when the audio device pool is changed.
 * @member {string} device_name The human-readable name of the audio input device
 * 
 * @struct_end
 */

/**
 * @func eos_rtc_audio_copy_input_device_information_by_index
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_CopyInputDeviceInformationByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-copy-input-device-information-by-index)
 * 
 * This function fetches an audio input device's information from the given index that are cached locally.
 * 
 * @param {real} device_index The index of the audio input device's information to retrieve
 * 
 * @returns {struct.AudioInputDeviceInformation}
 * 
 * @func_end
 */

/**
 * @struct AudioOutputDeviceInformation
 * @desc **Epic Online Services Struct:** [EOS_RTCAudio_OutputDeviceInformation](https://dev.epicgames.com/docs/api-ref/structs/eos-rtc-audio-output-device-information)
 * 
 * This struct holds information about an audio output device.
 * 
 * @member {bool} default_device True if this is the default audio output device in the system.
 * @member {string} device_id The persistent unique ID of the audio output device. The value can be cached - invalidated only when the audio device pool is changed.
 * @member {string} device_name The human-readable name of the audio output device
 * 
 * @struct_end
 */

/**
 * @func eos_rtc_audio_copy_output_device_information_by_index
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_CopyOutputDeviceInformationByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-copy-output-device-information-by-index)
 * 
 * This function fetches an audio output device's information from the given index that are cached locally.
 * 
 * @param {real} device_index The index of the audio output device's information to retrieve
 * 
 * @returns {struct.AudioOutputDeviceInformation}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_get_audio_output_devices_count
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_GetOutputDevicesCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-get-output-devices-count)
 * 
 * This function fetches the number of audio output devices available in the system that are cached locally. The returned value should not be cached and should instead be used immediately with the ${function.eos_rtc_audio_copy_output_device_information_by_index} function.
 * 
 * The function returns the number of audio output devices available in the system or 0 if there is an error.
 * 
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_get_input_devices_count
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_GetInputDevicesCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-get-input-devices-count)
 * 
 * This function fetches the number of audio input devices available in the system that are cached locally. The returned value should not be cached and should instead be used immediately with the ${function.eos_rtc_audio_copy_input_device_information_by_index} function.
 * 
 * The function returns the number of audio input devices available in the system or 0 if there is an error.
 * 
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_query_input_devices_information
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_QueryInputDevicesInformation](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-query-input-devices-information)
 * 
 * This function queries for a list of audio input devices available in the system together with their specifications.
 * 
 * It returns the async identifier that you can compare against in the ${event.social}.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_audio_query_input_devices_information"`
 * @member {constant.EOS_Result} status `EOS_Result.Success` if the operation succeeded, `EOS_Result.InvalidParameters` if any of the parameters were incorrect
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_query_output_devices_information
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_QueryOutputDevicesInformation](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-query-output-devices-information)
 * 
 * This function queries for a list of audio output devices available in the system together with their specifications.
 * 
 * It returns the async identifier that you can compare against in the ${event.social}.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_audio_query_output_devices_information"`
 * @member {constant.EOS_Result} status `EOS_Result.Success` if the operation succeeded, `EOS_Result.InvalidParameters` if any of the parameters were incorrect
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_register_platform_user
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_RegisterPlatformUser](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-register-platform-user)
 * 
 * You can use this function to inform the audio system of a user. This function is only necessary for some platforms.
 * 
 * The function returns one of the following:
 * 
 * * `"EOS_Result.Success"` if the user was successfully registered
 * * `"EOS_Result.InvalidParameters"` if any of the parameters are incorrect
 * * `"EOS_Result.UnexpectedError"` otherwise
 * 
 * @param {string} user_id The platform dependent user ID
 * 
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_remove_notify_audio_before_render
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_RemoveNotifyAudioBeforeRender](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-remove-notify-audio-before-render)
 * 
 * This function unregisters a previously bound notification handler from receiving remote audio buffers before they are rendered.
 *
 * @param {real} notification_id The notification ID representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_remove_notify_audio_before_send
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_RemoveNotifyAudioBeforeSend](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-remove-notify-audio-before-send)
 * 
 * This function unregisters a previously bound notification handler from receiving local audio buffers before they are encoded and sent.
 * 
 * @param {real} notification_id The notification ID representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_remove_notify_audio_devices_changed
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_RemoveNotifyAudioDevicesChanged](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-remove-notify-audio-devices-changed)
 * 
 * This function unregisters a previously bound notification handler from receiving audio devices notifications.
 * 
 * @param {real} notification_id The notification ID representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_remove_notify_audio_input_state
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_RemoveNotifyAudioInputState](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-remove-notify-audio-input-state)
 * 
 * This function unregisters a previously bound notification handler from receiving notifications on audio output state changed.
 *
 * @param {real} notification_id The notification ID representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_remove_notify_audio_output_state
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_RemoveNotifyAudioOutputState](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-remove-notify-audio-output-state)
 * 
 * This function unregisters a previously bound notification handler from receiving notifications on audio output state changed.
 *
 * @param {real} notification_id The notification ID representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_remove_notify_participant_updated
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_RemoveNotifyParticipantUpdated](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-remove-notify-participant-updated)
 * 
 * This function unregisters a previously bound notification handler from receiving participant updated notifications.
 *
 * @param {real} notification_id The notification ID representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_send_audio
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_SendAudio](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-send-audio)
 * 
 * You can use this function to push a new audio buffer to be sent to the participants of a room. This should only be used if Manual Audio Input was enabled locally for the specified room.
 * 
 * @param {real} channels The number of audio channels
 * @param {real} frames_count The number of frames
 * @param {real} sample_rate The sample rate of the audio in the buffer
 * @param {string} local_user_id The Product User ID of the user trying to request this operation
 * @param {string} room_name The room this event is registered on
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_set_input_device_settings
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_SetInputDeviceSettings](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-set-input-device-settings)
 * 
 * You can use this function to set audio input device settings, such as the active input device, or platform AEC.
 * 
 * The function returns an async identifier.
 *
 * @param {bool} platform_aec Whether to enable or disable Platform AEC (Acoustic Echo Cancellation) if available.
 * @param {string} local_user_id The Product User ID of the user trying to request this operation.
 * @param {string} real_device_id The device ID to be used for this user. Pass an empty string to use a default input device. If the device ID is invalid, the default device will be used instead. Despite this fact, that device ID will be stored and the library will try to move on it when an audio device pool is being changed. The actual hardware audio input device usage depends on the current payload and optimized not to use it when generated audio frames cannot be processed by someone else based on a scope of rules (For instance, when a client is alone in a room).
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_audio_set_input_device_settings"`
 * @member {constant.EOS_Result} status `EOS_Result.Success` if the operation succeeded, `EOS_Result.InvalidParameters` if any of the parameters are incorrect
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} real_device_id The associated audio input device ID
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_set_output_device_settings
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_SetOutputDeviceSettings](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-set-output-device-settings)
 * 
 * You can use this function to set audio output device settings, such as the active output device.
 * 
 * The function returns an async identifier.
 *
 * @param {string} local_user_id The Product User ID of the user who initiated this request
 * @param {string} real_device_id The device ID to be used for this user. Pass an empty string to use a default output device. If the device ID is invalid, the default device will be used instead. Despite this fact, that device ID will be stored and the library will try to move on it when an audio device pool is being changed. The actual hardware audio output device usage depends on the current payload and optimized not to use it when generated audio frames cannot be processed by someone else based on a scope of rules (For instance, when a client is alone in a room).
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_audio_set_output_device_settings"`
 * @member {constant.EOS_Result} status `EOS_Result.Success` if the operation succeeded, `EOS_Result.InvalidParameters` if any of the parameters are incorrect
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} real_device_id The associated audio output device ID
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_unregister_platform_user
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_UnregisterPlatformUser](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-unregister-platform-user)
 * 
 * You can use this function to remove a user that was added with ${function.eos_rtc_audio_register_platform_user}. This function is only necessary for some platforms.
 * 
 * The function returns an async identifier.
 *
 * @param {string} platform_user_id The account of a user associated with this event
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_audio_unregister_platform_user"`
 * @member {constant.EOS_Result} status `EOS_Result.Success` if the user was successfully unregistered, `EOS_Result.InvalidParameters` if any of the parameters are incorrect, `EOS_Result.UnexpectedError` otherwise
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} platform_user_id The platform dependent user ID
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_update_participant_volume
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_UpdateParticipantVolume](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-update-participant-volume)
 * 
 * You can use this function to change participant audio volume for a room.
 * 
 * The function returns an async identifier.
 * 
 * [[Note: Due to Epic Online Services implementation details, this function requires that you first register to any notification for room.]]
 *
 * @param {string} local_user_id The Product User ID of the user trying to request this operation
 * @param {string} participant_id The participant to modify or null to update the global configuration
 * @param {string} room_name The room this setting should be applied on
 * @param {real} volume The volume to be set for received audio (range 0.0 to 100.0). Volume 50 means that the audio volume is not modified and stays in its source value.
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_audio_unregister_platform_user"`
 * @member {constant.EOS_Result} status `EOS_Result.Success` if volume of remote participant audio was successfully changed, `EOS_Result.UnexpectedError` otherwise
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} local_user_id The Product User ID of the user who initiated this request
 * @member {string} participant_id The participant to modify
 * @member {string} room_name The room this settings should be applied on
 * @member {real} volume The volume that was set for received audio (range 0.0 to 100.0)
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_update_receiving
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_UpdateReceiving](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-update-receiving)
 * 
 * You can use this function to tweak incoming audio options for a room.
 * 
 * The function returns an async identifier.
 * 
 * [[Note: Due to Epic Online Services implementation details, this function requires that you first register to any notification for room.]]
 *
 * @param {string} local_user_id The Product User ID of the user trying to request this operation
 * @param {string} participant_id The participant to modify or an empty string to update the global configuration
 * @param {string} room_name The room this setting should be applied on
 * @param {bool} audio_enabled Whether to mute or unmute audio track
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_audio_update_receiving"`
 * @member {constant.EOS_Result} status `EOS_Result.Success` if receiving of channels of remote users was successfully enabled/disabled, `EOS_Result.NotFound` if the participant isn't found by ParticipantId, `EOS_Result.UnexpectedError` otherwise
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} participant_id The participant modified
 * @member {string} room_name The room this setting was applied on
 * @member {bool} audio_enabled Whether the audio track is muted or unmuted
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_update_receiving_volume
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_UpdateReceivingVolume](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-update-receiving-volume)
 * 
 * You can use this function to change the incoming audio volume for a room.
 * 
 * The function returns an async identifier.
 * 
 * [[Note: Due to Epic Online Services implementation details, this function requires that you first register to any notification for room.]]
 *
 * @param {string} local_user_id The Product User ID of the user trying to request this operation.
 * @param {string} room_name The room this setting should be applied on.
 * @param {real} volume The volume to be set for received audio (range 0.0 to 100.0). Volume 50 means that the audio volume is not modified and stays in its source value.
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_audio_update_receiving_volume"`
 * @member {constant.EOS_Result} status `EOS_Result.Success` if receiving volume of channels of the local user was successfully changed. `EOS_Result.UnexpectedError` otherwise.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_update_sending
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_UpdateSending](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-update-sending)
 * 
 * You can use this function to tweak outgoing audio options for a room.
 * 
 * The function returns an async identifier.
 * 
 * [[Note: Due to Epic Online Services implementation details, this function requires that you first register to any notification for room.]]
 *
 * @param {string} local_user_id The Product User ID of the user trying to request this operation.
 * @param {string} room_name The room this settings should be applied on.
 * @param {constant.EOS_RTCAudioStatus} audio_status Muted or unmuted audio track status
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_audio_update_sending"`
 * @member {constant.EOS_Result} status `EOS_Result.Success` if sending of channels of the local user was successfully enabled/disabled. `EOS_Result.UnexpectedError` otherwise.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} room_name The room this setting was applied on
 * @member {string} local_user_id The Product User ID of the user who initiated this request
 * @member {constant.EOS_RTCAudioStatus} audio_status Muted or unmuted audio track status
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_audio_update_sending_volume
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_UpdateSendingVolume](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-audio-update-sending-volume)
 * 
 * You can use this function to change outgoing audio volume for a room.
 * 
 * The function returns an async identifier.
 * 
 * [[Note: Due to Epic Online Services implementation details, this function requires that you first register to any notification for room.]]
 *
 * @param {string} local_user_id The Product User ID of the user trying to request this operation
 * @param {string} room_name The room this settings should be applied on
 * @param {real} volume The volume to be set for sent audio (range 0.0 to 100.0). Volume 50 means that the audio volume is not modified and stays in its source value.
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_audio_update_sending_volume"`
 * @member {constant.EOS_Result} status `EOS_Result.Success` if sending volume of channels of the local user was successfully changed, `EOS_Result.UnexpectedError` otherwise
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_data_add_notify_data_received
 * @desc **Epic Online Services Function:** [EOS_RTCData_AddNotifyDataReceived](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-data-add-notify-data-received)
 * 
 * This function registers to receive notifications with remote data packet received. If the returned notification ID is valid, you must call ${function.eos_rtc_data_remove_notify_data_received} when you no longer wish to have the ${event.social} called.
 * 
 * The function returns an async identifier.
 * 
 * @param {string} local_user_id The Product User ID of the user trying to request this operation
 * @param {string} room_name The room this event is registered on
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_data_add_notify_data_received"`
 * @member {string} local_user_id The Product User ID of the user who initiated this request
 * @member {string} room_name The room associated with this event
 * @member {string} participant_id The Product User ID of the participant that sent the data
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_data_add_notify_participant_updated
 * @desc **Epic Online Services Function:** [EOS_RTCData_AddNotifyParticipantUpdated](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-data-add-notify-participant-updated)
 * 
 * This function registers to receive notifications when a room participant data status is updated (e.g. when connection state changes). The notification is raised when the participant's data status is updated. In order not to miss any participant status changes, applications need to add the notification before joining a room. If the returned notification ID is valid, you must call ${function.eos_rtc_data_remove_notify_participant_updated} when you no longer wish to have the ${event.social} called.
 * 
 * The function returns an async identifier.
 *
 * @param {string} local_user_id The Product User ID of the user trying to request this operation
 * @param {string} room_name The room this event is registered on
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_data_add_notify_participant_updated"`
 * @member {string} local_user_id The Product User ID of the user who initiated this request
 * @member {string} room_name The room associated with this event
 * @member {string} participant_id The participant updated
 * @member {constant.EOS_RTCDataStatus} data_status The data channel status
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_data_remove_notify_data_received
 * @desc **Epic Online Services Function:** [EOS_RTCData_RemoveNotifyDataReceived](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-data-remove-notify-data-received)
 * 
 * This function unregisters a previously bound notification handler from receiving remote data packets.
 *
 * @param {real} notification_id The notification ID representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_rtc_data_remove_notify_participant_updated
 * @desc **Epic Online Services Function:** [EOS_RTCData_RemoveNotifyParticipantUpdated](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-data-remove-notify-participant-updated)
 * 
 * This function unregisters a previously bound notification handler from receiving participant updated notifications.
 *
 * @param {real} notification_id The notification ID representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_rtc_data_send_data
 * @desc **Epic Online Services Function:** [EOS_RTCData_SendData](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-data-send-data)
 * 
 * You can use this function to send a data packet to the rest of participants.
 * 
 * The data to be sent needs to be stored in a ${type.buffer}, which you pass to the function. A total of `length` bytes are sent, with the first byte being the first byte in the buffer.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` if the data packet was queued for sending
 * * `EOS_Result.InvalidParameters` if any of the options are invalid
 * * `EOS_Result.NotFound` if the specified room was not found
 * 
 * @param {buffer} buff The buffer containing the data to send
 * @param {real} length The number of bytes to send
 * @param {string} local_user_id The Product User ID of the user trying to request this operation
 * @param {string} room_name The room this event is registered on
 *
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_rtc_data_update_receiving
 * @desc **Epic Online Services Function:** [EOS_RTCData_UpdateReceiving](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-rtc-data-update-receiving)
 * 
 * You can use this function to tweak incoming data options for a room.
 * 
 * The function returns an async identifier.
 * 
 * @param {string} local_user_id The Product User ID of the user trying to request this operation
 * @param {string} participant_id The participant to modify or null to update the global configuration
 * @param {string} room_name The room this setting should be applied on
 * @param {bool} data_enabled Creates or destroys data channel subscription
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_rtc_data_update_receiving"
 * @member {constant.EOS_Result} status `EOS_Result.Success` if receiving of channels of remote users was successfully enabled/disabled, `EOS_Result.NotFound` if the participant isn't found by `participant_id`, `EOS_Result.UnexpectedError` otherwise
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} local_user_id The Product User ID of the user who initiated this request
 * @member {string} participant_id The participant to modify or an empty string to update the global configuration
 * @member {string} room_name The room this settings should be applied on
 * @member {real} data_enabled Created or destroyed data channel
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_rtc_data_update_sending
 * @desc **Epic Online Services Function:** [EOS_RTCData_UpdateSending](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-data-update-sending)
 * 
 * You can use this function to tweak outgoing data options for a room.
 * 
 * The function returns an async identifier.
 *
 * @param {string} local_user_id The Product User ID of the user trying to request this operation
 * @param {string} room_name The room this setting should be applied on
 * @param {real} data_enabled Creates or destroys data channel
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_rtc_data_update_sending"`
 * @member {constant.EOS_Result} status `EOS_Result.Success` if sending of channels of the local user was successfully enabled/disabled, `EOS_Result.UnexpectedError` otherwise
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} local_user_id The Product User ID of the user who initiated this request
 * @member {string} room_name The room this settings should be applied on
 * @member {real} data_enabled Created or destroyed data channel
 * @event_end
 * 
 * @func_end
 */

// Constants & Enums

/**
 * @constant EOS_RTCParticipantStatus
 * @desc **Epic Online Services Enum:** [EOS_ERTCParticipantStatus](https://dev.epicgames.com/docs/ja/api-ref/enums/eos-ertc-participant-status)
 * 
 * This enumeration holds the possible values for a participant's RTC status change.
 * 
 * @member Joined The participant joined the room
 * @member Left The participant left the room
 * 
 * @constant_end
 */

/**
 * @constant EOS_RTCBackgroundMode
 * @desc **Epic Online Services Enum:** [EOS_ERTCBackgroundMode](https://dev.epicgames.com/docs/ja/api-ref/enums/eos-ertc-background-mode)
 * 
 * This enumeration holds the possible background modes supported by the RTC components.
 * 
 * @member LeaveRooms Upon entering a background application status, all logged in users leave any RTC rooms. All subsequent attempts to join any RTC rooms will be rejected. Upon returning to a foreground application status, all subsequent attempts to join any RTC rooms will be allowed.
 * @member KeepRoomsAlive Application status has no effect on RTC rooms. Audio is captured from input devices and is played to output devices. Games should obtain consent from users and otherwise make users aware this is occurring.
 * 
 * @constant_end
 */

/**
 * @constant EOS_RTCAudioStatus
 * @desc **Epic Online Services Enum:** [EOS_ERTCAudioStatus](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-ertc-audio-status)
 * 
 * This enumeration holds the different possible audio channel statuses.
 * 
 * @member Unsupported Audio unsupported by the source (no devices)
 * @member Enabled Audio enabled
 * @member Disabled Audio disabled
 * @member AdminDisabled Audio disabled by the administrator
 * @member NotListeningDisabled Audio channel is disabled temporarily for both sending and receiving
 * 
 * @constant_end
 */

/**
 * @constant EOS_RTC_JOINROOMFLAGS
 * @desc **Epic Online Services Docs:** [EOS_RTC_JoinRoomOptions::Flags](https://dev.epicgames.com/docs/en-US/api-ref/structs/eos-rtc-join-room-options)
 * 
 * This set of macros holds flags that can be used when joining a room (using the function ${function.eos_rtc_join_room}).
 * 
 * @member EOS_RTC_JOINROOMFLAGS_ENABLE_ECHO Enables echo mode. This can be used during development to have the server send your voice back to you so you don't need 2 clients to test if voice is being sent and received.
 * @member EOS_RTC_JOINROOMFLAGS_ENABLE_DATACHANNEL Enables the (optional) data channel feature for RTC rooms. This feature allows members of a room to send packets to all members of a room they are in, and automatically receive data packets sent by other players in that room. Data packets sent this way will be automatically relayed by EOS RTC servers to all other members of the room that are listening. It is not currently possible to send packets to only a subset of members of a room chosen by the sender, all members listening will receive the data.
 * 
 * @constant_end
 */

/**
 * @constant EOS_RTCAudioInputStatus
 * @desc **Epic Online Services Enum:** [EOS_ERTCAudioInputStatus](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-ertc-audio-input-status)
 * 
 * This enumeration holds the different audio input device statuses.
 * 
 * @member Idle The device is not in use right now (e.g., you are alone in the room). In such cases, the hardware resources are not allocated.
 * @member Recording The device is being used and capturing audio.
 * @member RecordingSilent The SDK is in a recording state, but actually capturing silence because the device is exclusively being used by the platform at the moment. This only applies to certain platforms.
 * @member RecordingDisconnected The SDK is in a recording state, but actually capturing silence because the device is disconnected (e.g., the microphone is not plugged in). This only applies to certain platforms.
 * @member Failed Something failed while trying to use the device.
 * 
 * @constant_end
 */

/**
 * @constant EOS_RTCAudioOutputStatus
 * @desc **Epic Online Services Enum:** [EOS_ERTCAudioOutputStatus](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-ertc-audio-output-status)
 * 
 * This enumeration holds the different audio output device statuses.
 * 
 * @member Idle The device is not in used right now (e.g.: you are alone in the room). In such cases, the hardware resources are not allocated.
 * @member Playing Device is in use
 * @member Failed Something failed while trying to use the device
 * 
 * @constant_end
 */

/**
 * @constant EOS_RTCDataStatus
 * @desc **Epic Online Services Enum:** [EOS_ERTCDataStatus](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-ertc-data-status)
 * 
 * This enumeration holds the different data channel statuses.
 * 
 * @member Unsupported Data unsupported
 * @member Enabled Data enabled
 * @member Disabled Data disabled
 * 
 * @constant_end
 */

