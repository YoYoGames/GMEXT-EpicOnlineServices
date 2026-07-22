// Functions


/**
 * @function eos_reports_send_player_behavior_report
 * @desc **Epic Online Services Function:** [EOS_Reports_SendPlayerBehaviorReport](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Reports/EOS_Reports_SendPlayerBehaviorReport/index.html)
 *
 * This function sends a player behavior report about another player to the backend service for review.
 *
 * @param {String} reporter_user_id The Product User ID of the local user submitting the report.
 * @param {String} reported_user_id The Product User ID of the user being reported.
 * @param {Constant.EpicPlayerReportsCategory} category The category that best describes the reported behavior.
 * @param {String} message A human-readable description of what happened, to include with the report.
 * @param {String} context Additional application-defined context for the report (e.g. a JSON blob of the match/session state).
 * @param {Function} [callback] Called once the report has been submitted.
 *
 * @event callback
 * @desc Called with a single result struct once the report has been submitted.
 * @member {Struct.EpicReportsSendPlayerBehaviorReportCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_reports_send_player_behavior_report(
 *     local_user_id,
 *     reported_user_id,
 *     EpicPlayerReportsCategory.Cheating,
 *     "Was using an aimbot in the last match.",
 *     "",
 *     function(_result)
 *     {
 *         if (_result.result_code == EpicResult.Success)
 *         {
 *             show_debug_message("Report submitted");
 *         }
 *     });
 * ```
 * The above code reports `reported_user_id` for cheating.
 * @function_end
 */

// Structs

/**
 * @struct EpicReportsSendPlayerBehaviorReportCallbackInfo
 * @desc Result passed to the callback of ${function.eos_reports_send_player_behavior_report}.
 *
 * @member {Constant.EpicResult} result_code `EpicResult.Success` on success; any other value is an error.
 * @struct_end
 */

// Constants

/**
 * @const EpicPlayerReportsCategory
 * @desc **Epic Online Services Enum:** [EOS_EPlayerReportsCategory](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-player-reports-category)
 *
 * The category of behavior being reported via ${function.eos_reports_send_player_behavior_report}.
 *
 * @member Invalid Invalid category, do not use.
 * @member Cheating The reported user was cheating.
 * @member Exploiting The reported user was exploiting a bug for unfair advantage.
 * @member OffensiveProfile The reported user's profile (name/avatar/bio) is offensive.
 * @member VerbalAbuse The reported user engaged in verbal abuse.
 * @member Scamming The reported user attempted to scam another player.
 * @member Spamming The reported user was spamming.
 * @member Other Any other reason not covered above.
 * @const_end
 */

/**
 * @module reports
 * @title Reports
 * @desc **Epic Online Services Interface:** [Reports Interface](https://dev.epicgames.com/docs/game-services/reports-interface)
 *
 * The [Reports Interface](https://dev.epicgames.com/docs/game-services/reports-interface) lets players report other players' bad behavior directly from your game, forwarding the report to Epic for review.
 *
 * @section_func
 * @desc These functions are provided for handling player behavior reports:
 *
 * @ref eos_reports_send_player_behavior_report
 *
 * @section_end
 *
 * @section_struct
 * @desc These are the structs used by this module:
 *
 * @ref EpicReportsSendPlayerBehaviorReportCallbackInfo
 *
 * @section_end
 *
 * @section_const
 * @desc These are the constants used by this module:
 *
 * @ref EpicPlayerReportsCategory
 *
 * @section_end
 *
 * @module_end
 */
