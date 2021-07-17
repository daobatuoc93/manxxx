Obj := get_num.o error_functions.o
Header := tlpi_hdr.h get_num.h error_functions.h
SUBDIRS = capmanPMD shm_write shm_read shm_unlink

capmanPMD: get_num.c error_functions.o capmanPMD.o
			gcc -Wall -o capmanPMD capmanPMD.o $(Obj) -lrt

shm_write: $(Obj) pshm_write.o tlpi_hdr.h
			gcc -Wall -o shm_write pshm_write.o $(Obj) -lrt
shm_read : $(Obj) pshm_read.o tlpi_hdr.h
			gcc -o shm_read pshm_read.o $(Obj) -lrt

shm_unlink: $(Obj) pshm_unlink.o tlpi_hdr.h
			gcc -o shm_unlink pshm_unlink.o $(Obj) -lrt

error_functions.o : $(Header)

pshm_read.o capmanPMD.o  pshm_write.o pshm_unlink.o: $(Obj) $(Header)

get_num.o :  $(Header)

.PHONY: subdirs $(SUBDIRS) clean

subdirs: $(SUBDIRS)

clean :
		rm -f shm_read shm_write capmanPMD *.o 
