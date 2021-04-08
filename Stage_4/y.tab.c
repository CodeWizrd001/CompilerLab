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

    int codeGen(tnode *Tree) ;

    void addSymbols(tnode *Tree) ;
    void addSymbol(tnode *Tree) ;
    int getSymbol(char *name) ;

    void assignType(tnode *Tree,int type) ;
    int getAddress(tnode *Node) ;

    FILE *target_file ;
    int REG[20] ;
    int varSize = 0 ;
    int varEntry = 0 ;
    GSymbol *sTable = NULL ;
    int label = 0 ;

#line 101 "y.tab.c"

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
    INT = 287,                     /* INT  */
    BOOL = 288,                    /* BOOL  */
    STR = 289,                     /* STR  */
    TYPE = 290,                    /* TYPE  */
    IDLIST = 291,                  /* IDLIST  */
    STRING = 292,                  /* STRING  */
    ARRAY = 293                    /* ARRAY  */
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
#define INT 287
#define BOOL 288
#define STR 289
#define TYPE 290
#define IDLIST 291
#define STRING 292
#define ARRAY 293

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
  YYSYMBOL_INT = 32,                       /* INT  */
  YYSYMBOL_BOOL = 33,                      /* BOOL  */
  YYSYMBOL_STR = 34,                       /* STR  */
  YYSYMBOL_TYPE = 35,                      /* TYPE  */
  YYSYMBOL_IDLIST = 36,                    /* IDLIST  */
  YYSYMBOL_STRING = 37,                    /* STRING  */
  YYSYMBOL_ARRAY = 38,                     /* ARRAY  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* '['  */
  YYSYMBOL_44_ = 44,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_IfStmt = 47,                    /* IfStmt  */
  YYSYMBOL_WhStmt = 48,                    /* WhStmt  */
  YYSYMBOL_Slist = 49,                     /* Slist  */
  YYSYMBOL_Stmt = 50,                      /* Stmt  */
  YYSYMBOL_Declarations = 51,              /* Declarations  */
  YYSYMBOL_Declist = 52,                   /* Declist  */
  YYSYMBOL_Decl = 53,                      /* Decl  */
  YYSYMBOL_Type = 54,                      /* Type  */
  YYSYMBOL_Varlist = 55,                   /* Varlist  */
  YYSYMBOL_BrkStmt = 56,                   /* BrkStmt  */
  YYSYMBOL_Input = 57,                     /* Input  */
  YYSYMBOL_Output = 58,                    /* Output  */
  YYSYMBOL_Asgmt = 59,                     /* Asgmt  */
  YYSYMBOL_E = 60,                         /* E  */
  YYSYMBOL_ArrEl = 61                      /* ArrEl  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   230

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  104

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
      40,    41,     2,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    45,    45,    54,    59,    63,    65,    69,    70,    72,
      73,    74,    75,    76,    77,    78,    80,    83,    85,    86,
      88,    95,    96,    97,    99,   103,   108,   115,   117,   121,
     126,   131,   132,   134,   147,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   171
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
  "LTE", "GTE", "EE", "NE", "DECL", "ENDDECL", "IDDECL", "EXPR", "INT",
  "BOOL", "STR", "TYPE", "IDLIST", "STRING", "ARRAY", "';'", "'('", "')'",
  "','", "'['", "']'", "$accept", "program", "IfStmt", "WhStmt", "Slist",
  "Stmt", "Declarations", "Declist", "Decl", "Type", "Varlist", "BrkStmt",
  "Input", "Output", "Asgmt", "E", "ArrEl", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,    59,
      40,    41,    44,    91,    93
};
#endif

#define YYPACT_NINF (-80)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,   145,     8,    -8,    -6,    14,    15,     5,    22,    23,
     -13,   -80,   -80,   160,   -80,   -80,   -80,   -80,   -80,   -80,
      57,   -80,   -80,   -80,    62,    -3,    -3,    -3,    -3,    -3,
      33,   -80,   -80,   -80,    17,   -80,    64,    35,   -80,    -3,
     -19,    36,    37,   -80,   -80,    34,   -80,    86,     3,    42,
      80,   -80,    39,   -80,    41,    -7,   -80,   104,    40,    46,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    47,   -80,
     -80,    61,    74,   -80,    87,   -80,    91,   -80,   -80,   -80,
     -80,   106,   203,   203,   203,   203,   203,   203,   -80,   196,
     196,    73,   -80,   130,   168,   -80,   196,    79,    81,   183,
     -80,   -80,    83,   -80
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,    13,     0,     8,    15,    14,     9,    10,    11,
       0,     1,    27,     3,     0,     0,     0,     0,     0,     0,
       0,    21,    23,    22,     0,    19,     0,     0,     7,     0,
       0,     0,    41,    42,    43,     0,    44,     0,     0,     0,
       0,    17,     0,    18,    25,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      45,     0,     0,    16,     0,    20,     0,    32,    28,    29,
      33,    34,    35,    36,    39,    40,    37,    38,    30,     0,
       0,     0,    24,     0,     0,    26,     0,     0,     0,     0,
       5,     6,     0,     4
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -80,   -80,   -80,   -80,   -79,   -12,   -80,   -80,    67,   -80,
     -80,   -80,   -80,   -80,   -80,   -24,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    11,    12,    13,    14,    15,    34,    35,    36,
      55,    16,    17,    18,    19,    45,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      20,    38,    47,    48,    49,    50,    42,     1,    21,    43,
      93,    94,    20,    60,    61,    57,    30,    99,    26,    31,
      32,    33,    58,    41,    27,    62,    63,    64,    65,    66,
      67,    22,    75,    23,    44,    76,    80,    81,    82,    83,
      84,    85,    86,    87,    60,    61,    52,    70,    27,    31,
      32,    33,    60,    61,    24,    25,    62,    63,    64,    65,
      66,    67,    28,    29,    62,    63,    64,    65,    66,    67,
      39,    40,    51,    54,    56,    68,    89,    59,    73,    78,
      27,    38,    38,    71,    74,    79,    88,    38,    20,    20,
      60,    61,    20,    20,    90,    20,    60,    61,    20,    91,
      92,    53,    62,    63,    64,    65,    66,    67,    62,    63,
      64,    65,    66,    67,    60,    61,    60,    95,   100,     0,
     101,    72,   103,     0,     0,    69,    62,    63,    64,    65,
      66,    67,     0,     3,     0,     0,     0,     5,     6,     7,
       0,     0,     0,    77,     8,     0,    96,    97,     3,     9,
       0,     4,     5,     6,     7,     0,     0,     0,    10,     8,
       0,     0,     0,     3,     9,     0,    37,     5,     6,     7,
       0,     3,     0,    10,     8,     5,     6,     7,     0,     9,
       0,     0,     8,     0,     0,     0,     3,     9,    10,    98,
       5,     6,     7,     0,     0,     0,    10,     8,     0,     3,
     102,     0,     9,     5,     6,     7,     0,     0,     0,     0,
       8,    10,     0,    60,    61,     9,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    -1,    -1,    -1,    -1,    -1,
      -1
};

static const yytype_int8 yycheck[] =
{
       1,    13,    26,    27,    28,    29,     9,     5,     0,    12,
      89,    90,    13,    10,    11,    39,    29,    96,    13,    32,
      33,    34,    41,    24,    43,    22,    23,    24,    25,    26,
      27,    39,    39,    39,    37,    42,    60,    61,    62,    63,
      64,    65,    66,    67,    10,    11,    29,    44,    43,    32,
      33,    34,    10,    11,    40,    40,    22,    23,    24,    25,
      26,    27,    40,    40,    22,    23,    24,    25,    26,    27,
      13,     9,    39,     9,    39,    41,    15,    41,    39,    39,
      43,    93,    94,    41,    43,    39,    39,    99,    89,    90,
      10,    11,    93,    94,    20,    96,    10,    11,    99,    12,
       9,    34,    22,    23,    24,    25,    26,    27,    22,    23,
      24,    25,    26,    27,    10,    11,    10,    44,    39,    -1,
      39,    41,    39,    -1,    -1,    39,    22,    23,    24,    25,
      26,    27,    -1,     3,    -1,    -1,    -1,     7,     8,     9,
      -1,    -1,    -1,    39,    14,    -1,    16,    17,     3,    19,
      -1,     6,     7,     8,     9,    -1,    -1,    -1,    28,    14,
      -1,    -1,    -1,     3,    19,    -1,     6,     7,     8,     9,
      -1,     3,    -1,    28,    14,     7,     8,     9,    -1,    19,
      -1,    -1,    14,    -1,    -1,    -1,     3,    19,    28,    21,
       7,     8,     9,    -1,    -1,    -1,    28,    14,    -1,     3,
      17,    -1,    19,     7,     8,     9,    -1,    -1,    -1,    -1,
      14,    28,    -1,    10,    11,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    22,    23,    24,    25,    26,
      27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    46,     3,     6,     7,     8,     9,    14,    19,
      28,    47,    48,    49,    50,    51,    56,    57,    58,    59,
      61,     0,    39,    39,    40,    40,    13,    43,    40,    40,
      29,    32,    33,    34,    52,    53,    54,     6,    50,    13,
       9,    61,     9,    12,    37,    60,    61,    60,    60,    60,
      60,    39,    29,    53,     9,    55,    39,    60,    41,    41,
      10,    11,    22,    23,    24,    25,    26,    27,    41,    39,
      44,    41,    41,    39,    43,    39,    42,    39,    39,    39,
      60,    60,    60,    60,    60,    60,    60,    60,    39,    15,
      20,    12,     9,    49,    49,    44,    16,    17,    21,    49,
      39,    39,    17,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    46,    47,    47,    48,    49,    49,    50,
      50,    50,    50,    50,    50,    50,    51,    51,    52,    52,
      53,    54,    54,    54,    55,    55,    55,    56,    57,    57,
      58,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,    10,     8,     8,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     3,     2,     1,
       3,     1,     1,     1,     3,     1,     4,     2,     5,     5,
       5,     4,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     4
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
  case 2: /* program: BEGIN_ Slist END_ ';'  */
