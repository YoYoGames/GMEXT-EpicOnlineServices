// Functions - RTC Core

/**
 * @function eos_rtc_join_room
 * @desc **Epic Online Services Function:** [EOS_RTC_JoinRoom](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-join-room)
 *
 * Joins (or creates, if it doesn't exist yet) an RTC room. A room is a voice/data space shared by
 * every participant who joins it with the same `room_name` - rooms are commonly created implicitly by
 * ${function.eos_lobby_create_lobby}/${function.eos_lobby_join_lobby} (a Lobby-managed RTC room, see
 * ${function.eos_lobby_get_rtc_room_name}) or ${function.eos_sessions_join_session}, but can also be
 * joined directly for a standalone voice/data room.
 *
 * `manual_audio_input`/`manual_audio_output` opt this local user out of the SDK's default
 * capture/playback device handling - set either to `true` if your game supplies its own microphone
 * capture (via ${function.eos_rtc_audio_send_audio}) or does its own audio rendering (via the
 * `${event.callback}` on ${function.eos_rtc_audio_add_notify_audio_before_render}) instead of letting
 * the SDK open the platform's default input/output device.
 *
 * @param {String} local_user_id The Product User ID of the user joining the room.
 * @param {String} room_name The room to join. Rooms are created on first join.
 * @param {String} client_base_url The RTC room's base URL, normally obtained from a Lobby/Session's
 * connection details rather than hardcoded.
 * @param {String} participant_token The token authorizing this user to join the room, normally
 * obtained the same way as `client_base_url`.
 * @param {Bool} manual_audio_input `true` if this game supplies its own captured audio instead of the
 * SDK's default microphone capture.
 * @param {Bool} manual_audio_output `true` if this game renders received audio itself instead of the
 * SDK's default playback.
 * @param {Function} [callback] Called once with the result of the join attempt.
 *
 * @event callback
 * @desc Fires once after the join attempt completes.
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the room was joined.
 * @member {String} local_user_id The Product User ID that requested the join.
 * @member {String} room_name The room that was joined.
 * @member {Array[Struct.EpicRTCOption]} room_options Room-level options reported back by the RTC
 * backend for this room.
 * @event_end
 *
 * @example
 * ```gml
 * eos_rtc_join_room(local_user_id, "my_room", client_base_url, participant_token, false, false,
 *     function(_info)
 *     {
 *         if (_info.result_code == EpicResult.Success)
 *         {
 *             show_debug_message($"Joined RTC room {_info.room_name}");
 *         }
 *     });
 * ```
 * @function_end
 */

/**
 * @function eos_rtc_leave_room
 * @desc **Epic Online Services Function:** [EOS_RTC_LeaveRoom](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-leave-room)
 *
 * Leaves an RTC room previously joined with ${function.eos_rtc_join_room}.
 *
 * @param {String} local_user_id The Product User ID of the user leaving the room.
 * @param {String} room_name The room to leave.
 * @param {Function} [callback] Called once the room has been left.
 *
 * @event callback
 * @desc Fires once after the leave completes.
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the room was left cleanly.
 * @member {String} local_user_id The Product User ID that requested the leave.
 * @member {String} room_name The room that was left.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_block_participant
 * @desc **Epic Online Services Function:** [EOS_RTC_BlockParticipant](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-block-participant)
 *
 * Blocks or unblocks a specific participant's audio in a room, independent of the platform/Epic block
 * list. A blocked participant stops sending/receiving audio to/from the local user without being
 * removed from the room.
 *
 * @param {String} local_user_id The Product User ID performing the block.
 * @param {String} room_name The room the participant is in.
 * @param {String} participant_id The Product User ID of the participant to block/unblock.
 * @param {Bool} blocked `true` to block, `false` to unblock.
 * @param {Function} [callback] Called once the block/unblock completes.
 *
 * @event callback
 * @desc Fires once after the operation completes.
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the operation succeeded.
 * @member {String} local_user_id The Product User ID that requested the operation.
 * @member {String} room_name The room the target participant is in.
 * @member {String} participant_id The Product User ID that was blocked/unblocked.
 * @member {Bool} blocked The resulting blocked state.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_set_setting
 * @desc **Epic Online Services Function:** [EOS_RTC_SetSetting](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-set-setting)
 *
 * Sets a global (not room-specific) RTC setting by name. See ${function.eos_rtc_set_room_setting} for
 * the per-room equivalent. Refer to Epic's RTC Interface documentation for the current list of
 * recognized setting names/values - this is a free-form string key/value pair, not a fixed enum.
 *
 * @param {String} setting_name The setting to change.
 * @param {String} setting_value The new value for the setting.
 *
 * @returns {Bool} `true` if the setting was applied.
 *
 * @function_end
 */

/**
 * @function eos_rtc_set_room_setting
 * @desc **Epic Online Services Function:** [EOS_RTC_SetRoomSetting](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-set-room-setting)
 *
 * Sets a per-room RTC setting by name. See ${function.eos_rtc_set_setting} for the global equivalent.
 *
 * @param {String} local_user_id The Product User ID the room membership belongs to.
 * @param {String} room_name The room to change the setting on.
 * @param {String} setting_name The setting to change.
 * @param {String} setting_value The new value for the setting.
 *
 * @returns {Bool} `true` if the setting was applied.
 *
 * @function_end
 */

/**
 * @function eos_rtc_add_notify_disconnected
 * @desc **Epic Online Services Function:** [EOS_RTC_AddNotifyDisconnected](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-add-notify-disconnected)
 *
 * Registers to be notified when the local user is disconnected from a room. Call
 * ${function.eos_rtc_remove_notify_disconnected} with the returned ID when you no longer need it.
 *
 * [[Note: This always returns an invalid notification ID when used with a Lobby-managed RTC room - use
 * ${function.eos_lobby_add_notify_rtc_room_connection_changed} instead for those.]]
 *
 * @param {String} local_user_id The Product User ID to listen for on this room.
 * @param {String} room_name The room to listen on.
 * @param {Function} [callback] Called every time the local user is disconnected from the room.
 *
 * @returns {Real} A notification ID for use with ${function.eos_rtc_remove_notify_disconnected}.
 *
 * @event callback
 * @desc Fires each time the local user is disconnected from the room.
 * @member {Constant.EpicResult} result_code Why the connection ended, e.g. `EpicResult.Success` (left
 * cleanly), `EpicResult.NoConnection`, `EpicResult.RTC_USER_KICKED`, `EpicResult.ServiceFailure`.
 * @member {String} local_user_id The Product User ID that was disconnected.
 * @member {String} room_name The room that was disconnected from.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_remove_notify_disconnected
 * @desc **Epic Online Services Function:** [EOS_RTC_RemoveNotifyDisconnected](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-remove-notify-disconnected)
 *
 * Unregisters a notification previously registered with ${function.eos_rtc_add_notify_disconnected}.
 *
 * @param {Real} notification_id The notification ID to remove.
 *
 * @function_end
 */

