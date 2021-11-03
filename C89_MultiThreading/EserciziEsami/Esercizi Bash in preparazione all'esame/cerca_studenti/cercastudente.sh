#!/bin/bash

EMAIL=$1;
MATRICOLA=$2;

while read NOME COGNOME MATR MATERIA; do

	if (( "$2" == "${MATR}" )) ; then
		
		echo "l'account ${EMAIL} appartiene allo studente ${NOME} ${COGNOME}";
	
	fi

done < matricola.txt
