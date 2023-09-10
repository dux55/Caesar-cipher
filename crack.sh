#!/bin/bash

for i in $(seq 1 25);
do
	echo $i:
	caesar "$1" $i d
	echo ---------------------------------------------
done
