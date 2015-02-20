#ifndef _VLC_MEX_H_
#define _VLC_MEX_H_

#include <mex.h>
#include <vlc/vlc.h>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
using std::vector;
using std::string;
using std::list;
using std::map;
using std::find;

typedef list<libvlc_instance_t*> instance_list;
typedef list<libvlc_media_player_t*> player_list;

#ifdef __APPLE__
typedef void NSWindow;
typedef void NSView;
extern "C" {
    NSView* create_window(NSWindow**, float, float, float, float);
    void close_window(NSWindow*);
}
typedef map<libvlc_media_player_t*, NSWindow*> window_list;
#endif

bool check_args(int nrhs, int n);
bool check_args(int nrhs, int m, int n);

string arr2str(const mxArray *arr);

void* unpack_pointer_INTERNAL(const mxArray *arr);
#define unpack_pointer(T,arr) ((T*)unpack_pointer_INTERNAL(arr))
void pack_pointer_INTERNAL(mxArray **arr, void *p);
#define pack_pointer(arr,p) pack_pointer_INTERNAL(&(arr), (void*)(p))
void pack_number_INTERNAL(mxArray **arr, double d);
void pack_number_INTERNAL(mxArray **arr, vector<double> vd);
#define pack_number(arr,d) pack_number_INTERNAL(&(arr), d)

#endif // _VLC_MEX_H_

