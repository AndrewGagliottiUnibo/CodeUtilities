#include <stdio.h>
#include <stdlib.h>

int main(){
	int numero1, numero2, verifica;

	puts("Inserire due numeri interi separati da uno spazio bianco:");
	verifica = scanf("%d %d", &numero1, &numero2);
    fflush(stdin);
    if (verifica==2)
        printf("Hai inserito: %d e %d\n", numero1, numero2);
    else
        printf("Almeno un valore inserito non e\' un intero!\n");

    printf("\n\n\n");
    system("PAUSE");
    return 0;
}

