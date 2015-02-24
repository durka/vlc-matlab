@rem MEX VLC controller - build script for Windows

@rem change to directory that the script is in
cd /d %0\..

@rem clear build files
del vlc.mex*

@rem build
mex -outdir %CD% vlc.cpp vlcmex.cpp -g -I%CD%\win\include -L%CD%\win -lvlc

