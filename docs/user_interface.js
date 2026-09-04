// Functions

/**
 * @function eos_ui_show_friends
 * @desc **Epic Online Services Function:** [EOS_UI_ShowFriends](https://dev.epicgames.com/docs/api-ref/functions/eos-ui-show-friends)
 *
 * Shows the Friends overlay for the given local user. On desktop platforms this is a fully featured
 * friends list; on mobile it's a slimmed-down view.
 *
 * [[Note: On some platforms the user must be logged in to Epic Account Services (see ${module.auth}) for this call to have an effect.]]
 *
 * @param {String} local_user_id The Product User ID of the local player requesting the overlay.
 * @param {Function} [callback] Called once the overlay has been shown (or the request has failed).
 *
 * @event callback
 * @desc Fires once, with the result of the show-friends request.
 * @member {Struct.EpicUIShowFriendsCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_ui_show_friends(local_user_id, function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         show_debug_message("Friends overlay shown.");
 *     }
 * });
 * ```
 * The above code shows the Friends overlay to the given local user and logs once it's up.
 * @function_end
 */

/**
 * @function eos_ui_show_native_profile
 * @desc **Epic Online Services Function:** [EOS_UI_ShowNativeProfile](https://dev.epicgames.com/docs/api-ref/functions/eos-ui-show-native-profile)
 *
 * Shows the native platform's profile overlay for the given target user, if the current platform has one
 * (e.g. a console's own profile card). Does nothing on platforms without a native profile UI.
 *
 * @param {String} local_user_id The Product User ID of the local player requesting the overlay.
 * @param {String} target_user_id The Product User ID of the player whose native profile should be shown.
 * @param {Function} [callback] Called once the overlay has been shown (or the request has failed).
 *
 * @event callback
 * @desc Fires once, with the result of the show-native-profile request.
 * @member {Struct.EpicUIShowNativeProfileCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_ui_acknowledge_event_id
 * @desc **Epic Online Services Function:** [EOS_UI_AcknowledgeEventId](https://dev.epicgames.com/docs/api-ref/functions/eos-ui-acknowledge-event-id)
 *
 * Acknowledges a UI event raised by the social overlay (e.g. a join-game or native-invite request that
 * came in with a `ui_event_id`).
 *
 * [[Important: Whenever a callback/notification hands you a `ui_event_id` (join-game-accepted, native-invite-requested, and similar overlay-driven events across ${module.sessions}/${module.lobbies}/${module.custom_invites}), you MUST call this function with that ID once you're done handling it, passing the real outcome as `result_code`. Skipping this - or acknowledging with a hardcoded ${constant.EpicResult} instead of the actual outcome - leaves the social overlay UI hanging or reports a false result to Epic's backend.]]
 *
 * @param {Real} ui_event_id The ID of the UI event to acknowledge, taken from the triggering callback/notification struct.
 * @param {Enum.EpicResult} result_code The real outcome of handling the event (e.g. `EpicResult.Success` once a join has actually completed, or an error code if it failed).
 *
 * @returns {Enum.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_ui_set_display_preference
 * @desc **Epic Online Services Function:** [EOS_UI_SetDisplayPreference](https://dev.epicgames.com/docs/api-ref/functions/eos-ui-set-display-preference)
 *
 * Sets the corner of the screen the notification/toast style overlay elements (friend requests, invites,
 * etc.) should appear in.
 *
 * @param {Enum.EpicUINotificationLocation} notification_location The screen corner to show notifications in.
 *
 * @returns {Enum.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_ui_report_input_state
 * @desc **Epic Online Services Function:** [EOS_UI_ReportInputState](https://dev.epicgames.com/docs/api-ref/functions/eos-ui-report-input-state)
 *
 * Reports the current state of a fixed set of gamepad-style buttons to the SDK so the social overlay can
 * be driven with a controller instead of a mouse/keyboard. Call this every frame the overlay is visible
 * (e.g. from the Step event) with the current button states.
 *
 * [[Note: This only reports the 4 D-Pad directions plus an accept/cancel pair - it is not a full input passthrough. Mouse and analog-stick state are not exposed by this function.]]
 *
 * @param {Bool} button_down `true` while the D-Pad down button is held.
 * @param {Bool} button_up `true` while the D-Pad up button is held.
 * @param {Bool} button_left `true` while the D-Pad left button is held.
 * @param {Bool} button_right `true` while the D-Pad right button is held.
 * @param {Bool} button_accept `true` while the accept/confirm face button is held.
 * @param {Bool} button_cancel `true` while the cancel/back face button is held.
 *
 * @example
 * ```gml
 * /// Step Event
 * eos_ui_report_input_state(
 *     keyboard_check(vk_down), keyboard_check(vk_up),
 *     keyboard_check(vk_left), keyboard_check(vk_right),
 *     keyboard_check(vk_enter), keyboard_check(vk_escape)
 * );
 * ```
 * The above code drives the overlay's D-Pad/accept/cancel input from the keyboard every step.
 * @function_end
 */

