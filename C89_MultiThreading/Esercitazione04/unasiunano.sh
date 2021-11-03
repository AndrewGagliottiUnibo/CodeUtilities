stampa=1;

while read RIGA; do
    if (( ${stampa} == 0 )); then 
        echo "${RIGA}"; stampa=1;
    else 
        stampa=0;
fi;

done