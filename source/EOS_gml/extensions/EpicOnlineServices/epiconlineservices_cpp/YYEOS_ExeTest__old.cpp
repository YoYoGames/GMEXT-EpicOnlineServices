
//To DLL:
//1) General->Configuration Type:    Dynamic Library (.dll)
//2) Propieties->Linker->System->SubSystem:    Windows(/ SUBSYSTEM:WINDOWS)

//To EXE
//1) General->Configuration Type:    Application (.exe)
//2) Propieties->Linker->System->SubSystem:    Console (/SUBSYSTEM:CONSOLE)


////////////////////////////////////COMMENT/REMOVE IF IS EXPORTED TO DLL

#include "pch.h"
//#include "YYEpicOnlineServices.h"
//
//#include <eos_auth.h>
//#include <eos_auth_types.h>
//
//#include <eos_achievements.h>
//#include <vector>
//
//#include <eos_version.h>
//
//EOS_HAuth EXE_HAuth;
//EOS_HConnect EXE_ConnectHandle;
//
//void EOS_CALL EXE_ConnectCreateUserCompleteCb_(const EOS_Connect_CreateUserCallbackInfo* Data)
//{
//	printf("[EOS SDK] ConnectCreateUserCompleteCb\n");
//
//	if (Data->ResultCode != EOS_EResult::EOS_Success)
//	{
//		printf("ConnectCreateUserCompleteCb Failed info: ");
//		printf(EOS_EResult_ToString(Data->ResultCode));
//		printf("\n");
//		return;
//	}
//
//	EOS_ProductUserId LocalUserId = Data->LocalUserId;
//
//	printf("[EOS SDK] ConnectCreateUserCompleteCb END\n");
//}
//
//
//
//struct EXE_SampleConstants
//{
//	static constexpr char ProductId[] = "1871b8543c784e7aa2638603b0299bb1";
//	static constexpr char SandboxId[] = "183a6910197a47bca8e8c0fd82ac547a";
//	static constexpr char DeploymentId[] = "381d7d3784954c1b93e701c944a91597";
//	static constexpr char ClientCredentialsId[] = "xyza7891fQVrHb3nJv0SNUUtDQHBUmmO";
//	static constexpr char ClientCredentialsSecret[] = "H3PJ826UOAdQhHEprgTyxX4pfUI9H6t3pOwnTV/fBTw";
//	static constexpr char GameName[] = "jzavala93's Product";
//	static constexpr char EncryptionKey[] = "1111111111111111111111111111111111111111111111111111111111111111";
//};
//
//struct FConnectLoginContext
//{
//	EOS_EpicAccountId AccountId;
//};
//
//#define zerotrick 1
//void EOS_CALL EXE_ConnectLoginCompleteCb(const EOS_Connect_LoginCallbackInfo* Data)
//{
//
//	if (Data->ResultCode == EOS_EResult::EOS_Success)
//	{
//		printf("EpicGames_Connect_Login SUCCESS\n");
//
//		int32_t ContinuanceTokenSize = 0;
//		EOS_ContinuanceToken_ToString(Data->ContinuanceToken, NULL, &ContinuanceTokenSize);
//		printf("ContinuanceTokenBuffer: %i\n", ContinuanceTokenSize);
//		static char* ContinuanceTokenBuffer = new char[ContinuanceTokenSize + 1];
//		EOS_EResult EResult = EOS_ContinuanceToken_ToString(Data->ContinuanceToken, ContinuanceTokenBuffer, &ContinuanceTokenSize);
//		
//		printf("ContinuanceTokenBuffer: %s",ContinuanceTokenBuffer);
//		
//		/*Data->LocalUserId;
//		Data->ClientData;*/
//	}
//	else if (Data->ResultCode == EOS_EResult::EOS_InvalidUser)
//	{
//		printf("EpicGames_Connect_Login INVALID USER\n");
//		/*EOS_HConnect ConnectHandle = EOS_Platform_GetConnectInterface(FPlatform::GetPlatformHandle());
//		EOS_Connect_CreateUser(ConnectHandle, &Options, ClientData.release(), ConnectCreateUserCompleteCb);*/
//	}
//	else
//	{
//		printf("EpicGames_Connect_Login INVALID .....\n");
//	}
//}
//
//void EOS_CALL EXE_LoginCompleteCallbackFn(const EOS_Auth_LoginCallbackInfo* Data)
//{
//	printf("EXE_LoginCompleteCallbackFn\n");
//	//std::unique_ptr<FConnectLoginContext> ClientData(static_cast<FConnectLoginContext*>(Data->ClientData));
//
//	/*int map = g_pYYRunnerInterface->CreateDsMap(0);
//	g_pYYRunnerInterface->DsMapAddString(map, "type", "EpicGames_Login");*/
//
//	if (Data->ResultCode == EOS_EResult::EOS_Success)
//	{
//		const int32_t AccountsCount = EOS_Auth_GetLoggedInAccountsCount(EXE_HAuth);
//		printf("Counting Accounts: %i\n", AccountsCount);
//		EOS_ELoginStatus LoginStatus;
//		EOS_EpicAccountId AccountId = NULL;
//		for (int32_t AccountIdx = 0; AccountIdx < AccountsCount; ++AccountIdx)
//		{
//			AccountId = EOS_Auth_GetLoggedInAccountByIndex(EXE_HAuth, AccountIdx);
//			LoginStatus = EOS_Auth_GetLoginStatus(EXE_HAuth, Data->LocalUserId);
//			printf("Account, LoginStatus: %i\n", LoginStatus);
//		}
//
//		static char TempBuffer[EOS_EPICACCOUNTID_MAX_LENGTH + 1];
//		int32_t TempBufferSize = sizeof(TempBuffer);
//		EOS_EResult Result = EOS_EpicAccountId_ToString(/*AccountId*/Data->LocalUserId, TempBuffer, &TempBufferSize);
//		if (Result == EOS_EResult::EOS_Success)
//		{
//			printf("EpicGames_EpicAccountId_ToString SUCCESS: ");
//			printf(TempBuffer);
//			printf("\n");
//		}
//		else
//		{
//			printf("EpicGames_EpicAccountId_ToString FAILED: ");
//			printf(EOS_EResult_ToString(Result));
//			printf("\n");
//		}
//
//		Result = EOS_EpicAccountId_ToString(AccountId, TempBuffer, &TempBufferSize);
//		if (Result == EOS_EResult::EOS_Success)
//		{
//			printf("EpicGames_EpicAccountId_ToString SUCCESS: ");
//			printf(TempBuffer);
//			printf("\n");
//		}
//		else
//		{
//			printf("EpicGames_EpicAccountId_ToString FAILED: ");
//			printf(EOS_EResult_ToString(Result));
//			printf("\n");
//		}
//
//		EOS_Auth_Token* UserAuthToken = nullptr;
//		EOS_Auth_CopyUserAuthTokenOptions CopyTokenOptions = { 0 };
//		CopyTokenOptions.ApiVersion = EOS_AUTH_COPYUSERAUTHTOKEN_API_LATEST;
//		//EOS_EResult ResultCode = EOS_Auth_CopyUserAuthToken(EXE_HAuth, &CopyTokenOptions, AccountId, &UserAuthToken);
//		EOS_EResult ResultCode = EOS_Auth_CopyUserAuthToken(EXE_HAuth, &CopyTokenOptions, /*AccountId*/Data->LocalUserId, &UserAuthToken);
//		if (ResultCode == EOS_EResult::EOS_Success)
//		{
//			printf("EpicGames_Auth_CopyUserAuthToken SUCCESS \n");
//
//			
//
//			/*EOS_EpicAccountId_ToString*/
//			//g_pYYRunnerInterface->DsMapAddString(map, "AccessToken", UserAuthToken->AccessToken);
//			////g_pYYRunnerInterface->DsMapAddString(map, "AccountId", UserAuthToken->AccountId);
//			////g_pYYRunnerInterface->DsMapAddString(map, "ApiVersion", UserAuthToken->ApiVersion);
//			//g_pYYRunnerInterface->DsMapAddString(map, "App", UserAuthToken->App);
//			//g_pYYRunnerInterface->DsMapAddString(map, "ExpiresAt", UserAuthToken->ExpiresAt);
//			////g_pYYRunnerInterface->DsMapAddString(map, "ExpiresInExpiresAt", UserAuthToken->ExpiresInExpiresAt);
//			//g_pYYRunnerInterface->DsMapAddString(map, "RefreshToken", UserAuthToken->RefreshToken);
//
//
//
//			const char* AccessToken = UserAuthToken->AccessToken;//YYGetString(arg, 0);
//
//			EOS_Connect_Credentials Credentials;
//			Credentials.ApiVersion = EOS_CONNECT_CREDENTIALS_API_LATEST;
//			Credentials.Token = AccessToken;
//			Credentials.Type = EOS_EExternalCredentialType::EOS_ECT_EPIC;
//
//			EOS_Connect_LoginOptions Options = { 0 };
//			Options.ApiVersion = EOS_CONNECT_LOGIN_API_LATEST;
//			Options.Credentials = &Credentials;
//			Options.UserLoginInfo = nullptr;
//
//			//assert(ConnectHandle != nullptr);
//			printf("EpicGames_Connect_Login\n");
//			EOS_Connect_Login(EXE_ConnectHandle, &Options, NULL, EXE_ConnectLoginCompleteCb);
//		}
//		else
//		{
//			EOS_Connect_CreateUserOptions Options;
//			Options.ApiVersion = EOS_CONNECT_CREATEUSER_API_LATEST;
//			Options.ContinuanceToken = ContinuanceToken;
//			
//			// NOTE: We're not deleting the received context because we're passing it down to another SDK call
//			EOS_Connect_CreateUser(EXE_ConnectHandle, &Options, NULL, EXE_ConnectCreateUserCompleteCb_);
//			printf("EpicGames_Auth_CopyUserAuthToken FAILED: ");
//			printf(EOS_EResult_ToString(ResultCode));
//			printf("\n");
//		}
//
//
//		/*g_pYYRunnerInterface->DsMapAddBool(map, "Success", true);
//		g_pYYRunnerInterface->DsMapAddString(map, "LocalUserId", TempBuffer);*/
//		//g_pYYRunnerInterface->DsMapAddString(map, "ContinuanceToken", EOS_ContinuanceToken_ToString(mContinuanceToken));
//		//g_pYYRunnerInterface->DsMapAddString(map, "LocalUserId", Data->SelectedAccountId);
//	}
//	else
//	{
//		//g_pYYRunnerInterface->DsMapAddBool(map, "Success", false);
//	}
//
//	//g_pYYRunnerInterface->CreateAsyncEventWithDSMap(map, 70);
//}
//
//
//
//
//int main()
//{
//	printf("EPIC ONLINE SERVICES by YoYoGames\n");
//	printf("Version: %s\n", EOS_GetVersion());
//
//	/////////////////////////////////////////////////////////////////EOS_Platform_Init
//	
//	// Init EOS SDK
//	EOS_InitializeOptions SDKOptions = {};
//	SDKOptions.ApiVersion = EOS_INITIALIZE_API_LATEST;
//	SDKOptions.AllocateMemoryFunction = nullptr;
//	SDKOptions.ReallocateMemoryFunction = nullptr;
//	SDKOptions.ReleaseMemoryFunction = nullptr;
//	SDKOptions.ProductName = EXE_SampleConstants::GameName;
//	SDKOptions.ProductVersion = "1.0";
//	SDKOptions.Reserved = nullptr;
//	SDKOptions.SystemInitializeOptions = nullptr;
//	SDKOptions.OverrideThreadAffinity = nullptr;
//
//	EOS_EResult InitResult = EOS_Initialize(&SDKOptions);
//
//	//Result.kind = VALUE_BOOL;
//	if (InitResult != EOS_EResult::EOS_Success)
//	{
//		//Result.val = false;
//		return -1;
//	}
//	else
//	{
//		EOS_Platform_Options PlatformOptions = {};
//		PlatformOptions.ApiVersion = EOS_PLATFORM_OPTIONS_API_LATEST;
//		PlatformOptions.bIsServer = false;// FCommandLine::Get().HasFlagParam(CommandLineConstants::Server);
//		PlatformOptions.OverrideCountryCode = nullptr;
//		PlatformOptions.OverrideLocaleCode = nullptr;
//		PlatformOptions.Flags = EOS_PF_WINDOWS_ENABLE_OVERLAY_D3D9 | EOS_PF_WINDOWS_ENABLE_OVERLAY_D3D10 | EOS_PF_WINDOWS_ENABLE_OVERLAY_OPENGL; // Enable overlay support for D3D9/10 and OpenGL. This sample uses D3D11 or SDL.
//		//PlatformOptions.CacheDirectory = "C:\\Users\\chuyz\\AppData\\Local\\Temp";// FUtils::GetTempDirectory();
//
//		std::string ProductId = EXE_SampleConstants::ProductId;
//		std::string SandboxId = EXE_SampleConstants::SandboxId;
//		std::string DeploymentId = EXE_SampleConstants::DeploymentId;
//		std::string ClientId = EXE_SampleConstants::ClientCredentialsId;
//		std::string ClientSecret = EXE_SampleConstants::ClientCredentialsSecret;
//
//		PlatformOptions.EncryptionKey = EXE_SampleConstants::EncryptionKey;
//
//		PlatformOptions.ProductId = ProductId.c_str();
//		PlatformOptions.SandboxId = SandboxId.c_str();
//		PlatformOptions.DeploymentId = DeploymentId.c_str();
//		PlatformOptions.ClientCredentials.ClientId = ClientId.c_str();
//		PlatformOptions.ClientCredentials.ClientSecret = ClientSecret.c_str();
//
//		EOS_Platform_RTCOptions RtcOptions = { 0 };
//		RtcOptions.ApiVersion = EOS_PLATFORM_RTCOPTIONS_API_LATEST;
//
//		//PlatformOptions.RTCOptions = &RtcOptions;
//		PlatformOptions.Reserved = NULL;
//
//		PlatformHandle = EOS_Platform_Create(&PlatformOptions);
//
//		//Result.kind = VALUE_BOOL;
//		if (PlatformHandle == nullptr)
//		{
//			//Result.val = false;
//			return -1;
//		}
//
//		//Result.val = true;
//	}
//
//	/////////////////////////////////////////////////////////////EOS_Auth_init
//	EXE_HAuth = EOS_Platform_GetAuthInterface(PlatformHandle);
//	EXE_ConnectHandle = EOS_Platform_GetConnectInterface(PlatformHandle);
//
//	/// //////////////////////////////////////////////////////////EOS_Auth_Login
//	EOS_Auth_Credentials Credentials = {};
//	Credentials.ApiVersion = EOS_AUTH_CREDENTIALS_API_LATEST;
//
//	EOS_Auth_LoginOptions LoginOptions;
//	memset(&LoginOptions, 0, sizeof(LoginOptions));
//	LoginOptions.ApiVersion = EOS_AUTH_LOGIN_API_LATEST;
//	LoginOptions.ScopeFlags = EOS_EAuthScopeFlags::EOS_AS_BasicProfile | EOS_EAuthScopeFlags::EOS_AS_FriendsList | EOS_EAuthScopeFlags::EOS_AS_Presence;
//
//	Credentials.Type = EOS_ELoginCredentialType::EOS_LCT_AccountPortal;
//
//	LoginOptions.Credentials = &Credentials;
//	
//	EOS_Auth_Login(EXE_HAuth, &LoginOptions, NULL, EXE_LoginCompleteCallbackFn);
//
//	printf("WHILE(TRUE)");
//	while (true)
//		EOS_Platform_Tick(PlatformHandle);
//	printf("WHILE END");
//
//	return 1;
//}

