#include "vlcmex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (!check_args(nrhs, 1)) return;

    unpack_pointer(libvlc_instance_t, vlc, prhs[0]);

    libvlc_release(vlc);
}