/**
 * @function eos_ui_add_notify_display_settings_updated
 * @desc **Epic Online Services Function:** [EOS_UI_AddNotifyDisplaySettingsUpdated](https://dev.epicgames.com/docs/api-ref/functions/eos-ui-add-notify-display-settings-updated)
 *
 * Registers to receive a notification whenever the visibility or input-exclusivity of the overlay
 * changes (e.g. the player opens/closes the Friends overlay, or the overlay starts/stops capturing
 * exclusive input). If the returned notification ID is valid, call ${function.eos_ui_remove_notify_display_settings_updated} when you no longer need it.
 *
 * @param {Function} [callback] Called every time the overlay's display settings change.
 *
 * @returns {Real} A notification ID, or `0` if registration failed.
 *
 * @event callback
 * @desc Fires every time the overlay's visibility or input-exclusivity changes.
 * @member {Struct.EpicUIDisplaySettingsUpdatedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_ui_remove_notify_display_settings_updated
 * @desc **Epic Online Services Function:** [EOS_UI_RemoveNotifyDisplaySettingsUpdated](https://dev.epicgames.com/docs/api-ref/functions/eos-ui-remove-notify-display-settings-updated)
 *
 * Unregisters a notification previously registered with ${function.eos_ui_add_notify_display_settings_updated}.
 *
 * @param {Real} notification_id The notification ID returned by ${function.eos_ui_add_notify_display_settings_updated}.
 *
 * @function_end
 */

/**
 * @function eos_ui_hide_friends
 * @desc **Epic Online Services Function:** [EOS_UI_HideFriends](https://dev.epicgames.com/docs/api-ref/functions/eos-ui-hide-friends)
 *
 * Hides the Friends overlay for the given local user, if it is currently visible.
 *
 * @param {String} local_user_id The Product User ID of the local player.
 * @param {Function} [callback] Called once the overlay has been hidden (or the request has failed).
 *
 * @event callback
 * @desc Fires once, with the result of the hide-friends request.
 * @member {Struct.EpicUIHideFriendsCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_ui_get_friends_visible
 * @desc **Epic Online Services Function:** [EOS_UI_GetFriendsVisible](https://dev.epicgames.com/docs/api-ref/functions/eos-ui-get-friends-visible)
 *
 * Checks whether the Friends overlay is currently visible for the given local user.
 *
 * @param {String} local_user_id The Product User ID of the local player.
 *
 * @returns {Bool}
 *
 * @function_end
 */

/**
 * @function eos_ui_get_friends_exclusive_input
 * @desc **Epic Online Services Function:** [EOS_UI_GetFriendsExclusiveInput](https://dev.epicgames.com/docs/api-ref/functions/eos-ui-get-friends-exclusive-input)
 *
 * Checks whether the Friends overlay currently has exclusive input for the given local user (i.e. it is
 * consuming input that would otherwise go to your game).
 *
 * @param {String} local_user_id The Product User ID of the local player.
 *
 * @returns {Bool}
 *
 * @function_end
 */

