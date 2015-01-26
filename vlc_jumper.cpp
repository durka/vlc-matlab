#include <mex.h>
#include <vlc/vlc.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    switch (nrhs) {
        case 0:
            mexErrMsgIdAndTxt("VLC:vlc_jumper:tooFewArgs", "Not enough arguments");
            return;
        case 1:
            break;
        default:
            mexErrMsgIdAndTxt("VLC:vlc_jumper:tooManyArgs", "Too many arguments");
            return;
    }

    if (mxGetM(prhs[0]) != 1) {
        mexErrMsgIdAndTxt("VLC:vlc_open:inputWrongShape", "Input string must be a row vector.");
        return;
    }

    char *filename = (char*)mxCalloc(mxGetN(prhs[0])+1, sizeof(char));
    if (mxGetString(prhs[0], filename, mxGetN(prhs[0])+1)) {
        mexWarnMsgIdAndTxt("VLC:vlc_open:stringError", "Error extracting filename argument.");
    }

    libvlc_instance_t *vlc = libvlc_new(0, NULL);

    libvlc_media_t *media = libvlc_media_new_path(vlc, filename);
    libvlc_media_player_t *player = libvlc_media_player_new_from_media(media);
    libvlc_media_release(media);
    
    libvlc_media_player_release(player);
    libvlc_release(vlc);
}

