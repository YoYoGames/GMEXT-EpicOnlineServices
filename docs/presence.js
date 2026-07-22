// Structs

/**
 * @struct EpicPresenceDataRecord
 * @desc A single free-form key/value pair attached to a user's presence.
 *
 * @member {String} key
 * @member {String} value
 *
 * @struct_end
 */

/**
 * @struct EpicPresenceInfo
 * @desc A snapshot of another user's presence, as returned by ${function.eos_presence_copy_presence}.
 *
 * @member {String} user_id The Epic Account ID this presence info belongs to.
 * @member {Constant.EpicPresenceStatus} status
 * @member {String} product_id The Epic product ID that owns this presence.
 * @member {String} product_version
 * @member {String} platform The platform the user is currently playing on.
 * @member {String} product_name
 * @member {String} integrated_platform The integrated platform (if any) the user is playing through.
 * @member {String} rich_text The rich-text presence string, as set by ${function.eos_presence_modification_set_raw_rich_text}.
 * @member {Real} records_count The number of entries in `records`.
 * @member {Array[Struct.EpicPresenceDataRecord]} records The free-form key/value data attached to this presence, as set by ${function.eos_presence_modification_set_data}.
 *
 * @struct_end
 */

/**
 * @struct EpicPresenceQueryPresenceCallbackInfo
 * @desc Passed to the callback of ${function.eos_presence_query_presence}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the query completed.
 * @member {String} local_user_id The Epic Account ID that requested the query.
 * @member {String} target_user_id The Epic Account ID whose presence was queried.
 *
 * @struct_end
 */

/**
 * @struct EpicPresenceSetPresenceCallbackInfo
 * @desc Passed to the callback of ${function.eos_presence_set_presence}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the presence update was applied.
 * @member {String} local_user_id The Epic Account ID whose presence was updated.
 *
 * @struct_end
 */

/**
 * @struct EpicPresenceChangedCallbackInfo
 * @desc Passed to the callback of ${function.eos_presence_add_notify_on_presence_changed} whenever a followed user's presence changes.
 *
 * @member {String} local_user_id The local Epic Account ID that is following `presence_user_id`.
 * @member {String} presence_user_id The Epic Account ID whose presence changed. Call ${function.eos_presence_copy_presence} to read the new value.
 *
 * @struct_end
 */

/**
 * @struct EpicPresenceJoinGameAcceptedCallbackInfo
 * @desc Passed to the callback of ${function.eos_presence_add_notify_join_game_accepted}, fired when the local user accepts a "Join Game" prompt from the social overlay.
 *
 * @member {String} join_info The join string previously set on the presence (game-defined format, e.g. a lobby/session ID).
 * @member {String} local_user_id The local Epic Account ID that accepted the join.
 * @member {String} target_user_id The Epic Account ID of the friend being joined.
 * @member {Real} ui_event_id Must be passed to ${function.eos_ui_acknowledge_event_id} once the join has been handled, or the social overlay UI hangs.
 *
 * @struct_end
 */


// Functions

/**
 * @function eos_presence_query_presence
 * @desc **Epic Online Services Function:** [EOS_Presence_QueryPresence](https://dev.epicgames.com/docs/api-ref/functions/eos-presence-query-presence)
 *
 * Queries a user's presence and caches it locally. Once the callback reports success, read the result with ${function.eos_presence_copy_presence}.
 *
 * @param {String} local_user_id The Epic Account ID of the user making the request.
 * @param {String} target_user_id The Epic Account ID whose presence should be queried.
 * @param {Function} [callback] Called once the query completes.
 *
 * @event callback
 * @desc Fired once with the query result.
 * @member {Struct.EpicPresenceQueryPresenceCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_presence_query_presence(my_account_id, friend_account_id, function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         var _info = eos_presence_copy_presence(my_account_id, friend_account_id);
 *         show_debug_message($"Friend status: {_info.status}");
 *     }
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_presence_has_presence
 * @desc **Epic Online Services Function:** [EOS_Presence_HasPresence](https://dev.epicgames.com/docs/api-ref/functions/eos-presence-has-presence)
 *
 * Checks whether presence info for the target user is already cached locally, without making a network request. Use ${function.eos_presence_query_presence} first if this returns `false`.
 *
 * @param {String} local_user_id The Epic Account ID of the user making the request.
 * @param {String} target_user_id The Epic Account ID to check.
 *
 * @returns {Bool}
 *
 * @function_end
 */

