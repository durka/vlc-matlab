#include <mex.h>
#include <vlc/vlc.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs > 0) {
        mexErrMsgIdAndTxt("VLC:vlc_init:tooManyArgs", "Too many arguments");
        return;
    }

    libvlc_instance_t *vlc = libvlc_new(0, NULL);

    plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
    *((libvlc_instance_t**)(mxGetPr(plhs[0]))) = vlc;
}

