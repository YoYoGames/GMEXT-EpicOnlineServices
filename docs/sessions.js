// ============================================================
// Session lifecycle
// ============================================================

/**
 * @function eos_sessions_create_session_modification
 * @desc **Epic Online Services Function:** [EOS_Sessions_CreateSessionModification](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-create-session-modification)
 *
 * Creates a session modification handle. This handle is used to build up the settings for a brand new
 * session (an empty `session_id` lets the backend assign one) before calling ${function.eos_sessions_update_session}
 * to publish it. Configure the modification with the `eos_sessions_session_modification_*` functions below.
 *
 * [[Note: `session_id`, when provided, must be 16-64 characters. An empty string is invalid; pass an empty string only when you want the backend to assign an id.]]
 *
 * @param {String} session_name A local, client-side label for this session. Must be unique among your currently active sessions.
 * @param {String} session_id Backend session id, or an empty string to let the backend assign one.
 * @param {String} bucket_id A logical bucket for filtering search results (e.g. region/gamemode).
 * @param {Real} max_players Maximum number of players allowed in the session.
 * @param {String} local_user_id The Product User ID creating the session.
 * @param {Bool} presence_enabled Whether this is the user's presence session (only one presence session may exist per local user).
 * @param {Bool} sanctions_enabled Whether joining players are checked against ${module.sanctions}.
 * @param {Array[Real]} allowed_platform_ids Platform ids (`EOS_EOnlineExternalAccountType`-style) allowed to join, or an empty array to allow every platform.
 *
 * @returns {Real} A session modification handle (`0` on failure), consumed by ${function.eos_sessions_update_session} or released with ${function.eos_sessions_session_modification_release}.
 *
 * @example
 * ```gml
 * var _mod = eos_sessions_create_session_modification("MySession", "", "region-eu", 4, local_user_id, true, false, []);
 * eos_sessions_session_modification_set_permission_level(_mod, EOS_ONLINE_SESSION_PERMISSION_LEVEL.PUBLIC_ADVERTISED);
 * eos_sessions_update_session(_mod, function(_result) {
 *     show_debug_message($"Session created: {_result.result_code}");
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_modification_release
 * @desc **Epic Online Services Function:** [EOS_SessionModificationHandle_Release](https://dev.epicgames.com/docs/api-ref/functions/eos-session-modification-handle-release)
 *
 * Releases a session modification handle without publishing it. Call this if you decide not to commit
 * changes built up with ${function.eos_sessions_create_session_modification}.
 *
 * [[Note: You do NOT need to call this after ${function.eos_sessions_update_session} - that function releases the handle internally once it hands the modification off to the SDK.]]
 *
 * @param {Real} modification_id A session modification handle.
 *
 * @example
 * ```gml
 * eos_sessions_session_modification_release(_mod);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_update_session
 * @desc **Epic Online Services Function:** [EOS_Sessions_UpdateSession](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-update-session)
 *
 * Publishes a session modification, creating the session on the first call or applying changes on later
 * calls. This function consumes and releases `modification_id` - don't call ${function.eos_sessions_session_modification_release} on it afterward.
 *
 * @param {Real} modification_id A session modification handle from ${function.eos_sessions_create_session_modification}.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Fires once with the outcome of the update.
 * @member {Struct.EpicSessionsUpdateSessionCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_sessions_update_session(_mod, function(_result) {
 *     if (_result.result_code == EPIC_RESULT.SUCCESS)
 *     {
 *         show_debug_message($"Session '{_result.session_name}' is live ({_result.session_id}).");
 *     }
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_destroy_session
 * @desc **Epic Online Services Function:** [EOS_Sessions_DestroySession](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-destroy-session)
 *
 * Destroys a session that this client is currently in, unregistering every player from it.
 *
 * @param {String} session_name The local session name.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @member {Struct.EpicSessionsDestroySessionCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_sessions_destroy_session("MySession", function(_result) {
 *     show_debug_message($"Destroy result: {_result.result_code}");
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_start_session
 * @desc **Epic Online Services Function:** [EOS_Sessions_StartSession](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-start-session)
 *
 * Marks a session as started (in progress), which prevents any further joins if `join_in_progress_allowed`
 * is false. Only the owning client should call this once gameplay begins.
 *
 * @param {String} session_name The local session name.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @member {Struct.EpicSessionsStartSessionCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_sessions_start_session("MySession", function(_result) {
 *     show_debug_message($"Start result: {_result.result_code}");
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_end_session
 * @desc **Epic Online Services Function:** [EOS_Sessions_EndSession](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-end-session)
 *
 * Marks a session as no longer in progress (e.g. back to a lobby/waiting state), re-opening it to joins.
 *
 * @param {String} session_name The local session name.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @member {Struct.EpicSessionsEndSessionCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_sessions_end_session("MySession", function(_result) {
 *     show_debug_message($"End result: {_result.result_code}");
 * });
 * ```
 * @function_end
 */

// ============================================================
// Joining and player registration
// ============================================================

