#!/bin/bash

accepted="ACCEPTED";
rejected="REJECTED";
result=0;
TESTS_DIR=.;
title="Running tests...";
echo $title;

for i in $TESTS_DIR/*.ling # para todos arquivos .ling
do

	./etapa3 $i lingoutput1.txt
	./etapa3 lingoutput1.txt lingoutput2.txt
	diff lingoutput1.txt lingoutput2.txt
	result=$?; #resultado do ultimo programa executado
	if [ $result == 0 ] 
	then echo "Test $i: $accepted"
	else echo "Test $i: $rejected"
	fi
	
done