/**
 * @function eos_rtc_add_notify_participant_status_changed
 * @desc **Epic Online Services Function:** [EOS_RTC_AddNotifyParticipantStatusChanged](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-add-notify-participant-status-changed)
 *
 * Registers to be notified when a participant joins or leaves the room, or is added to/removed from an
 * applicable block list. If you register before joining the room, you'll get a notification for every
 * member already present when you join, so you know who's already there.
 *
 * [[Note: For a Lobby-managed RTC room, register this during the ${function.eos_lobby_create_lobby}/
 * ${function.eos_lobby_join_lobby} completion callback (once `result_code` is `EpicResult.Success`) -
 * registering later can miss notifications for members who joined the room in between.]]
 *
 * @param {String} local_user_id The Product User ID to listen for on this room.
 * @param {String} room_name The room to listen on.
 * @param {Function} [callback] Called every time a participant's status changes.
 *
 * @returns {Real} A notification ID for use with
 * ${function.eos_rtc_remove_notify_participant_status_changed}.
 *
 * @event callback
 * @desc Fires each time a participant's status changes.
 * @member {String} local_user_id The Product User ID this notification is registered for.
 * @member {String} room_name The room the participant is in.
 * @member {String} participant_id The Product User ID of the affected participant.
 * @member {Constant.EpicRTCParticipantStatus} participant_status Whether the participant joined or left.
 * @member {Bool} participant_in_blocklist `true` while the SDK is still resolving whether this
 * participant is on an applicable block list - a second notification with this set to `false` follows
 * once resolved, if they aren't blocked.
 * @member {Array[Struct.EpicRTCParticipantMetadata]} participant_metadata Metadata attached to the
 * participant by the RTC backend.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_remove_notify_participant_status_changed
 * @desc **Epic Online Services Function:** [EOS_RTC_RemoveNotifyParticipantStatusChanged](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-remove-notify-participant-status-changed)
 *
 * Unregisters a notification previously registered with
 * ${function.eos_rtc_add_notify_participant_status_changed}.
 *
 * @param {Real} notification_id The notification ID to remove.
 *
 * @function_end
 */

/**
 * @function eos_rtc_add_notify_room_statistics_updated
 * @desc **Epic Online Services Function:** [EOS_RTC_AddNotifyRoomStatisticsUpdated](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-add-notify-room-statistics-updated)
 *
 * Registers to be notified with periodic connection-quality statistics for a room.
 *
 * @param {String} local_user_id The Product User ID to listen for on this room.
 * @param {String} room_name The room to listen on.
 * @param {Function} [callback] Called every time updated statistics are available.
 *
 * @returns {Real} A notification ID for use with
 * ${function.eos_rtc_remove_notify_room_statistics_updated}.
 *
 * @event callback
 * @desc Fires periodically with updated statistics.
 * @member {String} local_user_id The Product User ID this notification is registered for.
 * @member {String} room_name The room the statistics apply to.
 * @member {String} statistic Raw statistics payload, in the format documented by the EOS SDK for this
 * callback.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_remove_notify_room_statistics_updated
 * @desc **Epic Online Services Function:** [EOS_RTC_RemoveNotifyRoomStatisticsUpdated](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-remove-notify-room-statistics-updated)
 *
 * Unregisters a notification previously registered with
 * ${function.eos_rtc_add_notify_room_statistics_updated}.
 *
 * @param {Real} notification_id The notification ID to remove.
 *
 * @function_end
 */

// Functions - RTC Audio

