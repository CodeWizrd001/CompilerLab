%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "custom.h"

    int getReg(void) ;
    void freeReg(int) ;

    int codeGen(tnode *Tree) ;
    void paren(tnode *Tree) ;
    void post(tnode *Tree) ;
    void pre(tnode *Tree) ;
    
    FILE *target_file ;
    int REG[20] ;
%}

%token NUM OP OP2 NEWLINE

%left OP2
%left OP

%%

start : expr NEWLINE  {
                        printf("\nComplete\n");
                        //paren($1) ;
                        codeGen($1) ;
                        post($1) ;
                        printf("\n") ;
                        pre($1) ;
                        printf("\n") ;
                        exit(1);
                      }
  ;

expr: OP expr expr           {
                              $2->left = $1 ;
                              $2->right = $3 ;
                              $$ = $2 ;
                            }
  | OP2 expr expr            {
                              $2->left = $1 ;
                              $2->right = $3 ;
                              $$ = $2 ;
                            }
  | '(' expr ')'            {$$ = $2;}
  | NUM                     {
                              //printf("%d ",$1);
                              $$=$1;
                            }
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
    printf("[%d %c] ",Tree->val,Tree->op) ;
    paren(Tree->left) ;
    paren(Tree->right) ;
  }
  printf(")"); 
  return ;
}

void post(tnode *Tree) 
{
  if(Tree==NULL) 
    return ;
  post(Tree->left) ;
  post(Tree->right) ;
  if(Tree->op==0)
    printf("%d",Tree->val) ;
  else 
    printf("%c",Tree->op) ;
}

void pre(tnode *Tree) 
{
  if(Tree==NULL) 
    return ;
  if(Tree->op==0)
    printf("%d",Tree->val) ;
  else 
    printf("%c",Tree->op) ;
  post(Tree->left) ;
  post(Tree->right) ;
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

int codeGen(tnode *Tree) 
{
  if(Tree == NULL)
    return 0 ;
  if(Tree->left==NULL&&Tree->right==NULL)
  {
    int p = getReg() ;
    fprintf(target_file,"MOV R%d, %d\n",p,Tree->val) ;
    return p ;
  }
  else 
  {
    int p = codeGen(Tree->left) ;
    int q = codeGen(Tree->right) ;
    int s = p ; 
    int b = q ;
    // s = p ; b = q ;
    switch(Tree->op)
    {
      case '+' :Tree->val = Tree->left->val + Tree->right->val ;
                fprintf(target_file,"ADD R%d, R%d\n",s,b) ;
                break ;
      case '-' :Tree->val = Tree->left->val - Tree->right->val ;
                fprintf(target_file,"SUB R%d, R%d\n",s,b) ;
                break ;
      case '*' :Tree->val = Tree->left->val * Tree->right->val ;
                fprintf(target_file,"MUL R%d, R%d\n",s,b) ;
                break ;
      case '/' :Tree->val = Tree->left->val / Tree->right->val ;
                fprintf(target_file,"DIV R%d, R%d\n",s,b) ;
                break ;
      default  :break ;
    }
    freeReg(b) ;
    return s ;
  }
}

int main(int argc,char **argv)
{
  if(argc==2)
    target_file = fopen(argv[1],"w") ;
  else 
    target_file = stdout ;
  
  for(int i=0;i<20;i+=1)
    REG[i] = 0 ;

  fprintf(target_file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0); 
  yyparse();
  return 1;
}