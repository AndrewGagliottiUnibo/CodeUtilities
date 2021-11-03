#!/bin/bash

for name in `ls -1` ; do
    echo "file is ${name}";
    ls -ld ${name};

    if (( $?!=0 )) then
        echo "error occured in ls";
    fi;
done