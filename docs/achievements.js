// Functions

/**
 * @function eos_achievements_query_definitions
 * @desc **Epic Online Services Function:** [EOS_Achievements_QueryDefinitions](https://dev.epicgames.com/docs/api-ref/functions/eos-achievements-query-definitions)
 *
 * Queries the list of achievement definitions for the running application, optionally including localized text
 * for the locale configured for `local_user_id`. Call this once at startup (or whenever you need fresh
 * definitions) before using ${function.eos_achievements_get_achievement_definition_count},
 * ${function.eos_achievements_copy_achievement_definition_by_index}, ${function.eos_achievements_copy_achievement_definition_by_id}
 * or ${function.eos_achievements_copy_achievement_definition_v2_by_index} — those accessors read from the
 * results of the most recent successful query.
 *
 * @param {String} local_user_id The Product User ID of the user querying the definitions.
 * @param {Function} [callback] Function invoked when the query completes.
 *
 * @event callback
 * @desc Called once when the definitions query completes.
 * @member {Struct.EpicAchievementsQueryDefinitionsCallbackInfo} result The result of the query.
 * @event_end
 *
 * @example
 * ```gml
 * eos_achievements_query_definitions(local_user_id, function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         var _count = eos_achievements_get_achievement_definition_count();
 *         show_debug_message($"Loaded {_count} achievement definitions");
 *     }
 * });
 * ```
 * The above code queries the achievement definitions and reports how many were loaded once the query succeeds.
 * @function_end
 */

/**
 * @function eos_achievements_query_player_achievements
 * @desc **Epic Online Services Function:** [EOS_Achievements_QueryPlayerAchievements](https://dev.epicgames.com/docs/api-ref/functions/eos-achievements-query-player-achievements)
 *
 * Queries a player's achievement progress. `target_user_id` doesn't need to be the same as `local_user_id` —
 * you can query another player's progress as long as `local_user_id` has permission to see it. Call this
 * before using ${function.eos_achievements_get_player_achievement_count}, ${function.eos_achievements_copy_player_achievement_by_index}
 * or ${function.eos_achievements_copy_player_achievement_by_id} for that `target_user_id`.
 *
 * @param {String} local_user_id The Product User ID of the user performing the query.
 * @param {String} target_user_id The Product User ID of the player whose achievements to query.
 * @param {Function} [callback] Function invoked when the query completes.
 *
 * @event callback
 * @desc Called once when the query completes.
 * @member {Struct.EpicAchievementsQueryPlayerAchievementsCallbackInfo} result The result of the query.
 * @event_end
 *
 * @example
 * ```gml
 * eos_achievements_query_player_achievements(local_user_id, local_user_id, function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         show_debug_message($"Loaded {eos_achievements_get_player_achievement_count(_result.user_id, _result.target_user_id)} achievements for {_result.target_user_id}");
 *     }
 * });
 * ```
 * The above code queries the local player's own achievement progress.
 * @function_end
 */

/**
 * @function eos_achievements_get_achievement_definition_count
 * @desc **Epic Online Services Function:** [EOS_Achievements_GetAchievementDefinitionCount](https://dev.epicgames.com/docs/api-ref/functions/eos-achievements-get-achievement-definition-count)
 *
 * Returns the number of achievement definitions available, from the last successful call to
 * ${function.eos_achievements_query_definitions}.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_achievements_get_player_achievement_count
 * @desc **Epic Online Services Function:** [EOS_Achievements_GetPlayerAchievementCount](https://dev.epicgames.com/docs/api-ref/functions/eos-achievements-get-player-achievement-count)
 *
 * Returns the number of achievements associated with `target_user_id`, from the last successful call to
 * ${function.eos_achievements_query_player_achievements} for that user.
 *
 * @param {String} local_user_id The Product User ID of the user making the request.
 * @param {String} target_user_id The Product User ID of the player whose achievement count to fetch.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_achievements_copy_achievement_definition_by_index
 * @desc **Epic Online Services Function:** [EOS_Achievements_CopyAchievementDefinitionByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-achievements-copy-achievement-definition-by-index)
 *
 * Fetches an achievement definition by index from the cached data populated by ${function.eos_achievements_query_definitions}.
 *
 * [[Note: This is the deprecated (V1) definition shape — prefer ${function.eos_achievements_copy_achievement_definition_v2_by_index} for new code, which reports separate unlocked/locked display text instead of a single ambiguous pair.]]
 *
 * @param {Real} index Index of the definition, between 0 and ${function.eos_achievements_get_achievement_definition_count} - 1.
 *
 * @returns {Struct.EpicAchievementsDefinition}
 *
 * [[Warning: Returns `undefined` if `index` is out of range or no definitions have been queried yet — check ${function.eos_api_last_error} for the reason.]]
 *
 * @function_end
 */

