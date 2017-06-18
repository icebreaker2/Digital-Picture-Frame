#ifndef DIGITAL_PICTURE_FRAME_FILEITERATOR_H
#define DIGITAL_PICTURE_FRAME_FILEITERATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>

FILE **getAllFilesFromDir(const char *dirPath);

#endif //DIGITAL_PICTURE_FRAME_FILEITERATOR_H
