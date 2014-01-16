/* -*- Mode: c; c-basic-offset: 2 -*-
 *
 * turtle_parser.y - Raptor Turtle parser - over tokens from turtle grammar lexer
 *
 * $Id: turtle_parser.y,v 1.1.1.1 2005/07/06 09:38:37 gully Exp $
 *
 * Copyright (C) 2003-2004 David Beckett - http://purl.org/net/dajobe/
 * Institute for Learning and Research Technology - http://www.ilrt.bristol.ac.uk/
 * University of Bristol - http://www.bristol.ac.uk/
 * 
 * This package is Free Software or Open Source available under the
 * following licenses (these are alternatives):
 *   1. GNU Lesser General Public License (LGPL)
 *   2. GNU General Public License (GPL)
 *   3. Mozilla Public License (MPL)
 * 
 * See LICENSE.html or LICENSE.txt at the top of this package for the
 * full license terms.
 * 
 * Turtle is defined in http://www.ilrt.bristol.ac.uk/discovery/2004/01/turtle/
 *
 * Made from a subset of the terms in
 *   http://www.w3.org/DesignIssues/Notatioturtle.html
 *
 */

%{
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

%}


/* directives */



%pure-parser


/* Interface between lexer and parser */
%union {
  unsigned char *string;
  raptor_identifier *identifier;
  raptor_sequence *sequence;
  raptor_uri *uri;
}




/* word symbols */
%token PREFIX

/* others */

%token WS A AT HAT
%token DOT COMMA SEMICOLON
%token LEFT_SQUARE RIGHT_SQUARE
%token LEFT_ROUND RIGHT_ROUND

/* literals */
%token <string> STRING_LITERAL
%token <uri> URI_LITERAL
%token <string> BLANK_LITERAL
%token <uri> QNAME_LITERAL
%token <string> PREFIX
%token <string> IDENTIFIER

/* syntax error */
%token ERROR

%type <identifier> subject predicate object verb literal resource blank collection
%type <sequence> objectList propertyList

%%

Document : statementList
;

statementList: statement statementList 
| /* empty line */
;

statement: directive
| subject propertyList DOT
{
  int i;

#if RAPTOR_DEBUG > 1  
  printf("statement 2\n subject=");
  raptor_identifier_print(stdout, $1);
  if($2) {
    printf("\n propertyList=");
    raptor_sequence_print($2, stdout);
    printf("\n");
  } else     
    printf("\n and empty propertyList\n");
#endif

  if($2) {
    /* non-empty property list, handle it  */
    for(i=0; i<raptor_sequence_size($2); i++) {
      raptor_triple* t2=(raptor_triple*)raptor_sequence_get_at($2, i);
      raptor_identifier *i2=(raptor_identifier*)RAPTOR_CALLOC(raptor_identifier, 1, sizeof(raptor_identifier));
      raptor_copy_identifier(i2, $1);
      t2->subject=i2;
      t2->subject->is_malloced=1;
    }
#if RAPTOR_DEBUG > 1  
    printf(" after substitution propertyList=");
    raptor_sequence_print($2, stdout);
    printf("\n\n");
#endif
    for(i=0; i<raptor_sequence_size($2); i++) {
      raptor_triple* t2=(raptor_triple*)raptor_sequence_get_at($2, i);
      raptor_turtle_generate_statement((raptor_parser*)rdf_parser, t2);
    }

    raptor_free_sequence($2);
  }

  if($1)
    raptor_free_identifier($1);
}
| error DOT
;


