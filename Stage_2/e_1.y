%{
    #include <stdio.h>
    #include <stdlib.h>
    
    #include "custom.h"
    #include "tree.h"

    void paren(tnode *Tree) ;

    int getReg(void) ;
    void freeReg(int) ;

    int eval(tnode *Tree) ;

    FILE *input_file = NULL ;
    int REG[20] ;
    int addr[26] ;
    int val[26] ;
%}

%token NEWLINE BEGIN_ END_ READ WRITE ID OP2 OP NUM EQ

%left OP
%left OP2

%%

program : BEGIN_ Slist END_ ';'   {
                                    printf("Evaluating\n");
                                    // paren($2) ;
                                    eval($2) ;
                                    exit(0);
                                  }
        | BEGIN_ END_ ';'         {
                                    printf("NULL\n");
                                    exit(0);
                                  }
  ;
Slist   : Slist Stmt      {$$ = (YYSTYPE) createTree(0,-1,Connector,NULL,$1,$2); }
        | Stmt            {$$ = $1; }
  ;
Stmt    : Input           {$$ = $1;}
        | Output          {$$ = $1;}
        | Asgmt           {$$ = $1;}
  ;
Input   : READ '(' ID ')' ';'     {
                                    $$ = (YYSTYPE) createTree(0,-1,READ,NULL,$3,NULL);
                                  }
  ;
Output  : WRITE '(' E ')' ';'     {
                                    $$ = (YYSTYPE) createTree(0,-1,WRITE,NULL,$3,NULL);
                                  }
  ;
Asgmt   : ID EQ E ';'     {$$ = (YYSTYPE) createTree(0,'=',EQ,NULL,$1,$3); }
  ;
E       : E OP2 E         {$$ = $2; $$->left = $1; $$->right = $3; }
        | E OP E          {$$ = $2; $$->left = $1; $$->right = $3; }
        | ID              {$$ = $1; }
        | NUM             {$$ = $1; }
  ;

%%

void yyerror(char const *s)
{
    printf("yyerror  %s\n",s);
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

int eval(tnode *Tree) 
{
  int p,q,s,b ;
  if(Tree==NULL)
    return -1;
  switch(Tree->nodeType)
  {
    case READ:  fscanf(input_file,"%d",val + *(Tree->left->varName)-'a') ;
                Tree->val = val[*(Tree->left->varName)-'a'] ;
                // printf("Scanned %c %d\n",*(Tree->left->varName),val[*(Tree->left->varName)-'a']) ;
                return -1 ;
                break ;
    case WRITE: eval(Tree->left) ;
                printf(" %d\n",Tree->left->val) ;
                return -1 ;
                break ;
    case NUM :  break ;
    case ID :   break ;
    case OP2 :
    case OP :   p = eval(Tree->left) ;
                q = eval(Tree->right) ;
                s = Tree->left->val ? Tree->left->val : val[*(Tree->left->varName)-'a'] ; 
                b = Tree->right->val ? Tree->right->val : val[*(Tree->right->varName)-'a'] ; 
                // s = p ; b = q ;
                // printf("Vals[%d %d] ",s,b) ;
                switch(Tree->op)
                {
                  case '+' :Tree->val = s + b ;
                            break ;
                  case '-' :Tree->val = s - b ;
                            break ;
                  case '*' :Tree->val = s * b ;
                            break ;
                  case '/' :Tree->val = s / b ;
                            break ;
                  default  :break ;
                }
                // printf("[%c %d] \n",Tree->op,Tree->val) ;
                freeReg(b) ;
                return s ;
                break ;
    case EQ :   q = eval(Tree->right) ;
                Tree->val = Tree->right->val ;
                val[*(Tree->left->varName)-'a'] = Tree->val ;
                // printf("[%c %d] \n",*(Tree->left->varName),Tree->val) ;
                return -1 ;
                break ;
    case Connector: p = eval(Tree->left) ;
                    q = eval(Tree->right) ; 
                    return -1 ; 
                    break ;
    default :   break ;
  }
  return -1 ;
}

int main(int argc,char **argv)
{
  input_file = fopen("input","r") ;
  
  for(int i=0;i<20;i+=1)
    REG[i] = 0 ;
  for(int i=0;i<26;i+=1)
    addr[i] = 4096 + i ;
  
  yyparse();
  return 1;
}