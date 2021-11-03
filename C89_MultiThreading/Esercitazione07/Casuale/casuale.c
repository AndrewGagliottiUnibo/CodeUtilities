#ifndef _POSIX_SOURCE
	#define _POSIX_SOURCE
#endif

#include <unistd.h>
#include <stdlib.h>		/* serve per la funzione rand */
#include <stdio.h>
#include <time.h>		/* serve per la funzione time */

int main(void) {
	srand( time(NULL) );	
	while(1) {
		if( (rand()%10) == 3 ) 
			break;
	}
return(0);
}