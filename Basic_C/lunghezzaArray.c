#include <stdio.h>
#include <stdlib.h>

/* Prototipo di funzione */
void stampaElementiVettore(int vett[], int indUltimoElementoDaStampare);

int main(void)
{
    int vettore[5] = {1, 2, 3, 4, 5};
    int dim, j;
    int * pnt_vettore;

    pnt_vettore = vettore;

    /* Notare che cosi' non si determina la lunghezza del vettore */
    for (dim=0; vettore[dim]!=NULL; dim++){
    }
    printf("\nLunghezza vettore (sbagliata):\t %d", dim);

    /* Cosa si determina la lunghezza del vettore */
    dim = sizeof(vettore)/sizeof(vettore[0]);
    printf("\nLunghezza vettore (giusta):\t %d", dim);

    printf("\n\nSTAMPA DA DENTRO IL MAIN\n");
    for (j=0; j<dim; j++){
        printf("\nVettore elemento %d, valore: %d", j, vettore[j]);
    }

    printf("\n\nSTAMPA DA FUNZIONE FUORI DAL MAIN (passando vettore)\n");
    stampaElementiVettore(vettore, dim);

    printf("\n\nSTAMPA DA FUNZIONE FUORI DAL MAIN (passando pnt_vettore)\n");
    stampaElementiVettore(pnt_vettore, dim);

    printf("\n\nFINE\n");

	printf("\n\n");
    system("PAUSE");
    return 0;
}


/* Funzione che prende come input il vettore e la sua dimensione */
void stampaElementiVettore(int vett[], int indUltimoElementoDaStampare){

    int j;

    for (j=0; j<indUltimoElementoDaStampare; j++){
        printf("\nVettore elemento %d, valore: %d", j, vett[j]);
    }

}