/**
 * @function eos_sessions_join_session
 * @desc **Epic Online Services Function:** [EOS_Sessions_JoinSession](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-join-session)
 *
 * Joins a session using a session details handle obtained from a search result (${function.eos_sessions_session_search_copy_search_result_by_index})
 * or an invite (${function.eos_sessions_copy_session_handle_by_invite_id}/${function.eos_sessions_copy_session_handle_by_ui_event_id}).
 *
 * @param {String} session_name A local label for the joined session, unique among your currently active sessions.
 * @param {Real} session_details_id A session details handle describing the session to join.
 * @param {String} local_user_id The Product User ID joining the session.
 * @param {Bool} presence_enabled Whether this becomes the user's presence session.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @member {Struct.EpicSessionsJoinSessionCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_sessions_join_session("MySession", _session_details_id, local_user_id, true, function(_result) {
 *     show_debug_message($"Join result: {_result.result_code}");
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_register_players
 * @desc **Epic Online Services Function:** [EOS_Sessions_RegisterPlayers](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-register-players)
 *
 * Registers additional players (e.g. local split-screen players, or players who joined outside of the
 * SDK's own join flow) as members of an existing session, so they count toward `max_players` and can be
 * enumerated via ${function.eos_sessions_active_session_get_registered_player_by_index}.
 *
 * @param {String} session_name The local session name.
 * @param {Array[String]} target_user_ids Product User IDs to register.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Fires once with the registration outcome. If ${module.sanctions} checking is enabled on the session, sanctioned players are reported separately and are NOT added to `registered_players`.
 * @member {Struct.EpicSessionsRegisterPlayersCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_sessions_register_players("MySession", [target_user_id], function(_result) {
 *     show_debug_message($"Registered: {_result.registered_players}, sanctioned: {_result.sanctioned_players}");
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_unregister_players
 * @desc **Epic Online Services Function:** [EOS_Sessions_UnregisterPlayers](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-unregister-players)
 *
 * Removes previously registered players from a session.
 *
 * @param {String} session_name The local session name.
 * @param {Array[String]} target_user_ids Product User IDs to unregister.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @member {Struct.EpicSessionsUnregisterPlayersCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_sessions_unregister_players("MySession", [target_user_id], function(_result) {
 *     show_debug_message($"Unregistered: {_result.unregistered_players}");
 * });
 * ```
 * @function_end
 */

// ============================================================
// Session search
// ============================================================

/**
 * @function eos_sessions_create_session_search
 * @desc **Epic Online Services Function:** [EOS_Sessions_CreateSessionSearch](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-create-session-search)
 *
 * Creates a session search handle. Configure it with the `eos_sessions_session_search_set_*` functions
 * below, then call ${function.eos_sessions_session_search_find} to run the search.
 *
 * @param {Real} max_search_results Maximum number of results the search should return.
 *
 * @returns {Real} A session search handle (`0` on failure), released with ${function.eos_sessions_session_search_release}.
 *
 * @example
 * ```gml
 * var _search = eos_sessions_create_session_search(10);
 * eos_sessions_session_search_set_parameter(_search, "region", "eu", EPIC_COMPARISON_OP.EQUAL);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_search_release
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_Release](https://dev.epicgames.com/docs/api-ref/functions/eos-session-search-release)
 *
 * Releases a session search handle and every search result it produced. Session details handles copied
 * out via ${function.eos_sessions_session_search_copy_search_result_by_index} remain valid after this
 * call - release them separately with ${function.eos_sessions_session_details_release}.
 *
 * @param {Real} search_id A session search handle.
 *
 * @example
 * ```gml
 * eos_sessions_session_search_release(_search);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_search_set_session_id
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_SetSessionId](https://dev.epicgames.com/docs/api-ref/functions/eos-session-search-set-session-id)
 *
 * Restricts a session search to a single, known session id.
 *
 * @param {Real} search_id A session search handle.
 * @param {String} session_id The session id to search for.
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * eos_sessions_session_search_set_session_id(_search, _session_id);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_search_set_target_user_id
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_SetTargetUserId](https://dev.epicgames.com/docs/api-ref/functions/eos-session-search-set-target-user-id)
 *
 * Restricts a session search to a single user's presence session.
 *
 * @param {Real} search_id A session search handle.
 * @param {String} target_user_id The Product User ID whose presence session to search for.
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * eos_sessions_session_search_set_target_user_id(_search, _target_user_id);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_search_set_parameter
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_SetParameter](https://dev.epicgames.com/docs/api-ref/functions/eos-session-search-set-parameter)
 *
 * Adds a string-valued attribute filter to a session search (compares against attributes set via
 * ${function.eos_sessions_session_modification_add_attribute_string} on the target sessions).
 *
 * @param {Real} search_id A session search handle.
 * @param {String} key The attribute key to filter on.
 * @param {String} value The value to compare against.
 * @param {Constant.EpicComparisonOp} comparison_op How `value` should be compared against each session's attribute.
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * eos_sessions_session_search_set_parameter(_search, "gamemode", "deathmatch", EPIC_COMPARISON_OP.EQUAL);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_search_remove_parameter
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_RemoveParameter](https://dev.epicgames.com/docs/api-ref/functions/eos-session-search-remove-parameter)
 *
 * Removes a previously added attribute filter, matched by key and comparison operator.
 *
 * @param {Real} search_id A session search handle.
 * @param {String} key The attribute key to remove.
 * @param {Constant.EpicComparisonOp} comparison_op The comparison operator the filter was added with.
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * eos_sessions_session_search_remove_parameter(_search, "gamemode", EPIC_COMPARISON_OP.EQUAL);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_search_find
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_Find](https://dev.epicgames.com/docs/api-ref/functions/eos-session-search-find)
 *
 * Executes a configured session search.
 *
 * @param {Real} search_id A session search handle.
 * @param {String} local_user_id The Product User ID performing the search.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @member {Struct.EpicSessionsFindCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_sessions_session_search_find(_search, local_user_id, function(_result) {
 *     if (_result.result_code == EPIC_RESULT.SUCCESS)
 *     {
 *         var _count = eos_sessions_session_search_get_search_result_count(_search);
 *         show_debug_message($"Found {_count} sessions.");
 *     }
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_search_get_search_result_count
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_GetSearchResultCount](https://dev.epicgames.com/docs/api-ref/functions/eos-session-search-get-search-result-count)
 *
 * Gets the number of results from the last completed ${function.eos_sessions_session_search_find} call.
 *
 * @param {Real} search_id A session search handle.
 *
 * @returns {Real}
 *
 * @example
 * ```gml
 * var _count = eos_sessions_session_search_get_search_result_count(_search);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_search_copy_search_result_by_index
 * @desc **Epic Online Services Function:** [EOS_SessionSearch_CopySearchResultByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-session-search-copy-search-result-by-index)
 *
 * Copies a session details handle for one of the search results.
 *
 * @param {Real} search_id A session search handle.
 * @param {Real} index Index in `[0, ${function.eos_sessions_session_search_get_search_result_count}())`.
 *
 * @returns {Real} A session details handle (`0` on failure), released with ${function.eos_sessions_session_details_release}.
 *
 * @example
 * ```gml
 * var _details_id = eos_sessions_session_search_copy_search_result_by_index(_search, 0);
 * ```
 * @function_end
 */

// ============================================================
// Session details / active session accessors
// ============================================================

/**
 * @function eos_sessions_session_details_release
 * @desc **Epic Online Services Function:** [EOS_SessionDetails_Release](https://dev.epicgames.com/docs/api-ref/functions/eos-session-details-release)
 *
 * Releases a session details handle obtained from a search result or an invite.
 *
 * @param {Real} session_details_id A session details handle.
 *
 * @example
 * ```gml
 * eos_sessions_session_details_release(_details_id);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_copy_active_session_handle
 * @desc **Epic Online Services Function:** [EOS_Sessions_CopyActiveSessionHandle](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-copy-active-session-handle)
 *
 * Copies a handle to a session this client is currently in, by its local session name.
 *
 * @param {String} session_name The local session name.
 *
 * @returns {Real} An active session handle (`0` on failure), released with ${function.eos_sessions_active_session_release}.
 *
 * @example
 * ```gml
 * var _active_id = eos_sessions_copy_active_session_handle("MySession");
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_active_session_release
 * @desc **Epic Online Services Function:** [EOS_ActiveSession_Release](https://dev.epicgames.com/docs/api-ref/functions/eos-active-session-release)
 *
 * Releases an active session handle.
 *
 * @param {Real} active_session_id An active session handle.
 *
 * @example
 * ```gml
 * eos_sessions_active_session_release(_active_id);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_active_session_copy_info
 * @desc **Epic Online Services Function:** [EOS_ActiveSession_CopyInfo](https://dev.epicgames.com/docs/api-ref/functions/eos-active-session-copy-info)
 *
 * Copies the current info for an active session.
 *
 * @param {Real} active_session_id An active session handle.
 *
 * @returns {Struct.EpicActiveSessionInfo} `undefined` if the handle is invalid or the info couldn't be copied.
 *
 * @example
 * ```gml
 * var _info = eos_sessions_active_session_copy_info(_active_id);
 * if (!is_undefined(_info)) { show_debug_message(_info.session_id); }
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_copy_session_handle_by_invite_id
 * @desc **Epic Online Services Function:** [EOS_Sessions_CopySessionHandleByInviteId](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-copy-session-handle-by-invite-id)
 *
 * Copies a session details handle for a pending invite, typically used from an
 * ${function.eos_sessions_add_notify_session_invite_received} callback.
 *
 * @param {String} invite_id The invite id.
 *
 * @returns {Real} A session details handle (`0` on failure), released with ${function.eos_sessions_session_details_release}.
 *
 * @example
 * ```gml
 * var _details_id = eos_sessions_copy_session_handle_by_invite_id(_invite_id);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_copy_session_handle_by_ui_event_id
 * @desc **Epic Online Services Function:** [EOS_Sessions_CopySessionHandleByUiEventId](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-copy-session-handle-by-ui-event-id)
 *
 * Copies a session details handle for a join request that originated from the Epic overlay, typically
 * used from an ${function.eos_sessions_add_notify_join_session_accepted} callback.
 *
 * [[Warning: After using `ui_event_id` to look up the session, you must still call ${function.eos_ui_acknowledge_event_id} with the same id once your join attempt resolves, or the overlay is left waiting indefinitely.]]
 *
 * @param {Real} ui_event_id The UI event id from ${struct.EpicSessionsJoinSessionAcceptedCallbackInfo}.
 *
 * @returns {Real} A session details handle (`0` on failure), released with ${function.eos_sessions_session_details_release}.
 *
 * @example
 * ```gml
 * var _details_id = eos_sessions_copy_session_handle_by_ui_event_id(_ui_event_id);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_details_copy_info
 * @desc **Epic Online Services Function:** [EOS_SessionDetails_CopyInfo](https://dev.epicgames.com/docs/api-ref/functions/eos-session-details-copy-info)
 *
 * Copies the info for a session details handle.
 *
 * @param {Real} session_details_id A session details handle.
 *
 * @returns {Struct.EpicSessionDetailsInfo} `undefined` if the handle is invalid or the info couldn't be copied.
 *
 * @example
 * ```gml
 * var _info = eos_sessions_session_details_copy_info(_details_id);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_details_get_session_attribute_count
 * @desc **Epic Online Services Function:** [EOS_SessionDetails_GetSessionAttributeCount](https://dev.epicgames.com/docs/api-ref/functions/eos-session-details-get-session-attribute-count)
 *
 * @param {Real} session_details_id A session details handle.
 *
 * @returns {Real}
 *
 * @example
 * ```gml
 * var _count = eos_sessions_session_details_get_session_attribute_count(_details_id);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_details_copy_session_attribute_by_index
 * @desc **Epic Online Services Function:** [EOS_SessionDetails_CopySessionAttributeByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-session-details-copy-session-attribute-by-index)
 *
 * @param {Real} session_details_id A session details handle.
 * @param {Real} index Index in `[0, ${function.eos_sessions_session_details_get_session_attribute_count}())`.
 *
 * @returns {Struct.EpicSessionDetailsAttribute} `undefined` on an out-of-range index or copy failure.
 *
 * @example
 * ```gml
 * var _attr = eos_sessions_session_details_copy_session_attribute_by_index(_details_id, 0);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_details_copy_session_attribute_by_key
 * @desc **Epic Online Services Function:** [EOS_SessionDetails_CopySessionAttributeByKey](https://dev.epicgames.com/docs/api-ref/functions/eos-session-details-copy-session-attribute-by-key)
 *
 * @param {Real} session_details_id A session details handle.
 * @param {String} key The attribute key to look up.
 *
 * @returns {Struct.EpicSessionDetailsAttribute} `undefined` if `key` doesn't exist on this session.
 *
 * @example
 * ```gml
 * var _attr = eos_sessions_session_details_copy_session_attribute_by_key(_details_id, "gamemode");
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_active_session_get_registered_player_count
 * @desc **Epic Online Services Function:** [EOS_ActiveSession_GetRegisteredPlayerCount](https://dev.epicgames.com/docs/api-ref/functions/eos-active-session-get-registered-player-count)
 *
 * @param {Real} active_session_id An active session handle.
 *
 * @returns {Real}
 *
 * @example
 * ```gml
 * var _count = eos_sessions_active_session_get_registered_player_count(_active_id);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_active_session_get_registered_player_by_index
 * @desc **Epic Online Services Function:** [EOS_ActiveSession_GetRegisteredPlayerByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-active-session-get-registered-player-by-index)
 *
 * @param {Real} active_session_id An active session handle.
 * @param {Real} index Index in `[0, ${function.eos_sessions_active_session_get_registered_player_count}())`.
 *
 * @returns {String} An empty string on an out-of-range index.
 *
 * @example
 * ```gml
 * var _player_id = eos_sessions_active_session_get_registered_player_by_index(_active_id, 0);
 * ```
 * @function_end
 */