/**
 * @function eos_presence_copy_presence
 * @desc **Epic Online Services Function:** [EOS_Presence_CopyPresence](https://dev.epicgames.com/docs/api-ref/functions/eos-presence-copy-presence)
 *
 * Reads the locally cached presence info for a user, previously fetched with ${function.eos_presence_query_presence}.
 *
 * [[Note: Returns `undefined` if no presence info is cached yet for `target_user_id` — call ${function.eos_presence_query_presence} first.]]
 *
 * @param {String} local_user_id The Epic Account ID of the user making the request.
 * @param {String} target_user_id The Epic Account ID whose cached presence should be read.
 *
 * @returns {Struct.EpicPresenceInfo}
 *
 * @function_end
 */

/**
 * @function eos_presence_create_presence_modification
 * @desc **Epic Online Services Function:** [EOS_Presence_CreatePresenceModification](https://dev.epicgames.com/docs/api-ref/functions/eos-presence-create-presence-modification)
 *
 * Creates a presence modification handle for the local user. Use the `eos_presence_modification_*` functions to build up the change, then apply it with ${function.eos_presence_set_presence}.
 *
 * [[Note: Returns `0` on failure.]]
 *
 * @param {String} local_user_id The Epic Account ID to build a presence modification for.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_presence_modification_release
 * @desc **Epic Online Services Function:** [EOS_PresenceModification_Release](https://dev.epicgames.com/docs/api-ref/functions/eos-presence-modification-release)
 *
 * Releases a presence modification handle created by ${function.eos_presence_create_presence_modification}. Call this if you decide not to apply the modification.
 *
 * [[Note: You do NOT need to call this after a successful ${function.eos_presence_set_presence} — the handle is released automatically once the presence update has been submitted.]]
 *
 * @param {Real} modification_id The handle returned by ${function.eos_presence_create_presence_modification}.
 *
 * @function_end
 */

/**
 * @function eos_presence_modification_set_status
 * @desc **Epic Online Services Function:** [EOS_PresenceModification_SetStatus](https://dev.epicgames.com/docs/api-ref/functions/eos-presence-modification-set-status)
 *
 * Sets the online status on a presence modification handle.
 *
 * @param {Real} modification_id The handle returned by ${function.eos_presence_create_presence_modification}.
 * @param {Constant.EpicPresenceStatus} status
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_presence_modification_set_raw_rich_text
 * @desc **Epic Online Services Function:** [EOS_PresenceModification_SetRawRichText](https://dev.epicgames.com/docs/api-ref/functions/eos-presence-modification-set-raw-rich-text)
 *
 * Sets the rich-text presence string on a presence modification handle.
 *
 * @param {Real} modification_id The handle returned by ${function.eos_presence_create_presence_modification}.
 * @param {String} rich_text
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_presence_modification_set_data
 * @desc **Epic Online Services Function:** [EOS_PresenceModification_SetData](https://dev.epicgames.com/docs/api-ref/functions/eos-presence-modification-set-data)
 *
 * Sets a single free-form key/value data record on a presence modification handle. Call this once per key you want to set.
 *
 * @param {Real} modification_id The handle returned by ${function.eos_presence_create_presence_modification}.
 * @param {String} key
 * @param {String} value
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_presence_modification_delete_data
 * @desc **Epic Online Services Function:** [EOS_PresenceModification_DeleteData](https://dev.epicgames.com/docs/api-ref/functions/eos-presence-modification-delete-data)
 *
 * Removes a single key previously set with ${function.eos_presence_modification_set_data}.
 *
 * @param {Real} modification_id The handle returned by ${function.eos_presence_create_presence_modification}.
 * @param {String} key
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_presence_set_presence
 * @desc **Epic Online Services Function:** [EOS_Presence_SetPresence](https://dev.epicgames.com/docs/api-ref/functions/eos-presence-set-presence)
 *
 * Submits a presence modification built with `eos_presence_modification_*` functions.
 *
 * [[Warning: `modification_id` is released internally as soon as this call is made, whether or not it eventually succeeds — don't call ${function.eos_presence_modification_release} on it afterward, and don't reuse the handle.]]
 *
 * @param {String} local_user_id The Epic Account ID whose presence is being updated.
 * @param {Real} modification_id The handle returned by ${function.eos_presence_create_presence_modification}, after being built up with `eos_presence_modification_*` calls.
 * @param {Function} [callback] Called once the update completes.
 *
 * @event callback
 * @desc Fired once with the result of the update.
 * @member {Struct.EpicPresenceSetPresenceCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_presence_add_notify_on_presence_changed
 * @desc **Epic Online Services Function:** [EOS_Presence_AddNotifyOnPresenceChanged](https://dev.epicgames.com/docs/api-ref/functions/eos-presence-add-notify-on-presence-changed)
 *
 * Registers to be notified whenever a followed user's presence changes. Call ${function.eos_presence_remove_notify_on_presence_changed} with the returned ID when you no longer need it.
 *
 * [[Note: Returns `0` if registration failed.]]
 *
 * @param {Function} [callback] Called every time a followed user's presence changes.
 *
 * @returns {Real}
 *
 * @event callback
 * @desc Fired every time a followed user's presence changes, for as long as this notification stays registered.
 * @member {Struct.EpicPresenceChangedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_presence_remove_notify_on_presence_changed
 * @desc **Epic Online Services Function:** [EOS_Presence_RemoveNotifyOnPresenceChanged](https://dev.epicgames.com/docs/api-ref/functions/eos-presence-remove-notify-on-presence-changed)
 *
 * Unregisters a notification previously registered with ${function.eos_presence_add_notify_on_presence_changed}.
 *
 * @param {Real} notification_id
 *
 * @function_end
 */

