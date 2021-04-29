/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "t_1.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    #include "custom.h"
    #include "tree.h"

    void paren(tnode *Tree) ;

    int getReg(void) ;
    void freeReg(int) ;
    void showRegs(void) ;
    void copyRegs(int *,int *) ;

    int codeGen(tnode *Tree) ;

    void addGSymbols(tnode *Tree) ;
    void addGSymbol(tnode *Tree) ;
    void showGTable(void) ;
    void showLTable(LSymbol *table) ;
    void setLTable(char *name,LSymbol *table) ;
    int getSymbol(char *name) ;
    void showParamList(ParamStruct *list) ;
    LSymbol *makeLocalTable(tnode *Node,tnode *decl) ;

    void assignType(tnode *Tree,int type) ;
    void assignTable(tnode *Tree,LSymbol *table) ;
    int getLAddress(tnode *Node) ;
    int getAddress(tnode *Node) ;
    int getLabel(tnode *Node) ;
    ParamStruct *getParams(tnode *Node) ;

    ParamStruct *makeParamlist(tnode *Tree,ParamStruct **paramList,int pars) ;
    void addParams(LSymbol *table,ParamStruct *params) ;


    FILE *target_file ;
    int REG[20] ;

    int varSize = 0 ;
    int varEntry = 0 ;
    GSymbol *sTable = NULL ;
    int label = 0 ;
    int flabel = 0 ;

    int lSize = 1 ;
    int lEntry = 0 ;

    int addr = 0 ;

