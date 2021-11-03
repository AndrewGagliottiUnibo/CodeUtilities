#!/bin/bash

cont=$1;
if (( ${cont} > 1 )); then
    (( RIS=${RIS}*${cont} ));
    (( cont=${cont}-1 ));
    source ./fattoriale1.sh "${cont}";
fi