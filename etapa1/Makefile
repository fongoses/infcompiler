target: main main2 

hashtable: hashtable.c
	gcc -o hashtable.obj -c hashtable.c

lex: scanner.l
	lex -o scanner.yy.c scanner.l
	gcc -o scanner.obj -c scanner.yy.c

main:  main.c lex hashtable
	gcc -o etapa1 main.c scanner.obj hashtable.obj

#testes: diferentes versoes da main.c
main2:	main.test2.c lex hashtable
	gcc -o etapa1.test2 main.test2.c scanner.obj hashtable.obj

clean:
	rm scanner.yy.c	
	rm *.obj
	rm etapa1*