/**
 * @function eos_rtc_audio_update_sending
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_UpdateSending](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-update-sending)
 *
 * Enables, disables, or re-enables the local user's outgoing audio in a room.
 *
 * @param {String} local_user_id The Product User ID sending audio.
 * @param {String} room_name The room to update.
 * @param {Constant.EpicRTCAudioStatus} audio_status The new sending status to request - typically
 * `EpicRTCAudioStatus.Enabled` or `EpicRTCAudioStatus.Disabled`.
 * @param {Function} [callback] Called once the update completes.
 *
 * @event callback
 * @desc Fires once after the update completes.
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the update succeeded.
 * @member {String} local_user_id The Product User ID that requested the update.
 * @member {String} room_name The room that was updated.
 * @member {Constant.EpicRTCAudioStatus} audio_status The resulting sending status.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_update_receiving
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_UpdateReceiving](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-update-receiving)
 *
 * Enables or disables receiving a specific participant's incoming audio.
 *
 * @param {String} local_user_id The Product User ID receiving audio.
 * @param {String} room_name The room the participant is in.
 * @param {String} participant_id The Product User ID whose audio to enable/disable receiving.
 * @param {Bool} audio_enabled `true` to receive this participant's audio, `false` to mute them locally.
 * @param {Function} [callback] Called once the update completes.
 *
 * @event callback
 * @desc Fires once after the update completes.
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the update succeeded.
 * @member {String} local_user_id The Product User ID that requested the update.
 * @member {String} room_name The room the participant is in.
 * @member {String} participant_id The participant whose receiving state was updated.
 * @member {Bool} audio_enabled The resulting receiving state.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_update_sending_volume
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_UpdateSendingVolume](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-update-sending-volume)
 *
 * Sets the local user's outgoing microphone volume for a room.
 *
 * @param {String} local_user_id The Product User ID sending audio.
 * @param {String} room_name The room to update.
 * @param {Real} volume The new sending volume, `0` (muted) to `100` (default/max).
 * @param {Function} [callback] Called once the update completes.
 *
 * @event callback
 * @desc Fires once after the update completes.
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the update succeeded.
 * @member {String} local_user_id The Product User ID that requested the update.
 * @member {String} room_name The room that was updated.
 * @member {Real} volume The resulting sending volume.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_update_receiving_volume
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_UpdateReceivingVolume](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-update-receiving-volume)
 *
 * Sets the local user's overall incoming (playback) volume for a room, applied on top of any individual
 * ${function.eos_rtc_audio_update_participant_volume} settings.
 *
 * @param {String} local_user_id The Product User ID receiving audio.
 * @param {String} room_name The room to update.
 * @param {Real} volume The new receiving volume, `0` (muted) to `100` (default/max).
 * @param {Function} [callback] Called once the update completes.
 *
 * @event callback
 * @desc Fires once after the update completes.
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the update succeeded.
 * @member {String} local_user_id The Product User ID that requested the update.
 * @member {String} room_name The room that was updated.
 * @member {Real} volume The resulting receiving volume.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_update_participant_volume
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_UpdateParticipantVolume](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-update-participant-volume)
 *
 * Sets the local user's incoming volume for one specific participant, on top of the overall
 * ${function.eos_rtc_audio_update_receiving_volume} setting.
 *
 * @param {String} local_user_id The Product User ID receiving audio.
 * @param {String} room_name The room the participant is in.
 * @param {String} participant_id The Product User ID whose incoming volume to change.
 * @param {Real} volume The new volume for this participant, `0` (muted) to `100` (default/max).
 * @param {Function} [callback] Called once the update completes.
 *
 * @event callback
 * @desc Fires once after the update completes.
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the update succeeded.
 * @member {String} local_user_id The Product User ID that requested the update.
 * @member {String} room_name The room the participant is in.
 * @member {String} participant_id The participant whose volume was updated.
 * @member {Real} volume The resulting volume for that participant.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_get_input_devices_count
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_GetInputDevicesCount](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-get-input-devices-count)
 *
 * Returns how many audio input (microphone) devices are known. Call
 * ${function.eos_rtc_audio_query_input_devices} first to (re)populate this list.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_copy_input_device_info_by_index
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_CopyInputDeviceInformationByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-copy-input-device-information-by-index)
 *
 * Copies information about one audio input device by index (`0` to
 * ${function.eos_rtc_audio_get_input_devices_count}` - 1`).
 *
 * @param {Real} index The index of the device to copy.
 *
 * @returns {Struct.EpicRTCAudioInputDeviceInfo} `undefined` if `index` is out of range.
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_get_output_devices_count
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_GetOutputDevicesCount](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-get-output-devices-count)
 *
 * Returns how many audio output (speaker/headphone) devices are known. Call
 * ${function.eos_rtc_audio_query_output_devices} first to (re)populate this list.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_copy_output_device_info_by_index
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_CopyOutputDeviceInformationByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-copy-output-device-information-by-index)
 *
 * Copies information about one audio output device by index (`0` to
 * ${function.eos_rtc_audio_get_output_devices_count}` - 1`).
 *
 * @param {Real} index The index of the device to copy.
 *
 * @returns {Struct.EpicRTCAudioOutputDeviceInfo} `undefined` if `index` is out of range.
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_query_input_devices
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_QueryInputDevicesInformation](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-query-input-devices-information)
 *
 * Refreshes the local audio input device list. Call this before reading
 * ${function.eos_rtc_audio_get_input_devices_count}/${function.eos_rtc_audio_copy_input_device_info_by_index}.
 *
 * @param {Function} [callback] Called once the query completes.
 *
 * @event callback
 * @desc Fires once after the device list has been refreshed.
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the query succeeded.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_query_output_devices
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_QueryOutputDevicesInformation](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-query-output-devices-information)
 *
 * Refreshes the local audio output device list. Call this before reading
 * ${function.eos_rtc_audio_get_output_devices_count}/${function.eos_rtc_audio_copy_output_device_info_by_index}.
 *
 * @param {Function} [callback] Called once the query completes.
 *
 * @event callback
 * @desc Fires once after the device list has been refreshed.
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the query succeeded.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_set_input_device_settings
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_SetInputDeviceSettings](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-set-input-device-settings)
 *
 * Selects the audio input device to use and configures platform-level acoustic echo cancellation for it.
 *
 * @param {String} local_user_id The Product User ID to change the input device for.
 * @param {String} real_device_id The device ID to select (from ${function.eos_rtc_audio_copy_input_device_info_by_index}), or an empty string for the system default.
 * @param {Bool} platform_aec `true` to enable the platform's own acoustic echo cancellation.
 * @param {Function} [callback] Called once the settings are applied.
 *
 * @event callback
 * @desc Fires once after the settings are applied.
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the settings were applied.
 * @member {String} real_device_id The device ID that ended up selected.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_set_output_device_settings
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_SetOutputDeviceSettings](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-set-output-device-settings)
 *
 * Selects the audio output device to use.
 *
 * @param {String} local_user_id The Product User ID to change the output device for.
 * @param {String} real_device_id The device ID to select (from ${function.eos_rtc_audio_copy_output_device_info_by_index}), or an empty string for the system default.
 * @param {Function} [callback] Called once the settings are applied.
 *
 * @event callback
 * @desc Fires once after the settings are applied.
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the settings were applied.
 * @member {String} real_device_id The device ID that ended up selected.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_add_notify_participant_updated
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_AddNotifyParticipantUpdated](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-add-notify-participant-updated)
 *
 * Registers to be notified when a participant starts/stops speaking or their audio status changes.
 *
 * @param {String} local_user_id The Product User ID to listen for on this room.
 * @param {String} room_name The room to listen on.
 * @param {Function} [callback] Called every time a participant's audio state changes.
 *
 * @returns {Real} A notification ID for use with
 * ${function.eos_rtc_audio_remove_notify_participant_updated}.
 *
 * @event callback
 * @desc Fires each time a participant's audio state changes.
 * @member {String} local_user_id The Product User ID this notification is registered for.
 * @member {String} room_name The room the participant is in.
 * @member {String} participant_id The affected participant.
 * @member {Bool} speaking `true` if the participant is currently detected as speaking.
 * @member {Constant.EpicRTCAudioStatus} audio_status The participant's current audio status.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_remove_notify_participant_updated
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_RemoveNotifyParticipantUpdated](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-remove-notify-participant-updated)
 *
 * Unregisters a notification previously registered with
 * ${function.eos_rtc_audio_add_notify_participant_updated}.
 *
 * @param {Real} notification_id The notification ID to remove.
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_add_notify_audio_devices_changed
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_AddNotifyAudioDevicesChanged](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-add-notify-audio-devices-changed)
 *
 * Registers to be notified when the system's available audio devices change (e.g. headphones plugged
 * in/unplugged). Not tied to a specific room or user.
 *
 * @param {Function} [callback] Called every time the available audio devices change.
 *
 * @returns {Real} A notification ID for use with
 * ${function.eos_rtc_audio_remove_notify_audio_devices_changed}.
 *
 * @event callback
 * @desc Fires each time the available audio devices change.
 * @member {Bool} triggered Always `true` - this notification carries no further payload, treat its
 * firing as a signal to re-query devices via ${function.eos_rtc_audio_query_input_devices}/
 * ${function.eos_rtc_audio_query_output_devices}.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_remove_notify_audio_devices_changed
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_RemoveNotifyAudioDevicesChanged](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-remove-notify-audio-devices-changed)
 *
 * Unregisters a notification previously registered with
 * ${function.eos_rtc_audio_add_notify_audio_devices_changed}.
 *
 * @param {Real} notification_id The notification ID to remove.
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_add_notify_audio_input_state
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_AddNotifyAudioInputState](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-add-notify-audio-input-state)
 *
 * Registers to be notified when the local user's microphone input state changes (e.g. starts/stops
 * recording, or fails).
 *
 * @param {String} local_user_id The Product User ID to listen for.
 * @param {String} room_name The room this is registered on.
 * @param {Function} [callback] Called every time the input state changes.
 *
 * @returns {Real} A notification ID for use with
 * ${function.eos_rtc_audio_remove_notify_audio_input_state}.
 *
 * @event callback
 * @desc Fires each time the local user's audio input state changes.
 * @member {String} local_user_id The Product User ID this notification is registered for.
 * @member {String} room_name The room the state applies to.
 * @member {Constant.EpicRTCAudioInputStatus} status The new input state.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_remove_notify_audio_input_state
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_RemoveNotifyAudioInputState](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-remove-notify-audio-input-state)
 *
 * Unregisters a notification previously registered with
 * ${function.eos_rtc_audio_add_notify_audio_input_state}.
 *
 * @param {Real} notification_id The notification ID to remove.
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_add_notify_audio_output_state
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_AddNotifyAudioOutputState](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-add-notify-audio-output-state)
 *
 * Registers to be notified when the local user's audio output (playback) state changes.
 *
 * @param {String} local_user_id The Product User ID to listen for.
 * @param {String} room_name The room this is registered on.
 * @param {Function} [callback] Called every time the output state changes.
 *
 * @returns {Real} A notification ID for use with
 * ${function.eos_rtc_audio_remove_notify_audio_output_state}.
 *
 * @event callback
 * @desc Fires each time the local user's audio output state changes.
 * @member {String} local_user_id The Product User ID this notification is registered for.
 * @member {String} room_name The room the state applies to.
 * @member {Constant.EpicRTCAudioOutputStatus} status The new output state.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_remove_notify_audio_output_state
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_RemoveNotifyAudioOutputState](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-remove-notify-audio-output-state)
 *
 * Unregisters a notification previously registered with
 * ${function.eos_rtc_audio_add_notify_audio_output_state}.
 *
 * @param {Real} notification_id The notification ID to remove.
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_send_audio
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_SendAudio](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-send-audio)
 *
 * Sends manually-captured PCM audio into the room. Only meaningful for a room joined with
 * `manual_audio_input` set to `true` on ${function.eos_rtc_join_room} - otherwise the SDK is already
 * capturing from the platform's default input device and this call has nothing to contribute.
 *
 * @param {String} local_user_id The Product User ID sending audio.
 * @param {String} room_name The room to send audio into.
 * @param {Real} sample_rate The sample rate of `frames`, in Hz (e.g. `48000`).
 * @param {Real} channels The channel count of `frames` (e.g. `1` for mono, `2` for stereo).
 * @param {Real} frames_count The number of frames (samples per channel) in `frames`.
 * @param {Buffer} frames Signed 16-bit PCM samples, interleaved by channel. Must hold at least
 * `frames_count * channels * 2` bytes.
 *
 * @returns {Bool} `true` if the audio was accepted.
 *
 * @example
 * ```gml
 * var _frame_count = 480;
 * var _channels = 1;
 * var _buffer = buffer_create(_frame_count * _channels * 2, buffer_fixed, 2);
 * // ... fill _buffer with captured int16 PCM samples ...
 * eos_rtc_audio_send_audio(local_user_id, room_name, 48000, _channels, _frame_count, _buffer);
 * buffer_delete(_buffer);
 * ```
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_add_notify_audio_before_send
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_AddNotifyAudioBeforeSend](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-add-notify-audio-before-send)
 *
 * Registers to observe the local user's outgoing audio right before it's sent, e.g. for a mic-activity
 * meter or your own recording. The callback only carries metadata (sample rate/channels/frame count and
 * a `handle_id`) - call ${function.eos_rtc_audio_before_send_data_fetch} with that `handle_id` to copy
 * out the actual PCM frames.
 *
 * [[Warning: Fetch the data synchronously inside your callback, on the same frame it fires.
 * `handle_id` is only valid until fetched **or until this same registration fires again**, whichever
 * happens first - deferring the fetch risks the frames already being gone.]]
 *
 * [[Warning: The underlying EOS SDK documents this hook as a **synchronous, in-place modification
 * point** - natively, you could edit `EOS_RTCAudio_AudioBuffer` in place to apply a custom filter/effect
 * before the SDK sends it. This extension's `GMFunction` callback model always runs your GML on the next
 * frame, so that in-place modification is **not achievable through this binding** - you can only observe
 * a copy of the frames after the fact, not alter what actually gets sent. If you need real-time audio
 * processing, do it before calling ${function.eos_rtc_audio_send_audio} in manual-audio-input mode.]]
 *
 * [[Note: This callback can fire from an internal SDK thread, not just the main thread during
 * ${function.eos_platform_tick} - the same caveat as ${function.eos_logging_set_callback} (see
 * ${module.logging}). Firing the `GMFunction` itself is still safe from any thread; this only matters if
 * your handler code assumes it's always running in step with your own game logic.]]
 *
 * @param {String} local_user_id The Product User ID to listen for.
 * @param {String} room_name The room this is registered on.
 * @param {Function} [callback] Called every time outgoing audio is about to be sent.
 *
 * @returns {Real} A notification ID for use with
 * ${function.eos_rtc_audio_remove_notify_audio_before_send}.
 *
 * @event callback
 * @desc Fires each time outgoing audio is about to be sent.
 * @member {String} local_user_id The Product User ID this notification is registered for.
 * @member {String} room_name The room the audio is being sent to.
 * @member {Real} sample_rate The sample rate of the pending frames, in Hz.
 * @member {Real} channels The channel count of the pending frames.
 * @member {Real} frames_count The number of frames available.
 * @member {Real} handle_id Pass to ${function.eos_rtc_audio_before_send_data_fetch} to copy out the
 * actual PCM bytes (`frames_count * channels * 2` bytes).
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_remove_notify_audio_before_send
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_RemoveNotifyAudioBeforeSend](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-remove-notify-audio-before-send)
 *
 * Unregisters a notification previously registered with
 * ${function.eos_rtc_audio_add_notify_audio_before_send}.
 *
 * @param {Real} notification_id The notification ID to remove.
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_before_send_data_fetch
 * @desc Copies the PCM frames referenced by a `handle_id` from
 * ${event.callback} on ${function.eos_rtc_audio_add_notify_audio_before_send} into `out_buffer`, and
 * releases the extension's copy of them. `out_buffer` must be at least `frames_count * channels * 2`
 * bytes (from the same callback firing).
 *
 * @param {Real} handle_id The handle from the `EpicRTCAudioBeforeSendCallbackInfo` callback firing.
 * @param {Buffer} out_buffer Receives the raw signed 16-bit PCM samples.
 *
 * @returns {Bool} `false` if `handle_id` is unknown, already fetched, or `out_buffer` is too small.
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_add_notify_audio_before_render
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_AddNotifyAudioBeforeRender](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-before-render)
 *
 * Registers to observe a participant's incoming audio right before it's rendered (played back), e.g.
 * for a per-participant activity meter or your own custom playback. As with
 * ${function.eos_rtc_audio_add_notify_audio_before_send}, the callback only carries metadata - call
 * ${function.eos_rtc_audio_before_render_data_fetch} with the given `handle_id` to copy out the PCM
 * frames.
 *
 * [[Warning: Fetch the data synchronously inside your callback, on the same frame it fires.
 * `handle_id` is only valid until fetched **or until this same registration fires again**, whichever
 * happens first - this notification can deliver different participants back-to-back, so a deferred
 * fetch risks reading a different participant's frames than the metadata you received.]]
 *
 * [[Warning: Like ${function.eos_rtc_audio_add_notify_audio_before_send}, the EOS SDK documents this as
 * a synchronous in-place modification point (for custom mixing/effects), which this extension's
 * next-frame `GMFunction` callback model cannot provide - you can only observe a copy of the frames
 * after they've already been (or are about to be) rendered, not alter the actual playback.]]
 *
 * [[Note: Like ${function.eos_rtc_audio_add_notify_audio_before_send}, this callback can fire from an
 * internal SDK thread rather than the main thread - see ${module.logging}'s
 * ${function.eos_logging_set_callback} note for the same caveat.]]
 *
 * @param {String} local_user_id The Product User ID to listen for.
 * @param {String} room_name The room this is registered on.
 * @param {Bool} unmixed_audio `true` to receive each remote participant's audio separately;
 * `false` to receive the already-mixed room audio.
 * @param {Function} [callback] Called every time incoming audio is about to be rendered.
 *
 * @returns {Real} A notification ID for use with
 * ${function.eos_rtc_audio_remove_notify_audio_before_render}.
 *
 * @event callback
 * @desc Fires each time incoming audio is about to be rendered.
 * @member {String} local_user_id The Product User ID this notification is registered for.
 * @member {String} room_name The room the audio belongs to.
 * @member {String} participant_id The participant this audio came from (meaningful when
 * `unmixed_audio` was `true`; otherwise a placeholder for the mixed room output).
 * @member {Real} sample_rate The sample rate of the pending frames, in Hz.
 * @member {Real} channels The channel count of the pending frames.
 * @member {Real} frames_count The number of frames available.
 * @member {Real} handle_id Pass to ${function.eos_rtc_audio_before_render_data_fetch} to copy out the
 * actual PCM bytes (`frames_count * channels * 2` bytes).
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_remove_notify_audio_before_render
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_RemoveNotifyAudioBeforeRender](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-remove-notify-audio-before-render)
 *
 * Unregisters a notification previously registered with
 * ${function.eos_rtc_audio_add_notify_audio_before_render}.
 *
 * @param {Real} notification_id The notification ID to remove.
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_before_render_data_fetch
 * @desc Copies the PCM frames referenced by a `handle_id` from
 * ${event.callback} on ${function.eos_rtc_audio_add_notify_audio_before_render} into `out_buffer`, and
 * releases the extension's copy of them. `out_buffer` must be at least `frames_count * channels * 2`
 * bytes (from the same callback firing).
 *
 * @param {Real} handle_id The handle from the `EpicRTCAudioBeforeRenderCallbackInfo` callback firing.
 * @param {Buffer} out_buffer Receives the raw signed 16-bit PCM samples.
 *
 * @returns {Bool} `false` if `handle_id` is unknown, already fetched, or `out_buffer` is too small.
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_register_platform_user
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_RegisterPlatformUser](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-register-platform-user)
 *
 * Registers a platform-specific user ID with the RTC audio system, required on some platforms before
 * that user's audio can be captured/rendered.
 *
 * @param {String} rtc_platform_user_id The platform-specific user ID to register.
 * @param {Function} [callback] Called once registration completes.
 *
 * @event callback
 * @desc Fires once after registration completes.
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if registration succeeded.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_audio_unregister_platform_user
 * @desc **Epic Online Services Function:** [EOS_RTCAudio_UnregisterPlatformUser](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-audio-unregister-platform-user)
 *
 * Unregisters a platform-specific user ID previously registered with
 * ${function.eos_rtc_audio_register_platform_user}.
 *
 * @param {String} rtc_platform_user_id The platform-specific user ID to unregister.
 * @param {Function} [callback] Called once unregistration completes.
 *
 * @event callback
 * @desc Fires once after unregistration completes.
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if unregistration succeeded.
 * @event_end
 *
 * @function_end
 */

