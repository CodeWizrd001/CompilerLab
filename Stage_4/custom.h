typedef struct tnode{
    int val ;
    int op ;
    int type ;
    char *varName ;
    int nodeType ;
    struct tnode *left,*right ;
} tnode;

typedef struct GSymbol  {
    char *name ;
    int type ;
    int size ;
    int address ;
    struct GSymbol *next ;
} GSymbol ;

#define YYSTYPE tnode*
#define Connector -1
#define RELOP -2

#define TRUE 1
#define FALSE 0