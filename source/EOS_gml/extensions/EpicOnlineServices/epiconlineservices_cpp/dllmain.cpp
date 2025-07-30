#include "pch.h"
#include "YYEpicOnlineServices.h"
//#include <eos_version.h>
//#include <eos_logging.h>

#include <string>
#include <codecvt>

#ifdef OS_Windows
#include <direct.h>
#endif

#if defined(OS_Linux) || defined(OS_MacOs)
#include <unistd.h>
#endif

#include "DesktopExtensionTools.h"

///////////////////Callback initilization

YYRunnerInterface gs_runnerInterface;
YYRunnerInterface* g_pYYRunnerInterface;

extern void OldPreGraphicsInitialisation();

YYEXPORT void YYExtensionInitialise(const struct YYRunnerInterface* _pFunctions, size_t _functions_size)
{
    // copy out all the functions
    memcpy(&gs_runnerInterface, _pFunctions, _functions_size);
    g_pYYRunnerInterface = &gs_runnerInterface;

    if (_functions_size < sizeof(YYRunnerInterface)) {
        tracef("ERROR : runner interface mismatch in extension DLL");
    } // end if

    OldPreGraphicsInitialisation();
}

std::vector<EOS_ProductUserId> _SW_GetArrayOfProductUserId(RValue* arg, int arg_idx, const char* _func)
{
	RValue* pV = &(arg[arg_idx]);

	std::vector<EOS_ProductUserId> EOS_ProductUserIds = {};

	if (KIND_RValue(pV) == VALUE_ARRAY){
		std::vector<const char*> vec_Users = _SW_GetArrayOfStrings(arg, arg_idx, _func);
		for (const char* e : vec_Users) {
			EOS_ProductUserIds.push_back(EOS_ProductUserId_FromString(e));
		}
	}

	return EOS_ProductUserIds;
}

std::vector<RValue> _SW_GetArrayOfRValues(RValue* arg, int arg_idx, const char* _func)
{
	RValue* pV = &(arg[arg_idx]);

	std::vector<RValue> strings;

	if (KIND_RValue(pV) == VALUE_ARRAY)
	{
		RValue elem;
        int length = YYArrayGetLength(pV);
        for (int i = 0; i < length; ++i)
		{
            GET_RValue(&elem, pV, NULL, i);
			if (KIND_RValue(&elem) != VALUE_OBJECT)
			{
				YYError("%s argument %d [array element %d] incorrect type (%s) expecting a Struct", _func, (arg_idx + 1), i, KIND_NAME_RValue(pV));
			}

			strings.push_back(elem);
		}
	}
	else {
		YYError("%s argument %d incorrect type (%s) expecting an Array", _func, (arg_idx + 1), KIND_NAME_RValue(pV));
	}

	return strings;
}

std::vector<std::string> _SW_GetArrayOfStdStrings(RValue* arg, int arg_idx, const char* fn)
{
	RValue* pV = &arg[arg_idx];
	std::vector<std::string> out;

	if (KIND_RValue(pV) != VALUE_ARRAY) {
		YYError("%s argument %d incorrect type (%s) expecting an Array",
			fn, arg_idx + 1, KIND_NAME_RValue(pV));
		return out;
	}

	int len = YYArrayGetLength(pV);
	out.reserve(len);
	for (int i = 0; i < len; ++i) {
		RValue elem;
		GET_RValue(&elem, pV, NULL, i);
		if (KIND_RValue(&elem) != VALUE_STRING) {
			YYError("%s argument %d [array element %d] incorrect type (%s) expecting a String",
				fn, arg_idx + 1, i, KIND_NAME_RValue(&elem));
			continue;
		}
		// COPY while 'elem' is alive
		out.emplace_back(elem.GetString());
	}
	return out;
}


std::vector<const char*> _SW_GetArrayOfStrings(RValue* arg, int arg_idx, const char* _func)
{
	RValue* pV = &(arg[arg_idx]);

	std::vector<const char*> strings;

	if (KIND_RValue(pV) == VALUE_ARRAY)
	{
		RValue elem;
        int length = YYArrayGetLength(pV);
		for (int i = 0; i < length; ++i)
		{
            GET_RValue(&elem, pV, NULL, i);
			if (KIND_RValue(&elem) != VALUE_STRING)
			{
				YYError("%s argument %d [array element %d] incorrect type (%s) expecting a String", _func, (arg_idx + 1), i, KIND_NAME_RValue(pV));
			}

			strings.push_back(elem.GetString());
		}
	}
	else {
		YYError("%s argument %d incorrect type (%s) expecting an Array", _func, (arg_idx + 1), KIND_NAME_RValue(pV));
	}

	return strings;
}

std::vector<int32> _SW_GetArrayOfInt32(RValue* arg, int arg_idx, const char* _func)
{
	RValue* pV = &(arg[arg_idx]);

	std::vector<int32> vec;

	if (KIND_RValue(pV) == VALUE_ARRAY)
	{
		RValue elem;
        int length = YYArrayGetLength(pV);
        for (int i = 0; i < length; ++i)
		{
            GET_RValue(&elem, pV, NULL, i);
			if (KIND_RValue(&elem) != VALUE_INT32)
			{
				YYError("%s argument %d [array element %d] incorrect type (%s) expecting a String", _func, (arg_idx + 1), i, KIND_NAME_RValue(pV));
			}

			vec.push_back(YYGetInt32(&elem, i));
		}
	}
	else {
		YYError("%s argument %d incorrect type (%s) expecting an Array", _func, (arg_idx + 1), KIND_NAME_RValue(pV));
	}

	return vec;
}

