// Functions


/**
 * @function eos_logging_set_callback
 * @desc **Epic Online Services Function:** [EOS_Logging_SetCallback](https://dev.epicgames.com/docs/api-ref/functions/eos-logging-set-callback)
 *
 * Registers a callback to receive every log message the SDK produces, across all categories. Call
 * ${function.eos_logging_set_log_level} to control which categories/levels actually reach it.
 *
 * [[Warning: Unlike every other callback in this extension, this one is NOT guaranteed to fire on the
 * main thread during ${function.eos_platform_tick} - the SDK can invoke it from an internal worker
 * thread. Do not touch instances, rooms, or any other main-thread-only GML state directly from this
 * callback; buffer the message (e.g. into a ds_queue) and drain it from a Step event instead.]]
 *
 * @param {Function} callback The function to call for every log message.
 *
 * @event callback
 * @desc Called once per log message.
 * @member {Struct.EpicLoggingMessage} message The log message.
 * @event_end
 *
 * @example
 * ```gml
 * eos_logging_set_callback(function(_message)
 * {
 *     show_debug_message($"[{_message.category}] {_message.message}");
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_logging_clear_callback
 * @desc **Epic Online Services Function:** [EOS_Logging_SetCallback](https://dev.epicgames.com/docs/api-ref/functions/eos-logging-set-callback)
 *
 * Unregisters the callback set by ${function.eos_logging_set_callback}. Safe to call even if no callback
 * is currently registered.
 *
 * @function_end
 */

/**
 * @function eos_logging_set_log_level
 * @desc **Epic Online Services Function:** [EOS_Logging_SetLogLevel](https://dev.epicgames.com/docs/api-ref/functions/eos-logging-set-log-level)
 *
 * Sets the logging level for a specific logging category (or every category at once).
 *
 * [[Note: By default all log categories are set to callback for Warning, Error, and Fatal.]]
 *
 * @param {Constant.EpicLogCategory} log_category The category to configure. Use `EpicLogCategory.AllCategories` to configure every category at once.
 * @param {Constant.EpicLogLevel} log_level The verbosity level to use for that category.
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * eos_logging_set_log_level(EpicLogCategory.AllCategories, EpicLogLevel.Off);
 * ```
 * The above turns off logging for every category.
 * @function_end
 */

// Constants

/**
 * @const EpicLogLevel
 * @desc **Epic Online Services Enum:** [EOS_ELogLevel](https://dev.epicgames.com/docs/api-ref/enums/eos-e-log-level)
 *
 * The verbosity levels usable with ${function.eos_logging_set_log_level}. A log message is only sent to
 * the ${function.eos_logging_set_callback} callback if its own level is less than or equal to the
 * configured level for its category.
 *
 * @member Off No log messages.
 * @member Fatal Fatal errors only.
 * @member Error Errors and above.
 * @member Warning Warnings and above.
 * @member Info Informational messages and above.
 * @member Verbose Verbose messages and above.
 * @member VeryVerbose Every log message.
 * @const_end
 */

/**
 * @const EpicLogCategory
 * @desc **Epic Online Services Enum:** [EOS_ELogCategory](https://dev.epicgames.com/docs/api-ref/enums/eos-e-log-category)
 *
 * The logging categories usable with ${function.eos_logging_set_log_level}.
 *
 * @member Core Low-level logs unrelated to a specific service.
 * @member Auth Logs related to the Auth service.
 * @member Friends Logs related to the Friends service.
 * @member Presence Logs related to the Presence service.
 * @member UserInfo Logs related to the UserInfo service.
 * @member HttpSerialization Logs related to HTTP serialization.
 * @member Ecom Logs related to the Ecommerce service.
 * @member P2P Logs related to the P2P service.
 * @member Sessions Logs related to the Sessions service.
 * @member RateLimiter Logs related to rate limiting.
 * @member PlayerDataStorage Logs related to the PlayerDataStorage service.
 * @member Analytics Logs related to SDK analytics.
 * @member Messaging Logs related to the messaging service.
 * @member Connect Logs related to the Connect service.
 * @member Overlay Logs related to the overlay.
 * @member Achievements Logs related to the Achievements service.
 * @member Stats Logs related to the Stats service.
 * @member UI Logs related to the UI service.
 * @member Lobby Logs related to the Lobby service.
 * @member Leaderboards Logs related to the Leaderboards service.
 * @member Keychain Logs related to an internal Keychain feature the auth interfaces use.
 * @member IntegratedPlatform Logs related to the Integrated Platform service.
 * @member TitleStorage Logs related to the Title Storage service.
 * @member Mods Logs related to the Mods service.
 * @member AntiCheat Logs related to the Anti-Cheat service.
 * @member Reports Logs related to the Reports client.
 * @member Sanctions Logs related to the Sanctions service.
 * @member ProgressionSnapshots Logs related to the Progression Snapshot service.
 * @member KWS Logs related to the Kids Web Services integration.
 * @member RTC Logs related to the RTC API.
 * @member RTCAdmin Logs related to the RTC Admin API.
 * @member CustomInvites Logs related to the Custom Invites API.
 * @member AllCategories Not a real category - configures every category at once when passed to ${function.eos_logging_set_log_level}.
 * @const_end
 */

// Structs

/**
 * @struct EpicLoggingMessage
 * @desc A single log message, passed to the ${function.eos_logging_set_callback} callback.
 *
 * @member {String} category The category this message belongs to (matches a name in ${constant.EpicLogCategory}, as text).
 * @member {Constant.EpicLogLevel} level The severity level of this message.
 * @member {String} message The log message text.
 *
 * @struct_end
 */

/**
 * @module logging
 * @title Logging
 * @desc **Epic Online Services Interface:** [Logging Interface](https://dev.epicgames.com/docs/api-ref/enums/eos-e-log-category)
 *
 * Routes the SDK's own diagnostic log output to a GML callback, and controls how verbose each category
 * is. This is independent of the extension's own **Log Level** build option (see
 * ${page.extension_options}), which only affects the extension's own startup diagnostics.
 *
 * @section_func
 * @desc Provided functions:
 *
 * @ref eos_logging_set_callback
 * @ref eos_logging_clear_callback
 * @ref eos_logging_set_log_level
 *
 * @section_end
 *
 * @section_struct
 * @desc These are the structs used by this API:
 *
 * @ref EpicLoggingMessage
 *
 * @section_end
 *
 * @section_const
 * @desc These are the constants used by this API:
 *
 * @ref EpicLogLevel
 * @ref EpicLogCategory
 *
 * @section_end
 *
 * @module_end
 */
