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
   call %Utils% assertFileHashEquals %SDK_SOURCE% %SDK_HASH_WIN% %ERROR_SDK_HASH%

   echo "Copying Windows (64 bit) dependencies"
   if not exist "EOSSDK-Win64-Shipping.dll" call %Utils% itemCopyTo %SDK_SOURCE% "EOSSDK-Win64-Shipping.dll"
   
exit /b %errorlevel%

:: ----------------------------------------------------------------------------------------------------
:setupmacOS

   set SDK_SOURCE="%SDK_PATH%\Bin\libEOSSDK-Mac-Shipping.dylib"
   call %Utils% assertFileHashEquals %SDK_SOURCE% %SDK_HASH_OSX% %ERROR_SDK_HASH%

   echo "Copying macOS (64 bit) dependencies"
   if "%YYTARGET_runtime%" == "VM" (
      :: This is used from VM compilation
      call %Utils% logError "Extension is not compatible with the macOS VM export, please use YYC."
   ) else (
      :: This is used from YYC compilation
      call %Utils% itemCopyTo %SDK_SOURCE% "%YYprojectName%\%YYprojectName%\Supporting Files\libEOSSDK-Mac-Shipping.dylib"
   )

exit /b %errorlevel%

:: ----------------------------------------------------------------------------------------------------
:setupLinux

   set SDK_SOURCE="%SDK_PATH%\Bin\libEOSSDK-Linux-Shipping.so"
   call %Utils% assertFileHashEquals %SDK_SOURCE% %SDK_HASH_LINUX% %ERROR_SDK_HASH%

   echo "Copying Linux (64 bit) dependencies"

   call %Utils% fileExtract "%YYprojectName%.zip" "_temp\"
   if not exist "assets\libEOSSDK-Linux-Shipping.so" (
      call %Utils% itemCopyTo %SDK_SOURCE% "_temp\assets\libEOSSDK-Linux-Shipping.so"
      call %Utils% folderCompress "_temp" "%YYprojectName%.zip"
   )
   rmdir /s /q _temp

exit /b %errorlevel%

