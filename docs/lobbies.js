// Functions


/**
 * @function eos_lobby_create_lobby
 * @desc **Epic Online Services Function:** [EOS_Lobby_CreateLobby](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-create-lobby)
 *
 * Creates a new lobby owned by the calling local user, with settings taken from `options`. The lobby is created empty (only the local user is a member) - invite or have other players join it via ${function.eos_lobby_join_lobby}/${function.eos_lobby_join_lobby_by_id}.
 *
 * [[Note: `bucket_id` is required. It's an arbitrary string used to group/filter lobbies, e.g. `"<region>:<mode>"`.]]
 *
 * [[Note: When `enable_rtc_room` is `true`, the SDK also creates a managed voice room for the lobby - see ${function.eos_lobby_get_rtc_room_name} and ${module.rtc}.]]
 *
 * @param {Struct.EpicLobbyCreateLobbyOptions} options Settings for the new lobby.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Fires once when the create attempt finishes.
 * @member {Struct.EpicLobbyCreateLobbyCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * var _options = {
 *     local_user_id: global.local_user_id,
 *     max_lobby_members: 4,
 *     permission_level: EpicLobbyPermissionLevel.PublicAdvertised,
 *     presence_enabled: true,
 *     allow_invites: true,
 *     bucket_id: "eu:deathmatch",
 *     disable_host_migration: false,
 *     enable_rtc_room: true,
 *     enable_join_by_id: true,
 *     rejoin_after_kick_requires_invite: false
 * };
 *
 * eos_lobby_create_lobby(_options, function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         show_debug_message($"Lobby created: {_result.lobby_id}");
 *     }
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_lobby_destroy_lobby
 * @desc **Epic Online Services Function:** [EOS_Lobby_DestroyLobby](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-destroy-lobby)
 *
 * Destroys a lobby given its ID. Only the lobby owner may destroy it.
 *
 * @param {String} lobby_id The lobby to destroy.
 * @param {String} local_user_id The Product User ID of the lobby owner requesting the destroy.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Fires once when the destroy attempt finishes.
 * @member {Struct.EpicLobbyDestroyLobbyCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_join_lobby
 * @desc **Epic Online Services Function:** [EOS_Lobby_JoinLobby](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-join-lobby)
 *
 * Joins a lobby using a lobby details handle previously obtained via ${function.eos_lobby_copy_lobby_details_handle}, ${function.eos_lobby_copy_lobby_details_handle_by_invite_id}, or ${function.eos_lobby_copy_lobby_details_handle_by_ui_event_id}.
 *
 * @param {Struct.EpicLobbyJoinLobbyOptions} options
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Fires once when the join attempt finishes.
 * @member {Struct.EpicLobbyJoinLobbyCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_leave_lobby
 * @desc **Epic Online Services Function:** [EOS_Lobby_LeaveLobby](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-leave-lobby)
 *
 * Leaves a lobby the local user is currently a member of. If the local user is the owner, ownership migrates to another member (unless `disable_host_migration` was set on creation).
 *
 * @param {String} lobby_id
 * @param {String} local_user_id
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Fires once when the leave attempt finishes.
 * @member {Struct.EpicLobbyLeaveLobbyCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_update_lobby_modification
 * @desc **Epic Online Services Function:** [EOS_Lobby_UpdateLobbyModification](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-update-lobby-modification)
 *
 * Creates a lobby modification handle, used to stage changes (permission level, max members, attributes, member attributes, ...) before applying them in one call to ${function.eos_lobby_update_lobby}. Release the handle with ${function.eos_lobby_lobby_modification_release} once you're done with it, whether or not you applied it.
 *
 * @param {String} lobby_id
 * @param {String} local_user_id
 *
 * @returns {Real} A modification handle ID, or `0` on failure.
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_modification_release
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_Release](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-modification-release)
 *
 * Releases a lobby modification handle created by ${function.eos_lobby_update_lobby_modification}.
 *
 * @param {Real} modification_id
 *
 * @function_end
 */

