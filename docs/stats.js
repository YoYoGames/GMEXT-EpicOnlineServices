// Functions


/**
 * @function eos_stats_ingest_stat
 * @desc **Epic Online Services Function:** [EOS_Stats_IngestStat](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Stats/EOS_Stats_IngestStat/index.html)
 *
 * This function ingests a stat by the amount specified in `ingest_amount`. When the operation completes and the callback fires, the stat will have been uploaded to the backend for processing. The stat may not be reflected immediately, and an achievement built on top of it may take a while to unlock once the stat has actually landed.
 *
 * @param {String} local_user_id The Product User ID of the local user requesting the ingest.
 * @param {String} target_user_id The Product User ID for the user whose stat is being ingested.
 * @param {String} stat_name Name of the stat to ingest, as configured in the Developer Portal.
 * @param {Real} ingest_amount Amount to ingest for the stat.
 * @param {Function} [callback] Called once the ingest completes.
 *
 * @event callback
 * @desc Called with a single result struct once the ingest completes.
 * @member {Struct.EpicStatsIngestStatCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_stats_ingest_stat(local_user_id, local_user_id, "Enemies_Killed", 1, function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         show_debug_message("Stat ingested");
 *     }
 * });
 * ```
 * The above code ingests one unit of the `Enemies_Killed` stat for the local user.
 * @function_end
 */

/**
 * @function eos_stats_query_stats
 * @desc **Epic Online Services Function:** [EOS_Stats_QueryStats](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Stats/EOS_Stats_QueryStats/index.html)
 *
 * This function queries a list of stats for a specific player and caches the result. Once the callback fires with `EpicResult.Success`, use ${function.eos_stats_get_stats_count}, ${function.eos_stats_copy_stat_by_index}, or ${function.eos_stats_copy_stat_by_name} to read the cached values.
 *
 * [[Note: This function always queries every stat configured for the product; there is no way to narrow the query to specific stat names.]]
 *
 * @param {String} local_user_id The Product User ID of the local user requesting the stats.
 * @param {String} target_user_id The Product User ID for the user whose stats are being retrieved.
 * @param {Real} start_time The POSIX timestamp to start the query range at.
 * @param {Real} end_time The POSIX timestamp to end the query range at.
 * @param {Function} [callback] Called once the query completes.
 *
 * @event callback
 * @desc Called with a single result struct once the query completes.
 * @member {Struct.EpicStatsQueryStatsCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_stats_query_stats(local_user_id, local_user_id, 0, 0, function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         var _count = eos_stats_get_stats_count(_result.target_user_id);
 *         for (var i = 0; i < _count; i++)
 *         {
 *             var _stat = eos_stats_copy_stat_by_index(_result.target_user_id, i);
 *             show_debug_message(_stat.name + " = " + string(_stat.value));
 *         }
 *     }
 * });
 * ```
 * The above code queries all stats for the local user and prints their cached values.
 * @function_end
 */

/**
 * @function eos_stats_get_stats_count
 * @desc **Epic Online Services Function:** [EOS_Stats_GetStatsCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Stats/EOS_Stats_GetStatsCount/index.html)
 *
 * This function fetches the number of stats cached locally for a user. Requires a previous successful call to ${function.eos_stats_query_stats}.
 *
 * @param {String} target_user_id The Product User ID whose cached stat count is being read.
 *
 * @returns {Real}
 *
 * @example
 * ```gml
 * var _count = eos_stats_get_stats_count(target_user_id);
 * ```
 * The above code returns the number of cached stats for `target_user_id`.
 * @function_end
 */