/**
 * @function eos_achievements_copy_achievement_definition_v2_by_index
 * @desc **Epic Online Services Function:** [EOS_Achievements_CopyAchievementDefinitionV2ByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-achievements-copy-achievement-definition-v2-by-index)
 *
 * Fetches an achievement definition (V2 shape, with separate unlocked/locked display text) by index from the
 * cached data populated by ${function.eos_achievements_query_definitions}.
 *
 * @param {Real} index Index of the definition, between 0 and ${function.eos_achievements_get_achievement_definition_count} - 1.
 *
 * @returns {Struct.EpicAchievementsDefinitionV2}
 *
 * [[Warning: Returns `undefined` if `index` is out of range or no definitions have been queried yet — check ${function.eos_api_last_error} for the reason.]]
 *
 * @function_end
 */

/**
 * @function eos_achievements_copy_achievement_definition_by_id
 * @desc **Epic Online Services Function:** [EOS_Achievements_CopyAchievementDefinitionByAchievementId](https://dev.epicgames.com/docs/api-ref/functions/eos-achievements-copy-achievement-definition-by-achievement-id)
 *
 * Fetches an achievement definition (V1 shape) by its achievement ID, from the cached data populated by
 * ${function.eos_achievements_query_definitions}.
 *
 * @param {String} achievement_id ID of the achievement definition to fetch.
 *
 * @returns {Struct.EpicAchievementsDefinition}
 *
 * [[Warning: Returns `undefined` if `achievement_id` doesn't match any queried definition — check ${function.eos_api_last_error} for the reason.]]
 *
 * @function_end
 */

/**
 * @function eos_achievements_copy_player_achievement_by_index
 * @desc **Epic Online Services Function:** [EOS_Achievements_CopyPlayerAchievementByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-achievements-copy-player-achievement-by-index)
 *
 * Fetches a player's achievement progress by index, from the cached data populated by
 * ${function.eos_achievements_query_player_achievements}.
 *
 * @param {String} local_user_id The Product User ID of the user making the request.
 * @param {String} target_user_id The Product User ID of the player whose achievement to fetch.
 * @param {Real} index Index of the achievement, between 0 and ${function.eos_achievements_get_player_achievement_count} - 1.
 *
 * @returns {Struct.EpicPlayerAchievement}
 *
 * [[Warning: Returns `undefined` if `index` is out of range or the ids are invalid — check ${function.eos_api_last_error} for the reason.]]
 *
 * @function_end
 */

/**
 * @function eos_achievements_copy_player_achievement_by_id
 * @desc **Epic Online Services Function:** [EOS_Achievements_CopyPlayerAchievementByAchievementId](https://dev.epicgames.com/docs/api-ref/functions/eos-achievements-copy-player-achievement-by-achievement-id)
 *
 * Fetches a player's achievement progress by achievement ID, from the cached data populated by
 * ${function.eos_achievements_query_player_achievements}.
 *
 * @param {String} local_user_id The Product User ID of the user making the request.
 * @param {String} target_user_id The Product User ID of the player whose achievement to fetch.
 * @param {String} achievement_id ID of the achievement to fetch.
 *
 * @returns {Struct.EpicPlayerAchievement}
 *
 * [[Warning: Returns `undefined` if `achievement_id` doesn't match a queried achievement or the ids are invalid — check ${function.eos_api_last_error} for the reason.]]
 *
 * @function_end
 */

