
#import <Foundation/Foundation.h>

#include "DesktopExtensionTools.h"

#include "Extension_Interface.h"

#include <filesystem>
#include <string>

#include <stdio.h>
#include <crt_externs.h> // for _NSGetArgc and _NSGetArgv

std::string DesktopExtensionTools_getPathToExe()
{
    NSString *bundlename = [[NSBundle mainBundle] executablePath];
    std::filesystem::path exePath =  [bundlename UTF8String];
        
    exePath = exePath.parent_path();
    return exePath.string();
}

std::vector<std::string> GetCommandLineArgs() {
    std::vector<std::string> args;
    int argc = *_NSGetArgc();
    char** argv = *_NSGetArgv();
    for (int i = 0; i < argc; ++i) {
        args.push_back(std::string(argv[i]));
    }
    return args;
}
