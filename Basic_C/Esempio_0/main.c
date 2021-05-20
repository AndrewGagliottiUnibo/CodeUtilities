#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int val = 18;
    int *p_val;

    p_val = &val;                           //ci sono vari metodi di scrittura, questo e' quello piu' didattico

    printf("%p\n", &p_val);
    printf("%d\n", *p_val);
    printf("%d\n", val);
    printf("%p\n", &val);

    /*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

    //segna errore perche' il termine array da fastidio al compilatore
    printf("\n\n");
    int barray[10] = {1,2,3,4,5,6,7,8,9,0};
    int *p_barray;
    p_barray = &barray;

    for(int i=0 ; i<10 ; i++)
        printf("%d\n", *p_barray++);

    printf("\n\n");
    int iarray[10] = {1,2,3,4,5,6,7,8,9,0};
    int *p_iarray;
    p_iarray = iarray;

    for(int i=0 ; i<10 ; i++)
        printf("%d\n", *p_iarray++);    //iarray[i] - stampa classica, &iarray[i] - tutti gli indirizzi, iarray - primo indirizzo

    printf("\n\n");
    float farray[10] = {1,2,3,4,5,6,7,8,9,0};
    float *p_farray;
    p_farray = &farray;

    for(int i=0 ; i<10 ; i++)
        printf("%f\n", *p_farray++);

    /*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

    printf("\n\n");
    int matrix[10][15];
    int *p = &matrix[0][0];


    /*for(int i=0 ; i<10 ; i++)
        for(int j=0 ; j<15 ; j++)
        matrix[i][j] = ((rand()+(time(NULL))) % 5 + 1);


    for(int i=0 ; i<10 ; i++)
    {
        for(int j=0 ; j<15 ; j++)
            printf("|%d", *(p++));

        printf("|\n");
    }
    */
    for (p=&matrix[0][0] ; p<&matrix[10][15] ; p++)
        *p = ((rand()+(time(NULL))) % 5 + 1);

    for(int i=0 ; i<10 ; i++)
    {
        for(int j=0 ; j<15 ; j++)
            printf("|%d", *(p++));

        printf("|\n");
    }

    /*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

    return 0 ;
}
