
//Platform Interface
//Interface that grants access to all other interfaces.


//EOS_Platform_CheckForLauncherAndRestart
//EOS_Platform_GetActiveCountryCode
//EOS_Platform_GetActiveLocaleCode
//EOS_Platform_GetOverrideCountryCode
//EOS_Platform_GetOverrideLocaleCode
//EOS_Platform_Release
//EOS_Platform_SetOverrideCountryCode
//EOS_Platform_SetOverrideLocaleCode
//EOS_Platform_Tick

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include <string>
#include <iostream>

#include <filesystem>

#ifdef OS_Windows
#include <direct.h>
#endif

#if defined(OS_Linux) || defined(OS_MacOs)
#include <unistd.h>
#endif

#include "DesktopExtensionTools.h"

#if defined(OS_Linux) || defined(OS_MacOs)
extern "C" void PreGraphicsInitialisation(char* arg1) {};
#endif
#ifdef OS_Windows
extern "C" __declspec(dllexport) void PreGraphicsInitialisation(char* arg1) {};
#endif

	bool EOS_isInitialised = false;
	void OldPreGraphicsInitialisation()
	{
		tracef("Starting initialization...");

		std::string ProductId = extOptGetString("EpicOnlineServices", "ProductId");
		std::string SandboxId = extOptGetString("EpicOnlineServices", "SandboxId");
		std::string DeploymentId = extOptGetString("EpicOnlineServices", "DeploymentId");
		std::string ClientId = extOptGetString("EpicOnlineServices", "ClientCredentialsId");
		std::string ClientSecret = extOptGetString("EpicOnlineServices", "ClientCredentialsSecret");
		std::string EncryptionKey = extOptGetString("EpicOnlineServices", "EncryptionKey");
		std::string GameName = extOptGetString("EpicOnlineServices", "GameName");
		bool debug = ((std::string)extOptGetString("EpicOnlineServices", "Debug")).find("True") != std::string::npos;

		// Init EOS SDK
		EOS_InitializeOptions SDKOptions = {};
		SDKOptions.ApiVersion = EOS_INITIALIZE_API_LATEST;
		SDKOptions.AllocateMemoryFunction = nullptr;
		SDKOptions.ReallocateMemoryFunction = nullptr;
		SDKOptions.ReleaseMemoryFunction = nullptr;
		SDKOptions.ProductName = GameName.c_str();//SampleConstants::GameName;
		SDKOptions.ProductVersion = "1.0";
		SDKOptions.Reserved = nullptr;
		SDKOptions.SystemInitializeOptions = nullptr;
		SDKOptions.OverrideThreadAffinity = nullptr;

		EOS_EResult InitResult = EOS_Initialize(&SDKOptions);

		if (InitResult != EOS_EResult::EOS_Success)
		{
			tracef("EOS_Initialize :: Initialization Error (%x)", InitResult);
			return;
		}
		else
		{
			EOS_Platform_Options PlatformOptions = {};
			PlatformOptions.ApiVersion = EOS_PLATFORM_OPTIONS_API_LATEST;
			PlatformOptions.bIsServer = false;// FCommandLine::Get().HasFlagParam(CommandLineConstants::Server);
			PlatformOptions.OverrideCountryCode = nullptr;
			PlatformOptions.OverrideLocaleCode = nullptr;
			PlatformOptions.Flags = EOS_PF_WINDOWS_ENABLE_OVERLAY_D3D9 | EOS_PF_WINDOWS_ENABLE_OVERLAY_D3D10 | EOS_PF_WINDOWS_ENABLE_OVERLAY_OPENGL; // Enable overlay support for D3D9/10 and OpenGL. This sample uses D3D11 or SDL.
			//PlatformOptions.CacheDirectory = "C:/Users/chuyz/Desktop/Here/Here_";//"C:/Users/chuyz/AppData/Local/EpicOnlineServices";//"C:\\Users\\chuyz\\AppData\\Local\\Temp";// FUtils::GetTempDirectory();
			
	#ifdef OS_Windows
            char cwd[1000];
			if (_getcwd(cwd, sizeof(cwd)) != NULL) {
                PlatformOptions.CacheDirectory = cwd;
            }
	#endif
	#if defined(OS_Linux)
            
            std::filesystem::path cwd_ = std::filesystem::current_path();
            //PlatformOptions.CacheDirectory = cwd_.string().c_str();
    #endif
	#if defined(OS_MacOs)
			//NSString* bundlename = [[NSBundle mainBundle]executablePath];
			//std::filesystem::path exePath = [bundlename UTF8String];

			std::string localPath = DesktopExtensionTools_getPathToExe();
			std::filesystem::path exePath = localPath;
			
			exePath = exePath.parent_path();
			exePath = exePath.parent_path();
			exePath = exePath.append("Resources");

			//PlatformO	ptions.CacheDirectory = exePath.string().c_str();
			std::string str = exePath.string();
			PlatformOptions.CacheDirectory = str.c_str();
	#endif
                

			tracef("Current working dir: %s", PlatformOptions.CacheDirectory);
			
			PlatformOptions.EncryptionKey = EncryptionKey.c_str(); //SampleConstants::EncryptionKey;

			PlatformOptions.ProductId = ProductId.c_str();
			PlatformOptions.SandboxId = SandboxId.c_str();
			PlatformOptions.DeploymentId = DeploymentId.c_str();
			PlatformOptions.ClientCredentials.ClientId = ClientId.c_str();
			PlatformOptions.ClientCredentials.ClientSecret = ClientSecret.c_str();

			EOS_Platform_RTCOptions RtcOptions = { 0 };
			RtcOptions.ApiVersion = EOS_PLATFORM_RTCOPTIONS_API_LATEST;

			//PlatformOptions.RTCOptions = &RtcOptions;
			PlatformOptions.Reserved = NULL;

			PlatformHandle = EOS_Platform_Create(&PlatformOptions);

			//Result.kind = VALUE_BOOL;
			if (PlatformHandle == nullptr)
			{
				tracef("EOS_Platform_Create :: Platform creation error (check extension configuration)");
				return;
			}

			if (!debug)
				EOS_Platform_CheckForLauncherAndRestart(PlatformHandle);

			tracef("EOS_Achievements_Init :: Starting module...");
			EpicGames_Achievements_Init();
			tracef("EOS_Connect_Init :: Starting module...");
			EpicGames_Connect_Init();
			tracef("EOS_Friends_Init :: Starting module...");
			EpicGames_Friends_Init();
			tracef("EOS_Leaderboards_Init :: Starting module...");
			EpicGames_Leaderboards_Init();
			tracef("EOS_Metrics_Init :: Starting module...");
			EpicGames_Metrics_Init();

			tracef("EOS_PlayerDataStorage_Init :: Starting module...");
			EpicGames_PlayerDataStorage_Init();
			tracef("EOS_TitleStorage_Init :: Starting module...");
			EpicGames_TitleStorage_Init();
			tracef("EOS_UI_Init :: Starting module...");
			EpicGames_UI_Init();
			tracef("EOS_Stats_Init :: Starting module...");
			EpicGames_Stats_Init();
			tracef("EOS_UserInfo_Init :: Starting module...");
			EpicGames_UserInfo_Init();

			tracef("EOS_Presence_Init :: Starting module...");
			EpicGames_Presence_Init();
			tracef("EOS_ProgressionSnapshot_Init :: Starting module...");
			EpicGames_ProgressionSnapshot_Init();
			tracef("EOS_Reports_Init :: Starting module...");
			EpicGames_Reports_Init();
			tracef("EOS_Sanctions_Init :: Starting module...");
			EpicGames_Sanctions_Init();

			tracef("Initialization finished!");
			
			EOS_isInitialised = true;
			//Result.val = true;
		}
	}

	YYEXPORT void EpicGames_Platform_CheckForLauncherAndRestart(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		EOS_NotInitialisedReturn_BOOL

		EOS_Platform_CheckForLauncherAndRestart(PlatformHandle);

		Result.kind = VALUE_BOOL;
		Result.val = true;
	}

	YYEXPORT void EpicGames_Platform_GetActiveCountryCode(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		EOS_NotInitialisedReturn_STRING

		const char* user = YYGetString(arg, 0);

		char Buffer[EOS_COUNTRYCODE_MAX_LENGTH];
		int32_t BufferLen = sizeof(Buffer);
		if (EOS_Platform_GetActiveCountryCode(PlatformHandle, EOS_EpicAccountId_FromString(user), Buffer, &BufferLen) == EOS_EResult::EOS_Success)
			YYCreateString(&Result, Buffer);
		else
			YYCreateString(&Result, "");
	}

	YYEXPORT void EpicGames_Platform_GetActiveLocaleCode(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		EOS_NotInitialisedReturn_STRING

		const char* user = YYGetString(arg, 0);

		char Buffer[EOS_LOCALECODE_MAX_BUFFER_LEN];
		int32_t BufferLen = sizeof(Buffer);
		Result.kind = VALUE_STRING;
		if (EOS_Platform_GetActiveLocaleCode(PlatformHandle, EOS_EpicAccountId_FromString(user), Buffer, &BufferLen) == EOS_EResult::EOS_Success)
			YYCreateString(&Result, Buffer);
		else
			YYCreateString(&Result, "");
	}

	YYEXPORT void EpicGames_Platform_GetOverrideCountryCode(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		EOS_NotInitialisedReturn_STRING

		char Buffer[EOS_COUNTRYCODE_MAX_BUFFER_LEN];
		int32_t BufferLen = sizeof(Buffer);
		Result.kind = VALUE_STRING;
		if (EOS_Platform_GetOverrideCountryCode(PlatformHandle, Buffer, &BufferLen) == EOS_EResult::EOS_Success)
			YYCreateString(&Result, Buffer);
		else
			YYCreateString(&Result, "");
	}

	YYEXPORT void EpicGames_Platform_GetOverrideLocaleCode(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		EOS_NotInitialisedReturn_STRING

		char Buffer[EOS_LOCALECODE_MAX_BUFFER_LEN];
		int32_t BufferLen = sizeof(Buffer);
		Result.kind = VALUE_STRING;
		if (EOS_Platform_GetOverrideLocaleCode(PlatformHandle, Buffer, &BufferLen) == EOS_EResult::EOS_Success)
			YYCreateString(&Result, Buffer);
		else
			YYCreateString(&Result, "");
	}

	YYEXPORT void EpicGames_Platform_Release(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		EOS_NotInitialisedReturn_BOOL

		EOS_Platform_Release(PlatformHandle);

		Result.kind = VALUE_BOOL;
		Result.val = true;
	}

	YYEXPORT void EpicGames_Platform_SetOverrideCountryCode(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		EOS_NotInitialisedReturn_BOOL

		const char* countryCode = YYGetString(arg, 0);

		EOS_Platform_SetOverrideCountryCode(PlatformHandle, countryCode);

		Result.kind = VALUE_BOOL;
		Result.val = true;
	}


	YYEXPORT void EpicGames_Platform_SetOverrideLocaleCode(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		EOS_NotInitialisedReturn_BOOL

		const char* localCode = YYGetString(arg, 0);

		EOS_Platform_SetOverrideLocaleCode(PlatformHandle, localCode);

		Result.kind = VALUE_BOOL;
		Result.val = true;
	}

	YYEXPORT void EpicGames_Platform_Tick(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		EOS_NotInitialisedReturn_BOOL

		Result.kind = VALUE_BOOL;

		if (PlatformHandle != NULL)
		{
			EOS_Platform_Tick(PlatformHandle);
			Result.val = 1.0;
		}
		else
		{
			Result.val = 0.0;
		}
	}
