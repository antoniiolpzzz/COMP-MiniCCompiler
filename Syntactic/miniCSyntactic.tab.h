/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VAR = 258,
     CONST = 259,
     IF = 260,
     ELSE = 261,
     WHILE = 262,
     PRINT = 263,
     READ = 264,
     DO = 265,
     GREATER = 266,
     GEQUAL = 267,
     LESS = 268,
     LEQUAL = 269,
     EEQUAL = 270,
     NEQUAL = 271,
     SEMICOLON = 272,
     COMMA = 273,
     PLUSOP = 274,
     MINUSOP = 275,
     TIMES = 276,
     DIV = 277,
     EQUALS = 278,
     LPAR = 279,
     RPAR = 280,
     LKEY = 281,
     RKEY = 282,
     STRING = 283,
     ID = 284,
     NUMBER = 285,
     UMINUS = 286
   };
#endif
/* Tokens.  */
#define VAR 258
#define CONST 259
#define IF 260
#define ELSE 261
#define WHILE 262
#define PRINT 263
#define READ 264
#define DO 265
#define GREATER 266
#define GEQUAL 267
#define LESS 268
#define LEQUAL 269
#define EEQUAL 270
#define NEQUAL 271
#define SEMICOLON 272
#define COMMA 273
#define PLUSOP 274
#define MINUSOP 275
#define TIMES 276
#define DIV 277
#define EQUALS 278
#define LPAR 279
#define RPAR 280
#define LKEY 281
#define RKEY 282
#define STRING 283
#define ID 284
#define NUMBER 285
#define UMINUS 286




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 41 "Syntactic/miniCSyntactic.y"
{
	char * str;
	ListaC cod;
}
/* Line 1529 of yacc.c.  */
#line 116 "Syntactic/miniCSyntactic.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

