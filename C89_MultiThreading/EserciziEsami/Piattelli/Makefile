cfalgs=-std=c99 -Wall -Wpedantic -D_C_POSIX_SORCE=200112L -D_THREAD_SAFE

all: piattello.exe

piattello.exe: piattello.o DBGpthread.o
	gcc -o piattello.exe piattello.o DBGpthread.o ${cflags} -lpthread

piattello.o: piattello.c DBGpthread.h printerror.h
	gcc -c piattello.c ${cflags}

DBGpthread.o: DBGpthread.c printerror.h
	gcc -c DBGpthread.c ${cflags}

.PHONY: clean

clean: 
	-rm *.o *.exe
