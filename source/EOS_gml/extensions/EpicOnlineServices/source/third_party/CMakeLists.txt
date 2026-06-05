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
    "D:/Github/GMEXT-EpicOnlineServices/source/EOS_sdk/c"
    CACHE PATH "Path to Epic Online Services SDK root" FORCE)

set(_EOS_INCLUDE_DIR "${EOS_SDK_ROOT}/Include")
set(_EOS_BIN_DIR     "${EOS_SDK_ROOT}/Bin")
set(_EOS_LIB_DIR     "${EOS_SDK_ROOT}/Lib")

message(STATUS "EOS_SDK_ROOT = ${EOS_SDK_ROOT}")
message(STATUS "_EOS_INCLUDE_DIR = ${_EOS_INCLUDE_DIR}")
message(STATUS "_EOS_BIN_DIR = ${_EOS_BIN_DIR}")
message(STATUS "_EOS_LIB_DIR = ${_EOS_LIB_DIR}")

# Derive sibling SDK roots. Android and iOS ship their own headers + binaries
# next to the desktop "c" SDK (EOS_sdk/Android, EOS_sdk/iOS).
get_filename_component(_EOS_SDK_BASE "${EOS_SDK_ROOT}" DIRECTORY)
set(EOS_SDK_ANDROID_ROOT
    "${_EOS_SDK_BASE}/Android/SDK"
    CACHE PATH "Path to Epic Online Services Android SDK root" FORCE)
set(EOS_SDK_IOS_ROOT
    "${_EOS_SDK_BASE}/iOS/SDK"
    CACHE PATH "Path to Epic Online Services iOS SDK root" FORCE)

# Classify the mobile platforms. They use their own platform SDK headers, not
# the desktop C SDK (whose Include/ only carries Windows/Mac/Linux sub-headers).
set(_EOS_IS_ANDROID FALSE)
set(_EOS_IS_IOS FALSE)
if(ANDROID)
  set(_EOS_IS_ANDROID TRUE)
elseif(APPLE AND CMAKE_OSX_SYSROOT MATCHES "iphone")
  set(_EOS_IS_IOS TRUE)
endif()

# Desktop (Windows/macOS/Linux) headers come from the C SDK Include directory.
# Mobile headers are added in their respective platform blocks below.
if(NOT _EOS_IS_ANDROID AND NOT _EOS_IS_IOS)
  if(NOT EXISTS "${_EOS_INCLUDE_DIR}/eos_sdk.h")
    message(FATAL_ERROR
      "Missing EOS header:\n"
      "  ${_EOS_INCLUDE_DIR}/eos_sdk.h\n"
      "Check EOS_SDK_ROOT:\n"
      "  ${EOS_SDK_ROOT}")
  endif()
  target_include_directories(ext_third_party INTERFACE "${_EOS_INCLUDE_DIR}")
endif()