#line 123 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    CALL = 300,                    /* CALL  */
    ARGLIST = 301,                 /* ARGLIST  */
    AND = 302,                     /* AND  */
    OR = 303                       /* OR  */
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
#define CALL 300
#define ARGLIST 301
#define AND 302
#define OR 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BRKP = 3,                       /* BRKP  */
  YYSYMBOL_NEWLINE = 4,                    /* NEWLINE  */
  YYSYMBOL_BEGIN_ = 5,                     /* BEGIN_  */
  YYSYMBOL_END_ = 6,                       /* END_  */
  YYSYMBOL_READ = 7,                       /* READ  */
  YYSYMBOL_WRITE = 8,                      /* WRITE  */
  YYSYMBOL_ID = 9,                         /* ID  */
  YYSYMBOL_OP2 = 10,                       /* OP2  */
  YYSYMBOL_OP = 11,                        /* OP  */
  YYSYMBOL_NUM = 12,                       /* NUM  */
  YYSYMBOL_EQ = 13,                        /* EQ  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_THEN = 15,                      /* THEN  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_ENDIF = 17,                     /* ENDIF  */
  YYSYMBOL_IFTHEN = 18,                    /* IFTHEN  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_DO = 20,                        /* DO  */
  YYSYMBOL_ENDWHILE = 21,                  /* ENDWHILE  */
  YYSYMBOL_LT = 22,                        /* LT  */
  YYSYMBOL_GT = 23,                        /* GT  */
  YYSYMBOL_LTE = 24,                       /* LTE  */
  YYSYMBOL_GTE = 25,                       /* GTE  */
  YYSYMBOL_EE = 26,                        /* EE  */
  YYSYMBOL_NE = 27,                        /* NE  */
  YYSYMBOL_DECL = 28,                      /* DECL  */
  YYSYMBOL_ENDDECL = 29,                   /* ENDDECL  */
  YYSYMBOL_IDDECL = 30,                    /* IDDECL  */
  YYSYMBOL_EXPR = 31,                      /* EXPR  */
  YYSYMBOL_MAIN = 32,                      /* MAIN  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_ERROR = 34,                     /* ERROR  */
  YYSYMBOL_INT = 35,                       /* INT  */
  YYSYMBOL_BOOL = 36,                      /* BOOL  */
  YYSYMBOL_STR = 37,                       /* STR  */
  YYSYMBOL_TYPE = 38,                      /* TYPE  */
  YYSYMBOL_IDLIST = 39,                    /* IDLIST  */
  YYSYMBOL_STRING = 40,                    /* STRING  */
  YYSYMBOL_ARRAY = 41,                     /* ARRAY  */
  YYSYMBOL_PARAM = 42,                     /* PARAM  */
  YYSYMBOL_FUNCTION = 43,                  /* FUNCTION  */
  YYSYMBOL_FDEF = 44,                      /* FDEF  */
  YYSYMBOL_CALL = 45,                      /* CALL  */
  YYSYMBOL_ARGLIST = 46,                   /* ARGLIST  */
  YYSYMBOL_AND = 47,                       /* AND  */
  YYSYMBOL_OR = 48,                        /* OR  */
  YYSYMBOL_49_ = 49,                       /* ';'  */
  YYSYMBOL_50_ = 50,                       /* ','  */
  YYSYMBOL_51_ = 51,                       /* '['  */
  YYSYMBOL_52_ = 52,                       /* ']'  */
  YYSYMBOL_53_ = 53,                       /* '('  */
  YYSYMBOL_54_ = 54,                       /* ')'  */
  YYSYMBOL_55_ = 55,                       /* '{'  */
  YYSYMBOL_56_ = 56,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_program = 58,                   /* program  */
  YYSYMBOL_GDeclBlock = 59,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 60,                 /* GDeclList  */
  YYSYMBOL_GDecl = 61,                     /* GDecl  */
  YYSYMBOL_GidList = 62,                   /* GidList  */
  YYSYMBOL_Gid = 63,                       /* Gid  */
  YYSYMBOL_ParamList = 64,                 /* ParamList  */
  YYSYMBOL_Param = 65,                     /* Param  */
  YYSYMBOL_FDefBlock = 66,                 /* FDefBlock  */
  YYSYMBOL_Fdef = 67,                      /* Fdef  */
  YYSYMBOL_LDeclBlock = 68,                /* LDeclBlock  */
  YYSYMBOL_LDeclList = 69,                 /* LDeclList  */
  YYSYMBOL_LDecl = 70,                     /* LDecl  */
  YYSYMBOL_Type = 71,                      /* Type  */
  YYSYMBOL_MainBlock = 72,                 /* MainBlock  */
  YYSYMBOL_IfStmt = 73,                    /* IfStmt  */
  YYSYMBOL_WhStmt = 74,                    /* WhStmt  */
  YYSYMBOL_LBody = 75,                     /* LBody  */
  YYSYMBOL_Slist = 76,                     /* Slist  */
  YYSYMBOL_Stmt = 77,                      /* Stmt  */
  YYSYMBOL_Varlist = 78,                   /* Varlist  */
  YYSYMBOL_RetStmt = 79,                   /* RetStmt  */
  YYSYMBOL_BrkStmt = 80,                   /* BrkStmt  */
  YYSYMBOL_Input = 81,                     /* Input  */
  YYSYMBOL_Output = 82,                    /* Output  */
  YYSYMBOL_Asgmt = 83,                     /* Asgmt  */
  YYSYMBOL_E = 84,                         /* E  */
  YYSYMBOL_ArgList = 85,                   /* ArgList  */
  YYSYMBOL_ArrEl = 86                      /* ArrEl  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   335

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      53,    54,     2,     2,    50,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    49,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    85,    99,   113,   114,   117,   118,   121,
     128,   131,   134,   137,   142,   149,   153,   154,   157,   164,
     165,   168,   183,   202,   203,   206,   207,   210,   217,   218,
     219,   222,   235,   251,   255,   258,   263,   264,   267,   268,
     271,   272,   273,   274,   275,   276,   277,   280,   284,   291,
     296,   304,   307,   310,   314,   320,   326,   327,   330,   343,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   372,   377,   383
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "BRKP", "NEWLINE",
  "BEGIN_", "END_", "READ", "WRITE", "ID", "OP2", "OP", "NUM", "EQ", "IF",
  "THEN", "ELSE", "ENDIF", "IFTHEN", "WHILE", "DO", "ENDWHILE", "LT", "GT",
  "LTE", "GTE", "EE", "NE", "DECL", "ENDDECL", "IDDECL", "EXPR", "MAIN",
  "RETURN", "ERROR", "INT", "BOOL", "STR", "TYPE", "IDLIST", "STRING",
  "ARRAY", "PARAM", "FUNCTION", "FDEF", "CALL", "ARGLIST", "AND", "OR",
  "';'", "','", "'['", "']'", "'('", "')'", "'{'", "'}'", "$accept",
  "program", "GDeclBlock", "GDeclList", "GDecl", "GidList", "Gid",
  "ParamList", "Param", "FDefBlock", "Fdef", "LDeclBlock", "LDeclList",
  "LDecl", "Type", "MainBlock", "IfStmt", "WhStmt", "LBody", "Slist",
  "Stmt", "Varlist", "RetStmt", "BrkStmt", "Input", "Output", "Asgmt", "E",
  "ArgList", "ArrEl", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    59,
      44,    91,    93,    40,    41,   123,   125
};
#endif

#define YYPACT_NINF (-101)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -16,    38,   -30,    15,   103,  -101,  -101,  -101,  -101,  -101,
      41,  -101,    62,    33,  -101,   -30,   103,  -101,    78,  -101,
    -101,  -101,   112,   -27,  -101,    35,  -101,  -101,    45,    89,
     116,  -101,    62,    47,   116,    54,   -20,  -101,   101,  -101,
      -1,    -5,  -101,   116,  -101,  -101,   252,    68,   106,    63,
      86,  -101,    99,  -101,   107,   113,    -3,   118,   135,    16,
    -101,  -101,   267,  -101,  -101,  -101,  -101,  -101,  -101,   141,
    -101,   168,  -101,   146,   134,  -101,    -1,  -101,   150,    16,
      16,    16,    16,    16,   136,  -101,  -101,    16,   151,  -101,
    -101,  -101,    16,  -101,  -101,   160,     1,  -101,   106,   145,
      34,   148,    36,   159,   120,    69,   102,    12,   110,    16,
      16,    16,    16,    16,    16,    16,    16,    16,    16,  -101,
     169,   200,  -101,   204,   158,  -101,   166,   178,   179,  -101,
    -101,   214,   210,  -101,   199,    18,  -101,   227,  -101,   303,
     303,   303,   303,   303,   303,   209,   209,  -101,   187,   189,
    -101,  -101,  -101,  -101,   302,   302,    16,  -101,  -101,   232,
     234,   275,   199,   193,   302,   203,   205,  -101,   284,  -101,
    -101,   213,  -101
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     6,    28,    30,    29,
       0,     8,     0,     0,     1,    28,     0,    20,     0,     3,
       5,     7,    12,     0,    11,     0,    19,     2,     0,     0,
      17,     9,     0,     0,    17,     0,     0,    16,     0,    10,
       0,     0,    13,     0,    14,    18,     0,     0,     0,     0,
       0,    15,     0,    37,     0,     0,     0,     0,     0,     0,
      43,    44,     0,    39,    46,    45,    40,    41,    42,     0,
      24,     0,    26,     0,     0,    32,     0,    52,     0,     0,
       0,     0,     0,     0,    68,    71,    72,     0,     0,    73,
      36,    38,     0,    23,    25,    49,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    51,
       0,     0,    27,     0,     0,    22,     0,     0,     0,    56,
      77,     0,     0,    69,    76,     0,    74,    58,    59,    60,
      61,    64,    65,    62,    63,    67,    66,    57,     0,    47,
      21,    53,    54,    55,     0,     0,     0,    70,    50,     0,
       0,     0,    75,     0,     0,     0,     0,    48,     0,    34,
      35,     0,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,  -101,  -101,   239,  -101,   231,   230,   222,  -101,
     253,   192,  -101,   201,    10,    13,  -101,  -101,   -45,  -100,
     -61,  -101,  -101,  -101,  -101,  -101,  -101,   -74,  -101,   -46
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,    10,    11,    23,    24,    36,    37,    16,
      17,    48,    71,    72,    38,     5,    60,    61,    49,    62,
      63,    96,    64,    65,    66,    67,    68,    88,   135,    89
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      69,    91,    13,    74,    46,   102,   103,   104,   105,   106,
      80,    12,     1,   108,    18,    14,    69,    19,   120,     2,
      12,    84,    31,    32,    85,    84,    18,    47,    85,    27,
      43,    99,   101,   134,    44,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    43,   109,   110,    81,    50,
     122,   123,    86,   124,   160,   161,    86,    73,   111,   112,
     113,   114,   115,   116,   168,    87,   133,     6,   156,    87,
      20,    22,   157,     7,     8,     9,     7,     8,     9,   109,
     110,    73,   162,   117,   118,    81,    25,    28,   126,    33,
     128,   111,   112,   113,   114,   115,   116,    70,    34,    91,
      91,    35,    40,     7,     8,     9,    42,    91,    69,    69,
      45,    46,   109,   110,    69,    69,   117,   118,    69,    75,
     109,   110,    69,   131,   111,   112,   113,   114,   115,   116,
     109,   110,   111,   112,   113,   114,   115,   116,    15,     8,
       9,    76,   111,   112,   113,   114,   115,   116,    77,   117,
     118,     7,     8,     9,    92,    95,   132,   117,   118,   100,
      78,   109,   110,    29,   136,    30,    79,   117,   118,   109,
     110,    82,   130,   111,   112,   113,   114,   115,   116,   109,
     110,   111,   112,   113,   114,   115,   116,    81,    83,   107,
      97,   111,   112,   113,   114,   115,   116,    93,   117,   118,
     119,   125,   127,     7,     8,     9,   117,   118,   129,   109,
     110,   121,   148,   149,   150,   151,   117,   118,   147,   109,
     110,   111,   112,   113,   114,   115,   116,   152,   153,   154,
     155,   111,   112,   113,   114,   115,   116,    52,   110,   158,
     159,    54,    55,    56,   163,   167,   117,   118,    57,    21,
     164,   165,   169,    58,   170,    52,    -1,    -1,    53,    54,
      55,    56,   172,    39,    41,    51,    57,    59,    98,    26,
      52,    58,    94,    90,    54,    55,    56,     0,    52,     0,
       0,    57,    54,    55,    56,    59,    58,    52,     0,    57,
       0,    54,    55,    56,    58,     0,   166,     0,    57,     0,
      59,   171,     0,    58,     0,    52,     0,     0,    59,    54,
      55,    56,     0,   109,   110,     0,    57,    59,     0,     0,
       0,    58,     0,     0,     0,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     0,     0,     0,    59
};

static const yytype_int16 yycheck[] =
{
      46,    62,    32,    48,     5,    79,    80,    81,    82,    83,
      13,     1,    28,    87,     4,     0,    62,     4,    92,    35,
      10,     9,    49,    50,    12,     9,    16,    28,    12,    16,
      50,    76,    78,   107,    54,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    50,    10,    11,    51,    54,
      49,    50,    40,    98,   154,   155,    40,    47,    22,    23,
      24,    25,    26,    27,   164,    53,    54,    29,    50,    53,
      29,     9,    54,    35,    36,    37,    35,    36,    37,    10,
      11,    71,   156,    47,    48,    51,    53,     9,    54,    54,
      54,    22,    23,    24,    25,    26,    27,    29,    53,   160,
     161,    12,    55,    35,    36,    37,    52,   168,   154,   155,
       9,     5,    10,    11,   160,   161,    47,    48,   164,    56,
      10,    11,   168,    54,    22,    23,    24,    25,    26,    27,
      10,    11,    22,    23,    24,    25,    26,    27,    35,    36,
      37,    55,    22,    23,    24,    25,    26,    27,    49,    47,
      48,    35,    36,    37,    13,     9,    54,    47,    48,     9,
      53,    10,    11,    51,    54,    53,    53,    47,    48,    10,
      11,    53,    52,    22,    23,    24,    25,    26,    27,    10,
      11,    22,    23,    24,    25,    26,    27,    51,    53,    53,
      56,    22,    23,    24,    25,    26,    27,    29,    47,    48,
      49,    56,    54,    35,    36,    37,    47,    48,    49,    10,
      11,    51,    12,     9,    56,    49,    47,    48,    49,    10,
      11,    22,    23,    24,    25,    26,    27,    49,    49,    15,
      20,    22,    23,    24,    25,    26,    27,     3,    11,    52,
      51,     7,     8,     9,    12,    52,    47,    48,    14,    10,
      16,    17,    49,    19,    49,     3,    47,    48,     6,     7,
       8,     9,    49,    32,    34,    43,    14,    33,    76,    16,
       3,    19,    71,     6,     7,     8,     9,    -1,     3,    -1,
      -1,    14,     7,     8,     9,    33,    19,     3,    -1,    14,
      -1,     7,     8,     9,    19,    -1,    21,    -1,    14,    -1,
      33,    17,    -1,    19,    -1,     3,    -1,    -1,    33,     7,
       8,     9,    -1,    10,    11,    -1,    14,    33,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    28,    35,    58,    59,    72,    29,    35,    36,    37,
      60,    61,    71,    32,     0,    35,    66,    67,    71,    72,
      29,    61,     9,    62,    63,    53,    67,    72,     9,    51,
      53,    49,    50,    54,    53,    12,    64,    65,    71,    63,
      55,    64,    52,    50,    54,     9,     5,    28,    68,    75,
      54,    65,     3,     6,     7,     8,     9,    14,    19,    33,
      73,    74,    76,    77,    79,    80,    81,    82,    83,    86,
      29,    69,    70,    71,    75,    56,    55,    49,    53,    53,
      13,    51,    53,    53,     9,    12,    40,    53,    84,    86,
       6,    77,    13,    29,    70,     9,    78,    56,    68,    75,
       9,    86,    84,    84,    84,    84,    84,    53,    84,    10,
      11,    22,    23,    24,    25,    26,    27,    47,    48,    49,
      84,    51,    49,    50,    75,    56,    54,    54,    54,    49,
      52,    54,    54,    54,    84,    85,    54,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    49,    12,     9,
      56,    49,    49,    49,    15,    20,    50,    54,    52,    51,
      76,    76,    84,    12,    16,    17,    21,    52,    76,    49,
      49,    17,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    58,    58,    59,    59,    60,    60,    61,
      62,    62,    63,    63,    63,    64,    64,    64,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    71,    71,
      71,    72,    72,    73,    73,    74,    75,    75,    76,    76,
      77,    77,    77,    77,    77,    77,    77,    78,    78,    78,
      78,    79,    80,    81,    81,    82,    83,    83,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    85,    85,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       3,     1,     1,     4,     4,     3,     1,     0,     2,     2,
       1,     9,     8,     3,     2,     2,     1,     3,     1,     1,
       1,     8,     7,    10,     8,     8,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     6,     1,
       4,     3,     2,     5,     5,     5,     4,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       4,     1,     1,     1,     3,     3,     1,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: GDeclBlock FDefBlock MainBlock  */
#line 69 "t_1.y"
                                             {
                                                // printf("GDecFDecMainBlock\n") ;
                                                fprintf(target_file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0); 
                                                fprintf(target_file,"MOV SP,%d\nMOV BP,%d\n",4096+varSize,4096+varSize+1);
                                                
                                                printf("------%15s  -----\n","Global") ;
                                                showGTable() ;
                                                printf("----------------------------\n") ;
                                                fprintf(target_file,"PUSH R0\n") ;
                                                fprintf(target_file,"CALL _MAIN\n") ;
                                                fprintf(target_file,"INT 10\n") ;
                                                codeGen(yyvsp[-1]) ;
                                                codeGen(yyvsp[0]) ;
                                                fprintf(target_file,"INT 10\n") ;
                                                exit(0);
                                              }
#line 1500 "y.tab.c"
    break;

  case 3: /* program: GDeclBlock MainBlock  */
#line 85 "t_1.y"
                                              {
                                                // printf("GDecMainBlock\n") ;
                                                fprintf(target_file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0); 
                                                fprintf(target_file,"MOV SP,%d\nMOV BP,%d\n",4096+varSize,4096+varSize+1);
                                                
                                                printf("------%15s  -----\n","Global") ;
                                                showGTable() ;
                                                printf("----------------------------\n") ;
                                                fprintf(target_file,"CALL _MAIN\n") ;
                                                fprintf(target_file,"INT 10\n") ;
                                                codeGen(yyvsp[0]) ;
                                                fprintf(target_file,"INT 10\n") ;
                                                exit(0);
                                              }
#line 1519 "y.tab.c"
    break;

  case 4: /* program: MainBlock  */
#line 99 "t_1.y"
                                              {
                                                printf("MainBlock\n") ;
                                                fprintf(target_file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0); 
                                                fprintf(target_file,"MOV SP,%d\nMOV BP,%d\n",4096+varSize,4096+varSize+1);
                                                
                                                printf("------%15s  -----\n","Global") ;
                                                showGTable() ;
                                                printf("----------------------------\n") ;
                                                codeGen(yyvsp[0]) ;
                                                fprintf(target_file,"INT 10\n") ;
                                                exit(0);
                                              }
#line 1536 "y.tab.c"
    break;

  case 9: /* GDecl: Type GidList ';'  */
#line 121 "t_1.y"
                                              {
                                                assignType(yyvsp[-1],yyvsp[-2]->type) ;
                                                addGSymbols(yyvsp[-1]) ;
                                                yyval = yyvsp[-1] ;
                                              }
#line 1546 "y.tab.c"
    break;

  case 10: /* GidList: GidList ',' Gid  */
#line 128 "t_1.y"
                                          {
                                            yyval = (YYSTYPE) createTree(0,-1,IDLIST,IDLIST,NULL,yyvsp[-2],yyvsp[0]);
                                          }
#line 1554 "y.tab.c"
    break;

  case 11: /* GidList: Gid  */
#line 131 "t_1.y"
                                          {yyval = yyvsp[0];}
#line 1560 "y.tab.c"
    break;

  case 12: /* Gid: ID  */
#line 134 "t_1.y"
                                          {
                                            yyval = yyvsp[0] ;
                                          }
#line 1568 "y.tab.c"
    break;

  case 13: /* Gid: ID '[' NUM ']'  */
#line 137 "t_1.y"
                                          {
                                            yyval = yyvsp[-3] ;
                                            yyval->nodeType = ARRAY ;
                                            yyval->left = yyvsp[-1] ;
                                          }
#line 1578 "y.tab.c"
    break;

  case 14: /* Gid: ID '(' ParamList ')'  */
#line 142 "t_1.y"
                                          {
                                            yyval = yyvsp[-3] ;
                                            yyval->nodeType = FUNCTION ;
                                            yyval->left = yyvsp[-1] ;
                                          }
#line 1588 "y.tab.c"
    break;

  case 15: /* ParamList: ParamList ',' Param  */
#line 149 "t_1.y"
                                      {
                                        yyval = yyvsp[0];
                                        yyval->left = yyvsp[-2];
                                      }
#line 1597 "y.tab.c"
    break;

  case 16: /* ParamList: Param  */
#line 153 "t_1.y"
                                      {yyval = yyvsp[0] ;}
#line 1603 "y.tab.c"
    break;

  case 17: /* ParamList: %empty  */
#line 154 "t_1.y"
                                      {printf("Empty ParList") ;}
#line 1609 "y.tab.c"
    break;

  case 18: /* Param: Type ID  */
#line 157 "t_1.y"
                                      {
                                        yyval = yyvsp[0] ;
                                        yyval->type = yyvsp[-1]->type ;
                                        yyval->nodeType = PARAM ;
                                      }
#line 1619 "y.tab.c"
    break;

  case 19: /* FDefBlock: FDefBlock Fdef  */
#line 164 "t_1.y"
                                            {yyval = (YYSTYPE) createTree(0,-1,Connector,Connector,NULL,yyvsp[-1],yyvsp[0]);}
#line 1625 "y.tab.c"
    break;

  case 20: /* FDefBlock: Fdef  */
#line 165 "t_1.y"
                                            {yyval = yyvsp[0];}
#line 1631 "y.tab.c"
    break;

  case 21: /* Fdef: Type ID '(' ParamList ')' '{' LDeclBlock LBody '}'  */
