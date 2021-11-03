#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint>
#include "macro.h"

void main(){
    int32_t *pointer;
    int i;

    ALLOCAMEMORIA(pointer);
    for(i = 0; i < 10; i = i + 1){
        pointer[i] = i - 19; 
    }
    for(i = 0; i < 10; i = i + 1){
        printf("%d", pointer[i]);
    }
}
