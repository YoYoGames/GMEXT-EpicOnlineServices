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
    :: Windows can't run the macOS-only framework tooling (ditto/codesign), so it
    :: only stages the RAW EOSSDK.xcframework into iOSSourceFromMac. The Mac build
    :: host then strips the signature and zips it in remote_build_step.sh. (Same
    :: split the Discord extension uses: raw libs staged on Windows, processed on
    :: the Mac in remote_build_step.)
    call %Utils% pathResolveExisting "%YYprojectDir%" "%SDK_PATH_IOS%" SDK_PATH

    :: Locate the xcframework anywhere under the SDK (layout varies by download).
    set "EOS_XCFW="
    for /f "delims=" %%F in ('dir /s /b /a:d "%SDK_PATH%\EOSSDK.xcframework" 2^>nul') do set "EOS_XCFW=%%F"
    if not defined EOS_XCFW call %Utils% logError "EOSSDK.xcframework not found under '%SDK_PATH%' (check the sdkIosPath option)."

    set "IOS_DIR=%EXTENSION_DIR%iOSSourceFromMac"

    :: Clean any stale staged copies, then stage the raw framework for transfer.
    if exist "%IOS_DIR%\EOSSDK.xcframework" rmdir /s /q "%IOS_DIR%\EOSSDK.xcframework"
    if exist "%IOS_DIR%\EOSSDK.zip" del /q "%IOS_DIR%\EOSSDK.zip"
    echo Staging RAW EOS iOS xcframework (processed on the Mac by remote_build_step.sh)
    call %Utils% itemCopyTo "%EOS_XCFW%" "%IOS_DIR%\EOSSDK.xcframework"
exit /b 0
