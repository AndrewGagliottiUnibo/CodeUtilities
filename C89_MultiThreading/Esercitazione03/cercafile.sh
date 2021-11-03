#!/bin/bash

for car in {c..g}; do
    for name in /usr/include/?${car}*; do
        if [[ ${#name} -lt 18 || ${#name} -gt 23 ]];

        then
            echo ${name};

        fi;
    done
done