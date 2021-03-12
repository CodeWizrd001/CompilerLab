%{
    #include <stdio.h>
    #include "custom.h"
    #include "y.tab.h"
    tnode* createTree(int val,int op,int type,int t,char* c,tnode *l,tnode *r) ;
%}

%%
[0-9]+	    {
              yylval = createTree(atoi(yytext),-1,NUM,INT,NULL,NULL,NULL) ;
              return NUM ;
            }
[a-z] 	    {
              yylval = createTree(-1,-1,ID,INT,yytext,NULL,NULL) ;
              return ID ;
            }
[+|-]	      {
              yylval = createTree(0,*yytext,OP,INT,NULL,NULL,NULL) ;
              return OP;
            }
[*|/|%]     {
              yylval = createTree(0,*yytext,OP2,INT,NULL,NULL,NULL) ;
              return OP2;
            }
"<>"        return NE ;
"!="        return NE ;
"<"         return LT ;
">"         return GT ;
"=="        return EE ;
"<="        return LTE ;
">="        return GTE ;
"if"        return IF ;
"do"        return DO ;
"="         return EQ ;
"end"       return END_ ;
"then"      return THEN ;
"else"      return ELSE ;
"read"      return READ ;
"write"     return WRITE ;
"endif"     return ENDIF ;
"while"     return WHILE ;
"begin"     return BEGIN_ ;
"endwhile"  return ENDWHILE ;
"breakpoint"  return BRKP ;
"brkp"      return BRKP ;
";"         return *yytext ;
[()]        return *yytext;
[ \t\n] 
.           return *yytext;

%%

int yywrap(void)
{
	return 1;
}