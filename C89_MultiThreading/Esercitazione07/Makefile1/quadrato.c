#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double salva2;
double quadrato(double variable){
    return salva2 = pow(variable, 2);
}