// ============================================================
// SessionModification setters
// ============================================================

/**
 * @function eos_sessions_session_modification_set_bucket_id
 * @desc **Epic Online Services Function:** [EOS_SessionModification_SetBucketId](https://dev.epicgames.com/docs/api-ref/functions/eos-session-modification-set-bucket-id)
 *
 * @param {Real} modification_id A session modification handle.
 * @param {String} bucket_id A non-empty bucket id.
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * eos_sessions_session_modification_set_bucket_id(_mod, "region-eu");
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_modification_set_host_address
 * @desc **Epic Online Services Function:** [EOS_SessionModification_SetHostAddress](https://dev.epicgames.com/docs/api-ref/functions/eos-session-modification-set-host-address)
 *
 * @param {Real} modification_id A session modification handle.
 * @param {String} host_address Free-form connect address for players to use after joining (your own format - EOS doesn't interpret it). Pass an empty string to clear it.
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * eos_sessions_session_modification_set_host_address(_mod, "203.0.113.4:7777");
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_modification_set_permission_level
 * @desc **Epic Online Services Function:** [EOS_SessionModification_SetPermissionLevel](https://dev.epicgames.com/docs/api-ref/functions/eos-session-modification-set-permission-level)
 *
 * @param {Real} modification_id A session modification handle.
 * @param {Constant.EpicOnlineSessionPermissionLevel} permission_level Who can find/join the session.
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * eos_sessions_session_modification_set_permission_level(_mod, EPIC_ONLINE_SESSION_PERMISSION_LEVEL.PUBLIC_ADVERTISED);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_modification_set_join_in_progress_allowed
 * @desc **Epic Online Services Function:** [EOS_SessionModification_SetJoinInProgressAllowed](https://dev.epicgames.com/docs/api-ref/functions/eos-session-modification-set-join-in-progress-allowed)
 *
 * @param {Real} modification_id A session modification handle.
 * @param {Bool} allow_join_in_progress Whether players can join after ${function.eos_sessions_start_session} has been called.
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * eos_sessions_session_modification_set_join_in_progress_allowed(_mod, true);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_modification_set_max_players
 * @desc **Epic Online Services Function:** [EOS_SessionModification_SetMaxPlayers](https://dev.epicgames.com/docs/api-ref/functions/eos-session-modification-set-max-players)
 *
 * @param {Real} modification_id A session modification handle.
 * @param {Real} max_players New player cap.
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * eos_sessions_session_modification_set_max_players(_mod, 8);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_modification_set_invites_allowed
 * @desc **Epic Online Services Function:** [EOS_SessionModification_SetInvitesAllowed](https://dev.epicgames.com/docs/api-ref/functions/eos-session-modification-set-invites-allowed)
 *
 * @param {Real} modification_id A session modification handle.
 * @param {Bool} invites_allowed Whether ${function.eos_sessions_send_invite} can be used for this session.
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * eos_sessions_session_modification_set_invites_allowed(_mod, true);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_modification_add_attribute_string
 * @desc **Epic Online Services Function:** [EOS_SessionModification_AddAttribute](https://dev.epicgames.com/docs/api-ref/functions/eos-session-modification-add-attribute)
 *
 * Sets a string-valued session attribute, searchable via ${function.eos_sessions_session_search_set_parameter}
 * when `advertisement_type` is `EPIC_SESSION_ATTRIBUTE_ADVERTISEMENT_TYPE.ADVERTISE`.
 *
 * @param {Real} modification_id A session modification handle.
 * @param {String} key Attribute key.
 * @param {String} value Attribute value.
 * @param {Constant.EpicSessionAttributeAdvertisementType} advertisement_type Whether this attribute is visible to searches or private to the session.
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * eos_sessions_session_modification_add_attribute_string(_mod, "gamemode", "deathmatch", EPIC_SESSION_ATTRIBUTE_ADVERTISEMENT_TYPE.ADVERTISE);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_modification_add_attribute_bool
 * @desc **Epic Online Services Function:** [EOS_SessionModification_AddAttribute](https://dev.epicgames.com/docs/api-ref/functions/eos-session-modification-add-attribute)
 *
 * Bool-valued equivalent of ${function.eos_sessions_session_modification_add_attribute_string}.
 *
 * @param {Real} modification_id A session modification handle.
 * @param {String} key Attribute key.
 * @param {Bool} value Attribute value.
 * @param {Constant.EpicSessionAttributeAdvertisementType} advertisement_type Whether this attribute is visible to searches or private to the session.
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * eos_sessions_session_modification_add_attribute_bool(_mod, "ranked", true, EPIC_SESSION_ATTRIBUTE_ADVERTISEMENT_TYPE.ADVERTISE);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_modification_add_attribute_double
 * @desc **Epic Online Services Function:** [EOS_SessionModification_AddAttribute](https://dev.epicgames.com/docs/api-ref/functions/eos-session-modification-add-attribute)
 *
 * Numeric-valued equivalent of ${function.eos_sessions_session_modification_add_attribute_string}.
 *
 * @param {Real} modification_id A session modification handle.
 * @param {String} key Attribute key.
 * @param {Real} value Attribute value.
 * @param {Constant.EpicSessionAttributeAdvertisementType} advertisement_type Whether this attribute is visible to searches or private to the session.
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * eos_sessions_session_modification_add_attribute_double(_mod, "skill_rating", 1500, EPIC_SESSION_ATTRIBUTE_ADVERTISEMENT_TYPE.ADVERTISE);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_session_modification_remove_attribute
 * @desc **Epic Online Services Function:** [EOS_SessionModification_RemoveAttribute](https://dev.epicgames.com/docs/api-ref/functions/eos-session-modification-remove-attribute)
 *
 * @param {Real} modification_id A session modification handle.
 * @param {String} key The attribute key to remove.
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * eos_sessions_session_modification_remove_attribute(_mod, "gamemode");
 * ```
 * @function_end
 */

