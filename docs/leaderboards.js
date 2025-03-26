// Functions


/**
 * @function eos_leaderboards_copy_leaderboard_definition_by_index
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_CopyLeaderboardDefinitionByIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_CopyLeaderboardDefinitionByIndex/index.html)
 * 
 * This function fetches a leaderboard definition from the cache using an index.
 * 
 * [[Note: Requires a previous call to ${function.eos_leaderboards_query_leaderboard_definitions} to store values in cache.]]
 * 
 * @param {real} index Index of the leaderboard definition to retrieve from the cache
 * 
 * @returns {struct.LeaderboardDefinition}
 * 
 * @example
 * ```gml
 * var _count = eos_leaderboards_get_leaderboard_definition_count();
 * for(var i = 0 ; i < _count ; i++)
 * {
 *     var _struct = eos_leaderboards_copy_leaderboard_definition_by_index(i);
 *     var _LeaderboardId = _struct.LeaderboardId;
 * }
 * ```
 * The above code shows an example of how the function should be used. The leaderboard definition data is returned providing an leaderboard index.
 * @function_end
 */

/**
 * @function eos_leaderboards_copy_leaderboard_definition_by_leaderboard_id
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_CopyLeaderboardDefinitionByLeaderboardId](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_CopyLeaderboardDefinitionByLeaderboardId/index.html)
 * 
 * This function fetches a leaderboard definition from the cache using a leaderboard ID.
 * 
 * [[Note: Requires a previous call to ${function.eos_leaderboards_query_leaderboard_definitions} to store values in cache.]]
 * 
 * @param {string} leaderboardID The ID of the leaderboard whose definition you want to copy from the cache
 * 
 * @returns {struct.LeaderboardDefinition}
 * 
 * @example
 * ```gml
 * var _struct = eos_leaderboards_copy_leaderboard_definition_by_leaderboard_id("MyLeaderboard");
 * if(_struct.status == EOS_SUCCESS)
 * {
 *     var LeaderboardId = _struct.LeaderboardId;
 * }
 * ```
 * The above code shows an example of how the function should be used. The leaderboard definition data is returned providing a leaderboard ID.
 * @function_end
 */

/**
 * @function eos_leaderboards_copy_leaderboard_record_by_index
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_CopyLeaderboardRecordByIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_CopyLeaderboardRecordByIndex/index.html)
 * 
 * This function fetches a leaderboard record from a given index.
 * 
 * [[Note: Requires a previous call to ${function.eos_leaderboards_query_leaderboard_ranks} to store values in cache.]]
 * 
 * @param {real} index Index of the leaderboard record to retrieve from the cache
 * 
 * @returns {struct.LeaderboardRecord}
 * 
 * @example
 * ```gml
 * var _count = eos_leaderboards_get_leaderboard_record_count();
 * for(var i = 0 ; i < _count ; i++)
 * {
 *     var _struct = eos_leaderboards_copy_leaderboard_record_by_index(i);
 *     var _rank = struct.Rank;
 * }
 * ```
 * The above code shows an example of how the function should be used. The leaderboard record data is returned providing a leaderboard index.
 * @function_end
 */

/**
 * @function eos_leaderboards_copy_leaderboard_record_by_user_id
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_CopyLeaderboardRecordByUserId](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_CopyLeaderboardRecordByUserId/index.html)
 * 
 * This function fetches a leaderboard record from a given user ID.
 * 
 * [[Note: Requires a previous call to ${function.eos_leaderboards_query_leaderboard_ranks} to store values in cache.]]
 * 
 * @param {string} userId Leaderboard data will be copied from the cache if it relates to the user matching this Product User ID
 * 
 * @returns {struct.LeaderboardRecord}
 * 
 * @example
 * ```gml
 * var _struct = eos_leaderboards_copy_leaderboard_record_by_user_id("MyLeaderboard");
 * if(_struct.status == EOS_SUCCESS)
 * {
 *     var _rank = struct.Rank;
 * }
 * ```
 * The above code shows an example of how the function should be used. The leaderboard record data is returned providing an user ID.
 * @function_end
 */

