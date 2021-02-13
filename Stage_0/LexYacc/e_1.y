%{
    #include <stdio.h>
    #include <stdlib.h>
    int yyerror();
%}

%token NUMBER NEWLINE

%%

start: expr NEWLINE     {printf("\nComplete\n");exit(1);}
	;

expr: expr '+' expr	    {printf("+ ");}
	| expr '*' expr	    {printf("* ");}
	| '(' expr ')'
	| NUMBER	        {printf("%d ",$1);}
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