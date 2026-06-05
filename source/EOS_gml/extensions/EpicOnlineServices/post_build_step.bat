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
    :: Stage the EOS runtime DLL next to the game executable (in the output).
    :: It is git-ignored and never committed; it ships only in the build output.
    call %Utils% pathResolveExisting "%YYprojectDir%" "%SDK_PATH_C%" SDK_PATH
    echo Staging EOS Windows dependency (EOSSDK-Win64-Shipping.dll)
    call %Utils% itemCopyTo "%SDK_PATH%\Bin\EOSSDK-Win64-Shipping.dll" "EOSSDK-Win64-Shipping.dll"
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupMacOS
    :: macOS builds run on a Mac host (post_build_step.sh handles them)
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupLinux
    :: Linux builds run on a Linux host (post_build_step.sh handles them)
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupAndroid
    :: NOTE: do NOT delete the staged AndroidSource/libs binaries here -- GameMaker's
    :: Gradle packaging runs AFTER post_build_step, so they must still be present.
    :: pre_build_step removes stale copies at the start of the next build instead.
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupiOS
    :: TODO (unverified on a Mac): see pre_build_step.bat :setupiOS
exit /b 0
