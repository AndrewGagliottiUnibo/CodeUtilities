/*
preso in ingresso una lettera dall'utente se si tratta di una lettera in minuscolo
restituisce la corrispondente in maiuscolo, l'inverso altrimenti
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char lettera;

    printf("Inserire una lettera e premere INVIO: ");
    scanf("%c", &lettera);
    fflush(stdin);
    if (lettera >= 65 && lettera <= 90) {
        printf("hai inserito una lettera in maiuscolo\n");
        lettera += 32;
        printf("corrispondente della lettera in minuscolo: %c", lettera);
    }
    else {
        if (lettera >= 97 && lettera <= 122) {
            printf("hai inserito una lettera in minuscolo\n");
            lettera -= 32;
            printf("corrispondente della lettera in maiuscolo: %c", lettera);
        }
        else {
            printf("non hai inserito una lettera dell'alfabeto, conversione non possibile, %d");
        }
    }

    printf("\n\n");
    system("pause");
    return 0;
}
