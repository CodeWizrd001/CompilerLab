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
                                    // paren($2) ;
                                    codeGen($2) ;
                                    fprintf(target_file,"INT 10\n") ;
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

int codeGen(tnode *Tree) 
{
  int p,q,s,b ;
  if(Tree==NULL)
    return -1;
  switch(Tree->nodeType)
  {
    case READ:  fprintf(target_file,"MOV R15,7\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"MOV R15,-2\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"MOV R15,%d\n",addr[*(Tree->left->varName)-'a']) ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"INT 6\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                return -1 ;
                break ;
    case WRITE: fprintf(target_file,"MOV R15,5\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"MOV R15,-1\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"MOV R15,R%d\n",codeGen(Tree->left)) ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"INT 7\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                return -1 ;
                break ;
    case NUM :  p = getReg() ;
                fprintf(target_file,"MOV R%d, %d\n",p,Tree->val) ;
                return p ;
                break ;
    case ID :   p = getReg() ;
                fprintf(target_file,"MOV R%d, [%d]\n",p,addr[*(Tree->varName)-'a']) ;
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
                  default  :break ;
                }
                freeReg(b) ;
                return s ;
                break ;
    case EQ :   q = codeGen(Tree->right) ;
                printf("[%c %d] \n",Tree->right->op,q) ;
                fprintf(target_file,"MOV [%d],R%d\n",addr[*(Tree->left->varName)-'a'],q)  ;
                return -1 ;
                break ;
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
  for(int i=0;i<26;i+=1)
    addr[i] = 4096 + i ;
  
  fprintf(target_file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0); 
  fprintf(target_file,"MOV SP,4122\nMOV BP,4122\n");
  yyparse();
  return 1;
}