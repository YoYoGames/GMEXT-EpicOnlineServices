// Functions


/**
 * @function EpicGames_Platform_CheckForLauncherAndRestart
 * @desc **Epic Online Services Function:** [EOS_Platform_CheckForLauncherAndRestart](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/NoInterface/EOS_Platform_CheckForLauncherAndRestart/index.html)
 * 
 * This function checks if the app was launched through the Epic Launcher, and relaunches it through the Epic Launcher if it wasn't.
 * The function returns one of 3 possible results:
 * 
 * 1. `EpicGames_Success` is returned if the app is being restarted. You should quit your process as soon as possible. 
 * 2. `EpicGames_NoChange` is returned if the app was already launched through the Epic Launcher, and no action needs to be taken.
 * 3. `EpicGames_UnexpectedError` is returned if the **LauncherCheck** module failed to initialise, or the module tried and failed to restart the app.
 * 
 * @returns {real}
 * 
 * @example
 * ```gml
 * if (EpicGames_Platform_CheckForLauncherAndRestart() != EpicGames_NoChange) { game_end(); }
 * ```
 * The above code shows an example of how the function should be used. If the output of the function is other than `EpicGames_NoChange` it will force close the project.
 * @function_end
 */

/**
 * @function EpicGames_Platform_GetActiveCountryCode
 * @desc **Epic Online Services Function:** [EOS_Platform_GetActiveCountryCode](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/NoInterface/EOS_Platform_GetActiveCountryCode/index.html)
 * 
 * This function returns the active country code. This will only return the value set as the override otherwise empty string is returned.
 * 
 * [[Note: This is NOT currently used for anything internally.]]
 * 
 * @param {string} accountID The account to get the active country code of
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * show_debug_message("CountryCode: " + EpicGames_Platform_GetActiveCountryCode(accountID));
 * ```
 * The above code shows an example of how the function should be used.
 * @function_end
 */

/**
 * @function EpicGames_Platform_GetActiveLocaleCode
 * @desc **Epic Online Services Function:** [EOS_Platform_GetActiveLocaleCode](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/NoInterface/EOS_Platform_GetActiveLocaleCode/index.html)
 * 
 * This function gets the active locale code that the SDK will send to services which require it. This returns the override value otherwise it will use the locale code of the given user. This is used for localization. This follows ISO 639.
 * 
 * @param {string} accountID The account to get the local code of
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * show_debug_message("LocaleCode: " + EpicGames_Platform_GetActiveLocaleCode(accountID));
 * ```
 * The above code shows an example of how the function should be used.
 * @function_end
 */

/**
 * @function EpicGames_Platform_GetOverrideCountryCode
 * @desc **Epic Online Services Function:** [EOS_Platform_GetOverrideCountryCode](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/NoInterface/EOS_Platform_GetOverrideCountryCode/index.html)
 * 
 * This function gets the override country code that the SDK will send to services which require it. This is not currently used for anything internally.
 * 
 * [[Note: This is NOT currently used for anything internally.]]
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * show_debug_message("CountryCode: " + EpicGames_Platform_GetOverrideCountryCode());
 * ```
 * The above code shows an example of how the function should be used.
 * @function_end
 */

/**
 * @function EpicGames_Platform_GetOverrideLocaleCode
 * @desc **Epic Online Services Function:** [EOS_Platform_GetOverrideLocaleCode](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/NoInterface/EOS_Platform_GetOverrideLocaleCode/index.html)
 * 
 * This function gets the override locale code that the SDK will send to services which require it. This is used for localization. This follows ISO 639.
 * 
 * @returns {string}
 * 
 * @example
 * ```gml
 * show_debug_message("LocaleCode: " + EpicGames_Platform_GetOverrideCountryCode());
 * ```
 * The above code shows an example of how the function should be used.
 * @function_end
 */

/**
 * @function EpicGames_Platform_Release
 * @desc **Epic Online Services Function:** [EOS_Platform_Release](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/NoInterface/EOS_Platform_Release/index.html)
 * 
 * This function releases an Epic Online Services platform. This function should only be called when terminating your application right before calling ${function.EpicGames_Shutdown}.
 * Undefined behaviour will result in calling it more than once.
 * 
 * @example
 * ```gml
 * EpicGames_Platform_Release();
 * EpicGames_Shutdown();
 * 
 * game_end();
 * ```
 * The above code shows an example of how the function should be used.
 * @function_end
 */

/**
 * @function EpicGames_Platform_SetOverrideCountryCode
 * @desc **Epic Online Services Function:** [EOS_Platform_SetOverrideCountryCode](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/NoInterface/EOS_Platform_SetOverrideCountryCode/index.html)
 * 
 * This function sets the override country code that the SDK will send to services which require it. This is not currently used for anything internally.
 * 
 * @param {string} countryCode New country code ISO 639
 * 
 * @example
 * ```gml
 * EpicGames_Platform_SetOverrideCountryCode("UK");
 * ```
 * The above code shows an example of how the function should be used.
 * @function_end
 */

/**
 * @function EpicGames_Platform_SetOverrideLocaleCode
 * @desc **Epic Online Services Function:** [EOS_Platform_SetOverrideLocaleCode](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/NoInterface/EOS_Platform_SetOverrideLocaleCode/index.html)
 * 
 * This function sets the override locale code that the SDK will send to services which require it. This is used for localization. This follows ISO 639.
 * 
 * @param {string} localCode New local code
 * 
 * @example
 * ```gml
 * EpicGames_Platform_SetOverrideLocaleCode("en");
 * ```
 * The above code shows an example of how the function should be used.
 * @function_end
 */

/**
 * @function EpicGames_Platform_Tick
 * @desc **Epic Online Services Function:** [EOS_Platform_Tick](https://dev.epicgames.com/docs/services/en-US/API/Members/Functions/NoInterface/EOS_Platform_Tick/index.html)
 * 
 * This function notifies the platform instance to do work. This function must be called frequently in order for the services provided by the SDK to work properly.
 * 
 * [[Note: For tick-based applications, it is usually desirable to call this once per-tick.]]
 * 
 * @example
 * ```gml
 * /// Step Event
 * EpicGames_Platform_Tick();
 * ```
 * The above code shows a code example.
 * @function_end
 */


/**
 * @module Platform
 * @desc **Epic Online Services Interface:** [Platform Interface](https://dev.epicgames.com/docs/game-services/eos-platform-interface)
 * 
 * The [Platform Interface](https://dev.epicgames.com/docs/game-services/eos-platform-interface) sits at the heart of the **Epic Online Services** (EOS) SDK and holds the handles you need to access every other interface and keep them all running. When your application starts up, you can initialise the SDK and get a handle to the Platform Interface. This handle is usable for the lifetime of the SDK.
 * 
 * @section_func
 * @desc These functions are provided for handling platform functionality:
 * 
 * @ref EpicGames_Platform_CheckForLauncherAndRestart
 * @ref EpicGames_Platform_GetActiveCountryCode
 * @ref EpicGames_Platform_GetActiveLocaleCode
 * @ref EpicGames_Platform_GetOverrideCountryCode
 * @ref EpicGames_Platform_GetOverrideLocaleCode
 * @ref EpicGames_Platform_Release
 * @ref EpicGames_Platform_SetOverrideCountryCode
 * @ref EpicGames_Platform_SetOverrideLocaleCode
 * @ref EpicGames_Platform_Tick
 * 
 * @section_end
 */
