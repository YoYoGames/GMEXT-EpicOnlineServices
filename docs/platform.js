// Functions


/**
 * @function eos_platform_is_created
 * @desc **Epic Online Services Function:** [EOS_Platform_Create](https://dev.epicgames.com/docs/api-ref/functions/eos-platform-create)
 *
 * Returns whether ${function.eos_platform_create} has already succeeded.
 *
 * @returns {Bool}
 *
 * @function_end
 */

/**
 * @function eos_platform_create
 * @desc **Epic Online Services Function:** [EOS_Platform_Create](https://dev.epicgames.com/docs/api-ref/functions/eos-platform-create)
 *
 * Creates the Epic Online Services platform handle. Every other module in this extension needs this to
 * have succeeded first — call it once, right after ${function.eos_api_initialize}.
 *
 * The **Product ID**, **Sandbox ID**, **Deployment ID**, **Client Credentials ID**, and **Client
 * Credentials Secret** extension options are all required and read directly from the extension's own
 * options (not passed as parameters) — see ${page.extension_options}.
 *
 * [[Note: On Android/iOS the extension resolves a writable per-app cache directory itself and ignores
 * `cache_directory` — call ${function.eos_platform_get_storage_directory} afterwards if you need to know
 * which directory ended up being used, on any platform.]]
 *
 * @param {String} cache_directory Absolute, writable directory the SDK can use for its own cache files.
 * `working_directory` is a common choice on desktop.
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * if (eos_api_initialize("MyGame", "1.0.0") == EpicResult.Success)
 * {
 *     eos_platform_create(working_directory);
 * }
 * ```
 * @function_end
 */

/**
 * @function eos_platform_release
 * @desc **Epic Online Services Function:** [EOS_Platform_Release](https://dev.epicgames.com/docs/api-ref/functions/eos-platform-release)
 *
 * Releases the platform handle created by ${function.eos_platform_create}. Called automatically by
 * ${function.eos_api_shutdown} if you haven't called it yourself, so most games don't need to call this
 * directly.
 *
 * [[Warning: Undefined behaviour results from calling this more than once, or from calling any other
 * module's functions afterwards.]]
 *
 * @function_end
 */

/**
 * @function eos_platform_tick
 * @desc **Epic Online Services Function:** [EOS_Platform_Tick](https://dev.epicgames.com/docs/api-ref/functions/eos-platform-tick)
 *
 * Gives the platform time to do its work — network I/O, and firing every pending completion callback and
 * notification across every module in this extension. Nothing else in this extension will report
 * progress or fire a callback unless this is called regularly.
 *
 * [[Note: Call this once per step, for example in the Step event of a persistent controller object.]]
 *
 * @example
 * ```gml
 * /// Step Event
 * eos_platform_tick();
 * ```
 * @function_end
 */

/**
 * @function eos_platform_check_for_launcher_and_restart
 * @desc **Epic Online Services Function:** [EOS_Platform_CheckForLauncherAndRestart](https://dev.epicgames.com/docs/api-ref/functions/eos-platform-check-for-launcher-and-restart)
 *
 * Checks whether the game was launched through the Epic Games Launcher, and if it wasn't, relaunches it
 * through the launcher instead.
 *
 * 1. `EpicResult.Success` — the app is being relaunched through the launcher. Quit your process as soon
 * as possible afterwards.
 * 2. `EpicResult.NoChange` — the app was already launched through the launcher; no action needed.
 * 3. `EpicResult.UnexpectedError` — the launcher-check module failed to initialize, or failed to restart
 * the app.
 *
 * [[Note: This is skipped while the **Debug Mode** extension option forces debug mode on — see
 * ${page.extension_options}.]]
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * if (eos_platform_check_for_launcher_and_restart() == EpicResult.Success)
 * {
 *     game_end();
 * }
 * ```
 * @function_end
 */

/**
 * @function eos_platform_set_network_status
 * @desc **Epic Online Services Function:** [EOS_Platform_SetNetworkStatus](https://dev.epicgames.com/docs/api-ref/functions/eos-platform-set-network-status)
 *
 * Tells the SDK about a change in the device's network connectivity, so it can adjust its own online
 * behaviour accordingly.
 *
 * @param {Constant.EpicNetworkStatus} status The device's current network status.
 *
 * @returns {Constant.EpicResult}
 *
 * @function_end
 */

/**
 * @function eos_platform_get_storage_directory
 * @desc Returns the absolute, writable directory (with a trailing separator) that
 * ${function.eos_platform_create} ended up using — the `cache_directory` you passed in on desktop, or the
 * extension's own resolved per-app cache directory on Android/iOS. Use this instead of tracking the
 * directory yourself if you need to build a path for `file_exists`/`sprite_add`/etc. against SDK-written
 * files (e.g. from ${module.player_data_storage}).
 *
 * @returns {String} Empty string if the platform hasn't been created yet.
 *
 * @function_end
 */


/**
 * @module platform
 * @title Platform
 * @desc **Epic Online Services Interface:** [Platform Interface](https://dev.epicgames.com/docs/game-services/eos-platform-interface)
 *
 * The [Platform Interface](https://dev.epicgames.com/docs/game-services/eos-platform-interface) sits at
 * the heart of the Epic Online Services SDK — creating it is what every other module needs before it can
 * do anything, and ${function.eos_platform_tick} is what actually drives the SDK's network I/O and fires
 * every callback/notification this extension exposes.
 *
 * @section_func
 * @desc These functions are provided for handling platform functionality:
 *
 * @ref eos_platform_is_created
 * @ref eos_platform_create
 * @ref eos_platform_release
 * @ref eos_platform_tick
 * @ref eos_platform_check_for_launcher_and_restart
 * @ref eos_platform_set_network_status
 * @ref eos_platform_get_storage_directory
 *
 * @section_end
 *
 * @module_end
 */
