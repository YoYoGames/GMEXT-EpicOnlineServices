@echo off
set Utils="%~dp0\scriptUtils.bat"

:: ######################################################################################
:: Script Logic

:: Always init the script
call %Utils% scriptInit

:: Version locks
call %Utils% optionGetValue "versionStable" RUNTIME_VERSION_STABLE
call %Utils% optionGetValue "versionBeta" RUNTIME_VERSION_BETA
call %Utils% optionGetValue "versionDev" RUNTIME_VERSION_DEV
call %Utils% optionGetValue "versionLTS" RUNTIME_VERSION_LTS

:: SDK Hash
call %Utils% optionGetValue "sdkHashWin" SDK_HASH_WIN
call %Utils% optionGetValue "sdkHashMac" SDK_HASH_OSX
call %Utils% optionGetValue "sdkHashLinux" SDK_HASH_LINUX

:: SDK Path
call %Utils% optionGetValue "sdkPath" SDK_PATH
call %Utils% optionGetValue "sdkVersion" SDK_VERSION

:: Debug Mode
call %Utils% optionGetValue "debug" DEBUG_MODE

:: Error String
set ERROR_SDK_HASH="Invalid EpicOnlineSerices SDK version, sha256 hash mismatch (expected v%SDK_VERSION%)."

:: Checks IDE and Runtime versions
call %Utils% versionLockCheck "%YYruntimeVersion%" %RUNTIME_VERSION_STABLE% %RUNTIME_VERSION_BETA% %RUNTIME_VERSION_DEV% %RUNTIME_VERSION_LTS%

:: Resolve the SDK path (must exist)
call %Utils% pathResolveExisting "%YYprojectDir%" "%SDK_PATH%" SDK_PATH

:: Ensure we are on the output path
pushd "%YYoutputFolder%"

:: Call setup method depending on the platform
:: NOTE: the setup method can be (:setupWindows, :setupMacOS or :setupLinux)
call :setup%YYPLATFORM_name%

:: If debug is set to 'Enabled' provide a warning to the user.
if "%DEBUG_MODE%" equ "Enabled" call %Utils% logWarning "Debug mode is set to 'Enabled', make sure to set it to 'Auto' before publishing."


popd

exit %errorlevel%

:: ----------------------------------------------------------------------------------------------------
:setupWindows
   set SDK_SOURCE="%SDK_PATH%\Bin\EOSSDK-Win64-Shipping.dll"
   set XAUDIO_SOURCE="%SDK_PATH%\Bin\x64\xaudio2_9redist.dll"
   call %Utils% assertFileHashEquals %SDK_SOURCE% %SDK_HASH_WIN% %ERROR_SDK_HASH%

   echo "Copying Windows (64 bit) dependencies"
   if not exist "EOSSDK-Win64-Shipping.dll" call %Utils% itemCopyTo %SDK_SOURCE% "EOSSDK-Win64-Shipping.dll"
   if not exist "xaudio2_9redist.dll" call %Utils% itemCopyTo %XAUDIO_SOURCE% "xaudio2_9redist.dll"
   
exit /b %errorlevel%

:: ----------------------------------------------------------------------------------------------------
:setupmacOS

   set SDK_SOURCE="%SDK_PATH%\Bin\libEOSSDK-Mac-Shipping.dylib"
   call %Utils% assertFileHashEquals %SDK_SOURCE% %SDK_HASH_OSX% %ERROR_SDK_HASH%

   echo "Copying macOS (64 bit) dependencies"

   if "%YYTARGET_runtime%" == "VM" (
      :: This is used for VM compilation
      call %Utils% logError "Extension is not compatible with the macOS VM export, please use YYC."
   ) else (
      setlocal enabledelayedexpansion

      :: When running from CI the 'YYprojectName' will not be set use 'YYprojectPath' instead.
      if "%YYprojectName%"=="" (
         for %%A in ("%YYprojectPath%") do set "YYprojectName=%%~nA"
      )
      :: Replace spaces with underscores (this matches the assetcompiler output)
      set YYfixedProjectName=!YYprojectName: =_!

      :: This is used for YYC compilation
      call %Utils% itemCopyTo %SDK_SOURCE% "!YYfixedProjectName!\!YYfixedProjectName!\Supporting Files\libEOSSDK-Mac-Shipping.dylib"
      endlocal
   )
exit /b %errorlevel%

:: ----------------------------------------------------------------------------------------------------
:setupLinux

   set SDK_SOURCE="%SDK_PATH%\Bin\libEOSSDK-Linux-Shipping.so"
   call %Utils% assertFileHashEquals %SDK_SOURCE% %SDK_HASH_LINUX% %ERROR_SDK_HASH%

   echo "Copying Linux (64 bit) dependencies"

   setlocal enabledelayedexpansion

   :: When running from CI the 'YYprojectName' will not be set use 'YYprojectPath' instead.
   if "%YYprojectName%"=="" (
      for %%A in ("%YYprojectPath%") do set "YYprojectName=%%~nA"
   )

   :: Update the zip file with the required SDKs
   mkdir _temp\assets
   call %Utils% itemCopyTo %SDK_SOURCE% "_temp\assets\libEOSSDK-Linux-Shipping.so"
   call %Utils% zipUpdate "_temp" "!YYprojectName!.zip"
   rmdir /s /q _temp

   endlocal

exit /b %errorlevel%

