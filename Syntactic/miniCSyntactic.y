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
	int labelCount = 0;
	
	#include "../Semantic/miniCSymbolTable.h"
	Lista symbolTable;
	Tipo symbolType;
	int stringCount = 0;
	
	extern int lexicalErr;
	int syntacticErr = 0;
	int semanticErr = 0;
	
	void imprimirCodigo(ListaC codigo);
	void liberarReg(char * registro);
	void añadeEntrada(Lista lista, char * simbolo, Tipo tipo);
	int numErrors();
	char * obtenerReg();
	char * newLabel();
	char * concatenaStr(char * str0, char * str1);
	
%}

%union{
	char * str;
	ListaC cod;
}

%type <cod> expression statement statement_list print_item print_list read_list declarations identifier_list identifier

%token VAR CONST IF ELSE WHILE PRINT READ DO
%token GREATER GEQUAL LESS LEQUAL EEQUAL NEQUAL
%token SEMICOLON COMMA PLUSOP MINUSOP TIMES
%token DIV EQUALS LPAR RPAR LKEY RKEY
%token <str> STRING ID NUMBER

%nonassoc GREATER GEQUAL LESS LEQUAL EEQUAL NEQUAL
%left PLUSOP MINUSOP
%left DIV TIMES
%left UMINUS

//%expect 1

%%

program			:	{symbolTable = creaLS();} ID LPAR RPAR LKEY declarations statement_list RKEY {
	
																if( numErrors() == 0){
																	imprimirTablaS(symbolTable);
																}
																concatenaLC($6, $7);
																if( numErrors() == 0){
																	imprimirCodigo($6);
																}
																liberaLS(symbolTable);
																liberaLC($6); 
															}
				;


declarations		: { $$ = creaLC(); }

				|	declarations VAR { symbolType = VARIABLE; } identifier_list SEMICOLON {
																							$$ = $1;
																							concatenaLC($$, $4);
																							liberaLC($4);
																						}
				
				|	declarations CONST { symbolType = CONSTANTE; } identifier_list SEMICOLON {
																							$$ = $1;
																							concatenaLC($$, $4);
																							liberaLC($4);
																						}
				|	declarations CONST error SEMICOLON	{
												$$ = creaLC();
												guardaResLC($$, "" );
												fprintf(stderr, "Linea %d: Error en la declaración de una constante\n", yylineno);
												syntacticErr++;
											}
							
				|	declarations VAR error SEMICOLON	{
												$$ = creaLC();
												guardaResLC($$, "" );
												fprintf(stderr, "Linea %d: Error en la declaración de una variable\n", yylineno);
												syntacticErr++;
											}
							
				;
			
			
identifier_list :	identifier											{ $$ = $1; }

				|	identifier_list COMMA identifier					{ 
																		$$ = $1;
																		concatenaLC($$, $3);
																		liberaLC($3);
																	}
				;


identifier		:	ID													{if (!perteneceTS(symbolTable, $1)) añadeEntrada(symbolTable, $1, symbolType); else { fprintf(stderr, "Error en linea %d: Variable %s ya declarada\n", yylineno, $1); semanticErr++; }
	
																		$$ = creaLC(); 
																		
																	}

				| 	ID EQUALS expression								{if (!perteneceTS(symbolTable, $1)) añadeEntrada(symbolTable, $1, symbolType); else { fprintf(stderr, "Error en linea %d: Variable %s ya declarada\n", yylineno, $1); semanticErr++; }
																		$$ = $3;
																		
																		Operacion oper;
																		
																		oper.op = "sw";
																		oper.res = recuperaResLC($3);
																		oper.arg1 = concatenaStr("_", $1);
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		liberarReg(oper.res);
																		
																	}
				;
			
			
statement_list	:														{ $$ = creaLC(); }

				|	statement_list statement							{
																		$$ = $1;
																		concatenaLC($$, $2);
																		liberaLC($2);
																	}
				;


