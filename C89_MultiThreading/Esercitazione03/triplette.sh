#!/bin/bash

var=`ls`;
for x in ${var}; do
    for y in ${var}; do
        for z in ${var}; do
        echo \(${x}\; ${y}\; ${z}\);
        done
    done
done