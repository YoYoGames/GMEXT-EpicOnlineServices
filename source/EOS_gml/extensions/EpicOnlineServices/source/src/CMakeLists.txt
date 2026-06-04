set(SRC_DIR ${CMAKE_CURRENT_LIST_DIR})

# =============================================================================
# GameMaker iOS integration (optional)
# =============================================================================
set(EXT_GM_XCODEPROJ_OVERRIDE "/ABS/PATH/TO/GAME.xcodeproj" CACHE STRING "" FORCE)
set(EXT_GM_APP_TARGET_OVERRIDE "" CACHE STRING "" FORCE)

# =============================================================================
# Public headers for Apple XCFramework packaging
# Users should edit these to match their project structure.
# The packager will copy these into a headers folder passed to xcodebuild.
# =============================================================================
set(EXT_PUBLIC_HEADERS_IOS
    "${CMAKE_SOURCE_DIR}/src/ios/${PROJECT_NAME}_ios.h;${CMAKE_SOURCE_DIR}/code_gen/ios/${PROJECT_NAME}Internal_ios.h"
    CACHE STRING "Semicolon-separated list of public headers to embed in the iOS xcframework")

set(EXT_PUBLIC_HEADERS_TVOS
    "${CMAKE_SOURCE_DIR}/src/tvos/${PROJECT_NAME}_tvos.h;${CMAKE_SOURCE_DIR}/code_gen/tvos/${PROJECT_NAME}Internal_tvos.h"
    CACHE STRING "Semicolon-separated list of public headers to embed in the tvOS xcframework")

# =============================================================================
# User implementation sources per platform (editable template)
# =============================================================================
if(WIN32)
  file(GLOB TARGET_SRCS CONFIGURE_DEPENDS "${SRC_DIR}/native/*.cpp")

elseif(APPLE)
  if(CMAKE_OSX_SYSROOT MATCHES "iphone")
    # NATIVE flavour: ObjC++ wrapper (src/ios) over the shared, portable C++ EOS
    # implementation (src/native), matching the code_gen/native sources that
    # cmake/ios/extgen_post_project.cmake compiles under EXT_APPLE_NATIVE_FRAMEWORK.
    # STANDARD flavour: platform-native implementation in src/ios only.
    file(GLOB TARGET_SRCS CONFIGURE_DEPENDS "${SRC_DIR}/ios/*.mm" "${SRC_DIR}/ios/*.cpp")
    if(EXT_APPLE_NATIVE_FRAMEWORK)
      file(GLOB _SRC_NATIVE CONFIGURE_DEPENDS "${SRC_DIR}/native/*.cpp")
      list(APPEND TARGET_SRCS ${_SRC_NATIVE})
    endif()
  elseif(CMAKE_OSX_SYSROOT MATCHES "appletv")
    file(GLOB TARGET_SRCS CONFIGURE_DEPENDS "${SRC_DIR}/tvos/*.mm" "${SRC_DIR}/tvos/*.cpp")
    if(EXT_APPLE_NATIVE_FRAMEWORK)
      file(GLOB _SRC_NATIVE CONFIGURE_DEPENDS "${SRC_DIR}/native/*.cpp")
      list(APPEND TARGET_SRCS ${_SRC_NATIVE})
    endif()
  else()
    file(GLOB TARGET_SRCS CONFIGURE_DEPENDS "${SRC_DIR}/native/*.cpp" "${SRC_DIR}/native/*.mm")
  endif()

elseif(ANDROID)
  # Android links the EOS C SDK (same C API as desktop), so it reuses the
  # portable native implementation. The GML<->C++ JNI bridge lives in
  # code_gen/android and is added by cmake/android/extgen_post_project.cmake.
  file(GLOB TARGET_SRCS CONFIGURE_DEPENDS "${SRC_DIR}/native/*.cpp")

elseif(UNIX)
  file(GLOB TARGET_SRCS CONFIGURE_DEPENDS "${SRC_DIR}/native/*.cpp")
endif()

target_sources(${PROJECT_NAME} PRIVATE ${TARGET_SRCS})
target_include_directories(${PROJECT_NAME} PRIVATE "${SRC_DIR}")