#line 168 "t_1.y"
                                                                    {
                                                                      yyval = yyvsp[-7] ;
                                                                      yyval->type = yyvsp[-8]->type ;
                                                                      yyval->nodeType = FUNCTION ;
                                                                      yyval->sTable = makeLocalTable(yyval,yyvsp[-2]) ;
                                                                      yyval->left = yyvsp[-5] ;
                                                                      yyval->right = yyvsp[-1] ;
                                                                      assignTable(yyval,yyval->sTable) ;
                                                                      addParams(yyval->sTable,getParams(yyval)) ;
                                                                      setLTable(yyval->varName,yyval->sTable) ;
                                                                      
                                                                      printf("------%15s  -----\n",yyval->varName) ;
                                                                      showLTable(yyval->sTable) ;
                                                                      printf("----------------------------\n") ;
                                                                    }
#line 1651 "y.tab.c"
    break;

  case 22: /* Fdef: Type ID '(' ParamList ')' '{' LBody '}'  */
#line 183 "t_1.y"
                                                                    {
                                                                      yyval = yyvsp[-6] ;
                                                                      yyval->type = yyvsp[-7]->type ;
                                                                      yyval->nodeType = FUNCTION ;
                                                                      yyval->sTable = calloc(1,sizeof(LSymbol)) ;
                                                                      yyval->sTable->name = "NULL" ;
                                                                      yyval->sTable->next = NULL ;
                                                                      yyval->left = yyvsp[-4] ;
                                                                      yyval->right = yyvsp[-1] ;
                                                                      assignTable(yyval,yyval->sTable) ;
                                                                      addParams(yyval->sTable,getParams(yyval)) ;
                                                                      setLTable(yyval->varName,yyval->sTable) ;
                                                                      
                                                                      printf("------%15s  -----\n",yyval->varName) ;
                                                                      showLTable(yyval->sTable) ;
                                                                      printf("----------------------------\n") ;
                                                                    }
#line 1673 "y.tab.c"
    break;

  case 23: /* LDeclBlock: DECL LDeclList ENDDECL  */
#line 202 "t_1.y"
                                                      {yyval = yyvsp[-1] ;}
#line 1679 "y.tab.c"
    break;

  case 24: /* LDeclBlock: DECL ENDDECL  */
#line 203 "t_1.y"
                                                      {yyval = NULL ;}
#line 1685 "y.tab.c"
    break;

  case 25: /* LDeclList: LDeclList LDecl  */
#line 206 "t_1.y"
                                                      {yyval = (YYSTYPE) createTree(0,-1,Connector,IDDECL,NULL,yyvsp[-1],yyvsp[0]);}
#line 1691 "y.tab.c"
    break;

  case 26: /* LDeclList: LDecl  */
#line 207 "t_1.y"
                                                      {yyval = yyvsp[0];}
#line 1697 "y.tab.c"
    break;

  case 27: /* LDecl: Type Varlist ';'  */
#line 210 "t_1.y"
                                                      {
                                                        assignType(yyvsp[-1],yyvsp[-2]->type) ;
                                                        // printf("Local Table %d\n",$1->type) ;
                                                        yyval = yyvsp[-1] ;
                                                      }
#line 1707 "y.tab.c"
    break;

  case 28: /* Type: INT  */
#line 217 "t_1.y"
                                  {yyval = (YYSTYPE) createTree(0,-1,TYPE,INT,NULL,NULL,NULL);}
#line 1713 "y.tab.c"
    break;

  case 29: /* Type: STR  */
#line 218 "t_1.y"
                                  {yyval = (YYSTYPE) createTree(0,-1,TYPE,STR,NULL,NULL,NULL);}
#line 1719 "y.tab.c"
    break;

  case 30: /* Type: BOOL  */
#line 219 "t_1.y"
                                  {yyval = (YYSTYPE) createTree(0,-1,TYPE,BOOL,NULL,NULL,NULL);}
#line 1725 "y.tab.c"
    break;

  case 31: /* MainBlock: INT MAIN '(' ')' '{' LDeclBlock LBody '}'  */
#line 222 "t_1.y"
                                                                    {
                                                                      yyval = (YYSTYPE) createTree(-1,-1,ID,ID,"main",NULL,NULL) ;
                                                                      yyval->type = INT ;
                                                                      yyval->nodeType = FUNCTION ;
                                                                      yyval->sTable = makeLocalTable(yyval,yyvsp[-2]) ;
                                                                      yyval->right = yyvsp[-1] ;
                                                                      assignTable(yyval,yyval->sTable) ;
                                                                      setLTable(yyval->varName,yyval->sTable) ;

                                                                      // printf("------%15s  -----\n",$$->varName) ;
                                                                      // showLTable($$->sTable) ;
                                                                      // printf("----------------------------\n") ;
                                                                    }
#line 1743 "y.tab.c"
    break;

  case 32: /* MainBlock: INT MAIN '(' ')' '{' LBody '}'  */
#line 235 "t_1.y"
                                                         {
                                                                      yyval = (YYSTYPE) createTree(-1,-1,ID,ID,"main",NULL,NULL) ;
                                                                      yyval->type = INT ;
                                                                      yyval->nodeType = FUNCTION ;
                                                                      yyval->sTable = calloc(1,sizeof(LSymbol)) ;
                                                                      yyval->sTable->name = "NULL" ;
                                                                      yyval->right = yyvsp[-1] ;
                                                                      assignTable(yyval,yyval->sTable) ;
                                                                      setLTable(yyval->varName,yyval->sTable) ;

                                                                      // printf("------%15s  -----\n",$$->varName) ;
                                                                      // showLTable($$->sTable) ;
                                                                      // printf("----------------------------\n") ;
                                                                    }
#line 1762 "y.tab.c"
    break;

  case 33: /* IfStmt: IF '(' E ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 251 "t_1.y"
                                                        {
                                                          YYSTYPE Temp = (YYSTYPE) createTree(0,-1,IFTHEN,IFTHEN,NULL,yyvsp[-4],yyvsp[-2]);
                                                          yyval = (YYSTYPE) createTree(0,-1,IFTHEN,IF,NULL,yyvsp[-7],Temp) ;
                                                        }
#line 1771 "y.tab.c"
    break;

  case 34: /* IfStmt: IF '(' E ')' THEN Slist ENDIF ';'  */
#line 255 "t_1.y"
                                                        {yyval = (YYSTYPE) createTree(0,-1,IF,IF,NULL,yyvsp[-5],yyvsp[-2]);}
#line 1777 "y.tab.c"
    break;

  case 35: /* WhStmt: WHILE '(' E ')' DO Slist ENDWHILE ';'  */
#line 258 "t_1.y"
                                                  {
                                                    // printf("%d\n",$6->nodeType) ;
                                                    yyval = (YYSTYPE) createTree(0,-1,WHILE,WHILE,NULL,yyvsp[-5],yyvsp[-2]);}
#line 1785 "y.tab.c"
    break;

  case 36: /* LBody: BEGIN_ Slist END_  */
#line 263 "t_1.y"
                                    {yyval = yyvsp[-1];}
#line 1791 "y.tab.c"
    break;

  case 37: /* LBody: BEGIN_ END_  */
#line 264 "t_1.y"
                                    {printf("Empty Body") ;}
#line 1797 "y.tab.c"
    break;

  case 38: /* Slist: Slist Stmt  */
#line 267 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,-1,Connector,Connector,NULL,yyvsp[-1],yyvsp[0]);}
#line 1803 "y.tab.c"
    break;

  case 39: /* Slist: Stmt  */
#line 268 "t_1.y"
                                    {yyval = yyvsp[0];}
#line 1809 "y.tab.c"
    break;

  case 40: /* Stmt: Input  */
#line 271 "t_1.y"
                                    {yyval = yyvsp[0];}
#line 1815 "y.tab.c"
    break;

  case 41: /* Stmt: Output  */
#line 272 "t_1.y"
                                    {yyval = yyvsp[0];}
#line 1821 "y.tab.c"
    break;

  case 42: /* Stmt: Asgmt  */
#line 273 "t_1.y"
                                    {yyval = yyvsp[0];}
#line 1827 "y.tab.c"
    break;

  case 43: /* Stmt: IfStmt  */
#line 274 "t_1.y"
                                    {yyval = yyvsp[0];}
#line 1833 "y.tab.c"
    break;

  case 44: /* Stmt: WhStmt  */
#line 275 "t_1.y"
                                    {yyval = yyvsp[0];}
#line 1839 "y.tab.c"
    break;

  case 45: /* Stmt: BrkStmt  */
