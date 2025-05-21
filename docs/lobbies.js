// Modules

/**
 * @module lobbies
 * @title Lobbies
 * @desc **Epic Online Services Interface**: [Lobby Interface](https://dev.epicgames.com/docs/api-ref/interfaces/lobby)
 * 
 * This module can be used to add lobbies to your game so players can create, join, leave, and manage lobbies.
 * 
 * Lobbies provide a persistent connection between players (also called "users") for the purpose of sharing game (or other software application) and player state with real-time updates. Typically, players can create or join lobbies to form teams, select pre-game options, and wait for additional players to join in before playing together. Using the Lobbies module, your players can create, join, leave, and manage lobbies.
 * 
 * [[Note: See the [Lobbies Introduction](https://dev.epicgames.com/docs/game-services/lobbies-and-sessions/lobbies/lobbies-intro) for a more detailed guide.]]
 * 
 * @section_func
 * @desc 
 * @ref eos_lobby_*
 * @section_end
 * 
 * @section_struct
 * @desc 
 * @ref EOS_Lobby_Attribute
 * @ref EOS_LobbyDetails_Info
 * @ref EOS_LobbyDetails_MemberInfo
 * @section_end
 * 
 * @section_const
 * @desc 
 * @ref EOS_LOBBY_MAX_SEARCH_RESULTS
 * @ref EOS_LobbyAttributeVisibility
 * @ref EOS_LobbyMemberStatus
 * @ref EOS_LobbyPermissionLevel
 * @ref EOS_IntegratedPlatformType
 * @ref EOS_OnlinePlatformType
 * @section_end
 * 
 * @module_end
 */

// Functions

/**
 * @func eos_lobby_add_notify_join_lobby_accepted
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifyJoinLobbyAccepted](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-join-lobby-accepted)
 *
 * This function registers to receive notifications about lobby "JOIN" performed by local user (when no invite) via the overlay.
 * 
 * The function returns a notification ID.
 * 
 * [[Note: If the returned notification ID is valid, you must call ${function.eos_lobby_remove_notify_join_lobby_accepted} when you no longer wish to have the ${event.social} called.]]
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_add_notify_join_lobby_accepted"`
 * @member {string} local_user_id The Product User ID of the local user who is joining
 * @member {int64} ui_event_id The UI Event associated with this Join Game event. This should be used with ${function.eos_lobby_copy_lobby_details_handle_by_ui_event_id} to get a handle to be used when calling ${function.eos_lobby_join_lobby}.
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_add_notify_leave_lobby_requested
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifyLeaveLobbyRequested](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-leave-lobby-requested)
 * 
 * This function registers to receive notifications about leave lobby requests performed by the local user via the overlay. When a user requests to leave the lobby in the social overlay, the SDK does not automatically leave the lobby, it is up to the game to perform any necessary cleanup and call the ${function.eos_lobby_leave_lobby} method using the `lobby_id` sent in the ${event.social}.
 * 
 * The function returns a notification ID.
 * 
 * [[Note: If the returned notification ID is valid, you must call ${function.eos_lobby_remove_notify_leave_lobby_requested} when you no longer wish to have the ${event.social} called.]]
 * 
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_add_notify_leave_lobby_requested"`
 * @member {string} local_user_id The Product User ID of the local user who received the leave lobby notification.
 * @member {string} lobby_id The lobby ID associated with the leave lobby request.
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_add_notify_lobby_invite_accepted
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifyLobbyInviteAccepted](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-lobby-invite-accepted)
 *
 * This function registers to receive notifications about lobby invites accepted by local user via the overlay.
 * 
 * The function returns a notification ID.
 * 
 * [[Note: If the returned notification ID is valid, you must call ${function.eos_lobby_remove_notify_leave_lobby_requested} when you no longer wish to have the ${event.social} called.]]
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_add_notify_lobby_invite_accepted"`
 * @member {string} local_user_id The Product User ID of the local user who received the invitation
 * @member {string} lobby_id Lobby ID that the user has been invited to
 * @member {string} invite_id The invite ID
 * @member {string} target_user_id The Product User ID of the user who sent the invitation
 * @event_end

 * @func_end
 */

/**
 * @func eos_lobby_add_notify_lobby_invite_received
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifyLobbyInviteReceived](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-lobby-invite-received)
 * 
 * This function registers to receive notifications about lobby invites sent to local users.
 * 
 * The function returns a notification ID.
 * 
 * [[Note: If the returned notification ID is valid, you must call ${function.eos_lobby_remove_notify_leave_lobby_requested} when you no longer wish to have the ${event.social} called.]]
 * 
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_add_notify_lobby_invite_received"`
 * @member {string} local_user_id The Product User ID of the local user who received the invitation
 * @member {string} invite_id The ID of the invitation
 * @member {string} target_user_id The Product User ID of the user who sent the invitation
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_add_notify_lobby_invite_rejected
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifyLobbyInviteRejected](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-lobby-invite-rejected)
 *
 * This function registers to receive notifications about lobby invites rejected by local user.
 * 
 * The function returns a notification ID.
 * 
 * [[Note: If the returned notification ID is valid, you must call ${function.eos_lobby_remove_notify_leave_lobby_requested} when you no longer wish to have the ${event.social} called.]]
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_add_notify_lobby_invite_rejected"`
 * @member {string} local_user_id The Product User ID of the local user who received the invitation
 * @member {string} lobby_id Lobby ID that the user has been invited to
 * @member {string} invite_id The invite ID
 * @member {string} target_user_id The Product User ID of the user who sent the invitation
 * @event_end
 * 
 * @func_end
 */

/**
 * @constant EOS_LobbyMemberStatus
 * @desc **Epic Online Services Function:** [EOS_ELobbyMemberStatus](https://dev.epicgames.com/docs/api-ref/enums/eos-e-lobby-member-status)
 * 
 * This enumeration holds the possible types of lobby member status.
 * 
 * @member JOINED The user has joined the lobby
 * @member LEFT The user has explicitly left the lobby
 * @member DISCONNECTED The user has unexpectedly left the lobby
 * @member KICKED The user has been kicked from the lobby
 * @member PROMOTED The user has been promoted to lobby owner
 * @member CLOSED The lobby has been closed and user has been removed
 * 
 * @constant_end
 */

