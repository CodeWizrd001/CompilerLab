%{
	#include <stdio.h>
    #include <string.h>
	#include <y.tab.h>
	
	int global_variable;
%}

word [a-zA-Z.]+
num [0-9]+
openPar [{]
closePar [}]
op [+|-|*|-|%|=]
eol [\n]

%%

{letters} 	{
	printf("LETTERS [%s] ",yytext);
	words += 1 ;
	characters += strlen(yytext);
	}
{DIGIT}  	{printf("NUMS [%s] ",yytext);}
{op}      	{printf("OP [%s] ",yytext);}
{openPar}   {printf("OPEN ");}
{closePar}  {printf("CLOSE ");}
{space} 	{}
{eol}		{lines += 1;}

%%
int yywrap(void)
{
	return 1 ;
} 