/**
 * @function eos_leaderboards_copy_leaderboard_user_score_by_index
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_CopyLeaderboardUserScoreByIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_CopyLeaderboardUserScoreByIndex/index.html)
 * 
 * This function fetches a leaderboard user score from a given index.
 * 
 * [[Note: Requires a previous call to ${function.eos_leaderboards_query_leaderboard_user_scores} to store values in cache.]]
 * 
 * @param {real} index The index of the sorted leaderboard user score to retrieve from the cache.
 * @param {string} statName The name of the stat used to rank the leaderboard.
 * 
 * @returns {struct.LeaderboardUserScore}
 * 
 * @example
 * ```gml
 * var _count = eos_leaderboards_get_leaderboard_user_score_count();
 * for(var i = 0 ; i < _count ; i++)
 * {
 *     var _struct = eos_leaderboards_copy_leaderboard_user_score_by_index(i);
 *     var _score = _struct.Score;
 * }
 * ```
 * The above code shows an example of how the function should be used. The leaderboard user score is returned providing an index.
 * @function_end
 */

/**
 * @function eos_leaderboards_copy_leaderboard_user_score_by_user_id
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_CopyLeaderboardUserScoreByUserId](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_CopyLeaderboardUserScoreByUserId/index.html)
 * 
 * This function fetches leaderboard user score from a given user ID.
 * 
 * [[Note: Requires a previous call to ${function.eos_leaderboards_query_leaderboard_user_scores} to store values in cache.]]
 * 
 * @param {string} userId The Product User ID to look for when copying leaderboard score data from the cache
 * @param {string} statName The name of the stat that is used to rank this leaderboard
 * 
 * @returns {struct.LeaderboardUserScore}
 * 
 * @example
 * ```gml
 * var _struct = eos_leaderboards_copy_leaderboard_user_score_by_user_id("MyLeaderboard");
 * if(_struct.status == EOS_SUCCESS)
 * {
 *     var _score = struct.Score;
 * }
 * ```
 * The above code shows an example of how the function should be used. The leaderboard user  score is returned providing an user ID.
 * @function_end
 */

/**
 * @function eos_leaderboards_get_leaderboard_definition_count
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_GetLeaderboardDefinitionCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_GetLeaderboardDefinitionCount/index.html)
 * 
 * This function fetch thees number of leaderboards definitions that are cached locally.
 * 
 * [[Note: Requires a previous call to ${function.eos_leaderboards_query_leaderboard_definitions} to store values in cache.]]
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _count = eos_leaderboards_get_leaderboard_definition_count();
 * for(var i = 0 ; i < _count ; i++)
 * {
 *     var _struct = eos_leaderboards_copy_leaderboard_definition_by_index(i);
 *     var _leaderboardId = _struct.LeaderboardId;
 * }
 * ```
 * The above code shows an example of how the function should be used. After a successful call to ${function.eos_leaderboards_query_leaderboard_definitions}, the function ${function.eos_leaderboards_get_leaderboard_definition_count} will return the number of entries in the query array which can then be accessed using the ${function.eos_leaderboards_copy_leaderboard_definition_by_index} function.
 * @function_end
 */

/**
 * @function eos_leaderboards_get_leaderboard_record_count
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_GetLeaderboardRecordCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_GetLeaderboardRecordCount/index.html)
 * 
 * This function fetches the number of leaderboard records that are cached locally.
 * 
 * [[Note: Requires a previous call to ${function.eos_leaderboards_query_leaderboard_ranks} to store values in cache.]]
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _count = eos_leaderboards_get_leaderboard_record_count();
 * for(var i = 0 ; i < _count ; i++)
 * {
 *     var _struct = eos_leaderboards_copy_leaderboard_record_by_index(i);
 *     var _rank = _struct.Rank;
 * }
 * ```
 * The above code shows an example of how the function should be used. After a successful call to ${function.eos_leaderboards_query_leaderboard_ranks}, the function ${function.eos_leaderboards_get_leaderboard_record_count} will return the number of entries in the query array which can then be accessed using the ${function.eos_leaderboards_copy_leaderboard_record_by_index} function.
 * @function_end
 */

