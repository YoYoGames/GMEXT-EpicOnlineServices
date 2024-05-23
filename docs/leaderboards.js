// Functions


/**
 * @function EpicGames_Leaderboards_CopyLeaderboardDefinitionByIndex
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_CopyLeaderboardDefinitionByIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_CopyLeaderboardDefinitionByIndex/index.html)
 * 
 * This function fetches a leaderboard definition from the cache using an index.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_Leaderboards_QueryLeaderboardDefinitions} to store values in cache.]]
 * 
 * @param {real} index Index of the leaderboard definition to retrieve from the cache
 * 
 * @returns {struct.LeaderboardDefinition}
 * 
 * @example
 * ```gml
 * var _count = EpicGames_Leaderboards_GetLeaderboardDefinitionCount();
 * for(var i = 0 ; i < _count ; i++)
 * {
 *     var _struct = EpicGames_Leaderboards_CopyLeaderboardDefinitionByIndex(i);
 *     var _LeaderboardId = _struct.LeaderboardId;
 * }
 * ```
 * The above code shows an example of how the function should be used. The leaderboard definition data is returned providing an leaderboard index.
 * @function_end
 */

/**
 * @function EpicGames_Leaderboards_CopyLeaderboardDefinitionByLeaderboardId
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_CopyLeaderboardDefinitionByLeaderboardId](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_CopyLeaderboardDefinitionByLeaderboardId/index.html)
 * 
 * This function fetches a leaderboard definition from the cache using a leaderboard ID.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_Leaderboards_QueryLeaderboardDefinitions} to store values in cache.]]
 * 
 * @param {string} leaderboardID The ID of the leaderboard whose definition you want to copy from the cache
 * 
 * @returns {struct.LeaderboardDefinition}
 * 
 * @example
 * ```gml
 * var _struct = EpicGames_Leaderboards_CopyLeaderboardDefinitionByLeaderboardId("MyLeaderboard");
 * if(_struct.status == EpicGames_Success)
 * {
 *     var LeaderboardId = _struct.LeaderboardId;
 * }
 * ```
 * The above code shows an example of how the function should be used. The leaderboard definition data is returned providing a leaderboard ID.
 * @function_end
 */

/**
 * @function EpicGames_Leaderboards_CopyLeaderboardRecordByIndex
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_CopyLeaderboardRecordByIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_CopyLeaderboardRecordByIndex/index.html)
 * 
 * This function fetches a leaderboard record from a given index.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_Leaderboards_QueryLeaderboardRanks} to store values in cache.]]
 * 
 * @param {real} index Index of the leaderboard record to retrieve from the cache
 * 
 * @returns {struct.LeaderboardRecord}
 * 
 * @example
 * ```gml
 * var _count = EpicGames_Leaderboards_GetLeaderboardRecordCount();
 * for(var i = 0 ; i < _count ; i++)
 * {
 *     var _struct = EpicGames_Leaderboards_CopyLeaderboardRecordByIndex(i);
 *     var _rank = struct.Rank;
 * }
 * ```
 * The above code shows an example of how the function should be used. The leaderboard record data is returned providing a leaderboard index.
 * @function_end
 */

/**
 * @function EpicGames_Leaderboards_CopyLeaderboardRecordByUserId
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_CopyLeaderboardRecordByUserId](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_CopyLeaderboardRecordByUserId/index.html)
 * 
 * This function fetches a leaderboard record from a given user ID.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_Leaderboards_QueryLeaderboardRanks} to store values in cache.]]
 * 
 * @param {string} userId Leaderboard data will be copied from the cache if it relates to the user matching this Product User ID
 * 
 * @returns {struct.LeaderboardRecord}
 * 
 * @example
 * ```gml
 * var _struct = EpicGames_Leaderboards_CopyLeaderboardRecordByUserId("MyLeaderboard");
 * if(_struct.status == EpicGames_Success)
 * {
 *     var _rank = struct.Rank;
 * }
 * ```
 * The above code shows an example of how the function should be used. The leaderboard record data is returned providing an user ID.
 * @function_end
 */