std::vector<uint64> _SW_GetArrayOfUint64(RValue* arg, int arg_idx, const char* _func)
{
	RValue* pV = &(arg[arg_idx]);

	std::vector<uint64> vec;

	if (KIND_RValue(pV) == VALUE_ARRAY)
	{
		RValue elem;
        int length = YYArrayGetLength(pV);
		for (int i = 0; length; ++i)
		{
            GET_RValue(&elem, pV, NULL, i);
			if (KIND_RValue(&elem) != VALUE_INT64)
			{
				YYError("%s argument %d [array element %d] incorrect type (%s) expecting a String", _func, (arg_idx + 1), i, KIND_NAME_RValue(pV));
			}

			vec.push_back(YYGetInt64(&elem, i));
		}
	}
	else {
		YYError("%s argument %d incorrect type (%s) expecting an Array", _func, (arg_idx + 1), KIND_NAME_RValue(pV));
	}

	return vec;
}

void _SW_SetArrayOfString(RValue* _array, char* str, const char* delim)
{
	int idx = 0;
	char* token;

	/* get the first token */
	token = strtok(str, delim);

	/* walk through other tokens */
	while (token != NULL)
	{
		RValue tag = { 0 };
		YYCreateString(&tag, token);
		SET_RValue(_array, &tag, NULL, idx++);
		FREE_RValue(&tag);

		token = strtok(NULL, delim);
	}
}

void _SW_SetArrayOfReal(RValue* _array, std::vector<double>& values)
{
	for (int i = 0; i < values.size(); i++)
	{
		RValue tag = { 0 };
		tag.kind = VALUE_REAL;
		tag.val = values[i];

		SET_RValue(_array, &tag, NULL, i);
		FREE_RValue(&tag);
	}
}

void _SW_SetArrayOfRValue(RValue* _array, std::vector<RValue>& values)
{
	for (int i = 0; i < values.size(); i++)
	{
		RValue tag = values[i];

		SET_RValue(_array, &tag, NULL, i);
		FREE_RValue(&tag);
	}
}

void _SW_SetArrayOfInt32(RValue* _array, std::vector<int32>& values)
{
	for (int i = 0; i < values.size(); i++)
	{
		RValue tag = { 0 };
		tag.kind = VALUE_INT32;
		tag.v32 = values[i];

		SET_RValue(_array, &tag, NULL, i);
		FREE_RValue(&tag);
	}
}

void _SW_SetArrayOfInt64(RValue* _array, std::vector<int64>& values)
{
	for (int i = 0; i < values.size(); i++)
	{
		RValue tag = { 0 };
		tag.kind = VALUE_INT64;
		tag.v64 = values[i];

		SET_RValue(_array, &tag, NULL, i);
		FREE_RValue(&tag);
	}
}



    YYEXPORT void StructTest(RValue & Result, CInstance * selfinst, CInstance * otherinst, int argc, RValue * arg)
    {
        RValue* pV = &(arg[0]);



        COPY_RValue(&Result, pV);
        FREE_RValue(pV);
    }


    YYEXPORT void SimpleDesktopExample_ReturnString(RValue & Result, CInstance * selfinst, CInstance * otherinst, int argc, RValue * arg)
    {
        YYCreateString(&Result, "Hello World");
    }

    double val = 0;
    YYEXPORT void SimpleDesktopExample_ReturnDouble(RValue & Result, CInstance * selfinst, CInstance * otherinst, int argc, RValue * arg)
    {
        double inc = YYGetReal(arg, 0);

        val += inc;

        Result.kind = VALUE_REAL;
        Result.val = val;
    }

    YYEXPORT void SimpleDesktopExample_AsyncCallback(RValue & Result, CInstance * selfinst, CInstance * otherinst, int argc, RValue * arg)
    {
        int map = CreateDsMap(0,0);
        DsMapAddString(map, "type", "SimpleDesktopExample_AsyncCallback");
        DsMapAddDouble(map, "double", val);
        DsMapAddString(map, "string", "Hello World");

        CreateAsyncEventWithDSMap(map, 70);
    }

    YYEXPORT void SimpleDesktopExample_EchoStruct(RValue & Result, CInstance * selfinst, CInstance * otherinst, int argc, RValue * arg)
    {
        RValue* pV = &(arg[0]);

        COPY_RValue(&Result, pV);
        FREE_RValue(pV);
    }

    YYEXPORT void SimpleDesktopExample_ReturnStruct(RValue & Result, CInstance * selfinst, CInstance * otherinst, int argc, RValue * arg)
    {
        RValue Struct = { 0 };
        YYStructCreate(&Struct);

        YYStructAddDouble(&Struct, "double", val);
        YYStructAddString(&Struct, "string", "YoYoGames X Opera");

        COPY_RValue(&Result, &Struct);
        FREE_RValue(&Struct);
    }

