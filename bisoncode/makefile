
all: parser

parser: lex.yy.c parser.tab.c
	gcc -o parser lex.yy.c parser.tab.c


parser.tab.c parser.tab.h: parser.y
	bison -d parser.y

lex.yy.c: lexical_analyzer.l parser.tab.h
	lex lexical_analyzer.l

clean:
	rm parser *.c *.h