// ============================================================
// Invites
// ============================================================

/**
 * @function eos_sessions_send_invite
 * @desc **Epic Online Services Function:** [EOS_Sessions_SendInvite](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-send-invite)
 *
 * Sends a session invite. Requires `invites_allowed` to be set on the session (see
 * ${function.eos_sessions_session_modification_set_invites_allowed}).
 *
 * @param {String} session_name The local session name.
 * @param {String} local_user_id The inviting Product User ID.
 * @param {String} target_user_id The invited Product User ID.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @member {Struct.EpicSessionsSendInviteCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_sessions_send_invite("MySession", local_user_id, target_user_id, function(_result) {
 *     show_debug_message($"Invite result: {_result.result_code}");
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_reject_invite
 * @desc **Epic Online Services Function:** [EOS_Sessions_RejectInvite](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-reject-invite)
 *
 * @param {String} local_user_id The Product User ID rejecting the invite.
 * @param {String} invite_id The invite id, typically from ${struct.EpicSessionsSessionInviteReceivedCallbackInfo}.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @member {Struct.EpicSessionsRejectInviteCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_sessions_reject_invite(local_user_id, _invite_id, function(_result) {
 *     show_debug_message($"Reject result: {_result.result_code}");
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_query_invites
 * @desc **Epic Online Services Function:** [EOS_Sessions_QueryInvites](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-query-invites)
 *
 * Refreshes the local cache of pending invites for a user, read afterward via
 * ${function.eos_sessions_get_invite_count}/${function.eos_sessions_get_invite_id_by_index}.
 *
 * @param {String} local_user_id The Product User ID to query invites for.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @member {Struct.EpicSessionsQueryInvitesCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_sessions_query_invites(local_user_id, function(_result) {
 *     var _n = eos_sessions_get_invite_count(_result.local_user_id);
 *     show_debug_message($"{_n} pending invites");
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_get_invite_count
 * @desc **Epic Online Services Function:** [EOS_Sessions_GetInviteCount](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-get-invite-count)
 *
 * @param {String} local_user_id The Product User ID to check.
 *
 * @returns {Real}
 *
 * @example
 * ```gml
 * var _n = eos_sessions_get_invite_count(local_user_id);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_get_invite_id_by_index
 * @desc **Epic Online Services Function:** [EOS_Sessions_GetInviteIdByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-get-invite-id-by-index)
 *
 * @param {String} local_user_id The Product User ID that owns the invite.
 * @param {Real} index Index in `[0, ${function.eos_sessions_get_invite_count}())`.
 *
 * @returns {String} An empty string on an out-of-range index.
 *
 * @example
 * ```gml
 * var _invite_id = eos_sessions_get_invite_id_by_index(local_user_id, 0);
 * ```
 * @function_end
 */

// ============================================================
// Notifications
// ============================================================

/**
 * @function eos_sessions_add_notify_session_invite_received
 * @desc **Epic Online Services Function:** [EOS_Sessions_AddNotifySessionInviteReceived](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-add-notify-session-invite-received)
 *
 * Registers to be notified when a session invite is received. Call ${function.eos_sessions_remove_notify_session_invite_received}
 * with the returned id when you no longer need it.
 *
 * @param {Function} [callback] Called each time an invite is received.
 *
 * @returns {Real} A notification id (`0` on failure).
 *
 * @event callback
 * @member {Struct.EpicSessionsSessionInviteReceivedCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * global.notify_id = eos_sessions_add_notify_session_invite_received(function(_result) {
 *     var _details_id = eos_sessions_copy_session_handle_by_invite_id(_result.invite_id);
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_remove_notify_session_invite_received
 * @desc **Epic Online Services Function:** [EOS_Sessions_RemoveNotifySessionInviteReceived](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-remove-notify-session-invite-received)
 *
 * @param {Real} notification_id A notification id from ${function.eos_sessions_add_notify_session_invite_received}.
 *
 * @example
 * ```gml
 * eos_sessions_remove_notify_session_invite_received(global.notify_id);
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_add_notify_session_invite_accepted
 * @desc **Epic Online Services Function:** [EOS_Sessions_AddNotifySessionInviteAccepted](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-add-notify-session-invite-accepted)
 *
 * Registers to be notified when a session invite this client sent is accepted.
 *
 * @param {Function} [callback] Called each time a sent invite is accepted.
 *
 * @returns {Real} A notification id (`0` on failure).
 *
 * @event callback
 * @member {Struct.EpicSessionsSessionInviteAcceptedCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_sessions_add_notify_session_invite_accepted(function(_result) {
 *     show_debug_message($"{_result.target_user_id} accepted our invite");
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_remove_notify_session_invite_accepted
 * @desc **Epic Online Services Function:** [EOS_Sessions_RemoveNotifySessionInviteAccepted](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-remove-notify-session-invite-accepted)
 *
 * @param {Real} notification_id A notification id from ${function.eos_sessions_add_notify_session_invite_accepted}.
 *
 * @function_end
 */

