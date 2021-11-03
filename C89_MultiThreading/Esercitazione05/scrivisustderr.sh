#!/bin/bash

while read LINEA; do
    #inserisco la variabile tra doppi apici per evitare l'interpretazione
    PAROLA="${LINEA%% *}";
    echo "${PAROLA}" 1>&2;
done