/**
 * @func eos_lobby_add_notify_lobby_member_status_received
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifyLobbyMemberStatusReceived](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-lobby-member-status-received)
 *
 * This function registers to receive notifications about the changing status of lobby members.
 * 
 * The function returns a notification ID.
 * 
 * [[Note: If the returned notification ID is valid, you must call ${function.eos_lobby_remove_notify_leave_lobby_requested} when you no longer wish to have the ${event.social} called.]]
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_add_notify_lobby_member_status_received"`
 * @member {string} target_user_id The Product User ID of the lobby member
 * @member {string} lobby_id The ID of the lobby
 * @member {constant.EOS_LobbyMemberStatus} current_status The latest status of the user
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_add_notify_lobby_member_update_received
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifyLobbyMemberUpdateReceived](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-lobby-member-update-received)
 *
 * This function registers to receive notifications when a lobby member updates the attributes associated with themselves inside the lobby.
 * 
 * The function returns a notification ID.
 * 
 * [[Note: If the returned notification ID is valid, you must call ${function.eos_lobby_remove_notify_leave_lobby_requested} when you no longer wish to have the ${event.social} called.]]
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_add_notify_lobby_member_update_received"`
 * @member {string} target_user_id The Product User ID of the lobby member
 * @member {string} lobby_id The ID of the lobby
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_add_notify_lobby_update_received
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifyLobbyUpdateReceived](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-lobby-update-received)
 *
 * This function registers to receive notifications when a lobby owner updates the attributes associated with the lobby.
 * 
 * The function returns a notification ID.
 * 
 * [[Note: If the returned notification ID is valid, you must call ${function.eos_lobby_remove_notify_leave_lobby_requested} when you no longer wish to have the ${event.social} called.]]
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_add_notify_lobby_update_received"`
 * @member {string} lobby_id The ID of the lobby
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_add_notify_rtc_room_connection_changed
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifyRTCRoomConnectionChanged](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-add-notify-rtc-room-connection-changed)
 *
 * This function registers to receive notifications of when the RTC Room for a particular lobby has a connection status change. The RTC Room connection status is independent of the lobby connection status, however the lobby system will attempt to keep them consistent, automatically connecting to the RTC room after joining a lobby which has an associated RTC room and disconnecting from the RTC room when a lobby is left or disconnected. This notification is entirely informational and requires no action in response by the application. If the connected status is offline (`is_connected` is `false`), the connection will automatically attempt to reconnect. The purpose of this notification is to allow applications to show the current connection status of the RTC room when the connection is not established. Unlike ${function.eos_rtc_add_notify_disconnected}, ${function.eos_rtc_leave_room} should not be called when the RTC room is disconnected. This function will only succeed when called on a lobby the local user is currently a member of.
 * 
 * A valid notification ID if the callback handler was successfully registered, or EOS_INVALID_NOTIFICATIONID if the input was invalid, the lobby did not exist, or the lobby did not have an RTC room.
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_add_notify_rtc_room_connection_changed"`
 * @member {string} local_user_id The Product User ID of the local user who is in the lobby and registered for notifications
 * @member {string} lobby_id The ID of the lobby which had a RTC Room connection state change
 * @member {constant.EOS_Result} disconnect_reason If `is_connected` is `false`, this result will be the reason we were disconnected. `EOS_Result.Success`: The room was left locally. This may be because: the associated lobby was left or destroyed, the connection to the lobby was interrupted, or because the SDK is being shutdown. If the lobby connection returns (lobby did not permanently go away), EOS will reconnect. EOS_NoConnection: There was a network issue connecting to the server. EOS will attempt to reconnect soon. EOS_RTC_UserKicked: The user has been kicked by the server. We will not reconnect. EOS_RTC_UserBanned: The user has been banned by the server. We will not reconnect. EOS_ServiceFailure: A known error occurred during interaction with the server. We will attempt to reconnect soon. EOS_UnexpectedError: Unexpected error. We will attempt to reconnect soon.
 * @member {bool} is_connected The new connection state of the room
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_add_notify_send_lobby_native_invite_requested
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifySendLobbyNativeInviteRequested](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-send-lobby-native-invite-requested)
 * 
 * This function registers to receive notifications about a lobby "INVITE" performed by a local user via the overlay. This is only needed when a configured integrated platform has EOS_IPMF_DisableSDKManagedSessions set. The EOS SDK will then use the state of EOS_IPMF_PreferEOSIdentity and EOS_IPMF_PreferIntegratedIdentity to determine when the ${event.social} is called.
 * 
 * [[Note: If the returned notification ID is valid, you must call ${function.eos_lobby_remove_notify_leave_lobby_requested} when you no longer wish to have the ${event.social} called.]]
 *
 * @returns {int64}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_add_notify_send_lobby_native_invite_requested"`
 * @member {string} local_user_id The Product User ID of the local user who is inviting.
 * @member {string} lobby_id The lobby ID that the user is being invited to
 * @member {constant.EOS_IntegratedPlatformType} target_native_account_type The Native Platform Account Type. If only a single integrated platform is configured then this will always reference that platform.
 * @member {string} target_user_native_account_id The Native Platform Account ID of the target user being invited.
 * @member {int64} ui_event_id Identifies this event which will need to be acknowledged with EOS_UI_AcknowledgeEventId().
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_copy_lobby_details_handle
 * @desc **Epic Online Services Function:** [EOS_Lobby_CopyLobbyDetailsHandle](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-copy-lobby-details-handle)
 * 
 * This function creates a handle to an existing lobby. If the call returns an `EOS_Result.Success` result, the out parameter, OutLobbyDetailsHandle, must be passed to ${function.eos_lobby_details_release} to release the memory associated with it.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` if the lobby handle was created successfully
 * * `EOS_Result.InvalidParameters` if any of the options are incorrect
 * * `EOS_Result.IncompatibleVersion` if the API version passed in is incorrect
 * * `EOS_Result.NotFound` if the lobby doesn't exist
 * 
 * @param {string} lobby_id The ID of the lobby
 * @param {string} local_user_id The Product User ID of the local user making the request
 *
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_copy_lobby_details_handle_by_invite_id
 * @desc **Epic Online Services Function:** [EOS_Lobby_CopyLobbyDetailsHandleByInviteId](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-copy-lobby-details-handle-by-invite-id)
 * 
 * This function is used to immediately retrieve a handle to the lobby information from after notification of an invite. If the call returns an `EOS_Result.Success` result, the out parameter, OutLobbyDetailsHandle, must be passed to ${function.eos_lobby_details_release} to release the memory associated with it.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` if the information is available
 * * `EOS_Result.InvalidParameters` if you pass an invalid invite ID
 * * `EOS_Result.IncompatibleVersion` if the API version passed in is incorrect
 * * `EOS_Result.NotFound` If the invite ID cannot be found
 * 
 * @param {string} invite_id The ID of an invitation to join the lobby
 * 
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_copy_lobby_details_handle_by_ui_event_id
 * @desc **Epic Online Services Function:** [EOS_Lobby_CopyLobbyDetailsHandleByUiEventId](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-copy-lobby-details-handle-by-ui-event-id)
 * 
 * This function is used to immediately retrieve a handle to the lobby information from after notification of an join game. If the call returns an `EOS_Result.Success` result, the out parameter, OutLobbyDetailsHandle, must be passed to ${function.eos_lobby_details_release} to release the memory associated with it.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` if the information is available and passed out in OutLobbyDetailsHandle
 * * `EOS_Result.InvalidParameters` if you pass an invalid ui event ID
 * * `EOS_Result.IncompatibleVersion` if the API version passed in is incorrect
 * * `EOS_Result.NotFound` If the invite ID cannot be found
 * 
 * @param {real} ui_event_id The UI Event associated with the lobby
 * 
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_create_lobby
 * @desc **Epic Online Services Function:** [EOS_Lobby_CreateLobby](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-create-lobby)
 * 
 * This function creates a lobby and adds the user to the lobby membership. There is no data associated with the lobby at the start and can be added with ${function.eos_lobby_update_lobby_modification}. If the lobby is successfully created with an RTC Room enabled, the lobby system will automatically join and maintain the connection to the RTC room as long as the local user remains in the lobby. Applications can use the ${function.eos_lobby_get_rtc_room_name} to get the name of the RTC Room associated with a lobby, which may be used with many of the `eos_rtc_*` suite of functions. This can be useful to: register for notifications for talking status; to mute or unmute the local user's audio output; to block or unblock room participants; to set local audio device settings; and more.
 * 
 * The function returns the async identifier.
 * 
 * @param {string} local_user_id The Product User ID of the local user creating the lobby; this user will automatically join the lobby as its owner
 * @param {array} allowed_platform_ids An array of platform IDs indicating the player platforms allowed to register with the session. Platform IDs are found in the EOS header file. These values are of the form EOS_OPT_<PlatformName>. For some platforms, the value will be in the EOS Platform specific header file. If null, the lobby will be unrestricted.
 * @param {string} lobby_id Set to a globally unique value to override the backend assignment. If an empty string `""` is specified, the backend service will assign one to the lobby. Do not mix and match override and non override settings. This value can be of size [EOS_LOBBY_MIN_LOBBYIDOVERRIDE_LENGTH, EOS_LOBBY_MAX_LOBBYIDOVERRIDE_LENGTH]
 * @param {string} bucket_id The bucket ID associated with the lobby
 * @param {real} max_lobby_members The maximum number of users that can be in the lobby at a time
 * @param {constant.EOS_LobbyPermissionLevel} permission_level The initial permission level of the lobby
 * @param {bool} allow_invites Whether members of the lobby are allowed to invite others
 * @param {bool} crossplay_opt_out This value indicates whether or not the lobby owner allows crossplay interactions. If `false`, the lobby owner will be treated as allowing crossplay. If it is set to `true`, `allowed_platform_ids` must have a single entry that matches the platform of the lobby owner.
 * @param {bool} disable_host_migration Is host migration allowed (will the lobby stay open if the original host leaves?) NOTE: ${function.eos_lobby_promote_member} is still allowed regardless of this setting.
 * @param {bool} enable_join_by_id Whether ${function.eos_lobby_join_lobby_by_id} is allowed. This is provided to support cases where an integrated platform's invite system is used. In these cases the game should provide the lobby ID securely to the invited player. Such as by attaching the lobby ID to the integrated platform's session data or sending the lobby ID within the invite data.
 * @param {bool} presence_enabled If `true`, this lobby will be associated with the local user's presence information. A user's presence can only be associated with one lobby at a time. This affects the ability of the Social Overlay to show game related actions to take in the user's social graph. * using the `presence_enabled` flags within the Sessions module * using the `presence_enabled` flags within the Lobby module * using ${function.eos_presence_modification_set_join_info}.
 * @param {bool} enable_rtc_room Creates a real-time communication (RTC) room for all members of this lobby. All members of the lobby will automatically join the RTC room when they connect to the lobby and they will automatically leave the RTC room when they leave or are removed from the lobby. While the joining and leaving of the RTC room is automatic, applications will still need to use the EOS RTC interfaces to handle all other functionality for the room.
 * @param {constant.EOS_RTC_JOINROOMFLAGS} flags Flags for the local user in this room. Set to 0 to not specify any flags. See ${constant.EOS_RTC_JOINROOMFLAGS}.
 * @param {bool} use_manual_audio_input Set to `true` to enable Manual Audio Input. If manual audio input is enabled, audio recording is not started and the audio buffers must be passed manually using ${function.eos_rtc_audio_send_audio}. The default is `false` if this struct is not specified.
 * @param {bool} use_manual_audio_output Set to `true` to enable Manual Audio Output. If manual audio output is enabled, audio rendering is not started and the audio buffers must be received with ${function.eos_rtc_audio_add_notify_audio_before_render} and rendered manually. The default is `false` if this struct is not specified.
 * @param {bool} local_audio_device_input_starts_muted Set to `true` to start the audio input device's stream as muted when first connecting to the RTC room. It must be manually unmuted with a call to ${function.eos_rtc_audio_update_sending}. If manual audio output is enabled, this value is ignored. The default value is `false` if this struct is not specified.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_create_lobby"`
 * @member {constant.EOS_Result} status The result code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} lobby_id The new lobby's ID
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_create_lobby_search
 * @desc **Epic Online Services Function:** [EOS_Lobby_CreateLobbySearch](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-create-lobby-search)
 * 
 * This function creates a lobby search handle. This handle may be modified to include various search parameters. Searching is possible in three methods, all mutually exclusive:
 * 
 * * set the lobby ID to find a specific lobby
 * * set the target user ID to find a specific user
 * * set lobby parameters to find an array of lobbies that match the search criteria
 * 
 * The function returns `EOS_Result.Success` if the search creation completes successfully, or `EOS_Result.InvalidParameters` if any of the options are incorrect.
 * 
 * [[Note: You should make sure to free the handle when no longer needed with ${function.eos_lobby_search_release}.]]
 *
 * @param {real} max_results The maximum number of results allowed from the search
 *
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_destroy_lobby
 * @desc **Epic Online Services Function:** [EOS_Lobby_DestroyLobby](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-destroy-lobby)
 * 
 * This function destroys a lobby given a lobby ID. It returns an async identifier.
 *
 * @param {string} lobby_id The ID of the lobby to destroy
 * @param {string} local_user_id The Product User ID of the local user requesting destruction of the lobby; this user must currently own the lobby
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_destroy_lobby"`
 * @member {constant.EOS_Result} status The result code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} lobby_id The destroyed lobby's ID
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_get_connect_string
 * @desc **Epic Online Services Function:** [EOS_Lobby_GetConnectString](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-get-connect-string)
 * 
 * This function gets the connection string for an EOS lobby. The connection string describes the presence of a player in terms of game state. Xbox platforms expect titles to embed this into their MultiplayerActivity at creation. When present, the SDK will use this value to populate session presence in the social overlay and facilitate platform invitations.
 *
 * @param {string} lobby_id The ID of the lobby to generate a connection string for
 * @param {string} local_user_id The Product User ID of the local user requesting the connection string generated from the lobby; this user must currently own the lobby
 *
 * @returns {string}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_get_invite_count
 * @desc **Epic Online Services Function:** [EOS_Lobby_GetInviteCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-get-invite-count)
 * 
 * This function gets the number of known invites for a given user. It returns the number of known invites for a given user or 0 if there is an error.
 *
 * @param {string} local_user_id The Product User ID of the local user whose cached lobby invitations you want to count
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_get_invite_id_by_index
 * @desc **Epic Online Services Function:** [EOS_Lobby_GetInviteIdByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-get-invite-id-by-index)
 * 
 * This function retrieves an invite ID from a list of active invites for a given user.
 *
 * @param {string} local_user_id The Product User ID of the local user who received the cached invitation
 * @param {real} index The index of the invitation ID to retrieve
 *
 * @returns {string}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_get_rtc_room_name
 * @desc **Epic Online Services Function:** [EOS_Lobby_GetRTCRoomName](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-get-rtc-room-name)
 * 
 * This function gets the name of the RTC room associated with a specific lobby a local user belongs to. This value can be used whenever you need a `room_name` value in the `rtc_*` suite of functions. RTC room names must not be used with ${function.eos_rtc_join_room}, ${function.eos_rtc_leave_room}, or ${function.eos_rtc_add_notify_disconnected}. Doing so will return `EOS_Result.AccessDenied` or ${constant.EOS_INVALID_NOTIFICATIONID} if used with those functions. This function will only succeed when called on a lobby the local user is currently a member of.
 * 
 * @param {string} local_user_id The Product User ID of the local user in the lobby
 * @param {string} lobby_id The ID of the lobby to get the RTC room name for
 * 
 * @returns {string}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_hard_mute_member
 * @desc **Epic Online Services Function:** [EOS_Lobby_HardMuteMember](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-hard-mute-member)
 * 
 * This function hard mutes an existing member in the lobby, can't speak but can hear other members of the lobby.
 *
 * @param {bool} hard_mute The `target_user_id` hard mute status (mute on or off)
 * @param {string} lobby_id The ID of the lobby
 * @param {string} local_user_id The Product User ID of the local user requesting the hard mute; this user must be the lobby owner
 * @param {string} target_user_id The Product User ID of the lobby member to hard mute
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_hard_mute_member"`
 * @member {constant.EOS_Result} status The result code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} lobby_id The ID of the lobby
 * @member {string} target_user_id The Product User ID of the lobby member whose mute status has been updated
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_is_rtc_room_connected
 * @desc **Epic Online Services Function:** [EOS_Lobby_IsRTCRoomConnected](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-is-rtc-room-connected)
 * 
 * This function gets the current connection status of the RTC Room for a lobby. The RTC Room connection status is independent of the lobby connection status, however the lobby system will attempt to keep them consistent, automatically connecting to the RTC room after joining a lobby which has an associated RTC room and disconnecting from the RTC room when a lobby is left or disconnected. This function will only succeed when called on a lobby the local user is currently a member of.
 *
 * @param {string} lobby_id The ID of the lobby to get the RTC Room name for
 * @param {string} local_user_id The Product User ID of the local user in the lobby
 *
 * @returns {bool}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_join_lobby
 * @desc **Epic Online Services Function:** [EOS_Lobby_JoinLobby](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-join-lobby)
 * 
 * This function joins a lobby, creating a local instance under a given lobby ID. The backend will validate various conditions to make sure it is possible to join the lobby. If the lobby is successfully join has an RTC room enabled, the lobby system will automatically join and maintain the connection to the RTC room as long as the local user remains in the lobby. Applications can use the ${function.eos_lobby_get_rtc_room_name} to get the name of the RTC room associated with a lobby, which may be used with many of the `eos_rtc_*` suite of functions. This can be useful to: register for notifications for talking status; to mute or unmute the local user's audio output; to block or unblock room participants; to set local audio device settings; and more.
 *
 * @param {string} local_user_id The Product User ID of the local user joining the lobby
 * @param {bool} crossplay_opt_out This value indicates whether or not the local user allows crossplay interactions. If it is `false`, the local user will be treated as allowing crossplay.
 * @param {bool} presence_enabled If `true`, this lobby will be associated with the local user's presence information. A user can only associate one lobby at a time with their presence information. This affects the ability of the Social Overlay to show game related actions to take in the user's social graph. * using the `presence_enabled` flags within the Sessions interface * using the `presence_enabled` flags within the Lobby interface * using ${function.eos_presence_modification_set_join_info}
 * @param {bool} enable_rtc_room Creates a real-time communication (RTC) room for all members of this lobby. All members of the lobby will automatically join the RTC room when they connect to the lobby and they will automatically leave the RTC room when they leave or are removed from the lobby. While the joining and leaving of the RTC room is automatic, applications will still need to use the EOS RTC interfaces to handle all other functionality for the room.
 * @param {bool} local_audio_device_input_starts_muted Set to `true` to start the audio input device's stream as muted when first connecting to the RTC room. It must be manually unmuted with a call to ${function.eos_rtc_audio_update_sending}. If manual audio output is enabled, this value is ignored.
 * @param {bool} use_manual_audio_input Set to `true` to enable Manual Audio Input. If manual audio input is enabled, audio recording is not started and the audio buffers must be passed manually using ${function.eos_rtc_audio_send_audio}.
 * @param {bool} use_manual_audio_output Set to `true` to enable Manual Audio Output. If manual audio output is enabled, audio rendering is not started and the audio buffers must be received with ${function.eos_rtc_audio_add_notify_audio_before_render} and rendered manually.
 * @param {constant.EOS_RTC_JOINROOMFLAGS} flags Flags for the local user in this room. Set to 0 to not specify any flags. See ${constant.EOS_RTC_JOINROOMFLAGS}.
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_join_lobby"`
 * @member {constant.EOS_Result} status The result code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} lobby_id The ID of the lobby
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_join_lobby_by_id
 * @desc **Epic Online Services Function:** [EOS_Lobby_JoinLobbyById](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-join-lobby-by-id)
 * 
 * This function is a special case of ${function.eos_lobby_join_lobby}. It should only be used if the lobby has had Join-by-ID enabled. Additionally, Join-by-ID should only be enabled to support native invites on an integrated platform.
 *
 * @param {string} local_user_id The Product User ID of the local user joining the lobby
 * @param {bool} crossplay_opt_out This value indicates whether or not the local user allows crossplay interactions. If it is `false`, the local user will be treated as allowing crossplay.
 * @param {bool} presence_enabled If `true`, this lobby will be associated with the user's presence information. A user can only associate one lobby at a time with their presence information. This affects the ability of the Social Overlay to show game related actions to take in the user's social graph. * using the `presence_enabled` flags within the Sessions interface * using the `presence_enabled` flags within the Lobby interface * using ${function.eos_presence_modification_set_join_info}
 * @param {string} lobby_id The ID of the lobby
 * @param {bool} enable_rtc_room Creates a real-time communication (RTC) room for all members of this lobby. All members of the lobby will automatically join the RTC room when they connect to the lobby and they will automatically leave the RTC room when they leave or are removed from the lobby. While the joining and leaving of the RTC room is automatic, applications will still need to use the EOS RTC interfaces to handle all other functionality for the room.
 * @param {bool} local_audio_device_input_starts_muted Set to `true` to start the audio input device's stream as muted when first connecting to the RTC room. It must be manually unmuted with a call to ${function.eos_rtc_audio_update_sending}. If manual audio output is enabled, this value is ignored.
 * @param {bool} use_manual_audio_input Set to `true` to enable Manual Audio Input. If manual audio input is enabled, audio recording is not started and the audio buffers must be passed manually using ${function.eos_rtc_audio_send_audio}.
 * @param {bool} use_manual_audio_output Set to `true` to enable Manual Audio Output. If manual audio output is enabled, audio rendering is not started and the audio buffers must be received with ${function.eos_rtc_audio_add_notify_audio_before_render} and rendered manually.
 * @param {constant.EOS_RTC_JOINROOMFLAGS} flags Flags for the local user in this room. Set to 0 to not specify any flags. See ${constant.EOS_RTC_JOINROOMFLAGS}.
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_join_lobby_by_id"`
 * @member {constant.EOS_Result} status The result code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} lobby_id The ID of the lobby
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_kick_member
 * @desc **Epic Online Services Function:** [EOS_Lobby_KickMember](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-kick-member)
 * 
 * This function kicks an existing member from the lobby.
 *
 * @param {string} lobby_id The ID of the lobby
 * @param {string} local_user_id The Product User ID of the local user requesting the removal; this user must be the lobby owner
 * @param {string} target_user_id The Product User ID of the lobby member to remove
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_kick_member"`
 * @member {constant.EOS_Result} status The result code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} lobby_id The ID of the lobby
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_leave_lobby
 * @desc **Epic Online Services Function:** [EOS_Lobby_LeaveLobby](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-leave-lobby)
 * 
 * This function leaves a lobby given a lobby ID. If the lobby you are leaving had an RTC Room enabled, leaving the lobby will also automatically leave the RTC room.
 *
 * @param {string} lobby_id The ID of the lobby
 * @param {string} local_user_id The Product User ID of the local user leaving the lobby
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_leave_lobby"`
 * @member {constant.EOS_Result} status The result code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} lobby_id The ID of the lobby
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_parse_connect_string
 * @desc **Epic Online Services Function:** [EOS_Lobby_ParseConnectString](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-parse-connect-string)
 * 
 * This function parses the ConnectString for an EOS lobby invitation to extract just the lobby ID. Used for joining a lobby from a connection string (as generated by ${function.eos_lobby_get_connect_string}) found in a platform invitation or presence.
 * 
 * @returns {string}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_promote_member
 * @desc **Epic Online Services Function:** [EOS_Lobby_PromoteMember](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-promote-member)
 * 
 * This function promotes an existing member of the lobby to owner, allowing them to make lobby data modifications.
 * 
 * The function returns an async identifier.
 * 
 * @param {string} lobby_id The ID of the lobby
 * @param {string} local_user_id The Product User ID of the local user making the request
 * @param {string} target_user_id The Product User ID of the member to promote to owner of the lobby
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_promote_member"`
 * @member {constant.EOS_Result} status The result code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} lobby_id The ID of the lobby where the user was promoted
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_query_invites
 * @desc **Epic Online Services Function:** [EOS_Lobby_QueryInvites](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-query-invites)
 * 
 * This function retrieves all existing invites for a single user.
 *
 * @param {string} local_user_id The Product User ID of the local user whose invitations you want to retrieve
 *
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_query_invites"`
 * @member {constant.EOS_Result} status The result code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} local_user_id The Product User ID of the local user that made the request
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_reject_invite
 * @desc **Epic Online Services Function:** [EOS_Lobby_RejectInvite](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-reject-invite)
 * 
 * This function rejects an invite from another user.
 *
 * @param {string} invite_id The ID of the lobby associated with the invitation
 * @param {string} local_user_id The Product User ID of the local user who is rejecting the invitation
 *
 * @returns {real}
 * 
 * @event social 
 * @member {string} type the string `"eos_lobby_reject_invite"`
 * @member {constant.EOS_Result} status The result code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} invite_id The ID of the invitation being rejected
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_remove_notify_join_lobby_accepted
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyJoinLobbyAccepted](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-join-lobby-accepted)
 * 
 * This function unregisters from receiving notifications when a user accepts a lobby invitation via the overlay.
 *
 * @param {real} notification_id A handle representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_lobby_remove_notify_leave_lobby_requested
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyLeaveLobbyRequested](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-leave-lobby-requested)
 * 
 * This function unregisters from receiving notifications when a user performs a leave lobby action via the overlay.
 *
 * @param {real} notification_id A handle representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_lobby_remove_notify_lobby_invite_accepted
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyLobbyInviteAccepted](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-lobby-invite-accepted)
 * 
 * This function unregisters from receiving notifications when a user accepts a lobby invitation via the overlay.
 *
 * @param {real} notification_id A handle representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_lobby_remove_notify_lobby_invite_received
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyLobbyInviteReceived](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-lobby-invite-received)
 * 
 * This function unregisters from receiving notifications when a user receives a lobby invitation.
 *
 * @param {real} notification_id A handle representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_lobby_remove_notify_lobby_invite_rejected
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyLobbyInviteRejected](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-lobby-invite-rejected)
 * 
 * This function unregisters from receiving notifications when a user rejects a lobby invitation via the overlay.
 *
 * @param {real} notification_id A handle representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_lobby_remove_notify_lobby_member_status_received
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyLobbyMemberStatusReceived](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-lobby-member-status-received)
 * 
 * This function unregisters from receiving notifications when lobby members status change.
 *
 * @param {real} notification_id A handle representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_lobby_remove_notify_lobby_member_update_received
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyLobbyMemberUpdateReceived](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-lobby-member-update-received)
 * 
 * This function unregisters from receiving notifications when lobby members change their data.
 *
 * @param {real} notification_id A handle representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_lobby_remove_notify_lobby_update_received
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyLobbyUpdateReceived](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-lobby-update-received)
 * 
 * This function unregisters from receiving notifications when a lobby changes its data.
 *
 * @param {real} notification_id A handle representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_lobby_remove_notify_rtc_room_connection_changed
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyRTCRoomConnectionChanged](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-rtc-room-connection-changed)
 * 
 * This function unregisters from receiving notifications when an RTC Room's connection status changes. This should be called when the local user is leaving a lobby.
 *
 * @param {real} notification_id A handle representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_lobby_remove_notify_send_lobby_native_invite_requested
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifySendLobbyNativeInviteRequested](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-send-lobby-native-invite-requested)
 * 
 * This function unregisters from receiving notifications when a user requests a send invite via the overlay.
 *
 * @param {real} notification_id A handle representing the registered callback
 * 
 * @func_end
 */

