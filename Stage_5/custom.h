typedef struct ParamStruct {
    char *name ;
    int type ;
    struct ParamStruct *next ;
} ParamStruct ;

typedef struct GSymbol  {
    char *name ;
    int type ;
    int size ;
    int address ;
    ParamStruct *paramList ;
    int flabel ;
    struct GSymbol *next ;
} GSymbol ;

typedef struct LSymbol {
    char *name ;
    int type ;
    int size ;
    int address ;
    struct LSymbol *next ;
} LSymbol ;

typedef struct tnode{
    int val ;
    int op ;
    int type ;
    char *varName ;
    int nodeType ;
    LSymbol *sTable ;
    struct tnode *left,*right ;
} tnode;

#define YYSTYPE tnode*
#define Connector -1
#define RELOP -2

#define TRUE 1
#define FALSE 0