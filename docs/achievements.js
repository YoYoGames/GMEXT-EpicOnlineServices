// Functions

/**
 * @function EpicGames_Achievements_AddNotifyAchievementsUnlockedV2
 * @desc **Epic Online Services Function:** [EOS_Achievements_AddNotifyAchievementsUnlockedV2](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_AddNotifyAchievementsUnlockedV2/index.html)
 * 
 * This function registers to receive achievement unlocked notifications.
 * 
 * @event social
 * 
 * @member {string} type `"EpicGames_Achievements_AddNotifyAchievementsUnlockedV2"`
 * @member {int64} UnlockTime POSIX timestamp when the achievement was unlocked
 * @member {string} AchievementId The Achievement ID for the achievement that was unlocked. Pass this to ${function.EpicGames_Achievements_CopyPlayerAchievementByAchievementId} to get the full achievement information.
 * @member {string} UserId The Product User ID for the user who received the unlocked achievements notification
 * 
 * @event_end
 * 
 * @returns {int64}
 * 
 * @example
 * 
 * ```gml
 * identifier = EpicGames_Achievements_AddNotifyAchievementsUnlockedV2();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Achievements_AddNotifyAchievementsUnlockedV2")
 * if(async_load[? "identifier"] == identifier)
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
 * @function EpicGames_Achievements_CopyAchievementDefinitionV2ByAchievementId
 * @desc **Epic Online Services Function:** [EOS_Achievements_CopyAchievementDefinitionV2ByAchievementId](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_CopyAchievementDefinitionV2ByAchi/index.html)
 * 
 * This function fetches an ${struct.AchievementDefinition} from a given achievement ID.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_Achievements_QueryDefinitions} to store values in cache.]]
 * 
 * @param {string} AchievementId Achievement ID to look for when copying the definition from the cache
 *
 * @returns {struct.AchievementDefinition}
 * 
 * @example
 * 
 * ```gml
 * var _struct = EpicGames_Achievements_CopyAchievementDefinitionV2ByAchievementId("MyAchievement1");
 * if(_struct.status == EpicGames_Success)
 * {
 *     var _achievement_id = _struct.AchievementId;
 * }
 * ```
 * The above code will show an example of how the function should be used. The achievement definition data is returned providing an achievement ID.
 * @function_end
 */

/**
 * @function EpicGames_Achievements_CopyAchievementDefinitionV2ByIndex
 * @desc **Epic Online Services Function:** [EOS_Achievements_CopyAchievementDefinitionV2ByIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_CopyAchievementDefinitionV2ByIndex/index.html)
 * 
 * This function fetches an ${struct.AchievementDefinition} from a given index.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_Achievements_QueryDefinitions} to store values in cache.]]
 * 
 * @param {real} index Index of the achievement definition to retrieve from the cache
 * 
 * @returns {struct.AchievementDefinition}
 * 
 * @example
 * ```gml
 * for(var i = 0 ; i < EpicGames_Achievements_GetAchievementDefinitionCount() ; i ++)
 * {
 *     var _struct = EpicGames_Achievements_CopyAchievementDefinitionV2ByIndex(i);
 *     if(_struct.status == EpicGames_Success)
 *     {
 *          var _achievement_id = _struct.AchievementId;
 *     }
 * }
 * ```
 * The above code shows an example of how the function should be used. The achievement definition data is returned providing an achievement index.
 * @function_end
 */

/**
 * @function EpicGames_Achievements_CopyPlayerAchievementByAchievementId
 * @desc **Epic Online Services Function:** [EOS_Achievements_CopyPlayerAchievementByAchievementId](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_CopyPlayerAchievementByAchievemen/index.html)
 * 
 * This function fetches a player achievement from a given achievement ID.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_Achievements_QueryPlayerAchievements} to store values in cache.]]
 * 
 * @param {string} userID The Product User ID for the user who is querying for a player achievement. For a Dedicated Server this should be null.
 * @param {string} userID_target The Product User ID for the user whose achievement is to be retrieved.
 * @param {string} achievementID Achievement ID to search for when retrieving player achievement data from the cache.
 * 
 * @returns {struct.PlayerAchievement}
 * 
 * @example
 * ```gml
 * var _struct = EpicGames_Achievements_CopyPlayerAchievementByAchievementId(userID, userID_target, achievementID);
 * if(struct.status == EpicGames_Success)
 * {
 *     var _achievementd = _struct.AchievementId;_i
 * }
 * ```
 * The above code will show an example of how the function should be used. The player achievement data is returned providing an achievement ID.
 * @function_end
 */

