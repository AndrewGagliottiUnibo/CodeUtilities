#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#include "def.h"
#include "A.h"

SD fA( SD *pA ) { 
	SD B;
	B = *pA;
	pA->x = pA->x / 2.0; 
	return( B );
} 