/**
 * @func eos_lobby_send_invite
 * @desc **Epic Online Services Function:** [EOS_Lobby_SendInvite](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-send-invite)
 * 
 * This function sends an invite to another user. The user must be a member of the lobby or else the call will fail.
 * 
 * The function returns an async identifier.
 * 
 * @param {string} lobby_id The ID of the lobby associated with the invitation
 * @param {string} local_user_id The Product User ID of the local user sending the invitation
 * @param {string} target_user_id The Product User ID of the user receiving the invitation
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_send_invite"`
 * @member {constant.EOS_Result} status The result code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} lobby_id The ID of the lobby
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_update_lobby
 * @desc **Epic Online Services Function:** [EOS_Lobby_UpdateLobby](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-update-lobby)
 * 
 * This function updates a lobby given a lobby modification handle created by ${function.eos_lobby_update_lobby_modification}.
 * 
 * The function returns an async identifier.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_update_lobby"`
 * @member {constant.EOS_Result} status The result code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original call to the function
 * @member {string} lobby_id The ID of the lobby
 * @event_end
	
 * @func_end
 */

/**
 * @func eos_lobby_update_lobby_modification
 * @desc **Epic Online Services Function:** [EOS_Lobby_UpdateLobbyModification](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-update-lobby-modification)
 * 
 * This function creates a lobby modification handle. The lobby modification handle is used to modify an existing lobby and can be applied with ${function.eos_lobby_update_lobby}. The handle must be released by calling ${function.eos_lobby_modification_release} once it is no longer needed.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` if EOS successfully created the lobby modification handle, or an error result if the input data was invalid
 * * `EOS_Result.InvalidParameters` if any of the options are incorrect
 * 
 * @param {string} lobby_id The ID of the lobby
 * @param {string} local_user_id The ID of the local user making modifications. Must be the owner to modify lobby data, but any lobby member can modify their own attributes.
 * 
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @struct EOS_Lobby_Attribute
 * @desc **Epic Online Services Struct:** [EOS_Lobby_Attribute](https://dev.epicgames.com/docs/en-US/api-ref/structs/eos-lobby-attribute)
 * 
 * This struct stores an attribute and its visibility setting stored with a lobby. Used to store both lobby and lobby member data.
 * 
 * @member {string} key The name of the lobby attribute
 * @member {any} value The value of the lobby attribute
 * @member {constant.EOS_LobbyAttributeVisibility} visibility Whether this attribute is public or private to the lobby and its members
 * 
 * @struct_end
 */

