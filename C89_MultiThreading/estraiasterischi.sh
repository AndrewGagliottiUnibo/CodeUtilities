#!/bin/bash

int=0
init=$(cat input.txt)
init=$(echo "$init" | sed 's/\*/§/ g')
echo $init

for name in $init;
	do
	parte=$(echo $name | grep §)
	TUTTO="$TUTTO $parte";
	TUTTO=$(echo $TUTTO | sed 's/  / /')
done;

#TUTTO=$(echo "$init" | sed 's/\(.*\)/far \1/ g' | sed 's/.* \([^ ]*\*[^ ]*\).*/\1/' | sed 's/\(.*\)/\1 ciao/')


echo $TUTTO | sed 's/§/\*/ g'
