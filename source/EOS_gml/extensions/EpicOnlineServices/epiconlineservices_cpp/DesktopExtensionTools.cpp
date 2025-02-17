
#include "DesktopExtensionTools.h"
#include "Extension_Interface.h"

#include <filesystem>
#include <string>

#include <stdio.h>

std::string DesktopExtensionTools_getPathToExe()
{
    std::filesystem::path exePath = std::filesystem::current_path();
    return exePath.string();
}


#ifdef OS_Windows
#include <windows.h>
#include <shellapi.h>

std::vector<std::string> GetCommandLineArgs() {
    std::vector<std::string> args;
    int argc = 0;
    // Retrieve the wide-char command line and split it into arguments.
    LPWSTR* argvW = CommandLineToArgvW(GetCommandLineW(), &argc);
    if (!argvW)
        return args;

    for (int i = 0; i < argc; ++i) {
        // Convert wide string to UTF-8 std::string.
        int sizeNeeded = WideCharToMultiByte(CP_UTF8, 0, argvW[i], -1, nullptr, 0, nullptr, nullptr);
        if (sizeNeeded > 0) {
            std::string arg(sizeNeeded, 0);
            WideCharToMultiByte(CP_UTF8, 0, argvW[i], -1, &arg[0], sizeNeeded, nullptr, nullptr);
            // Remove the trailing null character, if present.
            if (!arg.empty() && arg.back() == '\0') {
                arg.pop_back();
            }
            args.push_back(arg);
        }
    }
    LocalFree(argvW);
    return args;
}

#elif defined(OS_MacOs)
#include <crt_externs.h> // for _NSGetArgc and _NSGetArgv

std::vector<std::string> GetCommandLineArgs() {
    std::vector<std::string> args;
    int argc = *_NSGetArgc();
    char** argv = *_NSGetArgv();
    for (int i = 0; i < argc; ++i) {
        args.push_back(std::string(argv[i]));
    }
    return args;
}

#elif defined(OS_Linux)
#include <fstream>
#include <iterator>

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

#else

// Fallback for other platforms.
std::vector<std::string> GetCommandLineArgs() {
    return std::vector<std::string>(); // or implement as needed
}

#endif