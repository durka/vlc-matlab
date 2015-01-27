#ifndef _VLC_MEX_H_
#define _VLC_MEX_H_

#include <mex.h>
#include <vlc/vlc.h>
#include <list>
#include <algorithm>
using std::list;
using std::find;

typedef list<libvlc_instance_t*> vlc_instance_list;
typedef list<libvlc_media_player_t*> vlc_player_list;
extern vlc_instance_list vlc_instances;
extern vlc_player_list vlc_players;

bool check_args(int nrhs, int n);

void* unpack_pointer_INTERNAL(const mxArray *arr);
void pack_pointer_INTERNAL(mxArray **arr, void *p);
#define unpack_pointer(T,name,arr) T* name = (T*)unpack_pointer_INTERNAL(arr)
#define pack_pointer(arr,p) pack_pointer_INTERNAL(&(arr), (void*)(p))

#endif // _VLC_MEX_H_

