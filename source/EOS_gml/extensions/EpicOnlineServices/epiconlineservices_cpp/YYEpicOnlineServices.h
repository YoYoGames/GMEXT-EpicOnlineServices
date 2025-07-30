
#include "pch.h"

#include <iostream>
#include "YYRValue.h"

#include "Extension_Interface.h"
#include <stdio.h>
#include <string>

#include <eos_sdk.h>
#include <vector>

#include "ExtBufferIO.h"

// #define YYEXPORT __declspec(dllexport)

extern bool EOS_isInitialised;

extern int identifier_count;
struct callback;
struct StringOwnerCallback;

extern callback *getCallbackData();
extern callback *getCallbackData(const char *str);
extern StringOwnerCallback *getStringOwnerCallback(const std::vector<const char*> &vec);

extern char *AccountID_toString(EOS_EpicAccountId account);
extern char *productID_toString(EOS_ProductUserId user);
std::wstring stringToWstring(const std::string &t_str);

extern void return_EOS_EResult(RValue *Result, EOS_EResult EpicResult);

std::vector<uint32_t> VectorUInt32FromVector(std::vector<const uint8_t *> array_ids);
std::vector<const char *> VectorStringFromVector(std::vector<const uint8_t *> array_ids);
std::vector<EOS_ProductUserId> VectorProductIdsFromVector(std::vector<const uint8_t *> array_ids);

// extern void eos_platform_init();
extern void eos_achievements_init();
extern void eos_connect_init();
extern void eos_ecom_init();
extern void eos_friends_init();
extern void eos_leaderboards_init();
extern void eos_metrics_init();
extern void eos_player_data_storage_init();
extern void eos_presence_init();
extern void eos_progression_snapshot_init();
extern void eos_reports_init();
extern void eos_sanctions_init();
extern void eos_stats_init();
extern void eos_title_storage_init();
extern void eos_user_info_init();
extern void eos_ui_init();
extern void eos_p2p_init();
extern void eos_sessions_init();
extern void eos_lobby_init();
extern void eos_rtc_init();

extern void _SW_SetArrayOfString(RValue *_array, char *str, const char *delim);
extern void _SW_SetArrayOfInt32(RValue *_array, std::vector<int> &values);
extern void _SW_SetArrayOfInt64(RValue *_array, std::vector<int64> &values);
extern void _SW_SetArrayOfReal(RValue *_array, std::vector<double> &values);
extern void _SW_SetArrayOfRValue(RValue *_array, std::vector<RValue> &values);
std::vector<EOS_ProductUserId> _SW_GetArrayOfProductUserId(RValue *arg, int arg_idx, const char *_func);
extern std::vector<RValue> _SW_GetArrayOfRValues(RValue *arg, int arg_idx, const char *func);
extern std::vector<const char *> _SW_GetArrayOfStrings(RValue *arg, int arg_idx, const char *func);
extern std::vector<int32> _SW_GetArrayOfInt32(RValue *arg, int arg_idx, const char *func);
extern std::vector<uint64> _SW_GetArrayOfUint64(RValue *arg, int arg_idx, const char *func);

#define eos_not_init_return_rvalue_bool \
	if (!EOS_isInitialised)             \
	{                                   \
		Result.kind = VALUE_BOOL;       \
		Result.val = 0.0;               \
		return;                         \
	}

#define eos_not_init_return_rvalue_string \
	if (!EOS_isInitialised)               \
	{                                     \
		Result.kind = VALUE_STRING;       \
		YYCreateString(&Result, "");      \
		return;                           \
	}

#define eos_not_init_return_rvalue_struct \
	if (!EOS_isInitialised)               \
	{                                     \
		RValue Struct = {0};              \
		YYStructCreate(&Struct);          \
		COPY_RValue(&Result, &Struct);    \
		FREE_RValue(&Struct);             \
		return;                           \
	}

#define eos_not_init_return_rvalue_int32 \
	if (!EOS_isInitialised)              \
	{                                    \
		Result.kind = VALUE_INT32;       \
		Result.val = 0.0;                \
		return;                          \
	}

#define eos_not_init_return_rvalue_int64 \
	if (!EOS_isInitialised)              \
	{                                    \
		Result.kind = VALUE_INT64;       \
		Result.v64 = 0;                  \
		return;                          \
	}

#define eos_not_init_return_rvalue_real \
	if (!EOS_isInitialised)             \
	{                                   \
		Result.kind = VALUE_REAL;       \
		Result.val = 0.0;               \
		return;                         \
	}

#define eos_not_init_return_buffer(ret_buff, value) \
	if (!EOS_isInitialised)                         \
	{                                               \
		DataStream data;                            \
		data << value;                              \
		data.writeTo(ret_buff);                     \
		return -1.0;                                \
	}

#define eos_not_init_return(value) \
	if (!EOS_isInitialised)        \
	{                              \
		return value;              \
	}

#define eos_ensure_argc(_ExpectedArgumentCount)                                                                        \
	do                                                                                                                 \
	{                                                                                                                  \
		if (argc < (_ExpectedArgumentCount) || nullptr == arg)                                                         \
		{                                                                                                              \
			YYError("%s expected at least %d arguments but got %d instead", __func__, (_ExpectedArgumentCount), argc); \
		}                                                                                                              \
	} while (0) /* so we are required to put a semicolon here... */

#pragma once
struct callback
{
	int identifier;
	/*std::wstring*/ /*const char**/ std::string string; // optional argument
};

struct StringOwnerCallback
{
	int identifier;
	// Own copies of all external account IDs
	std::vector<std::string>      ownedStrings;
	// Pointers into ownedStrings (what you pass to EOS)
	std::vector<const char*>      cStrings;
};

void ProductIdsToArray(RValue& result, EOS_ProductUserId* user_ids, int count);

#ifdef OS_Windows
#define func extern "C" __declspec(dllexport)
#else
#define func extern "C" __attribute__((visibility("default")))
#endif

extern EOS_HPlatform PlatformHandle;
extern EOS_ContinuanceToken ContinuanceToken;
extern EOS_HAchievements HAchievements;
extern EOS_HAuth HAuth;
extern EOS_HConnect HConnect;
extern EOS_HEcom HEcom;
extern EOS_HFriends HFriends;
extern EOS_HLeaderboards HLeaderboards;
extern EOS_HMetrics HMetrics;
extern EOS_HPlatform PlatformHandle;
extern EOS_HPlayerDataStorage HPlayerDataStorage;
extern EOS_HPresence HPresence;
extern EOS_HProgressionSnapshot HProgressionSnapshot;
extern EOS_HReports HReports;
extern EOS_HSanctions HSanctions;
extern EOS_HStats HStats;
extern EOS_HTitleStorage HTitleStorage;
extern EOS_HUI HUI;
extern EOS_HUserInfo HUserInfo;

