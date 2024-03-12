#
# MAKEFILE
# Created by Antonio López Toboso and Mercedes López Caballero on 14/2/24.

anLex: lex.yy.c main.c ./Lexico/miniC.h
	gcc main.c lex.yy.c -ll -o anLex

lex.yy.c: ./Lexico/miniC.l
	flex ./Lexico/miniC.l