/**
 * @function eos_leaderboards_get_leaderboard_user_score_count
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_GetLeaderboardUserScoreCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_GetLeaderboardUserScoreCount/index.html)
 * 
 * This function fetches the number of leaderboard user scores that are cached locally.
 * 
 * [[Note: Requires a previous call to ${function.eos_leaderboards_query_leaderboard_user_scores} to store values in cache.]]
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * var _count = eos_leaderboards_get_leaderboard_user_score_count();
 * for(var i = 0 ; i < _count; i++)
 * {
 *     var _struct = eos_leaderboards_copy_leaderboard_user_score_by_index(i);
 *     var _score = _struct.Score;
 * }
 * ```
 * The above code shows an example of how the function should be used. After a successful call to ${function.eos_leaderboards_query_leaderboard_user_scores}, the function ${function.eos_leaderboards_get_leaderboard_user_score_count} will return the number of entries in the query array which can then be accessed using the ${function.eos_leaderboards_copy_leaderboard_user_score_by_index} function.
 * @function_end
 */

/**
 * @function eos_leaderboards_query_leaderboard_definitions
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_QueryLeaderboardDefinitions](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_QueryLeaderboardDefinitions/index.html)
 * 
 * This function queries for a list of existing leaderboards definitions including their attributes.
 * Once the callback has been fired with a successful ${constant.eos_result}, it is possible to call one of the following functions:
 * 
 * * ${function.eos_leaderboards_copy_leaderboard_definition_by_index}
 * * ${function.eos_leaderboards_copy_leaderboard_definition_by_leaderboard_id}
 * * ${function.eos_leaderboards_get_leaderboard_definition_count}
 * 
 * @param {string} userID Product User ID for user who is querying definitions. Must be set when using a client policy that requires a valid logged in user. Not used for Dedicated Server where no user is available.
 * @param {int64} startTime An optional POSIX timestamp for the leaderboard's start time, or `undefined`.
 * @param {int64} endTime An optional POSIX timestamp for the leaderboard's end time, or `undefined`.
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type `"eos_leaderboards_query_leaderboard_definitions"`
 * @member {constant.eos_result} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_leaderboards_query_leaderboard_definitions();
 * ```
 * The code sample above save the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_leaderboards_query_leaderboard_definitions")
 * if(async_load[? "identifier"] == identifier)
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

/**
 * @function eos_leaderboards_query_leaderboard_ranks
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_QueryLeaderboardRanks](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_QueryLeaderboardRanks/index.html)
 * 
 * This function retrieves top leaderboard records by rank in the leaderboard matching the given leaderboard ID. 
 * Once the callback has been fired with a successful ${constant.eos_result}, it is possible to call one of the following functions:
 * 
 * * ${function.eos_leaderboards_copy_leaderboard_record_by_index}
 * * ${function.eos_leaderboards_copy_leaderboard_record_by_user_id}
 * * ${function.eos_leaderboards_get_leaderboard_record_count}
 * 
 * @param {string} userID The ID of the leaderboard whose information you want to retrieve
 * @param {string} LeaderboardId Product User ID for user who is querying ranks. Must be set when using a client policy that requires a valid logged in user. Not used for Dedicated Server where no user is available
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type `"eos_leaderboards_query_leaderboard_ranks"`
 * @member {constant.eos_result} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_leaderboards_query_leaderboard_ranks(userID, LeaderboardId);
 * ```
 * The code sample above save the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_leaderboards_query_leaderboard_ranks")
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

/**
 * @function eos_leaderboards_query_leaderboard_user_scores
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_QueryLeaderboardUserScores](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Leaderboards/EOS_Leaderboards_QueryLeaderboardUserScores/index.html)
 * 
 * This function queries for a list of scores for a given list of users.
 * Once the callback has been fired with a successful ${constant.eos_result}, it is possible to call one of the following functions:
 * 
 * * ${function.eos_leaderboards_copy_leaderboard_user_score_by_index}
 * * ${function.eos_leaderboards_copy_leaderboard_user_score_by_user_id}
 * * ${function.eos_leaderboards_get_leaderboard_user_score_count}
 * 
 * @param {string} userID The argument to be passed in
 * @param {string} LeaderboardId Product User ID indicating the users whose scores you want to retrieve
 * @param {string} name The name of the stat to query.
 * @param {constant.eos_leaderboard_aggregation} aggregation Aggregation used to sort the cached user scores.
 * @param {real} startTime An optional POSIX timestamp, or `undefined`; results will only include scores made after this time
 * @param {real} endTime An optional POSIX timestamp, or `undefined`; results will only include scores made before this time
 * 
 * @returns {real}
 * 
 * @event social
 * @member {string} type `"eos_leaderboards_query_leaderboard_user_scores"`
 * @member {constant.eos_result} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {real} identifier The asynchronous listener ID
 * @event_end
 * 
 * @example
 * ```gml
 * identifier = eos_leaderboards_query_leaderboard_user_scores(userID, LeaderboardId, name, aggregation, startTime, endTime);
 * ```
 * The code sample above save the identifier that can be used inside a ${event.social}.
 * 
 * ```gml
 * if (async_load[? "type"] == "eos_leaderboards_query_leaderboard_user_scores")
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

// Constants

/**
 * @constant eos_leaderboard_aggregation
 * @desc **Epic Online Services Enum:** [EOS_ELeaderboardAggregation](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-leaderboard-aggregation)
 * 
 * These constants represent the different leaderboard aggregation types.
 * 
 * @member EOS_LA_MIN Scores are aggregated by minimum.
 * @member EOS_LA_MAX Scores are aggregated by maximum.
 * @member EOS_LA_SUM Scores are aggregated by the sum of the values.
 * @member EOS_LA_LATEST Scores are aggregated by the last value.
 * @constant_end
 */


