#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define NAME "README.md"
#define MAX  1024

int
main(int argc, char *argv[])
{
    int fd;
    char line[MAX];
    size_t len = 0;
    
    fd = open(NAME, O_RDONLY);
    printf("Open file\n");
    sleep(1);

    read(fd, line, MAX);
    printf("Read file\n");
    sleep(1);

    close(fd);
    printf("Close file\n");
    
    return 0;
}
