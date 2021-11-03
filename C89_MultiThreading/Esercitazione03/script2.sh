#!/bin/bash

echo
echo "ordine inverso:";
cont=$#;
while (( ${cont} > 0 )); do
    echo "arg ${cont} is ${!cont}";
    (( cont=${cont}-1 ));
done