#line 45 "t_1.y"
                                  {
                                    printf("Completed\n");
                                    // paren($2) ;
                                    fprintf(target_file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0); 
                                    fprintf(target_file,"MOV SP,%d\nMOV BP,%d\n",4096+varSize,4096+varSize);
                                    codeGen(yyvsp[-2]) ;
                                    fprintf(target_file,"INT 10\n") ;
                                    exit(0);
                                  }
#line 1368 "y.tab.c"
    break;

  case 3: /* program: BEGIN_ END_ ';'  */
#line 54 "t_1.y"
                                  {
                                    printf("NULL\n");
                                    exit(0);
                                  }
#line 1377 "y.tab.c"
    break;

  case 4: /* IfStmt: IF '(' E ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 59 "t_1.y"
                                                        {
                                                          YYSTYPE Temp = (YYSTYPE) createTree(0,-1,IFTHEN,IFTHEN,NULL,yyvsp[-4],yyvsp[-2]);
                                                          yyval = (YYSTYPE) createTree(0,-1,IFTHEN,IF,NULL,yyvsp[-7],Temp) ;
                                                        }
#line 1386 "y.tab.c"
    break;

  case 5: /* IfStmt: IF '(' E ')' THEN Slist ENDIF ';'  */
#line 63 "t_1.y"
                                                        {yyval = (YYSTYPE) createTree(0,-1,IF,IF,NULL,yyvsp[-5],yyvsp[-2]);}
