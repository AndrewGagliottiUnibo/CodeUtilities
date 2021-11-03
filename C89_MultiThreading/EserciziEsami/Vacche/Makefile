cflags=-std=c99 -Wall -Wpedantic -D_POSIX_C_SOURCE=200112L -DTHREAD_SAFE

all: a.out

a.out: vacche.o DBGpthread.o
	gcc -o a.out vacche.o DBGpthread.o ${cflags} -lpthread

vacche.o: vacche.c printerror.h DBGpthread.h
	gcc -c vacche.c ${cflags}

DBGpthread.o: DBGpthread.c printerror.h
	gcc -c DBGpthread.c ${cflags}

.PHONY: clean

clean: 
	-rm *.o a.out