/**
 * @function eos_presence_add_notify_join_game_accepted
 * @desc **Epic Online Services Function:** [EOS_Presence_AddNotifyJoinGameAccepted](https://dev.epicgames.com/docs/api-ref/functions/eos-presence-add-notify-join-game-accepted)
 *
 * Registers to be notified when the local user accepts a "Join Game" prompt from the social overlay (e.g. from a friend's rich presence). Call ${function.eos_presence_remove_notify_join_game_accepted} with the returned ID when you no longer need it.
 *
 * [[Important: Register this as soon as possible after login — a join accepted before this notification is registered is missed entirely.]]
 *
 * [[Note: Returns `0` if registration failed.]]
 *
 * @param {Function} [callback] Called every time a "Join Game" prompt is accepted.
 *
 * @returns {Real}
 *
 * @event callback
 * @desc Fired every time the local user accepts a "Join Game" prompt, for as long as this notification stays registered. You MUST call ${function.eos_ui_acknowledge_event_id} with the result's `ui_event_id` once you've handled it.
 * @member {Struct.EpicPresenceJoinGameAcceptedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_presence_remove_notify_join_game_accepted
 * @desc **Epic Online Services Function:** [EOS_Presence_RemoveNotifyJoinGameAccepted](https://dev.epicgames.com/docs/api-ref/functions/eos-presence-remove-notify-join-game-accepted)
 *
 * Unregisters a notification previously registered with ${function.eos_presence_add_notify_join_game_accepted}.
 *
 * @param {Real} notification_id
 *
 * @function_end
 */


/**
 * @module presence
 * @title Presence
 * @desc **Epic Online Services Interface:** [Presence Interface](https://dev.epicgames.com/docs/game-services/eos-presence-interface)
 *
 * With the Presence Interface, an application can advertise its local player's status, known as presence, and query the presence of other players online. An application may also advertise transient key/value data to share more detailed information about the local player's state, plus a "Join Game" string other players can use to join them. Users can only receive presence information about other users with whom they are friends.
 *
 * [[Important: To use the Presence Interface, your product must have **Epic Account Services** (EAS) active, and must obtain user consent to access **Online Presence** data. You can activate EAS on the [Developer Portal](https://dev.epicgames.com/docs/dev-portal). Without EAS and user consent, you can still initialize the EOS SDK and the Presence Interface, but every Presence Interface call to the back-end service fails.]]
 *
 * @section_func
 * @desc Provided functions:
 *
 * @ref eos_presence_query_presence
 * @ref eos_presence_has_presence
 * @ref eos_presence_copy_presence
 * @ref eos_presence_create_presence_modification
 * @ref eos_presence_modification_release
 * @ref eos_presence_modification_set_status
 * @ref eos_presence_modification_set_raw_rich_text
 * @ref eos_presence_modification_set_data
 * @ref eos_presence_modification_delete_data
 * @ref eos_presence_set_presence
 * @ref eos_presence_add_notify_on_presence_changed
 * @ref eos_presence_remove_notify_on_presence_changed
 * @ref eos_presence_add_notify_join_game_accepted
 * @ref eos_presence_remove_notify_join_game_accepted
 *
 * @section_end
 *
 * @section_struct
 * @desc These are the structs used by this API:
 *
 * @ref EpicPresenceDataRecord
 * @ref EpicPresenceInfo
 * @ref EpicPresenceQueryPresenceCallbackInfo
 * @ref EpicPresenceSetPresenceCallbackInfo
 * @ref EpicPresenceChangedCallbackInfo
 * @ref EpicPresenceJoinGameAcceptedCallbackInfo
 *
 * @section_end
 *
 * @section_const
 * @desc These are the constants used by this API:
 *
 * @ref EpicPresenceStatus
 *
 * @section_end
 *
 * @module_end
 */

// Constants

/**
 * @const EpicPresenceStatus
 * @desc **Epic Online Services Enum:** [EOS_Presence_EStatus](https://dev.epicgames.com/docs/api-ref/enums/eos-e-presence-status)
 *
 * @member Offline
 * @member Online
 * @member Away
 * @member ExtendedAway
 * @member DoNotDisturb
 *
 * @const_end
 */
