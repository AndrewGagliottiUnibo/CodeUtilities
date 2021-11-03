#!/bin/bash

for var in * ; do
    echo "file is ${var}";
        if [[ -f ${var} ]]; then
            ls -ld ${var};
        fi;
done
