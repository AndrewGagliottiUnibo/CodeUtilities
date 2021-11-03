#define _POSIX_C_SOURCE 200112L

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdint.h>	/* uintptr_t */
#include <inttypes.h>	/* PRIiPTR */
#include <pthread.h>

#include <string.h>

#define NUM_THREADS 1000

int N=-1;

void *PrintHello(void *arg)
{
	printf("\n %"  PRIiPTR ": Hello World! N=%d\n", (intptr_t)arg, N );
	pthread_exit (NULL);
}

int main()
{
	pthread_t tid[NUM_THREADS];
	int rc, t, *p;
	uintptr_t t0 = 0;

    while (1) {
        
        for(t=0; t < NUM_THREADS ;t++, t0++){
            
            /*
            *
            * 
            * 
            */
            printf("Creating thread %" PRIuPTR "\n", t0);
            rc = pthread_create ((tid + t), NULL, PrintHello, (void*)t0 );
            if (rc){
                char message[100];
                strerror_r(rc, message, 100);
                printf("create: %s\n", message);
                exit(1);
            }
        }

        for(t=0; t < NUM_THREADS ;t++){

            /*  la pthread_join si occupa di ripulire lo stack di un thread
            *   questo perchè anche se questo è terminato, le informazioni rimangono
            *   comunque allocate in memoria. la soluzione adottata ora evita che lo
            *   stack si possa saturare.
            *   come argomenti richiede il tread di cui deve ripulire lo stack e un 
            *   puntatore generico che può contenere un qualsiasi tipo di dato richiesto.
            *   in questo sarà inserito quindi ciò che conteneva lo stack e che si vuole recuperare
            *   nel caso ci servissero dei dati che un particolare thread conteneva.
            *   il puntatore non è allocato dinamicamente, quindi non necessità della free()
            */
            rc = pthread_join (tid[t], (void **) &p);
            if (rc){
                char message[100];
                strerror_r(rc, message, 100);
                printf("join: %s\n", message);
                exit(1);
            }
        }
    }

	pthread_exit (NULL);  /* far vedere commentando questa riga */
    fflush(stdout);
	return(0);
}