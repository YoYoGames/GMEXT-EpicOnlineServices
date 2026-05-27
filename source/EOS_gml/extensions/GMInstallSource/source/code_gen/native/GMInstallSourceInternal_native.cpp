// ##### extgen :: Auto-generated file do not edit!! #####

#include "GMInstallSourceInternal_native.h"
#include "GMInstallSourceInternal_exports.h"

using namespace gm_structs;
using namespace gm::wire::codec;

static gm::runtime::DispatchQueue __dispatch_queue;

// Internal function used for fetching dispatched function calls to GML
GMEXPORT double __EXT_NATIVE__GMInstallSource_invocation_handler(char* __ret_buffer, double __ret_buffer_length)
{
    gm::byteio::BufferWriter __bw{ __ret_buffer, static_cast<size_t>(__ret_buffer_length) };
    return __dispatch_queue.fetch(__bw);
}

GMEXPORT double __EXT_NATIVE__install_source_request(char* __arg_buffer, double __arg_buffer_length)
{
    gm::byteio::BufferReader __br{__arg_buffer, static_cast<size_t>(__arg_buffer_length)};

    // field: callback, type: Function
    gm::wire::GMFunction callback = gm::wire::codec::readFunction(__br, &__dispatch_queue);

    install_source_request(callback);
    return 0;
}

GMEXPORT double __EXT_NATIVE__install_source_get_cached(char* __ret_buffer, double __ret_buffer_length)
{
    auto&& __result = install_source_get_cached();
    gm::byteio::BufferWriter __bw{__ret_buffer, static_cast<size_t>(__ret_buffer_length)};

    // return: __result, type: enum InstallSource
    gm::wire::codec::writeValue(__bw, __result);
    return 0;
}

GMEXPORT char* __EXT_NATIVE__install_source_get_cached_name()
{
    static std::string __result;
    __result = install_source_get_cached_name();
    return (char*)__result.c_str();
}

GMEXPORT char* __EXT_NATIVE__install_source_get_cached_raw()
{
    static std::string __result;
    __result = install_source_get_cached_raw();
    return (char*)__result.c_str();
}