/**
 * @constant EOS_LobbyAttributeVisibility
 * @desc **Epic Online Services Enumeration:** [EOS_ELobbyAttributeVisibility](https://dev.epicgames.com/docs/api-ref/enums/eos-e-lobby-attribute-visibility)
 * 
 * This enum holds the possible advertisement properties for a single attribute associated with a lobby.
 * 
 * @member PUBLIC Data is visible to lobby members, searchable and visible in search results.
 * @member PRIVATE Data is only visible to the user setting the data. Data is not visible to lobby members, not searchable, and not visible in search results.
 * 
 * @constant_end
 */

/**
 * @func eos_lobby_details_copy_attribute_by_index
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_CopyAttributeByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-copy-attribute-by-index)
 * 
 * This function is used to immediately retrieve a copy of a lobby attribute from a given source such as a existing lobby or a search result. If the call returns an `EOS_Result.Success` result, the out parameter, OutAttribute, must be passed to ${function.eos_lobby_attribute_release} to release the memory associated with it.
 * 
 * @param {real} index The index of the attribute to retrieve
 * 
 * @returns {struct.EOS_Lobby_Attribute}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_details_copy_attribute_by_key
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_CopyAttributeByKey](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-copy-attribute-by-key)
 * 
 * This function is used to immediately retrieve a copy of a lobby attribute from a given source such as a existing lobby or a search result. If the call returns an `EOS_Result.Success` result, the out parameter, OutAttribute, must be passed to ${function.eos_lobby_attribute_release} to release the memory associated with it.
 * 
 * @param {string} attr_key The name of the attribute
 * 
 * @returns {struct.EOS_Lobby_Attribute}
 * 
 * @func_end
 */

