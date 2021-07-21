#include <sys/stat.h>
#include <fcntl.h>
#include "../h/tlpi_hdr.h"
#ifndef BUF_SIZE /* Allow "cc -D" to override definition */
#define BUF_SIZE 1024
#endif
int main(int argc, char *argv[])
{
    int inputFd, outputFd, openFlags;
    mode_t filePerms;
    ssize_t numRead;
    char buf[BUF_SIZE];
    //memset(buf,0,sizeof(buf));
    if (argc != 3 || strcmp(argv[2], "-h") == 0 || strcmp(argv[2], "--help") == 0)
    {
        usageErr("%s filesource filcedes", argv[0]);
    }

    inputFd = open(argv[1], 0);
    if (inputFd == -1)
    {
        errExit("opening file: %s", argv[1]);
    }

    char deviceMod[32];

    memset(deviceMod,0,sizeof(deviceMod));


    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                S_IROTH | S_IWOTH; /* rw-rw-rw- */

    /* Open input and output files */
    //if the file doesn't exist,open may create based on the flag set(O_CREAT) if not,the mode can be omitted
    outputFd = open(argv[2], openFlags, filePerms);
    if (outputFd == -1)
    {
        errExit("opening file: %s", argv[2]);
    }

    /* Transfer data until we encounter end of input or an error */
    while ((numRead = read(inputFd, buf, BUF_SIZE)) > 0)
    {
        if (write(outputFd, buf, numRead) != numRead)
            fatal("couldn't write whole buffer");
    }

    if (numRead == -1)
        errExit("read");

    if (close(inputFd) == -1)
        errExit("close input");

    if (close(outputFd) == -1)
        errExit("close output");
        
    exit(EXIT_SUCCESS);
}
