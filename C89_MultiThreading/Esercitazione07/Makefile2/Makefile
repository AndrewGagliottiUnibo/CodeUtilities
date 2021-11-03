FLAG= -ansi -Wpedantic -Wall -Werror

all:		main.exe

main.exe:	main.o 
		gcc ${FLAG} -o main.o -lm macro.h

main.o:		main.c macro.h
		gcc ${FLAG} -c main.c

.PHONY:		clean

clean:
		rm -rf main.exe main.o quadrato.o dimezza.o