/**
 * @constant EOS_LobbyPermissionLevel
 * @desc **Epic Online Services Struct:** [EOS_ELobbyPermissionLevel](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-lobby-permission-level)
 * 
 * @member PUBLICADVERTISED Anyone can find this lobby as long as it isn't full
 * @member JOINVIAPRESENCE Players who have access to presence can see this lobby
 * @member INVITEONLY Only players with invites registered can see this lobby
 * 
 * @constant_end
 */

/**
 * @struct EOS_LobbyDetails_Info
 * @desc **Epic Online Services Struct:** [EOS_LobbyDetails_Info](https://dev.epicgames.com/docs/api-ref/structs/eos-lobby-details-info)
 * 
 * This struct holds details on a lobby.
 * 
 * @member {real} available_slots The current available space
 * @member {bool} allow_host_migration Whether host migration is allowed
 * @member {bool} allow_invites If `true`, users can invite others to this lobby
 * @member {bool} allow_join_by_id Whether ${function.eos_lobby_join_lobby_by_id} is allowed
 * @member {bool} presence_enabled If `true`, this lobby will be associated with the local user's presence information.
 * @member {bool} rejoin_after_kick_requires_invite Whether rejoining after being kicked requires an invite
 * @member {bool} rtc_room_enabled Was a Real-Time Communication (RTC) room enabled at lobby creation?
 * @member {string} bucket_id The main indexed parameter for this lobby, can be any string (i.e. `"Region:GameMode"`)
 * @member {string} lobby_id The lobby ID
 * @member {string} lobby_owner_user_id The Product User ID of the current owner of the lobby
 * @member {real} max_members Max allowed members in the lobby
 * @member {constant.EOS_LobbyPermissionLevel} permission_level The permission level of the lobby
 * 
 * @struct_end
 */

