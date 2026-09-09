#!/bin/bash

sed -i -e 's/\r$//' "$(dirname "$0")/scriptUtils.sh"
chmod +x "$(dirname "$0")/scriptUtils.sh"
source "$(dirname "$0")/scriptUtils.sh"

EXTENSION_DIR="$(cd "$(dirname "$0")" && pwd -P)"

# ######################################################################################
# Script Functions

setupWindows() { :; }
setupmacOS()   { :; }   # desktop runtime lib is staged into the output by post_build_step
setupMac()     { :; }
setupLinux()   { :; }

# ----------------------------------------------------------------------------------------------------
setupAndroid() {
    # Stage the EOS SDK's Android AAR as a whole into AndroidSource/libs-aar/ so
    # GameMaker's Gradle build consumes it directly (classes.jar + per-ABI
    # libEOSSDK.so extracted automatically) via the "implementation files(...)"
    # dependency declared in EpicOnlineServices.yy. Git-ignored.
    #
    # This MUST be a pre_build_step: the asset compiler copies the whole
    # AndroidSource/libs-aar folder into the Gradle project itself, and it runs
    # between pre_build_step and post_build_step. Staged from post_build_step the
    # AAR is always one build behind, so a clean checkout's first Android build
    # has no EOS SDK in it at all.
    pathResolveExisting "$YYprojectDir" "$SDK_PATH_ANDROID" SDK_PATH

    EOS_AAR="$SDK_PATH/SDK/Bin/Android/static-stdc++/aar/eossdk-StaticSTDC-release.aar"

    echo "Staging EOS Android dependency (eossdk-StaticSTDC-release.aar)"
    mkdir -p "$EXTENSION_DIR/AndroidSource/libs-aar"
    itemCopyTo "$EOS_AAR" "$EXTENSION_DIR/AndroidSource/libs-aar/eossdk-StaticSTDC-release.aar"
}

# ----------------------------------------------------------------------------------------------------
setupiOS() {
    # Stage the EOS SDK's xcframework into iOSSourceFromMac as a .zip (alongside
    # the extension's own packaged EpicOnlineServices.zip) so the GameMaker iOS
    # build links it. A zero-byte EOSSDK.zip is committed as a placeholder so
    # the entry exists in a clean checkout and in the packaged asset; this
    # overwrites it each build, so restore it rather than committing the SDK.
    pathResolveExisting "$YYprojectDir" "$SDK_PATH_IOS" SDK_PATH

    # Locate the xcframework anywhere under the SDK (the folder layout differs
    # between the raw Epic download and the repo's bundled copy).
    EOS_XCFW=$(find "$SDK_PATH" -maxdepth 6 -type d -iname "EOSSDK.xcframework" -print -quit)
    if [ -z "$EOS_XCFW" ]; then
        logError "EOSSDK.xcframework not found under '$SDK_PATH' (check the sdkIosPath option)."
    fi

    IOS_DIR="$EXTENSION_DIR/iOSSourceFromMac"
    TMP_DIR="$EXTENSION_DIR/_eos_xcfw_tmp"
    mkdir -p "$IOS_DIR"
    rm -f "$IOS_DIR/EOSSDK.zip"
    rm -rf "$TMP_DIR"
    mkdir -p "$TMP_DIR"

    # Work on a copy so the SDK is never modified (ditto copies faithfully).
    ditto "$EOS_XCFW" "$TMP_DIR/EOSSDK.xcframework"
    XCFW="$TMP_DIR/EOSSDK.xcframework"

    # Strip the vendor (Epic) code signature. Xcode 15+ verifies a bundled
    # xcframework's signature and fails with "signature cannot be verified" for a
    # third-party one. The app re-signs embedded frameworks with its own identity
    # during signing, so removing the vendor signature is the standard fix: drop
    # every _CodeSignature bundle seal and each framework binary's embedded sig.
    find "$XCFW" -type d -name "_CodeSignature" -exec rm -rf {} +
    find "$XCFW" -type d -name "*.framework" | while IFS= read -r fw; do
        bin="$fw/$(basename "$fw" .framework)"
        [ -f "$bin" ] && codesign --remove-signature "$bin" >/dev/null 2>&1 || true
    done

    echo "Staging EOS iOS dependency: $EOS_XCFW -> EOSSDK.zip (signature stripped)"
    # ditto on macOS preserves the (flat iOS) framework structure; --norsrc/
    # --noextattr prevent AppleDouble "._" files that break ProcessXCFramework.
    # --keepParent keeps the top-level EOSSDK.xcframework folder inside the archive.
    ditto -c -k --norsrc --noextattr --keepParent "$XCFW" "$IOS_DIR/EOSSDK.zip"
    rc=$?
    rm -rf "$TMP_DIR"
    if [ $rc -ne 0 ]; then
        logError "Failed to zip EOSSDK.xcframework into '$IOS_DIR/EOSSDK.zip'."
    fi
}

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

# Call setup method depending on the platform. Every platform the .bat counterpart declares a label
# for has a function here too - bash reports an undefined one as "command not found" (127), which the
# capture below turns into a failed build instead of a silent no-op.
setup$YYPLATFORM_name
SETUP_RESULT=$?

popd >/dev/null

exit $SETUP_RESULT
