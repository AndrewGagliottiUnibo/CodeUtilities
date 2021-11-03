#nome modulo main
NOME_MAIN=pontepericolante_semplice
SHELL=/bin/bash

#define da usare
DEFINE_LIST=

#DEBUG - commentare una delle due righe
#DEBUG_MODE=-DDEBUG
DEBUG_MODE=

#percorso headers vari
PATH_HEADERS=#-I

#opzioni di compilazione gcc
CFLAGS=${PATH_HEADERS} -ansi -Wpedantic -Wall -Werror ${DEFINE_LIST} ${DEBUG_MODE}

#opzioni di linking gcc
LFLAGS=-lpthread

#nei seguenti comandi trovo i rimandi ai target e alle dipendenze secondo questa notazione:
#$@ - contiene il nome del target
#$< - contiene il nome della prima dipendenza di un rispettivo target
#$^ - contiene i nomi di tutte le dipendenze
all:                    ${NOME_MAIN}.exe

${NOME_MAIN}.exe:       ${NOME_MAIN}.o DBGpthread.o
					gcc -o $@ $^ ${LFLAGS}

${NOME_MAIN}.o:         ${NOME_MAIN}.c DBGpthread.h printerror.h Makefile
					gcc -c -o $@ ${CFLAGS} $<

DBGpthread.o:           DBGpthread.c DBGpthread.h printerror.h Makefile
					gcc -c -o $@ ${CFLAGS} $<

.PHONY: clean

clean:
					-rm -f ${NOME_MAIN}.exe *.o *~ 
