@echo off

set Utils="%~dp0\scriptUtils.bat"

:: ######################################################################################
:: Macros

call %Utils% pathExtractDirectory "%~0" SCRIPT_PATH
call %Utils% pathExtractBase "%~0" EXTENSION_NAME
call %Utils% toUpper "%EXTENSION_NAME%" EXTENSION_NAME

:: ######################################################################################
:: Script Logic

:: Version locks
set RUNTIME_VERSION_STABLE="2022.11.0.0"
set RUNTIME_VERSION_BETA="2022.1100.0.0"
set RUNTIME_VERSION_DEV="9.9.1.293"

:: SDK version v1.55
set SDK_HASH_WIN="1DB3FD414039D3E5815A5721925DD2E0A3A9F2549603C6CAB7C49B84966A1AF3"
set SDK_HASH_OSX="88DC79403F68E81B6674C927ED362EF3CF69046F587ED009FDC6AD85D85E97F2"
set SDK_HASH_LINUX="C0CC3D2802E5F2463BFA0046C41D2F65A6335BAAEEFBBA6C7DBD5681D5CA7C46"

:: Checks IDE and Runtime versions
call %Utils% checkMinVersion "%YYruntimeVersion%" %RUNTIME_VERSION_STABLE% %RUNTIME_VERSION_BETA% %RUNTIME_VERSION_DEV% runtime

:: ############################################## WARNING ##############################################
::       THIS FILE IS SHOULD NOT BE CHANGED AND THE OPTIONS SHOULD BE CONTROLLED THROUGH THE IDE.
:: #####################################################################################################

:: Resolve the SDK path (must exist)
set SDK_PATH=%YYEXTOPT_EpicOnlineServices_sdkPath%
call %Utils% pathResolveExisting "%YYprojectDir%" "%SDK_PATH%" SDK_PATH

:: Ensure we are on the output path
pushd "%YYoutputFolder%"

:: Call setup method depending on the platform
:: NOTE: the setup method can be (:setupWindows, setupMacOS or setupLinux)
call :setup%YYPLATFORM_name%
if ERRORLEVEL 1 (
    call %Utils% logInformation "EOS Extension is not available in this target: %YYPLATFORM_name% (no setup required)"
)
popd

exit %ERRORLEVEL%

:: ----------------------------------------------------------------------------------------------------
:setupWindows
   set SDK_SOURCE="%SDK_PATH%\Bin\EOSSDK-Win64-Shipping.dll"
   call %Utils% assertFileHash %SDK_SOURCE% %SDK_HASH_WIN% "Epic Online Services SDK"

   echo "Copying Windows (64 bit) dependencies"
   if not exist "EOSSDK-Win64-Shipping.dll" call %Utils% fileCopyTo %SDK_SOURCE% "EOSSDK-Win64-Shipping.dll"
goto :eof

:: ----------------------------------------------------------------------------------------------------
:setupmacOS

   set SDK_SOURCE="%SDK_PATH%\Bin\libEOSSDK-Mac-Shipping.dylib"
   call %Utils% assertFileHash %SDK_SOURCE% %SDK_HASH_OSX% "Epic Online Services SDK"

   echo "Copying macOS (64 bit) dependencies"
   if "%YYTARGET_runtime%" == "VM" (
      :: This is used from VM compilation
      call %Utils% fileExtract "%YYprojectName%.zip" "_temp\"
      call %Utils% fileCopyTo %SDK_SOURCE% "_temp\assets\libEOSSDK-Mac-Shipping.dylib"
      call %Utils% folderCompress "_temp\*" "%YYprojectName%.zip"

      rmdir /s /q _temp

   ) else (

      :: This is used from YYC compilation
      call %Utils% fileCopyTo %SDK_SOURCE% "%YYprojectName%\%YYprojectName%\Supporting Files\libEOSSDK-Mac-Shipping.dylib"
   )

goto :eof

:: ----------------------------------------------------------------------------------------------------
:Linux_copy_dependencies

   set SDK_SOURCE="%SDK_PATH%\Bin\libEOSSDK-Linux-Shipping.so"
   call %Utils% assertFileHash %SDK_SOURCE% %SDK_HASH_LINUX% "Epic Online Services SDK"

   echo "Copying Linux (64 bit) dependencies"

   call %Utils% fileExtract "%YYprojectName%.zip" "_temp\"
   if not exist "assets\libEOSSDK-Linux-Shipping.so" (
      call %Utils% fileCopyTo %SDK_SOURCE% "_temp\assets\libEOSSDK-Linux-Shipping.so"
      call %Utils% folderCompress "_temp\*" "%YYprojectName%.zip"
   )

   rmdir /s /q _temp

goto :eof

