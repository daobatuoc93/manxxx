#include <fcntl.h>
#include <sys/fcntl.h>
#include <sys/mman.h>

#include <sys/stat.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[])
{
    int fd;
    char *addr;
    struct stat sbuf;
    memset(&sbuf,0,sizeof(stat));
    if (argc != 2 || strcmp(argv[1], "--help") == 0)
    {
        printf("Usage: 2 option!\n");
    }

    fd = shm_open(argv[1], O_RDWR |O_RDONLY, 0); /* Open existing object */
    if (fd == -1)
        errExit("shm_open");
    /* Use shared memory object size as length argument for mmap()
and as number of bytes to write() */
    if (fstat(fd, &sbuf) == -1)
        errExit("fstat");
    addr = mmap(NULL, sbuf.st_size, PROT_READ, MAP_SHARED, fd, 0);
    
    if (addr == MAP_FAILED)
        errExit("mmap");
    if (close(fd) == -1) /* 'fd' is no longer needed */
        errExit("close");
    write(STDOUT_FILENO, addr, sbuf.st_size);
    printf("\n");
    exit(EXIT_SUCCESS);
}