// Functions - RTC Data (binary data channel, alongside audio in the same room)

/**
 * @function eos_rtc_data_send_data
 * @desc **Epic Online Services Function:** [EOS_RTCData_SendData](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-data-send-data)
 *
 * Sends a data message to every other participant in the room over the RTC data channel. Sending must
 * first be enabled with ${function.eos_rtc_data_update_sending}.
 *
 * [[Note: The RTC data channel restricts how much data a player can send - see the
 * [RTC Data Interface](https://dev.epicgames.com/docs/game-services/real-time-communication-interface/rtc-data-interface#rtc-data-service-limits)
 * documentation for the current limits.]]
 *
 * @param {String} local_user_id The Product User ID sending the message.
 * @param {String} room_name The room to send to.
 * @param {Buffer} data The raw bytes to send.
 * @param {Real} bytes The number of bytes from `data` to send.
 *
 * @returns {Constant.EpicResult} `EpicResult.Success` if the message was accepted for sending.
 *
 * @function_end
 */

/**
 * @function eos_rtc_data_update_sending
 * @desc **Epic Online Services Function:** [EOS_RTCData_UpdateSending](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-data-update-sending)
 *
 * Enables or disables the local user's ability to send data messages in a room.
 *
 * @param {String} local_user_id The Product User ID sending data.
 * @param {String} room_name The room to update.
 * @param {Bool} data_enabled `true` to allow sending data, `false` to disable it.
 * @param {Function} [callback] Called once the update completes.
 *
 * @event callback
 * @desc Fires once after the update completes.
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the update succeeded.
 * @member {String} local_user_id The Product User ID that requested the update.
 * @member {String} room_name The room that was updated.
 * @member {Bool} data_enabled The resulting sending state.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_data_update_receiving
 * @desc **Epic Online Services Function:** [EOS_RTCData_UpdateReceiving](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-data-update-receiving)
 *
 * Enables or disables receiving data messages from one participant, or from everyone in the room.
 *
 * @param {String} local_user_id The Product User ID receiving data.
 * @param {String} room_name The room the participant is in.
 * @param {String} participant_id The Product User ID to change the receiving state for, or an empty
 * string to change it for every participant in the room at once.
 * @param {Bool} data_enabled `true` to receive data messages, `false` to ignore them.
 * @param {Function} [callback] Called once the update completes.
 *
 * @event callback
 * @desc Fires once after the update completes.
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the update succeeded.
 * @member {String} local_user_id The Product User ID that requested the update.
 * @member {String} room_name The room that was updated.
 * @member {String} participant_id The participant this update applies to.
 * @member {Bool} data_enabled The resulting receiving state.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_data_add_notify_data_received
 * @desc **Epic Online Services Function:** [EOS_RTCData_AddNotifyDataReceived](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-data-add-notify-data-received)
 *
 * Registers to be notified when a data message is received from another participant. As with the audio
 * before-send/before-render hooks, the callback only carries metadata (`data_length_bytes` and a
 * `handle_id`) - call ${function.eos_rtc_data_received_data_fetch} with that `handle_id` to copy out the
 * actual bytes.
 *
 * [[Warning: Fetch the data synchronously inside your callback, on the same frame it fires. `handle_id`
 * is only valid until fetched **or until this same registration fires again**, whichever happens first -
 * this notification can deliver different participants back-to-back, so a deferred fetch risks reading a
 * different participant's bytes than the metadata you received.]]
 *
 * @param {String} local_user_id The Product User ID to listen for.
 * @param {String} room_name The room this is registered on.
 * @param {Function} [callback] Called every time a data message is received.
 *
 * @returns {Real} A notification ID for use with
 * ${function.eos_rtc_data_remove_notify_data_received}.
 *
 * @event callback
 * @desc Fires each time a data message is received.
 * @member {String} local_user_id The Product User ID this notification is registered for.
 * @member {String} room_name The room the message was sent in.
 * @member {String} participant_id The participant who sent the message.
 * @member {Real} data_length_bytes The size of the received message, in bytes.
 * @member {Real} handle_id Pass to ${function.eos_rtc_data_received_data_fetch} to copy out the actual
 * bytes (`data_length_bytes` bytes).
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_data_remove_notify_data_received
 * @desc **Epic Online Services Function:** [EOS_RTCData_RemoveNotifyDataReceived](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-data-remove-notify-data-received)
 *
 * Unregisters a notification previously registered with
 * ${function.eos_rtc_data_add_notify_data_received}.
 *
 * @param {Real} notification_id The notification ID to remove.
 *
 * @function_end
 */

