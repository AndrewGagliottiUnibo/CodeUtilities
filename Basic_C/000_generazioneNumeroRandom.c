/*
    Generazione numero random
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int numeroInteroGenerato, valmin, valmax, i;

	valmin = 150;
	valmax = 160;

	for(i=0;i<50;i++){
        //numeroInteroGenerato = 1 + (rand()+time(NULL))%(100-1+1); // Genera numeri tra 1 e 100
        numeroInteroGenerato = valmin + (rand()+time(NULL))%(valmax+1-valmin); // Genera numeri tra valmin e valmax
        printf("\nIl numero genrrato e\': %d", numeroInteroGenerato);
    }

	printf("\n\n");
    system("PAUSE");
    return 0;
}
