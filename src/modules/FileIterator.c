#include "FileIterator.h"

const char *concatenateString(const char *path, char name[256]);

/* This is just a sample code, modify it to meet your need */
FILE **getAllFilesFromDir(const char *dirPath) {
	DIR *FD;
	struct dirent *in_file;
	FILE *entry_file;
	char buffer[BUFSIZ];

	/* Scanning the in directory */
	if (NULL == (FD = opendir(dirPath))) {
		fprintf(stderr, "Error : Failed to open input directory - %s\n", strerror(errno));
		return NULL;
	}
	FILE **fileList = calloc(sizeof(FILE), 10000); // TODO fix to dynamic length

	int iteratorCounter = 0;
	while ((in_file = readdir(FD))) {
		/* On linux/Unix we don't want current and parent directories
		 * On windows machine too, thanks Greg Hewgill
		 */
		if (!strcmp(in_file->d_name, "."))
			continue;
		if (!strcmp(in_file->d_name, ".."))
			continue;
		/* Open directory entry file for common operation */
		/* TODO : change permissions to meet your need! */
		const char *fullFilePath = concatenateString(dirPath, in_file->d_name);
		entry_file = fopen(fullFilePath, "rw");
		if (entry_file == NULL) {
			fprintf(stderr, "Error : Failed to open entry file %s - %s\n", in_file->d_name, strerror(errno));
			return NULL;
		}

		/* Use fprintf or fwrite to write some stuff into common_file*/
		printf("File read %i: %s\n", iteratorCounter, in_file->d_name);
		fileList[iteratorCounter] = entry_file;
		iteratorCounter++;
	}

	return fileList;
}

const char *concatenateString(const char *path, char name[256]) {
	char *tmp = calloc(sizeof(const char), strlen(path) + 256);
	for (int i = 0; i < strlen(path); i++) {
		tmp[i] = path[i];
	}
	for (int i = 0; i < 256; i++) {
		tmp[i + strlen(path)] = name[i];
	}
	return tmp;
}
