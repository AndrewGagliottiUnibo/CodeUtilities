#!/bin/bash

while read leggi; do
    INDICE=0;
    ACCUMULATO="";
    while (( ${INDICE} < ${#leggi} )); do
        CHAR=${leggi:${INDICE}:1}
        if [[ ${CHAR} == "*" || ${CHAR} == "?" || ${CHAR} == "[" || ${CHAR} == "]" ]]; then
            ACCUMULATO="${ACCUMULATO}\\${CHAR}";
        else
            ACCUMULATO="${ACCUMULATO}${CHAR}";
        fi
        ((INDICE=${INDICE}+1));
    done
    echo "${ACCUMULATO}";
done

# #!/bin/bash
# while read leggi; do
# leggi="${leggi//\*/\\\*}"
# leggi="${leggi//\?/\\\?}"
# leggi="${leggi//\[/\\\[}"
# leggi="${leggi//\]/\\\]}"
# echo "${leggi}"
# done