%{
	#include <stdio.h>
	int global_variable;
%}

letters [a-z A-Z]+
number [0-9]+
op     [-|+|*|/|^|=]
openPar [(]
closePar [)]

%%

{letters} {printf("LETTERS ");}
{number}  {printf("NUMS ");}
{op}      {printf("OP ");}
{openPar}   {printf("OPEN ");}
{closePar}  {printf("CLOSE ");}

%%
int yywrap(void){} 

int main()
{
    yylex();
    return 1;
}