statement		:	ID EQUALS expression SEMICOLON						{ if (!perteneceTS(symbolTable, $1)) { fprintf(stderr, "Error en linea %d: Variable %s no declarada\n", yylineno, $1); semanticErr++; } else { if (esConstante(symbolTable,$1)) { fprintf(stderr, "Error en linea %d: %s es constante\n", yylineno, $1); semanticErr++; } } 													
																		
																		$$ = $3;
																		Operacion oper;
																		oper.op = "sw";
																		oper.res = recuperaResLC($3);
																		oper.arg1 = concatenaStr("_", $1);
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		liberarReg(oper.res);
																	}

				|	LKEY statement_list RKEY							{ $$ = $2; }
				
				|	IF LPAR expression RPAR statement ELSE statement		{ $$ = $3;
																		char * label_ELSE = newLabel();
																		char * label_END = newLabel();
																		
																		Operacion oper;
					
																		oper.op = "beqz";
																		oper.res = recuperaResLC($3);
																		oper.arg1 = label_ELSE;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		liberarReg(oper.res);
																		
																		concatenaLC($$, $5);
																		
																		oper.op = "b";
																		oper.res = label_END;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		
																		oper.op = concatenaStr(label_ELSE, ":");
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		
																		concatenaLC($$, $7);
																		
																		oper.op = concatenaStr(label_END, ":");
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		
																		liberaLC($5);
																		liberaLC($7);
																	}
				
				|	IF LPAR expression RPAR statement					{ $$ = $3;
																		char * label_END = newLabel();
																		
																		Operacion oper;
																		
																		oper.op = "beqz";
																		oper.res = recuperaResLC($3);
																		oper.arg1 = label_END;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		liberarReg(oper.res);
																		
																		concatenaLC($$, $5);
																		
																		oper.op = concatenaStr(label_END, ":");
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		
																		liberaLC($5);
																	}
													
				|	DO statement WHILE LPAR expression RPAR 			{ $$ = creaLC();
																		concatenaLC($$, $5);
																		char * label_DOWHILE = newLabel();
																		char * label_ENDDW = newLabel();
					
																		Operacion oper;
					
																		oper.op = concatenaStr(label_DOWHILE, ":");
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		
																		concatenaLC($$, $2);
																		concatenaLC($$, $5);
					
																		oper.op = "beqz";
																		oper.res = recuperaResLC($5);
																		oper.arg1 = label_ENDDW;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		liberarReg(oper.res);
																							
																		oper.op = "b";
																		oper.res = label_DOWHILE;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
					
																		oper.op = concatenaStr(label_ENDDW, ":");
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
					
																		liberaLC($5);
																		liberaLC($2);
																	}
													
				|	WHILE LPAR expression RPAR statement				{ $$ = creaLC();
																		char * label_WHILE = newLabel();
																		char * label_ENDW = newLabel();
																		
																		Operacion oper;
																		
																		oper.op = concatenaStr(label_WHILE, ":");
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		
																		concatenaLC($$, $3);
																		
																		oper.op = "beqz";
																		oper.res = recuperaResLC($3);
																		oper.arg1 = label_ENDW;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		liberarReg(oper.res);
																		
																		concatenaLC($$, $5);
																		
																		oper.op = "b";
																		oper.res = label_WHILE;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		
																		oper.op = concatenaStr(label_ENDW, ":");
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		
																		liberaLC($5);
																		liberaLC($3);
																	}
				
				
				|	PRINT LPAR print_list RPAR SEMICOLON				{ $$ = $3; }
				
				
				|	READ LPAR read_list RPAR SEMICOLON					{ $$ = $3; }
				
				|	error		{
									$$ = creaLC();
									guardaResLC($$, "" );
									fprintf(stderr, "Linea %d: Error en una sentencia\n", yylineno);
									syntacticErr++;
								}
				;
				
				
print_list		:	print_item											{ $$ = $1;}

				|	print_list COMMA print_item							{
																		$$ = $1;
																		concatenaLC($$, $3);
																		liberaLC($3);
																	}
				;
				
				
print_item		:	expression											{ $$ = $1;
																		Operacion oper;
																		
																		oper.op = "li";
																		oper.res = "$v0";
																		oper.arg1 = "1";
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		
																		oper.op = "move";
																		oper.res = "$a0";
																		oper.arg1 = recuperaResLC($1);
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		liberarReg(oper.arg1);
																		
																		oper.op = "syscall";
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																	}
																	
				|	STRING												{ añadeEntrada(symbolTable, $1, CADENA); 
				
																		$$ = creaLC();
																		
																		Operacion oper;
																		
																		oper.op = "li";
																		oper.res = "$v0";
																		oper.arg1 = "4";
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		
																		oper.op = "la";
																		oper.res = "$a0";
																		oper.arg1 = concatenaStr("$str", "");
																		asprintf(&oper.arg1, "%s%d", oper.arg1, stringCount);
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		
																		oper.op = "syscall";
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																	}
				;
				
				
