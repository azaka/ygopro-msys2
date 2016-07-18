#!/bin/bash
ygopro_root=$PWD
mkdir build
pushd build
cmake -DGLEW_LIBRARIES="/c/msys64/mingw32/lib/libglew32.dll.a" -DCMAKE_CXX_FLAGS="-fpermissive -DLUA_COMPAT_5_2 -I$ygopro_root $CMAKE_CXX_FLAGS" -G "MSYS Makefiles" ..
mingw32-make && \
mv $ygopro_root/bin/netc.exe $ygopro_root/netc.exe
popd


