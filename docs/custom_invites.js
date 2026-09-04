// Functions


/**
 * @function eos_custominvites_set_custom_invite
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_SetCustomInvite](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-set-custom-invite)
 *
 * This function sets the payload that will be attached to any custom invite this local user sends afterwards, whether sent through ${function.eos_custominvites_send_custom_invite} or through a platform-native invite flow (see ${function.eos_custominvites_add_notify_send_custom_native_invite_requested}). Call this before sending an invite; the payload set here is what shows up as `payload` on the recipient's ${struct.EpicCustomInvitesCustomInviteReceivedCallbackInfo}.
 *
 * @param {String} local_user_id The Product User ID of the local user setting the invite.
 * @param {String} payload Application-defined data to attach to this user's outgoing custom invites (e.g. a lobby or session join string). The format is entirely up to your game.
 *
 * @returns {Bool} `true` on success. On `false`, call ${function.eos_api_last_error} for the reason.
 *
 * @example
 * ```gml
 * eos_custominvites_set_custom_invite(my_product_user_id, "lobby:" + lobby_id);
 * ```
 * The above code shows an example of how the function should be used.
 * @function_end
 */

/**
 * @function eos_custominvites_send_custom_invite
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_SendCustomInvite](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-send-custom-invite)
 *
 * This function sends a custom invite (carrying whatever payload was last set with ${function.eos_custominvites_set_custom_invite}) to one or more target users.
 *
 * @param {String} local_user_id The Product User ID of the local user sending the invite.
 * @param {Array[String]} target_user_ids The Product User IDs of the users to invite.
 * @param {Function} [callback] A callback function to be triggered when this async request completes.
 *
 * @event callback
 * @desc This event triggers when the send request completes.
 * @member {Struct.EpicCustomInvitesSendCustomInviteCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_custominvites_send_custom_invite(my_product_user_id, [friend_product_user_id], function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         show_debug_message("Custom invite sent to: " + string(_result.target_user_ids));
 *     }
 * });
 * ```
 * The above code shows an example of how the function should be used.
 * @function_end
 */

/**
 * @function eos_custominvites_finalize_invite
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_FinalizeInvite](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-finalize-invite)
 *
 * This function tells the EOS SDK that the local user has finished processing a custom invite they received (i.e. it was shown to the user, or handled and discarded). Call this once you're done handling the invite reported through ${function.eos_custominvites_add_notify_custom_invite_received}, using the same `custom_invite_id` from that callback.
 *
 * @param {String} target_user_id The Product User ID of the user who sent the invite.
 * @param {String} local_user_id The Product User ID of the local user who received the invite.
 * @param {String} custom_invite_id The invite id from the matching ${struct.EpicCustomInvitesCustomInviteReceivedCallbackInfo}.
 * @param {Constant.EpicResult} processing_result The result of processing the invite locally. Use `EpicResult.Success` if it was successfully shown/handled.
 *
 * @returns {Bool} `true` on success. On `false`, call ${function.eos_api_last_error} for the reason.
 *
 * @function_end
 */

