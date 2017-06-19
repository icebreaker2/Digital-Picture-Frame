#!/bin/bash
# Digital Picture Frame Start Script

gcc -std=c99 -Wall -Iinclude/modules src/modules/VLCPlayer.c src/modules/FileIterator.c src/main.c -o digitalPictureFrame -lvlc
echo "Digital Picture Frame compiled successfully!"
./digitalPictureFrame