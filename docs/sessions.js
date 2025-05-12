/**
 * @module sessions
 * @title Sessions
 * @desc **Epic Online Services Interface**: [Sessions Interface](https://dev.epicgames.com/docs/api-ref/interfaces/sessions)
 * 
 * Guide: https://dev.epicgames.com/docs/game-services/lobbies-and-sessions/sessions/sessions-intro
 * 
 * @section_func
 * @desc 
 * @ref eos_active_session_*
 * @ref eos_session_*
 * @ref eos_sessions_*
 * @section_end
 * 
 * @module_end
 */

/**
 * @struct SessionInfo
 * 
 * @member {string} session_name 
 * @member {EOS_EOnlineSessionState} state 
 * @member {struct} details 
	{
		host_address:string,
		num_open_public_connections: int,
		owner_server_client_id: string,
		owner_user_id: string,
		session_id: string,
	}
 * @member {struct} settings
	{
		allowed_platform_ids: array,
		allow_join_in_progress: bool,
		invites_allowed: bool.
		sanctions_enabled: bool,
		bucket_id: string,
		num_public_connections: int,
		permission_level: int,
	}
 * @struct_end
 */

/**
 * @func eos_active_session_copy_info
 * @desc **Epic Online Services Function:** [EOS_ActiveSession_CopyInfo](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-active-session-copy-info)
 * 
 * 
 * 
 * @returns {struct.SessionInfo}
 * 
 * @func_end
 */

/**
 * @func eos_active_session_get_registered_player_by_index
 * @desc **Epic Online Services Function:** [EOS_ActiveSession_GetRegisteredPlayerByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-active-session-get-registered-player-by-index)
 *
 * @param {string} session_name 
 *
 * @returns {string}
 * 
 * @func_end
 */

/**
 * @func eos_active_session_get_registered_player_count
 * @desc **Epic Online Services Function:** [EOS_ActiveSession_GetRegisteredPlayerCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-active-session-get-registered-player-count)
 *
 * string session_name
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @struct SessionInfoDetails
 * @desc 
 * 
 * @member {string} host_address 
 * @member {real} num_open_public_connections 
 * @member {string} owner_user_id 
 * @member {string} owner_server_client_id 
 * @member {string} session_id 
 * @member {struct} settings 
 * 
 * {
			allowed_platform_ids: _array,
			allow_join_in_progress: bool,
			invites_allowed: bool,
			sanctions_enabled: bool,
			bucket_id: string,
			num_public_connections: int,
			permission_level: int,
		}
 * 
 * @struct_end
 */

/**
 * @func eos_session_details_copy_info
 * @desc **Epic Online Services Function:** [EOS_SessionDetails_CopyInfo](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-details-copy-info)
 * 
 * @returns {struct.SessionInfoDetails}
 * 
 * @func_end
 */

/**
 * @struct SessionAttributeInfo
 * @desc 
 * 
 * 
 * 
 * @member {int} advertisement_type 
 * @member {string} key 
 * @member {any} value 
 * 
 * @struct_end
 */

/**
 * @func eos_session_details_copy_session_attribute_by_index
 * @desc **Epic Online Services Function:** [EOS_SessionDetails_CopySessionAttributeByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-details-copy-session-attribute-by-index)
 * 
 * 
 * 
 * @param {real} attr_index 
 * 
 * @returns {struct.SessionAttributeInfo}
 * 
 * @func_end
 */

/**
 * @func eos_session_details_copy_session_attribute_by_key
 * @desc **Epic Online Services Function:** [EOS_SessionDetails_CopySessionAttributeByKey](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-details-copy-session-attribute-by-key)
 * 
 * 
 * 
 * @param {string} attr_key 
 * 
 * @returns {struct.SessionAttributeInfo}
 * 
 * @func_end
 */

