#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CARATTERE '#'

int main()
{
    char ch, bufferA[100];
    int index = 0, counter1 = 0, space = 0;

    memset(bufferA, '\0', sizeof(bufferA));                            //riempe il buffer con caratteri di terminazione

    while ((ch = getchar()) != CARATTERE)                                 //salva in un buffer la stringa e ne analizza lettera per lettera. finchè il carattere è diverso si entra nel while. altrimenti no
{
    bufferA[index++]=ch;

        if(ch=='a'){
            counter1 = counter1 + 1;
        }
        if(ch==' '){
            space++;
        }

}
    printf("\n\nstringa %s\n", bufferA);
    printf("num of a%d\n", counter1);
    printf("space %d\n", space);

    return 0;

    }
