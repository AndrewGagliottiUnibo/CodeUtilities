#!/bin/bash
# inizializzo la variabile RANDOM con il numero di secondi
# trascorsi dal 1970-01-01 00:00:00 UTC modulo 32768

RANDOM=$(( `date +%s` % 32768 ));
NUM=0;

while (( ${RANDOM}%10 != 2 )); do
    (( NUM=${NUM}+1 ));
done

echo "NUM=${NUM}";