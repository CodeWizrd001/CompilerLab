%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    #include "custom.h"
    #include "tree.h"

    void paren(tnode *Tree) ;

    int getReg(void) ;
    void freeReg(int) ;
    void showRegs(void) ;
    void copyRegs(int *,int *) ;

    int codeGen(tnode *Tree) ;

    void addGSymbols(tnode *Tree) ;
    void addGSymbol(tnode *Tree) ;
    void showGTable(void) ;
    void showLTable(LSymbol *table) ;
    void setLTable(char *name,LSymbol *table) ;
    int getSymbol(char *name) ;
    void showParamList(ParamStruct *list) ;
    LSymbol *makeLocalTable(tnode *Node,tnode *decl) ;

    void assignType(tnode *Tree,int type) ;
    void assignTable(tnode *Tree,LSymbol *table) ;
    int getLAddress(tnode *Node) ;
    int getAddress(tnode *Node) ;
    int getLabel(tnode *Node) ;
    ParamStruct *getParams(tnode *Node) ;

    ParamStruct *makeParamlist(tnode *Tree,ParamStruct **paramList,int pars) ;
    void addParams(LSymbol *table,ParamStruct *params) ;


    FILE *target_file ;
    int REG[20] ;

    int varSize = 0 ;
    int varEntry = 0 ;
    GSymbol *sTable = NULL ;
    int label = 0 ;
    int flabel = 0 ;

    int lSize = 1 ;
    int lEntry = 0 ;

    int addr = 0 ;
%}

%token BRKP NEWLINE BEGIN_ END_ READ WRITE ID OP2 OP NUM EQ IF THEN ELSE ENDIF IFTHEN WHILE DO ENDWHILE
%token LT GT LTE GTE EE NE
%token DECL ENDDECL IDDECL EXPR MAIN RETURN ERROR 
%token INT BOOL STR TYPE IDLIST STRING ARRAY 
%token PARAM FUNCTION FDEF CALL
%token ARGLIST 

%nonassoc AND OR
%nonassoc LT GT EE NE LTE GTE EQ

%left OP2
%left OP


%%

program : GDeclBlock FDefBlock MainBlock     {
                                                // printf("GDecFDecMainBlock\n") ;
                                                fprintf(target_file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0); 
                                                fprintf(target_file,"MOV SP,%d\nMOV BP,%d\n",4096+varSize,4096+varSize+1);
                                                
                                                printf("------%15s  -----\n","Global") ;
                                                showGTable() ;
                                                printf("----------------------------\n") ;
                                                fprintf(target_file,"PUSH R0\n") ;
                                                fprintf(target_file,"CALL _MAIN\n") ;
                                                fprintf(target_file,"INT 10\n") ;
                                                codeGen($2) ;
                                                codeGen($3) ;
                                                fprintf(target_file,"INT 10\n") ;
                                                exit(0);
                                              }
        | GDeclBlock MainBlock                {
                                                // printf("GDecMainBlock\n") ;
                                                fprintf(target_file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0); 
                                                fprintf(target_file,"MOV SP,%d\nMOV BP,%d\n",4096+varSize,4096+varSize+1);
                                                
                                                printf("------%15s  -----\n","Global") ;
                                                showGTable() ;
                                                printf("----------------------------\n") ;
                                                fprintf(target_file,"CALL _MAIN\n") ;
                                                fprintf(target_file,"INT 10\n") ;
                                                codeGen($2) ;
                                                fprintf(target_file,"INT 10\n") ;
                                                exit(0);
                                              }
        | MainBlock                           {
                                                printf("MainBlock\n") ;
                                                fprintf(target_file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0); 
                                                fprintf(target_file,"MOV SP,%d\nMOV BP,%d\n",4096+varSize,4096+varSize+1);
                                                
                                                printf("------%15s  -----\n","Global") ;
                                                showGTable() ;
                                                printf("----------------------------\n") ;
                                                codeGen($1) ;
                                                fprintf(target_file,"INT 10\n") ;
                                                exit(0);
                                              }
        ;

GDeclBlock  : DECL GDeclList ENDDECL         
            | DECL ENDDECL 
            ;

GDeclList   : GDeclList GDecl                 
            | GDecl                           
            ;

