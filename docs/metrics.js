// Functions


/**
 * @function EpicGames_Metrics_BeginPlayerSession
 * @desc **Epic Online Services Function:** [EOS_Metrics_BeginPlayerSession](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Metrics/EOS_Metrics_BeginPlayerSession/index.html)
 * 
 * This function logs the start of a new game session for a local player. The game client should call this function whenever it joins into a new multiplayer, peer-to-peer or single player game session. Each call to ${function.EpicGames_Metrics_BeginPlayerSession} must be matched with a corresponding call to ${function.EpicGames_Metrics_EndPlayerSession}.
 * 
 * @param {string} accountID An Epic Account ID. Set this field when `AccountIdType` is set to `EpicGames_MAIT_Epic`.
 * @param {string} DisplayName The in-game display name for the user.
 * @param {constant.EpicGames_AccountId_Type} AccountIdType Account ID type that is set in the union.
 * @param {constant.EpicGames_User_Controller_Type} ControllerType The user's game controller type.
 * @param {string} ServerIp IP address of the game server hosting the game session. For a localhost session, set to `undefined`. If both IPv4 and IPv6 addresses are available, use the **IPv6** address.
 * @param {string} GameSessionId Optional, application-defined custom match session identifier. If the identifier is not used, set to `undefined` which will be shown in the Played Sessions listing at the user profile dashboard.
 * 
 * @returns {struct.EpicResult}
 * 
 * @example
 * ```gml
 * var _struct = EpicGames_Metrics_BeginPlayerSession(
 *         AccountID,
 *         "YYEpicGames",
 *         EpicGames_MAIT_Epic,
 *         EpicGames_UCT_MouseKeyboard,
 *         "No Server",
 *         "AnyRandomIDString");
 * 
 * if(struct.status != EpicGames_Success)
 * {
 *     show_debug_message("EpicGames_Metrics_BeginPlayerSession Failed");
 * }
 * ```
 * The above code shows an example of how the function should be used.
 * @function_end
 */

/**
 * @function EpicGames_Metrics_EndPlayerSession
 * @desc **Epic Online Services Function:** [EOS_Metrics_EndPlayerSession](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/Metrics/EOS_Metrics_EndPlayerSession/index.html)
 * 
 * This function logs the end of a game session for a local player. Call once when the game client leaves the active game session. Each call to ${function.EpicGames_Metrics_BeginPlayerSession} must be matched with a corresponding call to ${function.EpicGames_Metrics_EndPlayerSession}.
 * 
 * @param {string} accountID Set this field when `AccountIdType` is set to `EpicGames_MAIT_Epic`
 * @param {constant.EpicGames_AccountId_Type} AccountIdType The Account ID type that is set in the union
 * 
 * @returns {struct.EpicResult}
 * 
 * @example
 * ```gml
 * var _struct = EpicGames_Metrics_EndPlayerSession(AccountID, EpicGames_MAIT_Epic);
 * show_debug_message("EpicGames_Metrics_EndPlayerSession: " + string(_struct.status_message));
 * ```
 * The above code shows an example of how the function should be used.
 * @function_end
 */

// Constants

/**
 * @constant EpicGames_Metrics_Account_Id_Type
 * @desc **Epic Online Services Enum:** [EOS_EMetricsAccountIdType](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-metrics-account-id-type)
 * 
 * These constants are used to describe the AccountId type.
 * 
 * @member EpicGames_MAIT_Epic An Epic Account ID
 * @member EpicGames_MAIT_External An external service Account ID
 * @constant_end
 */

/**
 * @constant EpicGames_User_Controller_Type
 * @desc **Epic Online Services Enum:** [EOS_EUserControllerType](https://dev.epicgames.com/docs/en-US/api-ref/enums/eos-e-user-controller-type)
 * 
 * These constants are used to describe the type of controller being used during the current player session.
 * 
 * @member EpicGames_UCT_Unknown The game controller type is unknown
 * @member EpicGames_UCT_MouseKeyboard Mouse and keyboard controller
 * @member EpicGames_UCT_GamepadControl Gamepad controller
 * @member EpicGames_UCT_UCT_TouchControl Touch controller
 * @constant_end
 */

/**
 * @module Metrics
 * @desc **Epic Online Services Interface:** [Metrics Interface](https://dev.epicgames.com/docs/game-services/eos-metrics-interface)
 * 
 * The [Metrics Interface](https://dev.epicgames.com/docs/game-services/eos-metrics-interface) tracks your game's usage and populates the **Game Analytics dashboard** in the **Developer Portal**. This data includes active, online instances of the game's client and server, and past sessions played by local players.
 * 
 * @section_func
 * @desc These functions are provided for handling metrics:
 * 
 * @ref EpicGames_Metrics_BeginPlayerSession
 * @ref EpicGames_Metrics_EndPlayerSession
 * @section_end
 * 
 * @section_const
 * @desc These are the constants used by this API:
 * 
 * @ref EpicGames_Metrics_Account_Id_Type
 * @ref EpicGames_User_Controller_Type
 * @section_end

 * @module_end
 */