#line 1392 "y.tab.c"
    break;

  case 6: /* WhStmt: WHILE '(' E ')' DO Slist ENDWHILE ';'  */
#line 65 "t_1.y"
                                                  {
                                                    // printf("%d\n",$6->nodeType) ;
                                                    yyval = (YYSTYPE) createTree(0,-1,WHILE,WHILE,NULL,yyvsp[-5],yyvsp[-2]);}
#line 1400 "y.tab.c"
    break;

  case 7: /* Slist: Slist Stmt  */
#line 69 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,-1,Connector,Connector,NULL,yyvsp[-1],yyvsp[0]);}
#line 1406 "y.tab.c"
    break;

  case 8: /* Slist: Stmt  */
#line 70 "t_1.y"
                                    {yyval = yyvsp[0];}
#line 1412 "y.tab.c"
    break;

  case 9: /* Stmt: Input  */
#line 72 "t_1.y"
                                    {yyval = yyvsp[0];}
#line 1418 "y.tab.c"
    break;

  case 10: /* Stmt: Output  */
#line 73 "t_1.y"
                                    {yyval = yyvsp[0];}
#line 1424 "y.tab.c"
    break;

  case 11: /* Stmt: Asgmt  */
#line 74 "t_1.y"
                                    {yyval = yyvsp[0];}
