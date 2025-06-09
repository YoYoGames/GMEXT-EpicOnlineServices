// Functions


/**
 * @function eos_metrics_begin_player_session
 * @desc **Epic Online Services Function:** [EOS_Metrics_BeginPlayerSession](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Metrics/EOS_Metrics_BeginPlayerSession/index.html)
 * 
 * This function logs the start of a new game session for a local player. The game client should call this function whenever it joins into a new multiplayer, peer-to-peer or single player game session. Each call to ${function.eos_metrics_begin_player_session} must be matched with a corresponding call to ${function.eos_metrics_end_player_session}.
 * 
 * @param {string} account_id An Epic Account ID. Set this field when `account_id_type` is set to `EOS_METRICS_ACCOUNT_ID_TYPE.EPIC`.
 * @param {string} display_name The in-game display name for the user.
 * @param {constant.EOS_METRICS_ACCOUNT_ID_TYPE} account_id_type Account ID type that is set in the union.
 * @param {constant.EOS_USER_CONTROLLER_TYPE} controller_type The user's game controller type.
 * @param {string} server_ip IP address of the game server hosting the game session. For a localhost session, set to `undefined`. If both IPv4 and IPv6 addresses are available, use the **IPv6** address.
 * @param {string} [game_session_id] Optional, application-defined custom match session identifier. If the identifier is not used, set to `undefined` which will be shown in the Played Sessions listing at the user profile dashboard.
 * 
 * @returns {struct.EpicResult}
 * 
 * @example
 * ```gml
 * var _struct = eos_metrics_begin_player_session(
 *         account_id,
 *         "YYEpicGames",
 *         EOS_METRICS_ACCOUNT_ID_TYPE.EPIC,
 *         EOS_USER_CONTROLLER_TYPE.MOUSE_KEYBOARD,
 *         "No Server",
 *         "AnyRandomIDString");
 * 
 * if(_struct.status != EOS_RESULT.SUCCESS)
 * {
 *     show_debug_message("eos_metrics_begin_player_session failed");
 * }
 * ```
 * The above code shows an example of how the function should be used.
 * @function_end
 */

/**
 * @function eos_metrics_end_player_session
 * @desc **Epic Online Services Function:** [EOS_Metrics_EndPlayerSession](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Metrics/EOS_Metrics_EndPlayerSession/index.html)
 * 
 * This function logs the end of a game session for a local player. Call once when the game client leaves the active game session. Each call to ${function.eos_metrics_begin_player_session} must be matched with a corresponding call to ${function.eos_metrics_end_player_session}.
 * 
 * @param {string} account_id Set this field when `account_id_type` is set to `EOS_METRICS_ACCOUNT_ID_TYPE.EPIC`
 * @param {constant.EOS_METRICS_ACCOUNT_ID_TYPE} account_id_type The Account ID type that is set in the union
 * 
 * @returns {struct.EpicResult}
 * 
 * @example
 * ```gml
 * var _struct = eos_metrics_end_player_session(account_id, EOS_METRICS_ACCOUNT_ID_TYPE.EPIC);
 * show_debug_message("eos_metrics_end_player_session: " + string(_struct.status_message));
 * ```
 * The above code shows an example of how the function should be used.
 * @function_end
 */

// Constants

/**
 * @constant EOS_METRICS_ACCOUNT_ID_TYPE
 * @desc **Epic Online Services Enum:** [EOS_EMetricsAccountIdType](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-metrics-account-id-type)
 * 
 * These constants are used to describe the account ID type.
 * 
 * @member EPIC An Epic Account ID
 * @member EXTERNAL An external service Account ID
 * @constant_end
 */

/**
 * @constant EOS_USER_CONTROLLER_TYPE
 * @desc **Epic Online Services Enum:** [EOS_EUserControllerType](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-user-controller-type)
 * 
 * These constants are used to describe the type of controller being used during the current player session.
 * 
 * @member UNKNOWN The game controller type is unknown
 * @member MOUSE_KEYBOARD Mouse and keyboard controller
 * @member GAMEPAD_CONTROL Gamepad controller
 * @member TOUCH_CONTROL Touch controller
 * @constant_end
 */

/**
 * @module metrics
 * @title Metrics
 * @desc **Epic Online Services Interface:** [Metrics Interface](https://dev.epicgames.com/docs/game-services/eos-metrics-interface)
 * 
 * The [Metrics Interface](https://dev.epicgames.com/docs/game-services/eos-metrics-interface) tracks your game's usage and populates the **Game Analytics dashboard** in the **Developer Portal**. This data includes active, online instances of the game's client and server, and past sessions played by local players.
 * 
 * @section_func
 * @desc These functions are provided for handling metrics:
 * 
 * @ref eos_metrics_begin_player_session
 * @ref eos_metrics_end_player_session
 * @section_end
 * 
 * @section_const
 * @desc These are the constants used by this API:
 * 
 * @ref EOS_METRICS_ACCOUNT_ID_TYPE
 * @ref EOS_USER_CONTROLLER_TYPE
 * @section_end

 * @module_end
 */