/**
 * @func eos_lobby_details_copy_info
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_CopyInfo](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-copy-info)
 * 
 * This function is used to immediately retrieve a copy of lobby information from a given source such as a existing lobby or a search result. If the call returns an `EOS_Result.Success` result, the out parameter, OutLobbyDetailsInfo, must be passed to ${function.eos_lobby_details_info_release} to release the memory associated with it.
 * 
 * @returns {struct.EOS_LobbyDetails_Info}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_details_copy_member_attribute_by_index
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_CopyMemberAttributeByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-copy-member-attribute-by-index)
 * 
 * This function is used to immediately retrieve a copy of a lobby member attribute from an existing lobby. If the call returns an `EOS_Result.Success` result, the out parameter, OutAttribute, must be passed to EOS_Lobby_Attribute_Release to release the memory associated with it.
 * 
 * [[Note: this information is only available if you are actively in the lobby. It is not available for search results.]]
 * 
 * @param {real} index The index of the attribute to copy
 * @param {string} target_user_id The Product User ID of the lobby member
 *
 * @returns {struct.EOS_Lobby_Attribute}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_details_copy_member_attribute_by_key
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_CopyMemberAttributeByKey](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-copy-member-attribute-by-key)
 * 
 * This function is used to immediately retrieve a copy of a lobby member attribute from an existing lobby. If the call returns an `EOS_Result.Success` result, the out parameter, OutAttribute, must be passed to EOS_Lobby_Attribute_Release to release the memory associated with it.
 * 
 * [[Note: this information is only available if you are actively in the lobby. It is not available for search results.]]
 *
 * @param {string} attr_key The name of the attribute to copy
 * @param {string} target_user_id The Product User ID of the lobby member
 *
 * @returns {struct.EOS_Lobby_Attribute}
 * 
 * @func_end
 */

