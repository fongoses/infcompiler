#target: main main2
target: main2

#-d gera o arquivo y.tab.h, com os tokens
yacc: yacc.y
	yacc -d yacc.y
	gcc -o yac.obj -c y.tab.c

hashtable: hashtable.c
	gcc -o hashtable.obj -c hashtable.c

lex: scanner.l
	lex -o scanner.yy.c scanner.l
	gcc -o scanner.obj -c scanner.yy.c

#funcao main depende agora, tambem, do analisador sintatico(yac.obj)
#main: yacc lex hashtable main.c
#	gcc -o etapa2 main.c scanner.obj yac.obj hashtable.obj


#testes: diferentes versoes da main.c
main2:	yacc lex hashtable 
	gcc -o etapa2.test2 yac.obj scanner.obj hashtable.obj

clean:
	rm scanner.yy.c
	rm y.tab.c
	rm y.tab.h
	rm *.obj
	rm etapa2
	rm etapa2.test2
		

