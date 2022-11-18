
#include "pch.h"
#include "YYEpicOnlineServices.h"
#include <eos_version.h>
#include <eos_logging.h>

#include <string>
#include <codecvt>

#ifdef OS_Windows
#include <direct.h>
#endif

#if defined(OS_Linux) || defined(OS_MacOs)
#include <unistd.h>
#endif

	///////////////////////////////// EOS ///////////////////////////////////

	EOS_HPlatform PlatformHandle = nullptr;
	EOS_ContinuanceToken ContinuanceToken = nullptr;

	int identifier_count = 0;

	callback* getCallbackData()
	{
		callback* mCallback = new callback();
		mCallback->identifier = identifier_count;
		identifier_count++;

		return mCallback;
	}

	/*std::wstring stringToWstring(const std::string& t_str)
	{
		//setup converter
		typedef std::codecvt_utf8<wchar_t> convert_type;
		std::wstring_convert<convert_type, wchar_t> converter;

		//use converter (.to_bytes: wstr->str, .from_bytes: str->wstr)
		return converter.from_bytes(t_str);
	}*/

	callback* getCallbackData(const char* str)
	{
		callback* mCallback = new callback();
		mCallback->identifier = identifier_count;
		mCallback->string = /*stringToWstring*/(str);
		identifier_count++;

		return mCallback;
	}

	char* AccountID_toString(EOS_EpicAccountId account)
	{
		static char TempBuffer[EOS_EPICACCOUNTID_MAX_LENGTH + 1];
		int32_t TempBufferSize = sizeof(TempBuffer);
		EOS_EResult EResult = EOS_EpicAccountId_ToString(account, TempBuffer, &TempBufferSize);

		return TempBuffer;
	}

	char* productID_toString(EOS_ProductUserId user)
	{
		static char TempBuffer[EOS_PRODUCTUSERID_MAX_LENGTH + 1];
		int32_t TempBufferSize = sizeof(TempBuffer);
		EOS_EResult Result = EOS_ProductUserId_ToString(user, TempBuffer, &TempBufferSize);
	
		return TempBuffer;
	}
	
	void return_EOS_EResult(RValue* Result,EOS_EResult EpicResult)
	{
		RValue Struct = { 0 };
		YYStructCreate(&Struct);
		YYStructAddDouble(&Struct, "status", (double)EpicResult);
		YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(EpicResult));
		COPY_RValue(Result, &Struct);
		FREE_RValue(&Struct);
	}




	//////////////////////// NO INTERFACE FUNCTIONS:

	YYEXPORT void EpicGames_EpicAccountId_IsValid(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		const char* accountId = YYGetString(arg, 0);

		Result.kind = VALUE_BOOL;
		Result.val = EOS_EpicAccountId_IsValid(EOS_EpicAccountId_FromString(accountId));;
	}

	YYEXPORT void EpicGames_GetVersion(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		YYCreateString(&Result, EOS_GetVersion());
	}

	YYEXPORT void EpicGames_Logging_SetLogLevel(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		int32 category = YYGetInt32(arg, 0);
		int32 logLevel = YYGetInt32(arg, 1);

		EOS_Logging_SetLogLevel((EOS_ELogCategory)category, (EOS_ELogLevel)logLevel);

		Result.kind = VALUE_BOOL;
		Result.val = true;
	}

	YYEXPORT void EpicGames_ProductUserId_IsValid(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		const char* mProductUserId = YYGetString(arg, 0);

		Result.kind = VALUE_BOOL;
		Result.val = EOS_ProductUserId_IsValid(EOS_ProductUserId_FromString(mProductUserId));
	}

	YYEXPORT void EpicGames_Shutdown(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		return_EOS_EResult(&Result, EOS_Shutdown());
	}