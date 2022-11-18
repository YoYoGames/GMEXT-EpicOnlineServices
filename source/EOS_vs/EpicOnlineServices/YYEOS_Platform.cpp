
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

	//#if defined(OS_Linux) || defined(OS_MacOs)
	//extern "C" void PreGraphicsInitialisation(char* arg1)
	//#endif
	//#ifdef OS_Windows
	//extern "C" __declspec(dllexport) void PreGraphicsInitialisation(char* arg1)
	//#endif
	void OldPreGraphicsInitialisation()
	{
		printf("YYG -> PreGraphicsInitialisation\n");

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
			printf("EOS Initialization Error\n");
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
                

            printf("Current working dir: %s\n", PlatformOptions.CacheDirectory);
			
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
				printf("EOS PlatformHandle Error");
				//Result.val = false;
				return;
			}

			if (!debug)
				EOS_Platform_CheckForLauncherAndRestart(PlatformHandle);

			printf("\n\nEOS Initializations:\n\n");

			printf("EOS_Achievements_Init\n");
			EpicGames_Achievements_Init();
			printf("EOS_Connect_Init\n");
			EpicGames_Connect_Init();
			printf("EOS_Friends_Init\n");
			EpicGames_Friends_Init();
			printf("EOS_Leaderboards_Init\n");
			EpicGames_Leaderboards_Init();
			printf("EOS_Metrics_Init\n");
			EpicGames_Metrics_Init();

			printf("EOS_PlayerDataStorage_Init\n");
			EpicGames_PlayerDataStorage_Init();
			printf("EOS_TitleStorage_Init\n");
			EpicGames_TitleStorage_Init();
			printf("EOS_UI_Init\n");
			EpicGames_UI_Init();
			printf("EOS_Stats_Init\n");
			EpicGames_Stats_Init();
			printf("EOS_UserInfo_Init\n");
			EpicGames_UserInfo_Init();

			printf("EOS_Presence_Init\n");
			EpicGames_Presence_Init();
			printf("EOS_ProgressionSnapshot_Init\n");
			EpicGames_ProgressionSnapshot_Init();
			printf("EOS_Reports_Init\n");
			EpicGames_Reports_Init();
			printf("EOS_Sanctions_Init\n");
			EpicGames_Sanctions_Init();

			printf("EOS INITIlIZATION SUCCESS\n");
			//Result.val = true;
		}
	}

	char works[1024];
	YYEXPORT void EpicGames_Platform_Init(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		DebugConsoleOutput("EOS_Platform_Init\n");
		DebugConsoleOutput("%s\n", works);
	}


	YYEXPORT void EpicGames_Platform_CheckForLauncherAndRestart(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		EOS_Platform_CheckForLauncherAndRestart(PlatformHandle);

		Result.kind = VALUE_BOOL;
		Result.val = true;
	}

	YYEXPORT void EpicGames_Platform_GetActiveCountryCode(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
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
		const char* user = YYGetString(arg, 0);

		char Buffer[EOS_LOCALECODE_MAX_BUFFER_LEN];
		int32_t BufferLen = sizeof(Buffer);
		if (EOS_Platform_GetActiveLocaleCode(PlatformHandle, EOS_EpicAccountId_FromString(user), Buffer, &BufferLen) == EOS_EResult::EOS_Success)
			YYCreateString(&Result, Buffer);
		else
			YYCreateString(&Result, "");
	}

	YYEXPORT void EpicGames_Platform_GetOverrideCountryCode(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		char Buffer[EOS_COUNTRYCODE_MAX_BUFFER_LEN];
		int32_t BufferLen = sizeof(Buffer);
		if (EOS_Platform_GetOverrideCountryCode(PlatformHandle, Buffer, &BufferLen) == EOS_EResult::EOS_Success)
			YYCreateString(&Result, Buffer);
		else
			YYCreateString(&Result, "");
	}

	YYEXPORT void EpicGames_Platform_GetOverrideLocaleCode(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		char Buffer[EOS_LOCALECODE_MAX_BUFFER_LEN];
		int32_t BufferLen = sizeof(Buffer);
		if (EOS_Platform_GetOverrideLocaleCode(PlatformHandle, Buffer, &BufferLen) == EOS_EResult::EOS_Success)
			YYCreateString(&Result, Buffer);
		else
			YYCreateString(&Result, "");
	}

	YYEXPORT void EpicGames_Platform_Release(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		EOS_Platform_Release(PlatformHandle);

		Result.kind = VALUE_BOOL;
		Result.val = true;
	}

	YYEXPORT void EpicGames_Platform_SetOverrideCountryCode(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		const char* countryCode = YYGetString(arg, 0);

		EOS_Platform_SetOverrideCountryCode(PlatformHandle, countryCode);

		Result.kind = VALUE_BOOL;
		Result.val = true;
	}


	YYEXPORT void EpicGames_Platform_SetOverrideLocaleCode(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		const char* localCode = YYGetString(arg, 0);

		EOS_Platform_SetOverrideLocaleCode(PlatformHandle, localCode);

		Result.kind = VALUE_BOOL;
		Result.val = true;
	}

	YYEXPORT void EpicGames_Platform_Tick(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
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

	YYEXPORT void EpicGames_Platform_Tick_(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		Result.kind = VALUE_BOOL;

		if (PlatformHandle != nullptr)
		{
			EOS_Platform_Tick(PlatformHandle);
			Result.val = 1.0;
		}
		else
			Result.val = 0.0;
	}

