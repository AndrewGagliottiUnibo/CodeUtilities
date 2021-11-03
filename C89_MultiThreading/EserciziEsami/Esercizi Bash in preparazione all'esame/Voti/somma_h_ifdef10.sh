#!/bin/bash

for name in `ls /usr/include/*.h`; do

    ANALISI=`cat ${name} | grep ifdef | wc -l`;
    #echo "${ANALISI}-2";
    if (( "${ANALISI}" >= "10" )) ; then
        cat ${name} | grep ifdef | head -n 5 >> LETTURA.txt;
    fi

done

sort LETTURA.txt > FINALE.txt
rm -f LETTURA.txt

(geany FINALE.txt)