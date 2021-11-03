#!/bin/bash

STR=""
NUM=0

for (( NUM=2; ${NUM}<=$#; NUM=${NUM}+2 )) ; do
    STR="${STR}${!NUM}";
done

for (( NUM=1; ${NUM}<=$#; NUM=${NUM}+2 )) ; do
    STR="${STR}${!NUM}";
done

echo ${STR};