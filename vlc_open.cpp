#include "vlcmex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (!check_args(nrhs, 2)) return;

    if (mxGetM(prhs[1]) != 1) {
        mexErrMsgIdAndTxt("VLC:vlc_open:inputWrongShape", "Input string must be a row vector.");
        return;
    }

    char *filename = (char*)mxCalloc(mxGetN(prhs[1])+1, sizeof(char));
    if (mxGetString(prhs[1], filename, mxGetN(prhs[1])+1)) {
        mexWarnMsgIdAndTxt("VLC:vlc_open:stringError", "Error extracting filename argument.");
    }

    unpack_pointer(libvlc_instance_t, vlc, prhs[0]);

    libvlc_media_t *media = libvlc_media_new_path(vlc, filename);
    libvlc_media_player_t *player = libvlc_media_player_new_from_media(media);
    libvlc_media_release(media);
    
    libvlc_media_player_play(player);
    while (!libvlc_media_player_is_playing(player));
    libvlc_media_player_pause(player);
    
    pack_pointer(plhs[0], player);
}

