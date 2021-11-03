#!/bin/bash
RIGA='1 * 2'

# itero fino a che la stringa ha qualcosa dentro
while [[ -n "${RIGA}" ]] ; do

    # copio prima parola, cioè quello che c'e' fino al primo bianco
    PAROLA="${RIGA%% *}"

        # Se a fine riga non c'e' spazio bianco allora
        # non sono riuscito ad estrarre la parola,
        # e ho preso tutta la riga.
        # Se ho preso tutta la riga vuol dire che sono alla fine.
        if [[ "${PAROLA}" == "${RIGA}" ]] ; then
            RIGA=
        else
        # rimuovo la prima parola e il successivo bianco
            RIGA="${RIGA#* }"
        fi
    echo "PAROLA is ${PAROLA}"
done