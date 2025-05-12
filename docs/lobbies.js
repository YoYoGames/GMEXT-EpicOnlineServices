// Modules

/**
 * @module lobbies
 * @title Lobbies
 * @desc **Epic Online Services Interface**: [Lobby Interface](https://dev.epicgames.com/docs/api-ref/interfaces/lobby)
 * 
 * Guide: https://dev.epicgames.com/docs/game-services/lobbies-and-sessions/lobbies/lobbies-intro
 * 
 * @section_func
 * @desc 
 * @ref eos_lobby_*
 * @section_end
 * 
 * @module_end
 */

// Functions

/**
 * @func eos_lobby_add_notify_join_lobby_accepted
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-join-lobby-accepted)
 *
 * 
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_add_notify_join_lobby_accepted"`
 * @member {string} "local_user_id"
 * @member {int64} "ui_event_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_add_notify_leave_lobby_requested
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-leave-lobby-requested)
 *
 * 
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_lobby_add_notify_leave_lobby_requested"
 * @member {string} "local_user_id"
 * @member {string} "lobby_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_add_notify_lobby_invite_accepted
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-lobby-invite-accepted)
 *
 * 
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_lobby_add_notify_lobby_invite_accepted"
 * @member {string} "local_user_id"
 * @member {string} "lobby_id"
 * @member {string} "invite_id"
 * @member {string} "target_user_id"
 * @event_end

 * @func_end
 */

/**
 * @func eos_lobby_add_notify_lobby_invite_received
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-lobby-invite-received)
 *
 * 
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_lobby_add_notify_lobby_invite_received"
 * @member {string} "local_user_id"
 * @member {string} "invite_id"
 * @member {string} "target_user_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_add_notify_lobby_invite_rejected
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-lobby-invite-rejected)
 *
 * 
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_lobby_add_notify_lobby_invite_rejected"
 * @member {string} "local_user_id"
 * @member {string} "lobby_id"
 * @member {string} "invite_id"
 * @member {string} "target_user_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_add_notify_lobby_member_status_received
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-lobby-member-status-received)
 *
 * 
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_lobby_add_notify_lobby_member_status_received"
 * @member {string} "target_user_id"
 * @member {string} "lobby_id"
 * @member {real} "current_status"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_add_notify_lobby_member_update_received
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-lobby-member-update-received)
 *
 * 
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_lobby_add_notify_lobby_member_update_received"
 * @member {string} "target_user_id"
 * @member {string} "lobby_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_add_notify_lobby_update_received
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-lobby-update-received)
 *
 * 
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_lobby_add_notify_lobby_update_received"
 * @member {string} "lobby_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_add_notify_rtc_room_connection_changed
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifyRTCRoomConnectionChangedOptions](https://dev.epicgames.com/docs/en-US/api-ref/structs/eos-lobby-add-notify-rtc-room-connection-changed-options)
 *
 * 
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_lobby_add_notify_rtc_room_connection_changed"
 * @member {string} "local_user_id"
 * @member {string} "lobby_id"
 * @member {EOS_Result} "disconnect_reason" 
 * @member {real} "is_connected"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_add_notify_send_lobby_native_invite_requested
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-send-lobby-native-invite-requested)
 *
 * 
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_lobby_add_notify_send_lobby_native_invite_requested"
 * @member {string} "local_user_id"
 * @member {string} "lobby_id"
 * @member {string} "local_user_id"
 * @member {string} "lobby_id"
 * @member {int64} "ui_event_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_copy_lobby_details_handle
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-copy-lobby-details-handle)
 * 
 * 
 *
 * @param {string} lobby_id 
 * @param {string} local_user_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_copy_lobby_details_handle_by_invite_id
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-copy-lobby-details-handle-by-invite-id)
 *
 * @param {string} InviteId 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_copy_lobby_details_handle_by_ui_event_id
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-copy-lobby-details-handle-by-ui-event-id)
 *
 * 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_create_lobby
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-create-lobby)
 * 
 * @param {string} local_user_id 
 * @param {array} allowed_platform_ids 
 * @param {string} lobby_id 
 * @param {string} bucket_id 
 * @param {real} max_lobby_members 
 * @param {EOS_LobbyPermissionLevel} permission_level 
 * @param {bool} allow_invites 
 * @param {bool} crossplay_opt_out 
 * @param {bool} disable_host_migration 
 * @param {bool} enable_join_by_id 
 * @param {bool} presence_enabled 
 * @param {bool} enable_rtc_room 
 * @param {flags} flags 
 * @param {bool} use_manual_audio_input 
 * @param {bool} use_manual_audio_output 
 * @param {bool} local_audio_device_input_starts_muted 
 * 
 * @event social
 * @member {string} type the string "eos_lobby_create_lobby"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "lobby_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_create_lobby_search
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-create-lobby-search)
 *
 * @param {real} max_results 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_destroy_lobby
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-destroy-lobby)
 *
 * @param {string} lobby_id 
 * @param {string} local_user_id 
 *
 * @returns {real}
 * 
 * @event social
 * @member string -> type the string "eos_lobby_destroy_lobby"
 * @member EOS_Result -> "status"
 * @member string -> "status_message"
 * @member real -> "identifier"
 * @member string -> "lobby_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_get_connect_string
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-get-connect-string)
 *
 * @param {string} lobby_id 
 * @param {string} local_user_id 
 *
 * @returns {string}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_get_invite_count
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-get-invite-count)
 *
 * @param {string} local_user_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_get_invite_id_by_index
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-get-invite-id-by-index)
 *
 * @param {string} local_user_id 
 * @param {real} index 
 *
 * @returns {string}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_get_rtc_room_name
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-get-rtc-room-name)
 *
 * @param {string} local_user_id 
 * @param {string} lobby_id 
 *
 * @returns {string}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_hard_mute_member
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-hard-mute-member)
 *
 * @param {real} hard_mute 
 * @param {string} lobby_id 
 * @param {string} local_user_id 
 * @param {string} target_user_id 
 *
 * @returns {real}
 * 
 * @event social
 * @param {string} type the string "eos_lobby_hard_mute_member"
 * @param {EOS_Result} "status"
 * @param {string} "status_message"
 * @param {real} "identifier"
 * @param {string} "lobby_id"
 * @param {string} "target_user_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_is_rtc_room_connected
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-is-rtc-room-connected)
 *
 * @param {string} lobby_id 
 * @param {string} local_user_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_join_lobby
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-join-lobby)
 *
 * @param {string} local_user_id 
 * @param {bool} crossplay_opt_out 
 * @param {bool} presence_enabled 
 * @param {bool} enable_rtc_room 
 * @param {bool} local_audio_device_input_starts_muted 
 * @param {bool} use_manual_audio_input 
 * @param {bool} use_manual_audio_output 
 * @param {flags} flags 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_lobby_join_lobby"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "lobby_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_join_lobby_by_id
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-join-lobby-by-id)
 *
 * @param {string} local_user_id 
 * @param {bool} crossplay_opt_out 
 * @param {bool} presence_enabled 
 * @param {string} lobby_id 
 * @param {bool} enable_rtc_room 
 * @param {bool} local_audio_device_input_starts_muted 
 * @param {bool} use_manual_audio_input 
 * @param {bool} use_manual_audio_output 
 * @param {flags} flags 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_lobby_join_lobby_by_id"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "lobby_id"
 * @func_end
 */

