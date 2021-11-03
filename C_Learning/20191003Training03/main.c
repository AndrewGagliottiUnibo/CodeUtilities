#include <stdio.h>
#include <stdlib.h>

int main()
{
    int HH, MM;
    char sign;

    //primo mom per farlo
    printf("Immettere l'ora attuale in HH:MM: ");
    scanf("%2d%[:,.,_]%2d", &HH, &sign, &MM);
    fflush(stdin);

    printf("\n\nSono le: %02d%c%02d.\n", HH, sign, MM);

    system("pause");

    //secondo modo di farlo
    printf("Immettere l'ora attuale in HH:MM: ");
    scanf("%2d%c%2d", &HH, &sign, &MM);
    fflush(stdin);

    printf("\n\nSono le: %02d:%02d.\n", HH, MM);

    system("pause");
    return 0;
}

//terzo modo disponibile nella dispensa 04
