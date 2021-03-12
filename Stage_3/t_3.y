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
    int label = 0 ;
    int l1 , l2 ;
%}

%token BRKP NEWLINE BEGIN_ END_ READ WRITE ID OP2 OP NUM EQ IF THEN ELSE ENDIF IFTHEN WHILE DO ENDWHILE
%token LT GT LTE GTE EE NE

%left OP
%left OP2

%nonassoc LT GT EE NE LTE GTE EQ 

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
IfStmt  : IF '(' E ')' THEN Slist ELSE Slist ENDIF ';'  {
                                                          YYSTYPE Temp = (YYSTYPE) createTree(0,-1,IFTHEN,IFTHEN,NULL,$6,$8);
                                                          $$ = (YYSTYPE) createTree(0,-1,IFTHEN,IF,NULL,$3,Temp) ;
                                                        }
        | IF '(' E ')' THEN Slist ENDIF ';'             {$$ = (YYSTYPE) createTree(0,-1,IF,IF,NULL,$3,$6);}
        ;
WhStmt  : WHILE '(' E ')' DO Slist ENDWHILE ';'   {
                                                    printf("%d\n",$6->nodeType) ;
                                                    $$ = (YYSTYPE) createTree(0,-1,WHILE,WHILE,NULL,$3,$6);}
        ;
Slist   : Slist Stmt                {$$ = (YYSTYPE) createTree(0,-1,Connector,Connector,NULL,$1,$2);}
        | Stmt                      {$$ = $1;}
        ;
Stmt    : Input                     {$$ = $1;}
        | Output                    {$$ = $1;}
        | Asgmt                     {$$ = $1;}
        | IfStmt                    {$$ = $1;}
        | WhStmt                    {$$ = $1;}
        | BrkStmt                   {$$ = $1;}
        ;
BrkStmt : BRKP ';'                {$$ = (YYSTYPE) createTree(0,-1,BRKP,BRKP,NULL,NULL,NULL);}
        ;
Input   : READ '(' ID ')' ';'     {
                                    $$ = (YYSTYPE) createTree(0,-1,READ,INT,NULL,$3,NULL); 
                                    printf("[%#x %d] ",$$,$3->nodeType);
                                  }
        ;
Output  : WRITE '(' E ')' ';'     {
                                    $$ = (YYSTYPE) createTree(0,-1,WRITE,INT,NULL,$3,NULL); 
                                    printf("[%#x %d] ",$$,$3->nodeType);
                                  }
        ;
Asgmt   : ID EQ E ';'               {$$ = (YYSTYPE) createTree(0,'=',EQ,EQ,NULL,$1,$3);}
        ;
E       : E OP2 E                   {
                                      if($1->type==INT &&  $3->type==INT)
                                      {
                                        $$ = $2;
                                        $$->left = $1; 
                                        $$->right = $3; 
                                      }
                                      else 
                                      {
                                        printf("Type Mismatch\n") ;
                                        exit(0) ;
                                      }
                                    }
        | E OP E                    {
                                      if($1->type==INT &&  $3->type==INT)
                                      {
                                        $$ = $2;
                                        $$->left = $1; 
                                        $$->right = $3; 
                                      }
                                      else 
                                      {
                                        printf("Type Mismatch\n") ;
                                        exit(0) ;
                                      }
                                    }
        | ID                        {$$ = $1; }
        | NUM                       {$$ = $1; }
        | E LT E                    {$$ = (YYSTYPE) createTree(0,LT,RELOP,BOOL,NULL,$1,$3);}
        | E GT E                    {$$ = (YYSTYPE) createTree(0,GT,RELOP,BOOL,NULL,$1,$3);}
        | E EE E                    {$$ = (YYSTYPE) createTree(0,EE,RELOP,BOOL,"==",$1,$3);}
        | E NE E                    {$$ = (YYSTYPE) createTree(0,NE,RELOP,BOOL,"!=",$1,$3);}
        | E LTE E                   {$$ = (YYSTYPE) createTree(0,LTE,RELOP,BOOL,"<=",$1,$3);}
        | E GTE E                   {$$ = (YYSTYPE) createTree(0,GTE,RELOP,BOOL,">=",$1,$3);}
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
                break ;
    case WHILE :l1 = label++ ;
                l2 = label++ ;
                fprintf(target_file,"_L%d:\n",l1) ;
                p = codeGen(Tree->left) ;
                fprintf(target_file,"JZ R%d,_L%d\n",p,l2) ;
                q = codeGen(Tree->right) ;
                fprintf(target_file,"JMP _L%d\n",l1) ;
                fprintf(target_file,"_L%d:\n",l2) ;
                break ;
    case EQ :   q = codeGen(Tree->right) ;
                printf("[%c %d] \n",Tree->right->op,q) ;
                fprintf(target_file,"MOV [%d],R%d\n",addr[*(Tree->left->varName)-'a'],q)  ;
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
  for(int i=0;i<26;i+=1)
    addr[i] = 4096 + i ;
  
  fprintf(target_file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0); 
  fprintf(target_file,"MOV SP,4122\nMOV BP,4122\n");
  yyparse();
  return 1;
}