/**
 * @function eos_rtc_data_received_data_fetch
 * @desc Copies the raw bytes referenced by a `handle_id` from ${event.callback} on
 * ${function.eos_rtc_data_add_notify_data_received} into `out_buffer`, and releases the extension's copy
 * of them. `out_buffer` must be at least `data_length_bytes` (from the same callback firing).
 *
 * @param {Real} handle_id The handle from the `EpicRTCDataReceivedCallbackInfo` callback firing.
 * @param {Buffer} out_buffer Receives the raw received bytes.
 *
 * @returns {Bool} `false` if `handle_id` is unknown, already fetched, or `out_buffer` is too small.
 *
 * @function_end
 */

/**
 * @function eos_rtc_data_add_notify_participant_updated
 * @desc **Epic Online Services Function:** [EOS_RTCData_AddNotifyParticipantUpdated](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-data-add-notify-participant-updated)
 *
 * Registers to be notified when a participant's data-channel status changes (e.g. becomes able/unable
 * to exchange data messages).
 *
 * @param {String} local_user_id The Product User ID to listen for.
 * @param {String} room_name The room this is registered on.
 * @param {Function} [callback] Called every time a participant's data-channel status changes.
 *
 * @returns {Real} A notification ID for use with
 * ${function.eos_rtc_data_remove_notify_participant_updated}.
 *
 * @event callback
 * @desc Fires each time a participant's data-channel status changes.
 * @member {String} local_user_id The Product User ID this notification is registered for.
 * @member {String} room_name The room the participant is in.
 * @member {String} participant_id The affected participant.
 * @member {Constant.EpicRTCDataStatus} data_status The participant's new data-channel status.
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_rtc_data_remove_notify_participant_updated
 * @desc **Epic Online Services Function:** [EOS_RTCData_RemoveNotifyParticipantUpdated](https://dev.epicgames.com/docs/api-ref/functions/eos-rtc-data-remove-notify-participant-updated)
 *
 * Unregisters a notification previously registered with
 * ${function.eos_rtc_data_add_notify_participant_updated}.
 *
 * @param {Real} notification_id The notification ID to remove.
 *
 * @function_end
 */

