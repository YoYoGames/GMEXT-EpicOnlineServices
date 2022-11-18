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
        DebugConsoleOutput("ERROR : runner interface mismatch in extension DLL\n ");
    } // end if

    DebugConsoleOutput("YYExtensionInitialise CONFIGURED \n ");

    OldPreGraphicsInitialisation();
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

