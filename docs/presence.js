/**
 * @module presence
 * @title Presence
 * @desc **Epic Online Services Interface:** [Presence Interface](https://dev.epicgames.com/docs/epic-account-services/eos-presence-interface)
 * 
 * With the Presence Interface, an application can advertise its local player's status, known as presence, and query the presence of other players online. An application may also advertise transient data to others, in order to share more detailed information about the state of the local player. Users can only receive presence information about other users with whom they are friends.
 * 
 * [[Important: To use the Presence Interface, your product must have **Epic Account Services** (EAS) active, and must obtain [user consent](https://dev.epicgames.com/docs/en-US/epic-account-services/eos-data-privacy-visibility) to access **Online Presence** data. You can activate EAS on the [Developer Portal](https://dev.epicgames.com/docs/en-US/dev-portal), or learn more in [Epic's documentation](https://dev.epicgames.com/docs/en-US/epic-account-services). Without EAS and user consent, you will still be able to initialize the EOS SDK and the Presence Interface, but all Presence Interface function calls to the back-end service will fail.]]
 * 
 * @section_func
 * @desc These are the functions in the Presence module:
 * 
 * @ref eos_presence_modification_set_join_info
 * 
 * @section_end
 * 
 * @module_end
 */

/**
 * @func eos_presence_modification_set_join_info
 * @desc **Epic Online Services Function:** [EOS_PresenceModification_SetJoinInfo](https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-presence-modification-set-join-info)
 * 
 * This function sets your new join info custom game-data string. This is a helper function for reading the presence data related to how a user can be joined. Its meaning is entirely application dependent.
 * 
 * The function returns `EOS_RESULT.SUCCESS` if the modification was added successfully, otherwise an error code related to the problem.
 * 
 * @param {string} join_info The string which will be advertised as this player's join info. An application is expected to freely define the meaning of this string to use for connecting to an active game session. The string should not exceed EOS_PRESENCEMODIFICATION_JOININFO_MAX_LENGTH in length. This affects the ability of the Social Overlay to show game related actions to take in the player's social graph. * using the `presence_enabled` flags within the ${module.sessions} interface * using the `presence_enabled` flags within the ${module.lobbies} interface * using ${function.eos_presence_modification_set_join_info}
 * 
 * @returns {constant.EOS_RESULT}
 * 
 * @func_end
 */
