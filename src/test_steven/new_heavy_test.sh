#!/bin/bash
for (( c=$1; c<=$2; c++ ))
do
	./crack 43p0Ej8w7jMqs 43 "$c" >> result"$3".csv
done

