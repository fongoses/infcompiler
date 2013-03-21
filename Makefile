all: scanner gcc

scanner: scanner.l hashtable.c
	lex -o scanner.yy.c scanner.l

gcc:
	gcc -o scanner scanner.yy.c


clean:
	rm scanner.yy.c
	rm scanner