/**
 * @func eos_session_details_get_session_attribute_count
 * @desc **Epic Online Services Function:** [EOS_SessionDetails_GetSessionAttributeCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-details-get-session-attribute-count)
 *
 * 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_details_release
 * @desc **Epic Online Services Function:** [EOS_SessionDetails_Release](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-details-release)
 *
 * 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_modification_add_attribute
 * @desc **Epic Online Services Function:** [EOS_SessionModification_AddAttribute](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-add-attribute)
 * 
 * 
 *
 * @param {AdvertisementType} type 
 * @param {Sessionattribute} attribute 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_modification_release
 * @desc **Epic Online Services Function:** [EOS_SessionModification_Release](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-release)
 *
 * 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_modification_remove_attribute
 * @desc **Epic Online Services Function:** [EOS_SessionModification_Release](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-release)
 * 
 * 
 *
 * @param {string} key 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_modification_set_allowed_platform_ids
 * @desc **Epic Online Services Function:** [EOS_SessionModification_SetAllowedPlatformIds](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-allowed-platform-ids)
 * 
 * 
 * 
 * @param {array} array_ids 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_modification_set_bucket_id
 * @desc **Epic Online Services Function:** [EOS_SessionModification_SetBucketId](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-bucket-id)
 * 
 * 
 *
 * @param {string} bucket_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_modification_set_host_address
 * @desc **Epic Online Services Function:** [EOS_SessionModification_SetHostAddress](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-host-address)
 * 
 * 
 *
 * @param {string} host_address 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_modification_set_invites_allowed
 * @desc **Epic Online Services Function:** [EOS_SessionModification_SetInvitesAllowed](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-invites-allowed)
 * 
 * 
 *
 * @param {bool} invites_allowed 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_modification_set_join_in_progress_allowed
 * @desc **Epic Online Services Function:** [EOS_SessionModification_SetJoinInProgressAllowed](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-join-in-progress-allowed)
 * 
 * 
 *
 * @param {bool} allow_join_in_progress 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_modification_set_max_players
 * @desc **Epic Online Services Function:** [EOS_SessionModification_SetMaxPlayers](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-max-players)
 * 
 * 
 *
 * @param {real} max_players 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_modification_set_permission_level
 * @desc **Epic Online Services Function:** [EOS_SessionModification_SetPermissionLevel](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-permission-level)
 * 
 * 
 *
 * @param {real} permission_level 
 *
 * @returns {real}
 * 
 * @func_end
 */