read_list		:	ID													{ if (!perteneceTS(symbolTable, $1)) { fprintf(stderr, "Error en linea %d: Variable %s no declarada\n", yylineno, $1); semanticErr++; } else { if (esConstante(symbolTable,$1)) { fprintf(stderr, "Error en linea %d: %s es constante\n", yylineno, $1); semanticErr++; } }
																		$$ = creaLC(); /*$1;*/
																		
																		Operacion oper;
																		
																		oper.op = "li";
																		oper.res = "$v0";
																		oper.arg1 = "5";
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		
																		oper.op = "syscall";
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		
																		oper.op = "sw";
																		oper.res = "$v0";
																		oper.arg1 = concatenaStr("_", $1);
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);

}

				|	read_list COMMA ID									{ if (!perteneceTS(symbolTable, $3)) { fprintf(stderr, "Error en linea %d: Variable %s no declarada\n", yylineno, $3); semanticErr++; } else { if (esConstante(symbolTable,$3)) { fprintf(stderr, "Error en linea %d: %s es constante\n", yylineno, $3); semanticErr++; } }
					
																		$$ = $1;
					
																		Operacion oper;
					
																		oper.op = "li";
																		oper.res = "$v0";
																		oper.arg1 = "5";
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
					
																		oper.op = "syscall";
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
					
																		oper.op = "sw";
																		oper.res = "$v0";
																		oper.arg1 = concatenaStr("_", $3);
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																	}
				;
				
				
