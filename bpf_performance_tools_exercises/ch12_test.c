#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>

const char * find_path(const char *file_name, const char character)
{
	char *path = malloc(strlen(file_name));
	int pos;

	printf("\nfile_name %s\n", file_name);

	for (pos = strlen(file_name); pos > 0; pos--) {
		if(file_name[pos] == character) {
			break;
		}
	}

	printf("pos %d\n", pos);

	if (pos > 0) {
		strncpy(path, file_name, pos+1);
		printf("path %s\n", path);
	} else {
		memcpy(path, file_name, strlen(file_name));
		printf("not a good idea\n");
	}

	return path;
}


int
main(int argc, char *argv[])
{
	struct stat buffer;
	const char *file_name = "/tmp/non_existing.socket";
	const char *another_file_name = "./tests.c";
	const char *yet_another_file_name = "/tmp/abc/cda/bgf/socket.socket";
	const char *test_path = "/tmp";
	const char *another_test_path = "/";
	char *path;
	int result;

	path = find_path(file_name,'/');
	result = stat (path, &buffer);
	if (result != 0) {
		printf("result %d, errno %m\n", result);
	}

	path = find_path(another_file_name,'/');
	result = stat (path, &buffer);
	if (result != 0) {
		printf("result %d, errno %m\n", result);
	}

	path = find_path(yet_another_file_name,'/');
	result = stat (path, &buffer);
	if (result != 0) {
		printf("result %d, errno %m\n", result);
	}

	path = find_path(test_path,'/');
	result = stat (path, &buffer);
	if (result != 0) {
		printf("result %d, errno %m\n", result);
	}

	path = find_path(another_test_path,'/');
	result = stat (path, &buffer);
	if (result != 0) {
		printf("result %d, errno %m\n", result);
	}
}
