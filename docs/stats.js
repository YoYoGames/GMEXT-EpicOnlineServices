// Functions


/**
 * @function eos_stats_copy_stat_by_index
 * @desc **Epic Online Services Function:** [EOS_Stats_CopyStatByIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Stats/EOS_Stats_CopyStatByIndex/index.html)
 * 
 * This function fetches a stat from a given index.
 * 
 * [[Note: Requires a previous call to ${function.eos_stats_query_stats} to store values in cache.]]
 * 
 * @param {string} user_id_target The Product User ID of the user who owns the stat
 * @param {real} index Index of the stat to retrieve from the cache
 * 
 * @returns {struct.StatData}
 * 
 * @example
 * ```gml
 * var _count = eos_stats_get_stats_count(userID_target);
 * for(var i = 0 ; i < _count ; i ++)
 * {
 *     var _struct = eos_stats_copy_stat_by_index(userID_target, i);
 *     var Name = _struct.Name;
 * }
 * ```
 * The above code shows an example of how the function should be used. The stats data is returned for the provided stat index.
 * @function_end
 */

/**
 * @function eos_stats_copy_stat_by_name
 * @desc **Epic Online Services Function:** [EOS_Stats_CopyStatByName](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Stats/EOS_Stats_CopyStatByName/index.html)
 * 
 * This function fetches a stat from cached stats by name.
 * 
 * [[Note: Requires a previous call to ${function.eos_stats_query_stats} to store values in cache.]]
 * 
 * @param {string} user_target The Product User ID of the user who owns the stat
 * @param {string} name Name of the stat to retrieve from the cache
 * 
 * @returns {struct.StatData}
 * 
 * @example
 * ```gml
 * var _struct = eos_stats_copy_stat_by_name(userID_target, "MyStatName");
 * var _name = _struct.Name;
 * ```
 * The above code shows an example of how the function should be used. The stats data is returned for the provided stat name.
 * @function_end
 */

/**
 * @function eos_stats_get_stats_count
 * @desc **Epic Online Services Function:** [EOS_Stats_GetStatsCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Stats/EOS_Stats_GetStatsCount/index.html)
 * 
 * This function fetches the number of stats that are cached locally.
 * 
 * [[Note: Requires a previous call to ${function.eos_stats_query_stats} to store values in cache.]]
 * 
 * @param {string} userID_target The Product User ID for the user whose stats are being counted
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _count = eos_stats_get_stats_count(userID_target);
 * for(var i = 0 ; i < _count ; i ++)
 * {
 *     var _struct = eos_stats_copy_stat_by_index(userID_target, i);
 *     var _name = _struct.Name;
 * }
 * ```
 * The above code shows an example of how the function should be used. After a successful call to ${function.eos_stats_query_stats}, the function ${function.eos_stats_get_stats_count} will return the number of entries in the query array which can then be accessed using the ${function.eos_stats_copy_stat_by_index} function.
 * @function_end
 */

/**
 * @function eos_stats_ingest_stat
 * @desc **Epic Online Services Function:** [EOS_Stats_IngestStat](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Stats/EOS_Stats_IngestStat/index.html)
 * 
 * This function ingests a stat by the amount specified in Options.
 * 
 * When the operation is complete and the delegate is triggered the stat will be uploaded to the backend to be processed. The stat may not be updated immediately and an achievement using the stat may take a while to be unlocked once the stat has been uploaded.
 * 
 * @param {string} userID The Product User ID of the local user requesting the ingest. Set to `undefined` for dedicated server.
 * @param {string} userID_target The Product User ID for the user whose stat is being ingested
 * @param {string} statName Name of the Stat to ingest
 * @param {real} amount Amount of the Stat to ingest
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_stats_ingest_stat"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_stats_ingest_stat(userID, userID, "Leaderboard_Stat", 183);
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_stats_ingest_stat")
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
 * @function eos_stats_query_stats
 * @desc **Epic Online Services Function:**  [EOS_Stats_QueryStats](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Stats/EOS_Stats_QueryStats/index.html)
 * 
 * This function queries a list of stats for a specific player.
 * Once the callback has been fired with a successful ${constant.EOS_RESULT}, it is possible to call one of the following functions:
 * 
 * * ${function.eos_stats_copy_stat_by_index}
 * * ${function.eos_stats_copy_stat_by_name}
 * * ${function.eos_stats_get_stats_count}
 * 
 * @param {string} userID The Product User ID of the local user requesting the stats. Set to `undefined` for dedicated server.
 * @param {string} userID_target The Product User ID for the user whose stats are being retrieved
 * @param {real} [startTime] The POSIX timestamp for start time
 * @param {real} [endTime] The POSIX timestamp for end time
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type The string `"eos_stats_query_stats"`
 * @member {constant.EOS_RESULT} status The status code for the operation. `EOS_RESULT.SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID.
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_stats_query_stats();
 * ```
 * The code sample above saves the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_stats_query_stats")
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

// Structs

/**
 * @struct StatData
 * @desc The stat data is represented by a struct and contains information for a specific stat.
 * 
 * [[Note: The stat info members are only present in the struct if the request was successful.]]
 * 
 * @member {constant.EOS_RESULT} status The status code of the request
 * @member {string} status_message A text representation of the status code
 * @member {string} [name] The name of the stat
 * @member {real} [start_time] If not `EOS_STATS_TIME_UNDEFINED` then this is the POSIX timestamp for start time.
 * @member {real} [end_time] If not `EOS_STATS_TIME_UNDEFINED` then this is the POSIX timestamp for end time.
 * @member {real} [value] The current value for the stat.
 * @struct_end
 */

/**
 * @module stats
 * @title Stats
 * @desc **Epic Online Services Interface:** [Stats Interface](https://dev.epicgames.com/docs/game-services/eos-stats-interface)
 * 
 * The [Stats Interface](https://dev.epicgames.com/docs/game-services/eos-stats-interface) provides the ability for developers to manage users' **stats** for an application, which can include any statistical data that a developer wishes to track, such as the number of items collected, the player's fastest completion time for a level, the total number of victories or losses, or the number of times that a user has performed a certain action. You can use stats to determine when to unlock ${module.achievements} and how to use rank users in ${module.leaderboards}.
 * 
 * @section_func
 * @desc These functions are provided for handling stats:
 * 
 * @ref eos_stats_copy_stat_by_index
 * @ref eos_stats_copy_stat_by_name
 * @ref eos_stats_get_stats_count
 * @ref eos_stats_ingest_stat
 * @ref eos_stats_query_stats
 * 
 * @section_end
 * 
 * @section_struct
 * @desc These are the structures used by this API:
 * @ref StatData
 * @section_end
 * 
 * @module_end
 */