/**
 * @function eos_lobby_update_lobby
 * @desc **Epic Online Services Function:** [EOS_Lobby_UpdateLobby](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-update-lobby)
 *
 * Applies a staged modification (built with the `eos_lobby_lobby_modification_*` functions below) to the live lobby.
 *
 * @param {String} lobby_id
 * @param {Real} modification_id A handle from ${function.eos_lobby_update_lobby_modification}.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Fires once when the update attempt finishes.
 * @member {Struct.EpicLobbyUpdateLobbyCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_modification_set_permission_level
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_SetPermissionLevel](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-modification-set-permission-level)
 *
 * Stages a new ${constant.EpicLobbyPermissionLevel} on a modification handle.
 *
 * @param {Real} modification_id
 * @param {Constant.EpicLobbyPermissionLevel} permission_level
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_modification_set_max_members
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_SetMaxMembers](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-modification-set-max-members)
 *
 * Stages a new member limit on a modification handle. Cannot be set below the current member count.
 *
 * @param {Real} modification_id
 * @param {Real} max_members
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_modification_set_bucket_id
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_SetBucketId](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-modification-set-bucket-id)
 *
 * Stages a new bucket ID on a modification handle.
 *
 * @param {Real} modification_id
 * @param {String} bucket_id
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_modification_set_invites_allowed
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_SetInvitesAllowed](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-modification-set-invites-allowed)
 *
 * Stages whether invites can currently be sent to this lobby.
 *
 * @param {Real} modification_id
 * @param {Bool} invites_allowed
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_modification_add_attribute_string
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_AddAttribute](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-modification-add-attribute)
 *
 * Stages a string lobby attribute (key/value pair visible to the whole lobby or just members, depending on `visibility`). Lobby attributes can be searched on via ${function.eos_lobby_lobby_search_set_parameter_string}.
 *
 * @param {Real} modification_id
 * @param {String} key
 * @param {String} value
 * @param {Constant.EpicLobbyAttributeVisibility} visibility
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_modification_add_attribute_bool
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_AddAttribute](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-modification-add-attribute)
 *
 * Bool-valued variant of ${function.eos_lobby_lobby_modification_add_attribute_string}.
 *
 * @param {Real} modification_id
 * @param {String} key
 * @param {Bool} value
 * @param {Constant.EpicLobbyAttributeVisibility} visibility
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_modification_add_attribute_double
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_AddAttribute](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-modification-add-attribute)
 *
 * Numeric-valued variant of ${function.eos_lobby_lobby_modification_add_attribute_string}.
 *
 * @param {Real} modification_id
 * @param {String} key
 * @param {Real} value
 * @param {Constant.EpicLobbyAttributeVisibility} visibility
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_modification_remove_attribute
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_RemoveAttribute](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-modification-remove-attribute)
 *
 * Stages removal of a lobby attribute added by one of the `add_attribute_*` functions above.
 *
 * @param {Real} modification_id
 * @param {String} key
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_modification_add_member_attribute_string
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_AddMemberAttribute](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-modification-add-member-attribute)
 *
 * Stages a string attribute on the *local user's own membership record* within the lobby (e.g. team, ready state). Only members may set their own member attributes.
 *
 * @param {Real} modification_id
 * @param {String} key
 * @param {String} value
 * @param {Constant.EpicLobbyAttributeVisibility} visibility
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_modification_add_member_attribute_bool
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_AddMemberAttribute](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-modification-add-member-attribute)
 *
 * Bool-valued variant of ${function.eos_lobby_lobby_modification_add_member_attribute_string}.
 *
 * @param {Real} modification_id
 * @param {String} key
 * @param {Bool} value
 * @param {Constant.EpicLobbyAttributeVisibility} visibility
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_modification_add_member_attribute_double
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_AddMemberAttribute](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-modification-add-member-attribute)
 *
 * Numeric-valued variant of ${function.eos_lobby_lobby_modification_add_member_attribute_string}.
 *
 * @param {Real} modification_id
 * @param {String} key
 * @param {Real} value
 * @param {Constant.EpicLobbyAttributeVisibility} visibility
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_modification_remove_member_attribute
 * @desc **Epic Online Services Function:** [EOS_LobbyModification_RemoveMemberAttribute](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-modification-remove-member-attribute)
 *
 * Stages removal of a member attribute added by one of the `add_member_attribute_*` functions above.
 *
 * @param {Real} modification_id
 * @param {String} key
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_lobby_promote_member
 * @desc **Epic Online Services Function:** [EOS_Lobby_PromoteMember](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-promote-member)
 *
 * Promotes another lobby member to be the new lobby owner. Only the current owner may call this.
 *
 * @param {Struct.EpicLobbyPromoteMemberOptions} options
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Fires once when the promote attempt finishes.
 * @member {Struct.EpicLobbyPromoteMemberCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_kick_member
 * @desc **Epic Online Services Function:** [EOS_Lobby_KickMember](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-kick-member)
 *
 * Removes another member from the lobby. Only the current owner may call this.
 *
 * @param {Struct.EpicLobbyKickMemberOptions} options
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Fires once when the kick attempt finishes.
 * @member {Struct.EpicLobbyKickMemberCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_create_lobby_search
 * @desc **Epic Online Services Function:** [EOS_Lobby_CreateLobbySearch](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-create-lobby-search)
 *
 * Creates a lobby search handle. Configure it with the `eos_lobby_lobby_search_*` functions below, then run it with ${function.eos_lobby_lobby_search_find}. Release it with ${function.eos_lobby_lobby_search_release} once you're done.
 *
 * @param {Real} max_results Maximum number of results the search should return.
 *
 * @returns {Real} A search handle ID, or `0` on failure.
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_search_release
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_Release](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-search-release)
 *
 * Releases a lobby search handle created by ${function.eos_lobby_create_lobby_search}.
 *
 * @param {Real} search_id
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_search_set_lobby_id
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_SetLobbyId](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-search-set-lobby-id)
 *
 * Configures the search to look up one specific lobby by ID, instead of searching by attribute parameters.
 *
 * @param {Real} search_id
 * @param {String} lobby_id
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_search_set_target_user_id
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_SetTargetUserId](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-search-set-target-user-id)
 *
 * Configures the search to look up the lobby a specific user is presence-sharing/currently in, instead of searching by attribute parameters.
 *
 * @param {Real} search_id
 * @param {String} target_user_id
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_search_set_parameter_string
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_SetParameter](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-search-set-parameter)
 *
 * Adds a string attribute search filter (`key` `comparison_op` `value`) to the search. Only matches lobby attributes added with visibility `EpicLobbyAttributeVisibility.Public`.
 *
 * @param {Real} search_id
 * @param {String} key
 * @param {String} value
 * @param {Constant.EpicComparisonOp} comparison_op
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_search_set_parameter_bool
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_SetParameter](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-search-set-parameter)
 *
 * Bool-valued variant of ${function.eos_lobby_lobby_search_set_parameter_string}.
 *
 * @param {Real} search_id
 * @param {String} key
 * @param {Bool} value
 * @param {Constant.EpicComparisonOp} comparison_op
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_search_set_parameter_double
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_SetParameter](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-search-set-parameter)
 *
 * Numeric-valued variant of ${function.eos_lobby_lobby_search_set_parameter_string}.
 *
 * @param {Real} search_id
 * @param {String} key
 * @param {Real} value
 * @param {Constant.EpicComparisonOp} comparison_op
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_search_remove_parameter
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_RemoveParameter](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-search-remove-parameter)
 *
 * Removes a previously added search parameter matching `options.key`/`options.comparison_op`.
 *
 * @param {Real} search_id
 * @param {Struct.EpicLobbySearchRemoveParameterOptions} options
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_search_set_max_results
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_SetMaxResults](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-search-set-max-results)
 *
 * Overrides the max-results limit given to ${function.eos_lobby_create_lobby_search}.
 *
 * @param {Real} search_id
 * @param {Real} max_results
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_search_find
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_Find](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-search-find)
 *
 * Executes the configured search. Read results afterward with ${function.eos_lobby_lobby_search_get_search_result_count} and ${function.eos_lobby_lobby_search_copy_search_result_by_index}.
 *
 * @param {Real} search_id
 * @param {String} local_user_id The Product User ID performing the search.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Fires once when the search finishes.
 * @member {Struct.EpicLobbySearchFindCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_search_get_search_result_count
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_GetSearchResultCount](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-search-get-search-result-count)
 *
 * Returns the number of lobbies found by the last ${function.eos_lobby_lobby_search_find} call.
 *
 * @param {Real} search_id
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_lobby_lobby_search_copy_search_result_by_index
 * @desc **Epic Online Services Function:** [EOS_LobbySearch_CopySearchResultByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-search-copy-search-result-by-index)
 *
 * Gets a lobby details handle for a search result. Release it with ${function.eos_lobby_details_release} once you're done reading it (e.g. after passing it to ${function.eos_lobby_join_lobby}).
 *
 * @param {Real} search_id
 * @param {Real} index Zero-based, must be less than ${function.eos_lobby_lobby_search_get_search_result_count}'s return value.
 *
 * @returns {Real} A lobby details handle ID.
 *
 * @function_end
 */

