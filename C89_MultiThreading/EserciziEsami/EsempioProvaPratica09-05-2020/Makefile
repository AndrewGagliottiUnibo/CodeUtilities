cflags=-std=c99 -Wall -Wpedantic -D_POSIX_C_SOURCE=200112L -D_DEBUG

all: Esame

Esame: studenti.o DBGpthread.o
	gcc -o Esame studenti.o DBGpthread.o ${cflags} -lpthread

studenti.o: studenti.c printerror.h DBGpthread.h
	gcc -c studenti.c ${cflags}

DGBpthread.o: DGBpthread.c DGBpthread.h printerror.h
	gcc -c DGBpthread.c ${cflags}

.PHONY: clean

clean: 
	-rm *.o Esame
