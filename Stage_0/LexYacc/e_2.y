%{
    #include <stdio.h>
    #include <stdlib.h>
    int yyerror();
%}

%token NUMBER NEWLINE
%left '+'
%left '*'
%left ','

%%

start: expr NEWLINE     {printf("\nComplete\n");exit(1);}
	;

expr: expr '+' expr	    {printf("%d + %d ",$1,$3);}
	| expr '*' expr	    {printf("%d * %d ",$1,$3);}
	| expr ',' expr		{printf("pair(%d,%d) ",$1,$3);$$=$1+$3;}
	| '(' expr ')'
	| NUMBER	        {$$=$1;}
	;

%%

int yyerror()
{
	printf("Error\n");
}

int main(int argc, char* argv[])
{
	if(argc > 1)
	{
		FILE *f1 = fopen(argv[1], "r");
	}

    yyparse();
    return 1;
}