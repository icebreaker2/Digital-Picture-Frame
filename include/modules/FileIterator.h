#ifndef DIGITAL_PICTURE_FRAME_FILEITERATOR_H
#define DIGITAL_PICTURE_FRAME_FILEITERATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>

const char **getAllFilesFromDir(const char *dirPath, uint32_t** length);

#endif //DIGITAL_PICTURE_FRAME_FILEITERATOR_H