/**
 * @func eos_sessions_add_notify_join_session_accepted
 * @desc **Epic Online Services Function:** [EOS_Sessions_AddNotifyJoinSessionAccepted](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-add-notify-join-session-accepted)
 * 
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_sessions_add_notify_join_session_accepted"
 * @member {string} "local_user_id"
 * @member {int64} "ui_event_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_add_notify_leave_session_requested
 * @desc **Epic Online Services Function:** [EOS_Sessions_AddNotifyLeaveSessionRequested](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-add-notify-leave-session-requested)
 * 
 * 
 * 
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_sessions_add_notify_leave_session_requested"
 * @member {string} "local_user_id"
 * @member {string} "session_name"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_add_notify_send_session_native_invite_requested
 * @desc **Epic Online Services Function:** [EOS_Sessions_AddNotifySendSessionNativeInviteRequested](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-add-notify-send-session-native-invite-requested)
 * 
 * 
 * 
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_sessions_add_notify_send_session_native_invite_requested"
 * @member {string} "local_user_id"
 * @member {string} "target_native_account_type"
 * @member {string} "target_user_native_account_id"
 * @member {string} "session_id"
 * @member {int64} "ui_event_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_add_notify_session_invite_accepted
 * @desc **Epic Online Services Function:** [EOS_Sessions_AddNotifySessionInviteAccepted](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-add-notify-session-invite-accepted)
 * 
 * 
 * 
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_sessions_add_notify_session_invite_accepted"
 * @member {string} "local_user_id"
 * @member {string} "invite_id"
 * @member {string} "session_id"
 * @member {string} "target_user_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_add_notify_session_invite_rejected
 * @desc **Epic Online Services Function:** [EOS_Sessions_AddNotifySessionInviteRejected](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-add-notify-session-invite-rejected)
 * 
 * 
 * 
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string "eos_sessions_add_notify_session_invite_rejected"
 * @member {string} "invite_id"
 * @member {string} "target_user_id"
 * @member {string} "session_id"
 * @member {string} "local_user_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_copy_session_handle_by_invite_id
 * @desc **Epic Online Services Function:** [temp](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-copy-session-handle-by-invite-id)
 *
 * @param {string} invite_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_copy_session_handle_by_ui_event_id
 * @desc **Epic Online Services Function:** [EOS_Sessions_CopySessionHandleByUiEventId](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-copy-session-handle-by-ui-event-id)
 * 
 * 
 * 
 * @param {int64} ui_event_id 
 * 
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_copy_session_handle_for_presence
 * @desc **Epic Online Services Function:** [EOS_Sessions_CopySessionHandleForPresenceOptions](https://dev.epicgames.com/docs/en-US/api-ref/structs/eos-sessions-copy-session-handle-for-presence-options)
 *
 * @param {string} local 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_create_session_modification
 * @desc **Epic Online Services Function:** [EOS_Sessions_CreateSessionModification](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-create-session-modification)
 * 
 * 
 * 
 * @param {array} allowed_platform_ids 
 * @param {bool} presence_enabled 
 * @param {bool} sanctions_enabled 
 * @param {string} bucket_id 
 * @param {string} local_user_id 
 * @param {real} max_players 
 * @param {string} session_id 
 * @param {string} session_name 
 * 
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_create_session_search
 * @desc **Epic Online Services Function:** [EOS_Sessions_CreateSessionSearch](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-create-session-search)
 * 
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_destroy_session
 * @desc **Epic Online Services Function:** [EOS_Sessions_DestroySession](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-destroy-session)
 *
 * @param {string} session_name 
 *
 * @returns {real}
 * @event social
 * @member {string} type the string "eos_sessions_destroy_session"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_dump_session_state
 * @desc **Epic Online Services Function:** [EOS_Sessions_DumpSessionState](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-dump-session-state)
 *
 * @param {string} session_name 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_end_session
 * @desc **Epic Online Services Function:** [EOS_Sessions_EndSession](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-end-session)
 *
 * @param {string} session_name 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_sessions_end_session"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_get_invite_count
 * @desc **Epic Online Services Function:** [EOS_Sessions_GetInviteCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-get-invite-count)
 *
 * @param {string} local 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_get_invite_id_by_index
 * @desc **Epic Online Services Function:** [EOS_Sessions_GetInviteIdByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-get-invite-id-by-index)
 * 
 * @param {string} local_user_id 
 * @param {real} index 
 *
 * @returns {string}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_is_user_in_session
 * @desc **Epic Online Services Function:** [EOS_Sessions_IsUserInSession](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-is-user-in-session)
 * 
 * @param {string} session_name 
 * @param {string} target_user_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_join_session
 * @desc **Epic Online Services Function:** [EOS_Sessions_JoinSession](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-join-session)
 * 
 * @param {real} presence_enabled 
 * @param {string} local_user_id 
 * @param {string} session_name 
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_sessions_join_session"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_query_invites
 * @desc **Epic Online Services Function:** [EOS_Sessions_QueryInvites](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-query-invites)
 *
 * @param {string} target_user_id 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_sessions_query_invites"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "local_user_id"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_register_players
 * @desc **Epic Online Services Function:** [EOS_Sessions_RegisterPlayers](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-register-players)
 *
 * @param {string} session_name 
 * @param {array} array_product_ids 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_sessions_register_players"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "registered_players"
 * @member {string} "sanctioned_players"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_reject_invite
 * @desc **Epic Online Services Function:** [EOS_Sessions_RejectInvite](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-reject-invite)
 * 
 * @param {string} local_user_id 
 * @param {string} invite_id 
 * 
 * @event social
 * @member {string} type the string "eos_sessions_reject_invite"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_remove_notify_join_session_accepted
 * @desc **Epic Online Services Function:** [EOS_Sessions_RemoveNotifyJoinSessionAccepted](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-remove-notify-join-session-accepted)
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_remove_notify_leave_session_requested
 * @desc **Epic Online Services Function:** [EOS_Sessions_RemoveNotifyLeaveSessionRequested](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-remove-notify-leave-session-requested)
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_remove_notify_send_session_native_invite_requested
 * @desc **Epic Online Services Function:** [EOS_Sessions_RemoveNotifySendSessionNativeInviteRequested](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-remove-notify-send-session-native-invite-requested)
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_remove_notify_session_invite_accepted
 * @desc **Epic Online Services Function:** [EOS_Sessions_RemoveNotifySessionInviteAccepted](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-remove-notify-session-invite-accepted)
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_remove_notify_session_invite_received
 * @desc **Epic Online Services Function:** [EOS_Sessions_RemoveNotifySessionInviteReceived](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-remove-notify-session-invite-received)
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_remove_notify_session_invite_rejected
 * @desc **Epic Online Services Function:** [EOS_Sessions_RemoveNotifySessionInviteReceived](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-remove-notify-session-invite-received)
 *
 * @param {int64} notification_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_send_invite
 * @desc **Epic Online Services Function:** [EOS_Sessions_SendInvite](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-send-invite)
 * 
 * @param {string} local_user_id 
 * @param {string} session_name 
 * @param {string} target_user_id 
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_sessions_send_invite"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_start_session
 * @desc **Epic Online Services Function:** [EOS_Sessions_StartSession](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-start-session)
 *
 * @param {string} session_name 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_sessions_start_session"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_unregister_players
 * @desc **Epic Online Services Function:** [EOS_Sessions_UnregisterPlayers](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-unregister-players)
 *
 * @param {string} session_name 
 * @param {array} array_product_ids 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_sessions_unregister_players"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "unregistered_players"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_update_session
 * @desc **Epic Online Services Function:** [EOS_Sessions_UpdateSession](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-update-session)
 *
 * 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_sessions_update_session"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @member {string} "session_id"
 * @member {string} "session_name"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_update_session_modification
 * @desc **Epic Online Services Function:** [EOS_Sessions_UpdateSessionModification](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-update-session-modification)
 *
 * @param {string} session_name 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_search_copy_search_result_by_index
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_CopySearchResultByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-copy-search-result-by-index)
 *
 * @param {real} session_index 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_search_find
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_Find](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-find)
 *
 * @param {string} local_user_id 
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string "eos_session_search_find"
 * @member {EOS_Result} "status"
 * @member {string} "status_message"
 * @member {real} "identifier"
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_session_search_get_search_result_count
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_GetSearchResultCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-get-search-result-count)
 *
 * 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_search_release
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_Release](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-release)
 *
 * 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_search_remove_parameter
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_RemoveParameter](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-remove-parameter)
 *
 * @param {string} key 
 * @param {EOS_ComparisonOp} comparison_op 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_search_set_max_results
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_SetMaxResults](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-set-max-results)
 *
 * @param {real} max_search_results 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_search_set_parameter
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_SetParameter](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-set-parameter)
 *
 * @param {EOS_ComparisonOp} comparison_op 
 * @param {Struct} attribute 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_search_set_session_id
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_SetSessionId](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-set-session-id)
 *
 * @param {string} session_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_search_set_target_user_id
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_SetTargetUserId](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-set-target-user-id)
 *
 * @param {string} target_user_id 
 *
 * @returns {real}
 * 
 * @func_end
 */

