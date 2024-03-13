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
%token DIV EQUALS LPAR RPAR LKEY RKEY
%token <cad> ID NUMBER STRING

%left PLUSOP MINUSOP
%left DIV TIMES
%left UMINUS

%%

program			:	ID LPAR RPAR LKEY declarations statement_list RKEY	{printf("program -> ID LPAR RPAR LKEY declarations statement_list RKEY\n")}
				;

declarations		:														{printf("declarations -> LAMBDA\n")}
				|	declarations VAR identifier_list SEMICOLON			{printf("declarations -> declarations VAR identifier_list SEMICOLON\n")}
				|	declarations CONST identifier_list SEMICOLON		{printf("declarations -> declarations CONST identifier_list SEMICOLON\n")}
				;
			
identifier_list :	identifier											{printf("identifier_list -> identifier\n")}
				|	identifier_list COMMA identifier					{printf("identifier_list -> identifier_list COMMA identifier\n")}
				;

identifier		:	ID													{printf("identifier -> ID\n")}
				| 	ID EQUALS expression								{printf("identifier -> ID EQUALS expression\n")}
				;
			
statement_list	:														{printf("statement_list -> LAMBDA\n")}
				|	statement_list statement							{printf("statement_list -> statement_list statement\n")}
				;

statement		:	ID EQUALS expression SEMICOLON						{printf("statement -> ID EQUALS expression SEMICOLON\n")}
				|	LKEY statement_list RKEY							{printf("statement -> LKEY statement_list RKEY\n")}
				|	IF LPAR expression RPAR statement ELSE statement		{printf("statement -> IF LPAR expression RPAR statement ELSE statement	\n")}
				|	IF LPAR expression RPAR statement					{printf("statement -> IF LPAR expression RPAR statement\n")}
				|	WHILE LPAR expression RPAR statement				{printf("statement -> WHILE LPAR expression RPAR statement\n")}
				|	PRINT LPAR print_list RPAR SEMICOLON				{printf("statement -> PRINT LPAR print_list RPAR SEMICOLON\n")}
				|	READ LPAR read_list RPAR SEMICOLON					{printf("statement -> READ LPAR read_list RPAR SEMICOLON\n")}
				;
				
print_list		:	print_item											{printf("print_list -> print_item\n")}
				|	print_list COMMA print_item							{printf("print_list -> print_list COMMA print_item\n")}
				;
				
print_item		:	expression
				|	STRING
				;
				
read_list		:	ID													{printf("read_list -> ID\n")}
				|	read_list COMMA ID									{printf("read_list -> read_list COMMA ID\n")}
				;
				
expression		:	expression PLUSOP expression						{printf("expression -> expression PLUSOP expression\n")}
				|	expression MINUSOP expression						{printf("expression -> expression MINUSOP expression\n")}
				|	expression TIMES expression							{printf("expression -> expression TIMES expression\n")}
				|	expression DIV expression							{printf("expression -> expression DIV expression\n")}
				|	MINUSOP expression %prec UMINUS						{printf("expression -> MINUSOP expression %prec UMINUS\n")}
				|	LPAR expression RPAR								{printf("expression -> LPAR expression RPAR\n")}
				|	ID													{printf("expression -> ID\n")}
				|	NUMBER												{printf("expression -> NUMBER\n")}
				;
				
%%

void yyerror(){
	
	
}