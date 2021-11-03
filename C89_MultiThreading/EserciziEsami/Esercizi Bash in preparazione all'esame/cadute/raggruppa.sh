#!/bin/bash

#per tutti gli argomenti del file
while read a b c d ; do
	#ne stampo il contenuto su un file temporaneo
	echo ${c} >> file.txt

done < cadutevic.txt

#ordino il file e sfrutto uniq, cancello il temporaneo
#uniq -c seleziona le parole uniche e ne indica il numero di volte che compaiono
sort -d file.txt | uniq -c;
rm -f file.txt;