/**
 * @function EpicGames_Achievements_CopyPlayerAchievementByIndex
 * @desc **Epic Online Services Function:** [EOS_Achievements_CopyPlayerAchievementByIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_CopyPlayerAchievementByAchievemen/index.html)
 * 
 * This function fetches a player achievement from a given index.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_Achievements_QueryPlayerAchievements} to store values in cache.]]
 * 
 * @param {string} userID The Product User ID for the user who is querying for a player achievement. For a Dedicated Server this should be null.
 * @param {string} userID_target The Product User ID for the user whose achievement is to be retrieved.
 * @param {real} index The index of the player achievement data to retrieve from the cache.
 * 
 * @returns {struct.PlayerAchievement}
 * 
 * @example
 * ```gml
 * for(var i = 0 ; i < EpicGames_Achievements_GetPlayerAchievementCount(userID) ; i ++)
 * {
 *     var _struct = EpicGames_Achievements_CopyPlayerAchievementByIndex(i);
 *     if(_struct.status == EpicGames_Success)
 *     {
 *          var _achievement_id = _struct.AchievementId;
 *     }
 * }
 * ```
 * The above code will show an example of how the function should be used. The player achievement data is returned providing an achievement index.
 * @function_end
 */

/**
 * @function EpicGames_Achievements_GetAchievementDefinitionCount
 * @desc **Epic Online Services Function:** [EOS_Achievements_GetAchievementDefinitionCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_GetAchievementDefinitionCount/index.html)
 * 
 * This function fetches the number of achievement definitions that are cached locally.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_Achievements_QueryDefinitions} to store values in cache.]]
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * for(var i = 0 ; i < EpicGames_Achievements_GetAchievementDefinitionCount() ; i ++)
 * {
 *     var _struct = EpicGames_Achievements_CopyAchievementDefinitionV2ByIndex(i);
 *     if(_struct.status == EpicGames_Success)
 *     {
 *          var _achievement_id = _struct.AchievementId;
 *     }
 * }
 * ```
 * The above code will show an example of how the function should be used. After a successful call to ${function.EpicGames_Achievements_QueryDefinitions}, the function ${function.EpicGames_Achievements_GetAchievementDefinitionCount} will return the number of entries in the query array which can then be accessed using the ${function.EpicGames_Achievements_CopyAchievementDefinitionV2ByIndex} function.
 * @function_end
 */

/**
 * @function EpicGames_Achievements_GetPlayerAchievementCount
 * @desc **Epic Online Services Function:** [EOS_Achievements_GetPlayerAchievementCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_GetPlayerAchievementCount/index.html)
 * 
 * This function fetches the number of player achievements that are cached locally.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_Achievements_QueryPlayerAchievements} to store values in cache.]]
 * 
 * @param {string} userID The Product User ID for the user whose achievement count is being retrieved.
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * for(var i = 0 ; i < EpicGames_Achievements_GetPlayerAchievementCount(userID) ; i ++)
 * {
 *     var _struct = EpicGames_Achievements_CopyPlayerAchievementByIndex(i);
 *     if(_struct.status == EpicGames_Success)
 *     {
 *          var _achievement_id = _struct.AchievementId;
 *     }
 * }
 * ```
 * The above code will show an example of how the function should be used. After a successful call to ${function.EpicGames_Achievements_QueryPlayerAchievements}, the function ${function.EpicGames_Achievements_GetPlayerAchievementCount} will return the number of entries in the query array which can then be accessed using the ${function.EpicGames_Achievements_CopyPlayerAchievementByIndex} function.
 * @function_end
 */

