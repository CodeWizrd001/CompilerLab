%{
	#include <stdio.h>
    #include <string.h>
	int global_variable;
	FILE *f1 ;
	int flag = 0 ;
	int floats = 0 ;
	int ints = 0 ;
	int ans = 0 ;
%}

letters [a-zA-Z]
number [0-9]+
floatn [0-9.]+
op     [-|+|*|/|^|=]
space [ ]+
eol [\n|\0]

%%

[A]{letters}{letters} {
	printf("REQUIRED [%s] ",yytext);
	ans += 1 ;
	}
{letters}+ {printf("WORD ",yytext);}
{number}  	{
	printf("NUMS [%s] ",yytext);
	ints += 1 ;
	}
{floatn}	{
	printf("FLOAT [%s] ",yytext);
	floats += 1 ;
	}	
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
	printf("Found: %d\n",num);
	printf("Answer : %d\n",ans) ;
	return 1;
}