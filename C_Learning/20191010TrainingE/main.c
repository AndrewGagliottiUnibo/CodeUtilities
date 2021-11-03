#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

/*----------------------------------------------------------------------------------------------------------------------------------------------------------*/

    //Esercizio4
    int NumeroUtente;
    int VarRand;
    int NumeroTentativi = 2;

    srand(time(NULL));
    VarRand = rand() % 4 + 1;

    printf("Ho generato un numero casuale da 1 a 10!, prova ad indovinarlo!\n");
    scanf("%d", &NumeroUtente);
    fflush(stdin);

    while(NumeroTentativi != 0)
    {
            if(VarRand == NumeroUtente)
            {
                printf("WOW! Hai indovinato\n");
                break;
            }
            else
            {
                --NumeroTentativi;
                printf("Hai sbagliato e perdi un tentativo, riprova con questo indizio: \n");
                if(NumeroUtente < VarRand)
                {
                    printf("Il numero da indovinare e' MAGGIORE del tuo numero!\n");
                }
                else
                {
                    printf("Il numero da indovinare e' MINORE del tuo numero!\n");
                }
                printf("Riprova ad indovinare il numero nascosto: ");
                scanf("%d", &NumeroUtente);
                fflush(stdin);
        }
    }
    if(NumeroTentativi == 0 && VarRand != NumeroUtente)
        printf("Hai finito tutti i tentativi, il numero nascosto era: %d\n", VarRand);

}
/*----------------------------------------------------------------------------------------------------------------------------------------------------------*/