/*
Notes:

------------------------------------------------------------------------------------

mOutSessionSearchHandle

Obtain:
	eos_sessions_create_session_search
	
Uses:
	eos_session_search_copy_search_result_by_index
	eos_session_search_find
	eos_session_search_get_search_result_count
	eos_session_search_remove_parameter
	eos_session_search_set_max_results
	__eos_session_search_set_parameter
	eos_session_search_set_session_id
	eos_session_search_set_target_user_id
	
	
Release:
	eos_session_search_release()

------------------------------------------------------------------------------------

mHSessionDetails

Obtain:
	eos_sessions_copy_session_handle_by_invite_id
	__eos_sessions_copy_session_handle_by_ui_event_id
	eos_sessions_copy_session_handle_for_presence
	eos_session_search_copy_search_result_by_index
	
Uses:
	__eos_session_details_copy_info
	__eos_session_details_copy_session_attribute_by_index
	__eos_session_details_copy_session_attribute_by_key
	eos_session_details_get_session_attribute_count
	eos_sessions_join_session
	
Release:
	eos_session_details_release()

------------------------------------------------------------------------------------

mHSessionModification

Obtain:
	__eos_sessions_create_session_modification
	eos_sessions_update_session_modification
	
Uses:
	__eos_session_modification_add_attribute
	eos_session_modification_remove_attribute
	__eos_session_modification_set_allowed_platform_ids
	eos_session_modification_set_bucket_id
	eos_session_modification_set_host_address
	eos_session_modification_set_invites_allowed
	eos_session_modification_set_join_in_progress_allowed
	eos_session_modification_set_max_players
	eos_session_modification_set_permission_level
	eos_sessions_update_session
	
Release:
	eos_session_modification_release()

*/
