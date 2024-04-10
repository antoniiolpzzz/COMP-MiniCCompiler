#
# MAKEFILE
# Created by Antonio López Toboso and Mercedes López Caballero on 14/2/24.

SEM_DIR := Semantic
SYN_DIR := Syntactic
LEX_DIR := Lexical
GEN_DIR := makeTmp

miniCCompiler:  miniCCompilerMain.c $(LEX_DIR)/lex.yy.c $(SYN_DIR)/miniCSyntactic.tab.c $(SYN_DIR)/miniCSyntactic.tab.h $(SEM_DIR)/miniCSymbolTable.h $(SEM_DIR)/miniCSymbolTable.c

	gcc-13 miniCCompilerMain.c $(LEX_DIR)/lex.yy.c $(SYN_DIR)/miniCSyntactic.tab.c $(SEM_DIR)/miniCSymbolTable.c -ll -o miniCCompiler

$(LEX_DIR)/lex.yy.c: $(LEX_DIR)/miniCLexical.l
	flex -o $(LEX_DIR)/lex.yy.c $(LEX_DIR)/miniCLexical.l

$(SYN_DIR)/miniCSyntactic.tab.c $(SYN_DIR)/miniCSyntactic.tab.h: $(SYN_DIR)/miniCSyntactic.y
	bison -d -v -o $(SYN_DIR)/miniCSyntactic.tab.c $(SYN_DIR)/miniCSyntactic.y

clean:
	rm -f make/*
	rm -f miniCCompiler
