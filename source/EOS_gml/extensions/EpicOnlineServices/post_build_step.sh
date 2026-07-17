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

    # Strip macOS quarantine flag if present (Gatekeeper would otherwise block the dylib)
    if xattr -p com.apple.quarantine "$SDK_SOURCE" >/dev/null 2>&1; then
        logWarning "'$(basename "$SDK_SOURCE")' is quarantined. Removing com.apple.quarantine…"
        if xattr -d com.apple.quarantine "$SDK_SOURCE" >/dev/null 2>&1; then
            logInformation "Removed quarantine from '$SDK_SOURCE'"
        else
            logError "Failed to remove quarantine from '$SDK_SOURCE' (permissions/path?)."
        fi
    fi

    # When running from CI 'YYprojectName' is not set; derive it from the path.
    if [ -z "$YYprojectName" ]; then
        YYprojectName=$(basename "${YYprojectPath%.*}")
    fi
    YYfixedProjectName="${YYprojectName// /_}"

    SUPPORTING_FILES="${YYfixedProjectName}/${YYfixedProjectName}/Supporting Files"

    echo "Staging EOS macOS dependency (libEOSSDK-Mac-Shipping.dylib)"
    itemCopyTo "$SDK_SOURCE" "${SUPPORTING_FILES}/libEOSSDK-Mac-Shipping.dylib"

    # Explicitly code sign the dependency (and the extension binary) with the
    # hardened runtime so YYC exports pass notarization. Only sign when an
    # identity is provided so unsigned local builds still succeed.
    if [ -n "${YYPLATFORM_option_mac_signing_identity}" ]; then
        assertXcodeToolsInstalled
        codesign -s "${YYPLATFORM_option_mac_signing_identity}" -f --timestamp --options runtime "${SUPPORTING_FILES}/libEOSSDK-Mac-Shipping.dylib"
        if [ -f "${SUPPORTING_FILES}/libEpicOnlineServices.dylib" ]; then
            codesign -s "${YYPLATFORM_option_mac_signing_identity}" -f --timestamp --options runtime "${SUPPORTING_FILES}/libEpicOnlineServices.dylib"
        fi
    else
        logWarning "No mac signing identity set; skipping explicit dylib signing (GameMaker will sign the bundle)."
    fi
}
setupmacOS() { _eos_stage_macos; }

# GMRT (the new runner) variant of the macOS setup.
# Under GMRT the platform name is 'Mac' (this dispatches here) and the
# dependency must live inside the output 'build/assets' folder.
setupMac() {
    pathResolveExisting "$YYprojectDir" "$SDK_PATH_C" SDK_PATH
    SDK_SOURCE="$SDK_PATH/Bin/libEOSSDK-Mac-Shipping.dylib"

    if xattr -p com.apple.quarantine "$SDK_SOURCE" >/dev/null 2>&1; then
        logWarning "'$(basename "$SDK_SOURCE")' is quarantined. Removing com.apple.quarantine…"
        if xattr -d com.apple.quarantine "$SDK_SOURCE" >/dev/null 2>&1; then
            logInformation "Removed quarantine from '$SDK_SOURCE'"
        else
            logError "Failed to remove quarantine from '$SDK_SOURCE' (permissions/path?)."
        fi
    fi

    echo "Staging EOS macOS dependency (libEOSSDK-Mac-Shipping.dylib) (GMRT)"

    # GMRT expects the dependency inside the 'build/assets' folder
    pushd "./build/assets/" >/dev/null

    itemCopyTo "$SDK_SOURCE" "./libEOSSDK-Mac-Shipping.dylib"

    if [ -n "${YYPLATFORM_option_mac_signing_identity}" ]; then
        assertXcodeToolsInstalled
        codesign -s "${YYPLATFORM_option_mac_signing_identity}" -f --timestamp --options runtime "./libEOSSDK-Mac-Shipping.dylib"
    else
        logWarning "No mac signing identity set; skipping explicit dylib signing (GameMaker will sign the bundle)."
    fi

    popd >/dev/null
}

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
    # Stage the EOS SDK's Android AAR as a whole into AndroidSource/libs-aar/ so
    # GameMaker's Gradle build consumes it directly (classes.jar + per-ABI
    # libEOSSDK.so extracted automatically) via the "implementation files(...)"
    # dependency declared in EpicOnlineServices.yy. Git-ignored; mirrors
    # GMEXT-Discord's post_build_step.sh pattern.
    pathResolveExisting "$YYprojectDir" "$SDK_PATH_ANDROID" SDK_PATH

    EOS_AAR="$SDK_PATH/SDK/Bin/Android/static-stdc++/aar/eossdk-StaticSTDC-release.aar"

    echo "Staging EOS Android dependency (eossdk-StaticSTDC-release.aar)"
    mkdir -p "$EXTENSION_DIR/AndroidSource/libs-aar"
    itemCopyTo "$EOS_AAR" "$EXTENSION_DIR/AndroidSource/libs-aar/eossdk-StaticSTDC-release.aar"
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
