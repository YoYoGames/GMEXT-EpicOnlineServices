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

# Fail configure with a clear, actionable error if a required vendored SDK
# file is missing (wrong/stale root override, or an SDK not yet vendored).
function(_ext_tp_require_file _path _description _root_var_name)
  if(NOT EXISTS "${_path}")
    message(FATAL_ERROR
      "Missing ${_description}:\n"
      "  ${_path}\n"
      "Check ${_root_var_name}:\n"
      "  ${${_root_var_name}}")
  endif()
endfunction()

# =============================================================================
# Epic Online Services SDK
# =============================================================================
# Resolve the SDK location relative to this file so the build is portable across
# machines/checkouts. From <repo>/source/EOS_gml/extensions/EpicOnlineServices/
# source/third_party, the SDK lives at <repo>/source/EOS_sdk (five levels up).
# This is only the DEFAULT for EOS_SDK_ROOT below -- it is not re-read if
# EOS_SDK_ROOT is overridden (see _EOS_SDK_BASE further down, which IS derived
# from the actual, possibly-overridden EOS_SDK_ROOT).
get_filename_component(_EOS_SDK_BASE_DEFAULT
    "${CMAKE_CURRENT_LIST_DIR}/../../../../../EOS_sdk"
    ABSOLUTE)

# No FORCE: this only seeds the cache with the computed default on first
# configure (or after the cache entry is cleared) -- CACHE's own default
# behavior, not a workaround. Override with -DEOS_SDK_ROOT=... or via
# CMakeUserPresets.json; the override then sticks across reconfigures. If this
# file's default-computation logic changes and an existing build directory's
# CMakeCache.txt holds a stale value from before the change, clear it
# explicitly, e.g. `cmake -UEOS_SDK_ROOT <build-dir>`, or reconfigure into a
# fresh build directory.
set(EOS_SDK_ROOT
    "${_EOS_SDK_BASE_DEFAULT}/C"
    CACHE PATH "Path to Epic Online Services SDK root")

set(_EOS_INCLUDE_DIR "${EOS_SDK_ROOT}/Include")
set(_EOS_BIN_DIR     "${EOS_SDK_ROOT}/Bin")
set(_EOS_LIB_DIR     "${EOS_SDK_ROOT}/Lib")

message(STATUS "EOS_SDK_ROOT = ${EOS_SDK_ROOT}")
message(STATUS "_EOS_INCLUDE_DIR = ${_EOS_INCLUDE_DIR}")
message(STATUS "_EOS_BIN_DIR = ${_EOS_BIN_DIR}")
message(STATUS "_EOS_LIB_DIR = ${_EOS_LIB_DIR}")

# Derive sibling SDK roots from the ACTUAL EOS_SDK_ROOT (not
# _EOS_SDK_BASE_DEFAULT above), so Android/iOS roots stay correct if
# EOS_SDK_ROOT is overridden. Android and iOS ship their own headers +
# binaries next to the desktop "C" SDK (EOS_sdk/Android, EOS_sdk/iOS) -- each
# of those folders IS the SDK root directly (Bin/Include right underneath),
# there's no extra nested SDK/ subfolder. Same no-FORCE override rules apply
# as EOS_SDK_ROOT above.
get_filename_component(_EOS_SDK_BASE "${EOS_SDK_ROOT}" DIRECTORY)
set(EOS_SDK_ANDROID_ROOT
    "${_EOS_SDK_BASE}/Android"
    CACHE PATH "Path to Epic Online Services Android SDK root")
set(EOS_SDK_IOS_ROOT
    "${_EOS_SDK_BASE}/iOS"
    CACHE PATH "Path to Epic Online Services iOS SDK root")

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
  _ext_tp_require_file("${_EOS_INCLUDE_DIR}/eos_sdk.h" "EOS header" EOS_SDK_ROOT)
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
  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(STATUS "Windows: linking EOS win64")
    set(_EOS_DLL "${_EOS_BIN_DIR}/EOSSDK-Win64-Shipping.dll")
    set(_EOS_LIB "${_EOS_LIB_DIR}/EOSSDK-Win64-Shipping.lib")
  else()
    message(STATUS "Windows: linking EOS win32")
    set(_EOS_DLL "${_EOS_BIN_DIR}/EOSSDK-Win32-Shipping.dll")
    set(_EOS_LIB "${_EOS_LIB_DIR}/EOSSDK-Win32-Shipping.lib")
  endif()

  _ext_tp_require_file("${_EOS_DLL}" "EOS Windows DLL" EOS_SDK_ROOT)

  _ext_tp_require_file("${_EOS_LIB}" "EOS Windows import lib" EOS_SDK_ROOT)

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

  _ext_tp_require_file("${_EOS_ANDROID_INCLUDE_DIR}/eos_sdk.h" "EOS Android header" EOS_SDK_ANDROID_ROOT)

  _ext_tp_require_file("${_EOS_ANDROID_AAR}" "EOS Android AAR" EOS_SDK_ANDROID_ROOT)

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

  if(_EOS_IS_IOS)
    set(_IS_IOS TRUE)
  elseif(CMAKE_OSX_SYSROOT MATCHES "appletv")
    set(_IS_TVOS TRUE)
  else()
    set(_IS_MACOS TRUE)
  endif()

  if(_IS_MACOS)
    message(STATUS "macOS: linking EOS libEOSSDK-Mac-Shipping.dylib")

    set(_EOS_DYLIB "${_EOS_BIN_DIR}/libEOSSDK-Mac-Shipping.dylib")

    _ext_tp_require_file("${_EOS_DYLIB}" "EOS macOS dylib" EOS_SDK_ROOT)

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

    _ext_tp_require_file("${_EOS_IOS_HEADERS}/eos_sdk.h" "EOS iOS header" EOS_SDK_IOS_ROOT)

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

  set(_EOS_SO "${_EOS_BIN_DIR}/libEOSSDK-Linux-Shipping.so")

  _ext_tp_require_file("${_EOS_SO}" "EOS Linux shared lib" EOS_SDK_ROOT)

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