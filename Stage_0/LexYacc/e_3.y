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

start: expr NEWLINE     {printf("\n%d Complete\n",$1);exit(1);}
	;

expr: expr '+' expr	    {$$ = $1 + $3 ;}
	| expr '-' expr	    {$$ = $1 - $3 ;}
	| expr '*' expr	    {$$ = $1 * $3 ;}
	| expr ',' expr		{$$ = $1 + $3 ;}
	| '(' expr ')'		{$$ = $2 ;}
	| NUMBER	        {$$ = $1 ;}
	;

%%

int yyerror(char *s)
{
	printf("[Error] %s\n",s);
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