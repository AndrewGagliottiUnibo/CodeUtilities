#include <stdio.h>
#define VETLENGHT 10

void main()
{
    int *p_vet,i,j,tmp;
    int vet[VETLENGHT];

    p_vet = vet;

    printf("\n\n Ordinare un vettore usando un puntatore:\n");
    printf("--------------------------------------------\n");

    printf(" Inserire valori del vettore: \n");
    for(i=0; i<VETLENGHT; i++)
    {
        printf(" element - %d/%d : ", i+1, VETLENGHT);
        scanf("%d",p_vet+i);
    }

    /* Ordinare il vettore */
    for(i=0; i<VETLENGHT-1; i++)
    {
        for(j=i+1; j<VETLENGHT; j++)
        {
            if( *(p_vet+i) > *(p_vet+j) )
            {
                tmp = *(p_vet+i);
                *(p_vet+i) = *(p_vet+j);
                *(p_vet+j) = tmp;
            }
        }
    }

    printf("\n Vettore dopo l'ordinamento: \n");

    for(i=0; i<VETLENGHT; i++)
    {
        printf(" element - %d : %d \n", i+1, *(p_vet+i));
    }
    printf("\n");

}