/**
 * @function eos_custominvites_send_request_to_join
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_SendRequestToJoin](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-send-request-to-join)
 *
 * This function sends a request to join to a target user, without that user having sent an invite first. Use this for "ask to join" flows (e.g. a player asking to join a friend who doesn't currently have an open invite out).
 *
 * @param {String} local_user_id The Product User ID of the local user sending the request.
 * @param {String} target_user_id The Product User ID of the user being asked.
 * @param {Function} [callback] Called once the send request completes.
 *
 * @event callback
 * @desc This event triggers when the send request completes.
 * @member {Struct.EpicCustomInvitesSendRequestToJoinCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_custominvites_accept_request_to_join
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_AcceptRequestToJoin](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-accept-request-to-join)
 *
 * This function accepts a request to join that was received through ${function.eos_custominvites_add_notify_request_to_join_received}.
 *
 * @param {String} local_user_id The Product User ID of the local user accepting the request (the one who was asked).
 * @param {String} target_user_id The Product User ID of the user whose request is being accepted (the one who asked).
 * @param {Function} [callback] Called once the accept request completes.
 *
 * @event callback
 * @desc This event triggers when the accept request completes.
 * @member {Struct.EpicCustomInvitesAcceptRequestToJoinCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_custominvites_reject_request_to_join
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_RejectRequestToJoin](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-reject-request-to-join)
 *
 * This function rejects a request to join that was received through ${function.eos_custominvites_add_notify_request_to_join_received}.
 *
 * @param {String} local_user_id The Product User ID of the local user rejecting the request (the one who was asked).
 * @param {String} target_user_id The Product User ID of the user whose request is being rejected (the one who asked).
 * @param {Function} [callback] Called once the reject request completes.
 *
 * @event callback
 * @desc This event triggers when the reject request completes.
 * @member {Struct.EpicCustomInvitesRejectRequestToJoinCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_custominvites_add_notify_custom_invite_received
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_AddNotifyCustomInviteReceived](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-add-notify-custom-invite-received)
 *
 * This function registers to receive a notification when a custom invite is received. Once you're done handling a received invite, call ${function.eos_custominvites_finalize_invite}.
 *
 * [[Note: Only one callback can be registered at a time for this notification. Calling this function again replaces the previously registered callback rather than adding a second one.]]
 *
 * @param {Function} [callback] A callback function to be triggered when this event happens.
 *
 * @returns {Real} A valid notification ID if successfully subscribed, or `0` otherwise.
 *
 * @event callback
 * @desc This event triggers when a custom invite is received.
 * @member {Struct.EpicCustomInvitesCustomInviteReceivedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_custominvites_remove_notify_custom_invite_received
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_RemoveNotifyCustomInviteReceived](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-remove-notify-custom-invite-received)
 *
 * This function unregisters from receiving notifications when a custom invite is received.
 *
 * @param {Real} notification_id The notification ID returned by ${function.eos_custominvites_add_notify_custom_invite_received}.
 *
 * @function_end
 */

/**
 * @function eos_custominvites_add_notify_custom_invite_accepted
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_AddNotifyCustomInviteAccepted](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-add-notify-custom-invite-accepted)
 *
 * This function registers to receive a notification when a custom invite this local user sent is accepted by its recipient.
 *
 * [[Note: Only one callback can be registered at a time for this notification. Calling this function again replaces the previously registered callback rather than adding a second one.]]
 *
 * @param {Function} [callback] A callback function to be triggered when this event happens.
 *
 * @returns {Real} A valid notification ID if successfully subscribed, or `0` otherwise.
 *
 * @event callback
 * @desc This event triggers when a sent custom invite is accepted.
 * @member {Struct.EpicCustomInvitesCustomInviteAcceptedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_custominvites_remove_notify_custom_invite_accepted
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_RemoveNotifyCustomInviteAccepted](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-remove-notify-custom-invite-accepted)
 *
 * This function unregisters from receiving notifications when a sent custom invite is accepted.
 *
 * @param {Real} notification_id The notification ID returned by ${function.eos_custominvites_add_notify_custom_invite_accepted}.
 *
 * @function_end
 */

/**
 * @function eos_custominvites_add_notify_custom_invite_rejected
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_AddNotifyCustomInviteRejected](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-add-notify-custom-invite-rejected)
 *
 * This function registers to receive a notification when a custom invite this local user sent is rejected by its recipient.
 *
 * [[Note: Only one callback can be registered at a time for this notification. Calling this function again replaces the previously registered callback rather than adding a second one.]]
 *
 * @param {Function} [callback] A callback function to be triggered when this event happens.
 *
 * @returns {Real} A valid notification ID if successfully subscribed, or `0` otherwise.
 *
 * @event callback
 * @desc This event triggers when a sent custom invite is rejected.
 * @member {Struct.EpicCustomInvitesCustomInviteRejectedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_custominvites_remove_notify_custom_invite_rejected
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_RemoveNotifyCustomInviteRejected](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-remove-notify-custom-invite-rejected)
 *
 * This function unregisters from receiving notifications when a sent custom invite is rejected.
 *
 * @param {Real} notification_id The notification ID returned by ${function.eos_custominvites_add_notify_custom_invite_rejected}.
 *
 * @function_end
 */