/**
 * @func eos_lobby_kick_member
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-kick-member)
 *
 * @param {string} lobby_id 
 * @param {string} local_user_id 
 * @param {string} target_user_id 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_lobby_kick_member"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "lobby_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_leave_lobby
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-leave-lobby)
 *
 * @param {string} lobby_id 
 * @param {string} local_user_id 
 *
 * @returns {real}
 * @event social
 * @member {string} type the string "eos_lobby_leave_lobby"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "lobby_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_parse_connect_string
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-parse-connect-string)
 *
 * 
 *
 * @returns {string}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_promote_member
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-promote-member)
 * 
 * 
 * 
 * @param {string} lobby_id 
 * @param {string} local_user_id 
 * @param {string} target_user_id 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_lobby_promote_member"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "lobby_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_query_invites
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-query-invites)
 *
 * @param {string} local_user_id 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_lobby_query_invites"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "local_user_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_reject_invite
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-reject-invite)
 *
 * @param {string} invite_id 
 * @param {string} local_user_id 
 *
 * @returns {real}
 * 
 * @event social 
 * @member {string} type the string "eos_lobby_reject_invite"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "status_message"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_remove_notify_join_lobby_accepted
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-join-lobby-accepted)
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_remove_notify_leave_lobby_requested
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-leave-lobby-requested)
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_remove_notify_lobby_invite_accepted
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-lobby-invite-accepted)
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_remove_notify_lobby_invite_received
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-lobby-invite-received)
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_remove_notify_lobby_invite_rejected
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyLobbyInviteRejected](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-lobby-invite-rejected)
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_remove_notify_lobby_member_status_received
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyLobbyMemberStatusReceived](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-lobby-member-status-received)
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_remove_notify_lobby_member_update_received
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyLobbyMemberUpdateReceived](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-lobby-member-update-received)
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_remove_notify_lobby_update_received
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyLobbyUpdateReceived](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-lobby-update-received)
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_remove_notify_rtc_room_connection_changed
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyRTCRoomConnectionChanged](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-rtc-room-connection-changed)
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_remove_notify_send_lobby_native_invite_requested
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifySendLobbyNativeInviteRequested](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-send-lobby-native-invite-requested)
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_send_invite
 * @desc **Epic Online Services Function:** [EOS_Lobby_SendInvite](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-send-invite)
 * 
 * 
 * 
 * @param {string} lobby_id 
 * @param {string} local_user_id 
 * @param {string} target_user_id 
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_lobby_send_invite"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "lobby_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_update_lobby
 * @desc **Epic Online Services Function:** [EOS_Lobby_UpdateLobby](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-update-lobby)
 *
 * 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_lobby_update_lobby"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "lobby_id"
 * @event_end
	
 * @func_end
 */

