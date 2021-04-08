%{
    #include <stdio.h>
    #include "custom.h"
    #include "y.tab.h"
    tnode* createTree(int val,int op,int type,int t,char* c,tnode *l,tnode *r) ;
%}

%%
[+|-]	      {
              yylval = createTree(0,*yytext,OP,INT,NULL,NULL,NULL) ;
              return OP;
            }
[*|/|%]     {
              yylval = createTree(0,*yytext,OP2,INT,NULL,NULL,NULL) ;
              return OP2;
            }
\"[a-zA-Z ]+\"  {
                  printf("String : %s\n",yytext) ;
                  char *str = (char *) calloc(strlen(yytext),sizeof(char)) ;
                  strcpy(str,yytext) ;

                  yylval = createTree(-1,-1,STRING,STRING,str,NULL,NULL) ;
                  return STRING ;
                }
"<>"        return NE ;
"!="        return NE ;
"<"         return LT ;
">"         return GT ;
"=="        return EE ;
"<="        return LTE ;
">="        return GTE ;

"enddecl"   return ENDDECL ;
"decl"      return DECL ;

"int"       return INT ;
"str"       return STR ;
"bool"      return BOOL ;

"endif"     return ENDIF ;
"if"        return IF ;
"do"        return DO ;
"="         return EQ ;
"end"       return END_ ;
"then"      return THEN ;
"else"      return ELSE ;
"read"      return READ ;
"write"     return WRITE ;
"endwhile"  return ENDWHILE ;
"while"     return WHILE ;
"begin"     return BEGIN_ ;
"breakpoint"  return BRKP ;
"brkp"      return BRKP ;
";"         return *yytext ;
[()]        return *yytext;
[ \t\n] 
[0-9]+	    {
              yylval = createTree(atoi(yytext),-1,NUM,INT,NULL,NULL,NULL) ;
              // printf("NUM %d\n",atoi(yytext)) ;
              return NUM ;
            }
[a-z0-9]+ 	{
              char *name = (char *) calloc(strlen(yytext),sizeof(char)) ;
              strcpy(name,yytext) ;
              // printf("ID %s\n",yytext) ;
              yylval = createTree(-1,-1,ID,ID,name,NULL,NULL) ;
              return ID ;
            }
.           {
              printf("Other %c\n",*yytext) ;
              return *yytext;
            }

%%

int yywrap(void)
{
	return 1;
}