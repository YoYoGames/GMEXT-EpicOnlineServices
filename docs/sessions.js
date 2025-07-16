/**
 * @module sessions
 * @title Sessions
 * @desc **Epic Online Services Interface**: [Sessions Interface](https://dev.epicgames.com/docs/api-ref/interfaces/sessions)
 * 
 * Epic Online Services (EOS) gives players the ability to host, find, and interact with online gaming sessions through the Sessions Interface. A session can be short, like filling a certain number of player slots before starting a game, then disbanding after the game ends, or it could be longer, like keeping track of a game that cycles through matches on multiple maps or levels. The Sessions Interface also manages game-specific data that supports the back-end service searching and matchmaking functionality. For more information on the considerations you should take for matchmaking, see the documentation: [Security Considerations](https://dev.epicgames.com/docs/en-US/game-services/lobbies-and-sessions/security-considerations) section.
 * 
 * [[Note: See the [Sessions Introduction](https://dev.epicgames.com/docs/game-services/lobbies-and-sessions/sessions/sessions-intro) for a more detailed guide.]]
 * 
 * @section Session Handles
 * @desc Sessions in Epic Online Services make use of session handles. Before you can use certain functions you need to obtain a valid handle for that which you're trying to do. The handles themselves are kept by the extension. However, whenever you request a handle, you should still manually release it afterwards, once you are done using it.
 * 
 * The following is an overview of the different session handles and the functions you can use to obtain and release them and the functions that require them.
 * 
 * ### OutSessionSearchHandle
 * 
 * * Obtain:
 *   * ${function.eos_sessions_create_session_search}
 * * Used by:
 *   * ${function.eos_session_search_copy_search_result_by_index}
 *   * ${function.eos_session_search_find}
 *   * ${function.eos_session_search_get_search_result_count}
 *   * ${function.eos_session_search_remove_parameter}
 *   * ${function.eos_session_search_set_max_results}
 *   * ${function.eos_session_search_set_parameter}
 *   * ${function.eos_session_search_set_session_id}
 *   * ${function.eos_session_search_set_target_user_id}
 * * Release:
 *   * ${function.eos_session_search_release}
 * 
 * ### SessionDetails
 * 
 * * Obtain:
 *   * ${function.eos_sessions_copy_session_handle_by_invite_id}
 *   * ${function.eos_sessions_copy_session_handle_by_ui_event_id}
 *   * ${function.eos_sessions_copy_session_handle_for_presence}
 *   * ${function.eos_session_search_copy_search_result_by_index}
 * * Used by:
 *   * ${function.eos_session_details_copy_info}
 *   * ${function.eos_session_details_copy_session_attribute_by_index}
 *   * ${function.eos_session_details_copy_session_attribute_by_key}
 *   * ${function.eos_session_details_get_session_attribute_count}
 *   * ${function.eos_sessions_join_session}
 * * Release:
 *   * ${function.eos_session_details_release}
 * 
 * ### SessionModification
 * 
 * * Obtain:
 *   * ${function.eos_sessions_create_session_modification}
 *   * ${function.eos_sessions_update_session_modification}
 * * Used by:
 *   * ${function.eos_session_modification_add_attribute}
 *   * ${function.eos_session_modification_remove_attribute}
 *   * ${function.eos_session_modification_set_allowed_platform_ids}
 *   * ${function.eos_session_modification_set_bucket_id}
 *   * ${function.eos_session_modification_set_host_address}
 *   * ${function.eos_session_modification_set_invites_allowed}
 *   * ${function.eos_session_modification_set_join_in_progress_allowed}
 *   * ${function.eos_session_modification_set_max_players}
 *   * ${function.eos_session_modification_set_permission_level}
 *   * ${function.eos_sessions_update_session}
 * * Release:
 *   * ${function.eos_session_modification_release}
 * 
 * @section_end
 * 
 * @section_func
 * @desc 
 * @ref eos_active_session_*
 * @ref eos_session_*
 * @ref eos_sessions_*
 * @section_end
 * 
 * @section_struct
 * @desc 
 * @ref ActiveSessionInfo
 * @ref SessionAttribute
 * @ref SessionDetails_Info
 * @ref SessionDetails_Settings
 * @section_end
 * 
 * @section_const
 * @desc 
 * @ref EOS_ATTRIBUTE_TYPE
 * @ref EOS_ONLINE_SESSION_PERMISSION_LEVEL
 * @ref EOS_ONLINE_SESSION_STATE
 * @ref EOS_SESSION_ATTRIBUTE_ADVERTISEMENT_TYPE
 * @ref EOS_SESSIONS_MAX_SEARCH_RESULTS
 * @section_end
 * 
 * @module_end
 */

/**
 * @struct ActiveSessionInfo
 * @desc **Epic Online Services Struct:** [EOS_ActiveSession_Info](https://dev.epicgames.com/docs/api-ref/structs/eos-active-session-info)
 * 
 * This struct holds top level details about an active session.
 * 
 * @member {string} session_name The name of the session
 * @member {constant.EOS_ONLINE_SESSION_STATE} state The current state of the session
 * @member {struct.SessionDetails_Info} details Details about the session
 * @member {struct.SessionDetails_Settings} settings The session's settings
 * 
 * @struct_end
 */

/**
 * @func eos_active_session_copy_info
 * @desc **Epic Online Services Function:** [EOS_ActiveSession_CopyInfo](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-active-session-copy-info)
 * 
 * This function is used to immediately retrieve a copy of active session information. The returned struct will be empty if the result is not `EOS_RESULT.SUCCESS`.
 * 
 * @param {string} session_name The name of the session
 * 
 * @returns {struct.ActiveSessionInfo}
 * 
 * @func_end
 */

