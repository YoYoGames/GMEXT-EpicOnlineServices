
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



	std::vector<uint32_t> VectorUInt32FromVector(std::vector<const uint8_t*> array_ids)
	{
		EOS_SessionModification_SetAllowedPlatformIdsOptions Options = { 0 };

		std::vector<uint32_t> ids = {};
		for (int a = 0; a < array_ids.size(); a++)
		{
			ids.push_back((uint32_t)YYGetInt32(array_ids[a]));
		}

		return ids;
	}

	std::vector<std::string> VectorStringFromVector(std::vector<const uint8_t*> array_ids)
	{
		EOS_SessionModification_SetAllowedPlatformIdsOptions Options = { 0 };

		std::vector<std::string> ids = {};
		for (int a = 0; a < array_ids.size(); a++)
		{
			ids.push_back(YYGetString(array_ids[a]));
		}

		return ids;
	}

	std::vector<EOS_ProductUserId> VectorProductIdsFromVector(std::vector<const uint8_t*> array_ids)
	{
		EOS_SessionModification_SetAllowedPlatformIdsOptions Options = { 0 };

		std::vector<EOS_ProductUserId> ids = {};
		for (int a = 0; a < array_ids.size(); a++)
		{
			ids.push_back(EOS_ProductUserId_FromString(YYGetString(array_ids[a])));
		}

		return ids;
	}


	//////////////////////// NO INTERFACE FUNCTIONS:

	YYEXPORT void EpicGames_EpicAccountId_IsValid(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		EOS_NotInitialisedReturn_BOOL;

		eos_ensure_argc(1);

		const char* accountId = YYGetString(arg, 0);

		Result.kind = VALUE_BOOL;
		Result.val = EOS_EpicAccountId_IsValid(EOS_EpicAccountId_FromString(accountId));;
	}

	YYEXPORT void EpicGames_GetVersion(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		EOS_NotInitialisedReturn_STRING;

		Result.kind = VALUE_STRING;
		YYCreateString(&Result, EOS_GetVersion());
	}

	YYEXPORT void EpicGames_Logging_SetLogLevel(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		EOS_NotInitialisedReturn_BOOL;

		eos_ensure_argc(2);

		int32 category = YYGetInt32(arg, 0);
		int32 logLevel = YYGetInt32(arg, 1);

		EOS_Logging_SetLogLevel((EOS_ELogCategory)category, (EOS_ELogLevel)logLevel);

		Result.kind = VALUE_BOOL;
		Result.val = true;
	}

	YYEXPORT void EpicGames_ProductUserId_IsValid(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		EOS_NotInitialisedReturn_BOOL;

		eos_ensure_argc(1);

		const char* mProductUserId = YYGetString(arg, 0);

		Result.kind = VALUE_BOOL;
		Result.val = EOS_ProductUserId_IsValid(EOS_ProductUserId_FromString(mProductUserId));
	}

	YYEXPORT void EpicGames_Shutdown(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		EOS_NotInitialisedReturn_BOOL;

		return_EOS_EResult(&Result, EOS_Shutdown());
	}

	YYEXPORT void EpicGames_Result_ToString(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		EOS_NotInitialisedReturn_STRING;

		eos_ensure_argc(1);

		double v = YYGetReal(arg, 0);
		
		Result.kind = VALUE_STRING;
		YYCreateString(&Result, EOS_EResult_ToString((EOS_EResult)v));
	}
	


	std::string VectorOfStr2ArrayStr(std::vector<const char*> vec)
	{
		std::string str = "[";
		for (int a = 0; a < vec.size(); a++)
		{
			if (a != 0)
			{
				str += ",";
			}
			
			std::string element = vec.at(a);
			str += "\"" + element + "\"";
		}

		str += "]";

		return str;
	}

	std::string productIds2ArrayStr(EOS_ProductUserId* user_ids, int count)
	{
		std::vector<const char*> vec = {};
		for (int a = 0; a < count; a++)
		{
			vec.push_back(productID_toString(user_ids[a]));
		}
		
		std::cout << vec.size() << " ->" << VectorOfStr2ArrayStr(vec) << std::endl;

		return VectorOfStr2ArrayStr(vec);
	}
