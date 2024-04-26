/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 6 "Syntactic/miniCSyntactic.y"

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
	


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 41 "Syntactic/miniCSyntactic.y"
{
	char * str;
	ListaC cod;
}
/* Line 193 of yacc.c.  */
#line 198 "Syntactic/miniCSyntactic.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 211 "Syntactic/miniCSyntactic.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   207

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  46
/* YYNRULES -- Number of states.  */
#define YYNSTATES  102

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,    13,    14,    15,    21,    22,    28,
      33,    38,    40,    44,    46,    50,    51,    54,    59,    63,
      71,    77,    84,    90,    96,   102,   104,   106,   110,   112,
     114,   116,   120,   124,   128,   132,   136,   139,   143,   147,
     151,   155,   159,   163,   167,   169,   171
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      33,     0,    -1,    -1,    34,    29,    24,    25,    26,    35,
      40,    27,    -1,    -1,    -1,    35,     3,    36,    38,    17,
      -1,    -1,    35,     4,    37,    38,    17,    -1,    35,     4,
       1,    17,    -1,    35,     3,     1,    17,    -1,    39,    -1,
      38,    18,    39,    -1,    29,    -1,    29,    23,    45,    -1,
      -1,    40,    41,    -1,    29,    23,    45,    17,    -1,    26,
      40,    27,    -1,     5,    24,    45,    25,    41,     6,    41,
      -1,     5,    24,    45,    25,    41,    -1,    10,    41,     7,
      24,    45,    25,    -1,     7,    24,    45,    25,    41,    -1,
       8,    24,    42,    25,    17,    -1,     9,    24,    44,    25,
      17,    -1,     1,    -1,    43,    -1,    42,    18,    43,    -1,
      45,    -1,    28,    -1,    29,    -1,    44,    18,    29,    -1,
      45,    19,    45,    -1,    45,    20,    45,    -1,    45,    21,
      45,    -1,    45,    22,    45,    -1,    20,    45,    -1,    24,
      45,    25,    -1,    45,    11,    45,    -1,    45,    12,    45,
      -1,    45,    13,    45,    -1,    45,    14,    45,    -1,    45,
      15,    45,    -1,    45,    16,    45,    -1,    29,    -1,    30,
      -1,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    63,    78,    80,    80,    86,    86,    91,
      98,   108,   110,   118,   124,   140,   142,   150,   162,   164,
     203,   226,   265,   305,   308,   310,   319,   321,   329,   352,
     380,   405,   432,   444,   456,   468,   480,   490,   492,   508,
     523,   538,   553,   570,   588,   598,   606
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "CONST", "IF", "ELSE", "WHILE",
  "PRINT", "READ", "DO", "GREATER", "GEQUAL", "LESS", "LEQUAL", "EEQUAL",
  "NEQUAL", "SEMICOLON", "COMMA", "PLUSOP", "MINUSOP", "TIMES", "DIV",
  "EQUALS", "LPAR", "RPAR", "LKEY", "RKEY", "STRING", "ID", "NUMBER",
  "UMINUS", "$accept", "program", "@1", "declarations", "@2", "@3",
  "identifier_list", "identifier", "statement_list", "statement",
  "print_list", "print_item", "read_list", "expression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    34,    33,    35,    36,    35,    37,    35,    35,
      35,    38,    38,    39,    39,    40,    40,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    42,    42,    43,    43,
      44,    44,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     8,     0,     0,     5,     0,     5,     4,
       4,     1,     3,     1,     3,     0,     2,     4,     3,     7,
       5,     6,     5,     5,     5,     1,     1,     3,     1,     1,
       1,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     4,    15,     0,
       0,     0,     0,     0,     0,     0,    25,     0,     0,     0,
       0,     0,    15,     3,     0,    16,    10,    13,     0,    11,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     0,     8,    46,     0,     0,    44,    45,     0,     0,
      29,     0,    26,    28,    30,     0,     0,    18,     0,    14,
      12,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,    37,    38,    39,    40,    41,    42,    43,    32,    33,
      34,    35,    20,    22,    27,    23,    31,    24,     0,     0,
      21,    19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     8,    13,    15,    28,    29,    11,    25,
      51,    52,    55,    53
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -32
static const yytype_int16 yypact[] =
{
     -32,    20,   -23,   -32,     4,    -2,     3,   -32,     6,     2,
      14,    59,     7,    -4,     9,    -4,   -32,    21,    23,    25,
      27,    82,   -32,   -32,    34,   -32,   -32,    35,    -1,   -32,
     -32,     1,    41,    41,    26,    15,    52,    72,    41,    41,
     -32,    -4,   -32,   -32,    41,    41,   -32,   -32,   101,   116,
     -32,   -14,   -32,   173,   -32,   -13,    38,   -32,   161,   173,
     -32,   -32,   131,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    82,    82,    26,    13,    43,    46,    41,
     -32,   -32,   185,   185,   185,   185,   185,   185,     0,     0,
     -32,   -32,    68,   -32,   -32,   -32,   -32,   -32,   146,    82,
     -32,   -32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,   -32,   -32,   -32,   -32,    60,    53,    54,   -21,
     -32,    18,   -32,   -31
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -8
static const yytype_int8 yytable[] =
{
      36,    48,    49,    12,    75,    77,     4,    58,    59,     9,
      10,    76,    78,    61,    62,    14,    40,    41,    42,    41,
       3,    71,    72,     6,    26,    27,    30,    43,     5,     7,
      95,    -5,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    43,    -7,    54,    32,    44,    33,    98,    34,
      45,    35,    92,    93,    50,    46,    47,    38,    39,    56,
      16,    44,    79,    97,    17,    45,    18,    19,    20,    21,
      46,    47,    96,    16,    99,    31,    37,    17,   101,    18,
      19,    20,    21,    16,     0,    22,    23,    17,    24,    18,
      19,    20,    21,    94,    60,     0,     0,     0,    22,    57,
       0,    24,     0,     0,     0,     0,     0,     0,    22,     0,
       0,    24,    63,    64,    65,    66,    67,    68,     0,     0,
      69,    70,    71,    72,     0,     0,    73,    63,    64,    65,
      66,    67,    68,     0,     0,    69,    70,    71,    72,     0,
       0,    74,    63,    64,    65,    66,    67,    68,     0,     0,
      69,    70,    71,    72,     0,     0,    81,    63,    64,    65,
      66,    67,    68,     0,     0,    69,    70,    71,    72,     0,
       0,   100,    63,    64,    65,    66,    67,    68,    80,     0,
      69,    70,    71,    72,    63,    64,    65,    66,    67,    68,
       0,     0,    69,    70,    71,    72,    -8,    -8,    -8,    -8,
      -8,    -8,     0,     0,    69,    70,    71,    72
};

static const yytype_int8 yycheck[] =
{
      21,    32,    33,     1,    18,    18,    29,    38,    39,     3,
       4,    25,    25,    44,    45,     1,    17,    18,    17,    18,
       0,    21,    22,    25,    17,    29,    17,     1,    24,    26,
      17,    29,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,     1,    29,    29,    24,    20,    24,    79,    24,
      24,    24,    73,    74,    28,    29,    30,    23,    23,     7,
       1,    20,    24,    17,     5,    24,     7,     8,     9,    10,
      29,    30,    29,     1,     6,    15,    22,     5,    99,     7,
       8,     9,    10,     1,    -1,    26,    27,     5,    29,     7,
       8,     9,    10,    75,    41,    -1,    -1,    -1,    26,    27,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    29,    11,    12,    13,    14,    15,    16,    -1,    -1,
      19,    20,    21,    22,    -1,    -1,    25,    11,    12,    13,
      14,    15,    16,    -1,    -1,    19,    20,    21,    22,    -1,
      -1,    25,    11,    12,    13,    14,    15,    16,    -1,    -1,
      19,    20,    21,    22,    -1,    -1,    25,    11,    12,    13,
      14,    15,    16,    -1,    -1,    19,    20,    21,    22,    -1,
      -1,    25,    11,    12,    13,    14,    15,    16,    17,    -1,
      19,    20,    21,    22,    11,    12,    13,    14,    15,    16,
      -1,    -1,    19,    20,    21,    22,    11,    12,    13,    14,
      15,    16,    -1,    -1,    19,    20,    21,    22
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    34,     0,    29,    24,    25,    26,    35,     3,
       4,    40,     1,    36,     1,    37,     1,     5,     7,     8,
       9,    10,    26,    27,    29,    41,    17,    29,    38,    39,
      17,    38,    24,    24,    24,    24,    41,    40,    23,    23,
      17,    18,    17,     1,    20,    24,    29,    30,    45,    45,
      28,    42,    43,    45,    29,    44,     7,    27,    45,    45,
      39,    45,    45,    11,    12,    13,    14,    15,    16,    19,
      20,    21,    22,    25,    25,    18,    25,    18,    25,    24,
      17,    25,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    41,    41,    43,    17,    29,    17,    45,     6,
      25,    41
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 63 "Syntactic/miniCSyntactic.y"
    {symbolTable = creaLS();;}
    break;

  case 3:
#line 63 "Syntactic/miniCSyntactic.y"
    {
	
																if( numErrors() == 0){
																	imprimirTablaS(symbolTable);
																}
																concatenaLC((yyvsp[(6) - (8)].cod), (yyvsp[(7) - (8)].cod));
																if( numErrors() == 0){
																	imprimirCodigo((yyvsp[(6) - (8)].cod));
																}
																liberaLS(symbolTable);
																liberaLC((yyvsp[(6) - (8)].cod)); 
															;}
    break;

  case 4:
#line 78 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = creaLC(); ;}
    break;

  case 5:
#line 80 "Syntactic/miniCSyntactic.y"
    { symbolType = VARIABLE; ;}
    break;

  case 6:
#line 80 "Syntactic/miniCSyntactic.y"
    {
																							(yyval.cod) = (yyvsp[(1) - (5)].cod);
																							concatenaLC((yyval.cod), (yyvsp[(4) - (5)].cod));
																							liberaLC((yyvsp[(4) - (5)].cod));
																						;}
    break;

  case 7:
#line 86 "Syntactic/miniCSyntactic.y"
    { symbolType = CONSTANTE; ;}
    break;

  case 8:
#line 86 "Syntactic/miniCSyntactic.y"
    {
																							(yyval.cod) = (yyvsp[(1) - (5)].cod);
																							concatenaLC((yyval.cod), (yyvsp[(4) - (5)].cod));
																							liberaLC((yyvsp[(4) - (5)].cod));
																						;}
    break;

  case 9:
#line 91 "Syntactic/miniCSyntactic.y"
    {
												(yyval.cod) = creaLC();
												guardaResLC((yyval.cod), "" );
												fprintf(stderr, "Linea %d: Error en la declaración de una constante\n", yylineno);
												syntacticErr++;
											;}
    break;

  case 10:
#line 98 "Syntactic/miniCSyntactic.y"
    {
												(yyval.cod) = creaLC();
												guardaResLC((yyval.cod), "" );
												fprintf(stderr, "Linea %d: Error en la declaración de una variable\n", yylineno);
												syntacticErr++;
											;}
    break;

  case 11:
#line 108 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = (yyvsp[(1) - (1)].cod); ;}
    break;

  case 12:
#line 110 "Syntactic/miniCSyntactic.y"
    { 
																		(yyval.cod) = (yyvsp[(1) - (3)].cod);
																		concatenaLC((yyval.cod), (yyvsp[(3) - (3)].cod));
																		liberaLC((yyvsp[(3) - (3)].cod));
																	;}
    break;

  case 13:
#line 118 "Syntactic/miniCSyntactic.y"
    {if (!perteneceTS(symbolTable, (yyvsp[(1) - (1)].str))) añadeEntrada(symbolTable, (yyvsp[(1) - (1)].str), symbolType); else { fprintf(stderr, "Error en linea %d: Variable %s ya declarada\n", yylineno, (yyvsp[(1) - (1)].str)); semanticErr++; }
	
																		(yyval.cod) = creaLC(); 
																		
																	;}
    break;

  case 14:
#line 124 "Syntactic/miniCSyntactic.y"
    {if (!perteneceTS(symbolTable, (yyvsp[(1) - (3)].str))) añadeEntrada(symbolTable, (yyvsp[(1) - (3)].str), symbolType); else { fprintf(stderr, "Error en linea %d: Variable %s ya declarada\n", yylineno, (yyvsp[(1) - (3)].str)); semanticErr++; }
																		(yyval.cod) = (yyvsp[(3) - (3)].cod);
																		
																		Operacion oper;
																		
																		oper.op = "sw";
																		oper.res = recuperaResLC((yyvsp[(3) - (3)].cod));
																		oper.arg1 = concatenaStr("_", (yyvsp[(1) - (3)].str));
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		liberarReg(oper.res);
																		
																	;}
    break;

  case 15:
#line 140 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = creaLC(); ;}
    break;

  case 16:
#line 142 "Syntactic/miniCSyntactic.y"
    {
																		(yyval.cod) = (yyvsp[(1) - (2)].cod);
																		concatenaLC((yyval.cod), (yyvsp[(2) - (2)].cod));
																		liberaLC((yyvsp[(2) - (2)].cod));
																	;}
    break;

  case 17:
#line 150 "Syntactic/miniCSyntactic.y"
    { if (!perteneceTS(symbolTable, (yyvsp[(1) - (4)].str))) { fprintf(stderr, "Error en linea %d: Variable %s no declarada\n", yylineno, (yyvsp[(1) - (4)].str)); semanticErr++; } else { if (esConstante(symbolTable,(yyvsp[(1) - (4)].str))) { fprintf(stderr, "Error en linea %d: %s es constante\n", yylineno, (yyvsp[(1) - (4)].str)); semanticErr++; } } 													
																		
																		(yyval.cod) = (yyvsp[(3) - (4)].cod);
																		Operacion oper;
																		oper.op = "sw";
																		oper.res = recuperaResLC((yyvsp[(3) - (4)].cod));
																		oper.arg1 = concatenaStr("_", (yyvsp[(1) - (4)].str));
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		liberarReg(oper.res);
																	;}
    break;

  case 18:
#line 162 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = (yyvsp[(2) - (3)].cod); ;}
    break;

  case 19:
#line 164 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = (yyvsp[(3) - (7)].cod);
																		char * label_ELSE = newLabel();
																		char * label_END = newLabel();
																		
																		Operacion oper;
					
																		oper.op = "beqz";
																		oper.res = recuperaResLC((yyvsp[(3) - (7)].cod));
																		oper.arg1 = label_ELSE;
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		liberarReg(oper.res);
																		
																		concatenaLC((yyval.cod), (yyvsp[(5) - (7)].cod));
																		
																		oper.op = "b";
																		oper.res = label_END;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		
																		oper.op = concatenaStr(label_ELSE, ":");
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		
																		concatenaLC((yyval.cod), (yyvsp[(7) - (7)].cod));
																		
																		oper.op = concatenaStr(label_END, ":");
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		
																		liberaLC((yyvsp[(5) - (7)].cod));
																		liberaLC((yyvsp[(7) - (7)].cod));
																	;}
    break;

  case 20:
#line 203 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = (yyvsp[(3) - (5)].cod);
																		char * label_END = newLabel();
																		
																		Operacion oper;
																		
																		oper.op = "beqz";
																		oper.res = recuperaResLC((yyvsp[(3) - (5)].cod));
																		oper.arg1 = label_END;
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		liberarReg(oper.res);
																		
																		concatenaLC((yyval.cod), (yyvsp[(5) - (5)].cod));
																		
																		oper.op = concatenaStr(label_END, ":");
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		
																		liberaLC((yyvsp[(5) - (5)].cod));
																	;}
    break;

  case 21:
#line 226 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = creaLC();
																		concatenaLC((yyval.cod), (yyvsp[(5) - (6)].cod));
																		char * label_DOWHILE = newLabel();
																		char * label_ENDDW = newLabel();
					
																		Operacion oper;
					
																		oper.op = concatenaStr(label_DOWHILE, ":");
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		
																		concatenaLC((yyval.cod), (yyvsp[(2) - (6)].cod));
																		concatenaLC((yyval.cod), (yyvsp[(5) - (6)].cod));
					
																		oper.op = "beqz";
																		oper.res = recuperaResLC((yyvsp[(5) - (6)].cod));
																		oper.arg1 = label_ENDDW;
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		liberarReg(oper.res);
																							
																		oper.op = "b";
																		oper.res = label_DOWHILE;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
					
																		oper.op = concatenaStr(label_ENDDW, ":");
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
					
																		liberaLC((yyvsp[(5) - (6)].cod));
																		liberaLC((yyvsp[(2) - (6)].cod));
																	;}
    break;

  case 22:
#line 265 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = creaLC();
																		char * label_WHILE = newLabel();
																		char * label_ENDW = newLabel();
																		
																		Operacion oper;
																		
																		oper.op = concatenaStr(label_WHILE, ":");
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		
																		concatenaLC((yyval.cod), (yyvsp[(3) - (5)].cod));
																		
																		oper.op = "beqz";
																		oper.res = recuperaResLC((yyvsp[(3) - (5)].cod));
																		oper.arg1 = label_ENDW;
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		liberarReg(oper.res);
																		
																		concatenaLC((yyval.cod), (yyvsp[(5) - (5)].cod));
																		
																		oper.op = "b";
																		oper.res = label_WHILE;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		
																		oper.op = concatenaStr(label_ENDW, ":");
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		
																		liberaLC((yyvsp[(5) - (5)].cod));
																		liberaLC((yyvsp[(3) - (5)].cod));
																	;}
    break;

  case 23:
#line 305 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = (yyvsp[(3) - (5)].cod); ;}
    break;

  case 24:
#line 308 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = (yyvsp[(3) - (5)].cod); ;}
    break;

  case 25:
#line 310 "Syntactic/miniCSyntactic.y"
    {
									(yyval.cod) = creaLC();
									guardaResLC((yyval.cod), "" );
									fprintf(stderr, "Linea %d: Error en una sentencia\n", yylineno);
									syntacticErr++;
								;}
    break;

  case 26:
#line 319 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = (yyvsp[(1) - (1)].cod);;}
    break;

  case 27:
#line 321 "Syntactic/miniCSyntactic.y"
    {
																		(yyval.cod) = (yyvsp[(1) - (3)].cod);
																		concatenaLC((yyval.cod), (yyvsp[(3) - (3)].cod));
																		liberaLC((yyvsp[(3) - (3)].cod));
																	;}
    break;

  case 28:
#line 329 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = (yyvsp[(1) - (1)].cod);
																		Operacion oper;
																		
																		oper.op = "li";
																		oper.res = "$v0";
																		oper.arg1 = "1";
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		
																		oper.op = "move";
																		oper.res = "$a0";
																		oper.arg1 = recuperaResLC((yyvsp[(1) - (1)].cod));
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		liberarReg(oper.arg1);
																		
																		oper.op = "syscall";
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																	;}
    break;

  case 29:
#line 352 "Syntactic/miniCSyntactic.y"
    { añadeEntrada(symbolTable, (yyvsp[(1) - (1)].str), CADENA); 
				
																		(yyval.cod) = creaLC();
																		
																		Operacion oper;
																		
																		oper.op = "li";
																		oper.res = "$v0";
																		oper.arg1 = "4";
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		
																		oper.op = "la";
																		oper.res = "$a0";
																		oper.arg1 = concatenaStr("$str", "");
																		asprintf(&oper.arg1, "%s%d", oper.arg1, stringCount);
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		
																		oper.op = "syscall";
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																	;}
    break;

  case 30:
#line 380 "Syntactic/miniCSyntactic.y"
    { if (!perteneceTS(symbolTable, (yyvsp[(1) - (1)].str))) { fprintf(stderr, "Error en linea %d: Variable %s no declarada\n", yylineno, (yyvsp[(1) - (1)].str)); semanticErr++; } else { if (esConstante(symbolTable,(yyvsp[(1) - (1)].str))) { fprintf(stderr, "Error en linea %d: %s es constante\n", yylineno, (yyvsp[(1) - (1)].str)); semanticErr++; } }
																		(yyval.cod) = creaLC(); /*$1;*/
																		
																		Operacion oper;
																		
																		oper.op = "li";
																		oper.res = "$v0";
																		oper.arg1 = "5";
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		
																		oper.op = "syscall";
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		
																		oper.op = "sw";
																		oper.res = "$v0";
																		oper.arg1 = concatenaStr("_", (yyvsp[(1) - (1)].str));
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);