/**
 * @function eos_sessions_add_notify_join_session_accepted
 * @desc **Epic Online Services Function:** [EOS_Sessions_AddNotifyJoinSessionAccepted](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-add-notify-join-session-accepted)
 *
 * Registers to be notified when the local user accepts a session join request from the Epic overlay.
 * Use ${function.eos_sessions_copy_session_handle_by_ui_event_id} to look up the session, join it, then
 * call ${function.eos_ui_acknowledge_event_id} with `ui_event_id` once the join resolves.
 *
 * [[Warning: Failing to acknowledge `ui_event_id` leaves the social overlay's join UI stuck waiting.]]
 *
 * @param {Function} [callback] Called each time a join is accepted from the overlay.
 *
 * @returns {Real} A notification id (`0` on failure).
 *
 * @event callback
 * @member {Struct.EpicSessionsJoinSessionAcceptedCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_sessions_add_notify_join_session_accepted(function(_result) {
 *     var _details_id = eos_sessions_copy_session_handle_by_ui_event_id(_result.ui_event_id);
 *     eos_sessions_join_session("MySession", _details_id, local_user_id, true, function(_join_result) {
 *         eos_ui_acknowledge_event_id(_result.ui_event_id, _join_result.result_code);
 *     });
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_sessions_remove_notify_join_session_accepted
 * @desc **Epic Online Services Function:** [EOS_Sessions_RemoveNotifyJoinSessionAccepted](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-remove-notify-join-session-accepted)
 *
 * @param {Real} notification_id A notification id from ${function.eos_sessions_add_notify_join_session_accepted}.
 *
 * @function_end
 */

/**
 * @function eos_sessions_add_notify_session_invite_rejected
 * @desc **Epic Online Services Function:** [EOS_Sessions_AddNotifySessionInviteRejected](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-add-notify-session-invite-rejected)
 *
 * Registers to be notified when a session invite this client sent is rejected.
 *
 * @param {Function} [callback] Called each time a sent invite is rejected.
 *
 * @returns {Real} A notification id (`0` on failure).
 *
 * @event callback
 * @member {Struct.EpicSessionsSessionInviteRejectedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_sessions_remove_notify_session_invite_rejected
 * @desc **Epic Online Services Function:** [EOS_Sessions_RemoveNotifySessionInviteRejected](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-remove-notify-session-invite-rejected)
 *
 * @param {Real} notification_id A notification id from ${function.eos_sessions_add_notify_session_invite_rejected}.
 *
 * @function_end
 */

/**
 * @function eos_sessions_add_notify_leave_session_requested
 * @desc **Epic Online Services Function:** [EOS_Sessions_AddNotifyLeaveSessionRequested](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-add-notify-leave-session-requested)
 *
 * Registers to be notified when the platform (e.g. the Epic overlay, or a console's system UI) requests
 * that the local user leave a session. Respond by calling ${function.eos_sessions_destroy_session} (if
 * you own the session) or otherwise removing the user from it.
 *
 * @param {Function} [callback] Called each time a leave is requested.
 *
 * @returns {Real} A notification id (`0` on failure).
 *
 * @event callback
 * @member {Struct.EpicSessionsLeaveSessionRequestedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_sessions_remove_notify_leave_session_requested
 * @desc **Epic Online Services Function:** [EOS_Sessions_RemoveNotifyLeaveSessionRequested](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-remove-notify-leave-session-requested)
 *
 * @param {Real} notification_id A notification id from ${function.eos_sessions_add_notify_leave_session_requested}.
 *
 * @function_end
 */

/**
 * @function eos_sessions_add_notify_send_session_native_invite_requested
 * @desc **Epic Online Services Function:** [EOS_Sessions_AddNotifySendSessionNativeInviteRequested](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-add-notify-send-session-native-invite-requested)
 *
 * Registers to be notified when the local platform's own native invite UI (e.g. a console's system
 * invite flow) is used to invite someone to a session, so you can mirror it into an EOS session invite.
 *
 * [[Warning: You must call ${function.eos_ui_acknowledge_event_id} with `ui_event_id` once you've handled the request, or the native invite UI is left waiting.]]
 *
 * @param {Function} [callback] Called each time a native invite is requested.
 *
 * @returns {Real} A notification id (`0` on failure).
 *
 * @event callback
 * @member {Struct.EpicSessionsSendSessionNativeInviteRequestedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_sessions_remove_notify_send_session_native_invite_requested
 * @desc **Epic Online Services Function:** [EOS_Sessions_RemoveNotifySendSessionNativeInviteRequested](https://dev.epicgames.com/docs/api-ref/functions/eos-sessions-remove-notify-send-session-native-invite-requested)
 *
 * @param {Real} notification_id A notification id from ${function.eos_sessions_add_notify_send_session_native_invite_requested}.
 *
 * @function_end
 */

// ============================================================
// Structs
// ============================================================

/**
 * @struct EpicSessionsUpdateSessionCallbackInfo
 * @desc Result of ${function.eos_sessions_update_session}.
 * @member {Constant.EpicResult} result_code
 * @member {String} session_name
 * @member {String} session_id
 * @struct_end
 */

/**
 * @struct EpicSessionsDestroySessionCallbackInfo
 * @desc Result of ${function.eos_sessions_destroy_session}.
 * @member {Constant.EpicResult} result_code
 * @struct_end
 */

/**
 * @struct EpicSessionsStartSessionCallbackInfo
 * @desc Result of ${function.eos_sessions_start_session}.
 * @member {Constant.EpicResult} result_code
 * @struct_end
 */

/**
 * @struct EpicSessionsEndSessionCallbackInfo
 * @desc Result of ${function.eos_sessions_end_session}.
 * @member {Constant.EpicResult} result_code
 * @struct_end
 */

/**
 * @struct EpicSessionsJoinSessionCallbackInfo
 * @desc Result of ${function.eos_sessions_join_session}.
 * @member {Constant.EpicResult} result_code
 * @struct_end
 */

/**
 * @struct EpicSessionsRegisterPlayersCallbackInfo
 * @desc Result of ${function.eos_sessions_register_players}.
 * @member {Constant.EpicResult} result_code
 * @member {Array[String]} registered_players Players successfully registered.
 * @member {Array[String]} sanctioned_players Players rejected due to an active ${module.sanctions} sanction.
 * @struct_end
 */

