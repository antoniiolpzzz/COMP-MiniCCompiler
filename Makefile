#
# MAKEFILE
# Created by Antonio López Toboso and Mercedes López Caballero on 14/2/24.

miniC: lex.yy.c main.c miniC.tab.c miniC.tab.h
	gcc-13 main.c make/lex.yy.c make/miniC.tab.c -ll -o miniC

lex.yy.c: ./Lexico/miniC.l
	flex -o make/lex.yy.c ./Lexico/miniC.l

miniC.tab.c miniC.tab.h: ./Sintactico/miniC.y
	bison -d -v -o make/miniC.tab.c ./Sintactico/miniC.y

clean:
	rm make/*
	rm miniC
