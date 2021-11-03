#ifndef _THREAD_SAFE
#define _THREAD_SAFE
#endif 

#ifndef _REENTRANT
#define _REENTRANT
#endif 

#ifdef POSIX_C_SOURCE
#undef POSIX_C_SOURCE
#define _BSD_SOURCE
#define POSIX_C_SOURCE 200112L
#endif 

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

struct PippoBaudo {
    int number;
    pthread_t identifier;
};

typedef struct PippoBaudo CreazioneThread;

void *printIndexAndWait(void *arg)
{
    pthread_t th_pointer, temporary;
    int return_value, *ptr;
    CreazioneThread *p_index = arg;

    temporary = p_index->identifier;

    printf("%d\n", p_index->number);
    usleep(1000);

    p_index->number = (p_index->number) + 1;
    p_index->identifier = pthread_self();
    printf("Creating thread %d\n", p_index->number); 
    return_value = pthread_create(&th_pointer, NULL, printIndexAndWait, p_index);
    if (return_value){
			printf("ERROR; return code from pthread_create() is %d\n", return_value);
			exit(-1);
		}

    return_value = pthread_join(temporary, (void **) &ptr);
    if (return_value){
			printf("ERROR; return code from pthread_create() is %d\n",return_value);
			exit(-1);
		}

	pthread_exit (NULL);
}


int main()
{
	pthread_t tid;
	int rc;  
    CreazioneThread *container;    	

		container = malloc (sizeof(CreazioneThread));       /* alloco memoria sullo heap in cui mettere i parametri per i pthread */
		if(container == NULL) {
			perror("malloc failed: ");
			pthread_exit (NULL);
		}

		container->number = 0;
        container->identifier = pthread_self();

		printf("Creating thread %d\n", container->number);
		rc = pthread_create (&tid, NULL, printIndexAndWait, container);  
		if (rc){
			printf("ERROR; return code from pthread_create() is %d\n",rc);
			exit(-1);
		}

	printf("fine main\n"); 
    fflush(stdout);
	pthread_exit (NULL);
	return(0);
}