/**
 * @function EpicGames_Achievements_QueryDefinitions
 * @desc **Epic Online Services Function:** [EOS_Achievements_QueryDefinitions](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_QueryDefinitions/index.html)
 * 
 * This function queries for a list of definitions for all existing achievements, including localized text, icon IDs and whether an achievement is hidden.
 * Once the callback has been fired with a successful ${constant.EpicGames_Result}, it is possible to call one of the following functions:
 * 
 * * ${function.EpicGames_Achievements_CopyAchievementDefinitionV2ByAchievementId}
 * * ${function.EpicGames_Achievements_CopyAchievementDefinitionV2ByIndex}
 * * ${function.EpicGames_Achievements_GetAchievementDefinitionCount}
 * 
 * @param {string} userId Product User ID for user who is querying definitions.
 * 
 * @event social
 * @member {string} type `"EpicGames_Achievements_QueryDefinitions"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @returns {real}
 * 
 * @example
 * 
 * ```gml
 * identifier = EpicGames_Achievements_QueryDefinitions(userId);
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Achievements_QueryDefinitions")
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
 * @function EpicGames_Achievements_QueryPlayerAchievements
 * @desc **Epic Online Services Function:** [EOS_Achievements_QueryPlayerAchievements](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_QueryPlayerAchievements/index.html)
 * 
 * This function queries for a list of achievements for a specific player, including progress towards completion for each achievement.
 * 
 * Once the callback has been fired with a successful ${constant.EpicGames_Result}, it is possible to call one of the following functions:
 * 
 * * ${function.EpicGames_Achievements_CopyPlayerAchievementByAchievementId}
 * * ${function.EpicGames_Achievements_CopyPlayerAchievementByIndex}
 * * ${function.EpicGames_Achievements_GetPlayerAchievementCount}
 * 
 * @param {string} userID The Product User ID for the user who is querying for player achievements. For a Dedicated Server this should be null.
 * @param {string} userID_target The Product User ID for the user whose achievements are to be retrieved.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type `"EpicGames_Achievements_QueryPlayerAchievements"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * 
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_Achievements_QueryPlayerAchievements(userID, userID);
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Achievements_QueryPlayerAchievements")
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
 * @function EpicGames_Achievements_RemoveNotifyAchievementsUnlocked
 * @desc **Epic Online Services Function:** [EOS_Achievements_RemoveNotifyAchievementsUnlocked](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_RemoveNotifyAchievementsUnlocked/index.html)
 * 
 * This function unregisters from receiving achievement unlocked notifications, should be passed the identifier returned from the function:
 * 
 * * ${function.EpicGames_Achievements_AddNotifyAchievementsUnlockedV2}
 * 
 * @param {real} id The notification registration handle (returned by ${function.EpicGames_Achievements_AddNotifyAchievementsUnlockedV2})
 * 
 * @example
 * ```gml
 * handle = EpicGames_Achievements_AddNotifyAchievementsUnlockedV2();
 * //...
 * //later...
 * //...
 * EpicGames_Achievements_RemoveNotifyAchievementsUnlocked(handle);
 * ```
 * The code sample above enables the achievement unlock notifications (${function.EpicGames_Achievements_AddNotifyAchievementsUnlockedV2}) and later disables them by referring to the previous generated handle.
 * @function_end
 */

