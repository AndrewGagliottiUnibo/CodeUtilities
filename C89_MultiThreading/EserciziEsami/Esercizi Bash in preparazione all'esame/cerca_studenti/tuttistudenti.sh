#!/bin/bash

while read MATR EMAIL; do

	./cercastudente.sh ${EMAIL} ${MATR}

done < email.txt
