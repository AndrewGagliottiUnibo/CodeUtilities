#!/bin/bash

for name in $(ls /usr/include); do
if [[ -d /usr/include/${name} &&
     -r /usr/include/${name} &&
     /usr/include/${name} -nt /usr/include/stdio.h ]];
then
    echo ${name};
fi;
done
