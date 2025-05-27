// Functions

/**
 * @function eos_achievements_add_notify_achievements_unlocked_v2
 * @desc **Epic Online Services Function:** [EOS_Achievements_AddNotifyAchievementsUnlockedV2](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_AddNotifyAchievementsUnlockedV2/index.html)
 * 
 * This function registers to receive achievement unlocked notifications.
 * 
 * @event social
 * 
 * @member {string} type `"eos_achievements_add_notify_achievements_unlocked_v2"`
 * @member {int64} unlock_time POSIX timestamp when the achievement was unlocked
 * @member {string} achievement_id The achievement ID for the achievement that was unlocked. Pass this to ${function.eos_achievements_copy_player_achievement_by_achievement_id} to get the full achievement information.
 * @member {string} user_id The Product User ID for the user who received the unlocked achievements notification
 * 
 * @event_end
 * 
 * @returns {int64}
 * 
 * @example
 * 
 * ```gml
 * identifier = eos_achievements_add_notify_achievements_unlocked_v2();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_achievements_add_notify_achievements_unlocked_v2")
 * if(async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EOS_Result.Success)
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
 * @function eos_achievements_copy_achievement_definition_v2_by_achievement_id
 * @desc **Epic Online Services Function:** [EOS_Achievements_CopyAchievementDefinitionV2ByAchievementId](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_CopyAchievementDefinitionV2ByAchi/index.html)
 * 
 * This function fetches an ${struct.AchievementDefinition} from a given achievement ID.
 * 
 * [[Note: Requires a previous call to ${function.eos_achievements_query_definitions} to store values in cache.]]
 * 
 * @param {string} achievement_id Achievement ID to look for when copying the definition from the cache
 *
 * @returns {struct.AchievementDefinition}
 * 
 * @example
 * 
 * ```gml
 * var _struct = eos_achievements_copy_achievement_definition_v2_by_achievement_id("MyAchievement1");
 * if(_struct.status == EOS_Result.Success)
 * {
 *     var _achievement_id = _struct.achievement_id;
 * }
 * ```
 * The above code will show an example of how the function should be used. The achievement definition data is returned providing an achievement ID.
 * @function_end
 */

/**
 * @function eos_achievements_copy_achievement_definition_v2_by_index
 * @desc **Epic Online Services Function:** [EOS_Achievements_CopyAchievementDefinitionV2ByIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_CopyAchievementDefinitionV2ByIndex/index.html)
 * 
 * This function fetches an ${struct.AchievementDefinition} from a given index.
 * 
 * [[Note: Requires a previous call to ${function.eos_achievements_query_definitions} to store values in cache.]]
 * 
 * @param {real} index Index of the achievement definition to retrieve from the cache
 * 
 * @returns {struct.AchievementDefinition}
 * 
 * @example
 * ```gml
 * for(var i = 0 ; i < eos_achievements_get_achievement_definition_count() ; i ++)
 * {
 *     var _struct = eos_achievements_copy_achievement_definition_v2_by_index(i);
 *     if(_struct.status == EOS_Result.Success)
 *     {
 *         var _achievement_id = _struct.achievement_id;
 *     }
 * }
 * ```
 * The above code shows an example of how the function should be used. The achievement definition data is returned providing an achievement index.
 * @function_end
 */

/**
 * @function eos_achievements_copy_player_achievement_by_achievement_id
 * @desc **Epic Online Services Function:** [EOS_Achievements_CopyPlayerAchievementByAchievementId](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_CopyPlayerAchievementByAchievemen/index.html)
 * 
 * This function fetches a player achievement from a given achievement ID.
 * 
 * [[Note: Requires a previous call to ${function.eos_achievements_query_player_achievements} to store values in cache.]]
 * 
 * @param {string} user_id The Product User ID for the user who is querying for a player achievement. For a Dedicated Server this value will not be present in the struct.
 * @param {string} user_id_target The Product User ID for the user whose achievement is to be retrieved
 * @param {string} achievement_id Achievement ID to search for when retrieving player achievement data from the cache
 * 
 * @returns {struct.PlayerAchievement}
 * 
 * @example
 * ```gml
 * var _struct = eos_achievements_copy_player_achievement_by_achievement_id(user_id, user_id_target, achievement_id);
 * if(_struct.status == EOS_Result.Success)
 * {
 *     var _achievement_id = _struct.achievement_id;
 * }
 * ```
 * The above code will show an example of how the function should be used. The player achievement data is returned providing an achievement ID.
 * @function_end
 */

