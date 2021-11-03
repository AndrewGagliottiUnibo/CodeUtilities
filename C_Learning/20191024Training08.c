#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define valmin 5
#define valmax 10
#define numval 10
#define LENGTHVECTOR 8

int main()
{
   /* int n, i;
    time_t t;                       //dichiaro l'srand per usare questa variabile


    srand((unsigned) time(&t));     //affido a questa variabile ogni tot tempo che deve generare un numero

    for (i = 0 ; i <= 10 ; i++){
        n = rand() % 100;
        printf("%d\t", n);}

    printf("\n\n");
    system("pause");*/
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    /*int a, numerogenerato;

    for(a = 0;a<n;a++)  {
        numerogenerato = valmin + (rand()+time(NULL)) % (valmax + 1 - valmin);
        printf("%02d,  %02d\n", a, numerogenerato); }

    printf("\n\n");
    system("pause");*/
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Per generare numero random float:
    /*int b, numerointero;
    float numerofloat;

    for(b = 0 ; b < numval ; b++)
        {
        numerointero = valmin + (rand() + time(NULL)) % (valmax+1-valmin);      //valmin + random % campomassimo +1, che vuol dire partire da 1 a campo massimo
        numerofloat = ((float)(rand())/(float)(RAND_MAX))* (valmax-1) + 1;      //trovare il campo minimo
        printf("%02d, %02d, %lf\n", b, numerointero, numerofloat);
        }

    printf("\n\n");
    system("pause");*/
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        /*int i;
        float elenco[5], somma, media = somma / 5;
        for (i = 0; i < 5; i++)
        {
            printf("\n Inserire numero %d: ",i);
            scanf("%f",&elenco[i]);
            fflush(stdin);
        }
            somma = 0;
            for (i = 0; i < 5; i++)
            {
                somma += elenco[i];
            }

            printf("\nla somma e' %f\n\n",somma);

            media = 0;
            printf("La media e': %f", media = somma / 5);


    printf("\n\n");
    system("pause");*/
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    /*int elenco[10];
    int i, cerca, conta, assegnazione;

    for (i = 0 ; i < 10 ; i++)
    {
      printf("Inserisci un numero:");
      scanf("%d", &elenco[i]);
      fflush(stdin);
    }

    printf("inserire il numero da cercare: ");
    scanf("%d",&cerca);

    conta = 0;
    for (i = 0; i < 10; i++)
    {
        if (elenco[i] == cerca)
        conta++;
    }

    printf("\n Il numero compare %d volte",conta);


    printf("\n\n");
    system("pause");*/
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    int binaryVector[LENGTHVECTOR];
    int binaryInput, decimalInput, i, j, verifica;

    /* Vector initialization */
    for (i=0; i<LENGTHVECTOR; i++)
    {
        binaryVector[i]=0;
    }

    /* Ask the binary number to the user */
    printf("\nInsert a binary number with %d characters:\n", LENGTHVECTOR);
    for (i=0; i<LENGTHVECTOR; i++)
    {
        verifica = scanf("%1d", &binaryInput);
        if (verifica!=1){
            printf("\nError: wrong input value! Program closing.\n");
            exit(1);
        }
        binaryVector[i] = binaryInput;
    }
    fflush(stdin);

    /* Show vector */
    printf("\nBinary number: ");
    for (i=0; i<LENGTHVECTOR; i++)
    {
        binaryInput = binaryVector[i];
        if (binaryInput>1)
        {
            printf("\nWRONG INPUT VALUE!\n\n", LENGTHVECTOR);
            system("pause");
            exit(1);
        }
        printf("%d",binaryVector[i]);
    }

    /* Convert binary input into decimal number */
    decimalInput = 0;
    for (i=LENGTHVECTOR-1, j=0; i>=0; i--, j++)
    {
        binaryInput = binaryVector[i];
        decimalInput = decimalInput + (binaryInput*pow(2,j));
    }

    /* Show decimal */
    printf(" -> Decimal number: %d\n", decimalInput);

    printf("\n\n");
    system("pause");
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    return 0;
  }