/**
 * @function EpicGames_Leaderboards_CopyLeaderboardUserScoreByIndex
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_CopyLeaderboardUserScoreByIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_CopyLeaderboardUserScoreByIndex/index.html)
 * 
 * This function fetches a leaderboard user score from a given index.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_Leaderboards_QueryLeaderboardUserScores} to store values in cache.]]
 * 
 * @param {real} index The index of the sorted leaderboard user score to retrieve from the cache.
 * @param {string} statName The name of the stat used to rank the leaderboard.
 * 
 * @returns {struct.LeaderboardUserScore}
 * 
 * @example
 * ```gml
 * var _count = EpicGames_Leaderboards_GetLeaderboardUserScoreCount();
 * for(var i = 0 ; i < _count ; i++)
 * {
 *     var _struct = EpicGames_Leaderboards_CopyLeaderboardUserScoreByIndex(i);
 *     var _score = _struct.Score;
 * }
 * ```
 * The above code shows an example of how the function should be used. The leaderboard user score is returned providing an index.
 * @function_end
 */

/**
 * @function EpicGames_Leaderboards_CopyLeaderboardUserScoreByUserId
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_CopyLeaderboardUserScoreByUserId](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_CopyLeaderboardUserScoreByUserId/index.html)
 * 
 * This function fetches leaderboard user score from a given user ID.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_Leaderboards_QueryLeaderboardUserScores} to store values in cache.]]
 * 
 * @param {string} userId The Product User ID to look for when copying leaderboard score data from the cache
 * @param {string} statName The name of the stat that is used to rank this leaderboard
 * 
 * @returns {struct.LeaderboardUserScore}
 * 
 * @example
 * ```gml
 * var _struct = EpicGames_Leaderboards_CopyLeaderboardUserScoreByUserId("MyLeaderboard");
 * if(_struct.status == EpicGames_Success)
 * {
 *     var _score = struct.Score;
 * }
 * ```
 * The above code shows an example of how the function should be used. The leaderboard user  score is returned providing an user ID.
 * @function_end
 */

/**
 * @function EpicGames_Leaderboards_GetLeaderboardDefinitionCount
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_GetLeaderboardDefinitionCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_GetLeaderboardDefinitionCount/index.html)
 * 
 * This function fetch the number of leaderboards definitions that are cached locally.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_Leaderboards_QueryLeaderboardDefinitions} to store values in cache.]]
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _count = EpicGames_Leaderboards_GetLeaderboardDefinitionCount();
 * for(var i = 0 ; i < _count ; i++)
 * {
 *     var _struct = EpicGames_Leaderboards_CopyLeaderboardDefinitionByIndex(i);
 *     var _leaderboardId = _struct.LeaderboardId;
 * }
 * ```
 * The above code shows an example of how the function should be used. After a successful call to ${function.EpicGames_Leaderboards_QueryLeaderboardDefinitions}, the function ${function.EpicGames_Leaderboards_GetLeaderboardDefinitionCount} will return the number of entries in the query array which can then be accessed using the${function.EpicGames_Leaderboards_CopyLeaderboardDefinitionByIndex}  function.
 * @function_end
 */

/**
 * @function EpicGames_Leaderboards_GetLeaderboardRecordCount
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_GetLeaderboardRecordCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_GetLeaderboardRecordCount/index.html)
 * 
 * This function fetch the number of leaderboard records that are cached locally.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_Leaderboards_QueryLeaderboardRanks} to store values in cache.]]
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _count = EpicGames_Leaderboards_GetLeaderboardRecordCount();
 * for(var i = 0 ; i < _count ; i++)
 * {
 *     var _struct = EpicGames_Leaderboards_CopyLeaderboardRecordByIndex(i);
 *     var _rank = _struct.Rank;
 * }
 * ```
 * The above code shows an example of how the function should be used. After a successful call to ${function.EpicGames_Leaderboards_QueryLeaderboardRanks}, the function ${function.EpicGames_Leaderboards_GetLeaderboardRecordCount} will return the number of entries in the query array which can then be accessed using the ${function.EpicGames_Leaderboards_CopyLeaderboardRecordByIndex} function.
 * @function_end
 */

/**
 * @function EpicGames_Leaderboards_GetLeaderboardUserScoreCount
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_GetLeaderboardUserScoreCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_GetLeaderboardUserScoreCount/index.html)
 * 
 * This function fetch the number of leaderboard user scores that are cached locally.
 * 
 * [[Note: Requires a previous call to ${function.EpicGames_Leaderboards_QueryLeaderboardUserScores} to store values in cache.]]
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _count = EpicGames_Leaderboards_GetLeaderboardUserScoreCount();
 * for(var i = 0 ; i < _count; i++)
 * {
 *     var _struct = EpicGames_Leaderboards_CopyLeaderboardUserScoreByIndex(i);
 *     var _score = _struct.Score;
 * }
 * ```
 * The above code shows an example of how the function should be used. After a successful call to ${function.EpicGames_Leaderboards_QueryLeaderboardUserScores}, the function ${function.EpicGames_Leaderboards_GetLeaderboardUserScoreCount} will return the number of entries in the query array which can then be accessed using the ${function.EpicGames_Leaderboards_CopyLeaderboardUserScoreByIndex} function.
 * @function_end
 */

