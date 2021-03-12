typedef struct tnode{
    int val ;
    int op ;
    int type ;
    char *varName ;
    int nodeType ;
    struct tnode *left,*right ;
} tnode;
    
#define YYSTYPE tnode*
#define Connector -1
#define RELOP -2

#define TRUE 1
#define FALSE 0

#define INT 1
#define BOOL 2