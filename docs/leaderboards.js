// Functions

/**
 * @function eos_leaderboards_query_definitions
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_QueryLeaderboardDefinitions](https://dev.epicgames.com/docs/api-ref/functions/eos-leaderboards-query-leaderboard-definitions)
 *
 * Queries the list of leaderboard definitions for the running application. Call this before using
 * ${function.eos_leaderboards_get_definition_count}, ${function.eos_leaderboards_copy_definition_by_index}
 * or ${function.eos_leaderboards_copy_definition_by_id}.
 *
 * @param {String} local_user_id The Product User ID of the user querying the definitions.
 * @param {Real} start_time Unix timestamp to restrict the query to, or ${constant.macros}'s `EOS_LEADERBOARDS_TIME_UNDEFINED` for no lower bound.
 * @param {Real} end_time Unix timestamp to restrict the query to, or ${constant.macros}'s `EOS_LEADERBOARDS_TIME_UNDEFINED` for no upper bound.
 * @param {Function} [callback] Function invoked when the query completes.
 *
 * @event callback
 * @desc Called once when the definitions query completes.
 * @member {Struct.EpicLeaderboardsQueryDefinitionsCallbackInfo} result The result of the query.
 * @event_end
 *
 * @example
 * ```gml
 * eos_leaderboards_query_definitions(local_user_id, EOS_LEADERBOARDS_TIME_UNDEFINED, EOS_LEADERBOARDS_TIME_UNDEFINED, function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         show_debug_message($"Loaded {eos_leaderboards_get_definition_count()} leaderboard definitions");
 *     }
 * });
 * ```
 * The above code queries every leaderboard definition, with no time restriction.
 * @function_end
 */

/**
 * @function eos_leaderboards_query_ranks
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_QueryLeaderboardRanks](https://dev.epicgames.com/docs/api-ref/functions/eos-leaderboards-query-leaderboard-ranks)
 *
 * Queries the top-ranked entries (records) for a single leaderboard. Call this before using
 * ${function.eos_leaderboards_get_record_count}, ${function.eos_leaderboards_copy_record_by_index} or
 * ${function.eos_leaderboards_copy_record_by_user_id}.
 *
 * @param {String} local_user_id The Product User ID of the user querying the ranks.
 * @param {String} leaderboard_id ID of the leaderboard to query, as returned by ${struct.EpicLeaderboardDefinition}'s `leaderboard_id`.
 * @param {Function} [callback] Function invoked when the query completes.
 *
 * @event callback
 * @desc Called once when the ranks query completes.
 * @member {Struct.EpicLeaderboardsQueryRanksCallbackInfo} result The result of the query.
 * @event_end
 *
 * @example
 * ```gml
 * eos_leaderboards_query_ranks(local_user_id, "high_score", function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         show_debug_message($"Loaded {eos_leaderboards_get_record_count()} records for {_result.leaderboard_id}");
 *     }
 * });
 * ```
 * The above code queries the top records for the `"high_score"` leaderboard.
 * @function_end
 */

