%{
	#include <stdio.h>
    #include <string.h>
	int global_variable;
	FILE *f1 ;
	int flag = 0 ;
	int words = 0 ;
	int lines = 0 ;
	int characters = 0 ;
%}

letters [a-zA-Z.]+
number [0-9]+
op     [-|+|*|/|^|=]
openPar [(]
closePar [)]
space [ ]+
eol [\n|\0]

%%

{letters} 	{
	printf("LETTERS [%s] ",yytext);
	words += 1 ;
	characters += strlen(yytext);
	}
{number}  	{printf("NUMS [%s] ",yytext);}
{op}      	{printf("OP [%s] ",yytext);}
{openPar}   {printf("OPEN ");}
{closePar}  {printf("CLOSE ");}
{space} 	{}
{eol}		{lines += 1;}

%%
int yywrap(void)
{
	lines += 1 ;
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
	printf("Chars : %d \nWords : %d \nLines : %d\n",characters,words,lines) ;
	return 1;
}