/**
 * @function eos_stats_copy_stat_by_index
 * @desc **Epic Online Services Function:** [EOS_Stats_CopyStatByIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Stats/EOS_Stats_CopyStatByIndex/index.html)
 *
 * This function copies a cached stat by index. Requires a previous successful call to ${function.eos_stats_query_stats}.
 *
 * @param {String} target_user_id The Product User ID who owns the stat.
 * @param {Real} index Index of the stat to retrieve from the cache, between 0 and ${function.eos_stats_get_stats_count} minus one.
 *
 * @returns {Struct.EpicStatsStat}
 *
 * [[Note: Returns `undefined` if the index is out of range or the stat could not be copied.]]
 *
 * @example
 * ```gml
 * var _count = eos_stats_get_stats_count(target_user_id);
 * for (var i = 0; i < _count; i++)
 * {
 *     var _stat = eos_stats_copy_stat_by_index(target_user_id, i);
 *     show_debug_message(_stat.name + " = " + string(_stat.value));
 * }
 * ```
 * The above code iterates and prints every cached stat for `target_user_id`.
 * @function_end
 */

/**
 * @function eos_stats_copy_stat_by_name
 * @desc **Epic Online Services Function:** [EOS_Stats_CopyStatByName](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Stats/EOS_Stats_CopyStatByName/index.html)
 *
 * This function copies a cached stat by name. Requires a previous successful call to ${function.eos_stats_query_stats}.
 *
 * @param {String} target_user_id The Product User ID who owns the stat.
 * @param {String} name Name of the stat to retrieve from the cache.
 *
 * @returns {Struct.EpicStatsStat}
 *
 * [[Note: Returns `undefined` if no cached stat matches `name`.]]
 *
 * @example
 * ```gml
 * var _stat = eos_stats_copy_stat_by_name(target_user_id, "Enemies_Killed");
 * if (!is_undefined(_stat)) show_debug_message(string(_stat.value));
 * ```
 * The above code reads the cached `Enemies_Killed` stat for `target_user_id`.
 * @function_end
 */

// Structs

/**
 * @struct EpicStatsStat
 * @desc A single cached stat value, returned by ${function.eos_stats_copy_stat_by_index}/${function.eos_stats_copy_stat_by_name}.
 *
 * @member {String} name The name of the stat.
 * @member {Real} start_time The POSIX timestamp for the start of the query range this value was aggregated over.
 * @member {Real} end_time The POSIX timestamp for the end of the query range this value was aggregated over.
 * @member {Real} value The stat's current aggregated value.
 * @struct_end
 */

/**
 * @struct EpicStatsIngestStatCallbackInfo
 * @desc Result passed to the callback of ${function.eos_stats_ingest_stat}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` on success; any other value is an error.
 * @member {String} local_user_id The Product User ID of the local user who requested the ingest.
 * @member {String} target_user_id The Product User ID for the user whose stat was ingested.
 * @struct_end
 */

/**
 * @struct EpicStatsQueryStatsCallbackInfo
 * @desc Result passed to the callback of ${function.eos_stats_query_stats}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` on success; any other value is an error.
 * @member {String} local_user_id The Product User ID of the local user who requested the query.
 * @member {String} target_user_id The Product User ID whose stats were queried.
 * @struct_end
 */

/**
 * @module stats
 * @title Stats
 * @desc **Epic Online Services Interface:** [Stats Interface](https://dev.epicgames.com/docs/game-services/eos-stats-interface)
 *
 * The [Stats Interface](https://dev.epicgames.com/docs/game-services/eos-stats-interface) provides the ability to manage users' stats for an application - any statistical data you want to track, such as items collected, fastest completion time, or number of victories. Stats are commonly used to drive ${module.achievements} unlock conditions and ${module.leaderboards} rankings.
 *
 * @section_func
 * @desc These functions are provided for handling stats:
 *
 * @ref eos_stats_ingest_stat
 * @ref eos_stats_query_stats
 * @ref eos_stats_get_stats_count
 * @ref eos_stats_copy_stat_by_index
 * @ref eos_stats_copy_stat_by_name
 *
 * @section_end
 *
 * @section_struct
 * @desc These are the structs used by this module:
 *
 * @ref EpicStatsStat
 * @ref EpicStatsIngestStatCallbackInfo
 * @ref EpicStatsQueryStatsCallbackInfo
 *
 * @section_end
 *
 * @module_end
 */
