#!/bin/bash

exec {FD}< /usr/include/stdio.h

    while read -u ${FD} wrong wrongy correcto gustavo; do
        echo "${correcto}";
    done

exec {FD}>&-