/**
 * @function eos_lobby_details_release
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_Release](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-details-release)
 *
 * Releases a lobby details handle obtained from ${function.eos_lobby_lobby_search_copy_search_result_by_index}, ${function.eos_lobby_copy_lobby_details_handle}, ${function.eos_lobby_copy_lobby_details_handle_by_invite_id}, or ${function.eos_lobby_copy_lobby_details_handle_by_ui_event_id}.
 *
 * @param {Real} lobby_details_id
 *
 * @function_end
 */

/**
 * @function eos_lobby_copy_lobby_details_handle
 * @desc **Epic Online Services Function:** [EOS_Lobby_CopyLobbyDetailsHandle](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-copy-lobby-details-handle)
 *
 * Gets a lobby details handle for a lobby the local user is already a member of.
 *
 * @param {String} lobby_id
 * @param {String} local_user_id
 *
 * @returns {Real} A lobby details handle ID, or `0` on failure.
 *
 * @function_end
 */

/**
 * @function eos_lobby_copy_lobby_details_handle_by_invite_id
 * @desc **Epic Online Services Function:** [EOS_Lobby_CopyLobbyDetailsHandleByInviteId](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-copy-lobby-details-handle-by-invite-id)
 *
 * Gets a lobby details handle from an invite ID (e.g. one received via the ${event.callback} of ${function.eos_lobby_add_notify_lobby_invite_received}).
 *
 * @param {String} invite_id
 *
 * @returns {Real} A lobby details handle ID, or `0` on failure.
 *
 * @function_end
 */

/**
 * @function eos_lobby_copy_lobby_details_handle_by_ui_event_id
 * @desc **Epic Online Services Function:** [EOS_Lobby_CopyLobbyDetailsHandleByUiEventId](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-copy-lobby-details-handle-by-ui-event-id)
 *
 * Gets a lobby details handle from a `ui_event_id`, as received via the ${event.callback} of ${function.eos_lobby_add_notify_join_lobby_accepted} (the user accepted a join request from the social overlay). Pass the resulting handle to ${function.eos_lobby_join_lobby}.
 *
 * @param {Real} ui_event_id
 *
 * @returns {Real} A lobby details handle ID, or `0` on failure.
 *
 * @function_end
 */

/**
 * @function eos_lobby_details_copy_info
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_CopyInfo](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-details-copy-info)
 *
 * Copies the general info of a lobby details handle.
 *
 * @param {Real} lobby_details_id
 *
 * @returns {Struct.EpicLobbyDetailsInfo} `undefined` if `lobby_details_id` is not a valid handle.
 *
 * @function_end
 */

/**
 * @function eos_lobby_details_get_member_count
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_GetMemberCount](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-details-get-member-count)
 *
 * @param {Real} lobby_details_id
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_lobby_details_get_member_by_index
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_GetMemberByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-details-get-member-by-index)
 *
 * @param {Real} lobby_details_id
 * @param {Real} index Zero-based, must be less than ${function.eos_lobby_details_get_member_count}'s return value.
 *
 * @returns {String} The member's Product User ID.
 *
 * @function_end
 */

/**
 * @function eos_lobby_details_get_lobby_owner
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_GetLobbyOwner](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-details-get-lobby-owner)
 *
 * @param {Real} lobby_details_id
 *
 * @returns {String} The owner's Product User ID.
 *
 * @function_end
 */

/**
 * @function eos_lobby_add_notify_lobby_update_received
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifyLobbyUpdateReceived](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-add-notify-lobby-update-received)
 *
 * Registers to be notified whenever the top-level settings of a lobby the local user belongs to change (permission level, max members, attributes, ...). Call ${function.eos_lobby_remove_notify_lobby_update_received} when you no longer want notifications.
 *
 * @param {String} local_user_id
 * @param {Function} [callback]
 *
 * @returns {Real} A notification ID, used to unregister later, or `0` if registration failed.
 *
 * @event callback
 * @desc Fires every time a subscribed lobby's settings change (not just once).
 * @member {Struct.EpicLobbyLobbyUpdateReceivedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_remove_notify_lobby_update_received
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyLobbyUpdateReceived](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-remove-notify-lobby-update-received)
 *
 * @param {Real} notification_id A handle from ${function.eos_lobby_add_notify_lobby_update_received}.
 *
 * @function_end
 */

/**
 * @function eos_lobby_add_notify_lobby_member_update_received
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifyLobbyMemberUpdateReceived](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-add-notify-lobby-member-update-received)
 *
 * Registers to be notified whenever a member's attributes change in a lobby the local user belongs to.
 *
 * @param {String} local_user_id
 * @param {Function} [callback]
 *
 * @returns {Real} A notification ID, or `0` if registration failed.
 *
 * @event callback
 * @desc Fires every time a member's attributes change (not just once).
 * @member {Struct.EpicLobbyLobbyMemberUpdateReceivedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_remove_notify_lobby_member_update_received
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyLobbyMemberUpdateReceived](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-remove-notify-lobby-member-update-received)
 *
 * @param {Real} notification_id A handle from ${function.eos_lobby_add_notify_lobby_member_update_received}.
 *
 * @function_end
 */

/**
 * @function eos_lobby_add_notify_lobby_member_status_received
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifyLobbyMemberStatusReceived](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-add-notify-lobby-member-status-received)
 *
 * Registers to be notified whenever a member's status changes (joined, left, disconnected, kicked, promoted, or the lobby closed) in a lobby the local user belongs to.
 *
 * @param {String} local_user_id
 * @param {Function} [callback]
 *
 * @returns {Real} A notification ID, or `0` if registration failed.
 *
 * @event callback
 * @desc Fires every time a member's status changes (not just once).
 * @member {Struct.EpicLobbyLobbyMemberStatusReceivedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_remove_notify_lobby_member_status_received
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyLobbyMemberStatusReceived](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-remove-notify-lobby-member-status-received)
 *
 * @param {Real} notification_id A handle from ${function.eos_lobby_add_notify_lobby_member_status_received}.
 *
 * @function_end
 */

/**
 * @function eos_lobby_add_notify_join_lobby_accepted
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifyJoinLobbyAccepted](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-add-notify-join-lobby-accepted)
 *
 * Registers to be notified when the local user accepts an invite to join a lobby from the Epic Games/social overlay (as opposed to accepting it in-game). Not tied to any single lobby, so it takes no `local_user_id` parameter.
 *
 * [[Note: On receiving this, call ${function.eos_lobby_copy_lobby_details_handle_by_ui_event_id} with the callback's `ui_event_id`, then ${function.eos_lobby_join_lobby} with the resulting handle to actually join.]]
 *
 * @param {Function} [callback]
 *
 * @returns {Real} A notification ID, or `0` if registration failed.
 *
 * @event callback
 * @desc Fires every time the user accepts an overlay join-lobby invite (not just once).
 * @member {Struct.EpicLobbyJoinLobbyAcceptedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_remove_notify_join_lobby_accepted
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyJoinLobbyAccepted](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-remove-notify-join-lobby-accepted)
 *
 * @param {Real} notification_id A handle from ${function.eos_lobby_add_notify_join_lobby_accepted}.
 *
 * @function_end
 */

