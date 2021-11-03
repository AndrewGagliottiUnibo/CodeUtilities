#!/bin/bash

./estraiasterischi.sh < input.txt &

pid=$!;

echo "fatto!" &

wait "${pid}"