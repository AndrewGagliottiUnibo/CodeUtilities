CFLAGS=-ansi -Wpedantic -Wall -Werror -D_POSIX_SOURCE

all: 	dammi_il_precedente.exe 

dammi_il_precedente.exe: dammi_il_precedente.o
	gcc ${CFLAGS} -o dammi_il_precedente.exe dammi_il_precedente.o ${LIBRARIES}

dammi_il_precedente.o: dammi_il_precedente.c
	gcc ${CFLAGS} -c dammi_il_precedente.c ${LIBRARIES}


.PHONY:	clean

clean:
	rm -f dammi_il_precedente.o dammi_il_precedente.exe 
