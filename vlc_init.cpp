#include "vlcmex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (!check_args(nrhs, 0)) return;

    libvlc_instance_t *vlc = libvlc_new(0, NULL);
    vlc_instances.push_back(vlc);

    pack_pointer(plhs[0], vlc);
}

