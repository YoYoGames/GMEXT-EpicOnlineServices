#!/bin/bash

sed -i -e 's/\r$//' "$(dirname "$0")/scriptUtils.sh"
chmod +x "$(dirname "$0")/scriptUtils.sh"
source "$(dirname "$0")/scriptUtils.sh"

EXTENSION_DIR="$(cd "$(dirname "$0")" && pwd -P)"

# ######################################################################################
# Script Functions

setupWindows() { :; }

# Strip the macOS quarantine flag if present - Gatekeeper would otherwise block the dylib.
_eos_strip_quarantine() {
    local target="$1"

    if xattr -p com.apple.quarantine "$target" >/dev/null 2>&1; then
        logWarning "'$(basename "$target")' is quarantined. Removing com.apple.quarantine..."
        if xattr -d com.apple.quarantine "$target" >/dev/null 2>&1; then
            logInformation "Removed quarantine from '$target'"
        else
            logError "Failed to remove quarantine from '$target' (permissions/path?)."
        fi
    fi
}

# Sign with the hardened runtime so the export passes notarization. Only signs when an identity is
# set, so unsigned local builds still succeed.
_eos_codesign() {
    local target="$1"

    [ -f "$target" ] || return 0

    if [ -n "${YYPLATFORM_option_mac_signing_identity}" ]; then
        assertXcodeToolsInstalled
        codesign -s "${YYPLATFORM_option_mac_signing_identity}" -f --timestamp --options runtime "$target"
    else
        logWarning "No mac signing identity set; skipping explicit signing of '$(basename "$target")' (GameMaker will sign the bundle)."
    fi
}

# ----------------------------------------------------------------------------------------------------
setupmacOS() {
    pathResolveExisting "$YYprojectDir" "$SDK_PATH_C" SDK_PATH
    SDK_SOURCE="$SDK_PATH/Bin/libEOSSDK-Mac-Shipping.dylib"
    assertFileHashEquals "$SDK_SOURCE" "$SDK_HASH_MAC" "$ERROR_SDK_HASH"

    _eos_strip_quarantine "$SDK_SOURCE"

    # When running from CI 'YYprojectName' is not set; derive it from the path.
    if [ -z "$YYprojectName" ]; then
        YYprojectName=$(basename "${YYprojectPath%.*}")
    fi

    if [ "$YYTARGET_runtime" = "VM" ]; then
        # VM export: the dylibs sit next to the runner, in the output folder we are already in.
        # This is supportable from a macOS host and not from a Windows one, which has no codesign -
        # post_build_step.bat rejects it there for that reason.
        echo "Staging EOS macOS dependency (libEOSSDK-Mac-Shipping.dylib) (VM)"
        itemCopyTo "$SDK_SOURCE" "./libEOSSDK-Mac-Shipping.dylib"
        _eos_codesign "./libEOSSDK-Mac-Shipping.dylib"
        _eos_codesign "./libEpicOnlineServices.dylib"

        # A game.zip alongside means this is the package command, and the runtime loads from
        # assets/ inside it - so both dylibs have to go in there too.
        if [ -f "./game.zip" ]; then
            TEMP_FOLDER="${YYprojectName}___temp___"
            mkdir "./${TEMP_FOLDER}"
            itemCopyTo "./libEOSSDK-Mac-Shipping.dylib" "${TEMP_FOLDER}/assets/libEOSSDK-Mac-Shipping.dylib"
            itemCopyTo "./libEpicOnlineServices.dylib" "${TEMP_FOLDER}/assets/libEpicOnlineServices.dylib"
            zipUpdate "${TEMP_FOLDER}" "game.zip"
            rm -r "./${TEMP_FOLDER}"
        fi

        return 0
    fi

    # YYC: the Xcode-project-style output GameMaker assembles locally even when the export target is
    # macOS (the remote Mac build host only does the final Xcode compile/sign).
    YYfixedProjectName="${YYprojectName// /_}"
    SUPPORTING_FILES="${YYfixedProjectName}/${YYfixedProjectName}/Supporting Files"

    echo "Staging EOS macOS dependency (libEOSSDK-Mac-Shipping.dylib)"
    itemCopyTo "$SDK_SOURCE" "${SUPPORTING_FILES}/libEOSSDK-Mac-Shipping.dylib"

    _eos_codesign "${SUPPORTING_FILES}/libEOSSDK-Mac-Shipping.dylib"
    _eos_codesign "${SUPPORTING_FILES}/libEpicOnlineServices.dylib"
}

# ----------------------------------------------------------------------------------------------------
# GMRT (the new runner) variant of the macOS setup.
# Under GMRT the platform name is 'Mac' (this dispatches here) and the
# dependency must live inside the output 'build/assets' folder.
setupMac() {
    pathResolveExisting "$YYprojectDir" "$SDK_PATH_C" SDK_PATH
    SDK_SOURCE="$SDK_PATH/Bin/libEOSSDK-Mac-Shipping.dylib"
    assertFileHashEquals "$SDK_SOURCE" "$SDK_HASH_MAC" "$ERROR_SDK_HASH"

    _eos_strip_quarantine "$SDK_SOURCE"

    echo "Staging EOS macOS dependency (libEOSSDK-Mac-Shipping.dylib) (GMRT)"

    # GMRT expects the dependency inside the 'build/assets' folder
    pushd "./build/assets/" >/dev/null

    itemCopyTo "$SDK_SOURCE" "./libEOSSDK-Mac-Shipping.dylib"
    _eos_codesign "./libEOSSDK-Mac-Shipping.dylib"

    popd >/dev/null
}

# ----------------------------------------------------------------------------------------------------
setupLinux() {
    pathResolveExisting "$YYprojectDir" "$SDK_PATH_C" SDK_PATH
    SDK_SOURCE="$SDK_PATH/Bin/libEOSSDK-Linux-Shipping.so"
    assertFileHashEquals "$SDK_SOURCE" "$SDK_HASH_LINUX" "$ERROR_SDK_HASH"

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
    # Nothing to do here. The AAR is staged in pre_build_step, because the asset
    # compiler copies AndroidSource/libs-aar into the Gradle project before this
    # script ever runs.
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

# SDK integrity (extension options). The desktop libs are staged straight out of the folder the
# sdkPath option points at, so a wrong or truncated download otherwise produces a game that builds
# and then fails to load its native library with no diagnostic at all.
optionGetValue "sdkVersion"   SDK_VERSION
optionGetValue "sdkHashMac"   SDK_HASH_MAC
optionGetValue "sdkHashLinux" SDK_HASH_LINUX

ERROR_SDK_HASH="Invalid EOS SDK version, sha256 hash mismatch (expected v$SDK_VERSION)."

# Ensure we are on the output path
pushd "$YYoutputFolder" >/dev/null

# Call setup method depending on the platform. Every platform the .bat counterpart declares a label
# for has a function here too - bash reports an undefined one as "command not found" (127), which the
# capture below turns into a failed build instead of a silent no-op.
setup$YYPLATFORM_name
SETUP_RESULT=$?

popd >/dev/null

exit $SETUP_RESULT