/**
 * @func eos_lobby_update_lobby_modification
 * @desc **Epic Online Services Function:** [EOS_Lobby_UpdateLobbyModification](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-update-lobby-modification)
 *
 * @param {string} lobby_id 
 * @param {string} local_user_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_details_copy_attribute_by_index
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_CopyAttributeByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-copy-attribute-by-index)
 * 
 * 
 * 
 * @param {real} index 
 * @param {string} buff_ret 
 * 
 * @returns {struct.Attribute}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_details_copy_attribute_by_key
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_CopyAttributeByKey](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-copy-attribute-by-key)
 * 
 * 
 * 
 * @param {string} attr_key 
 * 
 * @returns {struct.Attribute}
 * 
 * @func_end
 */


/**
 * @struct LobbyDetails
 * @desc 
 * 
 * @member {real} available_slots 
 * @member {bool} allow_host_migration 
 * @member {bool} allow_invites 
 * @member {bool} allow_join_by_id 
 * @member {bool} presence_enabled 
 * @member {bool} rejoin_after_kick_requires_invite 
 * @member {bool} rtc_room_enabled 
 * @member {string} bucket_id 
 * @member {string} lobby_id 
 * @member {string} lobby_owner_user_id 
 * @member {real} max_members 
 * @member {EOS_ELobbyPermissionLevel} permission_level 
 * 
 * @struct_end
 */

/**
 * @func eos_lobby_details_copy_info
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_CopyInfo](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-copy-info)
 * 
 * @returns {struct.LobbyDetails}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_details_copy_member_attribute_by_index
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_CopyMemberAttributeByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-copy-member-attribute-by-index)
 *
 * @param {ind} index 
 * @param {ind} target_user_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_details_copy_member_attribute_by_key
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_CopyMemberAttributeByKey](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-copy-member-attribute-by-key)
 *
 * @param {string} attr_key 
 * @param {string} target_user_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @struct MemberInfo
 * @desc 
 * 
 * @member {bool} allows_crossplay 
 * @member {EOS_OnlinePlatformType} platform 
 * @member {string} user_id 
 * 
 * @struct_end
 */

