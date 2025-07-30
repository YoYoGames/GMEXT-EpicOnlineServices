
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

	int identifier_count = 0;

	callback* getCallbackData()
	{
		callback* mCallback = new callback();
		mCallback->identifier = identifier_count;
		identifier_count++;

		return mCallback;
	}

	StringOwnerCallback* getStringOwnerCallback(const std::vector<const char*> &vec) {
		StringOwnerCallback* mCallback = new StringOwnerCallback();
		mCallback->identifier = identifier_count;
		identifier_count++;

		mCallback->ownedStrings.reserve(vec.size());
		for (const auto& user : vec) {
			mCallback->ownedStrings.push_back(user);
		}
		mCallback->cStrings.reserve(vec.size());
		for (const auto& user : mCallback->ownedStrings) {
			mCallback->cStrings.push_back(user.c_str());
		}

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

	std::vector<const char*> VectorStringFromVector(std::vector<const uint8_t*> array_ids)
	{
		EOS_SessionModification_SetAllowedPlatformIdsOptions Options = { 0 };

		std::vector<const char*> ids = {};
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

	YYEXPORT void eos_epic_account_id_is_valid(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		eos_not_init_return_rvalue_bool;

		eos_ensure_argc(1);

		const char* accountId = YYGetString(arg, 0);

		Result.kind = VALUE_BOOL;
		Result.val = EOS_EpicAccountId_IsValid(EOS_EpicAccountId_FromString(accountId));;
	}

	YYEXPORT void eos_get_version(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		eos_not_init_return_rvalue_string;

		Result.kind = VALUE_STRING;
		YYCreateString(&Result, EOS_GetVersion());
	}

	YYEXPORT void eos_logging_set_log_level(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		eos_not_init_return_rvalue_bool;

		eos_ensure_argc(2);

		int32 category = YYGetInt32(arg, 0);
		int32 logLevel = YYGetInt32(arg, 1);

		EOS_Logging_SetLogLevel((EOS_ELogCategory)category, (EOS_ELogLevel)logLevel);

		Result.kind = VALUE_BOOL;
		Result.val = true;
	}

	YYEXPORT void eos_product_user_id_is_valid(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		eos_not_init_return_rvalue_bool;

		eos_ensure_argc(1);

		const char* mProductUserId = YYGetString(arg, 0);

		Result.kind = VALUE_BOOL;
		Result.val = EOS_ProductUserId_IsValid(EOS_ProductUserId_FromString(mProductUserId));
	}

	YYEXPORT void eos_shutdown(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		eos_not_init_return_rvalue_bool;

		return_EOS_EResult(&Result, EOS_Shutdown());
	}

	YYEXPORT void eos_result_to_string(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
	{
		eos_not_init_return_rvalue_string;

		eos_ensure_argc(1);

		double v = YYGetReal(arg, 0);
		
		Result.kind = VALUE_STRING;
		YYCreateString(&Result, EOS_EResult_ToString((EOS_EResult)v));
	}
	
	void ProductIdsToArray(RValue& result, EOS_ProductUserId* user_ids, int count)
	{
		YYCreateArray(&result);

		for (int i = 0; i < count; i++)
		{
			RValue value{};
			YYCreateString(&value, productID_toString(user_ids[i]));
			SET_RValue(&result, &value, NULL, i);
		}
	}
