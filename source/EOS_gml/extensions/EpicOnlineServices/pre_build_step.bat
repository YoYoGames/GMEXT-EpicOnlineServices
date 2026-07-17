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
    :: Nothing to do here (handled in post_build_step)
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
