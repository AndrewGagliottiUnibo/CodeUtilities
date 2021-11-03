#!/bin/bash

( head -n 5 /usr/include/stdio.h | tail -n 3; 
tail -n 4 /usr/include/stdio.h | cut -b -3 ) | ( read RIGA1; read RIGA2; echo "${RIGA2}"; 
echo "${RIGA1}"; read RIGA &> /dev/null;
while read RIGA; do echo ${#RIGA} ; done )