/**
 * @struct EOS_LobbyDetails_MemberInfo
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_MemberInfo](https://dev.epicgames.com/docs/api-ref/structs/eos-lobby-details-member-info)
 * 
 * This struct holds information on a lobby member.
 * 
 * @member {bool} allows_crossplay Whether this member allows crossplay
 * @member {constant.EOS_OnlinePlatformType} platform The platform of the lobby member
 * @member {string} user_id The Product User ID of the lobby member
 * 
 * @struct_end
 */

/**
 * @func eos_lobby_details_copy_member_info
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_CopyMemberInfo](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-copy-member-info)
 * 
 * This function is used to immediately retrieve a copy of lobby member information from an existing lobby. If the call returns an `EOS_Result.Success` result, the out parameter, OutLobbyDetailsMemberInfo, must be passed to EOS_LobbyDetails_MemberInfo_Release to release the memory associated with it.
 * 
 * [[Note: this information is only available if you are actively in the lobby. It is not available for search results.]]
 * 
 * @param {string} target_user_id The Product User ID of the lobby member to copy
 * 
 * @returns {struct.EOS_LobbyDetails_MemberInfo}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_details_get_attribute_count
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_GetAttributeCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-get-attribute-count)
 *
 * This function gets the number of attributes associated with this lobby. It returns the number of attributes on the lobby or 0 if there is an error.
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_details_get_lobby_owner
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_GetLobbyOwner](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-get-lobby-owner)
 *
 * This function gets the product user ID of the current owner for a given lobby, or an empty string `""` if the input parameters are invalid.
 *
 * @returns {string}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_details_get_member_attribute_count
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_GetMemberAttributeCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-get-member-attribute-count)
 * 
 * This function is used to immediately retrieve the attribute count for members in a lobby. It returns the number of attributes associated with a given lobby member or 0 if that member is invalid.
 * 
 * [[Note: this information is only available if you are actively in the lobby. It is not available for search results.]]
 *
 * @param {string} target_user_id The Product User ID of the lobby member
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_details_get_member_by_index
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_GetMemberByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-get-member-by-index)
 * 
 * This function is used to immediately retrieve individual members registered with a lobby.
 * 
 * [[Note: this information is only available if you are actively in the lobby. It is not available for search results.]]
 * 
 * @param {real} index The index of the member to retrieve
 *
 * @returns {string}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_details_get_member_count
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_GetMemberCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-get-member-count)
 *
 * This function gets the number of members associated with this lobby.
 *
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_details_release
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_Info_Release](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-info-release)
 * 
 * This function releases previously retrieved lobby details.
 * 
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_modification_add_attribute
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_AddAttribute](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-add-attribute)
 * 
 * This function associates an attribute with this lobby. An attribute is something that may be public or private with the lobby. If public, it can be queried for in a search, otherwise the data remains known only to lobby members.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` if setting this parameter was successful
 * * `EOS_Result.InvalidParameters` if the attribute is missing information or otherwise invalid
 * * `EOS_Result.IncompatibleVersion` if the API version passed in is incorrect
 *
 * @param {constant.EOS_LobbyAttributeVisibility} visibility Whether this attribute is public or private to the lobby and its members
 * @param {struct} attribute A struct that defines a single key/value pair describing the attribute to add to the lobby. The struct must contain the following variables:
 * 
 * * `key` (${type.string})
 * * `value_type` (${constant.EOS_AttributeType})
 * * `value` (a value of the given `value_type`)
 *
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_modification_add_member_attribute
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_AddMemberAttribute](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-add-member-attribute)
 * 
 * This function associates an attribute with a member of the lobby. Lobby member data is always private to the lobby.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` if setting this parameter was successful
 * * `EOS_Result.InvalidParameters` if the attribute is missing information or otherwise invalid
 * * `EOS_Result.IncompatibleVersion` if the API version passed in is incorrect
 * 
 * @param {constant.EOS_LobbyAttributeVisibility} visibility Whether this attribute is public or private to the rest of the lobby members
 * @param {struct} attribute A struct that defines a single key/value pair describing the attribute to add to the lobby member. The struct must contain the following variables:
 * 
 * * `key` (${type.string})
 * * `value_type` (${constant.EOS_AttributeType})
 * * `value` (a value of the given `value_type`)
 * 
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_modification_release
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_Release](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-release)
 *
 * This function releases a previously obtained lobby modification.
 * 
 * @func_end
 */