# =============================================================================
# Shared native implementation on mobile (Android / iOS)
# =============================================================================
# The generator-owned src/CMakeLists.txt compiles src/native for desktop, but its
# per-platform globs don't cover Android (it globs a non-existent src/android) or
# the iOS NATIVE flavour. EOS uses the same portable C++ core on those platforms,
# so we add src/native here instead of editing src/CMakeLists.txt (which would be
# overwritten the next time the extension generator runs).
if(ANDROID OR (_EOS_IS_IOS AND EXT_APPLE_NATIVE_FRAMEWORK))
  file(GLOB _EOS_SRC_NATIVE CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/native/*.cpp")
  if(_EOS_SRC_NATIVE)
    target_sources(${EXT_MAIN_TARGET} PRIVATE ${_EOS_SRC_NATIVE})
  endif()
endif()

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
# Android
# =============================================================================
# The Android SDK ships as an AAR bundling a per-ABI libEOSSDK.so and the EOS
# Java classes (classes.jar). We link against the extracted libEOSSDK.so and
# register it as a runtime lib so the framework post-build stages it into
# AndroidSource/libs/<abi>/. The Java side (EOSSDK.jar) is a static SDK artifact
# committed under AndroidSource/libs/ (re-extract from the AAR on SDK updates).
if(ANDROID)
  set(_EOS_ANDROID_INCLUDE_DIR "${EOS_SDK_ANDROID_ROOT}/Include")
  set(_EOS_ANDROID_AAR
      "${EOS_SDK_ANDROID_ROOT}/Bin/Android/static-stdc++/aar/eossdk-StaticSTDC-release.aar")

  message(STATUS "Android: EOS SDK = ${EOS_SDK_ANDROID_ROOT}")
  message(STATUS "Android: ABI = ${CMAKE_ANDROID_ARCH_ABI}")

  if(NOT EXISTS "${_EOS_ANDROID_INCLUDE_DIR}/eos_sdk.h")
    message(FATAL_ERROR
      "Missing EOS Android header:\n"
      "  ${_EOS_ANDROID_INCLUDE_DIR}/eos_sdk.h\n"
      "Check EOS_SDK_ANDROID_ROOT:\n"
      "  ${EOS_SDK_ANDROID_ROOT}")
  endif()

  if(NOT EXISTS "${_EOS_ANDROID_AAR}")
    message(FATAL_ERROR
      "Missing EOS Android AAR:\n"
      "  ${_EOS_ANDROID_AAR}")
  endif()

  # Headers: common headers live in Include/, the Android platform base header
  # lives in Include/Android/ (eos_Android_base.h).
  target_include_directories(ext_third_party INTERFACE
    "${_EOS_ANDROID_INCLUDE_DIR}"
    "${_EOS_ANDROID_INCLUDE_DIR}/Android")

  # The AAR provides libEOSSDK.so for arm64-v8a and x86_64 only (no armeabi-v7a).
  set(_EOS_AAR_ABI "${CMAKE_ANDROID_ARCH_ABI}")
  if(NOT _EOS_AAR_ABI MATCHES "^(arm64-v8a|x86_64)$")
    message(FATAL_ERROR
      "EOS Android SDK has no libEOSSDK.so for ABI '${_EOS_AAR_ABI}'.\n"
      "Supported ABIs: arm64-v8a, x86_64.")
  endif()

  # Extract the per-ABI libEOSSDK.so from the AAR at configure time so we have
  # something to link against. NB: use `cmake -E tar` and ignore its exit code --
  # this AAR's 1980 entry timestamps make libarchive report a benign "Can't
  # restore time" error AFTER the bytes are written; success is verified below by
  # the file's presence.
  set(_EOS_AAR_EXTRACT_DIR "${CMAKE_CURRENT_BINARY_DIR}/eos_aar")
  set(_EOS_ANDROID_SO "${_EOS_AAR_EXTRACT_DIR}/jni/${_EOS_AAR_ABI}/libEOSSDK.so")

  file(MAKE_DIRECTORY "${_EOS_AAR_EXTRACT_DIR}")
  if(NOT EXISTS "${_EOS_ANDROID_SO}")
    execute_process(
      COMMAND ${CMAKE_COMMAND} -E tar xf
              "${_EOS_ANDROID_AAR}" "jni/${_EOS_AAR_ABI}/libEOSSDK.so"
      WORKING_DIRECTORY "${_EOS_AAR_EXTRACT_DIR}")
  endif()

  if(NOT EXISTS "${_EOS_ANDROID_SO}")
    message(FATAL_ERROR
      "Failed to extract libEOSSDK.so for ABI '${_EOS_AAR_ABI}' from:\n"
      "  ${_EOS_ANDROID_AAR}")
  endif()

  add_library(EOS::EOSSDK SHARED IMPORTED GLOBAL)
  set_target_properties(EOS::EOSSDK PROPERTIES
    IMPORTED_LOCATION "${_EOS_ANDROID_SO}")

  target_link_libraries(ext_third_party INTERFACE EOS::EOSSDK)

  # NOTE: libEOSSDK.so is staged into AndroidSource/libs/<abi>/ at game-build time
  # by the extension's pre_build_step (from the EOS Android SDK at sdkAndroidPath),
  # and git-ignored. The native build only needs it to LINK against, so it is
  # intentionally NOT registered as a runtime lib for the framework to copy.
endif()

# =============================================================================
# Apple (macOS and iOS)
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

  if(_IS_IOS)
    set(_EOS_IOS_FRAMEWORK "${EOS_SDK_IOS_ROOT}/Bin/IOS/EOSSDK.framework")
    set(_EOS_IOS_HEADERS   "${_EOS_IOS_FRAMEWORK}/Headers")

    message(STATUS "iOS: EOS SDK framework = ${_EOS_IOS_FRAMEWORK}")

    if(NOT EXISTS "${_EOS_IOS_HEADERS}/eos_sdk.h")
      message(FATAL_ERROR
        "Missing EOS iOS header:\n"
        "  ${_EOS_IOS_HEADERS}/eos_sdk.h\n"
        "Check EOS_SDK_IOS_ROOT:\n"
        "  ${EOS_SDK_IOS_ROOT}")
    endif()

    # Header-only for the iOS build: the extension is archived into a static lib
    # (and then an xcframework), so it never links its dependencies itself.
    # EOSSDK.framework is linked into the final app by GameMaker's Xcode project.
    # The shipped EOS xcframework also has a device (arm64) slice only — no
    # simulator — so deliberately do NOT add it to the link line here.
    target_include_directories(ext_third_party INTERFACE "${_EOS_IOS_HEADERS}")
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