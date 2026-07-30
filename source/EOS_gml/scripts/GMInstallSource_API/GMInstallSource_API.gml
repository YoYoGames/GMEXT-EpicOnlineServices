// ##### extgen :: Auto-generated file do not edit!! #####

// #####################################################################
// # Macros
// #####################################################################

// #####################################################################
// # Enums
// #####################################################################

enum InstallSource
{
    Unknown = 0,
    GooglePlay = 1,
    EpicAndroid = 2,
    AndroidOther = 3,
    AndroidSideload = 4,
    IOSAppStore = 5,
    IOSTestFlight = 6,
    IOSMarketplace = 7,
    IOSOther = 8,
    Unsupported = 9,
    Error = 10
}

// #####################################################################
// # Constructors
// #####################################################################

// #####################################################################
// # Codecs
// #####################################################################

// #####################################################################
// # Functions
// #####################################################################

/**
 * @param {Function} _callback
 */
function install_source_request(_callback)
{
    var __available__ = __GMInstallSource_is_available();
    if (!__available__) return;

    var __dispatcher__ = __GMInstallSource_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher__);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var __return_value__ = __install_source_request(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return __return_value__;
}

/**
 * @returns {Enum.InstallSource}
 */
function install_source_get_cached()
{
    var __available__ = __GMInstallSource_is_available();
    if (!__available__) return;

    var __ret_buffer = __ext_core_get_ret_buffer();

    var __return_value__ = __install_source_get_cached(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var __result__ = undefined;
    __result__ = buffer_read(__ret_buffer, buffer_u32);
    return __result__;
}

// Skipping function install_source_get_cached_name (no wrapper is required)


// Skipping function install_source_get_cached_raw (no wrapper is required)


/// @ignore
function __GMInstallSource_get_decoders()
{
    static __decoders__ = [];
    return __decoders__;
}
/// @ignore
function __GMInstallSource_get_dispatcher()
{
    static __dispatcher__ = new __GMNativeFunctionDispatcher(__GMInstallSource_invocation_handler, __GMInstallSource_get_decoders());
    return __dispatcher__;
}
/// @ignore
function __GMInstallSource_is_available()
{
    static __available__ = extension_exists("GMInstallSource");
    return __available__;
}
