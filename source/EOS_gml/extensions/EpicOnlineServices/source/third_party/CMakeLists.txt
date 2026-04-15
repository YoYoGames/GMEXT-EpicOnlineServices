cmake_minimum_required(VERSION 3.18)

add_library(ext_third_party INTERFACE)
target_compile_definitions(ext_third_party INTERFACE HAVE_THIRDPARTY_FEATURE=1)

set(_EXT_TP_RUNTIME_DLLS "")
set(_MAP_REL_CONFIGS "Release")

function(_ext_tp_append_runtime)
  foreach(_f IN LISTS ARGN)
    if(_f)
      list(APPEND _EXT_TP_RUNTIME_DLLS "${_f}")
    endif()
  endforeach()
  set(_EXT_TP_RUNTIME_DLLS
      "${_EXT_TP_RUNTIME_DLLS}"
      PARENT_SCOPE)
endfunction()

# =============================================================================
# Epic Online Services SDK
# =============================================================================
set(EOS_SDK_ROOT
    "D:/Github/GMEXT-EpicOnlineServices/source/EOS_sdk"
    CACHE PATH "Path to Epic Online Services SDK root" FORCE)

set(_EOS_INCLUDE_DIR "${EOS_SDK_ROOT}/Include")
set(_EOS_BIN_DIR     "${EOS_SDK_ROOT}/Bin")
set(_EOS_LIB_DIR     "${EOS_SDK_ROOT}/Lib")

message(STATUS "EOS_SDK_ROOT = ${EOS_SDK_ROOT}")
message(STATUS "_EOS_INCLUDE_DIR = ${_EOS_INCLUDE_DIR}")
message(STATUS "_EOS_BIN_DIR = ${_EOS_BIN_DIR}")
message(STATUS "_EOS_LIB_DIR = ${_EOS_LIB_DIR}")

if(NOT EXISTS "${_EOS_INCLUDE_DIR}/eos_sdk.h")
  message(FATAL_ERROR
    "Missing EOS header:\n"
    "  ${_EOS_INCLUDE_DIR}/eos_sdk.h\n"
    "Check EOS_SDK_ROOT:\n"
    "  ${EOS_SDK_ROOT}")
endif()

# Headers (all platforms)
target_include_directories(ext_third_party INTERFACE "${_EOS_INCLUDE_DIR}")

# =============================================================================
# Windows
# =============================================================================
if(WIN32)
  get_filename_component(_TP_DIR "${CMAKE_CURRENT_LIST_DIR}" ABSOLUTE)
  get_filename_component(_SRC_DIR "${_TP_DIR}/.." ABSOLUTE)
  get_filename_component(_EXT_DIR "${_SRC_DIR}/.." ABSOLUTE)

  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(STATUS "Windows: linking EOS win64")
    set(_EOS_DLL "${_EOS_BIN_DIR}/EOSSDK-Win64-Shipping.dll")
    set(_EOS_LIB "${_EOS_LIB_DIR}/EOSSDK-Win64-Shipping.lib")
  else()
    message(STATUS "Windows: linking EOS win32")
    set(_EOS_DLL "${_EOS_BIN_DIR}/EOSSDK-Win32-Shipping.dll")
    set(_EOS_LIB "${_EOS_LIB_DIR}/EOSSDK-Win32-Shipping.lib")
  endif()

  if(NOT EXISTS "${_EOS_DLL}")
    message(FATAL_ERROR
      "Missing EOS Windows DLL:\n"
      "  ${_EOS_DLL}\n"
      "Check EOS_SDK_ROOT:\n"
      "  ${EOS_SDK_ROOT}")
  endif()

  if(NOT EXISTS "${_EOS_LIB}")
    message(FATAL_ERROR
      "Missing EOS Windows import lib:\n"
      "  ${_EOS_LIB}\n"
      "Check EOS_SDK_ROOT:\n"
      "  ${EOS_SDK_ROOT}")
  endif()

  # Link ONLY the import library (.lib). Do NOT link the DLL.
  target_link_libraries(ext_third_party INTERFACE "${_EOS_LIB}")

  # Package the runtime DLL next to the runner/game (do not link it)
  _ext_tp_append_runtime("${_EOS_DLL}")