/**
 * @struct EpicSessionsUnregisterPlayersCallbackInfo
 * @desc Result of ${function.eos_sessions_unregister_players}.
 * @member {Constant.EpicResult} result_code
 * @member {Array[String]} unregistered_players
 * @struct_end
 */

/**
 * @struct EpicSessionsFindCallbackInfo
 * @desc Result of ${function.eos_sessions_session_search_find}.
 * @member {Constant.EpicResult} result_code
 * @struct_end
 */

/**
 * @struct EpicSessionDetailsInfo
 * @desc Returned by ${function.eos_sessions_session_details_copy_info}.
 * @member {String} session_id
 * @member {String} host_address
 * @member {String} owner_user_id
 * @member {Real} num_open_public_connections
 * @member {String} owner_server_client_id
 * @member {String} bucket_id The main indexed parameter for this session, e.g. `"Region:GameMode"`.
 * @member {Real} num_public_connections Total number of players allowed in the session.
 * @member {Bool} allow_join_in_progress Whether players may join while the session is in progress.
 * @member {Constant.EpicOnlineSessionPermissionLevel} permission_level Who is allowed to find and join the session.
 * @member {Bool} invites_allowed Whether players are allowed to send invites for the session.
 * @member {Bool} sanctions_enabled Whether sanctioned players are rejected when they try to join.
 * @member {Real} allowed_platform_ids_count Number of entries in `allowed_platform_ids`.
 * @member {Array[Real]} allowed_platform_ids Platform IDs allowed to register with the session. Empty means unrestricted.
 * @struct_end
 */

/**
 * @struct EpicActiveSessionInfo
 * @desc Returned by ${function.eos_sessions_active_session_copy_info}.
 * @member {String} session_name
 * @member {String} local_user_id
 * @member {String} session_id
 * @member {String} bucket_id
 * @member {String} owner_user_id Empty if the session is owned by a dedicated server rather than a user.
 * @member {String} host_address
 * @member {Constant.EpicOnlineSessionState} state Current state of the session.
 * @struct_end
 */

/**
 * @struct EpicSessionsSessionInviteReceivedCallbackInfo
 * @desc Fired by ${function.eos_sessions_add_notify_session_invite_received}.
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @member {String} invite_id
 * @struct_end
 */

/**
 * @struct EpicSessionsSessionInviteAcceptedCallbackInfo
 * @desc Fired by ${function.eos_sessions_add_notify_session_invite_accepted}.
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @member {String} invite_id
 * @struct_end
 */

/**
 * @struct EpicSessionsJoinSessionAcceptedCallbackInfo
 * @desc Fired by ${function.eos_sessions_add_notify_join_session_accepted}.
 * @member {Real} ui_event_id Pass to ${function.eos_sessions_copy_session_handle_by_ui_event_id} and, once the join resolves, to ${function.eos_ui_acknowledge_event_id}.
 * @struct_end
 */

/**
 * @struct EpicSessionDetailsAttribute
 * @desc A single session attribute, returned by the `session_details_copy_session_attribute_*` functions.
 * @member {String} key
 * @member {String} value String form of the value regardless of `value_type` (numeric/bool values are formatted as strings).
 * @member {Constant.EpicAttributeType} value_type The attribute's real data type.
 * @member {Constant.EpicSessionAttributeAdvertisementType} advertisement_type
 * @struct_end
 */

/**
 * @struct EpicSessionsSendInviteCallbackInfo
 * @desc Result of ${function.eos_sessions_send_invite}.
 * @member {Constant.EpicResult} result_code
 * @struct_end
 */

/**
 * @struct EpicSessionsRejectInviteCallbackInfo
 * @desc Result of ${function.eos_sessions_reject_invite}.
 * @member {Constant.EpicResult} result_code
 * @struct_end
 */

/**
 * @struct EpicSessionsQueryInvitesCallbackInfo
 * @desc Result of ${function.eos_sessions_query_invites}.
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end
 */

/**
 * @struct EpicSessionsSessionInviteRejectedCallbackInfo
 * @desc Fired by ${function.eos_sessions_add_notify_session_invite_rejected}.
 * @member {String} invite_id
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @member {String} session_id
 * @struct_end
 */

/**
 * @struct EpicSessionsLeaveSessionRequestedCallbackInfo
 * @desc Fired by ${function.eos_sessions_add_notify_leave_session_requested}.
 * @member {String} local_user_id
 * @member {String} session_name
 * @struct_end
 */

/**
 * @struct EpicSessionsSendSessionNativeInviteRequestedCallbackInfo
 * @desc Fired by ${function.eos_sessions_add_notify_send_session_native_invite_requested}.
 * @member {Real} ui_event_id Pass to ${function.eos_ui_acknowledge_event_id} once handled.
 * @member {String} local_user_id
 * @member {String} session_id
 * @struct_end
 */

// ============================================================
// Constants
// ============================================================

/**
 * @const EpicOnlineSessionState
 * @desc **Epic Online Services Enum:** [EOS_EOnlineSessionState](https://dev.epicgames.com/docs/api-ref/enums/eos-e-online-session-state)
 *
 * The lifecycle state of a session.
 *
 * @member NoSession
 * @member Creating
 * @member Pending
 * @member Starting
 * @member InProgress
 * @member Ending
 * @member Ended
 * @member Destroying
 * @const_end
 */

/**
 * @const EpicSessionAttributeAdvertisementType
 * @desc **Epic Online Services Enum:** [EOS_ESessionAttributeAdvertisementType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-session-attribute-advertisement-type)
 *
 * @member DontAdvertise The attribute is stored on the session but not searchable.
 * @member Advertise The attribute is included in session search results and can be filtered on.
 * @const_end
 */

/**
 * @const EpicOnlineSessionPermissionLevel
 * @desc **Epic Online Services Enum:** [EOS_EOnlineSessionPermissionLevel](https://dev.epicgames.com/docs/api-ref/enums/eos-e-online-session-permission-level)
 *
 * @member PublicAdvertised Anyone can find and join the session.
 * @member JoinViaPresence Only friends who can see the owner's presence can join.
 * @member InviteOnly Only players who receive an explicit invite can join.
 * @const_end
 */

