#
# MAKEFILE
# Created by Antonio López Toboso and Mercedes López Caballero on 14/2/24.

miniCCompiler: lex.yy.c main.c miniCSyntactic.tab.c miniCSyntactic.tab.h
	gcc-13 main.c make/lex.yy.c make/miniCSyntactic.tab.c -ll -o miniCCompiler

lex.yy.c: ./Lexical/miniCLexical.l
	flex -o make/lex.yy.c ./Lexical/miniC.l

miniCSyntactic.tab.c miniCSyntactic.tab.h: ./Syntactic/miniC.y
	bison -d -v -o make/miniC.tab.c ./Syntactic/miniCSyntactic.y

clean:
	rm make/*
	rm miniCCompiler