#line 276 "t_1.y"
                                    {yyval = yyvsp[0];}
#line 1845 "y.tab.c"
    break;

  case 46: /* Stmt: RetStmt  */
#line 277 "t_1.y"
                                    {yyval = yyvsp[0];}
#line 1851 "y.tab.c"
    break;

  case 47: /* Varlist: Varlist ',' ID  */
#line 280 "t_1.y"
                                  {
                                    yyvsp[0]->nodeType = IDDECL ;
                                    yyval = (YYSTYPE) createTree(0,-1,IDLIST,IDLIST,NULL,yyvsp[-2],yyvsp[0]);
                                  }
#line 1860 "y.tab.c"
    break;

  case 48: /* Varlist: Varlist ',' ID '[' NUM ']'  */
#line 284 "t_1.y"
                                          {
                                            yyvsp[-3]->nodeType = IDDECL ;
                                            yyvsp[-3]->type = ARRAY ;
                                            // $1->left = (YYSTYPE) createTree(0,-1,EXPR,EXPR,NULL,$3,NULL) ;
                                            yyvsp[-3]->left = yyvsp[-1] ;
                                            yyval = (YYSTYPE) createTree(0,-1,IDLIST,IDLIST,NULL,yyvsp[-5],yyvsp[-3]);
                                          }
#line 1872 "y.tab.c"
    break;

  case 49: /* Varlist: ID  */
#line 291 "t_1.y"
                                  {
                                    yyvsp[0]->nodeType = IDDECL ;
                                    yyval = yyvsp[0] ;
                                    // printf("VAR %s %d\n",$$->varName,$$->type);
                                  }
#line 1882 "y.tab.c"
    break;

  case 50: /* Varlist: ID '[' NUM ']'  */
#line 296 "t_1.y"
                                  {
                                    yyvsp[-3]->nodeType = IDDECL ;
                                    yyvsp[-3]->type = ARRAY ;
                                    // $1->left = (YYSTYPE) createTree(0,-1,EXPR,EXPR,NULL,$3,NULL) ;
                                    yyvsp[-3]->left = yyvsp[-1] ;
                                  }
#line 1893 "y.tab.c"
    break;

  case 51: /* RetStmt: RETURN E ';'  */
#line 304 "t_1.y"
                                  {yyval = (YYSTYPE) createTree(0,-1,RETURN,RETURN,NULL,yyvsp[-1],NULL) ;}
#line 1899 "y.tab.c"
    break;

  case 52: /* BrkStmt: BRKP ';'  */
#line 307 "t_1.y"
                                  {yyval = (YYSTYPE) createTree(0,-1,BRKP,BRKP,NULL,NULL,NULL);}
#line 1905 "y.tab.c"
    break;

  case 53: /* Input: READ '(' ID ')' ';'  */
#line 310 "t_1.y"
                                  {
                                    yyval = (YYSTYPE) createTree(0,-1,READ,INT,NULL,yyvsp[-2],NULL); 
                                    // printf("[%#x %d] ",$$,$3->nodeType);
                                  }
#line 1914 "y.tab.c"
    break;

  case 54: /* Input: READ '(' ArrEl ')' ';'  */
#line 314 "t_1.y"
                                  {
                                    yyval = (YYSTYPE) createTree(0,-1,READ,INT,NULL,yyvsp[-2],NULL); 
                                    // printf("[%#x %d] ",$$,$3->nodeType);
                                  }
#line 1923 "y.tab.c"
    break;

  case 55: /* Output: WRITE '(' E ')' ';'  */
#line 320 "t_1.y"
                                  {
                                    yyval = (YYSTYPE) createTree(0,-1,WRITE,INT,NULL,yyvsp[-2],NULL); 
                                    // printf("[%#x %d] ",$$,$3->nodeType);
                                  }
#line 1932 "y.tab.c"
    break;

  case 56: /* Asgmt: ID EQ E ';'  */
#line 326 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,'=',EQ,EQ,NULL,yyvsp[-3],yyvsp[-1]);}
#line 1938 "y.tab.c"
    break;

  case 57: /* Asgmt: ArrEl EQ E ';'  */
#line 327 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,'=',EQ,EQ,NULL,yyvsp[-3],yyvsp[-1]);}
#line 1944 "y.tab.c"
    break;

  case 58: /* E: E OP2 E  */
#line 330 "t_1.y"
                                    {
                                      if((yyvsp[-2]->type==INT||yyvsp[-2]->type==ID||yyvsp[-2]->type==CALL) && (yyvsp[0]->type==INT||yyvsp[0]->type==ID||yyvsp[0]->type==CALL))
                                      {
                                        yyval = yyvsp[-1];
                                        yyval->left = yyvsp[-2]; 
                                        yyval->right = yyvsp[0]; 
                                      }
                                      else 
                                      {
                                        printf("Type Mismatch %d %d %c\n",yyvsp[-2]->type,yyvsp[0]->type,yyvsp[-1]->op) ;
                                        exit(0) ;
                                      }
                                    }
#line 1962 "y.tab.c"
    break;

  case 59: /* E: E OP E  */
#line 343 "t_1.y"
                                    {
                                      if((yyvsp[-2]->type==INT||yyvsp[-2]->type==ID||yyvsp[-2]->type==CALL) && (yyvsp[0]->type==INT||yyvsp[0]->type==ID||yyvsp[0]->type==CALL))
                                      {
                                        yyval = yyvsp[-1];
                                        yyval->left = yyvsp[-2]; 
                                        yyval->right = yyvsp[0]; 
                                      }
                                      else 
                                      {
                                        printf("Type Mismatch %c\n",yyvsp[-1]->op) ;
                                        exit(0) ;
                                      }
                                    }
#line 1980 "y.tab.c"
    break;

  case 60: /* E: E LT E  */
#line 356 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,LT,RELOP,BOOL,NULL,yyvsp[-2],yyvsp[0]);}
#line 1986 "y.tab.c"
    break;

  case 61: /* E: E GT E  */
#line 357 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,GT,RELOP,BOOL,NULL,yyvsp[-2],yyvsp[0]);}
#line 1992 "y.tab.c"
    break;

  case 62: /* E: E EE E  */
#line 358 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,EE,RELOP,BOOL,"==",yyvsp[-2],yyvsp[0]);}
#line 1998 "y.tab.c"
    break;

  case 63: /* E: E NE E  */
#line 359 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,NE,RELOP,BOOL,"!=",yyvsp[-2],yyvsp[0]);}
#line 2004 "y.tab.c"
    break;

  case 64: /* E: E LTE E  */
#line 360 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,LTE,RELOP,BOOL,"<=",yyvsp[-2],yyvsp[0]);}
#line 2010 "y.tab.c"
    break;

  case 65: /* E: E GTE E  */
#line 361 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,GTE,RELOP,BOOL,">=",yyvsp[-2],yyvsp[0]);}
#line 2016 "y.tab.c"
    break;

  case 66: /* E: E OR E  */
#line 362 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,OR,OR,BOOL,"||",yyvsp[-2],yyvsp[0]);}
#line 2022 "y.tab.c"
    break;

  case 67: /* E: E AND E  */
#line 363 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,AND,AND,BOOL,"&&",yyvsp[-2],yyvsp[0]);}
#line 2028 "y.tab.c"
    break;

  case 68: /* E: ID  */
#line 364 "t_1.y"
                                    {yyval = yyvsp[0];}
#line 2034 "y.tab.c"
    break;

  case 69: /* E: ID '(' ')'  */
#line 365 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,-1,FUNCTION,CALL,NULL,NULL,yyvsp[-2]) ;}
#line 2040 "y.tab.c"
    break;

  case 70: /* E: ID '(' ArgList ')'  */
#line 366 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,-1,FUNCTION,CALL,NULL,yyvsp[-1],yyvsp[-3]) ;}
#line 2046 "y.tab.c"
    break;

  case 71: /* E: NUM  */
#line 367 "t_1.y"
                                    {yyval = yyvsp[0]; }
#line 2052 "y.tab.c"
    break;

  case 72: /* E: STRING  */
#line 368 "t_1.y"
                                    {yyval = yyvsp[0]; }
