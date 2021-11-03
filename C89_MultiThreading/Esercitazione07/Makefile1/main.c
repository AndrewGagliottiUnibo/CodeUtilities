#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "dimezza.h"
#include "quadrato.h"

static double salva3;

void main (){
    double valore1 = 13.17;

    salva3 = quadrato(dimezza(valore1));
    printf("%F", valore1);
}