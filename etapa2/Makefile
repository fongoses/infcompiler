target: main 

#-d gera o arquivo y.tab.h, com os tokens
yacc: yacc.y
	yacc -d yacc.y
	gcc -o yac.obj -c y.tab.c

hashtable: hashtable.c
	gcc -o hashtable.obj -c hashtable.c

lex: scanner.l
	lex -o scanner.yy.c scanner.l
	gcc -o scanner.obj -c scanner.yy.c

main:   yacc lex hashtable main.c
	gcc -o etapa2 yac.obj scanner.obj hashtable.obj -Wall
clean:
	rm scanner.yy.c
	rm y.tab.c
	rm y.tab.h
	rm *.obj
	rm etapa2
		

