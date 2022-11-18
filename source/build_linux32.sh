#!/bin/sh
g++ -m32 \
    -std=c++17 \
	json-c-0.9/*.c \
	VS_Project/EpicOnlineServices/*.cpp \
    -Wl,-rpath,assets/ -fPIC \
	-Ijson-c-0.9/ \
	-LSDK/Bin \
    -lEOSSDK-Linux-Shipping \
	-ISDK/include \
    -shared -o GM_Project/extensions/EpicOnlineServices/EpicOnlineServices.so