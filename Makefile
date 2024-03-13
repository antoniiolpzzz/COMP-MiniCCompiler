#
# MAKEFILE
# Created by Antonio López Toboso and Mercedes López Caballero on 14/2/24.

anLex: lex.yy.c main.c miniC.tab.c miniC.tab.h
	gcc-13 main.c lex.yy.c miniC.tab.c -ll -o anLex

lex.yy.c: ./Lexico/miniC.l
	flex ./Lexico/miniC.l
	
miniC.tab.c miniC.tab.h: ./Sintactico/miniC.y
	bison -d -v ./Sintactico/miniC.y
	