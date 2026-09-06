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

:: SDK integrity (extension options). The desktop libs are staged straight out of the folder the
:: sdkPath option points at, so a wrong or truncated download otherwise produces a game that builds
:: and then fails to load its native library with no diagnostic at all.
call %Utils% optionGetValue "sdkVersion"   SDK_VERSION
call %Utils% optionGetValue "sdkHashWin"   SDK_HASH_WIN
call %Utils% optionGetValue "sdkHashMac"   SDK_HASH_MAC
call %Utils% optionGetValue "sdkHashLinux" SDK_HASH_LINUX

set "ERROR_SDK_HASH=Invalid EOS SDK version, sha256 hash mismatch (expected v%SDK_VERSION%)."

:: Ensure we are on the output path
:: NOTE: GMRT (the new runner) expects the dependencies inside the 'build\assets' folder
if "%YYTARGET_runtime%" == "GMRT" (
    pushd "%YYoutputFolder%\build\assets"
) else (
    pushd "%YYoutputFolder%"
)

:: Call setup method depending on the platform
:: NOTE: the setup method can be (:setupWindows, :setupMacOS, :setupMac [GMRT], :setupLinux,
:: :setupAndroid or :setupiOS). Every label the .sh counterpart defines exists here too, even
:: when the body is empty - cmd treats a missing :setup<platform> as non-fatal, so a gap in the
:: label set turns into a confusing "cannot find the batch label" instead of a clean no-op.
call :setup%YYPLATFORM_name%

:: Capture the dispatch result before anything else can reset it, so whatever is added between
:: here and the exit below cannot mask it.
set "SETUP_RESULT=%ERRORLEVEL%"

popd

exit %SETUP_RESULT%

:: ----------------------------------------------------------------------------------------------------
:setupWindows
    :: Stage the EOS runtime DLL next to the game executable (in the output).
    :: It is git-ignored and never committed; it ships only in the build output.
    call %Utils% pathResolveExisting "%YYprojectDir%" "%SDK_PATH_C%" SDK_PATH
    call %Utils% assertFileHashEquals "%SDK_PATH%\Bin\EOSSDK-Win64-Shipping.dll" %SDK_HASH_WIN% "%ERROR_SDK_HASH%"
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
    call %Utils% assertFileHashEquals "%SDK_PATH%\Bin\libEOSSDK-Mac-Shipping.dylib" %SDK_HASH_MAC% "%ERROR_SDK_HASH%"

    echo Staging EOS macOS dependency (libEOSSDK-Mac-Shipping.dylib)

    if "%YYTARGET_runtime%" == "VM" (
        call %Utils% logError "Extension is not compatible with the macOS VM export from a Windows host (no codesign available); use YYC, or build from a macOS host."
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
    call %Utils% assertFileHashEquals "%SDK_PATH%\Bin\libEOSSDK-Linux-Shipping.so" %SDK_HASH_LINUX% "%ERROR_SDK_HASH%"

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
    :: script ever runs. The label must stay: without it the dispatch above fails with
    :: "cannot find the batch label" and takes the whole build down for nothing.
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupiOS
    :: Nothing to do here. pre_build_step.bat stages EOSSDK.zip into
    :: iOSSourceFromMac before the asset compiler reads it, and remote_build_step.sh
    :: strips its signature on the Mac afterwards.
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:: GMRT (the new runner) variant of the macOS setup. Under GMRT the platform name is 'Mac' (legacy is
:: 'macOS', which dispatches to :setupMacOS above) and the dependency goes bare into the output
:: 'build\assets' folder the top-level pushd already entered. No code signing here - codesign only
:: exists on a macOS host, where post_build_step.sh's setupMac() handles it.
:setupMac
    call %Utils% pathResolveExisting "%YYprojectDir%" "%SDK_PATH_C%" SDK_PATH
    call %Utils% assertFileHashEquals "%SDK_PATH%\Bin\libEOSSDK-Mac-Shipping.dylib" %SDK_HASH_MAC% "%ERROR_SDK_HASH%"
    echo Staging EOS macOS dependency (libEOSSDK-Mac-Shipping.dylib) (GMRT)
    call %Utils% itemCopyTo "%SDK_PATH%\Bin\libEOSSDK-Mac-Shipping.dylib" "libEOSSDK-Mac-Shipping.dylib"
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setuptvOS
    :: No tvOS EOS SDK is vendored, so there is nothing to stage.
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupXbox
    :: No console EOS SDK is vendored, so there is nothing to stage.
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupPlaystation
    :: No console EOS SDK is vendored, so there is nothing to stage.
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupSwitch
    :: No console EOS SDK is vendored, so there is nothing to stage.
exit /b 0