#line 2058 "y.tab.c"
    break;

  case 73: /* E: ArrEl  */
#line 369 "t_1.y"
                                    {yyval = yyvsp[0]; }
#line 2064 "y.tab.c"
    break;

  case 74: /* E: '(' E ')'  */
#line 370 "t_1.y"
                                    {yyval = yyvsp[-1]; }
#line 2070 "y.tab.c"
    break;

  case 75: /* ArgList: ArgList ',' E  */
#line 372 "t_1.y"
                                    {
                                      yyvsp[0]->type = ARGLIST ;
                                      yyval = (YYSTYPE) createTree(0,-1,ARGLIST,ARGLIST,NULL,yyvsp[-2],yyvsp[0]) ;
                                      yyval->val = yyvsp[-2]->val + 1 ;
                                    }
#line 2080 "y.tab.c"
    break;

  case 76: /* ArgList: E  */
#line 377 "t_1.y"
                                    {
                                      yyvsp[0]->val = 0 ;
                                      yyval = (YYSTYPE) createTree(0,-1,ARGLIST,ARGLIST,NULL,yyvsp[0],NULL) ;
                                      yyval->val = yyvsp[0]->val + 1 ;
                                    }
#line 2090 "y.tab.c"
    break;

  case 77: /* ArrEl: ID '[' E ']'  */
#line 383 "t_1.y"
                                    {
                                      yyval = yyvsp[-3]; 
                                      yyval->nodeType = ARRAY ;
                                      // printf("Array Index %d\n",$3->val) ;
                                      // $$->left = (YYSTYPE) createTree(0,-1,EXPR,EXPR,NULL,$3,NULL) ;
                                      yyval->left = yyvsp[-1] ;
                                    }
#line 2102 "y.tab.c"
    break;


#line 2106 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 394 "t_1.y"


void yyerror(char const *s)
{
    printf("yyerror %c %s\n",yychar,s);
    return ;
}

void paren(tnode *Tree) 
{
  printf("(") ;
  if(Tree != NULL) 
  {
    printf("[%d %c %s] ",Tree->nodeType,Tree->op,Tree->varName) ;
    paren(Tree->left) ;
    paren(Tree->right) ;
  }
  printf(")"); 
  return ;
}

int getReg()
{
  for(int i=1;i<19;i+=1)
    if(REG[i] == 0)
    {
      REG[i] = 1 ;
      return i ;
    }
}

void freeReg(int reg)
{
  REG[reg] = 0 ;
}

void assignType(tnode *Tree,int type)
{
  if(Tree == NULL||Tree->nodeType == PARAM)
    return ;
  Tree->type = type ;
  assignType(Tree->left,type) ;
  assignType(Tree->right,type) ;
}

int getAddress(tnode *Node)
{
  for(int i=0;i<varEntry;i+=1)
    if(!strcmp(sTable[i].name,Node->varName))
        return sTable[i].address ;
  return -1 ;
}

int getLabel(tnode *Node)
{
  for(int i=0;i<varEntry;i+=1)
    if(!strcmp(sTable[i].name,Node->varName))
        return sTable[i].flabel ;
  return -1 ;
}

ParamStruct *getParams(tnode *Node)
{
  for(int i=0;i<varEntry;i+=1)
    if(!strcmp(sTable[i].name,Node->varName))
        return sTable[i].paramList ;
  return -1 ;
}

int getLAddress(tnode *Node)
{
  if(Node==NULL)
    return -1 ;
  // printf("-----------\n") ;
  // showLTable(Node->sTable) ;
  // printf("-----------\n") ;
  LSymbol *sTable = Node->sTable ;
  while(sTable != NULL)
  {
    // printf("Search %10s %10s\n",sTable->name , Node->varName) ;
    if(!strcmp(sTable->name,Node->varName))
    {
      // printf("%s Returning %d\n",sTable->name,sTable->address); 
      return sTable->address ;
    }
    else 
      sTable = sTable->next ;
  }
  return -1 ;
}

void addLSymbol(LSymbol **table,tnode *Node)
{
  LSymbol *temp = NULL ;
  if(*table == NULL)
  {
    *table = calloc(1,sizeof(LSymbol)) ;
    temp = *table ;
    temp->name = Node->varName ;
    temp->type = Node->type ;
    temp->type = Node->type ;
    temp->address = lSize ;
    temp->size = Node->left ? Node->left->val : 1 ;
    temp->next = NULL ;
  }
  else 
  {
    temp = *table ;
    while(temp->next!=NULL)
      temp = temp->next ;
    temp->next = calloc(1,sizeof(LSymbol)) ;
    temp = temp->next ;
    temp->name = Node->varName ;
    temp->type = Node->type ;
    temp->address = lSize ;
    temp->size = Node->left ? Node->left->val : 1 ;
    temp->next = NULL ;
  }
  lSize += temp->size ;
  lEntry += 1 ;
}

void addLSymbols(LSymbol **table,tnode *Node)
{
  if(Node==NULL)
    return ;
  if((Node->type==INT||Node->type==STR||Node->type==BOOL)&&Node->nodeType!=IDLIST)
    addLSymbol(table,Node) ;
  else
  {
    addLSymbols(table,Node->left) ;
    addLSymbols(table,Node->right) ;
  }
}

void addParams(LSymbol *table,ParamStruct *param)
{
  int s = -3 ;
  while(table->next!=NULL)
  {
    // s += table->size ;
    table = table->next ;
  }
  while(param!=NULL)
  {
    table->next = calloc(1,sizeof(LSymbol)) ;
    table = table->next ;
    table->name = param->name ;
    table->type = param->type ;
    table->address = s ;
    table->size = 1 ;
    table->next = NULL ;
    param = param->next ;
    s -= table->size ;
  }
}

void assignTable(tnode *Tree,LSymbol *table)
{
  if(Tree == NULL)
    return ;
  Tree->sTable = table ;
  assignTable(Tree->left,table) ;
  assignTable(Tree->right,table) ;
}

void showLTable(LSymbol *table)
{
  while(table!=NULL)
    {
      printf("%10s %4d %4d %4d %#x\n",table->name,table->type,table->address,table->size,table) ;
      table = table->next ;
    }
}

void setLTable(char *name,LSymbol *table) 
{
  for(int i=0;i<varEntry;i+=1)
    if(!strcmp(sTable[i].name,name))
      sTable[i].sTable = table ;
}

LSymbol *makeLocalTable(tnode *Node,tnode *decl)
{
  if(decl == NULL)
    Node->sTable = NULL ;
  else
    addLSymbols(&(Node->sTable),decl) ;
  // printf("------%15s  -----\n",Node->varName) ;
  // showLTable(Node->sTable) ;
  // printf("----------------------------\n") ;
  lEntry = 0 ;
  lSize = 1;
  return Node->sTable ;
}

ParamStruct *makeParamlist(tnode *Node,ParamStruct **paramList,int pars)
{
  if(Node==NULL)
    return NULL ;
  if(*paramList==NULL)
    *paramList = calloc(1,sizeof(ParamStruct)) ;
  else 
    *paramList = realloc(*paramList,(pars+1)*sizeof(ParamStruct)) ;
  (*paramList)[pars].name = Node->varName ;
  (*paramList)[pars].type = Node->type ;
  (*paramList)[pars].next = NULL ;
  if(pars!=0)
    (*paramList)[pars-1].next = *paramList + pars ;
  if(Node->left==NULL)
    return *paramList ;
  else 
    return makeParamlist(Node->left,paramList,pars+1) ;
}

void addGSymbol(tnode *Node)
{
  if(getAddress(Node) != -1)
  {
    printf("[+] Error : Duplicate Declaration\n") ;
    exit(0) ;
  }
  if(sTable == NULL)
    sTable = (GSymbol *) calloc(1,sizeof(GSymbol)) ;
  else 
    sTable = (GSymbol *) realloc(sTable,(varEntry+1)*sizeof(GSymbol)) ;
  sTable[varEntry].name = Node->varName ;
  sTable[varEntry].type = Node->type ;
  if(Node->nodeType == FUNCTION)
  {
    sTable[varEntry].address = 0 ;
    sTable[varEntry].size = -1 ;
    ParamStruct *paramList = NULL ;
    sTable[varEntry].paramList = makeParamlist(Node->left,&paramList,0) ;
    sTable[varEntry].flabel = flabel++ ;
  }
  else
  {
    sTable[varEntry].flabel = -1 ;
    sTable[varEntry].address = varSize + 4096 ;
    sTable[varEntry].size = Node->left ? Node->left->val : 1 ;
    varSize += sTable[varEntry].size ;
  }
  varEntry += 1 ;
}