/**
 * @function eos_lobby_add_notify_leave_lobby_requested
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifyLeaveLobbyRequested](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-add-notify-leave-lobby-requested)
 *
 * Registers to be notified when the platform's native UI (e.g. a console's system UI) requests that the local user leave a lobby.
 *
 * @param {String} local_user_id
 * @param {Function} [callback]
 *
 * @returns {Real} A notification ID, or `0` if registration failed.
 *
 * @event callback
 * @desc Fires every time a leave is requested (not just once).
 * @member {Struct.EpicLobbyLeaveLobbyRequestedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_remove_notify_leave_lobby_requested
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyLeaveLobbyRequested](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-remove-notify-leave-lobby-requested)
 *
 * @param {Real} notification_id A handle from ${function.eos_lobby_add_notify_leave_lobby_requested}.
 *
 * @function_end
 */

/**
 * @function eos_lobby_add_notify_send_lobby_native_invite_requested
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifySendLobbyNativeInviteRequested](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-add-notify-send-lobby-native-invite-requested)
 *
 * Registers to be notified when the platform's native social UI requests that the local user invite someone to a lobby (e.g. inviting a console friend who isn't cross-platform-linked yet).
 *
 * [[Warning: After handling this callback you MUST call ${function.eos_ui_acknowledge_event_id} with the callback's `ui_event_id`, or the native UI will hang.]]
 *
 * @param {String} local_user_id
 * @param {Function} [callback]
 *
 * @returns {Real} A notification ID, or `0` if registration failed.
 *
 * @event callback
 * @desc Fires every time a native invite is requested (not just once).
 * @member {Struct.EpicLobbySendLobbyNativeInviteRequestedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_remove_notify_send_lobby_native_invite_requested
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifySendLobbyNativeInviteRequested](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-remove-notify-send-lobby-native-invite-requested)
 *
 * @param {Real} notification_id A handle from ${function.eos_lobby_add_notify_send_lobby_native_invite_requested}.
 *
 * @function_end
 */

/**
 * @function eos_lobby_get_rtc_room_name
 * @desc **Epic Online Services Function:** [EOS_Lobby_GetRTCRoomName](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-get-rtc-room-name)
 *
 * Gets the name of the managed ${module.rtc} voice room tied to a lobby created with `enable_rtc_room` set. Use this name with the RTC-room notify functions below and with ${module.rtc}'s own functions.
 *
 * @param {String} local_user_id
 * @param {String} lobby_id
 *
 * @returns {String} Empty string if the lobby has no RTC room.
 *
 * @function_end
 */

/**
 * @function eos_lobby_add_notify_rtc_room_connection_changed
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifyRTCRoomConnectionChanged](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-add-notify-rtc-room-connection-changed)
 *
 * Registers to be notified when the local user's connection state to a lobby-managed RTC room changes. This is the correct way to track RTC connection status for a lobby room - ${function.eos_rtc_add_notify_disconnected} always reports `0` for lobby-managed rooms.
 *
 * @param {Function} [callback]
 *
 * @returns {Real} A notification ID, or `0` if registration failed.
 *
 * @event callback
 * @desc Fires every time the RTC room connection state changes (not just once).
 * @member {Struct.EpicLobbyRTCRoomConnectionChangedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_remove_notify_rtc_room_connection_changed
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyRTCRoomConnectionChanged](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-remove-notify-rtc-room-connection-changed)
 *
 * @param {Real} notification_id A handle from ${function.eos_lobby_add_notify_rtc_room_connection_changed}.
 *
 * @function_end
 */

/**
 * @function eos_lobby_details_get_attribute_count
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_GetAttributeCount](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-details-get-attribute-count)
 *
 * @param {Real} lobby_details_id
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_lobby_details_copy_attribute_by_index
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_CopyAttributeByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-details-copy-attribute-by-index)
 *
 * @param {Real} lobby_details_id
 * @param {Real} index Zero-based, must be less than ${function.eos_lobby_details_get_attribute_count}'s return value.
 *
 * @returns {Struct.EpicLobbyDetailsAttribute} `undefined` if `index` is out of range.
 *
 * @function_end
 */

/**
 * @function eos_lobby_details_copy_attribute_by_key
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_CopyAttributeByKey](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-details-copy-attribute-by-key)
 *
 * @param {Real} lobby_details_id
 * @param {String} key
 *
 * @returns {Struct.EpicLobbyDetailsAttribute} `undefined` if no attribute with that key exists.
 *
 * @function_end
 */

/**
 * @function eos_lobby_details_get_member_attribute_count
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_GetMemberAttributeCount](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-details-get-member-attribute-count)
 *
 * @param {Real} lobby_details_id
 * @param {String} target_user_id
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_lobby_details_copy_member_attribute_by_index
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_CopyMemberAttributeByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-details-copy-member-attribute-by-index)
 *
 * @param {Real} lobby_details_id
 * @param {String} target_user_id
 * @param {Real} index Zero-based, must be less than ${function.eos_lobby_details_get_member_attribute_count}'s return value.
 *
 * @returns {Struct.EpicLobbyDetailsAttribute} `undefined` if `index` is out of range.
 *
 * @function_end
 */

/**
 * @function eos_lobby_details_copy_member_attribute_by_key
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_CopyMemberAttributeByKey](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-details-copy-member-attribute-by-key)
 *
 * @param {Real} lobby_details_id
 * @param {String} target_user_id
 * @param {String} key
 *
 * @returns {Struct.EpicLobbyDetailsAttribute} `undefined` if no attribute with that key exists.
 *
 * @function_end
 */

/**
 * @function eos_lobby_details_copy_member_info
 * @desc **Epic Online Services Function:** [EOS_LobbyDetails_CopyMemberInfo](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-details-copy-member-info)
 *
 * @param {Real} lobby_details_id
 * @param {String} target_user_id
 *
 * @returns {Struct.EpicLobbyDetailsMemberInfo} `undefined` if `target_user_id` is not a member.
 *
 * @function_end
 */

