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

/**
 *
 * @param dirPath Is the path to the media dir where to fet the file names from.
 * @param length Is a referenced pointer to store the amount of files at.
 * @return Is a list of file names including their paths.
 */
const char **getAllFilePathFromDir(const char *dirPath, uint32_t** length);

#endif //DIGITAL_PICTURE_FRAME_FILEITERATOR_H