objectList: object COMMA objectList
{
  raptor_triple *triple;

#if RAPTOR_DEBUG > 1  
  printf("objectList 1\n");
  if($1) {
    printf(" object=\n");
    raptor_identifier_print(stdout, $1);
    printf("\n");
  } else  
    printf(" and empty object\n");
  if($3) {
    printf(" objectList=");
    raptor_sequence_print($3, stdout);
    printf("\n");
  } else
    printf(" and empty objectList\n");
#endif

  if(!$1)
    $$=NULL;
  else {
    triple=raptor_new_triple(NULL, NULL, $1);
    $$=$3;
    raptor_sequence_shift($$, triple);
#if RAPTOR_DEBUG > 1  
    printf(" objectList is now ");
    raptor_sequence_print($$, stdout);
    printf("\n\n");
#endif
  }
}
| object
{
  raptor_triple *triple;

#if RAPTOR_DEBUG > 1  
  printf("objectList 2\n");
  if($1) {
    printf(" object=\n");
    raptor_identifier_print(stdout, $1);
    printf("\n");
  } else  
    printf(" and empty object\n");
#endif

  if(!$1)
    $$=NULL;
  else {
    triple=raptor_new_triple(NULL, NULL, $1);
#ifdef RAPTOR_DEBUG
    $$=raptor_new_sequence((raptor_free_handler*)raptor_free_triple,
                           (raptor_print_handler*)raptor_triple_print);
#else
    $$=raptor_new_sequence((raptor_free_handler*)raptor_free_triple, NULL);
#endif
    raptor_sequence_push($$, triple);
#if RAPTOR_DEBUG > 1  
    printf(" objectList is now ");
    raptor_sequence_print($$, stdout);
    printf("\n\n");
#endif
  }
}
;

verb: predicate
{
#if RAPTOR_DEBUG > 1  
  printf("verb predicate=");
  raptor_identifier_print(stdout, $1);
  printf("\n");
#endif

  $$=$1;
}
| A
{
  raptor_uri *uri;

#if RAPTOR_DEBUG > 1  
  printf("verb predicate=rdf:type (a)\n");
#endif

  uri=raptor_new_uri_for_rdf_concept("type");
  $$=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_RESOURCE, uri, RAPTOR_URI_SOURCE_URI, NULL, NULL, NULL, NULL);
}
;


propertyList: verb objectList SEMICOLON propertyList
{
  int i;
  
#if RAPTOR_DEBUG > 1  
  printf("propertyList 1\n verb=");
  raptor_identifier_print(stdout, $1);
  printf("\n objectList=");
  raptor_sequence_print($2, stdout);
  printf("\n propertyList=");
  raptor_sequence_print($4, stdout);
  printf("\n\n");
#endif
  
  if($2 == NULL) {
#if RAPTOR_DEBUG > 1  
    printf(" empty objectList not processed\n");
#endif
  } else if($1 && $2) {
    /* non-empty property list, handle it  */
    for(i=0; i<raptor_sequence_size($2); i++) {
      raptor_triple* t2=(raptor_triple*)raptor_sequence_get_at($2, i);
      raptor_identifier *i2=(raptor_identifier*)RAPTOR_CALLOC(raptor_identifier, 1, sizeof(raptor_identifier));
      raptor_copy_identifier(i2, $1);
      t2->predicate=i2;
      t2->predicate->is_malloced=1;
    }
  
#if RAPTOR_DEBUG > 1  
    printf(" after substitution objectList=");
    raptor_sequence_print($2, stdout);
    printf("\n");
#endif
  }

  if($4 == NULL) {
#if RAPTOR_DEBUG > 1  
    printf(" empty propertyList not copied\n\n");
#endif
  } else if ($1 && $2 && $4) {
    while(raptor_sequence_size($4) > 0) {
      raptor_triple* t2=(raptor_triple*)raptor_sequence_unshift($4);
      raptor_sequence_push($2, t2);
    }

#if RAPTOR_DEBUG > 1  
    printf(" after appending objectList=");
    raptor_sequence_print($2, stdout);
    printf("\n\n");
#endif

    raptor_free_sequence($4);
  }

  if($1)
    raptor_free_identifier($1);

  $$=$2;
}
| verb objectList
{
  int i;
#if RAPTOR_DEBUG > 1  
  printf("propertyList 2\n verb=");
  raptor_identifier_print(stdout, $1);
  if($2) {
    printf("\n objectList=");
    raptor_sequence_print($2, stdout);
    printf("\n");
  } else
    printf("\n and empty objectList\n");
#endif

  if($1 && $2) {
    for(i=0; i<raptor_sequence_size($2); i++) {
      raptor_triple* t2=(raptor_triple*)raptor_sequence_get_at($2, i);
      raptor_identifier *i2=(raptor_identifier*)RAPTOR_CALLOC(raptor_identifier, 1, sizeof(raptor_identifier));
      raptor_copy_identifier(i2, $1);
      t2->predicate=i2;
      t2->predicate->is_malloced=1;
    }

#if RAPTOR_DEBUG > 1  
    printf(" after substitution objectList=");
    raptor_sequence_print($2, stdout);
    printf("\n\n");
#endif
  }

  if($1)
    raptor_free_identifier($1);

  $$=$2;
}
| /* empty */
{
#if RAPTOR_DEBUG > 1  
  printf("propertyList 3\n empty returning NULL\n\n");
#endif
  $$=NULL;
}
;

