#!/usr/bin/env bash

# MEX VLC controller - build script for Linux

# change to directory that the script is in
cd `dirname $0`

# clear build files
rm vlc.mex*

# build
mex vlc.cpp vlcmex.cpp -g -lvlc