#line 1430 "y.tab.c"
    break;

  case 12: /* Stmt: IfStmt  */
#line 75 "t_1.y"
                                    {yyval = yyvsp[0];}
#line 1436 "y.tab.c"
    break;

  case 13: /* Stmt: WhStmt  */
#line 76 "t_1.y"
                                    {yyval = yyvsp[0];}
#line 1442 "y.tab.c"
    break;

  case 14: /* Stmt: BrkStmt  */
#line 77 "t_1.y"
                                    {yyval = yyvsp[0];}
#line 1448 "y.tab.c"
    break;

  case 15: /* Stmt: Declarations  */
#line 78 "t_1.y"
                                    {yyval = yyvsp[0];}
#line 1454 "y.tab.c"
    break;

  case 16: /* Declarations: DECL Declist ENDDECL ';'  */
#line 80 "t_1.y"
                                        {
                                          yyval = (YYSTYPE) createTree(0,-1,DECL,DECL,NULL,yyvsp[-2],NULL);
                                        }
#line 1462 "y.tab.c"
    break;

  case 17: /* Declarations: DECL ENDDECL ';'  */
#line 83 "t_1.y"
                                  {yyval = (YYSTYPE) createTree(0,-1,DECL,0,NULL,NULL,NULL);}
#line 1468 "y.tab.c"
    break;

  case 18: /* Declist: Declist Decl  */
#line 85 "t_1.y"
                                  {yyval = (YYSTYPE) createTree(0,-1,DECL,Connector,NULL,yyvsp[-1],yyvsp[0]);}
#line 1474 "y.tab.c"
    break;

  case 19: /* Declist: Decl  */
#line 86 "t_1.y"
                                  {yyval = yyvsp[0] ;}
#line 1480 "y.tab.c"
    break;

  case 20: /* Decl: Type Varlist ';'  */
#line 88 "t_1.y"
                                  {
                                    assignType(yyvsp[-1],yyvsp[-2]->type) ;
                                    yyval = (YYSTYPE) createTree(0,-1,DECL,DECL,NULL,yyvsp[-2],yyvsp[-1]);
                                    yyval = NULL ;
                                    addSymbols(yyvsp[-1]) ;
                                  }
#line 1491 "y.tab.c"
    break;

  case 21: /* Type: INT  */
#line 95 "t_1.y"
                                  {yyval = (YYSTYPE) createTree(0,-1,TYPE,INT,NULL,NULL,NULL);}
#line 1497 "y.tab.c"
    break;

  case 22: /* Type: STR  */
#line 96 "t_1.y"
                                  {yyval = (YYSTYPE) createTree(0,-1,TYPE,STR,NULL,NULL,NULL);}
#line 1503 "y.tab.c"
    break;

  case 23: /* Type: BOOL  */
#line 97 "t_1.y"
                                  {yyval = (YYSTYPE) createTree(0,-1,TYPE,BOOL,NULL,NULL,NULL);}
#line 1509 "y.tab.c"
    break;

  case 24: /* Varlist: Varlist ',' ID  */
#line 99 "t_1.y"
                                  {
                                    yyvsp[0]->nodeType = IDDECL ;
                                    yyval = (YYSTYPE) createTree(0,-1,IDLIST,IDLIST,NULL,yyvsp[-2],yyvsp[0]);
                                  }
#line 1518 "y.tab.c"
    break;

  case 25: /* Varlist: ID  */
#line 103 "t_1.y"
                                  {
                                    yyvsp[0]->nodeType = IDDECL ;
                                    yyval = yyvsp[0] ;
                                    // printf("VAR %s %d\n",$$->varName,$$->type);
                                  }
#line 1528 "y.tab.c"
    break;

  case 26: /* Varlist: ID '[' NUM ']'  */
