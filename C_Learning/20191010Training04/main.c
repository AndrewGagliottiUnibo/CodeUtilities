#include <stdio.h>
#include <stdlib.h>

int main()
{
    char lettera1;

    printf("Inserisci una lettera in minuscolo appartenente all'alfabeto italiano:\n");
    scanf("%c", &lettera1);
    fflush(stdin);
    printf("\n\n");

    switch(lettera1)
    {
        case 'a'...'z':
            printf("%c\n\n", lettera1 - 32);
            break;
        case 'A'...'Z':
            printf("%c\n\n", lettera1 + 32);
            break;
        default:
            printf("Hai inserito un carattere non corretto.\n\n");

    }
}