/**
 * @func eos_active_session_get_registered_player_by_index
 * @desc **Epic Online Services Function:** [EOS_ActiveSession_GetRegisteredPlayerByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-active-session-get-registered-player-by-index)
 * 
 * This function is used to immediately retrieve individual players registered with the active session.
 *
 * @param {string} session_name The name of the session
 * @param {real} player_index The index of the registered player to retrieve
 *
 * @returns {string}
 * 
 * @func_end
 */

/**
 * @func eos_active_session_get_registered_player_count
 * @desc **Epic Online Services Function:** [EOS_ActiveSession_GetRegisteredPlayerCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-active-session-get-registered-player-count)
 * 
 * This function gets the number of registered players associated with this active session. It returns the number of registered players in the active session or 0 if there is an error.
 *
 * @param {string} session_name The name of the session
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @struct SessionDetails_Info
 * @desc **Epic Online Services Struct:** [EOS_SessionDetails_Info](https://dev.epicgames.com/docs/en-US/api-ref/structs/eos-session-details-info)
 * 
 * This struct holds internal details about a session, found on both active sessions and within search results.
 * 
 * @member {string} host_address The IP address of this session as visible by the backend service
 * @member {real} num_open_public_connections The number of remaining open spaces on the session (`num_public_connections` - `registered_players`)
 * @member {string} owner_user_id The Product User ID of the session owner. Pass an empty string `""` if the session is not owned by a user.
 * @member {string} owner_server_client_id The client ID of the session owner. Pass an empty string `""` if the session is not owned by a server. The session is owned by a server if EOS_Platform_Options::bIsServer is `true`.
 * @member {string} session_id The session ID assigned by the backend service
 * @member {struct.SessionDetails_Settings} settings The additional settings associated with this session
 * @struct_end
 */

/**
 * @struct SessionDetails_Settings
 * @desc **Epic Online Services Struct:** [EOS_SessionDetails_Settings](https://dev.epicgames.com/docs/en-US/api-ref/structs/eos-session-details-settings)
 * 
 * This struct holds common settings associated with a single session.
 * 
 * @member {array[constant.EOS_ONLINE_PLATFORM_TYPE]} allowed_platform_ids An array of platform IDs indicating the player platforms allowed to register with the session. The session will be unrestricted if you pass an empty array.
 * @member {bool} allow_join_in_progress Whether players are allowed to join the session while it is in the "in progress" state
 * @member {bool} invites_allowed Whether players are allowed to send invites for the session
 * @member {bool} sanctions_enabled Whether sanctioned players are allowed to join or not - sanctioned players will be rejected if set to `true`
 * @member {string} bucket_id The main indexed parameter for this session, can be any string (i.e. `"Region:GameMode"`)
 * @member {real} num_public_connections The number of total players allowed in the session
 * @member {constant.EOS_ONLINE_SESSION_PERMISSION_LEVEL} permission_level The permission level describing allowed access to the session when joining or searching for the session
 * 
 * @struct_end
 */

/**
 * @func eos_session_details_copy_info
 * @desc **Epic Online Services Function:** [EOS_SessionDetails_CopyInfo](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-details-copy-info)
 * 
 * This function is used to immediately retrieve a copy of session information from a given source such as a active session or a search result.
 * 
 * @returns {struct.SessionDetails_Info}
 * 
 * @func_end
 */

/**
 * @constant EOS_ATTRIBUTE_TYPE
 * @desc This enumeration holds the supported types of data that can be stored inside an attribute (used by sessions/lobbies/etc.).
 * 
 * @member BOOLEAN A boolean value (`true`/`false`)
 * @member INT64 A 64 bit integer
 * @member DOUBLE A double precision floating point value
 * @member STRING A UTF-8 string
 * 
 * @constant_end
 */

/**
 * @struct SessionAttribute
 * @desc **Epic Online Services Struct:** [EOS_SessionDetails_Attribute](https://dev.epicgames.com/docs/api-ref/structs/eos-session-details-attribute)
 * 
 * This struct holds an attribution value and its advertisement setting stored with a session.
 * 
 * @member {constant.EOS_SESSION_ATTRIBUTE_ADVERTISEMENT_TYPE} advertisement_type Whether this attribution is advertised with the backend or simply stored locally
 * @member {string} key The name of the session attribute
 * @member {any} value The value of the session attribute
 * 
 * @struct_end
 */

/**
 * @func eos_session_details_copy_session_attribute_by_index
 * @desc **Epic Online Services Function:** [EOS_SessionDetails_CopySessionAttributeByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-details-copy-session-attribute-by-index)
 * 
 * This function is used to immediately retrieve a copy of session attribution from a given source such as a active session or a search result.
 * 
 * @param {real} attr_index The index of the attribute to retrieve
 * 
 * @returns {struct.SessionAttribute}
 * 
 * @func_end
 */

/**
 * @func eos_session_details_copy_session_attribute_by_key
 * @desc **Epic Online Services Function:** [EOS_SessionDetails_CopySessionAttributeByKey](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-details-copy-session-attribute-by-key)
 * 
 * This function is used to immediately retrieve a copy of session attribution from a given source such as a active session or a search result.
 * 
 * @param {string} attr_key The name of the key to get the session attribution for
 * 
 * @returns {struct.SessionAttribute}
 * 
 * @func_end
 */