// Structs

/**
 * @struct LeaderboardUserScore
 * @desc A leaderboard definition is represented by a struct and contains information about a single leaderboard user score.
 * 
 * @member {constant.eos_result} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {string} UserId The Product User ID of the user who got this score
 * @member {real} Score Leaderboard score
 * @struct_end
 */

/**
 * @struct LeaderboardRecord
 * @desc A leaderboard record is represented by a struct and contains information about a single leaderboard record.
 * 
 * @member {constant.eos_result} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
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
 * @member {constant.eos_result} status The status code for the operation. `EOS_SUCCESS` indicates that the operation succeeded; other codes indicate errors
 * @member {string} status_message Text representation of the status code
 * @member {string} LeaderboardId Unique ID to identify leaderboard.
 * @member {string} StatName Name of stat used to rank leaderboard.
 * @member {real} StartTime The POSIX timestamp for the start time, or `EOS_LEADERBOARDS_TIME_UNDEFINED`.
 * @member {real} EndTime The POSIX timestamp for the end time, or `EOS_LEADERBOARDS_TIME_UNDEFINED`.
 * @member {constant.eos_leaderboard_aggregation} Aggregation used to sort the leaderboard.
 * @struct_end
 */


/**
 * @module leaderboards
 * @title Leaderboards
 * @desc **Epic Online Services Interface:** [Leaderboards Interface](https://dev.epicgames.com/docs/game-services/leaderboards)
 * 
 * The [Leaderboards Interface](https://dev.epicgames.com/docs/game-services/leaderboards) gives developers using **Epic Online Services** (EOS) the ability to rank scores from their entire player base, so that players can compete with their friends or other players worldwide for the top score. Each game can support multiple leaderboards, collecting scores from different sources, and ranking them with different scoring modes.
 * 
 * @section_func
 * @desc These functions are provided for handling leaderboards:
 * 
 * @ref eos_leaderboards_copy_leaderboard_definition_by_index
 * @ref eos_leaderboards_copy_leaderboard_definition_by_leaderboard_id
 * @ref eos_leaderboards_copy_leaderboard_record_by_index
 * @ref eos_leaderboards_copy_leaderboard_record_by_user_id
 * @ref eos_leaderboards_copy_leaderboard_user_score_by_index
 * @ref eos_leaderboards_copy_leaderboard_user_score_by_user_id
 * @ref eos_leaderboards_get_leaderboard_definition_count
 * @ref eos_leaderboards_get_leaderboard_record_count
 * @ref eos_leaderboards_get_leaderboard_user_score_count
 * @ref eos_leaderboards_query_leaderboard_definitions
 * @ref eos_leaderboards_query_leaderboard_ranks
 * @ref eos_leaderboards_query_leaderboard_user_scores
 * 
 * @section_end
 * 
 * @section_const
 * @desc These are the constants used for leaderboards:
 * 
 * @ref eos_leaderboard_aggregation
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
