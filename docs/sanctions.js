// Functions


/**
 * @function eos_sanctions_query_active_player_sanctions
 * @desc **Epic Online Services Function:** [EOS_Sanctions_QueryActivePlayerSanctions](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Sanctions/EOS_Sanctions_QueryActivePlayerSanctions/index.html)
 *
 * This function starts an asynchronous query to retrieve any active sanctions for a specified user. Once the callback fires with `EpicResult.Success`, use ${function.eos_sanctions_get_player_sanction_count} and ${function.eos_sanctions_copy_player_sanction_by_index} to read the cached results.
 *
 * @param {String} local_user_id The Product User ID of the local user who initiated this request. Dedicated servers should pass an empty string.
 * @param {String} target_user_id The Product User ID of the user whose active sanctions are being queried.
 * @param {Function} [callback] Called once the query completes.
 *
 * @event callback
 * @desc Called with a single result struct once the query completes.
 * @member {Struct.EpicSanctionsQueryActivePlayerSanctionsCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_sanctions_query_active_player_sanctions(local_user_id, target_user_id, function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         var _count = eos_sanctions_get_player_sanction_count(_result.target_user_id);
 *         for (var i = 0; i < _count; i++)
 *         {
 *             var _sanction = eos_sanctions_copy_player_sanction_by_index(_result.target_user_id, i);
 *             show_debug_message(_sanction.action);
 *         }
 *     }
 * });
 * ```
 * The above code queries active sanctions for `target_user_id` and prints each sanction's action.
 * @function_end
 */

/**
 * @function eos_sanctions_get_player_sanction_count
 * @desc **Epic Online Services Function:** [EOS_Sanctions_GetPlayerSanctionCount](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Sanctions/EOS_Sanctions_GetPlayerSanctionCount/index.html)
 *
 * This function fetches the number of active sanctions cached locally for a user. Requires a previous successful call to ${function.eos_sanctions_query_active_player_sanctions}.
 *
 * @param {String} target_user_id The Product User ID whose cached sanction count is being read.
 *
 * @returns {Real}
 *
 * @example
 * ```gml
 * var _count = eos_sanctions_get_player_sanction_count(target_user_id);
 * ```
 * The above code returns the number of active sanctions cached for `target_user_id`.
 * @function_end
 */

/**
 * @function eos_sanctions_copy_player_sanction_by_index
 * @desc **Epic Online Services Function:** [EOS_Sanctions_CopyPlayerSanctionByIndex](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Sanctions/EOS_Sanctions_CopyPlayerSanctionByIndex/index.html)
 *
 * This function copies a cached active sanction by index. Requires a previous successful call to ${function.eos_sanctions_query_active_player_sanctions}.
 *
 * @param {String} target_user_id The Product User ID who owns the sanction.
 * @param {Real} index Index of the sanction to retrieve from the cache, between 0 and ${function.eos_sanctions_get_player_sanction_count} minus one.
 *
 * @returns {Struct.EpicSanctionsPlayerSanction}
 *
 * [[Note: Returns `undefined` if the index is out of range or the sanction could not be copied.]]
 *
 * @example
 * ```gml
 * var _count = eos_sanctions_get_player_sanction_count(target_user_id);
 * for (var i = 0; i < _count; i++)
 * {
 *     var _sanction = eos_sanctions_copy_player_sanction_by_index(target_user_id, i);
 *     show_debug_message(_sanction.action);
 * }
 * ```
 * The above code iterates and prints every active sanction for `target_user_id`.
 * @function_end
 */