/**
 * @function eos_lobby_join_lobby_by_id
 * @desc **Epic Online Services Function:** [EOS_Lobby_JoinLobbyById](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-join-lobby-by-id)
 *
 * Joins a lobby directly by ID, without first obtaining a lobby details handle via search. Only works if the lobby was created with `enable_join_by_id` set.
 *
 * @param {Struct.EpicLobbyJoinLobbyByIdOptions} options
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Fires once when the join attempt finishes.
 * @member {Struct.EpicLobbyJoinLobbyByIdCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_hard_mute_member
 * @desc **Epic Online Services Function:** [EOS_Lobby_HardMuteMember](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-hard-mute-member)
 *
 * Forcibly mutes/unmutes a member's voice in the lobby's RTC room server-side (as opposed to a purely local mute). Only the lobby owner may call this.
 *
 * @param {Struct.EpicLobbyHardMuteMemberOptions} options
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Fires once when the mute attempt finishes.
 * @member {Struct.EpicLobbyHardMuteMemberCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_send_invite
 * @desc **Epic Online Services Function:** [EOS_Lobby_SendInvite](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-send-invite)
 *
 * Sends an Epic-account-to-Epic-account lobby invite to another user.
 *
 * @param {Struct.EpicLobbySendInviteOptions} options
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Fires once when the send attempt finishes.
 * @member {Struct.EpicLobbySendInviteCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_reject_invite
 * @desc **Epic Online Services Function:** [EOS_Lobby_RejectInvite](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-reject-invite)
 *
 * @param {String} invite_id
 * @param {String} local_user_id
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Fires once when the reject attempt finishes.
 * @member {Struct.EpicLobbyRejectInviteCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_query_invites
 * @desc **Epic Online Services Function:** [EOS_Lobby_QueryInvites](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-query-invites)
 *
 * Refreshes the local cache of pending lobby invites for the local user, read afterward via ${function.eos_lobby_get_invite_count}/${function.eos_lobby_get_invite_id_by_index}.
 *
 * @param {String} local_user_id
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Fires once when the query finishes.
 * @member {Struct.EpicLobbyQueryInvitesCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_get_invite_count
 * @desc **Epic Online Services Function:** [EOS_Lobby_GetInviteCount](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-get-invite-count)
 *
 * @param {String} local_user_id
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_lobby_get_invite_id_by_index
 * @desc **Epic Online Services Function:** [EOS_Lobby_GetInviteIdByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-get-invite-id-by-index)
 *
 * @param {String} local_user_id
 * @param {Real} index Zero-based, must be less than ${function.eos_lobby_get_invite_count}'s return value.
 *
 * @returns {String}
 *
 * @function_end
 */

/**
 * @function eos_lobby_add_notify_lobby_invite_received
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifyLobbyInviteReceived](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-add-notify-lobby-invite-received)
 *
 * Registers to be notified whenever the local user receives a new lobby invite.
 *
 * @param {Function} [callback]
 *
 * @returns {Real} A notification ID, or `0` if registration failed.
 *
 * @event callback
 * @desc Fires every time an invite is received (not just once).
 * @member {Struct.EpicLobbyLobbyInviteReceivedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_remove_notify_lobby_invite_received
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyLobbyInviteReceived](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-remove-notify-lobby-invite-received)
 *
 * @param {Real} notification_id A handle from ${function.eos_lobby_add_notify_lobby_invite_received}.
 *
 * @function_end
 */

/**
 * @function eos_lobby_add_notify_lobby_invite_accepted
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifyLobbyInviteAccepted](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-add-notify-lobby-invite-accepted)
 *
 * Registers to be notified when the local user accepts one of their own sent invites' recipient response - i.e. fires for the *inviter* when the invitee accepts via the overlay.
 *
 * @param {Function} [callback]
 *
 * @returns {Real} A notification ID, or `0` if registration failed.
 *
 * @event callback
 * @desc Fires every time a sent invite is accepted (not just once).
 * @member {Struct.EpicLobbyLobbyInviteAcceptedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_remove_notify_lobby_invite_accepted
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyLobbyInviteAccepted](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-remove-notify-lobby-invite-accepted)
 *
 * @param {Real} notification_id A handle from ${function.eos_lobby_add_notify_lobby_invite_accepted}.
 *
 * @function_end
 */

/**
 * @function eos_lobby_add_notify_lobby_invite_rejected
 * @desc **Epic Online Services Function:** [EOS_Lobby_AddNotifyLobbyInviteRejected](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-add-notify-lobby-invite-rejected)
 *
 * Registers to be notified when someone rejects an invite the local user sent.
 *
 * @param {Function} [callback]
 *
 * @returns {Real} A notification ID, or `0` if registration failed.
 *
 * @event callback
 * @desc Fires every time a sent invite is rejected (not just once).
 * @member {Struct.EpicLobbyLobbyInviteRejectedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_lobby_remove_notify_lobby_invite_rejected
 * @desc **Epic Online Services Function:** [EOS_Lobby_RemoveNotifyLobbyInviteRejected](https://dev.epicgames.com/docs/api-ref/functions/eos-lobby-remove-notify-lobby-invite-rejected)
 *
 * @param {Real} notification_id A handle from ${function.eos_lobby_add_notify_lobby_invite_rejected}.
 *
 * @function_end
 */


// Constants

/**
 * @const EpicLobbyPermissionLevel
 * @desc **Epic Online Services Enum:** [EOS_ELobbyPermissionLevel](https://dev.epicgames.com/docs/api-ref/enums/eos-e-lobby-permission-level)
 *
 * Controls who can see and join a lobby.
 *
 * @member PublicAdvertised The lobby is visible to everyone and shows up in searches.
 * @member JoinViaPresence The lobby is only joinable by users who can see the owner's presence (e.g. friends).
 * @member InviteOnly The lobby is only joinable via a direct invite.
 * @const_end
 */

/**
 * @const EpicLobbyAttributeVisibility
 * @desc **Epic Online Services Enum:** [EOS_ELobbyAttributeVisibility](https://dev.epicgames.com/docs/api-ref/enums/eos-e-lobby-attribute-visibility)
 *
 * @member Public The attribute is visible to anyone who can see the lobby (e.g. in search results).
 * @member Private The attribute is only visible to lobby members.
 * @const_end
 */

/**
 * @const EpicLobbyMemberStatus
 * @desc **Epic Online Services Enum:** [EOS_ELobbyMemberStatus](https://dev.epicgames.com/docs/api-ref/enums/eos-e-lobby-member-status)
 *
 * @member Joined The member joined the lobby.
 * @member Left The member left the lobby voluntarily.
 * @member Disconnected The member's connection to the lobby was lost.
 * @member Kicked The member was kicked from the lobby.
 * @member Promoted The member was promoted to lobby owner.
 * @member Closed The lobby was closed.
 * @const_end
 */

