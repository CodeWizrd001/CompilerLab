%{
    #include <stdio.h>
    #include <stdlib.h>
    
    #include "custom.h"
    #include "tree.h"

    void paren(tnode *Tree) ;

    int getReg(void) ;
    void freeReg(int) ;

    int codeGen(tnode *Tree) ;

    FILE *target_file ;
    int REG[20] ;
    int addr[26] ;
%}

%token NEWLINE BEGIN_ END_ READ WRITE ID OP2 OP NUM EQ

%left OP
%left OP2

%%

program : BEGIN_ Slist END_ ';'   {
                                    printf("Completed\n");
                                    paren($2) ;
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
                                    printf("[%#x %d] ",$$,$3->nodeType);
                                  }
  ;
Output  : WRITE '(' E ')' ';'     {
                                    $$ = (YYSTYPE) createTree(0,-1,WRITE,NULL,$3,NULL); 
                                    printf("[%#x %d] ",$$,$3->nodeType);
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

int main(int argc,char **argv)
{
  if(argc==2)
    target_file = fopen(argv[1],"w") ;
  else 
    target_file = stdout ;
  
  for(int i=0;i<20;i+=1)
    REG[i] = 0 ;
  for(int i=0;i<26;i+=1)
    addr[i] = 4096 + i ;
  
  yyparse();
  return 1;
}