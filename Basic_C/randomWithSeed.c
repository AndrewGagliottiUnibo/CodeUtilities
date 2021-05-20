#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i, seed, verifica;
    printf("This program displays the first five values of rand.\n");
    printf("Enter new seed value (0 to terminate): ");
    verifica = scanf("%d", &seed);
    if (verifica!=1){
        printf("\nError: wrong input value! Program closing.\n");
        exit(1);
    }

    //numeroInteroGenerato = valmin + (rand()+time(NULL))%(valmax+1-valmin); // Genera numeri tra valmin e valmax
    srand(seed);
    while (seed!=0)
    {
        for (i= 0; i< 5; i++)
        {
            printf("%d ", rand());
        }

        printf("\n\n");

        printf("Current time: %d\n", time(NULL));

        printf("Enter new seed value (0 to terminate): ");
        verifica = scanf("%d", &seed);
        if (verifica!=1){
            printf("\nError: wrong input value! Program closing.\n");
            exit(1);
        }
        srand(seed);

    }

	printf("\n\n");
    system("PAUSE");
    return 0;
}
