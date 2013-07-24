target: main

#-d gera o arquivo y.tab.h, com os tokens
yacc: yacc.y
	yacc -dv yacc.y
	gcc -o yac.obj -c y.tab.c

hashtable: hashtable.c
	gcc -o hashtable.obj -c hashtable.c

astree: astree.c
	gcc -o astree.obj -c astree.c

tac: tac.c
	gcc -o tac.obj -c tac.c

genco: genco.c
	gcc -o genco.obj -c genco.c

lex: scanner.l
	lex -o scanner.yy.c scanner.l
	gcc -o scanner.obj -c scanner.yy.c

main: yacc lex hashtable astree tac genco main.c
	gcc -o etapa6 main.c yac.obj scanner.obj hashtable.obj astree.obj tac.obj genco.obj -Wall -Wformat

clean:
	rm scanner.yy.c
	rm y.tab.c
	rm y.tab.h
	rm *.obj
	rm y.output
	rm etapa6
