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
	
	void imprimirCodigo(ListaC codigo);
	void liberarReg(char * registro);
	void añadeEntrada(Lista lista, char * simbolo, Tipo tipo);
	char * obtenerReg();
	char * newLabel();
	char * concatenaStr(char * str0, char * str1);
	
%}

%union{
	char * str;
	ListaC cod;
}

%type <cod> expression statement statement_list print_item print_list read_list declarations identifier_list identifier

%token VAR CONST IF ELSE WHILE PRINT READ
%token SEMICOLON COMMA PLUSOP MINUSOP TIMES
%token DIV EQUALS LPAR RPAR LKEY RKEY
%token <str> STRING ID NUMBER

%left PLUSOP MINUSOP
%left DIV TIMES
%left UMINUS

%%

program			:	{symbolTable = creaLS();} ID LPAR RPAR LKEY declarations statement_list RKEY { imprimirTablaS(symbolTable); concatenaLC($6, $7); imprimirCodigo($6); liberaLS(symbolTable); liberaLC($6); }
				;

declarations		: { $$ = creaLC(); }

				|	declarations VAR { symbolType = VARIABLE; } identifier_list SEMICOLON { $$ = $1;
																							concatenaLC($$, $4);
																							liberaLC($4);
																						}
				
				|	declarations CONST { symbolType = CONSTANTE; } identifier_list SEMICOLON { $$ = $1;
																								concatenaLC($$, $4);
																								liberaLC($4);
																							}
				;
			
identifier_list :	identifier											{ $$ = $1; }

				|	identifier_list COMMA identifier					{ $$ = $1;
																		concatenaLC($$, $3);
																		liberaLC($3);
																	}
				;

identifier		:	ID													{if (!perteneceTS(symbolTable, $1)) añadeEntrada(symbolTable, $1, symbolType); else printf("Error en linea %d: Variable %s ya declarada\n", yylineno, $1);
	
																		$$ = creaLC(); 
																		
																	}

				| 	ID EQUALS expression								{if (!perteneceTS(symbolTable, $1)) añadeEntrada(symbolTable, $1, symbolType); else printf("Error en linea %d: Variable %s ya declarada\n", yylineno, $1); 
																		$$ = $3;
																		
																		Operacion oper;
																		
																		oper.op = "sw";
																		oper.res = recuperaResLC($3);
																		oper.arg1 = concatenaStr("_", $1);
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		liberarReg(oper.arg1);
																		//liberaLC($3); //PUEDE SER QUE ESTO NO SEA CORRECTO VIDEO
																	}
				;
			
statement_list	:														{ $$ = creaLC(); }

				|	statement_list statement							{ $$ = $1;
																		concatenaLC($$, $2);
																		liberaLC($2);
																	}
				;

statement		:	ID EQUALS expression SEMICOLON						{ if (!perteneceTS(symbolTable, $1)) printf("Error en linea %d: Variable %s no declarada\n", yylineno, $1); else if (esConstante(symbolTable,$1)) printf("Error en linea %d: %s es constante\n", yylineno, $1); 													
																		
																		$$ = $3;
																		Operacion oper;
																		oper.op = "sw";
																		oper.res = recuperaResLC($3);
																		oper.arg1 = concatenaStr("_", $1);
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		guardaResLC($$, oper.res);
																		liberarReg(oper.res);
																		//liberaLC($3); //PUEDE QUE ESTE MAL
																		
																		
																		/*LIBERAR REGISTROS?*/ }

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
																		
																		liberaLC($5); //COMPROBAR SI HACE FALTA
																		liberaLC($7); //COMPROBAR SI HACE FALTA
																		
																	}
				
				|	IF LPAR expression RPAR statement					{ $$ = $3;
																		char * label_END = newLabel();
																		
																		Operacion oper;
																		
																		oper.op = "beqz";
																		oper.res = recuperaResLC($3);
																		oper.arg1 = label_END;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		
																		concatenaLC($$, $5);
																		
																		oper.op = concatenaStr(label_END, ":");
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC($$, finalLC($$), oper);
																		
																		liberaLC($5); //COMPROBAR SI HACE FALTA
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
				;
				
print_list		:	print_item											{ $$ = $1;}

				|	print_list COMMA print_item							{ $$ = $1;
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
				
				
read_list		:	ID													{ if (!perteneceTS(symbolTable, $1)) printf("Error en linea %d: Variable %s no declarada\n", yylineno, $1); else if (esConstante(symbolTable,$1)) printf("Error en linea %d: %s es constante\n", yylineno, $1); 
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

				|	read_list COMMA ID									{ if (!perteneceTS(symbolTable, $3)) printf("Error en linea %d: Variable %s no declarada\n", yylineno, $3); else if (esConstante(symbolTable,$3)) printf("Error en linea %d: %s es constante\n", yylineno, $3); 
					
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
																		liberaLC($2);
																		/*liberarReg(oper.arg1);*/ //PUEDE QUE SOBRE ESTO
																	} 
				
				|	LPAR expression RPAR								{ $$ = $2; }
				
				|	ID													{ if (!perteneceTS(symbolTable, $1)) printf("Error en linea %d: Variable %s no declarada\n", yylineno, $1); 
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