/**
 * @function eos_achievements_copy_stat_threshold_by_index
 * @desc **Epic Online Services Function:** [EOS_Achievements_CopyAchievementDefinitionV2ByAchievementId](https://dev.epicgames.com/docs/api-ref/functions/eos-achievements-copy-achievement-definition-v2-by-achievement-id)
 *
 * Fetches one stat threshold entry (a stat name and the value it must reach) from the given achievement's
 * definition, by index. Internally this fetches the achievement's V2 definition and indexes into its embedded
 * threshold list — it does not require you to have called ${function.eos_achievements_query_definitions}
 * again beforehand, but the achievement itself must exist on the backend.
 *
 * @param {String} achievement_id ID of the achievement whose thresholds to read.
 * @param {Real} index Index of the threshold entry, between 0 and the achievement's `stat_thresholds_count`.
 *
 * @returns {Struct.EpicStatThreshold}
 *
 * [[Warning: Returns `undefined` if `achievement_id` is invalid or `index` is out of range — check ${function.eos_api_last_error} for the reason.]]
 *
 * @function_end
 */

/**
 * @function eos_achievements_copy_player_stat_info_by_index
 * @desc **Epic Online Services Function:** [EOS_Achievements_CopyPlayerAchievementByAchievementId](https://dev.epicgames.com/docs/api-ref/functions/eos-achievements-copy-player-achievement-by-achievement-id)
 *
 * Fetches one stat progress entry (current value vs. threshold) from a player's achievement progress, by
 * index. Requires ${function.eos_achievements_query_player_achievements} to have completed for `target_user_id`.
 *
 * @param {String} local_user_id The Product User ID of the user making the request.
 * @param {String} target_user_id The Product User ID of the player whose stat info to read.
 * @param {String} achievement_id ID of the achievement whose stat info to read.
 * @param {Real} index Index of the stat info entry, between 0 and the achievement's `stat_info_count`.
 *
 * @returns {Struct.EpicPlayerStatInfo}
 *
 * [[Warning: Returns `undefined` if the ids are invalid or `index` is out of range — check ${function.eos_api_last_error} for the reason.]]
 *
 * @function_end
 */

/**
 * @function eos_achievements_unlock_achievements
 * @desc **Epic Online Services Function:** [EOS_Achievements_UnlockAchievements](https://dev.epicgames.com/docs/api-ref/functions/eos-achievements-unlock-achievements)
 *
 * Directly unlocks one or more achievements for a player. Most games instead unlock achievements
 * automatically on the backend once the underlying stats reach their thresholds — use this for achievements
 * that aren't stat-driven.
 *
 * @param {String} user_id The Product User ID of the player to unlock achievements for.
 * @param {Array[String]} achievement_ids The IDs of the achievements to unlock.
 * @param {Function} [callback] Function invoked when the request completes.
 *
 * @event callback
 * @desc Called once when the unlock request completes.
 * @member {Struct.EpicAchievementsUnlockAchievementsCallbackInfo} result The result of the request.
 * @event_end
 *
 * @example
 * ```gml
 * eos_achievements_unlock_achievements(user_id, ["ach_first_win", "ach_no_deaths"], function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         show_debug_message($"Unlocked {_result.achievements_count} achievement(s)");
 *     }
 * });
 * ```
 * The above code unlocks two achievements directly for the given player.
 * @function_end
 */

/**
 * @function eos_achievements_add_notify_achievements_unlocked_v2
 * @desc **Epic Online Services Function:** [EOS_Achievements_AddNotifyAchievementsUnlockedV2](https://dev.epicgames.com/docs/api-ref/functions/eos-achievements-add-notify-achievements-unlocked-v2)
 *
 * Registers to be notified whenever an achievement is unlocked for any locally logged-in user, however it
 * was unlocked (through ${function.eos_achievements_unlock_achievements} or automatically via stats). If the
 * returned notification ID is valid, call ${function.eos_achievements_remove_notify_achievements_unlocked}
 * when you no longer need it (e.g. on room/game end).
 *
 * @param {Function} [callback] Function invoked every time an achievement unlocks.
 *
 * @returns {Real} A notification ID, or `0` if registration failed.
 *
 * @event callback
 * @desc Called once per achievement unlock.
 * @member {Struct.EpicAchievementsUnlockedV2CallbackInfo} result Details of the unlocked achievement.
 * @event_end
 *
 * @example
 * ```gml
 * global.achievement_notify_id = eos_achievements_add_notify_achievements_unlocked_v2(function(_result)
 * {
 *     show_debug_message($"Achievement unlocked: {_result.achievement_id}");
 * });
 * ```
 * The above code registers a persistent listener for achievement unlocks.
 * @function_end
 */

