#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double salva;
double dimezza(double variable) {
    return salva = cos(variable) / 2;
}