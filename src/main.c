#include <stdio.h>

#include "VLCPlayer.h"
#include "FileIterator.h"

int main() {
	printf("Hello, World!\n");

	FILE** fileList = getAllFilesFromDir("/home/icebreaker/Pictures/PossiblePictures/");

	//playMovVideo("/home/icebreaker/Pictures/PossiblePictures");
	//playMovVideo("/home/icebreaker/Pictures/PossiblePictures/IMG_2235.MOV");
	//playMovVideo("/home/icebreaker/Pictures/PossiblePictures/IMG_2235.JPG");
	//playMovVideo("/home/icebreaker/Pictures/PossiblePictures/Moderation.mp4");

	return 0;
}