
#include "pch.h"

#include <iostream>
#include "YYRValue.h"

#include "Extension_Interface.h"
#include <stdio.h>
#include <string>

#include <eos_sdk.h>
#include <vector>

#include "ExtBufferIO.h"

//#define YYEXPORT __declspec(dllexport)

extern bool EOS_isInitialised;

extern EOS_HPlatform PlatformHandle;
extern EOS_ContinuanceToken ContinuanceToken;

extern int identifier_count;
struct callback;
extern callback* getCallbackData();
extern callback* getCallbackData(const char* str);

extern char* AccountID_toString(EOS_EpicAccountId account);
extern char* productID_toString(EOS_ProductUserId user);
std::wstring stringToWstring(const std::string& t_str);

extern void return_EOS_EResult(RValue* Result, EOS_EResult EpicResult);

//extern void EpicGames_Platform_Init();
extern void EpicGames_Achievements_Init();
extern void EpicGames_Connect_Init();
extern void EpicGames_Ecom_Init();
extern void EpicGames_Friends_Init();
extern void EpicGames_Leaderboards_Init();
extern void EpicGames_Metrics_Init();
extern void EpicGames_PlayerDataStorage_Init();
extern void EpicGames_Presence_Init();
extern void EpicGames_ProgressionSnapshot_Init();
extern void EpicGames_Reports_Init();
extern void EpicGames_Sanctions_Init();
extern void EpicGames_Stats_Init();
extern void EpicGames_TitleStorage_Init();
extern void EpicGames_UserInfo_Init();
extern void EpicGames_UI_Init();

extern void _SW_SetArrayOfString(RValue* _array, char* str, const char* delim);
extern void _SW_SetArrayOfInt32(RValue* _array, std::vector<int>& values);
extern void _SW_SetArrayOfInt64(RValue* _array, std::vector<int64>& values);
extern void _SW_SetArrayOfReal(RValue* _array, std::vector<double>& values);
extern void _SW_SetArrayOfRValue(RValue* _array, std::vector<RValue>& values);
extern std::vector<const char*> _SW_GetArrayOfStrings(RValue* arg, int arg_idx, const char* func);
extern std::vector<int32> _SW_GetArrayOfInt32(RValue* arg, int arg_idx, const char* func);
extern std::vector<uint64> _SW_GetArrayOfUint64(RValue* arg, int arg_idx, const char* func);

#define EOS_NotInitialisedReturn_BOOL if (!EOS_isInitialised) { Result.kind = VALUE_BOOL; Result.val = 0.0; return; }
#define EOS_NotInitialisedReturn_STRING if (!EOS_isInitialised) {Result.kind = VALUE_STRING; YYCreateString(&Result, ""); return; }
#define EOS_NotInitialisedReturn_STRUCT if (!EOS_isInitialised){ RValue Struct = { 0 }; YYStructCreate(&Struct); COPY_RValue(&Result, &Struct); FREE_RValue(&Struct); return; }
#define EOS_NotInitialisedReturn_INT32 if (!EOS_isInitialised) { Result.kind = VALUE_INT32; Result.val = 0.0; return; }
#define EOS_NotInitialisedReturn_INT64 if (!EOS_isInitialised) { Result.kind = VALUE_INT64; Result.v64 = 0; return; }
#define EOS_NotInitialisedReturn_REAL if (!EOS_isInitialised) { Result.kind = VALUE_REAL; Result.val = 0.0; return; }

#define eos_ensure_argc(_ExpectedArgumentCount) \
	do \
	{ \
		if (argc < (_ExpectedArgumentCount) || nullptr == arg) \
		{ \
			YYError("%s expected at least %d arguments but got %d instead", __func__, (_ExpectedArgumentCount), argc); \
		} \
	} while (0) /* so we are required to put a semicolon here... */

#pragma once
struct callback
{
	int identifier;
	/*std::wstring*//*const char**/ std::string string; //optional argument
};
