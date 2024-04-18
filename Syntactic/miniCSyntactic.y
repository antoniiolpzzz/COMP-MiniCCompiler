//
// miniC.y
// Created by Antonio López Toboso and Mercedes López Caballero on 6/3/24.


%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	
	#define MAX_REGISTERS 10
	
	void yyerror(const char *s);
	extern int yylex();
	extern int yylineno;
	extern char * yytext;
	
	#include "../Semantic/miniCCodeList.h"
	int registers[MAX_REGISTERS] = {0};
	
	void liberarReg(char * registro);
	char * obtenerReg();
	void imprimirCodigo(ListaC codigo);
	
	#include "../Semantic/miniCSymbolTable.h"
	Lista symbolTable;
	Tipo symbolType;
	int stringCount = 0;
	
	void añadeEntrada(Lista lista, char * simbolo, Tipo tipo);
	
%}

%union{
	char * str;
	ListaC cod;
}

%type <cod> expression statement

%token VAR CONST IF ELSE WHILE PRINT READ
%token SEMICOLON COMMA PLUSOP MINUSOP TIMES
%token DIV EQUALS LPAR RPAR LKEY RKEY
//%token <str> ID NUMBER STRING
%token <str> STRING ID NUMBER

%left PLUSOP MINUSOP
%left DIV TIMES
%left UMINUS

%%

program			:	{symbolTable = creaLS();} ID LPAR RPAR LKEY declarations statement_list RKEY { imprimirTablaS(symbolTable); liberaLS(symbolTable); }
				;

declarations		:
				|	declarations VAR { symbolType = VARIABLE; } identifier_list SEMICOLON
				|	declarations CONST { symbolType = CONSTANTE; } identifier_list SEMICOLON
				;
			
identifier_list :	identifier											
				|	identifier_list COMMA identifier					
				;

identifier		:	ID													{if (!perteneceTS(symbolTable, $1)) añadeEntrada(symbolTable, $1, symbolType); else printf("Error en linea %d: Variable %s ya declarada\n", yylineno, $1); }

				| 	ID EQUALS expression								{if (!perteneceTS(symbolTable, $1)) añadeEntrada(symbolTable, $1, symbolType); else printf("Error en linea %d: Variable %s ya declarada\n", yylineno, $1); }
				;
			
statement_list	:														
				|	statement_list statement							
				;

statement		:	ID EQUALS expression SEMICOLON						{ if (!perteneceTS(symbolTable, $1)) printf("Error en linea %d: Variable %s no declarada\n", yylineno, $1); else if (esConstante(symbolTable,$1)) printf("Error en linea %d: %s es constante\n", yylineno, $1); 														/*
																		$$ = $3;
																		Operacion oper;
																		oper.op = "sw";
																		oper.res = recuperaResLC($3);
																		sprintf(oper.arg1, "_%s", $1);
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		*/
																		imprimirCodigo($3);
																		/*LIBERAR REGISTROS?*/ }

				|	LKEY statement_list RKEY							
				|	IF LPAR expression RPAR statement ELSE statement		
				|	IF LPAR expression RPAR statement					
				|	WHILE LPAR expression RPAR statement				
				|	PRINT LPAR print_list RPAR SEMICOLON				
				|	READ LPAR read_list RPAR SEMICOLON					
				;
				
print_list		:	print_item											
				|	print_list COMMA print_item							
				;
				
print_item		:	expression											
				|	STRING												{ añadeEntrada(symbolTable, $1, CADENA); }
				;
				
				
read_list		:	ID													{ if (!perteneceTS(symbolTable, $1)) printf("Error en linea %d: Variable %s no declarada\n", yylineno, $1); else if (esConstante(symbolTable,$1)) printf("Error en linea %d: %s es constante\n", yylineno, $1); }

				|	read_list COMMA ID									{ if (!perteneceTS(symbolTable, $3)) printf("Error en linea %d: Variable %s no declarada\n", yylineno, $3); else if (esConstante(symbolTable,$3)) printf("Error en linea %d: %s es constante\n", yylineno, $3); }
				;
				
				
