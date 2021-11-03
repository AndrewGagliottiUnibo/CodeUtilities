#define ALLOCAMEMORIA(var)
do {
    counter = -1000;
    int i;
    var=(int32_*) malloc(10 * sizeof(int32_t));
    
    if(var==NULL) {
        //do nothing
    } 
    else {
        for(i = 0; i < 10; i=i+1){
            var[i] = counter;
            counter = counter + 1;
        }
    }
} while(0)