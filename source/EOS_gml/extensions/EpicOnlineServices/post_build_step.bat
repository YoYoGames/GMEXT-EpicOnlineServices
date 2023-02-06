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
set SDK_HASH_WIN="AB5FA25FD06BDEE37D08CF5E2F40FDAA297C509DD4CA6DCC3F9874DC7B3D3128"
set SDK_HASH_OSX="F49906EC86F4BDCE3B77BC5F93A7B3D8C7EDD221566D3B600D8B61B4E9CB0177"
set SDK_HASH_LINUX="F20295DCA422050297E138ED823046E7D00135164F95FBD2DF7A0737BAE8E4DC"

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

