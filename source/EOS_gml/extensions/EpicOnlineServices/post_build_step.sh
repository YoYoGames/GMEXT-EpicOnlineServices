#!/bin/bash
set echo off

# Useful for printing all variables
# ( set -o posix ; set ) | less

# ############################################## WARNING ##############################################
#      THIS FILE IS SHOULD NOT BE CHANGED AND THE OPTIONS SHOULD BE CONTROLLED THROUGH THE IDE.
# #####################################################################################################

function error_incorrect_EOS_path () {
    echo ""
    echo "################################################# ERROR #################################################"
    echo "The specified EOS SDK path doesn't exist please edit the extension options from the IDE extension window."
    echo "#########################################################################################################"
    echo ""
    exit 1
}

function error_macOS_VM_EOS_run () {
    echo ""
    echo "######################################################## ERROR ########################################################"
    echo "This version of EOS extension is not compatible with the macOS VM export, please use the YYC export instead"
    echo "#######################################################################################################################"
    echo ""
    exit 1
}

function macOS_copy_dependencies () {

    echo "Copying macOS (64 bit) dependencies"
    if [[ "$YYTARGET_runtime" == "VM" ]]; then
        error_macOS_VM_EOS_run
    else
        cp "${EOS_SDK_PATH}Bin/libEOSSDK-Mac-Shipping.dylib" "${YYprojectName}/${YYprojectName}/Supporting Files/libEOSSDK-Mac-Shipping.dylib"
    fi
}

function Linux_copy_dependencies () {

    echo "Copying Linux (64 bit) dependencies"
    unzip ${YYprojectName}.zip -d ./_temp

    if [[ ! -f "_temp/assets/libEOSSDK-Linux-Shipping.so" ]]; then
        cp "${EOS_SDK_PATH}Bin/libEOSSDK-Linux-Shipping.so" "_temp/assets/libEOSSDK-Linux-Shipping.so"
        cd _temp; zip -FS -r ../${YYprojectName}.zip *
        cd ..
    fi
    rm -r _temp
}

# Read extension options or use default (development) value
if [[ "${YYEXTOPT_EpicOnlineServices_sdkPath}" == "" ]]; then
    EOS_SDK_PATH=$(dirname "$0")/../../../EOS_sdk
    EOS_SDK_PATH=$(builtin cd "$EOS_SDK_PATH"; pwd)
else
    EOS_SDK_PATH=${YYEXTOPT_EpicOnlineServices_sdkPath}
fi

# Ensure the provided path ends with a slash
if [[ "$EOS_SDK_PATH" !=  */ ]]; then
    EOS_SDK_PATH=${EOS_SDK_PATH}/
fi

# Ensure the path exists
if [[ ! -d "$EOS_SDK_PATH" ]]; then
    error_incorrect_EOS_path
fi

# Ensure we are on the output path
pushd "$YYoutputFolder" 1>/dev/null

# Call setup method depending on the platform
# NOTE: the setup method can be (:MacOS_copy_dependencies or :Linux_copy_dependencies)
{ # try
    ${YYPLATFORM_name}_copy_dependencies 2>/dev/null
} || { # catch
    echo ""
    echo "################################### INFORMATION ###################################"
    echo "EOS Extension is not available in this target: $YYPLATFORM_name (no setup required)"
    echo "###################################################################################"
    echo ""
}

popd 1>/dev/null

# exit
exit 0