/**
 * @function EpicGames_Leaderboards_QueryLeaderboardDefinitions
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_QueryLeaderboardDefinitions](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_QueryLeaderboardDefinitions/index.html)
 * 
 * This function query for a list of existing leaderboards definitions including their attributes.
 * Once the callback has been fired with a successful ${constant.EpicGames_Result}, it is possible to call one of the following functions:
 * 
 * * ${function.EpicGames_Leaderboards_CopyLeaderboardDefinitionByIndex}
 * * ${function.EpicGames_Leaderboards_CopyLeaderboardDefinitionByLeaderboardId}
 * * ${function.EpicGames_Leaderboards_GetLeaderboardDefinitionCount}
 * 
 * @param {string} userID Product User ID for user who is querying definitions. Must be set when using a client policy that requires a valid logged in user. Not used for Dedicated Server where no user is available.
 * @param {int64} startTime An optional POSIX timestamp for the leaderboard's start time, or `undefined`.
 * @param {int64} endTime An optional POSIX timestamp for the leaderboard's end time, or `undefined`.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type `"EpicGames_Leaderboards_QueryLeaderboardDefinitions"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_Leaderboards_QueryLeaderboardDefinitions();
 * ```
 * The code sample above save the identifier that can be used inside an ${event.social} event.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Leaderboards_QueryLeaderboardDefinitions")
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
 * @function EpicGames_Leaderboards_QueryLeaderboardRanks
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_QueryLeaderboardRanks](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_QueryLeaderboardRanks/index.html)
 * 
 * This function retrieves top leaderboard records by rank in the leaderboard matching the given leaderboard ID. 
 * Once the callback has been fired with a successful ${constant.EpicGames_Result}, it is possible to call one of the following functions:
 * 
 * * ${function.EpicGames_Leaderboards_CopyLeaderboardRecordByIndex}
 * * ${function.EpicGames_Leaderboards_CopyLeaderboardRecordByUserId}
 * * ${function.EpicGames_Leaderboards_GetLeaderboardRecordCount}
 * 
 * @param {string} userID The ID of the leaderboard whose information you want to retrieve
 * @param {string} LeaderboardId Product User ID for user who is querying ranks. Must be set when using a client policy that requires a valid logged in user. Not used for Dedicated Server where no user is available
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type `"EpicGames_Leaderboards_QueryLeaderboardRanks"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_Leaderboards_QueryLeaderboardRanks(userID, LeaderboardId);
 * ```
 * The code sample above save the identifier that can be used inside an ${event.social} event.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Leaderboards_QueryLeaderboardRanks")
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
 * @function EpicGames_Leaderboards_QueryLeaderboardUserScores
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_QueryLeaderboardUserScores](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_QueryLeaderboardUserScores/index.html)
 * 
 * This function query for a list of scores for a given list of users.
 * Once the callback has been fired with a successful ${constant.EpicGames_Result}, it is possible to call one of the following functions:
 * 
 * * ${function.EpicGames_Leaderboards_CopyLeaderboardUserScoreByIndex}
 * * ${function.EpicGames_Leaderboards_CopyLeaderboardUserScoreByUserId}
 * * ${function.EpicGames_Leaderboards_GetLeaderboardUserScoreCount}
 * 
 * @param {string} userID The argument to be passed in
 * @param {string} LeaderboardId Product User ID indicating the users whose scores you want to retrieve
 * @param {string} name The name of the stat to query.
 * @param {[LeaderboardAggregation](Leaderboards_Constants#LeaderboardAggregation)} aggregation Aggregation used to sort the cached user scores.
 * @param {real} startTime An optional POSIX timestamp, or `undefined`; results will only include scores made after this time
 * @param {real} endTime An optional POSIX timestamp, or `undefined`; results will only include scores made before this time
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type `"EpicGames_Leaderboards_QueryLeaderboardUserScores"`
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = EpicGames_Leaderboards_QueryLeaderboardUserScores(userID, LeaderboardId, name, aggregation, startTime, endTime);
 * ```
 * The code sample above save the identifier that can be used inside an ${event.social} event.
 * 
 * ```gml
 * if (async_load[? "type"] == "EpicGames_Leaderboards_QueryLeaderboardUserScores")
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
 * @constant EpicGames_LeaderboardAggregation
 * @desc **Epic Online Services Enum:** [EOS_ELeaderboardAggregation](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-leaderboard-aggregation)
 * 
 * These constants represent the different leaderboard aggregation types.
 * 
 * EpicGames_LA_Min Scores are aggregated by minimum.
 * EpicGames_LA_Max Scores are aggregated by maximum.
 * EpicGames_LA_Sum Scores are aggregated by the sum of the values.
 * EpicGames_LA_Latest Scores are aggregated by the last value.
 * @constant_end
 */


