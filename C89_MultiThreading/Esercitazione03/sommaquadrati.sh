#!/bin/bash

RIS=0
for (( NUM=1; ${NUM}<=$#; NUM=${NUM}+1 )) ; do
 ((RIS=${RIS}+${!NUM}*${!NUM}));
done

for (( NUM=1; ${NUM}<=$#; NUM=${NUM}+1 )) ; do
 ((RIS=${RIS}-${NUM}));
done

echo ${RIS};