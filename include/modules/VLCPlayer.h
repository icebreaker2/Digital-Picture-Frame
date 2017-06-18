#ifndef DIGITAL_PICTURE_FRAME_MOVPLAYER_H
#define DIGITAL_PICTURE_FRAME_MOVPLAYER_H

#include <vlc/vlc.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * Plays a *.mov video given the path to the file.
 * @param pathToFile Is the path to the *.mov file including the files name.
 * @return If the video fails false is returned otherwise true.
 */
bool playMovVideo(const char *pathToFile);

bool playMultipleMediaFiles(const char **fileList, uint32_t fileListLength);

#endif //DIGITAL_PICTURE_FRAME_MOVPLAYER_H
