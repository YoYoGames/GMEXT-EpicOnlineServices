#!/bin/bash

sed -i -e 's/\r$//' "$(dirname "$0")/scriptUtils.sh"
chmod +x "$(dirname "$0")/scriptUtils.sh"
source "$(dirname "$0")/scriptUtils.sh"

EXTENSION_DIR="$(cd "$(dirname "$0")" && pwd -P)"

# ######################################################################################
# Script Functions

setupWindows() { :; }

# macOS: copy the EOS dylib next to the built game (mirrors the FMOD layout).
_eos_stage_macos() {
    pathResolveExisting "$YYprojectDir" "$SDK_PATH_C" SDK_PATH
    SDK_SOURCE="$SDK_PATH/Bin/libEOSSDK-Mac-Shipping.dylib"

    # When running from CI 'YYprojectName' is not set; derive it from the path.
    if [ -z "$YYprojectName" ]; then
        YYprojectName=$(basename "${YYprojectPath%.*}")
    fi
    YYfixedProjectName="${YYprojectName// /_}"

    echo "Staging EOS macOS dependency (libEOSSDK-Mac-Shipping.dylib)"
    itemCopyTo "$SDK_SOURCE" "${YYfixedProjectName}/${YYfixedProjectName}/Supporting Files/libEOSSDK-Mac-Shipping.dylib"
}
setupmacOS() { _eos_stage_macos; }
setupMac()   { _eos_stage_macos; }

# ----------------------------------------------------------------------------------------------------
setupLinux() {
    pathResolveExisting "$YYprojectDir" "$SDK_PATH_C" SDK_PATH
    SDK_SOURCE="$SDK_PATH/Bin/libEOSSDK-Linux-Shipping.so"

    if [ -z "$YYprojectName" ]; then
        YYprojectName=$(basename "${YYprojectPath%.*}")
    fi

    TEMP_FOLDER="${YYprojectName}___temp___"
    echo "Staging EOS Linux dependency (libEOSSDK-Linux-Shipping.so)"
    mkdir "./${TEMP_FOLDER}"
    itemCopyTo "$SDK_SOURCE" "${TEMP_FOLDER}/assets/libEOSSDK-Linux-Shipping.so"
    zipUpdate "${TEMP_FOLDER}" "${YYprojectName}.zip"
    rm -r "${TEMP_FOLDER}"
}

# ----------------------------------------------------------------------------------------------------
setupAndroid() {
    # Do NOT delete the staged AndroidSource/libs binaries here -- GameMaker's
    # Gradle packaging runs AFTER post_build_step, so they must still exist.
    # pre_build_step removes stale copies at the start of the next build.
    :
}

setupiOS()         { :; }
setuptvOS()        { :; }
setupXbox()        { :; }
setupPlaystation() { :; }
setupSwitch()      { :; }

# ######################################################################################
# Script Logic

scriptInit

# SDK paths (extension options)
optionGetValue "sdkPath"        SDK_PATH_C
optionGetValue "sdkAndroidPath" SDK_PATH_ANDROID
optionGetValue "sdkIosPath"     SDK_PATH_IOS

# Ensure we are on the output path
pushd "$YYoutputFolder" >/dev/null

# Call setup method depending on the platform
setup$YYPLATFORM_name

popd >/dev/null

exit 0
