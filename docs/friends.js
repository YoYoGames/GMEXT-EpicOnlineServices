// Functions


/**
 * @function eos_friends_accept_invite
 * @desc **Epic Online Services Function:** [EOS_Friends_AcceptInvite](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Friends/EOS_Friends_AcceptInvite/index.html)
 * 
 * This function starts an asynchronous task that accepts a friend invitation from another user. The completion delegate is executed after the backend response has been received.
 * 
 * @param {string} accountID The Epic Account ID of the local, logged-in user who is accepting the friends list invitation
 * @param {string} accountID_target The Epic Account ID of the user who sent the friends list invitation
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_friends_accept_invite"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_friends_accept_invite(accountID, accountID_target);
 * ```
 * The code sample above save the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_friends_accept_invite")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EOS_RESULT.SUCCESS)
 *     {
 *         show_debug_message(async_load[? "type"] + " succeeded!");
 *     }
 *     else
 *     {
 *          show_debug_message(async_load[? "type"] + " failed: " + async_load[? "status_message"]);
 *     }
 * }
 * ```
 * The code above matches the response against the correct event **type** and logs the success of the task.
 * @function_end
 */

/**
 * @function eos_friends_add_notify_friends_update
 * @desc **Epic Online Services Function:** [EOS_Friends_AddNotifyFriendsUpdate](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Friends/EOS_Friends_AddNotifyFriendsUpdate/index.html)
 * 
 * This function listens for changes to friends for a particular account.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_friends_add_notify_friends_update"`
 * @member {constant.EOS_FRIENDS_STATUS} current_status The current status of the user.
 * @member {constant.EOS_FRIENDS_STATUS} previous_status The previous status of the user.
 * @member {string} target_user_id The Epic Account ID of the user whose status is being updated.
 * @member {string} local_user_id The Epic Account ID of the local user who is receiving the update
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_friends_add_notify_friends_update();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_friends_add_notify_friends_update")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EOS_RESULT.SUCCESS)
 *     {
 *         show_debug_message(async_load[? "type"] + " succeeded!");
 *     }
 *     else
 *     {
 *         show_debug_message(async_load[? "type"] + " failed: " + async_load[? "status_message"]);
 *     }
 * }
 * ```
 * The code above matches the response against the correct event **type** and logs the success of the task.
 * @function_end
 */

/**
 * @function eos_friends_get_friend_at_index
 * @desc **Epic Online Services Function:** [EOS_Friends_GetFriendAtIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Friends/EOS_Friends_GetFriendAtIndex/index.html)
 * 
 * This function retrieves the Epic Account ID of an entry from the friends list that has already been cached. The Epic Account ID returned by this function may belong to an account that has been invited to be a friend or that has invited the local user to be a friend. To determine if the Epic Account ID returned by this function is a friend or a pending friend invitation, use the ${function.eos_friends_get_status} function.
 * 
 * [[Note: Requires a previous call to ${function.eos_friends_query_friends} to store values in cache.]]
 * 
 * @param {string} accountID The user account identifier to get the friend data from.
 * @param {real} index Index into the friend list. This value must be between 0 and ${function.eos_friends_get_friends_count} - 1 inclusively.
 * 
 * @returns {string}
 * @example
 * ```gml
 * var _count = eos_friends_get_friends_count(accountID);
 * for(var i = 0 ; i < _count; i++)
 * {
 *     var _friend_account = eos_friends_get_friend_at_index(accountID, i);
 * }
 * ```
 * The above code shows an example of how the function should be used. The friend's data is returned providing an index.
 * @function_end
 */

/**
 * @function eos_friends_get_friends_count
 * @desc **Epic Online Services Function:** [EOS_Friends_GetFriendsCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Friends/EOS_Friends_GetFriendsCount/index.html)
 * 
 * This function retrieves the number of friends on the friends list.
 * 
 * [[Note: Requires a previous call to ${function.eos_friends_query_friends} to store values in cache.]]
 * 
 * @param {string} accountID The Epic Account ID of the user whose friends should be counted
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _count = eos_friends_get_friends_count(accountID);
 * for(var i = 0 ; i < _count ; i++)
 * {
 *     var _friend_account = eos_friends_get_friend_at_index(accountID, i);
 * }
 * ```
 * The above code shows an example of how the function should be used. After a successful call to ${function.eos_friends_query_friends}, the function ${function.eos_friends_get_friends_count} will return the number of entries in the query array which can then be accessed using the ${function.eos_friends_get_friend_at_index} function.
 * @function_end
 */

/**
 * @function eos_friends_get_status
 * @desc **Epic Online Services Function:** [EOS_Friends_GetStatus](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Friends/EOS_Friends_GetStatus/index.html)
 * 
 * This function retrieves the friendship status between the local user and another user.
 * 
 * @param {string} accountID The Epic Account ID of the local, logged in user
 * @param {string} accountID_target The Epic Account ID of the user whose friendship status with the local user is being queried
 * 
 * @returns {constant.EOS_FRIENDS_STATUS}
 * 
 * @example
 * ```gml
 * if(eos_friends_get_status(accountID,accountID_target) == EOS_FS_FRIENDS)
 * {
 *      show_debug_message("It's my friend!!!");
 * }
 * else
 * {
 *      show_debug_message("Not my friend :(");
 * }
 * ```
 * The above code shows an example of how the function should be used. The friendship status is returned from the function call.
 * @function_end
 */

