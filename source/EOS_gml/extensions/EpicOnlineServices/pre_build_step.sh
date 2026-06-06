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
    mkdir -p "$IOS_DIR"
    rm -f "$IOS_DIR/EOSSDK.zip"

    echo "Staging EOS iOS dependency: $EOS_XCFW -> EOSSDK.zip"
    # Zip with ditto on macOS so the framework's symlinks + code signature survive
    # (a Linux/Windows zip would break them). --norsrc/--noextattr drop resource
    # forks and extended attributes, otherwise they extract as AppleDouble "._"
    # files inside the xcframework and break ProcessXCFramework/SignatureCollection.
    # --keepParent keeps the top-level EOSSDK.xcframework folder inside the archive.
    ditto -c -k --norsrc --noextattr --keepParent "$EOS_XCFW" "$IOS_DIR/EOSSDK.zip"
    if [ $? -ne 0 ]; then
        logError "Failed to zip '$EOS_XCFW' into '$IOS_DIR/EOSSDK.zip'."
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
