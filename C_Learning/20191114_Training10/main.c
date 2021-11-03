#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
    /*char *ptr_lettera;

    ptr_lettera = (char *) malloc(27*sizeof(char));
    printf("%p\n\n", &ptr_lettera);

    if(ptr_lettera == NULL)
    {
        puts("Memoria insufficiente");
        exit(1);
    }

    for(int i = 0; i < 27; i++)
        ptr_lettera[i] = 'a' + i;

    ptr_lettera[26] = '\0';

    for(int i = 0; i < 27; i++)
        printf("%c\n", ptr_lettera[i]);

    printf("%p\n\n", &ptr_lettera);

    free(ptr_lettera);*/

    //Il void non da nessun risultato in uscita e se indicato da usare in modo obbligatorio significa che viene richiesto un cast
    //di qualunque tipo di dato

    //REALLOC
    //Consente di prendere il blocco che avevamo precedentemente e di riallocarlo in un altro spazio di memoria.


     char *ptr_lettera;
     int numero_lettera;

    printf("%p\n\n", &ptr_lettera);

    scanf("%d", &numero_lettera);

    ptr_lettera = (char *) malloc(numero_lettera*sizeof(char));
    if(ptr_lettera == NULL)
    {
        puts("Memoria insufficiente");
        exit(1);
    }

    for(int i = 0; i < numero_lettera; i++)
        ptr_lettera[i] = 'a' + i;

    ptr_lettera[numero_lettera] = '\0';

    for(int i = 0; i < numero_lettera; i++)
        printf("%c\n", ptr_lettera[i]);

    printf("%p\n\n", &ptr_lettera);

    free(ptr_lettera);
    return 0;
}
