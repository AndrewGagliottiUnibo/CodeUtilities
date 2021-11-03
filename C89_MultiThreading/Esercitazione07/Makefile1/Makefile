FLAG= -ansi -Wpedantic -Wall -Werror

all:    main.exe

main.exe:    main.o quadrato.o dimezza.o
        gcc ${FLAG} -o main.exe main.o quadrato.o dimezza.o -lm

main.o: main.c dimezza.h quadrato.h
        gcc ${FLAG} -c main.c

quadrato.o:	quadrato.c
        gcc ${FLAG} -c quadrato.c

dimezza.o:  dimezza.c
        gcc ${FLAG} -c dimezza.c

.PHONY: clean

clean:
    rm -rf main.exe main.o quadrato.o dimezza.o