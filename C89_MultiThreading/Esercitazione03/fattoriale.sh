#!/bin/bash

cont=1;
prodotto=1;
while (( ${cont} <= $1 )); do
    (( prodotto=${prodotto}*${cont} ));
    (( cont=${cont}+1 ));
done;
echo prodotto=${prodotto};