/**
 * @func eos_lobby_modification_remove_attribute
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_RemoveAttribute](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-modification-remove-attribute)
 * 
 * This function removes an attribute associated with the lobby.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` if removing this parameter was successful
 * * `EOS_Result.InvalidParameters` if the key is empty
 * * `EOS_Result.IncompatibleVersion` if the API version passed in is incorrect
 * 
 * @param {string} key The name of the key
 * 
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_modification_remove_member_attribute
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_RemoveMemberAttribute](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-remove-member-attribute)
 * 
 * This function removes an attribute associated with of member of the lobby.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` if removing this parameter was successful
 * * `EOS_Result.InvalidParameters` if the key is empty
 * * `EOS_Result.IncompatibleVersion` if the API version passed in is incorrect
 * 
 * @param {string} key The name of the key
 * 
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_modification_set_allowed_platform_ids
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_SetAllowedPlatformIds](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-set-allowed-platform-ids)
 * 
 * This function sets the Allowed Platform IDs for the lobby.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` if setting this parameter was successful
 * * `EOS_Result.IncompatibleVersion` if the API version passed in is incorrect
 * * `EOS_Result.InvalidParameters` if the parameter is invalid
 *
 * @param {array} allowed_platform_ids An array of platform IDs indicating the player platforms allowed to register with the session. Platform IDs are found in the EOS header file, e.g. EOS_OPT_Epic. For some platforms, the value will be in the EOS Platform specific header file. If null, the lobby will be unrestricted.
 *
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_modification_set_bucket_id
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_SetBucketId](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-set-bucket-id)
 * 
 * This function sets the bucket ID associated with this lobby. Values such as region, game mode, etc., can be combined here depending on game need. Setting this is strongly recommended to improve search performance.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` if setting this parameter was successful
 * * `EOS_Result.InvalidParameters` if the bucket ID is invalid
 * * `EOS_Result.IncompatibleVersion` if the API version passed in is incorrect
 *
 * @param {string} bucket_id The new bucket ID associated with the lobby
 *
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_modification_set_invites_allowed
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_SetInvitesAllowed](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-set-invites-allowed)
 * 
 * This function allows enabling or disabling invites for this lobby. The lobby will also need to have `presence_enabled` set to `true`.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` if setting this parameter was successful
 * * `EOS_Result.IncompatibleVersion` if the API version passed in is incorrect
 *
 * @param {bool} invites_allowed If `true` then invites can currently be sent for the associated lobby
 *
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_modification_set_max_members
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_SetMaxMembers](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-set-max-members)
 * 
 * This function sets the maximum number of members allowed in this lobby. When updating the lobby, it is not possible to reduce this number below the current number of existing members.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` if setting this parameter was successful
 * * `EOS_Result.IncompatibleVersion` if the API version passed in is incorrect
 * 
 * @param {real} max_members The new maximum number of lobby members
 * 
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_modification_set_permission_level
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_SetPermissionLevel](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-set-permission-level)
 * 
 * This function sets the permissions associated with this lobby. The permissions range from "public" to "invite only" and are described by ${constant.EOS_LobbyPermissionLevel}.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` if setting this parameter was successful
 * * `EOS_Result.IncompatibleVersion` if the API version passed in is incorrect
 *
 * @param {constant.EOS_LobbyPermissionLevel} permission_level The permission level of the lobby
 *
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_search_copy_search_result_by_index
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_CopySearchResultByIndex](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-copy-search-result-by-index)
 * 
 * This function is used to immediately retrieve a handle to the lobby information from a given search result. If the call returns an `EOS_Result.Success` result, the out parameter, OutLobbyDetailsHandle, must be passed to ${function.eos_lobby_details_release} to release the memory associated with it.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` if the information is available
 * * `EOS_Result.InvalidParameters` if you pass an invalid index
 * * `EOS_Result.IncompatibleVersion` if the API version passed in is incorrect
 * 
 * @param {real} lobby_index The index of the lobby to retrieve within the completed search query
 *
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_search_find
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_Find](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-find)
 * 
 * This function finds lobbies matching the search criteria setup via this lobby search handle. When the operation completes, this handle will have the search results that can be parsed.
 * 
 * The function returns an async identifier.
 * 
 * @param {string} local_user_id The Product User ID of the user making the search request
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type the string `"eos_lobby_search_find"`
 * @member {constant.EOS_Result} status The result code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors.
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The identifier returned by the original function call
 * @event_end
 * 
 * @func_end
 */

/**
 * @func eos_lobby_search_get_search_result_count
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_GetSearchResultCount](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-get-search-result-count)
 * 
 * This function gets the number of search results found by the search parameters in this search. It returns the number of search results found by the query or 0 if search is not complete.
 * 
 * @returns {real}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_search_release
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_Release](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-search-release)
 *
 * This function releases the memory associated with a lobby search. This must be called on data retrieved from ${function.eos_lobby_create_lobby_search}.
 * 
 * @func_end
 */

/**
 * @func eos_lobby_search_remove_parameter
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_RemoveParameter](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-remove-parameter)
 * 
 * This function removes a parameter from the array of search criteria.
 * 
 * @param {string} key The search parameter key to remove from the search
 * @param {constant.EOS_ComparisonOp} comparison_op The search comparison operation associated with the key to remove
 * 
 * @func_end
 */

/**
 * @func eos_lobby_search_set_lobby_id
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_SetLobbyId](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-set-lobby-id)
 * 
 * This function sets a lobby ID to find and will return at most one search result. Setting TargetUserId or SearchParameters will result in ${function.eos_lobby_search_find} failing.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` if setting this lobby ID was successful
 * * `EOS_Result.InvalidParameters` if the lobby ID is invalid
 * * `EOS_Result.IncompatibleVersion` if the API version passed in is incorrect
 *
 * @param {string} lobby_id The ID of the lobby to find
 *
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @constant EOS_LOBBY_MAX_SEARCH_RESULTS
 * @desc This macro holds the maximum number of lobby search results.
 * 
 * @constant_end
 */

/**
 * @func eos_lobby_search_set_max_results
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_SetMaxResults](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-set-max-results)
 * 
 * This function sets the maximum number of search results to return in the query, can't be more than ${constant.EOS_LOBBY_MAX_SEARCH_RESULTS}.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` if setting the max results was successful
 * * `EOS_Result.InvalidParameters` if the number of results requested is invalid
 * * `EOS_Result.IncompatibleVersion` if the API version passed in is incorrect
 * 
 * @param {real} max_results The maximum number of search results to return from the query
 *
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_search_set_parameter
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_SetParameter](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-set-parameter)
 * 
 * This function adds a parameter to an array of search criteria combined via an implicit AND operator. Setting LobbyId or TargetUserId will result in ${function.eos_lobby_search_find} failing.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` if setting this search parameter was successful
 * * `EOS_Result.InvalidParameters` if the search criteria is invalid
 * * `EOS_Result.IncompatibleVersion` if the API version passed in is incorrect
 *
 * @param {constant.EOS_ComparisonOp} comparison_op The type of comparison to make against the search parameter
 * @param {struct.EOS_Lobby_Attribute} parameter A search parameter describing a key and a value to compare
 *
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

/**
 * @func eos_lobby_search_set_target_user_id
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_SetTargetUserId](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-set-target-user-id)
 * 
 * This function sets a target user ID to find. Setting LobbyId or SearchParameters will result in ${function.eos_lobby_search_find} failing.
 * 
 * The function returns one of the following:
 * 
 * * `EOS_Result.Success` if setting this target user ID was successful
 * * `EOS_Result.InvalidParameters` if the target user ID is invalid
 * * `EOS_Result.IncompatibleVersion` if the API version passed in is incorrect
 *
 * @param {string} target_user_id Search lobbies for the given user by Product User ID, returning any lobbies where this user is currently registered
 *
 * @returns {constant.EOS_Result}
 * 
 * @func_end
 */

// Constants & Enums

/**
 * @constant EOS_IntegratedPlatformType
 * @desc 
 * 
 * @member EOS_IntegratedPlatformType
 * 
 * @constant_end
 */

/**
 * @constant EOS_OnlinePlatformType
 * @desc 
 * 
 * @member EOS_OnlinePlatformType
 * 
 * @constant_end
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