/**
 * @module sessions
 * @title Sessions
 * @desc **Epic Online Services Interface:** [Sessions Interface](https://dev.epicgames.com/docs/game-services/eos-sessions-interface)
 *
 * The [Sessions Interface](https://dev.epicgames.com/docs/game-services/eos-sessions-interface) lets
 * players create, search for, join, and leave online game sessions - the general-purpose matchmaking
 * building block for match-based games. If you need a persistent group of players who stick together
 * across matches, see ${module.lobbies} instead.
 *
 * [[Note: A session is built/modified through a "session modification" handle: create one with ${function.eos_sessions_create_session_modification}, configure it with the `eos_sessions_session_modification_*` setters, then publish it with ${function.eos_sessions_update_session}.]]
 *
 * @section_func
 * @desc Session lifecycle:
 * @ref eos_sessions_create_session_modification
 * @ref eos_sessions_session_modification_release
 * @ref eos_sessions_update_session
 * @ref eos_sessions_destroy_session
 * @ref eos_sessions_start_session
 * @ref eos_sessions_end_session
 *
 * @desc Joining and player registration:
 * @ref eos_sessions_join_session
 * @ref eos_sessions_register_players
 * @ref eos_sessions_unregister_players
 *
 * @desc Session search:
 * @ref eos_sessions_create_session_search
 * @ref eos_sessions_session_search_release
 * @ref eos_sessions_session_search_set_session_id
 * @ref eos_sessions_session_search_set_target_user_id
 * @ref eos_sessions_session_search_set_parameter
 * @ref eos_sessions_session_search_remove_parameter
 * @ref eos_sessions_session_search_find
 * @ref eos_sessions_session_search_get_search_result_count
 * @ref eos_sessions_session_search_copy_search_result_by_index
 *
 * @desc Session details / active session accessors:
 * @ref eos_sessions_session_details_release
 * @ref eos_sessions_copy_active_session_handle
 * @ref eos_sessions_active_session_release
 * @ref eos_sessions_active_session_copy_info
 * @ref eos_sessions_copy_session_handle_by_invite_id
 * @ref eos_sessions_copy_session_handle_by_ui_event_id
 * @ref eos_sessions_session_details_copy_info
 * @ref eos_sessions_session_details_get_session_attribute_count
 * @ref eos_sessions_session_details_copy_session_attribute_by_index
 * @ref eos_sessions_session_details_copy_session_attribute_by_key
 * @ref eos_sessions_active_session_get_registered_player_count
 * @ref eos_sessions_active_session_get_registered_player_by_index
 *
 * @desc SessionModification setters:
 * @ref eos_sessions_session_modification_set_bucket_id
 * @ref eos_sessions_session_modification_set_host_address
 * @ref eos_sessions_session_modification_set_permission_level
 * @ref eos_sessions_session_modification_set_join_in_progress_allowed
 * @ref eos_sessions_session_modification_set_max_players
 * @ref eos_sessions_session_modification_set_invites_allowed
 * @ref eos_sessions_session_modification_add_attribute_string
 * @ref eos_sessions_session_modification_add_attribute_bool
 * @ref eos_sessions_session_modification_add_attribute_double
 * @ref eos_sessions_session_modification_remove_attribute
 *
 * @desc Invites:
 * @ref eos_sessions_send_invite
 * @ref eos_sessions_reject_invite
 * @ref eos_sessions_query_invites
 * @ref eos_sessions_get_invite_count
 * @ref eos_sessions_get_invite_id_by_index
 *
 * @desc Notifications:
 * @ref eos_sessions_add_notify_session_invite_received
 * @ref eos_sessions_remove_notify_session_invite_received
 * @ref eos_sessions_add_notify_session_invite_accepted
 * @ref eos_sessions_remove_notify_session_invite_accepted
 * @ref eos_sessions_add_notify_join_session_accepted
 * @ref eos_sessions_remove_notify_join_session_accepted
 * @ref eos_sessions_add_notify_session_invite_rejected
 * @ref eos_sessions_remove_notify_session_invite_rejected
 * @ref eos_sessions_add_notify_leave_session_requested
 * @ref eos_sessions_remove_notify_leave_session_requested
 * @ref eos_sessions_add_notify_send_session_native_invite_requested
 * @ref eos_sessions_remove_notify_send_session_native_invite_requested
 * @section_end
 *
 * @section_struct
 * @ref EpicSessionsUpdateSessionCallbackInfo
 * @ref EpicSessionsDestroySessionCallbackInfo
 * @ref EpicSessionsStartSessionCallbackInfo
 * @ref EpicSessionsEndSessionCallbackInfo
 * @ref EpicSessionsJoinSessionCallbackInfo
 * @ref EpicSessionsRegisterPlayersCallbackInfo
 * @ref EpicSessionsUnregisterPlayersCallbackInfo
 * @ref EpicSessionsFindCallbackInfo
 * @ref EpicSessionDetailsInfo
 * @ref EpicActiveSessionInfo
 * @ref EpicSessionsSessionInviteReceivedCallbackInfo
 * @ref EpicSessionsSessionInviteAcceptedCallbackInfo
 * @ref EpicSessionsJoinSessionAcceptedCallbackInfo
 * @ref EpicSessionDetailsAttribute
 * @ref EpicSessionsSendInviteCallbackInfo
 * @ref EpicSessionsRejectInviteCallbackInfo
 * @ref EpicSessionsQueryInvitesCallbackInfo
 * @ref EpicSessionsSessionInviteRejectedCallbackInfo
 * @ref EpicSessionsLeaveSessionRequestedCallbackInfo
 * @ref EpicSessionsSendSessionNativeInviteRequestedCallbackInfo
 * @section_end
 *
 * @section_const
 * @ref EpicOnlineSessionState
 * @ref EpicSessionAttributeAdvertisementType
 * @ref EpicOnlineSessionPermissionLevel
 * @section_end
 *
 * @module_end
 */
