#
# MAKEFILE
# Created by Antonio López Toboso and Mercedes López Caballero on 14/2/24.

LEX_DIR := Lexical
SYN_DIR := Syntactic
SEM_DIR := Semantic
GEN_DIR := makeTmp


miniCCompiler: $(LEX_DIR)/lex.yy.c miniCCompilerMain.c $(SYN_DIR)/miniCSyntactic.tab.h $(SYN_DIR)/miniCSyntactic.tab.c $(SEM_DIR)/miniCSymbolTable.h $(SEM_DIR)/miniCSymbolTable.c $(SEM_DIR)/miniCCodeList.h $(SEM_DIR)/miniCCodeList.c

	gcc-13 miniCCompilerMain.c $(LEX_DIR)/lex.yy.c $(SYN_DIR)/miniCSyntactic.tab.c $(SEM_DIR)/miniCSymbolTable.c $(SEM_DIR)/miniCCodeList.c -lfl -o miniCCompiler


$(LEX_DIR)/lex.yy.c: $(LEX_DIR)/miniCLexical.l $(SYN_DIR)/miniCSyntactic.tab.h
	flex -o $(LEX_DIR)/lex.yy.c $(LEX_DIR)/miniCLexical.l


$(SYN_DIR)/miniCSyntactic.tab.c $(SYN_DIR)/miniCSyntactic.tab.h: $(SYN_DIR)/miniCSyntactic.y $(SEM_DIR)/miniCSymbolTable.h
	bison -d -v -o $(SYN_DIR)/miniCSyntactic.tab.c $(SYN_DIR)/miniCSyntactic.y


clean:
	rm -f miniCCompiler $(LEX_DIR)/lex.yy.c $(SYN_DIR)/miniCSyntactic.tab.c $(SYN_DIR)/miniCSyntactic.tab.h $(SYN_DIR)/miniCSyntactic.output


run: miniCCompiler 
	./miniCCompiler testFile.mc > testFile.s