/**
 * @func eos_session_details_get_session_attribute_count
 * @desc **Epic Online Services Function:** [EOS_SessionDetails_GetSessionAttributeCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-details-get-session-attribute-count)
 *
 * This function gets the number of attributes associated with this session. It returns the number of attributes on the session or 0 if there is an error.
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_details_release
 * @desc **Epic Online Services Function:** [EOS_SessionDetails_Release](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-details-release)
 *
 * This function releases the memory associated with a single session. This must be called on data retrieved from ${function.eos_session_search_copy_search_result_by_index}.
 * 
 * @func_end
 */

/**
 * @func eos_session_modification_add_attribute
 * @desc **Epic Online Services Function:** [EOS_SessionModification_AddAttribute](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-add-attribute)
 * 
 * This function associates an attribute with this session. An attribute is something that may or may not be advertised with the session. If advertised, it can be queried for in a search, otherwise the data remains local to the client.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if setting this parameter was successful
 * * `EOS_RESULT.INVALID_PARAMETERS` if the attribution is missing information or otherwise invalid
 * * `EOS_RESULT.INCOMPATIBLE_VERSION` if the API version passed in is incorrect
 *
 * @param {constant.EOS_SESSION_ATTRIBUTE_ADVERTISEMENT_TYPE} type Whether this attribute is advertised with the backend or simply stored locally
 * @param {struct} attribute A struct with two variables `key` and `value`, representing the key/value pair that describes the attribute to add to the session
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_session_modification_release
 * @desc **Epic Online Services Function:** [EOS_SessionModification_Release](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-release)
 * 
 * This function releases the memory associated with session modification. This must be called on data retrieved from ${function.eos_sessions_create_session_modification} or ${function.eos_sessions_update_session_modification}.
 * 
 * @func_end
 */

/**
 * @func eos_session_modification_remove_attribute
 * @desc **Epic Online Services Function:** [EOS_SessionModification_RemoveAttribute](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-remove-attribute)
 * 
 * This function removes an attribute from this session.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if removing this parameter was successful
 * * `EOS_RESULT.INVALID_PARAMETERS` if the key is empty
 * * `EOS_RESULT.INCOMPATIBLE_VERSION` if the API version passed in is incorrect
 * 
 * @param {string} key The session attribute to remove from the session
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_session_modification_set_allowed_platform_ids
 * @desc **Epic Online Services Function:** [EOS_SessionModification_SetAllowedPlatformIds](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-allowed-platform-ids)
 * 
 * This function sets the Allowed Platform IDs for the session.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if setting this parameter was successful
 * * `EOS_RESULT.INCOMPATIBLE_VERSION` if the API version passed in is incorrect
 * * `EOS_RESULT.INVALID_PARAMETERS` if the attribution is missing information or otherwise invalid
 * 
 * @param {array[constant.EOS_ONLINE_PLATFORM_TYPE]} array_ids An array of platform IDs indicating the player platforms allowed to register with the session. The session will be unrestricted if you pass `undefined`.
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_session_modification_set_bucket_id
 * @desc **Epic Online Services Function:** [EOS_SessionModification_SetBucketId](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-bucket-id)
 * 
 * This function sets the bucket ID associated with this session. Values such as region, game mode, etc., can be combined here depending on game need. Setting this is strongly recommended to improve search performance.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if setting this parameter was successful
 * * `EOS_RESULT.INVALID_PARAMETERS` if the bucket ID is invalid
 * * `EOS_RESULT.INCOMPATIBLE_VERSION` if the API version passed in is incorrect
 * 
 * @param {string} bucket_id The new bucket ID associated with the session
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_session_modification_set_host_address
 * @desc **Epic Online Services Function:** [EOS_SessionModification_SetHostAddress](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-host-address)
 * 
 * This function sets the host address associated with this session. Setting this is optional, if the value is not set, the SDK will fill the value in from the service. It is useful to set if other addressing mechanisms are desired or if LAN addresses are preferred during development.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if setting this parameter was successful
 * * `EOS_RESULT.INVALID_PARAMETERS` if the host ID is an empty string
 * * `EOS_RESULT.INCOMPATIBLE_VERSION` if the API version passed in is incorrect
 * 
 * [[Note: No validation of this value occurs to allow for flexibility in addressing methods.]]
 * 
 * @param {string} host_address A string representing the host address for the session, its meaning is up to the application
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_session_modification_set_invites_allowed
 * @desc **Epic Online Services Function:** [EOS_SessionModification_SetInvitesAllowed](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-invites-allowed)
 * 
 * This function allows enabling or disabling invites for this session. The session will also need to have `presence_enabled` true.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if setting this parameter was successful
 * * `EOS_RESULT.INCOMPATIBLE_VERSION` if the API version passed in is incorrect
 *
 * @param {bool} invites_allowed If `true` then invites can currently be sent for the associated session
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_session_modification_set_join_in_progress_allowed
 * @desc **Epic Online Services Function:** [EOS_SessionModification_SetJoinInProgressAllowed](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-join-in-progress-allowed)
 * 
 * This function sets whether or not join in progress is allowed. Once a session is started, it will no longer be visible to search queries unless this flag is set or the session returns to the pending or ended state.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if setting this parameter was successful
 * * `EOS_RESULT.INCOMPATIBLE_VERSION` if the API version passed in is incorrect
 * 
 * @param {bool} allow_join_in_progress Whether the session allows join in progress
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_session_modification_set_max_players
 * @desc **Epic Online Services Function:** [EOS_SessionModification_SetMaxPlayers](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-max-players)
 * 
 * This function sets the maximum number of players allowed in this session. When updating the session, it is not possible to reduce this number below the current number of existing players.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if setting this parameter was successful
 * * `EOS_RESULT.INCOMPATIBLE_VERSION` if the API version passed in is incorrect
 * 
 * @param {real} max_players The max number of players to allow in the session
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_session_modification_set_permission_level
 * @desc **Epic Online Services Function:** [EOS_SessionModification_SetPermissionLevel](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-permission-level)
 * 
 * This function sets the session permissions associated with this session. The permissions range from "public" to "invite only" and are described by ${constant.EOS_ONLINE_SESSION_PERMISSION_LEVEL}.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if setting this parameter was successful
 * * `EOS_RESULT.INCOMPATIBLE_VERSION` if the API version passed in is incorrect
 *
 * @param {constant.EOS_ONLINE_SESSION_PERMISSION_LEVEL} permission_level The permission level to set on the session
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */


