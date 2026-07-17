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
    :: Stage the EOS SDK's Android AAR as a whole into AndroidSource/libs-aar/ so
    :: GameMaker's Gradle build consumes it directly (classes.jar + per-ABI
    :: libEOSSDK.so extracted automatically) via the "implementation files(...)"
    :: dependency declared in EpicOnlineServices.yy. Git-ignored; mirrors
    :: GMEXT-Discord's post_build_step.bat pattern.
    call %Utils% pathResolveExisting "%YYprojectDir%" "%SDK_PATH_ANDROID%" SDK_PATH

    set "EOS_AAR=%SDK_PATH%\SDK\Bin\Android\static-stdc++\aar\eossdk-StaticSTDC-release.aar"

    echo Staging EOS Android dependency (eossdk-StaticSTDC-release.aar)
    if not exist "%EXTENSION_DIR%AndroidSource\libs-aar" mkdir "%EXTENSION_DIR%AndroidSource\libs-aar"
    call %Utils% itemCopyTo "%EOS_AAR%" "%EXTENSION_DIR%AndroidSource\libs-aar\eossdk-StaticSTDC-release.aar"
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupiOS
    :: TODO (unverified on a Mac): see pre_build_step.bat :setupiOS
exit /b 0