/**
 * @function eos_leaderboards_query_user_scores
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_QueryLeaderboardUserScores](https://dev.epicgames.com/docs/api-ref/functions/eos-leaderboards-query-leaderboard-user-scores)
 *
 * Queries scores for a specific set of users across one or more stats, regardless of where those users rank.
 * Use this instead of ${function.eos_leaderboards_query_ranks} when you want specific players' scores (e.g.
 * a friends list) rather than the overall top ranks. Call this before using
 * ${function.eos_leaderboards_get_user_score_count} and ${function.eos_leaderboards_copy_user_score_by_index}.
 *
 * @param {String} local_user_id The Product User ID of the user querying the scores.
 * @param {Array[String]} target_user_ids The Product User IDs to fetch scores for.
 * @param {Array[Struct.EpicLeaderboardStatQuery]} stat_queries The stats to query scores for, and how to aggregate them.
 * @param {Real} start_time Unix timestamp to restrict the query to, or ${constant.macros}'s `EOS_LEADERBOARDS_TIME_UNDEFINED` for no lower bound.
 * @param {Real} end_time Unix timestamp to restrict the query to, or ${constant.macros}'s `EOS_LEADERBOARDS_TIME_UNDEFINED` for no upper bound.
 * @param {Function} [callback] Function invoked when the query completes.
 *
 * @event callback
 * @desc Called once when the user-scores query completes.
 * @member {Struct.EpicLeaderboardsQueryUserScoresCallbackInfo} result The result of the query.
 * @event_end
 *
 * [[Note: Results for every queried stat are read back together with ${function.eos_leaderboards_get_user_score_count}/${function.eos_leaderboards_copy_user_score_by_index}, keyed by `stat_name` — call the accessor once per stat you queried.]]
 *
 * @example
 * ```gml
 * var _stat_queries = [{ stat_name: "high_score", aggregation: EpicLeaderboardAggregation.Max }];
 *
 * eos_leaderboards_query_user_scores(local_user_id, [friend_a_id, friend_b_id], _stat_queries, EOS_LEADERBOARDS_TIME_UNDEFINED, EOS_LEADERBOARDS_TIME_UNDEFINED, function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         var _count = eos_leaderboards_get_user_score_count("high_score");
 *         for (var i = 0; i < _count; i++)
 *         {
 *             var _score = eos_leaderboards_copy_user_score_by_index("high_score", i);
 *             show_debug_message($"{_score.user_id}: {_score.score}");
 *         }
 *     }
 * });
 * ```
 * The above code queries two friends' high scores.
 * @function_end
 */

/**
 * @function eos_leaderboards_get_definition_count
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_GetLeaderboardDefinitionCount](https://dev.epicgames.com/docs/api-ref/functions/eos-leaderboards-get-leaderboard-definition-count)
 *
 * Returns the number of leaderboard definitions available, from the last successful call to
 * ${function.eos_leaderboards_query_definitions}.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_leaderboards_get_record_count
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_GetLeaderboardRecordCount](https://dev.epicgames.com/docs/api-ref/functions/eos-leaderboards-get-leaderboard-record-count)
 *
 * Returns the number of records available, from the last successful call to ${function.eos_leaderboards_query_ranks}.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_leaderboards_get_user_score_count
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_GetLeaderboardUserScoreCount](https://dev.epicgames.com/docs/api-ref/functions/eos-leaderboards-get-leaderboard-user-score-count)
 *
 * Returns the number of user scores available for `stat_name`, from the last successful call to
 * ${function.eos_leaderboards_query_user_scores}.
 *
 * @param {String} stat_name Name of the stat to count scores for, matching one of the `stat_name`s passed to ${function.eos_leaderboards_query_user_scores}.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_leaderboards_copy_definition_by_index
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_CopyLeaderboardDefinitionByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-leaderboards-copy-leaderboard-definition-by-index)
 *
 * Fetches a leaderboard definition by index, from the cached data populated by ${function.eos_leaderboards_query_definitions}.
 *
 * @param {Real} index Index of the definition, between 0 and ${function.eos_leaderboards_get_definition_count} - 1.
 *
 * @returns {Struct.EpicLeaderboardDefinition}
 *
 * [[Warning: Returns `undefined` if `index` is out of range or no definitions have been queried yet — check ${function.eos_api_last_error} for the reason.]]
 *
 * @function_end
 */

/**
 * @function eos_leaderboards_copy_definition_by_id
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_CopyLeaderboardDefinitionByLeaderboardId](https://dev.epicgames.com/docs/api-ref/functions/eos-leaderboards-copy-leaderboard-definition-by-leaderboard-id)
 *
 * Fetches a leaderboard definition by its leaderboard ID, from the cached data populated by
 * ${function.eos_leaderboards_query_definitions}.
 *
 * @param {String} leaderboard_id ID of the leaderboard definition to fetch.
 *
 * @returns {Struct.EpicLeaderboardDefinition}
 *
 * [[Warning: Returns `undefined` if `leaderboard_id` doesn't match any queried definition — check ${function.eos_api_last_error} for the reason.]]
 *
 * @function_end
 */