void addGSymbols(tnode *Node)
{
  if(Node==NULL)
    return ;
  if(Node->nodeType != IDLIST)
    addGSymbol(Node) ;
  else 
  {
    addGSymbols(Node->left) ;
    addGSymbols(Node->right) ;
  }
}

int getStackSize(LSymbol *table)
{
  int size = 0 ;
  while(table!=NULL)
  {
    size += table->size ;
    table = table->next ;
  }
  return size ;
}

void showParamList(ParamStruct *list)
{
  while(list!=NULL)
  {
    printf("\t%10s %4d\n",list->name,list->type) ;
    list = list->next ;
  }
}

void showGTable()
{
  for(int i=0;i<varEntry;i+=1)
    {
      printf("%10s %4d %4d %4d %#x %4d\n",sTable[i].name,sTable[i].type,sTable[i].address,sTable[i].size,sTable[i].paramList,sTable[i].flabel) ;
      if(sTable[i].flabel!=-1)
        showParamList(sTable[i].paramList);
    }
}

void copyRegs(int *from,int *to) 
{
  return ; 
}

void showRegs()
{
  for(int i=0;i<20;i+=1)
  {
    printf("R%d : %d\t\t",i,REG[i]) ;
    if(i%5==4)
      printf("\n") ;
  }
  printf("\n") ;
}