/**
 * @function eos_ui_pause_social_overlay
 * @desc **Epic Online Services Function:** [EOS_UI_PauseSocialOverlay](https://dev.epicgames.com/docs/api-ref/functions/eos-ui-pause-social-overlay)
 *
 * Pauses or resumes rendering/input-handling of the whole social overlay. Useful when you need to show
 * your own fullscreen UI (e.g. a cutscene or your own overlay) without the EOS overlay competing for input.
 *
 * @param {Bool} is_paused `true` to pause the overlay, `false` to resume it.
 *
 * @returns {Enum.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_ui_is_social_overlay_paused
 * @desc **Epic Online Services Function:** [EOS_UI_IsSocialOverlayPaused](https://dev.epicgames.com/docs/api-ref/functions/eos-ui-is-social-overlay-paused)
 *
 * Checks whether the social overlay is currently paused (see ${function.eos_ui_pause_social_overlay}).
 *
 * @returns {Bool}
 *
 * @function_end
 */

/**
 * @function eos_ui_get_notification_location_preference
 * @desc **Epic Online Services Function:** [EOS_UI_GetNotificationLocationPreference](https://dev.epicgames.com/docs/api-ref/functions/eos-ui-get-notification-location-preference)
 *
 * Gets the screen corner notifications are currently set to appear in (see ${function.eos_ui_set_display_preference}).
 *
 * @returns {Enum.EpicUINotificationLocation}
 *
 * @function_end
 */

/**
 * @function eos_ui_show_block_player
 * @desc **Epic Online Services Function:** [EOS_UI_ShowBlockPlayer](https://dev.epicgames.com/docs/api-ref/functions/eos-ui-show-block-player)
 *
 * Shows Epic's overlay UI for blocking the given target player.
 *
 * @param {String} local_user_id The Product User ID of the local player requesting the overlay.
 * @param {String} target_user_id The Product User ID of the player to be blocked.
 * @param {Function} [callback] Called once the overlay has been shown (or the request has failed).
 *
 * @event callback
 * @desc Fires once, with the result of the show-block-player request.
 * @member {Struct.EpicUIShowBlockPlayerCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_ui_show_report_player
 * @desc **Epic Online Services Function:** [EOS_UI_ShowReportPlayer](https://dev.epicgames.com/docs/api-ref/functions/eos-ui-show-report-player)
 *
 * Shows Epic's overlay UI for reporting the given target player.
 *
 * [[Note: This shows Epic's own report-player overlay. To submit a behavior report programmatically instead, see ${module.reports}.]]
 *
 * @param {String} local_user_id The Product User ID of the local player requesting the overlay.
 * @param {String} target_user_id The Product User ID of the player to be reported.
 * @param {Function} [callback] Called once the overlay has been shown (or the request has failed).
 *
 * @event callback
 * @desc Fires once, with the result of the show-report-player request.
 * @member {Struct.EpicUIShowReportPlayerCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

// Structs

/**
 * @struct EpicUIShowFriendsCallbackInfo
 * @desc The result of a ${function.eos_ui_show_friends} request.
 *
 * @member {Enum.EpicResult} result_code The result of the request. `EpicResult.Success` indicates the overlay was shown.
 * @member {String} local_user_id The Product User ID of the local player who requested the overlay.
 *
 * @struct_end
 */

/**
 * @struct EpicUIShowNativeProfileCallbackInfo
 * @desc The result of a ${function.eos_ui_show_native_profile} request.
 *
 * @member {Enum.EpicResult} result_code The result of the request. `EpicResult.Success` indicates the overlay was shown.
 * @member {String} local_user_id The Product User ID of the local player who requested the overlay.
 * @member {String} target_user_id The Product User ID of the player whose native profile was requested.
 *
 * @struct_end
 */

/**
 * @struct EpicUIDisplaySettingsUpdatedCallbackInfo
 * @desc The overlay's current display settings, delivered on every ${function.eos_ui_add_notify_display_settings_updated} notification.
 *
 * @member {Bool} is_visible `true` if the overlay is currently visible.
 * @member {Bool} is_exclusive_input `true` if the overlay currently has exclusive input.
 *
 * @struct_end
 */

