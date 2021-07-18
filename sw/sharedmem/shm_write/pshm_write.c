#include <fcntl.h>
#include <sys/mman.h>
#include "tlpi_hdr.h"
int main(int argc, char *argv[])
{
    int fd;
    size_t len; /* Size of shared memory object */
    void *pCapManSMA;
    if (argc != 3 || strcmp(argv[1], "--help") == 0)
        usageErr("%s shm-name string\n", argv[0]);
    fd = shm_open(argv[1], O_RDWR , (mode_t)0600); /* Open existing object */
    if (fd == -1)
        errExit("shm_open");
    len = strlen(argv[2]);
    // fix bug here:

    if (ftruncate(fd, len) == -1) /* Resize object to hold string */
        errExit("ftruncate");
    //if(len ==0){
        //errExit("error len of string");
    //}
    //printf("Resized to %ld bytes\n", (long)len);
    pCapManSMA = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    
    if(pCapManSMA == MAP_FAILED)
        errExit("mmap");
    if (close(fd) == -1)
        errExit("close"); /* 'fd' is no longer needed */
    

    printf("copying %ld bytes\n", (long)len);
    memcpy(pCapManSMA, argv[2], len); /* Copy string to shared memory */
    // I just refer here as capman try to refer the data in shared memory area
    // this line similiar if(pCapManSMA->magic.... != abcxyz)
    //printf("printf: %s \n",pCapManSMA);
    exit(EXIT_SUCCESS);
}