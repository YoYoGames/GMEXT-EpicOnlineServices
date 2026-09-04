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
    :: Stage the EOS SDK's Android AAR as a whole into AndroidSource/libs-aar/ so
    :: GameMaker's Gradle build consumes it directly (classes.jar + per-ABI
    :: libEOSSDK.so extracted automatically) via the "implementation files(...)"
    :: dependency declared in EpicOnlineServices.yy. Git-ignored.
    ::
    :: This MUST be a pre_build_step: the asset compiler copies the whole
    :: AndroidSource\libs-aar folder into the Gradle project itself, and it runs
    :: between pre_build_step and post_build_step. Staged from post_build_step
    :: the AAR is always one build behind, so a clean checkout's first Android
    :: build has no EOS SDK in it at all.
    call %Utils% pathResolveExisting "%YYprojectDir%" "%SDK_PATH_ANDROID%" SDK_PATH

    set "EOS_AAR=%SDK_PATH%\SDK\Bin\Android\static-stdc++\aar\eossdk-StaticSTDC-release.aar"

    echo Staging EOS Android dependency (eossdk-StaticSTDC-release.aar)
    if not exist "%EXTENSION_DIR%AndroidSource\libs-aar" mkdir "%EXTENSION_DIR%AndroidSource\libs-aar"
    call %Utils% itemCopyTo "%EOS_AAR%" "%EXTENSION_DIR%AndroidSource\libs-aar\eossdk-StaticSTDC-release.aar"
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupiOS
    :: Stage the EOS SDK's xcframework as iOSSourceFromMac\EOSSDK.zip. The asset
    :: compiler only ever picks up *.zip from iOSSourceFromMac - a raw folder there
    :: is silently ignored - and it copies each zip to the Mac and unzips it into
    :: <project>FromPC/Fw/. So the zip is the only way the framework reaches the
    :: build at all.
    ::
    :: Windows can't run the macOS-only tooling (ditto/codesign), so the vendor
    :: code signature is left intact here and stripped on the Mac afterwards by
    :: remote_build_step.sh, which finds the framework already unzipped in Fw/.
    call %Utils% pathResolveExisting "%YYprojectDir%" "%SDK_PATH_IOS%" SDK_PATH

    :: Locate the xcframework anywhere under the SDK (layout varies by download).
    set "EOS_XCFW="
    for /f "delims=" %%F in ('dir /s /b /a:d "%SDK_PATH%\EOSSDK.xcframework" 2^>nul') do set "EOS_XCFW=%%F"
    if not defined EOS_XCFW call %Utils% logError "EOSSDK.xcframework not found under '%SDK_PATH%' (check the sdkIosPath option)."

    set "IOS_DIR=%EXTENSION_DIR%iOSSourceFromMac"
    set "IOS_ZIP=%IOS_DIR%\EOSSDK.zip"
    set "IOS_TEMP=%IOS_DIR%\_eos_xcfw_tmp"

    :: Clear the previous staging so nothing stale is carried into the new zip.
    :: EOSSDK.xcframework is the raw folder older revisions of this script left
    :: behind; it is dead weight now and would be transferred by nothing.
    ::
    :: Folders use rmdir, not scriptUtils' itemDelete: itemDelete inspects
    :: 'dir /b /a:d <target>', which on a directory lists that directory's
    :: CONTENTS, so the name it is looking for never appears and it returns 0
    :: having deleted nothing. It is correct for files, which is why the zip
    :: below still goes through it.
    if exist "%IOS_DIR%\EOSSDK.xcframework" rmdir /s /q "%IOS_DIR%\EOSSDK.xcframework"
    if exist "%IOS_TEMP%" rmdir /s /q "%IOS_TEMP%"
    call %Utils% itemDelete "%IOS_ZIP%"

    :: folderCompress zips the CONTENTS of the folder it is given, so the
    :: xcframework goes under a temp parent to get EOSSDK.xcframework/ as the
    :: zip's top-level entry - which is what unzipping into Fw/ has to produce.
    echo Staging EOS iOS dependency into EOSSDK.zip from "%EOS_XCFW%"
    if not exist "%IOS_DIR%" mkdir "%IOS_DIR%"
    mkdir "%IOS_TEMP%"
    call %Utils% itemCopyTo "%EOS_XCFW%" "%IOS_TEMP%\EOSSDK.xcframework"
    call %Utils% folderCompress "%IOS_TEMP%" "%IOS_ZIP%"
    if exist "%IOS_TEMP%" rmdir /s /q "%IOS_TEMP%"
exit /b 0