// Structs

/**
 * @struct EpicRTCOption
 * @desc A single room-level key/value option, as reported by ${function.eos_rtc_join_room}'s callback.
 *
 * @member {String} key
 * @member {String} value
 *
 * @struct_end
 */

/**
 * @struct EpicRTCParticipantMetadata
 * @desc A single key/value metadata entry attached to a room participant.
 *
 * @member {String} key
 * @member {String} value
 *
 * @struct_end
 */

/**
 * @struct EpicRTCJoinRoomCallbackInfo
 * @desc Result of ${function.eos_rtc_join_room}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {Array[Struct.EpicRTCOption]} room_options
 *
 * @struct_end
 */

/**
 * @struct EpicRTCLeaveRoomCallbackInfo
 * @desc Result of ${function.eos_rtc_leave_room}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} room_name
 *
 * @struct_end
 */

/**
 * @struct EpicRTCBlockParticipantCallbackInfo
 * @desc Result of ${function.eos_rtc_block_participant}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {String} participant_id
 * @member {Bool} blocked
 *
 * @struct_end
 */

/**
 * @struct EpicRTCDisconnectedCallbackInfo
 * @desc Payload of ${function.eos_rtc_add_notify_disconnected}'s ${event.callback}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} room_name
 *
 * @struct_end
 */

/**
 * @struct EpicRTCParticipantStatusChangedCallbackInfo
 * @desc Payload of ${function.eos_rtc_add_notify_participant_status_changed}'s ${event.callback}.
 *
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {String} participant_id
 * @member {Constant.EpicRTCParticipantStatus} participant_status
 * @member {Bool} participant_in_blocklist
 * @member {Array[Struct.EpicRTCParticipantMetadata]} participant_metadata
 *
 * @struct_end
 */

/**
 * @struct EpicRTCRoomStatisticsUpdatedInfo
 * @desc Payload of ${function.eos_rtc_add_notify_room_statistics_updated}'s ${event.callback}.
 *
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {String} statistic
 *
 * @struct_end
 */

/**
 * @struct EpicRTCAudioParticipantUpdatedCallbackInfo
 * @desc Payload of ${function.eos_rtc_audio_add_notify_participant_updated}'s ${event.callback}.
 *
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {String} participant_id
 * @member {Bool} speaking
 * @member {Constant.EpicRTCAudioStatus} audio_status
 *
 * @struct_end
 */

/**
 * @struct EpicRTCAudioDevicesChangedCallbackInfo
 * @desc Payload of ${function.eos_rtc_audio_add_notify_audio_devices_changed}'s ${event.callback}.
 *
 * @member {Bool} triggered
 *
 * @struct_end
 */

/**
 * @struct EpicRTCAudioInputStateCallbackInfo
 * @desc Payload of ${function.eos_rtc_audio_add_notify_audio_input_state}'s ${event.callback}.
 *
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {Constant.EpicRTCAudioInputStatus} status
 *
 * @struct_end
 */

/**
 * @struct EpicRTCAudioOutputStateCallbackInfo
 * @desc Payload of ${function.eos_rtc_audio_add_notify_audio_output_state}'s ${event.callback}.
 *
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {Constant.EpicRTCAudioOutputStatus} status
 *
 * @struct_end
 */