/**
 * @func eos_sessions_add_notify_join_session_accepted
 * @desc **Epic Online Services Function:** [EOS_Sessions_AddNotifyJoinSessionAccepted](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-add-notify-join-session-accepted)
 * 
 * This function registers to receive notifications when a user accepts a session join game via the social overlay.
 * 
 * [[Note: If the returned notification ID is valid, you must call ${function.eos_sessions_remove_notify_join_session_accepted} when you no longer wish to have the ${event.social} called.]]
 * 
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_sessions_add_notify_join_session_accepted"`
 * @member {string} local_user_id The Product User ID for the user who initialized the game
 * @member {int64} ui_event_id The UI Event associated with this Join Game event. This should be used with ${function.eos_sessions_copy_session_handle_by_ui_event_id} to get a handle to be used when calling ${function.eos_sessions_join_session}.
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_add_notify_leave_session_requested
 * @desc **Epic Online Services Function:** [EOS_Sessions_AddNotifyLeaveSessionRequested](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-add-notify-leave-session-requested)
 * 
 * This function registers to receive notifications about leave session requests performed by local user via the overlay. When user requests to leave the session in the social overlay, the SDK does not automatically leave the session, it is up to the game to perform any necessary cleanup and call the ${function.eos_sessions_destroy_session} method using the `session_name` sent in the notification function.
 * 
 * [[Note: If the returned notification ID is valid, you must call ${function.eos_sessions_remove_notify_join_session_accepted} when you no longer wish to have the ${event.social} called.]]
 * 
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_sessions_add_notify_leave_session_requested"`
 * @member {string} local_user_id The Product User ID of the local user who received the leave session notification.
 * @member {string} session_name The name of the session associated with the leave session request.
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_add_notify_send_session_native_invite_requested
 * @desc **Epic Online Services Function:** [EOS_Sessions_AddNotifySendSessionNativeInviteRequested](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-add-notify-send-session-native-invite-requested)
 * 
 * This function registers to receive notifications about a session "INVITE" performed by a local user via the overlay. This is only needed when a configured integrated platform has EOS_IPMF_DisableSDKManagedSessions set. The EOS SDK will then use the state of EOS_IPMF_PreferEOSIdentity and EOS_IPMF_PreferIntegratedIdentity to determine when the ${event.social} is triggered.
 * 
 * [[Note: If the returned notification ID is valid, you must call ${function.eos_sessions_remove_notify_join_session_accepted} when you no longer wish to have the ${event.social} called.]]
 * 
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_sessions_add_notify_send_session_native_invite_requested"`
 * @member {string} local_user_id The Product User ID of the local user who is inviting
 * @member {string} target_native_account_type The Native Platform Account Type. If only a single integrated platform is configured then this will always reference that platform.
 * @member {string} target_user_native_account_id The Native Platform Account ID of the target user being invited
 * @member {string} session_id The session ID that the user is being invited to
 * @member {int64} ui_event_id Identifies this event which will need to be acknowledged with ${function.eos_ui_acknowledge_event_id}.
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_add_notify_session_invite_accepted
 * @desc **Epic Online Services Function:** [EOS_Sessions_AddNotifySessionInviteAccepted](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-add-notify-session-invite-accepted)
 * 
 * This function registers to receive notifications when a user accepts a session invite via the social overlay.
 * 
 * [[Note: If the returned notification ID is valid, you must call ${function.eos_sessions_remove_notify_join_session_accepted} when you no longer wish to have the ${event.social} called.]]
 * 
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_sessions_add_notify_session_invite_accepted"`
 * @member {string} local_user_id The Product User ID of the user who accepted the invitation
 * @member {string} invite_id The invite ID that was accepted
 * @member {string} session_id The session ID that should be used for joining
 * @member {string} target_user_id The Product User ID of the user who sent the invitation
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_add_notify_session_invite_rejected
 * @desc **Epic Online Services Function:** [EOS_Sessions_AddNotifySessionInviteRejected](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-add-notify-session-invite-rejected)
 * 
 * This function registers to receive notifications when a user rejects a session invite.
 * 
 * [[Note: If the returned notification ID is valid, you must call ${function.eos_sessions_remove_notify_join_session_accepted} when you no longer wish to have the ${event.social} called.]]
 * 
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_sessions_add_notify_session_invite_rejected"`
 * @member {string} invite_id The invite ID
 * @member {string} target_user_id The Product User ID of the user who sent the invitation
 * @member {string} session_id Session ID
 * @member {string} local_user_id The Product User ID of the local user who rejected the invitation
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_copy_session_handle_by_invite_id
 * @desc **Epic Online Services Function:** [EOS_Sessions_CopySessionHandleByInviteId](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-copy-session-handle-by-invite-id)
 * 
 * This function is used to immediately retrieve a handle to the session information from after notification of an invite. If the call returns an `EOS_RESULT.SUCCESS` result, a handle has been created and you need to manually free it afterwards by calling ${function.eos_session_details_release} to release the memory associated with it.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if the information is available
 * * `EOS_RESULT.INVALID_PARAMETERS` if you pass an invalid invite ID
 * * `EOS_RESULT.INCOMPATIBLE_VERSION` if the API version passed in is incorrect
 * * `EOS_RESULT.NOT_FOUND` if the invite ID cannot be found
 * 
 * @param {string} invite_id The invite ID for which to retrieve a session handle
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_copy_session_handle_by_ui_event_id
 * @desc **Epic Online Services Function:** [EOS_Sessions_CopySessionHandleByUiEventId](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-copy-session-handle-by-ui-event-id)
 * 
 * This function is used to immediately retrieve a handle to the session information from after notification of a join game event. If the call returns an `EOS_RESULT.SUCCESS` result, a handle has been created and you need to manually free it afterwards by calling ${function.eos_session_details_release} to release the memory associated with it.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if the information is available
 * * `EOS_RESULT.INVALID_PARAMETERS` if you pass an invalid invite ID
 * * `EOS_RESULT.INCOMPATIBLE_VERSION` if the API version passed in is incorrect
 * * `EOS_RESULT.NOT_FOUND` if the invite ID cannot be found
 * 
 * @param {int64} ui_event_id The UI Event associated with the session
 * 
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_copy_session_handle_for_presence
 * @desc **Epic Online Services Function:** [EOS_Sessions_CopySessionHandleForPresence](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-copy-session-handle-for-presence)
 * 
 * This function is used to immediately retrieve a handle to the session information which was marked with `presence_enabled` on create or join. If the call returns an `EOS_RESULT.SUCCESS` result, a handle has been created and you need to manually free it afterwards by calling ${function.eos_session_details_release} to release the memory associated with it.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if the information is available
 * * `EOS_RESULT.INVALID_PARAMETERS` if you pass an invalid invite ID
 * * `EOS_RESULT.INCOMPATIBLE_VERSION` if the API version passed in is incorrect
 * * `EOS_RESULT.NOT_FOUND` if there is no session with `presence_enabled`
 *
 * @param {string} local The Product User ID of the local user associated with the session
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_create_session_modification
 * @desc **Epic Online Services Function:** [EOS_Sessions_CreateSessionModification](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-create-session-modification)
 * 
 * This function creates a session modification handle. The session modification handle is used to build a new session and can be applied with ${function.eos_sessions_update_session}. The handle must be released by calling ${function.eos_session_modification_release} once it is no longer needed.
 * 
 * The function returns `EOS_RESULT.SUCCESS` if we successfully created the session modification handle, or an error result if the input data was invalid.
 * 
 * @param {array[constant.EOS_ONLINE_PLATFORM_TYPE]} allowed_platform_ids An array of platform IDs indicating the player platforms allowed to register with the session. The session will be unrestricted if you pass `undefined`.
 * @param {bool} presence_enabled Determines whether or not this session should be the one associated with the local user's presence information. If `true`, this session will be associated with presence. Only one session at a time can have this flag set to `true`. This affects the ability of the Social Overlay to show game related actions to take in the user's social graph. * using the `presence_enabled` flags within the Sessions interface * using the `presence_enabled` flags within the Lobby interface * using ${function.eos_presence_modification_set_join_info}.
 * @param {bool} sanctions_enabled If `true`, sanctioned players can neither join nor register with this session and, in the case of join, will return ${constant.EOS_RESULT} code `EOS_RESULT.SESSIONS_PLAYER_SANCTIONED`.
 * @param {string} bucket_id The bucket ID associated with the session
 * @param {string} local_user_id The Product User ID of the local user associated with the session
 * @param {real} max_players The maximum number of players allowed in the session
 * @param {string} session_id An optional session ID - set to a globally unique value to override the backend assignment. If not specified, the backend service will assign one to the session. Do not mix and match. This value can be of size [EOS_SESSIONMODIFICATION_MIN_SESSIONIDOVERRIDE_LENGTH, EOS_SESSIONMODIFICATION_MAX_SESSIONIDOVERRIDE_LENGTH]
 * @param {string} session_name The name of the session to create
 * 
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_create_session_search
 * @desc **Epic Online Services Function:** [EOS_Sessions_CreateSessionSearch](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-create-session-search)
 * 
 * This function creates a session search handle. This handle may be modified to include various search parameters. Searching is possible in three methods, all mutually exclusive:
 * 
 * * set the session ID to find a specific session
 * * set the target user ID to find a specific user
 * * set session parameters to find an array of sessions that match the search criteria
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if the search creation completes successfully
 * * `EOS_RESULT.INVALID_PARAMETERS` if any of the options are incorrect
 * 
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_destroy_session
 * @desc **Epic Online Services Function:** [EOS_Sessions_DestroySession](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-destroy-session)
 * 
 * This function destroys a session given a session name.
 *
 * @param {string} session_name The name of the session to destroy
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_sessions_destroy_session"`
 * @member {constant.EOS_RESULT} status The result of the function call
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned in the original call to the function
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_dump_session_state
 * @desc **Epic Online Services Function:** [EOS_Sessions_DumpSessionState](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-dump-session-state)
 * 
 * This function dumps the contents of active sessions that exist locally to the log output, purely for debug purposes.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if the output operation completes successfully
 * * `EOS_RESULT.NOT_FOUND` if the session specified does not exist
 * * `EOS_RESULT.INVALID_PARAMETERS` if any of the options are incorrect
 *
 * @param {string} session_name The name of the session
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_end_session
 * @desc **Epic Online Services Function:** [EOS_Sessions_EndSession](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-end-session)
 * 
 * This function marks a session as ended, making it available to find if "join in progress" was disabled. The session may be started again if desired.
 * 
 * The function returns an async identifier.
 *
 * @param {string} session_name The name of the session to set as no longer in progress
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_sessions_end_session"`
 * @member {constant.EOS_RESULT} status The result code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned in the original call to the function
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_get_invite_count
 * @desc **Epic Online Services Function:** [EOS_Sessions_GetInviteCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-get-invite-count)
 * 
 * This function gets the number of known invites for a given user. It returns the number of known invites for a given user or 0 if there is an error.
 *
 * @param {string} local The Product User ID of the local user who has one or more invitations in the cache
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_get_invite_id_by_index
 * @desc **Epic Online Services Function:** [EOS_Sessions_GetInviteIdByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-get-invite-id-by-index)
 * 
 * This function retrieves an invite ID from a list of active invites for a given user.
 * 
 * @param {string} local_user_id The Product User ID of the local user who has an invitation in the cache
 * @param {real} index The index of the invite ID to retrieve
 *
 * @returns {string}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_is_user_in_session
 * @desc **Epic Online Services Function:** [EOS_Sessions_IsUserInSession](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-is-user-in-session)
 * 
 * This function returns whether or not a given user can be found in a specified session.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if the user is found in the specified session
 * * `EOS_RESULT.NOT_FOUND` if the user is not found in the specified session
 * * `EOS_RESULT.INVALID_PARAMETERS` if you pass an invalid invite ID
 * * `EOS_RESULT.INCOMPATIBLE_VERSION` if the API version passed in is incorrect
 * * `EOS_RESULT.INVALID_PRODUCT_USER_ID` if an invalid target user is specified
 * * `EOS_RESULT.SESSIONS_INVALID_SESSION` if the session specified is invalid
 * 
 * @param {string} session_name The active session name to search within
 * @param {string} target_user_id The product User ID to search for in the session
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_sessions_join_session
 * @desc **Epic Online Services Function:** [EOS_Sessions_JoinSession](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-join-session)
 * 
 * This function joins a session, creating a local session under a given session name. The backend will validate various conditions to make sure it is possible to join the session.
 * 
 * The function returns the async identifier.
 * 
 * @param {bool} presence_enabled Determines whether or not this session should be the one associated with the local user's presence information. If true, this session will be associated with presence. Only one session at a time can have this flag true. This affects the ability of the Social Overlay to show game related actions to take in the user's social graph. * using the `presence_enabled` flags within the Sessions interface * using the `presence_enabled` flags within the Lobby interface * using ${function.eos_presence_modification_set_join_info}
 * @param {string} local_user_id The Product User ID of the local user who is joining the session
 * @param {string} session_name Name of the session to create after joining session
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_sessions_join_session"`
 * @member {constant.EOS_RESULT} status The result code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_query_invites
 * @desc **Epic Online Services Function:** [EOS_Sessions_QueryInvites](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-query-invites)
 * 
 * This function retrieves all existing invites for a single user.
 *
 * @param {string} target_user_id The Product User ID to query for invitations
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_sessions_query_invites"`
 * @member {constant.EOS_RESULT} status The result code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} local_user_id The Product User of the local user who made the request
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_register_players
 * @desc **Epic Online Services Function:** [EOS_Sessions_RegisterPlayers](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-register-players)
 * 
 * This function registers a group of players with the session, allowing them to invite others or otherwise indicate they are part of the session for determining a full session.
 * 
 * The function returns an async identifier.
 *
 * @param {string} session_name The name of the session for which to register players
 * @param {array} array_product_user_ids Array of players to register with the session
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_sessions_register_players"`
 * @member {constant.EOS_RESULT} status The result code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {array[string]} registered_players The players that were successfully registered
 * @member {array[string]} sanctioned_players The players that failed to register because they are sanctioned
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_reject_invite
 * @desc **Epic Online Services Function:** [EOS_Sessions_RejectInvite](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-reject-invite)
 * 
 * This function rejects an invite from another player.
 * 
 * The function returns an async identifier.
 * 
 * @param {string} local_user_id The Product User ID of the local user rejecting the invitation
 * @param {string} invite_id The invite ID to reject
 * 
 * @event social
 * @member {string} type the string `"eos_sessions_reject_invite"`
 * @member {constant.EOS_RESULT} status The result code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_remove_notify_join_session_accepted
 * @desc **Epic Online Services Function:** [EOS_Sessions_RemoveNotifyJoinSessionAccepted](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-remove-notify-join-session-accepted)
 * 
 * This function unregisters from receiving notifications when a user accepts a session join game via the social overlay.
 *
 * @param {real} notification_id A handle representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_sessions_remove_notify_leave_session_requested
 * @desc **Epic Online Services Function:** [EOS_Sessions_RemoveNotifyLeaveSessionRequested](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-remove-notify-leave-session-requested)
 * 
 * This function unregisters from receiving notifications when a user performs a leave lobby action via the overlay.
 * 
 * @param {real} notification_id A handle representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_sessions_remove_notify_send_session_native_invite_requested
 * @desc **Epic Online Services Function:** [EOS_Sessions_RemoveNotifySendSessionNativeInviteRequested](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-remove-notify-send-session-native-invite-requested)
 * 
 * This function unregisters from receiving notifications when a user requests a send invite via the overlay.
 *
 * @param {real} notification_id A handle representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_sessions_remove_notify_session_invite_accepted
 * @desc **Epic Online Services Function:** [EOS_Sessions_RemoveNotifySessionInviteAccepted](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-remove-notify-session-invite-accepted)
 * 
 * This function unregisters from receiving notifications when a user accepts a session invite via the social overlay.
 *
 * @param {real} notification_id A handle representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_sessions_remove_notify_session_invite_received
 * @desc **Epic Online Services Function:** [EOS_Sessions_RemoveNotifySessionInviteReceived](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-remove-notify-session-invite-received)
 * 
 * This function unregisters from receiving session invites.
 *
 * @param {real} notification_id A handle representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_sessions_remove_notify_session_invite_rejected
 * @desc **Epic Online Services Function:** [EOS_Sessions_RemoveNotifySessionInviteReceived](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-remove-notify-session-invite-rejected)
 * 
 * This function unregisters from receiving notifications when a user rejects a session invite via the social overlay.
 * 
 * @param {real} notification_id A handle representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_sessions_send_invite
 * @desc **Epic Online Services Function:** [EOS_Sessions_SendInvite](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-send-invite)
 * 
 * This function sends an invite to another player. User must have created the session or be registered in the session or else the call will fail.
 * 
 * The function returns an async identifier.
 * 
 * @param {string} local_user_id The Product User ID of the local user sending the invitation
 * @param {string} session_name The name of the session associated with the invite
 * @param {string} target_user_id The Product User of the remote user receiving the invitation
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_sessions_send_invite"`
 * @member {constant.EOS_RESULT} status The result code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_start_session
 * @desc **Epic Online Services Function:** [EOS_Sessions_StartSession](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-start-session)
 * 
 * This function marks a session as started, making it unable to find if session properties indicate "join in progress" is not available.
 * 
 * The function returns an async identifier.
 *
 * @param {string} session_name The name of the session to set in progress
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_sessions_start_session"`
 * @member {constant.EOS_RESULT} status The result code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_unregister_players
 * @desc **Epic Online Services Function:** [EOS_Sessions_UnregisterPlayers](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-unregister-players)
 * 
 * This function unregisters a group of players with the session, freeing up space for others to join.
 * 
 * The function returns an async identifier.
 * 
 * @param {string} session_name The name of the session for which to unregister players
 * @param {array} array_product_user_ids An array of players to unregister from the session
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_sessions_unregister_players"`
 * @member {constant.EOS_RESULT} status The result code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {array[string]} unregistered_players The players that successfully unregistered
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_update_session
 * @desc **Epic Online Services Function:** [EOS_Sessions_UpdateSession](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-update-session)
 *
 * This function updates a session given a session modification handle created by ${function.eos_sessions_create_session_modification} or ${function.eos_sessions_update_session_modification}.
 * 
 * The function returns an async identifier.
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_sessions_update_session"`
 * @member {constant.EOS_RESULT} status The result code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} session_id ID of the session that was created/modified
 * @member {string} session_name Name of the session that was created/modified
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_sessions_update_session_modification
 * @desc **Epic Online Services Function:** [EOS_Sessions_UpdateSessionModification](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-update-session-modification)
 * 
 * This function creates a session modification handle. The session modification handle is used to modify an existing session and can be applied with ${function.eos_sessions_update_session}. The handle must be released by calling ${function.eos_session_modification_release} once it is no longer needed.
 * 
 * The function returns `EOS_RESULT.SUCCESS` if the session modification handle could be successfully created, or an error result if the input data was invalid.
 *
 * @param {string} session_name The name of the session to update
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_session_search_copy_search_result_by_index
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_CopySearchResultByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-copy-search-result-by-index)
 * 
 * This function is used to immediately retrieve a handle to the session information from a given search result. If the call returns an `EOS_RESULT.SUCCESS` result, a handle has been created and you need to manually free it afterwards by calling ${function.eos_session_details_release} to release the memory associated with it.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if the information is available
 * * `EOS_RESULT.INVALID_PARAMETERS` if you pass an invalid index
 * * `EOS_RESULT.INCOMPATIBLE_VERSION` if the API version passed in is incorrect
 * 
 * @param {real} session_index The index of the session to retrieve within the completed search query
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_session_search_find
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_Find](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-find)
 * 
 * This function finds sessions matching the search criteria set up via this session search handle. When the operation completes, this handle will have the search results that can be parsed.
 * 
 * The function returns an async identifier.
 *
 * @param {string} local_user_id The Product User ID of the local user who is searching
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_session_search_find"`
 * @member {constant.EOS_RESULT} status The result code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_session_search_get_search_result_count
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_GetSearchResultCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-get-search-result-count)
 *
 * This function gets the number of search results found by the search parameters in this search. It returns the number of search results found by the query or 0 if the search is not complete.
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_session_search_release
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_Release](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-release)
 *
 * This function releases the memory associated with a session search. This must be called on data retrieved from ${function.eos_sessions_create_session_search}.
 * 
 * @func_end
 */

