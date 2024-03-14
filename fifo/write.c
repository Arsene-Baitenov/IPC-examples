#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define NAMEDPIPE_NAME "/tmp/named_pipe"
#define BUFSIZE        50

int main (int argc, char ** argv) {
    int fd, len;

    if (argc != 2) {
        printf("Need 1 message\n");
        return 2;
    }

    if ( (fd = open(NAMEDPIPE_NAME, O_WRONLY)) <= 0 ) {
        perror("open");
        return 1;
    }
    printf("%s is opened\n", NAMEDPIPE_NAME);

    int size = 0;
    size = strlen(argv[1]);
    if (size > BUFSIZE-1) {
        printf("\"%s\" length more than %d\n", argv[1], (BUFSIZE-1));
        return 0;
    }
    if ( (len = write(fd, argv[1], size)) <= 0 ) {
        perror("write");
        close(fd);
        remove(NAMEDPIPE_NAME);
        return 0;
    }
    printf("Outcomming message (%d): %s\n", len, argv[1]);
}