/**
 * @function eos_achievements_remove_notify_achievements_unlocked
 * @desc **Epic Online Services Function:** [EOS_Achievements_RemoveNotifyAchievementsUnlocked](https://dev.epicgames.com/docs/api-ref/functions/eos-achievements-remove-notify-achievements-unlocked)
 *
 * Unregisters a notification previously registered with ${function.eos_achievements_add_notify_achievements_unlocked_v2}.
 *
 * @param {Real} notification_id The notification ID returned by ${function.eos_achievements_add_notify_achievements_unlocked_v2}.
 *
 * @function_end
 */

// Structs

/**
 * @struct EpicAchievementsQueryDefinitionsCallbackInfo
 * @desc The result of ${function.eos_achievements_query_definitions}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the definitions were queried successfully.
 *
 * @struct_end
 */

/**
 * @struct EpicAchievementsQueryPlayerAchievementsCallbackInfo
 * @desc The result of ${function.eos_achievements_query_player_achievements}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the player's achievements were queried successfully.
 * @member {String} user_id The Product User ID that made the request.
 * @member {String} target_user_id The Product User ID whose achievements were queried.
 *
 * @struct_end
 */

/**
 * @struct EpicStatThreshold
 * @desc One stat name/threshold pair required for an achievement to unlock, as returned by
 * ${function.eos_achievements_copy_stat_threshold_by_index}.
 *
 * @member {String} name The name of the stat.
 * @member {Real} threshold The value the stat must reach to satisfy this part of the achievement.
 *
 * @struct_end
 */

/**
 * @struct EpicPlayerStatInfo
 * @desc A player's current progress towards one of an achievement's stat thresholds, as returned by
 * ${function.eos_achievements_copy_player_stat_info_by_index}.
 *
 * @member {String} name The name of the stat.
 * @member {Real} current_value The player's current value for this stat.
 * @member {Real} threshold_value The value the stat must reach for this part of the achievement.
 *
 * @struct_end
 */

/**
 * @struct EpicAchievementsStatThresholds
 * @desc One stat threshold entry embedded in a ${struct.EpicAchievementsDefinition}'s `stat_thresholds` array.
 *
 * @member {String} name The name of the stat.
 * @member {Real} threshold The value the stat must reach to satisfy this part of the achievement.
 *
 * @struct_end
 */

/**
 * @struct EpicAchievementsUnlockAchievementsCallbackInfo
 * @desc The result of ${function.eos_achievements_unlock_achievements}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the achievements were unlocked successfully.
 * @member {String} user_id The Product User ID the achievements were unlocked for.
 * @member {Real} achievements_count The number of achievements that were unlocked by this call.
 *
 * @struct_end
 */

/**
 * @struct EpicAchievementsDefinition
 * @desc The deprecated (V1) achievement definition shape, as returned by
 * ${function.eos_achievements_copy_achievement_definition_by_index}/${function.eos_achievements_copy_achievement_definition_by_id}.
 * Prefer ${struct.EpicAchievementsDefinitionV2} for new code.
 *
 * @member {String} achievement_id The ID of the achievement.
 * @member {String} display_name The unlocked display name.
 * @member {String} description The unlocked description.
 * @member {String} locked_display_name The locked display name.
 * @member {String} locked_description The locked description.
 * @member {String} hidden_description The description shown for a hidden achievement before it's unlocked.
 * @member {String} completion_description Flavor text shown once the achievement completes.
 * @member {String} unlocked_icon_id ID of the icon shown when unlocked.
 * @member {String} locked_icon_id ID of the icon shown when locked.
 * @member {Bool} is_hidden Whether the achievement is hidden until unlocked.
 * @member {Real} stat_thresholds_count Number of entries in `stat_thresholds`.
 * @member {Array[Struct.EpicAchievementsStatThresholds]} stat_thresholds The stat name/threshold pairs required to unlock this achievement.
 *
 * @struct_end
 */

/**
 * @struct EpicAchievementsDefinitionV2
 * @desc The current achievement definition shape, as returned by
 * ${function.eos_achievements_copy_achievement_definition_v2_by_index}. Unlike ${struct.EpicAchievementsDefinition}
 * this reports separate display text for the unlocked and locked states rather than one ambiguous pair.
 *
 * @member {String} achievement_id The ID of the achievement.
 * @member {String} unlocked_display_name The display name shown once unlocked.
 * @member {String} unlocked_description The description shown once unlocked.
 * @member {String} locked_display_name The display name shown while locked.
 * @member {String} locked_description The description shown while locked.
 * @member {String} flavor_text Flavor text for the achievement.
 * @member {String} completion_description Description shown when the achievement is completed.
 * @member {String} unlocked_icon_url URL of the icon shown when unlocked.
 * @member {String} locked_icon_url URL of the icon shown when locked.
 * @member {Bool} is_hidden Whether the achievement is hidden until unlocked.
 * @member {Real} stat_thresholds_count Number of stat thresholds behind this achievement (fetch them individually with ${function.eos_achievements_copy_stat_threshold_by_index}).
 *
 * @struct_end
 */