/**
 * @struct EpicRTCAudioUpdateSendingCallbackInfo
 * @desc Result of ${function.eos_rtc_audio_update_sending}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {Constant.EpicRTCAudioStatus} audio_status
 *
 * @struct_end
 */

/**
 * @struct EpicRTCAudioUpdateReceivingCallbackInfo
 * @desc Result of ${function.eos_rtc_audio_update_receiving}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {String} participant_id
 * @member {Bool} audio_enabled
 *
 * @struct_end
 */

/**
 * @struct EpicRTCAudioUpdateSendingVolumeCallbackInfo
 * @desc Result of ${function.eos_rtc_audio_update_sending_volume}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {Real} volume
 *
 * @struct_end
 */

/**
 * @struct EpicRTCAudioUpdateReceivingVolumeCallbackInfo
 * @desc Result of ${function.eos_rtc_audio_update_receiving_volume}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {Real} volume
 *
 * @struct_end
 */

/**
 * @struct EpicRTCAudioUpdateParticipantVolumeCallbackInfo
 * @desc Result of ${function.eos_rtc_audio_update_participant_volume}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {String} participant_id
 * @member {Real} volume
 *
 * @struct_end
 */

/**
 * @struct EpicRTCAudioInputDeviceInfo
 * @desc An audio input device, from ${function.eos_rtc_audio_copy_input_device_info_by_index}.
 *
 * @member {Bool} default_device
 * @member {String} device_id
 * @member {String} device_name
 *
 * @struct_end
 */

/**
 * @struct EpicRTCAudioOutputDeviceInfo
 * @desc An audio output device, from ${function.eos_rtc_audio_copy_output_device_info_by_index}.
 *
 * @member {Bool} default_device
 * @member {String} device_id
 * @member {String} device_name
 *
 * @struct_end
 */

/**
 * @struct EpicRTCAudioSetInputDeviceSettingsCallbackInfo
 * @desc Result of ${function.eos_rtc_audio_set_input_device_settings}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} real_device_id
 *
 * @struct_end
 */

/**
 * @struct EpicRTCAudioSetOutputDeviceSettingsCallbackInfo
 * @desc Result of ${function.eos_rtc_audio_set_output_device_settings}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} real_device_id
 *
 * @struct_end
 */

/**
 * @struct EpicRTCAudioQueryInputDevicesCallbackInfo
 * @desc Result of ${function.eos_rtc_audio_query_input_devices}.
 *
 * @member {Constant.EpicResult} result_code
 *
 * @struct_end
 */

/**
 * @struct EpicRTCAudioQueryOutputDevicesCallbackInfo
 * @desc Result of ${function.eos_rtc_audio_query_output_devices}.
 *
 * @member {Constant.EpicResult} result_code
 *
 * @struct_end
 */

/**
 * @struct EpicRTCAudioBeforeSendCallbackInfo
 * @desc Payload of ${function.eos_rtc_audio_add_notify_audio_before_send}'s ${event.callback}. Metadata
 * only - fetch the actual PCM bytes with ${function.eos_rtc_audio_before_send_data_fetch}.
 *
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {Real} sample_rate
 * @member {Real} channels
 * @member {Real} frames_count
 * @member {Real} handle_id
 *
 * @struct_end
 */

/**
 * @struct EpicRTCAudioBeforeRenderCallbackInfo
 * @desc Payload of ${function.eos_rtc_audio_add_notify_audio_before_render}'s ${event.callback}.
 * Metadata only - fetch the actual PCM bytes with ${function.eos_rtc_audio_before_render_data_fetch}.
 *
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {String} participant_id
 * @member {Real} sample_rate
 * @member {Real} channels
 * @member {Real} frames_count
 * @member {Real} handle_id
 *
 * @struct_end
 */

/**
 * @struct EpicRTCAudioRegisterPlatformUserCallbackInfo
 * @desc Result of ${function.eos_rtc_audio_register_platform_user}.
 *
 * @member {Constant.EpicResult} result_code
 *
 * @struct_end
 */

/**
 * @struct EpicRTCAudioUnregisterPlatformUserCallbackInfo
 * @desc Result of ${function.eos_rtc_audio_unregister_platform_user}.
 *
 * @member {Constant.EpicResult} result_code
 *
 * @struct_end
 */

/**
 * @struct EpicRTCDataParticipantUpdatedCallbackInfo
 * @desc Payload of ${function.eos_rtc_data_add_notify_participant_updated}'s ${event.callback}.
 *
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {String} participant_id
 * @member {Constant.EpicRTCDataStatus} data_status
 *
 * @struct_end
 */

/**
 * @struct EpicRTCDataReceivedCallbackInfo
 * @desc Payload of ${function.eos_rtc_data_add_notify_data_received}'s ${event.callback}. Metadata
 * only - fetch the actual bytes with ${function.eos_rtc_data_received_data_fetch}.
 *
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {String} participant_id
 * @member {Real} data_length_bytes
 * @member {Real} handle_id
 *
 * @struct_end
 */

/**
 * @struct EpicRTCDataUpdateSendingCallbackInfo
 * @desc Result of ${function.eos_rtc_data_update_sending}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {Bool} data_enabled
 *
 * @struct_end
 */

/**
 * @struct EpicRTCDataUpdateReceivingCallbackInfo
 * @desc Result of ${function.eos_rtc_data_update_receiving}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {String} participant_id
 * @member {Bool} data_enabled
 *
 * @struct_end
 */

// Constants

/**
 * @const EpicRTCParticipantStatus
 * @desc Whether a room participant joined or left. See
 * ${function.eos_rtc_add_notify_participant_status_changed}.
 *
 * @member Joined
 * @member Left
 *
 * @const_end
 */

/**
 * @const EpicRTCAudioStatus
 * @desc A participant's (or room's) audio sending/receiving status.
 *
 * @member Unsupported
 * @member Enabled
 * @member Disabled
 * @member AdminDisabled
 * @member NotListeningDisabled
 *
 * @const_end
 */

/**
 * @const EpicRTCAudioInputStatus
 * @desc The local user's microphone input state. See
 * ${function.eos_rtc_audio_add_notify_audio_input_state}.
 *
 * @member Idle
 * @member Recording
 * @member RecordingSilent
 * @member RecordingDisconnected
 * @member Failed
 *
 * @const_end
 */

/**
 * @const EpicRTCAudioOutputStatus
 * @desc The local user's audio output (playback) state. See
 * ${function.eos_rtc_audio_add_notify_audio_output_state}.
 *
 * @member Idle
 * @member Playing
 * @member Failed
 *
 * @const_end
 */

/**
 * @const EpicRTCDataStatus
 * @desc A participant's data-channel status. See
 * ${function.eos_rtc_data_add_notify_participant_updated}.
 *
 * @member Unsupported
 * @member Enabled
 * @member Disabled
 *
 * @const_end
 */