#line 108 "t_1.y"
                                  {
                                    yyvsp[-3]->nodeType = IDDECL ;
                                    yyvsp[-3]->type = ARRAY ;
                                    // $1->left = (YYSTYPE) createTree(0,-1,EXPR,EXPR,NULL,$3,NULL) ;
                                    yyvsp[-3]->left = yyvsp[-1] ;
                                  }
#line 1539 "y.tab.c"
    break;

  case 27: /* BrkStmt: BRKP ';'  */
#line 115 "t_1.y"
                                  {yyval = (YYSTYPE) createTree(0,-1,BRKP,BRKP,NULL,NULL,NULL);}
#line 1545 "y.tab.c"
    break;

  case 28: /* Input: READ '(' ID ')' ';'  */
#line 117 "t_1.y"
                                  {
                                    yyval = (YYSTYPE) createTree(0,-1,READ,INT,NULL,yyvsp[-2],NULL); 
                                    printf("[%#x %d] ",yyval,yyvsp[-2]->nodeType);
                                  }
#line 1554 "y.tab.c"
    break;

  case 29: /* Input: READ '(' ArrEl ')' ';'  */
#line 121 "t_1.y"
                                  {
                                    yyval = (YYSTYPE) createTree(0,-1,READ,INT,NULL,yyvsp[-2],NULL); 
                                    printf("[%#x %d] ",yyval,yyvsp[-2]->nodeType);
                                  }
#line 1563 "y.tab.c"
    break;

  case 30: /* Output: WRITE '(' E ')' ';'  */
#line 126 "t_1.y"
                                  {
                                    yyval = (YYSTYPE) createTree(0,-1,WRITE,INT,NULL,yyvsp[-2],NULL); 
                                    // printf("[%#x %d] ",$$,$3->nodeType);
                                  }
#line 1572 "y.tab.c"
    break;

  case 31: /* Asgmt: ID EQ E ';'  */
#line 131 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,'=',EQ,EQ,NULL,yyvsp[-3],yyvsp[-1]);}
#line 1578 "y.tab.c"
    break;

  case 32: /* Asgmt: ArrEl EQ E ';'  */
#line 132 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,'=',EQ,EQ,NULL,yyvsp[-3],yyvsp[-1]);}
#line 1584 "y.tab.c"
    break;

  case 33: /* E: E OP2 E  */
#line 134 "t_1.y"
                                    {
                                      if((yyvsp[-2]->type==INT||yyvsp[-2]->type==ID)&& yyvsp[0]->type==INT||yyvsp[0]->type==ID)
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
#line 1602 "y.tab.c"
    break;

  case 34: /* E: E OP E  */
#line 147 "t_1.y"
                                    {
                                      if((yyvsp[-2]->type==INT||yyvsp[-2]->type==ID) && (yyvsp[0]->type==INT||yyvsp[0]->type==ID))
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
#line 1620 "y.tab.c"
    break;

  case 35: /* E: E LT E  */
#line 160 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,LT,RELOP,BOOL,NULL,yyvsp[-2],yyvsp[0]);}
#line 1626 "y.tab.c"
    break;

  case 36: /* E: E GT E  */
#line 161 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,GT,RELOP,BOOL,NULL,yyvsp[-2],yyvsp[0]);}
#line 1632 "y.tab.c"
    break;

  case 37: /* E: E EE E  */
#line 162 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,EE,RELOP,BOOL,"==",yyvsp[-2],yyvsp[0]);}
#line 1638 "y.tab.c"
    break;

  case 38: /* E: E NE E  */
#line 163 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,NE,RELOP,BOOL,"!=",yyvsp[-2],yyvsp[0]);}
#line 1644 "y.tab.c"
    break;

  case 39: /* E: E LTE E  */
#line 164 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,LTE,RELOP,BOOL,"<=",yyvsp[-2],yyvsp[0]);}
#line 1650 "y.tab.c"
    break;

  case 40: /* E: E GTE E  */
#line 165 "t_1.y"
                                    {yyval = (YYSTYPE) createTree(0,GTE,RELOP,BOOL,">=",yyvsp[-2],yyvsp[0]);}
#line 1656 "y.tab.c"
    break;

  case 41: /* E: ID  */
#line 166 "t_1.y"
                                    {yyval = yyvsp[0]; }
#line 1662 "y.tab.c"
    break;

  case 42: /* E: NUM  */
#line 167 "t_1.y"
                                    {yyval = yyvsp[0]; }
#line 1668 "y.tab.c"
    break;

  case 43: /* E: STRING  */
#line 168 "t_1.y"
                                    {yyval = yyvsp[0]; }
#line 1674 "y.tab.c"
    break;

  case 44: /* E: ArrEl  */
#line 169 "t_1.y"
                                    {yyval = yyvsp[0]; }
#line 1680 "y.tab.c"
    break;

  case 45: /* ArrEl: ID '[' E ']'  */
#line 171 "t_1.y"
                                    {
                                      yyval = yyvsp[-3]; 
                                      yyval->nodeType = ARRAY ;
                                      // printf("Array Index %d\n",$3->val) ;
                                      // $$->left = (YYSTYPE) createTree(0,-1,EXPR,EXPR,NULL,$3,NULL) ;
                                      yyval->left = yyvsp[-1] ;
                                    }
#line 1692 "y.tab.c"
    break;


#line 1696 "y.tab.c"

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

#line 182 "t_1.y"


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
    printf("[%d %c] ",Tree->nodeType,Tree->op) ;
    paren(Tree->left) ;
    paren(Tree->right) ;
  }
  printf(")"); 
  return ;
}

