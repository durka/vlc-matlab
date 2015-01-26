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

    if (mxGetM(prhs[1]) != 1) {
        mexErrMsgIdAndTxt("VLC:vlc_open:inputWrongShape", "Input string must be a row vector.");
        return;
    }

    char *filename = (char*)mxCalloc(mxGetN(prhs[1])+1, sizeof(char));
    if (mxGetString(prhs[1], filename, mxGetN(prhs[1])+1)) {
        mexWarnMsgIdAndTxt("VLC:vlc_open:stringError", "Error extracting filename argument.");
    }

    libvlc_instance_t *vlc = *((libvlc_instance_t**)(mxGetPr(prhs[0])));

    libvlc_media_t *media = libvlc_media_new_path(vlc, filename);
    libvlc_media_player_t *player = libvlc_media_player_new_from_media(media);
    libvlc_media_release(media);
    
    plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
    *((libvlc_media_player_t**)(mxGetPr(plhs[0]))) = player;
}