/**
 * @function eos_sanctions_create_player_sanction_appeal
 * @desc **Epic Online Services Function:** [EOS_Sanctions_CreatePlayerSanctionAppeal](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Sanctions/EOS_Sanctions_CreatePlayerSanctionAppeal/index.html)
 *
 * This function submits an appeal for a previously placed sanction.
 *
 * @param {String} local_user_id The Product User ID of the local user filing the appeal.
 * @param {String} reference_id The sanction's `reference_id` (from ${struct.EpicSanctionsPlayerSanction}) being appealed.
 * @param {Constant.EpicSanctionAppealReason} reason The reason for the appeal.
 * @param {Function} [callback] Called once the appeal has been submitted.
 *
 * @event callback
 * @desc Called with a single result struct once the appeal has been submitted.
 * @member {Struct.EpicSanctionsCreatePlayerSanctionAppealCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_sanctions_create_player_sanction_appeal(local_user_id, reference_id, EpicSanctionAppealReason.CompromisedAccount, function(_result)
 * {
 *     show_debug_message("Appeal result: " + string(_result.result_code));
 * });
 * ```
 * The above code appeals a sanction, claiming the account was compromised.
 * @function_end
 */

// Structs

/**
 * @struct EpicSanctionsPlayerSanction
 * @desc A single active sanction, returned by ${function.eos_sanctions_copy_player_sanction_by_index}.
 *
 * @member {Real} time_placed The POSIX timestamp when the sanction was placed.
 * @member {String} action The action associated with this sanction.
 * @member {Real} time_expires The POSIX timestamp when the sanction will expire. `0` if the sanction is permanent.
 * @member {String} reference_id A unique identifier for this specific sanction, used with ${function.eos_sanctions_create_player_sanction_appeal}.
 * @struct_end
 */

/**
 * @struct EpicSanctionsQueryActivePlayerSanctionsCallbackInfo
 * @desc Result passed to the callback of ${function.eos_sanctions_query_active_player_sanctions}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` on success; any other value is an error.
 * @member {String} local_user_id The Product User ID of the local user who initiated the request.
 * @member {String} target_user_id The Product User ID whose sanctions were queried.
 * @struct_end
 */

/**
 * @struct EpicSanctionsCreatePlayerSanctionAppealCallbackInfo
 * @desc Result passed to the callback of ${function.eos_sanctions_create_player_sanction_appeal}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` on success; any other value is an error.
 * @member {String} reference_id The sanction's reference ID that was appealed.
 * @struct_end
 */

// Constants

/**
 * @const EpicSanctionAppealReason
 * @desc **Epic Online Services Enum:** [EOS_ESanctionAppealReason](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-sanction-appeal-reason)
 *
 * The reason given for an appeal submitted via ${function.eos_sanctions_create_player_sanction_appeal}.
 *
 * @member Invalid Invalid reason, do not use.
 * @member IncorrectSanction The sanction was placed incorrectly.
 * @member CompromisedAccount The account was compromised at the time of the offending action.
 * @member UnfairPunishment The punishment is considered unfair for the offense.
 * @member AppealForForgiveness A general request for forgiveness/leniency.
 * @const_end
 */

/**
 * @module sanctions
 * @title Sanctions
 * @desc **Epic Online Services Interface:** [Sanctions Interface](https://dev.epicgames.com/docs/game-services/sanctions-interface)
 *
 * The [Sanctions Interface](https://dev.epicgames.com/docs/game-services/sanctions-interface) manages punitive actions taken against your users, such as temporary or permanent bans from gameplay or communication. You define the disciplinary actions for your product and how to handle negative behaviour.
 *
 * @section_func
 * @desc These functions are provided for handling sanctions:
 *
 * @ref eos_sanctions_query_active_player_sanctions
 * @ref eos_sanctions_get_player_sanction_count
 * @ref eos_sanctions_copy_player_sanction_by_index
 * @ref eos_sanctions_create_player_sanction_appeal
 *
 * @section_end
 *
 * @section_struct
 * @desc These are the structs used by this module:
 *
 * @ref EpicSanctionsPlayerSanction
 * @ref EpicSanctionsQueryActivePlayerSanctionsCallbackInfo
 * @ref EpicSanctionsCreatePlayerSanctionAppealCallbackInfo
 *
 * @section_end
 *
 * @section_const
 * @desc These are the constants used by this module:
 *
 * @ref EpicSanctionAppealReason
 *
 * @section_end
 *
 * @module_end
 */
