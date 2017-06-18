# Digital-Picture-Frame
A digital picture frame software for anyone. The software detects pictures and videos (*.mov) videos at any usb port your device provides. After detecting the *Digital Picture Frame* frames the pictures and videos one by one like a screensaver.

## Installation

### Prerequisites
Make sure you have the following components installed

* [CMake](https://cmake.org/download/)
* A [c-Compiler](https://wiki.ubuntuusers.de/GCC/).
* [dev](http://www.videolan.org/vlc/index.de.html) package
* [libvlc-dev](https://wiki.videolan.org/LibVLC_Tutorial/) package

### Software install
```bash
git clone https://github.com/icebreaker2/Digital-Picture-Frame.git
cd Digital-Picture-Frame
```

Now run start the `CMakeLists.txt` or compile yourself (familiar to):
```bash
gcc -std=c99 -Wall -Iinclude/modules src/modules/VLCPlayer.c src/modules/FileIterator.c src/main.c -o main -lvlc 
```

## Developer Notes
To be continued...