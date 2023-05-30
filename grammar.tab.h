/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    T_EOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_START_TAG = 258,             /* T_START_TAG  */
    T_END_TAG = 259,               /* T_END_TAG  */
    T_EMPTY_TAG = 260,             /* T_EMPTY_TAG  */
    T_SELF_CLOSING_TAG = 261,      /* T_SELF_CLOSING_TAG  */
    T_ATTRIBUTE = 262,             /* T_ATTRIBUTE  */
    T_ATTRIBUTE_VALUE = 263,       /* T_ATTRIBUTE_VALUE  */
    T_CDATA_SECTION = 264,         /* T_CDATA_SECTION  */
    T_XML_DECLARATION = 265,       /* T_XML_DECLARATION  */
    T_TEXT_CONTENT = 266,          /* T_TEXT_CONTENT  */
    T_NAMESPACE = 267,             /* T_NAMESPACE  */
    T_PROCESING_INSTRUCTION = 268, /* T_PROCESING_INSTRUCTION  */
    T_COMMENT_OPEN = 269,          /* T_COMMENT_OPEN  */
    T_COMMENT_CLOSE = 270,         /* T_COMMENT_CLOSE  */
    T_LINEAR_LAYOUT = 271,         /* T_LINEAR_LAYOUT  */
    T_RELATIVE_LAYOUT = 272,       /* T_RELATIVE_LAYOUT  */
    T_TEXT_VIEW = 273,             /* T_TEXT_VIEW  */
    T_IMAGE_VIEW = 274,            /* T_IMAGE_VIEW  */
    T_BUTTON = 275,                /* T_BUTTON  */
    T_RADIO_BUTTON = 276,          /* T_RADIO_BUTTON  */
    T_RADIO_GROUP = 277,           /* T_RADIO_GROUP  */
    T_PROGRESS_BAR = 278,          /* T_PROGRESS_BAR  */
    T_STRING = 279,                /* T_STRING  */
    T_POSITIVE_INTEGER = 280,      /* T_POSITIVE_INTEGER  */
    T_DOT = 281,                   /* T_DOT  */
    T_COMMA = 283,                 /* T_COMMA  */
    T_ASSIGN = 285,                /* T_ASSIGN  */
    T_COLON = 287,                 /* ":"  */
    T_LBRACK = 288,                /* T_LBRACK  */
    T_RBRACK = 290,                /* T_RBRACK  */
    T_SLASH = 292,                 /* "/"  */
    T_EXCLAMATION = 293,           /* "!"  */
    T_DASH = 294,                  /* "-"  */
    T_LBRACES = 295,               /* "{"  */
    T_RBRACES = 296,               /* "}"  */
    T_AT = 297,                    /* T_AT  */
    T_QUESTION_MARK = 299,         /* "?"  */
    T_UNDERSCORE = 300,            /* "_"  */
    T_HASH = 301,                  /* "#"  */
    T_SQUOTES = 302                /* "'"  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 40 "grammar.y"

   int intval;
   float floatval;
   char charval;
   char *strval;

#line 112 "grammar.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */
