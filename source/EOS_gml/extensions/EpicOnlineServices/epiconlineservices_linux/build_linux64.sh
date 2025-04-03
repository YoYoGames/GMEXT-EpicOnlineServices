#!/bin/sh

YYCOMPILER="g++"

if [ -n "$YYSTEAMRT" ]; then
    YYCOMPILER="g++-9";
fi

echo Compiler: "$YYCOMPILER"
echo Steam RT? "$YYSTEAMRT"

if "$YYCOMPILER" -m64 \
    -std=c++17 \
	./../epiconlineservices_cpp/*.cpp \
    -Wl,-rpath,assets/ -fPIC \
	-L./../../../../EOS_sdk/Bin \
    -l./../../../../EOSSDK-Linux-Shipping \
	-I./../../../../EOS_sdk/Include \
    -shared -o ./../EpicOnlineServices.so
then
    echo "BUILD SUCCESS";
else
    echo "BUILD FAILED";
fi