endif()

# =============================================================================
# Apple (macOS only in this block)
# =============================================================================
if(APPLE)
  set(_IS_IOS FALSE)
  set(_IS_TVOS FALSE)
  set(_IS_MACOS FALSE)

  if(CMAKE_OSX_SYSROOT MATCHES "iphone")
    set(_IS_IOS TRUE)
  elseif(CMAKE_OSX_SYSROOT MATCHES "appletv")
    set(_IS_TVOS TRUE)
  else()
    set(_IS_MACOS TRUE)
  endif()

  if(_IS_MACOS)
    message(STATUS "macOS: linking EOS libEOSSDK-Mac-Shipping.dylib")

    get_filename_component(_TP_DIR "${CMAKE_CURRENT_LIST_DIR}" ABSOLUTE)
    get_filename_component(_SRC_DIR "${_TP_DIR}/.." ABSOLUTE)
    get_filename_component(_EXT_DIR "${_SRC_DIR}/.." ABSOLUTE)

    set(_EOS_DYLIB "${_EOS_BIN_DIR}/libEOSSDK-Mac-Shipping.dylib")

    if(NOT EXISTS "${_EOS_DYLIB}")
      message(FATAL_ERROR
        "Missing EOS macOS dylib:\n"
        "  ${_EOS_DYLIB}\n"
        "Check EOS_SDK_ROOT:\n"
        "  ${EOS_SDK_ROOT}")
    endif()

    add_library(EOS::EOSSDK SHARED IMPORTED GLOBAL)
    set_target_properties(EOS::EOSSDK PROPERTIES
      IMPORTED_LOCATION "${_EOS_DYLIB}"
    )

    target_link_libraries(ext_third_party INTERFACE EOS::EOSSDK)

    # Register runtime dylib for packaging/staging
    _ext_tp_append_runtime("${_EOS_DYLIB}")
  endif()
endif()

# =============================================================================
# Linux (desktop only)
# =============================================================================
if(UNIX AND NOT APPLE AND NOT ANDROID)
  message(STATUS "Linux: linking EOS libEOSSDK-Linux-Shipping.so")

  get_filename_component(_TP_DIR  "${CMAKE_CURRENT_LIST_DIR}" ABSOLUTE)
  get_filename_component(_SRC_DIR "${_TP_DIR}/.." ABSOLUTE)
  get_filename_component(_EXT_DIR "${_SRC_DIR}/.." ABSOLUTE)

  set(_EOS_SO "${_EOS_BIN_DIR}/libEOSSDK-Linux-Shipping.so")

  if(NOT EXISTS "${_EOS_SO}")
    message(FATAL_ERROR
      "Missing EOS Linux shared lib:\n"
      "  ${_EOS_SO}\n"
      "Check EOS_SDK_ROOT:\n"
      "  ${EOS_SDK_ROOT}")
  endif()

  add_library(EOS::EOSSDK SHARED IMPORTED GLOBAL)
  set_target_properties(EOS::EOSSDK PROPERTIES
    IMPORTED_LOCATION "${_EOS_SO}"
    MAP_IMPORTED_CONFIG_RELWITHDEBINFO "${_MAP_REL_CONFIGS}"
    MAP_IMPORTED_CONFIG_MINSIZEREL     "${_MAP_REL_CONFIGS}"
  )

  target_link_libraries(ext_third_party INTERFACE EOS::EOSSDK)

  # Register runtime .so for packaging/staging
  _ext_tp_append_runtime("${_EOS_SO}")
endif()

# Export to parent
set(EXT_TP_RUNTIME_DLLS "${_EXT_TP_RUNTIME_DLLS}" PARENT_SCOPE)