int getReg()
{
  for(int i=0;i<20;i+=1)
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
  if(Tree == NULL)
    return ;
  Tree->type = type ;
  assignType(Tree->left,type) ;
  assignType(Tree->right,type) ;
}

int getAddress(tnode *Node)
{
  for(int i=0;i<varEntry;i+=1)
    if(!strcmp(sTable[i].name,Node->varName))
      // if(Node->nodeType==ARRAY) 
      //   return sTable[i].address + Node->left->val ;
      // else 
        return sTable[i].address ;
  return -1 ;
}

void addSymbol(tnode *Node)
{
  if(getAddress(Node) != -1)
  {
    printf("[+] Error : Duplicate Declaration\n") ;
    exit(0) ;
  }
  // printf("Adding Variable %s %d\n",Node->varName,Node->left ? Node->left->val : 1) ;
  if(sTable == NULL)
    sTable = (GSymbol *) calloc(1,sizeof(GSymbol)) ;
  else 
    sTable = (GSymbol *) realloc(sTable,(varEntry+1)*sizeof(GSymbol)) ;
  // int size = 1 ;
  // if(Node->left!=NULL)
  //   size = Node->left->val ;
  sTable[varEntry].name = Node->varName ;
  sTable[varEntry].type = Node->type ;
  sTable[varEntry].address = varSize + 4096 ;
  sTable[varEntry].size = Node->left ? Node->left->val : 1 ;
  varSize += sTable[varEntry].size ;
  varEntry += 1 ;
}

void addSymbols(tnode *Node)
{
  if(Node==NULL)
    return ;
  if(Node->nodeType == IDDECL)
    addSymbol(Node) ;
  else 
  {
    addSymbols(Node->left) ;
    addSymbols(Node->right) ;
  }
}

