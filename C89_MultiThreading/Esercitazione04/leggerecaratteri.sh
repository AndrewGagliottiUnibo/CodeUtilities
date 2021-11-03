#!/bin/bash

counter=0;
exec {FD}< /usr/include/stdio.h

    #-r serve per non interpretare i \ e quindi contarli
    while read -N 1 -r -u ${FD} char; do
        #$(()) perchè non opero su un intera riga
        counter=$(( ${counter}+1 ));
    done
echo "${counter}";

exec {FD}>&-