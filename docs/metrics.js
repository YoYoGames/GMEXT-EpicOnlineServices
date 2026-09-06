// Functions


/**
 * @function eos_metrics_begin_player_session
 * @desc **Epic Online Services Function:** [EOS_Metrics_BeginPlayerSession](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Metrics/EOS_Metrics_BeginPlayerSession/index.html)
 *
 * This function logs the start of a new game session for a local player. Call it whenever the game client joins a new multiplayer, peer-to-peer, or single-player session. Each call must be matched with a corresponding call to ${function.eos_metrics_end_player_session}.
 *
 * @param {String} account_id An Epic Account ID or an external service account ID, depending on `account_id_type`.
 * @param {Constant.EpicMetricsAccountIdType} account_id_type Whether `account_id` is an Epic Account ID or an external account ID.
 * @param {String} display_name The in-game display name for the user.
 * @param {Constant.EpicUserControllerType} controller_type The user's game controller type.
 * @param {String} server_ip IP address of the game server hosting the session. Pass an empty string for a local/host session.
 * @param {String} game_session_id Application-defined match/session identifier shown in the Played Sessions listing on the user's profile dashboard. Pass an empty string if unused.
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * var _result = eos_metrics_begin_player_session(
 *     account_id,
 *     EpicMetricsAccountIdType.Epic,
 *     "PlayerOne",
 *     EpicUserControllerType.MouseKeyboard,
 *     "",
 *     "");
 *
 * if (_result != EpicResult.Success)
 * {
 *     show_debug_message("eos_metrics_begin_player_session failed");
 * }
 * ```
 * The above code begins a metrics session for the local Epic account, playing with mouse and keyboard on a local session.
 * @function_end
 */

/**
 * @function eos_metrics_end_player_session
 * @desc **Epic Online Services Function:** [EOS_Metrics_EndPlayerSession](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Metrics/EOS_Metrics_EndPlayerSession/index.html)
 *
 * This function logs the end of a game session for a local player. Call once when the game client leaves the session started by ${function.eos_metrics_begin_player_session}.
 *
 * @param {String} account_id The same account identifier passed to ${function.eos_metrics_begin_player_session} for this session.
 * @param {Constant.EpicMetricsAccountIdType} account_id_type Whether `account_id` is an Epic Account ID or an external account ID. Must match what was passed to ${function.eos_metrics_begin_player_session}.
 * @param {Constant.EpicUserControllerType} controller_type The user's game controller type.
 * @param {String} server_ip IP address of the game server hosting the session.
 * @param {String} game_session_id Application-defined match/session identifier.
 *
 * @returns {Constant.EpicResult}
 *
 * [[Note: The SDK's End Player Session call only requires the account and its type; `controller_type`/`server_ip`/`game_session_id` are accepted by this function for symmetry with ${function.eos_metrics_begin_player_session} but are not sent as part of the end-session request.]]
 *
 * @example
 * ```gml
 * var _result = eos_metrics_end_player_session(
 *     account_id,
 *     EpicMetricsAccountIdType.Epic,
 *     EpicUserControllerType.MouseKeyboard,
 *     "",
 *     "");
 *
 * show_debug_message("eos_metrics_end_player_session: " + string(_result));
 * ```
 * The above code ends the metrics session started earlier for the local Epic account.
 * @function_end
 */

// Constants

/**
 * @const EpicMetricsAccountIdType
 * @desc **Epic Online Services Enum:** [EOS_EMetricsAccountIdType](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-metrics-account-id-type)
 *
 * Describes which kind of account identifier is being passed to ${function.eos_metrics_begin_player_session}/${function.eos_metrics_end_player_session}.
 *
 * @member Epic An Epic Account ID.
 * @member External An external service account ID.
 * @const_end
 */

/**
 * @const EpicUserControllerType
 * @desc **Epic Online Services Enum:** [EOS_EUserControllerType](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-user-controller-type)
 *
 * Describes the type of controller in use during the player session.
 *
 * @member Unknown The controller type is unknown.
 * @member MouseKeyboard Mouse and keyboard.
 * @member GamepadControl Gamepad.
 * @member TouchControl Touch controls.
 * @const_end
 */

/**
 * @module metrics
 * @title Metrics
 * @desc **Epic Online Services Interface:** [Metrics Interface](https://dev.epicgames.com/docs/game-services/eos-metrics-interface)
 *
 * The [Metrics Interface](https://dev.epicgames.com/docs/game-services/eos-metrics-interface) reports your game's play-session activity to the **Game Analytics** dashboard in the Developer Portal, tracking active client/server instances and past local-player sessions.
 *
 * @section_func
 * @desc These functions are provided for handling metrics:
 *
 * @ref eos_metrics_begin_player_session
 * @ref eos_metrics_end_player_session
 *
 * @section_end
 *
 * @section_const
 * @desc These are the constants used by this module:
 *
 * @ref EpicMetricsAccountIdType
 * @ref EpicUserControllerType
 *
 * @section_end
 *
 * @module_end
 */
