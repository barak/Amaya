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




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 118 "./turtle_parser.y"
typedef union YYSTYPE {
  unsigned char *string;
  raptor_identifier *identifier;
  raptor_sequence *sequence;
  raptor_uri *uri;
} YYSTYPE;
/* Line 1248 of yacc.c.  */
#line 83 "turtle_parser.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif





