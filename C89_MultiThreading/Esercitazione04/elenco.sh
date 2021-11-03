#!/bin/bash

LungNomiDirectory=0;
NumFileNonDirectory=0;

for name in `ls ./`; do
    if [[ -d ${name} ]]; then
        (( LungNomiDirectory=${LungNomiDirectory}+${#name} ));
    else
        (( NumFileNonDirectory=${NumFileNonDirectory}+1 ));
    fi;
done

echo "LungNomiDirectory=${LungNomiDirectory}"
echo "NumFileNonDirectory=${NumFileNonDirectory}"