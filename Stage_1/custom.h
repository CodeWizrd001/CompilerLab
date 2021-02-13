typedef struct tnode{
    int val;
    char op; //indicates the name of the operator for a non leaf node
    struct tnode *left,*right; //left and right branches
} tnode;
    
#define YYSTYPE tnode*