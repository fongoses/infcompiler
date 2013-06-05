#!/bin/bash

accepted="ACCEPTED";
rejected="REJECTED";
result=0;
TESTS_DIR=.;
#TESTS_DIR=testej;
title="Running tests...";
echo $title;

for i in $TESTS_DIR/*.ling # para todos arquivos .ling
do

	./etapa3 $i lingoutput1.txt 2> /dev/null
	./etapa3 lingoutput1.txt lingoutput2.txt 2> /dev/null
	diff lingoutput1.txt lingoutput2.txt > /dev/null
	result=$?; #resultado do ultimo programa executado
	if [ $result == 0 ] 
	then echo "Test $i: $accepted"
	else echo "Test $i: $rejected"
	fi
	
done

