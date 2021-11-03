/* file:  ponte_pericolante_semplice.c */

#ifndef _THREAD_SAFE
	#define _THREAD_SAFE
#endif

#include "printerror.h"

#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <stdint.h>
#include <inttypes.h>
#include <pthread.h> 

#include "DBGpthread.h"

#define NUMAUTOORARIO 4
#define NUMAUTOANTIORARIO 4
#define INDICESENSOORARIO 0
#define INDICESENSOANTIORARIO 1

int bigliettoDistributore[2];
int biglietto[2];

pthread_mutex_t  mutexDistributori;
pthread_mutex_t  mutex;
pthread_cond_t   condPonteLibero;

void *Auto (void *arg) 
{ 
	char Plabel[128];
	intptr_t indice;
	int myBiglietto, indiceSenso;
	char senso; /* O orario  A antiorario */

	/* le prime NUMAUTOORARIO auto viaggiano in senso ORARIO
	   le successive viaggiano in senso ANTIORARIO */

	indice=(intptr_t)arg;
	if( indice<NUMAUTOORARIO ) 
	{	senso='O'; indiceSenso=INDICESENSOORARIO; }
	else
	{	senso='A'; indiceSenso=INDICESENSOANTIORARIO; }

	sprintf(Plabel,"%cA%" PRIiPTR "", senso, indice);

	while(1) {
		DBGpthread_mutex_lock(&mutexDistributori,Plabel); 
		myBiglietto = bigliettoDistributore[indiceSenso];
		bigliettoDistributore[indiceSenso]++;
		DBGpthread_mutex_unlock(&mutexDistributori,Plabel); 

		printf("auto %s ha preso biglietto %i \n", Plabel, myBiglietto);
		fflush(stdout);

		/*Attesa di attraversamento*/
		DBGpthread_mutex_lock(&mutex, Plabel);
		/*Controllo ordine di senso*/
		while (myBiglietto !=  biglietto[indiceSenso]) {
			DBGpthread_cond_wait(&condPonteLibero, &mutex, Plabel);
		}
		/*Controllo ordine globale*/
		while (biglietto[indiceSenso] > biglietto[(indiceSenso + 1) % 2]) {
			DBGpthread_cond_wait(&condPonteLibero, &mutex, Plabel);
		}
		
		/*Attraversamento e incremento display*/
		printf("auto %s inizia attraversamento ponte con biglietto %i \n", Plabel,
			myBiglietto );
		fflush(stdout);
		biglietto[indiceSenso]++;
		sleep(1);

		DBGpthread_cond_broadcast(&condPonteLibero, Plabel);
		DBGpthread_mutex_unlock(&mutex, Plabel);
		/* auto fa un giro intorno */
		printf("auto %s gira intorno \n", Plabel );
		fflush(stdout);
		sleep(5); 
	}	

	pthread_exit(NULL); 
}


int main ( int argc, char* argv[] ) 
{ 
	pthread_t th; 
	int  rc;
	intptr_t i;

	rc = pthread_cond_init(&condPonteLibero, NULL);
	if( rc ) PrintERROR_andExit(rc,"pthread_cond_init failed");

	rc = pthread_mutex_init(&mutex, NULL); 
	if( rc ) PrintERROR_andExit(rc,"pthread_mutex_init failed");

	rc = pthread_mutex_init(&mutexDistributori, NULL); 
	if( rc ) PrintERROR_andExit(rc,"pthread_mutex_init failed");

	for( i=0; i<2; i++ ) {
		bigliettoDistributore[i]=0;
		biglietto[i]=0;
	}

	for(i=0;i<NUMAUTOORARIO+NUMAUTOANTIORARIO;i++) {
		rc=pthread_create(&th,NULL,Auto,(void*)i); 
		if(rc) PrintERROR_andExit(rc,"pthread_create failed");
	}
	
	pthread_exit(NULL);
	return(0); 
} 
  
  
  
