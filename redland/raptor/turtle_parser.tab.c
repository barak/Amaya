/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* If NAME_PREFIX is specified substitute the variables and functions
   names.  */
#define yyparse turtle_parser_parse
#define yylex   turtle_parser_lex
#define yyerror turtle_parser_error
#define yylval  turtle_parser_lval
#define yychar  turtle_parser_char
#define yydebug turtle_parser_debug
#define yynerrs turtle_parser_nerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PREFIX = 258,
     WS = 259,
     A = 260,
     AT = 261,
     HAT = 262,
     DOT = 263,
     COMMA = 264,
     SEMICOLON = 265,
     LEFT_SQUARE = 266,
     RIGHT_SQUARE = 267,
     LEFT_ROUND = 268,
     RIGHT_ROUND = 269,
     STRING_LITERAL = 270,
     URI_LITERAL = 271,
     BLANK_LITERAL = 272,
     QNAME_LITERAL = 273,
     IDENTIFIER = 274,
     ERROR = 275
   };
#endif
#define PREFIX 258
#define WS 259
#define A 260
#define AT 261
#define HAT 262
#define DOT 263
#define COMMA 264
#define SEMICOLON 265
#define LEFT_SQUARE 266
#define RIGHT_SQUARE 267
#define LEFT_ROUND 268
#define RIGHT_ROUND 269
#define STRING_LITERAL 270
#define URI_LITERAL 271
#define BLANK_LITERAL 272
#define QNAME_LITERAL 273
#define IDENTIFIER 274
#define ERROR 275




/* Copy the first part of user declarations.  */
#line 27 "./turtle_parser.y"

#ifdef HAVE_CONFIG_H
#include <raptor_config.h>
#endif

#ifdef WIN32
#include <win32_config.h>
#endif

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#include <raptor.h>
#include <raptor_internal.h>

#include <turtle_parser.tab.h>

#define YY_DECL int turtle_lexer_lex (YYSTYPE *turtle_parser_lval, yyscan_t yyscanner)
#include <turtle_lexer.h>

#include <turtle_common.h>


/* Make verbose error messages for syntax errors */
#ifdef RAPTOR_DEBUG
#define YYERROR_VERBOSE 1
#endif

/* Slow down the grammar operation and watch it work */
#if RAPTOR_DEBUG > 2
#define YYDEBUG 1
#endif

/* the lexer does not seem to track this */
#undef RAPTOR_TURTLE_USE_ERROR_COLUMNS

/* Prototypes */ 
int turtle_parser_error(void* rdf_parser, const char *msg);

/* Missing turtle_lexer.c/h prototypes */
int turtle_lexer_get_column(yyscan_t yyscanner);
/* Not used here */
/* void turtle_lexer_set_column(int  column_no , yyscan_t yyscanner);*/


/* What the lexer wants */
extern int turtle_lexer_lex (YYSTYPE *turtle_parser_lval, yyscan_t scanner);
#define YYLEX_PARAM ((raptor_turtle_parser*)(((raptor_parser*)rdf_parser)->context))->scanner

/* Pure parser argument (a void*) */
#define YYPARSE_PARAM rdf_parser

/* Make the yyerror below use the rdf_parser */
#undef yyerror
#define yyerror(message) turtle_parser_error(rdf_parser, message)

/* Make lex/yacc interface as small as possible */
#undef yylex
#define yylex turtle_lexer_lex


static raptor_triple* raptor_new_triple(raptor_identifier *subject, raptor_identifier *predicate, raptor_identifier *object);
static void raptor_free_triple(raptor_triple *triple);

#ifdef RAPTOR_DEBUG
static void raptor_triple_print(raptor_triple *data, FILE *fh);
#endif


