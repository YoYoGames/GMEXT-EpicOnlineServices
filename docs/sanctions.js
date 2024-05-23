// Functions


/**
 * @function EpicGames_Sanctions_CopyPlayerSanctionByIndex
 * @desc **Epic Online Services Function:** [EOS_Sanctions_CopyPlayerSanctionByIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Sanctions/EOS_Sanctions_CopyPlayerSanctionByIndex/index.html)
 * 
 * This function copies an active player sanction.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_Sanctions_QueryActivePlayerSanctions} to store values in cache.]]
 * 
 * @param {string} UserID_target Product User ID of the user whose active sanctions are to be copied
 * @param {real} index Index of the sanction to retrieve from the cache
 * 
 * @returns {struct.PlayerSanctionData}
 * 
 * @example
 * ```gml
 * var _count = EpicGames_Sanctions_GetPlayerSanctionCount(UserID_target);
 * for(var i = 0 ; i < _count ; i++)
 * {
 *     EpicGames_Sanctions_CopyPlayerSanctionByIndex(UserID_target, i);
 *     var Action = struct.Action;
 * }
 * ```
 * The above code shows an example of how the function should be used. The player sanction data is returned for the provided index.
 * @function_end
 */

/**
 * @function EpicGames_Sanctions_GetPlayerSanctionCount
 * @desc **Epic Online Services Function:** [EOS_Sanctions_GetPlayerSanctionCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Sanctions/EOS_Sanctions_GetPlayerSanctionCount/index.html)
 * 
 * This function fetches the number of player sanctions that have been retrieved for a given player.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_Sanctions_QueryActivePlayerSanctions} to store values in cache.]]
 * 
 * @param {string} UserID_target Product User ID of the user whose sanction count should be returned
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _count = EpicGames_Sanctions_GetPlayerSanctionCount(UserID_target);
 * for(var i = 0 ; i < _count ; i++)
 * {
 *     var _struct = EpicGames_Sanctions_CopyPlayerSanctionByIndex(UserID_target, i);
 *     var _action = _struct.Action;
 * }
 * ```
 * The above code shows an example of how the function should be used. After a successful call to ${function.EpicGames_Sanctions_QueryActivePlayerSanctions}, the function ${function.EpicGames_Sanctions_GetPlayerSanctionCount} will return the number of entries in the query array which can then be accessed using the ${function.EpicGames_Sanctions_CopyPlayerSanctionByIndex} function.
 * @function_end
 */

/**
 * @function EpicGames_Sanctions_QueryActivePlayerSanctions
 * @desc **Epic Online Services Function:** [EOS_Sanctions_QueryActivePlayerSanctions](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Sanctions/EOS_Sanctions_QueryActivePlayerSanctions/index.html)
 * 
 * This function starts an asynchronous query to retrieve any active sanctions for a specified user.
 * Once the callback has been fired with a successful ${constant.EpicGames_Result}, it is possible to call one of the following functions:
 * 
 * * ${function.EpicGames_Sanctions_CopyPlayerSanctionByIndex}
 * * ${function.EpicGames_Sanctions_GetPlayerSanctionCount}
 * 
 * @param {string} UserID The Product User ID of the local user who initiated this request. Dedicated servers should set this to null.
 * @param {string} UserID_target Product User ID of the user whose active sanctions are to be retrieved.
 * 
 * @returns {real}
 *
 * @event social
 * @member {string} type The string `"EpicGames_Sanctions_QueryActivePlayerSanctions"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_Sanctions_QueryActivePlayerSanctions();
 * ```
 * The code sample above saves the identifier that can be used inside an ${event.social} event.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Sanctions_QueryActivePlayerSanctions")
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
 * @struct PlayerSanctionData
 * @desc A struct holding the sanction data for a player
 * @member {string} Action The action associated with this sanction
 * @member {string} ReferenceId A unique identifier for this specific sanction
 * @member {real} TimeExpires The POSIX timestamp when the sanction will expire. If the sanction is permanent, this will be 0
 * @member {real} TimePlaced The POSIX timestamp when the sanction was placed
 * @struct_end
 */

/**
 * @module Sanctions
 * @desc **Epic Online Services Interface:** [Sanctions Interface](https://dev.epicgames.com/docs/game-services/sanctions-interface)
 * 
 * This function the [Sanctions Interface](https://dev.epicgames.com/docs/game-services/sanctions-interface) manages punitive actions taken against your users. Actions may include temporary or permanent bans from gameplay or communication bans that limit the social aspects of your product for a particular user. You define the disciplinary actions for your product to handle negative behaviour based on your use cases.
 * 
 * These functions are provided for handling sanctions:
 * 
 * * ${function.EpicGames_Sanctions_CopyPlayerSanctionByIndex}
 * * ${function.EpicGames_Sanctions_GetPlayerSanctionCount}
 * * ${function.EpicGames_Sanctions_QueryActivePlayerSanctions}
 * 
 * @module_end
 */
