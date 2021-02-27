typedef struct tnode{
    int val ;
    char op ;
    char *varName ;
    int nodeType ;
    struct tnode *left,*right ;
} tnode;
    
#define YYSTYPE tnode*
#define Connector -1