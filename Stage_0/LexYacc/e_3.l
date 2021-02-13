%{
    #include <stdio.h> 
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
%}

%%
[0-9]+	{
          yylval = atoi(yytext);
          return NUMBER;
        }
[\n]    return NEWLINE;
.       return *yytext;

%%

yywrap()
{
	return 1;
}