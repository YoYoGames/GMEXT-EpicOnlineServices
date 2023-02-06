#!/bin/bash

source "$(dirname "$0")/scriptUtils.sh"

# ######################################################################################
# Macros

pathExtractDirectory "$0" SCRIPT_PATH
pathExtractBase "$0" EXTENSION_NAME
toUpper "$EXTENSION_NAME" EXTENSION_NAME

export SCRIPT_PATH
export EXTENSION_NAME

# Version locks
RUNTIME_VERSION_STABLE="2022.11.0.0"
RUNTIME_VERSION_BETA="2022.1100.0.0"
RUNTIME_VERSION_RED="9.9.1.293"

# SDK version v1.55
SDK_HASH_WIN="AB5FA25FD06BDEE37D08CF5E2F40FDAA297C509DD4CA6DCC3F9874DC7B3D3128"
SDK_HASH_OSX="F49906EC86F4BDCE3B77BC5F93A7B3D8C7EDD221566D3B600D8B61B4E9CB0177"
SDK_HASH_LINUX="F20295DCA422050297E138ED823046E7D00135164F95FBD2DF7A0737BAE8E4DC"

# ######################################################################################
# Script Functions

setupmacOS() {

    SDK_SOURCE="$SDK_PATH/Bin/libEOSSDK-Mac-Shipping.dylib"
    assertFileHash $SDK_SOURCE $SDK_HASH_OSX "Epic Online Services SDK"

    echo "Copying macOS (64 bit) dependencies"
    if [[ "$YYTARGET_runtime" == "VM" ]]; then
        fileCopyTo $SDK_SOURCE "libEOSSDK-Mac-Shipping.dylib"
    else
        fileCopyTo $SDK_SOURCE "${YYprojectName}/${YYprojectName}/Supporting Files/libEOSSDK-Mac-Shipping.dylib"
    fi
}

setupLinux() {

    SDK_SOURCE="$SDK_PATH/Bin/libEOSSDK-Linux-Shipping.so"
    assertFileHash $SDK_SOURCE $SDK_HASH_LINUX "Epic Online Services SDK"

    echo "Copying Linux (64 bit) dependencies"
    
    fileExtract "${YYprojectName}.zip" "_temp"
    [[ ! -f "_temp/assets/libEOSSDK-Linux-Shipping.so" ]] && fileCopyTo $SDK_SOURCE "_temp/assets/libEOSSDK-Linux-Shipping.so"

    [[ ! -z ${DEBUG_MODE+x} ]] && echo "Running $YYTARGET_runtime Linux Steamworks project via IDE, enabling Debug..."
	
    folderCompress "_temp" "${YYprojectName}.zip"
    rm -r _temp
}

# ######################################################################################
# Script Logic

# Checks IDE and Runtime versions
checkMinVersion "$YYruntimeVersion" $RUNTIME_VERSION_STABLE $RUNTIME_VERSION_BETA $RUNTIME_VERSION_RED runtime

# Resolve the SDK path (must exist)
SDK_PATH=$YYEXTOPT_EpicOnlineServices_sdkPath
pathResolveExisting "$YYprojectDir" "$SDK_PATH" SDK_PATH

# Ensure we are on the output path
pushd "$YYoutputFolder" >/dev/null

# Call setup method depending on the platform
# NOTE: the setup method can be (:setupmacOS or :setupLinux)
setup$YYPLATFORM_name

popd >/dev/null

exit 0