/* Prototypes for local functions */
static void raptor_turtle_generate_statement(raptor_parser *parser, raptor_triple *triple);



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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 118 "./turtle_parser.y"
typedef union YYSTYPE {
  unsigned char *string;
  raptor_identifier *identifier;
  raptor_sequence *sequence;
  raptor_uri *uri;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 213 "turtle_parser.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 225 "turtle_parser.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
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
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   53

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  21
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  15
/* YYNRULES -- Number of rules. */
#define YYNRULES  34
/* YYNRULES -- Number of states. */
#define YYNSTATES  51

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   275

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
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
      15,    16,    17,    18,    19,    20
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    15,    18,    22,
      24,    26,    28,    33,    36,    37,    42,    44,    46,    48,
      50,    52,    54,    58,    64,    70,    74,    78,    80,    82,
      84,    86,    90,    92,    96
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      22,     0,    -1,    23,    -1,    24,    23,    -1,    -1,    28,
      -1,    29,    27,     8,    -1,     1,     8,    -1,    31,     9,
      25,    -1,    31,    -1,    30,    -1,     5,    -1,    26,    25,
      10,    27,    -1,    26,    25,    -1,    -1,     3,    19,    16,
       8,    -1,    33,    -1,    34,    -1,    33,    -1,    33,    -1,
      34,    -1,    32,    -1,    15,     6,    19,    -1,    15,     6,
      19,     7,    16,    -1,    15,     6,    19,     7,    18,    -1,
      15,     7,    16,    -1,    15,     7,    18,    -1,    15,    -1,
      16,    -1,    18,    -1,    17,    -1,    11,    27,    12,    -1,
      35,    -1,    13,    25,    14,    -1,    13,    14,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   154,   154,   157,   158,   161,   162,   202,   206,   239,
     273,   283,   297,   356,   392,   400,   429,   433,   439,   445,
     449,   453,   465,   473,   485,   497,   509,   520,   531,   542,
     555,   562,   603,   610,   676
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PREFIX", "WS", "A", "AT", "HAT", "DOT", 
  "COMMA", "SEMICOLON", "LEFT_SQUARE", "RIGHT_SQUARE", "LEFT_ROUND", 
  "RIGHT_ROUND", "STRING_LITERAL", "URI_LITERAL", "BLANK_LITERAL", 
  "QNAME_LITERAL", "IDENTIFIER", "ERROR", "$accept", "Document", 
  "statementList", "statement", "objectList", "verb", "propertyList", 
  "directive", "subject", "predicate", "object", "literal", "resource", 
  "blank", "collection", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    21,    22,    23,    23,    24,    24,    24,    25,    25,
      26,    26,    27,    27,    27,    28,    29,    29,    30,    31,
      31,    31,    32,    32,    32,    32,    32,    32,    33,    33,
      34,    34,    34,    35,    35
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     0,     1,     3,     2,     3,     1,
       1,     1,     4,     2,     0,     4,     1,     1,     1,     1,
       1,     1,     3,     5,     5,     3,     3,     1,     1,     1,
       1,     3,     1,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     0,    14,     0,    28,    30,    29,     0,     2,
       0,     5,    14,    16,    17,    32,     7,     0,    11,     0,
       0,    10,    18,    34,    27,     0,     9,    21,    19,    20,
       1,     3,     0,     0,    13,    31,     0,     0,    33,     0,
       6,    15,    14,    22,    25,    26,     8,    12,     0,    23,
      24
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,     8,     9,    10,    25,    19,    20,    11,    12,    21,
      26,    27,    22,    29,    15
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -18
static const yysigned_char yypact[] =
{
      12,    -3,    -1,    -2,    27,   -18,   -18,   -18,    24,   -18,
      12,   -18,    -2,   -18,   -18,   -18,   -18,    10,   -18,    35,
      15,   -18,   -18,   -18,    14,    18,    25,   -18,   -18,   -18,
     -18,   -18,    28,    29,    23,   -18,    16,   -10,   -18,    35,
     -18,   -18,    -2,    40,   -18,   -18,   -18,   -18,    -7,   -18,
     -18
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -18,   -18,    39,   -18,   -17,   -18,   -11,   -18,   -18,   -18,
     -18,   -18,     0,     7,   -18
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yysigned_char yytable[] =
{
      13,    32,    34,    18,    28,    16,    44,    14,    45,    49,
      13,    50,    -4,     1,     5,     2,     7,    14,    17,    28,
      36,    37,    46,     3,    30,     4,    33,    35,     5,     6,
       7,    47,    38,    42,    39,    43,    40,    41,     3,    28,
       4,    23,    24,     5,     6,     7,     3,    48,     4,    31,
      24,     5,     6,     7
};

static const unsigned char yycheck[] =
{
       0,    12,    19,     5,     4,     8,    16,     0,    18,    16,
      10,    18,     0,     1,    16,     3,    18,    10,    19,    19,
       6,     7,    39,    11,     0,    13,    16,    12,    16,    17,
      18,    42,    14,    10,     9,    19,     8,     8,    11,    39,
      13,    14,    15,    16,    17,    18,    11,     7,    13,    10,
      15,    16,    17,    18
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     1,     3,    11,    13,    16,    17,    18,    22,    23,
      24,    28,    29,    33,    34,    35,     8,    19,     5,    26,
      27,    30,    33,    14,    15,    25,    31,    32,    33,    34,
       0,    23,    27,    16,    25,    12,     6,     7,    14,     9,
       8,     8,    10,    19,    16,    18,    25,    27,     7,    16,
      18
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1

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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
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
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
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
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  /* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
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

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
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

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
        case 6:
#line 163 "./turtle_parser.y"
    {
  int i;

#if RAPTOR_DEBUG > 1  
  printf("statement 2\n subject=");
  raptor_identifier_print(stdout, yyvsp[-2].identifier);
  if(yyvsp[-1].sequence) {
    printf("\n propertyList=");
    raptor_sequence_print(yyvsp[-1].sequence, stdout);
    printf("\n");
  } else     
    printf("\n and empty propertyList\n");
#endif

  if(yyvsp[-1].sequence) {
    /* non-empty property list, handle it  */
    for(i=0; i<raptor_sequence_size(yyvsp[-1].sequence); i++) {
      raptor_triple* t2=(raptor_triple*)raptor_sequence_get_at(yyvsp[-1].sequence, i);
      raptor_identifier *i2=(raptor_identifier*)RAPTOR_CALLOC(raptor_identifier, 1, sizeof(raptor_identifier));
      raptor_copy_identifier(i2, yyvsp[-2].identifier);
      t2->subject=i2;
      t2->subject->is_malloced=1;
    }
#if RAPTOR_DEBUG > 1  
    printf(" after substitution propertyList=");
    raptor_sequence_print(yyvsp[-1].sequence, stdout);
    printf("\n\n");
#endif
    for(i=0; i<raptor_sequence_size(yyvsp[-1].sequence); i++) {
      raptor_triple* t2=(raptor_triple*)raptor_sequence_get_at(yyvsp[-1].sequence, i);
      raptor_turtle_generate_statement((raptor_parser*)rdf_parser, t2);
    }

    raptor_free_sequence(yyvsp[-1].sequence);
  }

  if(yyvsp[-2].identifier)
    raptor_free_identifier(yyvsp[-2].identifier);
}
    break;

  case 8:
#line 207 "./turtle_parser.y"
    {
  raptor_triple *triple;

#if RAPTOR_DEBUG > 1  
  printf("objectList 1\n");
  if(yyvsp[-2].identifier) {
    printf(" object=\n");
    raptor_identifier_print(stdout, yyvsp[-2].identifier);
    printf("\n");
  } else  
    printf(" and empty object\n");
  if(yyvsp[0].sequence) {
    printf(" objectList=");
    raptor_sequence_print(yyvsp[0].sequence, stdout);
    printf("\n");
  } else
    printf(" and empty objectList\n");
#endif

  if(!yyvsp[-2].identifier)
    yyval.sequence=NULL;
  else {
    triple=raptor_new_triple(NULL, NULL, yyvsp[-2].identifier);
    yyval.sequence=yyvsp[0].sequence;
    raptor_sequence_shift(yyval.sequence, triple);
#if RAPTOR_DEBUG > 1  
    printf(" objectList is now ");
    raptor_sequence_print(yyval.sequence, stdout);
    printf("\n\n");
#endif
  }
}
    break;

  case 9:
#line 240 "./turtle_parser.y"
    {
  raptor_triple *triple;

#if RAPTOR_DEBUG > 1  
  printf("objectList 2\n");
  if(yyvsp[0].identifier) {
    printf(" object=\n");
    raptor_identifier_print(stdout, yyvsp[0].identifier);
    printf("\n");
  } else  
    printf(" and empty object\n");
#endif

  if(!yyvsp[0].identifier)
    yyval.sequence=NULL;
  else {
    triple=raptor_new_triple(NULL, NULL, yyvsp[0].identifier);
#ifdef RAPTOR_DEBUG
    yyval.sequence=raptor_new_sequence((raptor_free_handler*)raptor_free_triple,
                           (raptor_print_handler*)raptor_triple_print);
#else
    yyval.sequence=raptor_new_sequence((raptor_free_handler*)raptor_free_triple, NULL);
#endif
    raptor_sequence_push(yyval.sequence, triple);
#if RAPTOR_DEBUG > 1  
    printf(" objectList is now ");
    raptor_sequence_print(yyval.sequence, stdout);
    printf("\n\n");
#endif
  }
}
    break;

  case 10:
#line 274 "./turtle_parser.y"
    {
#if RAPTOR_DEBUG > 1  
  printf("verb predicate=");
  raptor_identifier_print(stdout, yyvsp[0].identifier);
  printf("\n");
#endif

  yyval.identifier=yyvsp[0].identifier;
}
    break;

  case 11:
#line 284 "./turtle_parser.y"
    {
  raptor_uri *uri;

#if RAPTOR_DEBUG > 1  
  printf("verb predicate=rdf:type (a)\n");
#endif

  uri=raptor_new_uri_for_rdf_concept("type");
  yyval.identifier=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_RESOURCE, uri, RAPTOR_URI_SOURCE_URI, NULL, NULL, NULL, NULL);
}
    break;

  case 12:
#line 298 "./turtle_parser.y"
    {
  int i;
  
#if RAPTOR_DEBUG > 1  
  printf("propertyList 1\n verb=");
  raptor_identifier_print(stdout, yyvsp[-3].identifier);
  printf("\n objectList=");
  raptor_sequence_print(yyvsp[-2].sequence, stdout);
  printf("\n propertyList=");
  raptor_sequence_print(yyvsp[0].sequence, stdout);
  printf("\n\n");
#endif
  
  if(yyvsp[-2].sequence == NULL) {
#if RAPTOR_DEBUG > 1  
    printf(" empty objectList not processed\n");
#endif
  } else if(yyvsp[-3].identifier && yyvsp[-2].sequence) {
    /* non-empty property list, handle it  */
    for(i=0; i<raptor_sequence_size(yyvsp[-2].sequence); i++) {
      raptor_triple* t2=(raptor_triple*)raptor_sequence_get_at(yyvsp[-2].sequence, i);
      raptor_identifier *i2=(raptor_identifier*)RAPTOR_CALLOC(raptor_identifier, 1, sizeof(raptor_identifier));
      raptor_copy_identifier(i2, yyvsp[-3].identifier);
      t2->predicate=i2;
      t2->predicate->is_malloced=1;
    }
  
#if RAPTOR_DEBUG > 1  
    printf(" after substitution objectList=");
    raptor_sequence_print(yyvsp[-2].sequence, stdout);
    printf("\n");
#endif
  }

  if(yyvsp[0].sequence == NULL) {
#if RAPTOR_DEBUG > 1  
    printf(" empty propertyList not copied\n\n");
#endif
  } else if (yyvsp[-3].identifier && yyvsp[-2].sequence && yyvsp[0].sequence) {
    while(raptor_sequence_size(yyvsp[0].sequence) > 0) {
      raptor_triple* t2=(raptor_triple*)raptor_sequence_unshift(yyvsp[0].sequence);
      raptor_sequence_push(yyvsp[-2].sequence, t2);
    }

#if RAPTOR_DEBUG > 1  
    printf(" after appending objectList=");
    raptor_sequence_print(yyvsp[-2].sequence, stdout);
    printf("\n\n");
#endif

    raptor_free_sequence(yyvsp[0].sequence);
  }

  if(yyvsp[-3].identifier)
    raptor_free_identifier(yyvsp[-3].identifier);

  yyval.sequence=yyvsp[-2].sequence;
}
    break;

  case 13:
#line 357 "./turtle_parser.y"
    {
  int i;
#if RAPTOR_DEBUG > 1  
  printf("propertyList 2\n verb=");
  raptor_identifier_print(stdout, yyvsp[-1].identifier);
  if(yyvsp[0].sequence) {
    printf("\n objectList=");
    raptor_sequence_print(yyvsp[0].sequence, stdout);
    printf("\n");
  } else
    printf("\n and empty objectList\n");
#endif

  if(yyvsp[-1].identifier && yyvsp[0].sequence) {
    for(i=0; i<raptor_sequence_size(yyvsp[0].sequence); i++) {
      raptor_triple* t2=(raptor_triple*)raptor_sequence_get_at(yyvsp[0].sequence, i);
      raptor_identifier *i2=(raptor_identifier*)RAPTOR_CALLOC(raptor_identifier, 1, sizeof(raptor_identifier));
      raptor_copy_identifier(i2, yyvsp[-1].identifier);
      t2->predicate=i2;
      t2->predicate->is_malloced=1;
    }

#if RAPTOR_DEBUG > 1  
    printf(" after substitution objectList=");
    raptor_sequence_print(yyvsp[0].sequence, stdout);
    printf("\n\n");
#endif
  }

  if(yyvsp[-1].identifier)
    raptor_free_identifier(yyvsp[-1].identifier);

  yyval.sequence=yyvsp[0].sequence;
}
    break;

  case 14:
#line 392 "./turtle_parser.y"
    {
#if RAPTOR_DEBUG > 1  
  printf("propertyList 3\n empty returning NULL\n\n");
#endif
  yyval.sequence=NULL;
}
    break;

  case 15:
#line 401 "./turtle_parser.y"
    {
  unsigned char *prefix=yyvsp[-2].string;
  raptor_turtle_parser* turtle_parser=(raptor_turtle_parser*)(((raptor_parser*)rdf_parser)->context);

#if RAPTOR_DEBUG > 1  
  printf("directive @prefix %s %s\n",(yyvsp[-2].string ? (char*)yyvsp[-2].string : "(default)"),raptor_uri_as_string(yyvsp[-1].uri));
#endif

  if(prefix) {
    size_t len=strlen((const char*)prefix);
    if(prefix[len-1] == ':') {
      if(len == 1)
         /* declaring default namespace prefix @prefix : ... */
        prefix=NULL;
      else
        prefix[len-1]='\0';
    }
  }

  raptor_namespaces_start_namespace_full(&turtle_parser->namespaces,
                                         prefix, 
                                         (const unsigned char*)raptor_uri_as_string(yyvsp[-1].uri), 0);
  if(yyvsp[-2].string)
    free(yyvsp[-2].string);
  raptor_free_uri(yyvsp[-1].uri);
}
    break;

  case 16:
#line 430 "./turtle_parser.y"
    {
  yyval.identifier=yyvsp[0].identifier;
}
    break;

  case 17:
#line 434 "./turtle_parser.y"
    {
  yyval.identifier=yyvsp[0].identifier;
}
    break;

  case 18:
#line 440 "./turtle_parser.y"
    {
  yyval.identifier=yyvsp[0].identifier;
}
    break;

  case 19:
#line 446 "./turtle_parser.y"
    {
  yyval.identifier=yyvsp[0].identifier;
}
    break;

  case 20:
#line 450 "./turtle_parser.y"
    {
  yyval.identifier=yyvsp[0].identifier;
}
    break;

  case 21:
#line 454 "./turtle_parser.y"
    {
#if RAPTOR_DEBUG > 1  
  printf("object literal=");
  raptor_identifier_print(stdout, yyvsp[0].identifier);
  printf("\n");
#endif

  yyval.identifier=yyvsp[0].identifier;
}
    break;

  case 22:
#line 466 "./turtle_parser.y"
    {
#if RAPTOR_DEBUG > 1  
  printf("literal + language string=\"%s\"\n", yyvsp[-2].string);
#endif

  yyval.identifier=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_LITERAL, NULL, RAPTOR_URI_SOURCE_ELEMENT, NULL, yyvsp[-2].string, NULL, yyvsp[0].string);
}
    break;

  case 23:
#line 474 "./turtle_parser.y"
    {
#if RAPTOR_DEBUG > 1  
  printf("literal + language=\"%s\" datatype string=\"%s\" uri=\"%s\"\n", yyvsp[-4].string, yyvsp[-2].string, raptor_uri_as_string(yyvsp[0].uri));
#endif

  if(yyvsp[0].uri)
    yyval.identifier=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_LITERAL, NULL, RAPTOR_URI_SOURCE_ELEMENT, NULL, yyvsp[-4].string, yyvsp[0].uri, yyvsp[-2].string);
  else
    yyval.identifier=NULL;
    
}
    break;

  case 24:
#line 486 "./turtle_parser.y"
    {
#if RAPTOR_DEBUG > 1  
  printf("literal + language=\"%s\" datatype string=\"%s\" qname URI=<%s>\n", yyvsp[-4].string, yyvsp[-2].string, raptor_uri_as_string(yyvsp[0].uri));
#endif

  if(yyvsp[0].uri)
    yyval.identifier=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_LITERAL, NULL, RAPTOR_URI_SOURCE_ELEMENT, NULL, (const unsigned char*)yyvsp[-4].string, yyvsp[0].uri, yyvsp[-2].string);
  else
    yyval.identifier=NULL;

}
    break;

  case 25:
#line 498 "./turtle_parser.y"
    {
#if RAPTOR_DEBUG > 1  
  printf("literal + datatype string=\"%s\" uri=\"%s\"\n", yyvsp[-2].string, raptor_uri_as_string(yyvsp[0].uri));
#endif

  if(yyvsp[0].uri)
    yyval.identifier=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_LITERAL, NULL, RAPTOR_URI_SOURCE_ELEMENT, NULL, yyvsp[-2].string, yyvsp[0].uri, NULL);
  else
    yyval.identifier=NULL;
    
}
    break;

  case 26:
#line 510 "./turtle_parser.y"
    {
#if RAPTOR_DEBUG > 1  
  printf("literal + datatype string=\"%s\" qname URI=<%s>\n", yyvsp[-2].string, raptor_uri_as_string(yyvsp[0].uri));
#endif

  if(yyvsp[0].uri) {
    yyval.identifier=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_LITERAL, NULL, RAPTOR_URI_SOURCE_ELEMENT, NULL, yyvsp[-2].string, yyvsp[0].uri, NULL);
  } else
    yyval.identifier=NULL;
}
    break;

  case 27:
#line 521 "./turtle_parser.y"
    {
#if RAPTOR_DEBUG > 1  
  printf("literal string=\"%s\"\n", yyvsp[0].string);
#endif

  yyval.identifier=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_LITERAL, NULL, RAPTOR_URI_SOURCE_ELEMENT, NULL, yyvsp[0].string, NULL, NULL);
}
    break;

  case 28:
#line 532 "./turtle_parser.y"
    {
#if RAPTOR_DEBUG > 1  
  printf("resource URI=<%s>\n", raptor_uri_as_string(yyvsp[0].uri));
#endif

  if(yyvsp[0].uri)
    yyval.identifier=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_RESOURCE, yyvsp[0].uri, RAPTOR_URI_SOURCE_URI, NULL, NULL, NULL, NULL);
  else
    yyval.identifier=NULL;
}
    break;

  case 29:
#line 543 "./turtle_parser.y"
    {
#if RAPTOR_DEBUG > 1  
  printf("resource qname URI=<%s>\n", raptor_uri_as_string(yyvsp[0].uri));
#endif

  if(yyvsp[0].uri)
    yyval.identifier=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_RESOURCE, yyvsp[0].uri, RAPTOR_URI_SOURCE_ELEMENT, NULL, NULL, NULL, NULL);
  else
    yyval.identifier=NULL;
}
    break;

  case 30:
#line 556 "./turtle_parser.y"
    {
#if RAPTOR_DEBUG > 1  
  printf("subject blank=\"%s\"\n", yyvsp[0].string);
#endif
  yyval.identifier=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_ANONYMOUS, NULL, RAPTOR_URI_SOURCE_BLANK_ID, yyvsp[0].string, NULL, NULL, NULL);
}
    break;

  case 31:
#line 563 "./turtle_parser.y"
    {
  int i;
  const unsigned char *id=raptor_generate_id((raptor_parser*)rdf_parser, 0, NULL);
  
  yyval.identifier=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_ANONYMOUS, NULL, RAPTOR_URI_SOURCE_GENERATED, id, NULL, NULL, NULL);

  if(yyvsp[-1].sequence == NULL) {
#if RAPTOR_DEBUG > 1  
    printf("resource\n propertyList=");
    raptor_identifier_print(stdout, yyval.identifier);
    printf("\n");
#endif
  } else {
    /* non-empty property list, handle it  */
#if RAPTOR_DEBUG > 1  
    printf("resource\n propertyList=");
    raptor_sequence_print(yyvsp[-1].sequence, stdout);
    printf("\n");
#endif

    for(i=0; i<raptor_sequence_size(yyvsp[-1].sequence); i++) {
      raptor_triple* t2=(raptor_triple*)raptor_sequence_get_at(yyvsp[-1].sequence, i);
      raptor_identifier *i2=(raptor_identifier*)RAPTOR_CALLOC(raptor_identifier, 1, sizeof(raptor_identifier));
      raptor_copy_identifier(i2, yyval.identifier);
      t2->subject=i2;
      t2->subject->is_malloced=1;
      raptor_turtle_generate_statement((raptor_parser*)rdf_parser, t2);
    }

#if RAPTOR_DEBUG > 1
    printf(" after substitution objectList=");
    raptor_sequence_print(yyvsp[-1].sequence, stdout);
    printf("\n\n");
#endif

    raptor_free_sequence(yyvsp[-1].sequence);

  }
  
}
    break;

  case 32:
#line 604 "./turtle_parser.y"
    {
  yyval.identifier=yyvsp[0].identifier;
}
    break;

  case 33:
#line 611 "./turtle_parser.y"
    {
  int i;
  raptor_turtle_parser* turtle_parser=(raptor_turtle_parser*)(((raptor_parser*)rdf_parser)->context);
  raptor_identifier* first_identifier;
  raptor_identifier* rest_identifier;
  raptor_identifier* object;

#if RAPTOR_DEBUG > 1  
  printf("collection\n objectList=");
  raptor_sequence_print(yyvsp[-1].sequence, stdout);
  printf("\n");
#endif

  first_identifier=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_RESOURCE, raptor_uri_copy(turtle_parser->first_uri), RAPTOR_URI_SOURCE_URI, NULL, NULL, NULL, NULL);
  rest_identifier=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_RESOURCE, raptor_uri_copy(turtle_parser->rest_uri), RAPTOR_URI_SOURCE_URI, NULL, NULL, NULL, NULL);
  
  /* non-empty property list, handle it  */
#if RAPTOR_DEBUG > 1  
  printf("resource\n propertyList=");
  raptor_sequence_print(yyvsp[-1].sequence, stdout);
  printf("\n");
#endif

  object=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_RESOURCE, raptor_uri_copy(turtle_parser->nil_uri), RAPTOR_URI_SOURCE_URI, NULL, NULL, NULL, NULL);

  for(i=raptor_sequence_size(yyvsp[-1].sequence)-1; i>=0; i--) {
    raptor_triple* t2=(raptor_triple*)raptor_sequence_get_at(yyvsp[-1].sequence, i);
    const unsigned char *blank_id=raptor_generate_id((raptor_parser*)rdf_parser, 0, NULL);
    raptor_identifier* blank=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_ANONYMOUS, NULL, RAPTOR_URI_SOURCE_GENERATED, blank_id, NULL, NULL, NULL);
    raptor_identifier* temp;
    
    t2->subject=blank;
    t2->predicate=first_identifier;
    /* t2->object already set to the value we want */
    raptor_turtle_generate_statement((raptor_parser*)rdf_parser, t2);
    
    temp=t2->object;
    
    t2->subject=blank;
    t2->predicate=rest_identifier;
    t2->object=object;
    raptor_turtle_generate_statement((raptor_parser*)rdf_parser, t2);

    raptor_free_identifier(object);
      
    t2->subject=NULL;
    t2->predicate=NULL;
    t2->object=temp;

    object=blank;
  }
  
#if RAPTOR_DEBUG > 1
  printf(" after substitution objectList=");
  raptor_sequence_print(yyvsp[-1].sequence, stdout);
  printf("\n\n");
#endif

  raptor_free_sequence(yyvsp[-1].sequence);

  raptor_free_identifier(first_identifier);
  raptor_free_identifier(rest_identifier);

  yyval.identifier=object;
}
    break;

  case 34:
#line 677 "./turtle_parser.y"
    {
  raptor_turtle_parser* turtle_parser=(raptor_turtle_parser*)(((raptor_parser*)rdf_parser)->context);

#if RAPTOR_DEBUG > 1  
  printf("collection\n empty\n");
#endif

  yyval.identifier=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_RESOURCE, raptor_uri_copy(turtle_parser->nil_uri), RAPTOR_URI_SOURCE_URI, NULL, NULL, NULL, NULL);
}
    break;


    }

/* Line 991 of yacc.c.  */
#line 1723 "turtle_parser.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab2;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:



  goto yyerrlab2;


/*---------------------------------------------------------------.
| yyerrlab2 -- pop states until the error token can be shifted.  |
`---------------------------------------------------------------*/
yyerrlab2:
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 154 "./turtle_parser.y"



/* Support functions */

/* This is declared in turtle_lexer.h but never used, so we always get
 * a warning unless this dummy code is here.  Used once below as a return.
 */
static int yy_init_globals (yyscan_t yyscanner ) { return 0; };


/* helper - everything passed in is now owned by triple */
static raptor_triple*
raptor_new_triple(raptor_identifier *subject,
                  raptor_identifier *predicate,
                  raptor_identifier *object) 
{
  raptor_triple* t;
  
  t=(raptor_triple*)RAPTOR_MALLOC(raptor_triple, sizeof(raptor_triple));
  if(!t)
    return NULL;
  
  t->subject=subject;
  t->predicate=predicate;
  t->object=object;

  return t;
}

static void
raptor_free_triple(raptor_triple *t) {
  if(t->subject)
    raptor_free_identifier(t->subject);
  if(t->predicate)
    raptor_free_identifier(t->predicate);
  if(t->object)
    raptor_free_identifier(t->object);
  RAPTOR_FREE(raptor_triple, t);
}
 
#ifdef RAPTOR_DEBUG
static void
raptor_triple_print(raptor_triple *t, FILE *fh) 
{
  fputs("triple(", fh);
  raptor_identifier_print(fh, t->subject);
  fputs(", ", fh);
  raptor_identifier_print(fh, t->predicate);
  fputs(", ", fh);
  raptor_identifier_print(fh, t->object);
  fputc(')', fh);
}
#endif


extern char *filename;
 
int
turtle_parser_error(void* ctx, const char *msg)
{
  raptor_parser* rdf_parser=(raptor_parser *)ctx;
  raptor_turtle_parser* turtle_parser=(raptor_turtle_parser*)rdf_parser->context;
  
  rdf_parser->locator.line=turtle_parser->lineno;
#ifdef RAPTOR_TURTLE_USE_ERROR_COLUMNS
  rdf_parser->locator.column=turtle_lexer_get_column(yyscanner);
#endif

  raptor_parser_simple_error(rdf_parser, msg);
  return yy_init_globals(NULL); /* 0 but a way to use yy_init_globals */
}