/**
 * @function eos_custominvites_add_notify_request_to_join_response_received
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_AddNotifyRequestToJoinResponseReceived](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-add-notify-request-to-join-response-received)
 *
 * This function registers to receive a notification when a request to join this local user sent (via ${function.eos_custominvites_send_request_to_join}) has been responded to, carrying the actual accept/reject result. This fires regardless of whether the response came through ${function.eos_custominvites_accept_request_to_join}/${function.eos_custominvites_reject_request_to_join} or through a platform-native response flow.
 *
 * [[Note: Only one callback can be registered at a time for this notification. Calling this function again replaces the previously registered callback rather than adding a second one.]]
 *
 * @param {Function} [callback] A callback function to be triggered when this event happens.
 *
 * @returns {Real} A valid notification ID if successfully subscribed, or `0` otherwise.
 *
 * @event callback
 * @desc This event triggers when a sent request to join receives a response.
 * @member {Struct.EpicCustomInvitesRequestToJoinResponseReceivedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_custominvites_remove_notify_request_to_join_response_received
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_RemoveNotifyRequestToJoinResponseReceived](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-remove-notify-request-to-join-response-received)
 *
 * This function unregisters from receiving notifications about responses to a sent request to join.
 *
 * @param {Real} notification_id The notification ID returned by ${function.eos_custominvites_add_notify_request_to_join_response_received}.
 *
 * @function_end
 */

/**
 * @function eos_custominvites_add_notify_request_to_join_received
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_AddNotifyRequestToJoinReceived](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-add-notify-request-to-join-received)
 *
 * This function registers to receive a notification when this local user receives a request to join from another user. Respond to it with ${function.eos_custominvites_accept_request_to_join} or ${function.eos_custominvites_reject_request_to_join}.
 *
 * [[Note: Only one callback can be registered at a time for this notification. Calling this function again replaces the previously registered callback rather than adding a second one.]]
 *
 * @param {Function} [callback] A callback function to be triggered when this event happens.
 *
 * @returns {Real} A valid notification ID if successfully subscribed, or `0` otherwise.
 *
 * @event callback
 * @desc This event triggers when a request to join is received.
 * @member {Struct.EpicCustomInvitesRequestToJoinReceivedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_custominvites_remove_notify_request_to_join_received
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_RemoveNotifyRequestToJoinReceived](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-remove-notify-request-to-join-received)
 *
 * This function unregisters from receiving notifications about incoming requests to join.
 *
 * @param {Real} notification_id The notification ID returned by ${function.eos_custominvites_add_notify_request_to_join_received}.
 *
 * @function_end
 */

/**
 * @function eos_custominvites_add_notify_send_custom_native_invite_requested
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_AddNotifySendCustomNativeInviteRequested](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-add-notify-send-custom-native-invite-requested)
 *
 * This function registers to receive a notification when the user has requested (via the platform-native share/invite UI, e.g. the console or mobile system invite sheet) that a custom invite be sent. Use this to send your own custom invite (through ${function.eos_custominvites_send_custom_invite} or another method carrying your own payload) in response to a native platform invite action.
 *
 * [[Warning: You **must** call ${function.eos_ui_acknowledge_event_id} with the callback's `ui_event_id` after handling this notification. Failing to acknowledge the event leaves the platform's native UI hung.]]
 *
 * [[Note: Only one callback can be registered at a time for this notification. Calling this function again replaces the previously registered callback rather than adding a second one.]]
 *
 * @param {Function} [callback] A callback function to be triggered when this event happens.
 *
 * @returns {Real} A valid notification ID if successfully subscribed, or `0` otherwise.
 *
 * @event callback
 * @desc This event triggers when a native invite send is requested.
 * @member {Struct.EpicCustomInvitesSendCustomNativeInviteRequestedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_custominvites_remove_notify_send_custom_native_invite_requested
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_RemoveNotifySendCustomNativeInviteRequested](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-remove-notify-send-custom-native-invite-requested)
 *
 * This function unregisters from receiving notifications about native invite send requests.
 *
 * @param {Real} notification_id The notification ID returned by ${function.eos_custominvites_add_notify_send_custom_native_invite_requested}.
 *
 * @function_end
 */

