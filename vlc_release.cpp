#include "vlcmex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (!check_args(nrhs, 1)) return;

    unpack_pointer(libvlc_instance_t, vlc, prhs[0]);
    vlc_instance_list::iterator iter = find(vlc_instances.begin(), vlc_instances.end(), vlc);
    if (iter == vlc_instances.end()) {
        mexErrMsgIdAndTxt("VLC:vlc_release:invalidHandle", "Not a VLC instance");
        return;
    }

    vlc_instances.erase(iter);
    libvlc_release(vlc);
}

