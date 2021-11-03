#!/bin/bash
# REVERSE=""

echo $1 | while (( 1 )); do
            read -n 1 CAR;
                if (( $? == 0 )); then
                    REVERSE=${CAR}${REVERSE};
                else
                    echo stringa rovesciata ${REVERSE};
                    break;
                fi
        done

echo GUARDARE SE STAMPA IL CONTENUTO DI STA STRINGA ${REVERSE};