// Structs

/**
 * @struct LeaderboardUserScore
 * @desc A leaderboard definition is represented by a struct and contains information about a single leaderboard user score.
 * 
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {string} UserId The Product User ID of the user who got this score
 * @member {real} Score Leaderboard score
 * @struct_end
 */

/**
 * @struct LeaderboardRecord
 * @desc A leaderboard record is represented by a struct and contains information about a single leaderboard record.
 * 
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {string} UserId The Product User ID associated with this record
 * @member {real} Rank Sorted position on leaderboard
 * @member {real} Score Leaderboard score
 * @member {string} UserDisplayName The latest display name seen for the user since they last time logged in. This is empty if the user does not have a display name set
 * @struct_end
 */

/**
 * @struct LeaderboardDefinition
 * @desc An leaderboard definition is represented by a struct and contains information about a single leaderboard definition.
 * 
 * @member {constant.EpicGames_Result} status The status code for the operation. `EpicGames_Success` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {string} LeaderboardId Unique ID to identify leaderboard.
 * @member {string} StatName Name of stat used to rank leaderboard.
 * @member {real} StartTime The POSIX timestamp for the start time, or `EpicGames_LEADERBOARDS_TIME_UNDEFINED`.
 * @member {real} EndTime The POSIX timestamp for the end time, or `EpicGames_LEADERBOARDS_TIME_UNDEFINED`.
 * @member {constant.EpicGames_LeaderboardAggregation} Aggregation used to sort the leaderboard.
 * @struct_end
 */


/**
 * @module Leaderboards
 * @desc 
 * 
 * The [Leaderboards Interface](https://dev.epicgames.com/docs/game-services/leaderboards) gives developers using **Epic Online Services** (EOS) the ability to rank scores from their entire player base, so that players can compete with their friends or other players worldwide for the top score. Each game can support multiple leaderboards, collecting scores from different sources, and ranking them with different scoring modes.
 * 
 * @section_func
 * @desc These functions are provided for handling leaderboards:
 * 
 * @ref EpicGames_Leaderboards_CopyLeaderboardDefinitionByIndex
 * @ref EpicGames_Leaderboards_CopyLeaderboardDefinitionByLeaderboardId
 * @ref EpicGames_Leaderboards_CopyLeaderboardRecordByIndex
 * @ref EpicGames_Leaderboards_CopyLeaderboardRecordByUserId
 * @ref EpicGames_Leaderboards_CopyLeaderboardUserScoreByIndex
 * @ref EpicGames_Leaderboards_CopyLeaderboardUserScoreByUserId
 * @ref EpicGames_Leaderboards_GetLeaderboardDefinitionCount
 * @ref EpicGames_Leaderboards_GetLeaderboardRecordCount
 * @ref EpicGames_Leaderboards_GetLeaderboardUserScoreCount
 * @ref EpicGames_Leaderboards_QueryLeaderboardDefinitions
 * @ref EpicGames_Leaderboards_QueryLeaderboardRanks
 * @ref EpicGames_Leaderboards_QueryLeaderboardUserScores
 * 
 * @section_end
 * 
 * @section_const
 * @desc These are the constants used for leaderboards:
 * 
 * @ref EpicGames_LeaderboardAggregation
 * 
 * @section_end
 * 
 * @section_struct
 * @desc These are the structures used by this API:
 * 
 * @ref LeaderboardDefinition
 * @ref LeaderboardRecord
 * @ref LeaderboardUserScore
 * 
 * @section_end
 * 
 * @module_end
 */
