#include <iostream>
#include <vlc/vlc.h>
using namespace std;

int main(int argc, char *argv[])
{
    libvlc_instance_t *vlc = libvlc_new(0, NULL);
    libvlc_media_t *media = libvlc_media_new_path(vlc, argv[1]);
    libvlc_media_player_t *player = libvlc_media_player_new_from_media(media);
    libvlc_media_release(media);

    libvlc_media_player_play(player);
    while (!libvlc_media_player_is_playing(player));
    libvlc_media_player_pause(player);

    float a = 0;
    while (true) {
        cin >> a;
        if (a < 0) break;
        libvlc_media_player_set_time(player, a);
    }

    libvlc_media_player_release(player);
    libvlc_release(vlc);

    return 0;
}