/**
 * @func eos_session_search_remove_parameter
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_RemoveParameter](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-remove-parameter)
 * 
 * This function removes a parameter from the array of search criteria.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if removing this search parameter was successful
 * * `EOS_RESULT.INVALID_PARAMETERS` if the search key is invalid
 * * `EOS_RESULT.NOT_FOUND` if the parameter was not a part of the search criteria
 * * `EOS_RESULT.INCOMPATIBLE_VERSION` if the API version passed in is incorrect
 *
 * @param {string} key The search parameter key to remove from the search
 * @param {constant.EOS_COMPARISON_OP} comparison_op The search comparison operation associated with the key to remove
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_session_search_set_max_results
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_SetMaxResults](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-set-max-results)
 * 
 * This function sets the maximum number of search results to return in the query, can't be more than ${constant.EOS_SESSIONS_MAX_SEARCH_RESULTS}.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if setting the max results was successful
 * * `EOS_RESULT.INVALID_PARAMETERS` if the number of results requested is invalid
 * * `EOS_RESULT.INCOMPATIBLE_VERSION` if the API version passed in is incorrect
 *
 * @param {real} max_search_results The maximum number of search results returned with this query, may not exceed ${constant.EOS_SESSIONS_MAX_SEARCH_RESULTS}
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_session_search_set_parameter
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_SetParameter](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-set-parameter)
 * 
 * This function adds a parameter to an array of search criteria combined via an implicit AND operator. Setting SessionId or TargetUserId will result in ${function.eos_session_search_find} failing.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if setting this search parameter was successful
 * * `EOS_RESULT.INVALID_PARAMETERS` if the search criteria is invalid
 * * `EOS_RESULT.INCOMPATIBLE_VERSION` if the API version passed in is incorrect
 *
 * @param {constant.EOS_COMPARISON_OP} comparison_op The type of comparison to make against the search parameter
 * @param {struct} attribute A struct with two variables `key` and `value`, representing the key/value pair that describes the search parameter
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_session_search_set_session_id
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_SetSessionId](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-set-session-id)
 * 
 * This function sets a session ID to find and will return at most one search result. Setting TargetUserId or SearchParameters will result in ${function.eos_session_search_find} failing.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if setting this session ID was successful
 * * `EOS_RESULT.INVALID_PARAMETERS` if the session ID is invalid
 * * `EOS_RESULT.INCOMPATIBLE_VERSION` if the API version passed in is incorrect
 *
 * @param {string} session_id Search sessions for a specific session ID, returning at most one session
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @func eos_session_search_set_target_user_id
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_SetTargetUserId](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-set-target-user-id)
 * 
 * This function sets a target user ID to find and will return at most one search result. Setting SessionId or SearchParameters will result in ${function.eos_session_search_find} failing.
 * 
 * [[Note: A search result will only be found if this user is in a public session.]]
 * 
 * The function returns one of the following:
 * 
 * * `EOS_RESULT.SUCCESS` if setting this target user ID was successful
 * * `EOS_RESULT.INVALID_PARAMETERS` if the target user ID is invalid
 * * `EOS_RESULT.INCOMPATIBLE_VERSION` if the API version passed in is incorrect
 *
 * @param {string} target_user_id The Product User ID to find; return any sessions where the user matching this ID is currently registered
 *
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */

