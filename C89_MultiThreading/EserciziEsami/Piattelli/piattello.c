/* file:  piattello.c */

#ifndef _THREAD_SAFE
	#define _THREAD_SAFE
#endif
#ifndef _POSIX_C_SOURCE
	#define _POSIX_C_SOURCE 200112L
#endif

/* la   #define _POSIX_C_SOURCE 200112L   e' dentro printerror.h */
#ifndef _BSD_SOURCE
#define _BSD_SOURCE     /* per random e srandom */
#endif


/* messo prima perche' contiene define _POSIX_C_SOURCE */
#include "printerror.h"

#include <unistd.h>   /* exit() etc */
#include <stdlib.h>     /* random  srandom */
#include <stdio.h>
#include <string.h>     /* per strerror_r  and  memset */
#include <sys/types.h>
#include <signal.h>
#include <sys/time.h> /*gettimeofday() struct timeval timeval{} for select()*/
#include <time.h> /* timespec{} for pselect() */
#include <limits.h> /* for OPEN_MAX */
#include <errno.h>
#include <assert.h>
#include <stdint.h>     /* uint64_t intptr_t */
#include <inttypes.h>   /* per PRIiPTR */
#include <fcntl.h>
#include <sys/stat.h>
#include <pthread.h>

#include "DBGpthread.h"

#define NUMTIRATORI 10
#define DELAYTRADUEPIATTELLI8sec 8

/* dati da proteggere */


/* variabili per la sincronizzazione */
pthread_mutex_t mutex;
pthread_cond_t cond;
int piattello_in_volo;

void attendi( int min, int max) {
	int secrandom=0;
	if( min > max ) return;
	else if ( min == max ) 
		secrandom = min;
	else
		secrandom = min + ( random()%(max-min+1) );
	do {
		/* printf("attendi %i\n", secrandom);fflush(stdout); */
		secrandom=sleep(secrandom);
		if( secrandom>0 ) 
			{ printf("sleep interrupted - continue\n"); fflush(stdout); }
	} while( secrandom>0 );
	return;
}

void *Tiratore (void *arg) 
{ 
	char Plabel[128];
	intptr_t indice;

	indice=(intptr_t)arg;
	sprintf(Plabel,"Tiratore%" PRIiPTR "",indice);

	/*  da completare  */

	while ( 1 ) {


		/*  inizia aspettando di essere svegliato dal piattello che parte  */

		DBGpthread_mutex_lock(&mutex, Plabel);

		/* il tiratore  attende l'inizio del volo del piattello */
		printf("tiratore %s attende piattello \n", Plabel);
	        fflush(stdout);

		DBGpthread_cond_wait(&cond, &mutex, Plabel);


		DBGpthread_mutex_unlock(&mutex,Plabel);

		printf("tiratore %s mira e .... \n", Plabel);
	        fflush(stdout);

		/* il tiratore si prepara a sparare impiegando da 2 a 4 secondi */
		attendi( 2, 4 );


		DBGpthread_mutex_lock(&mutex, Plabel);
		if (piattello_in_volo) printf("Tiratore ha colpito il piattello!\n");
		else printf("Cazzo non sono riuscito a colpiare il piattello!\n");
		/* il tiratore finisce il tentativo di sparare al piattello in volo */
	        fflush(stdout);
	    DBGpthread_mutex_unlock(&mutex,Plabel);

	}
	pthread_exit(NULL); 
}


void *Piattello (void *arg) 
{ 
	char Plabel[128];
	intptr_t indice;

	indice=(intptr_t)arg;
	sprintf(Plabel,"Piattello%" PRIiPTR "",indice);


	/*  faccio capire che il piattello e' in volo */
	DBGpthread_mutex_lock(&mutex, Plabel);
	piattello_in_volo=1;
	DBGpthread_cond_broadcast(&cond, Plabel);
	printf("piattelo %s inizia volo\n", Plabel);
        fflush(stdout);

    DBGpthread_mutex_unlock(&mutex,Plabel);
	/*  da completare  */


	/* il piattello vola per tre secondi */
	attendi( 3, 3 );


	/*  faccio capire che e' atterrato */

	DBGpthread_mutex_lock(&mutex, Plabel);
	piattello_in_volo=0;
	
	
	printf("piattelo %s finisce volo e termina\n", Plabel);
       	fflush(stdout);
	DBGpthread_mutex_unlock(&mutex,Plabel);
	
	/*  anche se termina prima degli 8 secondi cambia poco visto che la variabile condivisa resta a 0 */


	pthread_exit(NULL); 
}


int main ( int argc, char* argv[] ) 
{ 
	pthread_t    th; 
	int  rc;
	uintptr_t i=0;
	int seme;
	void *join_retval;
	char Plabel[128];
	/* aggiungete eventuali vostre variabili */


	seme=time(NULL);
        srandom(seme);

	/* INIZIALIZZATE LE VOSTRE VARIABILI CONDIVISE e tutto quel che serve - fate voi */

    DBGpthread_mutex_init(&mutex, NULL, Plabel);
    DBGpthread_cond_init(&cond, NULL, Plabel);
	/* all'inizio non c'e' nessun piattello in volo */


	/* CREAZIONE PTHREAD dei tiratori */
	for(i=0;i<NUMTIRATORI;i++) {
		rc=pthread_create(&th,NULL,Tiratore,(void*)i); 
		if(rc) PrintERROR_andExit(rc,"pthread_create failed");
	}

	/* CREAZIONE NUOVO PIATTELLO OGNI 8 secondi */
	i=0;
	while(1) {
			/* un nuovo piattello ogni 8 secondi */
			attendi( DELAYTRADUEPIATTELLI8sec, DELAYTRADUEPIATTELLI8sec );
			i++;

			rc = pthread_create(&th,NULL,Piattello,(void*)i);
			if(rc) PrintERROR_andExit(rc,"pthread_create failed");
			/* crea pthread piattello - completate voi */
			rc = pthread_join(th,&join_retval);
			if(rc) PrintERROR_andExit(rc , "pthread_join failed");


	}

	pthread_exit(NULL);
	return(0); 
} 
  