/**
 * @struct EpicPlayerAchievement
 * @desc A player's progress towards a single achievement, as returned by
 * ${function.eos_achievements_copy_player_achievement_by_index}/${function.eos_achievements_copy_player_achievement_by_id}.
 *
 * @member {String} achievement_id The ID of the achievement.
 * @member {Real} progress Progress towards completion, from `0` to `1`.
 * @member {Real} unlock_time Unix timestamp the achievement was unlocked at, or `-1` if not yet unlocked.
 * @member {Real} stat_info_count Number of entries in `stat_info`.
 * @member {Array[Struct.EpicPlayerStatInfo]} stat_info Per-stat progress towards this achievement's thresholds.
 * @member {String} display_name The display name for the achievement's current state (locked/unlocked).
 * @member {String} description The description for the achievement's current state (locked/unlocked).
 * @member {String} icon_url URL of the icon for the achievement's current state (locked/unlocked).
 * @member {String} flavor_text Flavor text for the achievement.
 *
 * @struct_end
 */

/**
 * @struct EpicAchievementsUnlockedV2CallbackInfo
 * @desc Reported to a listener registered with ${function.eos_achievements_add_notify_achievements_unlocked_v2}
 * whenever an achievement unlocks.
 *
 * @member {String} user_id The Product User ID the achievement was unlocked for.
 * @member {String} achievement_id The ID of the achievement that was unlocked.
 * @member {Real} unlock_time Unix timestamp the achievement was unlocked at.
 *
 * @struct_end
 */

/**
 * @module achievements
 * @title Achievements
 * @desc **Epic Online Services Interface:** [Achievements Interface](https://dev.epicgames.com/docs/game-services/eos-achievements-interface)
 *
 * The Achievements Interface lets you query achievement definitions and player progress, unlock achievements
 * directly, and listen for unlocks that happen automatically as stats cross their thresholds.
 *
 * [[Note: Query the achievement definitions with ${function.eos_achievements_query_definitions} and a player's
 * progress with ${function.eos_achievements_query_player_achievements} before reading either — the accessor
 * functions below read from the most recently cached query result.]]
 *
 * @section_func
 * @desc Provided functions:
 *
 * @ref eos_achievements_query_definitions
 * @ref eos_achievements_query_player_achievements
 * @ref eos_achievements_get_achievement_definition_count
 * @ref eos_achievements_get_player_achievement_count
 * @ref eos_achievements_copy_achievement_definition_by_index
 * @ref eos_achievements_copy_achievement_definition_v2_by_index
 * @ref eos_achievements_copy_achievement_definition_by_id
 * @ref eos_achievements_copy_player_achievement_by_index
 * @ref eos_achievements_copy_player_achievement_by_id
 * @ref eos_achievements_copy_stat_threshold_by_index
 * @ref eos_achievements_copy_player_stat_info_by_index
 * @ref eos_achievements_unlock_achievements
 * @ref eos_achievements_add_notify_achievements_unlocked_v2
 * @ref eos_achievements_remove_notify_achievements_unlocked
 *
 * @section_end
 *
 * @section_struct
 * @desc These are the structs used by this module:
 *
 * @ref EpicAchievementsQueryDefinitionsCallbackInfo
 * @ref EpicAchievementsQueryPlayerAchievementsCallbackInfo
 * @ref EpicStatThreshold
 * @ref EpicPlayerStatInfo
 * @ref EpicAchievementsStatThresholds
 * @ref EpicAchievementsUnlockAchievementsCallbackInfo
 * @ref EpicAchievementsDefinition
 * @ref EpicAchievementsDefinitionV2
 * @ref EpicPlayerAchievement
 * @ref EpicAchievementsUnlockedV2CallbackInfo
 *
 * @section_end
 *
 * @module_end
 */
