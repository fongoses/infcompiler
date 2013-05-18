#!/bin/bash
title="Running tests...";
accepted="ACCEPTED";
rejected="REJECTED";
result=0;
echo $title;

for i in 1 2 3 4 5 6 7 8 9 10
do

	./etapa2 sample$i.ling;
	result=$?; #resultado do ultimo programa executado
	if [ $result == 0 ] 
	then echo "Test $i: $accepted"
	else echo "Test $i: $rejected"
	fi
	
done

