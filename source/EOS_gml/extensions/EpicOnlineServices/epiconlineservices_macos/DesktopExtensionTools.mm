
#import <Foundation/Foundation.h>

#include "DesktopExtensionTools.h"

#include "Extension_Interface.h"

#include <filesystem>
#include <string>

#include <stdio.h>

std::string DesktopExtensionTools_getPathToExe()
{
    NSString *bundlename = [[NSBundle mainBundle] executablePath];
    std::filesystem::path exePath =  [bundlename UTF8String];
        
    exePath = exePath.parent_path();
    return exePath.string();
}

std::vector<std::string> GetCommandLineArgs() {
    std::vector<std::string> args;
    std::ifstream cmdlineFile("/proc/self/cmdline", std::ios::binary);
    if (!cmdlineFile)
        return args;

    // Read the entire file into a string.
    std::string content((std::istreambuf_iterator<char>(cmdlineFile)),
        std::istreambuf_iterator<char>());

    // The command-line arguments are null-separated.
    size_t pos = 0;
    while (pos < content.size()) {
        std::string arg(&content[pos]);
        if (!arg.empty())
            args.push_back(arg);
        pos += arg.size() + 1;
    }
    return args;
}

