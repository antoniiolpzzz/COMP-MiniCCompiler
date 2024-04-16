//
// miniC.y
// Created by Antonio López Toboso and Mercedes López Caballero on 6/3/24.

%{
	#include <stdio.h>
	void yyerror(const char *s);
	extern int yylex();
	extern int yylineno;
	extern char * yytext;
	
	#include "../Semantic/miniCSymbolTable.h"
	Lista symbolTable;
	Tipo symbolType;
	int stringCount = 0;
	
	void añadeEntrada(Lista lista, char * simbolo, Tipo tipo);
%}

%union{
	char * str;
}

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

statement		:	ID EQUALS expression SEMICOLON						{ if (!perteneceTS(symbolTable, $1)) printf("Error en linea %d: Variable %s no declarada\n", yylineno, $1); else if (esConstante(symbolTable,$1)) printf("Error en linea %d: %s es constante\n", yylineno, $1); }
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
				
expression		:	expression PLUSOP expression						
				|	expression MINUSOP expression						
				|	expression TIMES expression							
				|	expression DIV expression							
				|	MINUSOP expression %prec UMINUS						
				|	LPAR expression RPAR								
				|	ID													{ if (!perteneceTS(symbolTable, $1)) printf("Error en linea %d: Variable %s no declarada\n", yylineno, $1); }
				|	NUMBER												
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
			//PUEDE SER QUE QUEDE PENDIENTE MODIFICAR LA CADENA
			//QUITAR COMILLAS O AÑADIR SALTO DE LINEA
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
