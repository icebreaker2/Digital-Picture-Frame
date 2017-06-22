#include "FileIterator.h"

/**
 * Concatenates two strings. In this example: The filename is added to the path. This function is private.
 * @param path Is the path where to look for media files.
 * @param name Is a filename to add to the path.
 * @return The path including the filename as a new string.
 */
const char *concatenateString(const char *path, char name[256]);

/**
 *
 * @param dirPath Is the path to the media dir where to fet the file names from.
 * @param length Is a referenced pointer to store the amount of files at.
 * @return Is a list of file names including their paths.
 */
const char **getAllFilePathFromDir(const char *dirPath, uint32_t **length) {
	DIR *FD;
	struct dirent *in_file;
	FILE *entry_file;
	char buffer[BUFSIZ];

	/* Scanning the in directory */
	if (NULL == (FD = opendir(dirPath))) {
		fprintf(stderr, "Error : Failed to open input directory - %s\n", strerror(errno));
		return NULL;
	}
	const char **fileList = calloc(sizeof(const char), 10000); // TODO fix to dynamic length

	uint32_t iteratorCounter = 0;
	while ((in_file = readdir(FD))) {
		/* On linux/Unix we don't want current and parent directories
		 * On windows machine too, thanks Greg Hewgill
		 */
		if (!strcmp(in_file->d_name, "."))
			continue;
		if (!strcmp(in_file->d_name, ".."))
			continue;
		/* Open directory entry file for common operation */
		const char *fullFilePath = concatenateString(dirPath, in_file->d_name);
		entry_file = fopen(fullFilePath, "rw");
		if (entry_file == NULL) {
			fprintf(stderr, "Error : Failed to open entry file %s - %s\n", in_file->d_name, strerror(errno));
			return NULL;
		}

		fileList[iteratorCounter] = fullFilePath;
		iteratorCounter++;
	}

	*length = &iteratorCounter;

	return fileList;
}

/**
 * Concatenates two strings. In this example: The filename is added to the path. This function is private.
 * @param path Is the path where to look for media files.
 * @param name Is a filename to add to the path.
 * @return The path including the filename as a new string.
 */
const char *concatenateString(const char *path, char name[256]) {
	char *tmp = calloc(sizeof(const char), strlen(path) + 256);
	int i = 0;
	for (i; i < strlen(path); i++) {
		tmp[i] = path[i];
	}
	for (i = 0; i < 256; i++) {
		tmp[i + strlen(path)] = name[i];
	}
	return tmp;
}
