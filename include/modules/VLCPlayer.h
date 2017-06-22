#ifndef DIGITAL_PICTURE_FRAME_MOVPLAYER_H
#define DIGITAL_PICTURE_FRAME_MOVPLAYER_H

#include <vlc/vlc.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * Plays every known media file with vlc in full screen. Once the method is called it screens the media forever.
 * @param fileList Is a list of file names including their paths. The names and paths are used by vlc to play them.
 * @param fileListLength Is the length of the list.
 */
void playMultipleMediaFiles(const char **fileList, uint32_t fileListLength);

#endif //DIGITAL_PICTURE_FRAME_MOVPLAYER_H
