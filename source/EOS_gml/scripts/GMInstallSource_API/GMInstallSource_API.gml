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
    static __dispatcher = __GMInstallSource_get_dispatcher();

    var __args_buffer = __ext_core_get_args_buffer();

    // param: _callback, type: Function
    if (!is_callable(_callback)) show_error($"{_GMFUNCTION_} :: _callback expected callable type", true);
    var _callback_handle = __ext_core_function_register(_callback, __dispatcher);
    buffer_write(__args_buffer, buffer_u64, _callback_handle);

    var _return_value = __install_source_request(buffer_get_address(__args_buffer), buffer_tell(__args_buffer));

    return _return_value;
}

/**
 * @returns {Enum.InstallSource} 
 */
function install_source_get_cached()
{
    var __ret_buffer = __ext_core_get_ret_buffer();

    var _return_value = __install_source_get_cached(buffer_get_address(__ret_buffer), buffer_get_size(__ret_buffer));

    var _result = undefined;
    _result = buffer_read(__ret_buffer, buffer_u32);
    return _result;
}

// Skipping function install_source_get_cached_name (no wrapper is required)


// Skipping function install_source_get_cached_raw (no wrapper is required)


/// @ignore
function __GMInstallSource_get_decoders()
{
    static __decoders = [];
    return __decoders;
}
/// @ignore
function __GMInstallSource_get_dispatcher()
{
    static __dispatcher = new __GMNativeFunctionDispatcher(__GMInstallSource_invocation_handler, __GMInstallSource_get_decoders());
    return __dispatcher;
}
