target: main

hashtable: hashtable.c
	gcc -o hashtable.obj -c hashtable.c

lex: scanner.l
	lex -o scanner.yy.c scanner.l

main:  main.c lex hashtable
	gcc -o scanner.obj -c scanner.yy.c
	gcc -o etapa1 main.c scanner.obj hashtable.obj

clean:
	rm scanner.yy.c	
	rm *.obj
	rm etapa1
