#include "vlcmex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (!check_args(nrhs, 2)) return;

    unpack_pointer(libvlc_media_player_t, player, prhs[0]);

    libvlc_media_player_set_time(player, mxGetPr(prhs[1])[0]);
}

