// Functions


/**
 * @function eos_progression_snapshot_begin_snapshot
 * @desc **Epic Online Services Function:** [EOS_ProgressionSnapshot_BeginSnapshot](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/ProgressionSnapshot/EOS_ProgressionSnapshot_BeginSnapshot/index.html)
 *
 * This function creates a new progression-snapshot resource for a given user and returns a snapshot ID. Use that ID with ${function.eos_progression_snapshot_add_progression}, ${function.eos_progression_snapshot_end_snapshot}, ${function.eos_progression_snapshot_submit_snapshot}, and ${function.eos_progression_snapshot_delete_snapshot}.
 *
 * @param {String} local_user_id The Product User ID of the local user the snapshot belongs to.
 *
 * @returns {Real}
 *
 * [[Note: Returns `-1` if the snapshot could not be created (invalid `local_user_id`, or the interface is unavailable).]]
 *
 * @example
 * ```gml
 * var _snapshot_id = eos_progression_snapshot_begin_snapshot(local_user_id);
 * eos_progression_snapshot_add_progression(_snapshot_id, "PlayerLevel", "12");
 * ```
 * The above code begins a snapshot and adds one progression key/value pair to it.
 * @function_end
 */

/**
 * @function eos_progression_snapshot_add_progression
 * @desc **Epic Online Services Function:** [EOS_ProgressionSnapshot_AddProgression](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/ProgressionSnapshot/EOS_ProgressionSnapshot_AddProgression/index.html)
 *
 * This function stores a key/value pair in memory for a given snapshot. If called multiple times with the same key, the last call wins. Typically you call this several times, then finish with a single call to ${function.eos_progression_snapshot_submit_snapshot}.
 *
 * @param {Real} snapshot_id The snapshot ID received from ${function.eos_progression_snapshot_begin_snapshot}.
 * @param {String} key The key of the progression entry.
 * @param {String} value The value of the progression entry.
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * var _snapshot_id = eos_progression_snapshot_begin_snapshot(local_user_id);
 * eos_progression_snapshot_add_progression(_snapshot_id, "PlayerLevel", "12");
 * eos_progression_snapshot_add_progression(_snapshot_id, "PlayerClass", "Warrior");
 * ```
 * The above code adds two progression key/value pairs to a snapshot.
 * @function_end
 */

/**
 * @function eos_progression_snapshot_end_snapshot
 * @desc **Epic Online Services Function:** [EOS_ProgressionSnapshot_EndSnapshot](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/ProgressionSnapshot/EOS_ProgressionSnapshot_EndSnapshot/index.html)
 *
 * This function cleans up and releases resources associated with a progression snapshot ID.
 *
 * [[Note: Call this after ${function.eos_progression_snapshot_submit_snapshot} has completed.]]
 *
 * @param {Real} snapshot_id The snapshot ID received from ${function.eos_progression_snapshot_begin_snapshot}.
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * eos_progression_snapshot_end_snapshot(snapshot_id);
 * ```
 * The above code releases the resources held by `snapshot_id`.
 * @function_end
 */

/**
 * @function eos_progression_snapshot_submit_snapshot
 * @desc **Epic Online Services Function:** [EOS_ProgressionSnapshot_SubmitSnapshot](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/ProgressionSnapshot/EOS_ProgressionSnapshot_SubmitSnapshot/index.html)
 *
 * This function saves the previously added key/value pairs for a snapshot to the backend service.
 *
 * [[Note: This overwrites any prior progression data already stored for the user.]]
 *
 * @param {Real} snapshot_id The snapshot ID received from ${function.eos_progression_snapshot_begin_snapshot}.
 * @param {Function} [callback] Called once the submission completes.
 *
 * @event callback
 * @desc Called with a single result struct once the submission completes.
 * @member {Struct.EpicProgressionSnapshotSubmitSnapshotCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_progression_snapshot_submit_snapshot(snapshot_id, function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         eos_progression_snapshot_end_snapshot(snapshot_id);
 *     }
 * });
 * ```
 * The above code submits the snapshot and, on success, releases it.
 * @function_end
 */

/**
 * @function eos_progression_snapshot_delete_snapshot
 * @desc **Epic Online Services Function:** [EOS_ProgressionSnapshot_DeleteSnapshot](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/ProgressionSnapshot/EOS_ProgressionSnapshot_DeleteSnapshot/index.html)
 *
 * This function wipes all previously submitted progression data for a user from the backend service. Any progression data added locally but not yet submitted is unaffected.
 *
 * @param {String} local_user_id The Product User ID of the local user whose submitted progression data should be deleted.
 * @param {Function} [callback] Called once the deletion completes.
 *
 * @event callback
 * @desc Called with a single result struct once the deletion completes.
 * @member {Struct.EpicProgressionSnapshotDeleteSnapshotCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_progression_snapshot_delete_snapshot(local_user_id, function(_result)
 * {
 *     show_debug_message("Delete result: " + string(_result.result_code));
 * });
 * ```
 * The above code deletes all submitted progression data for the local user.
 * @function_end
 */

// Structs

/**
 * @struct EpicProgressionSnapshotSubmitSnapshotCallbackInfo
 * @desc Result passed to the callback of ${function.eos_progression_snapshot_submit_snapshot}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` on success; any other value is an error.
 * @struct_end
 */

/**
 * @struct EpicProgressionSnapshotDeleteSnapshotCallbackInfo
 * @desc Result passed to the callback of ${function.eos_progression_snapshot_delete_snapshot}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` on success; any other value is an error.
 * @struct_end
 */

/**
 * @module progression_snapshot
 * @title Progression Snapshot
 * @desc **Epic Online Services:** [Progression Snapshot Interface](https://dev.epicgames.com/docs/epic-account-services/progression-snapshot)
 *
 * The [Progression Snapshot Interface](https://dev.epicgames.com/docs/epic-account-services/progression-snapshot) stores player-specific progress data to support Epic account merging. When a user with two separate Epic accounts merges them, the Epic overlay can present a snapshot of their game progress on each account, letting them choose which progression to keep.
 *
 * @section_func
 * @desc These functions are provided for handling progression snapshots:
 *
 * @ref eos_progression_snapshot_begin_snapshot
 * @ref eos_progression_snapshot_add_progression
 * @ref eos_progression_snapshot_end_snapshot
 * @ref eos_progression_snapshot_submit_snapshot
 * @ref eos_progression_snapshot_delete_snapshot
 *
 * @section_end
 *
 * @section_struct
 * @desc These are the structs used by this module:
 *
 * @ref EpicProgressionSnapshotSubmitSnapshotCallbackInfo
 * @ref EpicProgressionSnapshotDeleteSnapshotCallbackInfo
 *
 * @section_end
 *
 * @module_end
 */