expression		:	expression PLUSOP expression						{ $$ = $1;
																		concatenaLC($$, $3);
																		Operacion oper;
																		oper.op = "add";
																		oper.res = recuperaResLC($1);
																		oper.arg1 = recuperaResLC($1);
																		oper.arg2 = recuperaResLC($3);
																		insertaLC($$, finalLC($$), oper);
																		guardaResLC($$, oper.res);
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
																		guardaResLC($$, oper.res);
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
																		guardaResLC($$, oper.res);
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
																		guardaResLC($$, oper.res);
																		liberaLC($3);
																		liberarReg(oper.arg2); }
													
				|	MINUSOP expression %prec UMINUS						{ $$ = $2;
																		Operacion oper;
																		oper.op = "neg";
																		oper.res = recuperaResLC($2);
																		oper.arg1 = recuperaResLC($2);
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		guardaResLC($$, oper.res);
																	} 
				
				|	LPAR expression RPAR								{ $$ = $2; }
				
				|	expression GREATER expression					{
																	$$ = $1;
																	concatenaLC($$, $3);
																	
																	Operacion oper;
																	oper.op = "slt";
																	oper.res = recuperaResLC($1);
																	oper.arg1 = recuperaResLC($3);
																	oper.arg2 = recuperaResLC($1);
																	insertaLC($$, finalLC($$), oper);
																	guardaResLC($$, oper.res);
																	
																	liberaLC($3);
																	liberarReg(oper.arg1);
																}
												
				|	expression GEQUAL expression					{ $$ = $1;
																	concatenaLC($$, $3);
																	
																	Operacion oper;
																	oper.op = "sge";
																	oper.res = recuperaResLC($1);
																	oper.arg1 = recuperaResLC($1);
																	oper.arg2 = recuperaResLC($3);
																	insertaLC($$, finalLC($$), oper);
																	guardaResLC($$, oper.res);
																	
																	liberaLC($3);
																	liberarReg(oper.arg2);
																}
				
				|	expression LESS expression						{ $$ = $1;
																	concatenaLC($$, $3);
																	
																	Operacion oper;
																	oper.op = "slt";
																	oper.res = recuperaResLC($1);
																	oper.arg1 = recuperaResLC($1);
																	oper.arg2 = recuperaResLC($3);
																	insertaLC($$, finalLC($$), oper);
																	guardaResLC($$, oper.res);
																	
																	liberaLC($3);
																	liberarReg(oper.arg2);
				}

				|	expression LEQUAL expression					{ $$ = $1;
																	concatenaLC($$, $3);
																	
																	Operacion oper;
																	oper.op = "sle";
																	oper.res = recuperaResLC($1);
																	oper.arg1 = recuperaResLC($1);
																	oper.arg2 = recuperaResLC($3);
																	insertaLC($$, finalLC($$), oper);
																	guardaResLC($$, oper.res);
																	
																	liberaLC($3);
																	liberarReg(oper.arg2);
																}
				
				|	expression EEQUAL expression					{ $$ = $1;
																	concatenaLC($$, $3);
																	
																	Operacion oper;
																	oper.op = "seq";
																	oper.res = recuperaResLC($1);
																	oper.arg1 = recuperaResLC($1);
																	oper.arg2 = recuperaResLC($3);
																	insertaLC($$, finalLC($$), oper);
																	guardaResLC($$, oper.res);
																	
																	liberaLC($3);
																	liberarReg(oper.arg2);
																	
																														
																}
				
				|	expression NEQUAL expression					{ $$ = $1;
																	concatenaLC($$, $3);
					
																	Operacion oper;
																	oper.op = "sne";
																	oper.res = recuperaResLC($1);
																	oper.arg1 = recuperaResLC($1);
																	oper.arg2 = recuperaResLC($3);
																	insertaLC($$, finalLC($$), oper);
																	guardaResLC($$, oper.res);
																	
																	liberaLC($3);
																	liberarReg(oper.arg2);
																}
				
				
				
				
				|	ID													{ if (!perteneceTS(symbolTable, $1)) { fprintf(stderr, "Error en linea %d: Variable %s no declarada\n", yylineno, $1); semanticErr++; }
																		$$ = creaLC();
																		Operacion oper;
																		oper.op = "lw";
																		oper.res = obtenerReg();
																		oper.arg1 = concatenaStr("_", $1);
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
				|	error		{
									$$ = creaLC();
									guardaResLC($$, "" );
									fprintf(stderr, "Linea %d: Error en una expresión aritmética\n", yylineno);
									syntacticErr++;
								}
				;
				
%%

void yyerror(const char *str){
	syntacticErr++;
	//fprintf(stderr, "Error sintáctico (línea %d): (yyerror) %s \n", yylineno, yytext);
	fprintf(stderr, "Error sintáctico: (línea %d): %s \n", yylineno, str);
}


void añadeEntrada(Lista lista, char * simbolo, Tipo tipo){
	
	Simbolo entrada;
	
	switch(tipo) {
		case CADENA:
		
			stringCount++;
			entrada.nombre = strdup(simbolo);
			entrada.tipo = CADENA;
			entrada.valor = stringCount;
			
			insertaLS(lista, finalLS(lista), entrada);
			
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
	semanticErr++;
	fprintf(stderr, "No es posible compilar el programa. Registros insuficientes.\n");
	
	return NULL;
}



void liberarReg(char * registro){
	
	char * numeroRegistro = registro + 2;
	int indice = atoi(numeroRegistro);
	
	if (indice >= 0 && indice < MAX_REGISTERS) {
			registers[indice] = 0;
	} else {
		fprintf(stderr, "Índice fuera de rango.\n");
	}
	
}



void imprimirCodigo(ListaC codigo) {
	
	printf("##################\n");
	printf("# Seccion de codigo\n");
	printf("\t.text\n");
	printf("\t.globl main\n");
	printf("main:\n");
	
	PosicionListaC p = inicioLC(codigo); 
	while (p != finalLC(codigo)) {
		Operacion oper = recuperaLC(codigo,p);
		char labelCheck[7];
		strncpy(labelCheck, oper.op, 6);
		if (strcmp(labelCheck, "$label")){
			printf("\t");
		}
		else{
			printf("\n");
		}
		printf("%s",oper.op);
		if (oper.res) printf(" %s",oper.res);
		if (oper.arg1) printf(",%s",oper.arg1);
		if (oper.arg2) printf(",%s",oper.arg2);
		printf("\n");
		p = siguienteLC(codigo,p);
	}
	
	printf("\n##################\n");
	printf("# Fin de la ejecucion\n");
	
	printf("\tli $v0, 10\n");
	printf("\tsyscall\n");
}

char * concatenaStr(char * str0, char * str1){
	
	char * string;
	asprintf(&string, "%s%s", str0, str1);
	return string;
}

char * newLabel(){
	char * label;
	asprintf(&label, "$label_%d",labelCount++);
	return label;
	
}

int numErrors(){
	
	int errCounter = 0;
	errCounter = lexicalErr + syntacticErr + semanticErr;
		
	return errCounter;
}