expression		:	expression PLUSOP expression						{ $$ = $1;
																		concatenaLC($$, $3);
																		Operacion oper;
																		oper.op = "add";
																		oper.res = recuperaResLC($1);
																		oper.arg1 = recuperaResLC($1);
																		oper.arg2 = recuperaResLC($3);
																		insertaLC($$, finalLC($$), oper);
																		liberaLC($3);
																		liberarReg(oper.arg2); }
																	
				|	expression MINUSOP expression						{ $$ = $1;
																		concatenaLC($$, $3);
																		Operacion oper;
																		oper.op = "sub";
																		oper.res = recuperaResLC($1);
																		oper.arg1 = recuperaResLC($1);
																		oper.arg2 = recuperaResLC($3);
																		insertaLC($$, finalLC($$), oper);
																		liberaLC($3);
																		liberarReg(oper.arg2); }
													
				|	expression TIMES expression							{ $$ = $1;
																		concatenaLC($$, $3);
																		Operacion oper;
																		oper.op = "mul";
																		oper.res = recuperaResLC($1);
																		oper.arg1 = recuperaResLC($1);
																		oper.arg2 = recuperaResLC($3);
																		insertaLC($$, finalLC($$), oper);
																		liberaLC($3);
																		liberarReg(oper.arg2); }
													
				|	expression DIV expression							{ $$ = $1;
																		concatenaLC($$, $3);
																		Operacion oper;
																		oper.op = "div";
																		oper.res = recuperaResLC($1);
																		oper.arg1 = recuperaResLC($1);
																		oper.arg2 = recuperaResLC($3);
																		insertaLC($$, finalLC($$), oper);
																		liberaLC($3);
																		liberarReg(oper.arg2); }
													
				|	MINUSOP expression %prec UMINUS						{ $$ = $2;
																		Operacion oper;
																		oper.op = "neg";
																		oper.res = recuperaResLC($2);
																		oper.arg1 = recuperaResLC($2);
																		insertaLC($$, finalLC($$), oper);
																		/*liberarReg(oper.arg1);*/ } //PUEDE QUE SOBRE ESTO
				
				|	LPAR expression RPAR								{ $$ = $2; }
				
				|	ID													{ if (!perteneceTS(symbolTable, $1)) printf("Error en linea %d: Variable %s no declarada\n", yylineno, $1); 
																		$$ = creaLC();
																		Operacion oper;
																		oper.op = "lw";
																		oper.res = obtenerReg();
																		sprintf(oper.arg1, "_%s", $1);
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		guardaResLC($$, oper.res); }

				|	NUMBER												{ $$ = creaLC();
																		Operacion oper;
																		oper.op = "li";
																		oper.res = obtenerReg();
																		oper.arg1 = $1;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		guardaResLC($$, oper.res); }
				
				;
				
%%

void yyerror(const char *s){
	
	printf("Error sintáctico (línea %d): (yyerror) %s \n", yylineno, yytext);
	printf("Error sintáctico (línea %d): (yyerror) %s \n", yylineno, s);
}


void añadeEntrada(Lista lista, char * simbolo, Tipo tipo){
	
	Simbolo entrada;
	
	switch(tipo) {
		case CADENA:
		
			entrada.nombre = strdup(simbolo);
			entrada.tipo = CADENA;
			entrada.valor = stringCount;
			
			insertaLS(lista, finalLS(lista), entrada);
			stringCount++;
			break;
		
		default:
			entrada.nombre = simbolo;
			entrada.tipo = tipo;
			entrada.valor = 0;
			
			insertaLS(lista, finalLS(lista), entrada);
			break;
	}
}




char * obtenerReg(){
	
	for (int i = 0; i < MAX_REGISTERS; i++) {
			if (registers[i] == 0) {
				registers[i] = 1;
				
				char* resultado = (char*) malloc(4 * sizeof(char));
				
				snprintf(resultado, 4, "$t%d", i);
				return resultado;
			}
		}
		return NULL;
}

void liberarReg(char * registro){
	
	char * numeroRegistro = registro + 2;
	int indice = atoi(numeroRegistro);
	
	if (indice >= 0 && indice < MAX_REGISTERS) {
			registers[indice] = 0;
		} else {
			printf("Índice fuera de rango.\n");
		}
	
}

void imprimirCodigo(ListaC codigo) { 
	PosicionListaC p = inicioLC(codigo); 
	while (p != finalLC(codigo)) {
		Operacion oper = recuperaLC(codigo,p);
		printf("%s",oper.op);
		if (oper.res) printf(" %s",oper.res);
		if (oper.arg1) printf(",%s",oper.arg1);
		if (oper.arg2) printf(",%s",oper.arg2);
		printf("\n");
		p = siguienteLC(codigo,p);
	}
}