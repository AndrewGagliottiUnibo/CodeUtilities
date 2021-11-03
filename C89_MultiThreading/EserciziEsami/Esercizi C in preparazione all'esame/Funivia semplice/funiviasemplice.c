/* funiviasemplice.c */

#ifndef _THREAD_SAFE
	#define _THREAD_SAFE
#endif
#ifndef _POSIX_C_SOURCE
	#define _POSIX_C_SOURCE 200112L
#endif

#include "printerror.h"

#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <stdint.h>
#include <pthread.h> 
#include "DBGpthread.h"

#define NUMSOBRI 4


/* dati da proteggere */
int numSobriSu=0;

/* variabili per la sincronizzazione */
pthread_mutex_t  mutex; 
pthread_cond_t   condPasseggeriSu, condPasseggeriGiu, condFuniviaParti, condFineGiro; 


void *Sobrio (void *arg) 
{ 
	char Slabel[128];
	int indice;

	indice=*((int*)arg);
	free(arg);
	sprintf(Slabel,"S%d",indice);
	
	while (1) {
		
		DBGpthread_mutex_lock(&mutex, Slabel);

		/*attesa*/
		while (numSobriSu == 2) {
			printf("%s attende\n", Slabel);
			fflush(stdout);
			DBGpthread_cond_wait(&condPasseggeriSu, &mutex, Slabel);
		}
		
		/*salita*/
		numSobriSu++;
		printf("%s sale\n", Slabel);
		fflush(stdout);

		/*partenza*/
		if(numSobriSu == 2) {
			DBGpthread_cond_signal(&condFuniviaParti, Slabel);
		}

		/*viaggiano e attendo la fine*/
		DBGpthread_cond_wait(&condFineGiro, &mutex, Slabel);

		/*scendono*/
		numSobriSu--;
		printf("%s scende, che bello!\n", Slabel);
		fflush(stdout);	

		if(numSobriSu == 0) {
			DBGpthread_cond_signal(&condPasseggeriGiu, Slabel);
		}

		DBGpthread_cond_wait(&condPasseggeriSu, &mutex, Slabel);
		DBGpthread_mutex_unlock(&mutex, Slabel);
	}
	
	pthread_exit(NULL); 
} 


/* void stampo_composizione_passeggeri( char *Flabel) {

	if( numSobriSu!=2 ) {
		printf("Funivia %s porta carico NON AMMESSO. %d sobri STOP\n",
			Flabel, numSobriSu);
		fflush(stdout);
		exit(1);
	}
	else {
		printf("Funivia %s trasporta %d sobri (%d %d) \n",
			Flabel, numSobriSu, sedili[0], sedili[1] );
		fflush(stdout);
	}
} */


void *Funivia (void *arg) 
{ 
	
	char Flabel[128];
	int indice;

	indice=*((int*)arg);
	free(arg);
	sprintf(Flabel,"F%d",indice);
	
	while(1) {
		DBGpthread_mutex_lock(&mutex, Flabel);

		/*attendo passeggeri*/
		printf("Funivia attende ...\n");
		fflush(stdout);
		DBGpthread_cond_wait(&condFuniviaParti, &mutex, Flabel);

		DBGpthread_mutex_unlock(&mutex, Flabel);

		/*viaggio*/
		printf("Funivia sale ...\n");
		fflush(stdout);
		sleep(3);

		printf("Funivia scende ...\n");
		fflush(stdout);
		sleep(3);

		/*finito il giro ...*/
		DBGpthread_mutex_lock(&mutex, Flabel);

		/*... avviso che il giro è finito, avviso tutti i sobri*/
		DBGpthread_cond_broadcast(&condFineGiro, Flabel);

		/*attendo che le persone scendano*/
		DBGpthread_cond_wait(&condPasseggeriGiu, &mutex, Flabel);

		/*do la disponibilità di salita*/
		DBGpthread_cond_broadcast(&condPasseggeriSu, Flabel);

		DBGpthread_mutex_unlock(&mutex, Flabel);
	}

	pthread_exit(NULL); 
}

int main (int argc, char* argv[]) 
{ 
	pthread_t    th; 
	int  rc, i, *intptr;
	
	/*inizializzo strutture e  variabili per sincronizzazione*/
	rc = pthread_cond_init(&condPasseggeriSu, NULL);
	if( rc ) PrintERROR_andExit(rc,"pthread_cond_init failed");
	rc = pthread_cond_init(&condPasseggeriGiu, NULL);
	if( rc ) PrintERROR_andExit(rc,"pthread_cond_init failed");
	rc = pthread_cond_init(&condFuniviaParti, NULL);
	if( rc ) PrintERROR_andExit(rc,"pthread_cond_init failed");
	rc = pthread_cond_init(&condFineGiro, NULL);
	if( rc ) PrintERROR_andExit(rc,"pthread_cond_init failed");

	rc = pthread_mutex_init(&mutex, NULL); 
	if( rc ) PrintERROR_andExit(rc,"pthread_mutex_init failed");

	/*inizializzo variabili globali da proteggere*/
	numSobriSu=0;

	/*creo passeggeri sobri*/
	for(i=0;i<NUMSOBRI;i++) {
		intptr=malloc(sizeof(int));
		if( !intptr ) { printf("malloc failed\n");exit(1); }
		*intptr=i;
		rc=pthread_create( &th,NULL,Sobrio,(void*)intptr); 
		if(rc) PrintERROR_andExit(rc,"pthread_create failed");
	}
	
	/*creo funivia*/
	intptr=malloc(sizeof(int));
	if( !intptr ) { printf("malloc failed\n");exit(1); }
	*intptr=0;
	rc=pthread_create( &th,NULL,Funivia,(void*)intptr); 
	if(rc) PrintERROR_andExit(rc,"pthread_create failed");
	
	
	pthread_exit(NULL); 

	return(0); 
} 
 
 
