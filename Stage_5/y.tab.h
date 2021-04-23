/* A Bison parser, made by GNU Bison 3.7.5.  */

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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    BRKP = 258,                    /* BRKP  */
    NEWLINE = 259,                 /* NEWLINE  */
    BEGIN_ = 260,                  /* BEGIN_  */
    END_ = 261,                    /* END_  */
    READ = 262,                    /* READ  */
    WRITE = 263,                   /* WRITE  */
    ID = 264,                      /* ID  */
    OP2 = 265,                     /* OP2  */
    OP = 266,                      /* OP  */
    NUM = 267,                     /* NUM  */
    EQ = 268,                      /* EQ  */
    IF = 269,                      /* IF  */
    THEN = 270,                    /* THEN  */
    ELSE = 271,                    /* ELSE  */
    ENDIF = 272,                   /* ENDIF  */
    IFTHEN = 273,                  /* IFTHEN  */
    WHILE = 274,                   /* WHILE  */
    DO = 275,                      /* DO  */
    ENDWHILE = 276,                /* ENDWHILE  */
    LT = 277,                      /* LT  */
    GT = 278,                      /* GT  */
    LTE = 279,                     /* LTE  */
    GTE = 280,                     /* GTE  */
    EE = 281,                      /* EE  */
    NE = 282,                      /* NE  */
    DECL = 283,                    /* DECL  */
    ENDDECL = 284,                 /* ENDDECL  */
    IDDECL = 285,                  /* IDDECL  */
    EXPR = 286,                    /* EXPR  */
    MAIN = 287,                    /* MAIN  */
    RETURN = 288,                  /* RETURN  */
    ERROR = 289,                   /* ERROR  */
    INT = 290,                     /* INT  */
    BOOL = 291,                    /* BOOL  */
    STR = 292,                     /* STR  */
    TYPE = 293,                    /* TYPE  */
    IDLIST = 294,                  /* IDLIST  */
    STRING = 295,                  /* STRING  */
    ARRAY = 296,                   /* ARRAY  */
    PARAM = 297,                   /* PARAM  */
    FUNCTION = 298,                /* FUNCTION  */
    FDEF = 299,                    /* FDEF  */
    AND = 300,                     /* AND  */
    OR = 301                       /* OR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define BRKP 258
#define NEWLINE 259
#define BEGIN_ 260
#define END_ 261
#define READ 262
#define WRITE 263
#define ID 264
#define OP2 265
#define OP 266
#define NUM 267
#define EQ 268
#define IF 269
#define THEN 270
#define ELSE 271
#define ENDIF 272
#define IFTHEN 273
#define WHILE 274
#define DO 275
#define ENDWHILE 276
#define LT 277
#define GT 278
#define LTE 279
#define GTE 280
#define EE 281
#define NE 282
#define DECL 283
#define ENDDECL 284
#define IDDECL 285
#define EXPR 286
#define MAIN 287
#define RETURN 288
#define ERROR 289
#define INT 290
#define BOOL 291
#define STR 292
#define TYPE 293
#define IDLIST 294
#define STRING 295
#define ARRAY 296
#define PARAM 297
#define FUNCTION 298
#define FDEF 299
#define AND 300
#define OR 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