/**
 * @function EpicGames_Achievements_UnlockAchievement
 * @desc **Epic Online Services Function:** [EOS_Achievements_UnlockAchievements](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Achievements/EOS_Achievements_UnlockAchievements/index.html)
 * 
 * This function unlocks an achievement for a specific player.
 * 
 * @param {string} userID The Product User ID for the user whose achievements we want to unlock.
 * @param {string} AchievementID Achievement ID to unlock.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"EpicGames_Achievements_UnlockAchievement"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * 
 * 
 * ```gml
 * identifier = EpicGames_Achievements_UnlockAchievement();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Achievements_UnlockAchievement")
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


// Structs

/**
 * @struct PlayerAchievement
 * @desc A player achievement is represented by a struct and contains information about a single player achievement.
 * 
 * The status member present in the struct can be represented by one of the following values:
 * 
 * * `EpicGames_Success` if the information is available and was correctly returned;
 * * `EpicGames_InvalidParameters` (extension internal error, should never be returned);
 * * `EpicGames_NotFound` if the achievement definition is not found;
 * * `EpicGames_Invalid_ProductUserID` if you pass an invalid user ID;
 * 
 * @member {constant.EpicGames_Result} status The result value of the task
 * @member {string} status_message Text representation of the status code
 * @member {string} AchievementId This achievement's unique identifier
 * @member {real} Progress Progress towards completing this achievement (as a percentage)
 * @member {string} UnlockTime The POSIX timestamp when the achievement was unlocked. If the achievement has not been unlocked, this value will be `EpicGames_ACHIEVEMENTS_ACHIEVEMENT_UNLOCKTIME_UNDEFINED`.
 * @member {string} StatInfoCount The number of player stat info entries associated with this achievement.
 * @member {array} StatInfo Array of EpicGames_Achievements_PlayerStatInfo structures containing information about stat thresholds used to unlock the achievement and the player's current values for those stats
 * @member {string} DisplayName Localized display name for the achievement based on this specific player's current progress on the achievement
 * @member {string} Description Localized description for the achievement based on this specific player's current progress on the achievement
 * @member {string} IconURL URL of an icon to display for the achievement based on this specific player's current progress on the achievement. This may be null if there is no data configured in the developer portal
 * @member {string} FlavorText Localized flavor text that can be used by the game in an arbitrary manner. This may be null if there is no data configured in the developer portal
 * @struct_end
 */

/**
 * @struct AchievementDefinition
 * @desc An achievement definition is represented by a struct and contains information about a single achievement definition with localised text.
 * 
 *   The status member present in the struct can be represented by one of the following values:
 *   
 * * `EpicGames_Success` if the information is available and was correctly returned;
 * * `EpicGames_InvalidParameters` (extension internal error, should never be returned);
 * * `EpicGames_NotFound` if the achievement definition is not found;
 * * `EpicGames_Invalid_ProductUserID` if any of the userid options are incorrect;
 * 
 * @member {constant.EpicGames_Result} status The result value of the task
 * @member {string} status_message Text representation of the status code
 * @member {string} AchievementId Achievement ID that can be used to uniquely identify the achievement
 * @member {string} UnlockedDisplayName Localized display name for the achievement when it has been unlocked
 * @member {string} UnlockedDescription Localized description for the achievement when it has been unlocked
 * @member {string} LockedDisplayName Localized display name for the achievement when it is locked or hidden
 * @member {string} LockedDescription Localized description for the achievement when it is locked or hidden
 * @member {string} FlavorText Localized flavor text that can be used by the game in an arbitrary manner. This may be null if there is no data configured in the development portal
 * @member {string} UnlockedIconURL URL of an icon to display for the achievement when it is unlocked. This may be null if there is no data configured in the development portal
 * @member {string} LockedIconURL URL of an icon to display for the achievement when it is locked or hidden. This may be null if there is no data configured in the development portal
 * @member {bool} bIsHidden `true` if the achievement is hidden; `false` otherwise
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
 * @ref EpicGames_Achievements_AddNotifyAchievementsUnlockedV2
 * @ref EpicGames_Achievements_CopyAchievementDefinitionV2ByAchievementId
 * @ref EpicGames_Achievements_CopyAchievementDefinitionV2ByIndex
 * @ref EpicGames_Achievements_CopyPlayerAchievementByAchievementId
 * @ref EpicGames_Achievements_CopyPlayerAchievementByIndex
 * @ref EpicGames_Achievements_GetAchievementDefinitionCount
 * @ref EpicGames_Achievements_GetPlayerAchievementCount
 * @ref EpicGames_Achievements_QueryDefinitions
 * @ref EpicGames_Achievements_QueryPlayerAchievements
 * @ref EpicGames_Achievements_RemoveNotifyAchievementsUnlocked
 * @ref EpicGames_Achievements_UnlockAchievement
 * @section_end
 * 
 * @section_struct
 * @desc These are the structures used by this API:
 * @ref AchievementDefinition
 * @ref PlayerAchievement
 * @section_end
 * 
 * @module_end
 */
