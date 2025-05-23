// Functions


/**
 * @function eos_sanctions_copy_player_sanction_by_index
 * @desc **Epic Online Services Function:** [EOS_Sanctions_CopyPlayerSanctionByIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Sanctions/EOS_Sanctions_CopyPlayerSanctionByIndex/index.html)
 * 
 * This function copies an active player sanction.
 * 
 * [[Note: Requires a previous call to ${function.eos_sanctions_query_active_player_sanctions} to store values in cache.]]
 * 
 * @param {string} UserID_target Product User ID of the user whose active sanctions are to be copied
 * @param {real} index Index of the sanction to retrieve from the cache
 * 
 * @returns {struct.PlayerSanctionData}
 * 
 * @example
 * ```gml
 * var _count = eos_sanctions_get_player_sanction_count(UserID_target);
 * for(var i = 0 ; i < _count ; i++)
 * {
 *     eos_sanctions_copy_player_sanction_by_index(UserID_target, i);
 *     var Action = struct.Action;
 * }
 * ```
 * The above code shows an example of how the function should be used. The player sanction data is returned for the provided index.
 * @function_end
 */

/**
 * @function eos_sanctions_get_player_sanction_count
 * @desc **Epic Online Services Function:** [EOS_Sanctions_GetPlayerSanctionCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Sanctions/EOS_Sanctions_GetPlayerSanctionCount/index.html)
 * 
 * This function fetches the number of player sanctions that have been retrieved for a given player.
 * 
 * [[Note: Requires a previous call to ${function.eos_sanctions_query_active_player_sanctions} to store values in cache.]]
 * 
 * @param {string} UserID_target Product User ID of the user whose sanction count should be returned
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _count = eos_sanctions_get_player_sanction_count(UserID_target);
 * for(var i = 0 ; i < _count ; i++)
 * {
 *     var _struct = eos_sanctions_copy_player_sanction_by_index(UserID_target, i);
 *     var _action = _struct.Action;
 * }
 * ```
 * The above code shows an example of how the function should be used. After a successful call to ${function.eos_sanctions_query_active_player_sanctions}, the function ${function.eos_sanctions_get_player_sanction_count} will return the number of entries in the query array which can then be accessed using the ${function.eos_sanctions_copy_player_sanction_by_index} function.
 * @function_end
 */

/**
 * @function eos_sanctions_query_active_player_sanctions
 * @desc **Epic Online Services Function:** [EOS_Sanctions_QueryActivePlayerSanctions](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Sanctions/EOS_Sanctions_QueryActivePlayerSanctions/index.html)
 * 
 * This function starts an asynchronous query to retrieve any active sanctions for a specified user.
 * Once the callback has been fired with a successful ${constant.EOS_Result}, it is possible to call one of the following functions:
 * 
 * * ${function.eos_sanctions_copy_player_sanction_by_index}
 * * ${function.eos_sanctions_get_player_sanction_count}
 * 
 * @param {string} UserID The Product User ID of the local user who initiated this request. Dedicated servers should set this to an empty string.
 * @param {string} UserID_target Product User ID of the user whose active sanctions are to be retrieved.
 * 
 * @returns {real}
 *
 * @event social
 * @member {string} type The string `"eos_sanctions_query_active_player_sanctions"`
 * @member {constant.EOS_Result} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_sanctions_query_active_player_sanctions();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_sanctions_query_active_player_sanctions")
 * if (async_load[? "identifier"] == identifier)
 * {
 *     if (async_load[? "status"] == EOS_SUCCESS)
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
 * @module sanctions
 * @title Sanctions
 * @desc **Epic Online Services Interface:** [Sanctions Interface](https://dev.epicgames.com/docs/game-services/sanctions-interface)
 * 
 * The [Sanctions Interface](https://dev.epicgames.com/docs/game-services/sanctions-interface) manages punitive actions taken against your users. Actions may include temporary or permanent bans from gameplay or communication bans that limit the social aspects of your product for a particular user. You define the disciplinary actions for your product to handle negative behaviour based on your use cases.
 * 
 * @section_func
 * @desc These functions are provided for handling sanctions:
 * 
 * @ref eos_sanctions_copy_player_sanction_by_index
 * @ref eos_sanctions_get_player_sanction_count
 * @ref eos_sanctions_query_active_player_sanctions
 * 
 * @section_end
 * 
 * @section_struct
 * @desc These are the structs used by the Sanctions module:
 * 
 * @ref PlayerSanctionData
 * 
 * @section_end
 * 
 * @module_end
 */
