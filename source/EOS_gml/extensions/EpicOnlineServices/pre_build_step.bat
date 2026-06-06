@echo off
set Utils="%~dp0scriptUtils.bat"
set "EXTENSION_DIR=%~dp0"

:: ######################################################################################
:: Script Logic

:: Always init the script
call %Utils% scriptInit

:: SDK paths (extension options)
call %Utils% optionGetValue "sdkPath"        SDK_PATH_C
call %Utils% optionGetValue "sdkAndroidPath" SDK_PATH_ANDROID
call %Utils% optionGetValue "sdkIosPath"     SDK_PATH_IOS

:: Ensure we are on the output path
pushd "%YYoutputFolder%"

:: Call setup method depending on the platform
call :setup%YYPLATFORM_name%

popd

exit %ERRORLEVEL%

:: ----------------------------------------------------------------------------------------------------
:setupWindows
    :: EOS runtime DLL is staged into the output by post_build_step
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupMacOS
    :: Desktop runtime lib is staged into the output by post_build_step
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupLinux
    :: Desktop runtime lib is staged into the output by post_build_step
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupAndroid
    :: Stage the EOS SDK's Java classes + per-ABI native lib (extracted from the
    :: Android SDK's AAR) into AndroidSource/libs so GameMaker's Gradle build
    :: packages them. These are git-ignored; the extension's own
    :: libEpicOnlineServices.so stays committed alongside them.
    call %Utils% pathResolveExisting "%YYprojectDir%" "%SDK_PATH_ANDROID%" SDK_PATH

    set "EOS_AAR=%SDK_PATH%\SDK\Bin\Android\static-stdc++\aar\eossdk-StaticSTDC-release.aar"
    set "LIBS_DIR=%EXTENSION_DIR%AndroidSource\libs"
    set "TMP_DIR=%EXTENSION_DIR%_eos_aar_tmp"

    :: Clean any stale staged SDK binaries from a previous build
    call %Utils% itemDelete "%LIBS_DIR%\EOSSDK.jar"
    call %Utils% itemDelete "%LIBS_DIR%\arm64-v8a\libEOSSDK.so"
    call %Utils% itemDelete "%LIBS_DIR%\x86_64\libEOSSDK.so"
    :: NB: itemDelete only removes files, so use rmdir for the temp directory
    if exist "%TMP_DIR%" rmdir /s /q "%TMP_DIR%"

    :: Expand-Archive needs a .zip name, so copy the AAR to a temp .zip first
    call %Utils% itemCopyTo "%EOS_AAR%" "%TMP_DIR%\eos.zip"
    call %Utils% fileExtract "%TMP_DIR%\eos.zip" "%TMP_DIR%\eos"

    :: Java classes (architecture-independent)
    call %Utils% itemCopyTo "%TMP_DIR%\eos\classes.jar" "%LIBS_DIR%\EOSSDK.jar"

    :: Per-ABI native lib (the EOS AAR ships arm64-v8a and x86_64 only)
    if "%YYPLATFORM_option_android_arch_arm64%"=="True" (
        echo Staging EOS Android dependencies (arm64-v8a)
        call %Utils% itemCopyTo "%TMP_DIR%\eos\jni\arm64-v8a\libEOSSDK.so" "%LIBS_DIR%\arm64-v8a\libEOSSDK.so"
    )
    if "%YYPLATFORM_option_android_arch_x86_64%"=="True" (
        echo Staging EOS Android dependencies (x86_64)
        call %Utils% itemCopyTo "%TMP_DIR%\eos\jni\x86_64\libEOSSDK.so" "%LIBS_DIR%\x86_64\libEOSSDK.so"
    )

    if exist "%TMP_DIR%" rmdir /s /q "%TMP_DIR%"
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupiOS
    :: iOS frameworks must be zipped on macOS (ditto) to preserve symlinks and the
    :: code signature -- a Windows/Linux zip would break them. EOS iOS staging is
    :: therefore handled by pre_build_step.sh on the Mac build host; nothing to do
    :: from a Windows host.
exit /b 0