/**
 * @function eos_leaderboards_copy_record_by_index
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_CopyLeaderboardRecordByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-leaderboards-copy-leaderboard-record-by-index)
 *
 * Fetches a leaderboard record (rank entry) by index, from the cached data populated by
 * ${function.eos_leaderboards_query_ranks}.
 *
 * @param {Real} index Index of the record, between 0 and ${function.eos_leaderboards_get_record_count} - 1.
 *
 * @returns {Struct.EpicLeaderboardRecord}
 *
 * [[Warning: Returns `undefined` if `index` is out of range or no ranks have been queried yet — check ${function.eos_api_last_error} for the reason.]]
 *
 * @function_end
 */

/**
 * @function eos_leaderboards_copy_record_by_user_id
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_CopyLeaderboardRecordByUserId](https://dev.epicgames.com/docs/api-ref/functions/eos-leaderboards-copy-leaderboard-record-by-user-id)
 *
 * Fetches a specific user's leaderboard record (rank entry), from the cached data populated by
 * ${function.eos_leaderboards_query_ranks}.
 *
 * @param {String} user_id The Product User ID whose record to fetch.
 *
 * @returns {Struct.EpicLeaderboardRecord}
 *
 * [[Warning: Returns `undefined` if `user_id` isn't part of the queried ranks — check ${function.eos_api_last_error} for the reason.]]
 *
 * @function_end
 */

/**
 * @function eos_leaderboards_copy_user_score_by_index
 * @desc **Epic Online Services Function:** [EOS_Leaderboards_CopyLeaderboardUserScoreByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-leaderboards-copy-leaderboard-user-score-by-index)
 *
 * Fetches one user score by index for `stat_name`, from the cached data populated by
 * ${function.eos_leaderboards_query_user_scores}.
 *
 * @param {String} stat_name Name of the stat to read a score for, matching one of the `stat_name`s passed to ${function.eos_leaderboards_query_user_scores}.
 * @param {Real} index Index of the score, between 0 and ${function.eos_leaderboards_get_user_score_count} - 1.
 *
 * @returns {Struct.EpicLeaderboardUserScore}
 *
 * [[Warning: Returns `undefined` if `stat_name` wasn't queried or `index` is out of range — check ${function.eos_api_last_error} for the reason.]]
 *
 * @function_end
 */

// Structs

/**
 * @struct EpicLeaderboardStatQuery
 * @desc One stat to query in ${function.eos_leaderboards_query_user_scores}, and how to aggregate multiple
 * entries for that stat into a single score.
 *
 * @member {String} stat_name Name of the stat to query.
 * @member {Constant.EpicLeaderboardAggregation} aggregation How to aggregate the stat's values into a score.
 *
 * @struct_end
 */

/**
 * @struct EpicLeaderboardsQueryDefinitionsCallbackInfo
 * @desc The result of ${function.eos_leaderboards_query_definitions}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the definitions were queried successfully.
 *
 * @struct_end
 */

/**
 * @struct EpicLeaderboardsQueryRanksCallbackInfo
 * @desc The result of ${function.eos_leaderboards_query_ranks}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the ranks were queried successfully.
 * @member {String} leaderboard_id ID of the leaderboard that was queried.
 *
 * @struct_end
 */

/**
 * @struct EpicLeaderboardsQueryUserScoresCallbackInfo
 * @desc The result of ${function.eos_leaderboards_query_user_scores}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the user scores were queried successfully.
 *
 * @struct_end
 */

/**
 * @struct EpicLeaderboardDefinition
 * @desc A leaderboard definition, as returned by ${function.eos_leaderboards_copy_definition_by_index}/
 * ${function.eos_leaderboards_copy_definition_by_id}.
 *
 * @member {String} leaderboard_id ID of the leaderboard.
 * @member {String} stat_name The stat this leaderboard ranks.
 * @member {Real} start_time Unix timestamp the leaderboard's tracked period starts at.
 * @member {Real} end_time Unix timestamp the leaderboard's tracked period ends at.
 * @member {String} aggregation How scores are aggregated for this leaderboard, as one of ${constant.EpicLeaderboardAggregation}'s member names (`"Min"`/`"Max"`/`"Sum"`/`"Latest"`).
 *
 * @struct_end
 */

