FLAGS=-ansi -Wpedantic -Wall -D_THREAD_SAFE -D_REENTRANT -DPOSIX_C_SOURCE=200112L
LFLAG=-lpthread

all:		main.exe

main.exe:	main.o
		gcc ${FLAGS} -o main.exe main.o ${LFLAG}

main.o:		main.c
		gcc -c ${FLAGS} main.c

.PHONY:		clean

clean::
			rm -rf main.exe main.o