/**
 * @func eos_lobby_details_copy_member_info
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_CopyMemberInfo](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-copy-member-info)
 * 
 * @param {string} target_user_id 
 * 
 * @returns {struct.MemberInfo}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_details_get_attribute_count
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_GetAttributeCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-get-attribute-count)
 *
 * 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_details_get_lobby_owner
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_GetLobbyOwner](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-get-lobby-owner)
 *
 * 
 *
 * @returns {string}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_details_get_member_attribute_count
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_GetMemberAttributeCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-get-member-attribute-count)
 *
 * @param {string} target_user_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_details_get_member_by_index
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_GetMemberByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-get-member-by-index)
 *
 * @param {real} index 
 *
 * @returns {string}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_details_get_member_count
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_GetMemberCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-get-member-count)
 *
 * 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_details_release
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_Info_Release](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-info-release)
 *
 * 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_modification_add_attribute
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_AddAttribute](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-add-attribute)
 *
 * @param {EOS_LobbyAttributeVisibility} visibility 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_modification_add_member_attribute
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_AddMemberAttribute](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-add-member-attribute)
 *
 * @param {EOS_ELobbyAttributeVisibility} visibility 
 * @param {par} Attribute 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_modification_release
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_Release](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-release)
 *
 * 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_modification_remove_attribute
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_RemoveAttribute](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-modification-remove-attribute)
 *
 * @param {string} key 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_modification_remove_member_attribute
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_RemoveMemberAttribute](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-remove-member-attribute)
 *
 * @param {string} key 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_modification_set_allowed_platform_ids
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_SetAllowedPlatformIds](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-set-allowed-platform-ids)
 *
 * @param {array} allowed_platform_ids 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_modification_set_bucket_id
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_SetBucketId](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-set-bucket-id)
 *
 * @param {string} bucket_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_modification_set_invites_allowed
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_SetInvitesAllowed](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-set-invites-allowed)
 *
 * @param {bool} invites_allowed 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_modification_set_max_members
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_SetMaxMembers](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-set-max-members)
 *
 * @param {real} max_members 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_modification_set_permission_level
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_SetPermissionLevel](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-set-permission-level)
 *
 * @param {EOS_LobbyPermissionLevel} PermissionLevel 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_search_copy_search_result_by_index
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_CopySearchResultByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-copy-search-result-by-index)
 *
 * @param {real} index 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_search_find
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_Find](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-find)
 *
 * @param {string} local_user_id 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_lobby_search_find"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_search_get_search_result_count
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_GetSearchResultCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-get-search-result-count)
 *
 * 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_search_release
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_Release](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-search-release)
 *
 * 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_search_remove_parameter
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_RemoveParameter](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-remove-parameter)
 * 
 * 
 *
 * @param {string} key 
 * @param {EOS_ComparisonOp} comparison_op 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_search_set_lobby_id
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_SetLobbyId](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-set-lobby-id)
 * 
 * 
 *
 * @param {string} lobby_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_search_set_max_results
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_SetMaxResults](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-set-max-results)
 * 
 * 
 *
 * @param {real} max_results 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_search_set_parameter
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_SetParameter](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-set-parameter)
 * 
 * 
 *
 * @param {EOS_ComparisonOp} comparison_op 
 * @param {par} attribute 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_search_set_target_user_id
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_SetTargetUserId](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-set-target-user-id)
 * 
 * 
 *
 * @param {string} target_user_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/*
NOTES:

------------------------------------------------------------------------------------
mHLobbyDetails

Obtain:
	eos_lobby_copy_lobby_details_handle
	eos_lobby_copy_lobby_details_handle_by_invite_id
	eos_lobby_search_copy_search_result_by_index
	__eos_lobby_copy_lobby_details_handle_by_ui_event_id
Uses:
	eos_lobby_join_lobby
	eos_lobby_details_copy_attribute_by_index
	eos_lobby_details_copy_attribute_by_key
	eos_lobby_details_copy_info
	eos_lobby_details_copy_member_attribute_by_index
	eos_lobby_details_copy_member_attribute_by_key
	eos_lobby_details_copy_member_info
	eos_lobby_details_get_attribute_count
	eos_lobby_details_get_lobby_owner
	eos_lobby_details_get_member_attribute_count
	eos_lobby_details_get_member_by_index
	eos_lobby_details_get_member_count
Release:
	eos_lobby_details_release()


------------------------------------------------------------------------------------


mHLobbyModification

Obtain:
	eos_lobby_update_lobby_modification
	
Uses:
	eos_lobby_update_lobby
	__eos_lobby_modification_add_attribute
	__eos_lobby_modification_add_member_attribute
	eos_lobby_modification_remove_attribute
	eos_lobby_modification_remove_member_attribute
	__eos_lobby_modification_set_allowed_platform_ids
	eos_lobby_modification_set_bucket_id
	eos_lobby_modification_set_invites_allowed
	eos_lobby_modification_set_max_members
	eos_lobby_modification_set_permission_level
	
Release:
	eos_lobby_modification_release()


------------------------------------------------------------------------------------

mHLobbySearch


Obtain:
	eos_lobby_create_lobby_search
	
Uses:
	eos_lobby_search_copy_search_result_by_index
	eos_lobby_search_find
	eos_lobby_search_get_search_result_count
	eos_lobby_search_remove_parameter
	eos_lobby_search_set_lobby_id
	eos_lobby_search_set_max_results
	__eos_lobby_search_set_parameter
	eos_lobby_search_set_target_user_id
	
Release:
	func real eos_lobby_search_release()

------------------------------------------------------------------------------------

Attribute: {key:string, type: EOS_AttributeType, value: any}

*/