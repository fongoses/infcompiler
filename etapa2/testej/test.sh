#!/bin/bash
accepted="ACCEPTED";
rejected="REJECTED";
result=0;
TESTS_DIR=.;
title="Running tests...";
echo $title;

for i in $TESTS_DIR/*.ling # para todos arquivos .ling
do

	./etapa2 $i 
	result=$?; #resultado do ultimo programa executado
	if [ $result == 0 ] 
	then echo "Test $i: $accepted"
	else echo "Test $i: $rejected"
	fi
	
done