/**
 * @struct EpicUIHideFriendsCallbackInfo
 * @desc The result of a ${function.eos_ui_hide_friends} request.
 *
 * @member {Enum.EpicResult} result_code The result of the request. `EpicResult.Success` indicates the overlay was hidden.
 * @member {String} local_user_id The Product User ID of the local player who requested the overlay be hidden.
 *
 * @struct_end
 */

/**
 * @struct EpicUIShowBlockPlayerCallbackInfo
 * @desc The result of a ${function.eos_ui_show_block_player} request.
 *
 * @member {Enum.EpicResult} result_code The result of the request. `EpicResult.Success` indicates the overlay was shown.
 * @member {String} local_user_id The Product User ID of the local player who requested the overlay.
 * @member {String} target_user_id The Product User ID of the player to be blocked.
 *
 * @struct_end
 */

/**
 * @struct EpicUIShowReportPlayerCallbackInfo
 * @desc The result of a ${function.eos_ui_show_report_player} request.
 *
 * @member {Enum.EpicResult} result_code The result of the request. `EpicResult.Success` indicates the overlay was shown.
 * @member {String} local_user_id The Product User ID of the local player who requested the overlay.
 * @member {String} target_user_id The Product User ID of the player to be reported.
 *
 * @struct_end
 */

// Constants

/**
 * @const EpicUINotificationLocation
 * @desc **Epic Online Services Enum:** [EOS_UI_ENotificationLocation](https://dev.epicgames.com/docs/api-ref/enums/eos-ui-enotification-location)
 *
 * The screen corner notification/toast style overlay elements should appear in. Used by ${function.eos_ui_set_display_preference}/${function.eos_ui_get_notification_location_preference}.
 *
 * @member TopLeft
 * @member TopRight
 * @member BottomLeft
 * @member BottomRight
 *
 * @const_end
 */


/**
 * @module user_interface
 * @title User Interface
 * @desc **Epic Online Services Interface:** [UI Interface](https://dev.epicgames.com/docs/game-services/eos-ui-interface)
 *
 * The [UI Interface](https://dev.epicgames.com/docs/game-services/eos-ui-interface) controls Epic's built-in social overlay: the Friends list, native platform profile cards, block/report player dialogs, and controller-driven overlay navigation.
 *
 * [[Important: Any callback/notification elsewhere in this extension that hands you a `ui_event_id` must be acknowledged via ${function.eos_ui_acknowledge_event_id} - see that function's description.]]
 *
 * @section_func
 * @desc These functions are provided for controlling the social overlay:
 *
 * @ref eos_ui_show_friends
 * @ref eos_ui_show_native_profile
 * @ref eos_ui_acknowledge_event_id
 * @ref eos_ui_set_display_preference
 * @ref eos_ui_report_input_state
 * @ref eos_ui_add_notify_display_settings_updated
 * @ref eos_ui_remove_notify_display_settings_updated
 * @ref eos_ui_hide_friends
 * @ref eos_ui_get_friends_visible
 * @ref eos_ui_get_friends_exclusive_input
 * @ref eos_ui_pause_social_overlay
 * @ref eos_ui_is_social_overlay_paused
 * @ref eos_ui_get_notification_location_preference
 * @ref eos_ui_show_block_player
 * @ref eos_ui_show_report_player
 *
 * @section_end
 *
 * @section_struct
 * @desc These are the structs used by this API:
 *
 * @ref EpicUIShowFriendsCallbackInfo
 * @ref EpicUIShowNativeProfileCallbackInfo
 * @ref EpicUIDisplaySettingsUpdatedCallbackInfo
 * @ref EpicUIHideFriendsCallbackInfo
 * @ref EpicUIShowBlockPlayerCallbackInfo
 * @ref EpicUIShowReportPlayerCallbackInfo
 *
 * @section_end
 *
 * @section_const
 * @desc These are the constants used by this API:
 *
 * @ref EpicUINotificationLocation
 *
 * @section_end
 *
 * @module_end
 */
