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
     SEMICOLON = 265,
     COMMA = 266,
     PLUSOP = 267,
     MINUSOP = 268,
     TIMES = 269,
     DIV = 270,
     EQUALS = 271,
     LPAR = 272,
     RPAR = 273,
     LKEY = 274,
     RKEY = 275,
     STRING = 276,
     ID = 277,
     NUMBER = 278,
     UMINUS = 279
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
#define SEMICOLON 265
#define COMMA 266
#define PLUSOP 267
#define MINUSOP 268
#define TIMES 269
#define DIV 270
#define EQUALS 271
#define LPAR 272
#define RPAR 273
#define LKEY 274
#define RKEY 275
#define STRING 276
#define ID 277
#define NUMBER 278
#define UMINUS 279




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 36 "Syntactic/miniCSyntactic.y"
{
	char * str;
	ListaC cod;
}
/* Line 1529 of yacc.c.  */
#line 102 "Syntactic/miniCSyntactic.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