;}
    break;

  case 31:
#line 405 "Syntactic/miniCSyntactic.y"
    { if (!perteneceTS(symbolTable, (yyvsp[(3) - (3)].str))) { fprintf(stderr, "Error en linea %d: Variable %s no declarada\n", yylineno, (yyvsp[(3) - (3)].str)); semanticErr++; } else { if (esConstante(symbolTable,(yyvsp[(3) - (3)].str))) { fprintf(stderr, "Error en linea %d: %s es constante\n", yylineno, (yyvsp[(3) - (3)].str)); semanticErr++; } }
					
																		(yyval.cod) = (yyvsp[(1) - (3)].cod);
					
																		Operacion oper;
					
																		oper.op = "li";
																		oper.res = "$v0";
																		oper.arg1 = "5";
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
					
																		oper.op = "syscall";
																		oper.res = NULL;
																		oper.arg1 = NULL;
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
					
																		oper.op = "sw";
																		oper.res = "$v0";
																		oper.arg1 = concatenaStr("_", (yyvsp[(3) - (3)].str));
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																	;}
    break;

  case 32:
#line 432 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = (yyvsp[(1) - (3)].cod);
																		concatenaLC((yyval.cod), (yyvsp[(3) - (3)].cod));
																		Operacion oper;
																		oper.op = "add";
																		oper.res = recuperaResLC((yyvsp[(1) - (3)].cod));
																		oper.arg1 = recuperaResLC((yyvsp[(1) - (3)].cod));
																		oper.arg2 = recuperaResLC((yyvsp[(3) - (3)].cod));
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		guardaResLC((yyval.cod), oper.res);
																		liberaLC((yyvsp[(3) - (3)].cod));
																		liberarReg(oper.arg2); ;}
    break;

  case 33:
#line 444 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = (yyvsp[(1) - (3)].cod);
																		concatenaLC((yyval.cod), (yyvsp[(3) - (3)].cod));
																		Operacion oper;
																		oper.op = "sub";
																		oper.res = recuperaResLC((yyvsp[(1) - (3)].cod));
																		oper.arg1 = recuperaResLC((yyvsp[(1) - (3)].cod));
																		oper.arg2 = recuperaResLC((yyvsp[(3) - (3)].cod));
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		guardaResLC((yyval.cod), oper.res);
																		liberaLC((yyvsp[(3) - (3)].cod));
																		liberarReg(oper.arg2); ;}
    break;

  case 34:
#line 456 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = (yyvsp[(1) - (3)].cod);
																		concatenaLC((yyval.cod), (yyvsp[(3) - (3)].cod));
																		Operacion oper;
																		oper.op = "mul";
																		oper.res = recuperaResLC((yyvsp[(1) - (3)].cod));
																		oper.arg1 = recuperaResLC((yyvsp[(1) - (3)].cod));
																		oper.arg2 = recuperaResLC((yyvsp[(3) - (3)].cod));
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		guardaResLC((yyval.cod), oper.res);
																		liberaLC((yyvsp[(3) - (3)].cod));
																		liberarReg(oper.arg2); ;}
    break;

  case 35:
#line 468 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = (yyvsp[(1) - (3)].cod);
																		concatenaLC((yyval.cod), (yyvsp[(3) - (3)].cod));
																		Operacion oper;
																		oper.op = "div";
																		oper.res = recuperaResLC((yyvsp[(1) - (3)].cod));
																		oper.arg1 = recuperaResLC((yyvsp[(1) - (3)].cod));
																		oper.arg2 = recuperaResLC((yyvsp[(3) - (3)].cod));
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		guardaResLC((yyval.cod), oper.res);
																		liberaLC((yyvsp[(3) - (3)].cod));
																		liberarReg(oper.arg2); ;}
    break;

  case 36:
#line 480 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = (yyvsp[(2) - (2)].cod);
																		Operacion oper;
																		oper.op = "neg";
																		oper.res = recuperaResLC((yyvsp[(2) - (2)].cod));
																		oper.arg1 = recuperaResLC((yyvsp[(2) - (2)].cod));
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		guardaResLC((yyval.cod), oper.res);
																	;}
    break;

  case 37:
#line 490 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = (yyvsp[(2) - (3)].cod); ;}
    break;

  case 38:
#line 492 "Syntactic/miniCSyntactic.y"
    {
																	(yyval.cod) = (yyvsp[(1) - (3)].cod);
																	concatenaLC((yyval.cod), (yyvsp[(3) - (3)].cod));
																	
																	Operacion oper;
																	oper.op = "slt";
																	oper.res = recuperaResLC((yyvsp[(1) - (3)].cod));
																	oper.arg1 = recuperaResLC((yyvsp[(3) - (3)].cod));
																	oper.arg2 = recuperaResLC((yyvsp[(1) - (3)].cod));
																	insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																	guardaResLC((yyval.cod), oper.res);
																	
																	liberaLC((yyvsp[(3) - (3)].cod));
																	liberarReg(oper.arg1);
																;}
    break;

  case 39:
#line 508 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = (yyvsp[(1) - (3)].cod);
																	concatenaLC((yyval.cod), (yyvsp[(3) - (3)].cod));
																	
																	Operacion oper;
																	oper.op = "sge";
																	oper.res = recuperaResLC((yyvsp[(1) - (3)].cod));
																	oper.arg1 = recuperaResLC((yyvsp[(1) - (3)].cod));
																	oper.arg2 = recuperaResLC((yyvsp[(3) - (3)].cod));
																	insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																	guardaResLC((yyval.cod), oper.res);
																	
																	liberaLC((yyvsp[(3) - (3)].cod));
																	liberarReg(oper.arg2);
																;}
    break;

  case 40:
#line 523 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = (yyvsp[(1) - (3)].cod);
																	concatenaLC((yyval.cod), (yyvsp[(3) - (3)].cod));
																	
																	Operacion oper;
																	oper.op = "slt";
																	oper.res = recuperaResLC((yyvsp[(1) - (3)].cod));
																	oper.arg1 = recuperaResLC((yyvsp[(1) - (3)].cod));
																	oper.arg2 = recuperaResLC((yyvsp[(3) - (3)].cod));
																	insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																	guardaResLC((yyval.cod), oper.res);
																	
																	liberaLC((yyvsp[(3) - (3)].cod));
																	liberarReg(oper.arg2);
				;}
    break;

  case 41:
#line 538 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = (yyvsp[(1) - (3)].cod);
																	concatenaLC((yyval.cod), (yyvsp[(3) - (3)].cod));
																	
																	Operacion oper;
																	oper.op = "sle";
																	oper.res = recuperaResLC((yyvsp[(1) - (3)].cod));
																	oper.arg1 = recuperaResLC((yyvsp[(1) - (3)].cod));
																	oper.arg2 = recuperaResLC((yyvsp[(3) - (3)].cod));
																	insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																	guardaResLC((yyval.cod), oper.res);
																	
																	liberaLC((yyvsp[(3) - (3)].cod));
																	liberarReg(oper.arg2);
																;}
    break;

  case 42:
#line 553 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = (yyvsp[(1) - (3)].cod);
																	concatenaLC((yyval.cod), (yyvsp[(3) - (3)].cod));
																	
																	Operacion oper;
																	oper.op = "seq";
																	oper.res = recuperaResLC((yyvsp[(1) - (3)].cod));
																	oper.arg1 = recuperaResLC((yyvsp[(1) - (3)].cod));
																	oper.arg2 = recuperaResLC((yyvsp[(3) - (3)].cod));
																	insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																	guardaResLC((yyval.cod), oper.res);
																	
																	liberaLC((yyvsp[(3) - (3)].cod));
																	liberarReg(oper.arg2);
																	
																														
																;}
    break;

  case 43:
#line 570 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = (yyvsp[(1) - (3)].cod);
																	concatenaLC((yyval.cod), (yyvsp[(3) - (3)].cod));
					
																	Operacion oper;
																	oper.op = "sne";
																	oper.res = recuperaResLC((yyvsp[(1) - (3)].cod));
																	oper.arg1 = recuperaResLC((yyvsp[(1) - (3)].cod));
																	oper.arg2 = recuperaResLC((yyvsp[(3) - (3)].cod));
																	insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																	guardaResLC((yyval.cod), oper.res);
																	
																	liberaLC((yyvsp[(3) - (3)].cod));
																	liberarReg(oper.arg2);
																;}
    break;

  case 44:
#line 588 "Syntactic/miniCSyntactic.y"
    { if (!perteneceTS(symbolTable, (yyvsp[(1) - (1)].str))) { fprintf(stderr, "Error en linea %d: Variable %s no declarada\n", yylineno, (yyvsp[(1) - (1)].str)); semanticErr++; }
																		(yyval.cod) = creaLC();
																		Operacion oper;
																		oper.op = "lw";
																		oper.res = obtenerReg();
																		oper.arg1 = concatenaStr("_", (yyvsp[(1) - (1)].str));
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		guardaResLC((yyval.cod), oper.res); ;}
    break;

  case 45:
#line 598 "Syntactic/miniCSyntactic.y"
    { (yyval.cod) = creaLC();
																		Operacion oper;
																		oper.op = "li";
																		oper.res = obtenerReg();
																		oper.arg1 = (yyvsp[(1) - (1)].str);
																		oper.arg2 = NULL;
																		insertaLC((yyval.cod), finalLC((yyval.cod)), oper);
																		guardaResLC((yyval.cod), oper.res); ;}
    break;

  case 46:
#line 606 "Syntactic/miniCSyntactic.y"
    {
									(yyval.cod) = creaLC();
									guardaResLC((yyval.cod), "" );
									fprintf(stderr, "Linea %d: Error en una expresión aritmética\n", yylineno);
									syntacticErr++;
								;}
    break;


/* Line 1267 of yacc.c.  */
#line 2175 "Syntactic/miniCSyntactic.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 614 "Syntactic/miniCSyntactic.y"


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