/**
 * @function eos_achievements_copy_player_achievement_by_index
 * @desc **Epic Online Services Function:** [EOS_Achievements_CopyPlayerAchievementByIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_CopyPlayerAchievementByAchievemen/index.html)
 * 
 * This function fetches a player achievement from a given index.
 * 
 * [[Note: Requires a previous call to ${function.eos_achievements_query_player_achievements} to store values in cache.]]
 * 
 * @param {string} user_id The Product User ID for the user who is querying for a player achievement. For a Dedicated Server this value will not be present in the struct.
 * @param {string} user_id_target The Product User ID for the user whose achievement is to be retrieved
 * @param {real} index The index of the player achievement data to retrieve from the cache
 * 
 * @returns {struct.PlayerAchievement}
 * 
 * @example
 * ```gml
 * for(var i = 0 ; i < eos_achievements_get_player_achievement_count(userID) ; i ++)
 * {
 *     var _struct = eos_achievements_copy_player_achievement_by_index(i);
 *     if(_struct.status == EOS_Result.Success)
 *     {
 *         var _achievement_id = _struct.achievement_id;
 *     }
 * }
 * ```
 * The above code will show an example of how the function should be used. The player achievement data is returned providing an achievement index.
 * @function_end
 */

/**
 * @function eos_achievements_get_achievement_definition_count
 * @desc **Epic Online Services Function:** [EOS_Achievements_GetAchievementDefinitionCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_GetAchievementDefinitionCount/index.html)
 * 
 * This function fetches the number of achievement definitions that are cached locally.
 * 
 * [[Note: Requires a previous call to ${function.eos_achievements_query_definitions} to store values in cache.]]
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * for(var i = 0 ; i < eos_achievements_get_achievement_definition_count() ; i ++)
 * {
 *     var _struct = eos_achievements_copy_achievement_definition_v2_by_index(i);
 *     if(_struct.status == EOS_Result.Success)
 *     {
 *         var _achievement_id = _struct.achievement_id;
 *     }
 * }
 * ```
 * The above code will show an example of how the function should be used. After a successful call to ${function.eos_achievements_query_definitions}, the function ${function.eos_achievements_get_achievement_definition_count} will return the number of entries in the query array which can then be accessed using the ${function.eos_achievements_copy_achievement_definition_v2_by_index} function.
 * @function_end
 */

/**
 * @function eos_achievements_get_player_achievement_count
 * @desc **Epic Online Services Function:** [EOS_Achievements_GetPlayerAchievementCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_GetPlayerAchievementCount/index.html)
 * 
 * This function fetches the number of player achievements that are cached locally.
 * 
 * [[Note: Requires a previous call to ${function.eos_achievements_query_player_achievements} to store values in cache.]]
 * 
 * @param {string} user_id The Product User ID for the user whose achievement count is being retrieved
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * for(var i = 0 ; i < eos_achievements_get_player_achievement_count(userID) ; i ++)
 * {
 *     var _struct = eos_achievements_copy_player_achievement_by_index(i);
 *     if(_struct.status == EOS_Result.Success)
 *     {
 *         var _achievement_id = _struct.achievement_id;
 *     }
 * }
 * ```
 * The above code will show an example of how the function should be used. After a successful call to ${function.eos_achievements_query_player_achievements}, the function ${function.eos_achievements_get_player_achievement_count} will return the number of entries in the query array which can then be accessed using the ${function.eos_achievements_copy_player_achievement_by_index} function.
 * @function_end
 */

/**
 * @function eos_achievements_query_definitions
 * @desc **Epic Online Services Function:** [EOS_Achievements_QueryDefinitions](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_QueryDefinitions/index.html)
 * 
 * This function queries for a list of definitions for all existing achievements, including localized text, icon IDs and whether an achievement is hidden.
 * Once the callback has been fired with a successful ${constant.EOS_Result}, it is possible to call one of the following functions:
 * 
 * * ${function.eos_achievements_copy_achievement_definition_v2_by_achievement_id}
 * * ${function.eos_achievements_copy_achievement_definition_v2_by_index}
 * * ${function.eos_achievements_get_achievement_definition_count}
 * 
 * @param {string} user_id Product User ID for user who is querying definitions.
 * 
 * @event social
 * @member {string} type `"eos_achievements_query_definitions"`
 * @member {constant.EOS_Result} status The status code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @returns {real}
 * 
 * @example
 * 
 * ```gml
 * identifier = eos_achievements_query_definitions(user_id);
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_achievements_query_definitions")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EOS_Result.Success)
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
 * @function eos_achievements_query_player_achievements
 * @desc **Epic Online Services Function:** [EOS_Achievements_QueryPlayerAchievements](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_QueryPlayerAchievements/index.html)
 * 
 * This function queries for a list of achievements for a specific player, including progress towards completion for each achievement.
 * 
 * Once the callback has been fired with a successful ${constant.EOS_Result}, it is possible to call one of the following functions:
 * 
 * * ${function.eos_achievements_copy_player_achievement_by_achievement_id}
 * * ${function.eos_achievements_copy_player_achievement_by_index}
 * * ${function.eos_achievements_get_player_achievement_count}
 * 
 * @param {string} user_id The Product User ID for the user who is querying for player achievements. For a Dedicated Server this value will not be present in the struct.
 * @param {string} user_id_target The Product User ID for the user whose achievements are to be retrieved
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type `"eos_achievements_query_player_achievements"`
 * @member {constant.EOS_Result} status The status code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * 
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_achievements_query_player_achievements(user_id, user_id);
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_achievements_query_player_achievements")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EOS_Result.Success)
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
 * @function eos_achievements_remove_notify_achievements_unlocked
 * @desc **Epic Online Services Function:** [EOS_Achievements_RemoveNotifyAchievementsUnlocked](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_RemoveNotifyAchievementsUnlocked/index.html)
 * 
 * This function unregisters from receiving achievement unlocked notifications, should be passed the identifier returned from the function:
 * 
 * * ${function.eos_achievements_add_notify_achievements_unlocked_v2}
 * 
 * @param {real} id The notification registration handle (returned by ${function.eos_achievements_add_notify_achievements_unlocked_v2})
 * 
 * @example
 * ```gml
 * handle = eos_achievements_add_notify_achievements_unlocked_v2();
 * //...
 * //later...
 * //...
 * eos_achievements_remove_notify_achievements_unlocked(handle);
 * ```
 * The code sample above enables the achievement unlock notifications (${function.eos_achievements_add_notify_achievements_unlocked_v2}) and later disables them by referring to the previously generated handle.
 * @function_end
 */

/**
 * @function eos_achievements_unlock_achievement
 * @desc **Epic Online Services Function:** [EOS_Achievements_UnlockAchievements](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_UnlockAchievements/index.html)
 * 
 * This function unlocks an achievement for a specific player.
 * 
 * @param {string} user_id The Product User ID for the user whose achievements we want to unlock
 * @param {string} achievement_id Achievement ID to unlock
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_achievements_unlock_achievement"`
 * @member {constant.EOS_Result} status The status code for the operation. `EOS_Result.Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @example
 * 
 * 
 * ```gml
 * identifier = eos_achievements_unlock_achievement();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_achievements_unlock_achievement")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EOS_Result.Success)
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


// Structs

/**
 * @struct PlayerAchievement
 * @desc A player achievement is represented by a struct and contains information about a single player achievement.
 * 
 * The status member present in the struct can be represented by one of the following values:
 * 
 * * `EOS_Result.Success` if the information is available and was correctly returned;
 * * `EOS_Result.InvalidParameters` (extension internal error, should never be returned);
 * * `EOS_Result.NotFound` if the achievement definition is not found;
 * * `EOS_Result.Invalid_ProductUserID` if you pass an invalid user ID;
 * 
 * @member {constant.EOS_Result} status The result value of the task
 * @member {string} status_message Text representation of the status code
 * @member {string} achievement_id This achievement's unique identifier
 * @member {real} progress Progress towards completing this achievement (as a percentage)
 * @member {string} unlock_time The POSIX timestamp when the achievement was unlocked. If the achievement has not been unlocked, this value will be `EOS_ACHIEVEMENTS_ACHIEVEMENT_UNLOCKTIME_UNDEFINED`.
 * @member {string} stat_info_count The number of player stat info entries associated with this achievement.
 * @member {array[struct.PlayerStatInfo]} stat_info Array of ${struct.PlayerStatInfo} structures containing information about stat thresholds used to unlock the achievement and the player's current values for those stats
 * @member {string} display_name Localized display name for the achievement based on this specific player's current progress on the achievement
 * @member {string} description Localized description for the achievement based on this specific player's current progress on the achievement
 * @member {string} icon_url URL of an icon to display for the achievement based on this specific player's current progress on the achievement. This value may not be present in the struct if there is no data configured in the developer portal
 * @member {string} flavor_text Localized flavor text that can be used by the game in an arbitrary manner. This value may not be present in the struct if there is no data configured in the developer portal
 * @struct_end
 */

/**
 * @struct PlayerStatInfo
 * @desc **Epic Online Services Struct:** (EOS_Achievements_StatThresholds)[https://dev.epicgames.com/docs/en-US/api-ref/structs/eos-achievements-stat-thresholds]
 * 
 * This struct contains information about a collection of stat threshold data.
 * 
 * @member {string} name The name of the stat.
 * @member {real} api_version The API version.
 * @member {real} current_value The current value of the stat.
 * @member {real} threshold_value The value that the stat must surpass to satisfy the requirement for unlocking an achievement.
 * @struct_end
 */

/**
 * @struct AchievementDefinition
 * @desc An achievement definition is represented by a struct and contains information about a single achievement definition with localised text.
 * 
 *   The status member present in the struct can be represented by one of the following values:
 *   
 * * `EOS_Result.Success` if the information is available and was correctly returned;
 * * `EOS_Result.InvalidParameters` (extension internal error, should never be returned);
 * * `EOS_Result.NotFound` if the achievement definition is not found;
 * * `EOS_Result.Invalid_ProductUserID` if any of the user_id options are incorrect;
 * 
 * @member {constant.EOS_Result} status The result value of the task
 * @member {string} status_message Text representation of the status code
 * @member {string} achievement_id Achievement ID that can be used to uniquely identify the achievement
 * @member {string} unlocked_display_name Localized display name for the achievement when it has been unlocked
 * @member {string} unlocked_description Localized description for the achievement when it has been unlocked
 * @member {string} locked_display_name Localized display name for the achievement when it is locked or hidden
 * @member {string} locked_description Localized description for the achievement when it is locked or hidden
 * @member {string} flavor_text Localized flavor text that can be used by the game in an arbitrary manner. This value may not be present in the struct if there is no data configured in the development portal
 * @member {string} unlocked_icon_url URL of an icon to display for the achievement when it is unlocked. This value may not be present in the struct if there is no data configured in the development portal
 * @member {string} locked_icon_url URL of an icon to display for the achievement when it is locked or hidden. This value may not be present in the struct if there is no data configured in the development portal
 * @member {bool} is_hidden `true` if the achievement is hidden; `false` otherwise
 * @struct_end
 */


/**
 * @module achievements
 * @title Achievements
 * @desc **Epic Online Services Interface:** [Achievements Interface](https://dev.epicgames.com/docs/game-services/achievements)
 * 
 * The **[Achievements Interface](https://dev.epicgames.com/docs/game-services/achievements)** provides a way for developers to retrieve data about a player's Epic Online Services achievements, unlock achievements for that player, and retrieve data about all of the Epic Online Services achievements belonging to an application.
 * 
 * @section_func
 * @desc These functions are provided for handling achievements:
 * @ref eos_achievements_add_notify_achievements_unlocked_v2
 * @ref eos_achievements_copy_achievement_definition_v2_by_achievement_id
 * @ref eos_achievements_copy_achievement_definition_v2_by_index
 * @ref eos_achievements_copy_player_achievement_by_achievement_id
 * @ref eos_achievements_copy_player_achievement_by_index
 * @ref eos_achievements_get_achievement_definition_count
 * @ref eos_achievements_get_player_achievement_count
 * @ref eos_achievements_query_definitions
 * @ref eos_achievements_query_player_achievements
 * @ref eos_achievements_remove_notify_achievements_unlocked
 * @ref eos_achievements_unlock_achievement
 * @section_end
 * 
 * @section_struct
 * @desc These are the structures used by this API:
 * @ref AchievementDefinition
 * @ref PlayerAchievement
 * @ref PlayerStatInfo
 * @section_end
 * 
 * @module_end
 */
