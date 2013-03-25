target: main main2 main3 main4 main5 hashtabletest

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

main3:	main.test3.c lex hashtable
	gcc -o etapa1.test3 main.test3.c scanner.obj hashtable.obj

main4:	main.test4.c lex hashtable
	gcc -o etapa1.test4 main.test4.c scanner.obj hashtable.obj

main5:	main.test5.c lex hashtable
	gcc -o etapa1.test5 main.test5.c scanner.obj hashtable.obj

#teste da hashtable

hashtabletest: hashtable.test.c lex hashtable
	gcc -o hashtable.test hashtable.test.c scanner.obj hashtable.obj

clean:
	rm scanner.yy.c	
	rm *.obj
	rm etapa1*
	rm hashtable.test
