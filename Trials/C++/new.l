%{
	#include <iostream>
    #include <string.h>
    using namespace std ;
	int global_variable;
%}

letters [a-z A-Z]+
number [0-9]+
op     [-|+|*|/|^|=]

%%

{letters} {printf("letters ");}
{number}  {printf("number ");}
{op}      {printf("operator ");}

%%
int yywrap(void){} 

int main()
{
    yylex();
    return 1;
}