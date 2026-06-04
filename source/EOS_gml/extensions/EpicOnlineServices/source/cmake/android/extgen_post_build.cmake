# Android post-build: copy .so to AndroidSource/libs/<ABI>/, optional AAR and third-party .so files

if(EXT_ANDROID_OUTPUT_DIR STREQUAL "")
  set(_EXT_ANDROID_OUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../AndroidSource")
elseif(IS_ABSOLUTE "${EXT_ANDROID_OUTPUT_DIR}")
  set(_EXT_ANDROID_OUT_DIR "${EXT_ANDROID_OUTPUT_DIR}")
else()
  get_filename_component(_EXT_ANDROID_OUT_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/${EXT_ANDROID_OUTPUT_DIR}"
    ABSOLUTE
  )
endif()

set(_ANDROID_ABI_DIR "${_EXT_ANDROID_OUT_DIR}/libs/${CMAKE_ANDROID_ARCH_ABI}")

add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E make_directory "${_ANDROID_ABI_DIR}"
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
          "$<TARGET_FILE:${PROJECT_NAME}>"
          "${_ANDROID_ABI_DIR}/lib$<TARGET_PROPERTY:${PROJECT_NAME},OUTPUT_NAME>.so"
  COMMENT "Copying Android shared library to ${_ANDROID_ABI_DIR}"
)

# Third-party Java classes (e.g. EOS SDK classes.jar) -> AndroidSource/libs/,
# which GameMaker picks up as a jar dependency. Renamed so it does not collide
# with the runner's own classes.jar.
if(DEFINED EXT_TP_ANDROID_JAR AND EXISTS "${EXT_TP_ANDROID_JAR}")
  set(_ANDROID_LIBS_DIR "${_EXT_ANDROID_OUT_DIR}/libs")
  add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "${_ANDROID_LIBS_DIR}"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${EXT_TP_ANDROID_JAR}" "${_ANDROID_LIBS_DIR}/EOSSDK.jar"
    COMMENT "Copying EOS SDK Java classes to ${_ANDROID_LIBS_DIR}/EOSSDK.jar"
  )
endif()

if(EXT_TP_RUNTIME_DLLS)
  add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${EXT_TP_RUNTIME_DLLS} "${_ANDROID_ABI_DIR}/"
    COMMENT "Copying third-party Android .so(s) to ${_ANDROID_ABI_DIR}"
  )
endif()
