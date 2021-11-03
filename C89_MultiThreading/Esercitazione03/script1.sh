#!/bin/bash

echo
echo "ordine crescente:";
cont=1;
while (( ${cont} <= $# )); do
    echo "arg ${cont} is ${!cont}";
    (( cont=${cont}+1 ));
done

./script2.sh "$@";