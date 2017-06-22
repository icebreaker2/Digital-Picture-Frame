#include <stdio.h>

#include "VLCPlayer.h"
#include "FileIterator.h"

int main() {

	uint32_t *length = calloc(sizeof(uint32_t), 1);
	const char **fileList = getAllFilePathFromDir("/Your/Path/To/The/Media/Dir", &length);

	playMultipleMediaFiles(fileList, *length);
	return 0;
}