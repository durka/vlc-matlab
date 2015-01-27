#include "vlcmex.h"
#include <string>
using std::string;

bool check_args(int nrhs, int n)
{
    if (nrhs > n) {
        mexErrMsgIdAndTxt(("VLC:"
                           + string(mexFunctionName())
                           + ":tooManyArgs").c_str(),
                          "Too many arguments");
        return false;
    } else if (nrhs < n) {
        mexErrMsgIdAndTxt(("VLC:"
                           + string(mexFunctionName())
                           + ":tooFewArgs").c_str(),
                          "Not enough arguments");
        return false;
    }
    return true;
}

void* unpack_pointer_INTERNAL(const mxArray *arr)
{
    return *((void**)(mxGetPr(arr)));
}

void pack_pointer_INTERNAL(mxArray **arr, void *p)
{
    *arr = mxCreateDoubleMatrix(1, 1, mxREAL);
    *((void**)(mxGetPr(*arr))) = p;
}

