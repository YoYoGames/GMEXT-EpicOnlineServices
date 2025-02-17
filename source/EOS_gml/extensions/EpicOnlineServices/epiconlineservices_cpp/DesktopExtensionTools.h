//
// Copyright (C) 2020 Opera Norway AS. All rights reserved.
//
// This file is an original work developed by Opera.
//

#include <filesystem>
#include <fstream>
#include <string>


std::string DesktopExtensionTools_getPathToExe();
std::vector<std::string> GetCommandLineArgs();


#define tracef(...) do { DebugConsoleOutput("[EPIC ONLINE SERVICES]: "); DebugConsoleOutput(__VA_ARGS__); DebugConsoleOutput("\n"); } while (0)