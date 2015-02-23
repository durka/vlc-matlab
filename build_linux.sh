#!/usr/bin/env bash

# MEX VLC controller - build script for Linux

MATLAB=/usr/local/Matlab/R2014a

# change to directory that the script is in
cd `dirname $0`

# clear build files
rm vlc.mex*

# build
$MATLAB/bin/mex vlc.cpp vlcmex.cpp -g -lvlc