/**
 * @const EpicLobbyRTCRoomJoinActionType
 * @desc **Epic Online Services Enum:** [EOS_ELobbyRTCRoomJoinActionType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-lobby-rtc-room-join-action-type)
 *
 * [[Note: Currently fixed to `AutomaticJoin` by this extension's native implementation - the SDK's manual-join mode isn't exposed via `spec.gmidl` yet.]]
 *
 * @member AutomaticJoin The RTC room is joined automatically as soon as the lobby's RTC room is created/joined.
 * @member ManualJoin The RTC room must be joined manually by the application.
 * @const_end
 */


// Structs

/**
 * @struct EpicLobbyCreateLobbyOptions
 * @desc Input for ${function.eos_lobby_create_lobby}.
 *
 * @member {String} local_user_id The Product User ID of the lobby owner.
 * @member {Real} max_lobby_members Maximum number of members allowed to join.
 * @member {Constant.EpicLobbyPermissionLevel} permission_level
 * @member {Bool} presence_enabled Whether this is the user's single "presence lobby" (shown in their rich presence).
 * @member {Bool} allow_invites Whether members are allowed to send invites to this lobby.
 * @member {String} bucket_id Arbitrary grouping/filter string, required.
 * @member {Bool} disable_host_migration If `true`, the lobby is destroyed instead of migrating ownership when the owner leaves.
 * @member {Bool} enable_rtc_room If `true`, a managed voice room is created for this lobby - see ${function.eos_lobby_get_rtc_room_name}.
 * @member {Bool} enable_join_by_id If `true`, the lobby can be joined directly via ${function.eos_lobby_join_lobby_by_id}.
 * @member {Bool} rejoin_after_kick_requires_invite If `true`, a kicked member needs a fresh invite to rejoin.
 * @struct_end
 */

/**
 * @struct EpicLobbyCreateLobbyCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_create_lobby}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} lobby_id
 * @struct_end
 */

/**
 * @struct EpicLobbyDestroyLobbyCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_destroy_lobby}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} lobby_id
 * @struct_end
 */

/**
 * @struct EpicLobbyJoinLobbyOptions
 * @desc Input for ${function.eos_lobby_join_lobby}.
 *
 * @member {Real} lobby_details_handle_id A handle from ${function.eos_lobby_copy_lobby_details_handle}/${function.eos_lobby_copy_lobby_details_handle_by_invite_id}/${function.eos_lobby_copy_lobby_details_handle_by_ui_event_id}/${function.eos_lobby_lobby_search_copy_search_result_by_index}.
 * @member {String} local_user_id
 * @member {Bool} presence_enabled
 * @struct_end
 */

/**
 * @struct EpicLobbyJoinLobbyCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_join_lobby}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} lobby_id
 * @struct_end
 */

/**
 * @struct EpicLobbyLeaveLobbyCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_leave_lobby}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} lobby_id
 * @struct_end
 */

/**
 * @struct EpicLobbyUpdateLobbyCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_update_lobby}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} lobby_id
 * @struct_end
 */

/**
 * @struct EpicLobbyPromoteMemberOptions
 * @desc Input for ${function.eos_lobby_promote_member}.
 *
 * @member {String} lobby_id
 * @member {String} local_user_id The current owner making the request.
 * @member {String} target_user_id The member to promote.
 * @struct_end
 */

/**
 * @struct EpicLobbyPromoteMemberCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_promote_member}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} lobby_id
 * @struct_end
 */

/**
 * @struct EpicLobbyKickMemberOptions
 * @desc Input for ${function.eos_lobby_kick_member}.
 *
 * @member {String} lobby_id
 * @member {String} local_user_id The current owner making the request.
 * @member {String} target_user_id The member to kick.
 * @struct_end
 */

/**
 * @struct EpicLobbyKickMemberCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_kick_member}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} lobby_id
 * @struct_end
 */

/**
 * @struct EpicLobbyModificationAddAttributeOptions
 * @desc Shape of a lobby attribute (key/value/visibility). Declared in `spec.gmidl` alongside ${function.eos_lobby_lobby_modification_add_attribute_string}, but that function (and its `_bool`/`_double` siblings) currently takes `key`/`value`/`visibility` as flat parameters rather than this struct - it isn't reachable from any function today.
 *
 * @member {String} key
 * @member {String} value
 * @member {Constant.EpicLobbyAttributeVisibility} visibility
 * @struct_end
 */

/**
 * @struct EpicLobbyModificationAddMemberAttributeOptions
 * @desc Shape of a lobby member attribute (key/value/visibility). Declared in `spec.gmidl` alongside ${function.eos_lobby_lobby_modification_add_member_attribute_string}, but that function (and its `_bool`/`_double` siblings) currently takes `key`/`value`/`visibility` as flat parameters rather than this struct - it isn't reachable from any function today.
 *
 * @member {String} key
 * @member {String} value
 * @member {Constant.EpicLobbyAttributeVisibility} visibility
 * @struct_end
 */

/**
 * @struct EpicLobbySearchFindCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_lobby_search_find}.
 *
 * @member {Constant.EpicResult} result_code
 * @struct_end
 */

/**
 * @struct EpicLobbySearchSetParameterOptions
 * @desc Shape of a lobby search parameter (key/value/comparison). Declared in `spec.gmidl` alongside ${function.eos_lobby_lobby_search_set_parameter_string}, but that function (and its `_bool`/`_double` siblings) currently takes `key`/`value`/`comparison_op` as flat parameters rather than this struct - it isn't reachable from any function today.
 *
 * @member {String} key
 * @member {String} value
 * @member {Constant.EpicComparisonOp} comparison_op
 * @struct_end
 */

/**
 * @struct EpicLobbySearchRemoveParameterOptions
 * @desc Input for ${function.eos_lobby_lobby_search_remove_parameter}.
 *
 * @member {String} key
 * @member {Constant.EpicComparisonOp} comparison_op Must match the operator the parameter was originally added with.
 * @struct_end
 */

/**
 * @struct EpicLobbyDetailsInfo
 * @desc Result of ${function.eos_lobby_details_copy_info}.
 *
 * @member {String} lobby_id
 * @member {String} bucket_id
 * @member {String} lobby_owner_user_id
 * @member {Real} available_slots
 * @member {Real} max_members
 * @member {Constant.EpicLobbyPermissionLevel} permission_level
 * @member {Bool} allow_invites
 * @member {Bool} presence_enabled
 * @member {Bool} rtc_room_enabled
 * @member {Bool} allow_host_migration
 * @member {Bool} allow_join_by_id
 * @member {Bool} rejoin_after_kick_requires_invite
 * @member {Real} allowed_platform_ids_count
 * @member {Array[Real]} allowed_platform_ids Platform IDs allowed to join, when the lobby restricts crossplay.
 * @struct_end
 */

/**
 * @struct EpicLobbyLobbyUpdateReceivedCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_add_notify_lobby_update_received}.
 *
 * @member {String} lobby_id
 * @member {String} local_user_id
 * @struct_end
 */

