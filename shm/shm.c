#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define SHARED_MEMORY_OBJECT_NAME "shared_memory"
#define SHARED_MEMORY_OBJECT_SIZE 50
#define SHM_CREATE 1
#define SHM_WRITE 2
#define SHM_READ  3

void usage(const char * s) {
    printf("Usage: %s <create|write|read|unlink> ['text']\n", s);
}

int main (int argc, char ** argv) {
    int shm, len, cmd, mode = 0;
    char *addr;

    if (argc < 2) {
        usage(argv[0]);
        return 1;
    }

    if (!strcmp(argv[1], "create")) {
        mode = O_CREAT;
        cmd = SHM_CREATE;
    } else if (!strcmp(argv[1], "write") && (argc == 3)) {
        len = strlen(argv[2]);
        len = (len<=SHARED_MEMORY_OBJECT_SIZE)?len:SHARED_MEMORY_OBJECT_SIZE;
        cmd = SHM_WRITE;
    } else if (!strcmp(argv[1], "read")) {
        cmd = SHM_READ;
    } else if (!strcmp(argv[1], "unlink")) {
        shm_unlink(SHARED_MEMORY_OBJECT_NAME);
        return 0;
    } else {
        usage(argv[0]);
        return 1;
    }

    if ( (shm = shm_open(SHARED_MEMORY_OBJECT_NAME, mode|O_RDWR, 0777)) == -1 ) {
        perror("shm_open");
        return 1;
    }

    if ( cmd == SHM_CREATE ) {
        if ( ftruncate(shm, SHARED_MEMORY_OBJECT_SIZE+1) == -1 ) {
            perror("ftruncate");
            return 1;
        }
    } else {
        addr = mmap(0, SHARED_MEMORY_OBJECT_SIZE+1, PROT_WRITE|PROT_READ, MAP_SHARED, shm, 0);
        if ( addr == (char*)-1 ) {
            perror("mmap");
            return 1;
        }

        switch ( cmd ) {
        case SHM_WRITE:
            memcpy(addr, argv[2], len);
            addr[len] = '\0';
            printf("Msg: %s\n", argv[2]);
            break;
        case SHM_READ:
            printf("Msg: %s\n", addr);
            break;
        }

        munmap(addr, SHARED_MEMORY_OBJECT_SIZE);
    }
    
    close(shm);
}