int
turtle_syntax_error(raptor_parser *rdf_parser, const char *message, ...)
{
  raptor_turtle_parser* turtle_parser=(raptor_turtle_parser*)rdf_parser->context;
  va_list arguments;

  rdf_parser->locator.line=turtle_parser->lineno;
#ifdef RAPTOR_TURTLE_USE_ERROR_COLUMNS
  rdf_parser->locator.column=turtle_lexer_get_column(yyscanner);
#endif

  va_start(arguments, message);
  
  raptor_parser_error_varargs(((raptor_parser*)rdf_parser), message, arguments);

  va_end(arguments);

  return (0);
}


raptor_uri*
turtle_qname_to_uri(raptor_parser *rdf_parser, unsigned char *name, size_t name_len) 
{
  raptor_turtle_parser* turtle_parser=(raptor_turtle_parser*)rdf_parser->context;

  rdf_parser->locator.line=turtle_parser->lineno;
#ifdef RAPTOR_TURTLE_USE_ERROR_COLUMNS
  rdf_parser->locator.column=turtle_lexer_get_column(yyscanner);
#endif

  return raptor_qname_string_to_uri(&turtle_parser->namespaces,
                                    name, name_len,
                                    raptor_parser_simple_error, rdf_parser);
}



static int
turtle_parse(raptor_parser *rdf_parser, const char *string) {
  raptor_turtle_parser* turtle_parser=(raptor_turtle_parser*)rdf_parser->context;
  void *buffer;
  
  if(!string || !*string)
    return 0;
  
  turtle_lexer_lex_init(&turtle_parser->scanner);
  turtle_parser->scanner_set=1;

  turtle_lexer_set_extra(((raptor_parser*)rdf_parser), turtle_parser->scanner);
  buffer= turtle_lexer__scan_string(string, turtle_parser->scanner);

  turtle_parser_parse(rdf_parser);

  turtle_parser->scanner_set=0;

  return 0;
}


/**
 * raptor_turtle_parse_init - Initialise the Raptor Turtle parser
 *
 * Return value: non 0 on failure
 **/

static int
raptor_turtle_parse_init(raptor_parser* rdf_parser, const char *name) {
  raptor_turtle_parser* turtle_parser=(raptor_turtle_parser*)rdf_parser->context;
  raptor_uri_handler *uri_handler;
  void *uri_context;

  raptor_uri_get_handler(&uri_handler, &uri_context);

  raptor_namespaces_init(&turtle_parser->namespaces,
                         uri_handler, uri_context,
                         raptor_parser_simple_error, rdf_parser, 
                         0);

  turtle_parser->nil_uri=raptor_new_uri_for_rdf_concept("nil");
  turtle_parser->first_uri=raptor_new_uri_for_rdf_concept("first");
  turtle_parser->rest_uri=raptor_new_uri_for_rdf_concept("rest");

  return 0;
}


/* PUBLIC FUNCTIONS */


/*
 * raptor_turtle_parse_terminate - Free the Raptor Turtle parser
 * @rdf_parser: parser object
 * 
 **/
static void
raptor_turtle_parse_terminate(raptor_parser *rdf_parser) {
  raptor_turtle_parser *turtle_parser=(raptor_turtle_parser*)rdf_parser->context;

  raptor_free_uri(turtle_parser->nil_uri);
  raptor_free_uri(turtle_parser->first_uri);
  raptor_free_uri(turtle_parser->rest_uri);

  raptor_namespaces_clear(&turtle_parser->namespaces);

  if(turtle_parser->scanner_set) {
    turtle_lexer_lex_destroy(&turtle_parser->scanner);
    turtle_parser->scanner_set=0;
  }

  if(turtle_parser->buffer_length)
    RAPTOR_FREE(cdata, turtle_parser->buffer);
}


static void
raptor_turtle_generate_statement(raptor_parser *parser, raptor_triple *t)
{
  raptor_statement *statement=&parser->statement;
  int predicate_ordinal=0;

  if(!t->subject || !t->predicate || !t->object)
    return;

  /* Two choices for subject from N-Triples */
  statement->subject_type=t->subject->type;
  if(t->subject->type == RAPTOR_IDENTIFIER_TYPE_ANONYMOUS) {
    statement->subject=t->subject->id;
  } else { /* URI */
    statement->subject=t->subject->uri;
  }

  /* Predicates are URIs, in Raptor some are turned into ordinals */
  if(!strncmp((const char*)raptor_uri_as_string(t->predicate->uri),
              "http://www.w3.org/1999/02/22-rdf-syntax-ns#_", 44)) {
    predicate_ordinal=raptor_check_ordinal(raptor_uri_as_string(t->predicate->uri)+44);
    if(predicate_ordinal > 0) {
      statement->predicate=(void*)&predicate_ordinal;
      statement->predicate_type=RAPTOR_IDENTIFIER_TYPE_ORDINAL;
    } else {
      predicate_ordinal=0;
    }
  }
  
  if(!predicate_ordinal) {
    statement->predicate_type=RAPTOR_IDENTIFIER_TYPE_PREDICATE;
    statement->predicate=t->predicate->uri;
  }
  

  /* Three choices for object from N-Triples */
  statement->object_type=t->object->type;
  if(t->object->type == RAPTOR_IDENTIFIER_TYPE_RESOURCE) {
    statement->object=t->object->uri;
  } else if(t->object->type == RAPTOR_IDENTIFIER_TYPE_ANONYMOUS) {
    statement->object=t->object->id;
  } else {  /* literal */
    statement->object=t->object->literal;
    statement->object_literal_language=t->object->literal_language;
    statement->object_literal_datatype=t->object->literal_datatype;
  }

  if(!parser->statement_handler)
    return;

  /* Generate the statement */
  (*parser->statement_handler)(parser->user_data, statement);
}



