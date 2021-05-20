#include <stdio.h>
#include <stdlib.h>

int main(){

    /*dichiara e inizializza una variabile di tipo int*/
    int var1 = 100;

    /*dichiara un puntatore a int*/
    int *p_var1;

	/*inizializza ptr in modo che punti a var1*/
	p_var1 = &var1;

	/*si accede a var1 in modo diretto e indiretto*/
	printf("\nAccesso diretto (var1), var1 = %d", var1);
	printf("\nAccesso indiretto (*p_var1), var1 = %d", *p_var1);

	/*mostriamo l'indirizzo di var in due modi*/
	printf("\n\nIndirizzo di var1 (&var1): %d", &var1);
	printf("\nIndirizzo di var1 (p_var1): %d", p_var1);

	/*mostriamo l'indirizzo del puntatore*/
	printf("\n\nIndirizzo di p_var1 (&p_var1): %d", &p_var1);

    printf("\n\n");
	system("pause");
	return 0;
}
