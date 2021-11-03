#!/bin/bash

#stampa anche i permessi
for name in * ; do
    echo "file is ${name}";
    ls -ld ${name};
done