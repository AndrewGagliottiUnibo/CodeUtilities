#!/bin/bash

if (( $# != 1 )); then 
    echo "serve nomefile"; 
    exit 1; 
fi

if [[ ! -r $1 ]]; then 
    echo "il file $1 non esiste"; exit 2; 
fi

while read PRIMA SECONDA ALTRO; do
    if [[ -n ${SECONDA} ]]; then
        OUT=${OUT}${SECONDA}
    fi
done < $1

echo "OUT=${OUT}"
