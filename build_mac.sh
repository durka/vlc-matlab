#!/usr/bin/env bash

# MEX VLC controller - build script for Linux

MATLAB=~/Applications/MATLAB_R2014b.app

# change to directory that the script is in
cd `dirname $0`

# clear build files
rm vlc.mex*

# build XCode
cd osx/MexWindowHelper
xcodebuild clean
xcodebuild build
cd ../..

# build MEX
$MATLAB/bin/mex vlc.cpp vlcmex.cpp -g -lvlc -lMexWindowHelper -I/Applications/VLC.app/Contents/MacOS/include -L/Applications/VLC.app/Contents/MacOS/lib -Losx/MexWindowHelper/build/Release
install_name_tool -change @loader_path/lib/libvlc.5.dylib /Applications/VLC.app/Contents/MacOS/lib/libvlc.5.dylib vlc.mexmaci64
install_name_tool -change /usr/local/lib/libMexWindowHelper.dylib osx/MexWindowHelper/build/Release/libMexWindowHelper.dylib vlc.mexmaci64
