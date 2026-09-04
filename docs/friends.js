// Functions

/**
 * @function eos_friends_query_friends
 * @desc **Epic Online Services Function:** [EOS_Friends_QueryFriends](https://dev.epicgames.com/docs/api-ref/functions/eos-friends-query-friends)
 *
 * Starts an asynchronous task that reads the local user's friends list from the backend and caches it
 * locally. You must call this at least once for a given `local_user_id` before ${function.eos_friends_get_friends_count}/${function.eos_friends_get_friend_at_index}/${function.eos_friends_get_status} return anything meaningful for that user.
 *
 * @param {String} local_user_id The Epic Account ID of the local, logged-in user whose friends list is being queried.
 * @param {Function} [callback] Called once with the result. See the `callback` event below.
 *
 * @event callback
 * @desc Fires once, after the friends list has been retrieved (or the query has failed).
 * @member {Struct.EpicFriendsQueryFriendsCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_friends_query_friends(local_user_id, function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         var _count = eos_friends_get_friends_count(_result.local_user_id);
 *         show_debug_message($"Friend count: {_count}");
 *     }
 * });
 * ```
 * The above code queries the local user's friends list, then reads the cached friend count once the query completes.
 * @function_end
 */

/**
 * @function eos_friends_get_friends_count
 * @desc **Epic Online Services Function:** [EOS_Friends_GetFriendsCount](https://dev.epicgames.com/docs/api-ref/functions/eos-friends-get-friends-count)
 *
 * Returns the number of friends cached for the given local user, from the last successful ${function.eos_friends_query_friends}.
 *
 * @param {String} local_user_id The Epic Account ID of the local, logged-in user.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_friends_get_friend_at_index
 * @desc **Epic Online Services Function:** [EOS_Friends_GetFriendAtIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-friends-get-friend-at-index)
 *
 * Returns the Epic Account ID of the cached friend at the given index. Use ${function.eos_friends_get_friends_count} to get the valid index range.
 *
 * @param {String} local_user_id The Epic Account ID of the local, logged-in user.
 * @param {Real} index Index into the cached friends list, in the range `[0, ${function.eos_friends_get_friends_count} - 1]`.
 *
 * @returns {String}
 *
 * [[Note: Returns an empty string if the index is out of range.]]
 *
 * @function_end
 */

/**
 * @function eos_friends_get_status
 * @desc **Epic Online Services Function:** [EOS_Friends_GetStatus](https://dev.epicgames.com/docs/api-ref/functions/eos-friends-get-status)
 *
 * Returns the cached friendship status between a local user and a target user.
 *
 * @param {String} local_user_id The Epic Account ID of the local, logged-in user.
 * @param {String} target_user_id The Epic Account ID of the user to check the friendship status of.
 *
 * @returns {Constant.EpicFriendsStatus}
 *
 * @example
 * ```gml
 * if (eos_friends_get_status(local_user_id, target_user_id) == EpicFriendsStatus.Friends)
 * {
 *     show_debug_message("Already friends!");
 * }
 * ```
 * The above code checks whether the local user and a target user are already friends.
 * @function_end
 */

/**
 * @function eos_friends_add_notify_friends_update
 * @desc **Epic Online Services Function:** [EOS_Friends_AddNotifyFriendsUpdate](https://dev.epicgames.com/docs/api-ref/functions/eos-friends-add-notify-friends-update)
 *
 * Registers to be notified whenever a friend is added, removed, or has an invite sent/received/accepted between local users of this client and any other user. If the returned notification ID is valid, you must call ${function.eos_friends_remove_notify_friends_update} with it once you no longer need the notification (e.g. on logout).
 *
 * @param {Function} [callback] Called every time a friend status change is received. See the `callback` event below.
 *
 * @returns {Real} A notification ID, or `0` if registration failed.
 *
 * @event callback
 * @desc Fires every time a friendship status changes for any local user tracked by this client.
 * @member {Struct.EpicFriendsFriendsUpdateCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_friends_remove_notify_friends_update
 * @desc **Epic Online Services Function:** [EOS_Friends_RemoveNotifyFriendsUpdate](https://dev.epicgames.com/docs/api-ref/functions/eos-friends-remove-notify-friends-update)
 *
 * Unregisters a notification previously registered with ${function.eos_friends_add_notify_friends_update}.
 *
 * @param {Real} notification_id The notification ID returned by ${function.eos_friends_add_notify_friends_update}.
 *
 * @function_end
 */

// Structs

/**
 * @struct EpicFriendsQueryFriendsCallbackInfo
 * @desc The result of an ${function.eos_friends_query_friends} call.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the friends list was fetched; an error code otherwise.
 * @member {String} local_user_id The Epic Account ID of the local user the query was for.
 *
 * @struct_end
 */

/**
 * @struct EpicFriendsFriendsUpdateCallbackInfo
 * @desc Delivered by the ${function.eos_friends_add_notify_friends_update} callback whenever a friendship status changes.
 *
 * @member {String} local_user_id The Epic Account ID of the local user this change applies to.
 * @member {String} target_user_id The Epic Account ID of the other user whose relationship with `local_user_id` changed.
 * @member {Constant.EpicFriendsStatus} previous_status The friendship status before this change.
 * @member {Constant.EpicFriendsStatus} current_status The friendship status after this change.
 *
 * @struct_end
 */

/**
 * @const EpicFriendsStatus
 * @desc **Epic Online Services Enum:** [EOS_EFriendsStatus](https://dev.epicgames.com/docs/api-ref/enums/eos-e-friends-status)
 *
 * The relationship between the local user and another user.
 *
 * @member NotFriends The users are not friends and there is no pending invite.
 * @member InviteSent The local user has sent an invite to the other user, awaiting response.
 * @member InviteReceived The local user has received an invite from the other user, awaiting response.
 * @member Friends The users are friends.
 *
 * @const_end
 */

/**
 * @module friends
 * @title Friends
 * @desc **Epic Online Services Interface:** [Friends Interface](https://dev.epicgames.com/docs/game-services/eos-friends-interface)
 *
 * The [Friends Interface](https://dev.epicgames.com/docs/game-services/eos-friends-interface) exposes the local user's Epic friends list - its own social graph, independent from any platform-native friends list. This only covers Epic Account friendships; for the platform-native friends UI overlay see ${module.user_interface}.
 *
 * [[Note: You must call ${function.eos_friends_query_friends} at least once before the cached accessor functions below return anything useful.]]
 *
 * @section_func
 * @desc Provided functions:
 *
 * @ref eos_friends_query_friends
 * @ref eos_friends_get_friends_count
 * @ref eos_friends_get_friend_at_index
 * @ref eos_friends_get_status
 * @ref eos_friends_add_notify_friends_update
 * @ref eos_friends_remove_notify_friends_update
 *
 * @section_end
 *
 * @section_struct
 * @desc These are the structs used by this API:
 *
 * @ref EpicFriendsQueryFriendsCallbackInfo
 * @ref EpicFriendsFriendsUpdateCallbackInfo
 *
 * @section_end
 *
 * @section_const
 * @desc These are the constants used by this API:
 *
 * @ref EpicFriendsStatus
 *
 * @section_end
 *
 * @module_end
 */