static int
raptor_turtle_parse_chunk(raptor_parser* rdf_parser, 
                      const unsigned char *s, size_t len,
                      int is_end)
{
  char *buffer;
  char *ptr;
  raptor_turtle_parser *turtle_parser=(raptor_turtle_parser*)rdf_parser->context;
  
#if defined(RAPTOR_DEBUG) && RAPTOR_DEBUG > 1
  RAPTOR_DEBUG2(raptor_turtle_parse_chunk, "adding %d bytes to line buffer\n", len);
#endif

  if(len) {
    buffer=(char*)RAPTOR_MALLOC(cstring, turtle_parser->buffer_length + len + 1);
    if(!buffer) {
      raptor_parser_fatal_error(rdf_parser, "Out of memory");
      return 1;
    }

    if(turtle_parser->buffer_length) {
      strncpy(buffer, turtle_parser->buffer, turtle_parser->buffer_length);
      RAPTOR_FREE(cstring, turtle_parser->buffer);
    }

    turtle_parser->buffer=buffer;

    /* move pointer to end of cdata buffer */
    ptr=buffer+turtle_parser->buffer_length;

    /* adjust stored length */
    turtle_parser->buffer_length += len;

    /* now write new stuff at end of cdata buffer */
    strncpy(ptr, (char*)s, len);
    ptr += len;
    *ptr = '\0';

#if defined(RAPTOR_DEBUG) && RAPTOR_DEBUG > 1
    RAPTOR_DEBUG3(raptor_turtle_parse_chunk,
                  "buffer buffer now '%s' (%d bytes)\n", 
                  turtle_parser->buffer, turtle_parser->buffer_length);
#endif
  }
  
  /* if not end, wait for rest of input */
  if(!is_end)
    return 0;

  /* Nothing to do */
  if(!turtle_parser->buffer_length)
    return 0;
  
  turtle_parse(rdf_parser, turtle_parser->buffer);
  
  return 0;
}


static int
raptor_turtle_parse_start(raptor_parser *rdf_parser) 
{
  raptor_locator *locator=&rdf_parser->locator;
  raptor_turtle_parser *turtle_parser=(raptor_turtle_parser*)rdf_parser->context;

  locator->line=1;
  locator->column= -1; /* No column info */
  locator->byte= -1; /* No bytes info */

  turtle_parser->lineno=1;

  return 0;
}


static void
raptor_turtle_parser_register_factory(raptor_parser_factory *factory) 
{
  factory->context_length     = sizeof(raptor_turtle_parser);
  
  factory->init      = raptor_turtle_parse_init;
  factory->terminate = raptor_turtle_parse_terminate;
  factory->start     = raptor_turtle_parse_start;
  factory->chunk     = raptor_turtle_parse_chunk;
}


void
raptor_init_parser_turtle (void) {
  raptor_parser_register_factory("turtle", "Turtle Terse RDF Triple Language",
                                 "application/x-turtle",
                                 "ntriples-plus",
                                 (const unsigned char*)"http://www.ilrt.bristol.ac.uk/discovery/2004/01/turtle/",
                                 &raptor_turtle_parser_register_factory);
}



#ifdef STANDALONE
#include <stdio.h>
#include <locale.h>

#define TURTLE_FILE_BUF_SIZE 2048

static
void turtle_parser_print_statement(void *user, const raptor_statement *statement) 
{
  FILE* stream=(FILE*)user;
  raptor_print_statement(statement, stream);
  putc('\n', stream);
}
  


int
main(int argc, char *argv[]) 
{
  char string[TURTLE_FILE_BUF_SIZE];
  raptor_parser rdf_parser; /* static */
  raptor_turtle_parser turtle_parser; /* static */
  raptor_locator *locator=&rdf_parser.locator;
  FILE *fh;

#if RAPTOR_DEBUG > 2
  turtle_parser_debug=1;
#endif

  if(argc > 1) {
    filename=argv[1];
    fh = fopen(filename, "r");
    if(!fh) {
      fprintf(stderr, "%s: Cannot open file %s - %s\n", argv[0], filename,
              strerror(errno));
      exit(1);
    }
  } else {
    filename="<stdin>";
    fh = stdin;
  }

  memset(string, 0, TURTLE_FILE_BUF_SIZE);
  fread(string, TURTLE_FILE_BUF_SIZE, 1, fh);
  
  if(argc>1)
    fclose(fh);

  raptor_uri_init();

  memset(&rdf_parser, 0, sizeof(raptor_parser));
  memset(&turtle_parser, 0, sizeof(raptor_turtle_parser));

  locator->line= locator->column = -1;
  locator->file= filename;

  turtle_parser.line= 1;

  rdf_parser.context=&turtle_parser;
  rdf_parser.base_uri=raptor_new_uri("http://example.org/fake-base-uri/");

  raptor_set_statement_handler(&rdf_parser, stdout, turtle_parser_print_statement);
  raptor_turtle_parse_init(&rdf_parser, "turtle");
  
  turtle_parse(&rdf_parser, string);

  raptor_free_uri(rdf_parser.base_uri);

  return (0);
}
#endif

