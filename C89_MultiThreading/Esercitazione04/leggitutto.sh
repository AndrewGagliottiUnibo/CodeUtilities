#!/bin/bash

counter=0;
exec {FD}< ./miofileNoNL.txt
    if (( $?==0 )); then
        while read -u ${FD} RIGA; [[ $? == 0 || ${RIGA} != "" ]]; do
            echo ${RIGA}; 
        done
    fi;
exec {FD}>&-