#include <mex.h>
#include <vlc/vlc.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    switch (nrhs) {
        case 0:
        case 1:
            mexErrMsgIdAndTxt("VLC:vlc_open:tooFewArgs", "Not enough arguments");
            return;
        case 2:
            break;
        default:
            mexErrMsgIdAndTxt("VLC:vlc_open:tooManyArgs", "Too many arguments");
            return;
    }

    libvlc_media_player_t *player = *((libvlc_media_player_t**)(mxGetPr(prhs[0])));

    libvlc_media_player_play(player);
    mexCallMATLAB(0, NULL, 1, (mxArray**)&prhs[1], "pause");
    libvlc_media_player_stop(player);
}