/**
 * @constant EOS_ONLINE_SESSION_STATE
 * @desc **Epic Online Services Enum:** [EOS_EOnlineSessionState](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-online-session-state)
 * 
 * This enum contains all possible states of an existing named session.
 * 
 * @member NO_SESSION An online session has not been created yet
 * @member CREATING An online session is in the process of being created
 * @member PENDING Session has been created but the session hasn't started (pre match lobby)
 * @member STARTING Session has been asked to start (may take time due to communication with backend)
 * @member IN_PROGRESS The current session has started. Sessions with join in progress disabled are no longer joinable
 * @member ENDING The session is still valid, but the session is no longer being played (post match lobby)
 * @member ENDED The session is closed and any stats committed
 * @member DESTROYING The session is being destroyed
 * 
 * @constant_end
 */

/**
 * @constant EOS_SESSION_ATTRIBUTE_ADVERTISEMENT_TYPE
 * @desc **Epic Online Services Enum:** [EOS_ESessionAttributeAdvertisementType](https://dev.epicgames.com/docs/ja/api-ref/enums/eos-e-session-attribute-advertisement-type)
 * 
 * This enum holds the possible advertisement properties for a single attribute associated with a session.
 * 
 * @member DONT_ADVERTISE Don't advertise via the online service
 * @member ADVERTISE Advertise via the online service only
 * 
 * @constant_end
 */

/**
 * @constant EOS_ONLINE_SESSION_PERMISSION_LEVEL
 * @desc **Epic Online Services Enum:** [EOS_EOnlineSessionState](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-online-session-state)
 * 
 * This enum holds the possible permission levels for a session. The permission level gets more restrictive further down.
 * 
 * @member PUBLIC_ADVERTISED Anyone can find this session as long as it isn't full
 * @member JOIN_VIA_PRESENCE Players who have access to presence can see this session
 * @member INVITE_ONLY Only players with invites registered can see this session
 * 
 * @constant_end
 */

/**
 * @constant EOS_SESSIONS_MAX_SEARCH_RESULTS
 * @desc This macro defines the maximum number of session search results.
 * 
 * @constant_end
 */