/**
 * @function eos_friends_query_friends
 * @desc **Epic Online Services Function:** [EOS_Friends_QueryFriends](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Friends/EOS_Friends_QueryFriends/index.html)
 * 
 * This function starts an asynchronous task that reads the user's friends list from the backend service, caching it for future use.
 * Once the callback has been fired with a successful ${constant.EOS_RESULT}, it is possible to call one of the following functions:
 *
 * * ${function.eos_friends_get_friend_at_index}
 * * ${function.eos_friends_get_friends_count}
 * 
 * @param {string} accountID The Epic Account ID of the local, logged-in user whose friends list you want to retrieve
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_friends_query_friends"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_friends_query_friends(accountID);
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_friends_query_friends")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EOS_RESULT.SUCCESS)
 *     {
 *         show_debug_message(async_load[? "type"] + " succeeded!");
 *     }
 *     else
 *     {
 *          show_debug_message(async_load[? "type"] + " failed: " + async_load[? "status_message"]);
 *     }
 * }
 * ```
 * The code above matches the response against the correct event **type** and logs the success of the task.
 * @function_end
 */

/**
 * @function eos_friends_reject_invite
 * @desc **Epic Online Services Function:** [EOS_Friends_RejectInvite](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Friends/EOS_Friends_RejectInvite/index.html)
 * 
 * This function starts an asynchronous task that rejects a friend invitation from another user. The completion delegate is executed after the backend response has been received.
 * 
 * @param {string} accountID The Epic Account ID of the local, logged-in user who is rejecting a friends list invitation
 * @param {string} accountID_target The Epic Account ID of the user who sent the friends list invitation
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_friends_reject_invite"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_friends_reject_invite(accountID, accountID_target);
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_friends_reject_invite")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EOS_RESULT.SUCCESS)
 *     {
 *         show_debug_message(async_load[? "type"] + " succeeded!");
 *     }
 *     else
 *     {
 *          show_debug_message(async_load[? "type"] + " failed: " + async_load[? "status_message"]);
 *     }
 * }
 * ```
 * The code above matches the response against the correct event **type** and logs the success of the task.
 * @function_end
 */

/**
 * @function eos_friends_remove_notify_friends_update
 * @desc **Epic Online Services Function:** [EOS_Friends_RemoveNotifyFriendsUpdate](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Friends/EOS_Friends_RemoveNotifyFriendsUpdate/index.html)
 * 
 * This function stop listening for friends changes on a previously bound handler.
 * 
 * @param {real} id The handle representing the registered callback (return by ${function.eos_friends_add_notify_friends_update})
 * 
 * @example
 * ```gml
 * handle = eos_friends_add_notify_friends_update();
 * //...
 * //...later
 * //...
 * eos_friends_remove_notify_friends_update(handle);
 * ```
 * The code sample above enables the friend update notifications (${function.eos_friends_add_notify_friends_update}) and later disables them by referring to the previously generated handle.
 * @function_end
 */

/**
 * @function eos_friends_send_invite
 * @desc **Epic Online Services Function:** [EOS_Friends_SendInvite](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Friends/EOS_Friends_SendInvite/index.html)
 * 
 * This function starts an asynchronous task that sends a friend invitation to another user. The completion delegate is executed after the backend response has been received. It does not indicate that the target user has responded to the friend invitation.
 * 
 * @param {string} accountID The Epic Account ID of the local, logged-in user who is sending the friends list invitation
 * @param {string} accountID_target The Epic Account ID of the user who is receiving the friends list invitation
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_friends_send_invite"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_friends_send_invite(accountID, accountID_target);
 * ```
 * The code sample above save the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_friends_send_invite")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EOS_RESULT.SUCCESS)
 *     {
 *         show_debug_message(async_load[? "type"] + " succeeded!");
 *     }
 *     else
 *     {
 *          show_debug_message(async_load[? "type"] + " failed: " + async_load[? "status_message"]);
 *     }
 * }
 * ```
 * @function_end
 */

/**
 * @constant EOS_FRIENDS_STATUS
 * @desc **Epic Online Services Enum:** [EOS_EFriendsStatus](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-friends-status)
 * 
 * These constants are used to describe the friendship status with a given account.
 * 
 * @member NOT_FRIENDS The two accounts have no friendship status
 * @member INVITE_SENT The local account has sent a friend invite to the other account
 * @member INVITE_RECEIVED The other account has sent a friend invite to the local account
 * @member FRIENDS The accounts have accepted friendship
 * @constant_end
 */

/**
 * @module friends
 * @title Friends
 * @desc Playing games with your friends and meeting new players online are important parts of many online services. The **Epic Online Services** (EOS) SDK uses the [Friends Interface](https://dev.epicgames.com/docs/epic-account-services/eos-friends-interface) to retrieve the friends lists for a logged-in user.
 * Friends lists are stored by the online service's servers, and can change during a session as friends are added or removed or if friends grant or revoke consent for the game to use their information.
 * 
 * @section_func
 * @desc These functions are provided for handling friend lists:
 * @ref eos_friends_accept_invite
 * @ref eos_friends_add_notify_friends_update
 * @ref eos_friends_get_friend_at_index
 * @ref eos_friends_get_friends_count
 * @ref eos_friends_get_status
 * @ref eos_friends_query_friends
 * @ref eos_friends_reject_invite
 * @ref eos_friends_remove_notify_friends_update
 * @ref eos_friends_send_invite
 * @section_end
 * 
 * @section_const
 * @desc These are the constants used by this API:
 * @ref EOS_FRIENDS_STATUS
 * @section_end
 * 
 * @module_end
 */