directive : PREFIX IDENTIFIER URI_LITERAL DOT
{
  unsigned char *prefix=$2;
  raptor_turtle_parser* turtle_parser=(raptor_turtle_parser*)(((raptor_parser*)rdf_parser)->context);

#if RAPTOR_DEBUG > 1  
  printf("directive @prefix %s %s\n",($2 ? (char*)$2 : "(default)"),raptor_uri_as_string($3));
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
                                         (const unsigned char*)raptor_uri_as_string($3), 0);
  if($2)
    free($2);
  raptor_free_uri($3);
}
;

subject: resource
{
  $$=$1;
}
| blank
{
  $$=$1;
}
;

predicate: resource
{
  $$=$1;
}
;

object: resource
{
  $$=$1;
}
| blank
{
  $$=$1;
}
| literal
{
#if RAPTOR_DEBUG > 1  
  printf("object literal=");
  raptor_identifier_print(stdout, $1);
  printf("\n");
#endif

  $$=$1;
}
;

literal: STRING_LITERAL AT IDENTIFIER
{
#if RAPTOR_DEBUG > 1  
  printf("literal + language string=\"%s\"\n", $1);
#endif

  $$=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_LITERAL, NULL, RAPTOR_URI_SOURCE_ELEMENT, NULL, $1, NULL, $3);
}
| STRING_LITERAL AT IDENTIFIER HAT URI_LITERAL
{
#if RAPTOR_DEBUG > 1  
  printf("literal + language=\"%s\" datatype string=\"%s\" uri=\"%s\"\n", $1, $3, raptor_uri_as_string($5));
#endif

  if($5)
    $$=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_LITERAL, NULL, RAPTOR_URI_SOURCE_ELEMENT, NULL, $1, $5, $3);
  else
    $$=NULL;
    
}
| STRING_LITERAL AT IDENTIFIER HAT QNAME_LITERAL
{
#if RAPTOR_DEBUG > 1  
  printf("literal + language=\"%s\" datatype string=\"%s\" qname URI=<%s>\n", $1, $3, raptor_uri_as_string($5));
#endif

  if($5)
    $$=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_LITERAL, NULL, RAPTOR_URI_SOURCE_ELEMENT, NULL, (const unsigned char*)$1, $5, $3);
  else
    $$=NULL;

}
| STRING_LITERAL HAT URI_LITERAL
{
#if RAPTOR_DEBUG > 1  
  printf("literal + datatype string=\"%s\" uri=\"%s\"\n", $1, raptor_uri_as_string($3));
#endif

  if($3)
    $$=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_LITERAL, NULL, RAPTOR_URI_SOURCE_ELEMENT, NULL, $1, $3, NULL);
  else
    $$=NULL;
    
}
| STRING_LITERAL HAT QNAME_LITERAL
{
#if RAPTOR_DEBUG > 1  
  printf("literal + datatype string=\"%s\" qname URI=<%s>\n", $1, raptor_uri_as_string($3));
#endif

  if($3) {
    $$=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_LITERAL, NULL, RAPTOR_URI_SOURCE_ELEMENT, NULL, $1, $3, NULL);
  } else
    $$=NULL;
}
| STRING_LITERAL
{
#if RAPTOR_DEBUG > 1  
  printf("literal string=\"%s\"\n", $1);
#endif

  $$=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_LITERAL, NULL, RAPTOR_URI_SOURCE_ELEMENT, NULL, $1, NULL, NULL);
}
;

resource:
URI_LITERAL
{
#if RAPTOR_DEBUG > 1  
  printf("resource URI=<%s>\n", raptor_uri_as_string($1));
#endif

  if($1)
    $$=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_RESOURCE, $1, RAPTOR_URI_SOURCE_URI, NULL, NULL, NULL, NULL);
  else
    $$=NULL;
}
| QNAME_LITERAL
{
#if RAPTOR_DEBUG > 1  
  printf("resource qname URI=<%s>\n", raptor_uri_as_string($1));
#endif

  if($1)
    $$=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_RESOURCE, $1, RAPTOR_URI_SOURCE_ELEMENT, NULL, NULL, NULL, NULL);
  else
    $$=NULL;
}


