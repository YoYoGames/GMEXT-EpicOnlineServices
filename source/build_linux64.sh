#!/bin/sh
g++ -m64 \
    -std=c++17 \
	EOS_vs/EpicOnlineServices/*.cpp \
    -Wl,-rpath,assets/ -fPIC \
	-LEOS_sdk/Bin \
    -lEOSSDK-Linux-Shipping \
	-IEOS_sdk/Include \
    -shared -o EOS_gml/extensions/EpicOnlineServices/EpicOnlineServices.so
