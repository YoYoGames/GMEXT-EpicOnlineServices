// Functions

/**
 * @function eos_user_info_query_user_info
 * @desc **Epic Online Services Function:** [EOS_UserInfo_QueryUserInfo](https://dev.epicgames.com/docs/api-ref/functions/eos-user-info-query-user-info)
 *
 * Starts an asynchronous task that fetches a target user's basic info (display name, country, preferred
 * language, nickname) from the backend and caches it locally. You must call this before
 * ${function.eos_user_info_copy_user_info} returns anything for that pair of users.
 *
 * @param {String} local_user_id The Epic Account ID of the local, logged-in user making the request.
 * @param {String} target_user_id The Epic Account ID of the user to query info for.
 * @param {Function} [callback] Called once with the result. See the `callback` event below.
 *
 * @event callback
 * @desc Fires once, after the query completes (or fails).
 * @member {Struct.EpicUserInfoQueryUserInfoCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_user_info_query_user_info(local_user_id, target_user_id, function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         var _info = eos_user_info_copy_user_info(_result.local_user_id, _result.target_user_id);
 *         show_debug_message($"Display name: {_info.display_name}");
 *     }
 * });
 * ```
 * The above code queries a target user's info, then reads the cached display name once the query completes.
 * @function_end
 */

/**
 * @function eos_user_info_copy_user_info
 * @desc **Epic Online Services Function:** [EOS_UserInfo_CopyUserInfo](https://dev.epicgames.com/docs/api-ref/functions/eos-user-info-copy-user-info)
 *
 * Returns the cached info for a target user, from the last successful ${function.eos_user_info_query_user_info}.
 *
 * @param {String} local_user_id The Epic Account ID of the local, logged-in user.
 * @param {String} target_user_id The Epic Account ID of the user whose cached info to copy.
 *
 * @returns {Struct.EpicUserInfo}
 *
 * [[Note: Returns `undefined` if no info is cached for this pair of users — call ${function.eos_user_info_query_user_info} first.]]
 *
 * @function_end
 */

/**
 * @function eos_user_info_get_local_platform_type
 * @desc **Epic Online Services Function:** [EOS_UserInfo_GetLocalPlatformType](https://dev.epicgames.com/docs/api-ref/functions/eos-user-info-get-local-platform-type)
 *
 * Returns the online platform type of the current running instance of the game.
 *
 * [[Note: The SDK exposes this as a set of loose integer constants rather than a real enum, so this function returns a plain real value. Known values: `0` Unknown, `100` Epic, `1000` PSN, `2000` Nintendo, `3000` Xbox Live.]]
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_user_info_copy_best_display_name
 * @desc **Epic Online Services Function:** [EOS_UserInfo_CopyBestDisplayName](https://dev.epicgames.com/docs/api-ref/functions/eos-user-info-copy-best-display-name)
 *
 * Returns the best available display name string for a target user — the SDK internally picks the most
 * appropriate display name source (Epic display name, platform display name, etc.) for the pair of users
 * involved, which can differ from the raw `display_name` field on ${struct.EpicUserInfo}.
 *
 * @param {String} local_user_id The Epic Account ID of the local, logged-in user.
 * @param {String} target_user_id The Epic Account ID of the user to get the best display name for.
 *
 * @returns {String}
 *
 * [[Note: Returns an empty string if a best display name could not be determined for this pair of users.]]
 *
 * @function_end
 */

/**
 * @function eos_user_info_copy_external_user_info_by_index
 * @desc **Epic Online Services Function:** [EOS_UserInfo_CopyExternalUserInfoByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-user-info-copy-external-user-info-by-index)
 *
 * Returns a target user's cached linked external account info (e.g. a linked Steam or PSN account) at the given index.
 *
 * @param {String} local_user_id The Epic Account ID of the local, logged-in user.
 * @param {String} target_user_id The Epic Account ID of the user to look up external account info for.
 * @param {Real} index Index into the cached external account list.
 *
 * @returns {Struct.EpicUserInfoExternalUserInfo}
 *
 * [[Note: Returns `undefined` if the index is out of range.]]
 *
 * @function_end
 */

