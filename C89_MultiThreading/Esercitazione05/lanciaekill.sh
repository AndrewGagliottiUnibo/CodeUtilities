#!/bin/bash

variabile=`./lanciaeprendiPID.sh`;
echo ${variabile};
for pid in ${variabile}; do kill -9 ${pid}; done