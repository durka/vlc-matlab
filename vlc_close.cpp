#include <mex.h>
#include <vlc/vlc.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    switch (nrhs) {
        case 0:
            mexErrMsgIdAndTxt("VLC:vlc_close:tooFewArgs", "Not enough arguments");
            return;
        case 1:
            break;
        default:
            mexErrMsgIdAndTxt("VLC:vlc_close:tooManyArgs", "Too many arguments");
            return;
    }

    libvlc_media_player_t *player = *((libvlc_media_player_t**)(mxGetPr(prhs[0])));

    libvlc_media_player_release(player);
}

