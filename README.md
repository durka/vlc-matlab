# vlc-matlab
Thin, limited Matlab wrapper for libvlc to do fast video playback

# What is this?
I needed real time video playback, synchronized with other data visualization happening in Matlab at the same time. In all my experiments, Matlab _really sucks_ at real time video playback. Even opening the video file takes a prohibitively long time, and then you can only plod along drawing one... frame... at... a... time. Synchronously. Meanwhile, I noticed that VLC is available on nearly every platform and is _great_ at real-time video playback. I decided that rather than try to reinvent the wheel in Matlab, I should just try to glue on VLC's existing wheel. This wrapper does that.

# Where does it work?
The wrapper has been tested and works on at least these platforms:

- Linux (Ubuntu 14.04)
- Mac OS X (10.9.5)
- Windows 7, 8

Software dependencies are (obviously) Matlab and VLC:

- Matlab (tested on versions 2014a and 2014b)
- VLC (tested using version 2.1.5)

# What can the wrapper do?
The functionality is very limited. You can get a handle to a VLC object. Armed with this handle, you can open a video file (which returns another handle to the media). A window is automatically created. With the media handle you can get basic information (frame rate and length), play and pause the media, seek to a specific point, or query the current position.

That's it! I wrapped the functions I needed and no more. Feature requests (or pull requests!) welcome if you need more features.

Planned features:

- Matlab facility for adaptively synchronizing a timer with the video