/**
 * @struct EpicLobbyLobbyMemberUpdateReceivedCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_add_notify_lobby_member_update_received}.
 *
 * @member {String} lobby_id
 * @member {String} target_user_id The member whose attributes changed.
 * @member {String} local_user_id
 * @struct_end
 */

/**
 * @struct EpicLobbyLobbyMemberStatusReceivedCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_add_notify_lobby_member_status_received}.
 *
 * @member {String} lobby_id
 * @member {String} target_user_id The member whose status changed.
 * @member {String} local_user_id
 * @member {Constant.EpicLobbyMemberStatus} current_status
 * @struct_end
 */

/**
 * @struct EpicLobbyJoinLobbyAcceptedCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_add_notify_join_lobby_accepted}.
 *
 * @member {Real} ui_event_id Pass to ${function.eos_lobby_copy_lobby_details_handle_by_ui_event_id}.
 * @member {String} local_user_id
 * @struct_end
 */

/**
 * @struct EpicLobbyLeaveLobbyRequestedCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_add_notify_leave_lobby_requested}.
 *
 * @member {String} lobby_id
 * @member {String} local_user_id
 * @struct_end
 */

/**
 * @struct EpicLobbySendLobbyNativeInviteRequestedCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_add_notify_send_lobby_native_invite_requested}.
 *
 * @member {Real} ui_event_id Pass to ${function.eos_ui_acknowledge_event_id} once handled.
 * @member {String} lobby_id
 * @member {String} local_user_id
 * @member {String} target_native_account_type The target's native platform account type.
 * @member {String} target_user_native_account_id The target's native platform account ID.
 * @struct_end
 */

/**
 * @struct EpicLobbyRTCRoomConnectionChangedCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_add_notify_rtc_room_connection_changed}.
 *
 * @member {String} lobby_id
 * @member {String} local_user_id
 * @member {Bool} is_connected
 * @member {Constant.EpicResult} disconnect_reason Only meaningful when `is_connected` is `false`.
 * @struct_end
 */

/**
 * @struct EpicLobbyDetailsAttribute
 * @desc A single lobby or lobby-member attribute, returned by the `details_copy_attribute_*`/`details_copy_member_attribute_*` accessors.
 *
 * @member {String} key
 * @member {String} value Always returned as a string; use `value_type` to know how to interpret/reparse it.
 * @member {Constant.EpicAttributeType} value_type
 * @member {Constant.EpicLobbyAttributeVisibility} visibility
 * @struct_end
 */

/**
 * @struct EpicLobbyDetailsMemberInfo
 * @desc Result of ${function.eos_lobby_details_copy_member_info}.
 *
 * @member {String} user_id
 * @member {Real} platform
 * @member {Bool} allows_crossplay
 * @struct_end
 */

/**
 * @struct EpicLobbyJoinLobbyByIdOptions
 * @desc Input for ${function.eos_lobby_join_lobby_by_id}.
 *
 * @member {String} lobby_id
 * @member {String} local_user_id
 * @member {Bool} presence_enabled
 * @struct_end
 */

/**
 * @struct EpicLobbyJoinLobbyByIdCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_join_lobby_by_id}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} lobby_id
 * @struct_end
 */

/**
 * @struct EpicLobbyHardMuteMemberOptions
 * @desc Input for ${function.eos_lobby_hard_mute_member}.
 *
 * @member {String} lobby_id
 * @member {String} local_user_id The lobby owner making the request.
 * @member {String} target_user_id The member to mute/unmute.
 * @member {Bool} hard_mute
 * @struct_end
 */

/**
 * @struct EpicLobbyHardMuteMemberCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_hard_mute_member}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} lobby_id
 * @member {String} target_user_id
 * @struct_end
 */

/**
 * @struct EpicLobbySendInviteOptions
 * @desc Input for ${function.eos_lobby_send_invite}.
 *
 * @member {String} lobby_id
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @struct_end
 */

/**
 * @struct EpicLobbySendInviteCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_send_invite}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} lobby_id
 * @struct_end
 */

/**
 * @struct EpicLobbyRejectInviteCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_reject_invite}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} invite_id
 * @struct_end
 */

/**
 * @struct EpicLobbyQueryInvitesCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_query_invites}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end
 */

/**
 * @struct EpicLobbyLobbyInviteReceivedCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_add_notify_lobby_invite_received}.
 *
 * @member {String} invite_id
 * @member {String} local_user_id
 * @member {String} target_user_id The user who sent the invite.
 * @struct_end
 */

/**
 * @struct EpicLobbyLobbyInviteAcceptedCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_add_notify_lobby_invite_accepted}.
 *
 * @member {String} invite_id
 * @member {String} local_user_id
 * @member {String} target_user_id The user who accepted the invite.
 * @member {String} lobby_id
 * @struct_end
 */

/**
 * @struct EpicLobbyLobbyInviteRejectedCallbackInfo
 * @desc Callback payload for ${function.eos_lobby_add_notify_lobby_invite_rejected}.
 *
 * @member {String} invite_id
 * @member {String} local_user_id
 * @member {String} target_user_id The user who rejected the invite.
 * @member {String} lobby_id
 * @struct_end
 */


