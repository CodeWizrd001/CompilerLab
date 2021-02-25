%{
    #include <stdio.h>
    #include <limits.h>
    #include "custom.h" 
	  #include "y.tab.h"
%}

%%
[0-9]+	{
          yylval = (YYSTYPE) calloc(1,sizeof(tnode)) ;
          yylval->val = atoi(yytext) ;
          yylval->op = 0 ;
          yylval->left = NULL ;
          yylval->right = NULL ;
          return NUM;
        }
[+|-]	  {
          yylval = (YYSTYPE) calloc(1,sizeof(tnode)) ;
          yylval->val = INT_MIN ;
          yylval->op = *yytext ;
          yylval->left = NULL ;
          yylval->right = NULL ;
          return OP;
        }
[*|/|%] {
          yylval = (YYSTYPE) calloc(1,sizeof(tnode)) ;
          yylval->val = 0 ;
          yylval->op = *yytext ;
          yylval->left = NULL ;
          yylval->right = NULL ;
          return OP2;
        }
[()]  return *yytext;
[\n]  return NEWLINE;
.     return *yytext;

%%

yywrap()
{
	return 1;
}