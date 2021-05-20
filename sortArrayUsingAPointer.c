#include <stdio.h>
#define VETLENGHT 10

void sortArray1D(int *array, int dimArray);

void main()
{
    int *p_vet, i, j;
    int vet[VETLENGHT];

    p_vet = vet;

    printf("\n\n Ordinare un vettore usando un puntatore:\n");
    printf("--------------------------------------------\n");

    printf(" Inserire valori del vettore: \n");
    for(i=0; i<VETLENGHT; i++)
    {
        printf(" element - %d/%d : ", i+1, VETLENGHT);
        scanf("%d",p_vet+i);
        fflush(stdin);
    }

    /* Ordinare il vettore */
    sortArray1D(p_vet, VETLENGHT);

    printf("\n Vettore dopo l'ordinamento: \n");

    for(i=0; i<VETLENGHT; i++)
    {
        printf(" element - %d : %d \n", i+1, *(p_vet+i));
    }
    printf("\n");

}


void sortArray1D(int *array, int DimArray)
{
    int i, j, tmp;

    /* Ordinare il vettore */
    for(i=0; i<DimArray-1; i++)
    {
        for(j=i+1; j<DimArray; j++)
        {
            if( *(array+i) > *(array+j) )
            {
                tmp = *(array+i);
                *(array+i) = *(array+j);
                *(array+j) = tmp;
            }
        }
    }
}
