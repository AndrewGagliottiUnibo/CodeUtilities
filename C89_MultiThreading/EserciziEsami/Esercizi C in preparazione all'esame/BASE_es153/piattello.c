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
static int inVolo = 0;
static int colpito = 0;

/* variabili per la sincronizzazione */
static pthread_mutex_t mutexVar = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t condVar;

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

	while (1) {

		DBGpthread_mutex_lock(&mutexVar, Plabel);
		while(!inVolo) {
			DBGpthread_cond_wait(&condVar, &mutexVar, Plabel);
		}

		printf("tiratore %s mira e .... \n", Plabel);
	        fflush(stdout);

		DBGpthread_mutex_unlock(&mutexVar, Plabel);

		/* il tiratore si prepara a sparare impiegando da 2 a 4 secondi */
		attendi( 2, 4 );

		DBGpthread_mutex_lock(&mutexVar, Plabel);
		fflush(stdout);
		if(inVolo){
			printf("%s: capperoni si ho colpito il disco!\n", Plabel);
			fflush(stdout);
			colpito = 1;
			while (inVolo) {
				printf("%s: aspetto che cada il piattello\n", Plabel);
				fflush(stdout);
				DBGpthread_cond_wait(&condVar, &mutexVar, Plabel);
			}
		} else {
			/* il tiratore finisce il tentativo di sparare al piattello in volo */
			printf("tiratore %s ha sparato e ha mancato\n", Plabel);
				fflush(stdout);
		}
		DBGpthread_mutex_unlock(&mutexVar, Plabel);
	}
	pthread_exit(NULL); 
}


void *Piattello (void *arg) 
{ 
	char Plabel[128];
	intptr_t indice;

	indice=(intptr_t)arg;
	sprintf(Plabel,"Piattello%" PRIiPTR "",indice);

	DBGpthread_mutex_lock(&mutexVar, Plabel);

	inVolo = 1;
	colpito = 0;
	printf("piattelo %s inizia volo\n", Plabel);
		fflush(stdout);

	DBGpthread_cond_broadcast(&condVar, Plabel);
	DBGpthread_mutex_unlock(&mutexVar, Plabel);

	/* il piattello vola per tre secondi */
	attendi( 3, 3 );
	
	DBGpthread_mutex_lock(&mutexVar, Plabel);
	if(!colpito) {
		printf("piattelo %s finisce volo e termina\n", Plabel);
			fflush(stdout);
	}
	inVolo = 0;
	DBGpthread_cond_broadcast(&condVar, Plabel);
	DBGpthread_mutex_unlock(&mutexVar, Plabel);
	pthread_exit(NULL); 
}

int main ( int argc, char* argv[] ) 
{ 
	pthread_t th; 
	int  rc;
	uintptr_t i=0;
	int seme;
	pthread_attr_t attr;

	/*inizializzo una variabile utile che rendo detached affinché i pthread piattello siano detached*/
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	seme=time(NULL);
        srandom(seme);

	for(i=0;i<NUMTIRATORI;i++) {
		rc=pthread_create(&th,NULL,Tiratore,(void*)i); 
		if(rc) PrintERROR_andExit(rc,"pthread_create failed");
	}

	i=0;
	while(1) {
			attendi( DELAYTRADUEPIATTELLI8sec, DELAYTRADUEPIATTELLI8sec );
			i++;

			/* crea pthread piattello - completate voi */	
			rc = pthread_create(&th, &attr, Piattello, (void*) i);
			if(rc) {
				PrintERROR_andExit(rc, "Failed piattello creation");
			}
	}
	pthread_exit(NULL);
	return(0); 
} 
  
