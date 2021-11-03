SHELL=/bin/bash

CFLAGS= -ansi -Wall -Werror -Wpedantic -D_REENTRANT -D_THREAD_SAFE -D_POSIX_C_SOURCE=200112L

all:					funiviasemplice.exe

funiviasemplice.exe:	funiviasemplice.o DBGpthread.o
					gcc ${CFLAGS} -o funiviasemplice.exe funiviasemplice.o DBGpthread.o -lpthread

funiviasemplice.o:		funiviasemplice.c DBGpthread.h printerror.h
					gcc -c ${CFLAGS} funiviasemplice.c

DBGpthread.o:			DBGpthread.c printerror.h
					gcc -c ${CFLAGS} DBGpthread.c

.PHONY:					clean

clean:
					-rm -f *.o *.exe