blank: BLANK_LITERAL
{
#if RAPTOR_DEBUG > 1  
  printf("subject blank=\"%s\"\n", $1);
#endif
  $$=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_ANONYMOUS, NULL, RAPTOR_URI_SOURCE_BLANK_ID, $1, NULL, NULL, NULL);
}
| LEFT_SQUARE propertyList RIGHT_SQUARE
{
  int i;
  const unsigned char *id=raptor_generate_id((raptor_parser*)rdf_parser, 0, NULL);
  
  $$=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_ANONYMOUS, NULL, RAPTOR_URI_SOURCE_GENERATED, id, NULL, NULL, NULL);

  if($2 == NULL) {
#if RAPTOR_DEBUG > 1  
    printf("resource\n propertyList=");
    raptor_identifier_print(stdout, $$);
    printf("\n");
#endif
  } else {
    /* non-empty property list, handle it  */
#if RAPTOR_DEBUG > 1  
    printf("resource\n propertyList=");
    raptor_sequence_print($2, stdout);
    printf("\n");
#endif

    for(i=0; i<raptor_sequence_size($2); i++) {
      raptor_triple* t2=(raptor_triple*)raptor_sequence_get_at($2, i);
      raptor_identifier *i2=(raptor_identifier*)RAPTOR_CALLOC(raptor_identifier, 1, sizeof(raptor_identifier));
      raptor_copy_identifier(i2, $$);
      t2->subject=i2;
      t2->subject->is_malloced=1;
      raptor_turtle_generate_statement((raptor_parser*)rdf_parser, t2);
    }

#if RAPTOR_DEBUG > 1
    printf(" after substitution objectList=");
    raptor_sequence_print($2, stdout);
    printf("\n\n");
#endif

    raptor_free_sequence($2);

  }
  
}
| collection
{
  $$=$1;
}
;


collection: LEFT_ROUND objectList RIGHT_ROUND
{
  int i;
  raptor_turtle_parser* turtle_parser=(raptor_turtle_parser*)(((raptor_parser*)rdf_parser)->context);
  raptor_identifier* first_identifier;
  raptor_identifier* rest_identifier;
  raptor_identifier* object;

#if RAPTOR_DEBUG > 1  
  printf("collection\n objectList=");
  raptor_sequence_print($2, stdout);
  printf("\n");
#endif

  first_identifier=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_RESOURCE, raptor_uri_copy(turtle_parser->first_uri), RAPTOR_URI_SOURCE_URI, NULL, NULL, NULL, NULL);
  rest_identifier=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_RESOURCE, raptor_uri_copy(turtle_parser->rest_uri), RAPTOR_URI_SOURCE_URI, NULL, NULL, NULL, NULL);
  
  /* non-empty property list, handle it  */
#if RAPTOR_DEBUG > 1  
  printf("resource\n propertyList=");
  raptor_sequence_print($2, stdout);
  printf("\n");
#endif

  object=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_RESOURCE, raptor_uri_copy(turtle_parser->nil_uri), RAPTOR_URI_SOURCE_URI, NULL, NULL, NULL, NULL);

  for(i=raptor_sequence_size($2)-1; i>=0; i--) {
    raptor_triple* t2=(raptor_triple*)raptor_sequence_get_at($2, i);
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
  raptor_sequence_print($2, stdout);
  printf("\n\n");
#endif

  raptor_free_sequence($2);

  raptor_free_identifier(first_identifier);
  raptor_free_identifier(rest_identifier);

  $$=object;
}
|  LEFT_ROUND RIGHT_ROUND 
{
  raptor_turtle_parser* turtle_parser=(raptor_turtle_parser*)(((raptor_parser*)rdf_parser)->context);

#if RAPTOR_DEBUG > 1  
  printf("collection\n empty\n");
#endif

  $$=raptor_new_identifier(RAPTOR_IDENTIFIER_TYPE_RESOURCE, raptor_uri_copy(turtle_parser->nil_uri), RAPTOR_URI_SOURCE_URI, NULL, NULL, NULL, NULL);
}

%%


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
