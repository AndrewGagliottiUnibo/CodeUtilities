# Makefile per es6_eliminaDaLista.c

CFLAGS=-ansi -Wpedantic -Wall -D_POSIX_SOURCE=1 -D_POSIX_C_SOURCE=200112L

all: 	es6_eliminaDaLista.exe

es6_eliminaDaLista.exe: es6_eliminaDaLista.o
	gcc -o es6_eliminaDaLista.exe ${CFLAGS} es6_eliminaDaLista.o

es6_eliminaDaLista.o: es6_eliminaDaLista.c
	gcc -c ${CFLAGS} es6_eliminaDaLista.c

.PHONY:	clean

clean:
	rm -f es6_eliminaDaLista.o es6_eliminaDaLista.exe