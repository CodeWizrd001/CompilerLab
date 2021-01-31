%{
	#include <stdio.h>
    #include <string.h>
	int global_variable;
	FILE *f1 ;
%}

letters [a-zA-Z., ]
lettersn [a-zA-Z.,\n ]
number [0-9]+
floatn [0-9.]+
op     [-|+|*|/|^|=]
space [ ]+
eol [\n|\0]

%%

[/][/]{letters}+ {printf("SINGLE [%s] ",yytext) ;}
[/][*]{lettersn}+[*][/] {printf("MULTI [%s] ",yytext) ;}
{letters}+ {printf("WORD [%s] ",yytext);}
{number}  	{printf("NUMS [%s] ",yytext);}
{floatn}	{printf("FLOAT [%s] ",yytext);}	
{op}      	{printf("OP [%s] ",yytext);}
{space} 	{}
{}

%%
int yywrap(void)
{
	return 1 ;
} 

int main(int argc, char* argv[])
{
	if(argc > 1)
	{
		FILE *f1 = fopen(argv[1], "r");
		if(f1)
			yyin = f1;
	}

	int num = yylex();
	return 1;
}