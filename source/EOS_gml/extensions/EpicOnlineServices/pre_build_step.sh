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
    # Stage the EOS SDK's Java classes + per-ABI native lib (extracted from the
    # Android SDK's AAR) into AndroidSource/libs so GameMaker's Gradle build
    # packages them. These are git-ignored; the extension's own
    # libEpicOnlineServices.so stays committed alongside them.
    pathResolveExisting "$YYprojectDir" "$SDK_PATH_ANDROID" SDK_PATH

    EOS_AAR="$SDK_PATH/SDK/Bin/Android/static-stdc++/aar/eossdk-StaticSTDC-release.aar"
    LIBS_DIR="$EXTENSION_DIR/AndroidSource/libs"
    TMP_DIR="$EXTENSION_DIR/_eos_aar_tmp"

    # Clean any stale staged SDK binaries from a previous build
    itemDelete "$LIBS_DIR/EOSSDK.jar"
    itemDelete "$LIBS_DIR/arm64-v8a/libEOSSDK.so"
    itemDelete "$LIBS_DIR/x86_64/libEOSSDK.so"
    # NB: itemDelete only removes files, so use rm -rf for the temp directory
    rm -rf "$TMP_DIR"

    # Extract the AAR (a zip archive) into a temp dir
    itemCopyTo "$EOS_AAR" "$TMP_DIR/eos.zip"
    fileExtract "$TMP_DIR/eos.zip" "$TMP_DIR/eos"

    # Java classes (architecture-independent)
    itemCopyTo "$TMP_DIR/eos/classes.jar" "$LIBS_DIR/EOSSDK.jar"

    # Per-ABI native lib (EOS AAR ships arm64-v8a and x86_64 only)
    if [[ "$YYPLATFORM_option_android_arch_arm64" == "True" ]]; then
        echo "Staging EOS Android dependencies (arm64-v8a)"
        itemCopyTo "$TMP_DIR/eos/jni/arm64-v8a/libEOSSDK.so" "$LIBS_DIR/arm64-v8a/libEOSSDK.so"
    fi
    if [[ "$YYPLATFORM_option_android_arch_x86_64" == "True" ]]; then
        echo "Staging EOS Android dependencies (x86_64)"
        itemCopyTo "$TMP_DIR/eos/jni/x86_64/libEOSSDK.so" "$LIBS_DIR/x86_64/libEOSSDK.so"
    fi

    rm -rf "$TMP_DIR"
}

# ----------------------------------------------------------------------------------------------------
setupiOS() {
    # Stage the EOS SDK's xcframework into iOSSourceFromMac as a .zip (alongside
    # the extension's own packaged EpicOnlineServices.zip) so the GameMaker iOS
    # build links it. It is git-ignored and re-zipped each build.
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

# Call setup method depending on the platform
setup$YYPLATFORM_name

popd >/dev/null

exit 0
