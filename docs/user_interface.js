// Functions


/**
 * @function EpicGames_UI_AddNotifyDisplaySettingsUpdated
 * @desc **Epic Online Services Function:** [EOS_UI_AddNotifyDisplaySettingsUpdated](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UI/EOS_UI_AddNotifyDisplaySettingsUpdated/index.html)
 * 
 * This function registers to receive notifications when the overlay display settings are updated. Newly registered handlers will always be called the next tick with the current state.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_UI_AddNotifyDisplaySettingsUpdated"`
 * @member {bool} bIsExclusiveInput `true` when the overlay has switched to exclusive input mode. While in exclusive input mode, no keyboard or mouse input will be sent to the game.
 * @member {bool} bIsVisible `true` when any portion of the overlay is visible.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_UI_AddNotifyDisplaySettingsUpdated();
 * ```
 * The code sample above saves the identifier that can be used inside an ${event.social} event.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_UI_AddNotifyDisplaySettingsUpdated")
 * {
 *     var _is_exclusive_input = async_load[?"bIsExclusiveInput"];
 *     var _is_visible = async_load[?"bIsVisible"];
 * }
 * ```
 * The code above matches the response against the correct event **type** and logs the success of the task.
 * @function_end
 */

/**
 * @function EpicGames_UI_GetFriendsVisible
 * @desc **Epic Online Services Function:** [EOS_UI_GetFriendsVisible](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UI/EOS_UI_GetFriendsVisible/index.html)
 * 
 * This function gets the friends overlay visibility.
 * 
 * @param {real} accountID The Epic Account ID of the user whose overlay is being updated.
 * 
 * @returns {bool}
 * 
 * @example
 * ```gml
 * if (EpicGames_UI_GetFriendsVisible(accountID))
 * {
 *     PauseGame(); // add logic to pause the game here
 * }
 * ```
 * The above code shows an example of how the function should be used. If the Friends UI is being displayed, the developer must make sure the game is set to pause.
 * @function_end
 */

/**
 * @function EpicGames_UI_GetNotificationLocationPreference
 * @desc **Epic Online Services Function:** [EOS_UI_GetNotificationLocationPreference](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UI/EOS_UI_GetNotificationLocationPreference/index.html)
 * 
 * This function returns the current notification location display preference.
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * show_debug_message("LocationPreference: " + EpicGames_UI_GetNotificationLocationPreference());
 * ```
 * The above code shows an example of how the function should be used.
 * @function_end
 */

/**
 * @function EpicGames_UI_HideFriends
 * @desc **Epic Online Services Function:** [EOS_UI_HideFriends](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UI/EOS_UI_HideFriends/index.html)
 * 
 * This function hides the active Social Overlay.
 * 
 * @param {real} accountID The Epic Account ID of the user whose friend list is being shown.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_UI_HideFriends"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_UI_HideFriends();
 * ```
 * The code sample above saves the identifier that can be used inside an ${event.social} event.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_UI_HideFriends")
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
 * @function EpicGames_UI_RemoveNotifyDisplaySettingsUpdated
 * @desc **Epic Online Services Function:** [EOS_UI_RemoveNotifyDisplaySettingsUpdated](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UI/EOS_UI_RemoveNotifyDisplaySettingsUpdated/index.html)
 * 
 * This function unregisters from receiving notifications when the overlay display settings are updated.
 * 
 * @param {real} id The handle representing the registered callback (return by ${function.EpicGames_UI_AddNotifyDisplaySettingsUpdated})
 * 
 * @example
 * ```gml
 * handle = EpicGames_UI_AddNotifyDisplaySettingsUpdated();
 * //...
 * //...Later
 * //...
 * EpicGames_UI_RemoveNotifyDisplaySettingsUpdated(handle);
 * ```
 * The code sample above enables the display settings update notifications (${function.EpicGames_UI_AddNotifyDisplaySettingsUpdated}) and later disables them by referring to the previously generated handle.
 * @function_end
 */

/**
 * @function EpicGames_UI_SetDisplayPreference
 * @desc **Epic Online Services Function:** [EOS_UI_SetDisplayPreference](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UI/EOS_UI_SetDisplayPreference/index.html)
 * 
 * This function defines any preferences for any display settings.
 * 
 * @param {constant.EpicGames_UINotificationLocation} Location preference for notification pop-up locations.
 * 
 * @returns {struct}
 * @param {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @param {string} status_message Text representation of the status code
 * 
 * @example
 * ```gml
 * EpicGames_UI_SetDisplayPreference(EpicGames_UNL_TopLeft);
 * ```
 * The above code shows an example of how the function should be used. The position of the notifications will now be the top-left corner of the game screen.
 * @function_end
 */

/**
 * @function EpicGames_UI_ShowFriends
 * @desc **Epic Online Services Function:** [EOS_UI_ShowFriends](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/UI/EOS_UI_ShowFriends/index.html)
 * 
 * This function opens the Social Overlay with a request to show the friends list.
 * 
 * @param {real} arg The argument to be passed in
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_UI_ShowFriends"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_UI_ShowFriends();
 * ```
 * The code sample above saves the identifier that can be used inside an ${event.social} event.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_UI_ShowFriends")
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

// Constants

/**
 * @constant EpicGames_UINotificationLocation
 * @desc **Epic Online Services Enum:** [EOS_UI_ENotificationLocation](https://dev.epicgames.com/docs/api-ref/enums/eos-ui-e-notification-location)
 * 
 * The UI Notification Location allows to change the positioning of the EOS notifications.
 * 
 * @member EpicGames_UNL_TopLeft Positions the overlay notification on the top-left corner
 * @member EpicGames_UNL_TopRight Positions the overlay notification on the top-right corner
 * @member EpicGames_UNL_BottomLeft Positions the overlay notification on the bottom-left corner
 * @member EpicGames_UNL_BottomRight Positions the overlay notification on the bottom-right corner
 * @constant_end
 */


/**
 * @module User_Interface
 * @desc **Epic Online Services Interface:** [UI Interface](https://dev.epicgames.com/docs/epic-account-services/eosui-interface)
 * 
 * **Epic Online Services** (EOS) supports product-independent overlay windows through its overlay system; these overlays give users product-independent access to various features. The [UI Interface](https://dev.epicgames.com/docs/epic-account-services/eosui-interface) manages interactions with the overlays by providing status updates, showing or hiding the overlays, and adjusting display and hotkey preferences.
 * 
 * @section_func
 * @desc These functions are provided for handling title storage:

 * @ref EpicGames_UI_AddNotifyDisplaySettingsUpdated
 * @ref EpicGames_UI_GetFriendsVisible
 * @ref EpicGames_UI_GetNotificationLocationPreference
 * @ref EpicGames_UI_HideFriends
 * @ref EpicGames_UI_RemoveNotifyDisplaySettingsUpdated
 * @ref EpicGames_UI_SetDisplayPreference
 * @ref EpicGames_UI_ShowFriends
 * 
 * @section_end
 * 
 * @section_constant
 * @desc These are the constants used by this API:
 * 
 * @ref EpicGames_UINotificationLocation
 * 
 * @section_end
 * 
 * @module_end
 */