/**
 * @function eos_user_info_copy_external_user_info_by_account_type
 * @desc **Epic Online Services Function:** [EOS_UserInfo_CopyExternalUserInfoByAccountType](https://dev.epicgames.com/docs/api-ref/functions/eos-user-info-copy-external-user-info-by-account-type)
 *
 * Returns a target user's cached linked external account info for a specific platform, e.g. their linked Steam account.
 *
 * @param {String} local_user_id The Epic Account ID of the local, logged-in user.
 * @param {String} target_user_id The Epic Account ID of the user to look up external account info for.
 * @param {Constant.EpicExternalAccountType} account_type The external platform to look up.
 *
 * @returns {Struct.EpicUserInfoExternalUserInfo}
 *
 * [[Note: Returns `undefined` if the target user has no linked account of this type.]]
 *
 * @function_end
 */

/**
 * @function eos_user_info_copy_external_user_info_by_account_id
 * @desc **Epic Online Services Function:** [EOS_UserInfo_CopyExternalUserInfoByAccountId](https://dev.epicgames.com/docs/api-ref/functions/eos-user-info-copy-external-user-info-by-account-id)
 *
 * Returns a target user's cached linked external account info matching a specific external account ID.
 *
 * @param {String} local_user_id The Epic Account ID of the local, logged-in user.
 * @param {String} target_user_id The Epic Account ID of the user to look up external account info for.
 * @param {String} account_id The external platform's account ID to look up.
 *
 * @returns {Struct.EpicUserInfoExternalUserInfo}
 *
 * [[Note: Returns `undefined` if no cached linked account matches this ID.]]
 *
 * @function_end
 */

// Structs

/**
 * @struct EpicUserInfo
 * @desc A user's basic public info, as cached by ${function.eos_user_info_query_user_info}.
 *
 * @member {String} user_id The Epic Account ID this info is for.
 * @member {String} country The user's country, as an ISO 3166 country code, if available.
 * @member {String} display_name The user's raw Epic display name.
 * @member {String} preferred_language The user's preferred language, as an ISO 639 language code, if available.
 * @member {String} nickname A per-relationship nickname (e.g. a friend nickname) the local user has set for this user, if any.
 *
 * @struct_end
 */

/**
 * @struct EpicUserInfoQueryUserInfoCallbackInfo
 * @desc The result of an ${function.eos_user_info_query_user_info} call.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` if the info was fetched; an error code otherwise.
 * @member {String} local_user_id The Epic Account ID of the local user the query was made for.
 * @member {String} target_user_id The Epic Account ID of the user the query was for.
 *
 * @struct_end
 */

/**
 * @struct EpicUserInfoExternalUserInfo
 * @desc A single external (non-Epic) account linked to a user, as returned by the `copy_external_user_info_by_*` functions.
 *
 * @member {String} account_id The external account's ID on its own platform.
 * @member {Constant.EpicExternalAccountType} account_type The external platform this account belongs to.
 * @member {String} display_name The external account's display name.
 *
 * @struct_end
 */

/**
 * @module user_info
 * @title User Info
 * @desc **Epic Online Services Interface:** [UserInfo Interface](https://dev.epicgames.com/docs/game-services/eos-user-info-interface)
 *
 * The [UserInfo Interface](https://dev.epicgames.com/docs/game-services/eos-user-info-interface) retrieves public account information — display name, country, linked external accounts — for any Epic user, not just friends. See ${module.friends} for the local user's own friends list, and ${module.connect} for `EpicExternalAccountType`/linking a user's own external accounts.
 *
 * [[Note: You must call ${function.eos_user_info_query_user_info} for a given target user before the cached accessor functions below return anything for them.]]
 *
 * @section_func
 * @desc Provided functions:
 *
 * @ref eos_user_info_query_user_info
 * @ref eos_user_info_copy_user_info
 * @ref eos_user_info_get_local_platform_type
 * @ref eos_user_info_copy_best_display_name
 * @ref eos_user_info_copy_external_user_info_by_index
 * @ref eos_user_info_copy_external_user_info_by_account_type
 * @ref eos_user_info_copy_external_user_info_by_account_id
 *
 * @section_end
 *
 * @section_struct
 * @desc These are the structs used by this API:
 *
 * @ref EpicUserInfo
 * @ref EpicUserInfoQueryUserInfoCallbackInfo
 * @ref EpicUserInfoExternalUserInfo
 *
 * @section_end
 *
 * @module_end
 */
