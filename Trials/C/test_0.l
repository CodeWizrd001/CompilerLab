%{
	#include <stdio.h>
    #include <string.h>
	int global_variable;
	FILE *f1 ;
	int flag = 0 ;
%}

lower 		[a-z]+
upper 		[A-Z]+
number		[0-9]+
op     		[-|+|*|/|^|=]
openPar 	[(]
closePar 	[)]
space 		[ ]+

%%
{lower} 	{printf("LOWER [%s] ",yytext);}
{upper} 	{printf("UPPER [%s] ",yytext);}
{number}  	{printf("NUMS [%s] ",yytext);}

({lower}|{upper})({lower}|{upper}|{number})*({lower}|{upper}|{number}) {printf("VARIABLE [%s] ",yytext);}


{op}      	{printf("OP [%s] ",yytext);}
{openPar}   {printf("OPEN ");}
{closePar}  {printf("CLOSE ");}
{space} 	{}

%%
int yywrap(void)
{
	return 1 ;
} 

int main(int argc, char* argv[])
{
	printf("[+]  Started\n") ;
	if(argc > 1)
	{
		FILE *f1 = fopen(argv[1], "r");
		if(f1)
			yyin = f1;
	}

	int num = yylex();
	printf("Found: %d\n",num);
	return 1;
}