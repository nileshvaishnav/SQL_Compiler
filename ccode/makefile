all:parser sentences

parser:c_parser.c c_lexical_analyzer.c
	gcc -o parser c_lexical_analyzer.c c_parser.c

sentences:build_sentence.cpp
	g++ -o sentences build_sentence.cpp

clean:
	rm parser sentences *.txt