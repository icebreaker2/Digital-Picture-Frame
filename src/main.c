#include <stdio.h>

#include "VLCPlayer.h"
#include "FileIterator.h"

int main() {

	uint32_t *length = calloc(sizeof(uint32_t), 1);
	const char **fileList = getAllFilesFromDir("/home/icebreaker/Pictures/PossiblePictures/", &length);

	playMultpleMediaFiles(fileList, *length);

	//playMovVideo("/home/icebreaker/Pictures/PossiblePictures");
	//playMovVideo("/home/icebreaker/Pictures/PossiblePictures/IMG_2235.MOV");
	//playMovVideo("/home/icebreaker/Pictures/PossiblePictures/IMG_2235.JPG");
	//playMovVideo("/home/icebreaker/Pictures/PossiblePictures/Moderation.mp4");

	return 0;
}