GDecl       : Type GidList ';'                {
                                                assignType($2,$1->type) ;
                                                addGSymbols($2) ;
                                                $$ = $2 ;
                                              }
            ;

GidList     : GidList ',' Gid             {
                                            $$ = (YYSTYPE) createTree(0,-1,IDLIST,IDLIST,NULL,$1,$3);
                                          }
            | Gid                         {$$ = $1;}
            ;

Gid         : ID                          {
                                            $$ = $1 ;
                                          }
            | ID '[' NUM ']'              {
                                            $$ = $1 ;
                                            $$->nodeType = ARRAY ;
                                            $$->left = $3 ;
                                          }
            | ID '(' ParamList ')'        {
                                            $$ = $1 ;
                                            $$->nodeType = FUNCTION ;
                                            $$->left = $3 ;
                                          }
            ;

ParamList   : ParamList ',' Param     {
                                        $$ = $3;
                                        $$->left = $1;
                                      }
            | Param                   {$$ = $1 ;}
            |                         {printf("Empty ParList") ;}
            ;

Param       : Type ID                 {
                                        $$ = $2 ;
                                        $$->type = $1->type ;
                                        $$->nodeType = PARAM ;
                                      }
            ;

FDefBlock   : FDefBlock Fdef                {$$ = (YYSTYPE) createTree(0,-1,Connector,Connector,NULL,$1,$2);} 
            | Fdef                          {$$ = $1;}
            ;

Fdef        : Type ID '(' ParamList ')' '{' LDeclBlock LBody '}'    {
                                                                      $$ = $2 ;
                                                                      $$->type = $1->type ;
                                                                      $$->nodeType = FUNCTION ;
                                                                      $$->sTable = makeLocalTable($$,$7) ;
                                                                      $$->left = $4 ;
                                                                      $$->right = $8 ;
                                                                      assignTable($$,$$->sTable) ;
                                                                      addParams($$->sTable,getParams($$)) ;
                                                                      setLTable($$->varName,$$->sTable) ;
                                                                      
                                                                      printf("------%15s  -----\n",$$->varName) ;
                                                                      showLTable($$->sTable) ;
                                                                      printf("----------------------------\n") ;
                                                                    }
            | Type ID '(' ParamList ')' '{' LBody '}'               {
                                                                      $$ = $2 ;
                                                                      $$->type = $1->type ;
                                                                      $$->nodeType = FUNCTION ;
                                                                      $$->sTable = calloc(1,sizeof(LSymbol)) ;
                                                                      $$->sTable->name = "NULL" ;
                                                                      $$->sTable->next = NULL ;
                                                                      $$->left = $4 ;
                                                                      $$->right = $7 ;
                                                                      assignTable($$,$$->sTable) ;
                                                                      addParams($$->sTable,getParams($$)) ;
                                                                      setLTable($$->varName,$$->sTable) ;
                                                                      
                                                                      printf("------%15s  -----\n",$$->varName) ;
                                                                      showLTable($$->sTable) ;
                                                                      printf("----------------------------\n") ;
                                                                    }
            ;

LDeclBlock  : DECL LDeclList ENDDECL                  {$$ = $2 ;}
            | DECL ENDDECL                            {$$ = NULL ;}
            ;

LDeclList   : LDeclList LDecl                         {$$ = (YYSTYPE) createTree(0,-1,Connector,IDDECL,NULL,$1,$2);}
            | LDecl                                   {$$ = $1;}
            ;

LDecl       : Type Varlist ';'                        {
                                                        assignType($2,$1->type) ;
                                                        // printf("Local Table %d\n",$1->type) ;
                                                        $$ = $2 ;
                                                      }
            ;

Type    : INT                     {$$ = (YYSTYPE) createTree(0,-1,TYPE,INT,NULL,NULL,NULL);}
        | STR                     {$$ = (YYSTYPE) createTree(0,-1,TYPE,STR,NULL,NULL,NULL);}
        | BOOL                    {$$ = (YYSTYPE) createTree(0,-1,TYPE,BOOL,NULL,NULL,NULL);}
        ;

