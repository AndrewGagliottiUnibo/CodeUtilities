#include <stdio.h>
#include <stdlib.h>

typedef struct nodolista {    int key;    struct nodolista *next;  } NODOLISTA;

void aggiungi_in_testa( int KEY, NODOLISTA* *proot        )
{
NODOLISTA *ptr;
ptr=(NODOLISTA*)malloc(sizeof(NODOLISTA));
ptr->next=*proot;
ptr->key=KEY;
*proot=ptr;
}

void stampa(NODOLISTA *ptr)
{
	printf("\n");
	while(ptr)
	{
		printf("%d ", ptr->key);
		ptr=ptr->next;
	}
	printf("\n");
}

/* implementazione della funzione da scrivere, specificando i parametri formali */
int  elimina( int KEY, NODOLISTA* *proot  )
{
	/* i need a new pointer or the root pointer will no longer point at the start of the list */
	NODOLISTA* tmp=*proot;
	if( (*proot)->key == KEY )
	{
	/* this is the code if the first element in the list must be deleted */
	/* only here the proot pointer can be modiefied */
		*proot = (*proot)->next;
		free(tmp);
			
	/* se commento questo return elimino tutti gli elementi con campo key */
	/* uguale a KEY, altrimenti ne elimino solo uno */
	/* i commenti sopra sono giusti e andrebbe fatta la stessa cosa nel ciclo while successivo per eliminare tutte le occorrenze */
		return(1); 
	}
	/* mi serve un'altro puntatore per attaccare i due elementi saltando quello da eliminare */
	NODOLISTA* prev = tmp;
	tmp= tmp->next;
	while ( tmp != NULL )
	{
		if(tmp->key == KEY)
		{
			prev->next=tmp->next;
			free(tmp);
			/* stesso discorso fatto sopora, se voglio eliminare tutte le occorrenze di KEY nella lista,
			devo togliere il return alla riga sotto */
			return 1;
		}
		else (
		{
			prev=tmp;
			tmp= tmp->next;
		}
	}
	return(0);
}


int main()
{
	NODOLISTA *root;
	root=NULL;

	/* codice aggiunto per fare la prova */
	/* chiamate alla funzione aggiungi_in_testa */
	aggiungi_in_testa( 111, &root );
	aggiungi_in_testa( 4,   &root );
	aggiungi_in_testa( 111, &root );
	aggiungi_in_testa( 71,  &root );
	stampa(root);

	elimina(   4 , &root );
	stampa(root);
	elimina( 111 , &root );
	stampa(root);
	elimina(  53 , &root );
	stampa(root);
	elimina(  71 , &root );
	stampa(root);
	elimina( 111 , &root );
	stampa(root);
	elimina(  10 , &root );
	stampa(root);

	return(0);
}
