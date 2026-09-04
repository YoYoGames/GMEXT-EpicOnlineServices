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
:: NOTE: GMRT (the new runner) expects the dependencies inside the 'build\assets' folder
if "%YYTARGET_runtime%" == "GMRT" (
    pushd "%YYoutputFolder%\build\assets"
) else (
    pushd "%YYoutputFolder%"
)

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
    :: Stage the EOS macOS dylib into the YYC Xcode-project-style output that
    :: GameMaker assembles locally even when the export target is macOS (the
    :: remote Mac build host only does the final Xcode compile/sign). Mirrors
    :: GMEXT-Steamworks/GMEXT-Discord's post_build_step.bat pattern.
    call %Utils% pathResolveExisting "%YYprojectDir%" "%SDK_PATH_C%" SDK_PATH

    echo Staging EOS macOS dependency (libEOSSDK-Mac-Shipping.dylib)

    if "%YYTARGET_runtime%" == "VM" (
        call %Utils% logError "Extension is not compatible with the macOS VM export, please use YYC."
    ) else (
        setlocal enabledelayedexpansion

        :: When running from CI the 'YYprojectName' will not be set; use 'YYprojectPath' instead.
        if "%YYprojectName%"=="" (
            for %%A in ("%YYprojectPath%") do set "YYprojectName=%%~nA"
        )
        :: Replace spaces with underscores (this matches the assetcompiler output)
        set YYfixedProjectName=!YYprojectName: =_!

        call %Utils% itemCopyTo "%SDK_PATH%\Bin\libEOSSDK-Mac-Shipping.dylib" "!YYfixedProjectName!\!YYfixedProjectName!\Supporting Files\libEOSSDK-Mac-Shipping.dylib"
        endlocal
    )
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupLinux
    :: Inject the EOS Linux .so into the game zip. GameMaker performs this
    :: packaging step locally on Windows even when the export target is
    :: Linux (no remote Linux host is used). Mirrors GMEXT-Steamworks/
    :: GMEXT-Discord's post_build_step.bat pattern.
    call %Utils% pathResolveExisting "%YYprojectDir%" "%SDK_PATH_C%" SDK_PATH

    setlocal enabledelayedexpansion

    :: When running from CI the 'YYprojectName' will not be set; use 'YYprojectPath' instead.
    if "%YYprojectName%"=="" (
        for %%A in ("%YYprojectPath%") do set "YYprojectName=%%~nA"
    )

    set "TEMP_FOLDER=!YYprojectName!___temp___"
    echo Staging EOS Linux dependency (libEOSSDK-Linux-Shipping.so)
    mkdir ".\!TEMP_FOLDER!"
    call %Utils% itemCopyTo "%SDK_PATH%\Bin\libEOSSDK-Linux-Shipping.so" "!TEMP_FOLDER!\assets\libEOSSDK-Linux-Shipping.so"
    call %Utils% zipUpdate "!TEMP_FOLDER!" "!YYprojectName!.zip"
    rmdir /s /q "!TEMP_FOLDER!"

    endlocal
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupAndroid
    :: Nothing to do here. The AAR is staged in pre_build_step, because the asset
    :: compiler copies AndroidSource\libs-aar into the Gradle project before this
    :: script ever runs. The label must stay: a missing :setup<platform> label is
    :: a silent failure that still reports a successful build.
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupiOS
    :: Nothing to do here. pre_build_step.bat stages EOSSDK.zip into
    :: iOSSourceFromMac before the asset compiler reads it, and remote_build_step.sh
    :: strips its signature on the Mac afterwards.
exit /b 0
