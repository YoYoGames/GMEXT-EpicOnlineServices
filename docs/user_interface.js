// Functions

/**
 * @function eos_ui_acknowledge_event_id
 * @desc **Epic Online Services Function:** [EOS_UI_AcknowledgeEventId](https://dev.epicgames.com/docs/api-ref/functions/eos-ui-acknowledge-event-id)
 * 
 * This function lets the SDK know that the given UI event ID has been acknowledged and should be released. `EOS_RESULT.SUCCESS` is returned if the UI event ID has been acknowledged. `EOS_RESULT.NOT_FOUND` is returned if the UI event ID does not exist.
 * 
 * @param {real} ui_event_id The event ID being acknowledged
 * 
 * @returns {constant.EOS_RESULT}
 * 
 * @function_end
 */

/**
 * @function eos_ui_add_notify_display_settings_updated
 * @desc **Epic Online Services Function:** [EOS_UI_AddNotifyDisplaySettingsUpdated](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UI/EOS_UI_AddNotifyDisplaySettingsUpdated/index.html)
 * 
 * This function registers to receive notifications when the overlay display settings are updated. Newly registered handlers will always be called the next tick with the current state.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_ui_add_notify_display_settings_updated"`
 * @member {bool} is_exclusive_input `true` when the overlay has switched to exclusive input mode. While in exclusive input mode, no keyboard or mouse input will be sent to the game.
 * @member {bool} is_visible `true` when any portion of the overlay is visible.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_ui_add_notify_display_settings_updated();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_ui_add_notify_display_settings_updated")
 * {
 *     var _is_exclusive_input = async_load[? "is_exclusive_input"];
 *     var _is_visible = async_load[? "is_visible"];
 * }
 * ```
 * The code above matches the response against the correct event **type** and logs the success of the task.
 * @function_end
 */

/**
 * @function eos_ui_get_friends_visible
 * @desc **Epic Online Services Function:** [EOS_UI_GetFriendsVisible](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UI/EOS_UI_GetFriendsVisible/index.html)
 * 
 * This function gets the friends overlay visibility.
 * 
 * @param {real} account_id The Epic Account ID of the user whose overlay is being updated.
 * 
 * @returns {bool}
 * 
 * @example
 * ```gml
 * if (eos_ui_get_friends_visible(account_id))
 * {
 *     pause_game(); // add logic to pause the game here
 * }
 * ```
 * The above code shows an example of how the function should be used. If the Friends UI is being displayed, the developer must make sure the game is set to pause.
 * @function_end
 */

/**
 * @function eos_ui_get_notification_location_preference
 * @desc **Epic Online Services Function:** [EOS_UI_GetNotificationLocationPreference](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UI/EOS_UI_GetNotificationLocationPreference/index.html)
 * 
 * This function returns the current notification location display preference.
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * show_debug_message("LocationPreference: " + eos_ui_get_notification_location_preference());
 * ```
 * The above code shows an example of how the function should be used.
 * @function_end
 */

/**
 * @function eos_ui_hide_friends
 * @desc **Epic Online Services Function:** [EOS_UI_HideFriends](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UI/EOS_UI_HideFriends/index.html)
 * 
 * This function hides the active Social Overlay.
 * 
 * @param {real} account_id The Epic Account ID of the user whose friend list is being shown
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_ui_hide_friends"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_ui_hide_friends();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_ui_hide_friends")
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
 * @function eos_ui_remove_notify_display_settings_updated
 * @desc **Epic Online Services Function:** [EOS_UI_RemoveNotifyDisplaySettingsUpdated](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UI/EOS_UI_RemoveNotifyDisplaySettingsUpdated/index.html)
 * 
 * This function unregisters from receiving notifications when the overlay display settings are updated.
 * 
 * @param {real} id The handle representing the registered callback (return by ${function.eos_ui_add_notify_display_settings_updated})
 * 
 * @example
 * ```gml
 * handle = eos_ui_add_notify_display_settings_updated();
 * //...
 * //...Later
 * //...
 * eos_ui_remove_notify_display_settings_updated(handle);
 * ```
 * The code sample above enables the display settings update notifications (${function.eos_ui_add_notify_display_settings_updated}) and later disables them by referring to the previously generated handle.
 * @function_end
 */

/**
 * @function eos_ui_set_display_preference
 * @desc **Epic Online Services Function:** [EOS_UI_SetDisplayPreference](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UI/EOS_UI_SetDisplayPreference/index.html)
 * 
 * This function defines any preferences for any display settings.
 * 
 * @param {constant.EOS_UI_NOTIFICATION_LOCATION} location The preference for notification pop-up locations
 * 
 * @returns {struct.EpicResult}
 * 
 * @example
 * ```gml
 * eos_ui_set_display_preference(EOS_UI_NOTIFICATION_LOCATION.TOP_LEFT);
 * ```
 * The above code shows an example of how the function should be used. The position of the notifications will now be the top-left corner of the game screen.
 * @function_end
 */

/**
 * @function eos_ui_show_friends
 * @desc **Epic Online Services Function:** [EOS_UI_ShowFriends](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UI/EOS_UI_ShowFriends/index.html)
 * 
 * This function opens the Social Overlay with a request to show the friends list.
 * 
 * @param {real} arg The argument to be passed in
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_ui_show_friends"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_ui_show_friends();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_ui_show_friends")
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

// Constants

/**
 * @constant EOS_UI_NOTIFICATION_LOCATION
 * @desc **Epic Online Services Enum:** [EOS_UI_ENotificationLocation](https://dev.epicgames.com/docs/api-ref/enums/eos-ui-e-notification-location)
 * 
 * The UI Notification Location allows to change the positioning of the EOS notifications.
 * 
 * @member TOP_LEFT Positions the overlay notification on the top-left corner
 * @member TOP_RIGHT Positions the overlay notification on the top-right corner
 * @member BOTTOM_LEFT Positions the overlay notification on the bottom-left corner
 * @member BOTTOM_RIGHT Positions the overlay notification on the bottom-right corner
 * @constant_end
 */


/**
 * @module user_interface
 * @title User Interface
 * @desc **Epic Online Services Interface:** [UI Interface](https://dev.epicgames.com/docs/epic-account-services/eosui-interface)
 * 
 * **Epic Online Services** (EOS) supports product-independent overlay windows through its overlay system; these overlays give users product-independent access to various features. The [UI Interface](https://dev.epicgames.com/docs/epic-account-services/eosui-interface) manages interactions with the overlays by providing status updates, showing or hiding the overlays, and adjusting display and hotkey preferences.
 * 
 * @section_func
 * @desc These functions are provided for handling user interface:
 * 
 * @ref eos_ui_acknowledge_event_id
 * @ref eos_ui_add_notify_display_settings_updated
 * @ref eos_ui_get_friends_visible
 * @ref eos_ui_get_notification_location_preference
 * @ref eos_ui_hide_friends
 * @ref eos_ui_remove_notify_display_settings_updated
 * @ref eos_ui_set_display_preference
 * @ref eos_ui_show_friends
 * 
 * @section_end
 * 
 * @section_constant
 * @desc These are the constants used by this API:
 * 
 * @ref EOS_UI_NOTIFICATION_LOCATION
 * 
 * @section_end
 * 
 * @module_end
 */
