// Functions


/**
 * @function EpicGames_Friends_AcceptInvite
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
 * @member {string} type The string `"EpicGames_Friends_AcceptInvite"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_Friends_AcceptInvite(accountID, accountID_target);
 * ```
 * The code sample above save the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Friends_AcceptInvite")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EpicGames_Success)
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
 * @function EpicGames_Friends_AddNotifyFriendsUpdate
 * @desc **Epic Online Services Function:** [EOS_Friends_AddNotifyFriendsUpdate](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Friends/EOS_Friends_AddNotifyFriendsUpdate/index.html)
 * 
 * This function listens for changes to friends for a particular account.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_Friends_AddNotifyFriendsUpdate"`
 * @member {constant.EpicGames_Friendship_Status} CurrentStatus The current status of the user.
 * @member {constant.EpicGames_Friendship_Status} PreviousStatus The previous status of the user.
 * @member {string} TargetUserId The Epic Account ID of the user whose status is being updated.
 * @member {string} LocalUserId The Epic Account ID of the local user who is receiving the update
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_Friends_AddNotifyFriendsUpdate();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Friends_AddNotifyFriendsUpdate")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EpicGames_Success)
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
 * @function EpicGames_Friends_GetFriendAtIndex
 * @desc **Epic Online Services Function:** [EOS_Friends_GetFriendAtIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Friends/EOS_Friends_GetFriendAtIndex/index.html)
 * 
 * This function retrieves the Epic Account ID of an entry from the friends list that has already been cached. The Epic Account ID returned by this function may belong to an account that has been invited to be a friend or that has invited the local user to be a friend. To determine if the Epic Account ID returned by this function is a friend or a pending friend invitation, use the ${function.EpicGames_Friends_GetStatus} function.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_Friends_QueryFriends} to store values in cache.]]
 * 
 * @param {string} accountID The user account Identifier to get the friend data from.
 * @param {real} index Index into the friend list. This value must be between 0 and ${function.EpicGames_Friends_GetFriendsCount} - 1 inclusively.
 * 
 * @returns {string}
 * @example
 * ```gml
 * var _count = EpicGames_Friends_GetFriendsCount(accountID);
 * for(var i = 0 ; i < _count; i++)
 * {
 *     var _friend_account = EpicGames_Friends_GetFriendAtIndex(accountID, i);
 * }
 * ```
 * The above code shows an example of how the function should be used. The friend's data is returned providing an index.
 * @function_end
 */

/**
 * @function EpicGames_Friends_GetFriendsCount
 * @desc **Epic Online Services Function:** [EOS_Friends_GetFriendsCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Friends/EOS_Friends_GetFriendsCount/index.html)
 * 
 * This function retrieves the number of friends on the friends list.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_Friends_QueryFriends} to store values in cache.]]
 * 
 * @param {string} accountID The Epic Account ID of the user whose friends should be counted
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _count = EpicGames_Friends_GetFriendsCount(accountID);
 * for(var i = 0 ; i < _count ; i++)
 * {
 *     var _friend_account = EpicGames_Friends_GetFriendAtIndex(accountID, i);
 * }
 * ```
 * The above code shows an example of how the function should be used. After a successful call to ${function.EpicGames_Friends_QueryFriends}, the function ${function.EpicGames_Friends_GetFriendsCount} will return the number of entries in the query array which can then be accessed using the ${function.EpicGames_Friends_GetFriendAtIndex} function.
 * @function_end
 */

/**
 * @function EpicGames_Friends_GetStatus
 * @desc **Epic Online Services Function:** [EOS_Friends_GetStatus](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Friends/EOS_Friends_GetStatus/index.html)
 * 
 * This function retrieves the friendship status between the local user and another user.
 * 
 * @param {string} accountID The Epic Account ID of the local, logged in user
 * @param {string} accountID_target The Epic Account ID of the user whose friendship status with the local user is being queried
 * 
 * @returns {constant.EpicGames_Friendship_Status}
 * 
 * @example
 * ```gml
 * if(EpicGames_Friends_GetStatus(accountID,accountID_target) == EpicGames_FS_Friends)
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
 * @function EpicGames_Friends_QueryFriends
 * @desc **Epic Online Services Function:** [EOS_Friends_QueryFriends](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Friends/EOS_Friends_QueryFriends/index.html)
 * 
 * This function starts an asynchronous task that reads the user's friends list from the backend service, caching it for future use.
 * Once the callback has been fired with a successful ${constant.EpicGames_Result}, it is possible to call one of the following functions:
 *
 * * ${function.EpicGames_Friends_GetFriendAtIndex}
 * * ${function.EpicGames_Friends_GetFriendsCount}
 * 
 * @param {string} accountID The Epic Account ID of the local, logged-in user whose friends list you want to retrieve
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_Friends_QueryFriends"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_Friends_QueryFriends(accountID);
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Friends_QueryFriends")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EpicGames_Success)
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
 * @function EpicGames_Friends_RejectInvite
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
 * @member {string} type The string `"EpicGames_Friends_RejectInvite"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_Friends_RejectInvite(accountID, accountID_target);
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Friends_RejectInvite")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EpicGames_Success)
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
 * @function EpicGames_Friends_RemoveNotifyFriendsUpdate
 * @desc **Epic Online Services Function:** [EOS_Friends_RemoveNotifyFriendsUpdate](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Friends/EOS_Friends_RemoveNotifyFriendsUpdate/index.html)
 * 
 * This function stop listening for friends changes on a previously bound handler.
 * 
 * @param {real} id The handle representing the registered callback (return by ${function.EpicGames_Friends_AddNotifyFriendsUpdate})
 * 
 * @example
 * ```gml
 * handle = EpicGames_Friends_AddNotifyFriendsUpdate();
 * //...
 * //...later
 * //...
 * EpicGames_Friends_RemoveNotifyFriendsUpdate(handle);
 * ```
 * The code sample above enables the friend update notifications (${function.EpicGames_Friends_AddNotifyFriendsUpdate}) and later disables them by referring to the previously generated handle.
 * @function_end
 */

/**
 * @function EpicGames_Friends_SendInvite
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
 * @member {string} type The string `"EpicGames_Friends_SendInvite"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_Friends_SendInvite(accountID, accountID_target);
 * ```
 * The code sample above save the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Friends_SendInvite")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EpicGames_Success)
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
 * @constant EpicGames_Friendship_Status
 * @desc **Epic Online Services Enum:** [EOS_EFriendsStatus](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-friends-status)
 * 
 * These constants are used to describe the friendship status with a given account.
 * 
 * @member EpicGames_FS_NotFriends The two accounts have no friendship status
 * @member EpicGames_FS_InviteSent The local account has sent a friend invite to the other account
 * @member EpicGames_FS_InviteRecieved The other account has sent a friend invite to the local account
 * @member EpicGames_FS_Friends The accounts have accepted friendship
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
 * @ref EpicGames_Friends_AcceptInvite
 * @ref EpicGames_Friends_AddNotifyFriendsUpdate
 * @ref EpicGames_Friends_GetFriendAtIndex
 * @ref EpicGames_Friends_GetFriendsCount
 * @ref EpicGames_Friends_GetStatus
 * @ref EpicGames_Friends_QueryFriends
 * @ref EpicGames_Friends_RejectInvite
 * @ref EpicGames_Friends_RemoveNotifyFriendsUpdate
 * @ref EpicGames_Friends_SendInvite
 * @section_end
 * 
 * @section_const
 * @desc These are the constants used by this API:
 * @ref EpicGames_Friendship_Status
 * @section_end
 * 
 * @module_end
 */
