#target: main main2 
target: main 

#-d gera o arquivo y.tab.h, com os tokens
yacc: yac.l
	yacc -d yac.l
	gcc -o yac.obj -c y.tab.c

hashtable: hashtable.c
	gcc -o hashtable.obj -c hashtable.c

lex: scanner.l
	lex -o scanner.yy.c scanner.l
	gcc -o scanner.obj -c scanner.yy.c

#funcao main depende agora, tambem, do analisador sintatico(yac.obj)
main: yacc lex hashtable main.c
	gcc -o etapa2 main.c scanner.obj yac.obj hashtable.obj


#testes: diferentes versoes da main.c
main2:	main.test2.c lex hashtable
	gcc -o etapa1.test2 main.test2.c scanner.obj hashtable.obj

clean:
	rm scanner.yy.c
	rm y.tab.c
	rm y.tab.h
	rm *.obj
	rm etapa2
		

