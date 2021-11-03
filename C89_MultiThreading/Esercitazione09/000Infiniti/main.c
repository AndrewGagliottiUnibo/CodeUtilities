#define _POSIX_C_SOURCE 200112L

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdint.h>	/* uintptr_t */
#include <inttypes.h>	/* PRIiPTR */
#include <pthread.h>

#include <string.h>

#define NUM_THREADS 5

int N=-1;

void *PrintHello(void *arg)
{
	printf("\n %"  PRIiPTR ": Hello World! N=%d\n", (intptr_t)arg, N );
	pthread_exit (NULL);
}

int main()
{
	pthread_t tid;
	int rc;
	intptr_t t;
	for(t=0; /*infinito*/ ;t++){

		printf("Creating thread %" PRIiPTR "\n", t);
		rc = pthread_create (&tid, NULL, PrintHello, (void*)t );
		if (rc){
            char message[100];
            strerror_r(rc, message, 100);
			printf("%s\n", message);
			exit(1);
		}
	}

	pthread_exit (NULL);  /* far vedere commentando questa riga */
	return(0);
}