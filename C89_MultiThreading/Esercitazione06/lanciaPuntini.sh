#!/bin/bash

export PRIMA=`ps`;
echo
( ./puntini.sh 30 )
export DOPO=`ps`;
echo
ps

sleep 5;
pidPuntini=$(echo "${DOPO}" | grep -v "${PRIMA}" | sed 's/\([0-9][0-9]*\).*/\1/')
echo
echo ${pidPuntini} pidfiglio;
kill -SIGSTP ${pidPuntini};
echo "sospeso";

sleep 3;
kill -SIGCONT ${pidPuntini};

(sleep 4; echo "hello";)

