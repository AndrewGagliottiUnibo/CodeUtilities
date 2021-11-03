#ifndef _THREAD_SAFE
#define _THREAD_SAFE
#endif

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define THREADS 10

void *to_do (void *pointer){
    sleep(5);
    printf("%f\n", *((double*)pointer));
    free(pointer);
    pthread_exit (NULL);
}

int main(){
    pthread_t thread_id;
    int return_code, index;
    double *ptr;

    index = 0;
    while(index < THREADS) {
        
        printf("Thread is: %d\n", index);
        ptr = (double *) malloc (sizeof(double));
        if(ptr == NULL) {
            perror("errore\n");
            pthread_exit(NULL);
        }
        *ptr = (double) (rand()%100000);
        
        return_code = pthread_create (&thread_id, NULL, to_do, ptr);

        if(return_code){
            printf("error in returning code is: %d\n", return_code);
            exit(-1);
        }
        index++;
    }
    pthread_exit(NULL);
    return 0;
}