int codeGen(tnode *Tree) 
{
  int p,q,s,b ;
  int l1 , l2 ;
  if(Tree==NULL)
    return -1;
  switch(Tree->nodeType)
  {
    case READ:  fprintf(target_file,"MOV R15,7\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"MOV R15,-2\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                if(Tree->left->nodeType == ARRAY)
                {  
                  Tree->left->op = READ ;
                  fprintf(target_file,"MOV R15,R%d\n",codeGen(Tree->left)) ;
                  p = codeGen(Tree->left) ;
                  // fprintf(target_file,"ADD R15,R%d\n",p); 
                }
                else
                  fprintf(target_file,"MOV R15,%d\n",getAddress(Tree->left)) ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"INT 6\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                if(Tree->left->nodeType == ARRAY)
                  freeReg(p) ;
                return -1 ;
                break ;
    case WRITE: fprintf(target_file,"MOV R15,5\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"MOV R15,-1\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                p = codeGen(Tree->left) ;
                fprintf(target_file,"MOV R15,R%d\n",p) ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"INT 7\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                freeReg(p) ;
                return -1 ;
                break ;
    case NUM :  p = getReg() ;
                fprintf(target_file,"MOV R%d, %d\n",p,Tree->val) ;
                return p ;
                break ;
    case STRING:p = getReg() ;
                fprintf(target_file,"MOV R%d, %s\n",p,Tree->varName) ;
                return p ;
                break ;
    /*case DECL  :p = codeGen(Tree->left) ;
                q = codeGen(Tree->right) ;
                break ;
    case IDLIST:printf("IDLIST LEFT  : %d\n",Tree->left->nodeType) ;
                printf("IDLIST RIGHT : %d\n",Tree->right->nodeType) ;
                p = codeGen(Tree->left) ;
                q = codeGen(Tree->right) ;
                break ;
    case IDDECL:printf("Add %s %d\n",Tree->varName,Tree->nodeType) ;
                addSymbol(Tree) ;
                break ;*/
    case ID :   p = getReg() ;
                fprintf(target_file,"MOV R%d, [%d]\n",p,getAddress(Tree)) ;
                return p ;
                break ;
    case ARRAY: p = getReg() ;
                q = codeGen(Tree->left) ;
                fprintf(target_file,"MOV R%d, %d\n",p,getAddress(Tree)) ;
                fprintf(target_file,"ADD R%d, R%d\n",p,q) ;
                if(Tree->op != READ && Tree->op != EQ) 
                  fprintf(target_file,"MOV R%d, [R%d]\n",p,p) ;
                freeReg(q) ;
                return p ;
                break ;
    case OP2 :
    case OP :   p = codeGen(Tree->left) ;
                q = codeGen(Tree->right) ;
                s = p ; 
                b = q ;
                // s = p ; b = q ;
                printf("[OP [%d %d] %d %d %c] \n",s,b,Tree->left->val,Tree->right->val,Tree->op) ;
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
    case RELOP :p = codeGen(Tree->left) ;
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
    case WHILE :l1 = label++ ;
                l2 = label++ ;
                fprintf(target_file,"_L%d:\n",l1) ;
                p = codeGen(Tree->left) ;
                fprintf(target_file,"JZ R%d,_L%d\n",p,l2) ;
                q = codeGen(Tree->right) ;
                fprintf(target_file,"JMP _L%d\n",l1) ;
                fprintf(target_file,"_L%d:\n",l2) ;
                  freeReg(p) ;
                break ;
    case IF   :   l1 = label++ ;
                  // l2 = label++ ;
                  // l3 = label++ ;
                  p = codeGen(Tree->left) ;
                  fprintf(target_file,"JZ R%d,_L%d\n",p,l1) ;
                  q = codeGen(Tree->right) ;
                  fprintf(target_file,"_L%d:\n",l1) ;
                  freeReg(p) ;
                  break ;
    case IFTHEN : l1 = label++ ;
                  l2 = label++ ;
                  // l3 = label++ ;
                  p = codeGen(Tree->left) ;
                  fprintf(target_file,"JZ R%d,_L%d\n",p,l1) ;
                  q = codeGen(Tree->right->left) ;
                  fprintf(target_file,"JMP _L%d\n",l2) ;
                  fprintf(target_file,"_L%d:\n",l1) ;
                  q = codeGen(Tree->right->right) ;
                  fprintf(target_file,"_L%d:\n",l2) ;
                  freeReg(p) ;
                  break ;
    case EQ :   q = codeGen(Tree->right) ;
                printf("[%c %d] \n",Tree->right->op,q) ;
                if(Tree->left->nodeType != ARRAY) 
                  fprintf(target_file,"MOV [%d],R%d\n",getAddress(Tree->left),q)  ;
                else
                {
                  Tree->left->op = EQ ;
                  p = codeGen(Tree->left) ;
                  fprintf(target_file,"MOV [R%d], R%d\n",p,q) ;
                }
                freeReg(q) ;
                return -1 ;
                break ;
    case BRKP : fprintf(target_file,"BRKP\n") ;
    case Connector: p = codeGen(Tree->left) ;
                    q = codeGen(Tree->right) ; 
                    return -1 ; 
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
