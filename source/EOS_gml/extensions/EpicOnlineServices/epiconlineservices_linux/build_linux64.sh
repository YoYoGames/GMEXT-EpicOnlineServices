#!/bin/sh

YYCOMPILER="g++"

if [ -n "$YYSTEAMRT" ]; then
    YYCOMPILER="g++-9";
fi

echo Compiler: "$YYCOMPILER"
echo Steam RT? "$YYSTEAMRT"

if "$YYCOMPILER" -m64 \
    -std=c++17 \
	EOS_gml/extensions/EpicOnlineServices/epiconlineservices_cpp/*.cpp \
    -Wl,-rpath,assets/ -fPIC \
	-LEOS_sdk/Bin \
    -lEOSSDK-Linux-Shipping \
	-IEOS_sdk/Include \
    -shared -o EOS_gml/extensions/EpicOnlineServices/EpicOnlineServices.so
then
    echo "BUILD SUCCESS";
else
    echo "BUILD FAILED";
fi