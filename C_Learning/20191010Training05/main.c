#include <stdio.h>

char letteraAlfabeto;

int main()
{
    for (letteraAlfabeto = 'a'; letteraAlfabeto <= 'z'; letteraAlfabeto++)
    {
        printf("Lettera %c\n", letteraAlfabeto);
    }

    printf ("\n\n");

    for (letteraAlfabeto = 97; letteraAlfabeto <= 122; letteraAlfabeto++)

    {
        printf("Lettera %c\n", letteraAlfabeto);
    }

    return 0;
}
