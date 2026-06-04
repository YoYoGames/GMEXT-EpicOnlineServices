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
# The Android SDK ships as an AAR that bundles the EOS Java classes and a
# per-ABI libEOSSDK.so. We link the extension against the extracted .so and hand
# the AAR to the post-build step so GameMaker's Gradle build packages both the
# Java side and the runtime .so into the final APK.
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

  # Unpack the AAR at configure time. We need:
  #   * jni/<abi>/libEOSSDK.so  -> to link against, AND packaged into the APK as
  #     a jniLib so the dynamic linker can satisfy libEpicOnlineServices.so's
  #     NEEDED libEOSSDK.so at load time.
  #   * classes.jar             -> the EOS Java classes (EOSSDK, auth handler,
  #     overlay, ...) needed once you start making real EOS calls from Java.
  set(_EOS_AAR_EXTRACT_DIR "${CMAKE_CURRENT_BINARY_DIR}/eos_aar")
  set(_EOS_ANDROID_SO  "${_EOS_AAR_EXTRACT_DIR}/jni/${_EOS_AAR_ABI}/libEOSSDK.so")
  set(_EOS_ANDROID_JAR "${_EOS_AAR_EXTRACT_DIR}/classes.jar")

  # NB: extract via `cmake -E tar` (relative to cwd), one member per call. The
  # result code is intentionally ignored: this AAR's 1980 entry timestamps make
  # libarchive report a benign "Can't restore time" error AFTER the bytes are
  # written. That error ABORTS the run, so a single tar invocation listing both
  # members would stop after the first extracted entry and never reach the
  # second -- hence one call each. Success is verified by file presence below.
  file(MAKE_DIRECTORY "${_EOS_AAR_EXTRACT_DIR}")
  if(NOT EXISTS "${_EOS_ANDROID_SO}")
    execute_process(
      COMMAND ${CMAKE_COMMAND} -E tar xf
              "${_EOS_ANDROID_AAR}" "jni/${_EOS_AAR_ABI}/libEOSSDK.so"
      WORKING_DIRECTORY "${_EOS_AAR_EXTRACT_DIR}")
  endif()
  if(NOT EXISTS "${_EOS_ANDROID_JAR}")
    execute_process(
      COMMAND ${CMAKE_COMMAND} -E tar xf "${_EOS_ANDROID_AAR}" "classes.jar"
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

  # Package libEOSSDK.so into AndroidSource/libs/<abi>/ alongside the extension
  # .so (GameMaker copies that folder into the APK's jniLibs). This is what makes
  # System.loadLibrary("EpicOnlineServices") succeed at runtime.
  _ext_tp_append_runtime("${_EOS_ANDROID_SO}")

  # Hand the EOS Java classes to cmake/android/extgen_post_build.cmake, which
  # drops them into AndroidSource/libs/ as a jar dependency for GameMaker.
  if(EXISTS "${_EOS_ANDROID_JAR}")
    set(EXT_TP_ANDROID_JAR "${_EOS_ANDROID_JAR}" PARENT_SCOPE)
  endif()
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