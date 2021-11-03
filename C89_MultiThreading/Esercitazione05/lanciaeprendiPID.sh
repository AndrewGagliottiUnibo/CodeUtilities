#!/bin/bash

for (( NUM=0; ${NUM}<10; NUM=${NUM}+1 )); do
    ./puntini.sh 30 1>&2 &
    echo -n "$! ";
done