//
// miniC.y
// Created by Antonio López Toboso and Mercedes López Caballero on 6/3/24.

%{
	#include <stdio.h>
	void yyerror();
	extern int yylex();
	extern int yylineno;
	extern char * yytext;
%}

%union{
	char * cad;
}

%token VAR CONST IF ELSE WHILE PRINT READ
%token SEMICOLON COMMA PLUSOP MINUSOP TIMES
%token DIV EQUALS LPAREN RPAREN LKEY RKEY
%token <cad> ID NUMBER STRING

%left PLUSOP MINUSOP
%left DIV TIMES
%left UMINUS

%%

program			:	ID LPAR RPAR LKEY declarations statement_list RKEY
				;

declarations		:	
				|	declarations VAR identifier_list SEMICOLON
				|	declarations CONST identifier_list SEMICOLON
				;
			
identifier_list :		identifier
				|	identifier_list COMMA identifier
				;

identifier		:		ID
				| 		ID EQUALS expression
				;
			
statement_list	:
				|	statement_list statement
				;

statement		:	ID EQUALS expression SEMICOLON
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
				
read_list		:	ID
				|	read_list COMMA ID
				;
				
expression		:	expression PLUSOP expression
				|	expression MINUSOP expression
				|	expression TIMES expression
				|	expression DIV expression
				|	MINUSOP expression %prec UMINUS
				|	LPAR expression RPAR
				|	ID
				|	NUMBER
				;
				
%%