int codeGen(tnode *Tree) 
{
  int p,q,s,b ;
  int l1 , l2 ;
  int *regStack = NULL ;
  if(Tree==NULL)
    return -1;
  switch(Tree->nodeType)
  {
    case READ:  //printf("PRINT \n") ;
                fprintf(target_file,"MOV R19,7\n") ;
                fprintf(target_file,"PUSH R19\n") ;
                fprintf(target_file,"MOV R19,-2\n") ;
                fprintf(target_file,"PUSH R19\n") ;
                if(Tree->left->nodeType == ARRAY)
                {  
                  Tree->left->op = READ ;
                  fprintf(target_file,"MOV R19,R%d\n",codeGen(Tree->left)) ;
                  p = codeGen(Tree->left) ;
                }
                else
                {
                  addr = getLAddress(Tree->left) ;
                  if(addr!=-1)
                  {
                    fprintf(target_file,"MOV R19,BP\n") ;
                    fprintf(target_file,"ADD R19,%d\n",addr) ;
                    // fprintf(target_file,"MOV R19,[R19]\n") ;
                  }
                  else 
                    fprintf(target_file,"MOV R19,%d\n",getAddress(Tree->left)) ;
                }
                fprintf(target_file,"PUSH R19\n") ;
                fprintf(target_file,"PUSH R19\n") ;
                fprintf(target_file,"PUSH R19\n") ;
                fprintf(target_file,"INT 6\n") ;
                fprintf(target_file,"POP R19\n") ;
                fprintf(target_file,"POP R19\n") ;
                fprintf(target_file,"POP R19\n") ;
                fprintf(target_file,"POP R19\n") ;
                fprintf(target_file,"POP R19\n") ;
                if(Tree->left->nodeType == ARRAY)
                  freeReg(p) ;
                return -1 ;
                break ;
    case WRITE: //printf("WRITE \n") ;
                fprintf(target_file,"MOV R19,5\n") ;
                fprintf(target_file,"PUSH R19\n") ;
                fprintf(target_file,"MOV R19,-1\n") ;
                fprintf(target_file,"PUSH R19\n") ;
                p = codeGen(Tree->left) ;
                fprintf(target_file,"MOV R19,R%d\n",p) ;
                fprintf(target_file,"PUSH R19\n") ;
                fprintf(target_file,"PUSH R19\n") ;
                fprintf(target_file,"PUSH R19\n") ;
                fprintf(target_file,"INT 7\n") ;
                fprintf(target_file,"POP R19\n") ;
                fprintf(target_file,"POP R19\n") ;
                fprintf(target_file,"POP R19\n") ;
                fprintf(target_file,"POP R19\n") ;
                fprintf(target_file,"POP R19\n") ;
                freeReg(p) ;
                return -1 ;
                break ;
    case NUM :  //printf("NUM \n") ;
                p = getReg() ;
                fprintf(target_file,"MOV R%d,%d\n",p,Tree->val) ;
                return p ;
                break ;
    case STRING://printf("STR \n") ;
                p = getReg() ;
                fprintf(target_file,"MOV R%d,%s\n",p,Tree->varName) ;
                return p ;
                break ;
    case ID :   //printf("ID \n") ;
                p = getReg() ;
                addr = getLAddress(Tree) ;
                if(addr!=-1)
                { 
                  fprintf(target_file,"MOV R%d,BP\n",p) ;
                  fprintf(target_file,"ADD R%d,%d\n",p,addr) ;
                  fprintf(target_file,"MOV R%d,[R%d]\n",p,p) ;
                }
                else 
                  fprintf(target_file,"MOV R%d,[%d]\n",p,getAddress(Tree)) ;
                return p ;
                break ;
    case ARRAY: //printf("ARRAY \n") ;
                p = getReg() ;
                q = codeGen(Tree->left) ;
                addr = getLAddress(Tree) ;
                if(addr!=-1)
                { 
                  fprintf(target_file,"MOV R%d,BP\n",p) ;
                  fprintf(target_file,"ADD R%d,%d\n",p,addr) ;
                }
                else 
                  fprintf(target_file,"MOV R%d,%d\n",p,getAddress(Tree)) ;
                fprintf(target_file,"ADD R%d, R%d\n",p,q) ;
                if(Tree->op != READ && Tree->op != EQ) 
                  fprintf(target_file,"MOV R%d,[R%d]\n",p,p) ;
                freeReg(q) ;
                return p ;
                break ;
    case OP2 :
    case OP :   //printf("OP \n") ;
                //showRegs() ;
                p = codeGen(Tree->left) ;
                //showRegs() ;
                q = codeGen(Tree->right) ;
                //showRegs() ;
                s = p ; 
                b = q ;
                //printf("Operation %d %c %d\n\n\n",s,Tree->op,b) ;
                // s = p ; b = q ;
                //printf("[OP [%d %d] %d %d %c] \n",s,b,Tree->left->val,Tree->right->val,Tree->op) ;
                switch(Tree->op)
                {
                  case '+' :fprintf(target_file,"ADD R%d, R%d\n",s,b) ;
                            break ;
                  case '-' :fprintf(target_file,"SUB R%d, R%d\n",s,b) ;
                            break ;
                  case '*' :fprintf(target_file,"MUL R%d, R%d\n",s,b) ;
                            break ;
                  case '/' :fprintf(target_file,"DIV R%d, R%d\n",s,b) ;
                            break ;
                  case '%' :fprintf(target_file,"MOD R%d, R%d\n",s,b) ;
                            break ;
                  default  :break ;
                }
                freeReg(b) ;
                return s ;
                break ;
    case AND    : //printf("AND \n") ;
                  s = getReg() ;
                  l1 = label++ ;
                  l2 = label++ ;
                  p = codeGen(Tree->left) ;
                  fprintf(target_file,"JZ R%d,_L%d\n",p,l1) ;
                  freeReg(p) ;
                  q = codeGen(Tree->right) ;
                  fprintf(target_file,"MOV R%d,R%d\n",s,q) ;
                  freeReg(q) ;
                  fprintf(target_file,"JMP _L%d\n",l2) ;
                  fprintf(target_file,"_L%d:\n",l1) ;
                  fprintf(target_file,"MOV R%d,0\n",s) ;
                  fprintf(target_file,"_L%d:\n",l2) ;
                  return s ;
                  break ;
    case OR     : //printf("OR \n") ;
                  s = getReg() ;
                  l1 = label++ ;
                  l2 = label++ ;
                  p = codeGen(Tree->left) ;
                  fprintf(target_file,"JNZ R%d,_L%d\n",p,l1) ;
                  freeReg(p) ;
                  q = codeGen(Tree->right) ;
                  fprintf(target_file,"MOV R%d,R%d\n",s,q) ;
                  freeReg(q) ;
                  fprintf(target_file,"JMP _L%d\n",l2) ;
                  fprintf(target_file,"_L%d:\n",l1) ;
                  fprintf(target_file,"MOV R%d,1\n",s) ;
                  fprintf(target_file,"_L%d:\n",l2) ;
                  return s ;
                  break ;
    case RELOP ://printf("RELOP \n") ;
                p = codeGen(Tree->left) ;
                q = codeGen(Tree->right) ;
                switch(Tree->op)
                {
                  case LT : fprintf(target_file,"LT R%d,R%d\n",p,q) ;
                            return p ;
                            break ;
                  case GT : fprintf(target_file,"GT R%d,R%d\n",p,q) ;
                            return p ;
                            break ;
                  case EE : fprintf(target_file,"EQ R%d,R%d\n",p,q) ;
                            return p ;
                            break ;
                  case NE : fprintf(target_file,"NE R%d,R%d\n",p,q) ;
                            return p ;
                            break ;
                  case GTE: fprintf(target_file,"GE R%d,R%d\n",p,q) ;
                            return p ;
                            break ;
                  case LTE: fprintf(target_file,"LE R%d,R%d\n",p,q) ;
                            return p ;
                            break ;
                  default : break ;
                }
                freeReg(q) ;
                break ;
    case WHILE ://printf("WHILE \n") ;
                l1 = label++ ;
                l2 = label++ ;
                fprintf(target_file,"_L%d:\n",l1) ;
                p = codeGen(Tree->left) ;
                fprintf(target_file,"JZ R%d,_L%d\n",p,l2) ;
                q = codeGen(Tree->right) ;
                fprintf(target_file,"JMP _L%d\n",l1) ;
                fprintf(target_file,"_L%d:\n",l2) ;
                freeReg(p) ;
                break ;
    case IF   :   //printf("IF \n") ;
                  l1 = label++ ;
                  // l2 = label++ ;
                  // l3 = label++ ;
                  p = codeGen(Tree->left) ;
                  fprintf(target_file,"JZ R%d,_L%d\n",p,l1) ;
                  q = codeGen(Tree->right) ;
                  fprintf(target_file,"_L%d:\n",l1) ;
                  freeReg(p) ;
                  break ;
    case IFTHEN : //printf("IFTHEN \n") ;
                  l1 = label++ ;
                  l2 = label++ ;
                  p = codeGen(Tree->left) ;
                  fprintf(target_file,"JZ R%d,_L%d\n",p,l1) ;
                  q = codeGen(Tree->right->left) ;
                  fprintf(target_file,"JMP _L%d\n",l2) ;
                  fprintf(target_file,"_L%d:\n",l1) ;
                  q = codeGen(Tree->right->right) ;
                  fprintf(target_file,"_L%d:\n",l2) ;
                  freeReg(p) ;
                  break ;
    case EQ :   //printf("EQ \n") ;
                q = codeGen(Tree->right) ;
                //printf("[%c %d] \n",Tree->right->op,q) ;
                addr = getLAddress(Tree->left) ;
                if(Tree->left->nodeType != ARRAY) 
                {
                  if(addr != -1)
                  { 
                    p = getReg() ;
                    fprintf(target_file,"MOV R%d,BP\n",p) ;
                    fprintf(target_file,"ADD R%d,%d\n",p,addr) ;
                    fprintf(target_file,"MOV [R%d],R%d\n",p,q) ;
                    freeReg(p) ;
                  }
                  else 
                    fprintf(target_file,"MOV [%d],R%d\n",getAddress(Tree->left),q)  ;
                }
                else
                {
                  Tree->left->op = EQ ;
                  p = codeGen(Tree->left) ;
                  fprintf(target_file,"MOV [R%d], R%d\n",p,q) ;
                  freeReg(p) ;
                }
                freeReg(q) ;
                return -1 ;
                break ;
    case BRKP : fprintf(target_file,"BRKP\n") ;
    case Connector: p = codeGen(Tree->left) ;
                    q = codeGen(Tree->right) ; 
                    return -1 ; 
                    break ;
    case ARGLIST  : //printf("ARGLIST\n") ;
                    // break ;
                    if(Tree->left) 
                    {
                      q = codeGen(Tree->left) ;
                      //printf("codeGen %d\n",q) ;
                      if(q==-1) ;
                        // fprintf(target_file,"PUSH R19\n") ;
                      else 
                      {
                        fprintf(target_file,"PUSH R%d\n",q) ;
                        freeReg(q) ;
                      }
                      /*
                      p = codeGen(Tree->left) ;
                      fprintf(target_file,"PUSH R%d\n",p) ;
                      freeReg(p) ;*/
                    }
                    if(Tree->right)
                    {
                      q = codeGen(Tree->right) ;
                      //printf("codeGen %d\n",q) ;
                      if(q==-1) ;
                        // fprintf(target_file,"PUSH R19\n") ;
                      else 
                      {
                        fprintf(target_file,"PUSH R%d\n",q) ;
                        freeReg(q) ;
                      }
                    }
                    break ;
    case FUNCTION : if(Tree->type==CALL)
                    {
                      printf("Function Call\n") ;
                      regStack = (int *) calloc(20,sizeof(int)) ;
                      // Save Regs
                      for(int i=0;i<20;i+=1)
                      {
                        regStack[i] = REG[i] ;
                        if(REG[i] == 1)
                          fprintf(target_file,"PUSH R%d\n",i) ;
                      }
                      // Evaluate Arguments
                      p = codeGen(Tree->left) ;
                      for(int i=0;i<20;i+=1)
                        REG[i] = 0 ;
                      // Push Return Variable
                      fprintf(target_file,"PUSH R0\n") ;
                      // Function Call 
                      fprintf(target_file,"CALL _F%d\n",getLabel(Tree->right)) ;
                      // Pop Out Arguments 
                      p = 0 ;
                      while(regStack[p]!=0)
                        p += 1; 
                      fprintf(target_file,"POP R%d\n",p) ;
                      if(Tree->left)
                        for(int i=0 ;i<Tree->left->val ;i+=1)
                          fprintf(target_file,"POP R19\n") ;
                      for(int i=19;i>=0;i-=1)
                      {
                        REG[i] = regStack[i] ;
                        if(regStack[i] == 1)
                          fprintf(target_file,"POP R%d\n",i) ;
                      }
                      REG[p] = 1 ;
                      free(regStack) ;
                      return p ;
                    }
                    else 
                    {
                      q = getLabel(Tree) ;
                      if(q==-1)
                      {
                        //printf("FunBlock _MAIN\n") ;
                        fprintf(target_file,"_MAIN:\n") ;
                      }
                      else 
                      {
                        //printf("FunBlock _F%d\n",q) ;
                        fprintf(target_file,"_F%d:\n",q) ;
                      }
                        fprintf(target_file,"PUSH BP\n") ;
                        fprintf(target_file,"MOV BP,SP\n") ;
                        fprintf(target_file,"ADD SP,%d\n",getStackSize(Tree->sTable)) ;
                      p = codeGen(Tree->right) ;
                    }
                    break ;
    case RETURN : p = codeGen(Tree->left) ;
                  q = getReg() ;
                  fprintf(target_file,"MOV R%d,BP\n",q) ;
                  fprintf(target_file,"SUB R%d,2\n",q) ;
                  fprintf(target_file,"MOV [R%d],R%d\n",q,p) ;
                  fprintf(target_file,"SUB SP,%d\n",getStackSize(Tree->sTable)) ;
                  fprintf(target_file,"POP BP\n");
                  fprintf(target_file,"RET\n") ;
                  return p ;
                  break ;
    default :   break ;
  }
  return -1 ;
}

int main(int argc,char **argv)
{
  if(argc==2)
    target_file = fopen(argv[1],"w") ;
  else 
    target_file = stdout ;
  
  for(int i=0;i<20;i+=1)
    REG[i] = 0 ;
  char fname[20] ;
  yyparse();
  return 1;
}