/**
 * @function eos_custominvites_add_notify_request_to_join_accepted
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_AddNotifyRequestToJoinAccepted](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-add-notify-request-to-join-accepted)
 *
 * This function registers to receive a notification when a request to join this local user sent is accepted. This is a convenience notification carrying just the accepted outcome; ${function.eos_custominvites_add_notify_request_to_join_response_received} reports both outcomes through a single event with a response code instead.
 *
 * [[Note: Only one callback can be registered at a time for this notification. Calling this function again replaces the previously registered callback rather than adding a second one.]]
 *
 * @param {Function} [callback] A callback function to be triggered when this event happens.
 *
 * @returns {Real} A valid notification ID if successfully subscribed, or `0` otherwise.
 *
 * @event callback
 * @desc This event triggers when a sent request to join is accepted.
 * @member {Struct.EpicCustomInvitesRequestToJoinAcceptedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_custominvites_remove_notify_request_to_join_accepted
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_RemoveNotifyRequestToJoinAccepted](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-remove-notify-request-to-join-accepted)
 *
 * This function unregisters from receiving notifications when a sent request to join is accepted.
 *
 * @param {Real} notification_id The notification ID returned by ${function.eos_custominvites_add_notify_request_to_join_accepted}.
 *
 * @function_end
 */

/**
 * @function eos_custominvites_add_notify_request_to_join_rejected
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_AddNotifyRequestToJoinRejected](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-add-notify-request-to-join-rejected)
 *
 * This function registers to receive a notification when a request to join this local user sent is rejected. This is a convenience notification carrying just the rejected outcome; ${function.eos_custominvites_add_notify_request_to_join_response_received} reports both outcomes through a single event with a response code instead.
 *
 * [[Note: Only one callback can be registered at a time for this notification. Calling this function again replaces the previously registered callback rather than adding a second one.]]
 *
 * @param {Function} [callback] A callback function to be triggered when this event happens.
 *
 * @returns {Real} A valid notification ID if successfully subscribed, or `0` otherwise.
 *
 * @event callback
 * @desc This event triggers when a sent request to join is rejected.
 * @member {Struct.EpicCustomInvitesRequestToJoinRejectedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_custominvites_remove_notify_request_to_join_rejected
 * @desc **Epic Online Services Function:** [EOS_CustomInvites_RemoveNotifyRequestToJoinRejected](https://dev.epicgames.com/docs/api-ref/functions/eos-custominvites-remove-notify-request-to-join-rejected)
 *
 * This function unregisters from receiving notifications when a sent request to join is rejected.
 *
 * @param {Real} notification_id The notification ID returned by ${function.eos_custominvites_add_notify_request_to_join_rejected}.
 *
 * @function_end
 */

// Structs

/**
 * @struct EpicCustomInvitesSendCustomInviteCallbackInfo
 * @desc Result data for ${function.eos_custominvites_send_custom_invite}.
 *
 * @member {Constant.EpicResult} result_code The result of the send operation. `EpicResult.Success` indicates the invite was sent to all target users.
 * @member {String} local_user_id The Product User ID of the local user who sent the invite.
 * @member {Array[String]} target_user_ids The Product User IDs the invite was sent to.
 *
 * @struct_end
 */

/**
 * @struct EpicCustomInvitesCustomInviteReceivedCallbackInfo
 * @desc Notification data for ${function.eos_custominvites_add_notify_custom_invite_received}.
 *
 * @member {String} target_user_id The Product User ID of the local user this invite was sent to.
 * @member {String} local_user_id The Product User ID of the user who sent the invite.
 * @member {String} custom_invite_id The id of this invite, used with ${function.eos_custominvites_finalize_invite}.
 * @member {String} payload The application-defined payload set by the sender via ${function.eos_custominvites_set_custom_invite}.
 *
 * @struct_end
 */

/**
 * @struct EpicCustomInvitesCustomInviteAcceptedCallbackInfo
 * @desc Notification data for ${function.eos_custominvites_add_notify_custom_invite_accepted}.
 *
 * @member {String} target_user_id The Product User ID of the user who accepted the invite.
 * @member {String} local_user_id The Product User ID of the local user who sent the invite.
 * @member {String} custom_invite_id The id of the accepted invite.
 * @member {String} payload The invite's payload.
 *
 * @struct_end
 */

/**
 * @struct EpicCustomInvitesCustomInviteRejectedCallbackInfo
 * @desc Notification data for ${function.eos_custominvites_add_notify_custom_invite_rejected}.
 *
 * @member {String} target_user_id The Product User ID of the user who rejected the invite.
 * @member {String} local_user_id The Product User ID of the local user who sent the invite.
 * @member {String} custom_invite_id The id of the rejected invite.
 * @member {String} payload The invite's payload.
 *
 * @struct_end
 */

/**
 * @struct EpicCustomInvitesSendRequestToJoinCallbackInfo
 * @desc Result data for ${function.eos_custominvites_send_request_to_join}.
 *
 * @member {Constant.EpicResult} result_code The result of the send operation.
 * @member {String} local_user_id The Product User ID of the local user who sent the request.
 * @member {String} target_user_id The Product User ID of the user who was asked.
 *
 * @struct_end
 */

/**
 * @struct EpicCustomInvitesRequestToJoinResponseReceivedCallbackInfo
 * @desc Notification data for ${function.eos_custominvites_add_notify_request_to_join_response_received}.
 *
 * @member {String} from_user_id The Product User ID of the user who responded (the one who was asked).
 * @member {String} to_user_id The Product User ID of the local user who sent the original request (the one who asked).
 * @member {Constant.EpicRequestToJoinResponse} response Whether the request was accepted or rejected.
 *
 * @struct_end
 */

/**
 * @struct EpicCustomInvitesRequestToJoinReceivedCallbackInfo
 * @desc Notification data for ${function.eos_custominvites_add_notify_request_to_join_received}.
 *
 * @member {String} from_user_id The Product User ID of the user who sent the request.
 * @member {String} to_user_id The Product User ID of the local user who received the request.
 *
 * @struct_end
 */

/**
 * @struct EpicCustomInvitesAcceptRequestToJoinCallbackInfo
 * @desc Result data for ${function.eos_custominvites_accept_request_to_join}.
 *
 * @member {Constant.EpicResult} result_code The result of the accept operation.
 * @member {String} local_user_id The Product User ID of the local user who accepted the request.
 * @member {String} target_user_id The Product User ID of the user whose request was accepted.
 *
 * @struct_end
 */

/**
 * @struct EpicCustomInvitesRejectRequestToJoinCallbackInfo
 * @desc Result data for ${function.eos_custominvites_reject_request_to_join}.
 *
 * @member {Constant.EpicResult} result_code The result of the reject operation.
 * @member {String} local_user_id The Product User ID of the local user who rejected the request.
 * @member {String} target_user_id The Product User ID of the user whose request was rejected.
 *
 * @struct_end
 */

/**
 * @struct EpicCustomInvitesSendCustomNativeInviteRequestedCallbackInfo
 * @desc Notification data for ${function.eos_custominvites_add_notify_send_custom_native_invite_requested}.
 *
 * @member {Real} ui_event_id Pass this to ${function.eos_ui_acknowledge_event_id} once you've handled this event.
 * @member {String} local_user_id The Product User ID of the local user who triggered the native invite UI.
 * @member {String} target_native_account_type The platform-native account type of the target (e.g. the console/store's own platform identifier scheme).
 * @member {String} target_user_native_account_id The platform-native account id of the target user.
 * @member {String} invite_id An id for this native invite request.
 *
 * @struct_end
 */

/**
 * @struct EpicCustomInvitesRequestToJoinAcceptedCallbackInfo
 * @desc Notification data for ${function.eos_custominvites_add_notify_request_to_join_accepted}.
 *
 * @member {String} target_user_id The Product User ID of the user who accepted the request.
 * @member {String} local_user_id The Product User ID of the local user who sent the request.
 *
 * @struct_end
 */

/**
 * @struct EpicCustomInvitesRequestToJoinRejectedCallbackInfo
 * @desc Notification data for ${function.eos_custominvites_add_notify_request_to_join_rejected}.
 *
 * @member {String} target_user_id The Product User ID of the user who rejected the request.
 * @member {String} local_user_id The Product User ID of the local user who sent the request.
 *
 * @struct_end
 */