/**
 * @module lobbies
 * @title Lobbies
 * @desc **Epic Online Services Interface:** [Lobby Interface](https://dev.epicgames.com/docs/game-services/eos-lobby-interface)
 *
 * A lobby is a small, mutable group of players (with attributes, per-member attributes, invites, and an
 * optional managed ${module.rtc} voice room) that exists before or alongside actual gameplay - e.g. a
 * party/pre-game staging area. For matchmaking large numbers of dedicated-server-backed players, see
 * ${module.sessions} instead.
 *
 * @section_func
 * @desc Provided functions:
 *
 * @ref eos_lobby_create_lobby
 * @ref eos_lobby_destroy_lobby
 * @ref eos_lobby_join_lobby
 * @ref eos_lobby_leave_lobby
 * @ref eos_lobby_update_lobby_modification
 * @ref eos_lobby_lobby_modification_release
 * @ref eos_lobby_update_lobby
 * @ref eos_lobby_lobby_modification_set_permission_level
 * @ref eos_lobby_lobby_modification_set_max_members
 * @ref eos_lobby_lobby_modification_set_bucket_id
 * @ref eos_lobby_lobby_modification_set_invites_allowed
 * @ref eos_lobby_lobby_modification_add_attribute_string
 * @ref eos_lobby_lobby_modification_add_attribute_bool
 * @ref eos_lobby_lobby_modification_add_attribute_double
 * @ref eos_lobby_lobby_modification_remove_attribute
 * @ref eos_lobby_lobby_modification_add_member_attribute_string
 * @ref eos_lobby_lobby_modification_add_member_attribute_bool
 * @ref eos_lobby_lobby_modification_add_member_attribute_double
 * @ref eos_lobby_lobby_modification_remove_member_attribute
 * @ref eos_lobby_promote_member
 * @ref eos_lobby_kick_member
 * @ref eos_lobby_create_lobby_search
 * @ref eos_lobby_lobby_search_release
 * @ref eos_lobby_lobby_search_set_lobby_id
 * @ref eos_lobby_lobby_search_set_target_user_id
 * @ref eos_lobby_lobby_search_set_parameter_string
 * @ref eos_lobby_lobby_search_set_parameter_bool
 * @ref eos_lobby_lobby_search_set_parameter_double
 * @ref eos_lobby_lobby_search_remove_parameter
 * @ref eos_lobby_lobby_search_set_max_results
 * @ref eos_lobby_lobby_search_find
 * @ref eos_lobby_lobby_search_get_search_result_count
 * @ref eos_lobby_lobby_search_copy_search_result_by_index
 * @ref eos_lobby_details_release
 * @ref eos_lobby_copy_lobby_details_handle
 * @ref eos_lobby_copy_lobby_details_handle_by_invite_id
 * @ref eos_lobby_copy_lobby_details_handle_by_ui_event_id
 * @ref eos_lobby_details_copy_info
 * @ref eos_lobby_details_get_member_count
 * @ref eos_lobby_details_get_member_by_index
 * @ref eos_lobby_details_get_lobby_owner
 * @ref eos_lobby_add_notify_lobby_update_received
 * @ref eos_lobby_remove_notify_lobby_update_received
 * @ref eos_lobby_add_notify_lobby_member_update_received
 * @ref eos_lobby_remove_notify_lobby_member_update_received
 * @ref eos_lobby_add_notify_lobby_member_status_received
 * @ref eos_lobby_remove_notify_lobby_member_status_received
 * @ref eos_lobby_add_notify_join_lobby_accepted
 * @ref eos_lobby_remove_notify_join_lobby_accepted
 * @ref eos_lobby_add_notify_leave_lobby_requested
 * @ref eos_lobby_remove_notify_leave_lobby_requested
 * @ref eos_lobby_add_notify_send_lobby_native_invite_requested
 * @ref eos_lobby_remove_notify_send_lobby_native_invite_requested
 * @ref eos_lobby_get_rtc_room_name
 * @ref eos_lobby_add_notify_rtc_room_connection_changed
 * @ref eos_lobby_remove_notify_rtc_room_connection_changed
 * @ref eos_lobby_details_get_attribute_count
 * @ref eos_lobby_details_copy_attribute_by_index
 * @ref eos_lobby_details_copy_attribute_by_key
 * @ref eos_lobby_details_get_member_attribute_count
 * @ref eos_lobby_details_copy_member_attribute_by_index
 * @ref eos_lobby_details_copy_member_attribute_by_key
 * @ref eos_lobby_details_copy_member_info
 * @ref eos_lobby_join_lobby_by_id
 * @ref eos_lobby_hard_mute_member
 * @ref eos_lobby_send_invite
 * @ref eos_lobby_reject_invite
 * @ref eos_lobby_query_invites
 * @ref eos_lobby_get_invite_count
 * @ref eos_lobby_get_invite_id_by_index
 * @ref eos_lobby_add_notify_lobby_invite_received
 * @ref eos_lobby_remove_notify_lobby_invite_received
 * @ref eos_lobby_add_notify_lobby_invite_accepted
 * @ref eos_lobby_remove_notify_lobby_invite_accepted
 * @ref eos_lobby_add_notify_lobby_invite_rejected
 * @ref eos_lobby_remove_notify_lobby_invite_rejected
 *
 * @section_end
 *
 * @section_const
 * @desc These are the constants used by this API:
 *
 * @ref EpicLobbyPermissionLevel
 * @ref EpicLobbyAttributeVisibility
 * @ref EpicLobbyMemberStatus
 * @ref EpicLobbyRTCRoomJoinActionType
 *
 * @section_end
 *
 * @section_struct
 * @desc These are the structs used by this API:
 *
 * @ref EpicLobbyCreateLobbyOptions
 * @ref EpicLobbyCreateLobbyCallbackInfo
 * @ref EpicLobbyDestroyLobbyCallbackInfo
 * @ref EpicLobbyJoinLobbyOptions
 * @ref EpicLobbyJoinLobbyCallbackInfo
 * @ref EpicLobbyLeaveLobbyCallbackInfo
 * @ref EpicLobbyUpdateLobbyCallbackInfo
 * @ref EpicLobbyPromoteMemberOptions
 * @ref EpicLobbyPromoteMemberCallbackInfo
 * @ref EpicLobbyKickMemberOptions
 * @ref EpicLobbyKickMemberCallbackInfo
 * @ref EpicLobbyModificationAddAttributeOptions
 * @ref EpicLobbyModificationAddMemberAttributeOptions
 * @ref EpicLobbySearchFindCallbackInfo
 * @ref EpicLobbySearchSetParameterOptions
 * @ref EpicLobbySearchRemoveParameterOptions
 * @ref EpicLobbyDetailsInfo
 * @ref EpicLobbyLobbyUpdateReceivedCallbackInfo
 * @ref EpicLobbyLobbyMemberUpdateReceivedCallbackInfo
 * @ref EpicLobbyLobbyMemberStatusReceivedCallbackInfo
 * @ref EpicLobbyJoinLobbyAcceptedCallbackInfo
 * @ref EpicLobbyLeaveLobbyRequestedCallbackInfo
 * @ref EpicLobbySendLobbyNativeInviteRequestedCallbackInfo
 * @ref EpicLobbyRTCRoomConnectionChangedCallbackInfo
 * @ref EpicLobbyDetailsAttribute
 * @ref EpicLobbyDetailsMemberInfo
 * @ref EpicLobbyJoinLobbyByIdOptions
 * @ref EpicLobbyJoinLobbyByIdCallbackInfo
 * @ref EpicLobbyHardMuteMemberOptions
 * @ref EpicLobbyHardMuteMemberCallbackInfo
 * @ref EpicLobbySendInviteOptions
 * @ref EpicLobbySendInviteCallbackInfo
 * @ref EpicLobbyRejectInviteCallbackInfo
 * @ref EpicLobbyQueryInvitesCallbackInfo
 * @ref EpicLobbyLobbyInviteReceivedCallbackInfo
 * @ref EpicLobbyLobbyInviteAcceptedCallbackInfo
 * @ref EpicLobbyLobbyInviteRejectedCallbackInfo
 *
 * @section_end
 *
 * @module_end
 */
