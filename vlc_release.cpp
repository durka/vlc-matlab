#include <mex.h>
#include <vlc/vlc.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    switch (nrhs) {
        case 0:
            mexErrMsgIdAndTxt("VLC:vlc_release:tooFewArgs", "Not enough arguments");
            return;
        case 1:
            break;
        default:
            mexErrMsgIdAndTxt("VLC:vlc_release:tooManyArgs", "Too many arguments");
            return;
    }

    libvlc_instance_t *vlc = *((libvlc_instance_t**)(mxGetPr(prhs[0])));

    libvlc_release(vlc);
}

