#!/bin/bash

var=${PATH};

while [[ -n ${var} ]]; do
    primo=${var%%:*};
    echo ${primo};
    primaVar=${var};
    var=${var#*:};
        #controllo uscita dal ciclo alla fine
        if [[ ${primaVar} == ${var} ]]; then
            break;
        fi
done