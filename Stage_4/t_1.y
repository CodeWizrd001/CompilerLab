%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    #include "custom.h"
    #include "tree.h"

    void paren(tnode *Tree) ;

    int getReg(void) ;
    void freeReg(int) ;

    int codeGen(tnode *Tree) ;

    void addSymbols(tnode *Tree) ;
    void addSymbol(tnode *Tree) ;
    int getSymbol(char *name) ;

    void assignType(tnode *Tree,int type) ;
    int getAddress(tnode *Node) ;

    FILE *target_file ;
    int REG[20] ;
    int varSize = 0 ;
    int varEntry = 0 ;
    GSymbol *sTable = NULL ;
    int label = 0 ;
%}

%token BRKP NEWLINE BEGIN_ END_ READ WRITE ID OP2 OP NUM EQ IF THEN ELSE ENDIF IFTHEN WHILE DO ENDWHILE
%token LT GT LTE GTE EE NE
%token DECL ENDDECL IDDECL EXPR
%token INT BOOL STR TYPE IDLIST STRING ARRAY

%nonassoc LT GT EE NE LTE GTE EQ

%left OP
%left OP2



%%

program : BEGIN_ Slist END_ ';'   {
                                    printf("Completed\n");
                                    // paren($2) ;
                                    fprintf(target_file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0); 
                                    fprintf(target_file,"MOV SP,%d\nMOV BP,%d\n",4096+varSize,4096+varSize);
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
                                                    // printf("%d\n",$6->nodeType) ;
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
        | Declarations              {$$ = $1;}
        ;
Declarations: DECL Declist ENDDECL ';'  {
                                          $$ = (YYSTYPE) createTree(0,-1,DECL,DECL,NULL,$2,NULL);
                                        }
            | DECL ENDDECL ';'    {$$ = (YYSTYPE) createTree(0,-1,DECL,0,NULL,NULL,NULL);}
            ;
Declist : Declist Decl            {$$ = (YYSTYPE) createTree(0,-1,DECL,Connector,NULL,$1,$2);}
        | Decl                    {$$ = $1 ;}
        ;
Decl    : Type Varlist ';'        {
                                    assignType($2,$1->type) ;
                                    $$ = (YYSTYPE) createTree(0,-1,DECL,DECL,NULL,$1,$2);
                                    $$ = NULL ;
                                    addSymbols($2) ;
                                  }
        ;
Type    : INT                     {$$ = (YYSTYPE) createTree(0,-1,TYPE,INT,NULL,NULL,NULL);}
        | STR                     {$$ = (YYSTYPE) createTree(0,-1,TYPE,STR,NULL,NULL,NULL);}
        | BOOL                    {$$ = (YYSTYPE) createTree(0,-1,TYPE,BOOL,NULL,NULL,NULL);}
        ;
Varlist : Varlist ',' ID          {
                                    $3->nodeType = IDDECL ;
                                    $$ = (YYSTYPE) createTree(0,-1,IDLIST,IDLIST,NULL,$1,$3);
                                  }
        | ID                      {
                                    $1->nodeType = IDDECL ;
                                    $$ = $1 ;
                                    // printf("VAR %s %d\n",$$->varName,$$->type);
                                  }
        | ID '[' NUM ']'          {
                                    $1->nodeType = IDDECL ;
                                    $1->type = ARRAY ;
                                    // $1->left = (YYSTYPE) createTree(0,-1,EXPR,EXPR,NULL,$3,NULL) ;
                                    $1->left = $3 ;
                                  }
        ;
BrkStmt : BRKP ';'                {$$ = (YYSTYPE) createTree(0,-1,BRKP,BRKP,NULL,NULL,NULL);}
        ;
Input   : READ '(' ID ')' ';'     {
                                    $$ = (YYSTYPE) createTree(0,-1,READ,INT,NULL,$3,NULL); 
                                    printf("[%#x %d] ",$$,$3->nodeType);
                                  }
        | READ '(' ArrEl ')' ';'  {
                                    $$ = (YYSTYPE) createTree(0,-1,READ,INT,NULL,$3,NULL); 
                                    printf("[%#x %d] ",$$,$3->nodeType);
                                  }
        ;
Output  : WRITE '(' E ')' ';'     {
                                    $$ = (YYSTYPE) createTree(0,-1,WRITE,INT,NULL,$3,NULL); 
                                    // printf("[%#x %d] ",$$,$3->nodeType);
                                  }
        ;
Asgmt   : ID EQ E ';'               {$$ = (YYSTYPE) createTree(0,'=',EQ,EQ,NULL,$1,$3);}
        | ArrEl EQ E ';'            {$$ = (YYSTYPE) createTree(0,'=',EQ,EQ,NULL,$1,$3);}
        ;
E       : E OP2 E                   {
                                      if(($1->type==INT||$1->type==ID)&& $3->type==INT||$3->type==ID)
                                      {
                                        $$ = $2;
                                        $$->left = $1; 
                                        $$->right = $3; 
                                      }
                                      else 
                                      {
                                        printf("Type Mismatch %d %d %c\n",$1->type,$3->type,$2->op) ;
                                        exit(0) ;
                                      }
                                    }
        | E OP E                    {
                                      if(($1->type==INT||$1->type==ID) && ($3->type==INT||$3->type==ID))
                                      {
                                        $$ = $2;
                                        $$->left = $1; 
                                        $$->right = $3; 
                                      }
                                      else 
                                      {
                                        printf("Type Mismatch %c\n",$2->op) ;
                                        exit(0) ;
                                      }
                                    }
        | E LT E                    {$$ = (YYSTYPE) createTree(0,LT,RELOP,BOOL,NULL,$1,$3);}
        | E GT E                    {$$ = (YYSTYPE) createTree(0,GT,RELOP,BOOL,NULL,$1,$3);}
        | E EE E                    {$$ = (YYSTYPE) createTree(0,EE,RELOP,BOOL,"==",$1,$3);}
        | E NE E                    {$$ = (YYSTYPE) createTree(0,NE,RELOP,BOOL,"!=",$1,$3);}
        | E LTE E                   {$$ = (YYSTYPE) createTree(0,LTE,RELOP,BOOL,"<=",$1,$3);}
        | E GTE E                   {$$ = (YYSTYPE) createTree(0,GTE,RELOP,BOOL,">=",$1,$3);}
        | ID                        {$$ = $1; }
        | NUM                       {$$ = $1; }
        | STRING                    {$$ = $1; }
        | ArrEl                     {$$ = $1; }
        ;
ArrEl   : ID '[' E ']'              {
                                      $$ = $1; 
                                      $$->nodeType = ARRAY ;
                                      // printf("Array Index %d\n",$3->val) ;
                                      // $$->left = (YYSTYPE) createTree(0,-1,EXPR,EXPR,NULL,$3,NULL) ;
                                      $$->left = $3 ;
                                    }
        ;

  

%%

void yyerror(char const *s)
{
    printf("yyerror %c %s\n",yychar,s);
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

void assignType(tnode *Tree,int type)
{
  if(Tree == NULL)
    return ;
  Tree->type = type ;
  assignType(Tree->left,type) ;
  assignType(Tree->right,type) ;
}

int getAddress(tnode *Node)
{
  for(int i=0;i<varEntry;i+=1)
    if(!strcmp(sTable[i].name,Node->varName))
      // if(Node->nodeType==ARRAY) 
      //   return sTable[i].address + Node->left->val ;
      // else 
        return sTable[i].address ;
  return -1 ;
}

void addSymbol(tnode *Node)
{
  if(getAddress(Node) != -1)
  {
    printf("[+] Error : Duplicate Declaration\n") ;
    exit(0) ;
  }
  // printf("Adding Variable %s %d\n",Node->varName,Node->left ? Node->left->val : 1) ;
  if(sTable == NULL)
    sTable = (GSymbol *) calloc(1,sizeof(GSymbol)) ;
  else 
    sTable = (GSymbol *) realloc(sTable,(varEntry+1)*sizeof(GSymbol)) ;
  // int size = 1 ;
  // if(Node->left!=NULL)
  //   size = Node->left->val ;
  sTable[varEntry].name = Node->varName ;
  sTable[varEntry].type = Node->type ;
  sTable[varEntry].address = varSize + 4096 ;
  sTable[varEntry].size = Node->left ? Node->left->val : 1 ;
  varSize += sTable[varEntry].size ;
  varEntry += 1 ;
}

void addSymbols(tnode *Node)
{
  if(Node==NULL)
    return ;
  if(Node->nodeType == IDDECL)
    addSymbol(Node) ;
  else 
  {
    addSymbols(Node->left) ;
    addSymbols(Node->right) ;
  }
}

int codeGen(tnode *Tree) 
{
  int p,q,s,b ;
  int l1 , l2 ;
  if(Tree==NULL)
    return -1;
  switch(Tree->nodeType)
  {
    case READ:  fprintf(target_file,"MOV R15,7\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"MOV R15,-2\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                if(Tree->left->nodeType == ARRAY)
                {  
                  Tree->left->op = READ ;
                  fprintf(target_file,"MOV R15,R%d\n",codeGen(Tree->left)) ;
                  p = codeGen(Tree->left) ;
                  // fprintf(target_file,"ADD R15,R%d\n",p); 
                }
                else
                  fprintf(target_file,"MOV R15,%d\n",getAddress(Tree->left)) ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"INT 6\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                if(Tree->left->nodeType == ARRAY)
                  freeReg(p) ;
                return -1 ;
                break ;
    case WRITE: fprintf(target_file,"MOV R15,5\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"MOV R15,-1\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                p = codeGen(Tree->left) ;
                fprintf(target_file,"MOV R15,R%d\n",p) ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"PUSH R15\n") ;
                fprintf(target_file,"INT 7\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                fprintf(target_file,"POP R15\n") ;
                freeReg(p) ;
                return -1 ;
                break ;
    case NUM :  p = getReg() ;
                fprintf(target_file,"MOV R%d, %d\n",p,Tree->val) ;
                return p ;
                break ;
    case STRING:p = getReg() ;
                fprintf(target_file,"MOV R%d, %s\n",p,Tree->varName) ;
                return p ;
                break ;
    /*case DECL  :p = codeGen(Tree->left) ;
                q = codeGen(Tree->right) ;
                break ;
    case IDLIST:printf("IDLIST LEFT  : %d\n",Tree->left->nodeType) ;
                printf("IDLIST RIGHT : %d\n",Tree->right->nodeType) ;
                p = codeGen(Tree->left) ;
                q = codeGen(Tree->right) ;
                break ;
    case IDDECL:printf("Add %s %d\n",Tree->varName,Tree->nodeType) ;
                addSymbol(Tree) ;
                break ;*/
    case ID :   p = getReg() ;
                fprintf(target_file,"MOV R%d, [%d]\n",p,getAddress(Tree)) ;
                return p ;
                break ;
    case ARRAY: p = getReg() ;
                q = codeGen(Tree->left) ;
                fprintf(target_file,"MOV R%d, %d\n",p,getAddress(Tree)) ;
                fprintf(target_file,"ADD R%d, R%d\n",p,q) ;
                if(Tree->op != READ && Tree->op != EQ) 
                  fprintf(target_file,"MOV R%d, [R%d]\n",p,p) ;
                freeReg(q) ;
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
                  case '%' :fprintf(target_file,"MOD R%d, R%d\n",s,b) ;
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
                freeReg(q) ;
                break ;
    case WHILE :l1 = label++ ;
                l2 = label++ ;
                fprintf(target_file,"_L%d:\n",l1) ;
                p = codeGen(Tree->left) ;
                fprintf(target_file,"JZ R%d,_L%d\n",p,l2) ;
                q = codeGen(Tree->right) ;
                fprintf(target_file,"JMP _L%d\n",l1) ;
                fprintf(target_file,"_L%d:\n",l2) ;
                  freeReg(p) ;
                break ;
    case IF   :   l1 = label++ ;
                  // l2 = label++ ;
                  // l3 = label++ ;
                  p = codeGen(Tree->left) ;
                  fprintf(target_file,"JZ R%d,_L%d\n",p,l1) ;
                  q = codeGen(Tree->right) ;
                  fprintf(target_file,"_L%d:\n",l1) ;
                  freeReg(p) ;
                  break ;
    case IFTHEN : l1 = label++ ;
                  l2 = label++ ;
                  // l3 = label++ ;
                  p = codeGen(Tree->left) ;
                  fprintf(target_file,"JZ R%d,_L%d\n",p,l1) ;
                  q = codeGen(Tree->right->left) ;
                  fprintf(target_file,"JMP _L%d\n",l2) ;
                  fprintf(target_file,"_L%d:\n",l1) ;
                  q = codeGen(Tree->right->right) ;
                  fprintf(target_file,"_L%d:\n",l2) ;
                  freeReg(p) ;
                  break ;
    case EQ :   q = codeGen(Tree->right) ;
                printf("[%c %d] \n",Tree->right->op,q) ;
                if(Tree->left->nodeType != ARRAY) 
                  fprintf(target_file,"MOV [%d],R%d\n",getAddress(Tree->left),q)  ;
                else
                {
                  Tree->left->op = EQ ;
                  p = codeGen(Tree->left) ;
                  fprintf(target_file,"MOV [R%d], R%d\n",p,q) ;
                }
                freeReg(q) ;
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
  char fname[20] ;
  yyparse();
  return 1;
}