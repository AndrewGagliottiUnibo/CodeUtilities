/* file:  studenti.c */

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

#define NUMSTUDENTI 3


pthread_mutex_t mutex;
pthread_cond_t cond_stud, cond_prof;
int banco_controllato;
int cond_prof_acc;

void *Studente (void *arg) 
{ 
	char Plabel[128],TmpLabel[128];
	intptr_t indice;
	indice=(intptr_t)arg;

	int local_ind = (int) indice;
	sprintf(Plabel,"Studente%" PRIiPTR "",indice);
	/* l'indice dello studente e' anche l'indice del banco dello studente */

	/* implementare lo studente  ...... */
	strcpy(TmpLabel,Plabel);
	
	DBGpthread_mutex_lock(&mutex,TmpLabel);
	DBGpthread_cond_wait(&cond_stud, &mutex, TmpLabel);
	while(1){



		if(banco_controllato == local_ind) printf("Bravo studente [%d] fa l'esame e non copia\n", local_ind);
		else printf("Studente [%d] copia fraudolentemente\n", local_ind);
		++cond_prof_acc;
		if(cond_prof_acc == NUMSTUDENTI ) {
			cond_prof_acc = 0;
			DBGpthread_cond_signal(&cond_prof, TmpLabel);
			DBGpthread_cond_wait(&cond_stud, &mutex, TmpLabel);
		} else DBGpthread_cond_wait(&cond_stud, &mutex, TmpLabel);
	}		

	
	pthread_exit(NULL); 
}


void *Professore (void *arg) 
{ 
	char Plabel[128],TmpLabel[128];
	intptr_t indice;
	int d=1;
	char s_d[10];
	indice=(intptr_t)arg;
	sprintf(Plabel,"Professore%" PRIiPTR "",indice);

	printf("professore controlla dalla cattedra\n");
        fflush(stdout);
	sleep(3);

	/* implementare professore gira tra i banchi  ...... */

	strcpy(TmpLabel,Plabel);
	sprintf(s_d, " %d", d);
	strcat(TmpLabel, s_d);
	DBGpthread_mutex_lock(&mutex, TmpLabel);
	while ( d ) {
		/* ripete indefinitamente ......... */
		printf("Professore gira tra i banchi\n");
		sleep(1);



		banco_controllato=rand()%3;
		printf("Professore controlla banco %d\n",banco_controllato);
		DBGpthread_cond_broadcast(&cond_stud, TmpLabel);
		DBGpthread_cond_wait(&cond_prof, &mutex, TmpLabel);
		sleep(3);
		d++;
		strcpy(TmpLabel,Plabel);
		sprintf(s_d, " %d", d);
		strcat(TmpLabel, s_d);
	}


	pthread_exit(NULL); 
}




int main ( int argc, char* argv[] ) 
{ 
	pthread_t    th; 
	int  rc;
	uintptr_t i=0;
	int seme;
	char dbg_string_control[128];
	/* inizializzazione generatore numeri casuali */
	seme=time(NULL);
        srandom(seme);

	/* inizializza strutture dati per mutua esclusione e sincronizzazione */
    strcpy(dbg_string_control, "cond_prof");
    DBGpthread_cond_init(&cond_prof, NULL, dbg_string_control);
    strcpy(dbg_string_control, "cond_stud");
    DBGpthread_cond_init(&cond_stud, NULL, dbg_string_control);
    strcpy(dbg_string_control, "mutex");
    DBGpthread_mutex_init(&mutex, NULL, dbg_string_control);

	for(i=0;i<NUMSTUDENTI;i++) {
		rc=pthread_create(&th,NULL,Studente,(void*)i); 
		if(rc) PrintERROR_andExit(rc,"pthread_create failed");
	}
	i=0;
	rc=pthread_create(&th,NULL,Professore,(void*)i); 
	if(rc) PrintERROR_andExit(rc,"pthread_create failed");
	
	pthread_exit(NULL);
	return(0); 
} 
  
  
  