// Constants

/**
 * @const EpicRequestToJoinResponse
 * @desc **Epic Online Services Enum:** [EOS_ERequestToJoinResponse](https://dev.epicgames.com/docs/api-ref/enums/eos-e-request-to-join-response)
 *
 * The outcome of a request to join, reported through ${function.eos_custominvites_add_notify_request_to_join_response_received}.
 *
 * @member Accepted The request was accepted.
 * @member Rejected The request was rejected.
 *
 * @const_end
 */


/**
 * @module custom_invites
 * @title Custom Invites
 * @desc **Epic Online Services Interface:** [Custom Invites Interface](https://dev.epicgames.com/docs/api-ref/interfaces/custom-invites)
 *
 * The [Custom Invites Interface](https://dev.epicgames.com/docs/api-ref/interfaces/custom-invites) lets players invite each other using a payload defined entirely by your game (a lobby id, a session join string, or anything else you need), instead of relying on a specific EOS lobby/session. It also covers "request to join" - a player asking to join someone without having received an invite first - and surfaces platform-native invite/share UI actions so you can respond to them with your own custom invite.
 *
 * [[Note: Only one callback can be registered at a time per notification type in this module - registering a new one replaces the previous registration rather than adding a second listener.]]
 *
 * @section_func
 * @desc Provided functions:
 *
 * @ref eos_custominvites_set_custom_invite
 * @ref eos_custominvites_send_custom_invite
 * @ref eos_custominvites_finalize_invite
 * @ref eos_custominvites_send_request_to_join
 * @ref eos_custominvites_accept_request_to_join
 * @ref eos_custominvites_reject_request_to_join
 * @ref eos_custominvites_add_notify_custom_invite_received
 * @ref eos_custominvites_remove_notify_custom_invite_received
 * @ref eos_custominvites_add_notify_custom_invite_accepted
 * @ref eos_custominvites_remove_notify_custom_invite_accepted
 * @ref eos_custominvites_add_notify_custom_invite_rejected
 * @ref eos_custominvites_remove_notify_custom_invite_rejected
 * @ref eos_custominvites_add_notify_request_to_join_response_received
 * @ref eos_custominvites_remove_notify_request_to_join_response_received
 * @ref eos_custominvites_add_notify_request_to_join_received
 * @ref eos_custominvites_remove_notify_request_to_join_received
 * @ref eos_custominvites_add_notify_send_custom_native_invite_requested
 * @ref eos_custominvites_remove_notify_send_custom_native_invite_requested
 * @ref eos_custominvites_add_notify_request_to_join_accepted
 * @ref eos_custominvites_remove_notify_request_to_join_accepted
 * @ref eos_custominvites_add_notify_request_to_join_rejected
 * @ref eos_custominvites_remove_notify_request_to_join_rejected
 *
 * @section_end
 *
 * @section_struct
 * @desc These are the structs used by this API:
 *
 * @ref EpicCustomInvitesSendCustomInviteCallbackInfo
 * @ref EpicCustomInvitesCustomInviteReceivedCallbackInfo
 * @ref EpicCustomInvitesCustomInviteAcceptedCallbackInfo
 * @ref EpicCustomInvitesCustomInviteRejectedCallbackInfo
 * @ref EpicCustomInvitesSendRequestToJoinCallbackInfo
 * @ref EpicCustomInvitesRequestToJoinResponseReceivedCallbackInfo
 * @ref EpicCustomInvitesRequestToJoinReceivedCallbackInfo
 * @ref EpicCustomInvitesAcceptRequestToJoinCallbackInfo
 * @ref EpicCustomInvitesRejectRequestToJoinCallbackInfo
 * @ref EpicCustomInvitesSendCustomNativeInviteRequestedCallbackInfo
 * @ref EpicCustomInvitesRequestToJoinAcceptedCallbackInfo
 * @ref EpicCustomInvitesRequestToJoinRejectedCallbackInfo
 *
 * @section_end
 *
 * @section_const
 * @desc These are the constants used by this API:
 *
 * @ref EpicRequestToJoinResponse
 *
 * @section_end
 *
 * @module_end
 */
