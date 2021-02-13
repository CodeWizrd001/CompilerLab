%{
    #include <stdio.h> 
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
%}

%%
[a-zA-Z]+	{
          yylval.word = yytext ;
          return WORD ;
        }
[\n]    return NEWLINE;
.       return *yytext;

%%

yywrap()
{
	return 1;
}