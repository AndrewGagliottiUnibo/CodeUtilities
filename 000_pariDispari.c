/*
numero pari o dispari,
il programma utilizza esclusivamente
istruzioni if
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numero;

	printf("inserisci un numero: ");
	scanf("%d",&numero);
	fflush(stdin);

	if ((numero % 2) == 0)
		printf("\nIl numero inserito e' PARI");
	else
		printf("\nIl numero inserito e' DISPARI");

	printf("\n\n");
    system("PAUSE");
    return 0;
}
