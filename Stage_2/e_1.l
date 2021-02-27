%{
    #include <stdio.h>
    #include "custom.h"
    #include "y.tab.h"
    tnode* createTree(int val,char op,int type,char* c,tnode *l,tnode *r) ;
%}

%%
[0-9]+	{
          yylval = createTree(atoi(yytext),0,NUM,NULL,NULL,NULL) ;
          // printf("NUM[%d] ",yylval->val) ;
          return NUM ;
        }
[a-z] 	{
          yylval = createTree(0,0,ID,yytext,NULL,NULL) ;
          // printf("ID[%d] ",yylval->val) ;
          return ID ;
        }
[+|-]	{
          yylval = createTree(0,*yytext,OP,NULL,NULL,NULL) ; 
          // printf("LexOP ") ;
          return OP;
        }
[*|/|%] {
          yylval = createTree(0,*yytext,OP2,NULL,NULL,NULL) ;
          // printf("LexOP2 ") ;
          return OP2;
        }
"begin" return BEGIN_ ;
"read"  return READ ;
"write" return WRITE ;
"end"   return END_ ;
";"     {
          return *yytext ;
        }
"="     {
          return EQ ;
        }
[()]    return *yytext;
[ \t\n] { }
.       return *yytext;

%%

int yywrap(void)
{
	return 1;
}