/**
 * @struct EpicLeaderboardRecord
 * @desc A single ranked entry on a leaderboard, as returned by ${function.eos_leaderboards_copy_record_by_index}/
 * ${function.eos_leaderboards_copy_record_by_user_id}.
 *
 * @member {String} user_id The Product User ID that holds this record.
 * @member {Real} rank The record's rank on the leaderboard (1-based).
 * @member {Real} score The record's score.
 * @member {String} user_display_name Display name of the user, when available.
 *
 * @struct_end
 */

/**
 * @struct EpicLeaderboardUserScore
 * @desc A single user's score for a queried stat, as returned by ${function.eos_leaderboards_copy_user_score_by_index}.
 *
 * @member {String} user_id The Product User ID the score belongs to.
 * @member {Real} score The user's aggregated score.
 *
 * @struct_end
 */

// Constants

/**
 * @const EpicLeaderboardAggregation
 * @desc **Epic Online Services Enum:** [EOS_ELeaderboardAggregation](https://dev.epicgames.com/docs/api-ref/enums/eos-e-leaderboard-aggregation)
 *
 * How a leaderboard or a user-scores query combines multiple stat ingests into a single score.
 *
 * @member Min The lowest ingested value.
 * @member Max The highest ingested value.
 * @member Sum The sum of all ingested values.
 * @member Latest The most recently ingested value.
 *
 * @const_end
 */

/**
 * @const macros
 * @desc Standalone constants used by this module.
 *
 * @member EOS_LEADERBOARDS_TIME_UNDEFINED Pass this for `start_time`/`end_time` in ${Function.eos_leaderboards_query_definitions}/${function.eos_leaderboards_query_user_scores} to leave that bound unrestricted. Value: `-1`.
 *
 * @const_end
 */

/**
 * @module leaderboards
 * @title Leaderboards
 * @desc **Epic Online Services Interface:** [Leaderboards Interface](https://dev.epicgames.com/docs/game-services/eos-leaderboards-interface)
 *
 * The Leaderboards Interface lets you query leaderboard definitions, top ranks, and specific users' scores.
 * Leaderboards are driven by stats — see ${module.stats} for ingesting the values leaderboards rank.
 *
 * [[Note: Query before you read: ${function.eos_leaderboards_query_definitions} populates the definition
 * accessors, ${function.eos_leaderboards_query_ranks} populates the record accessors, and
 * ${function.eos_leaderboards_query_user_scores} populates the user-score accessors.]]
 *
 * @section_func
 * @desc Provided functions:
 *
 * @ref eos_leaderboards_query_definitions
 * @ref eos_leaderboards_query_ranks
 * @ref eos_leaderboards_query_user_scores
 * @ref eos_leaderboards_get_definition_count
 * @ref eos_leaderboards_get_record_count
 * @ref eos_leaderboards_get_user_score_count
 * @ref eos_leaderboards_copy_definition_by_index
 * @ref eos_leaderboards_copy_definition_by_id
 * @ref eos_leaderboards_copy_record_by_index
 * @ref eos_leaderboards_copy_record_by_user_id
 * @ref eos_leaderboards_copy_user_score_by_index
 *
 * @section_end
 *
 * @section_struct
 * @desc These are the structs used by this module:
 *
 * @ref EpicLeaderboardStatQuery
 * @ref EpicLeaderboardsQueryDefinitionsCallbackInfo
 * @ref EpicLeaderboardsQueryRanksCallbackInfo
 * @ref EpicLeaderboardsQueryUserScoresCallbackInfo
 * @ref EpicLeaderboardDefinition
 * @ref EpicLeaderboardRecord
 * @ref EpicLeaderboardUserScore
 *
 * @section_end
 *
 * @section_const
 * @desc These are the constants used by this module:
 *
 * @ref EpicLeaderboardAggregation
 * @ref macros
 *
 * @section_end
 *
 * @module_end
 */