MainBlock   : INT MAIN '(' ')' '{' LDeclBlock LBody '}'             {
                                                                      $$ = (YYSTYPE) createTree(-1,-1,ID,ID,"main",NULL,NULL) ;
                                                                      $$->type = INT ;
                                                                      $$->nodeType = FUNCTION ;
                                                                      $$->sTable = makeLocalTable($$,$6) ;
                                                                      $$->right = $7 ;
                                                                      assignTable($$,$$->sTable) ;
                                                                      setLTable($$->varName,$$->sTable) ;

                                                                      // printf("------%15s  -----\n",$$->varName) ;
                                                                      // showLTable($$->sTable) ;
                                                                      // printf("----------------------------\n") ;
                                                                    }
            | INT MAIN '(' ')' '{' LBody '}'             {
                                                                      $$ = (YYSTYPE) createTree(-1,-1,ID,ID,"main",NULL,NULL) ;
                                                                      $$->type = INT ;
                                                                      $$->nodeType = FUNCTION ;
                                                                      $$->sTable = calloc(1,sizeof(LSymbol)) ;
                                                                      $$->sTable->name = "NULL" ;
                                                                      $$->right = $6 ;
                                                                      assignTable($$,$$->sTable) ;
                                                                      setLTable($$->varName,$$->sTable) ;

                                                                      // printf("------%15s  -----\n",$$->varName) ;
                                                                      // showLTable($$->sTable) ;
                                                                      // printf("----------------------------\n") ;
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

LBody   : BEGIN_ Slist END_         {$$ = $2;}
        | BEGIN_ END_               {printf("Empty Body") ;}
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
        | RetStmt                   {$$ = $1;}
        ;

Varlist : Varlist ',' ID          {
                                    $3->nodeType = IDDECL ;
                                    $$ = (YYSTYPE) createTree(0,-1,IDLIST,IDLIST,NULL,$1,$3);
                                  }
        | Varlist ',' ID '[' NUM ']'      {
                                            $3->nodeType = IDDECL ;
                                            $3->type = ARRAY ;
                                            // $1->left = (YYSTYPE) createTree(0,-1,EXPR,EXPR,NULL,$3,NULL) ;
                                            $3->left = $5 ;
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

RetStmt : RETURN E ';'            {$$ = (YYSTYPE) createTree(0,-1,RETURN,RETURN,NULL,$2,NULL) ;}
        ;

BrkStmt : BRKP ';'                {$$ = (YYSTYPE) createTree(0,-1,BRKP,BRKP,NULL,NULL,NULL);}
        ;

Input   : READ '(' ID ')' ';'     {
                                    $$ = (YYSTYPE) createTree(0,-1,READ,INT,NULL,$3,NULL); 
                                    // printf("[%#x %d] ",$$,$3->nodeType);
                                  }
        | READ '(' ArrEl ')' ';'  {
                                    $$ = (YYSTYPE) createTree(0,-1,READ,INT,NULL,$3,NULL); 
                                    // printf("[%#x %d] ",$$,$3->nodeType);
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
                                      if(($1->type==INT||$1->type==ID||$1->type==CALL) && ($3->type==INT||$3->type==ID||$3->type==CALL))
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
                                      if(($1->type==INT||$1->type==ID||$1->type==CALL) && ($3->type==INT||$3->type==ID||$3->type==CALL))
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
        | E OR E                    {$$ = (YYSTYPE) createTree(0,OR,OR,BOOL,"||",$1,$3);}
        | E AND E                   {$$ = (YYSTYPE) createTree(0,AND,AND,BOOL,"&&",$1,$3);}
        | ID                        {$$ = $1;}
        | ID '(' ')'                {$$ = (YYSTYPE) createTree(0,-1,FUNCTION,CALL,NULL,NULL,$1) ;}
        | ID '(' ArgList ')'        {$$ = (YYSTYPE) createTree(0,-1,FUNCTION,CALL,NULL,$3,$1) ;}
        | NUM                       {$$ = $1; }
        | STRING                    {$$ = $1; }
        | ArrEl                     {$$ = $1; }
        | '(' E ')'                 {$$ = $2; }
        ;
ArgList : ArgList ',' E             {
                                      $3->type = ARGLIST ;
                                      $$ = (YYSTYPE) createTree(0,-1,ARGLIST,ARGLIST,NULL,$1,$3) ;
                                      $$->val = $1->val + 1 ;
                                    }
        | E                         {
                                      $1->val = 0 ;
                                      $$ = (YYSTYPE) createTree(0,-1,ARGLIST,ARGLIST,NULL,$1,NULL) ;
                                      $$->val = $1->val + 1 ;
                                    }
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
    printf("[%d %c %s] ",Tree->nodeType,Tree->op,Tree->varName) ;
    paren(Tree->left) ;
    paren(Tree->right) ;
  }
  printf(")"); 
  return ;
}

int getReg()
{
  for(int i=1;i<19;i+=1)
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
  if(Tree == NULL||Tree->nodeType == PARAM)
    return ;
  Tree->type = type ;
  assignType(Tree->left,type) ;
  assignType(Tree->right,type) ;
}

int getAddress(tnode *Node)
{
  for(int i=0;i<varEntry;i+=1)
    if(!strcmp(sTable[i].name,Node->varName))
        return sTable[i].address ;
  return -1 ;
}

int getLabel(tnode *Node)
{
  for(int i=0;i<varEntry;i+=1)
    if(!strcmp(sTable[i].name,Node->varName))
        return sTable[i].flabel ;
  return -1 ;
}

ParamStruct *getParams(tnode *Node)
{
  for(int i=0;i<varEntry;i+=1)
    if(!strcmp(sTable[i].name,Node->varName))
        return sTable[i].paramList ;
  return -1 ;
}

int getLAddress(tnode *Node)
{
  if(Node==NULL)
    return -1 ;
  // printf("-----------\n") ;
  // showLTable(Node->sTable) ;
  // printf("-----------\n") ;
  LSymbol *sTable = Node->sTable ;
  while(sTable != NULL)
  {
    // printf("Search %10s %10s\n",sTable->name , Node->varName) ;
    if(!strcmp(sTable->name,Node->varName))
    {
      // printf("%s Returning %d\n",sTable->name,sTable->address); 
      return sTable->address ;
    }
    else 
      sTable = sTable->next ;
  }
  return -1 ;
}

void addLSymbol(LSymbol **table,tnode *Node)
{
  LSymbol *temp = NULL ;
  if(*table == NULL)
  {
    *table = calloc(1,sizeof(LSymbol)) ;
    temp = *table ;
    temp->name = Node->varName ;
    temp->type = Node->type ;
    temp->type = Node->type ;
    temp->address = lSize ;
    temp->size = Node->left ? Node->left->val : 1 ;
    temp->next = NULL ;
  }
  else 
  {
    temp = *table ;
    while(temp->next!=NULL)
      temp = temp->next ;
    temp->next = calloc(1,sizeof(LSymbol)) ;
    temp = temp->next ;
    temp->name = Node->varName ;
    temp->type = Node->type ;
    temp->address = lSize ;
    temp->size = Node->left ? Node->left->val : 1 ;
    temp->next = NULL ;
  }
  lSize += temp->size ;
  lEntry += 1 ;
}

void addLSymbols(LSymbol **table,tnode *Node)
{
  if(Node==NULL)
    return ;
  if((Node->type==INT||Node->type==STR||Node->type==BOOL)&&Node->nodeType!=IDLIST)
    addLSymbol(table,Node) ;
  else
  {
    addLSymbols(table,Node->left) ;
    addLSymbols(table,Node->right) ;
  }
}

void addParams(LSymbol *table,ParamStruct *param)
{
  int s = -3 ;
  while(table->next!=NULL)
  {
    // s += table->size ;
    table = table->next ;
  }
  while(param!=NULL)
  {
    table->next = calloc(1,sizeof(LSymbol)) ;
    table = table->next ;
    table->name = param->name ;
    table->type = param->type ;
    table->address = s ;
    table->size = 1 ;
    table->next = NULL ;
    param = param->next ;
    s -= table->size ;
  }
}

void assignTable(tnode *Tree,LSymbol *table)
{
  if(Tree == NULL)
    return ;
  Tree->sTable = table ;
  assignTable(Tree->left,table) ;
  assignTable(Tree->right,table) ;
}

void showLTable(LSymbol *table)
{
  while(table!=NULL)
    {
      printf("%10s %4d %4d %4d %#x\n",table->name,table->type,table->address,table->size,table) ;
      table = table->next ;
    }
}

void setLTable(char *name,LSymbol *table) 
{
  for(int i=0;i<varEntry;i+=1)
    if(!strcmp(sTable[i].name,name))
      sTable[i].sTable = table ;
}

LSymbol *makeLocalTable(tnode *Node,tnode *decl)
{
  if(decl == NULL)
    Node->sTable = NULL ;
  else
    addLSymbols(&(Node->sTable),decl) ;
  // printf("------%15s  -----\n",Node->varName) ;
  // showLTable(Node->sTable) ;
  // printf("----------------------------\n") ;
  lEntry = 0 ;
  lSize = 1;
  return Node->sTable ;
}

ParamStruct *makeParamlist(tnode *Node,ParamStruct **paramList,int pars)
{
  if(Node==NULL)
    return NULL ;
  if(*paramList==NULL)
    *paramList = calloc(1,sizeof(ParamStruct)) ;
  else 
    *paramList = realloc(*paramList,(pars+1)*sizeof(ParamStruct)) ;
  (*paramList)[pars].name = Node->varName ;
  (*paramList)[pars].type = Node->type ;
  (*paramList)[pars].next = NULL ;
  if(pars!=0)
    (*paramList)[pars-1].next = *paramList + pars ;
  if(Node->left==NULL)
    return *paramList ;
  else 
    return makeParamlist(Node->left,paramList,pars+1) ;
}

void addGSymbol(tnode *Node)
{
  if(getAddress(Node) != -1)
  {
    printf("[+] Error : Duplicate Declaration\n") ;
    exit(0) ;
  }
  if(sTable == NULL)
    sTable = (GSymbol *) calloc(1,sizeof(GSymbol)) ;
  else 
    sTable = (GSymbol *) realloc(sTable,(varEntry+1)*sizeof(GSymbol)) ;
  sTable[varEntry].name = Node->varName ;
  sTable[varEntry].type = Node->type ;
  if(Node->nodeType == FUNCTION)
  {
    sTable[varEntry].address = 0 ;
    sTable[varEntry].size = -1 ;
    ParamStruct *paramList = NULL ;
    sTable[varEntry].paramList = makeParamlist(Node->left,&paramList,0) ;
    sTable[varEntry].flabel = flabel++ ;
  }
  else
  {
    sTable[varEntry].flabel = -1 ;
    sTable[varEntry].address = varSize + 4096 ;
    sTable[varEntry].size = Node->left ? Node->left->val : 1 ;
    varSize += sTable[varEntry].size ;
  }
  varEntry += 1 ;
}

void addGSymbols(tnode *Node)
{
  if(Node==NULL)
    return ;
  if(Node->nodeType != IDLIST)
    addGSymbol(Node) ;
  else 
  {
    addGSymbols(Node->left) ;
    addGSymbols(Node->right) ;
  }
}

int getStackSize(LSymbol *table)
{
  int size = 0 ;
  while(table!=NULL)
  {
    size += table->size ;
    table = table->next ;
  }
  return size ;
}

void showParamList(ParamStruct *list)
{
  while(list!=NULL)
  {
    printf("\t%10s %4d\n",list->name,list->type) ;
    list = list->next ;
  }
}

void showGTable()
{
  for(int i=0;i<varEntry;i+=1)
    {
      printf("%10s %4d %4d %4d %#x %4d\n",sTable[i].name,sTable[i].type,sTable[i].address,sTable[i].size,sTable[i].paramList,sTable[i].flabel) ;
      if(sTable[i].flabel!=-1)
        showParamList(sTable[i].paramList);
    }
}

void copyRegs(int *from,int *to) 
{
  return ; 
}

void showRegs()
{
  for(int i=0;i<20;i+=1)
  {
    printf("R%d : %d\t\t",i,REG[i]) ;
    if(i%5==4)
      printf("\n") ;
  }
  printf("\n") ;
}

int codeGen(tnode *Tree) 
{
  int p,q,s,b ;
  int l1 , l2 ;
  int *regStack = NULL ;
  if(Tree==NULL)
    return -1;
  switch(Tree->nodeType)
  {
    case READ:  //printf("PRINT \n") ;
                fprintf(target_file,"MOV R19,7\n") ;
                fprintf(target_file,"PUSH R19\n") ;
                fprintf(target_file,"MOV R19,-2\n") ;
                fprintf(target_file,"PUSH R19\n") ;
                if(Tree->left->nodeType == ARRAY)
                {  
                  Tree->left->op = READ ;
                  fprintf(target_file,"MOV R19,R%d\n",codeGen(Tree->left)) ;
                  p = codeGen(Tree->left) ;
                }
                else
                {
                  addr = getLAddress(Tree->left) ;
                  if(addr!=-1)
                  {
                    fprintf(target_file,"MOV R19,BP\n") ;
                    fprintf(target_file,"ADD R19,%d\n",addr) ;
                    // fprintf(target_file,"MOV R19,[R19]\n") ;
                  }
                  else 
                    fprintf(target_file,"MOV R19,%d\n",getAddress(Tree->left)) ;
                }
                fprintf(target_file,"PUSH R19\n") ;
                fprintf(target_file,"PUSH R19\n") ;
                fprintf(target_file,"PUSH R19\n") ;
                fprintf(target_file,"INT 6\n") ;
                fprintf(target_file,"POP R19\n") ;
                fprintf(target_file,"POP R19\n") ;
                fprintf(target_file,"POP R19\n") ;
                fprintf(target_file,"POP R19\n") ;
                fprintf(target_file,"POP R19\n") ;
                if(Tree->left->nodeType == ARRAY)
                  freeReg(p) ;
                return -1 ;
                break ;
    case WRITE: //printf("WRITE \n") ;
                fprintf(target_file,"MOV R19,5\n") ;
                fprintf(target_file,"PUSH R19\n") ;
                fprintf(target_file,"MOV R19,-1\n") ;
                fprintf(target_file,"PUSH R19\n") ;
                p = codeGen(Tree->left) ;
                fprintf(target_file,"MOV R19,R%d\n",p) ;
                fprintf(target_file,"PUSH R19\n") ;
                fprintf(target_file,"PUSH R19\n") ;
                fprintf(target_file,"PUSH R19\n") ;
                fprintf(target_file,"INT 7\n") ;
                fprintf(target_file,"POP R19\n") ;
                fprintf(target_file,"POP R19\n") ;
                fprintf(target_file,"POP R19\n") ;
                fprintf(target_file,"POP R19\n") ;
                fprintf(target_file,"POP R19\n") ;
                freeReg(p) ;
                return -1 ;
                break ;
    case NUM :  //printf("NUM \n") ;
                p = getReg() ;
                fprintf(target_file,"MOV R%d,%d\n",p,Tree->val) ;
                return p ;
                break ;
    case STRING://printf("STR \n") ;
                p = getReg() ;
                fprintf(target_file,"MOV R%d,%s\n",p,Tree->varName) ;
                return p ;
                break ;
    case ID :   //printf("ID \n") ;
                p = getReg() ;
                addr = getLAddress(Tree) ;
                if(addr!=-1)
                { 
                  fprintf(target_file,"MOV R%d,BP\n",p) ;
                  fprintf(target_file,"ADD R%d,%d\n",p,addr) ;
                  fprintf(target_file,"MOV R%d,[R%d]\n",p,p) ;
                }
                else 
                  fprintf(target_file,"MOV R%d,[%d]\n",p,getAddress(Tree)) ;
                return p ;
                break ;
    case ARRAY: //printf("ARRAY \n") ;
                p = getReg() ;
                q = codeGen(Tree->left) ;
                addr = getLAddress(Tree) ;
                if(addr!=-1)
                { 
                  fprintf(target_file,"MOV R%d,BP\n",p) ;
                  fprintf(target_file,"ADD R%d,%d\n",p,addr) ;
                }
                else 
                  fprintf(target_file,"MOV R%d,%d\n",p,getAddress(Tree)) ;
                fprintf(target_file,"ADD R%d, R%d\n",p,q) ;
                if(Tree->op != READ && Tree->op != EQ) 
                  fprintf(target_file,"MOV R%d,[R%d]\n",p,p) ;
                freeReg(q) ;
                return p ;
                break ;
    case OP2 :
    case OP :   //printf("OP \n") ;
                //showRegs() ;
                p = codeGen(Tree->left) ;
                //showRegs() ;
                q = codeGen(Tree->right) ;
                //showRegs() ;
                s = p ; 
                b = q ;
                //printf("Operation %d %c %d\n\n\n",s,Tree->op,b) ;
                // s = p ; b = q ;
                //printf("[OP [%d %d] %d %d %c] \n",s,b,Tree->left->val,Tree->right->val,Tree->op) ;
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
    case AND    : //printf("AND \n") ;
                  s = getReg() ;
                  l1 = label++ ;
                  l2 = label++ ;
                  p = codeGen(Tree->left) ;
                  fprintf(target_file,"JZ R%d,_L%d\n",p,l1) ;
                  freeReg(p) ;
                  q = codeGen(Tree->right) ;
                  fprintf(target_file,"MOV R%d,R%d\n",s,q) ;
                  freeReg(q) ;
                  fprintf(target_file,"JMP _L%d\n",l2) ;
                  fprintf(target_file,"_L%d:\n",l1) ;
                  fprintf(target_file,"MOV R%d,0\n",s) ;
                  fprintf(target_file,"_L%d:\n",l2) ;
                  return s ;
                  break ;
    case OR     : //printf("OR \n") ;
                  s = getReg() ;
                  l1 = label++ ;
                  l2 = label++ ;
                  p = codeGen(Tree->left) ;
                  fprintf(target_file,"JNZ R%d,_L%d\n",p,l1) ;
                  freeReg(p) ;
                  q = codeGen(Tree->right) ;
                  fprintf(target_file,"MOV R%d,R%d\n",s,q) ;
                  freeReg(q) ;
                  fprintf(target_file,"JMP _L%d\n",l2) ;
                  fprintf(target_file,"_L%d:\n",l1) ;
                  fprintf(target_file,"MOV R%d,1\n",s) ;
                  fprintf(target_file,"_L%d:\n",l2) ;
                  return s ;
                  break ;
    case RELOP ://printf("RELOP \n") ;
                p = codeGen(Tree->left) ;
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
    case WHILE ://printf("WHILE \n") ;
                l1 = label++ ;
                l2 = label++ ;
                fprintf(target_file,"_L%d:\n",l1) ;
                p = codeGen(Tree->left) ;
                fprintf(target_file,"JZ R%d,_L%d\n",p,l2) ;
                q = codeGen(Tree->right) ;
                fprintf(target_file,"JMP _L%d\n",l1) ;
                fprintf(target_file,"_L%d:\n",l2) ;
                freeReg(p) ;
                break ;
    case IF   :   //printf("IF \n") ;
                  l1 = label++ ;
                  // l2 = label++ ;
                  // l3 = label++ ;
                  p = codeGen(Tree->left) ;
                  fprintf(target_file,"JZ R%d,_L%d\n",p,l1) ;
                  q = codeGen(Tree->right) ;
                  fprintf(target_file,"_L%d:\n",l1) ;
                  freeReg(p) ;
                  break ;
    case IFTHEN : //printf("IFTHEN \n") ;
                  l1 = label++ ;
                  l2 = label++ ;
                  p = codeGen(Tree->left) ;
                  fprintf(target_file,"JZ R%d,_L%d\n",p,l1) ;
                  q = codeGen(Tree->right->left) ;
                  fprintf(target_file,"JMP _L%d\n",l2) ;
                  fprintf(target_file,"_L%d:\n",l1) ;
                  q = codeGen(Tree->right->right) ;
                  fprintf(target_file,"_L%d:\n",l2) ;
                  freeReg(p) ;
                  break ;
    case EQ :   //printf("EQ \n") ;
                q = codeGen(Tree->right) ;
                //printf("[%c %d] \n",Tree->right->op,q) ;
                addr = getLAddress(Tree->left) ;
                if(Tree->left->nodeType != ARRAY) 
                {
                  if(addr != -1)
                  { 
                    p = getReg() ;
                    fprintf(target_file,"MOV R%d,BP\n",p) ;
                    fprintf(target_file,"ADD R%d,%d\n",p,addr) ;
                    fprintf(target_file,"MOV [R%d],R%d\n",p,q) ;
                    freeReg(p) ;
                  }
                  else 
                    fprintf(target_file,"MOV [%d],R%d\n",getAddress(Tree->left),q)  ;
                }
                else
                {
                  Tree->left->op = EQ ;
                  p = codeGen(Tree->left) ;
                  fprintf(target_file,"MOV [R%d], R%d\n",p,q) ;
                  freeReg(p) ;
                }
                freeReg(q) ;
                return -1 ;
                break ;
    case BRKP : fprintf(target_file,"BRKP\n") ;
    case Connector: p = codeGen(Tree->left) ;
                    q = codeGen(Tree->right) ; 
                    return -1 ; 
                    break ;
    case ARGLIST  : //printf("ARGLIST\n") ;
                    // break ;
                    if(Tree->left) 
                    {
                      q = codeGen(Tree->left) ;
                      //printf("codeGen %d\n",q) ;
                      if(q==-1) ;
                        // fprintf(target_file,"PUSH R19\n") ;
                      else 
                      {
                        fprintf(target_file,"PUSH R%d\n",q) ;
                        freeReg(q) ;
                      }
                      /*
                      p = codeGen(Tree->left) ;
                      fprintf(target_file,"PUSH R%d\n",p) ;
                      freeReg(p) ;*/
                    }
                    if(Tree->right)
                    {
                      q = codeGen(Tree->right) ;
                      //printf("codeGen %d\n",q) ;
                      if(q==-1) ;
                        // fprintf(target_file,"PUSH R19\n") ;
                      else 
                      {
                        fprintf(target_file,"PUSH R%d\n",q) ;
                        freeReg(q) ;
                      }
                    }
                    break ;
    case FUNCTION : if(Tree->type==CALL)
                    {
                      printf("Function Call\n") ;
                      regStack = (int *) calloc(20,sizeof(int)) ;
                      // Save Regs
                      for(int i=0;i<20;i+=1)
                      {
                        regStack[i] = REG[i] ;
                        if(REG[i] == 1)
                          fprintf(target_file,"PUSH R%d\n",i) ;
                      }
                      // Evaluate Arguments
                      p = codeGen(Tree->left) ;
                      for(int i=0;i<20;i+=1)
                        REG[i] = 0 ;
                      // Push Return Variable
                      fprintf(target_file,"PUSH R0\n") ;
                      // Function Call 
                      fprintf(target_file,"CALL _F%d\n",getLabel(Tree->right)) ;
                      // Pop Out Arguments 
                      p = 0 ;
                      while(regStack[p]!=0)
                        p += 1; 
                      fprintf(target_file,"POP R%d\n",p) ;
                      if(Tree->left)
                        for(int i=0 ;i<Tree->left->val ;i+=1)
                          fprintf(target_file,"POP R19\n") ;
                      for(int i=19;i>=0;i-=1)
                      {
                        REG[i] = regStack[i] ;
                        if(regStack[i] == 1)
                          fprintf(target_file,"POP R%d\n",i) ;
                      }
                      REG[p] = 1 ;
                      free(regStack) ;
                      return p ;
                    }
                    else 
                    {
                      q = getLabel(Tree) ;
                      if(q==-1)
                      {
                        //printf("FunBlock _MAIN\n") ;
                        fprintf(target_file,"_MAIN:\n") ;
                      }
                      else 
                      {
                        //printf("FunBlock _F%d\n",q) ;
                        fprintf(target_file,"_F%d:\n",q) ;
                      }
                        fprintf(target_file,"PUSH BP\n") ;
                        fprintf(target_file,"MOV BP,SP\n") ;
                        fprintf(target_file,"ADD SP,%d\n",getStackSize(Tree->sTable)) ;
                      p = codeGen(Tree->right) ;
                    }
                    break ;
    case RETURN : p = codeGen(Tree->left) ;
                  q = getReg() ;
                  fprintf(target_file,"MOV R%d,BP\n",q) ;
                  fprintf(target_file,"SUB R%d,2\n",q) ;
                  fprintf(target_file,"MOV [R%d],R%d\n",q,p) ;
                  fprintf(target_file,"SUB SP,%d\n",getStackSize(Tree->sTable)) ;
                  fprintf(target_file,"POP BP\n");
                  fprintf(target_file,"RET\n") ;
                  return p ;
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