/**
 * @const EpicRTCBackgroundMode
 * @desc How the RTC system should behave when the application goes to the background. This is a
 * platform-level `EOS_Platform_RTCOptions` setting configured when the SDK platform handle is created -
 * this extension's ${function.eos_platform_create} binding does not currently expose it, so this enum's
 * values aren't reachable from any function in this module today. Documented here for completeness
 * since it's part of the generated API surface.
 *
 * @member LeaveRooms
 * @member KeepRoomsAlive
 *
 * @const_end
 */

/**
 * @module rtc
 * @title RTC
 * @desc **Epic Online Services Interface:** [RTC Interface](https://dev.epicgames.com/docs/api-ref/interfaces/rtc)
 *
 * Real-time voice and peer-to-peer data messaging for a room of participants - typically the members of
 * a ${module.lobbies}/${module.sessions} room, though a room can also be joined directly. Covers three
 * related areas: joining/leaving rooms and tracking participants (RTC core), microphone/speaker control
 * (RTC Audio), and a binary data channel alongside the audio (RTC Data).
 *
 * [[Note: The extension initialises the RTC interface automatically along with everything else - see
 * ${module.platform}.]]
 *
 * @section_func
 * @desc RTC core - rooms and participants:
 * @ref eos_rtc_join_room
 * @ref eos_rtc_leave_room
 * @ref eos_rtc_block_participant
 * @ref eos_rtc_set_setting
 * @ref eos_rtc_set_room_setting
 * @ref eos_rtc_add_notify_disconnected
 * @ref eos_rtc_remove_notify_disconnected
 * @ref eos_rtc_add_notify_participant_status_changed
 * @ref eos_rtc_remove_notify_participant_status_changed
 * @ref eos_rtc_add_notify_room_statistics_updated
 * @ref eos_rtc_remove_notify_room_statistics_updated
 *
 * @desc RTC Audio - microphone/speaker control:
 * @ref eos_rtc_audio_update_sending
 * @ref eos_rtc_audio_update_receiving
 * @ref eos_rtc_audio_update_sending_volume
 * @ref eos_rtc_audio_update_receiving_volume
 * @ref eos_rtc_audio_update_participant_volume
 * @ref eos_rtc_audio_get_input_devices_count
 * @ref eos_rtc_audio_copy_input_device_info_by_index
 * @ref eos_rtc_audio_get_output_devices_count
 * @ref eos_rtc_audio_copy_output_device_info_by_index
 * @ref eos_rtc_audio_query_input_devices
 * @ref eos_rtc_audio_query_output_devices
 * @ref eos_rtc_audio_set_input_device_settings
 * @ref eos_rtc_audio_set_output_device_settings
 * @ref eos_rtc_audio_add_notify_participant_updated
 * @ref eos_rtc_audio_remove_notify_participant_updated
 * @ref eos_rtc_audio_add_notify_audio_devices_changed
 * @ref eos_rtc_audio_remove_notify_audio_devices_changed
 * @ref eos_rtc_audio_add_notify_audio_input_state
 * @ref eos_rtc_audio_remove_notify_audio_input_state
 * @ref eos_rtc_audio_add_notify_audio_output_state
 * @ref eos_rtc_audio_remove_notify_audio_output_state
 * @ref eos_rtc_audio_send_audio
 * @ref eos_rtc_audio_add_notify_audio_before_send
 * @ref eos_rtc_audio_remove_notify_audio_before_send
 * @ref eos_rtc_audio_before_send_data_fetch
 * @ref eos_rtc_audio_add_notify_audio_before_render
 * @ref eos_rtc_audio_remove_notify_audio_before_render
 * @ref eos_rtc_audio_before_render_data_fetch
 * @ref eos_rtc_audio_register_platform_user
 * @ref eos_rtc_audio_unregister_platform_user
 *
 * @desc RTC Data - binary data channel:
 * @ref eos_rtc_data_send_data
 * @ref eos_rtc_data_update_sending
 * @ref eos_rtc_data_update_receiving
 * @ref eos_rtc_data_add_notify_data_received
 * @ref eos_rtc_data_remove_notify_data_received
 * @ref eos_rtc_data_received_data_fetch
 * @ref eos_rtc_data_add_notify_participant_updated
 * @ref eos_rtc_data_remove_notify_participant_updated
 * @section_end
 *
 * @section_struct
 * @ref EpicRTCOption
 * @ref EpicRTCParticipantMetadata
 * @ref EpicRTCJoinRoomCallbackInfo
 * @ref EpicRTCLeaveRoomCallbackInfo
 * @ref EpicRTCBlockParticipantCallbackInfo
 * @ref EpicRTCDisconnectedCallbackInfo
 * @ref EpicRTCParticipantStatusChangedCallbackInfo
 * @ref EpicRTCRoomStatisticsUpdatedInfo
 * @ref EpicRTCAudioParticipantUpdatedCallbackInfo
 * @ref EpicRTCAudioDevicesChangedCallbackInfo
 * @ref EpicRTCAudioInputStateCallbackInfo
 * @ref EpicRTCAudioOutputStateCallbackInfo
 * @ref EpicRTCAudioUpdateSendingCallbackInfo
 * @ref EpicRTCAudioUpdateReceivingCallbackInfo
 * @ref EpicRTCAudioUpdateSendingVolumeCallbackInfo
 * @ref EpicRTCAudioUpdateReceivingVolumeCallbackInfo
 * @ref EpicRTCAudioUpdateParticipantVolumeCallbackInfo
 * @ref EpicRTCAudioInputDeviceInfo
 * @ref EpicRTCAudioOutputDeviceInfo
 * @ref EpicRTCAudioSetInputDeviceSettingsCallbackInfo
 * @ref EpicRTCAudioSetOutputDeviceSettingsCallbackInfo
 * @ref EpicRTCAudioQueryInputDevicesCallbackInfo
 * @ref EpicRTCAudioQueryOutputDevicesCallbackInfo
 * @ref EpicRTCAudioBeforeSendCallbackInfo
 * @ref EpicRTCAudioBeforeRenderCallbackInfo
 * @ref EpicRTCAudioRegisterPlatformUserCallbackInfo
 * @ref EpicRTCAudioUnregisterPlatformUserCallbackInfo
 * @ref EpicRTCDataParticipantUpdatedCallbackInfo
 * @ref EpicRTCDataReceivedCallbackInfo
 * @ref EpicRTCDataUpdateSendingCallbackInfo
 * @ref EpicRTCDataUpdateReceivingCallbackInfo
 * @section_end
 *
 * @section_const
 * @ref EpicRTCParticipantStatus
 * @ref EpicRTCAudioStatus
 * @ref EpicRTCAudioInputStatus
 * @ref EpicRTCAudioOutputStatus
 * @ref EpicRTCDataStatus
 * @ref EpicRTCBackgroundMode
 * @section_end
 *
 * @module_end
 */
