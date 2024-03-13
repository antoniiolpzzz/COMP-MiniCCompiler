
/* miniC.l */
/* Created by Antonio L—pez Toboso and Mercedes L—pez Caballero on 14/2/24. */

%{
#include "miniCSyntactic.tab.h" /*PENDIENTE CAMBIAR A .tab*/
#define MAX_INTEGER 2147483648
int in_range();
%}

%s comm

digito              [0-9]
letra               [a-zA-Z]
entero              {digito}+
panico				[^ \n\t\r/a-zA-Z_0-9{}(),;=+\-*"]+

%%

		/* COMENTARIOS Y MULTILINEA*/
"/*"										BEGIN comm;
<comm>[*]+[/]								BEGIN 0;
<comm>[^*]*									;
<comm>[*]+[^/*]*								;
"//"(.*)[\n]                                ;

		/* PALABRAS RESERVADAS*/
[ \n\t]+                                    ;
var											return VAR;
const										return CONST;
if											return IF;
else										return ELSE;
while										return WHILE;
print										return PRINT;
read										return READ;

		/* CARACTERES ESPECIALES*/
";"                                         return SEMICOLON;
","                                         return COMMA;
"+"                                         return PLUSOP;
"-"                                         return MINUSOP;
"*"											return TIMES;
"/"											return DIV;
"="											return EQUALS;
"("                                         return LPAR;
")"                                         return RPAR;
"{"											return LKEY;
"}"											return RKEY;

({letra}|_)({letra}|{digito}|_){0,31}       {yylval.cad = strdup(yytext); return ID;}
({letra}|_)({letra}|{digito}|_)*            {fprintf(stderr, "Linea %d: Error: ID (%s) excede el tama–o permitido.\n", yylineno, yytext); yylval.cad = strdup(yytext); return ID;};

{entero}                                    {yylval.cad = strdup(yytext); return in_range();}

\"([^"\n]|\\.)*\"							{yylval.cad = strdup(yytext); return STRING;}

{panico}									{fprintf(stderr, "Linea %d: Error: Caracter (%s) no permitido.\n",yylineno, yytext);}

%%

int in_range(){
	
	if( atoll(yytext) > MAX_INTEGER ) {
		printf("Linea %d: Error: NUMBER ( %s ) excede el tama–o permitido.\n", yylineno, yytext);
	}
	return NUMBER;
}
